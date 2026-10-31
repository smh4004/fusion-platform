#ifndef GERUTA_DATA_H
#define GERUTA_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sGerutaIdleYMovement[65]; // 36

extern const u32 sGerutaGfx[];
extern const u16 sGerutaPal[];

extern const struct FrameData sGerutaOam_Idle[5];
extern const struct FrameData sGerutaOam_AttackWarning[2];
extern const struct FrameData sGerutaOam_Lunging[2];
extern const struct FrameData sGerutaOam_Swiping[6];
extern const struct FrameData sGerutaOam_TurningAround[2];

#endif /* GERUTA_DATA_H */
