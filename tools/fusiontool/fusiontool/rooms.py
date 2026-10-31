"""Rooms <-> Tiled maps.

Each room's layers (clipdata, BG0, BG1, BG2) live in data/rooms/<area>/
<room>_<layer>.rle, and their width/height are the two bytes in front of
the INCBIN in src/data/rooms/<area>/<room>.c. A room becomes one Tiled map
(assets/rooms/<area>/<room>.tmx) with a CSV layer per room layer.

BG layers show the room's tileset (rendered by tilesets.py into
assets/tilesets/tileset_<n>.png/.tsx) and the clipdata layer shows a
labelled collision tileset. A cell holds the game's 16-bit value plus the
layer's first tile ID (stored in the layer's fusion_gid_base property), so
a round trip is exact. Room size is fixed by the C source for now.
"""
from __future__ import annotations

import re
import xml.etree.ElementTree as ET
from pathlib import Path

from . import rle

LAYER_RE = re.compile(r'\{\s*(\d+),[^\n]*\n\s*(\d+),[^\n]*\n\s*_INCBIN_U8\("(data/rooms/[^"]+?_(bg0|bg1|bg2|clipdata)\.rle)"\)')
LAYER_ORDER = ["clipdata", "bg0", "bg1", "bg2"]


def find_rooms(src_root: Path = Path("src/data/rooms")) -> dict:
    """{room_key: {layer: (data_path, width, height)}} from the room C files."""
    rooms: dict = {}
    for c in sorted(src_root.rglob("*.c")):
        for m in LAYER_RE.finditer(c.read_text()):
            w, h, path, layer = int(m.group(1)), int(m.group(2)), m.group(3), m.group(4)
            key = path[len("data/rooms/"): -len(f"_{layer}.rle")]
            rooms.setdefault(key, {})[layer] = (Path(path), w, h)
    return rooms


BG_TILES = 1024   # metatiles in a rendered room tileset
CLIP_FIRST_GID = 1 + BG_TILES


def export_room(key: str, layers: dict, out: Path, tileset: int | None = None) -> None:
    w, h = next(iter(layers.values()))[1:]
    m = ET.Element("map", version="1.10", orientation="orthogonal", renderorder="right-down",
                   width=str(w), height=str(h), tilewidth="16", tileheight="16", infinite="0",
                   nextlayerid=str(len(layers) + 1), nextobjectid="1")
    props = ET.SubElement(m, "properties")
    ET.SubElement(props, "property", name="fusion_room", value=key)
    depth = len(Path(key).parts)  # rooms/<area>/<room>.tmx -> ../../tilesets
    up = "../" * depth
    if tileset is not None:
        ET.SubElement(m, "tileset", firstgid="1", source=f"{up}tilesets/tileset_{tileset}.tsx")
    ET.SubElement(m, "tileset", firstgid=str(CLIP_FIRST_GID), source=f"{up}tilesets/clipdata.tsx")
    for lid, layer in enumerate([l for l in LAYER_ORDER if l in layers], start=1):
        path, lw, lh = layers[layer]
        raw = path.read_bytes()
        tiles, used = rle.decode(raw, lw, lh)
        le = ET.SubElement(m, "layer", id=str(lid), name=layer, width=str(lw), height=str(lh))
        base = CLIP_FIRST_GID if layer == "clipdata" else 1
        lp = ET.SubElement(le, "properties")
        ET.SubElement(lp, "property", name="fusion_tail", value=raw[used:].hex())
        ET.SubElement(lp, "property", name="fusion_gid_base", type="int", value=str(base))
        rows = [",".join(str(t + base) for t in tiles[y * lw:(y + 1) * lw]) for y in range(lh)]
        ET.SubElement(le, "data", encoding="csv").text = "\n" + ",\n".join(rows) + "\n"
    # Tiled wants tilesets before layers
    for ts in m.findall("tileset"):
        m.remove(ts)
        m.insert(1, ts)
    out.parent.mkdir(parents=True, exist_ok=True)
    ET.indent(m)
    ET.ElementTree(m).write(out, encoding="UTF-8", xml_declaration=True)


def build_room(tmx: Path) -> dict:
    """{layer: bytes} as they belong in data/rooms/..."""
    m = ET.parse(tmx).getroot()
    out = {}
    for le in m.findall("layer"):
        name = le.get("name")
        w, h = int(le.get("width")), int(le.get("height"))
        vals = [int(v) for v in le.find("data").text.replace("\n", "").split(",") if v.strip()]
        if len(vals) != w * h:
            raise ValueError(f"{tmx} layer {name}: expected {w * h} tiles, found {len(vals)}")
        tail, base = "", 1
        for p in le.iter("property"):
            if p.get("name") == "fusion_tail":
                tail = p.get("value")
            if p.get("name") == "fusion_gid_base":
                base = int(p.get("value"))
        tiles = [max(v - base, 0) for v in vals]
        out[name] = rle.encode(tiles) + bytes.fromhex(tail)
    return out
