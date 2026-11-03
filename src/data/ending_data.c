#include "macros.h"
#include "oam.h"

#include "data/ending_data.h"

#include "structs/ending.h"

#include "constants/ending.h"

#include "gba/memory.h"
extern const u8 sAddr_74a7f8[];
extern const u8 sAddr_74a812[];
extern const u8 sAddr_74a826[];
extern const u8 sAddr_74a82e[];
extern const u8 sAddr_74a836[];
extern const u8 sAddr_74a83e[];
extern const u8 sAddr_74a846[];
extern const u8 sAddr_74a84e[];
extern const u8 sAddr_74a856[];
extern const u8 sAddr_74a85e[];
extern const u8 sAddr_74a866[];
extern const u8 sAddr_74a86e[];
extern const u8 sAddr_74a888[];
extern const u8 sAddr_74a890[];
extern const u8 sAddr_74a898[];
extern const u8 sAddr_74a8a0[];
extern const u8 sAddr_74a8a8[];
extern const u8 sAddr_74a8b0[];
extern const u8 sAddr_74a8b8[];
extern const u8 sAddr_74a8c0[];
extern const u8 sAddr_74a8c8[];
extern const u8 sAddr_74a8d0[];
extern const u8 sAddr_74a8d8[];
extern const u8 sAddr_74a8e0[];
extern const u8 sAddr_74a900[];
extern const u8 sAddr_74a908[];
extern const u8 sAddr_74a910[];
extern const u8 sAddr_74a918[];
extern const u8 sAddr_74a920[];
extern const u8 sAddr_74a928[];
extern const u8 sAddr_74a930[];
extern const u8 sAddr_74a938[];
extern const u8 sAddr_74a940[];
extern const u8 sAddr_74a948[];
extern const u8 sAddr_74a950[];
extern const u8 sAddr_74a958[];
extern const u8 sAddr_74a960[];
extern const u8 sAddr_74a968[];
extern const u8 sAddr_74a970[];
extern const u8 sAddr_74a978[];
extern const u8 sAddr_74a980[];
extern const u8 sAddr_74a988[];
extern const u8 sAddr_74a9a8[];
extern const u8 sAddr_74a9c8[];
extern const u8 sAddr_74a9e2[];
extern const u8 sAddr_74aa02[];
extern const u8 sAddr_74aa0a[];
extern const u8 sAddr_74aa12[];
extern const u8 sAddr_74aa1a[];
extern const u8 sAddr_74aa22[];
extern const u8 sAddr_74aa2a[];
extern const u8 sAddr_74aa32[];
extern const u8 sAddr_74aa3a[];
extern const u8 sAddr_74aa42[];
extern const u8 sAddr_74aa4a[];
extern const u8 sAddr_74aa52[];
extern const u8 sAddr_74aa5a[];
extern const u8 sAddr_74aa62[];
extern const u8 sAddr_74aa6a[];
extern const u8 sAddr_74aa72[];
extern const u8 sAddr_74aa7a[];
extern const u8 sAddr_74aa82[];
extern const u8 sAddr_74aaae[];
extern const u8 sAddr_74aab6[];
extern const u8 sAddr_74aabe[];
extern const u8 sAddr_74aac6[];
extern const u8 sAddr_74aace[];
extern const u8 sAddr_74aad6[];
extern const u8 sAddr_74aade[];
extern const u8 sAddr_74aae6[];
extern const u8 sAddr_74aaee[];
extern const u8 sAddr_74aaf6[];
extern const u8 sAddr_74aafe[];
extern const u8 sAddr_74ab06[];
extern const u8 sAddr_74ab0e[];
extern const u8 sAddr_74ab16[];
extern const u8 sAddr_74ab1e[];
extern const u8 sAddr_74ab26[];
extern const u8 sAddr_74ab2e[];
extern const u8 sAddr_74ab36[];
extern const u8 sAddr_74ab3e[];
extern const u8 sAddr_74ab46[];
extern const u8 sAddr_74ab4e[];
extern const u8 sAddr_74ab62[];
extern const u8 sAddr_74ab82[];
extern const u8 sAddr_74ab9c[];
extern const u8 sAddr_74abc2[];
extern const u8 sAddr_74abca[];
extern const u8 sAddr_74abd2[];
extern const u8 sAddr_74abda[];
extern const u8 sAddr_74abe2[];
extern const u8 sAddr_74abea[];
extern const u8 sAddr_74abf2[];
extern const u8 sAddr_74abfa[];
extern const u8 sAddr_74ac02[];
extern const u8 sAddr_74ac0a[];
extern const u8 sAddr_74ac12[];
extern const u8 sAddr_74ac1a[];
extern const u8 sAddr_74ac22[];
extern const u8 sAddr_74ac2a[];
extern const u8 sAddr_74ac32[];
extern const u8 sAddr_74ac3a[];
extern const u8 sAddr_74ac42[];
extern const u8 sAddr_74ac4a[];
extern const u8 sAddr_74ac52[];
extern const u8 sAddr_74ac6c[];
extern const u8 sAddr_74ac74[];
extern const u8 sAddr_74ac7c[];
extern const u8 sAddr_74ac84[];
extern const u8 sAddr_74ac8c[];
extern const u8 sAddr_74ac94[];
extern const u8 sAddr_74ac9c[];
extern const u8 sAddr_74aca4[];
extern const u8 sAddr_74acac[];
extern const u8 sAddr_74acb4[];
extern const u8 sAddr_74acbc[];
extern const u8 sAddr_74acc4[];
extern const u8 sAddr_74ace4[];
extern const u8 sAddr_74acec[];
extern const u8 sAddr_74acf4[];
extern const u8 sAddr_74acfc[];
extern const u8 sAddr_74ad04[];
extern const u8 sAddr_74ad0c[];
extern const u8 sAddr_74ad14[];
extern const u8 sAddr_74ad1c[];
extern const u8 sAddr_74ad24[];
extern const u8 sAddr_74ad2c[];
extern const u8 sAddr_74ad34[];
extern const u8 sAddr_74ad3c[];
extern const u8 sAddr_74ad44[];
extern const u8 sAddr_74ad4c[];
extern const u8 sAddr_74ad54[];
extern const u8 sAddr_74ad5c[];
extern const u8 sAddr_74ad64[];
extern const u8 sAddr_74ad6c[];
extern const u8 sAddr_74ad8c[];
extern const u8 sAddr_74adac[];
extern const u8 sAddr_74adc6[];
extern const u8 sAddr_74ade6[];
extern const u8 sAddr_74adee[];
extern const u8 sAddr_74adf6[];
extern const u8 sAddr_74adfe[];
extern const u8 sAddr_74ae06[];
extern const u8 sAddr_74ae0e[];
extern const u8 sAddr_74ae16[];
extern const u8 sAddr_74ae1e[];
extern const u8 sAddr_74ae26[];
extern const u8 sAddr_74ae2e[];
extern const u8 sAddr_74ae36[];
extern const u8 sAddr_74ae3e[];
extern const u8 sAddr_74ae46[];
extern const u8 sAddr_74ae4e[];
extern const u8 sAddr_74ae56[];
extern const u8 sAddr_74ae5e[];
extern const u8 sAddr_74ae84[];
extern const u8 sAddr_74ae8c[];
extern const u8 sAddr_74ae94[];
extern const u8 sAddr_74ae9c[];
extern const u8 sAddr_74aea4[];
extern const u8 sAddr_74aeac[];
extern const u8 sAddr_74aeb4[];
extern const u8 sAddr_74aebc[];
extern const u8 sAddr_74aec4[];
extern const u8 sAddr_74aecc[];
extern const u8 sAddr_74aed4[];
extern const u8 sAddr_74aedc[];
extern const u8 sAddr_74aee4[];
extern const u8 sAddr_74aeec[];
extern const u8 sAddr_74aef4[];
extern const u8 sAddr_74aefc[];
extern const u8 sAddr_74af04[];
extern const u8 sAddr_74af0c[];
extern const u8 sAddr_74af14[];
extern const u8 sAddr_74af1c[];
extern const u8 sAddr_74af42[];
extern const u8 sAddr_74af62[];
extern const u8 sAddr_74af7c[];
extern const u8 sAddr_74af96[];
extern const u8 sAddr_74af9e[];
extern const u8 sAddr_74afa6[];
extern const u8 sAddr_74afae[];
extern const u8 sAddr_74afb6[];
extern const u8 sAddr_74afbe[];
extern const u8 sAddr_74afc6[];
extern const u8 sAddr_74afce[];
extern const u8 sAddr_74afd6[];
extern const u8 sAddr_74afde[];
extern const u8 sAddr_74afe6[];
extern const u8 sAddr_74afee[];
extern const u8 sAddr_74aff6[];
extern const u8 sAddr_74affe[];
extern const u8 sAddr_74b01e[];
extern const u8 sAddr_74b026[];
extern const u8 sAddr_74b02e[];
extern const u8 sAddr_74b036[];
extern const u8 sAddr_74b03e[];
extern const u8 sAddr_74b046[];
extern const u8 sAddr_74b04e[];
extern const u8 sAddr_74b056[];
extern const u8 sAddr_74b05e[];
extern const u8 sAddr_74b066[];
extern const u8 sAddr_74b06e[];
extern const u8 sAddr_74b076[];
extern const u8 sAddr_74b07e[];
extern const u8 sAddr_74b086[];
extern const u8 sAddr_74b08e[];

