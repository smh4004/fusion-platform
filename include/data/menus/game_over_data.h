#ifndef GAME_OVER_DATA_H
#define GAME_OVER_DATA_H

#include "types.h"
#include "oam.h"
#include "constants/game_state.h"

extern const u8 sGameOverOamXFlipOffsets[3][4];
extern const struct FrameData* sGameOverCursorOamPointers[3];
extern const u32* sGameOverTextGfxPointers[LANGUAGE_COUNT];

#endif /* GAME_OVER_DATA_H */
