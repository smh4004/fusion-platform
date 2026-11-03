#ifndef INTRO_SPACE_VIEW_H
#define INTRO_SPACE_VIEW_H

#include "types.h"

#include "structs/cutscene.h"

void IntroSpaceViewInit(void);
boolu32 IntroSpaceViewPartProcess(void);
void IntroFlyingViewInit(void);
boolu32 IntroFlyingViewProcess(void);
boolu32 IntroSpaceView(void);
void IntroProcessSpaceViewScrolling(struct SpecialCutsceneOam* pOam);
void IntroProcessBslShipSideways(struct SpecialCutsceneOam* pOam);
void IntroProcessSamusSHipEntering(struct SpecialCutsceneOam* pOam);
void IntroProcessSplashText(struct SpecialCutsceneOam* pOam);
void IntroProcessSpaceViewParticle(struct SpecialCutsceneOam* pOam);
void IntroProcessIdleShipBackview(struct SpecialCutsceneOam* pOam);
void IntroProcessBslShipSpawning_2(struct SpecialCutsceneOam* pOam);
void IntroProcessBslShipBackview(struct SpecialCutsceneOam* pOam);
void IntroProcessIdleDepthParticle(struct SpecialCutsceneOam* pOam);
u8 IntroSpaceViewSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch);
void IntroSpaceViewVblank(void);
void unk_94e80(void);

#endif /* INTRO_SPACE_VIEW_H */
