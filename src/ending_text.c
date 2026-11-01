#include "ending_text.h"
#include "gba.h"
#include "globals.h"
#include "macros.h"

#include "data/ending_data.h"

#include "constants/game_state.h"

#include "structs/ending.h"

/**
 * @brief a1480 | 1a8 | Loads the digit graphics of the in-game time and the completion percentage
 * 
 */
void EndingDrawIgtAndCompletionPercentage(void)
{
    s32 offset;
    s32 hoursTens;
    s32 hoursOnes;
    s32 minutesTens;
    s32 minutesOnes;

    hoursTens = 0;
    hoursOnes = gInGameTimer.hours;
    while (hoursOnes > 9)
    {
        hoursOnes -= 10;
        hoursTens++;
    }

    minutesTens = 0;
    minutesOnes = gInGameTimer.minutes;
    while (minutesOnes > 9)
    {
        minutesOnes -= 10;
        minutesTens++;
    }

    if (hoursTens != 0)
    {
        offset = hoursTens * 64;
        DMA3_COPY_16(&sEndingDigitsTopGfx[offset], VRAM_OBJ + 0x0, 64 / 2);
        DMA3_COPY_16(&sEndingDigitsBottomGfx[offset], VRAM_OBJ + 0x400, 64 / 2);
    }

    offset = hoursOnes * 64;
    DMA3_COPY_16(&sEndingDigitsTopGfx[offset], VRAM_OBJ + 0x40, 64 / 2);
    DMA3_COPY_16(&sEndingDigitsBottomGfx[offset], VRAM_OBJ + 0x440, 64 / 2);

    offset = minutesTens * 64;
    DMA3_COPY_16(&sEndingDigitsTopGfx[offset], VRAM_OBJ + 0xA0, 64 / 2);
    DMA3_COPY_16(&sEndingDigitsBottomGfx[offset], VRAM_OBJ + 0x4A0, 64 / 2);

    offset = minutesOnes * 64;
    DMA3_COPY_16(&sEndingDigitsTopGfx[offset], VRAM_OBJ + 0xE0, 64 / 2);
    DMA3_COPY_16(&sEndingDigitsBottomGfx[offset], VRAM_OBJ + 0x4E0, 64 / 2);

    hoursTens = 0;
    hoursOnes = 0;
    minutesTens = ENDING_DATA.completionPercentage;
    while (minutesTens > 99)
    {
        minutesTens -= 100;
        hoursTens++;
    }

    while (minutesTens > 9)
    {
        minutesTens -= 10;
        hoursOnes++;
    }

    if (hoursTens != 0)
    {
        offset = hoursTens * 64;
        DMA3_COPY_16(&sEndingDigitsTopGfx[offset], VRAM_OBJ + 0x120, 64 / 2);
        DMA3_COPY_16(&sEndingDigitsBottomGfx[offset], VRAM_OBJ + 0x520, 64 / 2);
    }

    if (hoursTens != 0 || hoursOnes != 0)
    {
        offset = hoursOnes * 64;
        DMA3_COPY_16(&sEndingDigitsTopGfx[offset], VRAM_OBJ + 0x160, 64 / 2);
        DMA3_COPY_16(&sEndingDigitsBottomGfx[offset], VRAM_OBJ + 0x560, 64 / 2);
    }

    offset = minutesTens * 64;
    DMA3_COPY_16(&sEndingDigitsTopGfx[offset], VRAM_OBJ + 0x1A0, 64 / 2);
    DMA3_COPY_16(&sEndingDigitsBottomGfx[offset], VRAM_OBJ + 0x5A0, 64 / 2);
}

/**
 * @brief a1628 | 3c | Updates the spawn delay of an ending text letter
 * 
 * @param slot Letter slot
 */
void EndingImageUpdateLettersSpawnDelay(u32 slot)
{
    if (ENDING_DATA.unk_124[slot] == 0)
        return;

    if (ENDING_DATA.lettersSpawnDelay[slot] == 0)
        return;

    ENDING_DATA.lettersSpawnDelay[slot]--;
    if (ENDING_DATA.lettersSpawnDelay[slot] == 0)
        ENDING_DATA.unk_124[slot]++;
}

