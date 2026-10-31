#!/usr/bin/env python3
"""Compile each given C file and add declarations for undeclared names.

For every "`name' undeclared" error: include the header under include/ that
declares it if there is one, otherwise add `extern const u8 name[];`
after the file's includes. Repeats until the file compiles or nothing
changes.

usage: fix_undeclared.py <file.c> [...]
"""
import re
import subprocess
import sys
from pathlib import Path

HEADERS = {h: h.read_text() for h in Path("include").rglob("*.h")}


def errors(c):
    s = c.with_suffix(".s")
    s.unlink(missing_ok=True)
    r = subprocess.run(["make", "-s", str(s)], capture_output=True, text=True)
    return sorted(set(re.findall(r"`(\w+)' undeclared", r.stderr)))


def header_for(name):
    decl = re.compile(rf"^(?:extern\s+)?[^\n#/]*\b{re.escape(name)}\b\s*(\(|\[|;)", re.M)
    for h, t in HEADERS.items():
        if decl.search(t):
            return str(h.relative_to("include"))
    return None


def main() -> int:
    for fn in sys.argv[1:]:
        c = Path(fn)
        for _ in range(5):
            names = errors(c)
            if not names:
                break
            text = c.read_text()
            incs, externs = set(), []
            for n in names:
                h = header_for(n)
                if h and f'#include "{h}"' not in text:
                    incs.add(h)
                elif not h:
                    externs.append(n)
            if not incs and not externs:
                print(f"{fn}: cannot resolve {names}")
                break
            ends = [m.end() for m in re.finditer(r'^#include "[^"]+"\n', text, re.M)]
            at = ends[-1] if ends else 0
            block = "".join(f'#include "{h}"\n' for h in sorted(incs))
            block += "".join(f"extern const u8 {n}[];\n" for n in sorted(externs))
            c.write_text(text[:at] + block + text[at:])
            print(f"{fn}: +{len(incs)} includes, +{len(externs)} externs")
    return 0


if __name__ == "__main__":
    sys.exit(main())
