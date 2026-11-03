#!/usr/bin/env python3
"""Write a make dependency file for one C or assembly source.

Lists every header it reaches through #include "..." (searched in the
source's own folder, then the -I folders) and every file pulled in with
INCBIN_*("..."), so editing a header or an asset in data/ rebuilds the
objects that use it. For assembly sources it follows `.include "..."`
(searched relative to the repository root, as the assembler does) and
`.incbin "..."` the same way, including `.incbin` inside inline asm() in C.

usage: scandeps.py <source.c|source.s> <target> <out.d> [-I dir ...]
"""
import re
import sys
from pathlib import Path

INCLUDE = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)
INCBIN = re.compile(r'INCBIN_\w+\(\s*"([^"]+)"')
ASM_INCLUDE = re.compile(r'^\s*\.include\s+"([^"]+)"', re.M)
ASM_INCBIN = re.compile(r'\.incbin\s+\\?"([^"\\]+)\\?"')


def main() -> int:
    src, target, out = sys.argv[1:4]
    inc_dirs = [Path(a[2:]) for a in sys.argv[4:] if a.startswith("-I")]
    seen, deps, stack = set(), [], [Path(src)]
    while stack:
        f = stack.pop()
        try:
            text = f.read_text(errors="replace")
        except OSError:
            continue
        for path in INCBIN.findall(text) + ASM_INCBIN.findall(text):
            if path not in seen:
                seen.add(path)
                deps.append(path)
        for name in ASM_INCLUDE.findall(text):
            cand = Path(name)
            if cand.is_file() and str(cand) not in seen:
                seen.add(str(cand))
                deps.append(str(cand))
                stack.append(cand)
        for name in INCLUDE.findall(text):
            for base in [f.parent, *inc_dirs]:
                cand = base / name
                if cand.is_file():
                    key = str(cand)
                    if key not in seen:
                        seen.add(key)
                        deps.append(key)
                        stack.append(cand)
                    break
    with open(out, "w") as fh:
        fh.write(f"{target} {out}: {' '.join(deps)}\n")
        # empty rules so a deleted header or asset doesn't break the build
        for d in deps:
            fh.write(f"{d}:\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
