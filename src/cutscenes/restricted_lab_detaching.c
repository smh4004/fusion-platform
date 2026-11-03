#include "cutscene.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "syscalls.h"
#include "init_helpers.h"
#include "oam.h"
#include "text.h"
#include "audio_wrappers.h"
#include "music_wrappers.h"
#include "audio/track_internal.h"
#include "new_file_intro.h"

#include "constants/audio.h"
#include "constants/text.h"

#include "data/audio.h"
#include "data/generic_data.h"
#include "data/intro_data.h"
#include "data/sprite_data.h"
#include "data/haze_data.h"
extern const u8 sBlob_68121c_68141c[];
extern const u8 sBlob_681a1c_682fac[];
extern const u8 sAddr_679420[];
extern const u8 sAddr_67d7cc[];
extern const u8 sAddr_680d54[];
extern const u8 sAddr_680d64[];
extern const u8 sAddr_680d74[];
extern const u8 sAddr_680d84[];
extern const u8 sAddr_680d94[];
extern const u8 sAddr_680da4[];
extern const u8 sAddr_680dcc[];
extern const u8 sAddr_680e2c[];
extern const u8 sAddr_680e3c[];
extern const u8 sAddr_680f2c[];
extern const u8 sAddr_680f74[];
extern const u8 sAddr_680f9c[];
extern const u8 sAddr_680fc4[];
extern const u8 sAddr_680fec[];
extern const u8 sAddr_6820a4[];
extern const u8 sAddr_68259c[];

/**
 * @brief 9ae18 | 8c | Main handler for the restricted lab detaching cutscene
 *
 */
boolu32 CutsceneRestrictedLabDetaching(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (CUTSCENE_OAM_DATA.stage)
    {
        case 0:
            CUTSCENE_OAM_DATA.stage = 1;
            CutsceneRestrictedLabDetachingInit();
            break;

        case 1:
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                SoundPlay_3b1c(SOUND_248);

            CutsceneFadeIn();
            if (gWrittenToBldy == 0)
                CUTSCENE_OAM_DATA.stage++;
            break;

        case 2:
            if (CutsceneRestrictedLabDetachingProcess())
            {
                CUTSCENE_OAM_DATA.stage = 3;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
            }
            break;

        case 3:
            CutsceneFadeOut();
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 9aea4 | 15c | Setup for the restricted lab detaching cutscene
 *
 */
void CutsceneRestrictedLabDetachingInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_9c1bc);
    unk_36c4();

    WRITE_16(REG_DISPCNT, 0);

    LZ77UncompVram((const u32*)sAddr_67d7cc, VRAM_OBJ);
    DMA3_COPY_32((const u16*)(&sBlob_68121c_68141c), PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);

    LZ77UncompVram((const u32*)sAddr_679420, VRAM_BASE);
    LZ77UncompVram((const u32*)sAddr_6820a4, VRAM_BASE + 0xE000);
    LZ77UncompVram((const u32*)(&sBlob_681a1c_682fac), VRAM_BASE + 0xE800);
    DMA3_COPY_32((const u16*)sAddr_68259c, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
    WRITE_16(PALRAM_BASE, 0);

    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 29, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 28, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);

    gWrittenToBldy = BLDY_MAX_VALUE;

    CutsceneRestrictedLabDetachingSetupOam(1, 150, 90);
    CutsceneRestrictedLabDetachingSetupOam(3, 150, 90);
    CutsceneRestrictedLabDetachingSetupOam(2, 150, 90);
    CutsceneRestrictedLabDetachingSetupOam(4, 120, 0);

    CutsceneProcessOam();
    CutsceneDrawAllOam();

    CUTSCENE_OAM_DATA.unk_A = 0;
    CUTSCENE_OAM_DATA.unk_C = 0;
    DMA3_COPY_32(&sCutsceneBslFirePal[CUTSCENE_OAM_DATA.unk_C * 16], PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);

    CallbackSetVBlank(CutsceneRestrictedLabDetachingVblank);
}

