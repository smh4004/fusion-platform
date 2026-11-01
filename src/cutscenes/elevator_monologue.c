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

/**
 * @brief 99b04 | a8 | Processes the current in-game cutscene
 * 
 */
boolu32 CutsceneProcess(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (gCurrentCutscene)
    {
        case 1:
        case 8:
            if (CutsceneInternalMonologue(0))
                ended = TRUE;
            break;

        case 2:
            if (CutsceneElevatorMonologue(0))
                ended = TRUE;
            break;

        case 3:
            if (CutsceneElevatorMonologue(0))
                ended = TRUE;
            break;

        case 4:
            if (CutsceneElevatorMonologue(0))
                ended = TRUE;
            break;

        case 5:
            if (CutsceneElevatorMonologue(1))
                ended = TRUE;
            break;

        case 6:
            if (CutsceneElevatorMonologue(0))
                ended = TRUE;
            break;

        case 7:
            if (CutsceneFederationMonologue(0))
                ended = TRUE;
            break;

        case 9:
            if (CutsceneSecretConversation())
                ended = TRUE;
            break;

        case 10:
        case 11:
            if (CutsceneRestrictedLabDetaching())
                ended = TRUE;
            break;

        case 12:
            if (CutsceneBslExploding())
                ended = TRUE;
            break;

        default:
            ended = TRUE;
    }

    return ended;
}

/**
 * @brief 99bac | 8c | Main handler for the elevator monologue cutscenes
 * 
 */
boolu32 CutsceneElevatorMonologue(u8 param_1)
{
    boolu32 ended;

    ended = FALSE;

    switch (CUTSCENE_DATA.stage)
    {
        case 0:
            CUTSCENE_DATA.stage = 1;
            CutsceneElevatorMonologueInit(param_1);
            break;

        case 1:
            CutsceneMonologueFadeIn();
            if (gWrittenToBldy == 0)
                CUTSCENE_DATA.stage++;
            break;

        case 2:
            if (CutsceneElevatorMonologueProcess())
            {
                CUTSCENE_DATA.stage = 3;
                WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
            }
            break;

        case 3:
            CutsceneMonologueFadeOut();
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 99c38 | 22c | Setup for the elevator monologue cutscenes
 * 
 */
void CutsceneElevatorMonologueInit(u8 param_1)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_9a31c);

    WRITE_16(REG_DISPCNT, 0);

    LZ77UncompVram(sCutsceneMonologueObjGfxPointers[gCurrentCutscene - 1], VRAM_OBJ + 0x2000);
    LZ77UncompVram((const u32*)0x865fb5c, VRAM_OBJ + 0x7C00);
    DMA3_COPY_32((const u16*)0x86638a0, PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sCutsceneMonologueObjPalPointers[gCurrentCutscene - 1], PALRAM_OBJ, 6 * PAL_ROW_SIZE / 4);

    LZ77UncompVram(sCutsceneMonologueBgGfxPointers[gCurrentCutscene - 1], VRAM_BASE);
    LZ77UncompVram(sCutsceneMonologueBgTilemapPointers[gCurrentCutscene - 1], VRAM_BASE + 0xD000);
    LZ77UncompWram(sIntroTilemap_662804, EWRAM_BASE);
    LZ77UncompVram((const u32*)0x8663598, VRAM_BASE + 0xD800);
    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xC800, 0x800 / 4);
    DMA3_COPY_32((const u16*)0x86636a0, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sCutsceneMonologueBgPalPointers[gCurrentCutscene - 1], PALRAM_BASE, 11 * PAL_ROW_SIZE / 4);

    WRITE_16(REG_BG0VOFS, 4);
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 25, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 27, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 26, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG2 | DCNT_OBJ);

    gWrittenToBldy--;

    CutsceneElevatorMonologueSetupOam(1, 12, 16);
    CutsceneElevatorMonologueSetupOam(2, 120, 120);
    CutsceneElevatorMonologueSetupOam(3, 120, 120);

    if (param_1 == 0)
        CutsceneElevatorMonologueSetupOam(4, 120, 104);
    else
        CutsceneElevatorMonologueSetupOam(5, 120, 104);

    CUTSCENE_DATA.unk_A = gCurrentCutscene - 1;
    CUTSCENE_DATA.pText = sMonologueTextPointers[gLanguage][CUTSCENE_DATA.unk_A];

    CutsceneMonologueDrawAllOam();
    CallbackSetVBlank(CutsceneElevatorMonologueVblank);
}

/**
 * @brief 99e64 | 3c | Processes the elevator monologue cutscenes
 * 
 */
