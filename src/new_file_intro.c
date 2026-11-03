#include "globals.h"
#include "new_file_intro.h"
#include "music_wrappers.h"

#include "constants/game_state.h"
#include "constants/audio.h"
#include "constants/text.h"
#include "constants/new_file_intro.h"

#include "structs/cutscene.h"

#include "data/intro_data.h"
#include "data/generic_data.h"
#include "data/menus/title_screen.h"
#include "data/sprite_data.h"
#include "data/sprites/hornoad.h"
#include "data/sprites/x_parasite.h"
#include "data/projectile_data.h"
#include "data/audio.h"
#include "data/menus/game_over_data.h"
#include "data/menus/file_select_data.h"
extern const u8 sBlob_5dfd6c_5e116c[];
extern const u8 sBlob_5f6990_5f7190[];
extern const u8 sBlob_65c468_662804[];
extern const u8 sBlob_662cfc_663820[];
extern const u8 sBlob_73dbcc_7478a0[];
extern u32 sPointerTable_79ce10[];
extern const u8 sAddr_5dfeac[];
extern const u8 sAddr_5dffec[];
extern const u8 sAddr_5e012c[];
extern const u8 sAddr_5e026c[];
extern const u8 sAddr_5e03ac[];
extern const u8 sAddr_5e04ec[];
extern const u8 sAddr_5e062c[];
extern const u8 sAddr_5e076c[];
extern const u8 sAddr_5e08ac[];
extern const u8 sAddr_5e09ec[];
extern const u8 sAddr_5e0b2c[];
extern const u8 sAddr_5e0c6c[];
extern const u8 sAddr_5e0dac[];
extern const u8 sAddr_5e0eec[];
extern const u8 sAddr_5e102c[];
extern const u8 sAddr_5f6a10[];
extern const u8 sAddr_5f6a90[];
extern const u8 sAddr_5f6b10[];
extern const u8 sAddr_5f6b90[];
extern const u8 sAddr_5f6c10[];
extern const u8 sAddr_5f6c90[];
extern const u8 sAddr_5f6d10[];
extern const u8 sAddr_5f6d90[];
extern const u8 sAddr_5f6e10[];
extern const u8 sAddr_5f6e90[];
extern const u8 sAddr_5f6f10[];
extern const u8 sAddr_5f6f90[];
extern const u8 sAddr_5f7010[];
extern const u8 sAddr_5f7090[];
extern const u8 sAddr_5f7110[];
extern const u8 sAddr_65fc24[];
extern const u8 sAddr_71e20c[];
extern const u8 sAddr_71e4e4[];
extern const u8 sAddr_71e67e[];
extern const u8 sAddr_71e814[];
extern const u8 sAddr_71e9b6[];
extern const u8 sAddr_71eb34[];
extern const u8 sAddr_71ecac[];
extern const u8 sAddr_71efc2[];
extern const u8 sAddr_71f498[];
extern const u8 sAddr_71f52c[];
extern const u8 sAddr_71f56c[];
extern const u8 sAddr_71f5fc[];
extern const u8 sAddr_71f656[];
extern const u8 sAddr_71f71a[];
extern const u8 sAddr_71f7cc[];
extern const u8 sAddr_71f896[];
extern const u8 sAddr_71f98a[];
extern const u8 sAddr_71fa32[];
extern const u8 sAddr_71fa92[];
extern const u8 sAddr_71fad4[];
extern const u8 sAddr_7200ee[];
extern const u8 sAddr_720310[];
extern const u8 sAddr_720528[];
extern const u8 sAddr_720748[];
extern const u8 sAddr_72094a[];
extern const u8 sAddr_720b4a[];
extern const u8 sAddr_721116[];
extern const u8 sAddr_72192e[];
extern const u8 sAddr_721a12[];
extern const u8 sAddr_721ab6[];
extern const u8 sAddr_721c28[];
extern const u8 sAddr_721d12[];
extern const u8 sAddr_721f20[];
extern const u8 sAddr_722068[];
extern const u8 sAddr_722238[];
extern const u8 sAddr_722438[];
extern const u8 sAddr_722550[];
extern const u8 sAddr_7225f8[];
extern const u8 sAddr_7226a0[];
extern const u8 sAddr_723016[];
extern const u8 sAddr_723324[];
extern const u8 sAddr_723624[];
extern const u8 sAddr_723958[];
extern const u8 sAddr_723be2[];
extern const u8 sAddr_723e44[];
extern const u8 sAddr_72475e[];
extern const u8 sAddr_7252c6[];
extern const u8 sAddr_725412[];
extern const u8 sAddr_7254ea[];
extern const u8 sAddr_7256d8[];
extern const u8 sAddr_72581e[];
extern const u8 sAddr_725a60[];
extern const u8 sAddr_725b94[];
extern const u8 sAddr_725dac[];
extern const u8 sAddr_72603c[];
extern const u8 sAddr_7261c6[];
extern const u8 sAddr_7262aa[];
extern const u8 sAddr_72638c[];
extern const u8 sAddr_726aa6[];
extern const u8 sAddr_726cfe[];
extern const u8 sAddr_726f04[];
extern const u8 sAddr_727106[];
extern const u8 sAddr_727314[];
extern const u8 sAddr_727522[];
extern const u8 sAddr_727b08[];
extern const u8 sAddr_7282bc[];
extern const u8 sAddr_7283a6[];
extern const u8 sAddr_728466[];
extern const u8 sAddr_728608[];
extern const u8 sAddr_7286e8[];
extern const u8 sAddr_7288ba[];
extern const u8 sAddr_728a12[];
extern const u8 sAddr_728bfc[];
extern const u8 sAddr_728e4a[];
extern const u8 sAddr_728f96[];
extern const u8 sAddr_72904e[];
extern const u8 sAddr_7290fc[];
extern const u8 sAddr_729792[];
extern const u8 sAddr_729a6e[];
extern const u8 sAddr_729c84[];
extern const u8 sAddr_729f24[];
extern const u8 sAddr_72a124[];
extern const u8 sAddr_72a330[];
extern const u8 sAddr_72a8f6[];
extern const u8 sAddr_72b142[];
extern const u8 sAddr_72b254[];
extern const u8 sAddr_72b2c8[];
extern const u8 sAddr_72b446[];
extern const u8 sAddr_72b56e[];
extern const u8 sAddr_72b7a6[];
extern const u8 sAddr_72b8e6[];
extern const u8 sAddr_72bab4[];
extern const u8 sAddr_72bcc2[];
extern const u8 sAddr_72bdb8[];
extern const u8 sAddr_72be4a[];
extern const u8 sAddr_72bef8[];
extern const u8 sAddr_72c69c[];
extern const u8 sAddr_72c8f2[];
extern const u8 sAddr_72cb02[];
extern const u8 sAddr_72cd92[];
extern const u8 sAddr_72d002[];
extern const u8 sAddr_72d212[];
extern const u8 sAddr_72d81e[];
extern const u8 sAddr_72e0b8[];
extern const u8 sAddr_72e1b6[];
extern const u8 sAddr_72e220[];
extern const u8 sAddr_72e3d2[];
extern const u8 sAddr_72e4ea[];
extern const u8 sAddr_72e70a[];
extern const u8 sAddr_72e848[];
extern const u8 sAddr_72ea20[];
extern const u8 sAddr_72ebf6[];
extern const u8 sAddr_72ed50[];
extern const u8 sAddr_72ee1c[];
extern const u8 sAddr_739d58[];
extern const u8 sAddr_73a430[];
extern const u8 sAddr_73ab28[];
extern const u8 sAddr_73b308[];
extern const u8 sAddr_73baac[];
extern const u8 sAddr_73c274[];
extern const u8 sAddr_73c29c[];
extern const u8 sAddr_73dbd8[];
extern const u8 sAddr_73dbde[];
extern const u8 sAddr_73dbe4[];
extern const u8 sAddr_73dbea[];
extern const u8 sAddr_73dbf6[];
extern const u8 sAddr_73dbfc[];
extern const u8 sAddr_73dc02[];
extern const u8 sAddr_73dc08[];
extern const u8 sAddr_73dc14[];
extern const u8 sAddr_740800[];
extern const u8 sAddr_740820[];
extern const u8 sAddr_740840[];
extern const u8 sAddr_7408c0[];
extern const u8 sAddr_7409d8[];
extern const u8 sAddr_7409e8[];
extern const u8 sAddr_7409f8[];
extern const u8 sAddr_740a08[];
extern const u8 sAddr_740a18[];
extern const u8 sAddr_740a28[];
extern const u8 sAddr_740a38[];
extern const u8 sAddr_740ab8[];
extern const u8 sAddr_740ac8[];
extern const u8 sAddr_740ad8[];
extern const u8 sAddr_740ae8[];
extern const u8 sAddr_740b08[];
extern const u8 sAddr_740b28[];
extern const u8 sAddr_740ba8[];
extern const u8 sAddr_740bb8[];
extern const u8 sAddr_740bc8[];
extern const u8 sAddr_740bd8[];
extern const u8 sAddr_740be8[];
extern const u8 sAddr_740bf8[];
extern const u8 sAddr_740c08[];
extern const u8 sAddr_740c18[];
extern const u8 sAddr_740c28[];
extern const u8 sAddr_740c38[];
extern const u8 sAddr_740c48[];
extern const u8 sAddr_740c58[];
extern const u8 sAddr_740c68[];
extern const u8 sAddr_740c78[];
extern const u8 sAddr_740c88[];
extern const u8 sAddr_740c98[];
extern const u8 sAddr_740ca8[];
extern const u8 sAddr_740cb8[];
extern const u8 sAddr_740cc8[];
extern const u8 sAddr_740cd8[];
extern const u8 sAddr_740ce8[];
extern const u8 sAddr_740cf8[];
extern const u8 sAddr_740f08[];
extern const u8 sAddr_740f3a[];
extern const u8 sAddr_740f64[];
extern const u8 sAddr_740f82[];
extern const u8 sAddr_740fc4[];
extern const u8 sAddr_740ff4[];
extern const u8 sAddr_741036[];
extern const u8 sAddr_741078[];
extern const u8 sAddr_7410ba[];
extern const u8 sAddr_7410fc[];
extern const u8 sAddr_74113e[];
extern const u8 sAddr_741180[];
extern const u8 sAddr_741196[];
extern const u8 sAddr_74119e[];
extern const u8 sAddr_7411b2[];
extern const u8 sAddr_7411da[];
extern const u8 sAddr_7411fa[];
extern const u8 sAddr_74120e[];
extern const u8 sAddr_741258[];
extern const u8 sAddr_741280[];
extern const u8 sAddr_7412ce[];
extern const u8 sAddr_7412ec[];
extern const u8 sAddr_74130e[];
extern const u8 sAddr_741334[];
extern const u8 sAddr_74134c[];
extern const u8 sAddr_741364[];
extern const u8 sAddr_741398[];
extern const u8 sAddr_7413ce[];
extern const u8 sAddr_741410[];
extern const u8 sAddr_741466[];
extern const u8 sAddr_74149c[];
extern const u8 sAddr_7414f6[];
extern const u8 sAddr_741550[];
extern const u8 sAddr_7415aa[];
extern const u8 sAddr_74160e[];
extern const u8 sAddr_741672[];
extern const u8 sAddr_7416d6[];
extern const u8 sAddr_7416ec[];
extern const u8 sAddr_74170a[];
extern const u8 sAddr_74171e[];
extern const u8 sAddr_741746[];
extern const u8 sAddr_741766[];
extern const u8 sAddr_74177a[];
extern const u8 sAddr_7417c4[];
extern const u8 sAddr_7417ee[];
extern const u8 sAddr_741814[];
extern const u8 sAddr_741830[];
extern const u8 sAddr_74185a[];
extern const u8 sAddr_741884[];
extern const u8 sAddr_7418b4[];
extern const u8 sAddr_7418dc[];
extern const u8 sAddr_741918[];
extern const u8 sAddr_741946[];
extern const u8 sAddr_74197e[];
extern const u8 sAddr_7419d4[];
extern const u8 sAddr_741a14[];
extern const u8 sAddr_741a76[];
extern const u8 sAddr_741ad8[];
extern const u8 sAddr_741b3a[];
extern const u8 sAddr_741b98[];
extern const u8 sAddr_741bf6[];
extern const u8 sAddr_741c54[];
extern const u8 sAddr_741c6e[];
extern const u8 sAddr_741c90[];
extern const u8 sAddr_741cb2[];
extern const u8 sAddr_741cdc[];
extern const u8 sAddr_741d0a[];
extern const u8 sAddr_741d28[];
extern const u8 sAddr_741d50[];
extern const u8 sAddr_741d82[];
extern const u8 sAddr_741db2[];
extern const u8 sAddr_741dd6[];
extern const u8 sAddr_741df2[];
extern const u8 sAddr_741e24[];
extern const u8 sAddr_741e48[];
extern const u8 sAddr_741e82[];
extern const u8 sAddr_741ec4[];
extern const u8 sAddr_741eee[];
extern const u8 sAddr_741f32[];
extern const u8 sAddr_741f80[];
extern const u8 sAddr_741fbe[];
extern const u8 sAddr_74202a[];
extern const u8 sAddr_742096[];
extern const u8 sAddr_742102[];
extern const u8 sAddr_742162[];
extern const u8 sAddr_7421c2[];
extern const u8 sAddr_742222[];
extern const u8 sAddr_742244[];
extern const u8 sAddr_742270[];
extern const u8 sAddr_74229c[];
extern const u8 sAddr_7422c0[];
extern const u8 sAddr_7422f2[];
extern const u8 sAddr_742318[];
extern const u8 sAddr_74234e[];
extern const u8 sAddr_742362[];
extern const u8 sAddr_742386[];
extern const u8 sAddr_7423aa[];
extern const u8 sAddr_7423d4[];
extern const u8 sAddr_7423f6[];
extern const u8 sAddr_742420[];
extern const u8 sAddr_74244c[];
extern const u8 sAddr_742486[];
extern const u8 sAddr_7424c0[];
extern const u8 sAddr_7424fe[];
extern const u8 sAddr_74254e[];
extern const u8 sAddr_742586[];
extern const u8 sAddr_7425f2[];
extern const u8 sAddr_74265e[];
extern const u8 sAddr_7426ca[];
extern const u8 sAddr_74272e[];
extern const u8 sAddr_742792[];
extern const u8 sAddr_7427f6[];
extern const u8 sAddr_74280c[];
extern const u8 sAddr_74282c[];
extern const u8 sAddr_742840[];
extern const u8 sAddr_74286a[];
extern const u8 sAddr_74289e[];
extern const u8 sAddr_7428c4[];
extern const u8 sAddr_74290a[];
extern const u8 sAddr_742938[];
extern const u8 sAddr_742964[];
extern const u8 sAddr_742982[];
extern const u8 sAddr_7429ac[];
extern const u8 sAddr_7429dc[];
extern const u8 sAddr_742a00[];
extern const u8 sAddr_742a28[];
extern const u8 sAddr_742a66[];
extern const u8 sAddr_742a8e[];
extern const u8 sAddr_742ac0[];
extern const u8 sAddr_742b18[];
extern const u8 sAddr_742b50[];
extern const u8 sAddr_742baa[];
extern const u8 sAddr_742c04[];
extern const u8 sAddr_742c5e[];
extern const u8 sAddr_742cba[];
extern const u8 sAddr_742d16[];
extern const u8 sAddr_742d74[];
extern const u8 sAddr_742d8a[];
extern const u8 sAddr_742da2[];
extern const u8 sAddr_742dc8[];
extern const u8 sAddr_742de4[];
extern const u8 sAddr_742df8[];
extern const u8 sAddr_742e18[];
extern const u8 sAddr_742e4c[];
extern const u8 sAddr_742e7c[];
extern const u8 sAddr_742e9c[];
extern const u8 sAddr_742ec6[];
extern const u8 sAddr_742eee[];
extern const u8 sAddr_742f14[];
extern const u8 sAddr_742f42[];
extern const u8 sAddr_742f66[];
extern const u8 sAddr_742f7a[];

extern const u8 sBlob_6b2fac_72eee0[];

void unk_99940(void); // For V-blank callback
u8 SpecialCutsceneGetRandomNumber(void);

static u16* sMonologueTextPointersJapanese[19];
static u16* sMonologueTextPointersEnglish[19];
static u16* sMonologueTextPointersGerman[19];
static u16* sMonologueTextPointersFrench[19];
static u16* sMonologueTextPointersItalian[19];
static u16* sMonologueTextPointersSpanish[19];

const u8* sTitleScreenDebugTextPointer = {
    sTitleScreenDebugText,
};

const struct FrameData* sData_79C2CC[6] = {
    sOam_597ec0,
    sOam_597ed0,
    sOam_597ee0,
    sOam_597ef0,
    sOam_597ee0,
    sOam_597ed0
};

static const u16* sArray_79c2e4[12] = {
	sPal_5bf838,
	sPal_5bf8b8,
	sPal_5bf938,
	sPal_5bf9b8,
	sPal_5bfa38,
	sPal_5bfab8,
	sPal_5bfb38,
	sPal_5bfbb8,
	sPal_5bfc38,
	sPal_5bfcb8,
	sPal_5bfd38,
	sPal_5bfdb8
};

static const u16* sPalPointers_79c314[16] = {
	(const u16*)(&sBlob_5dfd6c_5e116c),
	(const u16*)sAddr_5dfeac,
	(const u16*)sAddr_5e102c,
	(const u16*)sAddr_5dffec,
	(const u16*)sAddr_5e012c,
	(const u16*)sAddr_5e026c,
	(const u16*)sAddr_5e03ac,
	(const u16*)sAddr_5e04ec,
	(const u16*)sAddr_5e062c,
	(const u16*)sAddr_5e076c,
	(const u16*)sAddr_5e08ac,
	(const u16*)sAddr_5e09ec,
	(const u16*)sAddr_5e0b2c,
	(const u16*)sAddr_5e0c6c,
	(const u16*)sAddr_5e0dac,
	(const u16*)sAddr_5e0eec
};

static const u16* sPalPointers_79c354[16] = {
	(const u16*)(&sBlob_5f6990_5f7190),
	(const u16*)sAddr_5f6a10,
	(const u16*)sAddr_5f6a90,
	(const u16*)sAddr_5f6b10,
	(const u16*)sAddr_5f6b90,
	(const u16*)sAddr_5f6c10,
	(const u16*)sAddr_5f6c90,
	(const u16*)sAddr_5f6d10,
	(const u16*)sAddr_5f6d90,
	(const u16*)sAddr_5f6e10,
	(const u16*)sAddr_5f6e90,
	(const u16*)sAddr_5f6f10,
	(const u16*)sAddr_5f6f90,
	(const u16*)sAddr_5f7010,
	(const u16*)sAddr_5f7090,
	(const u16*)sAddr_5f7110
};

const struct FrameData* sIntroSpaceViewParticleOam[6] = {
    sOam_60ac08,
    sOam_60ac18,
    sOam_60ac28,
    sOam_60ac38,
    sOam_60ac28,
    sOam_60ac18
};

const u16** sEndingTextPointers[LANGUAGE_COUNT] = {
    (const u16**)(&sPointerTable_79ce10),
    (const u16**)((const u8*)&sPointerTable_79ce10 + 0x384),
    (const u16**)((const u8*)&sPointerTable_79ce10 + 0x6fc),
    (const u16**)((const u8*)&sPointerTable_79ce10 + 0xa80),
    (const u16**)((const u8*)&sPointerTable_79ce10 + 0xe04),
    (const u16**)((const u8*)&sPointerTable_79ce10 + 0x1188),
    (const u16**)((const u8*)&sPointerTable_79ce10 + 0x150c)
};

static const u32* sIntroSr388SurfaceBgGfxPointers[8] = {
    sIntroSr388SurfaceBgGfx0,
    sIntroSr388SurfaceBgGfx1,
    sIntroSr388SurfaceBgGfx2,
    sIntroSr388SurfaceBgGfx3,
    sIntroSr388SurfaceBgGfx4,
    sIntroSr388SurfaceBgGfx5,
    sIntroSr388SurfaceBgGfx6,
    sIntroSr388SurfaceBgGfx7
};

static const u32* sIntroSr388PlanetBgGfxPointers[5] = {
    sIntroSr388PlanetBgGfx0,
    sIntroSr388PlanetBgGfx1,
    sIntroSr388PlanetBgGfx2,
    sIntroSr388PlanetBgGfx3,
    sIntroSr388PlanetBgGfx4
};

static const u32* sIntroBslObjectGfxPointers[8] = {
    sIntroBslObjectGfx0,
    sIntroBslObjectGfx1,
    sIntroBslObjectGfx2,
    sIntroBslObjectGfx3,
    sIntroBslObjectGfx4,
    sIntroBslObjectGfx5,
    sIntroBslObjectGfx6,
    sIntroBslObjectGfx7
};

const u32* sIntroSamusSittingBgGfxPointers[5] = {
    sIntroSamusSittingBgGfx0,
    sIntroSamusSittingBgGfx1,
    sIntroSamusSittingBgGfx2,
    sIntroSamusSittingBgGfx3,
    sIntroSamusSittingBgGfx4
};

static const u32* sIntroSamusHelmetCloseupBgGfxPointers[6] = {
    sIntroSamusHelmetCloseupBgGfx0,
    sIntroSamusHelmetCloseupBgGfx1,
    sIntroSamusHelmetCloseupBgGfx2,
    sIntroSamusHelmetCloseupBgGfx3,
    sIntroSamusHelmetCloseupBgGfx4,
    sIntroSamusHelmetCloseupBgGfx5
};

const u32* sTitleIntroCollisionWarningBgGfxPointers[5] = {
    sTitleIntroCollisionWarningBgGfx0,
    sTitleIntroCollisionWarningBgGfx1,
    sTitleIntroCollisionWarningBgGfx2,
    sTitleIntroCollisionWarningBgGfx3,
    sTitleIntroCollisionWarningBgGfx4
};

const u32* sTitleIntroCollisionWarningObjGfxPointers[6] = {
    sTitleIntroCollisionWarningObjGfx0,
    sTitleIntroCollisionWarningObjGfx1,
    sTitleIntroCollisionWarningObjGfx2,
    sTitleIntroCollisionWarningObjGfx3,
    sTitleIntroCollisionWarningObjGfx4,
    sTitleIntroCollisionWarningObjGfx5
};

u32 sPointerTable_79c474[13] = {
    (u32)&sTitleIntroGfx_652bd4,
    (u32)&sTitleIntroGfx_653980,
    (u32)&sTitleIntroGfx_6546f4,
    (u32)&sTitleIntroGfx_6552a0,
    (u32)&sTitleIntroGfx_655f3c,
    (u32)&sTitleIntroGfx_656cd0,
    (u32)&sTitleIntroGfx_657408,
    (u32)&sTitleIntroGfx_6579c4,
    (u32)&sTitleIntroGfx_657d2c,
    (u32)&sTitleIntroGfx_657f60,
    (u32)&sTitleIntroGfx_658150,
    (u32)&sTitleIntroGfx_658468,
    (u32)&sTitleIntroGfx_658848
};

const u16* sCutsceneMonologueBgPalPointers[9] = {
    (const u16*)0x86638c0,
    (const u16*)0x866aa68,
    (const u16*)0x86638c0,
    (const u16*)0x86638c0,
    (const u16*)0x866aa68,
    (const u16*)0x8671a04,
    (const u16*)0x86638c0,
    (const u16*)0x86638c0,
    (const u16*)0x86638c0
};

const u16* sCutsceneMonologueObjPalPointers[9] = {
    (const u16*)0x8663a20,
    (const u16*)0x8663a20,
    (const u16*)0x8663a20,
    (const u16*)0x8663a20,
    (const u16*)0x866abc8,
    (const u16*)0x8671b64,
    (const u16*)0x8663a20,
    (const u16*)0x8663a20,
    (const u16*)0x8663a20
};

const u32* sCutsceneMonologueBgGfxPointers[9] = {
    (const u32*)(&sBlob_65c468_662804),
    (const u32*)0x8663eac,
    (const u32*)(&sBlob_65c468_662804),
    (const u32*)(&sBlob_65c468_662804),
    (const u32*)0x8663eac,
    (const u32*)0x866b524,
    (const u32*)(&sBlob_65c468_662804),
    (const u32*)(&sBlob_65c468_662804),
    (const u32*)(&sBlob_65c468_662804)
};

const u32* sCutsceneMonologueObjGfxPointers[9] = {
    (const u32*)sAddr_65fc24,
    (const u32*)sAddr_65fc24,
    (const u32*)sAddr_65fc24,
    (const u32*)sAddr_65fc24,
    (const u32*)0x8667c18,
    (const u32*)0x866ec18,
    (const u32*)sAddr_65fc24,
    (const u32*)sAddr_65fc24,
    (const u32*)sAddr_65fc24
};

const u32* sCutsceneMonologueBgTilemapPointers[9] = {
    (const u32*)(&sBlob_662cfc_663820),
    (const u32*)0x866ac88,
    (const u32*)(&sBlob_662cfc_663820),
    (const u32*)(&sBlob_662cfc_663820),
    (const u32*)0x866ac88,
    (const u32*)0x8671c24,
    (const u32*)(&sBlob_662cfc_663820),
    (const u32*)(&sBlob_662cfc_663820),
    (const u32*)(&sBlob_662cfc_663820)
};

const struct FrameData* sCutsceneMonologueOamPointers[9][2] = {
    { (const struct FrameData*)0x8663dd0, (const struct FrameData*)0x8663df8 },
    { (const struct FrameData*)0x8663dd0, (const struct FrameData*)0x8663df8 },
    { (const struct FrameData*)0x8663dd0, (const struct FrameData*)0x8663df8 },
    { (const struct FrameData*)0x8663dd0, (const struct FrameData*)0x8663df8 },
    { (const struct FrameData*)0x866aa30, (const struct FrameData*)0x866aa58 },
    { (const struct FrameData*)0x86719cc, (const struct FrameData*)0x86719f4 },
    { (const struct FrameData*)0x8663dd0, (const struct FrameData*)0x8663df8 },
    { (const struct FrameData*)0x8663dd0, (const struct FrameData*)0x8663df8 },
    { (const struct FrameData*)0x8663dd0, (const struct FrameData*)0x8663df8 }
};

u16** sMonologueTextPointers[LANGUAGE_COUNT] = {
    sMonologueTextPointersJapanese,
    sMonologueTextPointersJapanese,
    sMonologueTextPointersEnglish,
    sMonologueTextPointersGerman,
    sMonologueTextPointersFrench,
    sMonologueTextPointersItalian,
    sMonologueTextPointersSpanish
};

u32 sPointerTable_79c5c0[518] = {
    (u32)&sBlob_6b2fac_72eee0,
    (u32)&sBlob_6b2fac_72eee0 + 0x48,
    (u32)&sBlob_6b2fac_72eee0 + 0x92,
    (u32)&sBlob_6b2fac_72eee0 + 0xdc,
    (u32)&sBlob_6b2fac_72eee0 + 0x124,
    (u32)&sBlob_6b2fac_72eee0 + 0x164,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x1f0,
    (u32)&sBlob_6b2fac_72eee0 + 0x244,
    (u32)&sBlob_6b2fac_72eee0 + 0x286,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e4,
    (u32)&sBlob_6b2fac_72eee0 + 0x322,
    (u32)&sBlob_6b2fac_72eee0 + 0x372,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x410,
    (u32)&sBlob_6b2fac_72eee0 + 0x45e,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f8,
    (u32)&sBlob_6b2fac_72eee0 + 0x552,
    (u32)&sBlob_6b2fac_72eee0 + 0x58e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x60e,
    (u32)&sBlob_6b2fac_72eee0 + 0x656,
    (u32)&sBlob_6b2fac_72eee0 + 0x684,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b2,
    (u32)&sBlob_6b2fac_72eee0 + 0x6e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x70e,
    (u32)&sBlob_6b2fac_72eee0 + 0x734,
    (u32)&sBlob_6b2fac_72eee0 + 0x74e,
    (u32)&sBlob_6b2fac_72eee0 + 0x762,
    (u32)&sBlob_6b2fac_72eee0 + 0x782,
    (u32)&sBlob_6b2fac_72eee0 + 0x79e,
    (u32)&sBlob_6b2fac_72eee0 + 0x7ca,
    (u32)&sBlob_6b2fac_72eee0 + 0x808,
    (u32)&sBlob_6b2fac_72eee0 + 0x82e,
    (u32)&sBlob_6b2fac_72eee0 + 0x840,
    (u32)&sBlob_6b2fac_72eee0 + 0x86c,
    (u32)&sBlob_6b2fac_72eee0 + 0x884,
    (u32)&sBlob_6b2fac_72eee0 + 0x89c,
    (u32)&sBlob_6b2fac_72eee0 + 0x8c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x8f2,
    (u32)&sBlob_6b2fac_72eee0 + 0x930,
    (u32)&sBlob_6b2fac_72eee0 + 0x972,
    (u32)&sBlob_6b2fac_72eee0 + 0x9b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x9dc,
    (u32)&sBlob_6b2fac_72eee0 + 0xa00,
    (u32)&sBlob_6b2fac_72eee0 + 0xa40,
    (u32)&sBlob_6b2fac_72eee0 + 0xa80,
    (u32)&sBlob_6b2fac_72eee0 + 0xa92,
    (u32)&sBlob_6b2fac_72eee0 + 0xaa2,
    (u32)&sBlob_6b2fac_72eee0 + 0xabc,
    (u32)&sBlob_6b2fac_72eee0 + 0xad6,
    (u32)&sBlob_6b2fac_72eee0 + 0xaf0,
    (u32)&sBlob_6b2fac_72eee0 + 0xb0a,
    (u32)&sBlob_6b2fac_72eee0 + 0xb24,
    (u32)&sBlob_6b2fac_72eee0 + 0xb3e,
    (u32)&sBlob_6b2fac_72eee0 + 0xb4c,
    (u32)&sBlob_6b2fac_72eee0 + 0xb5a,
    (u32)&sBlob_6b2fac_72eee0 + 0xb72,
    (u32)&sBlob_6b2fac_72eee0 + 0xb80,
    (u32)&sBlob_6b2fac_72eee0 + 0xb92,
    (u32)&sBlob_6b2fac_72eee0 + 0xbaa,
    (u32)&sBlob_6b2fac_72eee0 + 0xbba,
    (u32)&sBlob_6b2fac_72eee0 + 0xbd2,
    (u32)&sBlob_6b2fac_72eee0 + 0xbe6,
    (u32)&sBlob_6b2fac_72eee0 + 0xbf6,
    (u32)&sBlob_6b2fac_72eee0 + 0xc0e,
    (u32)&sBlob_6b2fac_72eee0 + 0xc1c,
    (u32)&sBlob_6b2fac_72eee0 + 0xc2a,
    (u32)&sBlob_6b2fac_72eee0 + 0xc38,
    (u32)&sBlob_6b2fac_72eee0 + 0xc46,
    (u32)&sBlob_6b2fac_72eee0 + 0xc5a,
    (u32)&sBlob_6b2fac_72eee0 + 0xc68,
    (u32)&sBlob_6b2fac_72eee0 + 0xc7c,
    (u32)&sBlob_6b2fac_72eee0 + 0xc9c,
    (u32)&sBlob_6b2fac_72eee0 + 0xce4,
    (u32)&sBlob_6b2fac_72eee0 + 0xd2e,
    (u32)&sBlob_6b2fac_72eee0 + 0xd78,
    (u32)&sBlob_6b2fac_72eee0 + 0xdc0,
    (u32)&sBlob_6b2fac_72eee0 + 0xe00,
    (u32)&sBlob_6b2fac_72eee0 + 0xe48,
    (u32)&sBlob_6b2fac_72eee0 + 0xe8c,
    (u32)&sBlob_6b2fac_72eee0 + 0xee2,
    (u32)&sBlob_6b2fac_72eee0 + 0xf24,
    (u32)&sBlob_6b2fac_72eee0 + 0xf82,
    (u32)&sBlob_6b2fac_72eee0 + 0xfc0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1010,
    (u32)&sBlob_6b2fac_72eee0 + 0x105e,
    (u32)&sBlob_6b2fac_72eee0 + 0x10ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x10fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1150,
    (u32)&sBlob_6b2fac_72eee0 + 0x1196,
    (u32)&sBlob_6b2fac_72eee0 + 0x11f0,
    (u32)&sBlob_6b2fac_72eee0 + 0x122c,
    (u32)&sBlob_6b2fac_72eee0 + 0x126e,
    (u32)&sBlob_6b2fac_72eee0 + 0x12ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x12f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1322,
    (u32)&sBlob_6b2fac_72eee0 + 0x1350,
    (u32)&sBlob_6b2fac_72eee0 + 0x137e,
    (u32)&sBlob_6b2fac_72eee0 + 0x13ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x13d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x13ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x1400,
    (u32)&sBlob_6b2fac_72eee0 + 0x1420,
    (u32)&sBlob_6b2fac_72eee0 + 0x143c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1468,
    (u32)&sBlob_6b2fac_72eee0 + 0x14a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x14ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x14e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x150c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1524,
    (u32)&sBlob_6b2fac_72eee0 + 0x153c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1560,
    (u32)&sBlob_6b2fac_72eee0 + 0x1592,
    (u32)&sBlob_6b2fac_72eee0 + 0x15d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x160c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1650,
    (u32)&sBlob_6b2fac_72eee0 + 0x1676,
    (u32)&sBlob_6b2fac_72eee0 + 0x169a,
    (u32)&sBlob_6b2fac_72eee0 + 0x16da,
    (u32)&sBlob_6b2fac_72eee0 + 0x171a,
    (u32)&sBlob_6b2fac_72eee0 + 0x172c,
    (u32)&sBlob_6b2fac_72eee0 + 0x173c,
    (u32)&sBlob_6b2fac_72eee0 + 0x174a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1758,
    (u32)&sBlob_6b2fac_72eee0 + 0x1766,
    (u32)&sBlob_6b2fac_72eee0 + 0x1774,
    (u32)&sBlob_6b2fac_72eee0 + 0x1782,
    (u32)&sBlob_6b2fac_72eee0 + 0x1790,
    (u32)&sBlob_6b2fac_72eee0 + 0x179e,
    (u32)&sBlob_6b2fac_72eee0 + 0x17ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x17c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x17d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x17e4,
    (u32)&sBlob_6b2fac_72eee0 + 0x17fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x180c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1824,
    (u32)&sBlob_6b2fac_72eee0 + 0x1838,
    (u32)&sBlob_6b2fac_72eee0 + 0x1848,
    (u32)&sBlob_6b2fac_72eee0 + 0x1860,
    (u32)&sBlob_6b2fac_72eee0 + 0x186e,
    (u32)&sBlob_6b2fac_72eee0 + 0x187c,
    (u32)&sBlob_6b2fac_72eee0 + 0x188a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1898,
    (u32)&sBlob_6b2fac_72eee0 + 0x18ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x18ba,
    (u32)&sBlob_6b2fac_72eee0 + 0x18ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x18ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x195a,
    (u32)&sBlob_6b2fac_72eee0 + 0x19c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a38,
    (u32)&sBlob_6b2fac_72eee0 + 0x1aa2,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b04,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b72,
    (u32)&sBlob_6b2fac_72eee0 + 0x1be0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1c5c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1cd0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1d4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1dbc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1e14,
    (u32)&sBlob_6b2fac_72eee0 + 0x1e88,
    (u32)&sBlob_6b2fac_72eee0 + 0x1f06,
    (u32)&sBlob_6b2fac_72eee0 + 0x1f80,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ff8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2064,
    (u32)&sBlob_6b2fac_72eee0 + 0x20de,
    (u32)&sBlob_6b2fac_72eee0 + 0x2150,
    (u32)&sBlob_6b2fac_72eee0 + 0x21c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x223a,
    (u32)&sBlob_6b2fac_72eee0 + 0x22aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x232c,
    (u32)&sBlob_6b2fac_72eee0 + 0x23a6,
    (u32)&sBlob_6b2fac_72eee0 + 0x2428,
    (u32)&sBlob_6b2fac_72eee0 + 0x24a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2518,
    (u32)&sBlob_6b2fac_72eee0 + 0x2548,
    (u32)&sBlob_6b2fac_72eee0 + 0x2582,
    (u32)&sBlob_6b2fac_72eee0 + 0x25c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x25fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x2666,
    (u32)&sBlob_6b2fac_72eee0 + 0x26c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x26f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x2718,
    (u32)&sBlob_6b2fac_72eee0 + 0x274e,
    (u32)&sBlob_6b2fac_72eee0 + 0x2796,
    (u32)&sBlob_6b2fac_72eee0 + 0x27d8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2822,
    (u32)&sBlob_6b2fac_72eee0 + 0x2888,
    (u32)&sBlob_6b2fac_72eee0 + 0x28f2,
    (u32)&sBlob_6b2fac_72eee0 + 0x2966,
    (u32)&sBlob_6b2fac_72eee0 + 0x29d8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a20,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a6c,
    (u32)&sBlob_6b2fac_72eee0 + 0x2acc,
    (u32)&sBlob_6b2fac_72eee0 + 0x2b3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x2b50,
    (u32)&sBlob_6b2fac_72eee0 + 0x2b66,
    (u32)&sBlob_6b2fac_72eee0 + 0x2b86,
    (u32)&sBlob_6b2fac_72eee0 + 0x2ba6,
    (u32)&sBlob_6b2fac_72eee0 + 0x2bc6,
    (u32)&sBlob_6b2fac_72eee0 + 0x2be6,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c06,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c26,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c42,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c64,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c86,
    (u32)&sBlob_6b2fac_72eee0 + 0x2ca8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2cc4,
    (u32)&sBlob_6b2fac_72eee0 + 0x2ce6,
    (u32)&sBlob_6b2fac_72eee0 + 0x2cfc,
    (u32)&sBlob_6b2fac_72eee0 + 0x2d1a,
    (u32)&sBlob_6b2fac_72eee0 + 0x2d38,
    (u32)&sBlob_6b2fac_72eee0 + 0x2d4e,
    (u32)&sBlob_6b2fac_72eee0 + 0x2d70,
    (u32)&sBlob_6b2fac_72eee0 + 0x2d90,
    (u32)&sBlob_6b2fac_72eee0 + 0x2dbc,
    (u32)&sBlob_6b2fac_72eee0 + 0x2de8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e1a,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e48,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e6e,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e88,
    (u32)&sBlob_6b2fac_72eee0 + 0x2ebc,
    (u32)&sBlob_6b2fac_72eee0 + 0x2f2e,
    (u32)&sBlob_6b2fac_72eee0 + 0x2fa0,
    (u32)&sBlob_6b2fac_72eee0 + 0x3012,
    (u32)&sBlob_6b2fac_72eee0 + 0x3082,
    (u32)&sBlob_6b2fac_72eee0 + 0x30e6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3156,
    (u32)&sBlob_6b2fac_72eee0 + 0x31c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x3242,
    (u32)&sBlob_6b2fac_72eee0 + 0x32c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x333c,
    (u32)&sBlob_6b2fac_72eee0 + 0x33ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x3400,
    (u32)&sBlob_6b2fac_72eee0 + 0x3472,
    (u32)&sBlob_6b2fac_72eee0 + 0x34e4,
    (u32)&sBlob_6b2fac_72eee0 + 0x354c,
    (u32)&sBlob_6b2fac_72eee0 + 0x35c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x3640,
    (u32)&sBlob_6b2fac_72eee0 + 0x36b8,
    (u32)&sBlob_6b2fac_72eee0 + 0x3720,
    (u32)&sBlob_6b2fac_72eee0 + 0x378e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3802,
    (u32)&sBlob_6b2fac_72eee0 + 0x386e,
    (u32)&sBlob_6b2fac_72eee0 + 0x38ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x3966,
    (u32)&sBlob_6b2fac_72eee0 + 0x39e2,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a5a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ad6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b26,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b5a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bac,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bec,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c50,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cba,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ce8,
    (u32)&sBlob_6b2fac_72eee0 + 0x3d20,
    (u32)&sBlob_6b2fac_72eee0 + 0x3d74,
    (u32)&sBlob_6b2fac_72eee0 + 0x3dd0,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e2e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ea4,
    (u32)&sBlob_6b2fac_72eee0 + 0x3f0e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3f84,
    (u32)&sBlob_6b2fac_72eee0 + 0x4000,
    (u32)&sBlob_6b2fac_72eee0 + 0x4070,
    (u32)&sBlob_6b2fac_72eee0 + 0x40be,
    (u32)&sBlob_6b2fac_72eee0 + 0x4108,
    (u32)&sBlob_6b2fac_72eee0 + 0x4174,
    (u32)&sBlob_6b2fac_72eee0 + 0x41ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x4202,
    (u32)&sBlob_6b2fac_72eee0 + 0x4218,
    (u32)&sBlob_6b2fac_72eee0 + 0x4238,
    (u32)&sBlob_6b2fac_72eee0 + 0x4258,
    (u32)&sBlob_6b2fac_72eee0 + 0x4278,
    (u32)&sBlob_6b2fac_72eee0 + 0x4298,
    (u32)&sBlob_6b2fac_72eee0 + 0x42b8,
    (u32)&sBlob_6b2fac_72eee0 + 0x42d8,
    (u32)&sBlob_6b2fac_72eee0 + 0x4302,
    (u32)&sBlob_6b2fac_72eee0 + 0x431c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4336,
    (u32)&sBlob_6b2fac_72eee0 + 0x4358,
    (u32)&sBlob_6b2fac_72eee0 + 0x4370,
    (u32)&sBlob_6b2fac_72eee0 + 0x439a,
    (u32)&sBlob_6b2fac_72eee0 + 0x43b0,
    (u32)&sBlob_6b2fac_72eee0 + 0x43da,
    (u32)&sBlob_6b2fac_72eee0 + 0x43f6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4418,
    (u32)&sBlob_6b2fac_72eee0 + 0x4428,
    (u32)&sBlob_6b2fac_72eee0 + 0x444e,
    (u32)&sBlob_6b2fac_72eee0 + 0x447c,
    (u32)&sBlob_6b2fac_72eee0 + 0x44a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x44ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x44e8,
    (u32)&sBlob_6b2fac_72eee0 + 0x4510,
    (u32)&sBlob_6b2fac_72eee0 + 0x452c,
    (u32)&sBlob_6b2fac_72eee0 + 0x456a,
    (u32)&sBlob_6b2fac_72eee0 + 0x45e6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4662,
    (u32)&sBlob_6b2fac_72eee0 + 0x46de,
    (u32)&sBlob_6b2fac_72eee0 + 0x475a,
    (u32)&sBlob_6b2fac_72eee0 + 0x47b0,
    (u32)&sBlob_6b2fac_72eee0 + 0x4812,
    (u32)&sBlob_6b2fac_72eee0 + 0x4880,
    (u32)&sBlob_6b2fac_72eee0 + 0x48fa,
    (u32)&sBlob_6b2fac_72eee0 + 0x4962,
    (u32)&sBlob_6b2fac_72eee0 + 0x49d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a52,
    (u32)&sBlob_6b2fac_72eee0 + 0x4aa2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b14,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b82,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bf2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c62,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ce0,
    (u32)&sBlob_6b2fac_72eee0 + 0x4d52,
    (u32)&sBlob_6b2fac_72eee0 + 0x4dbc,
    (u32)&sBlob_6b2fac_72eee0 + 0x4e28,
    (u32)&sBlob_6b2fac_72eee0 + 0x4e9c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f16,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f86,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ff4,
    (u32)&sBlob_6b2fac_72eee0 + 0x5060,
    (u32)&sBlob_6b2fac_72eee0 + 0x50cc,
    (u32)&sBlob_6b2fac_72eee0 + 0x5146,
    (u32)&sBlob_6b2fac_72eee0 + 0x517c,
    (u32)&sBlob_6b2fac_72eee0 + 0x51c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x5214,
    (u32)&sBlob_6b2fac_72eee0 + 0x5254,
    (u32)&sBlob_6b2fac_72eee0 + 0x52c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x533c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5386,
    (u32)&sBlob_6b2fac_72eee0 + 0x53b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x53ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x5456,
    (u32)&sBlob_6b2fac_72eee0 + 0x54c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5534,
    (u32)&sBlob_6b2fac_72eee0 + 0x55a6,
    (u32)&sBlob_6b2fac_72eee0 + 0x561c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5690,
    (u32)&sBlob_6b2fac_72eee0 + 0x570e,
    (u32)&sBlob_6b2fac_72eee0 + 0x575a,
    (u32)&sBlob_6b2fac_72eee0 + 0x57a6,
    (u32)&sBlob_6b2fac_72eee0 + 0x5814,
    (u32)&sBlob_6b2fac_72eee0 + 0x5882,
    (u32)&sBlob_6b2fac_72eee0 + 0x5896,
    (u32)&sBlob_6b2fac_72eee0 + 0x58b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x58d8,
    (u32)&sBlob_6b2fac_72eee0 + 0x58fa,
    (u32)&sBlob_6b2fac_72eee0 + 0x591c,
    (u32)&sBlob_6b2fac_72eee0 + 0x593e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5960,
    (u32)&sBlob_6b2fac_72eee0 + 0x5982,
    (u32)&sBlob_6b2fac_72eee0 + 0x59a6,
    (u32)&sBlob_6b2fac_72eee0 + 0x59c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x59ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a10,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a36,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a5e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a84,
    (u32)&sBlob_6b2fac_72eee0 + 0x5aaa,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ad0,
    (u32)&sBlob_6b2fac_72eee0 + 0x5afa,
    (u32)&sBlob_6b2fac_72eee0 + 0x5b20,
    (u32)&sBlob_6b2fac_72eee0 + 0x5b4c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5b6c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ba4,
    (u32)&sBlob_6b2fac_72eee0 + 0x5be4,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c0c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c48,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c74,
    (u32)&sBlob_6b2fac_72eee0 + 0x5cb2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5d22,
    (u32)&sBlob_6b2fac_72eee0 + 0x5d96,
    (u32)&sBlob_6b2fac_72eee0 + 0x5e0c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5e80,
    (u32)&sBlob_6b2fac_72eee0 + 0x5eee,
    (u32)&sBlob_6b2fac_72eee0 + 0x5f68,
    (u32)&sBlob_6b2fac_72eee0 + 0x5fcc,
    (u32)&sBlob_6b2fac_72eee0 + 0x6042,
    (u32)&sBlob_6b2fac_72eee0 + 0x60ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x612c,
    (u32)&sBlob_6b2fac_72eee0 + 0x6194,
    (u32)&sBlob_6b2fac_72eee0 + 0x61ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x6260,
    (u32)&sBlob_6b2fac_72eee0 + 0x62c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x6334,
    (u32)&sBlob_6b2fac_72eee0 + 0x6396,
    (u32)&sBlob_6b2fac_72eee0 + 0x6404,
    (u32)&sBlob_6b2fac_72eee0 + 0x647c,
    (u32)&sBlob_6b2fac_72eee0 + 0x64ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x655c,
    (u32)&sBlob_6b2fac_72eee0 + 0x65cc,
    (u32)&sBlob_6b2fac_72eee0 + 0x6634,
    (u32)&sBlob_6b2fac_72eee0 + 0x66a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x6704,
    (u32)&sBlob_6b2fac_72eee0 + 0x6768,
    (u32)&sBlob_6b2fac_72eee0 + 0x67d8,
    (u32)&sBlob_6b2fac_72eee0 + 0x685e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6896,
    (u32)&sBlob_6b2fac_72eee0 + 0x68d6,
    (u32)&sBlob_6b2fac_72eee0 + 0x6926,
    (u32)&sBlob_6b2fac_72eee0 + 0x696c,
    (u32)&sBlob_6b2fac_72eee0 + 0x69c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a32,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a70,
    (u32)&sBlob_6b2fac_72eee0 + 0x6aa6,
    (u32)&sBlob_6b2fac_72eee0 + 0x6ae4,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b2c,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b7e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6bd6,
    (u32)&sBlob_6b2fac_72eee0 + 0x6c50,
    (u32)&sBlob_6b2fac_72eee0 + 0x6cc6,
    (u32)&sBlob_6b2fac_72eee0 + 0x6d40,
    (u32)&sBlob_6b2fac_72eee0 + 0x6db2,
    (u32)&sBlob_6b2fac_72eee0 + 0x6dfa,
    (u32)&sBlob_6b2fac_72eee0 + 0x6e4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x6ec4,
    (u32)&sBlob_6b2fac_72eee0 + 0x6f2e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6f3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6f62,
    (u32)&sBlob_6b2fac_72eee0 + 0x6f84,
    (u32)&sBlob_6b2fac_72eee0 + 0x6fa6,
    (u32)&sBlob_6b2fac_72eee0 + 0x6fc8,
    (u32)&sBlob_6b2fac_72eee0 + 0x6fea,
    (u32)&sBlob_6b2fac_72eee0 + 0x700c,
    (u32)&sBlob_6b2fac_72eee0 + 0x702e,
    (u32)&sBlob_6b2fac_72eee0 + 0x7046,
    (u32)&sBlob_6b2fac_72eee0 + 0x7068,
    (u32)&sBlob_6b2fac_72eee0 + 0x708a,
    (u32)&sBlob_6b2fac_72eee0 + 0x70ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x70d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x70ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x7108,
    (u32)&sBlob_6b2fac_72eee0 + 0x7132,
    (u32)&sBlob_6b2fac_72eee0 + 0x715e,
    (u32)&sBlob_6b2fac_72eee0 + 0x718a,
    (u32)&sBlob_6b2fac_72eee0 + 0x71aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x71d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x71f0,
    (u32)&sBlob_6b2fac_72eee0 + 0x7224,
    (u32)&sBlob_6b2fac_72eee0 + 0x7262,
    (u32)&sBlob_6b2fac_72eee0 + 0x7292,
    (u32)&sBlob_6b2fac_72eee0 + 0x72c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x72e8,
    (u32)&sBlob_6b2fac_72eee0 + 0x7328,
    (u32)&sBlob_6b2fac_72eee0 + 0x738e,
    (u32)&sBlob_6b2fac_72eee0 + 0x73f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x7460,
    (u32)&sBlob_6b2fac_72eee0 + 0x74c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x7510,
    (u32)&sBlob_6b2fac_72eee0 + 0x7566,
    (u32)&sBlob_6b2fac_72eee0 + 0x75cc,
    (u32)&sBlob_6b2fac_72eee0 + 0x7642,
    (u32)&sBlob_6b2fac_72eee0 + 0x76bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x773a,
    (u32)&sBlob_6b2fac_72eee0 + 0x77a4,
    (u32)&sBlob_6b2fac_72eee0 + 0x780e,
    (u32)&sBlob_6b2fac_72eee0 + 0x787e,
    (u32)&sBlob_6b2fac_72eee0 + 0x78f6,
    (u32)&sBlob_6b2fac_72eee0 + 0x795e,
    (u32)&sBlob_6b2fac_72eee0 + 0x79d6,
    (u32)&sBlob_6b2fac_72eee0 + 0x7a54,
    (u32)&sBlob_6b2fac_72eee0 + 0x7ac6,
    (u32)&sBlob_6b2fac_72eee0 + 0x7b30,
    (u32)&sBlob_6b2fac_72eee0 + 0x7ba4,
    (u32)&sBlob_6b2fac_72eee0 + 0x7c1e,
    (u32)&sBlob_6b2fac_72eee0 + 0x7c92,
    (u32)&sBlob_6b2fac_72eee0 + 0x7cfc,
    (u32)&sBlob_6b2fac_72eee0 + 0x7d62,
    (u32)&sBlob_6b2fac_72eee0 + 0x7dc6,
    (u32)&sBlob_6b2fac_72eee0 + 0x7e28,
    (u32)&sBlob_6b2fac_72eee0 + 0x7e9e,
    (u32)&sBlob_6b2fac_72eee0 + 0x7ee4,
    (u32)&sBlob_6b2fac_72eee0 + 0x7f2e,
    (u32)&sBlob_6b2fac_72eee0 + 0x7f88,
    (u32)&sBlob_6b2fac_72eee0 + 0x7fca,
    (u32)&sBlob_6b2fac_72eee0 + 0x8042,
    (u32)&sBlob_6b2fac_72eee0 + 0x80a2,
    (u32)&sBlob_6b2fac_72eee0 + 0x80da,
    (u32)&sBlob_6b2fac_72eee0 + 0x8106,
    (u32)&sBlob_6b2fac_72eee0 + 0x8142,
    (u32)&sBlob_6b2fac_72eee0 + 0x819c,
    (u32)&sBlob_6b2fac_72eee0 + 0x81fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x825a,
    (u32)&sBlob_6b2fac_72eee0 + 0x82d6,
    (u32)&sBlob_6b2fac_72eee0 + 0x8354,
    (u32)&sBlob_6b2fac_72eee0 + 0x83cc,
    (u32)&sBlob_6b2fac_72eee0 + 0x8448,
    (u32)&sBlob_6b2fac_72eee0 + 0x8482,
    (u32)&sBlob_6b2fac_72eee0 + 0x84d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x8540,
    (u32)&sBlob_6b2fac_72eee0 + 0x858e,
    (u32)&sBlob_6b2fac_72eee0 + 0x859e,
    (u32)&sBlob_6b2fac_72eee0 + 0x85c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x85e6,
    (u32)&sBlob_6b2fac_72eee0 + 0x8606,
    (u32)&sBlob_6b2fac_72eee0 + 0x8626,
    (u32)&sBlob_6b2fac_72eee0 + 0x8646,
    (u32)&sBlob_6b2fac_72eee0 + 0x8666,
    (u32)&sBlob_6b2fac_72eee0 + 0x8686,
    (u32)&sBlob_6b2fac_72eee0 + 0x86aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x86ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x8700,
    (u32)&sBlob_6b2fac_72eee0 + 0x872c,
    (u32)&sBlob_6b2fac_72eee0 + 0x8754,
    (u32)&sBlob_6b2fac_72eee0 + 0x877c,
    (u32)&sBlob_6b2fac_72eee0 + 0x879a,
    (u32)&sBlob_6b2fac_72eee0 + 0x87c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x87ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x8816,
    (u32)&sBlob_6b2fac_72eee0 + 0x8838,
    (u32)&sBlob_6b2fac_72eee0 + 0x8860,
    (u32)&sBlob_6b2fac_72eee0 + 0x8890,
    (u32)&sBlob_6b2fac_72eee0 + 0x88c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x8904,
    (u32)&sBlob_6b2fac_72eee0 + 0x8938,
    (u32)&sBlob_6b2fac_72eee0 + 0x8972,
    (u32)&sBlob_6b2fac_72eee0 + 0x8998
};

const u16** sLocationTextPointers[LANGUAGE_COUNT] = {
    (const u16**)((const u8*)&sPointerTable_79c5c0 + 0xc0),
    (const u16**)((const u8*)&sPointerTable_79c5c0 + 0x1e8),
    (const u16**)((const u8*)&sPointerTable_79c5c0 + 0x310),
    (const u16**)((const u8*)&sPointerTable_79c5c0 + 0x438),
    (const u16**)((const u8*)&sPointerTable_79c5c0 + 0x560),
    (const u16**)((const u8*)&sPointerTable_79c5c0 + 0x688),
    (const u16**)((const u8*)&sPointerTable_79c5c0 + 0x7b0)
};

u16** sMessageTextPointers[LANGUAGE_COUNT] = {
    (u16**)(&sPointerTable_79c5c0),
    (u16**)((const u8*)&sPointerTable_79c5c0 + 0x128),
    (u16**)((const u8*)&sPointerTable_79c5c0 + 0x250),
    (u16**)((const u8*)&sPointerTable_79c5c0 + 0x378),
    (u16**)((const u8*)&sPointerTable_79c5c0 + 0x4a0),
    (u16**)((const u8*)&sPointerTable_79c5c0 + 0x5c8),
    (u16**)((const u8*)&sPointerTable_79c5c0 + 0x6f0)
};

u32 sPointerTable_79ce10[1572] = {
    (u32)&sBlob_6b2fac_72eee0 + 0x89d8,
    (u32)&sBlob_6b2fac_72eee0 + 0x8c72,
    (u32)&sBlob_6b2fac_72eee0 + 0x8c8c,
    (u32)&sBlob_6b2fac_72eee0 + 0x8cd6,
    (u32)&sBlob_6b2fac_72eee0 + 0x8cf2,
    (u32)&sBlob_6b2fac_72eee0 + 0x8d08,
    (u32)&sBlob_6b2fac_72eee0 + 0x8d1a,
    (u32)&sBlob_6b2fac_72eee0 + 0x9334,
    (u32)&sBlob_6b2fac_72eee0 + 0x934c,
    (u32)&sBlob_6b2fac_72eee0 + 0x9522,
    (u32)&sBlob_6b2fac_72eee0 + 0x9538,
    (u32)&sBlob_6b2fac_72eee0 + 0x9554,
    (u32)&sBlob_6b2fac_72eee0 + 0x9570,
    (u32)&sBlob_6b2fac_72eee0 + 0x9582,
    (u32)&sBlob_6b2fac_72eee0 + 0x9594,
    (u32)&sBlob_6b2fac_72eee0 + 0x984a,
    (u32)&sBlob_6b2fac_72eee0 + 0x9862,
    (u32)&sBlob_6b2fac_72eee0 + 0x9874,
    (u32)&sBlob_6b2fac_72eee0 + 0x9886,
    (u32)&sBlob_6b2fac_72eee0 + 0x9ac0,
    (u32)&sBlob_6b2fac_72eee0 + 0x9ae8,
    (u32)&sBlob_6b2fac_72eee0 + 0x9d90,
    (u32)&sBlob_6b2fac_72eee0 + 0x9de6,
    (u32)&sBlob_6b2fac_72eee0 + 0x9eb4,
    (u32)&sBlob_6b2fac_72eee0 + 0x9f1e,
    (u32)&sBlob_6b2fac_72eee0 + 0xa10a,
    (u32)&sBlob_6b2fac_72eee0 + 0xa14e,
    (u32)&sBlob_6b2fac_72eee0 + 0xa886,
    (u32)&sBlob_6b2fac_72eee0 + 0xa8fa,
    (u32)&sBlob_6b2fac_72eee0 + 0xa9aa,
    (u32)&sBlob_6b2fac_72eee0 + 0xa9e8,
    (u32)&sBlob_6b2fac_72eee0 + 0xa9fa,
    (u32)&sBlob_6b2fac_72eee0 + 0xaa0c,
    (u32)&sBlob_6b2fac_72eee0 + 0xac04,
    (u32)&sBlob_6b2fac_72eee0 + 0xac5c,
    (u32)&sBlob_6b2fac_72eee0 + 0xb17a,
    (u32)&sBlob_6b2fac_72eee0 + 0xb1ba,
    (u32)&sBlob_6b2fac_72eee0 + 0xb1cc,
    (u32)&sBlob_6b2fac_72eee0 + 0xb1de,
    (u32)&sBlob_6b2fac_72eee0 + 0xb202,
    (u32)&sBlob_6b2fac_72eee0 + 0xb226,
    (u32)&sBlob_6b2fac_72eee0 + 0xb5c8,
    (u32)&sBlob_6b2fac_72eee0 + 0xb5f6,
    (u32)&sBlob_6b2fac_72eee0 + 0xbaa8,
    (u32)&sBlob_6b2fac_72eee0 + 0xbafa,
    (u32)&sBlob_6b2fac_72eee0 + 0xbb88,
    (u32)&sBlob_6b2fac_72eee0 + 0xbbca,
    (u32)&sBlob_6b2fac_72eee0 + 0xbbdc,
    (u32)&sBlob_6b2fac_72eee0 + 0xbbee,
    (u32)&sBlob_6b2fac_72eee0 + 0xc0b0,
    (u32)&sBlob_6b2fac_72eee0 + 0xc0de,
    (u32)&sBlob_6b2fac_72eee0 + 0xc168,
    (u32)&sBlob_6b2fac_72eee0 + 0xc188,
    (u32)&sBlob_6b2fac_72eee0 + 0xc1b8,
    (u32)&sBlob_6b2fac_72eee0 + 0xc1e8,
    (u32)&sBlob_6b2fac_72eee0 + 0xc568,
    (u32)&sBlob_6b2fac_72eee0 + 0xc5ac,
    (u32)&sBlob_6b2fac_72eee0 + 0xc5be,
    (u32)&sBlob_6b2fac_72eee0 + 0xc5d0,
    (u32)&sBlob_6b2fac_72eee0 + 0xcc3a,
    (u32)&sBlob_6b2fac_72eee0 + 0xcc9c,
    (u32)&sBlob_6b2fac_72eee0 + 0xce30,
    (u32)&sBlob_6b2fac_72eee0 + 0xce88,
    (u32)&sBlob_6b2fac_72eee0 + 0xcf2a,
    (u32)&sBlob_6b2fac_72eee0 + 0xcf72,
    (u32)&sBlob_6b2fac_72eee0 + 0xcf88,
    (u32)&sBlob_6b2fac_72eee0 + 0xcf9e,
    (u32)&sBlob_6b2fac_72eee0 + 0xd2e2,
    (u32)&sBlob_6b2fac_72eee0 + 0xd31c,
    (u32)&sBlob_6b2fac_72eee0 + 0xd332,
    (u32)&sBlob_6b2fac_72eee0 + 0xd348,
    (u32)&sBlob_6b2fac_72eee0 + 0xd75c,
    (u32)&sBlob_6b2fac_72eee0 + 0xd78c,
    (u32)&sBlob_6b2fac_72eee0 + 0xd7a2,
    (u32)&sBlob_6b2fac_72eee0 + 0xd7b8,
    (u32)&sBlob_6b2fac_72eee0 + 0xda92,
    (u32)&sBlob_6b2fac_72eee0 + 0xdaec,
    (u32)&sBlob_6b2fac_72eee0 + 0xdb70,
    (u32)&sBlob_6b2fac_72eee0 + 0xdbba,
    (u32)&sBlob_6b2fac_72eee0 + 0xdbcc,
    (u32)&sBlob_6b2fac_72eee0 + 0xdbde,
    (u32)&sBlob_6b2fac_72eee0 + 0xdc0a,
    (u32)&sBlob_6b2fac_72eee0 + 0xdc20,
    (u32)&sBlob_6b2fac_72eee0 + 0xdf14,
    (u32)&sBlob_6b2fac_72eee0 + 0xdf34,
    (u32)&sBlob_6b2fac_72eee0 + 0xdf46,
    (u32)&sBlob_6b2fac_72eee0 + 0xdf58,
    (u32)&sBlob_6b2fac_72eee0 + 0xe0e8,
    (u32)&sBlob_6b2fac_72eee0 + 0xe10e,
    (u32)&sBlob_6b2fac_72eee0 + 0xe376,
    (u32)&sBlob_6b2fac_72eee0 + 0xe3b0,
    (u32)&sBlob_6b2fac_72eee0 + 0xe576,
    (u32)&sBlob_6b2fac_72eee0 + 0xe59e,
    (u32)&sBlob_6b2fac_72eee0 + 0xe5c0,
    (u32)&sBlob_6b2fac_72eee0 + 0xe606,
    (u32)&sBlob_6b2fac_72eee0 + 0xe78e,
    (u32)&sBlob_6b2fac_72eee0 + 0xe7ec,
    (u32)&sBlob_6b2fac_72eee0 + 0xea66,
    (u32)&sBlob_6b2fac_72eee0 + 0xeab2,
    (u32)&sBlob_6b2fac_72eee0 + 0xebf0,
    (u32)&sBlob_6b2fac_72eee0 + 0xec50,
    (u32)&sBlob_6b2fac_72eee0 + 0xf222,
    (u32)&sBlob_6b2fac_72eee0 + 0xf23a,
    (u32)&sBlob_6b2fac_72eee0 + 0xf814,
    (u32)&sBlob_6b2fac_72eee0 + 0xf828,
    (u32)&sBlob_6b2fac_72eee0 + 0xfe48,
    (u32)&sBlob_6b2fac_72eee0 + 0xfe90,
    (u32)&sBlob_6b2fac_72eee0 + 0xff10,
    (u32)&sBlob_6b2fac_72eee0 + 0xff58,
    (u32)&sBlob_6b2fac_72eee0 + 0xff6a,
    (u32)&sBlob_6b2fac_72eee0 + 0xff7c,
    (u32)&sBlob_6b2fac_72eee0 + 0xffcc,
    (u32)&sBlob_6b2fac_72eee0 + 0xffde,
    (u32)&sBlob_6b2fac_72eee0 + 0x10086,
    (u32)&sBlob_6b2fac_72eee0 + 0x1008c,
    (u32)&sBlob_6b2fac_72eee0 + 0x100e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x100fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1014c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1019e,
    (u32)&sBlob_6b2fac_72eee0 + 0x101ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x10216,
    (u32)&sBlob_6b2fac_72eee0 + 0x10242,
    (u32)&sBlob_6b2fac_72eee0 + 0x1027a,
    (u32)&sBlob_6b2fac_72eee0 + 0x102b2,
    (u32)&sBlob_6b2fac_72eee0 + 0x1030c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1036e,
    (u32)&sBlob_6b2fac_72eee0 + 0x103c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1041a,
    (u32)&sBlob_6b2fac_72eee0 + 0x10470,
    (u32)&sBlob_6b2fac_72eee0 + 0x104c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x10518,
    (u32)&sBlob_6b2fac_72eee0 + 0x10578,
    (u32)&sBlob_6b2fac_72eee0 + 0x105dc,
    (u32)&sBlob_6b2fac_72eee0 + 0x10646,
    (u32)&sBlob_6b2fac_72eee0 + 0x106a6,
    (u32)&sBlob_6b2fac_72eee0 + 0x10706,
    (u32)&sBlob_6b2fac_72eee0 + 0x10766,
    (u32)&sBlob_6b2fac_72eee0 + 0x107c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1082a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1088c,
    (u32)&sBlob_6b2fac_72eee0 + 0x108f6,
    (u32)&sBlob_6b2fac_72eee0 + 0x1095c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1099c,
    (u32)&sBlob_6b2fac_72eee0 + 0x109b2,
    (u32)&sBlob_6b2fac_72eee0 + 0x10a1c,
    (u32)&sBlob_6b2fac_72eee0 + 0x10a38,
    (u32)&sBlob_6b2fac_72eee0 + 0x10aa2,
    (u32)&sBlob_6b2fac_72eee0 + 0x10afe,
    (u32)&sBlob_6b2fac_72eee0 + 0x10b54,
    (u32)&sBlob_6b2fac_72eee0 + 0x10bae,
    (u32)&sBlob_6b2fac_72eee0 + 0x10c18,
    (u32)&sBlob_6b2fac_72eee0 + 0x10c82,
    (u32)&sBlob_6b2fac_72eee0 + 0x10cec,
    (u32)&sBlob_6b2fac_72eee0 + 0x10d50,
    (u32)&sBlob_6b2fac_72eee0 + 0x10d7c,
    (u32)&sBlob_6b2fac_72eee0 + 0x10dcc,
    (u32)&sBlob_6b2fac_72eee0 + 0x10e0e,
    (u32)&sBlob_6b2fac_72eee0 + 0x10e50,
    (u32)&sBlob_6b2fac_72eee0 + 0x10e92,
    (u32)&sBlob_6b2fac_72eee0 + 0x10ed4,
    (u32)&sBlob_6b2fac_72eee0 + 0x10f16,
    (u32)&sBlob_6b2fac_72eee0 + 0x10f58,
    (u32)&sBlob_6b2fac_72eee0 + 0x10fb2,
    (u32)&sBlob_6b2fac_72eee0 + 0x1100c,
    (u32)&sBlob_6b2fac_72eee0 + 0x11066,
    (u32)&sBlob_6b2fac_72eee0 + 0x110c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x11120,
    (u32)&sBlob_6b2fac_72eee0 + 0x1117c,
    (u32)&sBlob_6b2fac_72eee0 + 0x111cc,
    (u32)&sBlob_6b2fac_72eee0 + 0x11228,
    (u32)&sBlob_6b2fac_72eee0 + 0x11290,
    (u32)&sBlob_6b2fac_72eee0 + 0x112f8,
    (u32)&sBlob_6b2fac_72eee0 + 0x11360,
    (u32)&sBlob_6b2fac_72eee0 + 0x113cc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1142a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1147a,
    (u32)&sBlob_6b2fac_72eee0 + 0x114d6,
    (u32)&sBlob_6b2fac_72eee0 + 0x11520,
    (u32)&sBlob_6b2fac_72eee0 + 0x11580,
    (u32)&sBlob_6b2fac_72eee0 + 0x115dc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1163c,
    (u32)&sBlob_6b2fac_72eee0 + 0x11698,
    (u32)&sBlob_6b2fac_72eee0 + 0x116f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x11750,
    (u32)&sBlob_6b2fac_72eee0 + 0x1176a,
    (u32)&sBlob_6b2fac_72eee0 + 0x11784,
    (u32)&sBlob_6b2fac_72eee0 + 0x117de,
    (u32)&sBlob_6b2fac_72eee0 + 0x11838,
    (u32)&sBlob_6b2fac_72eee0 + 0x1189a,
    (u32)&sBlob_6b2fac_72eee0 + 0x118c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x11926,
    (u32)&sBlob_6b2fac_72eee0 + 0x11984,
    (u32)&sBlob_6b2fac_72eee0 + 0x119e2,
    (u32)&sBlob_6b2fac_72eee0 + 0x11a30,
    (u32)&sBlob_6b2fac_72eee0 + 0x11a7a,
    (u32)&sBlob_6b2fac_72eee0 + 0x11aae,
    (u32)&sBlob_6b2fac_72eee0 + 0x11b10,
    (u32)&sBlob_6b2fac_72eee0 + 0x11b72,
    (u32)&sBlob_6b2fac_72eee0 + 0x11bce,
    (u32)&sBlob_6b2fac_72eee0 + 0x11c2a,
    (u32)&sBlob_6b2fac_72eee0 + 0x11c42,
    (u32)&sBlob_6b2fac_72eee0 + 0x11cb2,
    (u32)&sBlob_6b2fac_72eee0 + 0x11d00,
    (u32)&sBlob_6b2fac_72eee0 + 0x11d4e,
    (u32)&sBlob_6b2fac_72eee0 + 0x11d9c,
    (u32)&sBlob_6b2fac_72eee0 + 0x11dea,
    (u32)&sBlob_6b2fac_72eee0 + 0x11e1e,
    (u32)&sBlob_6b2fac_72eee0 + 0x11e6c,
    (u32)&sBlob_6b2fac_72eee0 + 0x11eba,
    (u32)&sBlob_6b2fac_72eee0 + 0x11ed8,
    (u32)&sBlob_6b2fac_72eee0 + 0x11f34,
    (u32)&sBlob_6b2fac_72eee0 + 0x11f8c,
    (u32)&sBlob_6b2fac_72eee0 + 0x11fac,
    (u32)&sBlob_6b2fac_72eee0 + 0x12004,
    (u32)&sBlob_6b2fac_72eee0 + 0x1205c,
    (u32)&sBlob_6b2fac_72eee0 + 0x120b4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1210c,
    (u32)&sBlob_6b2fac_72eee0 + 0x12164,
    (u32)&sBlob_6b2fac_72eee0 + 0x1219e,
    (u32)&sBlob_6b2fac_72eee0 + 0x121d8,
    (u32)&sBlob_6b2fac_72eee0 + 0x12212,
    (u32)&sBlob_6b2fac_72eee0 + 0x1224c,
    (u32)&sBlob_6b2fac_72eee0 + 0x122a4,
    (u32)&sBlob_6b2fac_72eee0 + 0x122d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x122fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x12328,
    (u32)&sBlob_6b2fac_72eee0 + 0x125c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x125dc,
    (u32)&sBlob_6b2fac_72eee0 + 0x12626,
    (u32)&sBlob_6b2fac_72eee0 + 0x12642,
    (u32)&sBlob_6b2fac_72eee0 + 0x12658,
    (u32)&sBlob_6b2fac_72eee0 + 0x1266a,
    (u32)&sBlob_6b2fac_72eee0 + 0x12c84,
    (u32)&sBlob_6b2fac_72eee0 + 0x12c9c,
    (u32)&sBlob_6b2fac_72eee0 + 0x12e72,
    (u32)&sBlob_6b2fac_72eee0 + 0x12e88,
    (u32)&sBlob_6b2fac_72eee0 + 0x12ea4,
    (u32)&sBlob_6b2fac_72eee0 + 0x12ec0,
    (u32)&sBlob_6b2fac_72eee0 + 0x12ed2,
    (u32)&sBlob_6b2fac_72eee0 + 0x12ee4,
    (u32)&sBlob_6b2fac_72eee0 + 0x13196,
    (u32)&sBlob_6b2fac_72eee0 + 0x131ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x131c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x131d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x1340c,
    (u32)&sBlob_6b2fac_72eee0 + 0x13434,
    (u32)&sBlob_6b2fac_72eee0 + 0x136dc,
    (u32)&sBlob_6b2fac_72eee0 + 0x13732,
    (u32)&sBlob_6b2fac_72eee0 + 0x13800,
    (u32)&sBlob_6b2fac_72eee0 + 0x1386a,
    (u32)&sBlob_6b2fac_72eee0 + 0x13a5a,
    (u32)&sBlob_6b2fac_72eee0 + 0x13a9e,
    (u32)&sBlob_6b2fac_72eee0 + 0x141d4,
    (u32)&sBlob_6b2fac_72eee0 + 0x14248,
    (u32)&sBlob_6b2fac_72eee0 + 0x142f8,
    (u32)&sBlob_6b2fac_72eee0 + 0x14336,
    (u32)&sBlob_6b2fac_72eee0 + 0x14348,
    (u32)&sBlob_6b2fac_72eee0 + 0x1435a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1455a,
    (u32)&sBlob_6b2fac_72eee0 + 0x145b2,
    (u32)&sBlob_6b2fac_72eee0 + 0x14aca,
    (u32)&sBlob_6b2fac_72eee0 + 0x14b0a,
    (u32)&sBlob_6b2fac_72eee0 + 0x14b1c,
    (u32)&sBlob_6b2fac_72eee0 + 0x14b2e,
    (u32)&sBlob_6b2fac_72eee0 + 0x14b52,
    (u32)&sBlob_6b2fac_72eee0 + 0x14b76,
    (u32)&sBlob_6b2fac_72eee0 + 0x14f1a,
    (u32)&sBlob_6b2fac_72eee0 + 0x14f4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x153fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1544e,
    (u32)&sBlob_6b2fac_72eee0 + 0x154da,
    (u32)&sBlob_6b2fac_72eee0 + 0x1551c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1552e,
    (u32)&sBlob_6b2fac_72eee0 + 0x15540,
    (u32)&sBlob_6b2fac_72eee0 + 0x159fa,
    (u32)&sBlob_6b2fac_72eee0 + 0x15a24,
    (u32)&sBlob_6b2fac_72eee0 + 0x15aae,
    (u32)&sBlob_6b2fac_72eee0 + 0x15ace,
    (u32)&sBlob_6b2fac_72eee0 + 0x15afa,
    (u32)&sBlob_6b2fac_72eee0 + 0x15b26,
    (u32)&sBlob_6b2fac_72eee0 + 0x15e9e,
    (u32)&sBlob_6b2fac_72eee0 + 0x15ee2,
    (u32)&sBlob_6b2fac_72eee0 + 0x15ef4,
    (u32)&sBlob_6b2fac_72eee0 + 0x15f06,
    (u32)&sBlob_6b2fac_72eee0 + 0x1656c,
    (u32)&sBlob_6b2fac_72eee0 + 0x165ca,
    (u32)&sBlob_6b2fac_72eee0 + 0x1675e,
    (u32)&sBlob_6b2fac_72eee0 + 0x167b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x16854,
    (u32)&sBlob_6b2fac_72eee0 + 0x16898,
    (u32)&sBlob_6b2fac_72eee0 + 0x168ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x168c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x16c02,
    (u32)&sBlob_6b2fac_72eee0 + 0x16c3c,
    (u32)&sBlob_6b2fac_72eee0 + 0x16c52,
    (u32)&sBlob_6b2fac_72eee0 + 0x16c68,
    (u32)&sBlob_6b2fac_72eee0 + 0x1707c,
    (u32)&sBlob_6b2fac_72eee0 + 0x170ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x170c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x170da,
    (u32)&sBlob_6b2fac_72eee0 + 0x173ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x17406,
    (u32)&sBlob_6b2fac_72eee0 + 0x1748a,
    (u32)&sBlob_6b2fac_72eee0 + 0x174d6,
    (u32)&sBlob_6b2fac_72eee0 + 0x174e8,
    (u32)&sBlob_6b2fac_72eee0 + 0x174fa,
    (u32)&sBlob_6b2fac_72eee0 + 0x17526,
    (u32)&sBlob_6b2fac_72eee0 + 0x1753c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1782e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1784e,
    (u32)&sBlob_6b2fac_72eee0 + 0x17860,
    (u32)&sBlob_6b2fac_72eee0 + 0x17872,
    (u32)&sBlob_6b2fac_72eee0 + 0x17a02,
    (u32)&sBlob_6b2fac_72eee0 + 0x17a28,
    (u32)&sBlob_6b2fac_72eee0 + 0x17c90,
    (u32)&sBlob_6b2fac_72eee0 + 0x17cca,
    (u32)&sBlob_6b2fac_72eee0 + 0x17e94,
    (u32)&sBlob_6b2fac_72eee0 + 0x17ebc,
    (u32)&sBlob_6b2fac_72eee0 + 0x17ede,
    (u32)&sBlob_6b2fac_72eee0 + 0x17f24,
    (u32)&sBlob_6b2fac_72eee0 + 0x17f50,
    (u32)&sBlob_6b2fac_72eee0 + 0x17f78,
    (u32)&sBlob_6b2fac_72eee0 + 0x181ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x18236,
    (u32)&sBlob_6b2fac_72eee0 + 0x18370,
    (u32)&sBlob_6b2fac_72eee0 + 0x183d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x18986,
    (u32)&sBlob_6b2fac_72eee0 + 0x1899e,
    (u32)&sBlob_6b2fac_72eee0 + 0x18f76,
    (u32)&sBlob_6b2fac_72eee0 + 0x18f8a,
    (u32)&sBlob_6b2fac_72eee0 + 0x195a6,
    (u32)&sBlob_6b2fac_72eee0 + 0x195ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x1966e,
    (u32)&sBlob_6b2fac_72eee0 + 0x196b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x196c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x196da,
    (u32)&sBlob_6b2fac_72eee0 + 0x1972a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1973c,
    (u32)&sBlob_6b2fac_72eee0 + 0x197e4,
    (u32)&sBlob_6b2fac_72eee0 + 0x197ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x19840,
    (u32)&sBlob_6b2fac_72eee0 + 0x1985c,
    (u32)&sBlob_6b2fac_72eee0 + 0x198ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x198fe,
    (u32)&sBlob_6b2fac_72eee0 + 0x1994a,
    (u32)&sBlob_6b2fac_72eee0 + 0x19976,
    (u32)&sBlob_6b2fac_72eee0 + 0x199ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x199e4,
    (u32)&sBlob_6b2fac_72eee0 + 0x19a1c,
    (u32)&sBlob_6b2fac_72eee0 + 0x19a76,
    (u32)&sBlob_6b2fac_72eee0 + 0x19ad8,
    (u32)&sBlob_6b2fac_72eee0 + 0x19b2e,
    (u32)&sBlob_6b2fac_72eee0 + 0x19b84,
    (u32)&sBlob_6b2fac_72eee0 + 0x19bda,
    (u32)&sBlob_6b2fac_72eee0 + 0x19c2a,
    (u32)&sBlob_6b2fac_72eee0 + 0x19c82,
    (u32)&sBlob_6b2fac_72eee0 + 0x19ce2,
    (u32)&sBlob_6b2fac_72eee0 + 0x19d46,
    (u32)&sBlob_6b2fac_72eee0 + 0x19db2,
    (u32)&sBlob_6b2fac_72eee0 + 0x19e14,
    (u32)&sBlob_6b2fac_72eee0 + 0x19e76,
    (u32)&sBlob_6b2fac_72eee0 + 0x19eba,
    (u32)&sBlob_6b2fac_72eee0 + 0x19f1c,
    (u32)&sBlob_6b2fac_72eee0 + 0x19f7e,
    (u32)&sBlob_6b2fac_72eee0 + 0x19fe0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a04a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a0b0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a0f0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a106,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a172,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a18e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a1b0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a20c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a262,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a2bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a326,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a390,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a3de,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a43c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a468,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a4b8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a4fa,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a53c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a57e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a5c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a602,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a644,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a69e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a6f8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a752,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a7b0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a80c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a868,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a8b8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a914,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a97c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1a9e4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1aa30,
    (u32)&sBlob_6b2fac_72eee0 + 0x1aa98,
    (u32)&sBlob_6b2fac_72eee0 + 0x1aafc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ab52,
    (u32)&sBlob_6b2fac_72eee0 + 0x1abae,
    (u32)&sBlob_6b2fac_72eee0 + 0x1abf8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ac58,
    (u32)&sBlob_6b2fac_72eee0 + 0x1acb4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ad14,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ad70,
    (u32)&sBlob_6b2fac_72eee0 + 0x1adcc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ae28,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ae42,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ae5c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1aeb6,
    (u32)&sBlob_6b2fac_72eee0 + 0x1af10,
    (u32)&sBlob_6b2fac_72eee0 + 0x1af72,
    (u32)&sBlob_6b2fac_72eee0 + 0x1afa0,
    (u32)&sBlob_6b2fac_72eee0 + 0x1affe,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b050,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b09a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b0ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b130,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b14c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b1a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b204,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b250,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b2b4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b302,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b350,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b39e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b3ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b420,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b46e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b4bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b4da,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b536,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b58e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b5b2,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b60a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b664,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b6be,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b718,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b772,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b7ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b7ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b826,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b87e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b8aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b8d6,
    (u32)&sBlob_6b2fac_72eee0 + 0x1b904,
    (u32)&sBlob_6b2fac_72eee0 + 0x1bcce,
    (u32)&sBlob_6b2fac_72eee0 + 0x1bd06,
    (u32)&sBlob_6b2fac_72eee0 + 0x1bd92,
    (u32)&sBlob_6b2fac_72eee0 + 0x1bdd2,
    (u32)&sBlob_6b2fac_72eee0 + 0x1bdf8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1be1e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1c926,
    (u32)&sBlob_6b2fac_72eee0 + 0x1c94c,
    (u32)&sBlob_6b2fac_72eee0 + 0x1cbd4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1cc04,
    (u32)&sBlob_6b2fac_72eee0 + 0x1cc3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1cc60,
    (u32)&sBlob_6b2fac_72eee0 + 0x1cc86,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ccac,
    (u32)&sBlob_6b2fac_72eee0 + 0x1d058,
    (u32)&sBlob_6b2fac_72eee0 + 0x1d07e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1d0a4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1d0ca,
    (u32)&sBlob_6b2fac_72eee0 + 0x1d470,
    (u32)&sBlob_6b2fac_72eee0 + 0x1d4a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1d872,
    (u32)&sBlob_6b2fac_72eee0 + 0x1d8da,
    (u32)&sBlob_6b2fac_72eee0 + 0x1da28,
    (u32)&sBlob_6b2fac_72eee0 + 0x1dad4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1dde2,
    (u32)&sBlob_6b2fac_72eee0 + 0x1de48,
    (u32)&sBlob_6b2fac_72eee0 + 0x1e814,
    (u32)&sBlob_6b2fac_72eee0 + 0x1e8e4,
    (u32)&sBlob_6b2fac_72eee0 + 0x1e9da,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ea3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ea64,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ea8a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ede2,
    (u32)&sBlob_6b2fac_72eee0 + 0x1ee52,
    (u32)&sBlob_6b2fac_72eee0 + 0x1f68a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1f6e8,
    (u32)&sBlob_6b2fac_72eee0 + 0x1f70e,
    (u32)&sBlob_6b2fac_72eee0 + 0x1f734,
    (u32)&sBlob_6b2fac_72eee0 + 0x1f742,
    (u32)&sBlob_6b2fac_72eee0 + 0x1f752,
    (u32)&sBlob_6b2fac_72eee0 + 0x1fd7a,
    (u32)&sBlob_6b2fac_72eee0 + 0x1fdb4,
    (u32)&sBlob_6b2fac_72eee0 + 0x20466,
    (u32)&sBlob_6b2fac_72eee0 + 0x204d8,
    (u32)&sBlob_6b2fac_72eee0 + 0x205c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x2062c,
    (u32)&sBlob_6b2fac_72eee0 + 0x20652,
    (u32)&sBlob_6b2fac_72eee0 + 0x20678,
    (u32)&sBlob_6b2fac_72eee0 + 0x20e74,
    (u32)&sBlob_6b2fac_72eee0 + 0x20ea8,
    (u32)&sBlob_6b2fac_72eee0 + 0x20f7a,
    (u32)&sBlob_6b2fac_72eee0 + 0x20f8c,
    (u32)&sBlob_6b2fac_72eee0 + 0x20fc6,
    (u32)&sBlob_6b2fac_72eee0 + 0x21000,
    (u32)&sBlob_6b2fac_72eee0 + 0x21500,
    (u32)&sBlob_6b2fac_72eee0 + 0x21568,
    (u32)&sBlob_6b2fac_72eee0 + 0x2158e,
    (u32)&sBlob_6b2fac_72eee0 + 0x215b4,
    (u32)&sBlob_6b2fac_72eee0 + 0x21dea,
    (u32)&sBlob_6b2fac_72eee0 + 0x21e5e,
    (u32)&sBlob_6b2fac_72eee0 + 0x220c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x22130,
    (u32)&sBlob_6b2fac_72eee0 + 0x22222,
    (u32)&sBlob_6b2fac_72eee0 + 0x22284,
    (u32)&sBlob_6b2fac_72eee0 + 0x222aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x222d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x22768,
    (u32)&sBlob_6b2fac_72eee0 + 0x227ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x227f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x2281a,
    (u32)&sBlob_6b2fac_72eee0 + 0x22eea,
    (u32)&sBlob_6b2fac_72eee0 + 0x22f3c,
    (u32)&sBlob_6b2fac_72eee0 + 0x22f62,
    (u32)&sBlob_6b2fac_72eee0 + 0x22f88,
    (u32)&sBlob_6b2fac_72eee0 + 0x23450,
    (u32)&sBlob_6b2fac_72eee0 + 0x234c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x2357c,
    (u32)&sBlob_6b2fac_72eee0 + 0x235f2,
    (u32)&sBlob_6b2fac_72eee0 + 0x23618,
    (u32)&sBlob_6b2fac_72eee0 + 0x2363e,
    (u32)&sBlob_6b2fac_72eee0 + 0x236b2,
    (u32)&sBlob_6b2fac_72eee0 + 0x236dc,
    (u32)&sBlob_6b2fac_72eee0 + 0x23c60,
    (u32)&sBlob_6b2fac_72eee0 + 0x23ca2,
    (u32)&sBlob_6b2fac_72eee0 + 0x23cc8,
    (u32)&sBlob_6b2fac_72eee0 + 0x23cee,
    (u32)&sBlob_6b2fac_72eee0 + 0x23f94,
    (u32)&sBlob_6b2fac_72eee0 + 0x23ff4,
    (u32)&sBlob_6b2fac_72eee0 + 0x24388,
    (u32)&sBlob_6b2fac_72eee0 + 0x243e2,
    (u32)&sBlob_6b2fac_72eee0 + 0x24796,
    (u32)&sBlob_6b2fac_72eee0 + 0x247d4,
    (u32)&sBlob_6b2fac_72eee0 + 0x24810,
    (u32)&sBlob_6b2fac_72eee0 + 0x24870,
    (u32)&sBlob_6b2fac_72eee0 + 0x24b36,
    (u32)&sBlob_6b2fac_72eee0 + 0x24be8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2503e,
    (u32)&sBlob_6b2fac_72eee0 + 0x250b0,
    (u32)&sBlob_6b2fac_72eee0 + 0x25280,
    (u32)&sBlob_6b2fac_72eee0 + 0x252f8,
    (u32)&sBlob_6b2fac_72eee0 + 0x25c70,
    (u32)&sBlob_6b2fac_72eee0 + 0x25c94,
    (u32)&sBlob_6b2fac_72eee0 + 0x26736,
    (u32)&sBlob_6b2fac_72eee0 + 0x26748,
    (u32)&sBlob_6b2fac_72eee0 + 0x27428,
    (u32)&sBlob_6b2fac_72eee0 + 0x27490,
    (u32)&sBlob_6b2fac_72eee0 + 0x2756e,
    (u32)&sBlob_6b2fac_72eee0 + 0x275a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x275ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x275f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x2767e,
    (u32)&sBlob_6b2fac_72eee0 + 0x276b0,
    (u32)&sBlob_6b2fac_72eee0 + 0x2779a,
    (u32)&sBlob_6b2fac_72eee0 + 0x277a4,
    (u32)&sBlob_6b2fac_72eee0 + 0x27812,
    (u32)&sBlob_6b2fac_72eee0 + 0x2784c,
    (u32)&sBlob_6b2fac_72eee0 + 0x278b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x27928,
    (u32)&sBlob_6b2fac_72eee0 + 0x2797c,
    (u32)&sBlob_6b2fac_72eee0 + 0x279ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x279dc,
    (u32)&sBlob_6b2fac_72eee0 + 0x27a1e,
    (u32)&sBlob_6b2fac_72eee0 + 0x27a60,
    (u32)&sBlob_6b2fac_72eee0 + 0x27ad6,
    (u32)&sBlob_6b2fac_72eee0 + 0x27b48,
    (u32)&sBlob_6b2fac_72eee0 + 0x27bbe,
    (u32)&sBlob_6b2fac_72eee0 + 0x27c34,
    (u32)&sBlob_6b2fac_72eee0 + 0x27caa,
    (u32)&sBlob_6b2fac_72eee0 + 0x27d14,
    (u32)&sBlob_6b2fac_72eee0 + 0x27d90,
    (u32)&sBlob_6b2fac_72eee0 + 0x27e08,
    (u32)&sBlob_6b2fac_72eee0 + 0x27e80,
    (u32)&sBlob_6b2fac_72eee0 + 0x27eec,
    (u32)&sBlob_6b2fac_72eee0 + 0x27f4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x27fa8,
    (u32)&sBlob_6b2fac_72eee0 + 0x28006,
    (u32)&sBlob_6b2fac_72eee0 + 0x28078,
    (u32)&sBlob_6b2fac_72eee0 + 0x280ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x2815c,
    (u32)&sBlob_6b2fac_72eee0 + 0x281c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2823c,
    (u32)&sBlob_6b2fac_72eee0 + 0x282a2,
    (u32)&sBlob_6b2fac_72eee0 + 0x282c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x28336,
    (u32)&sBlob_6b2fac_72eee0 + 0x28354,
    (u32)&sBlob_6b2fac_72eee0 + 0x283c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2843c,
    (u32)&sBlob_6b2fac_72eee0 + 0x284a4,
    (u32)&sBlob_6b2fac_72eee0 + 0x28506,
    (u32)&sBlob_6b2fac_72eee0 + 0x28566,
    (u32)&sBlob_6b2fac_72eee0 + 0x285c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x28626,
    (u32)&sBlob_6b2fac_72eee0 + 0x2869c,
    (u32)&sBlob_6b2fac_72eee0 + 0x286ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x28754,
    (u32)&sBlob_6b2fac_72eee0 + 0x287b8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2881c,
    (u32)&sBlob_6b2fac_72eee0 + 0x28880,
    (u32)&sBlob_6b2fac_72eee0 + 0x288e4,
    (u32)&sBlob_6b2fac_72eee0 + 0x28948,
    (u32)&sBlob_6b2fac_72eee0 + 0x289ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x28a10,
    (u32)&sBlob_6b2fac_72eee0 + 0x28a74,
    (u32)&sBlob_6b2fac_72eee0 + 0x28ad8,
    (u32)&sBlob_6b2fac_72eee0 + 0x28b50,
    (u32)&sBlob_6b2fac_72eee0 + 0x28bc0,
    (u32)&sBlob_6b2fac_72eee0 + 0x28c3c,
    (u32)&sBlob_6b2fac_72eee0 + 0x28ca8,
    (u32)&sBlob_6b2fac_72eee0 + 0x28d0c,
    (u32)&sBlob_6b2fac_72eee0 + 0x28d6e,
    (u32)&sBlob_6b2fac_72eee0 + 0x28dd0,
    (u32)&sBlob_6b2fac_72eee0 + 0x28e32,
    (u32)&sBlob_6b2fac_72eee0 + 0x28ea4,
    (u32)&sBlob_6b2fac_72eee0 + 0x28f0e,
    (u32)&sBlob_6b2fac_72eee0 + 0x28f7a,
    (u32)&sBlob_6b2fac_72eee0 + 0x28fe6,
    (u32)&sBlob_6b2fac_72eee0 + 0x2904c,
    (u32)&sBlob_6b2fac_72eee0 + 0x290be,
    (u32)&sBlob_6b2fac_72eee0 + 0x29128,
    (u32)&sBlob_6b2fac_72eee0 + 0x29184,
    (u32)&sBlob_6b2fac_72eee0 + 0x291f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x29264,
    (u32)&sBlob_6b2fac_72eee0 + 0x292d4,
    (u32)&sBlob_6b2fac_72eee0 + 0x292fe,
    (u32)&sBlob_6b2fac_72eee0 + 0x29328,
    (u32)&sBlob_6b2fac_72eee0 + 0x29396,
    (u32)&sBlob_6b2fac_72eee0 + 0x29404,
    (u32)&sBlob_6b2fac_72eee0 + 0x2947a,
    (u32)&sBlob_6b2fac_72eee0 + 0x294e4,
    (u32)&sBlob_6b2fac_72eee0 + 0x29556,
    (u32)&sBlob_6b2fac_72eee0 + 0x295c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2963a,
    (u32)&sBlob_6b2fac_72eee0 + 0x296b4,
    (u32)&sBlob_6b2fac_72eee0 + 0x2971c,
    (u32)&sBlob_6b2fac_72eee0 + 0x29790,
    (u32)&sBlob_6b2fac_72eee0 + 0x29804,
    (u32)&sBlob_6b2fac_72eee0 + 0x29878,
    (u32)&sBlob_6b2fac_72eee0 + 0x298f0,
    (u32)&sBlob_6b2fac_72eee0 + 0x29968,
    (u32)&sBlob_6b2fac_72eee0 + 0x29990,
    (u32)&sBlob_6b2fac_72eee0 + 0x29a04,
    (u32)&sBlob_6b2fac_72eee0 + 0x29a78,
    (u32)&sBlob_6b2fac_72eee0 + 0x29aec,
    (u32)&sBlob_6b2fac_72eee0 + 0x29b5a,
    (u32)&sBlob_6b2fac_72eee0 + 0x29bc8,
    (u32)&sBlob_6b2fac_72eee0 + 0x29c30,
    (u32)&sBlob_6b2fac_72eee0 + 0x29c98,
    (u32)&sBlob_6b2fac_72eee0 + 0x29d00,
    (u32)&sBlob_6b2fac_72eee0 + 0x29d38,
    (u32)&sBlob_6b2fac_72eee0 + 0x29d70,
    (u32)&sBlob_6b2fac_72eee0 + 0x29de6,
    (u32)&sBlob_6b2fac_72eee0 + 0x29e24,
    (u32)&sBlob_6b2fac_72eee0 + 0x29e8c,
    (u32)&sBlob_6b2fac_72eee0 + 0x29efc,
    (u32)&sBlob_6b2fac_72eee0 + 0x29f6c,
    (u32)&sBlob_6b2fac_72eee0 + 0x29fdc,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a04c,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a0a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a104,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a160,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a1bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a230,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a25a,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a276,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a294,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a6de,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a72c,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a808,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a86c,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a894,
    (u32)&sBlob_6b2fac_72eee0 + 0x2a8bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x2b714,
    (u32)&sBlob_6b2fac_72eee0 + 0x2b750,
    (u32)&sBlob_6b2fac_72eee0 + 0x2ba88,
    (u32)&sBlob_6b2fac_72eee0 + 0x2bb18,
    (u32)&sBlob_6b2fac_72eee0 + 0x2bb7e,
    (u32)&sBlob_6b2fac_72eee0 + 0x2bbbe,
    (u32)&sBlob_6b2fac_72eee0 + 0x2bbe6,
    (u32)&sBlob_6b2fac_72eee0 + 0x2bc0e,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c136,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c174,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c19c,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c1c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c628,
    (u32)&sBlob_6b2fac_72eee0 + 0x2c66e,
    (u32)&sBlob_6b2fac_72eee0 + 0x2cb8e,
    (u32)&sBlob_6b2fac_72eee0 + 0x2cc08,
    (u32)&sBlob_6b2fac_72eee0 + 0x2cdca,
    (u32)&sBlob_6b2fac_72eee0 + 0x2ceac,
    (u32)&sBlob_6b2fac_72eee0 + 0x2d2c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x2d350,
    (u32)&sBlob_6b2fac_72eee0 + 0x2dffa,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e146,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e268,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e318,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e340,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e368,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e7a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x2e878,
    (u32)&sBlob_6b2fac_72eee0 + 0x2f2ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x2f39a,
    (u32)&sBlob_6b2fac_72eee0 + 0x2f3c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x2f3ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x2f3f8,
    (u32)&sBlob_6b2fac_72eee0 + 0x2f406,
    (u32)&sBlob_6b2fac_72eee0 + 0x2fc54,
    (u32)&sBlob_6b2fac_72eee0 + 0x2fca4,
    (u32)&sBlob_6b2fac_72eee0 + 0x3066e,
    (u32)&sBlob_6b2fac_72eee0 + 0x30724,
    (u32)&sBlob_6b2fac_72eee0 + 0x30868,
    (u32)&sBlob_6b2fac_72eee0 + 0x30920,
    (u32)&sBlob_6b2fac_72eee0 + 0x30948,
    (u32)&sBlob_6b2fac_72eee0 + 0x30970,
    (u32)&sBlob_6b2fac_72eee0 + 0x31448,
    (u32)&sBlob_6b2fac_72eee0 + 0x31490,
    (u32)&sBlob_6b2fac_72eee0 + 0x31580,
    (u32)&sBlob_6b2fac_72eee0 + 0x31592,
    (u32)&sBlob_6b2fac_72eee0 + 0x315e2,
    (u32)&sBlob_6b2fac_72eee0 + 0x31632,
    (u32)&sBlob_6b2fac_72eee0 + 0x31d4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x31de4,
    (u32)&sBlob_6b2fac_72eee0 + 0x31e0c,
    (u32)&sBlob_6b2fac_72eee0 + 0x31e34,
    (u32)&sBlob_6b2fac_72eee0 + 0x328ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x32984,
    (u32)&sBlob_6b2fac_72eee0 + 0x32d2c,
    (u32)&sBlob_6b2fac_72eee0 + 0x32de0,
    (u32)&sBlob_6b2fac_72eee0 + 0x32f1a,
    (u32)&sBlob_6b2fac_72eee0 + 0x32fce,
    (u32)&sBlob_6b2fac_72eee0 + 0x32ff6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3301e,
    (u32)&sBlob_6b2fac_72eee0 + 0x335c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x33642,
    (u32)&sBlob_6b2fac_72eee0 + 0x3366a,
    (u32)&sBlob_6b2fac_72eee0 + 0x33692,
    (u32)&sBlob_6b2fac_72eee0 + 0x33fa8,
    (u32)&sBlob_6b2fac_72eee0 + 0x34028,
    (u32)&sBlob_6b2fac_72eee0 + 0x34050,
    (u32)&sBlob_6b2fac_72eee0 + 0x34078,
    (u32)&sBlob_6b2fac_72eee0 + 0x346ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x34798,
    (u32)&sBlob_6b2fac_72eee0 + 0x348ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x34976,
    (u32)&sBlob_6b2fac_72eee0 + 0x3499e,
    (u32)&sBlob_6b2fac_72eee0 + 0x349c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x34a5c,
    (u32)&sBlob_6b2fac_72eee0 + 0x34aa2,
    (u32)&sBlob_6b2fac_72eee0 + 0x350ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x3512c,
    (u32)&sBlob_6b2fac_72eee0 + 0x35154,
    (u32)&sBlob_6b2fac_72eee0 + 0x3517c,
    (u32)&sBlob_6b2fac_72eee0 + 0x354c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x35540,
    (u32)&sBlob_6b2fac_72eee0 + 0x359aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x35a2a,
    (u32)&sBlob_6b2fac_72eee0 + 0x35f08,
    (u32)&sBlob_6b2fac_72eee0 + 0x35f58,
    (u32)&sBlob_6b2fac_72eee0 + 0x35f94,
    (u32)&sBlob_6b2fac_72eee0 + 0x36048,
    (u32)&sBlob_6b2fac_72eee0 + 0x36418,
    (u32)&sBlob_6b2fac_72eee0 + 0x36500,
    (u32)&sBlob_6b2fac_72eee0 + 0x36a3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x36ad0,
    (u32)&sBlob_6b2fac_72eee0 + 0x36d78,
    (u32)&sBlob_6b2fac_72eee0 + 0x36e32,
    (u32)&sBlob_6b2fac_72eee0 + 0x37b7a,
    (u32)&sBlob_6b2fac_72eee0 + 0x37bbe,
    (u32)&sBlob_6b2fac_72eee0 + 0x38b96,
    (u32)&sBlob_6b2fac_72eee0 + 0x38ba8,
    (u32)&sBlob_6b2fac_72eee0 + 0x39c28,
    (u32)&sBlob_6b2fac_72eee0 + 0x39c8a,
    (u32)&sBlob_6b2fac_72eee0 + 0x39db6,
    (u32)&sBlob_6b2fac_72eee0 + 0x39ddc,
    (u32)&sBlob_6b2fac_72eee0 + 0x39e04,
    (u32)&sBlob_6b2fac_72eee0 + 0x39e2c,
    (u32)&sBlob_6b2fac_72eee0 + 0x39ed8,
    (u32)&sBlob_6b2fac_72eee0 + 0x39f16,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a084,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a090,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a108,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a14a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a1c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a240,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a2b2,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a310,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a36e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a3be,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a3f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a452,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a4ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a524,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a57a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a5d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a63a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a6b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a734,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a7ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a826,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a888,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a8ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a94c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3a9bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x3aa2c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3aa9c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ab16,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ab92,
    (u32)&sBlob_6b2fac_72eee0 + 0x3abf2,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ac18,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ac8a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3aca8,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ad1a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ad8e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ae04,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ae7a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3aedc,
    (u32)&sBlob_6b2fac_72eee0 + 0x3af3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3afa0,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b01a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b082,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b0fa,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b16a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b1da,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b24a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b2ba,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b32a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b39a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b40c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b47e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b4f0,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b55c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b5d4,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b654,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b6c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b73e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b7a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b802,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b864,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b8da,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b954,
    (u32)&sBlob_6b2fac_72eee0 + 0x3b9cc,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ba3a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3baa8,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bb1e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bb98,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bbf6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bc6e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bce6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bd5e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bd9a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bdd6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3be4e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bec6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bf3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3bfb4,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c026,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c098,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c10a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c180,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c1de,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c24a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c2ca,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c34a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c3b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c422,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c452,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c4ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c53c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c5aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c618,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c686,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c6f6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c764,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c7d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c806,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c83a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c8b4,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c8f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c964,
    (u32)&sBlob_6b2fac_72eee0 + 0x3c9de,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ca58,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cad2,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cb4c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cba8,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cc04,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cc60,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ccbc,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cd34,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cd7a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cd96,
    (u32)&sBlob_6b2fac_72eee0 + 0x3cdb4,
    (u32)&sBlob_6b2fac_72eee0 + 0x3d1e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x3d222,
    (u32)&sBlob_6b2fac_72eee0 + 0x3d2c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x3d334,
    (u32)&sBlob_6b2fac_72eee0 + 0x3d35a,
    (u32)&sBlob_6b2fac_72eee0 + 0x3d380,
    (u32)&sBlob_6b2fac_72eee0 + 0x3dea6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3dede,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e1c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e1fe,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e23e,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e276,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e29c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e2c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e672,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e6aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e6d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x3e6f6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ea8c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3eacc,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ef26,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ef98,
    (u32)&sBlob_6b2fac_72eee0 + 0x3f0d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x3f194,
    (u32)&sBlob_6b2fac_72eee0 + 0x3f4c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x3f52c,
    (u32)&sBlob_6b2fac_72eee0 + 0x3ff90,
    (u32)&sBlob_6b2fac_72eee0 + 0x40090,
    (u32)&sBlob_6b2fac_72eee0 + 0x401a4,
    (u32)&sBlob_6b2fac_72eee0 + 0x40222,
    (u32)&sBlob_6b2fac_72eee0 + 0x40248,
    (u32)&sBlob_6b2fac_72eee0 + 0x4026e,
    (u32)&sBlob_6b2fac_72eee0 + 0x405a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x40626,
    (u32)&sBlob_6b2fac_72eee0 + 0x40e4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x40ed2,
    (u32)&sBlob_6b2fac_72eee0 + 0x40ef8,
    (u32)&sBlob_6b2fac_72eee0 + 0x40f1e,
    (u32)&sBlob_6b2fac_72eee0 + 0x40f2a,
    (u32)&sBlob_6b2fac_72eee0 + 0x40f38,
    (u32)&sBlob_6b2fac_72eee0 + 0x41548,
    (u32)&sBlob_6b2fac_72eee0 + 0x4158e,
    (u32)&sBlob_6b2fac_72eee0 + 0x41c92,
    (u32)&sBlob_6b2fac_72eee0 + 0x41d14,
    (u32)&sBlob_6b2fac_72eee0 + 0x41e0e,
    (u32)&sBlob_6b2fac_72eee0 + 0x41e8e,
    (u32)&sBlob_6b2fac_72eee0 + 0x41eb4,
    (u32)&sBlob_6b2fac_72eee0 + 0x41eda,
    (u32)&sBlob_6b2fac_72eee0 + 0x426de,
    (u32)&sBlob_6b2fac_72eee0 + 0x4271c,
    (u32)&sBlob_6b2fac_72eee0 + 0x42810,
    (u32)&sBlob_6b2fac_72eee0 + 0x42822,
    (u32)&sBlob_6b2fac_72eee0 + 0x42860,
    (u32)&sBlob_6b2fac_72eee0 + 0x4289e,
    (u32)&sBlob_6b2fac_72eee0 + 0x42dd2,
    (u32)&sBlob_6b2fac_72eee0 + 0x42e4c,
    (u32)&sBlob_6b2fac_72eee0 + 0x42e72,
    (u32)&sBlob_6b2fac_72eee0 + 0x42e98,
    (u32)&sBlob_6b2fac_72eee0 + 0x436f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x43774,
    (u32)&sBlob_6b2fac_72eee0 + 0x43a10,
    (u32)&sBlob_6b2fac_72eee0 + 0x43a84,
    (u32)&sBlob_6b2fac_72eee0 + 0x43b82,
    (u32)&sBlob_6b2fac_72eee0 + 0x43bfe,
    (u32)&sBlob_6b2fac_72eee0 + 0x43c24,
    (u32)&sBlob_6b2fac_72eee0 + 0x43c4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x440e6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4415c,
    (u32)&sBlob_6b2fac_72eee0 + 0x44182,
    (u32)&sBlob_6b2fac_72eee0 + 0x441a6,
    (u32)&sBlob_6b2fac_72eee0 + 0x44916,
    (u32)&sBlob_6b2fac_72eee0 + 0x44982,
    (u32)&sBlob_6b2fac_72eee0 + 0x449a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x449ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x44f3c,
    (u32)&sBlob_6b2fac_72eee0 + 0x44fb4,
    (u32)&sBlob_6b2fac_72eee0 + 0x45096,
    (u32)&sBlob_6b2fac_72eee0 + 0x4510e,
    (u32)&sBlob_6b2fac_72eee0 + 0x45134,
    (u32)&sBlob_6b2fac_72eee0 + 0x4515a,
    (u32)&sBlob_6b2fac_72eee0 + 0x451d6,
    (u32)&sBlob_6b2fac_72eee0 + 0x45212,
    (u32)&sBlob_6b2fac_72eee0 + 0x457a2,
    (u32)&sBlob_6b2fac_72eee0 + 0x457e8,
    (u32)&sBlob_6b2fac_72eee0 + 0x4580e,
    (u32)&sBlob_6b2fac_72eee0 + 0x45834,
    (u32)&sBlob_6b2fac_72eee0 + 0x45b00,
    (u32)&sBlob_6b2fac_72eee0 + 0x45b62,
    (u32)&sBlob_6b2fac_72eee0 + 0x45f2c,
    (u32)&sBlob_6b2fac_72eee0 + 0x45f92,
    (u32)&sBlob_6b2fac_72eee0 + 0x46380,
    (u32)&sBlob_6b2fac_72eee0 + 0x463c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x46400,
    (u32)&sBlob_6b2fac_72eee0 + 0x46480,
    (u32)&sBlob_6b2fac_72eee0 + 0x46786,
    (u32)&sBlob_6b2fac_72eee0 + 0x46830,
    (u32)&sBlob_6b2fac_72eee0 + 0x46c62,
    (u32)&sBlob_6b2fac_72eee0 + 0x46ce4,
    (u32)&sBlob_6b2fac_72eee0 + 0x46ef4,
    (u32)&sBlob_6b2fac_72eee0 + 0x46f70,
    (u32)&sBlob_6b2fac_72eee0 + 0x47926,
    (u32)&sBlob_6b2fac_72eee0 + 0x4793c,
    (u32)&sBlob_6b2fac_72eee0 + 0x483ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x483fe,
    (u32)&sBlob_6b2fac_72eee0 + 0x490b0,
    (u32)&sBlob_6b2fac_72eee0 + 0x49124,
    (u32)&sBlob_6b2fac_72eee0 + 0x49204,
    (u32)&sBlob_6b2fac_72eee0 + 0x49244,
    (u32)&sBlob_6b2fac_72eee0 + 0x4926a,
    (u32)&sBlob_6b2fac_72eee0 + 0x49290,
    (u32)&sBlob_6b2fac_72eee0 + 0x4933a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4935e,
    (u32)&sBlob_6b2fac_72eee0 + 0x49468,
    (u32)&sBlob_6b2fac_72eee0 + 0x49474,
    (u32)&sBlob_6b2fac_72eee0 + 0x494ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x4952e,
    (u32)&sBlob_6b2fac_72eee0 + 0x4959e,
    (u32)&sBlob_6b2fac_72eee0 + 0x4960c,
    (u32)&sBlob_6b2fac_72eee0 + 0x49676,
    (u32)&sBlob_6b2fac_72eee0 + 0x496b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x496f6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4973a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4977c,
    (u32)&sBlob_6b2fac_72eee0 + 0x497ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x49856,
    (u32)&sBlob_6b2fac_72eee0 + 0x498c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x49932,
    (u32)&sBlob_6b2fac_72eee0 + 0x499a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x49a08,
    (u32)&sBlob_6b2fac_72eee0 + 0x49a7a,
    (u32)&sBlob_6b2fac_72eee0 + 0x49aec,
    (u32)&sBlob_6b2fac_72eee0 + 0x49b64,
    (u32)&sBlob_6b2fac_72eee0 + 0x49bde,
    (u32)&sBlob_6b2fac_72eee0 + 0x49c54,
    (u32)&sBlob_6b2fac_72eee0 + 0x49cca,
    (u32)&sBlob_6b2fac_72eee0 + 0x49d40,
    (u32)&sBlob_6b2fac_72eee0 + 0x49da2,
    (u32)&sBlob_6b2fac_72eee0 + 0x49e02,
    (u32)&sBlob_6b2fac_72eee0 + 0x49e64,
    (u32)&sBlob_6b2fac_72eee0 + 0x49ede,
    (u32)&sBlob_6b2fac_72eee0 + 0x49f50,
    (u32)&sBlob_6b2fac_72eee0 + 0x49fca,
    (u32)&sBlob_6b2fac_72eee0 + 0x49fec,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a052,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a070,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a0d6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a14a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a1c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a246,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a2bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a332,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a3a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a418,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a460,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a4d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a546,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a5ba,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a62e,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a6a2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a716,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a78a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a7fe,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a872,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a8e6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a95c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4a9c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x4aa34,
    (u32)&sBlob_6b2fac_72eee0 + 0x4aaaa,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ab26,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ab9c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ac12,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ac88,
    (u32)&sBlob_6b2fac_72eee0 + 0x4acfe,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ad78,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ade0,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ae5c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4aece,
    (u32)&sBlob_6b2fac_72eee0 + 0x4af48,
    (u32)&sBlob_6b2fac_72eee0 + 0x4afba,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b02c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b0a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b114,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b188,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b1c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b204,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b278,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b2ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b354,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b3ca,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b430,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b496,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b4fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b56a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b5e6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b658,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b6ca,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b73c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b7b8,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b834,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b86e,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b8e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b958,
    (u32)&sBlob_6b2fac_72eee0 + 0x4b9d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x4ba4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bac2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bb32,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bbac,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bc26,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bc5e,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bc96,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bd0c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bd4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bdba,
    (u32)&sBlob_6b2fac_72eee0 + 0x4be36,
    (u32)&sBlob_6b2fac_72eee0 + 0x4beb2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bf2e,
    (u32)&sBlob_6b2fac_72eee0 + 0x4bfaa,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c00c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c06e,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c0d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c132,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c19a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c1c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c1e2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c200,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c61c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c656,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c710,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c754,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c780,
    (u32)&sBlob_6b2fac_72eee0 + 0x4c7ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x4d2b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4d2ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x4d55a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4d59c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4d5d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x4d608,
    (u32)&sBlob_6b2fac_72eee0 + 0x4d634,
    (u32)&sBlob_6b2fac_72eee0 + 0x4d660,
    (u32)&sBlob_6b2fac_72eee0 + 0x4da02,
    (u32)&sBlob_6b2fac_72eee0 + 0x4da38,
    (u32)&sBlob_6b2fac_72eee0 + 0x4da64,
    (u32)&sBlob_6b2fac_72eee0 + 0x4da90,
    (u32)&sBlob_6b2fac_72eee0 + 0x4de62,
    (u32)&sBlob_6b2fac_72eee0 + 0x4dea6,
    (u32)&sBlob_6b2fac_72eee0 + 0x4e260,
    (u32)&sBlob_6b2fac_72eee0 + 0x4e2ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x4e412,
    (u32)&sBlob_6b2fac_72eee0 + 0x4e4d4,
    (u32)&sBlob_6b2fac_72eee0 + 0x4e7de,
    (u32)&sBlob_6b2fac_72eee0 + 0x4e82a,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f236,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f326,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f442,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f4b4,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f4e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f50c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f82c,
    (u32)&sBlob_6b2fac_72eee0 + 0x4f89e,
    (u32)&sBlob_6b2fac_72eee0 + 0x50094,
    (u32)&sBlob_6b2fac_72eee0 + 0x50116,
    (u32)&sBlob_6b2fac_72eee0 + 0x50142,
    (u32)&sBlob_6b2fac_72eee0 + 0x5016e,
    (u32)&sBlob_6b2fac_72eee0 + 0x50180,
    (u32)&sBlob_6b2fac_72eee0 + 0x50192,
    (u32)&sBlob_6b2fac_72eee0 + 0x507dc,
    (u32)&sBlob_6b2fac_72eee0 + 0x50820,
    (u32)&sBlob_6b2fac_72eee0 + 0x50f64,
    (u32)&sBlob_6b2fac_72eee0 + 0x50fde,
    (u32)&sBlob_6b2fac_72eee0 + 0x510fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x51178,
    (u32)&sBlob_6b2fac_72eee0 + 0x511a4,
    (u32)&sBlob_6b2fac_72eee0 + 0x511d0,
    (u32)&sBlob_6b2fac_72eee0 + 0x51a70,
    (u32)&sBlob_6b2fac_72eee0 + 0x51aa8,
    (u32)&sBlob_6b2fac_72eee0 + 0x51b6a,
    (u32)&sBlob_6b2fac_72eee0 + 0x51b7c,
    (u32)&sBlob_6b2fac_72eee0 + 0x51bb4,
    (u32)&sBlob_6b2fac_72eee0 + 0x51bec,
    (u32)&sBlob_6b2fac_72eee0 + 0x520ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x5213a,
    (u32)&sBlob_6b2fac_72eee0 + 0x52166,
    (u32)&sBlob_6b2fac_72eee0 + 0x52192,
    (u32)&sBlob_6b2fac_72eee0 + 0x52968,
    (u32)&sBlob_6b2fac_72eee0 + 0x529e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x52c3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x52cac,
    (u32)&sBlob_6b2fac_72eee0 + 0x52dee,
    (u32)&sBlob_6b2fac_72eee0 + 0x52e5c,
    (u32)&sBlob_6b2fac_72eee0 + 0x52e88,
    (u32)&sBlob_6b2fac_72eee0 + 0x52eb4,
    (u32)&sBlob_6b2fac_72eee0 + 0x53378,
    (u32)&sBlob_6b2fac_72eee0 + 0x533da,
    (u32)&sBlob_6b2fac_72eee0 + 0x53406,
    (u32)&sBlob_6b2fac_72eee0 + 0x53432,
    (u32)&sBlob_6b2fac_72eee0 + 0x53bcc,
    (u32)&sBlob_6b2fac_72eee0 + 0x53c20,
    (u32)&sBlob_6b2fac_72eee0 + 0x53c4c,
    (u32)&sBlob_6b2fac_72eee0 + 0x53c78,
    (u32)&sBlob_6b2fac_72eee0 + 0x5412e,
    (u32)&sBlob_6b2fac_72eee0 + 0x54198,
    (u32)&sBlob_6b2fac_72eee0 + 0x5426a,
    (u32)&sBlob_6b2fac_72eee0 + 0x542d4,
    (u32)&sBlob_6b2fac_72eee0 + 0x54300,
    (u32)&sBlob_6b2fac_72eee0 + 0x5432c,
    (u32)&sBlob_6b2fac_72eee0 + 0x543a2,
    (u32)&sBlob_6b2fac_72eee0 + 0x543d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x54916,
    (u32)&sBlob_6b2fac_72eee0 + 0x5496a,
    (u32)&sBlob_6b2fac_72eee0 + 0x54996,
    (u32)&sBlob_6b2fac_72eee0 + 0x549c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x54c76,
    (u32)&sBlob_6b2fac_72eee0 + 0x54cd8,
    (u32)&sBlob_6b2fac_72eee0 + 0x550a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x5510a,
    (u32)&sBlob_6b2fac_72eee0 + 0x554aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x554e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x55522,
    (u32)&sBlob_6b2fac_72eee0 + 0x5558e,
    (u32)&sBlob_6b2fac_72eee0 + 0x55882,
    (u32)&sBlob_6b2fac_72eee0 + 0x55920,
    (u32)&sBlob_6b2fac_72eee0 + 0x55d84,
    (u32)&sBlob_6b2fac_72eee0 + 0x55df2,
    (u32)&sBlob_6b2fac_72eee0 + 0x55fb2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5601c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5694a,
    (u32)&sBlob_6b2fac_72eee0 + 0x56958,
    (u32)&sBlob_6b2fac_72eee0 + 0x573da,
    (u32)&sBlob_6b2fac_72eee0 + 0x573ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x580bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x5811c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5825c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5829a,
    (u32)&sBlob_6b2fac_72eee0 + 0x582c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x582f2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5838e,
    (u32)&sBlob_6b2fac_72eee0 + 0x583ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x584b8,
    (u32)&sBlob_6b2fac_72eee0 + 0x584c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x58530,
    (u32)&sBlob_6b2fac_72eee0 + 0x58570,
    (u32)&sBlob_6b2fac_72eee0 + 0x585da,
    (u32)&sBlob_6b2fac_72eee0 + 0x5863c,
    (u32)&sBlob_6b2fac_72eee0 + 0x58696,
    (u32)&sBlob_6b2fac_72eee0 + 0x586c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x586f2,
    (u32)&sBlob_6b2fac_72eee0 + 0x58732,
    (u32)&sBlob_6b2fac_72eee0 + 0x58774,
    (u32)&sBlob_6b2fac_72eee0 + 0x587ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x58858,
    (u32)&sBlob_6b2fac_72eee0 + 0x588a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x588f8,
    (u32)&sBlob_6b2fac_72eee0 + 0x58948,
    (u32)&sBlob_6b2fac_72eee0 + 0x589ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x58a24,
    (u32)&sBlob_6b2fac_72eee0 + 0x58a88,
    (u32)&sBlob_6b2fac_72eee0 + 0x58b04,
    (u32)&sBlob_6b2fac_72eee0 + 0x58b72,
    (u32)&sBlob_6b2fac_72eee0 + 0x58bc8,
    (u32)&sBlob_6b2fac_72eee0 + 0x58c1e,
    (u32)&sBlob_6b2fac_72eee0 + 0x58c74,
    (u32)&sBlob_6b2fac_72eee0 + 0x58cde,
    (u32)&sBlob_6b2fac_72eee0 + 0x58d48,
    (u32)&sBlob_6b2fac_72eee0 + 0x58db2,
    (u32)&sBlob_6b2fac_72eee0 + 0x58e16,
    (u32)&sBlob_6b2fac_72eee0 + 0x58e80,
    (u32)&sBlob_6b2fac_72eee0 + 0x58ee0,
    (u32)&sBlob_6b2fac_72eee0 + 0x58f02,
    (u32)&sBlob_6b2fac_72eee0 + 0x58f5e,
    (u32)&sBlob_6b2fac_72eee0 + 0x58f82,
    (u32)&sBlob_6b2fac_72eee0 + 0x58fde,
    (u32)&sBlob_6b2fac_72eee0 + 0x59048,
    (u32)&sBlob_6b2fac_72eee0 + 0x590c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x59130,
    (u32)&sBlob_6b2fac_72eee0 + 0x5919e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5920c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5927a,
    (u32)&sBlob_6b2fac_72eee0 + 0x592f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x5933c,
    (u32)&sBlob_6b2fac_72eee0 + 0x593ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x59410,
    (u32)&sBlob_6b2fac_72eee0 + 0x59474,
    (u32)&sBlob_6b2fac_72eee0 + 0x594d8,
    (u32)&sBlob_6b2fac_72eee0 + 0x5953c,
    (u32)&sBlob_6b2fac_72eee0 + 0x595a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x59604,
    (u32)&sBlob_6b2fac_72eee0 + 0x59666,
    (u32)&sBlob_6b2fac_72eee0 + 0x596c8,
    (u32)&sBlob_6b2fac_72eee0 + 0x5972a,
    (u32)&sBlob_6b2fac_72eee0 + 0x5978a,
    (u32)&sBlob_6b2fac_72eee0 + 0x597f2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5985a,
    (u32)&sBlob_6b2fac_72eee0 + 0x598c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x59932,
    (u32)&sBlob_6b2fac_72eee0 + 0x599a2,
    (u32)&sBlob_6b2fac_72eee0 + 0x59a12,
    (u32)&sBlob_6b2fac_72eee0 + 0x59a82,
    (u32)&sBlob_6b2fac_72eee0 + 0x59afa,
    (u32)&sBlob_6b2fac_72eee0 + 0x59b76,
    (u32)&sBlob_6b2fac_72eee0 + 0x59bf0,
    (u32)&sBlob_6b2fac_72eee0 + 0x59c68,
    (u32)&sBlob_6b2fac_72eee0 + 0x59ce0,
    (u32)&sBlob_6b2fac_72eee0 + 0x59d56,
    (u32)&sBlob_6b2fac_72eee0 + 0x59db6,
    (u32)&sBlob_6b2fac_72eee0 + 0x59e30,
    (u32)&sBlob_6b2fac_72eee0 + 0x59ea2,
    (u32)&sBlob_6b2fac_72eee0 + 0x59f14,
    (u32)&sBlob_6b2fac_72eee0 + 0x59f86,
    (u32)&sBlob_6b2fac_72eee0 + 0x59fc6,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a006,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a072,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a0de,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a140,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a1b4,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a22a,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a2a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a316,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a390,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a3f2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a452,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a4cc,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a546,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a5c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a63a,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a66e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a6ea,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a756,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a7c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a82e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a89a,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a8fa,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a964,
    (u32)&sBlob_6b2fac_72eee0 + 0x5a9ce,
    (u32)&sBlob_6b2fac_72eee0 + 0x5aa06,
    (u32)&sBlob_6b2fac_72eee0 + 0x5aa3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5aab2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5aaec,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ab46,
    (u32)&sBlob_6b2fac_72eee0 + 0x5abbc,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ac32,
    (u32)&sBlob_6b2fac_72eee0 + 0x5aca8,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ad1e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ad80,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ade2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ae44,
    (u32)&sBlob_6b2fac_72eee0 + 0x5aea6,
    (u32)&sBlob_6b2fac_72eee0 + 0x5af22,
    (u32)&sBlob_6b2fac_72eee0 + 0x5af50,
    (u32)&sBlob_6b2fac_72eee0 + 0x5af6c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5af88,
    (u32)&sBlob_6b2fac_72eee0 + 0x5b394,
    (u32)&sBlob_6b2fac_72eee0 + 0x5b3e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x5b48e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5b4d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x5b4fa,
    (u32)&sBlob_6b2fac_72eee0 + 0x5b522,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c18e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c1ba,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c482,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c4c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c508,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c564,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c58c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5c5b4,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ca02,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ca32,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ca5a,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ca82,
    (u32)&sBlob_6b2fac_72eee0 + 0x5cea4,
    (u32)&sBlob_6b2fac_72eee0 + 0x5cee4,
    (u32)&sBlob_6b2fac_72eee0 + 0x5d316,
    (u32)&sBlob_6b2fac_72eee0 + 0x5d37c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5d508,
    (u32)&sBlob_6b2fac_72eee0 + 0x5d580,
    (u32)&sBlob_6b2fac_72eee0 + 0x5d936,
    (u32)&sBlob_6b2fac_72eee0 + 0x5d9a0,
    (u32)&sBlob_6b2fac_72eee0 + 0x5e59c,
    (u32)&sBlob_6b2fac_72eee0 + 0x5e6be,
    (u32)&sBlob_6b2fac_72eee0 + 0x5e7e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x5e85e,
    (u32)&sBlob_6b2fac_72eee0 + 0x5e886,
    (u32)&sBlob_6b2fac_72eee0 + 0x5e8ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ec16,
    (u32)&sBlob_6b2fac_72eee0 + 0x5ec96,
    (u32)&sBlob_6b2fac_72eee0 + 0x5f660,
    (u32)&sBlob_6b2fac_72eee0 + 0x5f6fa,
    (u32)&sBlob_6b2fac_72eee0 + 0x5f722,
    (u32)&sBlob_6b2fac_72eee0 + 0x5f74a,
    (u32)&sBlob_6b2fac_72eee0 + 0x5f75a,
    (u32)&sBlob_6b2fac_72eee0 + 0x5f76a,
    (u32)&sBlob_6b2fac_72eee0 + 0x5fe9a,
    (u32)&sBlob_6b2fac_72eee0 + 0x5feda,
    (u32)&sBlob_6b2fac_72eee0 + 0x606c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x6076c,
    (u32)&sBlob_6b2fac_72eee0 + 0x60830,
    (u32)&sBlob_6b2fac_72eee0 + 0x6088e,
    (u32)&sBlob_6b2fac_72eee0 + 0x608b6,
    (u32)&sBlob_6b2fac_72eee0 + 0x608de,
    (u32)&sBlob_6b2fac_72eee0 + 0x61208,
    (u32)&sBlob_6b2fac_72eee0 + 0x61248,
    (u32)&sBlob_6b2fac_72eee0 + 0x61300,
    (u32)&sBlob_6b2fac_72eee0 + 0x61326,
    (u32)&sBlob_6b2fac_72eee0 + 0x6135a,
    (u32)&sBlob_6b2fac_72eee0 + 0x6138e,
    (u32)&sBlob_6b2fac_72eee0 + 0x618ae,
    (u32)&sBlob_6b2fac_72eee0 + 0x61924,
    (u32)&sBlob_6b2fac_72eee0 + 0x6194c,
    (u32)&sBlob_6b2fac_72eee0 + 0x61974,
    (u32)&sBlob_6b2fac_72eee0 + 0x62228,
    (u32)&sBlob_6b2fac_72eee0 + 0x622ac,
    (u32)&sBlob_6b2fac_72eee0 + 0x625ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x6266a,
    (u32)&sBlob_6b2fac_72eee0 + 0x62786,
    (u32)&sBlob_6b2fac_72eee0 + 0x62804,
    (u32)&sBlob_6b2fac_72eee0 + 0x6282c,
    (u32)&sBlob_6b2fac_72eee0 + 0x62854,
    (u32)&sBlob_6b2fac_72eee0 + 0x62dde,
    (u32)&sBlob_6b2fac_72eee0 + 0x62e42,
    (u32)&sBlob_6b2fac_72eee0 + 0x62e6a,
    (u32)&sBlob_6b2fac_72eee0 + 0x62e92,
    (u32)&sBlob_6b2fac_72eee0 + 0x636dc,
    (u32)&sBlob_6b2fac_72eee0 + 0x63746,
    (u32)&sBlob_6b2fac_72eee0 + 0x6376e,
    (u32)&sBlob_6b2fac_72eee0 + 0x63796,
    (u32)&sBlob_6b2fac_72eee0 + 0x63d3e,
    (u32)&sBlob_6b2fac_72eee0 + 0x63dca,
    (u32)&sBlob_6b2fac_72eee0 + 0x63e78,
    (u32)&sBlob_6b2fac_72eee0 + 0x63f04,
    (u32)&sBlob_6b2fac_72eee0 + 0x63f2c,
    (u32)&sBlob_6b2fac_72eee0 + 0x63f54,
    (u32)&sBlob_6b2fac_72eee0 + 0x63fc4,
    (u32)&sBlob_6b2fac_72eee0 + 0x63fe8,
    (u32)&sBlob_6b2fac_72eee0 + 0x64666,
    (u32)&sBlob_6b2fac_72eee0 + 0x646c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x646ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x64716,
    (u32)&sBlob_6b2fac_72eee0 + 0x64a88,
    (u32)&sBlob_6b2fac_72eee0 + 0x64aea,
    (u32)&sBlob_6b2fac_72eee0 + 0x64f22,
    (u32)&sBlob_6b2fac_72eee0 + 0x64f82,
    (u32)&sBlob_6b2fac_72eee0 + 0x6537a,
    (u32)&sBlob_6b2fac_72eee0 + 0x653a8,
    (u32)&sBlob_6b2fac_72eee0 + 0x653e8,
    (u32)&sBlob_6b2fac_72eee0 + 0x6546e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6575e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6581a,
    (u32)&sBlob_6b2fac_72eee0 + 0x65ce2,
    (u32)&sBlob_6b2fac_72eee0 + 0x65d46,
    (u32)&sBlob_6b2fac_72eee0 + 0x65f76,
    (u32)&sBlob_6b2fac_72eee0 + 0x65fda,
    (u32)&sBlob_6b2fac_72eee0 + 0x669be,
    (u32)&sBlob_6b2fac_72eee0 + 0x669d6,
    (u32)&sBlob_6b2fac_72eee0 + 0x6746a,
    (u32)&sBlob_6b2fac_72eee0 + 0x6747c,
    (u32)&sBlob_6b2fac_72eee0 + 0x681cc,
    (u32)&sBlob_6b2fac_72eee0 + 0x6822e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6835c,
    (u32)&sBlob_6b2fac_72eee0 + 0x6839c,
    (u32)&sBlob_6b2fac_72eee0 + 0x683c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x683ec,
    (u32)&sBlob_6b2fac_72eee0 + 0x6847a,
    (u32)&sBlob_6b2fac_72eee0 + 0x684a4,
    (u32)&sBlob_6b2fac_72eee0 + 0x68584,
    (u32)&sBlob_6b2fac_72eee0 + 0x68590,
    (u32)&sBlob_6b2fac_72eee0 + 0x68608,
    (u32)&sBlob_6b2fac_72eee0 + 0x68650,
    (u32)&sBlob_6b2fac_72eee0 + 0x686ba,
    (u32)&sBlob_6b2fac_72eee0 + 0x68730,
    (u32)&sBlob_6b2fac_72eee0 + 0x6879a,
    (u32)&sBlob_6b2fac_72eee0 + 0x687e0,
    (u32)&sBlob_6b2fac_72eee0 + 0x68826,
    (u32)&sBlob_6b2fac_72eee0 + 0x68872,
    (u32)&sBlob_6b2fac_72eee0 + 0x688c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x6892e,
    (u32)&sBlob_6b2fac_72eee0 + 0x689a6,
    (u32)&sBlob_6b2fac_72eee0 + 0x68a18,
    (u32)&sBlob_6b2fac_72eee0 + 0x68a8a,
    (u32)&sBlob_6b2fac_72eee0 + 0x68afc,
    (u32)&sBlob_6b2fac_72eee0 + 0x68b74,
    (u32)&sBlob_6b2fac_72eee0 + 0x68be2,
    (u32)&sBlob_6b2fac_72eee0 + 0x68c56,
    (u32)&sBlob_6b2fac_72eee0 + 0x68cd0,
    (u32)&sBlob_6b2fac_72eee0 + 0x68d4a,
    (u32)&sBlob_6b2fac_72eee0 + 0x68dc0,
    (u32)&sBlob_6b2fac_72eee0 + 0x68e36,
    (u32)&sBlob_6b2fac_72eee0 + 0x68eac,
    (u32)&sBlob_6b2fac_72eee0 + 0x68f1e,
    (u32)&sBlob_6b2fac_72eee0 + 0x68f90,
    (u32)&sBlob_6b2fac_72eee0 + 0x69002,
    (u32)&sBlob_6b2fac_72eee0 + 0x69064,
    (u32)&sBlob_6b2fac_72eee0 + 0x690d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x69130,
    (u32)&sBlob_6b2fac_72eee0 + 0x69152,
    (u32)&sBlob_6b2fac_72eee0 + 0x691c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x691f0,
    (u32)&sBlob_6b2fac_72eee0 + 0x69262,
    (u32)&sBlob_6b2fac_72eee0 + 0x692d2,
    (u32)&sBlob_6b2fac_72eee0 + 0x69346,
    (u32)&sBlob_6b2fac_72eee0 + 0x693bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x69422,
    (u32)&sBlob_6b2fac_72eee0 + 0x69488,
    (u32)&sBlob_6b2fac_72eee0 + 0x694ee,
    (u32)&sBlob_6b2fac_72eee0 + 0x6955a,
    (u32)&sBlob_6b2fac_72eee0 + 0x695c2,
    (u32)&sBlob_6b2fac_72eee0 + 0x69628,
    (u32)&sBlob_6b2fac_72eee0 + 0x6968e,
    (u32)&sBlob_6b2fac_72eee0 + 0x696f4,
    (u32)&sBlob_6b2fac_72eee0 + 0x6975a,
    (u32)&sBlob_6b2fac_72eee0 + 0x697c0,
    (u32)&sBlob_6b2fac_72eee0 + 0x69826,
    (u32)&sBlob_6b2fac_72eee0 + 0x6988c,
    (u32)&sBlob_6b2fac_72eee0 + 0x698f2,
    (u32)&sBlob_6b2fac_72eee0 + 0x69958,
    (u32)&sBlob_6b2fac_72eee0 + 0x699be,
    (u32)&sBlob_6b2fac_72eee0 + 0x69a36,
    (u32)&sBlob_6b2fac_72eee0 + 0x69aa2,
    (u32)&sBlob_6b2fac_72eee0 + 0x69b0e,
    (u32)&sBlob_6b2fac_72eee0 + 0x69b78,
    (u32)&sBlob_6b2fac_72eee0 + 0x69bf4,
    (u32)&sBlob_6b2fac_72eee0 + 0x69c60,
    (u32)&sBlob_6b2fac_72eee0 + 0x69ccc,
    (u32)&sBlob_6b2fac_72eee0 + 0x69d38,
    (u32)&sBlob_6b2fac_72eee0 + 0x69dac,
    (u32)&sBlob_6b2fac_72eee0 + 0x69e14,
    (u32)&sBlob_6b2fac_72eee0 + 0x69e84,
    (u32)&sBlob_6b2fac_72eee0 + 0x69ef4,
    (u32)&sBlob_6b2fac_72eee0 + 0x69f6c,
    (u32)&sBlob_6b2fac_72eee0 + 0x69fde,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a04e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a0aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a11c,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a18e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a200,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a228,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a250,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a2c4,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a338,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a3b4,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a422,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a48a,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a4fe,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a556,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a5ca,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a648,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a6c6,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a738,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a7aa,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a80c,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a86e,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a8a4,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a912,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a988,
    (u32)&sBlob_6b2fac_72eee0 + 0x6a9fe,
    (u32)&sBlob_6b2fac_72eee0 + 0x6aa74,
    (u32)&sBlob_6b2fac_72eee0 + 0x6aaea,
    (u32)&sBlob_6b2fac_72eee0 + 0x6ab56,
    (u32)&sBlob_6b2fac_72eee0 + 0x6abc8,
    (u32)&sBlob_6b2fac_72eee0 + 0x6ac3a,
    (u32)&sBlob_6b2fac_72eee0 + 0x6ac86,
    (u32)&sBlob_6b2fac_72eee0 + 0x6acd2,
    (u32)&sBlob_6b2fac_72eee0 + 0x6ad48,
    (u32)&sBlob_6b2fac_72eee0 + 0x6ad80,
    (u32)&sBlob_6b2fac_72eee0 + 0x6adf8,
    (u32)&sBlob_6b2fac_72eee0 + 0x6ae74,
    (u32)&sBlob_6b2fac_72eee0 + 0x6aef0,
    (u32)&sBlob_6b2fac_72eee0 + 0x6af6c,
    (u32)&sBlob_6b2fac_72eee0 + 0x6afe8,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b052,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b0bc,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b126,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b190,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b1fc,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b226,
    (u32)&sBlob_6b2fac_72eee0 + 0x6b242
};

static u16* sMonologueTextPointersJapanese[19] = {
	(u16*)sAddr_71e20c,
	(u16*)sAddr_71e4e4,
	(u16*)sAddr_71e67e,
	(u16*)sAddr_71e814,
	(u16*)sAddr_71e9b6,
	(u16*)sAddr_71eb34,
	(u16*)sAddr_71ecac,
	(u16*)sAddr_71efc2,
	(u16*)sAddr_71f498,
	(u16*)sAddr_71f52c,
	(u16*)sAddr_71f56c,
	(u16*)sAddr_71f5fc,
	(u16*)sAddr_71f656,
	(u16*)sAddr_71f71a,
	(u16*)sAddr_71f7cc,
	(u16*)sAddr_71f896,
	(u16*)sAddr_71f98a,
	(u16*)sAddr_71fa32,
	(u16*)sAddr_71fa92
};

static u16* sMonologueTextPointersEnglish[19] = {
	(u16*)sAddr_71fad4,
	(u16*)sAddr_7200ee,
	(u16*)sAddr_720310,
	(u16*)sAddr_720528,
	(u16*)sAddr_720748,
	(u16*)sAddr_72094a,
	(u16*)sAddr_720b4a,
	(u16*)sAddr_721116,
	(u16*)sAddr_72192e,
	(u16*)sAddr_721a12,
	(u16*)sAddr_721ab6,
	(u16*)sAddr_721c28,
	(u16*)sAddr_721d12,
	(u16*)sAddr_721f20,
	(u16*)sAddr_722068,
	(u16*)sAddr_722238,
	(u16*)sAddr_722438,
	(u16*)sAddr_722550,
	(u16*)sAddr_7225f8
};

static u16* sMonologueTextPointersGerman[19] = {
	(u16*)sAddr_7226a0,
	(u16*)sAddr_723016,
	(u16*)sAddr_723324,
	(u16*)sAddr_723624,
	(u16*)sAddr_723958,
	(u16*)sAddr_723be2,
	(u16*)sAddr_723e44,
	(u16*)sAddr_72475e,
	(u16*)sAddr_7252c6,
	(u16*)sAddr_725412,
	(u16*)sAddr_7254ea,
	(u16*)sAddr_7256d8,
	(u16*)sAddr_72581e,
	(u16*)sAddr_725a60,
	(u16*)sAddr_725b94,
	(u16*)sAddr_725dac,
	(u16*)sAddr_72603c,
	(u16*)sAddr_7261c6,
	(u16*)sAddr_7262aa
};

static u16* sMonologueTextPointersFrench[19] = {
	(u16*)sAddr_72638c,
	(u16*)sAddr_726aa6,
	(u16*)sAddr_726cfe,
	(u16*)sAddr_726f04,
	(u16*)sAddr_727106,
	(u16*)sAddr_727314,
	(u16*)sAddr_727522,
	(u16*)sAddr_727b08,
	(u16*)sAddr_7282bc,
	(u16*)sAddr_7283a6,
	(u16*)sAddr_728466,
	(u16*)sAddr_728608,
	(u16*)sAddr_7286e8,
	(u16*)sAddr_7288ba,
	(u16*)sAddr_728a12,
	(u16*)sAddr_728bfc,
	(u16*)sAddr_728e4a,
	(u16*)sAddr_728f96,
	(u16*)sAddr_72904e
};

static u16* sMonologueTextPointersItalian[19] = {
	(u16*)sAddr_7290fc,
	(u16*)sAddr_729792,
	(u16*)sAddr_729a6e,
	(u16*)sAddr_729c84,
	(u16*)sAddr_729f24,
	(u16*)sAddr_72a124,
	(u16*)sAddr_72a330,
	(u16*)sAddr_72a8f6,
	(u16*)sAddr_72b142,
	(u16*)sAddr_72b254,
	(u16*)sAddr_72b2c8,
	(u16*)sAddr_72b446,
	(u16*)sAddr_72b56e,
	(u16*)sAddr_72b7a6,
	(u16*)sAddr_72b8e6,
	(u16*)sAddr_72bab4,
	(u16*)sAddr_72bcc2,
	(u16*)sAddr_72bdb8,
	(u16*)sAddr_72be4a
};

static u16* sMonologueTextPointersSpanish[19] = {
	(u16*)sAddr_72bef8,
	(u16*)sAddr_72c69c,
	(u16*)sAddr_72c8f2,
	(u16*)sAddr_72cb02,
	(u16*)sAddr_72cd92,
	(u16*)sAddr_72d002,
	(u16*)sAddr_72d212,
	(u16*)sAddr_72d81e,
	(u16*)sAddr_72e0b8,
	(u16*)sAddr_72e1b6,
	(u16*)sAddr_72e220,
	(u16*)sAddr_72e3d2,
	(u16*)sAddr_72e4ea,
	(u16*)sAddr_72e70a,
	(u16*)sAddr_72e848,
	(u16*)sAddr_72ea20,
	(u16*)sAddr_72ebf6,
	(u16*)sAddr_72ed50,
	(u16*)sAddr_72ee1c
};

const struct FrameData* sGameOverCursorOamPointers[3] = {
    (const struct FrameData*)sAddr_73c274,
    (const struct FrameData*)sAddr_73c29c,
    (const struct FrameData*)sAddr_73c29c
};

const u32* sGameOverTextGfxPointers[LANGUAGE_COUNT] = {
    (const u32*)sAddr_739d58,
    (const u32*)sAddr_739d58,
    (const u32*)sAddr_739d58,
    (const u32*)sAddr_73a430,
    (const u32*)sAddr_73ab28,
    (const u32*)sAddr_73b308,
    (const u32*)sAddr_73baac
};

const struct FrameData* sFileSelectFileOverlayOamPointers[5] = {
    (const struct FrameData*)sAddr_740ab8,
    (const struct FrameData*)sAddr_740ac8,
    (const struct FrameData*)sAddr_740ad8,
    (const struct FrameData*)sAddr_7408c0,
    (const struct FrameData*)sAddr_7408c0
};

const struct FrameData* sFileSelectCursorOamPointers[3][3] = {
    [0] = {
        (const struct FrameData*)sAddr_740800,
        (const struct FrameData*)sAddr_740800,
        (const struct FrameData*)sAddr_740820
    },
    [1] = {
        (const struct FrameData*)sAddr_740840,
        (const struct FrameData*)sAddr_740840,
        (const struct FrameData*)sAddr_740ae8
    },
    [2] = {
        (const struct FrameData*)sAddr_740b08,
        (const struct FrameData*)sAddr_740b28,
        (const struct FrameData*)sAddr_740b28
    }
};

const u16* sFileSelectTextPositions_Default[6] = {
    (const u16*)(&sBlob_73dbcc_7478a0),
    (const u16*)sAddr_73dbd8,
    (const u16*)sAddr_73dbde,
    (const u16*)sAddr_73dbde,
    (const u16*)sAddr_73dbde,
    (const u16*)sAddr_73dbe4
};

const u16* sFileSelectTextPositions_German[6] = {
    (const u16*)sAddr_73dbea,
    (const u16*)sAddr_73dbf6,
    (const u16*)sAddr_73dbfc,
    (const u16*)sAddr_73dbfc,
    (const u16*)sAddr_73dbfc,
    (const u16*)sAddr_73dc02
};

const u16* sFileSelectTextPositions_French[6] = {
    (const u16*)sAddr_73dc08,
    (const u16*)sAddr_73dbf6,
    (const u16*)sAddr_73dbfc,
    (const u16*)sAddr_73dbfc,
    (const u16*)sAddr_73dbfc,
    (const u16*)sAddr_73dc02
};

const u16* sFileSelectTextPositions_Spanish[6] = {
    (const u16*)sAddr_73dc14,
    (const u16*)sAddr_73dbf6,
    (const u16*)sAddr_73dbfc,
    (const u16*)sAddr_73dbfc,
    (const u16*)sAddr_73dbfc,
    (const u16*)sAddr_73dc02
};

const u16* const* sFileSelectTextPositionsPointers[LANGUAGE_COUNT] = {
    sFileSelectTextPositions_Default,
    sFileSelectTextPositions_Default,
    sFileSelectTextPositions_German,
    sFileSelectTextPositions_German,
    sFileSelectTextPositions_French,
    sFileSelectTextPositions_German,
    sFileSelectTextPositions_Spanish
};

const struct FrameData* sFileSelectAreaNameOamPointers[LANGUAGE_COUNT][7] = {
    [0] = {
        (const struct FrameData*)sAddr_740a38,
        (const struct FrameData*)sAddr_7409d8,
        (const struct FrameData*)sAddr_7409e8,
        (const struct FrameData*)sAddr_7409f8,
        (const struct FrameData*)sAddr_740a08,
        (const struct FrameData*)sAddr_740a18,
        (const struct FrameData*)sAddr_740a28
    },
    [1] = {
        (const struct FrameData*)sAddr_740a38,
        (const struct FrameData*)sAddr_7409d8,
        (const struct FrameData*)sAddr_7409e8,
        (const struct FrameData*)sAddr_7409f8,
        (const struct FrameData*)sAddr_740a08,
        (const struct FrameData*)sAddr_740a18,
        (const struct FrameData*)sAddr_740a28
    },
    [2] = {
        (const struct FrameData*)sAddr_740a38,
        (const struct FrameData*)sAddr_7409d8,
        (const struct FrameData*)sAddr_7409e8,
        (const struct FrameData*)sAddr_7409f8,
        (const struct FrameData*)sAddr_740a08,
        (const struct FrameData*)sAddr_740a18,
        (const struct FrameData*)sAddr_740a28
    },
    [3] = {
        (const struct FrameData*)sAddr_740c08,
        (const struct FrameData*)sAddr_740ba8,
        (const struct FrameData*)sAddr_740bb8,
        (const struct FrameData*)sAddr_740bc8,
        (const struct FrameData*)sAddr_740bd8,
        (const struct FrameData*)sAddr_740be8,
        (const struct FrameData*)sAddr_740bf8
    },
    [4] = {
        (const struct FrameData*)sAddr_740c78,
        (const struct FrameData*)sAddr_740c18,
        (const struct FrameData*)sAddr_740c28,
        (const struct FrameData*)sAddr_740c38,
        (const struct FrameData*)sAddr_740c48,
        (const struct FrameData*)sAddr_740c58,
        (const struct FrameData*)sAddr_740c68
    },
    [5] = {
        (const struct FrameData*)sAddr_740ce8,
        (const struct FrameData*)sAddr_740c88,
        (const struct FrameData*)sAddr_740c98,
        (const struct FrameData*)sAddr_740ca8,
        (const struct FrameData*)sAddr_740cb8,
        (const struct FrameData*)sAddr_740cc8,
        (const struct FrameData*)sAddr_740cd8
    },
    [6] = {
        (const struct FrameData*)sAddr_740cf8,
        (const struct FrameData*)sAddr_7409d8,
        (const struct FrameData*)sAddr_7409e8,
        (const struct FrameData*)sAddr_7409f8,
        (const struct FrameData*)sAddr_740a08,
        (const struct FrameData*)sAddr_740a18,
        (const struct FrameData*)sAddr_740a28
    }
};

const u16* sFileSelectTextPointers_Japanese[25] = {
    (const u16*)sAddr_740f08,
    (const u16*)sAddr_740f3a,
    (const u16*)sAddr_740f64,
    (const u16*)sAddr_740f82,
    (const u16*)sAddr_740fc4,
    (const u16*)sAddr_740ff4,
    (const u16*)sAddr_741036,
    (const u16*)sAddr_741078,
    (const u16*)sAddr_7410ba,
    (const u16*)sAddr_7410fc,
    (const u16*)sAddr_74113e,
    (const u16*)sAddr_741180,
    (const u16*)sAddr_741196,
    (const u16*)sAddr_74119e,
    (const u16*)sAddr_7411b2,
    (const u16*)sAddr_7411da,
    (const u16*)sAddr_7411fa,
    (const u16*)sAddr_74120e,
    (const u16*)sAddr_741258,
    (const u16*)sAddr_741280,
    (const u16*)sAddr_7412ce,
    (const u16*)sAddr_7412ec,
    (const u16*)sAddr_74130e,
    (const u16*)sAddr_741334,
    (const u16*)sAddr_74134c
};

const u16* sFileSelectTextPointers_English[25] = {
    (const u16*)sAddr_741364,
    (const u16*)sAddr_741398,
    (const u16*)sAddr_7413ce,
    (const u16*)sAddr_741410,
    (const u16*)sAddr_741466,
    (const u16*)sAddr_74149c,
    (const u16*)sAddr_7414f6,
    (const u16*)sAddr_741550,
    (const u16*)sAddr_7415aa,
    (const u16*)sAddr_74160e,
    (const u16*)sAddr_741672,
    (const u16*)sAddr_7416d6,
    (const u16*)sAddr_7416ec,
    (const u16*)sAddr_74170a,
    (const u16*)sAddr_74171e,
    (const u16*)sAddr_741746,
    (const u16*)sAddr_741766,
    (const u16*)sAddr_74177a,
    (const u16*)sAddr_7417c4,
    (const u16*)sAddr_7417ee,
    (const u16*)sAddr_741814,
    (const u16*)sAddr_741830,
    (const u16*)sAddr_74185a,
    (const u16*)sAddr_741884,
    (const u16*)sAddr_7418b4
};

const u16* sFileSelectTextPointers_German[25] = {
    (const u16*)sAddr_7418dc,
    (const u16*)sAddr_741918,
    (const u16*)sAddr_741946,
    (const u16*)sAddr_74197e,
    (const u16*)sAddr_7419d4,
    (const u16*)sAddr_741a14,
    (const u16*)sAddr_741a76,
    (const u16*)sAddr_741ad8,
    (const u16*)sAddr_741b3a,
    (const u16*)sAddr_741b98,
    (const u16*)sAddr_741bf6,
    (const u16*)sAddr_741c54,
    (const u16*)sAddr_741c6e,
    (const u16*)sAddr_741c90,
    (const u16*)sAddr_741cb2,
    (const u16*)sAddr_741cdc,
    (const u16*)sAddr_741d0a,
    (const u16*)sAddr_741d28,
    (const u16*)sAddr_741d50,
    (const u16*)sAddr_741d82,
    (const u16*)sAddr_741db2,
    (const u16*)sAddr_741dd6,
    (const u16*)sAddr_741df2,
    (const u16*)sAddr_741e24,
    (const u16*)sAddr_741e48
};

const u16* sFileSelectTextPointers_French[25] = {
    (const u16*)sAddr_741e82,
    (const u16*)sAddr_741ec4,
    (const u16*)sAddr_741eee,
    (const u16*)sAddr_741f32,
    (const u16*)sAddr_741f80,
    (const u16*)sAddr_741fbe,
    (const u16*)sAddr_74202a,
    (const u16*)sAddr_742096,
    (const u16*)sAddr_742102,
    (const u16*)sAddr_742162,
    (const u16*)sAddr_7421c2,
    (const u16*)sAddr_742222,
    (const u16*)sAddr_742244,
    (const u16*)sAddr_742270,
    (const u16*)sAddr_74229c,
    (const u16*)sAddr_7422c0,
    (const u16*)sAddr_7422f2,
    (const u16*)sAddr_742318,
    (const u16*)sAddr_74234e,
    (const u16*)sAddr_742362,
    (const u16*)sAddr_742386,
    (const u16*)sAddr_7423aa,
    (const u16*)sAddr_7423d4,
    (const u16*)sAddr_7423f6,
    (const u16*)sAddr_742420
};

const u16* sFileSelectTextPointers_Italian[25] = {
    (const u16*)sAddr_74244c,
    (const u16*)sAddr_742486,
    (const u16*)sAddr_7424c0,
    (const u16*)sAddr_7424fe,
    (const u16*)sAddr_74254e,
    (const u16*)sAddr_742586,
    (const u16*)sAddr_7425f2,
    (const u16*)sAddr_74265e,
    (const u16*)sAddr_7426ca,
    (const u16*)sAddr_74272e,
    (const u16*)sAddr_742792,
    (const u16*)sAddr_7427f6,
    (const u16*)sAddr_74280c,
    (const u16*)sAddr_74282c,
    (const u16*)sAddr_742840,
    (const u16*)sAddr_74286a,
    (const u16*)sAddr_74289e,
    (const u16*)sAddr_7428c4,
    (const u16*)sAddr_74290a,
    (const u16*)sAddr_742938,
    (const u16*)sAddr_742964,
    (const u16*)sAddr_742982,
    (const u16*)sAddr_7429ac,
    (const u16*)sAddr_7429dc,
    (const u16*)sAddr_742a00
};

const u16* sFileSelectTextPointers_Spanish[25] = {
    (const u16*)sAddr_742a28,
    (const u16*)sAddr_742a66,
    (const u16*)sAddr_742a8e,
    (const u16*)sAddr_742ac0,
    (const u16*)sAddr_742b18,
    (const u16*)sAddr_742b50,
    (const u16*)sAddr_742baa,
    (const u16*)sAddr_742c04,
    (const u16*)sAddr_742c5e,
    (const u16*)sAddr_742cba,
    (const u16*)sAddr_742d16,
    (const u16*)sAddr_742d74,
    (const u16*)sAddr_742d8a,
    (const u16*)sAddr_742da2,
    (const u16*)sAddr_742dc8,
    (const u16*)sAddr_742de4,
    (const u16*)sAddr_742df8,
    (const u16*)sAddr_742e18,
    (const u16*)sAddr_742e4c,
    (const u16*)sAddr_742e7c,
    (const u16*)sAddr_742e9c,
    (const u16*)sAddr_742ec6,
    (const u16*)sAddr_742eee,
    (const u16*)sAddr_742f14,
    (const u16*)sAddr_742f42
};

const u16* sFileSelectCorruptedTextPointers[2] = {
    (const u16*)sAddr_742f66,
    (const u16*)sAddr_742f7a
};

const u16** sFileSelectTextPointers[LANGUAGE_COUNT] = {
    sFileSelectTextPointers_Japanese,
    sFileSelectTextPointers_Japanese,
    sFileSelectTextPointers_English,
    sFileSelectTextPointers_German,
    sFileSelectTextPointers_French,
    sFileSelectTextPointers_Italian,
    sFileSelectTextPointers_Spanish
};

const u16** sFileSelectCorruptedTextPointersByLanguage[LANGUAGE_COUNT] = {
    sFileSelectCorruptedTextPointers,
    sFileSelectCorruptedTextPointers,
    sFileSelectCorruptedTextPointers,
    sFileSelectCorruptedTextPointers,
    sFileSelectCorruptedTextPointers,
    sFileSelectCorruptedTextPointers,
    sFileSelectCorruptedTextPointers
};

/**
 * @brief 87610 | f8 | Handler for the title intro
 * 
 */
boolu32 TitleIntroHandler(void) 
{
    boolu32 result;

    result = FALSE;
    
    if (gChangedInput & (KEY_START | KEY_A))
    {
        if (gSubGameMode1 == 3)
        {
            if (INTRO_DATA.unk_20E != 0)
                INTRO_DATA.unk_20E = 0;
        }
        else if (gSubGameMode1 != 0 && gSubGameMode1 != 3)
        {
            if (READ_16(REG_BLDCNT) & BLDCNT_ALPHA_BLENDING_EFFECT)
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
            
            INTRO_DATA.unk_20E = 0;
            gSubGameMode1 = 3;
            FadeAllSounds(20);
            FadeMusic(20);
        }
    }

    switch (gSubGameMode1)
    {
        case 0:
            NewFileIntroInit();
            gSubGameMode1 = 1;
            break;
        
        case 1:
            if (IntroSpaceView())
                gSubGameMode1 = 2;
            break;
        
        case 2:
            if (TitleIntroSamusShipCrashing())
                gSubGameMode1 = 3;
            break;
        
        case 3:
            if (INTRO_DATA.unk_20E == 0)
            {
                if (gWrittenToBldy < BLDY_MAX_VALUE)
                    gWrittenToBldy++;
                else
                    result = TRUE;
            }
            else
                INTRO_DATA.unk_20E--;
            
            SpecialCutsceneDrawAllOam(); 
    }

    return result;
}

 /**
 * @brief 87708 | 218 | Handler for new file intro
 * 
 */
boolu32 NewFileIntroHandler(void) 
{
    boolu32 result;

    result = FALSE;

    switch (gSubGameMode1)
    {
        case 0:
            StopAllMusicAndSounds();
            NewFileIntroInit();

            if (gGameCompletion.introPlayed == TRUE)
                return TRUE;
            else 
                gSubGameMode1 = 1;
            break;

        case 1:
            INTRO_DATA.timer++;
            if (INTRO_DATA.timer >= 100)
            {
                INTRO_DATA.timer = 0;
                gSubGameMode1 = 2;
            }
            break;

        case 2:
            if (NewFileIntroSr388Preview())
                gSubGameMode1 = 3;
            break;

        case 3:
            if (NewFileIntroInSr388())
                gSubGameMode1 = 4;
            break;

        case 4:
            if (NewFileIntroSamusShipFlying())
                gSubGameMode1 = 5;
            break;

        case 5:
            if (NewFileIntroSamusFainting())
                gSubGameMode1 = 6;
            break;

        case 6:
            if (NewFileIntroSamusDrifting())
                gSubGameMode1 = 7;
            break;

        case 7:
            if (NewFileIntroSamusFound())
                gSubGameMode1 = 8;
            break;

        case 8:
            if (NewFileIntroSamusGettingCured())
                gSubGameMode1 = 9;
            break;

        case 9:
            if (NewFileIntroSamusCured())
                gSubGameMode1 = 10;
            break;

        case 10:
            if (NewFileIntroArrivingAtBsl())
                gSubGameMode1 = 11;
            break;

        case 11:
            if (NewFileIntroLandingOnBsl())
            {
                INTRO_DATA.unk_20E = 0;
                gSubGameMode1 = 12;
            }
            break;
        
        case 12:
            INTRO_DATA.unk_20E++;
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (INTRO_DATA.unk_20E == 1)
                {
                    INTRO_DATA.unk_20E = 0;
                    gWrittenToBldy++;
                }
            }
            else
            {
                if (INTRO_DATA.unk_20E == 1)
                {
                    Sram_ProcessIntroSave(0);
                }
                else if (INTRO_DATA.unk_20E == 2)
                {
                    Sram_ProcessIntroSave(1);
                } 
                else if (INTRO_DATA.unk_20E == 3)
                {
                    Sram_ProcessIntroSave(2);
                }
                else if (INTRO_DATA.unk_20E == 4)
                {
                    Sram_ProcessIntroSave(3);
                    INTRO_DATA.timer = 0;
                    INTRO_DATA.unk_20E = 0;
                    result = TRUE;
                }
            }

            SpecialCutsceneDrawAllOam();
    }

    return result;
}

 /**
 * @brief 87920 | 50 | To document
 * 
 */
boolu32 unk_87920(void) 
{
    boolu32 result;
    boolu32 done;
    
    result = FALSE;

    switch (gCurrentCutscene)
    {
        default:
            result = TRUE;
            done = FALSE;
            break;

        case 1:
            done = TitleIntroHandler();
            break;

        case 2:
            done = NewFileIntroHandler();
            break;

        case 3:
            done = EndingHandler();
            break;

        case 4:
            done = DiedFromSr388CollisionHandler();
    }

    if (done)
    {
        StopAllMusicAndSounds();
        result = TRUE;
    }
    
    return result;
}

 /**
 * @brief 87970 | 94 | V-blank for the new file intro Samus ship flying cutscene
 * 
 */
void NewFileIntroSamusShipFlyingVblank(void) 
{
    DMA3_COPY_32(gOamData, OAM_BASE, 256);

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    WRITE_16(REG_BLDY, gWrittenToBldy);

    WRITE_16(REG_BG1HOFS, gBg1XPosition);
    WRITE_16(REG_BG1VOFS, gBg1YPosition);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);
}

 /**
 * @brief 87a04 | 264 | Setup for the new file intro Samus ship flying cutscene
 * 
 */
void NewFileIntroSamusShipFlyingInit(void) 
{
    u16 i;
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    for (i = 0; i < ARRAY_SIZE(sIntroBslObjectGfxPointers); i++)
        LZ77UncompVram(sIntroBslObjectGfxPointers[i], VRAM_OBJ + i * 0x1000);
    
    DMA3_COPY_32(sIntroSamusShipPal, PALRAM_OBJ, 5 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598150, PALRAM_OBJ + 0x100, 2 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    LZ77UncompWram(sIntroBslSpaceBgGfx, EWRAM_BASE + 0x10000);

    DMA3_COPY_32(EWRAM_BASE + 0x10000, VRAM_BASE, (VRAM_SIZE / 3) / 4);

    LZ77UncompVram(sIntroBslTilemap, VRAM_BASE + 0xE800);
    LZ77UncompVram(sIntroSpaceTilemap, VRAM_BASE + 0xF800);

    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 8 * PAL_ROW_SIZE / 4);

    WRITE_16(PALRAM_BASE, 0);

    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 48;
    gBg2YPosition = -8;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
    WRITE_16(REG_BG0CNT, 28 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | 2 << BGCNT_CHAR_BASE_BLOCK_SHIFT);
    WRITE_16(REG_BG2CNT, BGCNT_SIZE_512x256 << BGCNT_SCREEN_SIZE_SHIFT | 29 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | BGCNT_LOW_MID_PRIORITY);
    WRITE_16(REG_BG3CNT, 31 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | BGCNT_LOW_PRIORITY);

    NewFileIntroSetupOam(200, 250, 0, 0);
    NewFileIntroSetupOam(1, (s16)gBg2XPosition, (s16)gBg2YPosition, 0);
    NewFileIntroSetupOam(2, 160, 90, 0);
    NewFileIntroSetupOam(4, 0, 0, 1);

    for (i = 0; i < 10; i++)
        NewFileIntroSetupOam(3, SpecialCutsceneGetRandomNumber(), SpecialCutsceneGetRandomNumber(), 1);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4 );

    INTRO_DATA.pText = sCutsceneTextNone;
    WRITE_16(REG_DISPCNT, DCNT_OBJ | DCNT_BG3 | DCNT_BG2);

    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
}

 /**
 * @brief 87C68 | 188 | Processes the new file intro Samus ship flying cutscene
 * 
 */
boolu32 NewFileIntroSamusShipFlyingProcess(void) 
{
    boolu32 result;

    result = FALSE;

    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
        INTRO_DATA.unk_218 = 1;
    
    INTRO_DATA.timer++;

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
                NewFileIntroSetupOam(3, 0, SpecialCutsceneGetRandomNumber(), 1);

            if (INTRO_DATA.timer == 99)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
            }
            else if (INTRO_DATA.timer == 100)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][10];
                INTRO_DATA.subStage = 1;
            }
            break;
        
        case 1:
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
                NewFileIntroSetupOam(3, 0, SpecialCutsceneGetRandomNumber(), 1);

            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 2;
            }
            break;

        case 2:
            if (INTRO_DATA.timer == 30)
            {
                INTRO_DATA.timer = 0;
                gWrittenToBldy = BLDY_MAX_VALUE;
                result = TRUE;
            }
    }
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    IntroProcessText();

    return result;
}

 /**
 * @brief 87df0 | a0 | Main handler for new file intro Samus ship flying cutscene
 * 
 */
boolu32 NewFileIntroSamusShipFlying(void)
{
    boolu32 result;

    result = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSamusShipFlyingInit();
            INTRO_DATA.stage = 1;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusShipFlyingProcess())
            {
                INTRO_DATA.stage = 3;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;   
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
                gWrittenToBldy++;
            else 
            {
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.subStage = 0;
                INTRO_DATA.stage = 0;
                result = TRUE;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
    }

    return result;
}

 /**
 * @brief 87e90 | 1d8 | Setup for the new file intro Samus fainting cutscene
 * 
 */
void NewFileIntroSamusFaintingInit(void)
{
    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    LZ77UncompVram(sIntroSamusSittingTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusSittingTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusSittingGfx, VRAM_BASE);

    DMA3_COPY_32(sIntroSamusSittingPal, PALRAM_BASE, 128);

    WRITE_16(PALRAM_BASE, 0);

    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 64);
    
    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 10;
    gBg2YPosition = 2;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
    WRITE_16(REG_BG0CNT, 28 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | 2 << BGCNT_CHAR_BASE_BLOCK_SHIFT);
    WRITE_16(REG_BG2CNT, 30 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | BGCNT_LOW_MID_PRIORITY);
    WRITE_16(REG_BG3CNT, 31 << BGCNT_SCREEN_BASE_BLOCK_SHIFT | BGCNT_LOW_PRIORITY);

    NewFileIntroSetupOam(200, 250, 0, 0);
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, VRAM_SIZE / 24 );

    INTRO_DATA.pText = sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, DCNT_OBJ | DCNT_BG3 | DCNT_BG2);

    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
    
    gWrittenToBldy = 0;
    gWrittenToBldalpha_Eva = 12;
    gWrittenToBldalpha_Evb = 8;
}

 /**
 * @brief 88068 | 13c | Processes the new file intro Samus fainting cutscene
 * 
 */
boolu32 NewFileIntroSamusFaintingProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
        INTRO_DATA.unk_218 = 1;
    
    INTRO_DATA.timer += 1;
    
    switch (INTRO_DATA.subStage) 
    {
        case 0:
            if (INTRO_DATA.timer == 1)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_FIRST_TARGET_PIXEL);
                NewFileIntroSetupOam(10, gBg2XPosition, gBg2YPosition, 1);
            }
            else if (INTRO_DATA.timer == 59)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
            }
            else if (INTRO_DATA.timer == 60)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][11];
                INTRO_DATA.subStage = 1;
            }
            break;
        
        case 1:
            INTRO_DATA.timer = 0;

            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 2;
                gWrittenToBldy = 16;
            }
            break;
        
        case 2:
            if (INTRO_DATA.timer == 30) 
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
                INTRO_DATA.timer = 0;
                finished = TRUE;
            }
            break;
    }
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    IntroProcessText();
    
    return finished;
}

 /**
 * @brief 881a4 | 9c | Main handler for the new file intro Samus fainting cutscene
 * 
 */
boolu32 NewFileIntroSamusFainting(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSamusFaintingInit();
            INTRO_DATA.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusFaintingProcess())
            {
                INTRO_DATA.stage = 3;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
            }
            break;

        case 3:
            if (gWrittenToBldy < 16)
            {
                gWrittenToBldy++;
            }
            else 
            {
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.subStage = 0;
                INTRO_DATA.stage = 0;
                finished = TRUE;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

 /**
 * @brief 88240 | 26c | Setup for the 'gunship drifting away from BSL ship' cutscene
 * 
 */
void NewFileIntroSamusDriftingInit(void)
{
    u16 i;

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    
    for (i = 0; i < ARRAY_SIZE(sIntroBslObjectGfxPointers); i++)
        LZ77UncompVram(sIntroBslObjectGfxPointers[i], VRAM_OBJ + i * 0x1000);
    
    DMA3_COPY_32(sIntroSamusShipPal, PALRAM_OBJ, 5 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598150, PALRAM_OBJ + 0x100, 2 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);
    
    LZ77UncompWram(sIntroBslSpaceBgGfx, EWRAM_BASE + 0x10000);
    
    DMA3_COPY_32(EWRAM_BASE + 0x10000, VRAM_BASE, (VRAM_SIZE / 3) / 4);
    
    LZ77UncompVram(sIntroBslTilemap, VRAM_BASE + 0xE800);
    LZ77UncompVram(sIntroSpaceTilemap, VRAM_BASE + 0xF800);
    
    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 8 * PAL_ROW_SIZE / 4);
    
    SET_BACKDROP_COLOR(COLOR_BLACK);

    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    
    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);
    
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 48;
    gBg2YPosition = -8;
    gBg3XPosition = 0;
    gBg3YPosition = 0;
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 29, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_512x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    NewFileIntroSetupOam(200, 250, 0, 0);
    NewFileIntroSetupOam(1, gBg2XPosition, gBg2YPosition, 0);
    NewFileIntroSetupOam(20, 160, 90, 0);
    NewFileIntroSetupOam(4, 0, 0, 1);
    
    for (i = 0; i < 10; i++)
        NewFileIntroSetupOam(3, SpecialCutsceneGetRandomNumber(), SpecialCutsceneGetRandomNumber(), 1);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);
    
    INTRO_DATA.pText = sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
    
    gWrittenToBldy = 0;
}

 /**
 * @brief 884ac | c8 | V-blank for the 'Samus losing conciousness' cutscene
 * 
 */
void NewFileIntroSamusLosingConsciousnessVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    WRITE_16(REG_BLDY, gWrittenToBldy);

    WRITE_16(REG_BG1HOFS, gBg1XPosition);
    WRITE_16(REG_BG1VOFS, gBg1YPosition);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);
    
    if (INTRO_DATA.unk_110 == 1)
    {
        INTRO_DATA.unk_110 = 0;
        DMA3_COPY_32(sIntroSamusCloseupGrayscalePal, PALRAM_BASE, 4 * PAL_ROW_SIZE / 4);
    }
}

 /**
 * @brief 88574 | 1e0 | Setup for the 'Samus losing conciousness' cutscene
 * 
 */
void NewFileIntroSamusLosingConsciousnessInit(void) 
{
    u16 i;

    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, 0x030016a0, 720); // TODO: Find out what 16a0 is
    
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    for (i = 0; i < ARRAY_SIZE(sIntroSamusHelmetCloseupBgGfxPointers); i++)
        LZ77UncompVram(sIntroSamusHelmetCloseupBgGfxPointers[i], VRAM_BASE + i * 0x1000);
    
    LZ77UncompVram(sIntroSamusHelmetCloseupTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusHelmetCloseupTilemap, VRAM_BASE + 0xF800);

    DMA3_COPY_32(sIntroSamusHelmetCloseupPal, PALRAM_BASE, 4 * PAL_ROW_SIZE / 4);
    
    SET_BACKDROP_COLOR(COLOR_BLACK);

    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    
    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 8 * PAL_ROW_SIZE / 4);
    
    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);
    
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 10;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    NewFileIntroSetupOam(200, 250, 0, 0);
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);
    
    INTRO_DATA.pText = sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(NewFileIntroSamusLosingConsciousnessVblank);
    
    gWrittenToBldy = 0;
    gWrittenToBldalpha_Eva = 12;
    gWrittenToBldalpha_Evb = 8;
}

 /**
 * @brief 88754 | 25c | Setup for the 'gunship drifting into asteroids' cutscene
 * 
 */
void NewFileIntroSamusDriftingIntoAsteroidsInit(void) 
{
    u16 i;
    void* temp1;
    u32 temp2;
    
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
    
    for (i = 0; i < ARRAY_SIZE(sIntroBslObjectGfxPointers); i++)
        LZ77UncompVram(sIntroBslObjectGfxPointers[i], VRAM_OBJ + i * 0x1000);
    
    DMA3_COPY_32(sIntroSamusDriftingIntoAsteroidsObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598150, PALRAM_OBJ + 0x100, 2 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    LZ77UncompVram(sTitleScreenSpaceBackgroundGfx, VRAM_BASE);
    LZ77UncompVram(sTitleScreenSpaceBackgroundTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    
    DMA3_COPY_32(sIntroSamusDriftingIntoAsteroidsBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598a8c, PALRAM_BASE + 0x1E0, PAL_ROW_SIZE / 4);
    
    SET_BACKDROP_COLOR(COLOR_BLACK);
    
    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);
    
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);

    gWrittenToBldalpha_Eva = gWrittenToBldalpha_Evb = 0;

    //WRITE_16(REG_BLDALPHA, 0); // Doesn't match
    temp1 = REG_BLDALPHA;
    temp2 = 0;
    WRITE_16(temp1, temp2);
    
    NewFileIntroSetupOam(30, 140, 140, 0);
    NewFileIntroSetupOam(31, 140, 80, 0);
    
    for (i = 0; i < 4; i++)
        NewFileIntroSetupOam(36, SpecialCutsceneGetRandomNumber(), SpecialCutsceneGetRandomNumber(), 1);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    INTRO_DATA.pText = sCutsceneTextNone;
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);
    
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(NewFileIntroSamusShipFlyingVblank);
    
    gWrittenToBldy = 0;
}

 /**
 * @brief 889b0 | 318 | To document
 * 
 */
boolu32 NewFileIntroSamusDriftingProcess(void)
{
    boolu32 finished;
    s16 x;
    s16 y;

    finished = FALSE;
    
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && !INTRO_DATA.unk_218)
        INTRO_DATA.unk_218 = 1;
    
    INTRO_DATA.timer++;
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
                NewFileIntroSetupOam(3, 0, SpecialCutsceneGetRandomNumber(), TRUE);
            
            if (INTRO_DATA.timer != 149) // Why?
            {
                if (INTRO_DATA.timer == 150)
                {
                    INTRO_DATA.timer = 0;
                    INTRO_DATA.subStage = 1;
                    gWrittenToBldy = BLDY_MAX_VALUE;
                }
            }
            break;
        
        case 1:
            NewFileIntroSamusLosingConsciousnessInit();
            INTRO_DATA.timer = 0;
            INTRO_DATA.subStage = 2;
            break;
        
        case 2:
            if (INTRO_DATA.timer == 1)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
                NewFileIntroSetupOam(10, gBg2XPosition, gBg2YPosition, TRUE);
                gWrittenToBldy = 0;
            }
            else if (INTRO_DATA.timer == 118)
            {
                break;
            }
            else if (INTRO_DATA.timer == 120)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG2);
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                INTRO_DATA.unk_110 = 1;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 3;
            }
            break;

        case 3:
            if (INTRO_DATA.timer == 60)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 4;
                gWrittenToBldy = 16;
            }
            break;
        
        case 4:
            NewFileIntroSamusDriftingIntoAsteroidsInit();
            INTRO_DATA.timer = 0;
            INTRO_DATA.subStage = 5;
            break;
        
        case 5:
            INTRO_DATA.timer = 0;
            
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
            {
                x = SpecialCutsceneGetRandomNumber();
                y = SpecialCutsceneGetRandomNumber();
                NewFileIntroSetupOam(36, x, y, TRUE);
            }
            break;

        case 6:
            WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
            
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (INTRO_DATA.timer == 3)
                {
                    INTRO_DATA.timer = 0;
                    gWrittenToBldy++;
                }
            } 
            else if (INTRO_DATA.timer == 10)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 7;
                finished = TRUE;
            }
            
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
            {
                x = SpecialCutsceneGetRandomNumber();
                y = SpecialCutsceneGetRandomNumber();
                NewFileIntroSetupOam(36, x, y, TRUE);
            }
            break;
        
        case 7:
            if (gWrittenToBldy) 
            {
                if (INTRO_DATA.timer == 6) 
                {
                    INTRO_DATA.timer = 0;
                    gWrittenToBldy--;
                }
            } 
            else 
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 8;
            }

            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
            {
                x = SpecialCutsceneGetRandomNumber();
                y = SpecialCutsceneGetRandomNumber();
                NewFileIntroSetupOam(36, x, y, TRUE);
            }
            break;
        
        case 8:
            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 1)
            {
                SpecialCutsceneDestroyOamOfType(201);
                INTRO_DATA.subStage = 9;
            }
            
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
            {
                x = SpecialCutsceneGetRandomNumber();
                y = SpecialCutsceneGetRandomNumber();
                NewFileIntroSetupOam(36, x, y, TRUE);
            }
            break;
        
        case 9:
            finished = TRUE;
            break;
    }
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    IntroProcessText();
    
    return finished;
}

 /**
 * @brief 88cc8 | 9c | To document
 * 
 */
boolu32 NewFileIntroSamusDrifting(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSamusDriftingInit();
            INTRO_DATA.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusDriftingProcess())
            {
                INTRO_DATA.stage = 3;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else 
            {
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.subStage = 0;
                INTRO_DATA.stage = 0;
                finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

 /**
 * @brief 88d64 | 150 | To document
 * 
 */
void NewFileIntroProcessBslShip(struct SpecialCutsceneOam *pOam)
{
    s32 cos;
    s32 sin;
    
    pOam->unk_4 = pOam->xPosition;
    
    if (pOam->stage == 0) 
    {
        pOam->stage = 2;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_A++;
        pOam->xPosition = (((60 - pOam->spawnX) * pOam->unk_A) >> 10) + pOam->spawnX;
        pOam->yPosition = (((10 - pOam->spawnY) * pOam->unk_A) >> 10) + pOam->spawnY;
        
        if (pOam->xPosition > 39) 
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        pOam->unk_A++;
        if (pOam->unk_A == 1) 
        {
            pOam->unk_A = 0;
            pOam->spawnX = 0;
            pOam->spawnY = 4;
            pOam->unk_8 = pOam->yPosition;
            pOam->timer = 128;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        cos = pOam->spawnX * COS(pOam->timer);
        sin = pOam->spawnY * SIN(pOam->timer);
        pOam->yPosition = ((SIN(0) * cos + COS(0) * sin) >> 16) + pOam->unk_8;
        pOam->timer++;
        
        if (pOam->unk_A != 60) // Why?
        {
            if (pOam->unk_A == 200)
            {
                pOam->unk_A = 0;
                pOam->stage = 4;
            } 
        }
    }
    else if (pOam->stage == 4)
    {
        pOam->stage = 5;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
    } 
    else if (pOam->stage == 5)
    {    
        pOam->unk_A++;
        pOam->xPosition = (((520 - pOam->spawnX) * pOam->unk_A) >> 10) + pOam->spawnX;
        pOam->yPosition = (((100 - pOam->spawnY) * pOam->unk_A) >> 10) + pOam->spawnY;

        if (pOam->xPosition >= 520)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 6;
        }
    }
    
    gBg2XPosition = pOam->xPosition;
    gBg2YPosition = pOam->yPosition;
}

 /**
 * @brief 88eb4 | 128 | To document
 * 
 */
void NewFileIntroProcessFlyingSamusShip(struct SpecialCutsceneOam *pOam)
{
    s32 rotation;
    s32 cos;
    s32 sin;
    s32 x;
    s32 y;

    rotation = 0;
    
    if (pOam->stage == 0)
    {
        pOam->unk_4 = pOam->xPosition;
        pOam->unk_8 = pOam->yPosition;
        pOam->timer = 64;
        pOam->stage = 2;
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        pOam->scaling -= 2;

        if (pOam->timer == 128)
        {
            pOam->stage = 2;
            pOam->scaling = Q_8_8(1);
        }
    }
    else if (pOam->stage == 2)
    {
        pOam->spawnX = 0;
        pOam->spawnY = 8;
        pOam->unk_4 = pOam->xPosition;
        pOam->unk_8 = pOam->yPosition;
        pOam->stage = 3;
    }
    else if (pOam->stage == 3)
    {
        pOam->timer += 2;
    }
    else if (pOam->stage == 4)
    {
        pOam->timer++;
        pOam->unk_A++;
        if (pOam->unk_A == 180)
        {
            pOam->unk_A = 0;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 5)
    {
        pOam->spawnX = 280 - pOam->xPosition;
        pOam->spawnY = 60;
        pOam->unk_4 = pOam->xPosition + pOam->spawnX;
        pOam->unk_8 = pOam->yPosition;
        pOam->timer = 128;
        pOam->stage = 6;
    }
    else if (pOam->stage == 6)
    {
        pOam->timer++;
        if (pOam->timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
    
    cos = pOam->spawnX * COS(pOam->timer);
    sin = pOam->spawnY * SIN(pOam->timer);
    
    x = cos * COS(rotation) - sin * SIN(0);
    y = cos * SIN(0) + sin * COS(rotation);
    
    pOam->xPosition = (x >> 16) + pOam->unk_4;
    pOam->yPosition = (y >> 16) + pOam->unk_8;
}

 /**
 * @brief 88fdc | b4 | To document
 * 
 */
void NewFileIntroProcessHorizontalParticle(struct SpecialCutsceneOam *pOam)
{
    s32 rng;
    
    if (pOam->stage == 0)
    {
        rng = SpecialCutsceneGetRandomNumber() & 7;
        pOam->unk_8 = rng + 1;
        rng = SpecialCutsceneGetRandomNumber() & 3;
        pOam->unk_4 = rng;
        pOam->pOam = sData_79C2CC[pOam->unk_4];
        pOam->spawnX = pOam->xPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_A++;
        pOam->xPosition = ((pOam->unk_8 * pOam->unk_A) >> 4) + pOam->spawnX;
        
        pOam->timer++;
        if (pOam->timer == 8)
        {
            pOam->timer = 0;
            
            if (pOam->unk_4 < 5)
                pOam->unk_4++;
            else
                pOam->unk_4 = 0;
            
            pOam->pOam = sData_79C2CC[pOam->unk_4];
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }
    }
    
    if (pOam->xPosition >= SCREEN_SIZE_X || pOam->yPosition >= SCREEN_SIZE_Y)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 89090 | 28 | To document
 * 
 */
void unk_89090(struct SpecialCutsceneOam *pOam) 
{
    pOam->animationDurationCounter++;
    if (pOam->animationDurationCounter == 25)
    {
        pOam->animationDurationCounter = 0;
        gBg3XPosition--;
    }
}

 /**
 * @brief 890b8 | 104 | To document
 * 
 */
void NewFileIntroProcessSamusFainting(struct SpecialCutsceneOam* pOam)
{
    u8 rng1;
    u8 rng2;

    rng1 = sRandomNumberTable[MOD_AND(gFrameCounter16Bit, 32)] / 2;
    rng2 = sRandomNumberTable[MOD_AND(gFrameCounter16Bit + 7, 32)] / 2;

    if (!pOam->unk_8)
    {
        pOam->timer++;
        if (pOam->timer)
        {
            pOam->timer = 0;
            if (pOam->yPosition < 16)
            {
                pOam->yPosition += rng2;
                if (pOam->yPosition > 15)
                {
                    pOam->yPosition = 16;
                    pOam->unk_8 = 1;
                }
            }
        }
    }
    else
    {
        pOam->timer++;
        if (pOam->timer)
        {
            pOam->timer = 0;
            if (pOam->yPosition > 0)
            {
                pOam->yPosition -= rng2;
                if (pOam->yPosition <= 0)
                {
                    pOam->yPosition = 0;
                    pOam->unk_8 = 0;
                }
            }
        }
    }

    if (!pOam->unk_4)
    {
        pOam->unk_A++;
        if (pOam->unk_A)
        {
            pOam->unk_A = 0;
            if (pOam->xPosition < 16)
            {
                pOam->xPosition += rng1;
                if (pOam->xPosition > 15)
                {
                    pOam->xPosition = 16;
                    pOam->unk_4 = 1;
                }
            }
        }
    }
    else
    {
        pOam->unk_A++;
        if (pOam->unk_A)
        {
            pOam->unk_A = 0;
            if (pOam->xPosition > 0)
            {
                pOam->xPosition -= rng1;
                if (pOam->xPosition <= 0)
                {
                    pOam->xPosition = 0;
                    pOam->unk_4 = 0;
                }
            }
        }
    }

    gBg2XPosition = pOam->xPosition;
    gBg2YPosition = pOam->yPosition;
}

 /**
 * @brief 891bc | 74 | To document
 * 
 */
void NewFileIntroProcessSamusDrifting(struct SpecialCutsceneOam* pOam)
{
    pOam->unk_A++;
    
    if (pOam->stage == 0)
    {
        pOam->unk_A = 0;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->xPosition = pOam->spawnX + (pOam->unk_A >> 1);
        pOam->yPosition = pOam->spawnY + (pOam->unk_A >> 2);

        pOam->timer++;
        if (pOam->timer == 2)
        {
            pOam->timer = 0;
            pOam->scaling++;
        }
    }

    if (pOam->xPosition > (SCREEN_SIZE_X + 40) || pOam->yPosition > (SCREEN_SIZE_Y + 20))
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 89230 | 258 | To document
 * 
 */
void NewFileIntroProcessSamusDriftingIntoAsteroids(struct SpecialCutsceneOam *pOam)
{
    const struct FrameData* frame;

    pOam->unk_A++;
    
    if (pOam->stage == 0)
    {
        pOam->unk_A = 0;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->rotation -= 4;
        pOam->scaling -= 8;
        pOam->stage = 2;
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        pOam->yPosition = (SIN(pOam->timer) >> 7) + pOam->spawnY;
        
        if (pOam->timer > 52)
        {
            pOam->unk_4++;
            if (pOam->unk_4 == 12)
            {
                pOam->rotation--;
                pOam->xPosition--;
                pOam->unk_4 = 0;
            }
            
            pOam->unk_8++;
            if (pOam->unk_8 == 10)
            {
                pOam->unk_8 = 0;
                pOam->scaling--;
            }
        }

        if (pOam->timer > 127)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        pOam->timer++;
        pOam->xPosition = pOam->spawnX - (pOam->unk_A >> 2);
        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 3) + (SIN(pOam->timer) >> 7);
        pOam->unk_4++;
        
        if (pOam->unk_4 == 12)
        {
            pOam->rotation--;
            pOam->unk_4 = 0;
        }
        
        pOam->unk_8++;
        if (pOam->unk_8 == 2)
        {
            pOam->unk_8 = 0;
            pOam->scaling--;
        }
        
        if (pOam->timer == 0)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        pOam->timer++;
        pOam->xPosition = pOam->spawnX - (pOam->unk_A >> 2);
        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 3);
        pOam->unk_4++;
        
        if (pOam->unk_4 == 12)
        {
            pOam->rotation--;
            pOam->unk_4 = 0;
        }
        
        pOam->unk_8++;
        if (pOam->unk_8 == 1)
        {
            pOam->unk_8 = 0;
            pOam->scaling--;
        }
        
        if (pOam->timer == 0)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 4;
        }
        
        if (pOam->scaling < 3)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 4)
    {
        pOam->timer++;
        pOam->xPosition = pOam->spawnX - (pOam->unk_A >> 1);
        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 2);
        pOam->unk_4++;
        
        if (pOam->unk_4 == 12)
        {
            pOam->rotation--;
            pOam->unk_4 = 0;
        }
        
        pOam->unk_8++;
        if (pOam->unk_8 == 1)
        {
            pOam->unk_8 = 0;
            pOam->scaling--;
        }

        if (pOam->scaling < 3)
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 5)
    {
        pOam->unk_A = 0;
        pOam->scaling = Q_8_8(1);
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
        pOam->affineMode = OAM_AFFINE_MODE_NORMAL;
        pOam->pOam = sOam_598000;
        pOam->stage = 6;
        INTRO_DATA.subStage = 6;
    }
    else if (pOam->stage == 6)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

 /**
 * @brief 89488 | 64 | To document
 * 
 */
void unk_89488(struct SpecialCutsceneOam *pOam) 
{
    if (pOam->stage == 0)
    {
        NewFileIntroSetupOam(32, pOam->xPosition + 122, pOam->yPosition, FALSE);
        NewFileIntroSetupOam(33, pOam->xPosition + 50, pOam->yPosition + 1, FALSE);
        NewFileIntroSetupOam(34, pOam->xPosition + 36, pOam->yPosition, FALSE);
        NewFileIntroSetupOam(35, pOam->xPosition, pOam->yPosition, FALSE);
        pOam->type = 0;
    }
}

 /**
 * @brief 894ec | c4 | To document
 * 
 */
void NewFileIntroProcessSidewaysBslShip(struct SpecialCutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->timer++;
        if (pOam->timer == 20)
        {
            pOam->spawnX++;
            pOam->timer = 0;

            if (pOam->unk_A == 4)
                pOam->unk_A = 0;

            if (pOam->unk_A < 2)
                pOam->yPosition++;
            else if (pOam->unk_A < 4)
                pOam->yPosition--;
                
            pOam->unk_A++;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->unk_A = 0;
        pOam->stage = 2;
    }
    else if (pOam->stage == 2)
    {
        pOam->timer++;
        if (pOam->timer == 2)
        {
            pOam->unk_A++;
            pOam->timer = 0;
        }

        pOam->xPosition = (((900 - pOam->spawnX) * pOam->unk_A) >> 12) + pOam->spawnX;
        pOam->yPosition = (((pOam->unk_4 - pOam->spawnY) * pOam->unk_A) >> 11) + pOam->spawnY;

        if (pOam->xPosition > 320)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 3;
        }
    }
}

 /**
 * @brief 895b0 | c4 | To document
 * 
 */
void NewFileIntroProcessDepthParticle(struct SpecialCutsceneOam* pOam)
{
    s32 x;
    s32 y;
    s32 divisor;
    
    pOam->unk_4 = pOam->unk_A;

    if (pOam->stage == 0)
    {
        pOam->spawnX = (pOam->xPosition - SCREEN_X_MIDDLE) * 100;
        pOam->spawnY = (pOam->yPosition - SCREEN_Y_MIDDLE) * 100;
        pOam->stage = 1;
    }
    else
    {
        if ((s16)pOam->unk_A < 100)
        {
            if ((s16)pOam->unk_A == 25)
                pOam->pOam = sOam_597ed0;
            else if ((s16)pOam->unk_A == 50)
                pOam->pOam = sOam_597ee0;
            else if ((s16)pOam->unk_A == 70)
                pOam->pOam = sOam_597ef0;

            divisor = -pOam->unk_4 + 100;
            x = pOam->spawnX / divisor;
            pOam->xPosition = x + SCREEN_X_MIDDLE;
            y = pOam->spawnY / divisor + SCREEN_Y_MIDDLE;
            pOam->yPosition = y;

            if ((u16)(x + 128) > 256 || (s16)y > 168 || (s16)y < -8)
            {
                pOam->type = 0;
                pOam->unk_18_0 = 0;
            }
        }
        else
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
    
    pOam->unk_A++;
}

 /**
 * @brief 89674 | 400 | To document
 * 
 */
u8 NewFileIntroSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearchOrder)
{
    s8 slot;

    if (!descendingSearchOrder)
    {
        for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
        {
            if (INTRO_DATA.oam[slot].type == 0)
                break;
        }
        
        if (slot > 19)
            return 20;
    }
    else
    {
        for (slot = ARRAY_SIZE(INTRO_DATA.oam) - 1; slot >= 0; slot--)
        {
            if (INTRO_DATA.oam[slot].type == 0)
                break;
        }
        
        if (slot < 0)
            return 20;
    }
    
    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));

    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;

    if (type == 1)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessBslShip;
    }
    else if (type == 2)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].pOam = sOam_597f50;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessFlyingSamusShip;
    }
    else if (type == 3)
    {
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sOam_597ec0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessHorizontalParticle;
    }
    else if (type == 4)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_89090;
    }
    else if (type == 10)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusFainting;
    }
    else if (type == 20)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        INTRO_DATA.oam[slot].pOam = sOam_597f50;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusDrifting;
    }
    else if (type == 30)
    {
        INTRO_DATA.oam[slot].spawnX = xPosition;
        INTRO_DATA.oam[slot].spawnY = yPosition;
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        INTRO_DATA.oam[slot].pOam = sOam_597f88;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusDriftingIntoAsteroids;
    }
    else if (type == 31)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pOam = sOam_597f88;
        INTRO_DATA.oam[slot].pFunction = unk_89488;
    }
    else if (type == 32)
    {
        INTRO_DATA.oam[slot].unk_4 = -40;
        INTRO_DATA.oam[slot].pOam = sOam_597fe0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSidewaysBslShip;
    }
    else if (type == 33)
    {
        INTRO_DATA.oam[slot].unk_4 = -30;
        INTRO_DATA.oam[slot].pOam = sOam_597fd0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSidewaysBslShip;
    }
    else if (type == 34)
    {
        INTRO_DATA.oam[slot].unk_4 = -20;
        INTRO_DATA.oam[slot].pOam = sOam_597fc0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSidewaysBslShip;
    }
    else if (type == 35)
    {
        INTRO_DATA.oam[slot].unk_4 = -10;
        INTRO_DATA.oam[slot].pOam = sOam_597fb0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSidewaysBslShip;
    }
    else if (type == 36)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sOam_597ec0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessDepthParticle;
    }
    else if (type == 200)
    {
        INTRO_DATA.oam[slot].pOam = sIntroNextPageArrowOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessTextCursor;
    }
    else if (type == 201)
    {
        INTRO_DATA.oam[slot].pOam = sIntroNextPageArrowOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessOam_Empty;
    }
    
    return slot;
}

 /**
 * @brief 89a74 | 3c | To document
 * 
 */
void unk_89a74(u8 type, s16 xPos, s16 yPos, s16 arg3) 
{
    u8 slot;
    
    slot = NewFileIntroSetupOam(type, xPos, yPos, TRUE);
    INTRO_DATA.oam[slot].unk_8 = arg3;
}

 /**
 * @brief 89ab0 | 4 | To document
 * 
 */
void NewFileIntroProcessOam_Empty(void) 
{
    return;
}

 /**
 * @brief 89ab4 | 248 | To document
 * 
 */
void NewFileIntroSr388PreviewInit(void)
{
    u16 i;
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    
    LZ77UncompVram(sIntroSr388SpaceAndSurfaceObjGfx, VRAM_OBJ);
    
    DMA3_COPY_32(sIntroSr388SpaceAndSurfaceObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / sizeof(u32));
    
    CallbackSetVBlank(unk_99940);

    for (i = 0; i < ARRAY_SIZE(sIntroSr388SurfaceBgGfxPointers); i++)
        LZ77UncompVram(sIntroSr388SurfaceBgGfxPointers[i], VRAM_BASE + i * 0x1000);

    LZ77UncompVram(sIntroSr388SurfaceTilemap, VRAM_BASE + 0xE800);

    for (i = 0; i < ARRAY_SIZE(sIntroSr388PlanetBgGfxPointers); i++)
        LZ77UncompVram(sIntroSr388PlanetBgGfxPointers[i], VRAM_BASE + 0x8000 + i * 0x1000);
    
    LZ77UncompVram(sIntroSr388SpaceBgTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSr388PlanetTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    
    DMA3_COPY_32(sSr388SpaceAndSurfacePal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 29, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 16;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;
    
    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    
    NewFileIntroSr388SetupOam(50, 250, 200);
    NewFileIntroSr388SetupOam(1, 0, 0);
    NewFileIntroSr388SetupOam(2, gBg2XPosition, 0);
    
    NewFileIntroSetupSr388PreviewAsteroid(3, 250, 100, -12);
    NewFileIntroSetupSr388PreviewAsteroid(4, 150, 10, -8);
    NewFileIntroSetupSr388PreviewAsteroid(5, 50, 60, -6);
    NewFileIntroSetupSr388PreviewAsteroid(6, 190, 130, -20);
    NewFileIntroSetupSr388PreviewAsteroid(5, 280, 30, -10);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    INTRO_DATA.pText = sCutsceneTextNone;
    
    PlayMusic(MUSIC_SECTOR_1, 13);
    
    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(NewFileIntroSr388PreviewVblank);
}

 /**
 * @brief 89cfc | 348 | To document
 * 
 */
boolu32 NewFileIntroSr388PreviewProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    INTRO_DATA.timer++;
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (INTRO_DATA.timer == 1)
            {
                DMA3_FILL_32(0, VRAM_BASE + 0xD000, 0x1000);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
            }
            else if (INTRO_DATA.timer == 50)
            {
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][8];
            }
            else if (INTRO_DATA.timer == 58)
            {
                gWrittenToBldalpha_Eva = 0;
                gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
            }
            else if (INTRO_DATA.timer == 59)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);
            }
            else if (INTRO_DATA.timer == 60)
            {
                INTRO_DATA.timer = 0;
                NewFileIntroSr388SetupOam(9, gBg2XPosition + 92, 64);
                INTRO_DATA.subStage = 1;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 1:
            if (INTRO_DATA.timer == 2)
            {
                INTRO_DATA.timer = 0;

                if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
                    gWrittenToBldalpha_Eva++;
            }

            if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
                INTRO_DATA.unk_218 = 1;

            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 2;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (INTRO_DATA.timer == 2)
            {
                INTRO_DATA.timer = 0;

                if (gWrittenToBldalpha_Eva == 0)
                {
                    SpecialCutsceneDestroyOamOfType(9);
                    INTRO_DATA.subStage = 3;
                }
                else
                {
                    gWrittenToBldalpha_Eva--;
                }
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 3:
            if (INTRO_DATA.timer == 1)
            {
                gWrittenToBldalpha_Eva = 0;
                gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
            }
            else if (INTRO_DATA.timer == 2)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL 
                         | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 4;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 4:
            if (gWrittenToBldalpha_Eva == BLDALPHA_MAX_VALUE)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~(DCNT_BG2 | DCNT_BG3));
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.subStage = 5;
                NewFileIntroSr388SetupOam(10, 128, 210);
            }
            else if (gWrittenToBldalpha_Eva == 2)
            {
                NewFileIntroSr388SetupOam(7, 0, 0);
            }

            if (INTRO_DATA.timer == 7)
            {
                INTRO_DATA.timer = 0;

                if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
                {
                    gWrittenToBldalpha_Eva++;
                    gWrittenToBldalpha_Evb--;
                }
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 5:
            if (INTRO_DATA.timer == 70)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 6;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 6:
            INTRO_DATA.unk_213++;
            if (INTRO_DATA.unk_213 == 4)
            {
                INTRO_DATA.unk_213 = 0;

                if (gWrittenToBldy < BLDY_MAX_VALUE)
                {
                    gWrittenToBldy++;
                }
                else
                {
                    INTRO_DATA.timer = 0;
                    INTRO_DATA.subStage = 0;
                    finished = TRUE;
                }
            }

            if (gWrittenToBldy >= BLDY_MAX_VALUE)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
                finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    IntroProcessText();
    
    return finished;
}

 /**
 * @brief 8A044 | ac | To document
 * 
 */
boolu32 NewFileIntroSr388Preview(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSr388PreviewInit();
            INTRO_DATA.stage = 1;
            break;

        case 1:
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();

            INTRO_DATA.timer++;

            if (gWrittenToBldy)
            {
                if (INTRO_DATA.timer > 1)
                {
                    INTRO_DATA.timer = 0;
                    gWrittenToBldy--;
                }
            }
            else
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.stage = 2;
            }
            break;

        case 2:
            if (NewFileIntroSr388PreviewProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                INTRO_DATA.stage = 0;
                finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

 /**
 * @brief 8a0f0 | 40 | To document
 * 
 */
void unk_8a0f0(struct SpecialCutsceneOam* pOam)
{
    pOam->animationDurationCounter++;
    if (pOam->animationDurationCounter == 36)
        pOam->animationDurationCounter = 0;

    gBg3XPosition = pOam->xPosition;

    if (INTRO_DATA.subStage == 5)
    {
        gBg3XPosition = 0;
        pOam->type = 0;
    }
}

 /**
 * @brief 8a130 | 40 | To document
 * 
 */
void unk_8a130(struct SpecialCutsceneOam* pOam)
{
    pOam->animationDurationCounter++;
    if (pOam->animationDurationCounter == 29)
        pOam->animationDurationCounter = 0;

    gBg2XPosition = pOam->xPosition;

    if (INTRO_DATA.subStage == 5)
    {
        gBg2XPosition = 0;
        pOam->type = 0;
    }
}

 /**
 * @brief 8a170 | 6c | To document
 * 
 */
void NewFileIntroProcessSr388PreviewAsteroid(struct SpecialCutsceneOam *pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_A++;
        pOam->xPosition = ((pOam->unk_8 * pOam->unk_A) >> 6) + pOam->spawnX;
        
        if (pOam->xPosition < -40)
        {
            pOam->spawnX = 280;
            pOam->unk_A = 0;
        }
    }
    
    if (INTRO_DATA.subStage == 5)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 8a1dc | 28 | To document
 * 
 */
void unk_8a1dc(struct SpecialCutsceneOam* pOam)
{
    pOam->animationDurationCounter++;
    if (pOam->animationDurationCounter == 3)
    {
        pOam->animationDurationCounter = 0;
        pOam->unk_4++;
        gBg1YPosition = pOam->unk_4;
    }
}

 /**
 * @brief 8a204 | 64 | To document
 * 
 */
void unk_8a204(struct SpecialCutsceneOam *pOam)
{
    pOam->unk_A++;
    
    pOam->timer++;
    if (pOam->timer == 21)
        pOam->timer = 0;
    
    if (pOam->unk_A == 110)
        NewFileIntroSr388SetupOam(9, pOam->xPosition + 24, pOam->yPosition);
    else if (pOam->unk_A > 1000)
        pOam->unk_A = 1000;
    
    if (INTRO_DATA.subStage == 5)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 8a268 | 38 | To document
 * 
 */
void NewFileIntroProcessSunReflection(struct SpecialCutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == 29)
        pOam->timer = 0;

    if (INTRO_DATA.subStage == 5)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 8a2a0 | 30 | To document
 * 
 */
void NewFileIntroProcessSr388Rocks(struct SpecialCutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == 1)
    {
        pOam->timer = 0;
        pOam->yPosition--;
    }

    if (pOam->yPosition <= 160)
        pOam->pOam = sOam_59a0f0;
}

 /**
 * @brief 8a2d0 | 29c | To document
 * 
 */
u8 NewFileIntroSr388SetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == 0)
            break;
    }

    if (slot > 19)
        return 20;
    
    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));

    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;
    
    if (type == 1)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_8a0f0;
    }
    else if (type == 2)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_8a130;
    }
    else if (type == 3)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sOam_59a0a0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSr388PreviewAsteroid;
    }
    else if (type == 4)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sOam_59a0b0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSr388PreviewAsteroid;
    }
    else if (type == 5)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sOam_59a0c0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSr388PreviewAsteroid;
    }
    else if (type == 6)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sOam_59a0d0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSr388PreviewAsteroid;
    }
    else if (type == 7)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_8a1dc;
    }
    else if (type == 8)
    {
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sOam_59a100;
        INTRO_DATA.oam[slot].pFunction = unk_8a204;
    }
    else if (type == 9)
    {
        INTRO_DATA.oam[slot].unk_18_3 = 1;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sOam_59a0e0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSunReflection;
    }
    else if (type == 10)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sOam_59a168;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSr388Rocks;
    }
    else if (type == 50)
    {
        INTRO_DATA.oam[slot].pOam = sIntroNextPageArrowOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessTextCursor;
    }
    
    return slot;
}

 /**
 * @brief 8a56c | 38 | To document
 * 
 */
void NewFileIntroSetupSr388PreviewAsteroid(u8 type, s16 xPosition, s16 yPosition, s16 arg3)
{
    u8 slot;
    
    slot = NewFileIntroSr388SetupOam(type, xPosition, yPosition);
    INTRO_DATA.oam[slot].unk_8 = arg3;
}

 /**
 * @brief 8a5a4 | 94 | V-blank for the SR388 preview cutscene
 * 
 */
void NewFileIntroSr388PreviewVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    WRITE_16(REG_BLDY, gWrittenToBldy);

    WRITE_16(REG_BG1HOFS, gBg1XPosition);
    WRITE_16(REG_BG1VOFS, gBg1YPosition);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);
}

 /**
 * @brief 8a638 | 254 | Setup for the 'hornoad encounter in SR388' cutscene
 * 
 */
void NewFileIntroInSr388Init(void)
{
    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    LZ77UncompVram(sIntroHornoadEncounterObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sIntroHornoadEncounterObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sIntroHornoadEncounterBgGfx, VRAM_BASE);
    LZ77UncompVram(sTilemap_5a86c8, VRAM_BASE + 0xE800);
    LZ77UncompVram(sTilemap_5a83b8, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    LZ77UncompVram(sTilemap_5a9044, VRAM_BASE + 0xC000);

    DMA3_COPY_32(sPal_5a8e44, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 24, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_512x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 29, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_512x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    gBg2XPosition = 136;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg1XPosition = gBg3XPosition + 392;
    gBg1YPosition = gBg2YPosition - 96;

    gUnk_3001234 = 560;
    gUnk_3001236 = -40;

    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);

    NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_NEXT_PAGE_ARROW, 250, 200);
    NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_UNK_255, 0, 0);
    NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_UNK_255, 0, 0);
    NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_SAMUS, 234, 200);
    NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_LEFT_RESEARCHER, 288, 200);
    NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_RIGHT_RESEARCHER, 312, 100);
    NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_UNK_11, 0, 0);
    NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_CAVE_ENTRANCE_BG, 304 - gBg2XPosition, 200);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));
    
    INTRO_DATA.pText = sCutsceneTextNone;
    
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(NewFileIntroInSr388Vblank);
}

 /**
 * @brief 8a88c | 344 | Processes the 'hornoad encounter in SR388' cutscene
 * 
 */
boolu32 NewFileIntroInSr388Process(void)
{
    boolu32 finished;

    finished = FALSE;
    
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
        INTRO_DATA.unk_218 = 1;
    
    INTRO_DATA.timer++;
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            INTRO_DATA.unk_213++;
            if (INTRO_DATA.unk_213 == 4)
            {
                INTRO_DATA.unk_213 = 0;
            
                if (gWrittenToBldy)
                    gWrittenToBldy--;
            }
        
            if (INTRO_DATA.timer == 2)
            {
                INTRO_DATA.timer = 0;
                
                gBg2YPosition++;
                if (gBg2YPosition == 96)
                    INTRO_DATA.subStage = 2;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
        
            gBg2XPosition += INTRO_DATA.unk_216;
            break;
        
        case 1:
        case 2:
            INTRO_DATA.timer = 0;
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
        
            gBg2XPosition += INTRO_DATA.unk_216;
            break;
        
        case 3:
            if (INTRO_DATA.timer == 1)
                DMA3_FILL_32(0, VRAM_BASE + 0xD000, 0x1000);
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
        
            gBg2XPosition += INTRO_DATA.unk_216;
            break;
        
        case 4:
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            
            gBg2XPosition += INTRO_DATA.unk_216;
            INTRO_DATA.timer = 0;
            break;
        
        case 5:
            if (INTRO_DATA.timer == 1)
            {
                INTRO_DATA.unk_110 = 1;
            }
            else if (INTRO_DATA.timer == 30)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][9];
                INTRO_DATA.subStage = 6;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 6:
            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 9;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 7:
            if (INTRO_DATA.timer == 10)
            {
                DMA3_FILL_32(0, VRAM_BASE + 0xD000, 0x1000);
            }
            else if (INTRO_DATA.timer == 11)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_20C = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][10];
                INTRO_DATA.subStage = 8;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 8:
            INTRO_DATA.timer = 0;
        
            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 9;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 9:
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
        
            gBg2XPosition += INTRO_DATA.unk_216;
        
            if (INTRO_DATA.timer > 50)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                finished = TRUE;
            }
            break;
    }
    
    IntroProcessText();
    
    return finished;
}

 /**
 * @brief 8abd0 | 98 | Main handler for the 'hornoad encounter in SR388' cutscene
 * 
 */
boolu32 NewFileIntroInSr388(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroInSr388Init();
            
            INTRO_DATA.stage = 2;
            break;
        
        case 1:
            SpecialCutsceneFadeIn();

            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (NewFileIntroInSr388Process())
            {
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
                gWrittenToBldy = 0;
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                INTRO_DATA.stage = 0;
                INTRO_DATA.subStage = 0;
                finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

 /**
 * @brief 8ac68 | 5d8 | Processes Samus in the 'hornoad encounter in SR388' cutscene
 * 
 */
void NewFileIntroProcessSamusInSr388(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;
    s16 x;
    s16 y;

    pOam->timer++;
    
    if (INTRO_DATA.subStage == 0)
    {
        if (gBg2YPosition > 47)
        {
            pOam->yPosition = 240 - gBg2YPosition;
            pOam->xPosition--;
        }
        
        pOam->timer = 0;
    }
    else if (INTRO_DATA.subStage == 1)
    {
        pOam->yPosition = 240 - gBg2YPosition;
        
        if (pOam->stage == 0)
        {
            if (pOam->timer < 20)
            {
                pOam->xPosition--;
            }
            else if (pOam->timer < 70)
            {
                INTRO_DATA.unk_216 = -1;
            }
            else if (pOam->timer == 70)
            {
                INTRO_DATA.unk_216 = 0;
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_IdleLeft;
                pOam->stage = 1;
            }
        }
        else if (pOam->stage == 1)
        {
            if (pOam->timer == 30)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_TurningRight;
                pOam->stage = 2;
            }
        }
        else if (pOam->stage == 2)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_IdleRight;
                pOam->stage = 3;
                INTRO_DATA.unk_20C = 0;
            }
        }
        else if (pOam->stage == 3)
        {
            if (pOam->timer == 30)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_TurningLeft;
                pOam->stage = 4;
            }
        }
        else if (pOam->stage == 4)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_IdleLeft;
                pOam->stage = 5;
            }
        }
        else if (pOam->stage == 5)
        {
            if (pOam->timer == 30)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->stage = 0;
                INTRO_DATA.subStage = 2;
            }
        }
    }
    else if (INTRO_DATA.subStage == 2)
    {
        pOam->stage = 3;
        INTRO_DATA.subStage = 3;
    }
    else if (INTRO_DATA.subStage == 3)
    {
        if (pOam->stage == 0)
        {
            if (pOam->timer == 30)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_WalkingRight;
                pOam->stage = 1;
                pOam->xPosition++;
            }
        }
        else if (pOam->stage == 1)
        {
            if (pOam->xPosition < 260)
            {
                pOam->xPosition++;
            }
            else
            {
                pOam->xPosition = 260;
                pOam->timer = 0;
                pOam->stage = 2;
            }
        }
        else if (pOam->stage == 2)
        {
            if (pOam->timer == 1)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_WalkingLeft;
                pOam->stage = 3;
            }
        }
        else if (pOam->stage == 3)
        {
            if (pOam->xPosition > 140)
            {
                pOam->xPosition--;
            }
            else if (gBg2XPosition > 108)
            {
                INTRO_DATA.unk_216 = -1;
            }
            else
            {
                INTRO_DATA.unk_216 = 0;
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_IdleLeft;
                pOam->stage = 4;
            }
        }
        else if (pOam->stage == 4)
        {
            if (pOam->timer == 60)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->stage = 5;
            }
        }
        else if (pOam->stage == 5)
        {
            pOam->pOam = sIntroInSr388SamusOam_WalkingLeft;
            
            if (gBg2XPosition > 40)
            {
                INTRO_DATA.unk_216 = -1;
                
                if (gBg2XPosition == 56)
                    NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_HORNOAD, 0, 128);
            }
            else
            {
                INTRO_DATA.unk_216 = 0;
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_IdleLeft;
                pOam->stage = 6;
            }
        }
        else if (pOam->stage == 6)
        {
            if (pOam->timer == 30)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_TurningRight;
                pOam->stage = 7;
            }
        }
        else if (pOam->stage == 7)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_IdleRight;
                pOam->stage = 8;
            }
        }
        else if (pOam->stage == 8)
        {
            if (pOam->timer == 30)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_TurningLeft;
                pOam->stage = 9;
            }
        }
        else if (pOam->stage == 9)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_IdleLeft;
                pOam->stage = 10;
            }
        }
        else if (pOam->stage == 10)
        {
            if (pOam->timer == 30)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_WalkingLeft;
                pOam->stage = 11;
            }
        }
        else if (pOam->stage == 11)
        {
            pOam->pOam = sIntroInSr388SamusOam_WalkingLeft;
            
            if (pOam->timer == 1)
            {
                if (gBg2XPosition != 0)
                {
                    INTRO_DATA.unk_216 = -1;
                }
                else
                {
                    INTRO_DATA.unk_216 = 0;
                    pOam->timer = 0;
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame = 0;
                    pOam->pOam = sIntroInSr388SamusOam_IdleLeft;
                    INTRO_DATA.subStage = 4;
                    pOam->stage = 0;
                }
            }
            else
            {
                pOam->timer = 0;
                INTRO_DATA.unk_216 = 0;
            }
        }
    }
    else if (INTRO_DATA.subStage == 4)
    {
        if (pOam->stage == 0)
        {
            if (pOam->timer == 60)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_MissileArmedLeft;
                pOam->stage = 1;
            }
        }
        else if (pOam->stage == 1)
        {
            if (pOam->timer == 60)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_FiringMissileLeft;
                
                NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_HORIZONTAL_MISSILE, pOam->xPosition - 20, pOam->yPosition - 22);
                
                pOam->stage = 2;
            }
        }
        else if (pOam->stage == 2)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_MissileArmedLeft;
                pOam->stage = 3;
            }
        }
        else if (pOam->stage == 3)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_HORIZONTAL_MISSILE, &x, &y);
            
            if (x == 300)
            {
                pOam->timer = 0;
                pOam->stage = 4;
            }
        }
        else if (pOam->stage == 4)
        {
            if (pOam->timer == 8)
            {
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_MissileArmedUpLeft;
                return;
            }
            else if (pOam->timer == 10)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_FiringMissileUpLeft;
                
                NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_FIRST_DIAGONAL_MISSILE, pOam->xPosition - 20, pOam->yPosition - 40);
                
                pOam->stage = 5;
            }
        }
        else if (pOam->stage == 5)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_MissileArmedUpLeft;
                pOam->stage = 6;
            }
        }
        else if (pOam->stage == 6)
        {
            if (pOam->timer == 130)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_FiringMissileUpLeft;
                
                NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_SECOND_DIAGONAL_MISSILE, pOam->xPosition - 20, pOam->yPosition - 40);
                
                pOam->stage = 7;
            }
        }
        else if (pOam->stage == 7)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_MissileArmedUpLeft;
                pOam->stage = 8;
            }   
        }
        else if (pOam->stage == 8)
        {
            if (pOam->timer == 78)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_FiringMissileUpLeft;
                
                NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_SECOND_DIAGONAL_MISSILE, pOam->xPosition - 20, pOam->yPosition - 40);
                
                pOam->stage = 9;
            }
        }
        else if (pOam->stage == 9)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388SamusOam_MissileArmedUpLeft;
                pOam->stage = 10;
            }
        }
    }
    else if (INTRO_DATA.subStage > 4)
    {
        pOam->animationDurationCounter = 0;
    }
}

 /**
 * @brief 8b240 | 20c | Processes the left BSL guy in the 'hornoad encounter in SR388' cutscene
 * 
 */
void NewfileIntroProcessLeftBiologicalResearcher(struct SpecialCutsceneOam *pOam)
{
    const struct FrameData* frame;
    s16 x;
    s16 y;

    pOam->timer++;
    
    if (INTRO_DATA.subStage == 0)
    {
        if (gBg2YPosition > 47)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            pOam->xPosition = x + pOam->unk_8;
            pOam->yPosition = y;
        }
        
        pOam->timer = 0;
        pOam->stage = 20;
    }
    else if (INTRO_DATA.subStage == 1 || INTRO_DATA.subStage == 2)
    {
        NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
        
        pOam->xPosition = x + pOam->unk_8;
        pOam->yPosition = y;
        pOam->stage = 20;
    }
    else if (INTRO_DATA.subStage == 3)
    {
        if (pOam->stage == 16)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            if (pOam->xPosition < x)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->stage = 17;
            }
        }
        else if (pOam->stage == 17)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            if (pOam->xPosition > x + 10)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Turning;
                pOam->stage = 18;
            }
        }
        else if (pOam->stage == 18)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Idle;
                pOam->stage = 19;
            }
        }
        else if (pOam->stage == 19)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            if (pOam->xPosition > x + pOam->unk_8)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Walking;
                pOam->stage = 20;
            }
        }
        else if (pOam->stage == 20)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            if (pOam->xPosition <= x + pOam->unk_8 - 7)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Idle;
                pOam->stage = 21;
            }
            else
            {
                pOam->xPosition--;
            }
        }
        else if (pOam->stage == 21)
        {
            if (gBg2XPosition < 98)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Walking;
                pOam->stage = 22;
            }
        }
        else if (pOam->stage == 22)
        {
            if (gBg2XPosition > 45)
            {
                pOam->xPosition--;
            }
            else
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Idle;
                pOam->stage = 23;
            }
        }
    }
    else if (INTRO_DATA.subStage == 4)
    {
        pOam->timer = 0;
    }
    else if (INTRO_DATA.subStage > 4)
    {
        pOam->animationDurationCounter = 0;
    }
    
    pOam->xPosition -= INTRO_DATA.unk_216;
}

 /**
 * @brief 8b44c | 214 | Processes the right BSL guy in the 'hornoad encounter in SR388' cutscene
 * 
 */
void NewfileIntroProcessRightBiologicalResearcher(struct SpecialCutsceneOam *pOam)
{
    const struct FrameData* frame;
    s16 x;
    s16 y;

    pOam->timer++;
    
    if (INTRO_DATA.subStage == 0)
    {
        if (gBg2YPosition > 47)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            pOam->xPosition = x + pOam->unk_8;
            pOam->yPosition = y;
        }
        
        pOam->timer = 0;
        pOam->stage = 20;
    }
    else if (INTRO_DATA.subStage == 1 || INTRO_DATA.subStage == 2)
    {
        NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
        
        pOam->xPosition = x + pOam->unk_8;
        pOam->yPosition = y;
        pOam->stage = 20;
    }
    else if (INTRO_DATA.subStage == 3)
    {
        if (pOam->stage == 16)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            if (pOam->xPosition < x)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->stage = 17;
            }
        }
        else if (pOam->stage == 17)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            if (pOam->xPosition > x + 10)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Turning;
                pOam->stage = 18;
            }
        }
        else if (pOam->stage == 18)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Idle;
                pOam->stage = 19;
            }
        }
        else if (pOam->stage == 19)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            if (pOam->xPosition > x + pOam->unk_8 + 10)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Walking;
                pOam->stage = 20;
            }
        }
        else if (pOam->stage == 20)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);
            
            if (pOam->xPosition <= x + pOam->unk_8 - 10)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Idle;
                pOam->stage = 21;
            }
            else
            {
                pOam->xPosition--;
            }
        }
        else if (pOam->stage == 21)
        {
            if (gBg2XPosition < 103)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Walking;
                pOam->stage = 22;
            }
        }
        else if (pOam->stage == 22)
        {
            if (gBg2XPosition > 52)
            {
                pOam->xPosition--;
            }
            else
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388BslResearcherOam_Idle;
                pOam->stage = 23;
            }
        }
    }
    else if (INTRO_DATA.subStage == 4)
    {
        pOam->timer = 0;
    }
    else if (INTRO_DATA.subStage > 4)
    {
        pOam->animationDurationCounter = 0;
    }
    
    pOam->xPosition -= INTRO_DATA.unk_216;
}

 /**
 * @brief 8b660 | 174 | Processes the hornoad in the SR388 cutscene (unused?)
 * 
 */
void unk_8b660(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;
    u32 timer;
    u8 tmp;
    s16 y;
    
    pOam->timer++;

    if (pOam->stage == 0)
    {
        pOam->spawnY = pOam-> yPosition;
        pOam->unk_4 = 0;
        pOam->pOam = sIntroInSr388HornoadOam_IdleUnused;

        if (pOam->timer == 4)
        {
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->pOam = sIntroInSr388HornoadOam_JumpingUnused;

        if (pOam->unk_8 == 0)
        {
            timer = pOam->timer;
            y = sHornoadJumpVelocityHigh[pOam->unk_4] * timer >> 2;
        }
        else
        {
            timer = pOam->timer;
            tmp = timer; // From permuter
            y = sHornoadJumpVelocityLow[pOam->unk_4] * tmp >> 2;
        }
        
        pOam->yPosition = pOam->spawnY + y;
        if (pOam->yPosition > 144)
        {
            pOam->yPosition = 144;
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroInSr388HornoadOam_BouncingUnused;
            pOam->stage = 2;
        }

        if (y < 0)
            pOam->xPosition += 2;
        else
            pOam->xPosition += 1;

        if (pOam->animationDurationCounter == 4 && pOam->currentAnimationFrame == 2)
            pOam->xPosition += 8;

        if (pOam->timer == 4)
        {
            pOam->timer = 0;
            pOam->spawnY = pOam->yPosition;
            pOam->unk_4++;

            if (pOam->unk_4 == 10)
                pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            pOam->animationDurationCounter = 0;

        if (pOam->timer == sArray_59db00[pOam->unk_A])
        {
            pOam->unk_A++;
            if (pOam->unk_A == 6)
                pOam->unk_A = 0;

            if (!pOam->unk_8)
                pOam->unk_8 = 1;
            else
                pOam->unk_8 = 0;

            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->stage = 0;
        }
    }

    pOam->xPosition -= INTRO_DATA.unk_216;
    if (pOam->xPosition > 260)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 8b7d4 | 4c8 | Processes the hornoad in the SR388 cutscene
 * 
 */
void NewFileIntroProcessHornoad(struct SpecialCutsceneOam *pOam)
{
    const struct FrameData* frame;
    s16 var0;
    s16 var1;
    s32 var2;
    s32 spawnY;
    s32 xPos;
    s16 x;
    s16 y;

    pOam->timer++;

    if (pOam->stage == 0)
    {
        pOam->spawnY = pOam->yPosition;

        if (pOam->timer == 150)
        {
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroInSr388HornoadOam_Chomping;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->spawnY = pOam->yPosition;

        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroInSr388HornoadOam_Chomping;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_HORIZONTAL_MISSILE, &x, &y);

        pOam->spawnY = pOam->yPosition;

        if (x - pOam->xPosition < 25)
        {
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroInSr388HornoadOam_Biting;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        pOam->pOam = sIntroInSr388HornoadOam_Jumping;

        var0 = pOam->timer * sHornoadJumpVelocityHigh[pOam->unk_4] >> 2;
        var2 = var0 + (u16)pOam->spawnY;
        pOam->yPosition = var2;

        if (pOam->timer == 4)
        {
            pOam->timer = 0;
            pOam->spawnY = var2;

            pOam->unk_4++;
            if (pOam->unk_4 == 5)
            {
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388HornoadOam_MidAir;
            }
            else if (pOam->unk_4 > 10)
            {
                pOam->unk_4 = 10;
            }
        }

        if (pOam->yPosition > 128)
        {
            pOam->spawnY = 128;
            pOam->yPosition = 128;
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroInSr388HornoadOam_Bouncing;
            pOam->unk_4 = 0;
            pOam->stage = 4;
        }
    }
    else if (pOam->stage == 4)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroInSr388HornoadOam_Panting;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 5)
    {
        NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_HORIZONTAL_MISSILE, &x, &y);

        if (x == 300)
        {
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroInSr388HornoadOam_Biting;
            pOam->stage = 6;
        }
    }
    else if (pOam->stage == 6)
    {
        pOam->pOam = sIntroInSr388HornoadOam_Jumping;

        var0 = pOam->timer * sHornoadJumpVelocityHigh[pOam->unk_4] >> 1;
        do { pOam->spawnY += 0; } while (0);
        spawnY = (u16)pOam->spawnY;
        var2 = var0;
        pOam->yPosition = var2 + spawnY;
        pOam->xPosition++;

        if (pOam->currentAnimationFrame == 2 && pOam->animationDurationCounter == 4)
        {
            xPos = (u16)pOam->xPosition;
            xPos += 8;
            pOam->xPosition = xPos;
        }
        else
        {
            var0 += 0;
        }

        if (pOam->timer == 4)
        {
            pOam->timer = 0;
            pOam->spawnY = pOam->yPosition;

            pOam->unk_4++;
            if (pOam->unk_4 == 5)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388HornoadOam_MidAir;
            }
            else if (pOam->unk_4 > 10)
            {
                pOam->unk_4 = 10;
            }
        }

        if (pOam->unk_4 > 1)
        {
            NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_FIRST_DIAGONAL_MISSILE, &x, &y);

            if (pOam->xPosition >= x && pOam->yPosition >= y)
            {
                NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_MISSILE_EXPLOSION_BIG, pOam->xPosition, pOam->yPosition);

                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388HornoadOam_Shaking;
                pOam->unk_4 = 1;
                WRITE_16(REG_MOSAIC, sXParasiteMosaicValues[1] * 16);
                pOam->unk_18_5 = 1;
                pOam->stage = 7;
            }
        }
    }
    else if (pOam->stage == 7)
    {
        if (pOam->timer == 2)
        {
            pOam->timer = 0;
            pOam->unk_4++;
            WRITE_16(REG_MOSAIC, sXParasiteMosaicValues[pOam->unk_4] * 16);
        }

        if (pOam->unk_A == 1)
        {
            if (pOam->unk_4 == 15)
            {
                pOam->timer = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroInSr388XParasiteOam_Floating;
                pOam->xPosition -= 4;
                pOam->yPosition -= 10;
                pOam->unk_A = 0;
                pOam->stage = 8;
            }
        }
        else
        {
            if (pOam->unk_4 == 29)
            {
                pOam->unk_A++;
                pOam->unk_4 = 1;
            }
        }
    }
    else if (pOam->stage == 8)
    {
        if (pOam->timer == 2)
        {
            pOam->timer = 0;
            pOam->unk_4++;
            WRITE_16(REG_MOSAIC, sXParasiteMosaicValues[pOam->unk_4] * 16);
        }

        if (pOam->unk_A == 1)
        {
            if (pOam->unk_4 == 29)
            {
                pOam->timer = 0;
                pOam->unk_18_5 = 0;

                NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_SAMUS, &x, &y);

                pOam->spawnY = pOam->yPosition;
                pOam->spawnX = x;
                pOam->unk_4 = x - pOam->xPosition;
                pOam->unk_A = 63;
                pOam->stage = 9;
            }
        }
        else
        {
            if (pOam->unk_4 == 29)
            {
                pOam->unk_A++;
                pOam->unk_4 = 1;
            }
        }
    }
    else if (pOam->stage == 9)
    {
        if (pOam->timer != 10)
        {
            if (pOam->timer > 30)
            {
                pOam->timer = 0;
                pOam->stage = 10;
            }
        }
    }
    else if (pOam->stage == 10)
    {
        pOam->unk_A++;
        if (pOam->unk_A > 255)
            pOam->unk_A -= 256;

        var0 = pOam->unk_A;
        var1 = pOam->unk_A * 2;
        if (var1 > 255)
            var1 -= 256;

        pOam->xPosition = pOam->spawnX + ((pOam->unk_4 * COS(var1) * SIN(var0)) >> 16);
        pOam->yPosition = pOam->spawnY + ((pOam->unk_4 * COS(var1) * COS(var0)) >> 16);

        if (pOam->unk_A > 159)
        {
            pOam->unk_A = 0;
            pOam->timer = 0;
            pOam->unk_4 = 0;
            pOam->spawnY = 0;
            pOam->spawnX = 0;
            pOam->stage = 11;
        }
        else if (pOam->unk_A > 155)
        {
            pOam->spawnX--;
            pOam->spawnY++;
        }
        else if (pOam->unk_A > 119)
        {
            pOam->spawnY++;
        }
    }
    else if (pOam->stage == 11)
    {
        pOam->affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;

        pOam->scaling += Q_8_8(0.5f);
        if (pOam->scaling >= Q_8_8(2))
            pOam->stage = 12;
    }
    else if (pOam->stage == 12)
    {
        pOam->scaling -= Q_8_8(1.f / 16);
        if (pOam->scaling <= Q_8_8(0.56f))
        {
            INTRO_DATA.subStage = 5;
            pOam->stage = 13;
        }
    }
    else if (pOam->stage == 13)
    {
        pOam->animationDurationCounter = 0;
    }

    pOam->xPosition -= INTRO_DATA.unk_216;
}

 /**
 * @brief 8bc9c | b4 | Processes the horizontal missile in the 'hornoad encounter in SR388' cutscene
 * 
 */
void NewFileIntroProcessHorizontalMissile(struct SpecialCutsceneOam *pOam)
{
    const struct FrameData* frame;

    pOam->timer++;
    
    if (pOam->stage == 0)
    {
        pOam->xPosition = pOam->spawnX - (pOam->timer * sNormalMissileVelocity[pOam->unk_4] >> 2);
        
        if (pOam->timer == 4)
        {
            pOam->timer = 0;
            
            if (pOam->unk_4 < 6)
                pOam->unk_4++;
            
            pOam->spawnX = pOam->xPosition;
        }
        else if (pOam->timer == 1)
        {
            NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_MISSILE_TRAIL, pOam->xPosition + 12, pOam->yPosition + 2);
        }
        
        if (pOam->xPosition < 32)
        {
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroInSr388MissileExplosionOam_Small;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

 /**
 * @brief 8bd50 | c8 | Processes the first diagonal missile in the 'hornoad encounter in SR388' cutscene
 * 
 */
void NewFileIntroProcessFirstDiagonalMissile(struct SpecialCutsceneOam *pOam)
{
    const struct FrameData* frame;
    s16 x;
    s16 y;

    pOam->timer++;
    
    if (pOam->stage == 0)
    {
        pOam->xPosition = pOam->spawnX - (pOam->timer * (sNormalMissileVelocity[pOam->unk_4] + 1) >> 2);
        pOam->yPosition = pOam->spawnY - (pOam->timer * (sNormalMissileVelocity[pOam->unk_4] + 1) >> 2);
        
        if (pOam->timer == 4)
        {
            pOam->timer = 0;
            
            if (pOam->unk_4 < 6)
                pOam->unk_4++;
            
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
        }
        else if (pOam->timer == 1)
        {
            NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_MISSILE_TRAIL, pOam->xPosition + 10, pOam->yPosition + 12);
        }

        NewFileIntroGetPositionOfOamByType(INTRO_IN_SR388_OAM_TYPE_HORNOAD, &x, &y);

        if (pOam->xPosition <= x - 2 && pOam->yPosition <= y - 2)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

 /**
 * @brief 8be18 | 2c | To document
 * 
 */
void unk_8be18(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;
    
    frame = &pOam->pOam[pOam->currentAnimationFrame];
    if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 8be44 | d8 | To document
 * 
 */
void unk_8be44(struct SpecialCutsceneOam *pOam)
{
    if (pOam->stage == 0)
    {
        pOam->yPosition = gBg2YPosition;
        pOam->xPosition = gBg2XPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        if (pOam->yPosition + 1 < gBg2YPosition)
        {
            pOam->yPosition = gBg2YPosition;
            gBg3YPosition++;
        }
        
        if (pOam->xPosition - 1 > gBg2XPosition)
        {
            pOam->xPosition = gBg2XPosition;
            gBg3XPosition--;
        }
    }
    
    if (pOam->unk_4 == 0)
    {
        gBg1XPosition = gBg2XPosition + 256;
        gBg1YPosition = gBg2YPosition - 96;
        
        if (gBg1XPosition < 120)
        {
            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG1);
            WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
            
            gWrittenToBldalpha_Eva = gWrittenToBldalpha_Evb = 0;
            pOam->unk_4 = 1;
        }
    }
    
    if (gBg2XPosition == 0)
        pOam->type = 0;
}

 /**
 * @brief 8bf1c | 4c | To document
 * 
 */
void unk_8bf1c(struct SpecialCutsceneOam* pOam)
{
    if (gBg2YPosition > 23)
        pOam->yPosition = 216 - gBg2YPosition;

    pOam->xPosition -= INTRO_DATA.unk_216;
    if (pOam->xPosition > 302)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 8bf68 | 48 | To document
 * 
 */
void unk_8bf68(struct SpecialCutsceneOam* pOam)
{
    if (gBg2YPosition > 23)
        pOam->yPosition = 216 - gBg2YPosition;

    pOam->xPosition -= INTRO_DATA.unk_216;
    if (pOam->xPosition > 250)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 8bfb0 | d4 | Processes the second and subsequent diagonal missiles in the 'hornoad encounter in SR388' cutscene
 * 
 */
void NewFileIntroProcessSecondDiagonalMissile(struct SpecialCutsceneOam *pOam)
{
    const struct FrameData* frame;

    pOam->timer++;
    
    if (pOam->stage == 0)
    {
        pOam->xPosition = pOam->spawnX - (pOam->timer * (sNormalMissileVelocity[pOam->unk_4] + 1) >> 2);
        pOam->yPosition = pOam->spawnY - (pOam->timer * (sNormalMissileVelocity[pOam->unk_4] + 1) >> 2);
        
        if (pOam->timer == 4)
        {
            pOam->timer = 0;
            
            if (pOam->unk_4 < 6)
                pOam->unk_4++;
            
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
        }
        else if (pOam->timer == 1)
        {
            NewFileIntroInSr388SetupOam(INTRO_IN_SR388_OAM_TYPE_MISSILE_TRAIL, pOam->xPosition + 10, pOam->yPosition + 12);
        }
        
        if (pOam->yPosition < 50)
        {
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroInSr388MissileExplosionOam_Small;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

 /**
 * @brief 8c084 | 8 | To document
 * 
 */
void unk_8c084(struct SpecialCutsceneOam* pOam)
{
    pOam->type = 0;
}

 /**
 * @brief 8c08c | 478 | Spawns an object for the 'hornoad encounter in SR388' cutscene
 * 
 */
u8 NewFileIntroInSr388SetupOam(IntroInSr388OamType type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == 0)
            break;
    }

    if (slot > 19)
        return 20;
    
    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));

    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;

    if (type == INTRO_IN_SR388_OAM_TYPE_SAMUS)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388SamusOam_WalkingLeft;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusInSr388;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_LEFT_RESEARCHER)
    {
        INTRO_DATA.oam[slot].unk_8 = 38;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388BslResearcherOam_Walking;
        INTRO_DATA.oam[slot].pFunction = NewfileIntroProcessLeftBiologicalResearcher;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_RIGHT_RESEARCHER)
    {
        INTRO_DATA.oam[slot].unk_8 = 72;
        INTRO_DATA.oam[slot].currentAnimationFrame = 1;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388BslResearcherOam_Walking;
        INTRO_DATA.oam[slot].pFunction = NewfileIntroProcessRightBiologicalResearcher;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_HORNOAD_UNUSED)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388HornoadOam_IdleUnused;
        INTRO_DATA.oam[slot].pFunction = unk_8b660;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_HORNOAD_UNUSED_2)
    {
        INTRO_DATA.oam[slot].unk_8 = 1;
        INTRO_DATA.oam[slot].unk_A = 2;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388HornoadOam_IdleUnused;
        INTRO_DATA.oam[slot].pFunction = unk_8b660;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_HORIZONTAL_MISSILE)
    {
        INTRO_DATA.oam[slot].spawnX = xPosition;
        INTRO_DATA.oam[slot].spawnY = yPosition;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388MissileOam_Horizontal;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessHorizontalMissile;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_FIRST_DIAGONAL_MISSILE)
    {
        INTRO_DATA.oam[slot].spawnX = xPosition;
        INTRO_DATA.oam[slot].spawnY = yPosition;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388MissileOam_Diagonal;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessFirstDiagonalMissile;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_MISSILE_TRAIL)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388MissileTrailOam;
        INTRO_DATA.oam[slot].pFunction = unk_8be18;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_HORNOAD)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388HornoadOam_Panting;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessHornoad;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_MISSILE_EXPLOSION_BIG)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388MissileExplosionOam_Big;
        INTRO_DATA.oam[slot].pFunction = unk_8be18;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_UNK_11)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_8be44;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_CAVE_ENTRANCE_BG)
    {
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388CaveEntranceBgOam;
        INTRO_DATA.oam[slot].pFunction = unk_8bf1c;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_BLACK_RECTANGLE)
    {
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388BlackRectangeOam;
        INTRO_DATA.oam[slot].pFunction = unk_8bf68;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_SECOND_DIAGONAL_MISSILE)
    {
        INTRO_DATA.oam[slot].spawnX = xPosition;
        INTRO_DATA.oam[slot].spawnY = yPosition;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroInSr388MissileOam_Diagonal;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSecondDiagonalMissile;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_NEXT_PAGE_ARROW)
    {
        INTRO_DATA.oam[slot].pOam = sIntroNextPageArrowOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessTextCursor;
    }
    else if (type == INTRO_IN_SR388_OAM_TYPE_UNK_255)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_8c084;
    }

    return slot;
}

 /**
 * @brief 8c504 | 38 | To document
 * 
 */
void unk_8c504(IntroInSr388OamType type, s16 xPosition, s16 yPosition, u16 arg3)
{
    u8 slot;
    
    slot = NewFileIntroInSr388SetupOam(type, xPosition, yPosition);
    INTRO_DATA.oam[slot].unk_8 = arg3;
}

 /**
 * @brief 8c53c | 4 | Empty function
 * 
 */
void NewFileIntro_Empty(void)
{
    return;
}

 /**
 * @brief 8c540 | 54 | Returns the X and Y position of a new file intro OAM
 * 
 */
void NewFileIntroGetPositionOfOamByType(IntroInSr388OamType type, s16* pXPosition, s16* pYPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == type)
        {
            *pXPosition = INTRO_DATA.oam[slot].xPosition;
            *pYPosition = INTRO_DATA.oam[slot].yPosition;
            
            return;
        }
    }

    // Default values if not found
    *pXPosition = 300;
    *pYPosition = 200;
}

 /**
 * @brief 8c594 | dc | V-blank for the 'hornoad encounter in SR388' cutscene
 * 
 */
void NewFileIntroInSr388Vblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    WRITE_16(REG_BLDY, gWrittenToBldy);

    WRITE_16(REG_BG1HOFS, gBg1XPosition);
    WRITE_16(REG_BG1VOFS, gBg1YPosition);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);

    if (INTRO_DATA.unk_110 == 1)
    {
        INTRO_DATA.unk_110 = 0;

        DMA3_COPY_32(sPal_5a9440, PALRAM_OBJ, 15 * PAL_ROW_SIZE / sizeof(u32));
        DMA3_COPY_32(sPal_5a9260, PALRAM_BASE, 15 * PAL_ROW_SIZE / sizeof(u32));
    }
}

 /**
 * @brief 8c670 | 204 | Setup for the new file intro Metroid vaccine cutscene
 * 
 */
void NewFileIntroSamusGettingCuredInit(void)
{
    const u16* pText2;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    pText2 = INTRO_DATA.pText2; // Preserve second text pointer
    
    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    INTRO_DATA.pText2 = pText2;

    LZ77UncompVram(sIntroMetroidVaccineObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sIntroMetroidVaccineObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sIntroMetroidVaccineBgGfx, VRAM_BASE);
    LZ77UncompVram(sIntroMetroidVaccineBg1Tilemap, VRAM_BASE + 0xE800);
    LZ77UncompVram(sIntroMetroidVaccineBg2Tilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroMetroidVaccineBg3Tilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroMetroidVaccineBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 29, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
    
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_NEXT_PAGE_ARROW, 260, 0);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_DOUBLE_HELIX, 192, 96);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_VACCINE_BG_TEXT, 0, 0);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(NewFileIntroSamusGettingCuredVblank);
}

 /**
 * @brief 8c874 | 158 | Processes the new file intro Metroid vaccine cutscene
 * 
 */
boolu32 NewFileIntroSamusGettingCuredOperationProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
        INTRO_DATA.unk_218 = 1;

    INTRO_DATA.timer++;
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1))
            {
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = INTRO_DATA.pText2;
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(2 + 2.f / 3))
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(3))
            {
                NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_VACCINE_TEXTBOXES, 108, 64);
                NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_ELECTROCARDIOGRAM, 128, 68);
            }
            else if (INTRO_DATA.timer > CONVERT_SECONDS(6 + 2.f / 3))
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 1;
            }
        
            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
                INTRO_DATA.unk_218 = 0;
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 1:
            INTRO_DATA.timer = 0;

            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 2;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 2:
            if (INTRO_DATA.timer == CONVERT_SECONDS(.5f))
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
                INTRO_DATA.subStage = 3;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy += 2;
            }
            else
            {
                gWrittenToBldy = BLDY_MAX_VALUE;
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
                finished = TRUE;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    IntroProcessText();
    
    return finished;
}

 /**
 * @brief 8c9cc | 20 | H-blank code for the new file intro Samus nervous system cutscene
 * 
 */
void NewFileIntroSamusGettingCuredNervousSystemHblank(void)
{
    s16 val;

    val = READ_16(REG_VCOUNT) * 2; // * 2, / 2 shenanigans are needed for match
    WRITE_16(REG_WIN0H, ((u16*)(EWRAM_BASE + 0x2000))[val / 2]);
}

 /**
 * @brief 8c9ec | 320 | Setup for the new file intro Samus nervous system cutscene
 * 
 */
void NewFileIntroSamusGettingCuredNervousSystemInit(void)
{
    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));

    INTRO_DATA.unk_218 = 0;

    LZ77UncompVram(sIntroSamusNervousSystemObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sIntroSamusNervousSystemObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sIntroSamusNervousSystemBgGfx, VRAM_BASE);
    LZ77UncompVram(sIntroSamusNervousSystemBg1Tilemap, VRAM_BASE + 0xE800);
    LZ77UncompVram(sIntroSamusNervousSystemBg2Tilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusNervousSystemBg3Tilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroSamusNervousSystemBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    SET_BACKDROP_COLOR(COLOR_GREEN);

    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 29, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);

    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Evb = gWrittenToBldalpha_Eva = 0;

    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_NEXT_PAGE_ARROW, 260, 0);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_10, 0, 0);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_10, 0, 0);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_10, 0, 0);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_10, 0, 0);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_10, 0, 0);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_10, 0, 0);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_10, 0, 0);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_CORNER_TEXT, 172, 158);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_NERVE_PARTS, 120, 80);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_1, 195, 97);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_2, 128, 128);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_3, 145, 28);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_4, 100, 72);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_5, 44, 30);
    NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_6, 62, 121);

    INTRO_DATA.unk_110 = 0;
    INTRO_DATA.unk_111 = 0;

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_WIN0V, C_16_2_8(0, SCREEN_SIZE_Y));

    INTRO_DATA.unk_1F3 = 70;
    INTRO_DATA.unk_1F4 = 120;
    INTRO_DATA.unk_1F5 = 78;

    NewFileIntroSamusGettingCuredSetupWindow();
    NewFileIntroSamusGettingCuredSetupWindow();

    DMA3_COPY_32(NewFileIntroSamusGettingCuredNervousSystemHblank, INTRO_DATA.hBlankCode, sizeof(INTRO_DATA.hBlankCode) / sizeof(u32));
    INTRO_DATA.hBlankCodePointer = INTRO_DATA.hBlankCode + 1;
    CallbackSetHBlank(INTRO_DATA.hBlankCodePointer);

    WRITE_16(REG_IE, READ_16(REG_IE) | IF_HBLANK);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) | DSTAT_IF_HBLANK);
    WRITE_16(REG_WININ, WIN0_BG0 | WIN0_BG1 | WIN0_BG3 | WIN0_OBJ | WIN0_COLOR_EFFECT);
    WRITE_16(REG_WINOUT, WIN0_ALL);
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
    WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_WIN0);
    
    CallbackSetVBlank(NewFileIntroSamusGettingCuredNervousSystemVblank);
}

 /**
 * @brief 8cd0c | 274 | Processes the new file intro Samus nervous system cutscene
 * 
 */
boolu32 NewFileIntroSamusGettingCuredNervousSystemProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && !INTRO_DATA.unk_218)
        INTRO_DATA.unk_218 = 1;

    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);

    switch (INTRO_DATA.subStage)
    {
        case 0:
            NewFileIntroSamusGettingCuredNervousSystemInit();
            INTRO_DATA.subStage = 1;
            break;
        
        case 1:
            if (gWrittenToBldy)
            {
                gWrittenToBldy -= 2;
            }
            else
            {
                gWrittenToBldy = 0;
                INTRO_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL 
                         | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
                INTRO_DATA.subStage = 2;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 2:
            if (gWrittenToBldalpha_Eva < 12)
            {
                gWrittenToBldalpha_Eva++;
                gWrittenToBldalpha_Evb++;
            }
            else
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 3;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 3:
            if (INTRO_DATA.timer == CONVERT_SECONDS(.5f))
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][16];
                INTRO_DATA.subStage = 4;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 4:
            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 2)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.pText2 = INTRO_DATA.pText;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 5;
            }
            else if (INTRO_DATA.unk_218 == 4)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG0);
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 5;
                INTRO_DATA.pText2 = INTRO_DATA.pText;
                INTRO_DATA.pText = sCutsceneTextNone;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 5:
            if (INTRO_DATA.timer == DELTA_TIME)
            {
                NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_28, 0, 0);
            }
            else if (INTRO_DATA.timer > CONVERT_SECONDS(7.5f))
            {
                INTRO_DATA.timer = 0;
                gWrittenToBldy = 4;
                INTRO_DATA.subStage = 7;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 6:
            if (gWrittenToBldalpha_Eva)
            {
                gWrittenToBldalpha_Eva -= 2;
                gWrittenToBldalpha_Evb -= 2;
            }
            else
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                INTRO_DATA.subStage = 7;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 7:
            WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
            
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy += 2;
            }
            else
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
                finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    IntroProcessText();
    
    return finished;
}

 /**
 * @brief 8cf80 | dc | Main handler for the new file intro Samus getting cured cutscenes
 * 
 */
boolu32 NewFileIntroSamusGettingCured(void)
{
    boolu32 finished;

    finished = FALSE;
    
    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSamusGettingCuredInit();
            INTRO_DATA.stage = 1;
            break;

        case 1:
            SpecialCutsceneFadeIn();

            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusGettingCuredOperationProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;

        case 3:
            if (NewFileIntroSamusGettingCuredNervousSystemProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 4;
            }
            break;

        case 4:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                INTRO_DATA.stage = 0;
                finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

 /**
 * @brief 8d05c | 10 | Processes the new file intro Metroid vaccine background text OAM
 * 
 */
void NewFileIntroProcessVaccineBackgroundText(struct SpecialCutsceneOam* pOam)
{
    WRITE_16(REG_BG2VOFS, pOam->yPosition--);
}

 /**
 * @brief 8d06c | 10 | To document
 * 
 */
void unk_8d06c(struct SpecialCutsceneOam* pOam)
{
    pOam->type = 0;
    pOam->unk_18_0 = 0;
}

 /**
 * @brief 8d07c | e0 | Processes the first X parasite in the Samus nervous system cutscene
 * 
 */
void NewFileIntroProcessXInNervousSystem_1(struct SpecialCutsceneOam *pOam)
{
    u8 rng;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }

    rng = SpecialCutsceneGetRandomNumber();
    if (rng < 80)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->xPosition < pOam->spawnX)
                pOam->xPosition++;
        }
        else if (pOam->xPosition > pOam->spawnX - 4)
        {
            pOam->xPosition--;
        }
    }
    else if (rng < 160)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->yPosition < pOam->spawnY + 5)
                pOam->yPosition++;
        }
        else if (pOam->yPosition > pOam->spawnY)
        {
            pOam->yPosition--;
        }
    }
    
    if (INTRO_DATA.subStage == 5)
    {
        pOam->unk_A++;
        if (pOam->unk_A == 20)
        {
            NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_1, pOam->xPosition, pOam->yPosition);
        }
        else if (pOam->unk_A > 220)
        {
            pOam->scaling -= 2;
            if (pOam->scaling < Q_8_8(1.f/ 8))
            {
                pOam->type = 0;
                pOam->unk_18_0 = 0;
            }
        }
    }
}

 /**
 * @brief 8d15c | 6c | Processes the new file intro X lock-on OAM
 * 
 */
void NewFileIntroProcessXLockOn(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;
    
    if (INTRO_DATA.oam[pOam->unk_8].type != 0)
    {
        pOam->xPosition = INTRO_DATA.oam[pOam->unk_8].xPosition;
        pOam->yPosition = INTRO_DATA.oam[pOam->unk_8].yPosition;
    }

    frame = &pOam->pOam[pOam->currentAnimationFrame];
    if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 8d1c8 | e4 | Processes the second X parasite in the Samus nervous system cutscene
 * 
 */
void NewFileIntroProcessXInNervousSystem_2(struct SpecialCutsceneOam *pOam)
{
    u8 rng;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }

    rng = SpecialCutsceneGetRandomNumber();
    if (rng < 80)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->xPosition < pOam->spawnX + 4)
                pOam->xPosition++;
        }
        else if (pOam->xPosition > pOam->spawnX - 4)
        {
            pOam->xPosition--;
        }
    }
    else if (rng < 160)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->yPosition < pOam->spawnY + 4)
                pOam->yPosition++;
        }
        else if (pOam->yPosition > pOam->spawnY - 4)
        {
            pOam->yPosition--;
        }
    }
    
    if (INTRO_DATA.subStage == 5)
    {
        pOam->unk_A++;
        if (pOam->unk_A == 20)
        {
            NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_2, pOam->xPosition, pOam->yPosition);
        }
        else if (pOam->unk_A > 220)
        {
            pOam->scaling -= 2;
            if (pOam->scaling < Q_8_8(1.f/ 8))
            {
                pOam->type = 0;
                pOam->unk_18_0 = 0;
            }
        }
    }
}

 /**
 * @brief 8d2ac | f0 | Processes the third X parasite in the Samus nervous system cutscene
 * 
 */
void NewFileIntroProcessXInNervousSystem_3(struct SpecialCutsceneOam *pOam)
{
    u8 rng;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }

    rng = SpecialCutsceneGetRandomNumber();
    if (rng < 80)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->xPosition < pOam->spawnX + 6)
                pOam->xPosition++;
        }
        else if (pOam->xPosition > pOam->spawnX - 1)
        {
            pOam->xPosition--;
        }
    }
    else if (rng < 160)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->yPosition < pOam->spawnY + 4)
                pOam->yPosition++;
        }
        else if (pOam->yPosition > pOam->spawnY - 3)
        {
            pOam->yPosition--;
        }
    }
    
    if (INTRO_DATA.subStage == 5)
    {
        pOam->unk_A++;
        if (pOam->unk_A == 40)
        {
            NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_3, pOam->xPosition, pOam->yPosition);
        }
        else if (pOam->unk_A > 240)
        {
            pOam->affineMode = OAM_AFFINE_MODE_AFFINE;
            pOam->scaling -= 2;
            if (pOam->scaling < Q_8_8(1.f/ 8))
            {
                pOam->type = 0;
                pOam->unk_18_0 = 0;
            }
        }
    }
}

 /**
 * @brief 8d39c | e4 | Processes the fourth X parasite in the Samus nervous system cutscene
 * 
 */
void NewFileIntroProcessXInNervousSystem_4(struct SpecialCutsceneOam *pOam)
{
    u8 rng;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }

    rng = SpecialCutsceneGetRandomNumber();
    if (rng < 80)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->xPosition < pOam->spawnX + 5)
                pOam->xPosition++;
        }
        else if (pOam->xPosition > pOam->spawnX - 5)
        {
            pOam->xPosition--;
        }
    }
    else if (rng < 160)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->yPosition < pOam->spawnY + 5)
                pOam->yPosition++;
        }
        else if (pOam->yPosition > pOam->spawnY - 5)
        {
            pOam->yPosition--;
        }
    }
    
    if (INTRO_DATA.subStage == 5)
    {
        pOam->unk_A++;
        if (pOam->unk_A == 40)
        {
            NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_4, pOam->xPosition, pOam->yPosition);
        }
        else if (pOam->unk_A > 240)
        {
            pOam->scaling -= 2;
            if (pOam->scaling < Q_8_8(1.f/ 8))
            {
                pOam->type = 0;
                pOam->unk_18_0 = 0;
            }
        }
    }
}

 /**
 * @brief 8d480 | f0 | Processes the fifth X parasite in the Samus nervous system cutscene
 * 
 */
void NewFileIntroProcessXInNervousSystem_5(struct SpecialCutsceneOam *pOam)
{
    u8 rng;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }

    rng = SpecialCutsceneGetRandomNumber();
    if (rng < 80)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->xPosition < pOam->spawnX + 5)
                pOam->xPosition++;
        }
        else if (pOam->xPosition > pOam->spawnX - 1)
        {
            pOam->xPosition--;
        }
    }
    else if (rng < 160)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->yPosition < pOam->spawnY + 4)
                pOam->yPosition++;
        }
        else if (pOam->yPosition > pOam->spawnY)
        {
            pOam->yPosition--;
        }
    }
    
    if (INTRO_DATA.subStage == 5)
    {
        pOam->unk_A++;
        if (pOam->unk_A == 60)
        {
            NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_5, pOam->xPosition, pOam->yPosition);
        }
        else if (pOam->unk_A > 260)
        {
            pOam->affineMode = OAM_AFFINE_MODE_AFFINE;
            pOam->scaling -= 2;
            if (pOam->scaling < Q_8_8(1.f/ 8))
            {
                pOam->type = 0;
                pOam->unk_18_0 = 0;
            }
        }
    }
}

 /**
 * @brief 8d570 | f0 | Processes the sixth X parasite in the Samus nervous system cutscene
 * 
 */
void NewFileIntroProcessXInNervousSystem_6(struct SpecialCutsceneOam *pOam)
{
    u8 rng;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }

    rng = SpecialCutsceneGetRandomNumber();
    if (rng < 80)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->xPosition < pOam->spawnX + 5)
                pOam->xPosition++;
        }
        else if (pOam->xPosition > pOam->spawnX)
        {
            pOam->xPosition--;
        }
    }
    else if (rng < 160)
    {
        if (MOD_AND(rng, 2))
        {
            if (pOam->yPosition < pOam->spawnY + 3)
                pOam->yPosition++;
        }
        else if (pOam->yPosition > pOam->spawnY - 3)
        {
            pOam->yPosition--;
        }
    }
    
    if (INTRO_DATA.subStage == 5)
    {
        pOam->unk_A++;
        if (pOam->unk_A == 60)
        {
            NewFileIntroSamusGettingCuredSetupOam(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_6, pOam->xPosition, pOam->yPosition);
        }
        else if (pOam->unk_A > 260)
        {
            pOam->affineMode = OAM_AFFINE_MODE_AFFINE;
            pOam->scaling -= 2;
            if (pOam->scaling < Q_8_8(1.f/ 8))
            {
                pOam->type = 0;
                pOam->unk_18_0 = 0;
            }
        }
    }
}

 /**
 * @brief 8d660 | 94 | To document
 * 
 */
void unk_8d660(struct SpecialCutsceneOam *pOam)
{
    u8 value;
    
    pOam->unk_A++;

    if (pOam->stage == 0)
    {
        if (pOam->unk_A > 20)
        {
            pOam->unk_A = 0;
            INTRO_DATA.unk_110 = 1;
            INTRO_DATA.unk_111 = 0;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1 && LOW_BYTE(sArray_5a9620[pOam->unk_8]) == pOam->unk_A)
    {
        pOam->unk_A = 0;

        if (pOam->unk_8 < 29)
            pOam->unk_8++;

        value = HIGH_BYTE(sArray_5a9620[pOam->unk_8]);
        INTRO_DATA.unk_111 = value;
        INTRO_DATA.unk_110 = 1;
    }
}

 /**
 * @brief 8d6f4 | 6d0 | Spawns an OAM for a new file intro Samus getting cured cutscene
 * 
 */
u8 NewFileIntroSamusGettingCuredSetupOam(IntroSamusGettingCuredOamType type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == 0)
            break;
    }

    if (slot > 19)
        return 20;
    
    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));
    
    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;

    if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_DOUBLE_HELIX)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroMetroidVaccineDoubleHelixOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusGettingCuredProcessOam_Empty;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_VACCINE_TEXTBOXES)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroMetroidVaccineTextboxesOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusGettingCuredProcessOam_Empty;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_ELECTROCARDIOGRAM)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroMetroidVaccineElectrocardiogramOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusGettingCuredProcessOam_Empty;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_VACCINE_BG_TEXT)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessVaccineBackgroundText;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_10)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_8d06c;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_COUNTDOWN_FAST)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemCountdownOam_Fast;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusGettingCuredProcessOam_Empty;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_COUNTDOWN_SLOW)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemCountdownOam_Slow;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusGettingCuredProcessOam_Empty;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_NUMBER_281)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemNumber281Oam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusGettingCuredProcessOam_Empty;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_CORNER_TEXT)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemCornerTextOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusGettingCuredProcessOam_Empty;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_NERVE_PARTS)
    {
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemNervePartsOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusGettingCuredProcessOam_Empty;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_1)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1.25f);
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXParasiteOam_1;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXInNervousSystem_1;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_2)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1.5f);
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXParasiteOam_2;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXInNervousSystem_2;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_3)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXParasiteOam_3;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXInNervousSystem_3;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_4)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1.25f);
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXParasiteOam_4;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXInNervousSystem_4;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_5)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXParasiteOam_5;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXInNervousSystem_5;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_6)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXParasiteOam_6;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXInNervousSystem_6;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_1)
    {
        INTRO_DATA.oam[slot].unk_8 = NewFileIntroFindOamByType(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_1);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXLockOnOam_1;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXLockOn;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_2)
    {
        INTRO_DATA.oam[slot].unk_8 = NewFileIntroFindOamByType(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_2);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXLockOnOam_2;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXLockOn;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_3)
    {
        INTRO_DATA.oam[slot].unk_8 = NewFileIntroFindOamByType(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_3);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXLockOnOam_3;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXLockOn;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_4)
    {
        INTRO_DATA.oam[slot].unk_8 = NewFileIntroFindOamByType(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_4);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXLockOnOam_4;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXLockOn;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_5)
    {
        INTRO_DATA.oam[slot].unk_8 = NewFileIntroFindOamByType(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_5);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXLockOnOam_5;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXLockOn;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_LOCK_ON_6)
    {
        INTRO_DATA.oam[slot].unk_8 = NewFileIntroFindOamByType(INTRO_SAMUS_GETTING_CURED_OAM_TYPE_X_PARASITE_6);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusNervousSystemXLockOnOam_6;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessXLockOn;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_UNK_28)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_8d660;
    }
    else if (type == INTRO_SAMUS_GETTING_CURED_OAM_TYPE_NEXT_PAGE_ARROW)
    {
        INTRO_DATA.oam[slot].pOam = sIntroNextPageArrowOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessTextCursor;
    }
    
    return slot;
}

 /**
 * @brief 8ddc4 | 38 | Spawns an OAM for a new file intro Samus getting cured cutscene with an additional argument
 * 
 */
void unk_8ddc4(IntroSamusGettingCuredOamType type, s16 xPosition, s16 yPosition, s16 arg3)
{
    u8 slot;

    slot = NewFileIntroSamusGettingCuredSetupOam(type, xPosition, yPosition);
    INTRO_DATA.oam[slot].unk_8 = arg3;
}

 /**
 * @brief 8ddfc | 3c | Returns the OAM slot of the specified Samus getting cured cutscene OAM
 * 
 */
u8 NewFileIntroFindOamByType(IntroSamusGettingCuredOamType type)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == type)
            return slot;
    }

    // Default value if not found
    return ARRAY_SIZE(INTRO_DATA.oam);
}

 /**
 * @brief 8de38 | 4c | V-blank code for the new file intro Metroid vaccine cutscene
 * 
 */
void NewFileIntroSamusGettingCuredVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

 /**
 * @brief 8de84 | a8 | V-blank code for the new file intro Samus nervous system cutscene
 * 
 */
void NewFileIntroSamusGettingCuredNervousSystemVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);

    if (INTRO_DATA.unk_110 == 1)
    {
        INTRO_DATA.unk_110 = 0;

        DMA3_COPY_32(sArray_79c2e4[INTRO_DATA.unk_111], PALRAM_OBJ, 4 * PAL_ROW_SIZE / sizeof(u32));
        DMA3_COPY_32(sArray_79c2e4[INTRO_DATA.unk_111], PALRAM_BASE, 4 * PAL_ROW_SIZE / sizeof(u32));
    }
}

 /**
 * @brief 8df2c | 4 | Empty OAM handler function for the 'Samus getting cured' cutscenes 
 * 
 */
void NewFileIntroSamusGettingCuredProcessOam_Empty(struct SpecialCutsceneOam* pOam)
{
    return;
}

 /**
 * @brief 8df30 | 210 | Setup for the intro Samus found cutscene
 * 
 */
void NewFileIntroSamusFoundInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sIntroHazmatTeamGfx, VRAM_BASE);
    LZ77UncompVram(sIntroVariaSuitCoveredInXParasitesGfx, VRAM_BASE + 0x8000);
    LZ77UncompVram(sIntroHazmatTeamTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroVariaSuitCoveredInXParasitesTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroSamusFoundPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompWram(sIntroSuitRemovalSurgeryGfx, EWRAM_BASE);
    LZ77UncompWram(sIntroMetroidVaccineVialGfx, EWRAM_BASE + 0x8000);
    LZ77UncompWram(sIntroSuitRemovalSurgeryTilemap, EWRAM_BASE + 0xD000);
    LZ77UncompWram(sIntroMetroidVaccineVialTilemap, EWRAM_BASE + 0xD800);

    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    NewFileIntroSamusFoundSetupOam(INTRO_SAMUS_FOUND_OAM_TYPE_NEXT_PAGE_ARROW, 260, 0);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);

    CallbackSetVBlank(NewFileIntroSamusFoundVblank);
}

 /**
 * @brief 8e140 | 594 | Processes the intro Samus found cutscene
 * 
 */
boolu32 NewFileIntroSamusFoundProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && !INTRO_DATA.unk_218)
        INTRO_DATA.unk_218 = 1;
    
    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (INTRO_DATA.timer == TWO_THIRD_SECOND)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][12];
                INTRO_DATA.subStage = 1;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 1:
            INTRO_DATA.timer = 0;
            gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_Evb = 0;

            if (INTRO_DATA.unk_218 == 2)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 2;
            }
            else if (INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 2;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 2:
            if (INTRO_DATA.timer == CONVERT_SECONDS(.5f) - DELTA_TIME)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
                NewFileIntroSamusFoundSetupOam(INTRO_SAMUS_FOUND_OAM_TYPE_FADE_IN, 16, 0);
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(.5f))
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG3);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 3;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 3:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.5f) - DELTA_TIME)
            {
                SpecialCutsceneDestroyOamOfType(INTRO_SAMUS_FOUND_OAM_TYPE_FADE_IN);
                gWrittenToBldalpha_Eva = 0;
                gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG2);
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(1.5f))
            {
                DMA3_COPY_32(EWRAM_BASE + 0xD000, VRAM_BASE + 0xF000, 0x200);
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(1.5f) + DELTA_TIME)
            {
                NewFileIntroSamusFoundSetupOam(INTRO_SAMUS_FOUND_OAM_TYPE_LOAD_GFX, 0, 0);
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(1 + 2.f / 3) - DELTA_TIME)
            {
                // Empty
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(1 + 2.f / 3))
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 4;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 4:
            INTRO_DATA.timer = 0;
            gWrittenToBldalpha_Eva = 0;
            gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;

            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                NewFileIntroSamusFoundSetupOam(INTRO_SAMUS_FOUND_OAM_TYPE_FADE_IN_LAYING, 0, 0);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG2);
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 5;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 5:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.5f))
            {
                INTRO_DATA.timer = 0;
                SpecialCutsceneDestroyOamOfType(INTRO_SAMUS_FOUND_OAM_TYPE_FADE_IN_LAYING);
                gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
                gWrittenToBldalpha_Evb = 0;
                INTRO_DATA.subStage = 6;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 6:
            if (INTRO_DATA.timer == ONE_THIRD_SECOND)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][13];
                INTRO_DATA.subStage = 7;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 7:
            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 8;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 8:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
                INTRO_DATA.timer = 0;
                DMA3_FILL_32(0, VRAM_BASE + 0xD000, 0x1000);
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][14];
                INTRO_DATA.subStage = 9;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 9:
            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
                gWrittenToBldalpha_Evb = 0;
                INTRO_DATA.subStage = 10;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 10:
            if (INTRO_DATA.timer == DELTA_TIME)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG3);
                DMA3_COPY_32(EWRAM_BASE + 0xD800, VRAM_BASE + 0xF800, 0x200);
            }
            else if (INTRO_DATA.timer == 2 * DELTA_TIME)
            {
                NewFileIntroSamusFoundSetupOam(INTRO_SAMUS_FOUND_OAM_TYPE_LOAD_GFX_2, 0, 0);
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(.25f))
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG3);
                INTRO_DATA.timer = 0;
                NewFileIntroSamusFoundSetupOam(INTRO_SAMUS_FOUND_OAM_TYPE_FADE_IN_VACCINE, 0, 0);
                NewFileIntroSamusFoundSetupOam(INTRO_SAMUS_FOUND_OAM_TYPE_SCREEN_SCROLLING, 0, gBg2YPosition);
                INTRO_DATA.subStage = 11;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
	    case 11:
	        if (INTRO_DATA.timer == CONVERT_SECONDS(1.5f))
            {
	            gWrittenToBldalpha_Eva = 0;
	            gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
	            INTRO_DATA.timer = 0;
	            SpecialCutsceneDestroyOamOfType(INTRO_SAMUS_FOUND_OAM_TYPE_FADE_IN_VACCINE);
	            SpecialCutsceneDestroyOamOfType(INTRO_SAMUS_FOUND_OAM_TYPE_SCREEN_SCROLLING);
	            INTRO_DATA.subStage = 12;
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
        
	    case 12:
	        if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
	            INTRO_DATA.timer = 0;
	            DMA3_FILL_32(0, VRAM_BASE + 0xD000, 0x1000);
	            INTRO_DATA.unk_212 = 0;
	            INTRO_DATA.unk_E = 0;
	            INTRO_DATA.unk_C = 0;
	            INTRO_DATA.pText = sMonologueTextPointers[gLanguage][15];
	            INTRO_DATA.subStage = 13;
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
	
	    case 13:
	        INTRO_DATA.timer = 0;
            
	        if (INTRO_DATA.unk_218 == 2)
            {
                INTRO_DATA.unk_218 = 0;
	            INTRO_DATA.pText2 = INTRO_DATA.pText;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
	            INTRO_DATA.pText2 = INTRO_DATA.pText;
	            INTRO_DATA.pText = sCutsceneTextNone;
	            INTRO_DATA.subStage = 14;
            }
            else if (INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
	            INTRO_DATA.pText2 = INTRO_DATA.pText;
	            INTRO_DATA.pText = sCutsceneTextNone;
	            INTRO_DATA.subStage = 14;
            }
            
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
	
	    case 14:
	        if (INTRO_DATA.timer == CONVERT_SECONDS(.5f))
            {
	            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG2);
	            WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
	            gWrittenToBldy = 0;
	            INTRO_DATA.timer = 0;
	            INTRO_DATA.subStage = 0;
	            finished = TRUE;
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
    }
    
    IntroProcessText();
    
    return finished;
}

 /**
 * @brief 8e6d4 | a8 | Main handler of the intro Samus found cutscene
 * 
 */
boolu32 NewFileIntroSamusFound(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSamusFoundInit();
            INTRO_DATA.stage = 1;
            break;

        case 1:
            APPLY_DELTA_TIME_INC(INTRO_DATA.timer);
            if (INTRO_DATA.timer == CONVERT_SECONDS(.1f))
            {
                INTRO_DATA.timer = 0;

                if (gWrittenToBldy)
                    gWrittenToBldy--;
                else
                    INTRO_DATA.stage = 2;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (NewFileIntroSamusFoundProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                INTRO_DATA.stage = 0;
                finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

 /**
 * @brief 8e77c | 6c | Fades in the Varia suit covered in X parasites screen
 * 
 */
void NewFileIntroProcessSamusFoundFadeIn(struct SpecialCutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == 4)
    {
        pOam->timer = 0;

        if (pOam->xPosition > 0)
            pOam->xPosition--;
    }

    gBg3XPosition = pOam->xPosition;
    gBg3YPosition = 0;

    pOam->unk_A++;
    if (pOam->unk_A == 5)
    {
        pOam->unk_A = 0;

        if (gWrittenToBldalpha_Eva)
        {
            gWrittenToBldalpha_Eva--;
            gWrittenToBldalpha_Evb++;
        }
    }
}

 /**
 * @brief 8e7e8 | 48 | Copies intro Samus found cutscene graphics from EWRAM into VRAM
 * 
 */
void NewFileIntroProcessSamusLayingLoading(struct SpecialCutsceneOam* pOam)
{
    u32 offset;

    offset = pOam->unk_A * 0x1000;
    DMA3_COPY_32(EWRAM_BASE + offset, VRAM_BASE + offset, 0x1000 / sizeof(u32));

    pOam->unk_A++;
    if (pOam->unk_A == pOam->unk_8 + pOam->unk_4)
        pOam->type = 0;
}

 /**
 * @brief 8e830 | 6c | Fades in the intro Varia suit removal surgery screen
 * 
 */
void NewFileIntroProcessSamusFoundFadeInSamusLaying(struct SpecialCutsceneOam* pOam)
{
    APPLY_DELTA_TIME_INC(pOam->timer);
    if (pOam->timer == 3)
    {
        pOam->timer = 0;
        
        if (pOam->yPosition < 96)
            pOam->yPosition++;
    }

    gBg2XPosition = 0;
    gBg2YPosition = pOam->yPosition;

    pOam->unk_A++;
    if (pOam->unk_A == 4)
    {
        pOam->unk_A = 0;

        if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
        {
            gWrittenToBldalpha_Eva++;
            gWrittenToBldalpha_Evb--;
        }
    }
}

 /**
 * @brief 8e89c | 6c | Fades in the intro Metroid vaccine closeup screen
 * 
 */
void NewFileIntroProcessSamusFoundFadeInVaccineCloseUp(struct SpecialCutsceneOam* pOam)
{
    APPLY_DELTA_TIME_INC(pOam->timer);
    if (pOam->timer == 4)
    {
        pOam->timer = 0;
        
        if (pOam->xPosition < 16)
            pOam->xPosition++;
    }

    gBg3XPosition = pOam->xPosition;
    gBg3YPosition = 0;

    pOam->unk_A++;
    if (pOam->unk_A == 5)
    {
        pOam->unk_A = 0;

        if (gWrittenToBldalpha_Eva)
        {
            gWrittenToBldalpha_Eva--;
            gWrittenToBldalpha_Evb++;
        }
    }
}

 /**
 * @brief 8e908 | 3c | Handles the downward scrolling of the intro Varia suit removal surgery screen
 * 
 */
void NewFileIntroProcessSamusFoundScreenScrolling(struct SpecialCutsceneOam* pOam)
{
    APPLY_DELTA_TIME_INC(pOam->timer);
    if (pOam->timer == 3)
    {
        pOam->timer = 0;
        
        if (pOam->yPosition < 96)
            pOam->yPosition++;
    }

    gBg2XPosition = 0;
    gBg2YPosition = pOam->yPosition;
}

 /**
 * @brief 8e944 | 1bc | Spawns an OAM for a new file intro Samus found cutscene
 * 
 */
u8 NewFileIntroSamusFoundSetupOam(IntroSamusFoundOamType type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(INTRO_DATA.oam))
        return ARRAY_SIZE(INTRO_DATA.oam);

    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));

    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;

    if (type == INTRO_SAMUS_FOUND_OAM_TYPE_FADE_IN)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusFoundFadeIn;
    }
    else if (type == INTRO_SAMUS_FOUND_OAM_TYPE_LOAD_GFX)
    {
        INTRO_DATA.oam[slot].unk_A = 0;
        INTRO_DATA.oam[slot].unk_8 = 0;
        INTRO_DATA.oam[slot].unk_4 = 8;
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusLayingLoading;
    }
    else if (type == INTRO_SAMUS_FOUND_OAM_TYPE_FADE_IN_LAYING)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusFoundFadeInSamusLaying;
    }
    else if (type == INTRO_SAMUS_FOUND_OAM_TYPE_LOAD_GFX_2)
    {
        INTRO_DATA.oam[slot].unk_A = 8;
        INTRO_DATA.oam[slot].unk_8 = 8;
        INTRO_DATA.oam[slot].unk_4 = 5;
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusLayingLoading;
    }
    else if (type == INTRO_SAMUS_FOUND_OAM_TYPE_FADE_IN_VACCINE)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusFoundFadeInVaccineCloseUp;
    }
    else if (type == INTRO_SAMUS_FOUND_OAM_TYPE_SCREEN_SCROLLING)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusFoundScreenScrolling;
    }
    else if (type == INTRO_SAMUS_FOUND_OAM_TYPE_NEXT_PAGE_ARROW)
    {
        INTRO_DATA.oam[slot].pOam = sIntroNextPageArrowOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessTextCursor;
    }

    return slot;
}

 /**
 * @brief 8eb00 | 7c | V-blank for the intro Samus found cutscene
 * 
 */
void NewFileIntroSamusFoundVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);
}

 /**
 * @brief 8eb7c | 4 | Empty function
 * 
 */
void NewFileIntroSamusFound_Empty(void)
{
    return;
}

 /**
 * @brief 8eb80 | 250 | Setup for the intro Samus cured cutscene
 * 
 */
void NewFileIntroSamusCuredInit(void)
{
    const u16* pText2;
    
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    pText2 = INTRO_DATA.pText2;

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    INTRO_DATA.pText2 = pText2;

    LZ77UncompVram(sIntroApproachingBslObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sIntroApproachingBslObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(sNextPageArrowGfx, VRAM_OBJ + 0x7FE0, 8);
    DMA3_COPY_32(sNextPageArrowPal, PALRAM_OBJ + 15 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sIntroSamusRebornBgTopGfx, VRAM_BASE);
    LZ77UncompVram(sIntroSamusRebornBgBottomGfx, VRAM_BASE + 0x8000);
    LZ77UncompVram(sIntroSamusRebornBgTopTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusRebornBgBottomTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroSamusRebornBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    DMA3_COPY_32(&sIntroSamusFoundPal[15 * PAL_ROW], PALRAM_BASE + 15 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompWram(sIntroSamusMonologueBgTilemap, EWRAM_BASE);
    LZ77UncompWram(sIntroSamusMonologueBgGfx, EWRAM_BASE + 0x1000);

    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);

    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 256;

    NewFileIntroSamusCuredSetupOam(INTRO_SAMUS_CURED_OAM_TYPE_NEXT_PAGE_ARROW, 260, 0);
    NewFileIntroSamusCuredSetupOam(INTRO_SAMUS_CURED_OAM_TYPE_SCREEN_SCROLLER, 0, 0);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(NewFileIntroSamusCuredVblank);
}

 /**
 * @brief 8edd0 | 428 | Processes the Samus cured cutscene
 * 
 */
boolu32 NewFileIntroSamusCuredProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
        INTRO_DATA.unk_218 = 1;
    
    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (gWrittenToBldy)
            {
                gWrittenToBldy--;
            }
            else
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 1;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 1:
            if (INTRO_DATA.timer == CONVERT_SECONDS(4 + 2.f / 3))
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG2);
                INTRO_DATA.subStage = 2;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = INTRO_DATA.pText2;
                INTRO_DATA.subStage = 3;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
	    case 3:
	        INTRO_DATA.timer = 0;
	
	        if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
	        {
	            INTRO_DATA.unk_218 = 0;
	        }
	        else if (INTRO_DATA.unk_218 == 3)
	        {
	            INTRO_DATA.unk_218 = 0;
	            INTRO_DATA.subStage = 4;
	        }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 4:
            if (INTRO_DATA.timer == ONE_THIRD_SECOND)
            {
                INTRO_DATA.timer = 0;
                DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));
                INTRO_DATA.subStage = 5;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

	    case 5:
	        INTRO_DATA.unk_213++;
	        if (INTRO_DATA.unk_213 < 6)
	        {
	            DMA3_COPY_32(EWRAM_BASE + INTRO_DATA.unk_213 * 0x1000, VRAM_BASE + 0x7000 + INTRO_DATA.unk_213 * 0x1000, 0x1000 / sizeof(u32));
	        }
	        else if (INTRO_DATA.unk_213 == 6)
	        {
	            DMA3_COPY_32(sPalPointers_79c354[0], PALRAM_BASE, 2 * PAL_ROW);
	            DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xF000, 0x800 / sizeof(u32));
	            gWrittenToBldalpha_Eva = 0;
	            gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
	            gBg2YPosition = 0;
	        }
	        else
	        {
	            INTRO_DATA.unk_213 = 10;
	        }
	
	        if (INTRO_DATA.timer == DELTA_TIME)
	        {
	            INTRO_DATA.timer = 0;
	
	            if (INTRO_DATA.unk_111 < 15)
	            {
	                INTRO_DATA.unk_111++;
	                INTRO_DATA.unk_110 = 1;
	            }
	            else
	            {
	                WRITE_16(REG_BLDCNT, BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT 
	                         | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
	                INTRO_DATA.unk_213 = 0;
	                INTRO_DATA.subStage = 6;
	            }
	        }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
	    case 6:
	        if (INTRO_DATA.timer == CONVERT_SECONDS(1 + 1.f / 6))
            {
	            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG2);
	            INTRO_DATA.timer = 0;
	            INTRO_DATA.subStage = 7;
	        }

	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
        
	    case 7:
	        INTRO_DATA.unk_213++;
	        if (INTRO_DATA.unk_213 == 8)
	        {
	            INTRO_DATA.unk_213 = 0;
	
	            if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
	            {
	                gWrittenToBldalpha_Eva++;
	                gWrittenToBldalpha_Evb--;
	            }
	            else
	            {
	                INTRO_DATA.timer = 0;
	                INTRO_DATA.subStage = 8;
	            }
	        }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 8:
            if (INTRO_DATA.timer == CONVERT_SECONDS(2.f / 15))
            {
                INTRO_DATA.timer = 0;
                
                if (INTRO_DATA.unk_12D < 15)
                {
                    INTRO_DATA.unk_12D++;
                    INTRO_DATA.unk_12C = 1;
                }
                else
                {
                    gWrittenToBldy = 0;
                    INTRO_DATA.subStage = 9;
                }
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 9:
            if (INTRO_DATA.timer == CONVERT_SECONDS(.5f))
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][17];
                INTRO_DATA.subStage = 10;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 10:
            INTRO_DATA.timer = 0;

            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
	        {
	            INTRO_DATA.unk_218 = 0;
	        }
	        else if (INTRO_DATA.unk_218 == 3)
	        {
	            INTRO_DATA.unk_218 = 0;
	            INTRO_DATA.subStage = 11;
	        }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 11:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
                NewFileIntroSamusCuredSetupOam(INTRO_SAMUS_CURED_OAM_TYPE_SCREEN_GLARE, SCREEN_X_MIDDLE, 64);
            }
            else if (INTRO_DATA.timer == TWO_THIRD_SECOND)
            {
                INTRO_DATA.timer = 0;
                gWrittenToBldy = BLDY_MAX_VALUE;
                INTRO_DATA.subStage = 12;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 12:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
                gWrittenToBldy++;
            else
                finished = TRUE;

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    IntroProcessText();

    return finished;
}

 /**
 * @brief 8f1f8 | 88 | Main handler for the intro Samus cured cutscene
 * 
 */
boolu32 NewFileIntroSamusCured(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroSamusCuredInit();
            INTRO_DATA.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();

            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (NewFileIntroSamusCuredProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                INTRO_DATA.stage = 0;
                finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
        
    return finished;
}

 /**
 * @brief 8f280 | 104 | Processes the screen scrolling in the Samus cured cutscene
 * 
 */
void NewFileIntroSamusCuredProcessScrolling(struct SpecialCutsceneOam *pOam)
{
    APPLY_DELTA_TIME_INC(pOam->timer);

    if (pOam->stage == 0)
    {
        pOam->xPosition = gBg2XPosition;
        pOam->yPosition = gBg2YPosition;
        pOam->spawnX = gBg3XPosition;
        pOam->spawnY = gBg3YPosition;
        pOam->unk_A = 0x5000;
        pOam->timer = 0;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        if (pOam->timer == CONVERT_SECONDS(1.f / 6))
        {
            pOam->timer = 0;
            pOam->stage = 2;
        }
    }
    else if (INTRO_DATA.subStage == 1)
    {
        if (pOam->timer == DELTA_TIME)
        {
            pOam->timer = 0;
            
            if (pOam->yPosition > -SCREEN_SIZE_Y)
            {
                pOam->yPosition--;
                pOam->unk_8++;
            }
            
            if (pOam->spawnY > 0)
                pOam->spawnY--;

            gBg2YPosition = pOam->yPosition;
            gBg3YPosition = pOam->spawnY;
        }
        
        if (pOam->unk_8 == 9)
        {
            pOam->unk_8 = 0;
            
            if (pOam->unk_A)
            {
                pOam->unk_A -= 0x400;
                DMA3_FILL_32(0, VRAM_BASE + 0x8000 + pOam->unk_A, 0x400);
            }
        }
    }
    else
    {
        pOam->timer = 0;
    }
}

 /**
 * @brief 8f384 | 140 | Spawns an OAM for the intro Samus cured cutscene
 * 
 */
u8 NewFileIntroSamusCuredSetupOam(IntroSamusCuredOamType type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(INTRO_DATA.oam))
        return ARRAY_SIZE(INTRO_DATA.oam);

    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));

    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;

    if (type == INTRO_SAMUS_CURED_OAM_TYPE_SCREEN_SCROLLER)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusCuredProcessScrolling;
    }
    else if (type == INTRO_SAMUS_CURED_OAM_TYPE_SCREEN_GLARE)
    {
        SoundPlay(SOUND_12D);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusCuredScreenGlareOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroSamusCuredProcessOam_Empty;
    }
    else if (type == INTRO_SAMUS_CURED_OAM_TYPE_NEXT_PAGE_ARROW)
    {
        INTRO_DATA.oam[slot].pOam = sIntroNextPageArrowOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessTextCursor;
    }

    return slot;
}

 /**
 * @brief 8f4c4 | fc | V-blank for the Samus cured cutscene
 * 
 */
void NewFileIntroSamusCuredVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);

    if (INTRO_DATA.unk_110 == 1)
    {
        INTRO_DATA.unk_110 = 0;
        DMA3_COPY_32(sPalPointers_79c314[INTRO_DATA.unk_111], PALRAM_BASE + 5 * PAL_ROW_SIZE, 10 * PAL_ROW_SIZE / sizeof(u32));
    }

    if (INTRO_DATA.unk_12C == 1)
    {
        INTRO_DATA.unk_12C = 0;
        DMA3_COPY_32(sPalPointers_79c354[INTRO_DATA.unk_12D], PALRAM_BASE, 4 * PAL_ROW_SIZE / sizeof(u32));
    }
}

 /**
 * @brief 8f5c0 | 4 | Intro Samus cured OAM handler (empty)
 * 
 */
void NewFileIntroSamusCuredProcessOam_Empty(struct SpecialCutsceneOam* pOam)
{
    return;
}

 /**
 * @brief 8f5c4 | 230 | Setup for the arriving at BSL cutscene
 * 
 */
void NewFileIntroArrivingAtBslInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    LZ77UncompVram(sIntroApproachingBslObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sIntroApproachingBslObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sIntroArrivingAtBslSpaceMapBgGfx, VRAM_BASE);
    LZ77UncompVram(sIntroSamusMonologueBgGfx, VRAM_BASE + 0x8000);
    LZ77UncompVram(sIntroArrivingAtBslSpaceMapTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusMonologueBgTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroArrivingAtBslSpaceMapPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    SET_BACKDROP_COLOR(COLOR_BLACK);

    LZ77UncompWram(sIntroTilemap_662804, EWRAM_BASE);
    LZ77UncompWram(sIntroFlyingToBslObjGfx, EWRAM_BASE + 0x1000);
    LZ77UncompWram(sIntroFlyingToBslBgGfx, EWRAM_BASE + 0x9000);

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gBg0XPosition = -8;
    gBg0YPosition = 8;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);

    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = 0;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;

    NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_TRAJECTORY, 112, 80);
    NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_PLANETS_AND_SHIP, 112, 80);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);

    CallbackSetVBlank(NewFileIntroArrivingAtBslVblank);
}

 /**
 * @brief 8f7f4 | 750 | Processes the arriving at BSL cutscene
 * 
 */
boolu32 NewFileIntroArrivingAtBslProcess(void)
{
    boolu32 finished;

    finished = FALSE;
    
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
        INTRO_DATA.unk_218 = 1;

    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (INTRO_DATA.timer == DELTA_TIME)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 2;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 1:
            if (INTRO_DATA.timer == CONVERT_SECONDS(.05f))
            {
                INTRO_DATA.timer = 0;
                
                if (gWrittenToBldalpha_Evb > 8)
                    gWrittenToBldalpha_Evb--;
                
                if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
                    gWrittenToBldalpha_Eva += 2;
                else
                    INTRO_DATA.subStage = 2;
                
                if (gWrittenToBldalpha_Eva == 8)
                {
                    NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_TRAJECTORY, 112, 80);
                    NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_PLANETS_AND_SHIP, 112, 80);
                }
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_BSL_POPUP, 198, 36);
            }
            else if (INTRO_DATA.timer == TWO_THIRD_SECOND)
            {
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_UNK_255, 0, 0);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_ADAM_TEXT_CURSOR, 20, 192);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_ADAM_PANEL_FRAME, 128, 192);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_ADAM_PANEL_BACKGROUND, 128, 192);
                INTRO_DATA.subStage = 3;
                INTRO_DATA.timer = 0;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            NewFileIntroProcessAdamText();
            break;

        case 3:
            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
                SoundPlay(SOUND_203);
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~ DCNT_BG0);
                INTRO_DATA.unk_218 = 0;
                SoundPlay(SOUND_203);
                INTRO_DATA.subStage = 4;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            NewFileIntroProcessAdamText();
            break;

        case 4:
            INTRO_DATA.timer = 0;
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 5:
            if (INTRO_DATA.timer == DELTA_TIME)
            {
                ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_244].trackGroupNumber].pTrack, 0);
            }
            else if (INTRO_DATA.timer > CONVERT_SECONDS(.5f))
            {
                if (gWrittenToBldy < BLDY_MAX_VALUE)
                {
                    gWrittenToBldy++;
                }
                else
                {
                    WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG2);
                    WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG3);
                    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
                    INTRO_DATA.timer = 0;
                    INTRO_DATA.subStage = 6;
                }
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 6:
            INTRO_DATA.timer = 0;
            
            if (gWrittenToBldy)
                gWrittenToBldy--;
            else
                INTRO_DATA.subStage = 7;
            break;

        case 7:
            if (INTRO_DATA.timer == DELTA_TIME)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                DMA3_FILL_32(0, VRAM_BASE, 0x4800);
            }
            else if (INTRO_DATA.timer == 2 * DELTA_TIME)
            {
                DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0x4800, 0x800 / sizeof(u32));
                DMA3_COPY_32(sIntroPal_663820, PALRAM_BASE + 12 * PAL_ROW_SIZE, 4 * PAL_ROW_SIZE / sizeof(u32));
                gBg0XPosition = 0;
                gBg0YPosition = 4;
            }
            else if (INTRO_DATA.timer == 3 * DELTA_TIME)
            {
                WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 9, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(1))
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.unk_12 = 0;
                INTRO_DATA.unk_10 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][0];
                INTRO_DATA.subStage = 8;
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_MONOLOGUE_CURSOR, 260, 0);
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 8:
            INTRO_DATA.timer = 0;
            
            if (INTRO_DATA.unk_218 == 2 || INTRO_DATA.unk_218 == 4)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 9;
            }
            
            if (NewFileIntroCheckMonologueEnded())
            {
                INTRO_DATA.subStage = 9;
                INTRO_DATA.unk_218 = 0;
            }
            
            if (INTRO_DATA.unk_213 == 0)
            {
                INTRO_DATA.unk_213 = 100;
            }
            else if (INTRO_DATA.unk_213 == 1)
            {
                INTRO_DATA.unk_213 = 100;
                SpecialCutsceneProcessMonologue();
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 9:
            if (INTRO_DATA.timer == DELTA_TIME)
            {
                gWrittenToBldalpha_Evb = 0;
                gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
                FadeMusic(256);
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 6))
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL);
                INTRO_DATA.subStage = 10;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 10:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 15))
            {
                INTRO_DATA.timer = 0;
                
                if (gWrittenToBldalpha_Evb < BLDALPHA_MAX_VALUE)
                    gWrittenToBldalpha_Evb++;
                
                if (gWrittenToBldalpha_Eva)
                    gWrittenToBldalpha_Eva--;
                
                if (gWrittenToBldalpha_Evb == BLDALPHA_MAX_VALUE && !gWrittenToBldalpha_Eva)
                {
                    WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG0);
                    INTRO_DATA.subStage = 11;
                }
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 11:
            if (INTRO_DATA.timer == DELTA_TIME)
            {
                DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
                gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
                gWrittenToBldalpha_Evb = 0;
            }
            else if (INTRO_DATA.timer < 6 * DELTA_TIME)
            {
                DMA3_COPY_32(EWRAM_BASE - 0x3000 + INTRO_DATA.timer * 0x2000, VRAM_BASE + 0xC000 + INTRO_DATA.timer * 0x2000, 0x2000 / sizeof(u32));
            }
            else if (INTRO_DATA.timer < 10 * DELTA_TIME)
            {
                DMA3_COPY_32(EWRAM_BASE - 0x3000 + INTRO_DATA.timer * 0x2000, VRAM_BASE - 0xC000 + INTRO_DATA.timer * 0x2000, 0x2000 / sizeof(u32));
            }
            else if (INTRO_DATA.timer == 10 * DELTA_TIME)
            {
                LZ77UncompVram(sIntroTilemap_5f65d8, VRAM_BASE + 0xE800);
            }
            else if (INTRO_DATA.timer == 11 * DELTA_TIME)
            {
                LZ77UncompVram(sIntroTilemap_5f5454, VRAM_BASE + 0xF000);
                WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 31, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
            }
            else if (INTRO_DATA.timer == 12 * DELTA_TIME)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG3);
                WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 29, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
                WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
                WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL 
                        | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
                DMA3_COPY_32(sPal_5f4ed4, PALRAM_BASE + 4 * PAL_ROW_SIZE, 12 * PAL_ROW_SIZE / sizeof(u32));
                gBg2XPosition = 0;
                gBg2YPosition = 0;
                gBg3XPosition = 0;
                gBg3YPosition = 0;
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(.5f))
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG3);
                INTRO_DATA.timer = 0;
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_UNK_255, 0, 0);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_1, 208, 100);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_2, 208, 100);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_3, 208, 100);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP, 196, 100);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_BSL, 6, 78);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_BG3_SCROLLER, 0, 0);
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_BG2_SCROLLER, 0, 0);
                SoundPlay_3b1c(SOUND_245);
                INTRO_DATA.subStage = 12;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 12:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 15))
            {
                INTRO_DATA.timer = 0;
                
                if (gWrittenToBldalpha_Evb < BLDALPHA_MAX_VALUE)
                    gWrittenToBldalpha_Evb++;
                
                if (gWrittenToBldalpha_Eva)
                    gWrittenToBldalpha_Eva--;

                if (gWrittenToBldalpha_Evb == BLDALPHA_MAX_VALUE)
                {
                    if (!gWrittenToBldalpha_Eva)
                    {
                        WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG1);
                        INTRO_DATA.subStage = 13;
                    }
                }
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 13:
            INTRO_DATA.timer = 0;

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 14:
            if (INTRO_DATA.timer == CONVERT_SECONDS(4.f / 3))
            {
                INTRO_DATA.timer = 0;
                gWrittenToBldy = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    return finished;
}

 /**
 * @brief 8ff44 | 90 | Main handler of the arriving at BSL cutscene
 * 
 */
boolu32 NewFileIntroArrivingAtBsl(void)
{
    boolu32 finished;

    finished = FALSE;
    
    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroArrivingAtBslInit();
            INTRO_DATA.stage = 1;
            break;
        
        case 1:
            gWrittenToBldy = 0;
            SoundPlay(SOUND_244);
            
            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;
        
        case 2:
            if (NewFileIntroArrivingAtBslProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;
        
        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                INTRO_DATA.stage = 0;
                finished = TRUE;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }
    
    return finished;
}

 /**
 * @brief 8ffd4 | 270 | Processes Samus' ship in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessSamusShipArrivingAtBsl(struct SpecialCutsceneOam *pOam)
{
    const struct FrameData* frame;
    s16 x;
    s16 y;

    pOam->unk_A++;
    
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        
        if (pOam->unk_A == 20)
        {
            pOam->unk_A = 0;
            pOam->animationDurationCounter = 0;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        if (pOam->timer == CONVERT_SECONDS(1.f / 30))
        {
            pOam->timer = 0;
            pOam->scaling--;
        }

        pOam->xPosition = pOam->spawnX - (pOam->unk_A >> 3);
        
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->spawnX = pOam->spawnX - (pOam->unk_A >> 3);
            pOam->spawnY = pOam->yPosition;
            pOam->timer = 0;
            pOam->unk_A = 0;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        if (pOam->unk_A == 2)
        {
            NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_EXPLOSION, pOam->xPosition, pOam->yPosition);
            pOam->rotation -= 1;
        }
        else if (pOam->unk_A == 4)
        {
            pOam->unk_A = 0;
            pOam->stage = 3;
            pOam->rotation -= 1;
        }
        
        pOam->scaling--;
        pOam->animationDurationCounter = 0;
    }
    else if (pOam->stage == 3)
    {
        pOam->scaling -= 2;
        
        NewFileIntroGetPositionAndSlotOfOamByType(INTRO_ARRIVING_AT_BSL_OAM_TYPE_BSL, &x, &y);
        
        if (pOam->rotation > Q_8_8(15.f / 16))
            pOam->rotation--;

        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 1);
        pOam->xPosition = pOam->spawnX - (pOam->unk_A << 1);

        if (pOam->unk_A == 10)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 4;
        }
        
        pOam->animationDurationCounter = 0;
    }
    else if (pOam->stage == 4)
    {
        pOam->scaling -= 4;
        
        NewFileIntroGetPositionAndSlotOfOamByType(INTRO_ARRIVING_AT_BSL_OAM_TYPE_BSL, &x, &y);
        
        if (pOam->rotation > Q_8_8(15.f / 16))
            pOam->rotation--;
        
        pOam->yPosition = pOam->spawnY - pOam->unk_A;
        pOam->xPosition = pOam->spawnX - (pOam->unk_A << 2);
        
        if (x - pOam->xPosition > -20)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 5;
        }
        
        pOam->animationDurationCounter = 0;
    }
    else if (pOam->stage == 5)
    {
        pOam->scaling -= 2;
        
        NewFileIntroGetPositionAndSlotOfOamByType(INTRO_ARRIVING_AT_BSL_OAM_TYPE_BSL, &x, &y);
        
        if ((u8)(pOam->rotation - Q_8_8(.04f)) > Q_8_8(.745f))
            pOam->rotation++;

        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 1);
        pOam->xPosition = pOam->spawnX - (pOam->unk_A << 1);
        
        if (x - pOam->xPosition > 10)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 6;
        }
        
        pOam->animationDurationCounter = 0;
    }
    else if (pOam->stage == 6)
    {
        pOam->scaling--;

        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 2);
        pOam->xPosition = pOam->spawnX - (pOam->unk_A >> 1);
    
        if ((u8)(pOam->rotation - Q_8_8(.04f)) > Q_8_8(.745f))
        {
            pOam->rotation++;
        }
        else
        {
            pOam->unk_A = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 7;
        }
    
        pOam->animationDurationCounter = 0;
    }
    else if (pOam->stage == 7)
    {
        if ((u8)(pOam->rotation - Q_8_8(1.f / 16)) > Q_8_8(.72f))
        {
            pOam->timer++;
            if (pOam->timer == CONVERT_SECONDS(.05f))
            {
                pOam->timer = 0;
                pOam->rotation++;
            }
        }
        
        pOam->yPosition = pOam->spawnY - (pOam->unk_A >> 2);
        pOam->xPosition = (pOam->unk_A >> 1) + pOam->spawnX;
        
        pOam->scaling -= 2;
        if (pOam->scaling < Q_8_8(1.f / 8))
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
            INTRO_DATA.subStage = 14;
        }
        
        pOam->animationDurationCounter = 0;
    }
    
    if (pOam->scaling <= Q_8_8(1))
        pOam->affineMode = OAM_AFFINE_MODE_AFFINE;
}

 /**
 * @brief 90244 | 20 | Processes the BSL in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessBslPreview(struct SpecialCutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == CONVERT_SECONDS(1.f / 10))
    {
        pOam->timer = 0;
        pOam->xPosition++;
    }
}

 /**
 * @brief 90264 | 1ac | Processes the ship's thrusters in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessSamusShipArrivingAtBslThrusters(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;
    u8 slot;
    s16 x;
    s16 y;

    frame = &pOam->pOam[pOam->currentAnimationFrame];
    if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
    {
        pOam->currentAnimationFrame = 0;
        pOam->animationDurationCounter = 0;
    }

    pOam->timer++;
    if (pOam->timer == 4)
    {
        pOam->timer = 0;

        switch (pOam->type)
        {
            case 3:
                slot = NewFileIntroGetPositionAndSlotOfOamByType(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_2, &x, &y);
                if (slot == ARRAY_SIZE(INTRO_DATA.oam))
                {
                    pOam->type = 0;
                    pOam->unk_18_0 = 0;
                    break;
                }

                pOam->scaling = INTRO_DATA.oam[slot].scaling;
                pOam->affineMode = INTRO_DATA.oam[slot].affineMode;
                pOam->xPosition = x;
                pOam->yPosition = y;
                break;

            case 4:
                slot = NewFileIntroGetPositionAndSlotOfOamByType(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_3, &x, &y);
                if (slot == ARRAY_SIZE(INTRO_DATA.oam))
                {
                    pOam->type = 0;
                    pOam->unk_18_0 = 0;
                    break;
                }

                pOam->scaling = INTRO_DATA.oam[slot].scaling;
                pOam->affineMode = INTRO_DATA.oam[slot].affineMode;
                pOam->xPosition = x;
                pOam->yPosition = y;
                break;

            case 5:
                slot = NewFileIntroGetPositionAndSlotOfOamByType(INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP, &x, &y);
                if (slot == ARRAY_SIZE(INTRO_DATA.oam))
                {
                    pOam->type = 0;
                    pOam->unk_18_0 = 0;
                    break;
                }

                pOam->scaling = INTRO_DATA.oam[slot].scaling;
                pOam->affineMode = INTRO_DATA.oam[slot].affineMode;

                if (INTRO_DATA.oam[slot].stage < 2)
                {
                    pOam->yPosition = y;

                    switch (INTRO_DATA.oam[slot].currentAnimationFrame)
                    {
                        case 0:
                            pOam->xPosition = x + 12;
                            break;
                
                        case 1:
                            pOam->xPosition = x + 10;
                            break;
                
                        case 2:
                            pOam->xPosition = x + 8;
                            break;
                
                        case 3:
                            pOam->xPosition = x + 6;
                            break;
                
                        case 4:
                            pOam->xPosition = x + 5;
                            break;
                
                        case 5:
                            pOam->xPosition = x + 4;
                            break;
                
                        case 6:
                            pOam->xPosition = x + 3;
                            break;
                
                        case 7:
                            pOam->xPosition = x + 2;
                            break;
                
                        case 8:
                            pOam->xPosition = x + 1;
                            break;

                        default:
                            pOam->xPosition = x;
                            break;
                    }
                }
                else
                {
                    pOam->yPosition = y;
                    pOam->xPosition = x;
                }
                break;
        }
    }
}

 /**
 * @brief 90410 | 2c | Processes the ship's thrusters flaring up in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessSamusShipArrivingAtBslThrusterExplosion(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;
    
    frame = &pOam->pOam[pOam->currentAnimationFrame];
    if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

 /**
 * @brief 9043c | 8 | To document
 * 
 */
void unk_9043c(struct SpecialCutsceneOam* pOam)
{
    pOam->type = 0;
}

 /**
 * @brief 90444 | 34 | Processes the background scrolling in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessSamusArrivingAtBslBg3Scrolling(struct SpecialCutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == TWO_THIRD_SECOND)
    {
        pOam->timer = 0;
        
        if (pOam->xPosition < 16)
        {
            pOam->xPosition++;
            gBg3XPosition++;
        }
    }
}

 /**
 * @brief 90478 | 34 | Processes the BG2 scrolling in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessSamusArrivingAtBslBg2Scrolling(struct SpecialCutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == CONVERT_SECONDS(.5f))
    {
        pOam->timer = 0;
        
        if (pOam->xPosition < 16)
        {
            pOam->xPosition++;
            gBg2XPosition--;
        }
    }
}

 /**
 * @brief 904ac | 19c | Processes the Adam panel in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessAdamPanel(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    if (pOam->stage == 0)
    {
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
            
        if (pOam->yPosition > 128)
        {
            pOam->yPosition -= 8;
            return;
        }
            
        pOam->yPosition = 128;
            
        if (pOam->type == 20)
            SoundPlay(SOUND_20A);
            
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter)
        {
            if (frame[1].timer == 0)
            {
                pOam->animationDurationCounter = 0;
                pOam->stage = 2;
            }
            
            if (pOam->type != 20)
                return;

            if (pOam->currentAnimationFrame == 10)
                NewFileIntroArrivingAtBslSetupOam(INTRO_ARRIVING_AT_BSL_OAM_TYPE_ADAM_LENS, pOam->xPosition, pOam->yPosition);
        }
        
        if (pOam->type == 20)
        {
            if (pOam->currentAnimationFrame == 11)
            {
                if (pOam->animationDurationCounter == 15)
                {
                    INTRO_DATA.unk_212 = 0;
                    INTRO_DATA.unk_E = 0;
                    INTRO_DATA.unk_C = 0;
                    INTRO_DATA.pText = sMonologueTextPointers[gLanguage][18];
                }
            }
        }
    }
    else if (pOam->stage == 2)
    {
        pOam->animationDurationCounter = 0;
        pOam->timer++;
        if (pOam->timer == 1)
        {
            pOam->timer = 0;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        pOam->animationDurationCounter = 0;
        
        if (INTRO_DATA.subStage == 4)
        {
            pOam->currentAnimationFrame = 0;
            
            if (pOam->type == 20)
            {
                pOam->pOam = sIntroArrivingAtBslAdamPanelFrameOam_Closing;
                SoundPlay(SOUND_20B);
            }
            else if (pOam->type == 21)
            {
                pOam->pOam = sIntroArrivingAtBslAdamPanelBackgroundOam_Closing;
            }

            pOam->stage = 4;
        }
    }
    else if (pOam->stage == 4)
    {
        if (pOam->currentAnimationFrame == 11 && pOam->animationDurationCounter == 3)
        {
            if (pOam->type == 20)
                SpecialCutsceneDestroyOamOfType(22);
            
            pOam->animationDurationCounter = 0;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 5)
    {
        pOam->animationDurationCounter = 0;
        
        if (pOam->yPosition < 192)
        {
            pOam->yPosition += 8;
        }
        else
        {
            if (pOam->type == 20)
                INTRO_DATA.subStage = 5;

            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

 /**
 * @brief 90648 | 88 | Processes Adam's lens in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessAdamLens(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    frame = &pOam->pOam[pOam->currentAnimationFrame];

    if (pOam->stage == 0)
    {
        if (pOam->currentAnimationFrame == 3)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroArrivingAtBslAdamLensOam_Glowing;
            pOam->stage = 1;
        }
        
        if (INTRO_DATA.subStage == 4)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroArrivingAtBslAdamLensOam_Closing;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 1)
    {
        if (INTRO_DATA.subStage == 4)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroArrivingAtBslAdamLensOam_Closing;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            pOam->animationDurationCounter = 0;
    }
}

 /**
 * @brief 906d0 | 8c | Processes the Adam text cursor in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessAdamTextCursor(struct SpecialCutsceneOam* pOam)
{
    if (*INTRO_DATA.pText == CHAR_TERMINATOR)
    {
        pOam->xPosition = 290;
    }
    else if (*INTRO_DATA.pText != CHAR_NEW_LINE)
    {
        if (*INTRO_DATA.pText == CHAR_NEW_PAGE)
        {
            pOam->xPosition = 290;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroArrivingAtBslAdamTextCursorOam;
        }
        else if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW)
        {
            pOam->xPosition = SCREEN_X_MIDDLE;
            pOam->yPosition = 154;
            pOam->pOam = sIntroArrivingAtBslMonologueCursorOam;
        }
        else
        {
            pOam->xPosition = INTRO_DATA.unk_C * 8 + INTRO_DATA.unk_212 + 14;
            pOam->yPosition = INTRO_DATA.unk_E * 8 + 132;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }
    }
    else
    {
        pOam->xPosition = INTRO_DATA.unk_C * 8 + INTRO_DATA.unk_212 + 14;
        pOam->yPosition = INTRO_DATA.unk_E * 8 + 132;
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
    }
}

 /**
 * @brief 9075c | 9c | Processes the BSL preview popup in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessBslPopUp(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    frame = &pOam->pOam[pOam->currentAnimationFrame];
    
    if (pOam->stage == 0)
    {
        if (pOam->currentAnimationFrame == 1 && pOam->animationDurationCounter == 1)
            SoundPlay(SOUND_11C);

        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->animationDurationCounter = 0;
        
        if (INTRO_DATA.subStage == 4)
        {
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroArrivingAtBslBslPopupOam_Closing;
            SoundPlay(SOUND_11D);
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

 /**
 * @brief 907f8 | 30 | Processes the monologue cursor in the arriving at BSL cutscene
 * 
 */
void NewFileIntroProcessMonologueCursor(struct SpecialCutsceneOam* pOam)
{
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW)
    {
        pOam->xPosition = 118;
        pOam->yPosition = INTRO_DATA.unk_E * 8 + 24;
    }
    else
    {
        pOam->xPosition = 260;
    }
}

 /**
 * @brief 90828 | 438 | Spawns an OAM for the intro arriving at BSL cutscene
 * 
 */
u8 NewFileIntroArrivingAtBslSetupOam(IntroArrivingAtBslOamType type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(INTRO_DATA.oam))
        return ARRAY_SIZE(INTRO_DATA.oam);
    
    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));

    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;

    if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1.5f);
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslSamusShipOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusShipArrivingAtBsl;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_BSL)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslBslOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessBslPreview;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_1)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1.5f);
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslThrustersOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusShipArrivingAtBslThrusters;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_2)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1.5f);
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslThrustersOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusShipArrivingAtBslThrusters;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_3)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1.5f);
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslThrustersOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusShipArrivingAtBslThrusters;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_THRUSTER_EXPLOSION)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslThrusterExplosionOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusShipArrivingAtBslThrusterExplosion;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_BG3_SCROLLER)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusArrivingAtBslBg3Scrolling;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_BG2_SCROLLER)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessSamusArrivingAtBslBg2Scrolling;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_ADAM_PANEL_FRAME)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslAdamPanelFrameOam_Opening;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessAdamPanel;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_ADAM_PANEL_BACKGROUND)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslAdamPanelBackgroundOam_Opening;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessAdamPanel;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_ADAM_LENS)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslAdamLensOam_Opening;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessAdamLens;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_ADAM_TEXT_CURSOR)
    {
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslAdamTextCursorOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessAdamTextCursor;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_SHIP_TRAJECTORY)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslShipTrajectoryOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroArrivingAtBslProcessOam_Empty;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_PLANETS_AND_SHIP)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslPlanetsAndShipOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroArrivingAtBslProcessOam_Empty;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_BSL_POPUP)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslBslPopupOam_Opening;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessBslPopUp;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_SCREEN_GLARE)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroSamusCuredScreenGlareOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroArrivingAtBslProcessOam_Empty;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_MONOLOGUE_CURSOR)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sIntroArrivingAtBslMonologueCursorOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessMonologueCursor;
    }
    else if (type == INTRO_ARRIVING_AT_BSL_OAM_TYPE_UNK_255)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = unk_9043c;
    }

    return slot;
}

 /**
 * @brief 90c60 | 9c | V-blank for the arriving at BSL cutscene
 * 
 */
void NewFileIntroArrivingAtBslVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);
    WRITE_16(REG_BG0HOFS, gBg0XPosition);
    WRITE_16(REG_BG0VOFS, gBg0YPosition);
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);
    
    unk_98158();
}

 /**
 * @brief 90cfc | 60 | Returns slot, X and Y position of a new file intro OAM
 * 
 */
u8 NewFileIntroGetPositionAndSlotOfOamByType(IntroArrivingAtBslOamType type, s16* pXPosition, s16* pYPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == type)
        {
            *pXPosition = INTRO_DATA.oam[slot].xPosition;
            *pYPosition = INTRO_DATA.oam[slot].yPosition;
        
            return slot;
        }
    }

    // Default values if not found
    *pXPosition = 300;
    *pYPosition = 200;
        
    return ARRAY_SIZE(INTRO_DATA.oam);
}

 /**
 * @brief 90d5c | 4 | Empty OAM handler function
 * 
 */
void NewFileIntroArrivingAtBslProcessOam_Empty(struct SpecialCutsceneOam* pOam)
{
    return;
}

 /**
 * @brief 90d60 | 1f4 | Setup for the landing on BSL cutscene
 * 
 */
void NewFileIntroLandingOnBslInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    LZ77UncompVram(sIntroLandingOnBslObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sIntroLandingOnBslObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sIntroLandingOnBslBgGfx, VRAM_BASE);
    LZ77UncompVram(sIntroLandingOnBslHangarTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroLandingOnBslSpaceTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroLandingOnBslBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    gBg2XPosition = 0;
    gBg2YPosition = 40;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 40);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_BG_SCROLLER, SCREEN_X_MIDDLE, 0, FALSE);
    NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_LANDING_LIGHTS, 128, 100 - gBg2YPosition, TRUE);
    NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR, 128, 72 - gBg2YPosition, FALSE);
    NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_LIGHT, 0, 0, FALSE);
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(NewFileIntroLandingOnBslVblank);
}

 /**
 * @brief 90f54 | 128 | Processes the landing on BSL cutscene
 * 
 */
boolu32 NewFileIntroLandingOnBslProcess(void)
{
    boolu32 finished;

    finished = FALSE;

    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (gWrittenToBldy)
            {
                gWrittenToBldy--;
            }
            else
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 1;
                PlayMusic(MUSIC_MAIN_DECK_AMBIENCE, 13);
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 1:
            if (gBg2YPosition == 0)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 2;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1 + 1.f / 6))
            {
                INTRO_DATA.timer = 0;
                NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_SHIP, 128, 50, FALSE);
                INTRO_DATA.subStage = 3;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 3:
            INTRO_DATA.timer = 0;
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 4:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.5f))
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 5;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 5:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 30))
            {
                INTRO_DATA.timer = 0;
    
                if (gWrittenToBldy < BLDY_MAX_VALUE)
                    gWrittenToBldy++;
                else
                    finished = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

 /**
 * @brief 9107c | 88 | Main handler for the landing on BSL cutscene
 * 
 */
boolu32 NewFileIntroLandingOnBsl(void)
{
    boolu32 finished;

    finished = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            NewFileIntroLandingOnBslInit();
            INTRO_DATA.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();

            if (!gWrittenToBldy)
                INTRO_DATA.stage = 2;
            break;
        
        case 2:
            if (NewFileIntroLandingOnBslProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;
        
        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                INTRO_DATA.stage = 0;
                finished = TRUE;
            }
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return finished;
}

 /**
 * @brief 91104 | 74 | Handles the background scrolling in the landing on BSL cutscene
 * 
 */
void NewFileIntroProcessLandingOnBslScroll(struct SpecialCutsceneOam* pOam)
{
    INTRO_DATA.unk_217 = 0;

    APPLY_DELTA_TIME_INC(pOam->timer);

    if (pOam->stage == 0)
    {
        pOam->yPosition = gBg2YPosition;
        pOam->timer = 0;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        INTRO_DATA.unk_217 = 0;

        if (pOam->timer == 4)
        {
            pOam->timer = 0;

            if (pOam->yPosition > 0)
            {
                INTRO_DATA.unk_217 = -1;
                pOam->yPosition--;
                gBg2YPosition = pOam->yPosition;
            }
            else
            {
                INTRO_DATA.unk_217 = 0;
                pOam->type = 0;
            }
        }
    }
    else
    {
        pOam->timer = 0;
    }
}

 /**
 * @brief 91178 | a4 | Processes the hangar door in the intro
 * 
 */
void NewFileIntroProcessBslDoor(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    if (pOam->stage == 0)
    {
        NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_PALETTE_CHANGER, 0, 0, FALSE);
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
        pOam->pOam = sIntroBslHangarDoorOam_Opening;
        SoundPlay_3b1c(SOUND_246);
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_TOP, pOam->xPosition, pOam->yPosition, TRUE);
        NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_BOTTOM, pOam->xPosition, pOam->yPosition, TRUE);
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
    
    pOam->yPosition -= INTRO_DATA.unk_217;
}

 /**
 * @brief 9121c | 7c | Processes the hangar door lights in the intro
 * 
 */
void NewFileIntroProcessBslDoorLight(struct SpecialCutsceneOam* pOam)
{
    pOam->unk_A++;
    if (pOam->unk_A == 8)
    {
        pOam->unk_A = 0;
        INTRO_DATA.unk_110 = 1;
        
        if (INTRO_DATA.unk_111 < 5)
            INTRO_DATA.unk_111++;
        else
            INTRO_DATA.unk_111 = 0;
    }

    APPLY_DELTA_TIME_INC(pOam->timer);
    if (pOam->timer == 8)
    {
        pOam->timer = 0;
        INTRO_DATA.unk_12C = 1;
        
        if (INTRO_DATA.unk_12D < 7)
            INTRO_DATA.unk_12D++;
        else
            INTRO_DATA.unk_12D = 0;
    }
}

 /**
 * @brief 91298 | e8 | Processes the top half of the BSL hangar door in the intro
 * 
 */
void NewFileIntroProcessBslDoorTop(struct SpecialCutsceneOam* pOam)
{
    s16 x;
    s16 y;

    pOam->unk_A++;
    
    if (pOam->stage == 0)
    {
        pOam->unk_A = 0;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        if (pOam->unk_A == 8)
        {
            pOam->unk_A = 0;
            
            if (pOam->spawnY < 54)
            {
                pOam->spawnY++;
                pOam->yPosition--;
            }
            else
            {
                pOam->stage = 2;
            }
        }
    }
    else if (pOam->stage == 2)
    {
        // Bug: Checks for a nonexistent OAM
        NewFileIntroGetPositionAndSlotOfOamByType_2(INTRO_LANDING_ON_BSL_OAM_TYPE_SHIP_UNUSED, &x, &y);

        if (y > 90) // This is always true because the default Y for nonexistent OAMs is 200
        {
            pOam->unk_A = 0;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        if (pOam->unk_A == 8)
        {
            pOam->unk_A = 0;
            
            if (pOam->spawnY > 0)
            {
                pOam->spawnY--;
                if (pOam->spawnY == 37)
                    NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_SHIP_ARMS_EXTENDING, 0, 0, TRUE);

                pOam->yPosition++;
            }
            else
            {
                // This branch appears to never get hit
                pOam->stage = 4;
                NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_UNUSED, pOam->xPosition, pOam->yPosition, TRUE);
            }
        }
    }
    else if (pOam->stage == 4)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
    
    pOam->yPosition -= INTRO_DATA.unk_217;
}

 /**
 * @brief 91380 | c4 | Processes the bottom half of the BSL hangar door in the intro
 * 
 */
void NewFileIntroProcessBslDoorBottom(struct SpecialCutsceneOam* pOam)
{
    s16 x;
    s16 y;

    pOam->unk_A++;
    
    if (pOam->stage == 0)
    {
        pOam->unk_A = 0;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        if (pOam->unk_A == 8)
        {
            pOam->unk_A = 0;
            
            if (pOam->spawnY < 54)
            {
                pOam->spawnY++;
                pOam->yPosition++;
            }
            else
            {
                pOam->stage = 2;
            }
        }
    }
    else if (pOam->stage == 2)
    {
        // Bug: Checks for a nonexistent OAM
        NewFileIntroGetPositionAndSlotOfOamByType_2(INTRO_LANDING_ON_BSL_OAM_TYPE_SHIP_UNUSED, &x, &y);
        
        if (y > 90) // This is always true because the default Y for nonexistent OAMs is 200
        {
            pOam->unk_A = 0;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        if (pOam->unk_A == 8)
        {
            pOam->unk_A = 0;
            
            if (pOam->spawnY > 0)
            {
                pOam->spawnY--;
                pOam->yPosition--;
            }
            else
            {
                pOam->stage = 4;
            }
        }
    }
    else if (pOam->stage == 4)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
    
    pOam->yPosition -= INTRO_DATA.unk_217;
}

 /**
 * @brief 91444 | 64 | Processes the intro hangar palette changing effect
 * 
 */
void NewFileIntroProcessHangarPalettes(struct SpecialCutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        INTRO_DATA.unk_148 = 0;
        INTRO_DATA.unk_149 = 5;
        pOam->stage = 1;
    }

    pOam->unk_A++;
    if (pOam->unk_A == 75)
    {
        pOam->unk_A = 0;
        INTRO_DATA.unk_148 = 1;
        
        if (INTRO_DATA.unk_149 < 9)
            INTRO_DATA.unk_149++;
        else
            pOam->type = 0;
    }
}

 /**
 * @brief 914a8 | 334 | Processes Samus' ship in the landing on BSL cutscene (unused)
 * 
 */
void NewFileIntroProcessShipLanding_Unused(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;
    s16 x;
    s16 y;

    pOam->unk_A++;
    
    if (pOam->stage == 0)
    {
        if (NewFileIntroGetPositionAndSlotOfOamByType_2(INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_TOP, &x, &y) != ARRAY_SIZE(INTRO_DATA.oam))
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        NewFileIntroGetPositionAndSlotOfOamByType_2(INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_TOP, &x, &y);

        pOam->yPosition = (pOam->unk_A >> 2) + pOam->spawnY;
        if (pOam->yPosition - y > 8)
        {
            INTRO_DATA.unk_1F0 = 1;
            INTRO_DATA.unk_1F1 = 1;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->unk_A = 0;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        APPLY_DELTA_TIME_INC(pOam->timer);

        if (INTRO_DATA.unk_1F1 < 7)
        {
            pOam->yPosition = (pOam->unk_A >> 2) + pOam->spawnY;

            if (pOam->timer == CONVERT_SECONDS(1.f / 5))
            {
                pOam->timer = 0;
                INTRO_DATA.unk_1F0 = 1;
                INTRO_DATA.unk_1F1++;
                pOam->spawnX = pOam->xPosition;
                pOam->spawnY = pOam->yPosition;
                pOam->unk_A = 0;
            }
        }
        else if (INTRO_DATA.unk_1F1 == 7)
        {
            if (pOam->unk_A == 2)
            {
                pOam->unk_A = 0;
                pOam->yPosition++;
            }

            if (pOam->timer == CONVERT_SECONDS(1.f / 5))
            {
                pOam->timer = 0;
                pOam->pOam = sIntroShipLandingOam_Unused2;
                INTRO_DATA.unk_1F0 = 1;
                INTRO_DATA.unk_1F1++;
            }
        }
        else if (INTRO_DATA.unk_1F1 == 8)
        {
            if (pOam->unk_A == 2)
            {
                pOam->unk_A = 0;
                pOam->yPosition++;
            }

            if (pOam->timer == CONVERT_SECONDS(1.f / 6))
            {
                pOam->timer = 0;
                pOam->priority = 1;
                INTRO_DATA.unk_1F0 = 1;
                INTRO_DATA.unk_1F1++;
            }
        }
        else if (INTRO_DATA.unk_1F1 < 14)
        {
            if (pOam->unk_A == 2)
            {
                pOam->unk_A = 0;
                pOam->yPosition++;
            }

            if (pOam->timer == CONVERT_SECONDS(2.f / 15))
            {
                pOam->timer = 0;
                INTRO_DATA.unk_1F0 = 1;
                INTRO_DATA.unk_1F1++;
            }
        }
        else if (INTRO_DATA.unk_1F1 == 14)
        {
            if (pOam->unk_A == 2)
            {
                pOam->unk_A = 0;
                pOam->yPosition++;
            }

            if (pOam->timer == CONVERT_SECONDS(2.f / 15))
            {
                pOam->timer = 0;
                pOam->pOam = sIntroShipLandingOam;
                INTRO_DATA.unk_1F0 = 1;
                INTRO_DATA.unk_1F1++;
                pOam->spawnX = pOam->xPosition;
                pOam->spawnY = pOam->yPosition;
                pOam->unk_A = 0;
                pOam->stage = 3;
            }
        }

        if (pOam->yPosition > 80)
            pOam->yPosition = 80;
    }
    else if (pOam->stage == 3)
    {
        if (pOam->unk_A == 20)
        {
            pOam->unk_A = 0;
            pOam->stage = 4;
            NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_SMOKE, pOam->xPosition, 150, FALSE);
        }
    }
    else if (pOam->stage == 4)
    {
        pOam->unk_8++;
        if (pOam->unk_8 > 255)
            pOam->unk_8 -= 256;
        
        pOam->unk_A = 0;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
        pOam->affineMode = OAM_AFFINE_MODE_NORMAL;
        pOam->pOam = sIntroShipLandingOam_Hovering;
        pOam->stage = 5;
    }
    else if (pOam->stage == 5)
    {
        pOam->yPosition = (pOam->unk_A >> 4) + pOam->spawnY;
        if (pOam->yPosition > 90 && pOam->currentAnimationFrame == 0 && pOam->animationDurationCounter == 1)
        {
            pOam->pOam = sIntroShipLandingOam_ExtendingLandingGear;
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 6;
        }
    }
    else if (pOam->stage == 6)
    {
        pOam->yPosition = (pOam->unk_A >> 4) + pOam->spawnY;

        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroShipLandingOam_ExtendedLandingGearIdle;
            pOam->stage = 7;
        }
    }
    else if (pOam->stage == 7)
    {
        pOam->yPosition = (pOam->unk_A >> 4) + pOam->spawnY;
        if (pOam->yPosition > 103)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroShipLandingOam_ExtendedLandingGearHovering;
            pOam->stage = 8;
        }
    }
    else if (pOam->stage == 8)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroShipLandingOam_ExtendedLandingGearIdle;
            INTRO_DATA.subStage = 4;
            pOam->stage = 9;
        }
    }
}

 /**
 * @brief 917dc | cc | Processes the smoke in the landing on BSL cutscene
 * 
 */
void NewFileIntroProcessShipLandingSmoke(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;
    s16 x;
    s16 y;

    if (pOam->stage == 0)
    {
        NewFileIntroGetPositionAndSlotOfOamByType_2(INTRO_LANDING_ON_BSL_OAM_TYPE_SHIP, &x, &y);
        pOam->xPosition = x;
        pOam->yPosition = 150;

        if (y > 100)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->unk_A = 0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroShipLandingSmokeOam_2;
                pOam->stage = 1;
            }
        }
    }
    else if (pOam->stage == 1)
    {
        NewFileIntroGetPositionAndSlotOfOamByType_2(INTRO_LANDING_ON_BSL_OAM_TYPE_SHIP, &x, &y);
        pOam->xPosition = x;
        pOam->yPosition = 150;

        if (y > 103)
        {
            frame = &pOam->pOam[pOam->currentAnimationFrame];
            if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            {
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->stage = 2;
            }
        }
    }
    else if (pOam->stage == 2)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

 /**
 * @brief 918a8 | 44 | Processes the hangar door closing in the intro (unused)
 * 
 */
void NewFileIntroProcessBslDoorClosing_Unused(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    if (pOam->stage == 0)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroBslHangarDoorOam_Closed;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->animationDurationCounter = 0;
    }
}

 /**
 * @brief 918ec | 64 | Processes the ship arms extending in the landing on BSL cutscene
 * 
 */
void NewFileIntroProcessExtendingShipArms(struct SpecialCutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        INTRO_DATA.unk_148 = 0;
        INTRO_DATA.unk_149 = 9;
        pOam->stage = 1;
    }
    
    pOam->unk_A++;
    if (pOam->unk_A == 75)
    {
        pOam->unk_A = 0;
        INTRO_DATA.unk_148 = 1;
        
        if (INTRO_DATA.unk_149 > 6)
            INTRO_DATA.unk_149--;
        else
            pOam->type = 0;
    }
}

 /**
 * @brief 91950 | 1c | Processes the landing lights in the landing on BSL cutscene
 * 
 */
void NewFileIntroProcessLandingLights(struct SpecialCutsceneOam* pOam)
{
    pOam->yPosition -= INTRO_DATA.unk_217;
}

 /**
 * @brief 9196c | 208 | Processes Samus' ship in the landing on BSL cutscene
 * 
 */
void NewFileIntroProcessShipLanding(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

    pOam->unk_A++;
    
    if (pOam->stage == 0)
    {
        pOam->unk_A = 0;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 2;
    }
    else if (pOam->stage == 1)
    {
        pOam->yPosition = (pOam->unk_A >> 2) + pOam->spawnY;
        pOam->unk_A = 0;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 2;
    }
    else if (pOam->stage == 2)
    {
        if (pOam->scaling < Q_8_8(1))
        {
            pOam->scaling++;
            if (pOam->scaling >= Q_8_8(1))
            {
                pOam->scaling = Q_8_8(1);
                pOam->affineMode = OAM_AFFINE_MODE_NORMAL;
            }
            else if (pOam->scaling >= Q_8_8(.75f))
            {
                pOam->priority = 1;
            }
        }

        pOam->yPosition = (pOam->unk_A >> 2) + pOam->spawnY;
        if (pOam->yPosition > SCREEN_Y_MIDDLE)
        {
            pOam->yPosition = SCREEN_Y_MIDDLE;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = SCREEN_Y_MIDDLE;
            pOam->unk_A = 0;

            if (pOam->scaling == Q_8_8(1))
            {
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = sIntroShipLandingOam_Idle;
                pOam->stage = 3;
            }
        }
    }
    else if (pOam->stage == 3)
    {
        if (pOam->unk_A > 4)
        {
            pOam->unk_A = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroShipLandingOam_Hovering;
            pOam->stage = 4;
            NewFileIntroLandingOnBslSetupOam(INTRO_LANDING_ON_BSL_OAM_TYPE_SMOKE, pOam->xPosition, 150, FALSE);
        }
    }
    else if (pOam->stage == 4)
    {
        pOam->unk_A = 0;
        
        if (pOam->currentAnimationFrame == 6)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroShipLandingOam_Idle;
            pOam->stage = 5;
        }
    }
    else if (pOam->stage == 5)
    {
        if (pOam->unk_A > 10)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->stage = 6;
        }
    }
    else if (pOam->stage == 6)
    {
        pOam->yPosition = (pOam->unk_A >> 3) + pOam->spawnY;
        if (pOam->yPosition > 88)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroShipLandingOam_ExtendingLandingGear;
            pOam->stage = 7;
        }
    }
    else if (pOam->stage == 7)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
            pOam->animationDurationCounter = 0;

        pOam->yPosition = (pOam->unk_A >> 3) + pOam->spawnY;
        if (pOam->yPosition > 103)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroShipLandingOam_ExtendedLandingGearHovering;
            pOam->stage = 8;
        }
    }
    else if (pOam->stage == 8)
    {
        frame = &pOam->pOam[pOam->currentAnimationFrame];
        if (frame[0].timer == pOam->animationDurationCounter && frame[1].timer == 0)
        {
            pOam->unk_A = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = sIntroShipLandingOam_ExtendedLandingGearIdle;
            pOam->stage = 9;
            INTRO_DATA.subStage = 4;
        }
    }

    pOam->yPosition -= INTRO_DATA.unk_217;
}

 /**
 * @brief 91b74 | 388 | Spawns a new OAM for the landing on BSL cutscene
 * 
 */
u8 NewFileIntroLandingOnBslSetupOam(IntroLandingOnBslOamType type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
{
    s8 slot;

    if (!descendingSearch)
    {
        for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
        {
            if (INTRO_DATA.oam[slot].type == 0)
                break;
        }

        if (slot >= ARRAY_SIZE(INTRO_DATA.oam))
            return ARRAY_SIZE(INTRO_DATA.oam);
    }
    else
    {
        for (slot = ARRAY_SIZE(INTRO_DATA.oam) - 1; slot >= 0; slot--)
        {
            if (INTRO_DATA.oam[slot].type == 0)
                break;
        }

        if (slot < 0)
            return ARRAY_SIZE(INTRO_DATA.oam);
    }

    DMA3_FILL_32(0, &INTRO_DATA.oam[slot], sizeof(struct SpecialCutsceneOam));

    INTRO_DATA.oam[slot].xPosition = xPosition;
    INTRO_DATA.oam[slot].yPosition = yPosition;
    INTRO_DATA.oam[slot].type = type;
    INTRO_DATA.oam[slot].unk_18_0 = 1;

    if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_BG_SCROLLER)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessLandingOnBslScroll;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroBslHangarDoorOam_Closed;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessBslDoor;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_LIGHT)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessBslDoorLight;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_TOP)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroBslHangarDoorOam_Top;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessBslDoorTop;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_BOTTOM)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroBslHangarDoorOam_Bottom;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessBslDoorBottom;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_PALETTE_CHANGER)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessHangarPalettes;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_SHIP_UNUSED)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroShipLandingOam_Unused1;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessShipLanding_Unused;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_SMOKE)
    {
        INTRO_DATA.oam[slot].pOam = sIntroShipLandingSmokeOam_1;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessShipLandingSmoke;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_DOOR_UNUSED)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroBslHangarDoorOam_Closing;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessBslDoorClosing_Unused;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_SHIP_ARMS_EXTENDING)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessExtendingShipArms;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_LANDING_LIGHTS)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sIntroBslLandingLightsOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessLandingLights;
    }
    else if (type == INTRO_LANDING_ON_BSL_OAM_TYPE_SHIP)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1.f / 128);
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sIntroShipLandingOam;
        INTRO_DATA.oam[slot].pFunction = NewFileIntroProcessShipLanding;
    }

    return slot;
}

 /**
 * @brief 91efc | 13c | V-blank for the landing on BSL cutscene
 * 
 */
void NewFileIntroLandingOnBslVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);
    
    WRITE_16(REG_BG2HOFS, gBg2XPosition);
    WRITE_16(REG_BG2VOFS, gBg2YPosition);
    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);

    if (INTRO_DATA.unk_110 == 1)
    {
        INTRO_DATA.unk_110 = 0;
        DMA3_COPY_32(&sIntroPal_5ffb08[INTRO_DATA.unk_111 * PAL_ROW], PALRAM_OBJ + 10 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
    }

    if (INTRO_DATA.unk_12C == 1)
    {
        INTRO_DATA.unk_12C = 0;
        DMA3_COPY_32(&sIntroPal_5ff908[INTRO_DATA.unk_12D * PAL_ROW], PALRAM_OBJ + 8 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
    }

    if (INTRO_DATA.unk_148 == 1)
    {
        INTRO_DATA.unk_148 = 0;
        DMA3_COPY_32(&sIntroPal_5ffb08[INTRO_DATA.unk_149 * PAL_ROW], PALRAM_OBJ + 9 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
        DMA3_COPY_32(&sIntroPal_5ffb08[INTRO_DATA.unk_149 * PAL_ROW], PALRAM_BASE + 11 * PAL_ROW_SIZE, PAL_ROW_SIZE / sizeof(u32));
    }
}

 /**
 * @brief 92038 | 60 | Returns slot, X and Y position of a new file intro OAM
 * 
 */
u8 NewFileIntroGetPositionAndSlotOfOamByType_2(IntroLandingOnBslOamType type, s16* pXPosition, s16* pYPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(INTRO_DATA.oam); slot++)
    {
        if (INTRO_DATA.oam[slot].type == type)
        {
            *pXPosition = INTRO_DATA.oam[slot].xPosition;
            *pYPosition = INTRO_DATA.oam[slot].yPosition;
        
            return slot;
        }
    }

    // Default values if not found
    *pXPosition = 300;
    *pYPosition = 200;
        
    return ARRAY_SIZE(INTRO_DATA.oam);
}

 /**
 * @brief 92098 | 4 | Empty function
 * 
 */
void unk_92098(void)
{
    return;
}

