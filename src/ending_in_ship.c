#include "ending_in_ship.h"
#include "special_cutscene.h"
#include "new_file_intro.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "syscalls.h"
#include "audio_wrappers.h"
#include "music_wrappers.h"

#include "constants/audio.h"
#include "constants/text.h"

#include "data/generic_data.h"
#include "data/intro_data.h"

/**
 * @brief 95e24 | 200 | Setup for the ending monologue
 * 
 */
void EndingMonologueInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    LZ77UncompVram((const u32*)0x86150e8, VRAM_OBJ);
    DMA3_COPY_32((const u16*)0x8636638, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);

    LZ77UncompVram((const u32*)0x86186a4, VRAM_BASE + 0x8000);
    LZ77UncompVram((const u32*)0x86377f8, VRAM_BASE + 0xF800);
    DMA3_COPY_32((const u16*)0x8636438, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);

    LZ77UncompWram(sIntroTilemap_662804, EWRAM_BASE);
    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0x4800, 0x800 / 4);
    DMA3_FILL_32(0, VRAM_BASE, 0x4800);
    DMA3_COPY_32(sIntroPal_663820, PALRAM_BASE + 0x180, 4 * PAL_ROW_SIZE / 4);

    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 4);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 9, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = 0;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;

    EndingDialogueSetupOam(1, 260, 180, FALSE);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(EndingMonologueVblank);
}

/**
 * @brief 96024 | 204 | Setup for the ending conversation with Adam
 * 
 */
void EndingAdamConversationInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
    DMA3_FILL_16(0, INTRO_DATA.unk_14, sizeof(INTRO_DATA.unk_14));
    DMA3_FILL_16(0, &INTRO_DATA.unk_110, sizeof(INTRO_DATA.unk_14));

    LZ77UncompVram((const u32*)0x86131c8, VRAM_BASE + 0x8000);
    LZ77UncompVram((const u32*)0x8637238, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    DMA3_COPY_32((const u16*)0x8636438, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);

    gBg0XPosition = -8;
    gBg0YPosition = 8;
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, -8);
    WRITE_16(REG_BG0VOFS, 8);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    EndingDialogueSetupOam(2, 112, 80, TRUE);
    EndingDialogueSetupOam(3, 112, 80, TRUE);
    EndingDialogueSetupOam(4, 112, 80, TRUE);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(EndingConversationAndAnimalsVblank);
}

/**
 * @brief 96228 | 220 | Setup for the ending animals scene
 * 
 */
void EndingAnimalsInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
    DMA3_FILL_16(0, INTRO_DATA.unk_14, sizeof(INTRO_DATA.unk_14));
    DMA3_FILL_16(0, &INTRO_DATA.unk_110, sizeof(INTRO_DATA.unk_14));

    LZ77UncompVram((const u32*)0x861b89c, VRAM_BASE);
    LZ77UncompVram((const u32*)0x86217a8, VRAM_BASE + 0x8000);
    LZ77UncompVram((const u32*)0x8638654, VRAM_BASE + 0xF000);
    LZ77UncompVram((const u32*)0x8637db8, VRAM_BASE + 0xF800);
    DMA3_COPY_32((const u16*)0x8636838, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
    DMA3_FILL_16(0x2FF, VRAM_BASE + 0xF500, 0x300);

    gBg0XPosition = 0;
    gBg0YPosition = 0;
    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg3XPosition = 0;
    gBg2YPosition = -30;
    gBg3YPosition = 226;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 226);

    WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    EndingDialogueSetupOam(20, 0, 0, FALSE);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);

    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(EndingConversationAndAnimalsVblank);
}

// 0x08096448
NAKED_FUNCTION
boolu32 EndingInShipProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	movs r6, #0\n\
	ldr r2, _08096474 @ =gNonGameplayRam\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	adds r1, #1\n\
	strh r1, [r0]\n\
	movs r7, #0x85\n\
	lsls r7, r7, #2\n\
	adds r0, r2, r7\n\
	ldrb r0, [r0]\n\
	adds r5, r2, #0\n\
	cmp r0, #0xf\n\
	bls _0809646A\n\
	b _08096920\n\
