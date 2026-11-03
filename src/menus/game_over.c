#include "menus/game_over.h"
#include "gba.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "init_helpers.h"
#include "music_wrappers.h"
#include "audio_wrappers.h"
#include "syscalls.h"

#include "audio/track_internal.h"

#include "data/menus/game_over_data.h"

#include "constants/audio.h"
#include "constants/game_state.h"

/**
 * @brief 9deb4 | a4 | Main handler for the game over screen
 * 
 * @return u8 Option chosen (0 = none yet, 1 = continue, 2 = quit)
 */
u8 GameOverHandler(void)
{
    u8 result;

    result = 0;

    switch (gSubGameMode1)
    {
        case 0:
            GameOverInit();
            gSubGameMode1 = 1;
            break;

        case 1:
            GameOverDrawAllOam();
            if (gWrittenToBldy != 0)
            {
                gWrittenToBldy--;
                break;
            }

            PlayMusic(MUSIC_AFTER_EVENT, 0);
            gSubGameMode1++;
            break;

        case 2:
            if (GameOverAfterOptionDelay())
            {
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
                gSubGameMode1++;
            }
            break;

        case 3:
            GameOverDrawAllOam();
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
                break;
            }

            if (GAME_OVER_DATA.optionSelected == 1)
                result = 1;
            else if (GAME_OVER_DATA.optionSelected == 2)
                result = 2;

            gSubGameMode1 = 0;
            break;
    }

    return result;
}

/**
 * @brief 9df58 | 1cc | Initializes the game over screen
 * 
 */
void GameOverInit(void)
{
    u32 zero;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_9e58c);

    WRITE_16(REG_DISPCNT, 0);

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRam, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gNonGameplayRam) / sizeof(u32)));

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    DMA3_COPY_32(VRAM_OBJ, gSpriteGfxBackup, sizeof(gSpriteGfxBackup) / sizeof(u32));
    ClearGfxRam();

    gNextOamSlot = 0;
    ResetFreeOam();

    WRITE_16(REG_BG3CNT, 0);
    WRITE_16(REG_BG2CNT, 0);
    WRITE_16(REG_BG1CNT, 0);
    WRITE_16(REG_BG0CNT, 0);

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    LZ77UncompVram((const void*)0x8739a78, VRAM_OBJ);
    DMA3_COPY_32((const void*)0x873c4e4, PALRAM_OBJ, PAL_SIZE / sizeof(u32));

    LZ77UncompVram((const void*)0x873422c, VRAM_BASE);
    if (gLanguage > LANGUAGE_HIRAGANA)
        LZ77UncompVram(sGameOverTextGfxPointers[gLanguage], VRAM_BASE);

    LZ77UncompVram((const void*)0x873c6e4, VRAM_BASE + 0xF800);
    LZ77UncompVram((const void*)0x873cca8, VRAM_BASE + 0xF000);
    DMA3_COPY_32((const void*)0x873c2e4, PALRAM_BASE, PAL_SIZE / sizeof(u32));

    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    GameOverSetupOam(1, 43, 111);
    GameOverDrawAllOam();

    WRITE_16(REG_DISPCNT, DCNT_BG1 | DCNT_BG3 | DCNT_OBJ);
    CallbackSetVBlank(GameOverVblank);
}

/**
 * @brief 9e124 | 34 | Delay after choosing an option
 * 
 * @return boolu32 bool, ended
 */
boolu32 GameOverAfterOptionDelay(void)
{
    boolu32 ended;

    ended = FALSE;

    GameOverProcessOam();
    GameOverDrawAllOam();

    if (GAME_OVER_DATA.optionChosen == TRUE)
    {
        GAME_OVER_DATA.timer++;
        if (GAME_OVER_DATA.timer == 30)
        {
            GAME_OVER_DATA.timer = 0;
            ended = TRUE;
        }
    }

    return ended;
}

