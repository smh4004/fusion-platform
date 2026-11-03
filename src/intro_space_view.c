#include "intro_space_view.h"
#include "special_cutscene.h"
#include "new_file_intro.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "syscalls.h"
#include "audio_wrappers.h"
#include "music_wrappers.h"

#include "constants/audio.h"

#include "data/audio.h"
#include "data/generic_data.h"
#include "data/intro_data.h"
#include "data/sprite_data.h"

/**
 * @brief 93980 | 240 | Setup for the title intro space view
 * 
 */
void IntroSpaceViewInit(void)
{
    u16 i;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);
    DoSoundAction(0x1000000);
    StopAllMusicAndSounds();

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    LZ77UncompVram(sTitleIntroBslObjGfx, VRAM_OBJ);
    DMA3_COPY_32(sIntroSamusDriftingIntoAsteroidsObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);

    LZ77UncompVram(sIntroBslSpaceBgGfx, VRAM_BASE);
    LZ77UncompWram(sIntroBslTilemap, EWRAM_BASE + 0x10000);
    DMA3_COPY_32(EWRAM_BASE + 0x10000, VRAM_BASE + 0xE800, 0x800 / 4);
    DMA3_FILL_16(0x1FF, VRAM_BASE + 0xF000, 0x800);

    LZ77UncompVram(sIntroSpaceTilemap, VRAM_BASE + 0xF800);
    DMA3_COPY_32(sIntroBslSpaceBgPal, PALRAM_BASE + 0x100, 8 * PAL_ROW_SIZE / 4);
    WRITE_16(PALRAM_BASE, 0);

    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

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
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 29, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_512x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    IntroSpaceViewSetupOam(1, 0, 0, TRUE);
    IntroSpaceViewSetupOam(2, -240, -110, TRUE);

    for (i = 0; i < 10; i++)
        IntroSpaceViewSetupOam(5, SpecialCutsceneGetRandomNumber(), SpecialCutsceneGetRandomNumber(), TRUE);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);

    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(IntroSpaceViewVblank);
    PlayMusic(MUSIC_60, 15);
}

/**
 * @brief 93bc0 | 38c | Processes the space view part of the title intro
 * 
 */
boolu32 IntroSpaceViewPartProcess(void)
{
    boolu32 result;

    result = FALSE;
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
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 1;
            }

            if (SpecialCutsceneGetRandomNumber() < 64 && INTRO_DATA.unk_215 < 14)
                IntroSpaceViewSetupOam(5, SpecialCutsceneGetRandomNumber(), SpecialCutsceneGetRandomNumber(), TRUE);
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 1:
            if (INTRO_DATA.timer == 30)
            {
                INTRO_DATA.timer = 0;
                IntroSpaceViewSetupOam(4, 120, 74, FALSE);
                INTRO_DATA.subStage = 2;
            }

            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
                IntroSpaceViewSetupOam(5, 0, SpecialCutsceneGetRandomNumber(), TRUE);
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (INTRO_DATA.timer == 480)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 3;
            }

            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
                IntroSpaceViewSetupOam(5, 0, SpecialCutsceneGetRandomNumber(), TRUE);
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 3:
            if (INTRO_DATA.timer == 30)
            {
                SoundPlay(SOUND_1E9);
            }
            else if (INTRO_DATA.timer == 1050)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 5;
            }

            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 12)
                IntroSpaceViewSetupOam(5, 0, SpecialCutsceneGetRandomNumber(), TRUE);
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 4:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (gWrittenToBldy == 0)
                    ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1EB].trackGroupNumber].pTrack, 10);

                gWrittenToBldy += 2;
            }
            else
            {
                result = TRUE;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 5:
            if (INTRO_DATA.timer < 6)
            {
                LZ77UncompVram(sIntroSamusSittingBgGfxPointers[INTRO_DATA.timer - 1], VRAM_BASE + 0x8000 + (INTRO_DATA.timer - 1) * 0x1000);
            }
            else if (INTRO_DATA.timer == 6)
            {
                LZ77UncompVram(sTitleIntroSpaceBgTilemap_Unused, VRAM_BASE + 0xE000);
                DMA3_COPY_32(sTitleIntroSamusSittingBgPal, PALRAM_BASE, 8 * PAL_ROW_SIZE / 4);
                gWrittenToBldalpha_Eva = 0;
                gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
                WRITE_16(REG_BG1HOFS, 0);
                WRITE_16(REG_BG1VOFS, 0);
                WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            }
            else if (INTRO_DATA.timer == 7)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                    BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 6;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 6:
            if (INTRO_DATA.timer == 4)
            {
                INTRO_DATA.timer = 0;
                if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
                {
                    if (gWrittenToBldalpha_Eva == 0)
                    {
                        ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1E9].trackGroupNumber].pTrack, 60);
                        ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1EA].trackGroupNumber].pTrack, 60);
                        PlayFadingSound(SOUND_1EB, 60);
                    }
                    gWrittenToBldalpha_Eva++;
                    gWrittenToBldalpha_Evb--;
                }
                else
                {
                    DMA3_FILL_32(0, INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
                    INTRO_DATA.subStage = 7;
                    gWrittenToBldy = 0;
                }
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 7:
            if (INTRO_DATA.timer == 150)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 4;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
            }
            break;
    }

    IntroProcessText();
    return result;
}

