#!/usr/bin/env python3
"""Show which functions in a C file's object differ from the base ROM.

Compares each function's bytes in mf_us.gba against the same address
range in mf_us_baserom.gba, using the ELF's function symbols for bounds.
With -v, prints a side-by-side disassembly of the first mismatching
function.

usage: funcdiff.py [-v] [name-prefix]
"""
import subprocess
import sys


def functions():
    out = subprocess.run(["arm-none-eabi-nm", "-n", "mf_us.elf"], capture_output=True, text=True).stdout
    rows = []
    for l in out.splitlines():
        p = l.split()
        if len(p) == 3 and p[0].startswith("080") and not p[2].startswith(("_", "$")):
            rows.append((int(p[0], 16), p[1], p[2]))
    funcs = []
    for i, (a, k, n) in enumerate(rows):
        if k not in "Tt":
            continue
        nxt = next((b for b, kk, _ in rows[i + 1:] if b > a and kk in "TtRrDd"), a + 4)
        funcs.append((n, a, nxt))
    return funcs


def disasm(path, start, end):
    out = subprocess.run(
        ["arm-none-eabi-objdump", "-D", "-bbinary", "-marm", "-Mforce-thumb",
         f"--start-address=0x{start & 0xFFFFFF:x}", f"--stop-address=0x{end & 0xFFFFFF:x}", path],
        capture_output=True, text=True).stdout
    return [l.split("\t", 2)[-1] for l in out.splitlines() if ":\t" in l]


def main() -> int:
    verbose = "-v" in sys.argv
    prefix = next((a for a in sys.argv[1:] if not a.startswith("-")), "")
    base = open("mf_us_baserom.gba", "rb").read()
    new = open("mf_us.gba", "rb").read()
    bad = []
    for n, a, e in functions():
        if not n.startswith(prefix):
            continue
        lo, hi = a & 0xFFFFFF, e & 0xFFFFFF
        if base[lo:hi] != new[lo:hi]:
            bad.append((n, a, e))
            print(f"DIFF {n} @ {a:#x} ({hi - lo:#x} bytes)")
    if not bad:
        print("all matching")
    elif verbose:
        n, a, e = bad[0]
        old, cur = disasm("mf_us_baserom.gba", a, e), disasm("mf_us.gba", a, e)
        for i in range(max(len(old), len(cur))):
            l, r = (old[i] if i < len(old) else ""), (cur[i] if i < len(cur) else "")
            mark = "  " if l == r else "!!"
            print(f"{mark} {l:<40} {r}")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
