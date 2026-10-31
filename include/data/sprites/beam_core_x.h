#ifndef BEAM_CORE_X_DATA_H
#define BEAM_CORE_X_DATA_H

#include "macros.h"
#include "oam.h"

extern const s16 sIceBeamAbilityFloatingYMovement[65];

extern const u32 sChargeBeamCoreXGfx[5 * 512];
extern const u16 sChargeBeamCoreXPal[5 * 16];

extern const struct FrameData sBeamCoreXAbilityOam_Idle[9];
extern const struct FrameData sBeamCoreXAbilityOam_GettingAbsorbed[3];
extern const struct FrameData sBeamCoreXGlowingOam[25];
extern const struct FrameData sBeamCoreXShellOam[2];
extern const struct FrameData sBeamCoreXEyeOam_Closed[2];
extern const struct FrameData sBeamCoreXEyeOam_Opening[7];
extern const struct FrameData sBeamCoreXEyeOam_Opened[2];
extern const struct FrameData sBeamCoreXEyeOam_Charging1[10];
extern const struct FrameData sBeamCoreXEyeOam_Charging2[10];
extern const struct FrameData sBeamCoreXEyeOam_Closing[7];

extern const u32 sWideBeamCoreXGfx[5 * 512];
extern const u16 sWideBeamCoreXPal[5 * 16];
extern const u32 sPlasmaBeamCoreXGfx[];
extern const u16 sPlasmaBeamCoreXPal[];
extern const u32 sWaveBeamCoreXGfx[];
extern const u16 sWaveBeamCoreXPal[];
extern const u32 sIceBeamCoreXGfx[];
extern const u16 sIceBeamCoreXPal[];

#endif /* BEAM_CORE_X_DATA_H */
