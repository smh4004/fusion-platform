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

#include "data/audio.h"
#include "data/generic_data.h"
#include "data/intro_data.h"
extern const u8 sBlob_6131c8_63a19c[];
extern const u8 sAddr_6150e8[];
extern const u8 sAddr_6186a4[];
extern const u8 sAddr_61b89c[];
extern const u8 sAddr_6217a8[];
extern const u8 sAddr_6331ec[];
extern const u8 sAddr_633244[];
extern const u8 sAddr_633294[];
extern const u8 sAddr_6332fc[];
extern const u8 sAddr_633364[];
extern const u8 sAddr_6333cc[];
extern const u8 sAddr_633434[];
extern const u8 sAddr_63345c[];
extern const u8 sAddr_6338a4[];
extern const u8 sAddr_6338d4[];
extern const u8 sAddr_6339d4[];
extern const u8 sAddr_633c4c[];
extern const u8 sAddr_633e64[];
extern const u8 sAddr_633e8c[];
extern const u8 sAddr_633ec4[];
extern const u8 sAddr_633f0c[];
extern const u8 sAddr_633f24[];
extern const u8 sAddr_636438[];
extern const u8 sAddr_636638[];
extern const u8 sAddr_636838[];
extern const u8 sAddr_637238[];
extern const u8 sAddr_6377f8[];
extern const u8 sAddr_637db8[];
extern const u8 sAddr_638654[];

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

    LZ77UncompVram((const u32*)sAddr_6150e8, VRAM_OBJ);
    DMA3_COPY_32((const u16*)sAddr_636638, PALRAM_OBJ, 16 * PAL_ROW_SIZE / 4);

    LZ77UncompVram((const u32*)sAddr_6186a4, VRAM_BASE + 0x8000);
    LZ77UncompVram((const u32*)sAddr_6377f8, VRAM_BASE + 0xF800);
    DMA3_COPY_32((const u16*)sAddr_636438, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);

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

    LZ77UncompVram((const u32*)(&sBlob_6131c8_63a19c), VRAM_BASE + 0x8000);
    LZ77UncompVram((const u32*)sAddr_637238, VRAM_BASE + 0xF800);
    LZ77UncompVram(sIntroSamusShipFlyingTextTilemap, VRAM_BASE + 0xE000);
    DMA3_COPY_32((const u16*)sAddr_636438, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);

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

    LZ77UncompVram((const u32*)sAddr_61b89c, VRAM_BASE);
    LZ77UncompVram((const u32*)sAddr_6217a8, VRAM_BASE + 0x8000);
    LZ77UncompVram((const u32*)sAddr_638654, VRAM_BASE + 0xF000);
    LZ77UncompVram((const u32*)sAddr_637db8, VRAM_BASE + 0xF800);
    DMA3_COPY_32((const u16*)sAddr_636838, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
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

/**
 * @brief 96448 | 4e0 | Processes the ending in ship cutscenes
 * 
 */
boolu32 EndingInShipProcess(void)
{
    boolu32 ended;

    ended = FALSE;
    INTRO_DATA.timer++;

    switch (INTRO_DATA.subStage)
    {
        case 0:
            if (INTRO_DATA.timer == 7)
            {
                INTRO_DATA.timer = 0;
                if (gWrittenToBldy != 0)
                {
                    gWrittenToBldy--;
                }
                else
                {
                    PlayMusic(MUSIC_EPILOGUE, 14);
                    INTRO_DATA.subStage = 1;
                }
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 1:
            if (INTRO_DATA.timer == 70)
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
                INTRO_DATA.unk_12 = 0;
                INTRO_DATA.unk_10 = 0;
                INTRO_DATA.unk_E = 0;
                INTRO_DATA.unk_C = 0;
                INTRO_DATA.unk_212 = 0;
                INTRO_DATA.pText = sMonologueTextPointers[gLanguage][7];
                INTRO_DATA.subStage = 2;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 2:
            if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
                INTRO_DATA.unk_218 = 1;

            INTRO_DATA.timer = 0;

            if (INTRO_DATA.unk_218 == 2)
            {
                INTRO_DATA.unk_218 = 0;
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                INTRO_DATA.unk_218 = 0;
                INTRO_DATA.subStage = 3;
            }

            if (EndingCheckMonologueEnded())
            {
                INTRO_DATA.subStage = 3;
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

        case 3:
            if (INTRO_DATA.timer == 1)
            {
                gWrittenToBldalpha_Evb = 0;
                gWrittenToBldalpha_Eva = BLDALPHA_MAX_VALUE;
            }
            else if (INTRO_DATA.timer == 20)
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_BLDCNT, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL);
                INTRO_DATA.subStage = 4;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 4:
            if (INTRO_DATA.timer == 4)
            {
                INTRO_DATA.timer = 0;
                if (gWrittenToBldalpha_Evb < BLDALPHA_MAX_VALUE)
                    gWrittenToBldalpha_Evb++;

                if (gWrittenToBldalpha_Eva != 0)
                    gWrittenToBldalpha_Eva--;

                if (gWrittenToBldalpha_Evb == BLDALPHA_MAX_VALUE && gWrittenToBldalpha_Eva == 0)
                {
                    WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG0);
                    INTRO_DATA.subStage = 5;
                }
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 5:
            if (INTRO_DATA.timer == 10)
            {
                EndingDialogueSetupOam(30, 120, 80, TRUE);
            }
            else if (INTRO_DATA.timer == 39)
            {
                gWrittenToBldy = BLDY_MAX_VALUE;
            }
            else if (INTRO_DATA.timer == 40)
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 6;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 6:
            if (INTRO_DATA.timer == 1)
            {
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 7;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 7:
            INTRO_DATA.timer = 0;
            EndingAdamConversationInit();
            INTRO_DATA.subStage = 8;
            break;

        case 8:
            gWrittenToBldy = 0;
            INTRO_DATA.timer = 0;
            SoundPlay(SOUND_24C);
            INTRO_DATA.subStage = 9;
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 9:
            if (INTRO_DATA.timer == 10)
            {
            }
            else if (INTRO_DATA.timer == 40)
            {
                EndingDialogueSetupOam(255, 0, 0, FALSE);
                EndingDialogueSetupOam(6, 20, 192, FALSE);
                EndingDialogueSetupOam(7, 128, 192, FALSE);
                EndingDialogueSetupOam(9, 128, 192, FALSE);
                INTRO_DATA.timer = 0;
                INTRO_DATA.subStage = 10;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            EndingProcessAdamText();
            break;

        case 10:
            INTRO_DATA.timer = 0;
            if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW && gChangedInput & KEY_A && INTRO_DATA.unk_218 == 0)
                INTRO_DATA.unk_218 = 1;

            if (INTRO_DATA.unk_218 == 2)
            {
                INTRO_DATA.unk_218 = 0;
                SoundPlay(SOUND_203);
            }
            else if (INTRO_DATA.unk_218 == 3)
            {
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG0);
                INTRO_DATA.unk_218 = 0;
                SoundPlay(SOUND_203);
                FadeMusic(10);
                INTRO_DATA.subStage = 11;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            EndingProcessAdamText();
            break;

        case 11:
            INTRO_DATA.timer = 0;
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 12:
            if (INTRO_DATA.timer == 1)
            {
                ApplyMusicSoundFading(sMusicTrackDataRom[sSoundDataEntries[SOUND_24C].trackGroupNumber].pTrack, 0);
            }
            else if (INTRO_DATA.timer == 10)
            {
                INTRO_DATA.timer = 0;
                gWrittenToBldy = BLDY_MAX_VALUE;
                INTRO_DATA.subStage = 13;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 13:
            EndingAnimalsInit();
            INTRO_DATA.timer = 0;
            gWrittenToBldy = 0;
            INTRO_DATA.subStage = 14;
            break;

        case 14:
            if (INTRO_DATA.timer == 1)
            {
                PlayMusic(MUSIC_EPILOGUE_END, 14);
            }
            else if (INTRO_DATA.timer == 640)
            {
                INTRO_DATA.timer = 0;
                WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG2);
                INTRO_DATA.subStage = 15;
            }
            SpecialCutsceneProcessOam();
            SpecialCutsceneDrawAllOam();
            break;

        case 15:
            if (INTRO_DATA.timer == 2)
            {
                INTRO_DATA.timer = 0;
                if (gWrittenToBldy < BLDY_MAX_VALUE)
                {
                    gWrittenToBldy++;
                }
                else
                {
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
            pOam->pOam = (const struct FrameData*)sAddr_633ec4;
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
            pOam->pOam = (const struct FrameData*)sAddr_633f0c;
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
            pOam->pOam = (const struct FrameData*)sAddr_633244;
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
            pOam->pOam = (const struct FrameData*)sAddr_633e8c;
            return;
        }

        if (*pIntro->pText == CHAR_NEXT_PAGE_ARROW)
        {
            pOam->xPosition = 120;
            pOam->yPosition = 154;
            pOam->pOam = (const struct FrameData*)sAddr_633e64;
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
                pOam->pOam = (const struct FrameData*)sAddr_6332fc;
                SoundPlay(SOUND_20B);
            }
            else if (pOam->type == 9)
            {
                pOam->pOam = (const struct FrameData*)sAddr_6333cc;
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
            pOam->pOam = (const struct FrameData*)sAddr_6338a4;
            pOam->stage = 1;
        }

        if (INTRO_DATA.subStage == 11)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)sAddr_63345c;
            pOam->stage = 2;
        }
    }
    else if (pOam->stage == 1)
    {
        if (INTRO_DATA.subStage == 11)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)sAddr_63345c;
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
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_633e64;
        INTRO_DATA.oam[slot].pFunction = EndingProcessMonologueCursor;
    }
    else if (type == 2)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6338d4;
        INTRO_DATA.oam[slot].pFunction = unk_969e0;
    }
    else if (type == 3)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6339d4;
        INTRO_DATA.oam[slot].pFunction = EndingProcessSr388RadarView;
    }
    else if (type == 4)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_633c4c;
        INTRO_DATA.oam[slot].pFunction = EndingProcessSamusViewRadarView;
    }
    else if (type == 5)
    {
        INTRO_DATA.oam[slot].priority = 2;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6331ec;
        INTRO_DATA.oam[slot].pFunction = unk_96a70;
    }
    else if (type == 6)
    {
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_633e8c;
        INTRO_DATA.oam[slot].pFunction = EndingProcessAdamTextCursor;
    }
    else if (type == 7)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_633294;
        INTRO_DATA.oam[slot].pFunction = EndingProcessAdamPanel;
    }
    else if (type == 8)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_633434;
        INTRO_DATA.oam[slot].pFunction = EndingProcessAdamIcon;
    }
    else if (type == 9)
    {
        INTRO_DATA.oam[slot].priority = 1;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_633364;
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
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_633f24;
        INTRO_DATA.oam[slot].pFunction = unk_97418;
    }
    else if (type == 255)
    {
        INTRO_DATA.oam[slot].unk_18_0 = 0;
        INTRO_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6331ec;
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
