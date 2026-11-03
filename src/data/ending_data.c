#include "macros.h"
#include "oam.h"

#include "data/ending_data.h"

#include "structs/ending.h"

#include "constants/ending.h"

#include "gba/memory.h"

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

static const u8 sBlob_74a7d8_74b0b0[] = INCBIN_U8("data/Blob_74a7d8_74b0b0.bin");

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
    [0] = { 2, 0, 0, 120, 40, (const u16*)0x874a812 },
    [1] = { 2, 0, 0, 120, 60, (const u16*)0x874a7d8 },
    [2] = { 2, 0, 0, 120, 92, (const u16*)0x874a86e },
    [3] = { 2, 0, 0, 120, 108, (const u16*)0x874a8e0 },
    [4] = { 2, 0, 0, 124, 128, (const u16*)0x874a7f8 },
    [5] = { 2, 0, 0, 120, 158, (const u16*)0x874a988 },
};

const struct EndingTextLetter sEndingTextLetters_Default0[9] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)0x874a826 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)0x874a82e },
    [2] = { 1, 9, 0, 120, 40, (const u16*)0x874a836 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)0x874a83e },
    [4] = { 1, 17, 0, 120, 40, (const u16*)0x874a846 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)0x874a84e },
    [6] = { 1, 25, 0, 120, 40, (const u16*)0x874a856 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)0x874a85e },
    [8] = { 1, 33, 0, 120, 40, (const u16*)0x874a866 },
};

const struct EndingTextLetter sEndingTextLetters_Default1[11] = {
    [0] = { 1, 1, 0, 120, 92, (const u16*)0x874a888 },
    [1] = { 1, 5, 0, 120, 92, (const u16*)0x874a890 },
    [2] = { 1, 9, 0, 120, 92, (const u16*)0x874a898 },
    [3] = { 1, 13, 0, 120, 92, (const u16*)0x874a8a0 },
    [4] = { 1, 17, 0, 120, 92, (const u16*)0x874a8a8 },
    [5] = { 1, 21, 0, 120, 92, (const u16*)0x874a8b0 },
    [6] = { 1, 25, 0, 120, 92, (const u16*)0x874a8b8 },
    [7] = { 1, 29, 0, 120, 92, (const u16*)0x874a8c0 },
    [8] = { 1, 33, 0, 120, 92, (const u16*)0x874a8c8 },
    [9] = { 1, 37, 0, 120, 92, (const u16*)0x874a8d0 },
    [10] = { 1, 41, 0, 120, 92, (const u16*)0x874a8d8 },
};

const struct EndingTextLetter sEndingTextLetters_Default2[17] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)0x874a900 },
    [1] = { 1, 5, 0, 120, 108, (const u16*)0x874a908 },
    [2] = { 1, 9, 0, 120, 108, (const u16*)0x874a910 },
    [3] = { 1, 13, 0, 120, 108, (const u16*)0x874a918 },
    [4] = { 1, 17, 0, 120, 108, (const u16*)0x874a920 },
    [5] = { 1, 21, 0, 120, 108, (const u16*)0x874a928 },
    [6] = { 1, 25, 0, 120, 108, (const u16*)0x874a930 },
    [7] = { 1, 29, 0, 120, 108, (const u16*)0x874a938 },
    [8] = { 1, 33, 0, 120, 108, (const u16*)0x874a940 },
    [9] = { 1, 37, 0, 120, 108, (const u16*)0x874a948 },
    [10] = { 1, 41, 0, 120, 108, (const u16*)0x874a950 },
    [11] = { 1, 45, 0, 120, 108, (const u16*)0x874a958 },
    [12] = { 1, 49, 0, 120, 108, (const u16*)0x874a960 },
    [13] = { 1, 53, 0, 120, 108, (const u16*)0x874a968 },
    [14] = { 1, 57, 0, 120, 108, (const u16*)0x874a970 },
    [15] = { 1, 61, 0, 120, 108, (const u16*)0x874a978 },
    [16] = { 1, 65, 0, 120, 108, (const u16*)0x874a980 },
};

const struct EndingTextLetter sEndingTextLetters_PermanentGerman[6] = {
    [0] = { 2, 0, 0, 120, 40, (const u16*)0x874af7c },
    [1] = { 2, 0, 0, 120, 60, (const u16*)0x874af42 },
    [2] = { 2, 0, 0, 120, 108, (const u16*)0x874b08e },
    [3] = { 2, 0, 0, 120, 108, (const u16*)0x874affe },
    [4] = { 2, 0, 0, 124, 128, (const u16*)0x874af62 },
    [5] = { 2, 0, 0, 120, 158, (const u16*)0x874b08e },
};

