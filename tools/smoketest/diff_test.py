#!/usr/bin/env python3
"""Differential play test: same inputs on the matching ROM and on a shifted
ROM, screenshots compared pixel for pixel.

The game is deterministic, so with identical input every frame should look
the same. A pointer that didn't relocate shows up as a difference in
whatever part of the game the run reached.

    python3 tools/smoketest/diff_test.py [--pad 0x100] [--point "src/agbmain.o(.text)"]
                                         [--frames 30000] [--seed 1]

After the new-game intro, Samus is driven by seeded random input (walking,
jumping, shooting, morphing) with a screenshot every 300 frames.
"""
import argparse
import random
import shutil
import subprocess
from pathlib import Path

from PIL import Image, ImageChops

HERE = Path(__file__).resolve().parent


def scenario(frames, seed):
    base = (HERE / "new_game.txt").read_text()
    rng = random.Random(seed)
    moves = ["RIGHT", "LEFT", "RIGHT+A", "LEFT+A", "A", "B", "RIGHT+B", "LEFT+B", "DOWN", "UP", "UP+B", "R+B", "DOWN+DOWN"]
    out = [base, "# random play"]
    t, shot = 0, 0
    while t < frames:
        n = rng.randint(6, 45)
        out.append(f"hold {rng.choice(moves).replace('DOWN+DOWN', 'DOWN')} {n}")
        t += n
        if t // 300 > shot:
            shot = t // 300
            out.append(f"shot {{out}}/r{shot:04d}.ppm")
    return "\n".join(out) + "\n"


def run(rom, elf, script, out):
    if out.exists():
        shutil.rmtree(out)
    r = subprocess.run(["python3", str(HERE / "run.py"), str(script), "--rom", rom, "--elf", elf, "--out", str(out)],
                       capture_output=True, text=True)
    return r.returncode == 0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--pad", default="0x100")
    ap.add_argument("--point", default="src/agbmain.o(.text)")
    ap.add_argument("--frames", type=int, default=30000)
    ap.add_argument("--seed", type=int, default=1)
    args = ap.parse_args()

    out = Path("smoke_out")
    out.mkdir(exist_ok=True)
    script = out / "diff_scenario.txt"
    script.write_text(scenario(args.frames, args.seed))

    subprocess.run(["make", "-s", "-j8"], check=True, stdout=subprocess.DEVNULL)
    shutil.copy("mf_us.gba", out / "base.gba")
    shutil.copy("mf_us.elf", out / "base.elf")
    base_ok = run(str(out / "base.gba"), str(out / "base.elf"), script, out / "diff_base")

    ld = Path("linker.ld")
    orig = ld.read_text()
    try:
        lines = orig.split("\n")
        i = next(i for i, l in enumerate(lines) if l.strip() == args.point + ";")
        indent = lines[i][: len(lines[i]) - len(lines[i].lstrip())]
        lines.insert(i, f"{indent}. = . + {args.pad};")
        ld.write_text("\n".join(lines))
        subprocess.run(["make", "-s", "-j8"], check=True, stdout=subprocess.DEVNULL)
        shutil.copy("mf_us.gba", out / "shifted.gba")
        shutil.copy("mf_us.elf", out / "shifted.elf")
    finally:
        ld.write_text(orig)
        ld.touch()
        subprocess.run(["make", "-s", "-j8"], stdout=subprocess.DEVNULL)
    shifted_ok = run(str(out / "shifted.gba"), str(out / "shifted.elf"), script, out / "diff_shifted")

    shots = sorted(p.name for p in (out / "diff_base").glob("*.png"))
    diffs = []
    for name in shots:
        a = Image.open(out / "diff_base" / name).convert("RGB")
        b_path = out / "diff_shifted" / name
        if not b_path.exists():
            diffs.append(name)
            continue
        b = Image.open(b_path).convert("RGB")
        if ImageChops.difference(a, b).getbbox():
            diffs.append(name)
    print(f"base checks {'PASS' if base_ok else 'FAIL'}, shifted checks {'PASS' if shifted_ok else 'FAIL'}")
    print(f"{len(shots) - len(diffs)}/{len(shots)} screenshots identical")
    if diffs:
        print("first differing:", ", ".join(diffs[:5]))
    return 0 if (base_ok and shifted_ok and not diffs) else 1


if __name__ == "__main__":
    raise SystemExit(main())
