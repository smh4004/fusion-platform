#!/usr/bin/env python3
"""Find the latest linker.ld entry before which inserting padding breaks a
scenario (default: boot to file select).

Assumes padding late in the ROM is harmless and padding early breaks it, and
binary-searches the ROM objects in between. Restores linker.ld afterwards.

    python3 tools/smoketest/bisect_shift.py [--pad 0x100] [--scenario boot.txt] [--first N]
"""
import argparse
import re
import subprocess
from pathlib import Path

HERE = Path(__file__).resolve().parent


def entries(text):
    lines = text.split("\n")
    start = next(i for i, l in enumerate(lines) if l.strip().startswith("rom :"))
    return [(i, l.strip()[:-1]) for i, l in enumerate(lines)
            if i > start and re.match(r"^\s+\S+\.o\(\.(rodata|text|data)\);$", l)]


def try_point(orig, line_no, pad, scenario):
    lines = orig.split("\n")
    indent = lines[line_no][: len(lines[line_no]) - len(lines[line_no].lstrip())]
    lines.insert(line_no, f"{indent}. = . + {pad};")
    Path("linker.ld").write_text("\n".join(lines))
    if subprocess.run(["make", "-s", "-j8"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL).returncode:
        return None
    r = subprocess.run(["python3", str(HERE / "run.py"), str(scenario), "--out", "smoke_out/bisect"],
                       capture_output=True, text=True)
    return r.returncode == 0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--pad", default="0x100")
    ap.add_argument("--scenario", default=str(HERE / "boot.txt"))
    ap.add_argument("--first", type=int, default=0, help="index of the first entry to consider")
    args = ap.parse_args()

    orig = Path("linker.ld").read_text()
    ents = entries(orig)
    lo, hi = args.first, len(ents) - 1
    try:
        if not try_point(orig, ents[hi][0], args.pad, args.scenario):
            print(f"even padding before the last entry ({ents[hi][1]}) breaks the scenario")
            return 1
        # invariant: padding before ents[hi] passes; find first index that passes
        while lo < hi:
            mid = (lo + hi) // 2
            ok = try_point(orig, ents[mid][0], args.pad, args.scenario)
            print(f"  {'pass' if ok else 'FAIL'}  before [{mid}] {ents[mid][1]}", flush=True)
            if ok:
                hi = mid
            else:
                lo = mid + 1
        print(f"padding before [{lo}] {ents[lo][1]} passes;")
        if lo > 0:
            print(f"padding before [{lo - 1}] {ents[lo - 1][1]} breaks it.")
            print(f"So something moved by the latter is referenced by a fixed address.")
    finally:
        Path("linker.ld").write_text(orig)
        Path("linker.ld").touch()
        subprocess.run(["make", "-s", "-j8"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
