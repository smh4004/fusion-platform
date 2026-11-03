"""Undo relocate_pointers `tables` and `incbin` conversions: put the
original INCBIN blob lines back so the tree builds against fresh symbols.
Run from repo root."""
import json
import re
from pathlib import Path

db = json.loads(Path("database.json").read_text())
paths = {e["path"] for e in db}
rom = Path("mf_us_baserom.gba").read_bytes()
changed = []

for f in sorted(Path("src").rglob("*.c")):
    text = f.read_text(newline="")
    orig = text
    nl = "\r\n" if "\r\n" in text else "\n"

    # 1) u32 sPointerTable_<addr>[N] = { ... };  ->  u8 sBlob_<addr>_<end>[] = INCBIN
    def tab(m):
        quals, addr, n = m.group(1), int(m.group(2), 16), int(m.group(3))
        end = addr + 4 * n
        name = f"Blob_{addr:x}_{end:x}"
        if name + ".bin" not in paths:
            db.append({"path": name + ".bin", "count": f"0x{end - addr:X}", "addr": {"us": f"0x{addr:X}"}, "size": 1})
            paths.add(name + ".bin")
        changed.append((f"sPointerTable_{addr:x}", f"s{name}"))
        return f'{quals}u8 s{name}[] = INCBIN_U8("data/{name}.bin");'
    text = re.sub(r"^((?:static\s+)?(?:const\s+)?)u32 sPointerTable_([0-9a-f]+)\[(\d+)\] = \{.*?^\};", tab, text, flags=re.S | re.M)

    # 2) inline-asm incbin blocks -> plain INCBIN
    def blk(m):
        sym, const = m.group(2), "const " if m.group(1) else ""
        name = sym[1:]
        return f'{const}u8 {sym}[] = INCBIN_U8("data/{name}.bin");'
    text = re.sub(r"// Bytes come from the extracted file; pointers are relocated by the linker\.\r?\n"
                  r"extern (const )?u8 (sBlob_\w+)\[\];\r?\nasm\(\".*?\"\);", blk, text, flags=re.S)
    if text != orig:
        f.write_text(text, newline="")
        print("reverted in", f)

# references to the table names elsewhere -> blob names
for old, new in changed:
    for g in list(Path("src").rglob("*.c")) + list(Path("include").rglob("*.h")):
        t = g.read_text(newline="")
        if old in t:
            t = re.sub(rf"extern\s+(const\s+)?u32\s+{old}\[\];", lambda m: f"extern {m.group(1) or ''}u8 {new}[];", t)
            g.write_text(re.sub(rf"\b{old}\b", new, t), newline="")
db.sort(key=lambda e: int(e["addr"].get("us", "0x0"), 16))
Path("database.json").write_text(json.dumps(db, indent=2) + "\n")
print("tables reverted:", changed)
