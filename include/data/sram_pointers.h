#ifndef SRAM_POINTERS_H
#define SRAM_POINTERS_H

#include "types.h"
#include "globals.h"
#include "structs/save_file.h"
#include "structs/menus/boot_debug.h"
#include "constants/menus/erase_sram.h"

extern const void* const sSaveDataEwramPointers[3];
extern const void* const sSaveDataEwramBackupPointers[3];
extern const void* const sUnk_582274[3];
extern const void* const sUnk_582280[2];

extern const u8 sMostRecentFileSave_Text[2][SRAM_TEXT_SIZE];
extern const u8 sLanguageSave_Text[2][SRAM_TEXT_SIZE];
extern const struct ButtonAssignments sDefaultButtonAssignments;
extern const struct InGameTime sInGameTimer_Empty;
extern const struct BootDebugOptions sBootDebugOptions_Default;

extern const u8 sEraseSramMenuOamIds[ERASE_SRAM_OPTION_COUNT];
extern const u16 sEraseSramMenuSounds[ERASE_SRAM_SOUND_COUNT];
extern const u8 sEraseSramMenuWindowPositions[2][2];
extern const s8 sEraseSramMenuCursorOffsets[ERASE_SRAM_OPTION_COUNT][2];

#endif /* SRAM_POINTERS_H */
