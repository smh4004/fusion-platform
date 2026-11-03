#!/usr/bin/env python3
"""Make hard-coded pointers relocatable without needing to name every target.

    relocate_pointers.py tables <Blob_xxx_yyy> [...]
        Rewrite a blob as a C u32 array (named sPointerTable_<addr>) in which
        every word that is a ROM address becomes `(u32)&symbol + offset` and
        every other word stays a number. Bytes before the first or after the
        last 4-byte boundary stay small INCBIN blobs. Works for pure pointer
        tables and for mixed data; for mixed data a word that merely looks
        like an address is also converted (same bytes in the matching build).

    relocate_pointers.py incbin [--all] <Blob_xxx_yyy> [...]
        For blobs that are mostly graphics or other data: keep the bytes in
        the extracted .bin file and add relocations only at real pointers
        (animation frame tables, or every address-like word with --all).

    relocate_pointers.py literals <file.c|file.s> [...]
        Rewrite raw ROM addresses in C casts `(T)0x8xxxxxx`, bare
        addresses passed as arguments (e.g. DMA3_COPY_16(0x83e799c, ...)), and in asm
        `.4byte 0x08xxxxxx` as symbol (+ offset) expressions.

Targets are found in the built ELF (run `make` first). A target symbol that
is `static` in its file is made global so it can be referenced. Every
rewrite keeps the ROM byte-identical; run `make check` afterwards.
"""
import bisect
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

ROM = Path("mf_us_baserom.gba").read_bytes()
ROM_END = len(ROM.rstrip(b"\xff"))


def load_syms():
    out = subprocess.run(["arm-none-eabi-nm", "-n", "mf_us.elf"], capture_output=True, text=True, check=True).stdout
    rows = []
    for l in out.splitlines():
        p = l.split()
        if len(p) == 3 and p[0].startswith("08") and not p[2].startswith(("$", "_0", "lbl_")):
            rows.append((int(p[0], 16) & 0xFFFFFF, p[2], p[1]))
    rows.sort()
    return rows


SYMS = load_syms()
ADDRS = [a for a, _, _ in SYMS]
SRC_FILES = sorted(Path("src").rglob("*.c"))
HEADER_TEXT = "\n".join(h.read_text() for h in Path("include").rglob("*.h"))
made_global = set()
renamed = {}  # old blob symbol -> new table name (tables are always global)
table_types = {}


_def_cache = {}


def definition_file(name):
    """(file, match) for the C definition of `name`. Cached per name; the
    match offsets are only valid until that file is next modified."""
    if name in _def_cache:
        f = _def_cache[name]
        if f is None:
            return None, None
        pat = re.compile(rf"^(static\s+)?[^\n;()]*\b{re.escape(name)}\s*(\[[^\]\n]*\])?\s*=", re.M)
        return f, pat.search(f.read_text())
    pat = re.compile(rf"^(static\s+)?[^\n;()]*\b{re.escape(name)}\s*(\[[^\]\n]*\])?\s*=", re.M)
    for f in SRC_FILES:
        t = f.read_text()
        m = pat.search(t)
        if m:
            _def_cache[name] = f
            return f, m
    _def_cache[name] = None
    return None, None


def ensure_global(name, kind):
    """Drop `static` from a data symbol's definition so others can use it."""
    if kind.isupper() or name in made_global or name in table_types:
        return True
    f, m = definition_file(name)
    if f is None or not m.group(1):
        return False
    t = f.read_text()
    t = t[: m.start()] + t[m.start() + len(m.group(1)):]
    f.write_text(t)
    made_global.add(name)
    return True


def target(addr, allow_code=True):
    """(symbol, offset, kind) containing ROM address `addr`, or None."""
    i = bisect.bisect_right(ADDRS, addr) - 1
    if i < 0:
        return None
    base, name, kind = SYMS[i]
    if kind in "Tt":
        if not allow_code or addr not in (base, base | 1):
            return None
    off = addr - base
    if name in renamed:
        for seg_off, new_name in reversed(renamed[name]):
            if off >= seg_off:
                return new_name, off - seg_off, kind
    return name, off, kind


def expr(addr):
    t = target(addr & 0xFFFFFF)
    if t is None:
        return None, None
    name, off, kind = t
    if kind in "Tt":
        return f"(u32){name}", name
    if not ensure_global(name, kind):
        return None, None
    e = f"(u32)&{name}" + (f" + 0x{off:x}" if off else "")
    return e, name


