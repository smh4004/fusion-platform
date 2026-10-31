#ifndef MEMU_DATA_H
#define MEMU_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sMemuIdleYSpeed[65];
extern const s16 sMemuIdleXSpeed[81];

extern const u32 sMemuGfx[];
extern const u16 sMemuPal[];

extern const struct FrameData sMemuOam_Idle[5];
extern const struct FrameData sMemuOam_ChasingTarget[5];

#endif /* MEMU_DATA_H */