const u16 sPal_7478A0[] = INCBIN_U16("data/ending/7478a0.pal");

const u32 sCreditsCharacterGfx[] = INCBIN_U32("data/ending/credits_character.gfx");
const u32 sCreditsCopyrightText1_Gfx[] = INCBIN_U32("data/ending/copyright_text_1.gfx");
const u32 sCreditsCopyrightText2_Gfx[] = INCBIN_U32("data/ending/copyright_text_2.gfx");
const u32 sCreditsCopyrightText3_Gfx[] = INCBIN_U32("data/ending/copyright_text_3.gfx");
const u32 sCreditsCopyrightText4_Gfx[] = INCBIN_U32("data/ending/copyright_text_4.gfx");

const u16 sPal_749600[] = INCBIN_U16("data/ending/749600.pal");
const u16 sPal_7496c0[] = INCBIN_U16("data/ending/7496c0.pal");

const u16 sPreResultsSamusWithoutHelmetBgPal[] = INCBIN_U16("data/ending/samus_without_helmet_bg.pal");
const u16 sPreResultsSamusSuitlessBgPal[] = INCBIN_U16("data/ending/samus_suitless_bg.pal");
const u16 sPreResultsSamusObjPal[] = INCBIN_U16("data/ending/samus_obj.pal");

const u16 sOamFrame_749c80[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-18, -75, OAM_DIMS_32x32, OAM_NO_FLIP, 0x0, 2, 0),
    OAM_ENTRY(-10, -43, OAM_DIMS_16x8, OAM_NO_FLIP, 0x47, 2, 0),
    OAM_ENTRY(-34, -43, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-2, -43, OAM_DIMS_32x16, OAM_NO_FLIP, 0x48, 3, 0),
    OAM_ENTRY(-34, -59, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(-34, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0xd, 5, 0),
    OAM_ENTRY(-26, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8e, 5, 0),
    OAM_ENTRY(-18, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 5, 0),
    OAM_ENTRY(14, -59, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa, 1, 0),
    OAM_ENTRY(30, -51, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2c, 4, 0),
    OAM_ENTRY(22, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x6b, 3, 0),
    OAM_ENTRY(6, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 0x89, 6, 0),
    OAM_ENTRY(-10, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x10, 7, 0),
    OAM_ENTRY(-18, -19, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f, 4, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x90, 3, 0),
    OAM_ENTRY(-10, -3, OAM_DIMS_16x32, OAM_NO_FLIP, 0x13, 3, 0),
    OAM_ENTRY(-10, 29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x93, 6, 0),
    OAM_ENTRY(-18, 13, OAM_DIMS_8x32, OAM_NO_FLIP, 0x52, 7, 0),
    OAM_ENTRY(6, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x19, 7, 0),
    OAM_ENTRY(14, 21, OAM_DIMS_16x32, OAM_NO_FLIP, 0x5a, 7, 0),
    OAM_ENTRY(38, 69, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5e, 9, 0),
    OAM_ENTRY(-18, 45, OAM_DIMS_16x32, OAM_NO_FLIP, 0x16, 9, 0),
    OAM_ENTRY(-26, 69, OAM_DIMS_8x8, OAM_NO_FLIP, 0x75, 9, 0),
    OAM_ENTRY(-26, 77, OAM_DIMS_16x8, OAM_NO_FLIP, 0x95, 8, 0),
    OAM_ENTRY(22, 53, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1c, 9, 0),
};

const u16 sOamFrame_749d18[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-34, -75, OAM_DIMS_64x64, OAM_NO_FLIP, 0xc0, 1, 0),
    OAM_ENTRY(30, -75, OAM_DIMS_8x32, OAM_NO_FLIP, 0xc8, 1, 0),
    OAM_ENTRY(30, -43, OAM_DIMS_8x32, OAM_NO_FLIP, 0x148, 1, 0),
    OAM_ENTRY(-34, -11, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1c0, 1, 0),
    OAM_ENTRY(-34, 53, OAM_DIMS_64x32, OAM_NO_FLIP, 0x2c0, 1, 0),
    OAM_ENTRY(30, 53, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c8, 1, 0),
};

const u16 sOamFrame_749d3e[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-30, -76, OAM_DIMS_64x64, OAM_NO_FLIP, 0xca, 1, 0),
    OAM_ENTRY(-30, -12, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1ca, 1, 0),
    OAM_ENTRY(-30, 52, OAM_DIMS_64x32, OAM_NO_FLIP, 0x2ca, 1, 0),
    OAM_ENTRY(34, 52, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2d2, 1, 0),
};

const u16 sEnding_0_Pal[] = INCBIN_U16("data/ending/ending_0.pal");
const u16 sEnding_1_Pal[] = INCBIN_U16("data/ending/ending_1.pal");
const u16 sEnding_2_Pal[] = INCBIN_U16("data/ending/ending_2.pal");
const u16 sEnding_3_Pal[] = INCBIN_U16("data/ending/ending_3.pal");
const u16 sEnding_4_Pal[] = INCBIN_U16("data/ending/ending_4.pal");
const u16 sResultsTextPal[] = INCBIN_U16("data/ending/results_text.pal");