boolu32 CutsceneElevatorMonologueProcess(void)
{
    boolu32 ended;

    ended = CutsceneMonologueProcessSpecialTextCharacters();

    switch (CUTSCENE_DATA.textState)
    {
        case 0:
            CUTSCENE_DATA.textState = 100;
            break;

        case 1:
            CUTSCENE_DATA.textState = 100;
            CutsceneMonologueProcessText();
            break;
    }

    CutsceneMonologueProcessOam();
    CutsceneMonologueDrawAllOam();

    return ended;
}

/**
 * @brief 99ea0 | 1e8 | Sets up an elevator monologue OAM
 * 
 */
u8 CutsceneElevatorMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_DATA.u.monologue.oam); slot++)
    {
        if (CUTSCENE_DATA.u.monologue.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(CUTSCENE_DATA.u.monologue.oam))
        return ARRAY_SIZE(CUTSCENE_DATA.u.monologue.oam);

    CutsceneMonologueResetOam(slot);

    CUTSCENE_DATA.u.monologue.oam[slot].xPosition = xPosition;
    CUTSCENE_DATA.u.monologue.oam[slot].yPosition = yPosition;
    CUTSCENE_DATA.u.monologue.oam[slot].type = type;
    CUTSCENE_DATA.u.monologue.oam[slot].enabled = TRUE;

    if (type == 1)
    {
        CUTSCENE_DATA.u.monologue.oam[slot].paletteOffset = 15;
        CUTSCENE_DATA.u.monologue.oam[slot].tileOffset = 0x3E0;
        CUTSCENE_DATA.u.monologue.oam[slot].pOam = (const struct FrameData*)0x8663e5c;
        CUTSCENE_DATA.u.monologue.oam[slot].pFunction = CutsceneMonologueProcessCursor;
    }
    else if (type == 2)
    {
        CUTSCENE_DATA.u.monologue.oam[slot].priority = 3;
        CUTSCENE_DATA.u.monologue.oam[slot].pOam = sCutsceneMonologueOamPointers[gCurrentCutscene - 1][0];
        CUTSCENE_DATA.u.monologue.oam[slot].pFunction = unk_9d09c;
    }
    else if (type == 3)
    {
        CUTSCENE_DATA.u.monologue.oam[slot].objMode = 2;
        CUTSCENE_DATA.u.monologue.oam[slot].priority = type;
        CUTSCENE_DATA.u.monologue.oam[slot].pOam = sCutsceneMonologueOamPointers[gCurrentCutscene - 1][0];
        CUTSCENE_DATA.u.monologue.oam[slot].pFunction = unk_9d09c;
    }
    else if (type == 4)
    {
        CUTSCENE_DATA.u.monologue.oam[slot].priority = 3;
        CUTSCENE_DATA.u.monologue.oam[slot].pOam = sCutsceneMonologueOamPointers[gCurrentCutscene - 1][1];
        CUTSCENE_DATA.u.monologue.oam[slot].pFunction = CutsceneProcessElevatorScrolling;
    }
    else if (type == 5)
    {
        CUTSCENE_DATA.u.monologue.oam[slot].priority = 3;
        CUTSCENE_DATA.u.monologue.oam[slot].pOam = sCutsceneMonologueOamPointers[gCurrentCutscene - 1][1];
        CUTSCENE_DATA.u.monologue.oam[slot].pFunction = unk_9a1a8;
    }

    return slot;
}

