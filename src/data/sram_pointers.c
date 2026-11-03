#include "data/sram_pointers.h"
#include "gba/memory.h"
#include "structs/save_file.h"
#include "macros.h"
#include "globals.h"
#include "gba/keys.h"
#include "structs/menus/boot_debug.h"
#include "constants/menus/erase_sram.h"

const void* const sSaveDataEwramPointers[3] = {
    EWRAM_SRAM + 0x200 + sizeof(struct SaveFile) * 0,
    EWRAM_SRAM + 0x200 + sizeof(struct SaveFile) * 2,
    EWRAM_SRAM + 0x200 + sizeof(struct SaveFile) * 4
};

const void* const sSaveDataEwramBackupPointers[3] = {
    EWRAM_SRAM + 0x200 + sizeof(struct SaveFile) * 1,
    EWRAM_SRAM + 0x200 + sizeof(struct SaveFile) * 3,
    EWRAM_SRAM + 0x200 + sizeof(struct SaveFile) * 5
};

const void* const sUnk_582274[3] = {
    EWRAM_SRAM + 0x500 + sizeof(struct SaveFile) * 0,
    EWRAM_SRAM + 0x500 + sizeof(struct SaveFile) * 2,
    EWRAM_SRAM + 0x500 + sizeof(struct SaveFile) * 4
};

const void* const sUnk_582280[2] = {
    EWRAM_SRAM + 0x7040,
    EWRAM_SRAM + 0x7080
};

const u8 sMostRecentFileSave_Text[2][SRAM_TEXT_SIZE] = {
    "SELECTSAVENUMBER",
    "ENDDATA_SEL_SAVE"
};

const u8 sLanguageSave_Text[2][SRAM_TEXT_SIZE] = {
    "STARTKEYLANGUAGE",
    "ENDKEY_LANGUAGE_"
};

const struct ButtonAssignments sDefaultButtonAssignments = {
    .armMissiles = KEY_R,
    .diagonalAim = KEY_L,
    .swapMissiles = KEY_SELECT,
    .pause = KEY_START
};

const u8 sUnk_5822d0[4] = { 0 };

const struct InGameTime sInGameTimer_Empty = {
    .hours = 0,
    .minutes = 0,
    .seconds = 0,
    .frames = 0
};

const u8 sUnk_5822d8[12] = {
    0, 0, 0, 0, 0, 0, 7, 7, 0x7F, 4, 0, 0
};

const struct BootDebugOptions sBootDebugOptions_Default = {
    .securityHatchLevel = UCHAR_MAX
};

static const u8 sBlob_5822f0_58b3b0[] = INCBIN_U8("data/Blob_5822f0_58b3b0.bin");

const u8 sEraseSramMenuOamIds[ERASE_SRAM_OPTION_COUNT] = {
    [ERASE_SRAM_OPTION_QUESTION_NO] = ERASE_SRAM_OAM_ID_QUESTION_WINDOW_NO_SELECTED,
    [ERASE_SRAM_OPTION_QUESTION_YES] = ERASE_SRAM_OAM_ID_QUESTION_WINDOW_YES_SELECTED,
    [ERASE_SRAM_OPTION_CONFIRM_NO] = ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_NO_SELECTED,
    [ERASE_SRAM_OPTION_CONFIRM_YES] = ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_YES_SELECTED
};

const u16 sEraseSramMenuSounds[ERASE_SRAM_SOUND_COUNT] = {
    [ERASE_SRAM_SOUND_NONE] = 0,
    [ERASE_SRAM_SOUND_SELECT] = 0x1FB,
    [ERASE_SRAM_SOUND_ERASE] = 0x209,
    [ERASE_SRAM_SOUND_CANCEL] = 0,
    [ERASE_SRAM_SOUND_CURSOR] = 0x1FA
};

// X, Y of the question window and the confirm window
const u8 sEraseSramMenuWindowPositions[2][2] = {
    { 0x80, 0x60 },
    { 0x84, 0x5C }
};

// X, Y offset of the cursor for each option, relative to its window
const s8 sEraseSramMenuCursorOffsets[ERASE_SRAM_OPTION_COUNT][2] = {
    [ERASE_SRAM_OPTION_QUESTION_NO] = { -0x54, -2 },
    [ERASE_SRAM_OPTION_QUESTION_YES] = { 4, -2 },
    [ERASE_SRAM_OPTION_CONFIRM_NO] = { -0x54, 0x26 },
    [ERASE_SRAM_OPTION_CONFIRM_YES] = { 4, 0x26 }
};