/**
 * @brief 93f4c | 1c8 | Setup for the title intro flying view
 * 
 */
void IntroFlyingViewInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, INTRO_DATA.oam, sizeof(INTRO_DATA.oam));

    LZ77UncompVram(sTitleIntroBslObjGfx, VRAM_OBJ);
    DMA3_COPY_32(sIntroSamusDriftingIntoAsteroidsObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);

    LZ77UncompVram(sTitleScreenSpaceBackgroundGfx, VRAM_BASE);
    LZ77UncompVram(sTitleScreenSpaceBackgroundTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sIntroSamusDriftingIntoAsteroidsBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32(sPal_598a8c, PALRAM_BASE + 0x1E0, PAL_ROW_SIZE / 4);
    WRITE_16(PALRAM_BASE, 0);

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
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    IntroSpaceViewSetupOam(10, 145, 140, FALSE);
    IntroSpaceViewSetupOam(11, 140, 80, FALSE);

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / 4);

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG3 | DCNT_OBJ);

    CallbackSetVBlank(IntroSpaceViewVblank);
}

/**
 * @brief 94114 | f0 | Processes the title intro flying view
 * 
 */
boolu32 IntroFlyingViewProcess(void)
{
    boolu32 result;

    result = FALSE;
    INTRO_DATA.timer++;

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (gWrittenToBldy != 0)
            {
                if (gWrittenToBldy == BLDY_MAX_VALUE)
                {
                    PlayFadingSound(SOUND_1EC, 0);
                    PlayFadingSound(SOUND_1ED, 0);
                }
                gWrittenToBldy -= 2;
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
            if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 10)
                IntroSpaceViewSetupOam(16, SpecialCutsceneGetRandomNumber(), SpecialCutsceneGetRandomNumber(), FALSE);

            if (INTRO_DATA.timer == 300)
            {
                INTRO_DATA.timer = 0;
                result = TRUE;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
                gWrittenToBldy++;
            else
                result = TRUE;

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
    }

    IntroProcessText();
    return result;
}

/**
 * @brief 94204 | 124 | Main handler for the title intro space view
 * 
 */
