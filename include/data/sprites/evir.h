#ifndef EVIR_DATA_H
#define EVIR_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sEvirGfx[];
extern const u16 sEvirPal[];

extern const struct FrameData sEvirOam_Idle[9];
extern const struct FrameData sEvirOam_Shooting[8];
extern const struct FrameData sEvirOam_TurningAround1[4];
extern const struct FrameData sEvirOam_TurningAround2[4];
extern const struct FrameData sEvirProjectileOam_Moving[5];
extern const struct FrameData sEvirProjectileOam_Exploding[4];

#endif /* EVIR_DATA_H */
