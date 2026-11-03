# Fusion platform: progress log

Resume from here. Newest status first.

## Status 2026-11-03 (afternoon): decompilation merged into platform

`platform` now contains the decompilation work: **3561/3607 functions (98.72%)**, data 89.63% out of blobs. Verified on the merged build:
- `make check`: ROM matches.
- Shiftable: 0x100 before agbmain, generic_data, rooms_data, new_file_intro data; 64 KB before agbmain: new-game smoke test passes.
- Differential play test: 103/103 identical screenshots vs. the matching ROM, two seeds, two shift points (reaches the first navigation room conversation).
- `fusiontool check`: 2034 assets round-trip; pytest 6/6.

### Still to do
1. All decomp-* commits so far are integrated (decomp-integration and platform).
2. **~46 functions still naked asm** (NONMATCHING_*.md on the decomp branches, list in the 2026-10-31 notes below). wip-decomp-* branches hold unfinished attempts. Worktrees /home/claude/wt-* still exist with those edits on disk.
3. Merge lessons:
   - database.json: when both sides list the same file, keep platform's size for the four LZ77 entries fixed on fix-truncated-lz-entries.
   - Literal relocation in C uses one label per address inside a blob (`sAddr_<addr>`, automatic now); `blob + offset` makes agbcc share a base and changes code.
   - Naked asm inside C files has `.4byte 0x08...` literals too; the literal pass handles them now.
   - Never alias with `.set name, 0x08...` (absolute, can't move); define aliases in linker.ld (`a = b;`).
   - Assembly that `.include`s other files (sound/track_data.s) is now dependency-tracked (.sd files); before that a stale track_data.o hid raw voice-group addresses. Screenshots can't catch music bugs, so always also run `find_raw_pointers.py`.
   - fix_undeclared declares unknown names as `const u8[]`; for sPointerTable_* change the extern to `u32`.

## Earlier pause notes (2026-10-31)

Decompilation was running as four parallel agents, one per remaining asm file, each on its own branch in its own git worktree. They were stopped cleanly; every `decomp-*` branch builds a matching ROM (`make check` OK, verified at pause). Nothing here is merged into `platform` yet.

| Branch | Asm file it replaces | Matched | Still naked asm |
|---|---|---|---|
| `decomp-nav` | disasm_0x08079afc.s (navigation conversations) | 17 | 10 |
| `decomp-sram` | disasm_0x0807e678.s (save file, erase menu, status screen) | 33 | 21 |
| `decomp-fileselect` | disasm_0x0809deb4.s (file select, game over, ending text) | 50 | 3 |
| `decomp-cutscene` | disasm_0x080930C0.s (intro, cutscenes, ending) | 172 | 17 |
| **total** | | **272 of 323** | **51** |

All four branch from `decomp-gunship-end`. With everything merged: about 3557/3607 functions.

`wip-decomp-sram`, `wip-decomp-fileselect` and `wip-decomp-cutscene` hold each agent's uncommitted, NOT matching, in-progress edits at the moment of pause (stash-style commits). Restore with `git stash apply wip-decomp-<name>` inside that worktree, or just ignore them.

Functions still naked asm (see NONMATCHING_*.md on the fileselect and cutscene branches for notes):
- nav: NavigationConversationProcessText, NavigationConversationHandler, unk_7b674, ProcessPauseScreenText, ProcessEasySleepText, GetFlashingSectorNumber, unk_7bde0, NavigationConversationUpdateXParasitePopUp, unk_7cfb0 (+1)
- sram: all 10 of src/menus/erase_sram.c; Sram_ReadHeader, Sram_VerifyHeader, unk_7fb84, unk_7fd10, unk_7fdb0, Sram_InitSaveFile; StatusScreenDrawNumber, StatusScreenDrawBeamOrSuit, StatusScreenDrawMissileOrBomb, StatusScreenDrawMisc, StatusScreenRemoveAmmoHeader
- fileselect: FileSelectInput, FileSelectSetupOam, FileSelectDrawFileInfo
- cutscene: CutsceneBslExplodingInit, unk_9cc4c, CutsceneMnologueDrawOam, unk_9d1c4, CutsceneDrawOam, CutsceneProcessElevatorScrolling, unk_9a1a8, CutsceneRestrictedLabDetachingInit, unk_9bb30, unk_9bc04, unk_9bd24, unk_9be8c, unk_98158, unk_98a04, SpecialCutsceneDrawOam, SpecialCutsceneGetRandomNumber

### To resume the agents
1. Recreate a worktree per branch (if the old ones are gone):
   `git worktree add ../wt-<name> decomp-<name>`, then in it: copy `tools/agbcc` from a working checkout, copy `mf_us_baserom.gba`, `make -C tools/preproc`, `python3 tools/extractor.py`, `make && make check` (must be OK).
2. m2c: `git clone https://github.com/matt-kempster/m2c` next to the repo; `pip install pycparser`.
3. Give each agent `docs/decomp_brief.md` plus its worktree, branch and the functions above. Agents commit locally; push from one place afterwards (the git proxy allows only 2 concurrent transfers).

### To merge into platform when done
1. Merge the four branches into one integration branch off `decomp-gunship-end` (they touch different files; expect README/database.json/linker.ld conflicts only), `make check`.
2. Merge that into `platform`. Platform rewrote raw addresses inside the four asm files (relocate_pointers literals); the decomp branches delete those files, so resolve modify/delete conflicts by taking the deletion. Then run
   `python3 tools/relocate_pointers.py literals src/<new files>.c` and `python3 tools/fix_undeclared.py ...` for raw addresses in the new C/naked code, `make check`, `make smoke`, `python3 tools/smoketest/diff_test.py`.
3. `python3 tools/unsize_incbins.py --keep <sizeof users>` again for any new INCBIN arrays (see the --keep list method in the Phase notes above).

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
- Platform-only: 2189 INCBIN arrays size themselves (graphics, palettes, room layers); `tools/fusiontool` round-trips 2031 assets byte-for-byte: 1644 graphics/palettes and all 387 rooms.
- **Rooms in Tiled**: `fusiontool extract` writes every room as a Tiled map with real tileset pictures (all 98 tilesets rendered from the built ROM) and a labelled collision layer. Editing and resizing rooms works and plays (tested on the first room).

## Findings worth knowing

- **Room RLE**: runs of 3+ with 8-bit counts (mode byte 1) or 4+ with 16-bit counts (mode byte 2), shorter form per pass; reproduces all 1231 layers.
- **Room tilesets**: BG character base is VRAM 0x4000 (tile 0x40 = first common tile, 0xC0 = first tileset tile).
- **CRLF**: room sources use Windows line endings; tools that edit them must read and write with `newline=""`.
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
5. Rooms: doors, scroll boundaries and sprite placement as Tiled object layers; animated tiles in tileset previews.
