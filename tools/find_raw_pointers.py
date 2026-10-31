#!/usr/bin/env python3
"""List every pointer that would break if the ROM were shifted.

Builds a copy of the ROM with PAD bytes inserted before one linker.ld
entry, then compares it word-by-word with the matching build. Any word that
pointed past the insertion point in the original must have grown by PAD in
the shifted build; if it didn't, it's a hard-coded address the linker can't
fix. Each hit is reported with the symbol that contains it.

    python3 tools/find_raw_pointers.py ["src/data/generic_data.o(.rodata)"] [--pad 0x100]

Run from the repository root on a tree whose `make check` passes.
Only words that land exactly on a symbol are counted, so pointers into the
middle of unlabelled blobs are missed; label the blob first to see them.
Writes the full list to smoke_out/raw_pointers.txt.
"""
import argparse
import bisect
import collections
import shutil
import struct
import subprocess
from pathlib import Path


def nm(elf):
    out = subprocess.run(["arm-none-eabi-nm", "-n", elf], capture_output=True, text=True, check=True).stdout
    rows = []
    for l in out.splitlines():
        p = l.split()
        if len(p) == 3 and p[0].startswith("08") and not p[2].startswith(("$", "_0")):
            rows.append((int(p[0], 16), p[2]))
    return rows


def build():
    subprocess.run(["make", "-s", "-j8"], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("point", nargs="?", default="src/data/generic_data.o(.rodata)")
    ap.add_argument("--pad", default="0x100")
    ap.add_argument("--any", action="store_true", help="count pointers to any address past the cut, not only symbol starts (noisy for large regions)")
    args = ap.parse_args()
    pad = int(args.pad, 0)

    build()
    base = Path("mf_us.gba").read_bytes()
    base_syms = nm("mf_us.elf")
    shutil.copy("mf_us.elf", "smoke_out/base.elf")

    ld = Path("linker.ld")
    orig = ld.read_text()
    try:
        lines = orig.split("\n")
        idx = next(i for i, l in enumerate(lines) if l.strip() == args.point + ";")
        indent = lines[idx][: len(lines[idx]) - len(lines[idx].lstrip())]
        lines.insert(idx, f"{indent}. = . + {pad:#x};")
        ld.write_text("\n".join(lines))
        build()
        shifted = Path("mf_us.gba").read_bytes()
        shifted_syms = nm("mf_us.elf")
    finally:
        ld.write_text(orig)
        Path("linker.ld").touch()
        build()

    # insertion address = first uniquely-named symbol that moved by exactly pad
    def unique(rows):
        c = collections.Counter(n for _, n in rows)
        return {n: a for a, n in rows if c[n] == 1}
    ub, us = unique(base_syms), unique(shifted_syms)
    cut = min(a for n, a in ub.items() if n in us and us[n] - a == pad)
    cut_off = cut & 0xFFFFFF
    end = len(base.rstrip(b"\xff"))

    addrs = [a for a, _ in base_syms]
    starts = {a for a, n in base_syms if not n.startswith("sBlob_")}

    def owner(addr):
        i = bisect.bisect_right(addrs, addr) - 1
        return base_syms[i][1] if i >= 0 else "?"

    hits = []
    for off in range(0, end - 3, 2):  # halfword steps: literal pools are word aligned, data may not be
        if off % 4 and off < cut_off:
            continue
        w = struct.unpack_from("<I", base, off)[0]
        if not (cut <= w < 0x08000000 + end):
            continue
        new_off = off + pad if off >= cut_off else off
        if new_off + 4 > len(shifted):
            continue
        w2 = struct.unpack_from("<I", shifted, new_off)[0]
        if w2 == w + pad:
            continue  # linker-relocated: fine
        # only count words that point exactly at a known symbol (Thumb bit
        # allowed); anything else that didn't move is most likely plain data
        if w2 == w and (args.any or (w in starts) or ((w & ~1) in starts and w & 1)):
            hits.append((0x08000000 + off, w, owner(0x08000000 + off)))

    by_owner = collections.Counter(o for _, _, o in hits)
    out = Path("smoke_out/raw_pointers.txt")
    out.parent.mkdir(exist_ok=True)
    with out.open("w") as f:
        for at, w, o in hits:
            f.write(f"{at:#010x} -> {w:#010x}  in {o}  (target in {owner(w & ~1)})\n")
    print(f"insertion point {cut:#x}; {len(hits)} unshiftable pointers in {len(by_owner)} symbols")
    for o, n in by_owner.most_common(25):
        print(f"  {n:5d}  {o}")
    print(f"full list: {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