const struct EndingTextLetter sEndingTextLetters_German0[13] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)0x874af96 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)0x874af9e },
    [2] = { 1, 9, 0, 120, 40, (const u16*)0x874afa6 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)0x874afae },
    [4] = { 1, 17, 0, 120, 40, (const u16*)0x874afb6 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)0x874afbe },
    [6] = { 1, 25, 0, 120, 40, (const u16*)0x874afc6 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)0x874afce },
    [8] = { 1, 33, 0, 120, 40, (const u16*)0x874afd6 },
    [9] = { 1, 37, 0, 120, 40, (const u16*)0x874afde },
    [10] = { 1, 41, 0, 120, 40, (const u16*)0x874afe6 },
    [11] = { 1, 45, 0, 120, 40, (const u16*)0x874afee },
    [12] = { 1, 49, 0, 120, 40, (const u16*)0x874aff6 },
};

const struct EndingTextLetter sEndingTextLetters_German1[14] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)0x874b01e },
    [1] = { 1, 5, 0, 120, 108, (const u16*)0x874b026 },
    [2] = { 1, 9, 0, 120, 108, (const u16*)0x874b02e },
    [3] = { 1, 13, 0, 120, 108, (const u16*)0x874b036 },
    [4] = { 1, 17, 0, 120, 108, (const u16*)0x874b03e },
    [5] = { 1, 21, 0, 120, 108, (const u16*)0x874b046 },
    [6] = { 1, 25, 0, 120, 108, (const u16*)0x874b04e },
    [7] = { 1, 29, 0, 120, 108, (const u16*)0x874b056 },
    [8] = { 1, 33, 0, 120, 108, (const u16*)0x874b05e },
    [9] = { 1, 37, 0, 120, 108, (const u16*)0x874b066 },
    [10] = { 1, 41, 0, 120, 108, (const u16*)0x874b06e },
    [11] = { 1, 45, 0, 120, 108, (const u16*)0x874b076 },
    [12] = { 1, 49, 0, 120, 108, (const u16*)0x874b07e },
    [13] = { 1, 53, 0, 120, 108, (const u16*)0x874b086 },
};

const struct EndingTextLetter sEndingTextLetters_PermanentFrench[6] = {
    [0] = { 2, 0, 0, 120, 40, (const u16*)0x874a9e2 },
    [1] = { 2, 0, 0, 120, 60, (const u16*)0x874a9a8 },
    [2] = { 2, 0, 0, 120, 108, (const u16*)0x874ab4e },
    [3] = { 2, 0, 0, 120, 108, (const u16*)0x874aa82 },
    [4] = { 2, 0, 0, 124, 128, (const u16*)0x874a9c8 },
    [5] = { 2, 0, 0, 120, 158, (const u16*)0x874ab4e },
};

const struct EndingTextLetter sEndingTextLetters_French0[16] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)0x874aa02 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)0x874aa0a },
    [2] = { 1, 9, 0, 120, 40, (const u16*)0x874aa12 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)0x874aa1a },
    [4] = { 1, 17, 0, 120, 40, (const u16*)0x874aa22 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)0x874aa2a },
    [6] = { 1, 25, 0, 120, 40, (const u16*)0x874aa32 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)0x874aa3a },
    [8] = { 1, 33, 0, 120, 40, (const u16*)0x874aa42 },
    [9] = { 1, 37, 0, 120, 40, (const u16*)0x874aa4a },
    [10] = { 1, 41, 0, 120, 40, (const u16*)0x874aa52 },
    [11] = { 1, 45, 0, 120, 40, (const u16*)0x874aa5a },
    [12] = { 1, 49, 0, 120, 40, (const u16*)0x874aa62 },
    [13] = { 1, 53, 0, 120, 40, (const u16*)0x874aa6a },
    [14] = { 1, 57, 0, 120, 40, (const u16*)0x874aa72 },
    [15] = { 1, 61, 0, 120, 40, (const u16*)0x874aa7a },
};

