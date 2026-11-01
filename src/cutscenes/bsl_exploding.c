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
 * @brief 9c1c8 | 8c | Main handler for the BSL exploding cutscene
 * 
 */
boolu32 CutsceneBslExploding(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (CUTSCENE_OAM_DATA.stage)
    {
        case 0:
            CUTSCENE_OAM_DATA.stage = 1;
            CutsceneBslExplodingInit();
            break;

        case 1:
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                SoundPlay_3b1c(SOUND_247);

            CutsceneFadeIn();
            if (gWrittenToBldy == 0)
                CUTSCENE_OAM_DATA.stage++;
            break;

        case 2:
            if (CutsceneBslExplodingProcess())
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

// 0x0809C254
NAKED_FUNCTION
void CutsceneBslExplodingInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	ldr r3, _0809C360 @ =0x04000208\n\
	movs r5, #0\n\
	strh r5, [r3]\n\
	ldr r2, _0809C364 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809C368 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _0809C36C @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809C370 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _0809C374 @ =unk_9c92c\n\
	bl CallbackSetVBlank\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x13\n\
	mov r8, r0\n\
	strh r5, [r0]\n\
	ldr r0, _0809C378 @ =0x0867D7CC\n\
	ldr r1, _0809C37C @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r4, _0809C380 @ =0x040000D4\n\
	ldr r0, _0809C384 @ =0x0868121C\n\
	str r0, [r4]\n\
	ldr r0, _0809C388 @ =0x05000200\n\
	str r0, [r4, #4]\n\
	ldr r6, _0809C38C @ =0x84000080\n\
	str r6, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809C390 @ =0x08679420\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C394 @ =0x08681A1C\n\
	ldr r1, _0809C398 @ =0x0600E000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C39C @ =0x086820A4\n\
	ldr r1, _0809C3A0 @ =0x0600E800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C3A4 @ =0x086827A8\n\
	ldr r1, _0809C3A8 @ =0x0600F000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C3AC @ =0x08682BFC\n\
	ldr r1, _0809C3B0 @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C3B4 @ =0x0868259C\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	str r6, [r4, #8]\n\
	ldr r1, [r4, #8]\n\
	strh r5, [r0]\n\
	ldr r1, _0809C3B8 @ =0x04000008\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _0809C3BC @ =0x00001D03\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	adds r2, #0xfd\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _0809C3C0 @ =0x00001F03\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #5\n\
	adds r0, r1, #0\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
	ldr r0, _0809C3C4 @ =gWrittenToBldy\n\
	movs r2, #0x10\n\
	strh r2, [r0]\n\
	ldr r1, _0809C3C8 @ =gWrittenToBldalpha_Eva\n\
	movs r0, #8\n\
	strh r0, [r1]\n\
	ldr r0, _0809C3CC @ =gWrittenToBldalpha_Evb\n\
	strh r2, [r0]\n\
	movs r0, #1\n\
	movs r1, #0\n\
	movs r2, #0\n\
	movs r3, #0\n\
	bl CutsceneBslExplodingSetupOam\n\
	movs r0, #0x14\n\
	movs r1, #0x70\n\
	movs r2, #0x58\n\
	movs r3, #0\n\
	bl CutsceneBslExplodingSetupOam\n\
	ldr r0, _0809C3D0 @ =gNonGameplayRam\n\
	movs r1, #0\n\
	strh r1, [r0, #0xa]\n\
	strh r1, [r0, #0xc]\n\
	movs r1, #0xc\n\
	ldrsh r0, [r0, r1]\n\
	lsls r0, r0, #5\n\
	ldr r1, _0809C3D4 @ =0x0868101C\n\
	adds r0, r0, r1\n\
	str r0, [r4]\n\
	ldr r0, _0809C3D8 @ =0x05000120\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809C3DC @ =0x84000008\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	bl CutsceneDrawAllOam\n\
	ldr r0, _0809C3E0 @ =CutsceneBslExplodingVblank\n\
	bl CallbackSetVBlank\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809C360: .4byte 0x04000208\n\
_0809C364: .4byte 0x04000004\n\
_0809C368: .4byte 0x0000FFEF\n\
_0809C36C: .4byte 0x04000200\n\
_0809C370: .4byte 0x0000FFFD\n\
_0809C374: .4byte unk_9c92c\n\
_0809C378: .4byte 0x0867D7CC\n\
_0809C37C: .4byte 0x06010000\n\
_0809C380: .4byte 0x040000D4\n\
_0809C384: .4byte 0x0868121C\n\
_0809C388: .4byte 0x05000200\n\
_0809C38C: .4byte 0x84000080\n\
_0809C390: .4byte 0x08679420\n\
_0809C394: .4byte 0x08681A1C\n\
_0809C398: .4byte 0x0600E000\n\
_0809C39C: .4byte 0x086820A4\n\
_0809C3A0: .4byte 0x0600E800\n\
_0809C3A4: .4byte 0x086827A8\n\
_0809C3A8: .4byte 0x0600F000\n\
_0809C3AC: .4byte 0x08682BFC\n\
_0809C3B0: .4byte 0x0600F800\n\
_0809C3B4: .4byte 0x0868259C\n\
_0809C3B8: .4byte 0x04000008\n\
_0809C3BC: .4byte 0x00001D03\n\
_0809C3C0: .4byte 0x00001F03\n\
_0809C3C4: .4byte gWrittenToBldy\n\
_0809C3C8: .4byte gWrittenToBldalpha_Eva\n\
_0809C3CC: .4byte gWrittenToBldalpha_Evb\n\
_0809C3D0: .4byte gNonGameplayRam\n\
_0809C3D4: .4byte 0x0868101C\n\
_0809C3D8: .4byte 0x05000120\n\
_0809C3DC: .4byte 0x84000008\n\
_0809C3E0: .4byte CutsceneBslExplodingVblank\n\
    .syntax divided\n");
}

/**
 * @brief 9c3e4 | 214 | Processes the BSL exploding cutscene
 * 
 */
boolu32 CutsceneBslExplodingProcess(void)
{
    boolu32 ended;

    ended = FALSE;
    CUTSCENE_OAM_DATA.timer++;

    switch (CUTSCENE_OAM_DATA.subStage)
    {
        case 0:
            CUTSCENE_OAM_DATA.timer = 0;
            CUTSCENE_OAM_DATA.subStage = 1;
            break;

        case 1:
            if (CUTSCENE_OAM_DATA.timer == 15)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                    BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG2);
                CUTSCENE_OAM_DATA.timer = 0;
                CUTSCENE_OAM_DATA.subStage = 2;
            }
            break;

        case 2:
            if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
            {
                if (CUTSCENE_OAM_DATA.timer == 1)
                {
                    CUTSCENE_OAM_DATA.timer = 0;
                    gWrittenToBldalpha_Eva += 2;
                }
                gWrittenToBldy = BLDY_MAX_VALUE;
            }
            else if (CUTSCENE_OAM_DATA.timer == 40)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                WRITE_16(REG_DISPCNT, DCNT_BG1 | DCNT_OBJ);
                CutsceneDestroyOamOfType(1);
                CutsceneDestroyOamOfType(20);
                CutsceneBslExplodingSetupOam(21, 120, 90, TRUE);
                CUTSCENE_OAM_DATA.timer = 0;
                CUTSCENE_OAM_DATA.subStage = 3;
            }
            break;

        case 3:
            if (CUTSCENE_OAM_DATA.timer == 1)
            {
                gWrittenToBldy = 0;
                gWrittenToBldalpha_Eva = 10;
                gWrittenToBldalpha_Evb = 10;
                CUTSCENE_OAM_DATA.timer = 0;
                CUTSCENE_OAM_DATA.subStage = 4;
            }
            break;

        case 4:
            if (CUTSCENE_OAM_DATA.timer == 60)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                    BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
                CUTSCENE_OAM_DATA.timer = 0;
                CUTSCENE_OAM_DATA.subStage = 5;
            }
            break;

        case 5:
            if (CUTSCENE_OAM_DATA.unk_C < 15)
            {
                if (CUTSCENE_OAM_DATA.timer == 4)
                {
                    CUTSCENE_OAM_DATA.timer = 0;
                    CUTSCENE_OAM_DATA.unk_A = 1;
                    CUTSCENE_OAM_DATA.unk_C++;

                    if (CUTSCENE_OAM_DATA.unk_C == 1)
                    {
                        CutsceneBslExplodingSetupOam(22, 120, 96, FALSE);
                        CutsceneBslExplodingSetupOam(22, 95, 80, FALSE);
                        CutsceneBslExplodingSetupOam(22, 140, 105, FALSE);
                    }
                    else if (CUTSCENE_OAM_DATA.unk_C == 2)
                    {
                        CutsceneBslExplodingSetupOam(22, 120, 84, FALSE);
                        CutsceneBslExplodingSetupOam(22, 145, 85, FALSE);
                    }
                    else if (CUTSCENE_OAM_DATA.unk_C == 3)
                    {
                        CutsceneBslExplodingSetupOam(22, 96, 106, FALSE);
                    }
                }
            }
            else if (CUTSCENE_OAM_DATA.timer == 15)
            {
                CUTSCENE_OAM_DATA.timer = 0;
                gWrittenToBldy = BLDY_MAX_VALUE;
                CUTSCENE_OAM_DATA.subStage = 6;
            }
            break;

        case 6:
            if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
            {
                if (CUTSCENE_OAM_DATA.timer == 6)
                {
                    CUTSCENE_OAM_DATA.timer = 0;
                    gWrittenToBldalpha_Eva++;
                }
            }
            else
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
                if (CUTSCENE_OAM_DATA.timer == 16)
                {
                    CUTSCENE_OAM_DATA.timer = 0;
                    ended = TRUE;
                }
            }
            break;
    }

    CutsceneProcessOam();
    CutsceneDrawAllOam();
    return ended;
}

/**
 * @brief 9c5f8 | 2c | Processes the scrolling of the BSL exploding cutscene
 * 
 */
void CutsceneBslExplodingProcessScrolling(struct CutsceneOam* pOam)
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
 * @brief 9c624 | 5c | Processes the far BSL
 * 
 */
void CutsceneBslExplodingProcessBslFar(struct CutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->stage == 0)
    {
        if (CUTSCENE_OAM_DATA.subStage == 5 && CUTSCENE_OAM_DATA.unk_C == 5)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x8680ecc;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->enabled = FALSE;
        }
    }
}

