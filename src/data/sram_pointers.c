#include "data/sram_pointers.h"
#include "gba/memory.h"
#include "structs/save_file.h"
#include "macros.h"
#include "globals.h"
#include "gba/keys.h"
#include "structs/menus/boot_debug.h"

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

static const u8 sBlob_5822f0_58b3cc[] = INCBIN_U8("data/Blob_5822f0_58b3cc.bin");
