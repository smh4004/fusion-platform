#ifndef ZEBESIAN_AQUA_DATA_H
#define ZEBESIAN_AQUA_DATA_H

#include "types.h"
#include "oam.h"
#include "gba/memory.h"

extern const u32 sZebesianAquaGfx[];
extern const u16 sZebesianAquaPal[];

extern const struct FrameData sZebesianAquaOam_Unused_38172c[7];
extern const struct FrameData sZebesianAquaOam_Idle[7];
extern const struct FrameData sZebesianAquaOam_TurningAround[5];
extern const struct FrameData sZebesianAquaOam_Shooting[13];

extern const struct FrameData sZebesianAquaProjectileOam_Idle[4];

extern const struct FrameData sZebesianAquaOam_Unused_38184c[8];

#endif /* ZEBESIAN_AQUA_DATA_H */