_0809646A:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08096478 @ =_0809647C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08096474: .4byte gNonGameplayRam\n\
_08096478: .4byte _0809647C\n\
_0809647C: @ jump table\n\
	.4byte _080964BC @ case 0\n\
	.4byte _080964F2 @ case 1\n\
	.4byte _08096550 @ case 2\n\
	.4byte _080965F4 @ case 3\n\
	.4byte _0809663C @ case 4\n\
	.4byte _08096698 @ case 5\n\
	.4byte _080966E0 @ case 6\n\
	.4byte _080966FC @ case 7\n\
	.4byte _08096716 @ case 8\n\
	.4byte _0809673C @ case 9\n\
	.4byte _0809678A @ case 10\n\
	.4byte _0809681C @ case 11\n\
	.4byte _08096828 @ case 12\n\
	.4byte _08096878 @ case 13\n\
	.4byte _080968A0 @ case 14\n\
	.4byte _080968E8 @ case 15\n\
_080964BC:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #7\n\
	beq _080964CA\n\
	b _080968D8\n\
_080964CA:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _080964DC @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _080964E0\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	b _080968D8\n\
	.align 2, 0\n\
_080964DC: .4byte gWrittenToBldy\n\
_080964E0:\n\
	movs r0, #0x56\n\
	movs r1, #0xe\n\
	bl PlayMusic\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	b _080968D6\n\
_080964F2:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x46\n\
	beq _08096500\n\
	b _080968D8\n\
