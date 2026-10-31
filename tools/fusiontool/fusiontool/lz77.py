"""GBA BIOS LZ77 (type 0x10) codec.

`compress` reproduces the encoder used for Metroid Fusion's data
byte-for-byte: greedy longest match, nearest start wins ties, and matches
closer than 4 bytes back are never used. With those rules every LZ77 asset
in the US ROM re-encodes to its original bytes (tests/test_roundtrip.py).
"""
from __future__ import annotations

MIN_MATCH = 3
MAX_MATCH = 18
MAX_DIST = 0x1000
FUSION_MIN_DIST = 4


def decompress(data: bytes, offset: int = 0) -> tuple[bytes, int]:
    """Decode one stream starting at `offset`. Returns (output, bytes consumed)."""
    if data[offset] != 0x10:
        raise ValueError(f"not an LZ77 stream (header byte {data[offset]:#x})")
    size = int.from_bytes(data[offset + 1:offset + 4], "little")
    out = bytearray()
    i = offset + 4
    while len(out) < size:
        flags = data[i]
        i += 1
        for _ in range(8):
            if len(out) >= size:
                break
            if flags & 0x80:
                b0, b1 = data[i], data[i + 1]
                i += 2
                length = (b0 >> 4) + MIN_MATCH
                dist = (((b0 & 0xF) << 8) | b1) + 1
                for _ in range(length):
                    out.append(out[-dist])
            else:
                out.append(data[i])
                i += 1
            flags = (flags << 1) & 0xFF
    return bytes(out), i - offset


def _find_match(src: bytes, pos: int, chains: dict, min_dist: int, prefer_far: bool):
    """Longest match for src[pos:]. Ties go to the nearest (or farthest) start."""
    max_len = min(MAX_MATCH, len(src) - pos)
    if max_len < MIN_MATCH:
        return 0, 0
    starts = chains.get(src[pos:pos + MIN_MATCH])
    if not starts:
        return 0, 0
    lo = pos - MAX_DIST
    best_len, best_dist = 0, 0
    # `starts` is ascending; walk nearest-first unless prefer_far
    seq = starts if prefer_far else reversed(starts)
    for start in seq:
        if start < lo or pos - start < min_dist:
            continue
        n = MIN_MATCH
        while n < max_len and src[start + n] == src[pos + n]:
            n += 1
        if n > best_len:
            best_len, best_dist = n, pos - start
            if n == max_len:
                break
    return best_len, best_dist


def _index(chains: dict, src: bytes, pos: int) -> None:
    if pos + MIN_MATCH <= len(src):
        lst = chains.setdefault(src[pos:pos + MIN_MATCH], [])
        lst.append(pos)
        # drop entries that fell out of the window
        cut = 0
        while cut < len(lst) and lst[cut] < pos - MAX_DIST:
            cut += 1
        if cut:
            del lst[:cut]


def compress(src: bytes, min_dist: int = FUSION_MIN_DIST, prefer_far: bool = False) -> bytes:
    """Greedy LZ77 encode. Output is padded to a 4-byte boundary."""
    out = bytearray([0x10]) + len(src).to_bytes(3, "little")
    chains: dict = {}
    pos = 0
    while pos < len(src):
        flag_at = len(out)
        out.append(0)
        flags = 0
        for bit in range(8):
            if pos >= len(src):
                break
            length, dist = _find_match(src, pos, chains, min_dist, prefer_far)
            if length >= MIN_MATCH:
                d = dist - 1
                out += bytes([((length - MIN_MATCH) << 4) | (d >> 8), d & 0xFF])
                flags |= 0x80 >> bit
                for p in range(pos, pos + length):
                    _index(chains, src, p)
                pos += length
            else:
                out.append(src[pos])
                _index(chains, src, pos)
                pos += 1
        out[flag_at] = flags
    while len(out) % 4:
        out.append(0)
    return bytes(out)
