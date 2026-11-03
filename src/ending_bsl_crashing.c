#include "ending_bsl_crashing.h"
#include "ending_in_ship.h"
#include "special_cutscene.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "syscalls.h"
#include "music_wrappers.h"

#include "constants/audio.h"

#include "data/generic_data.h"
#include "data/intro_data.h"
extern const u8 sAddr_6238f4[];
extern const u8 sAddr_626738[];
extern const u8 sAddr_62b5f4[];
extern const u8 sAddr_636020[];
extern const u8 sAddr_636038[];
extern const u8 sAddr_636050[];
extern const u8 sAddr_636288[];
extern const u8 sAddr_6362a0[];
extern const u8 sAddr_6362b8[];
extern const u8 sAddr_6363a0[];
extern const u8 sAddr_6363b8[];
extern const u8 sAddr_636a38[];
extern const u8 sAddr_636c38[];
extern const u8 sAddr_636e38[];
extern const u8 sAddr_637038[];
extern const u8 sAddr_638c14[];
extern const u8 sAddr_63929c[];
extern const u8 sAddr_6395b8[];
extern const u8 sAddr_639bc4[];

void Sram_ProcessEndingSave(u8 stage);

/**
 * @brief 94e84 | f0 | Main handler for the ending cutscenes
 * 
 */
boolu32 EndingHandler(void)
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
            if (EndingBslCrashing())
                gSubGameMode1 = 2;
            break;

        case 2:
            if (EndingInShip())
            {
                INTRO_DATA.unk_20E = 0;
                gSubGameMode1 = 3;
            }
            break;

        case 3:
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
                    Sram_ProcessEndingSave(0);
                }
                else if (INTRO_DATA.unk_20E == 2)
                {
                    Sram_ProcessEndingSave(1);
                }
                else if (INTRO_DATA.unk_20E == 3)
                {
                    Sram_ProcessEndingSave(2);
                }
                else if (INTRO_DATA.unk_20E == 4)
                {
                    Sram_ProcessEndingSave(3);
                    INTRO_DATA.unk_20E = 0;
                    ended = TRUE;
                }
            }
            SpecialCutsceneDrawAllOam();
            break;
    }

    return ended;
}

/**
 * @brief 94f74 | 204 | Setup for the ending BSL crashing cutscene
 * 
 */
void EndingBslCrashingInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    LZ77UncompVram((const u32*)sAddr_6238f4, VRAM_OBJ);
    DMA3_COPY_32((const u16*)sAddr_636c38, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);

    LZ77UncompVram((const u32*)sAddr_62b5f4, VRAM_BASE);
    LZ77UncompVram((const u32*)sAddr_638c14, VRAM_BASE + 0xF000);
    LZ77UncompVram((const u32*)sAddr_639bc4, VRAM_BASE + 0xF800);
    DMA3_COPY_32((const u16*)sAddr_637038, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);

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

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = 8;
    gWrittenToBldalpha_Evb = 14;

    EndingBslCrashingSetupOam(5, -40, 200, FALSE);
    EndingBslCrashingSetupOam(4, 128, 72, TRUE);
    EndingBslCrashingSetupOam(2, 164, 40, TRUE);
    EndingBslCrashingSetupOam(1, 164, 40, TRUE);
    EndingBslCrashingSetupOam(3, 134, 60, TRUE);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);

    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(EndingBslCrashingVblank);
}

/**
 * @brief 95178 | 200 | Setup for the ending ship front view
 * 
 */
void EndingShipFrontViewInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
    DMA3_FILL_16(0, INTRO_DATA.unk_14, sizeof(INTRO_DATA.unk_14));
    DMA3_FILL_16(0, &INTRO_DATA.unk_110, sizeof(INTRO_DATA.unk_14));

    LZ77UncompVram((const u32*)sAddr_626738, VRAM_BASE);
    LZ77UncompVram((const u32*)sAddr_63929c, VRAM_BASE + 0xF000);
    LZ77UncompVram((const u32*)sAddr_6395b8, VRAM_BASE + 0xF800);
    DMA3_COPY_32((const u16*)sAddr_636e38, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);

    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg2XPosition = 0;
    gBg2YPosition = -30;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    EndingBslCrashingSetupOam(12, 0, gBg2YPosition, FALSE);
    EndingBslCrashingSetupOam(10, 120, 106, TRUE);
    EndingBslCrashingSetupOam(11, 120, 64, FALSE);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);

    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(EndingShipFrontViewVblank);
}

/**
 * @brief 95378 | 2c4 | x
 * 
 */
boolu32 EndingBslCrashingProcess(void)
{
    boolu32 ended;

    ended = FALSE;
    INTRO_DATA.timer++;

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (gWrittenToBldy != 0)
            {
                if (gWrittenToBldy == BLDY_MAX_VALUE)
                    SoundPlay_3b1c(SOUND_24B);
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
            else if (INTRO_DATA.timer == 20)
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
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 5;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 5:
            if (INTRO_DATA.timer == 10)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 6;
                EndingShipFrontViewInit();
            }
            break;

        case 6:
            WRITE_16(REG_BLDCNT, BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);
            INTRO_DATA.timer = 0;
            INTRO_DATA.subStage = 7;
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 7:
            if (INTRO_DATA.timer == 168)
            {
                INTRO_DATA.timer = 0;
                gWrittenToBldy = 2;
                INTRO_DATA.subStage = 8;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 8:
            if (INTRO_DATA.timer == 1)
            {
                INTRO_DATA.timer = 0;
                if (gWrittenToBldalpha_Eva != 0)
                {
                    gWrittenToBldalpha_Eva--;
                    if (gWrittenToBldalpha_Eva == 0)
                        SpecialCutsceneDestroyOamOfType(10);
                }
                else
                {
                    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                    INTRO_DATA.subStage = 9;
                }
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 9:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (INTRO_DATA.timer == 4)
                {
                    gWrittenToBldy++;
                    INTRO_DATA.timer = 0;
                }
            }
            else if (INTRO_DATA.timer == 90)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 0;
                ended = TRUE;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    return ended;
}

/**
 * @brief 9563c | 88 | Main handler for the ending BSL crashing cutscene
 * 
 */
boolu32 EndingBslCrashing(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            EndingBslCrashingInit();
            INTRO_DATA.stage = 2;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (gWrittenToBldy == 0)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (EndingBslCrashingProcess())
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
 * @brief 956c4 | d8 | Processes the falling BSL
 * 
 */
void EndingProcessFallingBsl(struct SpecialCutsceneOam* pOam)
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
            pOam->pOam = (const struct FrameData*)sAddr_6362b8;
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
 * @brief 9579c | 30 | To document
 * 
 */
void unk_9579c(struct SpecialCutsceneOam* pOam)
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
 * @brief 957cc | 64 | Processes the small ship leaving
 * 
 */
void EndingProcessLeavingSmallShip(struct SpecialCutsceneOam* pOam)
{
    s32 timer;

    timer = pOam->unk_A + 1;
    pOam->unk_A = timer;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        if ((u16)timer == 150)
        {
            pOam->unk_A = 0;
            pOam->unk_18_0 = 1;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->xPosition = pOam->spawnX - timer * 4;
        pOam->yPosition = pOam->spawnY + pOam->unk_A / 3;
        if (pOam->xPosition < 0)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 95830 | 64 | Processes the big ship leaving
 * 
 */
void EndingProcessLeavingBigShip(struct SpecialCutsceneOam* pOam)
{
    s32 timer;

    timer = pOam->unk_A + 1;
    pOam->unk_A = timer;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        if ((u16)timer == 240)
        {
            pOam->unk_A = 0;
            pOam->unk_18_0 = 1;
            pOam->stage = 1;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->xPosition = pOam->spawnX + timer * 4;
        pOam->yPosition = pOam->spawnY - pOam->unk_A * 3;
        if (pOam->xPosition > 280)
        {
            pOam->type = 0;
            pOam->unk_18_0 = 0;
        }
    }
}

/**
 * @brief 95894 | 34 | Processes the thrusters of the front facing ship
 * 
 */
void EndingProcessFrontFacingShipThrusters(struct SpecialCutsceneOam* pOam)
{
    s16 x;
    s16 y;

    if (pOam->stage == 0)
    {
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }

    EndingGetPositionAndSlotOfOamByType(12, &x, &y);
    pOam->yPosition = pOam->spawnY - y;
}

/**
 * @brief 958c8 | 90 | Processes the front facing ship
 * 
 */
void EndingProcessFrontFacingShip(struct SpecialCutsceneOam* pOam)
{
    pOam->unk_A++;

    if (pOam->stage == 0)
    {
        pOam->spawnY = pOam->yPosition;
        pOam->unk_A = 0;
        pOam->timer = 4;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        pOam->yPosition = (SIN(pOam->timer) >> 3) + pOam->spawnY;
        if (pOam->timer == 64)
        {
            pOam->stage = 2;
            pOam->unk_A = 0;
        }
    }
    else if (pOam->stage == 2)
    {
        if (pOam->unk_A == 2)
        {
            pOam->unk_A = 0;
            pOam->timer++;
        }
        pOam->yPosition = (SIN(pOam->timer) >> 3) + pOam->spawnY;
    }

    gBg2YPosition = pOam->yPosition;
}

/**
 * @brief 95958 | 2fc | Sets up an ending BSL crashing OAM
 * 
 */
u8 EndingBslCrashingSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
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
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_636020;
        INTRO_DATA.oam[slot].pFunction = EndingProcessFallingBsl;
    }
    else if (type == 2)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(2);
        INTRO_DATA.oam[slot].unk_18_3 = 1;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_636038;
        INTRO_DATA.oam[slot].pFunction = EndingProcessFallingBsl;
    }
    else if (type == 3)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_636050;
        INTRO_DATA.oam[slot].pFunction = unk_9579c;
    }
    else if (type == 4)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_636288;
        INTRO_DATA.oam[slot].pFunction = EndingProcessLeavingSmallShip;
    }
    else if (type == 5)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6362a0;
        INTRO_DATA.oam[slot].pFunction = EndingProcessLeavingBigShip;
    }
    else if (type == 10)
    {
        INTRO_DATA.oam[slot].unk_18_3 = 1;
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6363a0;
        INTRO_DATA.oam[slot].pFunction = unk_95e20;
    }
    else if (type == 11)
    {
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6363b8;
        INTRO_DATA.oam[slot].pFunction = EndingProcessFrontFacingShipThrusters;
    }
    else if (type == 12)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6363a0;
        INTRO_DATA.oam[slot].pFunction = EndingProcessFrontFacingShip;
    }

    return slot;
}

/**
 * @brief 95c54 | d8 | V-blank for the ending BSL crashing cutscene
 * 
 */
void EndingBslCrashingVblank(void)
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
        DMA3_COPY_32(((const u16*)sAddr_636a38 + INTRO_DATA.unk_111 * 16), PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);
    }
}

/**
 * @brief 95d2c | 94 | V-blank for the ending ship front view
 * 
 */
void EndingShipFrontViewVblank(void)
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
 * @brief 95dc0 | 60 | Gets the position and slot of an OAM by type
 * 
 */
u8 EndingGetPositionAndSlotOfOamByType(u8 type, s16* pXPosition, s16* pYPosition)
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
 * @brief 95e20 | 4 | Empty function
 * 
 */
void unk_95e20(struct SpecialCutsceneOam* pOam)
{
    return;
}
