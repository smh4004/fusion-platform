
## src/cutscenes/cutscene_monologue.c

- `CutsceneMnologueDrawOam` (0x9cec0): fully written (see git history of the
  scratch attempts); only difference is register choice when indexing the X flip
  offset table at 0x868279c (`adds r1, r1, r0` vs `adds r0, r0, r1`) and the
  ordering of the xPosition load. Likely needs the table as a real
  `const u8 [3][4]` symbol (it is inside sBlob_6638a0_682fac) instead of a raw cast.
