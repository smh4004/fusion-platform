#!/usr/bin/env python3
"""Turn a disassembled .s file into a C file of NAKED_FUNCTION wrappers.

Each `thumb_func_start Name` block becomes

    NAKED_FUNCTION
    void Name(void)
    {
        asm(" .syntax unified\\n\\
        ...original instructions...
        .syntax divided\\n");
    }

so the file builds byte-identical to the asm it came from. You can then
replace the functions with real C one at a time and re-run `make check`
after each. Every function is declared `void Name(void)`; fix the
signatures as you decompile them.

usage: asm_to_naked_c.py <in.s> <out.c> [--include header.h ...]
"""
import re
import sys
from pathlib import Path


def main() -> int:
    src, out = Path(sys.argv[1]), Path(sys.argv[2])
    includes = []
    if "--include" in sys.argv:
        includes = sys.argv[sys.argv.index("--include") + 1:]
    text = src.read_text()
    blocks = re.split(r"^\s*thumb_func_start\s+(\w+)\s*$", text, flags=re.M)
    funcs = []
    for name, body in zip(blocks[1::2], blocks[2::2]):
        lines = body.strip("\n").split("\n")
        # drop the "Name: @ 0x..." label line; agbcc emits its own
        assert re.match(rf"^{name}:", lines[0]), lines[0]
        addr = re.search(r"@ (0x[0-9A-Fa-f]+)", lines[0])
        body_lines = [l.rstrip() for l in lines[1:]]
        while body_lines and not body_lines[-1].strip():
            body_lines.pop()
        funcs.append((name, addr.group(1) if addr else "", body_lines))

    c = ['#include "globals.h"', '#include "macros.h"']
    c += [f'#include "{h}"' for h in includes]
    c.append("")
    for name, addr, body in funcs:
        c.append(f"// {addr}" if addr else "")
        c.append("NAKED_FUNCTION")
        c.append(f"void {name}(void)")
        c.append("{")
        c.append('    asm(" .syntax unified\\n\\')
        for l in body:
            l = l.replace("\\", "\\\\").replace('"', '\\"')
            c.append(f"{l}\\n\\")
        c.append('    .syntax divided\\n");')
        c.append("}")
        c.append("")
    out.write_text("\n".join(c))
    print(f"wrote {len(funcs)} naked functions to {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