/**
 * @brief 9e158 | ac | Sets up a game over OAM object
 * 
 * @return u8 Slot (3 if none free)
 */
u8 GameOverSetupOam(u8 type, u16 xPosition, u16 yPosition)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(GAME_OVER_DATA.oam); i++)
    {
        if (GAME_OVER_DATA.oam[i].type == 0)
            break;
    }

    if (i >= ARRAY_SIZE(GAME_OVER_DATA.oam))
        return ARRAY_SIZE(GAME_OVER_DATA.oam);

    GameOverResetOam(i);

    GAME_OVER_DATA.oam[i].xPosition = xPosition;
    GAME_OVER_DATA.oam[i].yPosition = yPosition;
    GAME_OVER_DATA.oam[i].type = type;
    GAME_OVER_DATA.oam[i].isDrawn = TRUE;

    if (type == 1)
    {
        GAME_OVER_DATA.oam[i].priority = 3;
        GAME_OVER_DATA.oam[i].pOam = sGameOverCursorOamPointers[0];
        GAME_OVER_DATA.oam[i].pHandler = GameOverProcessCursor;
    }
    else if (type == 2)
    {
        GAME_OVER_DATA.oam[i].priority = 3;
        GAME_OVER_DATA.oam[i].pOam = (const struct FrameData*)0x873c274;
        GAME_OVER_DATA.oam[i].pHandler = unk_9e2cc;
    }

    return i;
}

/**
 * @brief 9e204 | c8 | Processes the game over cursor
 * 
 */
void GameOverProcessCursor(struct GameOverOam* pOam)
{
    if (pOam->selected)
        return;

    if (gChangedInput & KEY_UP)
    {
        if (pOam->yPosition != 111)
        {
            pOam->yPosition = 111;
            SoundPlay(0x1F9);
        }
    }
    else if (gChangedInput & KEY_DOWN)
    {
        if (pOam->yPosition != 136)
        {
            pOam->yPosition = 136;
            SoundPlay(0x1F9);
        }
    }

    if (gChangedInput & (KEY_A | KEY_START))
    {
        if (pOam->yPosition == 111)
        {
            SoundPlay(0x1FE);
            FadeMusic(10);
            pOam->pOam = sGameOverCursorOamPointers[1];
            GAME_OVER_DATA.optionSelected = 1;
        }
        else if (pOam->yPosition == 136)
        {
            SoundPlay(0x1FE);
            FadeMusic(10);
            pOam->pOam = sGameOverCursorOamPointers[2];
            GAME_OVER_DATA.optionSelected = 2;
        }

        GAME_OVER_DATA.optionChosen = TRUE;
        pOam->currentAnimationFrame = 0;
        pOam->animationDurationCounter = 0;
        pOam->selected = TRUE;
    }
}

/**
 * @brief 9e2cc | 28 | Makes an object follow the cursor
 * 
 */
void unk_9e2cc(struct GameOverOam* pOam)
{
    u16 x;
    u16 y;

    GameOverGetPositionAndSlotOfOamByType(1, &x, &y);
    pOam->xPosition = x;
    pOam->yPosition = y;
}

/**
 * @brief 9e2f4 | 28 | Resets a game over OAM object
 * 
 */
void GameOverResetOam(u8 slot)
{
    GAME_OVER_DATA.oam[slot].currentAnimationFrame = 0;
    GAME_OVER_DATA.oam[slot].animationDurationCounter = 0;
    GAME_OVER_DATA.oam[slot].unk_8 = 0;
    GAME_OVER_DATA.oam[slot].selected = 0;
    GAME_OVER_DATA.oam[slot].objMode = 0;
    GAME_OVER_DATA.oam[slot].priority = 0;
    GAME_OVER_DATA.oam[slot].xFlip = 0;
    GAME_OVER_DATA.oam[slot].paletteOffset = 0;
    GAME_OVER_DATA.oam[slot].tileOffset = 0;
}

