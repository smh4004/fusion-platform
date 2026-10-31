#!/usr/bin/env python3
"""Replace hard-coded ROM addresses in C with the symbols that live there.

    [PSPRITE_HORNOAD] = (Func_T)0x801d775,     ->  [PSPRITE_HORNOAD] = Hornoad,
    (const u32*)0x0864e470                     ->  sTitleIntroCollisionWarningBgGfx0

A literal is only rewritten when the built ELF (run `make` first) has a
global symbol starting exactly at that address (the Thumb bit is ignored
for code). Static symbols are skipped; make them global first if needed.
The cast is dropped when the symbol already has a compatible type, i.e. for
functions in a function-pointer table and for arrays; otherwise it is kept
around the symbol. Blobs (sBlob_*) are never used as targets: those need
real labels first. The ROM must still match afterwards.

usage: symbolize_rom_literals.py <file.c> [...]  [--dry-run]
"""
import re
import subprocess
import sys
from pathlib import Path

LIT = re.compile(r"\((?P<cast>[^()]*?)\)\s*0x0?(?P<addr>8[0-9a-fA-F]{6})\b")


def load_symbols(elf: str) -> dict:
    out = subprocess.run(["arm-none-eabi-nm", "-n", elf], capture_output=True, text=True, check=True).stdout
    syms = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) != 3 or not parts[0].startswith("08"):
            continue
        addr, kind, name = int(parts[0], 16), parts[1], parts[2]
        if name.startswith(("sBlob_", "_0", "$")) or name.endswith("_end"):
            continue
        # keep the first (usually most meaningful) name at an address
        syms.setdefault(addr, (name, kind))
    return syms


def main() -> int:
    dry = "--dry-run" in sys.argv
    files = [a for a in sys.argv[1:] if not a.startswith("--")]
    syms = load_symbols("mf_us.elf")
    total = 0
    for f in files:
        p = Path(f)
        text = p.read_text()
        used = []

        def sub(m):
            addr = int(m.group("addr"), 16) | 0x08000000 if len(m.group("addr")) == 7 else int(m.group("addr"), 16)
            addr = 0x08000000 | (addr & 0xFFFFFF)
            cast = m.group("cast").strip()
            is_func = "Func" in cast or "(*" in cast
            hit = syms.get(addr & ~1 if is_func else addr)
            if hit is None:
                return m.group(0)
            name, kind = hit
            used.append(name)
            if kind.islower():  # file-local (static) symbol: not reachable from here
                used.pop()
                return m.group(0)
            if is_func and kind == "T":
                return name
            if kind in "RD":
                return f"({cast}){name}"
            used.pop()
            return m.group(0)

        new = LIT.sub(sub, text)
        print(f"{f}: {len(used)} literal(s) -> symbols")
        total += len(used)
        if not dry and new != text:
            p.write_text(new)
    print(f"total {total}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