/**
 * @brief 9c680 | 2c | Processes the explosions
 * 
 */
void CutsceneBslExplodingProcessExplosions(struct CutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    pFrame = &pOam->pOam[pOam->currentAnimationFrame];
    if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9c6ac | 1a4 | Sets up a BSL exploding OAM
 * 
 */
u8 CutsceneBslExplodingSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
{
    s8 slot;

    if (!descendingSearch)
    {
        for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_OAM_DATA.oam); slot++)
        {
            if (CUTSCENE_OAM_DATA.oam[slot].type == 0)
                break;
        }
        
        if (slot > 15)
            return 16;
    }
    else
    {
        for (slot = ARRAY_SIZE(CUTSCENE_OAM_DATA.oam) - 1; slot >= 0; slot--)
        {
            if (CUTSCENE_OAM_DATA.oam[slot].type == 0)
                break;
        }
        
        if (slot < 0)
            return 16;
    }

    DMA3_FILL_32(0, &CUTSCENE_OAM_DATA.oam[slot], sizeof(struct CutsceneOam));

    CUTSCENE_OAM_DATA.oam[slot].xPosition = xPosition;
    CUTSCENE_OAM_DATA.oam[slot].yPosition = yPosition;
    CUTSCENE_OAM_DATA.oam[slot].type = type;
    CUTSCENE_OAM_DATA.oam[slot].enabled = TRUE;

    if (type == 1)
    {
        CUTSCENE_OAM_DATA.oam[slot].enabled = FALSE;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneBslExplodingProcessScrolling;
    }
    else if (type == 20)
    {
        CUTSCENE_OAM_DATA.oam[slot].priority = 2;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)0x8680ffc;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9db70;
    }
    else if (type == 21)
    {
        CUTSCENE_OAM_DATA.oam[slot].priority = 2;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)0x868100c;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneBslExplodingProcessBslFar;
    }
    else if (type == 22)
    {
        CUTSCENE_OAM_DATA.oam[slot].priority = 2;
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)0x8680ecc;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneBslExplodingProcessExplosions;
    }

    return slot;
}

