#!/usr/bin/env python3
"""Replace one NAKED_FUNCTION in a C file with decompiled C.

The C snippet file holds the function (signature + body) without a doc
comment; this adds the project's `@brief <addr> | <size> | <text>` header
using the address comment the naked version carried and the size taken
from the ELF symbol table.

usage: replace_naked.py <file.c> <FunctionName> <snippet.c> "<brief text>"
"""
import re
import subprocess
import sys
from pathlib import Path


def func_size(name: str) -> int:
    out = subprocess.run(["arm-none-eabi-nm", "-n", "mf_us.elf"], capture_output=True, text=True).stdout
    rows = [l.split() for l in out.splitlines() if len(l.split()) == 3]
    # skip local labels from inline asm (_0805xxxx) and mapping symbols
    addrs = [(int(a, 16), n) for a, _, n in rows if not n.startswith(("_", "$"))]
    for i, (a, n) in enumerate(addrs):
        if n == name:
            nxt = next(b for b, _ in addrs[i + 1:] if b > a)
            return nxt - a
    raise SystemExit(f"{name} not in mf_us.elf (build first)")


def main() -> int:
    path, name, snippet, brief = Path(sys.argv[1]), sys.argv[2], Path(sys.argv[3]), sys.argv[4]
    text = path.read_text()
    pat = re.compile(rf"// (0x[0-9A-Fa-f]+)\nNAKED_FUNCTION\nvoid {name}\(void\)\n\{{\n.*?\n\}}\n", re.S)
    m = pat.search(text)
    if not m:
        raise SystemExit(f"naked {name} not found in {path}")
    addr = int(m.group(1), 16) & 0xFFFFFF
    size = func_size(name)
    doc = f"/**\n * @brief {addr:x} | {size:x} | {brief}\n * \n */\n"
    code = snippet.read_text().strip("\n") + "\n"
    path.write_text(text[:m.start()] + doc + code + text[m.end():])
    print(f"{name}: replaced ({size:#x} bytes)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
