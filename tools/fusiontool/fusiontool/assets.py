"""Map extracted ROM data files (data/) to editable assets (assets/) and back.

    data/foo.gfx      <->  assets/foo.gfx.png   (4bpp tiles, indexed PNG)
    data/foo.gfx.lz   <->  assets/foo.gfx.png   (same, LZ77 recompressed on import)
    data/foo.pal      <->  assets/foo.pal       (JASC-PAL text)

Everything Nintendo made stays local: data/ and assets/ are both git-ignored.
Import of an untouched asset reproduces the original bytes exactly, including
any padding after a compressed stream, so the ROM still matches until you
actually change something.
"""
from __future__ import annotations

from pathlib import Path

from PIL import Image

from . import gfx, lz77, pal

KINDS = {
    ".gfx": ("gfx", False),
    ".gfx.lz": ("gfx", True),
    ".pal": ("pal", False),
}


def kind_of(data_path: Path):
    name = data_path.name
    for suffix in sorted(KINDS, key=len, reverse=True):
        if name.endswith(suffix):
            return suffix, KINDS[suffix]
    return None, None


def asset_path(data_path: Path, data_root: Path, asset_root: Path) -> Path | None:
    suffix, kind = kind_of(data_path)
    if kind is None:
        return None
    rel = data_path.relative_to(data_root)
    stem = rel.name[: -len(suffix)]
    ext = ".gfx.png" if kind[0] == "gfx" else ".pal"
    return asset_root / rel.parent / (stem + ext)


def _split_tail(raw: bytes, used: int) -> bytes:
    """Bytes after the compressed stream that a plain 4-byte pad would not recreate."""
    padded = (used + 3) & ~3
    tail = raw[used:]
    if tail == bytes(padded - used):
        return b""
    return tail


def export(data_path: Path, out_path: Path, palette=None, width_tiles: int = 16) -> None:
    raw = data_path.read_bytes()
    suffix, (kind, compressed) = kind_of(data_path)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    if kind == "pal":
        out_path.write_text(pal.to_jasc(raw))
        return
    tail = b""
    body = raw
    if compressed:
        body, used = lz77.decompress(raw)
        tail = _split_tail(raw, used)
    extra = len(body) % gfx.TILE_BYTES
    img = gfx.to_image(body[: len(body) - extra], width_tiles, palette)
    img.info["fusion_compression"] = "lz77" if compressed else "none"
    img.info["fusion_tail"] = (body[len(body) - extra:] if extra else b"").hex()
    img.info["fusion_lz_tail"] = tail.hex()
    _save(img, out_path)


def _save(img: Image.Image, path: Path) -> None:
    from PIL import PngImagePlugin

    meta = PngImagePlugin.PngInfo()
    for key in ("fusion_tiles", "fusion_compression", "fusion_tail", "fusion_lz_tail"):
        meta.add_text(key, img.info.get(key, ""))
    meta.add_text("fusion_format", "4bpp")
    img.save(path, pnginfo=meta)


def build(asset: Path, data_path: Path) -> bytes:
    """Bytes that `asset` should produce for `data_path`."""
    suffix, (kind, compressed) = kind_of(data_path)
    if kind == "pal":
        return pal.from_jasc(asset.read_text())
    img = Image.open(asset)
    img.load()
    body = gfx.from_image(img) + bytes.fromhex(img.info.get("fusion_tail", ""))
    if not compressed:
        return body
    enc = lz77.compress(body, min_dist=lz77.FUSION_MIN_DIST)
    lz_tail = bytes.fromhex(img.info.get("fusion_lz_tail", ""))
    if lz_tail:
        # original layout: stream, then the bytes that followed it in the ROM
        return enc[:_stream_len(enc)] + lz_tail
    return enc


def _stream_len(enc: bytes) -> int:
    _, used = lz77.decompress(enc)
    return used