/**
 * @brief 9c850 | 58 | Gets the position and scaling of a BSL exploding OAM by type
 * 
 */
u8 CutsceneBslExplodingGetOamInfoByType(u8 type, s16* pXPosition, s16* pYPosition, s16* pScaling)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_OAM_DATA.oam); slot++)
    {
        if (CUTSCENE_OAM_DATA.oam[slot].type == type)
        {
            *pXPosition = CUTSCENE_OAM_DATA.oam[slot].xPosition;
            *pYPosition = CUTSCENE_OAM_DATA.oam[slot].yPosition;
            *pScaling = CUTSCENE_OAM_DATA.oam[slot].scaling;
            return slot;
        }
    }

    *pXPosition = 300;
    *pYPosition = 200;
    *pScaling = Q_8_8(1);
    return 0;
}

/**
 * @brief 9c8a8 | 84 | V-blank for the BSL exploding cutscene
 * 
 */
void CutsceneBslExplodingVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);

    if (CUTSCENE_OAM_DATA.unk_A == 1)
    {
        CUTSCENE_OAM_DATA.unk_A = 0;
        DMA3_COPY_32(&((const u16*)0x868101c)[CUTSCENE_OAM_DATA.unk_C * 16], PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);
    }
}

/**
 * @brief 9c92c | c | V-blank that only updates the audio
 * 
 */
void unk_9c92c(void)
{
    UpdateAudio();
}