/**
 * @brief 9e31c | 38 | Calls the handler of every game over OAM object
 * 
 */
void GameOverProcessOam(void)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(GAME_OVER_DATA.oam); i++)
    {
        if (GAME_OVER_DATA.oam[i].type != 0)
            GAME_OVER_DATA.oam[i].pHandler(&GAME_OVER_DATA.oam[i]);
    }
}

/**
 * @brief 9e354 | 40 | Draws every game over OAM object
 * 
 */
void GameOverDrawAllOam(void)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(GAME_OVER_DATA.oam); i++)
    {
        if (GAME_OVER_DATA.oam[i].isDrawn)
            GameOverDrawOam(&GAME_OVER_DATA.oam[i]);
    }

    ResetFreeOam();
    gNextOamSlot = 0;
}

/**
 * @brief 9e394 | 188 | Draws a game over OAM object
 * 
 * @param pOam Game over OAM pointer
 * 
 */
void GameOverDrawOam(struct GameOverOam* pOam)
{
    u16* dst;
    const u16* src;
    const struct FrameData* pFrame;
    s32 i;
    s32 partCount;
    s32 offset;
    u16 part1;
    u16 part2;
    u32 x;
    u32 y;
    u32 shape;
    u32 size;

    dst = (u16*)&gOamData[gNextOamSlot];
    pFrame = &pOam->pOam[pOam->currentAnimationFrame];

    if (pFrame->timer == pOam->animationDurationCounter)
    {
        pOam->currentAnimationFrame++;
        pOam->animationDurationCounter = 0;
        pFrame++;
    }

    if (pFrame->timer == 0)
    {
        pFrame -= pOam->currentAnimationFrame;
        pOam->currentAnimationFrame = 0;
    }

    src = pFrame->pFrame;
    partCount = *src++;

    for (i = 0; i < partCount; i++)
    {
        part1 = *src++;
        part2 = *src++;

        *dst++ = part1;
        *dst++ = part2;
        *dst++ = *src++;

        offset = gNextOamSlot + i;
        if (pOam->xFlip == TRUE)
        {
            gOamData[offset].split.xFlip ^= TRUE;
            size = gOamData[offset].split.size;
            shape = gOamData[offset].split.shape;
            x = MOD_AND(-(sGameOverOamXFlipOffsets[shape][size] * 8 + part2) + pOam->xPosition, 512);
            y = MOD_AND(part1 + (u16)pOam->yPosition, 256);
        }
        else
        {
            y = MOD_AND(part1 + (u16)pOam->yPosition, 256);
            x = MOD_AND(part2 + (u16)pOam->xPosition, 512);
        }

        gOamData[offset].split.y = y;
        gOamData[offset].split.x = x;
        gOamData[offset].split.priority = pOam->priority;
        gOamData[offset].split.paletteNum += pOam->paletteOffset;
        gOamData[offset].split.tileNum += pOam->tileOffset;
        gOamData[offset].split.objMode = pOam->objMode;

        dst++;
    }

    gNextOamSlot += partCount;
    pOam->animationDurationCounter++;
}

/**
 * @brief 9e51c | 44 | Gets the position of the first OAM object of a type
 * 
 */
void GameOverGetPositionAndSlotOfOamByType(u8 type, u16* pX, u16* pY)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(GAME_OVER_DATA.oam); i++)
    {
        if (GAME_OVER_DATA.oam[i].type == type)
        {
            *pX = GAME_OVER_DATA.oam[i].xPosition;
            *pY = GAME_OVER_DATA.oam[i].yPosition;
            return;
        }
    }

    *pX = 300;
    *pY = 200;
}

/**
 * @brief 9e560 | 2c | V-blank for the game over screen
 * 
 */
void GameOverVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief 9e58c | c | Game over, empty v-blank
 * 
 */
void unk_9e58c(void)
{
    UpdateAudio();
}
