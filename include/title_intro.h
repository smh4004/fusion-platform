#ifndef TITLE_INTRO_H
#define TITLE_INTRO_H

#include "types.h"

#include "structs/cutscene.h"

void unk_9209c(void);
boolu32 TitleIntroSamusInShipProcess(void);
void TitleIntroShipAlertInit(void);
boolu32 TitleIntroShipAlertProcess(void);
void TitleIntroSamusDriftingOutInit(void);
boolu32 TitleIntroSamusDriftingOutProcess(void);
boolu32 TitleIntroSamusShipCrashing(void);
void unk_92d0c(struct SpecialCutsceneOam* pOam);
void TitleIntroProcessDriftingShip(struct SpecialCutsceneOam* pOam);

void IntroProcessBslShipSpawning(struct SpecialCutsceneOam* pOam);
void IntroProcessBslShipBack(struct SpecialCutsceneOam* pOam);
void IntroProcessDepthParticle(struct SpecialCutsceneOam* pOam);
void IntroProcessTimeAndDistanceOam(struct SpecialCutsceneOam* pOam);
void IntroProcessAsteroidsPopUp(struct SpecialCutsceneOam* pOam);
void unk_93300(struct SpecialCutsceneOam* pOam);
void unk_93334(struct SpecialCutsceneOam* pOam);
void IntroOamProcessBigChangingNumber(struct SpecialCutsceneOam* pOam);
u8 TitleIntroSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch);
void IntroSetupBigNumberOam(u8 type, s16 xPosition, s16 yPosition, u16 value);
void unk_93884(void);
void TitleIntroShipAlertAndDraftingVblank(void);
void unk_9397c(struct SpecialCutsceneOam* pOam);

#endif /* TITLE_INTRO_H */