const struct EndingTextLetter sEndingTextLetters_French1[20] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)0x874aaae },
    [1] = { 1, 5, 0, 120, 108, (const u16*)0x874aab6 },
    [2] = { 1, 9, 0, 120, 108, (const u16*)0x874aabe },
    [3] = { 1, 13, 0, 120, 108, (const u16*)0x874aac6 },
    [4] = { 1, 17, 0, 120, 108, (const u16*)0x874aace },
    [5] = { 1, 21, 0, 120, 108, (const u16*)0x874aad6 },
    [6] = { 1, 25, 0, 120, 108, (const u16*)0x874aade },
    [7] = { 1, 29, 0, 120, 108, (const u16*)0x874aae6 },
    [8] = { 1, 33, 0, 120, 108, (const u16*)0x874aaee },
    [9] = { 1, 37, 0, 120, 108, (const u16*)0x874aaf6 },
    [10] = { 1, 41, 0, 120, 108, (const u16*)0x874aafe },
    [11] = { 1, 45, 0, 120, 108, (const u16*)0x874ab06 },
    [12] = { 1, 49, 0, 120, 108, (const u16*)0x874ab0e },
    [13] = { 1, 53, 0, 120, 108, (const u16*)0x874ab16 },
    [14] = { 1, 57, 0, 120, 108, (const u16*)0x874ab1e },
    [15] = { 1, 61, 0, 120, 108, (const u16*)0x874ab26 },
    [16] = { 1, 65, 0, 120, 108, (const u16*)0x874ab2e },
    [17] = { 1, 69, 0, 120, 108, (const u16*)0x874ab36 },
    [18] = { 1, 73, 0, 120, 108, (const u16*)0x874ab3e },
    [19] = { 1, 77, 0, 120, 108, (const u16*)0x874ab46 },
};

const struct EndingTextLetter sEndingTextLetters_PermanentItalian[6] = {
    [0] = { 2, 0, 0, 120, 40, (const u16*)0x874ab9c },
    [1] = { 2, 0, 0, 120, 60, (const u16*)0x874ab62 },
    [2] = { 2, 0, 0, 120, 92, (const u16*)0x874ac52 },
    [3] = { 2, 0, 0, 120, 108, (const u16*)0x874acc4 },
    [4] = { 2, 0, 0, 124, 128, (const u16*)0x874ab82 },
    [5] = { 2, 0, 0, 120, 158, (const u16*)0x874ad6c },
};

const struct EndingTextLetter sEndingTextLetters_Italian0[18] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)0x874abc2 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)0x874abca },
    [2] = { 1, 9, 0, 120, 40, (const u16*)0x874abd2 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)0x874abda },
    [4] = { 1, 17, 0, 120, 40, (const u16*)0x874abe2 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)0x874abea },
    [6] = { 1, 25, 0, 120, 40, (const u16*)0x874abf2 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)0x874abfa },
    [8] = { 1, 33, 0, 120, 40, (const u16*)0x874ac02 },
    [9] = { 1, 37, 0, 120, 40, (const u16*)0x874ac0a },
    [10] = { 1, 41, 0, 120, 40, (const u16*)0x874ac12 },
    [11] = { 1, 45, 0, 120, 40, (const u16*)0x874ac1a },
    [12] = { 1, 49, 0, 120, 40, (const u16*)0x874ac22 },
    [13] = { 1, 53, 0, 120, 40, (const u16*)0x874ac2a },
    [14] = { 1, 57, 0, 120, 40, (const u16*)0x874ac32 },
    [15] = { 1, 61, 0, 120, 40, (const u16*)0x874ac3a },
    [16] = { 1, 65, 0, 120, 40, (const u16*)0x874ac42 },
    [17] = { 1, 69, 0, 120, 40, (const u16*)0x874ac4a },
};

const struct EndingTextLetter sEndingTextLetters_Italian1[11] = {
    [0] = { 1, 1, 0, 120, 92, (const u16*)0x874ac6c },
    [1] = { 1, 5, 0, 120, 92, (const u16*)0x874ac74 },
    [2] = { 1, 9, 0, 120, 92, (const u16*)0x874ac7c },
    [3] = { 1, 13, 0, 120, 92, (const u16*)0x874ac84 },
    [4] = { 1, 17, 0, 120, 92, (const u16*)0x874ac8c },
    [5] = { 1, 21, 0, 120, 92, (const u16*)0x874ac94 },
    [6] = { 1, 25, 0, 120, 92, (const u16*)0x874ac9c },
    [7] = { 1, 29, 0, 120, 92, (const u16*)0x874aca4 },
    [8] = { 1, 33, 0, 120, 92, (const u16*)0x874acac },
    [9] = { 1, 37, 0, 120, 92, (const u16*)0x874acb4 },
    [10] = { 1, 41, 0, 120, 92, (const u16*)0x874acbc },
};

