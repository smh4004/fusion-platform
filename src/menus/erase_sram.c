#include "menus/erase_sram.h"
#include "globals.h"
#include "macros.h"
#include "gba.h"
#include "oam.h"
#include "callbacks.h"
#include "audio_wrappers.h"
#include "audio/track_internal.h"
#include "syscalls.h"
#include "init_helpers.h"
#include "sram_misc.h"
#include "data/sram_pointers.h"
#include "constants/game_state.h"
#include "constants/menus/erase_sram.h"
#include "structs/menus/erase_sram.h"

// FIXME these live in Blob_5822f0_58b3b0 and Blob_79c170_79c27c (text.c), use symbols once those are split
#define ERASE_SRAM_OBJECTS_PAL ((const u16*)0x085822F0)
#define ERASE_SRAM_BACKGROUND_PAL ((const u16*)0x085823D0)
#define ERASE_SRAM_OBJECTS_GFX ((const u32*)0x08582BBC)
#define ERASE_SRAM_BOX_GFX ((const u32*)0x0858340C)
#define ERASE_SRAM_BOX_TILE_TABLE ((const u32*)0x0858ABE4)
#define ERASE_SRAM_BACKGROUND_TILE_TABLE ((const u32*)0x0858ADF0)
// [language][question, confirm]
#define sEraseSramTextGfxPointers ((const u32* const (*)[2])0x0879C228)
// [oam id]
#define sEraseSramMenuOamPointers ((const struct FrameData* const*)0x0879C260)

/**
 * @brief 809f0 | 11c | Erase sram menu handler
 * 
 */
u32 EraseSramMenuHandler(void)
{
    u32 leaving;

    leaving = FALSE;
    ERASE_SRAM_DATA.timer++;

    switch (gSubGameMode1)
    {
        case 0:
            EraseSramMenuInit();
            gSubGameMode1++;
            break;

        case 1:
            if (gWrittenToBldy != 0)
            {
                gWrittenToBldy--;
                break;
            }

            ERASE_SRAM_DATA.bldcnt = (BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT) & ~BLDCNT_OBJ_FIRST_TARGET_PIXEL;
            ERASE_SRAM_DATA.bldyTarget = gWrittenToBldy;
            gSubGameMode1++;
            ERASE_SRAM_DATA.timer = gWrittenToBldy;
            break;

        case 2:
            gSubGameMode2 = EraseSramProcessInput();
            if (gSubGameMode2 == ERASE_SRAM_INPUT_ACTION_NONE)
                break;

            ERASE_SRAM_DATA.timer = 0;
            if (gSubGameMode2 == ERASE_SRAM_INPUT_ACTION_ERASING)
                gSubGameMode1 = 5;
            else
                gSubGameMode1 = 3;
            break;

        case 3:
            if (ERASE_SRAM_DATA.timer <= TWO_THIRD_SECOND)
                break;

            ERASE_SRAM_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;
            ERASE_SRAM_DATA.timer = 0;
            gSubGameMode1++;
            break;

        case 4:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
                break;
            }

            leaving = TRUE;
            break;

        case 5:
            if (ERASE_SRAM_DATA.timer <= TWO_THIRD_SECOND)
                break;

            ERASE_SRAM_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            ERASE_SRAM_DATA.timer = 0;
            gSubGameMode1++;
            break;

        case 6:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
                break;
            }

            EraseSram();
            leaving = TRUE;
            break;
    }

    EraseSramProcessOam();
    ResetFreeOam();

    return leaving;
}

/**
 * @brief 80b0c | 50 | Processes the input for the erase sram menu
 * 
 */
u32 EraseSramProcessInput(void)
{
    u32 result;

    result = ERASE_SRAM_INPUT_ACTION_NONE;

    if (ERASE_SRAM_DATA.nextOption & ERASE_SRAM_OPTION_CHANGED_FLAG)
        EraseSramApplyInput();
    else
        result = EraseSramCheckForInput();

    // Update BLDY based on target
    if (ERASE_SRAM_DATA.bldyTarget != gWrittenToBldy)
    {
        if (ERASE_SRAM_DATA.bldyTarget > gWrittenToBldy)
            gWrittenToBldy++;
        else
            gWrittenToBldy--;
    }

    EraseSramUpdateCursorPosition();

    return result;
}