_08096500:\n\
	movs r4, #0\n\
	movs r2, #0\n\
	strh r2, [r1]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #0x13\n\
	ldrh r0, [r3]\n\
	movs r7, #0x80\n\
	lsls r7, r7, #1\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	strh r2, [r5, #0x12]\n\
	strh r2, [r5, #0x10]\n\
	strh r2, [r5, #0xe]\n\
	strh r2, [r5, #0xc]\n\
	ldr r1, _08096544 @ =0x00000212\n\
	adds r0, r5, r1\n\
	strb r4, [r0]\n\
	ldr r1, _08096548 @ =0x0879C5A4\n\
	ldr r0, _0809654C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x1c]\n\
	str r0, [r5]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #2\n\
	b _080968D6\n\
	.align 2, 0\n\
_08096544: .4byte 0x00000212\n\
_08096548: .4byte 0x0879C5A4\n\
_0809654C: .4byte 0x03000011\n\
_08096550:\n\
	ldr r0, [r5]\n\
	ldrh r1, [r0]\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _08096578\n\
	ldr r0, _08096598 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08096578\n\
	movs r7, #0x86\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _08096578\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_08096578:\n\
	ldr r3, _0809659C @ =gNonGameplayRam\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	movs r4, #0\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	ldrb r2, [r0]\n\
	cmp r2, #2\n\
	bne _080965A0\n\
	strb r4, [r0]\n\
	b _080965AE\n\
	.align 2, 0\n\
_08096598: .4byte gChangedInput\n\
_0809659C: .4byte gNonGameplayRam\n\
_080965A0:\n\
	cmp r2, #3\n\
	bne _080965AE\n\
	strb r4, [r0]\n\
	movs r7, #0x85\n\
	lsls r7, r7, #2\n\
	adds r0, r3, r7\n\
	strb r2, [r0]\n\
_080965AE:\n\
	bl EndingCheckMonologueEnded\n\
	cmp r0, #0\n\
	beq _080965CC\n\
	ldr r3, _080965DC @ =gNonGameplayRam\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	movs r2, #0\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	strb r2, [r0]\n\
_080965CC:\n\
	ldr r0, _080965DC @ =gNonGameplayRam\n\
	ldr r2, _080965E0 @ =0x00000213\n\
	adds r1, r0, r2\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _080965E4\n\
	movs r0, #0x64\n\
	b _080968D6\n\
	.align 2, 0\n\
_080965DC: .4byte gNonGameplayRam\n\
_080965E0: .4byte 0x00000213\n\
_080965E4:\n\
	cmp r0, #1\n\
	beq _080965EA\n\
	b _080968D8\n\
_080965EA:\n\
	movs r0, #0x64\n\
	strb r0, [r1]\n\
	bl SpecialCutsceneProcessMonologue\n\
	b _080968D8\n\
_080965F4:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	bne _08096618\n\
	ldr r1, _08096610 @ =gWrittenToBldalpha_Evb\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08096614 @ =gWrittenToBldalpha_Eva\n\
_08096608:\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	b _080968D8\n\
	.align 2, 0\n\
_08096610: .4byte gWrittenToBldalpha_Evb\n\
_08096614: .4byte gWrittenToBldalpha_Eva\n\
_08096618:\n\
	cmp r0, #0x14\n\
	beq _0809661E\n\
	b _080968D8\n\
_0809661E:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08096634 @ =0x04000050\n\
	ldr r2, _08096638 @ =0x00001841\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r7, #0x85\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #4\n\
	b _080968D6\n\
	.align 2, 0\n\
_08096634: .4byte 0x04000050\n\
_08096638: .4byte 0x00001841\n\
_0809663C:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #4\n\
	beq _0809664A\n\
	b _080968D8\n\
_0809664A:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r2, _0809668C @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r2]\n\
	cmp r0, #0xf\n\
	bhi _0809665A\n\
	adds r0, #1\n\
	strh r0, [r2]\n\
_0809665A:\n\
	ldr r1, _08096690 @ =gWrittenToBldalpha_Eva\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _08096666\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
_08096666:\n\
	ldrh r0, [r2]\n\
	cmp r0, #0x10\n\
	beq _0809666E\n\
	b _080968D8\n\
_0809666E:\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _08096676\n\
	b _080968D8\n\
_08096676:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r1, [r2]\n\
	ldr r0, _08096694 @ =0x0000FEFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #5\n\
	b _080968D6\n\
	.align 2, 0\n\
_0809668C: .4byte gWrittenToBldalpha_Evb\n\
_08096690: .4byte gWrittenToBldalpha_Eva\n\
_08096694: .4byte 0x0000FEFF\n\
_08096698:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r2, r5, r7\n\
	ldrh r0, [r2]\n\
	cmp r0, #0xa\n\
	bne _080966B2\n\
	movs r0, #0x1e\n\
	movs r1, #0x78\n\
	movs r2, #0x50\n\
	movs r3, #1\n\
	bl EndingDialogueSetupOam\n\
	b _080968D8\n\
_080966B2:\n\
	cmp r0, #0x27\n\
	bne _080966C0\n\
	ldr r1, _080966BC @ =gWrittenToBldy\n\
	b _08096608\n\
	.align 2, 0\n\
_080966BC: .4byte gWrittenToBldy\n\
_080966C0:\n\
	cmp r0, #0x28\n\
	beq _080966C6\n\
	b _080968D8\n\
_080966C6:\n\
	ldr r1, _080966DC @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	movs r0, #0\n\
	strh r0, [r2]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r0, #6\n\
	b _080968D6\n\
	.align 2, 0\n\
_080966DC: .4byte 0x04000050\n\
_080966E0:\n\
	movs r2, #0x84\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	beq _080966EE\n\
	b _080968D8\n\
_080966EE:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r7, #0x85\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #7\n\
	b _080968D6\n\
_080966FC:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	bl EndingAdamConversationInit\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	b _08096920\n\
_08096716:\n\
	ldr r1, _08096738 @ =gWrittenToBldy\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r0, #0x93\n\
	lsls r0, r0, #2\n\
	bl SoundPlay\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r0, #9\n\
	b _080968D6\n\
	.align 2, 0\n\
_08096738: .4byte gWrittenToBldy\n\
_0809673C:\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r4, r5, r1\n\
	ldrh r0, [r4]\n\
	cmp r0, #0xa\n\
	beq _08096806\n\
	cmp r0, #0x28\n\
	bne _08096806\n\
	movs r0, #0xff\n\
	movs r1, #0\n\
	movs r2, #0\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #6\n\
	movs r1, #0x14\n\
	movs r2, #0xc0\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #7\n\
	movs r1, #0x80\n\
	movs r2, #0xc0\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #9\n\
	movs r1, #0x80\n\
	movs r2, #0xc0\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #0\n\
	strh r0, [r4]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #0xa\n\
	b _08096804\n\
_0809678A:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r0, [r5]\n\
	ldrh r1, [r0]\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _080967BC\n\
	ldr r0, _080967D4 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080967BC\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _080967BC\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_080967BC:\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r3, r5, r1\n\
	ldrb r0, [r3]\n\
	cmp r0, #2\n\
	bne _080967DC\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
	ldr r0, _080967D8 @ =0x00000203\n\
	bl SoundPlay\n\
	b _08096806\n\
	.align 2, 0\n\
_080967D4: .4byte gChangedInput\n\
_080967D8: .4byte 0x00000203\n\
_080967DC:\n\
	cmp r0, #3\n\
	bne _08096806\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r1, [r2]\n\
	ldr r0, _08096814 @ =0x0000FEFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
	ldr r0, _08096818 @ =0x00000203\n\
	bl SoundPlay\n\
	movs r0, #0xa\n\
	bl FadeMusic\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #0xb\n\
_08096804:\n\
	strb r0, [r1]\n\
_08096806:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	bl EndingProcessAdamText\n\
	b _08096920\n\
	.align 2, 0\n\
_08096814: .4byte 0x0000FEFF\n\
_08096818: .4byte 0x00000203\n\
_0809681C:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	b _080968D8\n\
_08096828:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	bne _0809685C\n\
	ldr r2, _08096850 @ =0x080A8CDC\n\
	ldr r0, _08096854 @ =0x080A8D3C\n\
	ldr r1, _08096858 @ =0x00001264\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	movs r1, #0\n\
	bl ApplyMusicSoundFading\n\
	b _080968D8\n\
	.align 2, 0\n\
_08096850: .4byte 0x080A8CDC\n\
_08096854: .4byte 0x080A8D3C\n\
_08096858: .4byte 0x00001264\n\
_0809685C:\n\
	cmp r0, #0xa\n\
	bne _080968D8\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08096874 @ =gWrittenToBldy\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #0xd\n\
	b _080968D6\n\
	.align 2, 0\n\
_08096874: .4byte gWrittenToBldy\n\
_08096878:\n\
	bl EndingAnimalsInit\n\
	ldr r2, _08096898 @ =gNonGameplayRam\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r0, r2, r7\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	ldr r0, _0809689C @ =gWrittenToBldy\n\
	strh r1, [r0]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	movs r0, #0xe\n\
	strb r0, [r1]\n\
	b _08096920\n\
	.align 2, 0\n\
_08096898: .4byte gNonGameplayRam\n\
_0809689C: .4byte gWrittenToBldy\n\
_080968A0:\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r2, r5, r1\n\
	ldrh r1, [r2]\n\
	cmp r1, #1\n\
	bne _080968B6\n\
	movs r0, #0x53\n\
	movs r1, #0xe\n\
	bl PlayMusic\n\
	b _080968D8\n\
_080968B6:\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	cmp r1, r0\n\
	bne _080968D8\n\
	movs r0, #0\n\
	strh r0, [r2]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r1, [r2]\n\
	ldr r0, _080968E4 @ =0x0000FBFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #0xf\n\
_080968D6:\n\
	strb r0, [r1]\n\
_080968D8:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	b _08096920\n\
	.align 2, 0\n\
_080968E4: .4byte 0x0000FBFF\n\
_080968E8:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	ldrh r0, [r1]\n\
	cmp r0, #2\n\
	bne _08096918\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08096908 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _0809690C\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _08096918\n\
	.align 2, 0\n\
_08096908: .4byte gWrittenToBldy\n\
_0809690C:\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	movs r6, #1\n\
_08096918:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_08096920:\n\
	adds r0, r6, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

/**
 * @brief 96928 | 88 | Main handler for the ending in ship cutscenes
 * 
 */
boolu32 EndingInShip(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            EndingMonologueInit();
            INTRO_DATA.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (gWrittenToBldy == 0)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (EndingInShipProcess())
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
                ended = TRUE;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return ended;
}

/**
 * @brief 969b0 | 30 | Processes the monologue text cursor
 * 
 */
void EndingProcessMonologueCursor(struct SpecialCutsceneOam* pOam)
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
 * @brief 969e0 | 28 | To document
 * 
 */
void unk_969e0(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->stage == 0)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
            pOam->animationDurationCounter = 0;
    }
}

