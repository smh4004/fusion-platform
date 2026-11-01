#ifndef CUTSCENE_H
#define CUTSCENE_H

#include "types.h"

#include "structs/cutscene.h"

// cutscene.c
boolu32 CutsceneHandler(void);
void CutsceneInit(void);
void CutsceneVblank(void);
void unk_99af8(void);

// elevator_monologue.c
boolu32 CutsceneProcess(void);
boolu32 CutsceneElevatorMonologue(u8 param_1);
void CutsceneElevatorMonologueInit(u8 param_1);
boolu32 CutsceneElevatorMonologueProcess(void);
u8 CutsceneElevatorMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition);
void CutsceneProcessElevatorScrolling(struct CutsceneMonologueOam* pOam);
void unk_9a1a8(struct CutsceneMonologueOam* pOam);
void CutsceneElevatorMonologueVblank(void);
void unk_9a31c(void);

// internal_monologue.c
boolu32 CutsceneInternalMonologue(u8 param_1);
void CutsceneInternalMonologueInit(u8 param_1);
boolu32 CutsceneInternalMonologueProcess(void);
u8 CutsceneInternalMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition);
void CutsceneInternalMonologueVblank(void);
void unk_9a63c(void);

// federation_monologue.c
boolu32 CutsceneFederationMonologue(u8 param_1);
void CutsceneFederationMonologueInit(u8 param_1);
boolu32 CutsceneFederationMonologueProcess(void);
u8 CutsceneFederationMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition);
void CutsceneFederationMonologueVblank(void);
void unk_9a99c(void);

// secret_conversation.c
boolu32 CutsceneSecretConversation(void);
void CutsceneSecretConversationInit(void);
boolu32 CutsceneSecretConversationProcess(void);
u8 CutsceneSecretConversationSetupOam(u8 type, s16 xPosition, s16 yPosition);
void CutsceneSecretConversationProcessNavigationPanel(struct CutsceneOam* pOam);
void CutsceneSecretConversationProcessIncomingDispatch(struct CutsceneOam* pOam);
void CutsceneSecretConversationVblank(void);
void unk_9ae0c(void);

// restricted_lab_detaching.c
boolu32 CutsceneRestrictedLabDetaching(void);
void CutsceneRestrictedLabDetachingInit(void);
boolu32 CutsceneRestrictedLabDetachingProcess(void);
void CutsceneRestrictedLabDetachingProcessFallingLab(struct CutsceneOam* pOam);
u8 CutsceneRestrictedLabDetachingSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch);
void CutsceneRestrictedLabDetachingProcessBslPart(struct CutsceneOam* pOam);
void CutsceneRestrictedLabDetachingProcessScrolling(struct CutsceneOam* pOam);
void unk_9ba50(struct CutsceneOam* pOam);
void unk_9bac0(struct CutsceneOam* pOam);
void unk_9bb30(struct CutsceneOam* pOam);
void unk_9bc04(struct CutsceneOam* pOam);
void unk_9bcdc(struct CutsceneOam* pOam);
void unk_9bd24(struct CutsceneOam* pOam);
void unk_9bdf8(struct CutsceneOam* pOam);
void unk_9be8c(struct CutsceneOam* pOam);
void unk_9bf54(struct CutsceneOam* pOam);
void unk_9bfb8(struct CutsceneOam* pOam);
void unk_9c04c(struct CutsceneOam* pOam);
void unk_9c080(u8 type, s16 xPosition, s16 yPosition, u16 param_4);
void unk_9c0b4(u8 type, s16 xPosition, s16 yPosition, u16 param_4, u16 param_5);
void CutsceneRestrictedLabDetachingGetPositionOfOamByType(u8 type, s16* pXPosition, s16* pYPosition);
void CutsceneRestrictedLabDetachingVblank(void);
void unk_9c1bc(void);

// bsl_exploding.c
boolu32 CutsceneBslExploding(void);
void CutsceneBslExplodingInit(void);
boolu32 CutsceneBslExplodingProcess(void);
void CutsceneBslExplodingProcessScrolling(struct CutsceneOam* pOam);
void CutsceneBslExplodingProcessBslFar(struct CutsceneOam* pOam);
void CutsceneBslExplodingProcessExplosions(struct CutsceneOam* pOam);
u8 CutsceneBslExplodingSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch);
u8 CutsceneBslExplodingGetOamInfoByType(u8 type, s16* pXPosition, s16* pYPosition, s16* pScaling);
void CutsceneBslExplodingVblank(void);
void unk_9c92c(void);

// cutscene_monologue.c
void CutsceneMonologueProcessCursor(struct CutsceneMonologueOam* pOam);
boolu32 CutsceneMonologueProcessSpecialTextCharacters(void);
void CutsceneMonologueProcessText(void);
void unk_9cc4c(void);
void CutsceneMonologueFadeIn(void);
void CutsceneMonologueFadeOut(void);
void CutsceneMonologueProcessOam(void);
void CutsceneMonologueDrawAllOam(void);
void CutsceneMnologueDrawOam(struct CutsceneMonologueOam* pOam);
void CutsceneMonologueResetOam(u8 slot);
void unk_9d09c(struct CutsceneMonologueOam* pOam);

// cutscene_utils.c
void unk_9d0a0(void);
void unk_9d1c4(void);
void CutsceneMonologueDestroyOamOfType(u8 type);
void CutsceneFadeIn(void);
void CutsceneFadeOut(void);
void CutsceneDestroyOamOfType(u8 type);
void CutsceneProcessOam(void);
void CutsceneDrawAllOam(void);
void CutsceneDrawOam(struct CutsceneOam* pOam);
void unk_9db70(struct CutsceneOam* pOam);

#endif /* CUTSCENE_H */
