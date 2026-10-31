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

#endif /* GUNSHIP_DATA_H */
