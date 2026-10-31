"""4bpp GBA tile graphics <-> indexed PNG.

Tiles are 8x8 pixels, 32 bytes each, two pixels per byte (low nibble first).
The PNG stores palette *indices*; its colour table is only for display, so an
edited image imports back exactly as long as the artist keeps to the 16
indices. Tile count and layout width are stored in PNG text chunks so a
round trip never needs extra arguments.
"""
from __future__ import annotations

from PIL import Image

TILE_BYTES = 32
GRAYSCALE = [c for i in range(16) for c in (i * 17, i * 17, i * 17)]


def to_image(raw: bytes, width_tiles: int = 16, palette: list[tuple[int, int, int]] | None = None) -> Image.Image:
    if len(raw) % TILE_BYTES:
        raise ValueError(f"4bpp data length {len(raw):#x} is not a whole number of tiles")
    ntiles = len(raw) // TILE_BYTES
    width_tiles = max(1, min(width_tiles, ntiles))
    height_tiles = -(-ntiles // width_tiles)
    img = Image.new("P", (width_tiles * 8, height_tiles * 8), 0)
    px = img.load()
    for t in range(ntiles):
        tx, ty = (t % width_tiles) * 8, (t // width_tiles) * 8
        tile = raw[t * TILE_BYTES:(t + 1) * TILE_BYTES]
        for y in range(8):
            for x in range(0, 8, 2):
                b = tile[y * 4 + x // 2]
                px[tx + x, ty + y] = b & 0xF
                px[tx + x + 1, ty + y] = b >> 4
    flat = [c for rgb in palette for c in rgb] if palette else GRAYSCALE
    img.putpalette(flat + [0] * (768 - len(flat)))
    img.info["fusion_tiles"] = str(ntiles)
    return img


def from_image(img: Image.Image, ntiles: int | None = None) -> bytes:
    if img.mode != "P":
        raise ValueError("image must be palette-indexed (mode P); convert it in your editor first")
    if img.width % 8 or img.height % 8:
        raise ValueError("image size must be a multiple of 8 pixels")
    width_tiles = img.width // 8
    if ntiles is None:
        ntiles = int(img.info.get("fusion_tiles", width_tiles * (img.height // 8)))
    px = img.load()
    out = bytearray()
    for t in range(ntiles):
        tx, ty = (t % width_tiles) * 8, (t // width_tiles) * 8
        for y in range(8):
            for x in range(0, 8, 2):
                lo, hi = px[tx + x, ty + y], px[tx + x + 1, ty + y]
                if lo > 15 or hi > 15:
                    raise ValueError(f"pixel index above 15 near ({tx + x},{ty + y}); 4bpp allows 0-15 only")
                out.append(lo | (hi << 4))
    return bytes(out)
