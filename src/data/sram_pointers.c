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

// Bytes come from the extracted file; pointers are relocated by the linker.
extern const u8 sBlob_5822f0_58b3cc[];
asm("\n\
    .pushsection .rodata\n\
    .global sBlob_5822f0_58b3cc\n\
sBlob_5822f0_58b3cc:\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x0, 0x74c\n\
    .4byte sBlob_5822f0_58b3cc + 0x60c\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x750, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x620\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x758, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x634\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x760, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x648\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x768, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x65c\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x770, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x670\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x778, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x684\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x780, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x698\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x788, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x6ac\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x790, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x6c0\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x798, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x6d4\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7a0, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x6e8\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7a8, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5bc\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7b0, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5d0\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7b8, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5e4\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7c0, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5f8\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7c8, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5bc\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7d0, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5d0\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7d8, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5e4\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7e0, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5f8\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7e8, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5bc\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7f0, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5d0\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x7f8, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5e4\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x800, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x5f8\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x808, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x6fc\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x810, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x710\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x818, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x724\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x820, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x738\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x828, 0xc\n\
    .4byte sBlob_5822f0_58b3cc + 0x4c6\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x838, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x4da\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x840, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x4ee\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x848, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x502\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x850, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x516\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x858, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x52a\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x860, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x53e\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x868, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x552\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x870, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x566\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x878, 0x4\n\
    .4byte sBlob_5822f0_58b3cc + 0x57a\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x880, 0xc\n\
    .4byte sBlob_5822f0_58b3cc + 0x588\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x890, 0xc\n\
    .4byte sBlob_5822f0_58b3cc + 0x5a2\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x8a0, 0xc\n\
    .4byte sBlob_5822f0_58b3cc + 0x366\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x8b0, 0xc\n\
    .4byte sBlob_5822f0_58b3cc + 0x416\n\
    .incbin \"data/Blob_5822f0_58b3cc.bin\", 0x8c0, 0x881c\n\
    .popsection\n\
");
