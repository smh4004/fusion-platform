#ifndef ENDING_DATA_H
#define ENDING_DATA_H

#include "macros.h"

#include "gba/memory.h"

extern const u16 sPal_7478A0[];

extern const u32 sCreditsCharacterGfx[];
extern const u32 sCreditsCopyrightText1_Gfx[];
extern const u32 sCreditsCopyrightText2_Gfx[];
extern const u32 sCreditsCopyrightText3_Gfx[];
extern const u32 sCreditsCopyrightText4_Gfx[];

extern const u16 sPal_749600[];
extern const u16 sPal_7496c0[];

extern const u16 sPreResultsSamusWithoutHelmetBgPal[];
extern const u16 sPreResultsSamusSuitlessBgPal[];
extern const u16 sPreResultsSamusObjPal[];

extern const u16 sOamFrame_749c80[OAM_DATA_SIZE(25)];
extern const u16 sOamFrame_749d18[OAM_DATA_SIZE(6)];
extern const u16 sOamFrame_749d3e[OAM_DATA_SIZE(4)];

extern const u16 sEnding_0_Pal[];
extern const u16 sEnding_1_Pal[];
extern const u16 sEnding_2_Pal[];
extern const u16 sEnding_3_Pal[];
extern const u16 sEnding_4_Pal[];
extern const u16 sResultsTextPal[];

extern const struct CreditsEntry sCredits[310];

extern const struct EndingTextLetter sEndingTextLetters_PermanentDefault[6];
extern const struct EndingTextLetter sEndingTextLetters_Default0[9];
extern const struct EndingTextLetter sEndingTextLetters_Default1[11];
extern const struct EndingTextLetter sEndingTextLetters_Default2[17];
extern const struct EndingTextLetter sEndingTextLetters_PermanentGerman[6];
extern const struct EndingTextLetter sEndingTextLetters_German0[13];
extern const struct EndingTextLetter sEndingTextLetters_German1[14];
extern const struct EndingTextLetter sEndingTextLetters_PermanentFrench[6];
extern const struct EndingTextLetter sEndingTextLetters_French0[16];
extern const struct EndingTextLetter sEndingTextLetters_French1[20];
extern const struct EndingTextLetter sEndingTextLetters_PermanentItalian[6];
extern const struct EndingTextLetter sEndingTextLetters_Italian0[18];
extern const struct EndingTextLetter sEndingTextLetters_Italian1[11];
extern const struct EndingTextLetter sEndingTextLetters_Italian2[17];
extern const struct EndingTextLetter sEndingTextLetters_PermanentSpanish[6];
extern const struct EndingTextLetter sEndingTextLetters_Spanish0[15];
extern const struct EndingTextLetter sEndingTextLetters_Spanish1[19];

extern const u32* const sPreResultsSamusBgGfxPointers1[4];
extern const u32* const sPreResultsSamusBgGfxPointers2[4];
extern const u8* const sPreResultsSamusBgTilemapPointers[4];

extern const u8 sEndingDigitsTopGfx[10 * 64];
extern const u8 sEndingDigitsBottomGfx[10 * 64];

extern const u32 sPreResultsSpaceBgGfx[];

extern const u8 sTilemap_7535e0[];
extern const u8 sTilemap_753E80[];

extern const u32 sPreResultsSamusSuitedGfx1[];
extern const u32 sPreResultsSamusSuitedGfx2[];
extern const u32 sPreResultsSamusSuitedGfx3[];
extern const u32 sPreResultsSamusSuitedGfx4[];
extern const u32 sPreResultsSamusSuitedGfx5[];
extern const u32 sPreResultsSamusSuitedGfx6[];
extern const u32 sPreResultsSamusSuitedGfx7[];
extern const u32 sPreResultsSamusSuitedGfx8[];
extern const u32 sPreResultsSamusSuitedGfx9[];
extern const u32 sPreResultsSamusSuitedGfx10[];

extern const u32 sPreResultsSamusWithoutHelmetBgGfx1[];
extern const u32 sPreResultsSamusWithoutHelmetBgGfx2[];
extern const u32 sPreResultsSamusSuitlessBgGfx1[];
extern const u32 sPreResultsSamusSuitlessBgGfx2[];

extern const u8 sTilemap_75db50[];
extern const u8 sTilemap_75de04[];
extern const u8 sTilemap_75e100[];
extern const u8 sTilemap_75e414[];
extern const u8 sTilemap_75e6fc[];
extern const u8 sTilemap_75E990[];
extern const u8 sTilemap_75EB94[];

extern const u32 sPreResultsSamusObjGfx[];

extern const u32 sEnding_0_GfxTop[];
extern const u32 sEnding_0_GfxBottom[];
extern const u32 sEnding_1_GfxTop[];
extern const u32 sEnding_1_GfxBottom[];
extern const u32 sEnding_2_GfxTop[];
extern const u32 sEnding_2_GfxBottom[];
extern const u32 sEnding_3_GfxTop[];
extern const u32 sEnding_3_GfxBottom[];
extern const u32 sEnding_4_GfxTop[];
extern const u32 sEnding_4_GfxBottom[];

extern const u8 sEnding_0_TilemapTop[];
extern const u8 sEnding_0_TilemapBottom[];
extern const u8 sEnding_1_TilemapTop[];
extern const u8 sEnding_1_TilemapBottom[];
extern const u8 sEnding_2_TilemapTop[];
extern const u8 sEnding_2_TilemapBottom[];
extern const u8 sEnding_3_TilemapTop[];
extern const u8 sEnding_3_TilemapBottom[];
extern const u8 sEnding_4_TilemapTop[];
extern const u8 sEnding_4_TilemapBottom[];

extern const u32 sResultsScreenEnglishTextGfx[];
extern const u32 sResultsScreenFrenchTextGfx[];
extern const u32 sResultsScreenItalianTextGfx[];
extern const u32 sResultsScreenSpanishTextGfx[];
extern const u32 sResultsScreenGermanTextGfx[];

#endif /* ENDING_DATA_H */