// Bytes come from the extracted file; pointers are relocated by the linker.
extern const u8 sBlob_74a7d8_74b0b0[];
asm("\n\
    .pushsection .rodata\n\
    .global sBlob_74a7d8_74b0b0\n\
sBlob_74a7d8_74b0b0:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x0, 0x20\n\
    .global sAddr_74a7f8\n\
sAddr_74a7f8:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x20, 0x1a\n\
    .global sAddr_74a812\n\
sAddr_74a812:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x3a, 0x14\n\
    .global sAddr_74a826\n\
sAddr_74a826:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4e, 0x8\n\
    .global sAddr_74a82e\n\
sAddr_74a82e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x56, 0x8\n\
    .global sAddr_74a836\n\
sAddr_74a836:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x5e, 0x8\n\
    .global sAddr_74a83e\n\
sAddr_74a83e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x66, 0x8\n\
    .global sAddr_74a846\n\
sAddr_74a846:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6e, 0x8\n\
    .global sAddr_74a84e\n\
sAddr_74a84e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x76, 0x8\n\
    .global sAddr_74a856\n\
sAddr_74a856:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7e, 0x8\n\
    .global sAddr_74a85e\n\
sAddr_74a85e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x86, 0x8\n\
    .global sAddr_74a866\n\
sAddr_74a866:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x8e, 0x8\n\
    .global sAddr_74a86e\n\
sAddr_74a86e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x96, 0x1a\n\
    .global sAddr_74a888\n\
sAddr_74a888:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xb0, 0x8\n\
    .global sAddr_74a890\n\
sAddr_74a890:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xb8, 0x8\n\
    .global sAddr_74a898\n\
sAddr_74a898:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xc0, 0x8\n\
    .global sAddr_74a8a0\n\
sAddr_74a8a0:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xc8, 0x8\n\
    .global sAddr_74a8a8\n\
sAddr_74a8a8:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xd0, 0x8\n\
    .global sAddr_74a8b0\n\
sAddr_74a8b0:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xd8, 0x8\n\
    .global sAddr_74a8b8\n\
sAddr_74a8b8:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xe0, 0x8\n\
    .global sAddr_74a8c0\n\
sAddr_74a8c0:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xe8, 0x8\n\
    .global sAddr_74a8c8\n\
sAddr_74a8c8:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xf0, 0x8\n\
    .global sAddr_74a8d0\n\
sAddr_74a8d0:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0xf8, 0x8\n\
    .global sAddr_74a8d8\n\
sAddr_74a8d8:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x100, 0x8\n\
    .global sAddr_74a8e0\n\
sAddr_74a8e0:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x108, 0x20\n\
    .global sAddr_74a900\n\
sAddr_74a900:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x128, 0x8\n\
    .global sAddr_74a908\n\
sAddr_74a908:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x130, 0x8\n\
    .global sAddr_74a910\n\
sAddr_74a910:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x138, 0x8\n\
    .global sAddr_74a918\n\
sAddr_74a918:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x140, 0x8\n\
    .global sAddr_74a920\n\
sAddr_74a920:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x148, 0x8\n\
    .global sAddr_74a928\n\
sAddr_74a928:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x150, 0x8\n\
    .global sAddr_74a930\n\
sAddr_74a930:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x158, 0x8\n\
    .global sAddr_74a938\n\
sAddr_74a938:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x160, 0x8\n\
    .global sAddr_74a940\n\
sAddr_74a940:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x168, 0x8\n\
    .global sAddr_74a948\n\
sAddr_74a948:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x170, 0x8\n\
    .global sAddr_74a950\n\
sAddr_74a950:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x178, 0x8\n\
    .global sAddr_74a958\n\
sAddr_74a958:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x180, 0x8\n\
    .global sAddr_74a960\n\
sAddr_74a960:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x188, 0x8\n\
    .global sAddr_74a968\n\
sAddr_74a968:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x190, 0x8\n\
    .global sAddr_74a970\n\
sAddr_74a970:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x198, 0x8\n\
    .global sAddr_74a978\n\
sAddr_74a978:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x1a0, 0x8\n\
    .global sAddr_74a980\n\
sAddr_74a980:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x1a8, 0x8\n\
    .global sAddr_74a988\n\
sAddr_74a988:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x1b0, 0x20\n\
    .global sAddr_74a9a8\n\
sAddr_74a9a8:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x1d0, 0x20\n\
    .global sAddr_74a9c8\n\
sAddr_74a9c8:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x1f0, 0x1a\n\
    .global sAddr_74a9e2\n\
sAddr_74a9e2:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x20a, 0x20\n\
    .global sAddr_74aa02\n\
sAddr_74aa02:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x22a, 0x8\n\
    .global sAddr_74aa0a\n\
sAddr_74aa0a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x232, 0x8\n\
    .global sAddr_74aa12\n\
sAddr_74aa12:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x23a, 0x8\n\
    .global sAddr_74aa1a\n\
sAddr_74aa1a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x242, 0x8\n\
    .global sAddr_74aa22\n\
sAddr_74aa22:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x24a, 0x8\n\
    .global sAddr_74aa2a\n\
sAddr_74aa2a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x252, 0x8\n\
    .global sAddr_74aa32\n\
sAddr_74aa32:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x25a, 0x8\n\
    .global sAddr_74aa3a\n\
sAddr_74aa3a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x262, 0x8\n\
    .global sAddr_74aa42\n\
sAddr_74aa42:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x26a, 0x8\n\
    .global sAddr_74aa4a\n\
sAddr_74aa4a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x272, 0x8\n\
    .global sAddr_74aa52\n\
sAddr_74aa52:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x27a, 0x8\n\
    .global sAddr_74aa5a\n\
sAddr_74aa5a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x282, 0x8\n\
    .global sAddr_74aa62\n\
sAddr_74aa62:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x28a, 0x8\n\
    .global sAddr_74aa6a\n\
sAddr_74aa6a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x292, 0x8\n\
    .global sAddr_74aa72\n\
sAddr_74aa72:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x29a, 0x8\n\
    .global sAddr_74aa7a\n\
sAddr_74aa7a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x2a2, 0x8\n\
    .global sAddr_74aa82\n\
sAddr_74aa82:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x2aa, 0x2c\n\
    .global sAddr_74aaae\n\
sAddr_74aaae:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x2d6, 0x8\n\
    .global sAddr_74aab6\n\
sAddr_74aab6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x2de, 0x8\n\
    .global sAddr_74aabe\n\
sAddr_74aabe:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x2e6, 0x8\n\
    .global sAddr_74aac6\n\
sAddr_74aac6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x2ee, 0x8\n\
    .global sAddr_74aace\n\
sAddr_74aace:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x2f6, 0x8\n\
    .global sAddr_74aad6\n\
sAddr_74aad6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x2fe, 0x8\n\
    .global sAddr_74aade\n\
sAddr_74aade:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x306, 0x8\n\
    .global sAddr_74aae6\n\
sAddr_74aae6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x30e, 0x8\n\
    .global sAddr_74aaee\n\
sAddr_74aaee:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x316, 0x8\n\
    .global sAddr_74aaf6\n\
sAddr_74aaf6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x31e, 0x8\n\
    .global sAddr_74aafe\n\
sAddr_74aafe:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x326, 0x8\n\
    .global sAddr_74ab06\n\
sAddr_74ab06:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x32e, 0x8\n\
    .global sAddr_74ab0e\n\
sAddr_74ab0e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x336, 0x8\n\
    .global sAddr_74ab16\n\
sAddr_74ab16:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x33e, 0x8\n\
    .global sAddr_74ab1e\n\
sAddr_74ab1e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x346, 0x8\n\
    .global sAddr_74ab26\n\
sAddr_74ab26:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x34e, 0x8\n\
    .global sAddr_74ab2e\n\
sAddr_74ab2e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x356, 0x8\n\
    .global sAddr_74ab36\n\
sAddr_74ab36:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x35e, 0x8\n\
    .global sAddr_74ab3e\n\
sAddr_74ab3e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x366, 0x8\n\
    .global sAddr_74ab46\n\
sAddr_74ab46:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x36e, 0x8\n\
    .global sAddr_74ab4e\n\
sAddr_74ab4e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x376, 0x14\n\
    .global sAddr_74ab62\n\
sAddr_74ab62:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x38a, 0x20\n\
    .global sAddr_74ab82\n\
sAddr_74ab82:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x3aa, 0x1a\n\
    .global sAddr_74ab9c\n\
sAddr_74ab9c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x3c4, 0x26\n\
    .global sAddr_74abc2\n\
sAddr_74abc2:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x3ea, 0x8\n\
    .global sAddr_74abca\n\
sAddr_74abca:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x3f2, 0x8\n\
    .global sAddr_74abd2\n\
sAddr_74abd2:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x3fa, 0x8\n\
    .global sAddr_74abda\n\
sAddr_74abda:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x402, 0x8\n\
    .global sAddr_74abe2\n\
sAddr_74abe2:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x40a, 0x8\n\
    .global sAddr_74abea\n\
sAddr_74abea:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x412, 0x8\n\
    .global sAddr_74abf2\n\
sAddr_74abf2:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x41a, 0x8\n\
    .global sAddr_74abfa\n\
sAddr_74abfa:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x422, 0x8\n\
    .global sAddr_74ac02\n\
sAddr_74ac02:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x42a, 0x8\n\
    .global sAddr_74ac0a\n\
sAddr_74ac0a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x432, 0x8\n\
    .global sAddr_74ac12\n\
sAddr_74ac12:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x43a, 0x8\n\
    .global sAddr_74ac1a\n\
sAddr_74ac1a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x442, 0x8\n\
    .global sAddr_74ac22\n\
sAddr_74ac22:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x44a, 0x8\n\
    .global sAddr_74ac2a\n\
sAddr_74ac2a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x452, 0x8\n\
    .global sAddr_74ac32\n\
sAddr_74ac32:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x45a, 0x8\n\
    .global sAddr_74ac3a\n\
sAddr_74ac3a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x462, 0x8\n\
    .global sAddr_74ac42\n\
sAddr_74ac42:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x46a, 0x8\n\
    .global sAddr_74ac4a\n\
sAddr_74ac4a:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x472, 0x8\n\
    .global sAddr_74ac52\n\
sAddr_74ac52:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x47a, 0x1a\n\
    .global sAddr_74ac6c\n\
sAddr_74ac6c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x494, 0x8\n\
    .global sAddr_74ac74\n\
sAddr_74ac74:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x49c, 0x8\n\
    .global sAddr_74ac7c\n\
sAddr_74ac7c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4a4, 0x8\n\
    .global sAddr_74ac84\n\
sAddr_74ac84:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4ac, 0x8\n\
    .global sAddr_74ac8c\n\
sAddr_74ac8c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4b4, 0x8\n\
    .global sAddr_74ac94\n\
sAddr_74ac94:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4bc, 0x8\n\
    .global sAddr_74ac9c\n\
sAddr_74ac9c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4c4, 0x8\n\
    .global sAddr_74aca4\n\
sAddr_74aca4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4cc, 0x8\n\
    .global sAddr_74acac\n\
sAddr_74acac:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4d4, 0x8\n\
    .global sAddr_74acb4\n\
sAddr_74acb4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4dc, 0x8\n\
    .global sAddr_74acbc\n\
sAddr_74acbc:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4e4, 0x8\n\
    .global sAddr_74acc4\n\
sAddr_74acc4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x4ec, 0x20\n\
    .global sAddr_74ace4\n\
sAddr_74ace4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x50c, 0x8\n\
    .global sAddr_74acec\n\
sAddr_74acec:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x514, 0x8\n\
    .global sAddr_74acf4\n\
sAddr_74acf4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x51c, 0x8\n\
    .global sAddr_74acfc\n\
sAddr_74acfc:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x524, 0x8\n\
    .global sAddr_74ad04\n\
sAddr_74ad04:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x52c, 0x8\n\
    .global sAddr_74ad0c\n\
sAddr_74ad0c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x534, 0x8\n\
    .global sAddr_74ad14\n\
sAddr_74ad14:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x53c, 0x8\n\
    .global sAddr_74ad1c\n\
sAddr_74ad1c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x544, 0x8\n\
    .global sAddr_74ad24\n\
sAddr_74ad24:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x54c, 0x8\n\
    .global sAddr_74ad2c\n\
sAddr_74ad2c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x554, 0x8\n\
    .global sAddr_74ad34\n\
sAddr_74ad34:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x55c, 0x8\n\
    .global sAddr_74ad3c\n\
sAddr_74ad3c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x564, 0x8\n\
    .global sAddr_74ad44\n\
sAddr_74ad44:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x56c, 0x8\n\
    .global sAddr_74ad4c\n\
sAddr_74ad4c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x574, 0x8\n\
    .global sAddr_74ad54\n\
sAddr_74ad54:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x57c, 0x8\n\
    .global sAddr_74ad5c\n\
sAddr_74ad5c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x584, 0x8\n\
    .global sAddr_74ad64\n\
sAddr_74ad64:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x58c, 0x8\n\
    .global sAddr_74ad6c\n\
sAddr_74ad6c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x594, 0x20\n\
    .global sAddr_74ad8c\n\
sAddr_74ad8c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x5b4, 0x20\n\
    .global sAddr_74adac\n\
sAddr_74adac:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x5d4, 0x1a\n\
    .global sAddr_74adc6\n\
sAddr_74adc6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x5ee, 0x20\n\
    .global sAddr_74ade6\n\
sAddr_74ade6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x60e, 0x8\n\
    .global sAddr_74adee\n\
sAddr_74adee:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x616, 0x8\n\
    .global sAddr_74adf6\n\
sAddr_74adf6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x61e, 0x8\n\
    .global sAddr_74adfe\n\
sAddr_74adfe:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x626, 0x8\n\
    .global sAddr_74ae06\n\
sAddr_74ae06:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x62e, 0x8\n\
    .global sAddr_74ae0e\n\
sAddr_74ae0e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x636, 0x8\n\
    .global sAddr_74ae16\n\
sAddr_74ae16:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x63e, 0x8\n\
    .global sAddr_74ae1e\n\
sAddr_74ae1e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x646, 0x8\n\
    .global sAddr_74ae26\n\
sAddr_74ae26:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x64e, 0x8\n\
    .global sAddr_74ae2e\n\
sAddr_74ae2e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x656, 0x8\n\
    .global sAddr_74ae36\n\
sAddr_74ae36:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x65e, 0x8\n\
    .global sAddr_74ae3e\n\
sAddr_74ae3e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x666, 0x8\n\
    .global sAddr_74ae46\n\
sAddr_74ae46:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x66e, 0x8\n\
    .global sAddr_74ae4e\n\
sAddr_74ae4e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x676, 0x8\n\
    .global sAddr_74ae56\n\
sAddr_74ae56:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x67e, 0x8\n\
    .global sAddr_74ae5e\n\
sAddr_74ae5e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x686, 0x26\n\
    .global sAddr_74ae84\n\
sAddr_74ae84:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6ac, 0x8\n\
    .global sAddr_74ae8c\n\
sAddr_74ae8c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6b4, 0x8\n\
    .global sAddr_74ae94\n\
sAddr_74ae94:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6bc, 0x8\n\
    .global sAddr_74ae9c\n\
sAddr_74ae9c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6c4, 0x8\n\
    .global sAddr_74aea4\n\
sAddr_74aea4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6cc, 0x8\n\
    .global sAddr_74aeac\n\
sAddr_74aeac:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6d4, 0x8\n\
    .global sAddr_74aeb4\n\
sAddr_74aeb4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6dc, 0x8\n\
    .global sAddr_74aebc\n\
sAddr_74aebc:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6e4, 0x8\n\
    .global sAddr_74aec4\n\
sAddr_74aec4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6ec, 0x8\n\
    .global sAddr_74aecc\n\
sAddr_74aecc:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6f4, 0x8\n\
    .global sAddr_74aed4\n\
sAddr_74aed4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x6fc, 0x8\n\
    .global sAddr_74aedc\n\
sAddr_74aedc:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x704, 0x8\n\
    .global sAddr_74aee4\n\
sAddr_74aee4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x70c, 0x8\n\
    .global sAddr_74aeec\n\
sAddr_74aeec:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x714, 0x8\n\
    .global sAddr_74aef4\n\
sAddr_74aef4:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x71c, 0x8\n\
    .global sAddr_74aefc\n\
sAddr_74aefc:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x724, 0x8\n\
    .global sAddr_74af04\n\
sAddr_74af04:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x72c, 0x8\n\
    .global sAddr_74af0c\n\
sAddr_74af0c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x734, 0x8\n\
    .global sAddr_74af14\n\
sAddr_74af14:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x73c, 0x8\n\
    .global sAddr_74af1c\n\
sAddr_74af1c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x744, 0x26\n\
    .global sAddr_74af42\n\
sAddr_74af42:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x76a, 0x20\n\
    .global sAddr_74af62\n\
sAddr_74af62:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x78a, 0x1a\n\
    .global sAddr_74af7c\n\
sAddr_74af7c:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7a4, 0x1a\n\
    .global sAddr_74af96\n\
sAddr_74af96:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7be, 0x8\n\
    .global sAddr_74af9e\n\
sAddr_74af9e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7c6, 0x8\n\
    .global sAddr_74afa6\n\
sAddr_74afa6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7ce, 0x8\n\
    .global sAddr_74afae\n\
sAddr_74afae:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7d6, 0x8\n\
    .global sAddr_74afb6\n\
sAddr_74afb6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7de, 0x8\n\
    .global sAddr_74afbe\n\
sAddr_74afbe:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7e6, 0x8\n\
    .global sAddr_74afc6\n\
sAddr_74afc6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7ee, 0x8\n\
    .global sAddr_74afce\n\
sAddr_74afce:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7f6, 0x8\n\
    .global sAddr_74afd6\n\
sAddr_74afd6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x7fe, 0x8\n\
    .global sAddr_74afde\n\
sAddr_74afde:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x806, 0x8\n\
    .global sAddr_74afe6\n\
sAddr_74afe6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x80e, 0x8\n\
    .global sAddr_74afee\n\
sAddr_74afee:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x816, 0x8\n\
    .global sAddr_74aff6\n\
sAddr_74aff6:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x81e, 0x8\n\
    .global sAddr_74affe\n\
sAddr_74affe:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x826, 0x20\n\
    .global sAddr_74b01e\n\
sAddr_74b01e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x846, 0x8\n\
    .global sAddr_74b026\n\
sAddr_74b026:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x84e, 0x8\n\
    .global sAddr_74b02e\n\
sAddr_74b02e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x856, 0x8\n\
    .global sAddr_74b036\n\
sAddr_74b036:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x85e, 0x8\n\
    .global sAddr_74b03e\n\
sAddr_74b03e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x866, 0x8\n\
    .global sAddr_74b046\n\
sAddr_74b046:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x86e, 0x8\n\
    .global sAddr_74b04e\n\
sAddr_74b04e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x876, 0x8\n\
    .global sAddr_74b056\n\
sAddr_74b056:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x87e, 0x8\n\
    .global sAddr_74b05e\n\
sAddr_74b05e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x886, 0x8\n\
    .global sAddr_74b066\n\
sAddr_74b066:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x88e, 0x8\n\
    .global sAddr_74b06e\n\
sAddr_74b06e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x896, 0x8\n\
    .global sAddr_74b076\n\
sAddr_74b076:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x89e, 0x8\n\
    .global sAddr_74b07e\n\
sAddr_74b07e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x8a6, 0x8\n\
    .global sAddr_74b086\n\
sAddr_74b086:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x8ae, 0x8\n\
    .global sAddr_74b08e\n\
sAddr_74b08e:\n\
    .incbin \"data/Blob_74a7d8_74b0b0.bin\", 0x8b6, 0x22\n\
    .popsection\n\
");

