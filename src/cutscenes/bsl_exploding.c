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

/**
 * @brief 9c254 | 190 | Setup for the BSL exploding cutscene
 *
 */
void CutsceneBslExplodingInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_9c92c);

    WRITE_16(REG_DISPCNT, 0);

    LZ77UncompVram((const u32*)0x867d7cc, VRAM_OBJ);
    DMA3_COPY_32((const u16*)0x868121c, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);

    LZ77UncompVram((const u32*)0x8679420, VRAM_BASE);
    LZ77UncompVram((const u32*)0x8681a1c, VRAM_BASE + 0xE000);
    LZ77UncompVram((const u32*)0x86820a4, VRAM_BASE + 0xE800);
    LZ77UncompVram((const u32*)0x86827a8, VRAM_BASE + 0xF000);
    LZ77UncompVram((const u32*)0x8682bfc, VRAM_BASE + 0xF800);
    DMA3_COPY_32((const u16*)0x868259c, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
    WRITE_16(PALRAM_BASE, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 29, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);

    gWrittenToBldy = BLDY_MAX_VALUE;
    gWrittenToBldalpha_Eva = 8;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;

    CutsceneBslExplodingSetupOam(1, 0, 0, FALSE);
    CutsceneBslExplodingSetupOam(20, 112, 88, FALSE);

    CUTSCENE_OAM_DATA.unk_A = 0;
    CUTSCENE_OAM_DATA.unk_C = 0;
    DMA3_COPY_32(&sCutsceneBslFirePal[CUTSCENE_OAM_DATA.unk_C * 16], PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);

    CutsceneDrawAllOam();
    CallbackSetVBlank(CutsceneBslExplodingVblank);
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
        DMA3_COPY_32(&sCutsceneBslFirePal[CUTSCENE_OAM_DATA.unk_C * 16], PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);
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