/**
 * @brief a1664 | 4fc | Loads the letters of a set of ending text lines
 * 
 * @param set Line set
 */
void EndingImageLoadTextOam(u32 set)
{
    s32 i;

    switch (gLanguage)
    {
        case LANGUAGE_GERMAN:
            if (set == 0)
            {
                ENDING_DATA.unk_9B = 13 + 6;
                for (i = 0; i < 13; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_German0[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_German0[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_German0[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_German0[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_German0[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_German0[i].pOam;
                }
            }
            else
            {
                ENDING_DATA.unk_9B = 14 + 6;
                for (i = 0; i < 14; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_German1[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_German1[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_German1[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_German1[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_German1[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_German1[i].pOam;
                }
            }
            break;

        case LANGUAGE_FRENCH:
            if (set == 0)
            {
                ENDING_DATA.unk_9B = 16 + 6;
                for (i = 0; i < 16; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_French0[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_French0[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_French0[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_French0[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_French0[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_French0[i].pOam;
                }
            }
            else
            {
                ENDING_DATA.unk_9B = 20 + 6;
                for (i = 0; i < 20; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_French1[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_French1[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_French1[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_French1[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_French1[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_French1[i].pOam;
                }
            }
            break;

        case LANGUAGE_ITALIAN:
            if (set == 0)
            {
                ENDING_DATA.unk_9B = 18 + 6;
                for (i = 0; i < 18; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_Italian0[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_Italian0[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_Italian0[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_Italian0[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_Italian0[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_Italian0[i].pOam;
                }
            }
            else if (set == 1)
            {
                ENDING_DATA.unk_9B = 11 + 6;
                for (i = 0; i < 11; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_Italian1[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_Italian1[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_Italian1[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_Italian1[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_Italian1[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_Italian1[i].pOam;
                }
            }
            else
            {
                ENDING_DATA.unk_9B = 17 + 6;
                for (i = 0; i < 17; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_Italian2[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_Italian2[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_Italian2[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_Italian2[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_Italian2[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_Italian2[i].pOam;
                }
            }
            break;

        case LANGUAGE_SPANISH:
            if (set == 0)
            {
                ENDING_DATA.unk_9B = 15 + 6;
                for (i = 0; i < 15; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_Spanish0[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_Spanish0[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_Spanish0[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_Spanish0[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_Spanish0[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_Spanish0[i].pOam;
                }
            }
            else
            {
                ENDING_DATA.unk_9B = 19 + 6;
                for (i = 0; i < 19; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_Spanish1[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_Spanish1[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_Spanish1[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_Spanish1[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_Spanish1[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_Spanish1[i].pOam;
                }
            }
            break;

        default:
            if (set == 0)
            {
                ENDING_DATA.unk_9B = 9 + 6;
                for (i = 0; i < 9; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_Default0[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_Default0[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_Default0[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_Default0[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_Default0[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_Default0[i].pOam;
                }
            }
            else if (set == 1)
            {
                ENDING_DATA.unk_9B = 11 + 6;
                for (i = 0; i < 11; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_Default1[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_Default1[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_Default1[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_Default1[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_Default1[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_Default1[i].pOam;
                }
            }
            else
            {
                ENDING_DATA.unk_9B = 17 + 6;
                for (i = 0; i < 17; i++)
                {
                    ENDING_DATA.unk_124[6 + i] = sEndingTextLetters_Default2[i].unk_0;
                    ENDING_DATA.lettersSpawnDelay[6 + i] = sEndingTextLetters_Default2[i].spawnDelay;
                    ENDING_DATA.unk_160[6 + i] = sEndingTextLetters_Default2[i].unk_2;
                    ENDING_DATA.oamXPositions[6 + i] = sEndingTextLetters_Default2[i].xPosition;
                    ENDING_DATA.oamYPositions[6 + i] = sEndingTextLetters_Default2[i].yPosition;
                    ENDING_DATA.oamFramePointers[6 + i] = (u16*)sEndingTextLetters_Default2[i].pOam;
                }
            }
            break;
    }
}

/**
 * @brief a1b60 | 124 | Displays an ending text line permanently
 * 
 * @param line Line
 */
void EndingImageDisplayLinePermanently(u32 line)
{
    s32 i;

    switch (gLanguage)
    {
        case LANGUAGE_GERMAN:
            ENDING_DATA.unk_124[line] = sEndingTextLetters_PermanentGerman[line].unk_0;
            ENDING_DATA.lettersSpawnDelay[line] = sEndingTextLetters_PermanentGerman[line].spawnDelay;
            ENDING_DATA.unk_160[line] = sEndingTextLetters_PermanentGerman[line].unk_2;
            ENDING_DATA.oamXPositions[line] = sEndingTextLetters_PermanentGerman[line].xPosition;
            ENDING_DATA.oamYPositions[line] = sEndingTextLetters_PermanentGerman[line].yPosition;
            ENDING_DATA.oamFramePointers[line] = (u16*)sEndingTextLetters_PermanentGerman[line].pOam;
            break;

        case LANGUAGE_FRENCH:
            ENDING_DATA.unk_124[line] = sEndingTextLetters_PermanentFrench[line].unk_0;
            ENDING_DATA.lettersSpawnDelay[line] = sEndingTextLetters_PermanentFrench[line].spawnDelay;
            ENDING_DATA.unk_160[line] = sEndingTextLetters_PermanentFrench[line].unk_2;
            ENDING_DATA.oamXPositions[line] = sEndingTextLetters_PermanentFrench[line].xPosition;
            ENDING_DATA.oamYPositions[line] = sEndingTextLetters_PermanentFrench[line].yPosition;
            ENDING_DATA.oamFramePointers[line] = (u16*)sEndingTextLetters_PermanentFrench[line].pOam;
            break;

        case LANGUAGE_ITALIAN:
            ENDING_DATA.unk_124[line] = sEndingTextLetters_PermanentItalian[line].unk_0;
            ENDING_DATA.lettersSpawnDelay[line] = sEndingTextLetters_PermanentItalian[line].spawnDelay;
            ENDING_DATA.unk_160[line] = sEndingTextLetters_PermanentItalian[line].unk_2;
            ENDING_DATA.oamXPositions[line] = sEndingTextLetters_PermanentItalian[line].xPosition;
            ENDING_DATA.oamYPositions[line] = sEndingTextLetters_PermanentItalian[line].yPosition;
            ENDING_DATA.oamFramePointers[line] = (u16*)sEndingTextLetters_PermanentItalian[line].pOam;
            break;

        case LANGUAGE_SPANISH:
            ENDING_DATA.unk_124[line] = sEndingTextLetters_PermanentSpanish[line].unk_0;
            ENDING_DATA.lettersSpawnDelay[line] = sEndingTextLetters_PermanentSpanish[line].spawnDelay;
            ENDING_DATA.unk_160[line] = sEndingTextLetters_PermanentSpanish[line].unk_2;
            ENDING_DATA.oamXPositions[line] = sEndingTextLetters_PermanentSpanish[line].xPosition;
            ENDING_DATA.oamYPositions[line] = sEndingTextLetters_PermanentSpanish[line].yPosition;
            ENDING_DATA.oamFramePointers[line] = (u16*)sEndingTextLetters_PermanentSpanish[line].pOam;
            break;

        default:
            ENDING_DATA.unk_124[line] = sEndingTextLetters_PermanentDefault[line].unk_0;
            ENDING_DATA.lettersSpawnDelay[line] = sEndingTextLetters_PermanentDefault[line].spawnDelay;
            ENDING_DATA.unk_160[line] = sEndingTextLetters_PermanentDefault[line].unk_2;
            ENDING_DATA.oamXPositions[line] = sEndingTextLetters_PermanentDefault[line].xPosition;
            ENDING_DATA.oamYPositions[line] = sEndingTextLetters_PermanentDefault[line].yPosition;
            ENDING_DATA.oamFramePointers[line] = (u16*)sEndingTextLetters_PermanentDefault[line].pOam;
            break;
    }

    for (i = 0; i < ENDING_DATA.unk_9B - 6; i++)
        ENDING_DATA.unk_124[6 + i] = 0;

    ENDING_DATA.unk_9B = 6;
}