const struct CreditsEntry sCredits[310] = {
	[0] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[1] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[2] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[3] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[4] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[5] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "           PRODUCER"
	},
	[6] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[7] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Izushi Takehiro"
	},
	[8] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = ""
	},
	[9] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[10] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[11] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[12] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[13] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[14] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        CHIEF DIRECTOR"
	},
	[15] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[16] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Sakamoto Yoshio"
	},
	[17] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[18] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[19] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[20] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[21] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[22] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[23] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SYSTEM DIRECTOR"
	},
	[24] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[25] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Hosokawa Takehiko"
	},
	[26] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[27] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[28] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[29] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SCENARIO & STORY"
	},
	[30] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[31] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Sakamoto Yoshio"
	},
	[32] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[33] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[34] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[35] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "          GAME DESIGN"
	},
	[36] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[37] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Yamane Tomoyoshi"
	},
	[38] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[39] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Hosokawa Takehiko"
	},
	[40] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[41] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[42] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[43] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "         COURSE DESIGN"
	},
	[44] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[45] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "          Ueda Masani"
	},
	[46] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[47] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Nakada Ryuichi"
	},
	[48] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[49] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[50] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[51] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        VISUAL DIRECTOR"
	},
	[52] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[53] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamane Tomoyoshi"
	},
	[54] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[55] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[56] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[57] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "         SAMUS DESIGN"
	},
	[58] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[59] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Sano Shinya"
	},
	[60] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[61] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[62] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[63] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "     SAMUS ORIGINAL DESIGN"
	},
	[64] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[65] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Kiyotake Hiroji"
	},
	[66] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[67] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[68] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[69] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "    ENEMY CHARACTER DESIGN"
	},
	[70] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[71] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Yamane Tomoyoshi"
	},
	[72] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[73] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Hirano Isao"
	},
	[74] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[75] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Sano Shinya"
	},
	[76] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[77] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "      Matsushita Tadashi"
	},
	[78] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[79] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[80] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[81] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "   BACKGROUND GRAPHIC DESIGN"
	},
	[82] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[83] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Morisawa Takayasu"
	},
	[84] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[85] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Miyamoto Fumiko"
	},
	[86] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[87] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[88] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[89] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        GRAPHIC DESIGN"
	},
	[90] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[91] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Momose Hiroshi"
	},
	[92] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[93] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Sakiyama Chiharu"
	},
	[94] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[95] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[96] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[97] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "       PROGRAM DIRECTOR"
	},
	[98] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[99] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamano Katsuya"
	},
	[100] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[101] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[102] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[103] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "       SAMUS PROGRAMMING"
	},
	[104] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[105] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Katsuki Yoshinori"
	},
	[106] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[107] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[108] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[109] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = " ENEMY CHARACTER PROGRAMMING"
	},
	[110] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[111] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamano Katsuya"
	},
	[112] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[113] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[114] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[115] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "      SYSTEM PROGRAMMING"
	},
	[116] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[117] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Ozaki Nobuhiro"
	},
	[118] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[119] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[120] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[121] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "   CINEMA SCENE PROGRAMMING"
	},
	[122] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[123] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Nakae Eisaku"
	},
	[124] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[125] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[126] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[127] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "       TOOL PROGRAMMING"
	},
	[128] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[129] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Harada Takahiro"
	},
	[130] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[131] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "          Fukui Kota"
	},
	[132] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[133] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Katsuki Yoshinori"
	},
	[134] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[135] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Ozaki Nobuhiro"
	},
	[136] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[137] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Momose Hiroshi"
	},
	[138] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[139] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[140] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[141] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SOUND DIRECTOR"
	},
	[142] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[143] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamamoto Kenji"
	},
	[144] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[145] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[146] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[147] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "      MUSIC COMPOSITION"
	},
	[148] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[149] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Hamano Minako"
	},
	[150] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[151] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Fujiwara Akira"
	},
	[152] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[153] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[154] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[155] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "  SOUND EFFECTS & PROGRAMMING"
	},
	[156] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[157] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Fujii Takaya"
	},
	[158] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[159] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[160] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[161] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        PACKAGE DESIGN"
	},
	[162] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[163] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Nakamichi Sachiko"
	},
	[164] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[165] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[166] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[167] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        MANUAL DESIGN"
	},
	[168] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[169] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "      Nakamichi Sachiko"
	},
	[170] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[171] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Itani Kiyomi"
	},
	[172] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[173] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Takahashi Yasuko"
	},
	[174] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[175] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[176] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[177] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "         COORDINATION"
	},
	[178] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[179] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Harada Takahiro"
	},
	[180] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[181] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[182] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[183] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "  INTERNATIONAL COORDINATION"
	},
	[184] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[185] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Yamazaki Sakae"
	},
	[186] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[187] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[188] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[189] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "            DEBUG"
	},
	[190] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[191] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       SUPER MARIO CLUB"
	},
	[192] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[193] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[194] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[195] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[196] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[197] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[198] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[199] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SPECIAL THANKS"
	},
	[200] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[201] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Matsumura Satoshi"
	},
	[202] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[203] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "      "
	},
	[204] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[205] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[206] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[207] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[208] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[209] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[210] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[211] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[212] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[213] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[214] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[215] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "   NOA ENGLISH LOCALIZATION"
	},
	[216] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[217] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[218] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "   LOCALIZATION MANAGEMENT"
	},
	[219] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[220] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Jeff Miller"
	},
	[221] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[222] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Leslie Swan"
	},
	[223] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[224] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[225] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[226] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "         LOCALIZATION"
	},
	[227] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[228] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Scot Ritchey"
	},
	[229] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[230] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Nathan Bihldorff"
	},
	[231] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[232] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Tim O-Leary"
	},
	[233] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[234] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[235] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[236] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "       ENGINEERING DEBUG"
	},
	[237] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[238] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Raychole L'Anett"
	},
	[239] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[240] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Robert Crombie"
	},
	[241] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[242] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Kirk Buchanan"
	},
	[243] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[244] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Yoshinobu Mantani"
	},
	[245] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[246] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[247] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[248] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Scott Callahan"
	},
	[249] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[250] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Don Dillinger"
	},
	[251] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[252] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Hisako Sakauchi"
	},
	[253] = {
		.type = CREDIT_LINE_TYPE_RED,
		.text = "               "
	},
	[254] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[255] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[256] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "        SPECIAL THANKS"
	},
	[257] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[258] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "       Tatsumi Kimishima"
	},
	[259] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[260] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Mike Fukuda"
	},
	[261] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[262] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "        Hiroshi Kamada"
	},
	[263] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[264] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[265] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[266] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[267] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[268] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[269] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[270] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[271] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[272] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[273] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[274] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[275] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[276] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[277] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[278] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "      EXECUTIVE PRODUCER"
	},
	[279] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[280] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "         Iwata Satoru"
	},
	[281] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[282] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = ""
	},
	[283] = {
		.type = CREDIT_LINE_TYPE_BLUE,
		.text = "               "
	},
	[284] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[285] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[286] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[287] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[288] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[289] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[290] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[291] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[292] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[293] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[294] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[295] = {
		.type = CREDIT_LINE_TYPE_WHITE_BIG,
		.text = "               "
	},
	[296] = {
		.type = CREDIT_LINE_TYPE_ALL_RIGHTS,
		.text = ""
	},
	[297] = {
		.type = CREDIT_LINE_TYPE_THE_COPYRIGHT,
		.text = ""
	},
	[298] = {
		.type = CREDIT_LINE_TYPE_SCENARIO,
		.text = ""
	},
	[299] = {
		.type = CREDIT_LINE_TYPE_RESERVED,
		.text = ""
	},
	[300] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[301] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[302] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[303] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[304] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[305] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[306] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[307] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[308] = {
		.type = CREDIT_LINE_TYPE_BLANK,
		.text = ""
	},
	[309] = {
		.type = CREDIT_LINE_TYPE_END,
		.text = ""
	},
};

