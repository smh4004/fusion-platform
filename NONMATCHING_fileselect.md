# Non-matching functions (file select / game over / ending text)

Functions left as NAKED_FUNCTION asm in their C files. The files still
build byte-identical.

## FileSelectSetupOam (src/menus/file_select.c, 0x9f518)

Logic is fully understood (slot search from 22 down to 0 with an `s8` index,
DMA-clear the slot, set position/type/isDrawn, then an if-chain on `type`
picking priority, OAM frames and handler). The C version is the right size
(0x418) but register allocation differs from the start: the original keeps
`type` in r3, `xPosition`/`yPosition` in r9/r8 and the loop index in r4
(pushes r8 and r9), while agbcc puts `type` in r4 and only saves r8. Tried:
old-style definition, u32 params narrowed into locals, local declaration
order, `DMA3_FILL_32` vs a `zero` local, a pointer to the slot, a do/while
search, a variable for the `isDrawn = FALSE` stores. Callers pass unnarrowed
arguments, so the prototype is `u8 FileSelectSetupOam(u32, u32, u32, u32)`.
