#include "title_intro.h"
#include "new_file_intro.h"
#include "globals.h"

#include "data/audio.h"
#include "data/generic_data.h"
#include "data/intro_data.h"
#include "data/sprite_data.h"

// V-blank callbacks
void unk_93884(void);
void unk_99940(void);
void TitleIntroShipAlertAndDraftingVblank(void);

u8 SpecialCutsceneGetRandomNumber(void);

/**
 * @brief 9209c | 1a0 | Unused intro setup function
 * 
 */
void unk_9209c(void)
{
    u16 i;
    u16* tmp1;
    u16* tmp2;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99940);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    for (i = 0; i < ARRAY_SIZE(sIntroSamusSittingBgGfxPointers); i++)
        LZ77UncompVram(sIntroSamusSittingBgGfxPointers[i], VRAM_BASE + 0x8000 + i * 0x1000);

    LZ77UncompVram(sTitleIntroSpaceBgTilemap_Unused, VRAM_BASE + 0xE800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sTitleIntroSamusSittingBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    gBg2XPosition = 8;
    gBg2YPosition = 8;
    gBg3XPosition = 8;
    gBg3YPosition = 8;

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 29, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    // Doesn't match
    //gWrittenToBldalpha_Eva = 0;
    //gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
    tmp1 = &gWrittenToBldalpha_Eva;
    tmp2 = &gWrittenToBldalpha_Evb;
    *tmp1 = 0;
    *tmp2 = BLDALPHA_MAX_VALUE;

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();

    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));

    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG1 | DCNT_OBJ);

    CallbackSetVBlank(unk_93884);
}

/**
 * @brief 9223c | 294 | Processes the title intro Samus in ship cutscene
 * 
 */
boolu32 TitleIntroSamusInShipProcess(void)
{
    boolu32 finished;

    finished = FALSE;

    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (INTRO_DATA.timer <= 5 * DELTA_TIME)
            {
                LZ77UncompVram(sIntroSamusSittingBgGfxPointers[INTRO_DATA.timer - 1], VRAM_BASE + 0x8000 + (INTRO_DATA.timer - 1) * 0x1000);
            }
            else if (INTRO_DATA.timer == 6 * DELTA_TIME)
            {
                LZ77UncompVram(sTitleIntroSpaceBgTilemap_Unused, VRAM_BASE + 0xE800);
                DMA3_COPY_32(sTitleIntroSamusSittingBgPal, PALRAM_BASE, 8 * PAL_ROW_SIZE / sizeof(u32));
                gWrittenToBldalpha_Eva = 0;
                gWrittenToBldalpha_Evb = BLDALPHA_MAX_VALUE;
                WRITE_16(REG_BG1HOFS, 0);
                WRITE_16(REG_BG1VOFS, 0);
                WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 29, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            }
            else if (INTRO_DATA.timer == 7 * DELTA_TIME)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL 
                         | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 1;
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 1:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 60))
            {
                INTRO_DATA.timer = 0;

                if (gWrittenToBldalpha_Evb)
                {
                    if (gWrittenToBldalpha_Evb == BLDALPHA_MAX_VALUE)
                    {
                        ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1EC].trackGroupNumber].pTrack, 10);
                        ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1ED].trackGroupNumber].pTrack, 10);
                    }

                    gWrittenToBldalpha_Evb -= 2;
                }
                else
                {
                    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
                    INTRO_DATA.subStage = 2;
                }
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 60))
            {
                INTRO_DATA.timer = 0;

                if (gWrittenToBldalpha_Eva < BLDALPHA_MAX_VALUE)
                {
                    if (!gWrittenToBldalpha_Eva)
                        PlayFadingSound(SOUND_1EB, 0);

                    gWrittenToBldalpha_Eva++;
                }
                else
                {
                    INTRO_DATA.subStage = 3;
                }
            }

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 3:
            if (INTRO_DATA.timer == TWO_THIRD_SECOND)
			{
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 4;
                gWrittenToBldy = 0;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 4:
            INTRO_DATA.timer = 0;
            INTRO_DATA.subStage = 5;
            
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 5:
            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 60))
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_SCREEN_FIRST_TARGET);
                INTRO_DATA.subStage = 6;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 6:
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
 * @brief 924d0 | 270 | Setup for the title intro ship collision alert cutscene
 * 
 */
