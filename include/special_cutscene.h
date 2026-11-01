#ifndef SPECIAL_CUTSCENE_H
#define SPECIAL_CUTSCENE_H

#include "types.h"

#include "structs/cutscene.h"

boolu32 NewFileIntroCheckMonologueEnded(void);
boolu32 EndingCheckMonologueEnded(void);
void SpecialCutsceneProcessMonologue(void);
void IntroProcessText(void);
void Dma3Transfer_Unused1(void* src, void* dst, u16 size, u16 count);
void Dma3Transfer_Unused2(void* src, void* dst, u16 size, u16 count);
void SpecialCutsceneFadeIn(void);
void SpecialCutsceneFadOut(void);
void SpecialCutsceneClearOam(void);
void SpecialCutsceneEnableOam(void);
void SpecialCutsceneDestroyOamOfType(u8 type);
void SpecialCutsceneProcessOam(void);
void SpecialCutsceneDrawAllOam(void);
void NewFileIntroInit(void);
u8 SpecialCutsceneGetRandomNumber(void);
void NewFileIntroVblank(void);
void unk_99940(void);

#endif /* SPECIAL_CUTSCENE_H */