const struct EndingTextLetter sEndingTextLetters_PermanentDefault[6] = {
    [0] = { 2, 0, 0, 120, 40, (const u16*)sAddr_74a812 },
    [1] = { 2, 0, 0, 120, 60, (const u16*)(&sBlob_74a7d8_74b0b0) },
    [2] = { 2, 0, 0, 120, 92, (const u16*)sAddr_74a86e },
    [3] = { 2, 0, 0, 120, 108, (const u16*)sAddr_74a8e0 },
    [4] = { 2, 0, 0, 124, 128, (const u16*)sAddr_74a7f8 },
    [5] = { 2, 0, 0, 120, 158, (const u16*)sAddr_74a988 },
};

const struct EndingTextLetter sEndingTextLetters_Default0[9] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)sAddr_74a826 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)sAddr_74a82e },
    [2] = { 1, 9, 0, 120, 40, (const u16*)sAddr_74a836 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)sAddr_74a83e },
    [4] = { 1, 17, 0, 120, 40, (const u16*)sAddr_74a846 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)sAddr_74a84e },
    [6] = { 1, 25, 0, 120, 40, (const u16*)sAddr_74a856 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)sAddr_74a85e },
    [8] = { 1, 33, 0, 120, 40, (const u16*)sAddr_74a866 },
};

