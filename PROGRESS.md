# Fusion platform: progress log

Resume from here. Newest status first.

## Branches

| Branch | Purpose | Base |
|---|---|---|
| `main` | Mirror of upstream `metroidret/mf`. Never commit here. | upstream |
| `platform` | Everything below merged together, plus modding-only changes. | `main` |
| `label-intro-collision-gfx` | Upstream-ready: split a blob into 24 named intro graphics. | `main` |
| `fix-truncated-lz-entries` | Upstream-ready: four LZ77 entries that were cut short. | `main` |
| `track-build-deps` | Upstream-ready: header/INCBIN dependency tracking, `.DELETE_ON_ERROR`. | `main` |
| `symbolize-sprite-pointers` | Upstream-ready: 648 raw addresses in sprite tables become symbols; fixes an inverted include guard. | `main` |
| `symbolize-rom-literals` | Upstream-ready: 26 more raw addresses in sprite AI become symbols. | `main` |
| `decomp-gunship-end` | Upstream-ready: all 20 gunship ending functions decompiled, plus their data. | `main` |

Each upstream-ready branch builds a matching ROM on its own. None has been offered upstream yet; that's the owner's call.

## Status (2026-10-31)

- Matching: `make check` passes on every branch.
- Functions: 3285/3607 (91.07%), 322 left, in 4 asm files:
  - `asm/disasm_0x080930C0.s` 189: intro, cutscenes, monologues, ending, new-file intro
  - `asm/disasm_0x0807e678.s` 54: SRAM read/write/test, erase-save menu, status screen
  - `asm/disasm_0x0809deb4.s` 53: file select, game over
  - `asm/disasm_0x08079afc.s` 27: navigation conversations, pause screen, easy sleep
- Data out of blobs (platform): 85.13%.
- Raw ROM addresses left in C: ~370 (was ~1030). Biggest: `src/new_file_intro.c` (~160, mostly into blobs or static symbols), `src/data/sprite_pointers.c` (168), `src/menus/pause_screen.c` (14), `src/menus/title_screen.c` (8, needed to match).
- Platform-only: 958 INCBIN arrays size themselves; `tools/fusiontool` round-trips all 1644 graphics/palette files byte-for-byte.

## Findings worth knowing

- **LZ77**: the ROM's encoder is greedy, takes the nearest match on ties, and never uses matches closer than 4 bytes. `tools/fusiontool/fusiontool/lz77.py` reproduces all 376 compressed assets.
- **Implicit declarations**: `gunship_end.c` must not include `sprite.h`. The original called `SpriteSpawnSecondary` without a prototype, so u16 arguments weren't narrowed. Expect this elsewhere when a call's arguments look un-truncated.
- **agbcc silently accepts undeclared names in static initializers** and emits 0. A wrong label in a data table can still compile, so always run `make check`.
- **`title_screen.c` raw addresses**: switching them to symbols makes agbcc emit different code, so they stay for now.
- **`rooms/test/test_water_bg0.tm.lz` is not LZ77** (header byte 0x02). It's mislabelled; real format unknown.
- Upstream `.PRECIOUS` on `.s` files kept half-written output after a failed compile; fixed on `track-build-deps`.

## Decompiling workflow

1. `python3 tools/asm_to_naked_c.py asm/<file>.s src/<new>.c --include <header>`; point `linker.ld` at the new object; `git rm` the asm; `make check` (must pass unchanged).
2. Draft a function with m2c: `python3 m2c.py -t gba --context ctx.c -f Name file.s` (context: `cpp -P -nostdinc -Iinclude -DREGION_US` over the headers you need).
3. Write the C in a snippet file and run `python3 tools/replace_naked.py src/<file>.c Name snippet.c "brief text"`. It adds the `@brief addr | size | text` header.
4. `make && python3 tools/funcdiff.py -v Name` shows the first mismatching function side by side.
5. Common fixes: read struct fields into locals in the original order; compute a DMA source into a local before `DMA3_COPY_*`; index with a `u8` local; drop a prototype if arguments aren't narrowed.

## Next steps

1. Navigation conversations (`disasm_0x08079afc.s`, 27 functions), then SRAM (54) and file select / game over (53). The Zero Mission decomp has close equivalents for SRAM and file select.
2. Emulator smoke test (boot, title, new game, first room, save/load) so a shifted ROM can be checked automatically.
3. Shift the RAM layout out of `linker.ld` (291 pinned symbols; Zero Mission is down to 30).
4. Label the remaining 47 blobs, starting with the pointer-heavy ones (`Blob_79ce10`, `Blob_a5710`, `Blob_6131c8`).
5. Tilemap and room (RLE) support in `fusiontool`, then a Tiled export.