const struct EndingTextLetter sEndingTextLetters_Italian2[17] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)0x874ace4 },
    [1] = { 1, 5, 0, 120, 108, (const u16*)0x874acec },
    [2] = { 1, 9, 0, 120, 108, (const u16*)0x874acf4 },
    [3] = { 1, 13, 0, 120, 108, (const u16*)0x874acfc },
    [4] = { 1, 17, 0, 120, 108, (const u16*)0x874ad04 },
    [5] = { 1, 21, 0, 120, 108, (const u16*)0x874ad0c },
    [6] = { 1, 25, 0, 120, 108, (const u16*)0x874ad14 },
    [7] = { 1, 29, 0, 120, 108, (const u16*)0x874ad1c },
    [8] = { 1, 33, 0, 120, 108, (const u16*)0x874ad24 },
    [9] = { 1, 37, 0, 120, 108, (const u16*)0x874ad2c },
    [10] = { 1, 41, 0, 120, 108, (const u16*)0x874ad34 },
    [11] = { 1, 45, 0, 120, 108, (const u16*)0x874ad3c },
    [12] = { 1, 49, 0, 120, 108, (const u16*)0x874ad44 },
    [13] = { 1, 53, 0, 120, 108, (const u16*)0x874ad4c },
    [14] = { 1, 57, 0, 120, 108, (const u16*)0x874ad54 },
    [15] = { 1, 61, 0, 120, 108, (const u16*)0x874ad5c },
    [16] = { 1, 65, 0, 120, 108, (const u16*)0x874ad64 },
};

const struct EndingTextLetter sEndingTextLetters_PermanentSpanish[6] = {
    [0] = { 2, 0, 0, 120, 40, (const u16*)0x874adc6 },
    [1] = { 2, 0, 0, 120, 60, (const u16*)0x874ad8c },
    [2] = { 2, 0, 0, 120, 108, (const u16*)0x874af1c },
    [3] = { 2, 0, 0, 120, 108, (const u16*)0x874ae5e },
    [4] = { 2, 0, 0, 124, 128, (const u16*)0x874adac },
    [5] = { 2, 0, 0, 120, 158, (const u16*)0x874af1c },
};

const struct EndingTextLetter sEndingTextLetters_Spanish0[15] = {
    [0] = { 1, 1, 0, 120, 40, (const u16*)0x874ade6 },
    [1] = { 1, 5, 0, 120, 40, (const u16*)0x874adee },
    [2] = { 1, 9, 0, 120, 40, (const u16*)0x874adf6 },
    [3] = { 1, 13, 0, 120, 40, (const u16*)0x874adfe },
    [4] = { 1, 17, 0, 120, 40, (const u16*)0x874ae06 },
    [5] = { 1, 21, 0, 120, 40, (const u16*)0x874ae0e },
    [6] = { 1, 25, 0, 120, 40, (const u16*)0x874ae16 },
    [7] = { 1, 29, 0, 120, 40, (const u16*)0x874ae1e },
    [8] = { 1, 33, 0, 120, 40, (const u16*)0x874ae26 },
    [9] = { 1, 37, 0, 120, 40, (const u16*)0x874ae2e },
    [10] = { 1, 41, 0, 120, 40, (const u16*)0x874ae36 },
    [11] = { 1, 45, 0, 120, 40, (const u16*)0x874ae3e },
    [12] = { 1, 49, 0, 120, 40, (const u16*)0x874ae46 },
    [13] = { 1, 53, 0, 120, 40, (const u16*)0x874ae4e },
    [14] = { 1, 57, 0, 120, 40, (const u16*)0x874ae56 },
};

const struct EndingTextLetter sEndingTextLetters_Spanish1[19] = {
    [0] = { 1, 1, 0, 120, 108, (const u16*)0x874ae84 },
    [1] = { 1, 5, 0, 120, 108, (const u16*)0x874ae8c },
    [2] = { 1, 9, 0, 120, 108, (const u16*)0x874ae94 },
    [3] = { 1, 13, 0, 120, 108, (const u16*)0x874ae9c },
    [4] = { 1, 17, 0, 120, 108, (const u16*)0x874aea4 },
    [5] = { 1, 21, 0, 120, 108, (const u16*)0x874aeac },
    [6] = { 1, 25, 0, 120, 108, (const u16*)0x874aeb4 },
    [7] = { 1, 29, 0, 120, 108, (const u16*)0x874aebc },
    [8] = { 1, 33, 0, 120, 108, (const u16*)0x874aec4 },
    [9] = { 1, 37, 0, 120, 108, (const u16*)0x874aecc },
    [10] = { 1, 41, 0, 120, 108, (const u16*)0x874aed4 },
    [11] = { 1, 45, 0, 120, 108, (const u16*)0x874aedc },
    [12] = { 1, 49, 0, 120, 108, (const u16*)0x874aee4 },
    [13] = { 1, 53, 0, 120, 108, (const u16*)0x874aeec },
    [14] = { 1, 57, 0, 120, 108, (const u16*)0x874aef4 },
    [15] = { 1, 61, 0, 120, 108, (const u16*)0x874aefc },
    [16] = { 1, 65, 0, 120, 108, (const u16*)0x874af04 },
    [17] = { 1, 69, 0, 120, 108, (const u16*)0x874af0c },
    [18] = { 1, 73, 0, 120, 108, (const u16*)0x874af14 },
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

static const u8 sBlob_79a19c_79a29c[] = INCBIN_U8("data/Blob_79a19c_79a29c.bin");
