"""Run from the repo root: python3 -m pytest tools/fusiontool/tests

Synthetic tests always run. The full-ROM tests need extracted data
(`python3 tools/extractor.py`) and are skipped without it.
"""
import random
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fusiontool import assets, gfx, lz77, pal  # noqa: E402

DATA = Path("data")


def test_lz77_roundtrip_synthetic():
    rng = random.Random(0)
    for n in (0, 1, 7, 64, 1000, 5000):
        src = bytes(rng.choice(b"\x00\x11\x22ABAB") for _ in range(n))
        enc = lz77.compress(src)
        assert len(enc) % 4 == 0
        assert lz77.decompress(enc)[0] == src


def test_lz77_never_uses_short_distances():
    src = b"\x00" * 64  # a greedy encoder would love distance 1 here
    enc = lz77.compress(src)
    i, n = 4, 0
    while n < len(src):
        flags = enc[i]
        i += 1
        for _ in range(8):
            if n >= len(src):
                break
            if flags & 0x80:
                dist = (((enc[i] & 0xF) << 8) | enc[i + 1]) + 1
                assert dist >= lz77.FUSION_MIN_DIST
                n += (enc[i] >> 4) + 3
                i += 2
            else:
                n += 1
                i += 1
            flags = (flags << 1) & 0xFF


def test_gfx_roundtrip_synthetic():
    raw = bytes(random.Random(1).randrange(256) for _ in range(32 * 37))
    img = gfx.to_image(raw, width_tiles=8)
    img.info["fusion_tiles"] = "37"
    assert gfx.from_image(img) == raw


def test_pal_roundtrip_keeps_top_bit():
    raw = pal.encode([0x0000, 0x7FFF, 0x801F, 0x1234])
    assert pal.from_jasc(pal.to_jasc(raw)) == raw


def test_pal_edit_drops_stale_top_bit():
    text = pal.to_jasc(pal.encode([0x801F]))
    edited = text.replace("255 0 0", "0 0 255")
    assert pal.decode(pal.from_jasc(edited)) == [0x7C00]


def _rom_files():
    if not DATA.is_dir():
        return []
    return [p for p in sorted(DATA.rglob("*")) if p.is_file() and assets.kind_of(p)[1]]


@pytest.mark.skipif(not _rom_files(), reason="needs extracted data/ (run tools/extractor.py)")
def test_every_rom_asset_roundtrips(tmp_path):
    bad = []
    for p in _rom_files():
        a = assets.asset_path(p, DATA, tmp_path)
        assets.export(p, a)
        if assets.build(a, p) != p.read_bytes():
            bad.append(str(p))
    assert not bad, f"{len(bad)} assets changed on round trip, e.g. {bad[:5]}"
