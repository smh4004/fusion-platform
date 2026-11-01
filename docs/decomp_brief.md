# Decompilation brief (Metroid Fusion, matching decomp)

You are decompiling one remaining assembly file of the Metroid Fusion decompilation into C that compiles **byte-identical** with agbcc. Work only inside your worktree (given in your task). Everything is already set up there: agbcc in tools/agbcc, the base ROM, extracted data/, and `make check` currently prints `mf_us.gba: OK`.

## Hard rules
- `make check` must print `mf_us.gba: OK` at every commit. Never commit a non-matching state.
- Clean room: never consult Nintendo code, leaked or otherwise. The Zero Mission decomp at /home/claude/mzm (a community clean-room project, same engine lineage) is fine to read for structure and naming.
- Never put ROM bytes into source (no hex dumps of graphics/data). Small tables of numbers written the way the repo already writes them (e.g. `const s16 x[] = { ... }`, OAM_ENTRY frames) are fine.
- Do not push and do not touch other worktrees or /home/claude/fusion-platform. Commit locally on your branch only.
- Only edit: your new C file, linker.ld (your one line), headers for your module (prototypes, data externs), data C files when you split a blob your functions use, README.md progress line, database.json for blob splits. Keep CRLF files CRLF (read/write with newline="" in Python).
- This branch's Makefile does NOT track header dependencies: after changing a header, delete the .s of every C file that includes it (or `make tidy` before `make`) so stale objects don't fool you.

## Workflow (proven on src/sprites_AI/gunship_end.c, 20/20 matched)
1. Convert the asm file to naked C wrappers:
   `python3 tools/asm_to_naked_c.py asm/<file>.s src/<new_name>.c --include <module header>`
   then in linker.ld replace `asm/<file>.o(.text);` with `src/<new_name>.o(.text);`, `git rm asm/<file>.s`, `make && make check` (must be OK unchanged). Commit.
   Choose a sensible C file name (or several files if the asm clearly covers several modules; then split the asm into consecutive ranges, one C file each, keeping order in linker.ld).
2. Make an m2c context once:
   `printf '#include "globals.h"\n#include "macros.h"\n...your headers...\n' > /tmp/ctx_in_<name>.c && cpp -P -nostdinc -Iinclude -DREGION_US -D'__attribute__(x)=' /tmp/ctx_in_<name>.c > /tmp/ctx_<name>.c`
   Keep a copy of the original asm: `git show HEAD~1:asm/<file>.s > /tmp/<name>.s` (or from the branch base).
3. Draft one function: `python3 /home/claude/m2c/m2c.py -t gba --context /tmp/ctx_<name>.c -f FuncName /tmp/<name>.s`
4. Write clean C in the repo's style (look at neighbouring src files: gCurrentSprite / struct field names, constants from include/constants/*, macros like DMA3_COPY_16, BLOCK_SIZE, Q_8_8, MOD_AND, DIV_SHIFT, SHORT_MAX). Put it in a snippet file and run
   `python3 tools/replace_naked.py src/<file>.c FuncName snippet.c "Short description"`
   which swaps the naked wrapper for your C and adds the `@brief addr | size | text` header. Fix the signature (parameters/return type) and update the prototype in the header.
5. `make && python3 tools/funcdiff.py -v FuncName` shows the first differing function side by side; iterate until `make check` is OK.
6. Commit every few matched functions with a message like
   "Decompile <module>: FuncA, FuncB, FuncC" and these trailer lines:
   Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
   Claude-Session: https://claude.ai/code/session_01PhCRM4sKi8M6L9QQ2jmY9K
   Also bump the "N/3607 functions decompiled (X%, M left)" line in README.md by the number you matched.

## Matching tips that worked
- Read struct fields into locals in the same order the asm loads them (e.g. `ramSlot = gCurrentSprite.primarySpriteRamSlot;` first).
- If a DMA source/pointer is loaded before the DMA register, compute it into a local first, then `DMA3_COPY_16(local, ...)`.
- Use a `u8` local for table indices when the asm truncates with lsl/lsr 24.
- If call arguments are NOT narrowed (no lsl/lsr 16 before a call taking u16), the original called without a prototype: don't include the header that declares it in this file (comment why).
- `switch` with fallthrough for jump tables; `if (x == 0)` vs `if (!x)` and `x--; if (x == 0)` patterns matter.
- Raw ROM addresses into data with no symbol: prefer splitting the blob into a named symbol (see how gunship_end's tables were split in src/data/sprites/omega_metroid.c); if that's too much, keep the raw cast like upstream does `(const u16*)0x0839xxxx` and move on.
- agbcc silently treats an undeclared identifier in a static initializer as 0: always rely on `make check`, not just a clean compile.

## When stuck
If a function still doesn't match after a solid effort (~40 minutes or ~15 attempts), leave it as its NAKED_FUNCTION asm (the file still matches) and move on. Keep a list in NONMATCHING_<name>.md at the repo root of your worktree with the function name and what the remaining difference looks like. Partial C in a comment is welcome.

## Finish
When every function is C or listed as non-matching, make a final commit and report: functions matched, functions left as asm (with reasons), any data you split, and anything surprising. Keep the report short.
