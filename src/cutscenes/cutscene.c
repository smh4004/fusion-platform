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
 * @brief 9994c | 78 | Main handler for the in-game cutscenes
 * 
 */
boolu32 CutsceneHandler(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (gSubGameMode1)
    {
        case 0:
            CutsceneInit();
            gSubGameMode1 = 2;
            break;

        case 1:
            if (gWrittenToBldy != 0)
                gWrittenToBldy--;
            else
                gSubGameMode1++;
            break;

        case 2:
            if (CutsceneProcess())
                gSubGameMode1++;
            break;

        case 3:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                ended = TRUE;
                gSubGameMode1 = 0;
            }
            break;
    }

    return ended;
}

/**
 * @brief 999c4 | 120 | Setup for the in-game cutscenes
 * 
 */
void CutsceneInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_99af8);

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    DMA3_COPY_32(VRAM_OBJ, gSpriteGfxBackup, sizeof(gSpriteGfxBackup) / 4);

    gNextOamSlot = 0;
    ResetFreeOam();

    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    DMA3_FILL_32(0x7FFF, PALRAM_BASE, PALRAM_SIZE / 2);
    WRITE_16(PALRAM_BASE, 0);
    DMA3_FILL_32(0, VRAM_BASE, 0x10000);

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

    WRITE_16(REG_DISPCNT, 0);

    CallbackSetVBlank(CutsceneVblank);
}

/**
 * @brief 99ae4 | 14 | V-blank for the in-game cutscenes
 * 
 */
void CutsceneVblank(void)
{
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief 99af8 | c | V-blank that only updates the audio
 * 
 */
void unk_99af8(void)
{
    UpdateAudio();
}