/**
 * @brief 96a08 | 34 | Processes the SR388 radar view
 * 
 */
void EndingProcessSr388RadarView(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->stage == 0)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x8633ec4;
            pOam->stage = 1;
        }
    }
}

/**
 * @brief 96a3c | 34 | Processes the Samus view radar view
 * 
 */
void EndingProcessSamusViewRadarView(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->stage == 0)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x8633f0c;
            pOam->stage = 1;
        }
    }
}

/**
 * @brief 96a70 | 9c | To document
 * 
 */
void unk_96a70(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    pFrame = &pOam->pOam[pOam->currentAnimationFrame];

    if (pOam->stage == 0)
    {
        if (pOam->currentAnimationFrame == 1 && pOam->animationDurationCounter == 1)
            SoundPlay(SOUND_11C);

        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->animationDurationCounter = 0;
        if (INTRO_DATA.subStage == 11)
        {
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x8633244;
            SoundPlay(SOUND_11D);
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 96b0c | 8c | Processes the Adam text cursor
 * 
 */
void EndingProcessAdamTextCursor(struct SpecialCutsceneOam* pOam)
{
    struct IntroData* pIntro;

    pIntro = &INTRO_DATA;
    if (*pIntro->pText == CHAR_TERMINATOR)
    {
        pOam->xPosition = 290;
        return;
    }

    if (*pIntro->pText != CHAR_NEW_LINE)
    {
        if (*pIntro->pText == CHAR_NEW_PAGE)
        {
            pOam->xPosition = 290;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x8633e8c;
            return;
        }

        if (*pIntro->pText == CHAR_NEXT_PAGE_ARROW)
        {
            pOam->xPosition = 120;
            pOam->yPosition = 154;
            pOam->pOam = (const struct FrameData*)0x8633e64;
            return;
        }
    }

    pOam->xPosition = pIntro->unk_C * 8 + pIntro->unk_212 + 14;
    pOam->yPosition = pIntro->unk_E * 8 + 132;
    pOam->animationDurationCounter = 0;
    pOam->currentAnimationFrame = 0;
}

/**
 * @brief 96b98 | 1a8 | Processes the Adam conversation panel
 * 
 */
void EndingProcessAdamPanel(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->stage == 0)
    {
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
        if (pOam->yPosition > 128)
        {
            pOam->yPosition -= 8;
        }
        else
        {
            pOam->yPosition = 128;
            if (pOam->type == 7)
                SoundPlay(SOUND_20A);
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame[0].timer == pOam->animationDurationCounter)
        {
            if (pFrame[1].timer == 0)
            {
                pOam->animationDurationCounter = 0;
                pOam->stage = 2;
            }

            if (pOam->type != 7)
                return;

            if (pOam->currentAnimationFrame == 10)
                EndingDialogueSetupOam(8, pOam->xPosition, pOam->yPosition, FALSE);
        }

        if (pOam->type != 7)
            return;

        if (pOam->currentAnimationFrame != 11)
            return;

        if (pOam->animationDurationCounter != 15)
            return;

        INTRO_DATA.unk_212 = 0;
        INTRO_DATA.unk_E = 0;
        INTRO_DATA.unk_C = 0;
        INTRO_DATA.pText = sEndingTextPointers[gLanguage][112];
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
        if (INTRO_DATA.subStage == 11)
        {
            pOam->currentAnimationFrame = 0;
            if (pOam->type == 7)
            {
                pOam->pOam = (const struct FrameData*)0x86332fc;
                SoundPlay(SOUND_20B);
            }
            else if (pOam->type == 9)
            {
                pOam->pOam = (const struct FrameData*)0x86333cc;
            }
            pOam->stage = 4;
        }
    }
    else if (pOam->stage == 4)
    {
        if (pOam->currentAnimationFrame == 11 && pOam->animationDurationCounter == 3)
        {
            if (pOam->type == 7)
                SpecialCutsceneDestroyOamOfType(8);
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
            if (pOam->type == 7)
                INTRO_DATA.subStage = 12;
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 96d40 | 88 | Processes the Adam icon
 * 
 */
void EndingProcessAdamIcon(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    pFrame = &pOam->pOam[pOam->currentAnimationFrame];

    if (pOam->stage == 0)
    {
        if (pOam->currentAnimationFrame == 3)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x86338a4;
            pOam->stage = 1;
        }

        if (INTRO_DATA.subStage == 11)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x863345c;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 1)
    {
        if (INTRO_DATA.subStage == 11)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x863345c;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 2)
    {
        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
            pOam->animationDurationCounter = 0;
    }
}

/**
 * @brief 96dc8 | 138 | Processes the scrolling of the animals scene
 * 
 */
void EndingProcessAnimalsScrolling(struct SpecialCutsceneOam* pOam)
{
    pOam->timer++;

    if (pOam->stage == 0)
    {
        pOam->xPosition = gBg2XPosition;
        pOam->yPosition = gBg2YPosition;
        pOam->spawnX = gBg3XPosition;
        pOam->spawnY = gBg3YPosition;

        if (pOam->yPosition < -32)
        {
            pOam->unk_A = 0x4000;
            DMA3_FILL_32(0, VRAM_BASE + 0x8000 + pOam->unk_A, 0x1000);
        }
        else
        {
            pOam->unk_A = 0x5000;
        }

        pOam->timer = 0;
        pOam->stage = 2;
    }
    else if (pOam->stage == 1)
    {
        if (pOam->timer == 10)
        {
            pOam->timer = 0;
            pOam->stage = 2;
        }
    }
    else if (INTRO_DATA.subStage == 14)
    {
        if (pOam->timer == 2)
        {
            pOam->timer = 0;
            if (pOam->yPosition > -160)
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
            if (pOam->unk_A != 0)
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
 * @brief 96f00 | 8 | To document
 * 
 */
void unk_96f00(struct SpecialCutsceneOam* pOam)
{
    pOam->type = 0;
}

/**
 * @brief 96f08 | 380 | Sets up an ending dialogue OAM
 * 
 */
u8 EndingDialogueSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
{
    s8 slot;

    if (!descendingSearch)
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
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8633e64;
        INTRO_DATA.oam[slot].pFunction = EndingProcessMonologueCursor;
    }
    else if (type == 2)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x86338d4;
        INTRO_DATA.oam[slot].pFunction = unk_969e0;
    }
    else if (type == 3)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x86339d4;
        INTRO_DATA.oam[slot].pFunction = EndingProcessSr388RadarView;
    }
    else if (type == 4)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8633c4c;
        INTRO_DATA.oam[slot].pFunction = EndingProcessSamusViewRadarView;
    }
    else if (type == 5)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x86331ec;
        INTRO_DATA.oam[slot].pFunction = unk_96a70;
    }
    else if (type == 6)
    {
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8633e8c;
        INTRO_DATA.oam[slot].pFunction = EndingProcessAdamTextCursor;
    }
    else if (type == 7)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8633294;
        INTRO_DATA.oam[slot].pFunction = EndingProcessAdamPanel;
    }
    else if (type == 8)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8633434;
        INTRO_DATA.oam[slot].pFunction = EndingProcessAdamIcon;
    }
    else if (type == 9)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8633364;
        INTRO_DATA.oam[slot].pFunction = EndingProcessAdamPanel;
    }
    else if (type == 20)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = EndingProcessAnimalsScrolling;
    }
    else if (type == 30)
    {
        SoundPlay(SOUND_12D);
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8633f24;
        INTRO_DATA.oam[slot].pFunction = unk_97418;
    }
    else if (type == 255)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x86331ec;
        INTRO_DATA.oam[slot].pFunction = unk_96f00;
    }

    return slot;
}

/**
 * @brief 97288 | 9c | V-blank for the ending monologue
 * 
 */
void EndingMonologueVblank(void)
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

    unk_98158();
}

/**
 * @brief 97324 | 94 | V-blank for the ending conversation and animals scenes
 * 
 */
void EndingConversationAndAnimalsVblank(void)
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
}

/**
 * @brief 973b8 | 60 | Gets the position and slot of an OAM by type
 * 
 */
u8 EndingGetPositionAndSlotOfOamByType_2(u8 type, s16* pXPosition, s16* pYPosition)
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

    *pXPosition = 300;
    *pYPosition = 200;
        
    return ARRAY_SIZE(INTRO_DATA.oam);
}

/**
 * @brief 97418 | 4 | Empty function
 * 
 */
void unk_97418(struct SpecialCutsceneOam* pOam)
{
    return;
}