boolu32 IntroSpaceView(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (INTRO_DATA.stage)
    {
        case 0:
            IntroSpaceViewInit();
            INTRO_DATA.stage = 1;
            break;

        case 1:
            SpecialCutsceneFadeIn();
            if (gWrittenToBldy == 0)
                INTRO_DATA.stage = 2;
            break;

        case 2:
            if (IntroSpaceViewPartProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
                gWrittenToBldy++;
            else
                INTRO_DATA.stage = 4;

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();

        case 4:
            IntroFlyingViewInit();
            INTRO_DATA.stage = 6;
            break;

        case 5:
            INTRO_DATA.stage = 6;
            break;

        case 6:
            if (IntroFlyingViewProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 0;
                ended = TRUE;
            }
            break;

        case 7:
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
 * @brief 94328 | 28 | Scrolls the background of the space view
 * 
 */
void IntroProcessSpaceViewScrolling(struct SpecialCutsceneOam* pOam)
{
    pOam->animationDurationCounter++;
    if (pOam->animationDurationCounter == 30)
    {
        pOam->animationDurationCounter = 0;
        gBg3XPosition--;
    }
}

/**
 * @brief 94350 | 23c | Processes the BSL ship seen sideways
 * 
 */
void IntroProcessBslShipSideways(struct SpecialCutsceneOam* pOam)
{
    s32 cos;
    s32 sin;
    s32 y;
    u8 state;

    pOam->unk_4 = pOam->xPosition;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        if (INTRO_DATA.subStage == 3)
            pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_A++;
        if (pOam->unk_A == 780)
            IntroSpaceViewSetupOam(3, 260, 110, FALSE);

        pOam->xPosition = (((60 - pOam->spawnX) * (pOam->unk_A << 1)) >> 11) + pOam->spawnX;
        pOam->yPosition = (((10 - pOam->spawnY) * (pOam->unk_A << 1)) >> 11) + pOam->spawnY;

        if (pOam->xPosition > 29)
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
            pOam->spawnY = 4;
            pOam->unk_4 = pOam->xPosition;
            pOam->unk_8 = pOam->yPosition;
            pOam->timer = 0;
            pOam->stage = 3;
        }
    }
    else if (pOam->stage == 3)
    {
        cos = pOam->spawnX * COS(pOam->timer);
        sin = pOam->spawnY * SIN(pOam->timer);
        y = cos * SIN(0) + sin * COS(0);
        pOam->xPosition = (pOam->unk_A / 4) + pOam->spawnX;
        pOam->yPosition = (y >> 16) + pOam->unk_8;
        pOam->timer++;
        pOam->unk_A++;

        if (pOam->unk_A != 60)
        {
            if (pOam->unk_A == 30000)
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

    if (pOam->xPosition < -120)
        return;

    pOam->currentAnimationFrame += pOam->xPosition - (u8)pOam->unk_4;

    state = pOam->unk_1A_4;
    if (state == 0)
    {
        if (pOam->currentAnimationFrame >= 8)
        {
            pOam->currentAnimationFrame -= 8;
            Dma3Transfer_Unused2(EWRAM_BASE + 0x10800 + pOam->animationDurationCounter * 2,
                VRAM_BASE + 0xF000 + pOam->animationDurationCounter * 2, 1, 20);

            pOam->animationDurationCounter++;
            if (pOam->animationDurationCounter == 32)
            {
                pOam->animationDurationCounter = 0;
                pOam->unk_1A_4 = 1;
            }
        }
    }
    else if (state == 1)
    {
        if (pOam->currentAnimationFrame >= 8)
        {
            pOam->currentAnimationFrame -= 8;
            pOam->animationDurationCounter++;
            if (pOam->animationDurationCounter == 32)
            {
                pOam->animationDurationCounter = 0;
                pOam->unk_1A_4 = 10;
            }
        }
    }
}

/**
 * @brief 9458c | 14c | Processes Samus' ship entering the view
 * 
 */
void IntroProcessSamusSHipEntering(struct SpecialCutsceneOam* pOam)
{
    s32 rotation;
    s32 cos;
    s32 sin;
    s32 x;
    s32 y;

    rotation = 0;

    if (pOam->stage == 0)
    {
        pOam->spawnX = 100;
        pOam->spawnY = 30;
        pOam->unk_4 = pOam->xPosition;
        pOam->unk_8 = pOam->yPosition - 30;
        pOam->timer = 64;
        pOam->stage = 1;
        SoundPlay(SOUND_1EA);
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
        pOam->spawnX = rotation;
        pOam->spawnY = 8;
        pOam->unk_4 = pOam->xPosition;
        pOam->unk_8 = pOam->yPosition;
        pOam->timer = 128;
        pOam->stage = 3;
    }
    else if (pOam->stage == 3)
    {
        pOam->timer += 2;
        if (pOam->timer == 192)
            pOam->stage = 4;
    }
    else if (pOam->stage == 4)
    {
        pOam->timer++;
        pOam->unk_A++;
        if (pOam->unk_A == 8)
        {
            pOam->unk_A = rotation;
            pOam->unk_4--;
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
            pOam->type = rotation;
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
 * @brief 946d8 | 2c | Processes the splash text
 * 
 */
void IntroProcessSplashText(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    pFrame = &pOam->pOam[pOam->currentAnimationFrame];
    if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
    {
        pOam->type = 0;
        pOam->unk_18_0 = 0;
    }
}

/**
 * @brief 94704 | b4 | Processes a space view particle
 * 
 */
void IntroProcessSpaceViewParticle(struct SpecialCutsceneOam* pOam)
{
    s32 rng;
    
    if (pOam->stage == 0)
    {
        rng = SpecialCutsceneGetRandomNumber() & 7;
        pOam->unk_8 = rng + 1;
        rng = SpecialCutsceneGetRandomNumber() & 3;
        pOam->unk_4 = rng;
        pOam->pOam = sIntroSpaceViewParticleOam[pOam->unk_4];
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
            
            pOam->pOam = sIntroSpaceViewParticleOam[pOam->unk_4];
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
 * @brief 947b8 | 40 | Processes the idle ship seen from the back
 * 
 */
void IntroProcessIdleShipBackview(struct SpecialCutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->unk_A = 0;
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        pOam->yPosition = (SIN(pOam->timer) >> 5) + pOam->spawnY;
    }
}

/**
 * @brief 947f8 | 64 | Spawns the parts of the BSL ship
 * 
 */
void IntroProcessBslShipSpawning_2(struct SpecialCutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        IntroSpaceViewSetupOam(12, pOam->xPosition + 122, pOam->yPosition, FALSE);
        IntroSpaceViewSetupOam(13, pOam->xPosition + 50, pOam->yPosition + 1, FALSE);
        IntroSpaceViewSetupOam(14, pOam->xPosition + 36, pOam->yPosition, FALSE);
        IntroSpaceViewSetupOam(15, pOam->xPosition, pOam->yPosition, FALSE);
        pOam->type = 0;
    }
}

/**
 * @brief 9485c | d8 | Processes a part of the BSL ship seen from the back
 * 
 */
void IntroProcessBslShipBackview(struct SpecialCutsceneOam* pOam)
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

            if (pOam->spawnX == 300)
            {
                pOam->stage = 1;
                pOam->timer = 0;
            }

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
 * @brief 94934 | c4 | Processes an idle depth particle
 * 
 */
void IntroProcessIdleDepthParticle(struct SpecialCutsceneOam* pOam)
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
                pOam->pOam = sOam_60ac18;
            else if ((s16)pOam->unk_A == 50)
                pOam->pOam = sOam_60ac28;
            else if ((s16)pOam->unk_A == 70)
                pOam->pOam = sOam_60ac38;

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
 * @brief 949f8 | 3f4 | Sets up a title intro space view OAM
 * 
 */
u8 IntroSpaceViewSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
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
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = IntroProcessSpaceViewScrolling;
    }
    else if (type == 2)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pFunction = IntroProcessBslShipSideways;
    }
    else if (type == 3)
    {
        INTRO_DATA.oam[slot].scaling = Q_8_8(1.5f);
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_DOUBLE_SIZED;
        INTRO_DATA.oam[slot].pOam = sOam_60ac98;
        INTRO_DATA.oam[slot].pFunction = IntroProcessSamusSHipEntering;
    }
    else if (type == 4)
    {
        INTRO_DATA.oam[slot].pOam = sOam_60af10;
        INTRO_DATA.oam[slot].pFunction = IntroProcessSplashText;
    }
    else if (type == 5)
    {
        INTRO_DATA.oam[slot].priority = 3;
        INTRO_DATA.oam[slot].pOam = sOam_60ac38;
        INTRO_DATA.oam[slot].pFunction = IntroProcessSpaceViewParticle;
    }
    else if (type == 10)
    {
        INTRO_DATA.oam[slot].spawnX = xPosition;
        INTRO_DATA.oam[slot].spawnY = yPosition;
        INTRO_DATA.oam[slot].scaling = Q_8_8(1);
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].affineMode = OAM_AFFINE_MODE_AFFINE;
        INTRO_DATA.oam[slot].pOam = sOam_60acd0;
        INTRO_DATA.oam[slot].pFunction = IntroProcessIdleShipBackview;
    }
    else if (type == 11)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pOam = sOam_60acd0;
        INTRO_DATA.oam[slot].pFunction = IntroProcessBslShipSpawning_2;
    }
    else if (type == 12)
    {
        INTRO_DATA.oam[slot].unk_4 = -40;
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sOam_60ad28;
        INTRO_DATA.oam[slot].pFunction = IntroProcessBslShipBackview;
    }
    else if (type == 13)
    {
        INTRO_DATA.oam[slot].unk_4 = -30;
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sOam_60ad18;
        INTRO_DATA.oam[slot].pFunction = IntroProcessBslShipBackview;
    }
    else if (type == 14)
    {
        INTRO_DATA.oam[slot].unk_4 = -20;
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sOam_60ad08;
        INTRO_DATA.oam[slot].pFunction = IntroProcessBslShipBackview;
    }
    else if (type == 15)
    {
        INTRO_DATA.oam[slot].unk_4 = -10;
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = sOam_60acf8;
        INTRO_DATA.oam[slot].pFunction = IntroProcessBslShipBackview;
    }
    else if (type == 16)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = sOam_60ac08;
        INTRO_DATA.oam[slot].pFunction = IntroProcessIdleDepthParticle;
    }

    return slot;
}

/**
 * @brief 94dec | 94 | V-blank for the title intro space view
 * 
 */
void IntroSpaceViewVblank(void)
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
 * @brief 94e80 | 4 | Empty function
 * 
 */
void unk_94e80(void)
{
    return;
}