def is_frame_pointer(word, nxt, lo, hi):
    """A FrameData entry {pFrame, timer}: even target inside the same blob,
    a timer below 256, and the target looks like an OAM frame (1-64 parts)."""
    a = word & 0xFFFFFF
    if word % 2 or nxt >= 0x100 or not (lo <= a < hi):
        return False
    return 1 <= (struct.unpack_from("<H", ROM, a)[0] & 0xFFF) <= 64


def cmd_tables(blobs):
    frames_only = "--frames" in blobs
    blobs = [b for b in blobs if not b.startswith("--")]
    db = json.loads(Path("database.json").read_text())
    for blob in blobs:
        entry = next(e for e in db if e["path"] == blob + ".bin")
        bstart = int(entry["addr"]["us"], 16)
        bend = bstart + int(entry["count"], 16) * entry["size"]
        start, end = (bstart + 3) & ~3, bend & ~3
        size = end - start
        words = struct.unpack_from(f"<{size // 4}I", ROM, start)
        pieces = []  # (start, end) of unaligned head/tail kept as raw bytes
        if start > bstart:
            pieces.append((bstart, start))
        if bend > end:
            pieces.append((end, bend))
        sym = "s" + blob[0].upper() + blob[1:]
        f, m = definition_file(sym)
        assert f, sym
        text = f.read_text()
        line_re = re.compile(rf"^((?:static\s+)?(?:const\s+)?)u8 {sym}\[\] = INCBIN_U8\(\"data/{re.escape(blob)}\.bin\"\);$", re.M)
        lm = line_re.search(text)
        assert lm, sym
        quals = lm.group(1).replace("static", "").strip()
        quals = (quals + " ") if quals else ""
        new_name = f"sPointerTable_{start:x}"
        segs = [(0, f"sBlob_{bstart:x}_{start:x}")] if start > bstart else []
        segs.append((start - bstart, new_name))
        if bend > end:
            segs.append((end - bstart, f"sBlob_{end:x}_{bend:x}"))
        renamed[sym] = segs
        table_types[new_name] = f"{quals}u32"
        items, externs = [], set()
        for i, w in enumerate(words):
            if frames_only and not is_frame_pointer(w, words[i + 1] if i + 1 < len(words) else 0x100, bstart, bend):
                items.append(f"0x{w:08x}")
                continue
            if 0x08000000 <= w < 0x08000000 + ROM_END:
                e, name = expr(w)
                if e:
                    items.append(e)
                    if Path(definition_file(name)[0] or "") != f:
                        externs.add(name)
                    continue
            items.append(f"0x{w:08x}")
        body = "\n".join(f"    {x}," for x in items).rstrip(",")
        text = f.read_text()  # may have changed via ensure_global
        lm = line_re.search(text)
        new = f"{quals}u32 {new_name}[{len(words)}] = {{\n{body}\n}};"
        for a, b in pieces:
            piece = f'{quals}u8 sBlob_{a:x}_{b:x}[] = INCBIN_U8("data/Blob_{a:x}_{b:x}.bin");'
            new = (piece + "\n" + new) if a < start else (new + "\n" + piece)
            db.append({"path": f"Blob_{a:x}_{b:x}.bin", "count": f"0x{b - a:X}", "addr": {"us": f"0x{a:X}"}, "size": 1})
        text = text[: lm.start()] + new + text[lm.end():]
        same_file_later = {n for n in re.findall(r"&(sPointerTable_[0-9a-f]+)", new) if n != new_name and n not in text.split(new)[0]}
        externs |= same_file_later
        if externs:
            def decl_of(n):
                if n in table_types:
                    return f"extern {table_types[n]} {n}[];\n"
                if re.search(rf"\b{n}\b", HEADER_TEXT):
                    return ""  # declared by a header (with its real type)
                return f"extern const u8 {n}[];\n"
            decl = "".join(decl_of(n) for n in sorted(externs) if not re.search(rf"^extern[^\n]*\b{n}\b", text, re.M))
            if decl:
                incs = [mm.end() for mm in re.finditer(r'^#include "[^"]+"\n', text, re.M)]
                at = incs[-1] if incs else 0
                text = text[:at] + "\n" + decl + text[at:]
        f.write_text(text)
        # references by the old name elsewhere
        def remap(m, segs=segs):
            amp, offtxt = m.group(1), m.group(3)
            off = int(offtxt, 16) if offtxt else 0
            seg_off, nm_ = next((so, n) for so, n in reversed(segs) if off >= so)
            rest = off - seg_off
            return f"{amp}{nm_}" + (f" + 0x{rest:x}" if rest else "")
        ref = re.compile(rf"(&?)\b{sym}\b(\s*\+\s*0x([0-9a-fA-F]+))?")
        for g in SRC_FILES + sorted(Path("asm").glob("*.s")) + sorted(Path("include").rglob("*.h")):
            gt = g.read_text()
            if sym in gt:
                if g.suffix == ".h":
                    gt = re.sub(rf"extern\s+(const\s+)?u8\s+{sym}\[\];", f"extern {table_types[new_name]} {new_name}[];", gt)
                g.write_text(ref.sub(remap, gt))
        db = [e for e in db if e["path"] != blob + ".bin"]
        print(f"{blob}: {len(words)} words -> {new_name} in {f} ({len(externs)} externs)")
    # forward declarations written before a later table's type was known
    for g in SRC_FILES + sorted(Path("include").rglob("*.h")):
        gt = g.read_text()
        new_gt = re.sub(r"extern\s+(?:const\s+)?u(?:8|32)\s+(sPointerTable_[0-9a-f]+)\[\];",
                        lambda m: f"extern {table_types[m.group(1)]} {m.group(1)}[];" if m.group(1) in table_types else m.group(0), gt)
        if new_gt != gt:
            g.write_text(new_gt)
    db.sort(key=lambda e: int(e["addr"]["us"], 16))
    Path("database.json").write_text(json.dumps(db, indent=2) + "\n")