// 0x0809B000
NAKED_FUNCTION
boolu32 CutsceneRestrictedLabDetachingProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #0xc\n\
	movs r7, #0\n\
	ldr r0, _0809B01C @ =gNonGameplayRam\n\
	ldrb r1, [r0, #0x10]\n\
	adds r5, r0, #0\n\
	cmp r1, #0xa\n\
	bls _0809B012\n\
	b _0809B356\n\
_0809B012:\n\
	lsls r0, r1, #2\n\
	ldr r1, _0809B020 @ =_0809B024\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0809B01C: .4byte gNonGameplayRam\n\
_0809B020: .4byte _0809B024\n\
_0809B024: @ jump table\n\
	.4byte _0809B050 @ case 0\n\
	.4byte _0809B068 @ case 1\n\
	.4byte _0809B178 @ case 2\n\
	.4byte _0809B356 @ case 3\n\
	.4byte _0809B356 @ case 4\n\
	.4byte _0809B1B0 @ case 5\n\
	.4byte _0809B218 @ case 6\n\
	.4byte _0809B236 @ case 7\n\
	.4byte _0809B268 @ case 8\n\
	.4byte _0809B2C8 @ case 9\n\
	.4byte _0809B308 @ case 10\n\
_0809B050:\n\
	ldrh r0, [r5, #8]\n\
	adds r0, #1\n\
	strh r0, [r5, #8]\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #1\n\
	beq _0809B060\n\
	b _0809B356\n\
_0809B060:\n\
	movs r0, #0\n\
	strh r0, [r5, #8]\n\
	strb r1, [r5, #0x10]\n\
	b _0809B356\n\
_0809B068:\n\
	ldrh r0, [r5, #8]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strh r0, [r5, #8]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bne _0809B0C0\n\
	mov r4, sp\n\
	adds r4, #6\n\
	movs r0, #2\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x14\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0x14\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #2\n\
	rsbs r3, r3, #0\n\
	movs r0, #6\n\
	str r0, [sp]\n\
	movs r0, #0x11\n\
	bl unk_9c0b4\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x46\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0x1a\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #1\n\
	rsbs r3, r3, #0\n\
	movs r0, #4\n\
	b _0809B156\n\
_0809B0C0:\n\
	cmp r0, #0x10\n\
	bne _0809B10C\n\
	mov r4, sp\n\
	adds r4, #6\n\
	movs r0, #2\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x1e\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0x1e\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #2\n\
	rsbs r3, r3, #0\n\
	movs r5, #8\n\
	str r5, [sp]\n\
	movs r0, #0x11\n\
	bl unk_9c0b4\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x32\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #8\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #1\n\
	rsbs r3, r3, #0\n\
	str r5, [sp]\n\
	b _0809B158\n\
_0809B10C:\n\
	cmp r0, #0x14\n\
	bne _0809B160\n\
	mov r4, sp\n\
	adds r4, #6\n\
	movs r0, #2\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x50\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0xe\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #3\n\
	rsbs r3, r3, #0\n\
	movs r0, #6\n\
	str r0, [sp]\n\
	movs r0, #0x11\n\
	bl unk_9c0b4\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0xa\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0x12\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #2\n\
	rsbs r3, r3, #0\n\
	movs r0, #2\n\
_0809B156:\n\
	str r0, [sp]\n\
_0809B158:\n\
	movs r0, #0x11\n\
	bl unk_9c0b4\n\
	b _0809B356\n\
_0809B160:\n\
	cmp r0, #0xaa\n\
	beq _0809B166\n\
	b _0809B356\n\
_0809B166:\n\
	strh r1, [r5, #8]\n\
	movs r0, #2\n\
	strb r0, [r5, #0x10]\n\
	ldr r0, _0809B174 @ =gWrittenToBldy\n\
	strh r1, [r0]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B174: .4byte gWrittenToBldy\n\
_0809B178:\n\
	ldr r1, _0809B1A0 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bls _0809B1B8\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	movs r0, #0\n\
	str r0, [sp, #8]\n\
	ldr r1, _0809B1A4 @ =0x040000D4\n\
	add r0, sp, #8\n\
	str r0, [r1]\n\
	ldr r2, _0809B1A8 @ =0x0300149C\n\
	str r2, [r1, #4]\n\
	ldr r0, _0809B1AC @ =0x85000090\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	subs r2, #0x18\n\
	movs r0, #5\n\
	strb r0, [r2, #0x10]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B1A0: .4byte gWrittenToBldy\n\
_0809B1A4: .4byte 0x040000D4\n\
_0809B1A8: .4byte 0x0300149C\n\
_0809B1AC: .4byte 0x85000090\n\
_0809B1B0:\n\
	ldr r1, _0809B1C0 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _0809B1C4\n\
_0809B1B8:\n\
	adds r0, #2\n\
	strh r0, [r1]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B1C0: .4byte gWrittenToBldy\n\
_0809B1C4:\n\
	movs r5, #0\n\
	str r5, [sp, #8]\n\
	ldr r1, _0809B208 @ =0x040000D4\n\
	add r0, sp, #8\n\
	str r0, [r1]\n\
	ldr r4, _0809B20C @ =0x0300149C\n\
	str r4, [r1, #4]\n\
	ldr r0, _0809B210 @ =0x85000090\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	subs r4, #0x18\n\
	strh r5, [r4, #8]\n\
	movs r0, #4\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	movs r0, #0x1e\n\
	movs r1, #0xcd\n\
	movs r2, #0xa\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	movs r0, #0xc\n\
	movs r1, #0x8c\n\
	movs r2, #0x50\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	ldr r0, _0809B214 @ =0x04000018\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	movs r0, #6\n\
	strb r0, [r4, #0x10]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B208: .4byte 0x040000D4\n\
_0809B20C: .4byte 0x0300149C\n\
_0809B210: .4byte 0x85000090\n\
_0809B214: .4byte 0x04000018\n\
_0809B218:\n\
	ldr r2, _0809B228 @ =gWrittenToBldy\n\
	ldrh r0, [r2]\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	beq _0809B22C\n\
	subs r0, #2\n\
	strh r0, [r2]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B228: .4byte gWrittenToBldy\n\
_0809B22C:\n\
	strh r1, [r2]\n\
	strh r1, [r5, #8]\n\
	movs r0, #7\n\
	strb r0, [r5, #0x10]\n\
	b _0809B356\n\
_0809B236:\n\
	ldrh r0, [r5, #8]\n\
	adds r0, #1\n\
	strh r0, [r5, #8]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x95\n\
	bne _0809B258\n\
	ldr r0, _0809B250 @ =gWrittenToBldalpha_Eva\n\
	movs r1, #0xa\n\
	strh r1, [r0]\n\
	ldr r0, _0809B254 @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B250: .4byte gWrittenToBldalpha_Eva\n\
_0809B254: .4byte gWrittenToBldalpha_Evb\n\
_0809B258:\n\
	cmp r0, #0x96\n\
	beq _0809B25E\n\
	b _0809B356\n\
_0809B25E:\n\
	movs r0, #0\n\
	strh r0, [r5, #8]\n\
	movs r0, #8\n\
	strb r0, [r5, #0x10]\n\
	b _0809B356\n\
_0809B268:\n\
	ldrh r0, [r5, #8]\n\
	adds r0, #1\n\
	movs r6, #0\n\
	strh r0, [r5, #8]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bne _0809B356\n\
	ldr r1, _0809B2C0 @ =0x04000050\n\
	ldr r2, _0809B2C4 @ =0x00001C42\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #2\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	mov r4, sp\n\
	adds r4, #6\n\
	movs r0, #0xc\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType\n\
	movs r0, #0xc\n\
	bl CutsceneDestroyOamOfType\n\
	add r0, sp, #4\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	movs r3, #0\n\
	ldrsh r2, [r4, r3]\n\
	str r6, [sp]\n\
	movs r0, #0x10\n\
	movs r3, #0\n\
	bl unk_9c0b4\n\
	strh r6, [r5, #8]\n\
	movs r0, #9\n\
	strb r0, [r5, #0x10]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B2C0: .4byte 0x04000050\n\
_0809B2C4: .4byte 0x00001C42\n\
_0809B2C8:\n\
	ldrh r0, [r5, #8]\n\
	adds r1, r0, #1\n\
	movs r3, #0\n\
	strh r1, [r5, #8]\n\
	ldrh r2, [r5, #0xc]\n\
	movs r4, #0xc\n\
	ldrsh r0, [r5, r4]\n\
	cmp r0, #0xe\n\
	bgt _0809B2EE\n\
	lsls r0, r1, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #4\n\
	bne _0809B356\n\
	strh r3, [r5, #8]\n\
	movs r0, #1\n\
	strh r0, [r5, #0xa]\n\
	adds r0, r2, #1\n\
	strh r0, [r5, #0xc]\n\
	b _0809B356\n\
_0809B2EE:\n\
	lsls r0, r1, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xf\n\
	bne _0809B356\n\
	strh r3, [r5, #8]\n\
	ldr r0, _0809B304 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	movs r0, #0xa\n\
	strb r0, [r5, #0x10]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B304: .4byte gWrittenToBldy\n\
_0809B308:\n\
	adds r3, r5, #0\n\
	ldrh r0, [r3, #8]\n\
	adds r2, r0, #1\n\
	movs r4, #0\n\
	strh r2, [r3, #8]\n\
	ldr r6, _0809B32C @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r6]\n\
	cmp r1, #0xf\n\
	bhi _0809B330\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #6\n\
	bne _0809B356\n\
	strh r4, [r3, #8]\n\
	adds r0, r1, #1\n\
	strh r0, [r6]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B32C: .4byte gWrittenToBldalpha_Eva\n\
_0809B330:\n\
	ldr r1, _0809B368 @ =0x04000050\n\
	movs r0, #0xbf\n\
	strh r0, [r1]\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x10\n\
	bne _0809B356\n\
	strh r4, [r5, #8]\n\
	str r4, [sp, #8]\n\
	adds r1, #0x84\n\
	add r0, sp, #8\n\
	str r0, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0x18\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809B36C @ =0x85000090\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r7, #1\n\
_0809B356:\n\
	bl CutsceneProcessOam\n\
	bl CutsceneDrawAllOam\n\
	adds r0, r7, #0\n\
	add sp, #0xc\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809B368: .4byte 0x04000050\n\
_0809B36C: .4byte 0x85000090\n\
    .syntax divided\n");
}

/**
 * @brief 9b370 | cc | Processes the falling restricted lab
 *
 */
void CutsceneRestrictedLabDetachingProcessFallingLab(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = (pOam->unk_E >> 1) + pOam->spawnX;
        pOam->yPosition = pOam->spawnY - (pOam->unk_E >> 2);
    }

    pOam->timer++;
    if (pOam->timer == 10)
    {
        pOam->timer = 0;
        if (pOam->unk_E < 220)
            pOam->scaling += 2;
        else if (pOam->unk_E < 440)
            pOam->scaling += 4;
        else
            pOam->scaling += 6;

        if (pOam->scaling > 0x1FF)
            pOam->scaling = 0x200;
    }

    pOam->unk_A++;
    if (pOam->unk_A == 6)
    {
        pOam->unk_A = 0;
        pOam->unk_C++;
        if (pOam->unk_C > 15)
            pOam->unk_C = 0;
    }

    if ((u16)(pOam->xPosition + 16) > 306 || pOam->yPosition < -50 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9b43c | 470 | Sets up a restricted lab detaching OAM
 *
 */
u8 CutsceneRestrictedLabDetachingSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_OAM_DATA.oam); slot++)
    {
        if (CUTSCENE_OAM_DATA.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(CUTSCENE_OAM_DATA.oam))
        return ARRAY_SIZE(CUTSCENE_OAM_DATA.oam);

    DMA3_FILL_32(0, &CUTSCENE_OAM_DATA.oam[slot], sizeof(struct CutsceneOam));

    CUTSCENE_OAM_DATA.oam[slot].xPosition = xPosition;
    CUTSCENE_OAM_DATA.oam[slot].yPosition = yPosition;
    CUTSCENE_OAM_DATA.oam[slot].type = type;
    CUTSCENE_OAM_DATA.oam[slot].enabled = TRUE;

    if (type == 1)
    {
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].scaling = Q_8_8(1.5f);
        CUTSCENE_OAM_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680d54;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneRestrictedLabDetachingProcessBslPart;
    }
    else if (type == 2)
    {
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].scaling = Q_8_8(1.5f);
        CUTSCENE_OAM_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680d64;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneRestrictedLabDetachingProcessBslPart;
    }
    else if (type == 3)
    {
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].scaling = Q_8_8(1.5f);
        CUTSCENE_OAM_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680d74;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneRestrictedLabDetachingProcessBslPart;
    }
    else if (type == 4)
    {
        CUTSCENE_OAM_DATA.oam[slot].enabled = FALSE;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneRestrictedLabDetachingProcessScrolling;
    }
    else if (type == 5)
    {
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680e2c;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9ba50;
    }
    else if (type == 6)
    {
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680e3c;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9ba50;
    }
    else if (type == 7)
    {
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680da4;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bac0;
    }
    else if (type == 8)
    {
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680d94;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bb30;
    }
    else if (type == 9)
    {
        CUTSCENE_OAM_DATA.oam[slot].scaling = Q_8_8(1);
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680d84;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bc04;
    }
    else if (type == 10)
    {
        CUTSCENE_OAM_DATA.oam[slot].enabled = FALSE;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bcdc;
    }
    else if (type == 11)
    {
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680dcc;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bac0;
    }
    else if (type == 12)
    {
        CUTSCENE_OAM_DATA.oam[slot].scaling = Q_8_8(1);
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680fec;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bd24;
    }
    else if (type == 13)
    {
        CUTSCENE_OAM_DATA.oam[slot].scaling = Q_8_8(1);
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680fc4;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bdf8;
    }
    else if (type == 14)
    {
        CUTSCENE_OAM_DATA.oam[slot].enabled = FALSE;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9be8c;
    }
    else if (type == 15)
    {
        CUTSCENE_OAM_DATA.oam[slot].enabled = FALSE;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bf54;
    }
    else if (type == 16)
    {
        CUTSCENE_OAM_DATA.oam[slot].unk_16_3 = 1;
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680f9c;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bfb8;
    }
    else if (type == 17)
    {
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680f74;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9bfb8;
    }
    else if (type == 18)
    {
        CUTSCENE_OAM_DATA.oam[slot].enabled = FALSE;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9c04c;
    }
    else if (type == 30)
    {
        CUTSCENE_OAM_DATA.oam[slot].scaling = 0x1A0;
        CUTSCENE_OAM_DATA.oam[slot].priority = 1;
        CUTSCENE_OAM_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_680f2c;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneRestrictedLabDetachingProcessFallingLab;
    }

    return slot;
}

/**
 * @brief 9b8ac | 178 | Processes a part of the BSL
 *
 */
void CutsceneRestrictedLabDetachingProcessBslPart(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->timer++;
        if (pOam->timer == 9)
        {
            pOam->timer = 0;
            pOam->xPosition--;
        }

        pOam->unk_E++;
        switch (pOam->spawnX)
        {
            case 0:
            if (pOam->unk_E == 4)
            {
                pOam->unk_E = 0;
                pOam->scaling += 2;
                if (pOam->scaling > 0x17F)
                    pOam->spawnX = 1;
            }
            break;

            case 1:
            if (pOam->unk_E == 5)
            {
                pOam->unk_E = 0;
                pOam->scaling += 2;
                if (pOam->scaling > 0x19F)
                    pOam->spawnX = 2;
            }
            break;

            case 2:
            if (pOam->unk_E == 6)
            {
                pOam->unk_E = 0;
                pOam->scaling += 2;
                if (pOam->scaling > 0x1BF)
                    pOam->spawnX = 3;
            }
            break;

            default:
            if (pOam->unk_E == 7)
            {
                pOam->unk_E = 0;
                pOam->scaling += 2;
            }
        }

        if (pOam->scaling > 0x200)
            pOam->scaling = 0x200;

        if (CUTSCENE_OAM_DATA.subStage == 1)
        {
            pOam->stage = CUTSCENE_OAM_DATA.subStage;
            pOam->timer = 0;
            pOam->spawnX = 0;
            pOam->unk_E = 0;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        if (pOam->timer == 9)
        {
            pOam->timer = 0;
            pOam->xPosition--;
        }

        if (pOam->type == 3)
        {
            pOam->yPosition += 6;
            pOam->spawnY = pOam->yPosition;
        }

        pOam->unk_E = 0;
        pOam->unk_A = 0;
        pOam->stage = 2;
    }
    else if (pOam->stage == 2)
    {
        pOam->timer++;
        if (pOam->timer == 9)
        {
            pOam->timer = 0;
            pOam->xPosition--;
        }

        pOam->unk_A++;
        if (pOam->unk_A == 7)
        {
            pOam->unk_A = 0;
            pOam->scaling += 2;
            if (pOam->scaling > 0x200)
                pOam->scaling = 0x200;
        }

        pOam->unk_E++;
        if (pOam->type == 3)
            pOam->yPosition = ((pOam->unk_E * pOam->unk_E) >> 10) + pOam->spawnY;
    }
}

/**
 * @brief 9ba24 | 2c | Processes the scrolling of the restricted lab detaching cutscene
 *
 */
void CutsceneRestrictedLabDetachingProcessScrolling(struct CutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == 30)
    {
        pOam->timer = 0;
        pOam->xPosition--;
    }

    WRITE_16(REG_BG3HOFS, pOam->xPosition);
}

/**
 * @brief 9ba50 | 70 | Processes a debris
 *
 */
void unk_9ba50(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = ((pOam->unk_C * pOam->unk_E) >> 6) + pOam->spawnX;
        pOam->yPosition = ((pOam->unk_A * pOam->unk_E) >> 6) + pOam->spawnY;
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9bac0 | 70 | Processes a debris
 *
 */
void unk_9bac0(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = ((pOam->unk_C * pOam->unk_E) >> 6) + pOam->spawnX;
        pOam->yPosition = ((pOam->unk_A * pOam->unk_E) >> 6) + pOam->spawnY;
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9bb30 | d4 | Processes a debris
 *
 */
void unk_9bb30(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = pOam->spawnX - (pOam->unk_E * 3U >> 4);
        pOam->yPosition = (u16)pOam->unk_E / 8 + pOam->spawnY;
    }

    pOam->timer++;
    if (pOam->timer == 12)
    {
        pOam->timer = 0;
        pOam->scaling -= 2;
        if (pOam->scaling <= 0)
            pOam->scaling = 2;
    }

    pOam->unk_A++;
    if (pOam->unk_A == 16)
    {
        pOam->unk_A = 0;
        pOam->unk_C++;
        if (pOam->unk_C > 3)
            pOam->unk_C = 0;
        DMA3_COPY_32(&sCutsceneLabDebrisPal2[pOam->unk_C * 16], PALRAM_OBJ + PAL_ROW_SIZE, PAL_ROW_SIZE / 4);
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9bc04 | d8 | Processes a debris
 *
 */
void unk_9bc04(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = ((pOam->unk_E * 11) >> 6) + pOam->spawnX;
        pOam->yPosition = pOam->spawnY - ((pOam->unk_E * 9) >> 6);
    }

    pOam->timer++;
    if (pOam->timer == 12)
    {
        pOam->timer = 0;
        pOam->scaling -= 2;
        if (pOam->scaling <= 0)
            pOam->scaling = 2;
    }

    pOam->unk_A++;
    if (pOam->unk_A == 6)
    {
        pOam->unk_A = 0;
        pOam->unk_C++;
        if (pOam->unk_C > 3)
            pOam->unk_C = 0;
        DMA3_COPY_32(&sCutsceneLabDebrisPal1[pOam->unk_C * 16], PALRAM_OBJ, PAL_ROW_SIZE / 4);
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9bcdc | 48 | Processes the scrolling of the restricted lab
 *
 */
void unk_9bcdc(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        WRITE_16(REG_BG2HOFS, pOam->xPosition);
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        WRITE_16(REG_BG2HOFS, ((pOam->unk_C * pOam->unk_E) >> 7) + pOam->xPosition);
    }
}

/**
 * @brief 9bd24 | d4 | Processes a debris
 *
 */
void unk_9bd24(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = pOam->spawnX - (u16)pOam->unk_E / 8;
        pOam->yPosition = (u16)pOam->unk_E / 16 + pOam->spawnY;
    }

    pOam->timer++;
    if (pOam->timer == 3)
    {
        pOam->timer = 0;
        pOam->scaling -= 4;
        if (pOam->scaling <= 2)
            pOam->scaling = 2;
    }

    pOam->unk_A++;
    if (pOam->unk_A == 15)
    {
        pOam->unk_A = 0;
        pOam->unk_C++;
        if (pOam->unk_C > 3)
            pOam->unk_C = 0;
        DMA3_COPY_32(&sCutsceneLabDebrisPal3[pOam->unk_C * 16], PALRAM_OBJ + PAL_ROW_SIZE * 3, PAL_ROW_SIZE / 4);
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9bdf8 | 94 | Processes a debris
 *
 */
void unk_9bdf8(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = ((pOam->unk_C * pOam->unk_E) >> 6) + pOam->spawnX;
        pOam->yPosition = ((pOam->unk_A * pOam->unk_E) >> 6) + pOam->spawnY;
    }

    pOam->timer++;
    if (pOam->timer == 5)
    {
        pOam->timer = 0;
        pOam->scaling -= 4;
        if (pOam->scaling <= 2)
            pOam->scaling = 2;
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9be8c | c8 | Fades in the BSL fire
 *
 */
void unk_9be8c(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        DMA3_COPY_32(sCutsceneBslFirePal, PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        if (pOam->timer == 8)
        {
            pOam->timer = 0;
            pOam->unk_C++;
            if (pOam->unk_C > 14)
            {
                pOam->unk_C = 15;
                pOam->stage = 2;
            }
            DMA3_COPY_32(&sCutsceneBslFirePal[pOam->unk_C * 16], PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);
        }
    }
    else if (pOam->stage == 2)
    {
        pOam->timer++;
        if (pOam->timer == 6)
        {
            pOam->timer = 0;
            if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
            {
                gWrittenToBldalpha_Eva++;
                if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
                    gWrittenToBldalpha_Evb++;
            }
        }
    }
}

/**
 * @brief 9bf54 | 64 | Shakes the screen
 *
 */
void unk_9bf54(struct CutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == 1)
    {
        pOam->timer = 0;
        CUTSCENE_OAM_DATA.unk_A += 2;
        if (CUTSCENE_OAM_DATA.unk_A > 160)
            CUTSCENE_OAM_DATA.unk_A = 160;
    }

    pOam->animationDurationCounter++;
    if (pOam->animationDurationCounter == 32)
        pOam->animationDurationCounter = 0;

    WRITE_16(REG_BG1HOFS, sRandomNumberTable[pOam->animationDurationCounter]);
    WRITE_16(REG_BG1VOFS, sRandomNumberTable[pOam->animationDurationCounter]);
}

/**
 * @brief 9bfb8 | 94 | Processes a debris
 *
 */
void unk_9bfb8(struct CutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = ((pOam->unk_C * pOam->unk_E) >> 6) + pOam->spawnX;
        pOam->yPosition = ((pOam->unk_A * pOam->unk_E) >> 6) + pOam->spawnY;
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }

    pFrame = &pOam->pOam[pOam->currentAnimationFrame];
    if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9c04c | 34 | To document
 *
 */
void unk_9c04c(struct CutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == 40)
    {
        pOam->timer = 0;
        if (pOam->xPosition > 0)
            pOam->xPosition--;
    }

    WRITE_16(REG_BG2HOFS, pOam->xPosition);
}

/**
 * @brief 9c080 | 34 | Sets up a restricted lab detaching OAM with a parameter
 *
 */
u8 unk_9c080(u8 type, s16 xPosition, s16 yPosition, u16 param_4)
{
    u8 slot;

    slot = CutsceneRestrictedLabDetachingSetupOam(type, xPosition, yPosition);
    CUTSCENE_OAM_DATA.oam[slot].unk_C = param_4;
    return slot;
}

/**
 * @brief 9c0b4 | 3c | Sets up a restricted lab detaching OAM with two parameters
 *
 */
u8 unk_9c0b4(u8 type, s16 xPosition, s16 yPosition, u16 param_4, u16 param_5)
{
    u8 slot;

    slot = CutsceneRestrictedLabDetachingSetupOam(type, xPosition, yPosition);
    CUTSCENE_OAM_DATA.oam[slot].unk_A = param_5;
    CUTSCENE_OAM_DATA.oam[slot].unk_C = param_4;
    return slot;
}

/**
 * @brief 9c0f0 | 48 | Gets the position of a restricted lab detaching OAM by type
 *
 */
void CutsceneRestrictedLabDetachingGetPositionOfOamByType(u8 type, s16* pXPosition, s16* pYPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_OAM_DATA.oam); slot++)
    {
        if (CUTSCENE_OAM_DATA.oam[slot].type == type)
        {
            *pXPosition = CUTSCENE_OAM_DATA.oam[slot].xPosition;
            *pYPosition = CUTSCENE_OAM_DATA.oam[slot].yPosition;
            return;
        }
    }

    *pXPosition = 300;
    *pYPosition = 200;
}

/**
 * @brief 9c138 | 84 | V-blank for the restricted lab detaching cutscene
 *
 */
void CutsceneRestrictedLabDetachingVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);

    if (CUTSCENE_OAM_DATA.unk_A == 1)
    {
        CUTSCENE_OAM_DATA.unk_A = 0;
        DMA3_COPY_32(&sCutsceneBslFirePal[CUTSCENE_OAM_DATA.unk_C * 16], PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);
    }
}

/**
 * @brief 9c1bc | c | V-blank that only updates the audio
 *
 */
void unk_9c1bc(void)
{
    UpdateAudio();
}
