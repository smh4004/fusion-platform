
## src/cutscenes/cutscene_monologue.c

- `CutsceneMnologueDrawOam` (0x9cec0): fully written (see git history of the
  scratch attempts); only difference is register choice when indexing the X flip
  offset table at 0x868279c (`adds r1, r1, r0` vs `adds r0, r0, r1`) and the
  ordering of the xPosition load. Likely needs the table as a real
  `const u8 [3][4]` symbol (it is inside sBlob_6638a0_682fac) instead of a raw cast.

## src/cutscenes/elevator_monologue.c

- `CutsceneProcessElevatorScrolling` (0x9a088) and `unk_9a1a8` (0x9a1a8): the C
  (scrolling BG2/BG1, fading BLDALPHA between 4 and 10) produces the right code
  except that agbcc cross-jumps the identical "bg1YPosition -= 3; write BG1VOFS"
  tails of the stage 1 and stage 2 branches, while the original keeps two copies.

## src/cutscenes/bsl_exploding.c

- `CutsceneBslExplodingInit` (0x9c254): everything matches except one register
  (`ldr r1` vs `ldr r2`) for the palette base 0x868101c in the final DMA.

## src/cutscenes/restricted_lab_detaching.c

- `unk_9bb30`, `unk_9bc04`, `unk_9bd24` (0x9bb30..): debris movers with a palette
  cycle (DMA of `((const u16*)0x868161c/0x868141c/0x868181c)[unk_C * 16]` to OBJ
  palette). Logic matches; agbcc keeps pOam in r2 instead of r3 because of the
  register pressure of the final DMA (the original loads the DMA register base
  before the palette address).