void TitleIntroShipAlertInit(void)
{
    u16 i;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
    
    for (i = 0; i < ARRAY_SIZE(sTitleIntroCollisionWarningObjGfxPointers); i++)
        LZ77UncompVram(sTitleIntroCollisionWarningObjGfxPointers[i], VRAM_OBJ + i * 0x1000);

    DMA3_COPY_32(sTitleIntroCollisionWarningObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));

    for (i = 0; i < ARRAY_SIZE(sTitleIntroCollisionWarningBgGfxPointers); i++)
        LZ77UncompVram(sTitleIntroCollisionWarningBgGfxPointers[i], VRAM_BASE + i * 0x1000);

    LZ77UncompVram(sTitleIntroCollisionWarningBgTilemap, VRAM_BASE + 0xF000);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);

    DMA3_COPY_32(sTitleIntroCollisionWarningBgPal, PALRAM_BASE, 8 * PAL_ROW_SIZE / sizeof(u32));

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
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = gWrittenToBldalpha_Evb = 0;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    
    TitleIntroSetupOam(19, 96, 128, FALSE);
    TitleIntroSetupOam(20, 128, 96, FALSE);
    TitleIntroSetupOam(21, 128, 128, FALSE);
    TitleIntroSetupOam(22, 200, 38, FALSE);
    TitleIntroSetupOam(23, 210, 88, FALSE);
    
    IntroSetupBigNumberOam(24, 210, 88, 210);
    IntroSetupBigNumberOam(25, 67, 151, 200);
    IntroSetupBigNumberOam(26, 44, 152, 200);
    IntroSetupBigNumberOam(27, 37, 152, 200);
    IntroSetupBigNumberOam(28, 69, 125, 200);
    IntroSetupBigNumberOam(29, 62, 125, 200);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    INTRO_DATA.pText = sCutsceneTextNone;

    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));
    
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_BG1 | DCNT_OBJ);
    
    CallbackSetVBlank(TitleIntroShipAlertAndDraftingVblank);
}

/**
 * @brief 92740 | f0 | Processes the title intro ship collision alert cutscene
 * 
 */
boolu32 TitleIntroShipAlertProcess(void)
{
    boolu32 finished;

    finished = FALSE;

    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);
    
    switch (INTRO_DATA.subStage)
    {
        case 0:
            TitleIntroShipAlertInit();
            INTRO_DATA.subStage = 1;
            INTRO_DATA.timer = 0;
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 1:
            if (gWrittenToBldy)
            {
                gWrittenToBldy -= 2;
            }
            else
            {
                INTRO_DATA.subStage = 2;
                INTRO_DATA.timer = 0;
            }
        
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 2:
            if (INTRO_DATA.timer == CONVERT_SECONDS(6 + 2.f / 3) - DELTA_TIME)
            {
                gWrittenToBldy = 0;
            }
            else if (INTRO_DATA.timer == CONVERT_SECONDS(6 + 2.f / 3))
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                INTRO_DATA.subStage = 3;
            }
    
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
        
        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                if (!gWrittenToBldy)
                    ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1EB].trackGroupNumber].pTrack, 10);

                gWrittenToBldy += 2;
            }
            else
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.timer = 0;
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
 * @brief 92830 | 1d0 | Setup for the title intro Samus drifting out cutscene
 * 
 */
void TitleIntroSamusDriftingOutInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVBlank(unk_99940);
    
    DMA3_FILL_32(0, &INTRO_DATA.oam, sizeof(INTRO_DATA.oam));
    
    LZ77UncompVram(sTitleIntroBslObjGfx, VRAM_OBJ);

    DMA3_COPY_32(sIntroSamusDriftingIntoAsteroidsObjPal, PALRAM_OBJ, 16 * PAL_ROW_SIZE / sizeof(u32));

    LZ77UncompVram(sTitleScreenSpaceBackgroundGfx, VRAM_BASE);
    LZ77UncompVram(sTitleScreenSpaceBackgroundTilemap, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    
    DMA3_COPY_32(sIntroSamusDriftingIntoAsteroidsBgPal, PALRAM_BASE, 16 * PAL_ROW_SIZE / sizeof(u32));
    
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
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    gWrittenToBldalpha_Eva = gWrittenToBldalpha_Evb = 0;
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));

    TitleIntroSetupOam(10, 145, 140, FALSE);
    TitleIntroSetupOam(11, 140, 80, FALSE);
    
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    
    INTRO_DATA.pText = sCutsceneTextNone;
    
    DMA3_FILL_32(0, VRAM_BASE + 0xD000, (VRAM_SIZE / 6) / sizeof(u32));
    
    WRITE_16(REG_DISPCNT, DCNT_BG3 | DCNT_OBJ);
    
    CallbackSetVBlank(TitleIntroShipAlertAndDraftingVblank);
}

/**
 * @brief 92a00 | 1f4 | Processes the title intro Samus drifting out cutscene
 * 
 */