const struct EndingTextLetter sEndingTextLetters_Default1[11] = {
    [0] = { 1, 1, 0, 120, 92, (const u16*)sAddr_74a888 },
    [1] = { 1, 5, 0, 120, 92, (const u16*)sAddr_74a890 },
    [2] = { 1, 9, 0, 120, 92, (const u16*)sAddr_74a898 },
    [3] = { 1, 13, 0, 120, 92, (const u16*)sAddr_74a8a0 },
    [4] = { 1, 17, 0, 120, 92, (const u16*)sAddr_74a8a8 },
    [5] = { 1, 21, 0, 120, 92, (const u16*)sAddr_74a8b0 },
    [6] = { 1, 25, 0, 120, 92, (const u16*)sAddr_74a8b8 },
    [7] = { 1, 29, 0, 120, 92, (const u16*)sAddr_74a8c0 },
    [8] = { 1, 33, 0, 120, 92, (const u16*)sAddr_74a8c8 },
    [9] = { 1, 37, 0, 120, 92, (const u16*)sAddr_74a8d0 },
    [10] = { 1, 41, 0, 120, 92, (const u16*)sAddr_74a8d8 },
};

const struct EndingTextLetter sEndingTextLetters_Default2[17] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)sAddr_74a900 },
    [1] = { 1, 5, 0, 120, 108, (const u16*)sAddr_74a908 },
    [2] = { 1, 9, 0, 120, 108, (const u16*)sAddr_74a910 },
    [3] = { 1, 13, 0, 120, 108, (const u16*)sAddr_74a918 },
    [4] = { 1, 17, 0, 120, 108, (const u16*)sAddr_74a920 },
    [5] = { 1, 21, 0, 120, 108, (const u16*)sAddr_74a928 },
    [6] = { 1, 25, 0, 120, 108, (const u16*)sAddr_74a930 },
    [7] = { 1, 29, 0, 120, 108, (const u16*)sAddr_74a938 },
    [8] = { 1, 33, 0, 120, 108, (const u16*)sAddr_74a940 },
    [9] = { 1, 37, 0, 120, 108, (const u16*)sAddr_74a948 },
    [10] = { 1, 41, 0, 120, 108, (const u16*)sAddr_74a950 },
    [11] = { 1, 45, 0, 120, 108, (const u16*)sAddr_74a958 },
    [12] = { 1, 49, 0, 120, 108, (const u16*)sAddr_74a960 },
    [13] = { 1, 53, 0, 120, 108, (const u16*)sAddr_74a968 },
    [14] = { 1, 57, 0, 120, 108, (const u16*)sAddr_74a970 },
    [15] = { 1, 61, 0, 120, 108, (const u16*)sAddr_74a978 },
    [16] = { 1, 65, 0, 120, 108, (const u16*)sAddr_74a980 },
};

const struct EndingTextLetter sEndingTextLetters_PermanentGerman[6] = {
    [0] = { 2, 0, 0, 120, 40, (const u16*)sAddr_74af7c },
    [1] = { 2, 0, 0, 120, 60, (const u16*)sAddr_74af42 },
    [2] = { 2, 0, 0, 120, 108, (const u16*)sAddr_74b08e },
    [3] = { 2, 0, 0, 120, 108, (const u16*)sAddr_74affe },
    [4] = { 2, 0, 0, 124, 128, (const u16*)sAddr_74af62 },
    [5] = { 2, 0, 0, 120, 158, (const u16*)sAddr_74b08e },
};

const struct EndingTextLetter sEndingTextLetters_German0[13] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)sAddr_74af96 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)sAddr_74af9e },
    [2] = { 1, 9, 0, 120, 40, (const u16*)sAddr_74afa6 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)sAddr_74afae },
    [4] = { 1, 17, 0, 120, 40, (const u16*)sAddr_74afb6 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)sAddr_74afbe },
    [6] = { 1, 25, 0, 120, 40, (const u16*)sAddr_74afc6 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)sAddr_74afce },
    [8] = { 1, 33, 0, 120, 40, (const u16*)sAddr_74afd6 },
    [9] = { 1, 37, 0, 120, 40, (const u16*)sAddr_74afde },
    [10] = { 1, 41, 0, 120, 40, (const u16*)sAddr_74afe6 },
    [11] = { 1, 45, 0, 120, 40, (const u16*)sAddr_74afee },
    [12] = { 1, 49, 0, 120, 40, (const u16*)sAddr_74aff6 },
};

const struct EndingTextLetter sEndingTextLetters_German1[14] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)sAddr_74b01e },
    [1] = { 1, 5, 0, 120, 108, (const u16*)sAddr_74b026 },
    [2] = { 1, 9, 0, 120, 108, (const u16*)sAddr_74b02e },
    [3] = { 1, 13, 0, 120, 108, (const u16*)sAddr_74b036 },
    [4] = { 1, 17, 0, 120, 108, (const u16*)sAddr_74b03e },
    [5] = { 1, 21, 0, 120, 108, (const u16*)sAddr_74b046 },
    [6] = { 1, 25, 0, 120, 108, (const u16*)sAddr_74b04e },
    [7] = { 1, 29, 0, 120, 108, (const u16*)sAddr_74b056 },
    [8] = { 1, 33, 0, 120, 108, (const u16*)sAddr_74b05e },
    [9] = { 1, 37, 0, 120, 108, (const u16*)sAddr_74b066 },
    [10] = { 1, 41, 0, 120, 108, (const u16*)sAddr_74b06e },
    [11] = { 1, 45, 0, 120, 108, (const u16*)sAddr_74b076 },
    [12] = { 1, 49, 0, 120, 108, (const u16*)sAddr_74b07e },
    [13] = { 1, 53, 0, 120, 108, (const u16*)sAddr_74b086 },
};

const struct EndingTextLetter sEndingTextLetters_PermanentFrench[6] = {
    [0] = { 2, 0, 0, 120, 40, (const u16*)sAddr_74a9e2 },
    [1] = { 2, 0, 0, 120, 60, (const u16*)sAddr_74a9a8 },
    [2] = { 2, 0, 0, 120, 108, (const u16*)sAddr_74ab4e },
    [3] = { 2, 0, 0, 120, 108, (const u16*)sAddr_74aa82 },
    [4] = { 2, 0, 0, 124, 128, (const u16*)sAddr_74a9c8 },
    [5] = { 2, 0, 0, 120, 158, (const u16*)sAddr_74ab4e },
};

const struct EndingTextLetter sEndingTextLetters_French0[16] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)sAddr_74aa02 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)sAddr_74aa0a },
    [2] = { 1, 9, 0, 120, 40, (const u16*)sAddr_74aa12 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)sAddr_74aa1a },
    [4] = { 1, 17, 0, 120, 40, (const u16*)sAddr_74aa22 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)sAddr_74aa2a },
    [6] = { 1, 25, 0, 120, 40, (const u16*)sAddr_74aa32 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)sAddr_74aa3a },
    [8] = { 1, 33, 0, 120, 40, (const u16*)sAddr_74aa42 },
    [9] = { 1, 37, 0, 120, 40, (const u16*)sAddr_74aa4a },
    [10] = { 1, 41, 0, 120, 40, (const u16*)sAddr_74aa52 },
    [11] = { 1, 45, 0, 120, 40, (const u16*)sAddr_74aa5a },
    [12] = { 1, 49, 0, 120, 40, (const u16*)sAddr_74aa62 },
    [13] = { 1, 53, 0, 120, 40, (const u16*)sAddr_74aa6a },
    [14] = { 1, 57, 0, 120, 40, (const u16*)sAddr_74aa72 },
    [15] = { 1, 61, 0, 120, 40, (const u16*)sAddr_74aa7a },
};

