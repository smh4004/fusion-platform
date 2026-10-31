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
| `voice-groups` | Upstream-ready: the sound voice groups as symbolic assembly; tracks use labels. | `main` |
| `symbolize-title-screen` | Upstream-ready: title screen uses symbols, resolving its FIXMEs. | `main` |

Each upstream-ready branch builds a matching ROM on its own. None has been offered upstream yet; that's the owner's call.

## Status (2026-10-31)

- Matching: `make check` passes on every branch.
- Functions: 3285/3607 (91.07%), 322 left, in 4 asm files:
  - `asm/disasm_0x080930C0.s` 189: intro, cutscenes, monologues, ending, new-file intro
  - `asm/disasm_0x0807e678.s` 54: SRAM read/write/test, erase-save menu, status screen
  - `asm/disasm_0x0809deb4.s` 53: file select, game over
  - `asm/disasm_0x08079afc.s` 27: navigation conversations, pause screen, easy sleep
- Data out of blobs (platform): 85.32%.
- Emulator smoke test (`tools/smoketest`) passes on the platform build: boot, title, file select, full intro, first room, walking.
- **Shiftability: everything after the ROM header can move.** With padding of 4 bytes, 0x100 or 64 KB inserted before crt0, agbmain (all code), generic_data (all data), rooms_data or sa_x_close_up, the new-game smoke test passes end to end. An edited graphic that grew from 0x738 to 0x1204 bytes also plays through. This covers boot, title, file select, the intro and the first room; other areas, saves and later events aren't exercised by the test yet.
- Raw ROM addresses: on `platform` essentially none are left that the shift tests or `find_raw_pointers.py` can find. Pointers into the middle of other blobs are written as `symbol + offset`, which relocates correctly.
- Platform-only: 958 INCBIN arrays size themselves; `tools/fusiontool` round-trips all 1644 graphics/palette files byte-for-byte.

## Findings worth knowing

- **LZ77**: the ROM's encoder is greedy, takes the nearest match on ties, and never uses matches closer than 4 bytes. `tools/fusiontool/fusiontool/lz77.py` reproduces all 376 compressed assets.
- **Implicit declarations**: `gunship_end.c` must not include `sprite.h`. The original called `SpriteSpawnSecondary` without a prototype, so u16 arguments weren't narrowed. Expect this elsewhere when a call's arguments look un-truncated.
- **agbcc silently accepts undeclared names in static initializers** and emits 0. A wrong label in a data table can still compile, so always run `make check`.
- **`title_screen.c` raw addresses** do switch to symbols cleanly (branch `symbolize-title-screen`). An earlier failure was a bug in my symbolizing tool, which used a variable's value where its address was meant.
- **Mixed blobs**: graphics blobs contain words that look like addresses by chance. `relocate_pointers.py incbin` only relocates animation frame tables there ({pFrame, timer} pointing at an OAM frame in the same blob: every match points back into its own blob), and keeps all bytes in the extracted file so no ROM data enters git.
- **`rooms/test/test_water_bg0.tm.lz` is not LZ77** (header byte 0x02). It's mislabelled; real format unknown.
- Platform-only relocation work (not meant for upstream): `tools/relocate_pointers.py` (`tables`, `incbin`, `literals`) and `tools/fix_undeclared.py`.
- Upstream `.PRECIOUS` on `.s` files kept half-written output after a failed compile; fixed on `track-build-deps`.

## Decompiling workflow

1. `python3 tools/asm_to_naked_c.py asm/<file>.s src/<new>.c --include <header>`; point `linker.ld` at the new object; `git rm` the asm; `make check` (must pass unchanged).
2. Draft a function with m2c: `python3 m2c.py -t gba --context ctx.c -f Name file.s` (context: `cpp -P -nostdinc -Iinclude -DREGION_US` over the headers you need).
3. Write the C in a snippet file and run `python3 tools/replace_naked.py src/<file>.c Name snippet.c "brief text"`. It adds the `@brief addr | size | text` header.
4. `make && python3 tools/funcdiff.py -v Name` shows the first mismatching function side by side.
5. Common fixes: read struct fields into locals in the original order; compute a DMA source into a local before `DMA3_COPY_*`; index with a `u8` local; drop a prototype if arguments aren't narrowed.

## Testing

- `make -C tools/smoketest` once (needs `libmgba-dev`), then `python3 tools/smoketest/run.py` after `make`. Screenshots land in `smoke_out/`.
- `tools/smoketest/shift_test.sh 0x100 "src/data/rooms_data.o(.rodata)"` builds with padding and runs the scenario; it restores `linker.ld` afterwards.
- `make smoke` and `make shift-test` wrap the above.
- `python3 tools/smoketest/bisect_shift.py --scenario tools/smoketest/new_game.txt` finds the latest object before which padding breaks a scenario.
- `python3 tools/find_raw_pointers.py` writes `smoke_out/raw_pointers.txt`, one line per unshiftable pointer with the symbol it sits in.

## Next steps

0. Widen the smoke tests: load a save, walk through a door, enter another sector, trigger an event, so shifted builds are checked beyond the first room.
1. Navigation conversations (`disasm_0x08079afc.s`, 27 functions), then SRAM (54) and file select / game over (53). The Zero Mission decomp has close equivalents for SRAM and file select.
2. Emulator smoke test (boot, title, new game, first room, save/load) so a shifted ROM can be checked automatically.
3. Shift the RAM layout out of `linker.ld` (291 pinned symbols; Zero Mission is down to 30).
4. Label the remaining 47 blobs, starting with the pointer-heavy ones (`Blob_79ce10`, `Blob_a5710`, `Blob_6131c8`).
5. Tilemap and room (RLE) support in `fusiontool`, then a Tiled export.
