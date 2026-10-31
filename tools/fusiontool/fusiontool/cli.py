"""fusiontool: turn the decomp's raw ROM data into editable assets and back.

    python3 -m fusiontool extract   # data/  -> assets/   (PNG, JASC palettes)
    python3 -m fusiontool build     # assets/ -> data/    (only files that changed)
    python3 -m fusiontool check     # prove every asset round-trips byte-for-byte

Run from the repository root after `python3 tools/extractor.py`.
"""
from __future__ import annotations

import argparse
import sys
import tempfile
from pathlib import Path

from . import assets, pal


def _data_files(data_root: Path):
    for p in sorted(data_root.rglob("*")):
        if p.is_file() and assets.kind_of(p)[1] is not None:
            yield p


def _guess_palette(data_path: Path):
    """Preview colours: a .pal with the same stem, else one in the same folder."""
    name = data_path.name.split(".")[0]
    same = data_path.with_name(name + ".pal")
    candidates = [same] if same.exists() else sorted(data_path.parent.glob("*.pal"))
    for c in candidates:
        raw = c.read_bytes()
        if len(raw) >= 32:
            return pal.row(raw, 0)
    return None


def cmd_extract(args) -> int:
    n = 0
    for p in _data_files(args.data):
        out = assets.asset_path(p, args.data, args.assets)
        if out.exists() and not args.force:
            continue
        palette = _guess_palette(p) if out.suffix == ".png" else None
        assets.export(p, out, palette, args.width)
        n += 1
    print(f"extracted {n} assets into {args.assets}/")
    return 0


def cmd_build(args) -> int:
    changed = 0
    for p in _data_files(args.data):
        a = assets.asset_path(p, args.data, args.assets)
        if not a.exists():
            continue
        new = assets.build(a, p)
        if new != p.read_bytes():
            p.write_bytes(new)
            changed += 1
            print(f"  updated {p}")
    print(f"{changed} data file(s) updated from {args.assets}/")
    return 0


def cmd_check(args) -> int:
    ok = bad = 0
    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        for p in _data_files(args.data):
            a = assets.asset_path(p, args.data, tmp)
            try:
                assets.export(p, a)
                same = assets.build(a, p) == p.read_bytes()
            except Exception as ex:  # report and keep going
                same = False
                print(f"  ERROR {p}: {ex}")
            if same:
                ok += 1
            else:
                bad += 1
                print(f"  MISMATCH {p}")
    print(f"{ok} assets round-trip exactly, {bad} do not")
    return 1 if bad else 0


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(prog="fusiontool", description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--data", type=Path, default=Path("data"))
    ap.add_argument("--assets", type=Path, default=Path("assets"))
    sub = ap.add_subparsers(dest="cmd", required=True)
    e = sub.add_parser("extract", help="write editable assets from data/")
    e.add_argument("--force", action="store_true", help="overwrite assets that already exist")
    e.add_argument("--width", type=int, default=16, help="tiles per row in exported PNGs")
    sub.add_parser("build", help="write data/ files from edited assets")
    sub.add_parser("check", help="verify every supported file round-trips")
    args = ap.parse_args(argv)
    return {"extract": cmd_extract, "build": cmd_build, "check": cmd_check}[args.cmd](args)


if __name__ == "__main__":
    sys.exit(main())
