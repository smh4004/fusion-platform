#ifndef GUNSHIP_H
#define GUNSHIP_H

#include "types.h"

void GunshipCheckSpawnBeam(void);
void GunshipInit(void);
void GunshipNavigation(void);
void GunshipIdle(void);
void GunshipLockingSamus(void);
void GunshipPullingSamusUp(void);
void GunshipRefill(void);
void GunshipSavePrompt(void);
void GunshipSpawnSavedPrompt(void);
void GunshipSavedPrompt(void);
void GunshipReleasingSamus(void);
void GunshipSamusReleased(void);
void GunshipLoadingSave(void);
void GunshipBeamInit(void);
void GunshipBeamMovingDown(void);
void GunshipBeamMovingUp(void);
void GunshipUpdatePalette(void);
void Gunship(void);
void GunshipBeam(void);
void GunshipPart(void);

// gunship_end.c
void GunshipEndSpawnBeams(void);
void GunshipEndInit(void);
void GunshipEndWaiting(void);
void GunshipEndMovingUp(void);
void GunshipEndWaitingToEnter(void);
void GunshipEndEntering(void);
void GunshipEndWaitingForSamus(void);
void GunshipEndLockingSamus(void);
void GunshipEndMovingSamusUp(void);
void GunshipEndStartingEngine1(void);
void GunshipEndStartingEngine2(void);
void GunshipEndTakingOff(void);
void GunshipEndDone(void);
void GunshipEndBottomIdle(void);
void GunshiEndpBeamInit(void);
void GunshipEndBeamMovingDown(void);
void GunshipEndBeamMovingUp(void);
void GunshipEnd(void);
void GunshipEndBottom(void);
void GunshipEndBeam(void);

#endif /* GUNSHIP_H */