/**
 * @brief 80b5c | 90 | Applies the input
 * 
 */
void EraseSramApplyInput(void)
{
    if (ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].oamId == ERASE_SRAM_OAM_ID_CURSOR_SELECTING)
        return;

    ERASE_SRAM_DATA.nextOption &= ~ERASE_SRAM_OPTION_CHANGED_FLAG;
    ERASE_SRAM_DATA.currentOption = ERASE_SRAM_DATA.nextOption;

    switch (ERASE_SRAM_DATA.nextOption)
    {
        case ERASE_SRAM_OPTION_QUESTION_NO:
            ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_QUESTION_WINDOW].oamId = sEraseSramMenuOamIds[ERASE_SRAM_OPTION_QUESTION_NO];
            ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].oamId = ERASE_SRAM_OAM_ID_NONE;
            break;

        case ERASE_SRAM_OPTION_QUESTION_YES:
            ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_QUESTION_WINDOW].oamId = sEraseSramMenuOamIds[ERASE_SRAM_OPTION_QUESTION_YES];
            ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].oamId = ERASE_SRAM_OAM_ID_NONE;
            break;

        case ERASE_SRAM_OPTION_CONFIRM_NO:
            ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].oamId = sEraseSramMenuOamIds[ERASE_SRAM_OPTION_CONFIRM_NO];
            break;

        case ERASE_SRAM_OPTION_CONFIRM_YES:
            ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].oamId = sEraseSramMenuOamIds[ERASE_SRAM_OPTION_CONFIRM_YES];
            break;
    }

    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].animationDurationCounter = 0;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].currentAnimationFrame = 0;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_QUESTION_WINDOW].animationDurationCounter = 0;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_QUESTION_WINDOW].currentAnimationFrame = 0;

    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].oamId = ERASE_SRAM_OAM_ID_CURSOR_IDLE;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].animationDurationCounter = 0;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].currentAnimationFrame = 0;
}

/**
 * @brief 80bec | 10c | Checks for input
 * 
 */
u32 EraseSramCheckForInput(void)
{
    u32 result;
    u32 sound;
    u32 exiting;

    result = ERASE_SRAM_INPUT_ACTION_NONE;
    sound = ERASE_SRAM_SOUND_NONE;
    exiting = FALSE;

    switch (ERASE_SRAM_DATA.currentOption)
    {
        case ERASE_SRAM_OPTION_QUESTION_NO:
            if (gChangedInput & KEY_RIGHT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_YES;
                sound = ERASE_SRAM_SOUND_CURSOR;
            }
            else if (gChangedInput & KEY_A)
            {
                result = ERASE_SRAM_INPUT_ACTION_OPENING_SUB_WINDOW;
                sound = ERASE_SRAM_SOUND_SELECT;
                exiting = TRUE;
            }
            break;

        case ERASE_SRAM_OPTION_QUESTION_YES:
            if (gChangedInput & KEY_LEFT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                sound = ERASE_SRAM_SOUND_CURSOR;
            }
            else if (gChangedInput & KEY_A)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_NO;
                sound = ERASE_SRAM_SOUND_SELECT;
                ERASE_SRAM_DATA.bldyTarget = 4;
            }
            break;

        case ERASE_SRAM_OPTION_CONFIRM_NO:
            if (gChangedInput & KEY_RIGHT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_YES;
                sound = ERASE_SRAM_SOUND_CURSOR;
            }
            else if (gChangedInput & (KEY_A | KEY_B))
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                ERASE_SRAM_DATA.bldyTarget = 0;
                sound = ERASE_SRAM_SOUND_CANCEL;
                if (gChangedInput & KEY_A)
                    sound = ERASE_SRAM_SOUND_SELECT;
            }
            break;

        case ERASE_SRAM_OPTION_CONFIRM_YES:
            if (gChangedInput & KEY_LEFT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_NO;
                sound = ERASE_SRAM_SOUND_CURSOR;
            }
            else if (gChangedInput & KEY_A)
            {
                result = ERASE_SRAM_INPUT_ACTION_ERASING;
                sound = ERASE_SRAM_SOUND_ERASE;
                exiting = TRUE;
            }
            else if (gChangedInput & KEY_B)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                sound = ERASE_SRAM_SOUND_CANCEL;
                ERASE_SRAM_DATA.bldyTarget = 0;
            }
            break;
    }

    if (exiting)
    {
        ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].oamId = ERASE_SRAM_OAM_ID_CURSOR_SELECTING;
        ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].animationDurationCounter = 0;
        ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].currentAnimationFrame = 0;
    }

    if (sEraseSramMenuSounds[sound] != 0)
        SoundPlay(sEraseSramMenuSounds[sound]);

    return result;
}

