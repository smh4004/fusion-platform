#include "died_on_sr388_collision.h"
#include "special_cutscene.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "syscalls.h"
#include "music_wrappers.h"

#include "constants/audio.h"

#include "data/generic_data.h"
#include "data/intro_data.h"

/**
 * @brief 9741c | a8 | Main handler for the died on SR388 collision cutscene
 * 
 */
boolu32 DiedFromSr388CollisionHandler(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (gSubGameMode1)
    {
        case 0:
            DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
            gSubGameMode1 = 1;
            break;

        case 1:
            if (DiedOnSr388Collision())
            {
                INTRO_DATA.unk_20E = 0;
                gSubGameMode1 = 2;
            }
            break;

        case 2:
            if (INTRO_DATA.unk_20E == 0)
            {
                if (gWrittenToBldy < BLDY_MAX_VALUE)
                    gWrittenToBldy++;
                else
                    ended = TRUE;
            }
            else
            {
                INTRO_DATA.unk_20E--;
            }

            SpecialCutsceneDrawAllOam();
            break;
    }

    return ended;
}

/**
 * @brief 974c4 | 1f4 | Setup for the died on SR388 collision cutscene
 * 
 */
void DiedOnSr388CollisionInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    LZ77UncompVram((const u32*)0x86238f4, VRAM_OBJ);
    DMA3_COPY_32((const u16*)0x8636c38, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);

    LZ77UncompVram((const u32*)0x862b5f4, VRAM_BASE);
    LZ77UncompVram((const u32*)0x8638c14, VRAM_BASE + 0xF000);
    LZ77UncompVram((const u32*)0x8639bc4, VRAM_BASE + 0xF800);
    DMA3_COPY_32((const u16*)0x8637038, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);

    gBg1XPosition = 0;
    gBg1YPosition = 8;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 8);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = 8;
    gWrittenToBldalpha_Evb = 14;

    SoundPlay_3b1c(SOUND_24D);

    DiedOnSr388CollisionSetupOam(2, 164, 40, TRUE);
    DiedOnSr388CollisionSetupOam(1, 164, 40, TRUE);
    DiedOnSr388CollisionSetupOam(3, 134, 60, TRUE);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);

    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(DiedOnSr388CollisionVblank);
}

/**
 * @brief 976b8 | 1b8 | Processes the died on SR388 collision cutscene
 * 
 */
boolu32 DiedOnSr388CollisionProcess(void)
{
    boolu32 ended;

    ended = FALSE;
    INTRO_DATA.timer++;

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (gWrittenToBldy != 0)
            {
                gWrittenToBldy--;
            }
            else
            {
                WRITE_16(REG_BLDCNT, BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 1;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 1:
            INTRO_DATA.timer = 0;
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (INTRO_DATA.timer == 1)
            {
                gWrittenToBldalpha_Eva = 10;
                gWrittenToBldalpha_Evb = 10;
                INTRO_DATA.unk_110 = 1;
                INTRO_DATA.unk_111 = 0;
            }
            else if (INTRO_DATA.timer == 2)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 3;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 3:
            if (INTRO_DATA.unk_111 < 15)
            {
                if (INTRO_DATA.timer == 4)
                {
                    INTRO_DATA.timer = 0;
                    INTRO_DATA.unk_110 = 1;
                    INTRO_DATA.unk_111++;
                }
            }
            else if (INTRO_DATA.timer == 15)
            {
                INTRO_DATA.timer = 0;
                gWrittenToBldy = BLDY_MAX_VALUE;
                INTRO_DATA.subStage = 4;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 4:
            if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
            {
                if (INTRO_DATA.timer == 6)
                {
                    INTRO_DATA.timer = 0;
                    gWrittenToBldalpha_Eva++;
                    gWrittenToBldalpha_Evb++;
                }
            }
            else
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
                if (INTRO_DATA.timer == 15)
                {
                    INTRO_DATA.timer = 0;
                    INTRO_DATA.subStage = 0;
                    ended = TRUE;
                }
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return ended;
}

/**
 * @brief 97870 | 88 | Main handler for the died on SR388 collision cutscene
 * 
 */
boolu32 DiedOnSr388Collision(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            DiedOnSr388CollisionInit();
            INTRO_DATA.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (gWrittenToBldy == 0)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (DiedOnSr388CollisionProcess())
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
 * @brief 978f8 | d8 | Processes the falling BSL
 * 
 */
void DiedOnSr388CollisionProcessFallingBsl(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    pOam->unk_A++;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->unk_A = 0;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
            pOam->animationDurationCounter = 0;

        pOam->xPosition = pOam->spawnX - pOam->unk_A / 5;
        pOam->yPosition = pOam->spawnY + pOam->unk_A / 5;

        if (pOam->yPosition > 80)
        {
            pOam->unk_A = 0;
            pOam->stage = 2;
        }

        if (pOam->type == 1)
            pOam->scaling -= 1;
        else
            pOam->scaling -= 2;
    }
    else if (pOam->stage == 2)
    {
        pOam->stage = 3;
        if (pOam->type == 1)
        {
            pOam->pOam = (const struct FrameData*)0x86362b8;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            INTRO_DATA.subStage = 2;
        }
        else
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
    else if (pOam->stage == 3)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 979d0 | 30 | To document
 * 
 */
void unk_979d0(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->stage == 0)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 97a00 | 200 | Sets up a died on SR388 collision OAM
 * 
 */
u8 DiedOnSr388CollisionSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
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
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8636020;
        INTRO_DATA.oam[slot].pFunction = DiedOnSr388CollisionProcessFallingBsl;
    }
    else if (type == 2)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(2);
        INTRO_DATA.oam[slot].unk_18_3 = 1;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8636038;
        INTRO_DATA.oam[slot].pFunction = DiedOnSr388CollisionProcessFallingBsl;
    }
    else if (type == 3)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)0x8636050;
        INTRO_DATA.oam[slot].pFunction = unk_979d0;
    }

    return slot;
}

/**
 * @brief 97c00 | d8 | V-blank for the died on SR388 collision cutscene
 * 
 */
void DiedOnSr388CollisionVblank(void)
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
        DMA3_COPY_32(((const u16*)0x8636a38 + INTRO_DATA.unk_111 * 16), PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);
    }
}

/**
 * @brief 97cd8 | 94 | Unused V-blank for the died on SR388 collision cutscene
 * 
 */
void DiedOnSr388CollisionVblank_Unused(void)
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
 * @brief 97d6c | 60 | Gets the position and slot of an OAM by type
 * 
 */
u8 DiedOnSr388CollisionGetPositionAndSlotOfOamByType(u8 type, s16* pXPosition, s16* pYPosition)
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
 * @brief 97dcc | 4 | Empty function
 * 
 */
void unk_97dcc(struct SpecialCutsceneOam* pOam)
{
    return;
}
