#ifndef GUNSHIP_DATA_H
#define GUNSHIP_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sGunshipGfx[];
extern const u16 sGunshipPal[];

extern const struct FrameData sGunshipOam_Idle[2];
extern const struct FrameData sGunshipBeamOam_Idle[5];
extern const struct FrameData sGunshipPartOam_Idle[2];

extern const u16 sGunshipFlashingPal[];

extern const s16 sGunshipEndEnteringYMovement[65];
extern const s16 sGunshipEnd_39ab62[49];
extern const s16 sGunshipEnd_39abc4[96];
extern const u8 sGunshipEndTakingOffRotation[12];
extern const u16 sGunshipEnd_39ac90[32];
extern const u16 sGunshipEndTakingOffScaling[68];
extern const struct FrameData sGunshipEndOam_39eb38[2];
extern const struct FrameData sGunshipEndOam_39eb48[7];
extern const struct FrameData sGunshipEndOam_39eb80[7];
extern const struct FrameData sGunshipEndOam_39ebb8[5];
extern const struct FrameData sGunshipEndOam_39ebe0[5];
extern const struct FrameData sGunshipEndOam_39ec08[5];
extern const struct FrameData sGunshipEndOam_39ec30[7];
extern const struct FrameData sGunshipEndOam_39ec68[2];
extern const struct FrameData sGunshipEndOam_39ec78[3];

#endif /* GUNSHIP_DATA_H */