/**
 * @brief 80cf8 | 200 | Initializes the erase sram menu
 * 
 */
void EraseSramMenuInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(EraseSramLoadingVBlank);

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    WRITE_16(REG_BLDY, gWrittenToBldy = BLDY_MAX_VALUE);

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    ClearGfxRam();
    gNextOamSlot = 0;
    ResetFreeOam();

    ERASE_SRAM_DATA.language = gLanguage;
    if ((u8)(ERASE_SRAM_DATA.language - LANGUAGE_ENGLISH) > LANGUAGE_SPANISH - LANGUAGE_ENGLISH)
    {
        ERASE_SRAM_DATA.language = LANGUAGE_ENGLISH;
        gLanguage = LANGUAGE_JAPANESE;
    }

    while (READ_16(REG_VCOUNT) >= 21 && READ_16(REG_VCOUNT) <= SCREEN_SIZE_Y);

    DMA3_COPY_16(ERASE_SRAM_BACKGROUND_PAL, PALRAM_BASE, 0x200 / sizeof(u16));
    DMA3_COPY_16(ERASE_SRAM_OBJECTS_PAL, PALRAM_OBJ, 0xE0 / sizeof(u16));

    LZ77UncompVram(ERASE_SRAM_BOX_GFX, VRAM_BASE + 0x1000);
    LZ77UncompVram(ERASE_SRAM_OBJECTS_GFX, VRAM_BASE + 0x12000);

    LZ77UncompVram(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][0], VRAM_BASE);
    LZ77UncompVram(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][1], VRAM_BASE + 0x11000);
    LZ77UncompVram(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][0], VRAM_OBJ);

    LZ77UncompVram(ERASE_SRAM_BOX_TILE_TABLE, VRAM_BASE + 0xD000);
    LZ77UncompVram(ERASE_SRAM_BACKGROUND_TILE_TABLE, VRAM_BASE + 0xF000);

    WRITE_16(REG_BG0CNT, 0);
    WRITE_16(REG_BG2CNT, 0);
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 26, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    gWrittenToBldalpha_Evb = 0;
    WRITE_16(REG_BLDALPHA, 0);

    gUnk_3000be3 = FALSE;

    gBg1XPosition = 0;
    gBg1YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    EraseSramResetOam();
    EraseSramProcessOam();

    WRITE_16(REG_DISPCNT, DCNT_BG1 | DCNT_BG3 | DCNT_OBJ);
    CallbackSetVBlank(EraseSramVBlank);
}

/**
 * @brief 80ef8 | 5c | Initializes the OAM for the erase sram menu
 * 
 */
void EraseSramResetOam(void)
{
    ERASE_SRAM_DATA.currentOption = ERASE_SRAM_OPTION_QUESTION_NO;
    ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;

    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_QUESTION_WINDOW].oamId = sEraseSramMenuOamIds[ERASE_SRAM_OPTION_QUESTION_NO];
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_QUESTION_WINDOW].animationDurationCounter = 0;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_QUESTION_WINDOW].currentAnimationFrame = 0;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_QUESTION_WINDOW].yPosition = sEraseSramMenuWindowPositions[0][1];
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_QUESTION_WINDOW].xPosition = sEraseSramMenuWindowPositions[0][0];

    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].oamId = ERASE_SRAM_OAM_ID_CURSOR_IDLE;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].animationDurationCounter = 0;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].currentAnimationFrame = 0;

    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].oamId = ERASE_SRAM_OAM_ID_NONE;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].animationDurationCounter = 0;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].currentAnimationFrame = 0;
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].yPosition = sEraseSramMenuWindowPositions[1][1];
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CONFIRM_WINDOW].xPosition = sEraseSramMenuWindowPositions[1][0];

    EraseSramUpdateCursorPosition();
}

/**
 * @brief 80f54 | 4c | Updates the cursor position based on the current option
 * 
 */
