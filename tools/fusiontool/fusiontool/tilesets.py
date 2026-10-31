"""Render room tilesets so Tiled shows real pictures.

Reads the built ROM and its ELF (mf_us.gba / mf_us.elf) the way
RoomLoadTileset does (BG character base 0x4000): common tiles at VRAM 0x4800, the tileset's LZ77
graphics at 0x5800, its palette in rows 2-15 with the common palette over
rows 0-2, and a tile table of four tilemap entries per 16x16 metatile
(after a one-word header). Output is one PNG + Tiled .tsx per tileset
under assets/tilesets/, plus a labelled clipdata tileset.
"""
from __future__ import annotations

import struct
import subprocess
import xml.etree.ElementTree as ET
from pathlib import Path

from PIL import Image, ImageDraw

from . import lz77, pal

COLS = 16  # metatiles per row in the tileset image


def _symbols(elf: str) -> dict:
    out = subprocess.run(["arm-none-eabi-nm", elf], capture_output=True, text=True, check=True).stdout
    return {p[2]: int(p[0], 16) for p in (l.split() for l in out.splitlines()) if len(p) == 3}


class Rom:
    def __init__(self, rom="mf_us.gba", elf="mf_us.elf"):
        self.data = Path(rom).read_bytes()
        self.syms = _symbols(elf)

    def u32(self, addr):
        return struct.unpack_from("<I", self.data, addr & 0xFFFFFF)[0]

    def u16(self, addr):
        return struct.unpack_from("<H", self.data, addr & 0xFFFFFF)[0]

    def u8(self, addr):
        return self.data[addr & 0xFFFFFF]


def tileset_entries(rom: Rom):
    base = rom.syms["sTilesetEntries"]
    count = 98
    for i in range(count):
        a = base + i * 20
        yield i, rom.u32(a), rom.u32(a + 4), rom.u32(a + 8), rom.u32(a + 12)


def render_tileset(rom: Rom, gfx_ptr, pal_ptr, table_ptr, metatiles=None) -> Image.Image:
    vram = bytearray(0x10000)
    common = rom.syms["sCommonTilesGfx"]
    common_end = min(a for a in rom.syms.values() if a > common)
    vram[0x4800:0x4800 + (common_end - common)] = rom.data[common & 0xFFFFFF: common_end & 0xFFFFFF][: 0x10000 - 0x4800]
    gfx, _ = lz77.decompress(rom.data, gfx_ptr & 0xFFFFFF)
    vram[0x5800:0x5800 + len(gfx)] = gfx[: 0x10000 - 0x5800]

    colors = [(0, 0, 0)] * 256
    pdata = rom.data[pal_ptr & 0xFFFFFF:(pal_ptr & 0xFFFFFF) + 14 * 32]
    for i, w in enumerate(pal.decode(pdata)):
        colors[32 + i] = pal.to_rgb(w)
    cp = rom.syms["sCommonTilesPal"]
    for i, w in enumerate(pal.decode(rom.data[cp & 0xFFFFFF:(cp & 0xFFFFFF) + 3 * 32])):
        colors[i] = pal.to_rgb(w)

    table = table_ptr & 0xFFFFFF
    if metatiles is None:
        metatiles = 0x400
    img = Image.new("RGBA", (COLS * 16, -(-metatiles // COLS) * 16), (0, 0, 0, 0))
    px = img.load()
    for m in range(metatiles):
        mx, my = (m % COLS) * 16, (m // COLS) * 16
        for q in range(4):
            off = table + 2 + (m * 4 + q) * 2
            if off + 2 > len(rom.data):
                break
            e = struct.unpack_from("<H", rom.data, off)[0]
            tile, hf, vf, prow = e & 0x3FF, e >> 10 & 1, e >> 11 & 1, e >> 12
            qx, qy = mx + (q & 1) * 8, my + (q >> 1) * 8
            tb = 0x4000 + tile * 32  # BG character base is VRAM 0x4000
            for y in range(8):
                for x in range(8):
                    b = vram[tb + y * 4 + x // 2] if tb + 32 <= len(vram) else 0
                    c = (b >> 4) if x & 1 else (b & 0xF)
                    if c == 0:
                        continue
                    dx, dy = (7 - x) if hf else x, (7 - y) if vf else y
                    px[qx + dx, qy + dy] = colors[prow * 16 + c] + (255,)
    return img


def clipdata_image(count=256) -> Image.Image:
    img = Image.new("RGBA", (COLS * 16, (count // COLS) * 16), (0, 0, 0, 0))
    d = ImageDraw.Draw(img)
    for v in range(1, count):
        x, y = (v % COLS) * 16, (v // COLS) * 16
        hue = (v * 47) % 256
        d.rectangle([x, y, x + 15, y + 15], fill=(hue, 255 - hue, (v * 91) % 256, 140), outline=(255, 255, 255, 200))
        d.text((x + 1, y + 3), f"{v:02x}", fill=(255, 255, 255, 255))
    return img


def write_tsx(path: Path, image: Path, name: str, tiles: int, img_h: int):
    ts = ET.Element("tileset", version="1.10", name=name, tilewidth="16", tileheight="16",
                    tilecount=str(tiles), columns=str(COLS))
    ET.SubElement(ts, "image", source=image.name, width=str(COLS * 16), height=str(img_h))
    ET.indent(ts)
    ET.ElementTree(ts).write(path, encoding="UTF-8", xml_declaration=True)


def export_all(out_root: Path, rom: Rom | None = None) -> int:
    rom = rom or Rom()
    out = out_root / "tilesets"
    out.mkdir(parents=True, exist_ok=True)
    n = 0
    for i, gfx, palp, _bg, table in tileset_entries(rom):
        try:
            img = render_tileset(rom, gfx, palp, table)
        except Exception:
            continue
        png = out / f"tileset_{i}.png"
        img.save(png)
        write_tsx(out / f"tileset_{i}.tsx", png, f"tileset_{i}", COLS * (img.height // 16), img.height)
        n += 1
    clip = clipdata_image()
    clip.save(out / "clipdata.png")
    write_tsx(out / "clipdata.tsx", out / "clipdata.png", "clipdata", 256, clip.height)
    return n


def room_tilesets(rom: Rom | None = None) -> dict:
    """{data-file address of a room's BG1 layer: tileset number} for every room."""
    rom = rom or Rom()
    base = rom.syms["sAreaRoomEntryPointers"]
    result = {}
    for area in range(16):
        entries = rom.u32(base + area * 4)
        if not (0x08000000 <= entries < 0x08000000 + len(rom.data)):
            break
        for r in range(128):
            e = entries + r * 0x3C
            tileset = rom.u8(e)
            if tileset == 0xFF:
                break
            for ptr_off in (8, 12, 16):  # BG0, BG1, BG2
                p = rom.u32(e + ptr_off)
                if 0x08000000 <= p < 0x08000000 + len(rom.data):
                    result[p & 0xFFFFFF] = tileset
    return result
