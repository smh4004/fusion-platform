#ifndef FILE_SELECT_DATA_H
#define FILE_SELECT_DATA_H

#include "types.h"
#include "oam.h"
#include "constants/game_state.h"

extern const u16 sFileSelectBackdropColors[6];
extern const u8 sFileSelectOamXFlipOffsets[3][4];
extern const u8 sFileSelectCopyArrowXPositions[LANGUAGE_COUNT][2];
extern const u8 sFileSelectEraseArrowXPositions[LANGUAGE_COUNT][2];
extern const struct FrameData* sFileSelectFileOverlayOamPointers[5];
extern const struct FrameData* sFileSelectCursorOamPointers[3][3];
extern const u16* sFileSelectTextPositions_Default[6];
extern const u16* sFileSelectTextPositions_German[6];
extern const u16* sFileSelectTextPositions_French[6];
extern const u16* sFileSelectTextPositions_Spanish[6];
extern const u16* const* sFileSelectTextPositionsPointers[LANGUAGE_COUNT];
extern const struct FrameData* sFileSelectAreaNameOamPointers[LANGUAGE_COUNT][7];
extern const u16* sFileSelectTextPointers_Japanese[25];
extern const u16* sFileSelectTextPointers_English[25];
extern const u16* sFileSelectTextPointers_German[25];
extern const u16* sFileSelectTextPointers_French[25];
extern const u16* sFileSelectTextPointers_Italian[25];
extern const u16* sFileSelectTextPointers_Spanish[25];
extern const u16* sFileSelectCorruptedTextPointers[2];
extern const u16** sFileSelectTextPointers[LANGUAGE_COUNT];
extern const u16** sFileSelectCorruptedTextPointersByLanguage[LANGUAGE_COUNT];

#endif /* FILE_SELECT_DATA_H */