def cmd_incbin(args):
    """Keep a blob's bytes in its extracted .bin file but give its real
    pointers relocations: the INCBIN line becomes an inline-asm block of
    .incbin slices with `.4byte symbol + offset` at each pointer. Only frame
    tables are treated as pointers unless --all is given. No ROM data enters
    the source; the blob keeps its name and database entry."""
    all_words = "--all" in args
    blobs = [b for b in args if not b.startswith("--")]
    db = json.loads(Path("database.json").read_text())
    for blob in blobs:
        entry = next(e for e in db if e["path"] == blob + ".bin")
        bstart = int(entry["addr"]["us"], 16)
        bend = bstart + int(entry["count"], 16) * entry["size"]
        sym = "s" + blob[0].upper() + blob[1:]
        f, _ = definition_file(sym)
        assert f, sym
        text = f.read_text()
        line_re = re.compile(rf"^((?:static\s+)?(const\s+)?)u8 {sym}\[\] = INCBIN_U8\(\"data/{re.escape(blob)}\.bin\"\);$", re.M)
        lm = line_re.search(text)
        assert lm, sym
        is_const = bool(lm.group(2))
        pointers = []  # (offset in blob, expression)
        o = (bstart + 3) & ~3
        while o + 4 <= bend:
            w = struct.unpack_from("<I", ROM, o)[0]
            nxt = struct.unpack_from("<I", ROM, o + 4)[0] if o + 8 <= bend else 0x100
            ok = 0x08000000 <= w < 0x08000000 + ROM_END and (all_words or is_frame_pointer(w, nxt, bstart, bend))
            if ok:
                t = target(w & 0xFFFFFF)
                if t:
                    name, off, kind = t
                    if name == sym:
                        e = sym + (f" + 0x{off:x}" if off else "")
                    elif kind in "Tt":
                        e = name
                    elif ensure_global(name, kind):
                        e = name + (f" + 0x{off:x}" if off else "")
                    else:
                        e = None
                    if e:
                        pointers.append((o - bstart, e))
            o += 4
        lines = [f"    .pushsection {'.rodata' if is_const else '.data'}",
                 "    .global " + sym, sym + ":"]
        pos = 0
        for off, e in pointers:
            if off > pos:
                lines.append(f'    .incbin "data/{blob}.bin", 0x{pos:x}, 0x{off - pos:x}')
            lines.append(f"    .4byte {e}")
            pos = off + 4
        if bend - bstart > pos:
            lines.append(f'    .incbin "data/{blob}.bin", 0x{pos:x}, 0x{bend - bstart - pos:x}')
        lines.append("    .popsection")
        block = "// Bytes come from the extracted file; pointers are relocated by the linker.\n"
        block += f"extern {'const ' if is_const else ''}u8 {sym}[];\n"
        block += 'asm("\\n\\\n' + "".join(l.replace('"', '\\"') + "\\n\\\n" for l in lines) + '");'
        f.write_text(text[: lm.start()] + block + text[lm.end():])
        print(f"{blob}: {len(pointers)} relocated pointers, {bend - bstart:#x} bytes kept in data/")