void EraseSramUpdateCursorPosition(void)
{
    // Window position + option offset
    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].yPosition = sEraseSramMenuWindowPositions[DIV_SHIFT(ERASE_SRAM_DATA.currentOption, 2)][1] +
        sEraseSramMenuCursorOffsets[ERASE_SRAM_DATA.currentOption][1];

    ERASE_SRAM_DATA.oam[ERASE_SRAM_OAM_IDX_CURSOR].xPosition = sEraseSramMenuWindowPositions[DIV_SHIFT(ERASE_SRAM_DATA.currentOption, 2)][0] +
        sEraseSramMenuCursorOffsets[ERASE_SRAM_DATA.currentOption][0];
}

/**
 * @brief 80fa0 | 78 | Erase sram menu V-blank code
 * 
 */
void EraseSramVBlank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));

    WRITE_16(REG_BLDY, gWrittenToBldy);

    WRITE_16(REG_BG1HOFS, gBg1XPosition);
    WRITE_16(REG_BG1VOFS, gBg1YPosition);

    WRITE_16(REG_BG3HOFS, gBg3XPosition);
    WRITE_16(REG_BG3VOFS, gBg3YPosition);

    if (ERASE_SRAM_DATA.bldcnt != 0)
    {
        WRITE_16(REG_BLDCNT, ERASE_SRAM_DATA.bldcnt);
        ERASE_SRAM_DATA.bldcnt = 0;
    }
}

/**
 * @brief 81018 | c | V-blank code while the erase sram menu is loading
 * 
 */
void EraseSramLoadingVBlank(void)
{
    UpdateAudio();
}

/**
 * @brief 81024 | 148 | Processes the OAM for the erase sram menu
 * 
 */
void EraseSramProcessOam(void)
{
    s32 i;
    s32 currSlot;
    s32 nextSlot;
    u16* dst;
    const u16* src;
    const struct FrameData* pFrame;
    u16 part;
    u16 yPosition;
    u16 xPosition;

    gNextOamSlot = 0;
    dst = (u16*)gOamData;
    nextSlot = 0;
    currSlot = 0;

    for (i = 0; i < ERASE_SRAM_OAM_IDX_COUNT; i++)
    {
        if (ERASE_SRAM_DATA.oam[i].oamId == ERASE_SRAM_OAM_ID_NONE)
            continue;

        switch (ERASE_SRAM_DATA.oam[i].oamId)
        {
            case ERASE_SRAM_OAM_ID_CURSOR_IDLE:
            case ERASE_SRAM_OAM_ID_CURSOR_SELECTING:
            case ERASE_SRAM_OAM_ID_QUESTION_WINDOW_NO_SELECTED:
            case ERASE_SRAM_OAM_ID_QUESTION_WINDOW_YES_SELECTED:
            case ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_NO_SELECTED:
            case ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_YES_SELECTED:
                pFrame = sEraseSramMenuOamPointers[ERASE_SRAM_DATA.oam[i].oamId];

                if (ERASE_SRAM_DATA.oam[i].animationDurationCounter >= pFrame[ERASE_SRAM_DATA.oam[i].currentAnimationFrame].timer)
                {
                    ERASE_SRAM_DATA.oam[i].animationDurationCounter = 0;
                    ERASE_SRAM_DATA.oam[i].currentAnimationFrame++;

                    if (pFrame[ERASE_SRAM_DATA.oam[i].currentAnimationFrame].timer == 0)
                        ERASE_SRAM_DATA.oam[i].currentAnimationFrame = 0;
                }
                break;
        }

        ERASE_SRAM_DATA.oam[i].animationDurationCounter++;

        yPosition = ERASE_SRAM_DATA.oam[i].yPosition - gBg1YPosition;
        xPosition = ERASE_SRAM_DATA.oam[i].xPosition - gBg1XPosition;

        src = pFrame[ERASE_SRAM_DATA.oam[i].currentAnimationFrame].pFrame;
        part = *src++;
        nextSlot += part;

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;
            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;
            gOamData[currSlot].split.x = (part + (s16)xPosition) & 0x1FF;

            *dst++ = *src++;
            gOamData[currSlot].split.priority = 1;

            dst++;
        }
    }

    gNextOamSlot = nextSlot;
}
