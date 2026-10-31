#ifndef GERUBOSS_DATA_H
#define GERUBOSS_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sGerubossGfx[];
extern const u16 sGerubossPal[];

extern const struct FrameData sGerubossOam_Stalling[4];
extern const struct FrameData sGerubossOam_Idle[5];
extern const struct FrameData sGerubossOam_Charging[6];
extern const struct FrameData sGerubossOam_StartGoingDown[4];
extern const struct FrameData sGerubossOam_GoingDown[4];
extern const struct FrameData sGerubossOam_StartGoingUp[4];
extern const struct FrameData sGerubossOam_GoingUp[4];
extern const struct FrameData sGerubossOam_TiltingUp[5];
extern const struct FrameData sGerubossOam_TiltingDown[5];
extern const struct FrameData sGerubossOam_GrabbingCeiling[5];

#endif /* GERUBOSS_DATA_H */
