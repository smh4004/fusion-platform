# fusiontool

Turns the decomp's raw ROM data into files you can edit with normal tools, and back.

| ROM data (`data/`) | Editable asset (`assets/`) | Edit with |
|---|---|---|
| `*.gfx` (4bpp tiles) | `*.gfx.png` (indexed PNG) | Aseprite, GIMP, Usenti, any palette-aware editor |
| `*.gfx.lz` (LZ77-compressed tiles) | `*.gfx.png` | same; recompressed on build |
| `*.pal` (BGR555) | `*.pal` (JASC-PAL text) | most pixel-art tools, or a text editor |

Both `data/` and `assets/` are git-ignored. They're generated from your own ROM and must never be committed.

## Use

From the repository root, after `python3 tools/extractor.py`:

```sh
pip install pillow                       # once
export PYTHONPATH=tools/fusiontool
python3 -m fusiontool extract           # data/ -> assets/
# ...edit PNGs / palettes in assets/...
python3 -m fusiontool build             # assets/ -> data/ (only changed files)
make                                     # rebuilds just what uses those files
```

`python3 -m fusiontool check` proves every supported file round-trips byte-for-byte. Untouched assets always rebuild the original bytes, so `make check` keeps passing until you actually change something.

## Rules for editing graphics

- Keep the PNG in indexed (palette) mode and use only indices 0–15. The PNG's colours are a preview only; the game uses the palette in the matching `.pal`.
- Index 0 is transparent for sprites and for every background layer except the backdrop.
- You can add or remove tiles; the build sizes the array from the file. A few assets (69, mostly palettes) are measured by the code with `sizeof` and keep a fixed size.
- Changing an asset's size moves everything after it in the ROM. The decomp isn't fully shiftable yet, so check that a moved build still boots.

## How the matching recompression works

The ROM's LZ77 data was produced by a greedy encoder that takes the longest match, prefers the nearest one on ties, and never uses matches closer than 4 bytes back. `lz77.compress` follows those rules, which reproduces all 376 compressed graphics and tilemaps in the US ROM exactly. Bytes that sat after a compressed stream in the ROM are stored in the PNG (`fusion_lz_tail`) and written back after it.

## Tests

```sh
python3 -m pytest tools/fusiontool/tests
```

The full-ROM test is skipped when `data/` hasn't been extracted.