// 0x0809A088
NAKED_FUNCTION
void CutsceneProcessElevatorScrolling(struct CutsceneMonologueOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldrh r0, [r4, #2]\n\
	adds r0, #2\n\
	movs r5, #0\n\
	strh r0, [r4, #2]\n\
	ldr r3, _0809A0F8 @ =0x0400001A\n\
	ldr r2, _0809A0FC @ =gNonGameplayRam\n\
	ldrh r0, [r2, #0x12]\n\
	subs r0, #1\n\
	strh r0, [r2, #0x12]\n\
	ldr r6, _0809A100 @ =0x0000FFFF\n\
	adds r1, r6, #0\n\
	ands r0, r1\n\
	strh r0, [r3]\n\
	ldrb r3, [r4, #9]\n\
	adds r6, r2, #0\n\
	cmp r3, #0\n\
	bne _0809A124\n\
	ldr r0, _0809A104 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809A19A\n\
	ldr r0, _0809A108 @ =gWrittenToBldalpha_Eva\n\
	strh r3, [r0]\n\
	ldr r0, _0809A10C @ =gWrittenToBldalpha_Evb\n\
	movs r2, #0x10\n\
	strh r2, [r0]\n\
	ldr r0, _0809A110 @ =0x04000048\n\
	strh r3, [r0]\n\
	ldr r1, _0809A114 @ =0x0400004A\n\
	ldr r5, _0809A118 @ =0x0000331D\n\
	adds r0, r5, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0809A11C @ =0x04000016\n\
	strh r3, [r6, #0x14]\n\
	strh r3, [r0]\n\
	adds r0, #0x3c\n\
	lsls r2, r2, #8\n\
	strh r2, [r0]\n\
	adds r1, #6\n\
	ldr r6, _0809A120 @ =0x00001042\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r3, #0x82\n\
	lsls r3, r3, #8\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _0809A19A\n\
	.align 2, 0\n\
_0809A0F8: .4byte 0x0400001A\n\
_0809A0FC: .4byte gNonGameplayRam\n\
_0809A100: .4byte 0x0000FFFF\n\
_0809A104: .4byte gWrittenToBldy\n\
_0809A108: .4byte gWrittenToBldalpha_Eva\n\
_0809A10C: .4byte gWrittenToBldalpha_Evb\n\
_0809A110: .4byte 0x04000048\n\
_0809A114: .4byte 0x0400004A\n\
_0809A118: .4byte 0x0000331D\n\
_0809A11C: .4byte 0x04000016\n\
_0809A120: .4byte 0x00001042\n\
_0809A124:\n\
	cmp r3, #1\n\
	bne _0809A164\n\
	ldr r2, _0809A138 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #0xa\n\
	bne _0809A13C\n\
	movs r0, #2\n\
	strb r0, [r4, #9]\n\
	strb r5, [r4, #8]\n\
	b _0809A14E\n\
	.align 2, 0\n\
_0809A138: .4byte gWrittenToBldalpha_Eva\n\
_0809A13C:\n\
	ldrb r0, [r4, #8]\n\
	cmp r0, #3\n\
	bls _0809A14A\n\
	strb r5, [r4, #8]\n\
	adds r0, r1, #1\n\
	strh r0, [r2]\n\
	b _0809A14E\n\
_0809A14A:\n\
	adds r0, #1\n\
	strb r0, [r4, #8]\n\
_0809A14E:\n\
	ldr r0, _0809A15C @ =0x04000016\n\
	ldrh r1, [r6, #0x14]\n\
	subs r1, #3\n\
	strh r1, [r6, #0x14]\n\
	ldr r5, _0809A160 @ =0x0000FFFF\n\
	adds r2, r5, #0\n\
	b _0809A196\n\
	.align 2, 0\n\
_0809A15C: .4byte 0x04000016\n\
_0809A160: .4byte 0x0000FFFF\n\
_0809A164:\n\
	ldr r2, _0809A174 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #4\n\
	bne _0809A178\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	strb r5, [r4, #8]\n\
	b _0809A18A\n\
	.align 2, 0\n\
_0809A174: .4byte gWrittenToBldalpha_Eva\n\
_0809A178:\n\
	ldrb r0, [r4, #8]\n\
	cmp r0, #3\n\
	bls _0809A186\n\
	strb r5, [r4, #8]\n\
	subs r0, r1, #1\n\
	strh r0, [r2]\n\
	b _0809A18A\n\
_0809A186:\n\
	adds r0, #1\n\
	strb r0, [r4, #8]\n\
_0809A18A:\n\
	ldr r0, _0809A1A0 @ =0x04000016\n\
	ldrh r1, [r6, #0x14]\n\
	subs r1, #3\n\
	strh r1, [r6, #0x14]\n\
	ldr r6, _0809A1A4 @ =0x0000FFFF\n\
	adds r2, r6, #0\n\
_0809A196:\n\
	ands r1, r2\n\
	strh r1, [r0]\n\
_0809A19A:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809A1A0: .4byte 0x04000016\n\
_0809A1A4: .4byte 0x0000FFFF\n\
    .syntax divided\n");
}

// 0x0809A1A8
NAKED_FUNCTION
void unk_9a1a8(struct CutsceneMonologueOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldrh r0, [r4, #2]\n\
	subs r0, #2\n\
	movs r5, #0\n\
	strh r0, [r4, #2]\n\
	ldr r3, _0809A218 @ =0x0400001A\n\
	ldr r2, _0809A21C @ =gNonGameplayRam\n\
	ldrh r0, [r2, #0x12]\n\
	adds r0, #1\n\
	strh r0, [r2, #0x12]\n\
	ldr r6, _0809A220 @ =0x0000FFFF\n\
	adds r1, r6, #0\n\
	ands r0, r1\n\
	strh r0, [r3]\n\
	ldrb r3, [r4, #9]\n\
	adds r6, r2, #0\n\
	cmp r3, #0\n\
	bne _0809A244\n\
	ldr r0, _0809A224 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809A2BA\n\
	ldr r0, _0809A228 @ =gWrittenToBldalpha_Eva\n\
	strh r3, [r0]\n\
	ldr r0, _0809A22C @ =gWrittenToBldalpha_Evb\n\
	movs r2, #0x10\n\
	strh r2, [r0]\n\
	ldr r0, _0809A230 @ =0x04000048\n\
	strh r3, [r0]\n\
	ldr r1, _0809A234 @ =0x0400004A\n\
	ldr r5, _0809A238 @ =0x0000331D\n\
	adds r0, r5, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0809A23C @ =0x04000016\n\
	strh r3, [r6, #0x14]\n\
	strh r3, [r0]\n\
	adds r0, #0x3c\n\
	lsls r2, r2, #8\n\
	strh r2, [r0]\n\
	adds r1, #6\n\
	ldr r6, _0809A240 @ =0x00001042\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r3, #0x82\n\
	lsls r3, r3, #8\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _0809A2BA\n\
	.align 2, 0\n\
_0809A218: .4byte 0x0400001A\n\
_0809A21C: .4byte gNonGameplayRam\n\
_0809A220: .4byte 0x0000FFFF\n\
_0809A224: .4byte gWrittenToBldy\n\
_0809A228: .4byte gWrittenToBldalpha_Eva\n\
_0809A22C: .4byte gWrittenToBldalpha_Evb\n\
_0809A230: .4byte 0x04000048\n\
_0809A234: .4byte 0x0400004A\n\
_0809A238: .4byte 0x0000331D\n\
_0809A23C: .4byte 0x04000016\n\
_0809A240: .4byte 0x00001042\n\
_0809A244:\n\
	cmp r3, #1\n\
	bne _0809A284\n\
	ldr r2, _0809A258 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #0xa\n\
	bne _0809A25C\n\
	movs r0, #2\n\
	strb r0, [r4, #9]\n\
	strb r5, [r4, #8]\n\
	b _0809A26E\n\
	.align 2, 0\n\
_0809A258: .4byte gWrittenToBldalpha_Eva\n\
_0809A25C:\n\
	ldrb r0, [r4, #8]\n\
	cmp r0, #3\n\
	bls _0809A26A\n\
	strb r5, [r4, #8]\n\
	adds r0, r1, #1\n\
	strh r0, [r2]\n\
	b _0809A26E\n\
_0809A26A:\n\
	adds r0, #1\n\
	strb r0, [r4, #8]\n\
_0809A26E:\n\
	ldr r0, _0809A27C @ =0x04000016\n\
	ldrh r1, [r6, #0x14]\n\
	adds r1, #3\n\
	strh r1, [r6, #0x14]\n\
	ldr r5, _0809A280 @ =0x0000FFFF\n\
	adds r2, r5, #0\n\
	b _0809A2B6\n\
	.align 2, 0\n\
_0809A27C: .4byte 0x04000016\n\
_0809A280: .4byte 0x0000FFFF\n\
_0809A284:\n\
	ldr r2, _0809A294 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #4\n\
	bne _0809A298\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	strb r5, [r4, #8]\n\
	b _0809A2AA\n\
	.align 2, 0\n\
_0809A294: .4byte gWrittenToBldalpha_Eva\n\
_0809A298:\n\
	ldrb r0, [r4, #8]\n\
	cmp r0, #3\n\
	bls _0809A2A6\n\
	strb r5, [r4, #8]\n\
	subs r0, r1, #1\n\
	strh r0, [r2]\n\
	b _0809A2AA\n\
_0809A2A6:\n\
	adds r0, #1\n\
	strb r0, [r4, #8]\n\
_0809A2AA:\n\
	ldr r0, _0809A2C0 @ =0x04000016\n\
	ldrh r1, [r6, #0x14]\n\
	adds r1, #3\n\
	strh r1, [r6, #0x14]\n\
	ldr r6, _0809A2C4 @ =0x0000FFFF\n\
	adds r2, r6, #0\n\
_0809A2B6:\n\
	ands r1, r2\n\
	strh r1, [r0]\n\
_0809A2BA:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809A2C0: .4byte 0x04000016\n\
_0809A2C4: .4byte 0x0000FFFF\n\
    .syntax divided\n");
}

/**
 * @brief 9a2c8 | 54 | V-blank for the elevator monologue cutscenes
 * 
 */
void CutsceneElevatorMonologueVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);
    unk_9cc4c();
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief 9a31c | c | V-blank that only updates the audio
 * 
 */
void unk_9a31c(void)
{
    UpdateAudio();
}