CAST_LIT = re.compile(r"\((?P<cast>[^()]*?\*[^()]*?)\)\s*0x0?(?P<addr>8[0-9a-fA-F]{6})\b")
BARE_LIT = re.compile(r"(?<=[(,]\s)0x0?(?P<addr>8[0-9a-fA-F]{6})\b|(?<=[(,])0x0?(?P<addr2>8[0-9a-fA-F]{6})\b")
ASM_LIT = re.compile(r"(\.4byte\s+)0x0?(8[0-9A-Fa-f]{6})\b")


labels_needed = {}   # blob symbol -> {offset: label}
naked_syms_used = {}  # file -> symbols referenced from naked asm (no C declaration needed)
externs_needed = {}  # file -> {label}


def blob_label(blob, addr):
    lbl = f"sAddr_{addr:x}"
    base = int(blob.split("_")[1], 16)
    labels_needed.setdefault(blob, {})[addr - base] = lbl
    return lbl


def add_blob_labels():
    """Give each needed address inside a blob its own global label, so C code
    loads one constant per address exactly as the raw literal did (a single
    base symbol + offsets makes agbcc share the base and changes the code)."""
    for blob, offs in labels_needed.items():
        f, _ = definition_file(blob)
        if f is None:
            for g in SRC_FILES:
                if f'"data/{blob[1:]}.bin"' in g.read_text() or f"{blob}:" in g.read_text():
                    f = g
                    break
        text = f.read_text(newline="")
        nl = "\r\n" if "\r\n" in text else "\n"
        size = int(blob.split("_")[2], 16) - int(blob.split("_")[1], 16)
        # existing pieces: either a plain INCBIN or an asm block from `incbin`
        plain = re.search(rf"^((?:static\s+)?(const\s+)?)u8 {blob}\[\] = INCBIN_U8\(\"data/{blob[1:]}\.bin\"\);", text, re.M)
        if plain:
            is_const = bool(plain.group(2))
            items = [("bin", 0, size)]
            start, end = plain.start(), plain.end()
        else:
            m = re.search(rf"// Bytes come from the extracted file; pointers are relocated by the linker\.\r?\nextern (const )?u8 {blob}\[\];\r?\nasm\(\"(.*?)\"\);", text, re.S)
            assert m, blob
            is_const = bool(m.group(1))
            items = []
            for line in m.group(2).split("\\n"):
                line = line.strip().strip("\\").strip()
                mm = re.match(r'\.incbin \\?"[^"\\]+\\?", 0x([0-9a-f]+), 0x([0-9a-f]+)', line)
                if mm:
                    items.append(("bin", int(mm.group(1), 16), int(mm.group(2), 16)))
                elif line.startswith(".4byte"):
                    items.append(("word", line[len(".4byte"):].strip()))
                elif line.startswith(".global sAddr_") or re.match(r"sAddr_[0-9a-f]+:", line):
                    pass
            # recover word offsets
            pos, fixed = 0, []
            for it in items:
                if it[0] == "bin":
                    fixed.append(it); pos = it[1] + it[2]
                else:
                    fixed.append(("word", pos, it[1])); pos += 4
            items = fixed
            start, end = m.start(), m.end()
        # split binary slices at label offsets
        out = []
        for it in items:
            if it[0] == "bin":
                a, ln = it[1], it[2]
                cuts = sorted(o for o in offs if a < o < a + ln)
                prev = a
                for c in cuts + [a + ln]:
                    out.append(("bin", prev, c - prev))
                    prev = c
            else:
                out.append(it)
        lines = [f"    .pushsection {'.rodata' if is_const else '.data'}", f"    .global {blob}", f"{blob}:"]
        for it in out:
            o = it[1]
            if o in offs:
                lines += [f"    .global {offs[o]}", f"{offs[o]}:"]
            if it[0] == "bin":
                if it[2]:
                    lines.append(f'    .incbin "data/{blob[1:]}.bin", 0x{o:x}, 0x{it[2]:x}')
            else:
                lines.append(f"    .4byte {it[2]}")
        lines.append("    .popsection")
        block = "// Bytes come from the extracted file; pointers are relocated by the linker." + nl
        block += f"extern {'const ' if is_const else ''}u8 {blob}[];" + nl
        block += 'asm("\\n\\' + nl + "".join(l.replace('"', '\\"') + "\\n\\" + nl for l in lines) + '");'
        f.write_text(text[:start] + block + text[end:], newline="")
        print(f"  {blob}: {len(offs)} label(s) in {f}")
    for fn, lbls in externs_needed.items():
        p = Path(fn)
        t = p.read_text(newline="")
        nl = "\r\n" if "\r\n" in t else "\n"
        decl = "".join(f"extern const u8 {l}[];{nl}" for l in sorted(lbls) if f" {l}[];" not in t)
        if decl:
            ends = [mm.end() for mm in re.finditer(r'^#include "[^"]+"\r?\n', t, re.M)]
            at = ends[-1] if ends else 0
            p.write_text(t[:at] + decl + t[at:], newline="")


