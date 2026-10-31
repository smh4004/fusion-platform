"""Room layer RLE codec (BG0/BG1/BG2 tilemaps and clipdata).

The C source stores width and height as two bytes in front of the
INCBIN, so the .rle file itself is just the body: two passes over the u16 tiles,
first the low bytes, then the high bytes. Each pass starts with a mode
byte: 1 = counts are 8-bit (0x80 flag, 7-bit length), 2 (any other value) = 16-bit
(0x8000 flag, 15-bit length). A count with the flag set repeats the next
byte; without it, that many literal bytes follow. A zero count ends the
pass. Mirrors RoomRleDecompress in src/room.c.
"""
from __future__ import annotations


def decode(data: bytes, w: int, h: int) -> tuple[list[int], int]:
    """Returns (tiles, bytes consumed) for a w x h layer."""
    n = w * h
    out = bytearray(n * 2)
    i = 0
    for pass_ in range(2):
        pos = pass_
        mode = data[i]
        i += 1
        while True:
            if mode == 1:
                v = data[i]
                i += 1
                rep, cnt = v & 0x80, v & 0x7F
            else:
                v = (data[i] << 8) | data[i + 1]
                i += 2
                rep, cnt = v & 0x8000, v & 0x7FFF
            if v == 0:
                break
            if rep:
                b = data[i]
                i += 1
                for _ in range(cnt):
                    out[pos] = b
                    pos += 2
            else:
                for _ in range(cnt):
                    out[pos] = data[i]
                    i += 1
                    pos += 2
    tiles = [out[k] | (out[k + 1] << 8) for k in range(0, n * 2, 2)]
    return tiles, i


def _encode_pass(stream: bytes, wide: bool, min_run: int) -> bytes:
    limit = 0x7FFF if wide else 0x7F
    out = bytearray([2 if wide else 1])

    def count(v, rep):
        v |= (0x8000 if wide else 0x80) if rep else 0
        if wide:
            out.extend(((v >> 8) & 0xFF, v & 0xFF))
        else:
            out.append(v)

    i, n = 0, len(stream)
    lit_start = None
    while i < n:
        j = i
        while j < n and stream[j] == stream[i] and j - i < limit:
            j += 1
        run = j - i
        if run >= min_run:
            if lit_start is not None:
                for k in range(lit_start, i, limit):
                    chunk = stream[k:min(i, k + limit)]
                    count(len(chunk), False)
                    out.extend(chunk)
                lit_start = None
            count(run, True)
            out.append(stream[i])
            i = j
        else:
            if lit_start is None:
                lit_start = i
            i += 1
    if lit_start is not None:
        for k in range(lit_start, n, limit):
            chunk = stream[k:min(n, k + limit)]
            count(len(chunk), False)
            out.extend(chunk)
    count(0, False)
    return bytes(out)


def encode(tiles: list[int], wide=None, min_run: int = 3, wide_min_run: int = 4) -> bytes:
    """wide=None picks the 8- or 16-bit form per pass, whichever is shorter.
    Runs shorter than min_run (8-bit form) or wide_min_run (16-bit form)
    are written as literals."""
    raw = bytearray()
    for t in tiles:
        raw += bytes((t & 0xFF, t >> 8))
    out = bytearray()
    for p in range(2):
        stream = bytes(raw[p::2])
        if wide is None:
            a, b = _encode_pass(stream, False, min_run), _encode_pass(stream, True, wide_min_run)
            out += a if len(a) <= len(b) else b
        else:
            out += _encode_pass(stream, wide, wide_min_run if wide else min_run)
    return bytes(out)
