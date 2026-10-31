"""GBA BGR555 palettes <-> JASC-PAL text (readable by most pixel-art tools).

Colours are written as 8-bit RGB scaled up from 5-bit. The top bit of a GBA
colour is ignored by the hardware but set in some ROM data; when it is, the
raw word is kept in a fourth column so untouched files round-trip exactly.
"""
from __future__ import annotations


def decode(raw: bytes) -> list[int]:
    if len(raw) % 2:
        raise ValueError("palette length must be even")
    return [int.from_bytes(raw[i:i + 2], "little") for i in range(0, len(raw), 2)]


def encode(words: list[int]) -> bytes:
    return b"".join(w.to_bytes(2, "little") for w in words)


def to_rgb(word: int) -> tuple[int, int, int]:
    r, g, b = word & 31, (word >> 5) & 31, (word >> 10) & 31
    return (r << 3 | r >> 2, g << 3 | g >> 2, b << 3 | b >> 2)


def from_rgb(r: int, g: int, b: int) -> int:
    return (r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10)


def to_jasc(raw: bytes) -> str:
    words = decode(raw)
    lines = ["JASC-PAL", "0100", str(len(words))]
    for w in words:
        r, g, b = to_rgb(w)
        line = f"{r} {g} {b}"
        if w & 0x8000:
            line += f" {w:#06x}"
        lines.append(line)
    return "\n".join(lines) + "\n"


def from_jasc(text: str) -> bytes:
    lines = [l.strip() for l in text.splitlines() if l.strip()]
    if lines[:2] != ["JASC-PAL", "0100"]:
        raise ValueError("not a JASC-PAL file")
    count = int(lines[2])
    words = []
    for line in lines[3:3 + count]:
        parts = line.split()
        r, g, b = (int(p) for p in parts[:3])
        w = from_rgb(r, g, b)
        if len(parts) > 3:
            raw = int(parts[3], 16)
            # keep the stored word only if the visible colour was not edited
            if raw & 0x7FFF == w:
                w = raw
        words.append(w)
    return encode(words)


def row(raw: bytes, index: int) -> list[tuple[int, int, int]]:
    """The 16 colours of palette row `index`, for previewing graphics."""
    words = decode(raw)[index * 16:(index + 1) * 16]
    return [to_rgb(w) for w in words]
