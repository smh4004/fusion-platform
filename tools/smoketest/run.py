#!/usr/bin/env python3
"""Run a smoke-test scenario against a built ROM in headless mGBA.

    python3 tools/smoketest/run.py [--rom mf_us.gba] [--elf mf_us.elf]
                                   [--out smoke_out] [scenario.txt]

Scenario files use {symbol} for addresses (looked up in the ELF, so the
test keeps working when things move), {out} for the output folder, and
`@REPEAT n` ... `@END` blocks. Screenshots are written as PNG.
Exit code 0 means every check passed.

Needs the harness built once: make -C tools/smoketest (requires libmgba-dev).
"""
import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent


def symbols(elf: str) -> dict:
    out = subprocess.run(["arm-none-eabi-nm", elf], capture_output=True, text=True, check=True).stdout
    return {p[2]: int(p[0], 16) for p in (l.split() for l in out.splitlines()) if len(p) == 3}


def expand(text: str, syms: dict, out: Path) -> str:
    lines, stack = [], [[]]
    counts = []
    for raw in text.splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        if line.startswith("@REPEAT"):
            counts.append(int(line.split()[1]))
            stack.append([])
            continue
        if line == "@END":
            block = stack.pop()
            stack[-1].extend(block * counts.pop())
            continue
        stack[-1].append(line)
    lines = stack[0]

    def sub(m):
        key = m.group(1)
        if key == "out":
            return str(out)
        if key not in syms:
            raise SystemExit(f"unknown symbol {{{key}}}")
        return f"0x{syms[key]:x}"

    return "\n".join(re.sub(r"\{(\w+)\}", sub, l) for l in lines) + "\n"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("scenario", nargs="?", default=str(HERE / "new_game.txt"))
    ap.add_argument("--rom", default="mf_us.gba")
    ap.add_argument("--elf", default="mf_us.elf")
    ap.add_argument("--out", default="smoke_out")
    args = ap.parse_args()

    harness = HERE / "smoke"
    if not harness.exists():
        raise SystemExit("build the harness first: make -C tools/smoketest")
    out = Path(args.out).resolve()
    out.mkdir(parents=True, exist_ok=True)
    script = expand(Path(args.scenario).read_text(), symbols(args.elf), out)
    with tempfile.NamedTemporaryFile("w", suffix=".txt", delete=False) as f:
        f.write(script)
    res = subprocess.run([str(harness), args.rom, f.name], capture_output=True, text=True)
    sys.stdout.write(res.stdout)
    sys.stderr.write(res.stderr)

    try:
        from PIL import Image
        for ppm in out.glob("*.ppm"):
            Image.open(ppm).save(ppm.with_suffix(".png"))
            ppm.unlink()
    except ImportError:
        pass

    print("PASS" if res.returncode == 0 else "FAIL")
    return res.returncode


if __name__ == "__main__":
    sys.exit(main())