boolu32 TitleIntroSamusDriftingOutProcess(void)
{
    boolu32 finished;
    s16 x;
    s16 y;

    finished = FALSE;
    
    APPLY_DELTA_TIME_INC(INTRO_DATA.timer);
    
    switch (INTRO_DATA.subStage)
    {
	    case 0:
	        TitleIntroSamusDriftingOutInit();
	        INTRO_DATA.subStage = 1;
	        INTRO_DATA.timer = 0;
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
	
	    case 1:
	        if (gWrittenToBldy)
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
	            INTRO_DATA.subStage = 2;
	            INTRO_DATA.timer = 0;
	        }
	
	        if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 10)
	        {
	            x = SpecialCutsceneGetRandomNumber();
	            y = SpecialCutsceneGetRandomNumber();
	            TitleIntroSetupOam(16, x, y, TRUE);
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
	
	    case 2:
	        if (INTRO_DATA.timer == CONVERT_SECONDS(2 + 1.f / 3))
	            PlayMusic(MUSIC_PRE_TITLE_END, 15);
	
	        if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 10)
	        {
	            x = SpecialCutsceneGetRandomNumber();
	            y = SpecialCutsceneGetRandomNumber();
	            TitleIntroSetupOam(16, x, y, TRUE);
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;
	
	    case 3:
	        if (SpecialCutsceneGetRandomNumber() < 128 && INTRO_DATA.unk_215 < 10)
	        {
	            x = SpecialCutsceneGetRandomNumber();
	            y = SpecialCutsceneGetRandomNumber();
	            TitleIntroSetupOam(16, x, y, TRUE);
	        }
	
	        if (INTRO_DATA.timer == DELTA_TIME)
	        {
	            WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
	            INTRO_DATA.timer = 0;
	            INTRO_DATA.subStage = 4;
	        }
	
	        SpecialCutsceneProcessOam();
	        SpecialCutsceneDrawAllOam();
	        break;

	    case 4:
	        if (gWrittenToBldy < BLDY_MAX_VALUE)
	        {
	            if (INTRO_DATA.timer == CONVERT_SECONDS(1.f / 20))
	            {
	                INTRO_DATA.timer = 0;
	
	                if (!gWrittenToBldy)
	                    ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_1EC].trackGroupNumber].pTrack, 30);
	
	                gWrittenToBldy++;
	            }
	        }
	        else if (INTRO_DATA.timer == CONVERT_SECONDS(2.f / 15))
	        {
	            INTRO_DATA.timer = 0;
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
 * @brief 92bf4 | 118 | Main handler for the title intro Samus crashing cutscenes
 * 
 */
boolu32 TitleIntroSamusShipCrashing(void)
{
    boolu32 finished;

    finished = FALSE;
    
    switch (INTRO_DATA.stage)
    {
        case 0:
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();

            INTRO_DATA.stage = 2;
            break;

        case 1:
            if (gWrittenToBldy)
                gWrittenToBldy--;
            else
                INTRO_DATA.stage = 2;

            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;
            
        case 2:
            if (TitleIntroSamusInShipProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 3;
            }
            break;
            
        case 3:
            if (TitleIntroShipAlertProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 4;
            }
            break;
            
        case 4:
            if (TitleIntroSamusDriftingOutProcess())
            {
                INTRO_DATA.subStage = 0;
                INTRO_DATA.unk_213 = 0;
                INTRO_DATA.stage = 5;
            }
            break;
    
        case 5:
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
 * @brief 92d0c | 148 | Unused, modified variant of NewFileIntroProcessSamusFainting
 * 
 */
void unk_92d0c(struct SpecialCutsceneOam* pOam)
{
    u8 rng1;
    u8 rng2;

    rng1 = sRandomNumberTable[MOD_AND(gFrameCounter16Bit, 32)] / 4;
    rng2 = sRandomNumberTable[MOD_AND(gFrameCounter16Bit + 7, 32)] / 4;

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

    if (INTRO_DATA.subStage == 4)
    {
        pOam->rotation++;
        if (pOam->rotation == Q_8_8(1.f / 128))
        {
            pOam->rotation = 0;
            
            if (gWrittenToBldalpha_Eva)
                gWrittenToBldalpha_Eva--;

            if (gWrittenToBldalpha_Evb < BLDALPHA_MAX_VALUE)
                gWrittenToBldalpha_Evb++;
        }
    }
}

/**
 * @brief 92e54 | 26c | Processes Samus' ship drifting into asteroids
 * 
 */
void TitleIntroProcessDriftingShip(struct SpecialCutsceneOam* pOam)
{
    const struct FrameData* frame;

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
        APPLY_DELTA_TIME_INC(pOam->timer);
        pOam->yPosition = pOam->spawnY + (SIN(pOam->timer) >> 7);

        if (pOam->timer > CONVERT_SECONDS(13.f / 15))
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

        if (pOam->timer >= CONVERT_SECONDS(2 + 2.f / 15))
        {
            pOam->unk_8 = 0;
            pOam->unk_A = 0;
            pOam->unk_4 = 0;
            pOam->timer = 0;
            pOam->spawnX = pOam->xPosition;
            pOam->spawnY = pOam->yPosition;
            pOam->stage = 2;
            SoundPlay(SOUND_1F2);
        }
    }
    else if (pOam->stage == 2)
    {
        APPLY_DELTA_TIME_INC(pOam->timer);
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
        APPLY_DELTA_TIME_INC(pOam->timer);
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
        APPLY_DELTA_TIME_INC(pOam->timer);
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
        pOam->pOam = sOam_60ad48;
        pOam->stage = 6;
        SoundPlay_3b1c(SOUND_1F3);
        INTRO_DATA.timer = 0;
        INTRO_DATA.subStage = 3;
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

// 0x080930C0
NAKED_FUNCTION
void IntroProcessBslShipSpawning(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #0x14]\n\
	cmp r5, #0\n\
	bne _0809311C\n\
	ldrh r1, [r4, #0xc]\n\
	adds r1, #0x7a\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	movs r0, #0xe\n\
	ldrsh r2, [r4, r0]\n\
	movs r0, #0xc\n\
	movs r3, #0\n\
	bl TitleIntroSetupOam\n\
	ldrh r1, [r4, #0xc]\n\
	adds r1, #0x32\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4, #0xe]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r0, #0xd\n\
	movs r3, #0\n\
	bl TitleIntroSetupOam\n\
	ldrh r1, [r4, #0xc]\n\
	adds r1, #0x24\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	movs r0, #0xe\n\
	ldrsh r2, [r4, r0]\n\
	movs r0, #0xe\n\
	movs r3, #0\n\
	bl TitleIntroSetupOam\n\
	movs r0, #0xc\n\
	ldrsh r1, [r4, r0]\n\
	movs r0, #0xe\n\
	ldrsh r2, [r4, r0]\n\
	movs r0, #0xf\n\
	movs r3, #0\n\
	bl TitleIntroSetupOam\n\
	strb r5, [r4, #0x10]\n\
_0809311C:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08093124
NAKED_FUNCTION
void IntroProcessBslShipBack(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r2, r0, #0\n\
	ldrb r3, [r2, #0x14]\n\
	cmp r3, #0\n\
	bne _0809317E\n\
	ldrb r0, [r2, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r2, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x14\n\
	bne _080931F0\n\
	ldrh r0, [r2]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strh r0, [r2]\n\
	strb r1, [r2, #0x13]\n\
	ldrh r0, [r2, #0xa]\n\
	cmp r0, #4\n\
	bne _0809314E\n\
	strh r3, [r2, #0xa]\n\
_0809314E:\n\
	ldrh r0, [r2, #0xa]\n\
	adds r1, r0, #0\n\
	adds r3, r0, #0\n\
	cmp r1, #1\n\
	bhi _0809315E\n\
	ldrh r0, [r2, #0xe]\n\
	adds r0, #1\n\
	b _08093166\n\
_0809315E:\n\
	cmp r1, #3\n\
	bhi _08093168\n\
	ldrh r0, [r2, #0xe]\n\
	subs r0, #1\n\
_08093166:\n\
	strh r0, [r2, #0xe]\n\
_08093168:\n\
	movs r1, #0\n\
	ldrsh r0, [r2, r1]\n\
	cmp r0, #0x1e\n\
	bne _08093178\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
	strb r1, [r2, #0x13]\n\
_08093178:\n\
	adds r0, r3, #1\n\
	strh r0, [r2, #0xa]\n\
	b _080931F0\n\
_0809317E:\n\
	cmp r3, #1\n\
	bne _08093192\n\
	ldrh r0, [r2, #0xc]\n\
	movs r1, #0\n\
	strh r0, [r2]\n\
	ldrh r0, [r2, #0xe]\n\
	strh r0, [r2, #2]\n\
	strh r1, [r2, #0xa]\n\
	movs r0, #2\n\
	b _080931EE\n\
_08093192:\n\
	cmp r3, #2\n\
	bne _080931F0\n\
	ldrb r0, [r2, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r2, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _080931AE\n\
	ldrh r0, [r2, #0xa]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strh r0, [r2, #0xa]\n\
	strb r1, [r2, #0x13]\n\
_080931AE:\n\
	movs r4, #0\n\
	ldrsh r1, [r2, r4]\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #2\n\
	subs r0, r0, r1\n\
	ldrh r1, [r2, #0xa]\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #0xc\n\
	ldrh r1, [r2]\n\
	adds r3, r0, r1\n\
	strh r3, [r2, #0xc]\n\
	movs r4, #4\n\
	ldrsh r0, [r2, r4]\n\
	movs r4, #2\n\
	ldrsh r1, [r2, r4]\n\
	subs r0, r0, r1\n\
	ldrh r1, [r2, #0xa]\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #0xb\n\
	ldrh r1, [r2, #2]\n\
	adds r4, r0, r1\n\
	strh r4, [r2, #0xe]\n\
	lsls r1, r3, #0x10\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x11\n\
	cmp r1, r0\n\
	ble _080931F0\n\
	movs r0, #0\n\
	strh r0, [r2, #0xa]\n\
	strh r3, [r2]\n\
	strh r4, [r2, #2]\n\
	movs r0, #3\n\
_080931EE:\n\
	strb r0, [r2, #0x14]\n\
_080931F0:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080931F8
NAKED_FUNCTION
void IntroProcessDepthParticle(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldrh r1, [r6, #0xa]\n\
	strh r1, [r6, #4]\n\
	ldrb r0, [r6, #0x14]\n\
	cmp r0, #0\n\
	bne _08093222\n\
	movs r1, #0xc\n\
	ldrsh r0, [r6, r1]\n\
	subs r0, #0x78\n\
	movs r1, #0x64\n\
	muls r0, r1, r0\n\
	strh r0, [r6]\n\
	movs r2, #0xe\n\
	ldrsh r0, [r6, r2]\n\
	subs r0, #0x50\n\
	muls r0, r1, r0\n\
	strh r0, [r6, #2]\n\
	movs r0, #1\n\
	strb r0, [r6, #0x14]\n\
	b _080932AE\n\
_08093222:\n\
	lsls r0, r1, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x63\n\
	bgt _080932A0\n\
	cmp r0, #0x19\n\
	bne _08093238\n\
	ldr r0, _08093234 @ =0x0860AC18\n\
	b _0809324A\n\
	.align 2, 0\n\
_08093234: .4byte 0x0860AC18\n\
_08093238:\n\
	cmp r0, #0x32\n\
	bne _08093244\n\
	ldr r0, _08093240 @ =0x0860AC28\n\
	b _0809324A\n\
	.align 2, 0\n\
_08093240: .4byte 0x0860AC28\n\
_08093244:\n\
	cmp r0, #0x46\n\
	bne _0809324C\n\
	ldr r0, _0809329C @ =0x0860AC38\n\
_0809324A:\n\
	str r0, [r6, #0x1c]\n\
_0809324C:\n\
	movs r0, #4\n\
	ldrsh r4, [r6, r0]\n\
	rsbs r4, r4, #0\n\
	adds r4, #0x64\n\
	movs r1, #0\n\
	ldrsh r0, [r6, r1]\n\
	adds r1, r4, #0\n\
	bl __divsi3\n\
	adds r5, r0, #0\n\
	adds r0, #0x78\n\
	strh r0, [r6, #0xc]\n\
	movs r2, #2\n\
	ldrsh r0, [r6, r2]\n\
	adds r1, r4, #0\n\
	bl __divsi3\n\
	adds r1, r0, #0\n\
	adds r1, #0x50\n\
	strh r1, [r6, #0xe]\n\
	adds r5, #0x80\n\
	lsls r5, r5, #0x10\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x11\n\
	cmp r5, r0\n\
	bhi _08093290\n\
	lsls r0, r1, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0xa8\n\
	bgt _08093290\n\
	movs r0, #8\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bge _080932AE\n\
_08093290:\n\
	movs r0, #0\n\
	strb r0, [r6, #0x10]\n\
	ldrb r1, [r6, #0x18]\n\
	subs r0, #2\n\
	b _080932AA\n\
	.align 2, 0\n\
_0809329C: .4byte 0x0860AC38\n\
_080932A0:\n\
	movs r0, #0\n\
	strb r0, [r6, #0x10]\n\
	ldrb r1, [r6, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
_080932AA:\n\
	ands r0, r1\n\
	strb r0, [r6, #0x18]\n\
_080932AE:\n\
	ldrh r0, [r6, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r6, #0xa]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080932BC
NAKED_FUNCTION
void IntroProcessTimeAndDistanceOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0x14]\n\
	cmp r0, #0\n\
	bne _080932D6\n\
	ldrb r5, [r4, #0x11]\n\
	cmp r5, #1\n\
	bne _080932D6\n\
	movs r0, #0xf7\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	strb r5, [r4, #0x14]\n\
_080932D6:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x080932DC
NAKED_FUNCTION
void IntroProcessAsteroidsPopUp(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0x14]\n\
	cmp r0, #0\n\
	bne _080932F4\n\
	ldrb r5, [r4, #0x11]\n\
	cmp r5, #1\n\
	bne _080932F4\n\
	ldr r0, _080932FC @ =0x000001EF\n\
	bl SoundPlay\n\
	strb r5, [r4, #0x14]\n\
_080932F4:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080932FC: .4byte 0x000001EF\n\
    .syntax divided\n");
}

// 0x08093300
NAKED_FUNCTION
void unk_93300(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	bne _0809332C\n\
	ldrh r0, [r2, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r2, #0xa]\n\
	ldrh r1, [r2, #0xa]\n\
	movs r3, #8\n\
	ldrsh r0, [r2, r3]\n\
	cmp r1, r0\n\
	bne _0809332C\n\
	ldrb r0, [r2, #0x18]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r2, #0x18]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
	ldr r0, _08093330 @ =0x000001F1\n\
	bl SoundPlay\n\
_0809332C:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08093330: .4byte 0x000001F1\n\
    .syntax divided\n");
}

// 0x08093334
NAKED_FUNCTION
void unk_93334(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldr r0, [r4, #0x10]\n\
	ldr r1, _08093374 @ =0x00FFFF00\n\
	ands r0, r1\n\
	ldr r1, _08093378 @ =0x00010100\n\
	cmp r0, r1\n\
	bne _0809334C\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
_0809334C:\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #0x12]\n\
	cmp r0, r2\n\
	bne _0809336E\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809336E\n\
	strb r1, [r4, #0x10]\n\
	ldrb r1, [r4, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r4, #0x18]\n\
_0809336E:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08093374: .4byte 0x00FFFF00\n\
_08093378: .4byte 0x00010100\n\
    .syntax divided\n");
}

// 0x0809337C
NAKED_FUNCTION
void IntroOamProcessBigChangingNumber(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	bne _080933A2\n\
	ldrh r0, [r2, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r2, #0xa]\n\
	ldrh r1, [r2, #0xa]\n\
	movs r3, #8\n\
	ldrsh r0, [r2, r3]\n\
	cmp r1, r0\n\
	bne _080933A2\n\
	ldrb r0, [r2, #0x18]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r2, #0x18]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
_080933A2:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080933A8
NAKED_FUNCTION
u8 TitleIntroSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov sb, r1\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	mov sl, r2\n\
	lsls r3, r3, #0x18\n\
	cmp r3, #0\n\
	bne _08093410\n\
	movs r2, #0\n\
	ldr r0, _0809340C @ =gNonGameplayRam\n\
	movs r3, #0x8b\n\
	lsls r3, r3, #2\n\
	adds r1, r0, r3\n\
	ldrb r1, [r1]\n\
	mov r8, r0\n\
	cmp r1, #0\n\
	beq _080933FE\n\
	mov r4, r8\n\
_080933DE:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0x13\n\
	bgt _08093450\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080933DE\n\
_080933FE:\n\
	lsls r0, r2, #0x18\n\
	asrs r1, r0, #0x18\n\
	mov ip, r0\n\
	cmp r1, #0x13\n\
	ble _08093458\n\
	b _08093450\n\
	.align 2, 0\n\
_0809340C: .4byte gNonGameplayRam\n\
_08093410:\n\
	movs r2, #0x13\n\
	ldr r0, _08093454 @ =gNonGameplayRam\n\
	movs r3, #0x9b\n\
	lsls r3, r3, #3\n\
	adds r1, r0, r3\n\
	ldrb r1, [r1]\n\
	mov r8, r0\n\
	cmp r1, #0\n\
	beq _08093448\n\
	mov r3, r8\n\
	movs r4, #0x8b\n\
	lsls r4, r4, #2\n\
_08093428:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0xff\n\
	lsls r1, r1, #0x18\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	blt _08093450\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08093428\n\
_08093448:\n\
	lsls r0, r2, #0x18\n\
	mov ip, r0\n\
	cmp r0, #0\n\
	bge _08093458\n\
_08093450:\n\
	movs r0, #0x14\n\
	b _0809382E\n\
	.align 2, 0\n\
_08093454: .4byte gNonGameplayRam\n\
_08093458:\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r2, _080934C0 @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r2]\n\
	mov r0, ip\n\
	asrs r1, r0, #0x18\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r4, r0, #2\n\
	ldr r3, _080934C4 @ =0x030016A0\n\
	adds r0, r4, r3\n\
	str r0, [r2, #4]\n\
	ldr r0, _080934C8 @ =0x85000009\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	ldr r1, _080934CC @ =0xFFFFFDE4\n\
	adds r0, r3, r1\n\
	adds r2, r4, r0\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	movs r7, #0\n\
	mov r1, sb\n\
	strh r1, [r0]\n\
	ldr r1, _080934D0 @ =0x0000022A\n\
	adds r0, r2, r1\n\
	mov r1, sl\n\
	strh r1, [r0]\n\
	movs r1, #0x8b\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	strb r5, [r0]\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r6, r2, r0\n\
	ldrb r1, [r6]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strb r1, [r6]\n\
	cmp r5, #1\n\
	bne _080934D8\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r6]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _080934D4 @ =unk_92d0c\n\
	str r1, [r0]\n\
	b _0809382A\n\
	.align 2, 0\n\
_080934C0: .4byte 0x040000D4\n\
_080934C4: .4byte 0x030016A0\n\
_080934C8: .4byte 0x85000009\n\
_080934CC: .4byte 0xFFFFFDE4\n\
_080934D0: .4byte 0x0000022A\n\
_080934D4: .4byte unk_92d0c\n\
_080934D8:\n\
	cmp r5, #0xa\n\
	bne _0809352C\n\
	movs r1, #0x87\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	mov r1, sb\n\
	strh r1, [r0]\n\
	ldr r1, _0809351C @ =0x0000021E\n\
	adds r0, r2, r1\n\
	mov r1, sl\n\
	strh r1, [r0]\n\
	ldr r0, _08093520 @ =0x00000222\n\
	adds r1, r2, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	ldrb r1, [r6]\n\
	movs r0, #7\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r6]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08093524 @ =0x0860ACD0\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08093528 @ =TitleIntroProcessDriftingShip\n\
	str r1, [r0]\n\
	b _0809382A\n\
	.align 2, 0\n\
_0809351C: .4byte 0x0000021E\n\
_08093520: .4byte 0x00000222\n\
_08093524: .4byte 0x0860ACD0\n\
_08093528: .4byte TitleIntroProcessDriftingShip\n\
_0809352C:\n\
	cmp r5, #0xb\n\
	bne _08093558\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r6]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08093550 @ =0x0860ACD0\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08093554 @ =IntroProcessBslShipSpawning\n\
	str r1, [r0]\n\
	b _0809382A\n\
	.align 2, 0\n\
_08093550: .4byte 0x0860ACD0\n\
_08093554: .4byte IntroProcessBslShipSpawning\n\
_08093558:\n\
	cmp r5, #0xc\n\
	bne _08093578\n\
	movs r0, #0x88\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _08093570 @ =0x0000FFD8\n\
	strh r0, [r1]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08093574 @ =0x0860AD28\n\
	b _080935CE\n\
	.align 2, 0\n\
_08093570: .4byte 0x0000FFD8\n\
_08093574: .4byte 0x0860AD28\n\
_08093578:\n\
	cmp r5, #0xd\n\
	bne _08093598\n\
	movs r0, #0x88\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _08093590 @ =0x0000FFE2\n\
	strh r0, [r1]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08093594 @ =0x0860AD18\n\
	b _080935CE\n\
	.align 2, 0\n\
_08093590: .4byte 0x0000FFE2\n\
_08093594: .4byte 0x0860AD18\n\
_08093598:\n\
	cmp r5, #0xe\n\
	bne _080935B8\n\
	movs r0, #0x88\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _080935B0 @ =0x0000FFEC\n\
	strh r0, [r1]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _080935B4 @ =0x0860AD08\n\
	b _080935CE\n\
	.align 2, 0\n\
_080935B0: .4byte 0x0000FFEC\n\
_080935B4: .4byte 0x0860AD08\n\
_080935B8:\n\
	cmp r5, #0xf\n\
	bne _080935E8\n\
	movs r0, #0x88\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _080935DC @ =0x0000FFF6\n\
	strh r0, [r1]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _080935E0 @ =0x0860ACF8\n\
_080935CE:\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _080935E4 @ =IntroProcessBslShipBack\n\
	str r1, [r0]\n\
	b _0809382A\n\
	.align 2, 0\n\
_080935DC: .4byte 0x0000FFF6\n\
_080935E0: .4byte 0x0860ACF8\n\
_080935E4: .4byte IntroProcessBslShipBack\n\
_080935E8:\n\
	cmp r5, #0x10\n\
	bne _0809360C\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08093604 @ =0x0860AC08\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08093608 @ =IntroProcessDepthParticle\n\
	str r1, [r0]\n\
	b _0809382A\n\
	.align 2, 0\n\
_08093604: .4byte 0x0860AC08\n\
_08093608: .4byte IntroProcessDepthParticle\n\
_0809360C:\n\
	cmp r5, #0x13\n\
	bne _08093630\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08093628 @ =0x0865BB38\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809362C @ =IntroProcessTimeAndDistanceOam\n\
	str r1, [r0]\n\
	b _0809382A\n\
	.align 2, 0\n\
_08093628: .4byte 0x0865BB38\n\
_0809362C: .4byte IntroProcessTimeAndDistanceOam\n\
_08093630:\n\
	cmp r5, #0x14\n\
	bne _0809364C\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08093648 @ =0x0865BD00\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	b _0809366E\n\
	.align 2, 0\n\
_08093648: .4byte 0x0865BD00\n\
_0809364C:\n\
	cmp r5, #0x15\n\
	bne _0809367C\n\
	mov r3, ip\n\
	asrs r1, r3, #0x18\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	movs r1, #0x8e\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	adds r1, r0, r1\n\
	ldr r2, _08093674 @ =0x0865BD48\n\
	str r2, [r1]\n\
	movs r1, #0x8f\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	adds r0, r0, r1\n\
_0809366E:\n\
	ldr r1, _08093678 @ =unk_9397c\n\
	str r1, [r0]\n\
	b _0809382A\n\
	.align 2, 0\n\
_08093674: .4byte 0x0865BD48\n\
_08093678: .4byte unk_9397c\n\
_0809367C:\n\
	cmp r5, #0x16\n\
	bne _080936AC\n\
	mov r0, ip\n\
	asrs r1, r0, #0x18\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	movs r1, #0x8e\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	adds r1, r0, r1\n\
	ldr r2, _080936A4 @ =0x0865BD60\n\
	str r2, [r1]\n\
	movs r1, #0x8f\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	adds r0, r0, r1\n\
	ldr r1, _080936A8 @ =IntroProcessAsteroidsPopUp\n\
	str r1, [r0]\n\
	b _0809382A\n\
	.align 2, 0\n\
_080936A4: .4byte 0x0865BD60\n\
_080936A8: .4byte IntroProcessAsteroidsPopUp\n\
_080936AC:\n\
	cmp r5, #0x17\n\
	bne _080936DC\n\
	mov r3, ip\n\
	asrs r1, r3, #0x18\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	movs r1, #0x8e\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	adds r1, r0, r1\n\
	ldr r2, _080936D4 @ =0x0865BE00\n\
	str r2, [r1]\n\
	movs r1, #0x8f\n\
	lsls r1, r1, #2\n\
	add r1, r8\n\
	adds r0, r0, r1\n\
	ldr r1, _080936D8 @ =unk_93334\n\
	str r1, [r0]\n\
	b _0809382A\n\
	.align 2, 0\n\
_080936D4: .4byte 0x0865BE00\n\
_080936D8: .4byte unk_93334\n\
_080936DC:\n\
	cmp r5, #0x18\n\
	bne _08093710\n\
	mov r1, ip\n\
	asrs r0, r1, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	mov r3, r8\n\
	adds r1, r2, r3\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r0, r2, r0\n\
	ldr r1, _0809370C @ =0x0865BF10\n\
	b _0809381C\n\
	.align 2, 0\n\
_0809370C: .4byte 0x0865BF10\n\
_08093710:\n\
	cmp r5, #0x19\n\
	bne _08093754\n\
	mov r1, ip\n\
	asrs r0, r1, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	mov r3, r8\n\
	adds r1, r2, r3\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r0, r2, r0\n\
	ldr r1, _0809374C @ =0x0865C0D0\n\
	str r1, [r0]\n\
	movs r0, #0x8f\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r2, r2, r0\n\
	ldr r0, _08093750 @ =unk_93300\n\
	b _08093828\n\
	.align 2, 0\n\
_0809374C: .4byte 0x0865C0D0\n\
_08093750: .4byte unk_93300\n\
_08093754:\n\
	cmp r5, #0x1a\n\
	bne _08093788\n\
	mov r1, ip\n\
	asrs r0, r1, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	mov r3, r8\n\
	adds r1, r2, r3\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r0, r2, r0\n\
	ldr r1, _08093784 @ =0x0865C128\n\
	b _0809381C\n\
	.align 2, 0\n\
_08093784: .4byte 0x0865C128\n\
_08093788:\n\
	cmp r5, #0x1b\n\
	bne _080937BC\n\
	mov r1, ip\n\
	asrs r0, r1, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	mov r3, r8\n\
	adds r1, r2, r3\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r0, r2, r0\n\
	ldr r1, _080937B8 @ =0x0865C180\n\
	b _0809381C\n\
	.align 2, 0\n\
_080937B8: .4byte 0x0865C180\n\
_080937BC:\n\
	cmp r5, #0x1c\n\
	bne _080937F0\n\
	mov r1, ip\n\
	asrs r0, r1, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	mov r3, r8\n\
	adds r1, r2, r3\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r0, r2, r0\n\
	ldr r1, _080937EC @ =0x0865C1D8\n\
	b _0809381C\n\
	.align 2, 0\n\
_080937EC: .4byte 0x0865C1D8\n\
_080937F0:\n\
	cmp r5, #0x1d\n\
	bne _0809382A\n\
	mov r1, ip\n\
	asrs r0, r1, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	mov r3, r8\n\
	adds r1, r2, r3\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r0, r2, r0\n\
	ldr r1, _08093840 @ =0x0865C230\n\
_0809381C:\n\
	str r1, [r0]\n\
	movs r0, #0x8f\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r2, r2, r0\n\
	ldr r0, _08093844 @ =IntroOamProcessBigChangingNumber\n\
_08093828:\n\
	str r0, [r2]\n\
_0809382A:\n\
	mov r1, ip\n\
	lsrs r0, r1, #0x18\n\
_0809382E:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08093840: .4byte 0x0865C230\n\
_08093844: .4byte IntroOamProcessBigChangingNumber\n\
    .syntax divided\n");
}

// 0x08093848
NAKED_FUNCTION
void IntroSetupBigNumberOam(u8 type, s16 xPosition, s16 yPosition, u16 value)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r3, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r4, r4, #0x10\n\
	lsrs r4, r4, #0x10\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #0\n\
	bl TitleIntroSetupOam\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldr r2, _08093880 @ =gNonGameplayRam\n\
	lsls r1, r0, #3\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	movs r0, #0x89\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	strh r4, [r1]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08093880: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x08093884
NAKED_FUNCTION
void unk_93884(void)
{
    asm(" .syntax unified\n\
	ldr r1, _080938D0 @ =0x040000D4\n\
	ldr r0, _080938D4 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _080938D8 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r2, _080938DC @ =0x04000052\n\
	ldr r0, _080938E0 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _080938E4 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _080938E8 @ =0x04000054\n\
	ldr r0, _080938EC @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x3c\n\
	ldr r0, _080938F0 @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _080938F4 @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _080938F8 @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _080938FC @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_080938D0: .4byte 0x040000D4\n\
_080938D4: .4byte gOamData\n\
_080938D8: .4byte 0x84000100\n\
_080938DC: .4byte 0x04000052\n\
_080938E0: .4byte gWrittenToBldalpha_Evb\n\
_080938E4: .4byte gWrittenToBldalpha_Eva\n\
_080938E8: .4byte 0x04000054\n\
_080938EC: .4byte gWrittenToBldy\n\
_080938F0: .4byte 0x0300122C\n\
_080938F4: .4byte 0x0300122E\n\
_080938F8: .4byte 0x03001230\n\
_080938FC: .4byte 0x03001232\n\
    .syntax divided\n");
}

// 0x08093900
NAKED_FUNCTION
void TitleIntroShipAlertAndDraftingVblank(void)
{
    asm(" .syntax unified\n\
	ldr r1, _0809394C @ =0x040000D4\n\
	ldr r0, _08093950 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _08093954 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r2, _08093958 @ =0x04000052\n\
	ldr r0, _0809395C @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _08093960 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08093964 @ =0x04000054\n\
	ldr r0, _08093968 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x3c\n\
	ldr r0, _0809396C @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08093970 @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08093974 @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08093978 @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_0809394C: .4byte 0x040000D4\n\
_08093950: .4byte gOamData\n\
_08093954: .4byte 0x84000100\n\
_08093958: .4byte 0x04000052\n\
_0809395C: .4byte gWrittenToBldalpha_Evb\n\
_08093960: .4byte gWrittenToBldalpha_Eva\n\
_08093964: .4byte 0x04000054\n\
_08093968: .4byte gWrittenToBldy\n\
_0809396C: .4byte 0x0300122C\n\
_08093970: .4byte 0x0300122E\n\
_08093974: .4byte 0x03001230\n\
_08093978: .4byte 0x03001232\n\
    .syntax divided\n");
}

// 0x0809397C
NAKED_FUNCTION
void unk_9397c(void)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}
