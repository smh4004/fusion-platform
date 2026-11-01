#ifndef FILE_SELECT_DATA_H
#define FILE_SELECT_DATA_H

#include "types.h"
#include "oam.h"
#include "constants/game_state.h"

extern const struct FrameData* sFileSelectFileOverlayOamPointers[5];
extern const struct FrameData* sFileSelectCursorOamPointers[3][3];
extern const u16* sFileSelectAreaNameFrames_Default[6];
extern const u16* sFileSelectAreaNameFrames_German[6];
extern const u16* sFileSelectAreaNameFrames_French[6];
extern const u16* sFileSelectAreaNameFrames_Spanish[6];
extern const u16* const* sFileSelectAreaNameFramesPointers[LANGUAGE_COUNT];
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