const struct EndingTextLetter sEndingTextLetters_French1[20] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)sAddr_74aaae },
    [1] = { 1, 5, 0, 120, 108, (const u16*)sAddr_74aab6 },
    [2] = { 1, 9, 0, 120, 108, (const u16*)sAddr_74aabe },
    [3] = { 1, 13, 0, 120, 108, (const u16*)sAddr_74aac6 },
    [4] = { 1, 17, 0, 120, 108, (const u16*)sAddr_74aace },
    [5] = { 1, 21, 0, 120, 108, (const u16*)sAddr_74aad6 },
    [6] = { 1, 25, 0, 120, 108, (const u16*)sAddr_74aade },
    [7] = { 1, 29, 0, 120, 108, (const u16*)sAddr_74aae6 },
    [8] = { 1, 33, 0, 120, 108, (const u16*)sAddr_74aaee },
    [9] = { 1, 37, 0, 120, 108, (const u16*)sAddr_74aaf6 },
    [10] = { 1, 41, 0, 120, 108, (const u16*)sAddr_74aafe },
    [11] = { 1, 45, 0, 120, 108, (const u16*)sAddr_74ab06 },
    [12] = { 1, 49, 0, 120, 108, (const u16*)sAddr_74ab0e },
    [13] = { 1, 53, 0, 120, 108, (const u16*)sAddr_74ab16 },
    [14] = { 1, 57, 0, 120, 108, (const u16*)sAddr_74ab1e },
    [15] = { 1, 61, 0, 120, 108, (const u16*)sAddr_74ab26 },
    [16] = { 1, 65, 0, 120, 108, (const u16*)sAddr_74ab2e },
    [17] = { 1, 69, 0, 120, 108, (const u16*)sAddr_74ab36 },
    [18] = { 1, 73, 0, 120, 108, (const u16*)sAddr_74ab3e },
    [19] = { 1, 77, 0, 120, 108, (const u16*)sAddr_74ab46 },
};

const struct EndingTextLetter sEndingTextLetters_PermanentItalian[6] = {
    [0] = { 2, 0, 0, 120, 40, (const u16*)sAddr_74ab9c },
    [1] = { 2, 0, 0, 120, 60, (const u16*)sAddr_74ab62 },
    [2] = { 2, 0, 0, 120, 92, (const u16*)sAddr_74ac52 },
    [3] = { 2, 0, 0, 120, 108, (const u16*)sAddr_74acc4 },
    [4] = { 2, 0, 0, 124, 128, (const u16*)sAddr_74ab82 },
    [5] = { 2, 0, 0, 120, 158, (const u16*)sAddr_74ad6c },
};

const struct EndingTextLetter sEndingTextLetters_Italian0[18] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)sAddr_74abc2 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)sAddr_74abca },
    [2] = { 1, 9, 0, 120, 40, (const u16*)sAddr_74abd2 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)sAddr_74abda },
    [4] = { 1, 17, 0, 120, 40, (const u16*)sAddr_74abe2 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)sAddr_74abea },
    [6] = { 1, 25, 0, 120, 40, (const u16*)sAddr_74abf2 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)sAddr_74abfa },
    [8] = { 1, 33, 0, 120, 40, (const u16*)sAddr_74ac02 },
    [9] = { 1, 37, 0, 120, 40, (const u16*)sAddr_74ac0a },
    [10] = { 1, 41, 0, 120, 40, (const u16*)sAddr_74ac12 },
    [11] = { 1, 45, 0, 120, 40, (const u16*)sAddr_74ac1a },
    [12] = { 1, 49, 0, 120, 40, (const u16*)sAddr_74ac22 },
    [13] = { 1, 53, 0, 120, 40, (const u16*)sAddr_74ac2a },
    [14] = { 1, 57, 0, 120, 40, (const u16*)sAddr_74ac32 },
    [15] = { 1, 61, 0, 120, 40, (const u16*)sAddr_74ac3a },
    [16] = { 1, 65, 0, 120, 40, (const u16*)sAddr_74ac42 },
    [17] = { 1, 69, 0, 120, 40, (const u16*)sAddr_74ac4a },
};

const struct EndingTextLetter sEndingTextLetters_Italian1[11] = {
    [0] = { 1, 1, 0, 120, 92, (const u16*)sAddr_74ac6c },
    [1] = { 1, 5, 0, 120, 92, (const u16*)sAddr_74ac74 },
    [2] = { 1, 9, 0, 120, 92, (const u16*)sAddr_74ac7c },
    [3] = { 1, 13, 0, 120, 92, (const u16*)sAddr_74ac84 },
    [4] = { 1, 17, 0, 120, 92, (const u16*)sAddr_74ac8c },
    [5] = { 1, 21, 0, 120, 92, (const u16*)sAddr_74ac94 },
    [6] = { 1, 25, 0, 120, 92, (const u16*)sAddr_74ac9c },
    [7] = { 1, 29, 0, 120, 92, (const u16*)sAddr_74aca4 },
    [8] = { 1, 33, 0, 120, 92, (const u16*)sAddr_74acac },
    [9] = { 1, 37, 0, 120, 92, (const u16*)sAddr_74acb4 },
    [10] = { 1, 41, 0, 120, 92, (const u16*)sAddr_74acbc },
};

const struct EndingTextLetter sEndingTextLetters_Italian2[17] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)sAddr_74ace4 },
    [1] = { 1, 5, 0, 120, 108, (const u16*)sAddr_74acec },
    [2] = { 1, 9, 0, 120, 108, (const u16*)sAddr_74acf4 },
    [3] = { 1, 13, 0, 120, 108, (const u16*)sAddr_74acfc },
    [4] = { 1, 17, 0, 120, 108, (const u16*)sAddr_74ad04 },
    [5] = { 1, 21, 0, 120, 108, (const u16*)sAddr_74ad0c },
    [6] = { 1, 25, 0, 120, 108, (const u16*)sAddr_74ad14 },
    [7] = { 1, 29, 0, 120, 108, (const u16*)sAddr_74ad1c },
    [8] = { 1, 33, 0, 120, 108, (const u16*)sAddr_74ad24 },
    [9] = { 1, 37, 0, 120, 108, (const u16*)sAddr_74ad2c },
    [10] = { 1, 41, 0, 120, 108, (const u16*)sAddr_74ad34 },
    [11] = { 1, 45, 0, 120, 108, (const u16*)sAddr_74ad3c },
    [12] = { 1, 49, 0, 120, 108, (const u16*)sAddr_74ad44 },
    [13] = { 1, 53, 0, 120, 108, (const u16*)sAddr_74ad4c },
    [14] = { 1, 57, 0, 120, 108, (const u16*)sAddr_74ad54 },
    [15] = { 1, 61, 0, 120, 108, (const u16*)sAddr_74ad5c },
    [16] = { 1, 65, 0, 120, 108, (const u16*)sAddr_74ad64 },
};

const struct EndingTextLetter sEndingTextLetters_PermanentSpanish[6] = {
    [0] = { 2, 0, 0, 120, 40, (const u16*)sAddr_74adc6 },
    [1] = { 2, 0, 0, 120, 60, (const u16*)sAddr_74ad8c },
    [2] = { 2, 0, 0, 120, 108, (const u16*)sAddr_74af1c },
    [3] = { 2, 0, 0, 120, 108, (const u16*)sAddr_74ae5e },
    [4] = { 2, 0, 0, 124, 128, (const u16*)sAddr_74adac },
    [5] = { 2, 0, 0, 120, 158, (const u16*)sAddr_74af1c },
};

const struct EndingTextLetter sEndingTextLetters_Spanish0[15] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)sAddr_74ade6 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)sAddr_74adee },
    [2] = { 1, 9, 0, 120, 40, (const u16*)sAddr_74adf6 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)sAddr_74adfe },
    [4] = { 1, 17, 0, 120, 40, (const u16*)sAddr_74ae06 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)sAddr_74ae0e },
    [6] = { 1, 25, 0, 120, 40, (const u16*)sAddr_74ae16 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)sAddr_74ae1e },
    [8] = { 1, 33, 0, 120, 40, (const u16*)sAddr_74ae26 },
    [9] = { 1, 37, 0, 120, 40, (const u16*)sAddr_74ae2e },
    [10] = { 1, 41, 0, 120, 40, (const u16*)sAddr_74ae36 },
    [11] = { 1, 45, 0, 120, 40, (const u16*)sAddr_74ae3e },
    [12] = { 1, 49, 0, 120, 40, (const u16*)sAddr_74ae46 },
    [13] = { 1, 53, 0, 120, 40, (const u16*)sAddr_74ae4e },
    [14] = { 1, 57, 0, 120, 40, (const u16*)sAddr_74ae56 },
};

