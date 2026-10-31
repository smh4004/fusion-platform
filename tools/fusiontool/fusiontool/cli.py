"""fusiontool: turn the decomp's raw ROM data into editable assets and back.

    python3 -m fusiontool extract   # data/  -> assets/   (PNG, JASC palettes, Tiled rooms)
    python3 -m fusiontool build     # assets/ -> data/    (only files that changed)
    python3 -m fusiontool check     # prove every asset round-trips byte-for-byte

Run from the repository root after `python3 tools/extractor.py`.
"""
from __future__ import annotations

import argparse
import sys
import tempfile
from pathlib import Path

from . import assets, pal, rooms


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
    try:
        from . import tilesets
        rom = tilesets.Rom()
        print(f"rendered {tilesets.export_all(args.assets, rom)} tilesets")
        by_addr = tilesets.room_tilesets(rom)
    except (FileNotFoundError, OSError, KeyError) as ex:
        print(f"  (tileset previews skipped: {ex}; run make first)")
        by_addr = {}
    db = {e["path"]: int(e["addr"]["us"], 16) for e in __import__("json").load(open("database.json")) if "us" in e["addr"]}
    for key, layers in rooms.find_rooms().items():
        out = args.assets / "rooms" / f"{key}.tmx"
        if out.exists() and not args.force:
            continue
        tileset = None
        for layer in ("bg1", "bg2", "bg0"):
            if layer in layers:
                addr = db.get(str(layers[layer][0])[len("data/"):])
                if addr is not None and (addr - 2) in by_addr:
                    tileset = by_addr[addr - 2]
                    break
        rooms.export_room(key, layers, out, tileset)
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
    all_rooms = rooms.find_rooms()
    for tmx in sorted((args.assets / "rooms").rglob("*.tmx")) if (args.assets / "rooms").exists() else []:
        key = str(tmx.relative_to(args.assets / "rooms"))[: -len(".tmx")]
        if key not in all_rooms:
            continue
        for layer, data in rooms.build_room(tmx).items():
            path = all_rooms[key][layer][0]
            if data != path.read_bytes():
                path.write_bytes(data)
                changed += 1
                print(f"  updated {path}")
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
        for key, layers in rooms.find_rooms().items():
            t = tmp / "rooms" / f"{key}.tmx"
            try:
                rooms.export_room(key, layers, t)
                built = rooms.build_room(t)
                same = all(built[l] == p.read_bytes() for l, (p, _, _) in layers.items())
            except Exception as ex:
                same = False
                print(f"  ERROR room {key}: {ex}")
            if same:
                ok += 1
            else:
                bad += 1
                print(f"  MISMATCH room {key}")
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
