#!/usr/bin/env python3
"""Make hard-coded pointers relocatable without needing to name every target.

    relocate_pointers.py tables <Blob_xxx_yyy> [...]
        Rewrite blobs that are pure pointer tables as C arrays of
        `(u32)&symbol + offset` entries (named sPointerTable_<addr>), and drop
        them from database.json.

    relocate_pointers.py literals <file.c|file.s> [...]
        Rewrite raw ROM addresses in C casts `(T)0x8xxxxxx` and in asm
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
    return renamed.get(name, name), addr - base, kind


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


def cmd_tables(blobs):
    db = json.loads(Path("database.json").read_text())
    for blob in blobs:
        entry = next(e for e in db if e["path"] == blob + ".bin")
        start = int(entry["addr"]["us"], 16)
        size = int(entry["count"], 16) * entry["size"]
        assert start % 4 == 0 and size % 4 == 0, blob
        words = struct.unpack_from(f"<{size // 4}I", ROM, start)
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
        renamed[sym] = new_name
        table_types[new_name] = f"{quals}u32"
        items, externs = [], set()
        for w in words:
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
        for g in SRC_FILES + sorted(Path("asm").glob("*.s")) + sorted(Path("include").rglob("*.h")):
            gt = g.read_text()
            if sym in gt:
                g.write_text(re.sub(rf"\b{sym}\b", new_name, gt))
        db = [e for e in db if e["path"] != blob + ".bin"]
        print(f"{blob}: {len(words)} words -> {new_name} in {f} ({len(externs)} externs)")
    Path("database.json").write_text(json.dumps(db, indent=2) + "\n")


CAST_LIT = re.compile(r"\((?P<cast>[^()]*?\*[^()]*?)\)\s*0x0?(?P<addr>8[0-9a-fA-F]{6})\b")
ASM_LIT = re.compile(r"(\.4byte\s+)0x0?(8[0-9A-Fa-f]{6})\b")


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
                inner = f"&{name}" if off == 0 else f"(const u8*)&{name} + 0x{off:x}"
                return f"({m.group('cast')})({inner})"
            text = p.read_text()
            text = CAST_LIT.sub(sub, text)
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
    print(f"total {total}; made global: {sorted(made_global)}")


if __name__ == "__main__":
    if len(sys.argv) < 3 or sys.argv[1] not in ("tables", "literals"):
        print(__doc__)
        sys.exit(2)
    (cmd_tables if sys.argv[1] == "tables" else cmd_literals)(sys.argv[2:])