const struct EndingTextLetter sEndingTextLetters_Spanish1[19] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)sAddr_74ae84 },
    [1] = { 1, 5, 0, 120, 108, (const u16*)sAddr_74ae8c },
    [2] = { 1, 9, 0, 120, 108, (const u16*)sAddr_74ae94 },
    [3] = { 1, 13, 0, 120, 108, (const u16*)sAddr_74ae9c },
    [4] = { 1, 17, 0, 120, 108, (const u16*)sAddr_74aea4 },
    [5] = { 1, 21, 0, 120, 108, (const u16*)sAddr_74aeac },
    [6] = { 1, 25, 0, 120, 108, (const u16*)sAddr_74aeb4 },
    [7] = { 1, 29, 0, 120, 108, (const u16*)sAddr_74aebc },
    [8] = { 1, 33, 0, 120, 108, (const u16*)sAddr_74aec4 },
    [9] = { 1, 37, 0, 120, 108, (const u16*)sAddr_74aecc },
    [10] = { 1, 41, 0, 120, 108, (const u16*)sAddr_74aed4 },
    [11] = { 1, 45, 0, 120, 108, (const u16*)sAddr_74aedc },
    [12] = { 1, 49, 0, 120, 108, (const u16*)sAddr_74aee4 },
    [13] = { 1, 53, 0, 120, 108, (const u16*)sAddr_74aeec },
    [14] = { 1, 57, 0, 120, 108, (const u16*)sAddr_74aef4 },
    [15] = { 1, 61, 0, 120, 108, (const u16*)sAddr_74aefc },
    [16] = { 1, 65, 0, 120, 108, (const u16*)sAddr_74af04 },
    [17] = { 1, 69, 0, 120, 108, (const u16*)sAddr_74af0c },
    [18] = { 1, 73, 0, 120, 108, (const u16*)sAddr_74af14 },
};

const u32* const sPreResultsSamusBgGfxPointers1[4] = {
    sPreResultsSamusSuitedGfx3,
    sPreResultsSamusSuitedGfx5,
    sPreResultsSamusSuitedGfx7,
    sPreResultsSamusSuitedGfx9
};

const u32* const sPreResultsSamusBgGfxPointers2[4] = {
    sPreResultsSamusSuitedGfx4,
    sPreResultsSamusSuitedGfx6,
    sPreResultsSamusSuitedGfx8,
    sPreResultsSamusSuitedGfx10
};

const u8* const sPreResultsSamusBgTilemapPointers[4] = {
    sTilemap_75de04,
    sTilemap_75e100,
    sTilemap_75e414,
    sTilemap_75e6fc
};

const u8 sEndingDigitsTopGfx[10 * 64] = INCBIN_U8("data/ending/digits_top.gfx");
const u8 sEndingDigitsBottomGfx[10 * 64] = INCBIN_U8("data/ending/digits_bottom.gfx");

const u32 sPreResultsSpaceBgGfx[] = INCBIN_U32("data/ending/space_bg.gfx.lz");

const u8 sTilemap_7535e0[] = INCBIN_U8("data/ending/7535e0.tm.lz");
const u8 sTilemap_753E80[] = INCBIN_U8("data/ending/753e80.tm.lz");

const u32 sPreResultsSamusSuitedGfx1[] = INCBIN_U32("data/ending/samus_suited_1.gfx.lz");
const u32 sPreResultsSamusSuitedGfx2[] = INCBIN_U32("data/ending/samus_suited_2.gfx.lz");
const u32 sPreResultsSamusSuitedGfx3[] = INCBIN_U32("data/ending/samus_suited_3.gfx.lz");
const u32 sPreResultsSamusSuitedGfx4[] = INCBIN_U32("data/ending/samus_suited_4.gfx.lz");
const u32 sPreResultsSamusSuitedGfx5[] = INCBIN_U32("data/ending/samus_suited_5.gfx.lz");
const u32 sPreResultsSamusSuitedGfx6[] = INCBIN_U32("data/ending/samus_suited_6.gfx.lz");
const u32 sPreResultsSamusSuitedGfx7[] = INCBIN_U32("data/ending/samus_suited_7.gfx.lz");
const u32 sPreResultsSamusSuitedGfx8[] = INCBIN_U32("data/ending/samus_suited_8.gfx.lz");
const u32 sPreResultsSamusSuitedGfx9[] = INCBIN_U32("data/ending/samus_suited_9.gfx.lz");
const u32 sPreResultsSamusSuitedGfx10[] = INCBIN_U32("data/ending/samus_suited_10.gfx.lz");

const u32 sPreResultsSamusWithoutHelmetBgGfx1[] = INCBIN_U32("data/ending/samus_without_helmet_bg_1.gfx.lz");
const u32 sPreResultsSamusWithoutHelmetBgGfx2[] = INCBIN_U32("data/ending/samus_without_helmet_bg_2.gfx.lz");
const u32 sPreResultsSamusSuitlessBgGfx1[] = INCBIN_U32("data/ending/samus_suitless_bg_1.gfx.lz");
const u32 sPreResultsSamusSuitlessBgGfx2[] = INCBIN_U32("data/ending/samus_suitless_bg_2.gfx.lz");

const u8 sTilemap_75db50[] = INCBIN_U8("data/ending/75db50.tm.lz");
const u8 sTilemap_75de04[] = INCBIN_U8("data/ending/75de04.tm.lz");
const u8 sTilemap_75e100[] = INCBIN_U8("data/ending/75e100.tm.lz");
const u8 sTilemap_75e414[] = INCBIN_U8("data/ending/75e414.tm.lz");
const u8 sTilemap_75e6fc[] = INCBIN_U8("data/ending/75e6fc.tm.lz");
const u8 sTilemap_75E990[] = INCBIN_U8("data/ending/75e990.tm.lz");
const u8 sTilemap_75EB94[] = INCBIN_U8("data/ending/75eb94.tm.lz");

const u32 sPreResultsSamusObjGfx[] = INCBIN_U32("data/ending/samus_obj.gfx.lz");

const u32 sEnding_0_GfxTop[] = INCBIN_U32("data/ending/ending_0_top.gfx.lz");
const u32 sEnding_0_GfxBottom[] = INCBIN_U32("data/ending/ending_0_bottom.gfx.lz");
const u32 sEnding_1_GfxTop[] = INCBIN_U32("data/ending/ending_1_top.gfx.lz");
const u32 sEnding_1_GfxBottom[] = INCBIN_U32("data/ending/ending_1_bottom.gfx.lz");
const u32 sEnding_2_GfxTop[] = INCBIN_U32("data/ending/ending_2_top.gfx.lz");
const u32 sEnding_2_GfxBottom[] = INCBIN_U32("data/ending/ending_2_bottom.gfx.lz");
const u32 sEnding_3_GfxTop[] = INCBIN_U32("data/ending/ending_3_top.gfx.lz");
const u32 sEnding_3_GfxBottom[] = INCBIN_U32("data/ending/ending_3_bottom.gfx.lz");
const u32 sEnding_4_GfxTop[] = INCBIN_U32("data/ending/ending_4_top.gfx.lz");
const u32 sEnding_4_GfxBottom[] = INCBIN_U32("data/ending/ending_4_bottom.gfx.lz");

const u8 sEnding_0_TilemapTop[] = INCBIN_U8("data/ending/ending_0_top.tm.lz");
const u8 sEnding_0_TilemapBottom[] = INCBIN_U8("data/ending/ending_0_bottom.tm.lz");
const u8 sEnding_1_TilemapTop[] = INCBIN_U8("data/ending/ending_1_top.tm.lz");
const u8 sEnding_1_TilemapBottom[] = INCBIN_U8("data/ending/ending_1_bottom.tm.lz");
const u8 sEnding_2_TilemapTop[] = INCBIN_U8("data/ending/ending_2_top.tm.lz");
const u8 sEnding_2_TilemapBottom[] = INCBIN_U8("data/ending/ending_2_bottom.tm.lz");
const u8 sEnding_3_TilemapTop[] = INCBIN_U8("data/ending/ending_3_top.tm.lz");
const u8 sEnding_3_TilemapBottom[] = INCBIN_U8("data/ending/ending_3_bottom.tm.lz");
const u8 sEnding_4_TilemapTop[] = INCBIN_U8("data/ending/ending_4_top.tm.lz");
const u8 sEnding_4_TilemapBottom[] = INCBIN_U8("data/ending/ending_4_bottom.tm.lz");

const u32 sResultsScreenEnglishTextGfx[] = INCBIN_U32("data/ending/results_english_text.gfx.lz");
const u32 sResultsScreenFrenchTextGfx[] = INCBIN_U32("data/ending/results_french_text.gfx.lz");
const u32 sResultsScreenItalianTextGfx[] = INCBIN_U32("data/ending/results_italian_text.gfx.lz");
const u32 sResultsScreenSpanishTextGfx[] = INCBIN_U32("data/ending/results_spanish_text.gfx.lz");
const u32 sResultsScreenGermanTextGfx[] = INCBIN_U32("data/ending/results_german_text.gfx.lz");

const u8 sBlob_79a19c_79a29c[] = INCBIN_U8("data/Blob_79a19c_79a29c.bin");
