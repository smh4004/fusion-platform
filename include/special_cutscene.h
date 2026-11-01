#ifndef SPECIAL_CUTSCENE_H
#define SPECIAL_CUTSCENE_H

#include "types.h"

#include "structs/cutscene.h"

// Random number state used by SpecialCutsceneGetRandomNumber
extern u16 gUnk_3005404;

boolu32 NewFileIntroCheckMonologueEnded(void);
boolu32 EndingCheckMonologueEnded(void);
void SpecialCutsceneProcessMonologue(void);
void unk_98158(void);
boolu32 EndingProcessAdamText(void);
boolu32 IntroProcessText(void);
void Dma3Transfer_Unused1(void* src, void* dst, u32 size, u16 count);
void Dma3Transfer_Unused2(void* src, void* dst, u32 size, u16 count);
void Dma3Clear_Unused(void* dst, u32 size, u16 count);
void SpecialCutsceneFadeIn(void);
void SpecialCutsceneFadOut(void);
void SpecialCutsceneClearOam(void);
void SpecialCutsceneEnableOam(void);
void SpecialCutsceneDestroyOamOfType(u8 type);
void SpecialCutsceneProcessOam(void);
void SpecialCutsceneDrawAllOam(void);
void SpecialCutsceneDrawOam(struct SpecialCutsceneOam* pOam);
void NewFileIntroInit(void);
u8 SpecialCutsceneGetRandomNumber(void);
void NewFileIntroVblank(void);
void unk_99940(void);

#endif /* SPECIAL_CUTSCENE_H */