def cmd_literals(files):
    total = 0
    for fn in files:
        p = Path(fn)
        text = p.read_text()
        n = 0
        if p.suffix == ".c":
            def sub(m):
                nonlocal n
                addr = int(m.group("addr"), 16) & 0xFFFFFF
                t = target(addr, allow_code=False)
                if not t:
                    return m.group(0)
                name, off, kind = t
                if not ensure_global(name, kind):
                    return m.group(0)
                n += 1
                if off and name.startswith("sBlob_"):
                    lbl = blob_label(name, addr)
                    externs_needed.setdefault(str(p), set()).add(lbl)
                    return f"({m.group('cast')}){lbl}"
                inner = f"&{name}" if off == 0 else f"(const u8*)&{name} + 0x{off:x}"
                return f"({m.group('cast')})({inner})"
            text = p.read_text()
            text = CAST_LIT.sub(sub, text)

            def bare(m):
                nonlocal n
                addr = int(m.group("addr") or m.group("addr2"), 16) & 0xFFFFFF
                t = target(addr, allow_code=False)
                if not t:
                    return m.group(0)
                name, off, kind = t
                if not ensure_global(name, kind):
                    return m.group(0)
                n += 1
                if off and name.startswith("sBlob_"):
                    lbl = blob_label(name, addr)
                    externs_needed.setdefault(str(p), set()).add(lbl)
                    return f"(u32){lbl}"
                return f"(u32)&{name}" + (f" + 0x{off:x}" if off else "")
            text = BARE_LIT.sub(bare, text)

            # naked functions: .4byte literals inside asm("...") strings
            def naked(m):
                nonlocal n
                addr = int(m.group(2), 16) & 0xFFFFFF
                t = target(addr)
                if not t:
                    return m.group(0)
                name, off, kind = t
                if kind not in "Tt" and not ensure_global(name, kind):
                    return m.group(0)
                n += 1
                if kind not in "Tt" and name not in naked_syms_used.setdefault(str(p), set()):
                    naked_syms_used[str(p)].add(name)
                return f"{m.group(1)}{name}" + (f" + 0x{off:x}" if off else "")
            text = ASM_LIT.sub(naked, text)
        else:
            def sub(m):
                nonlocal n
                addr = int(m.group(2), 16) & 0xFFFFFF
                t = target(addr)
                if not t:
                    return m.group(0)
                name, off, kind = t
                if kind not in "Tt" and not ensure_global(name, kind):
                    return m.group(0)
                n += 1
                if kind in "Tt":
                    # Thumb function symbols get their low bit set by the assembler
                    return f"{m.group(1)}{name}"
                return f"{m.group(1)}{name}" + (f" + 0x{off:x}" if off else "")
            text = ASM_LIT.sub(sub, p.read_text())
        if n:
            p.write_text(text)
        total += n
        print(f"{fn}: {n} literal(s)")
    add_blob_labels()
    print(f"total {total}; made global: {sorted(made_global)}")


if __name__ == "__main__":
    cmds = {"tables": cmd_tables, "literals": cmd_literals, "incbin": cmd_incbin}
    if len(sys.argv) < 3 or sys.argv[1] not in cmds:
        print(__doc__)
        sys.exit(2)
    cmds[sys.argv[1]](sys.argv[2:])
