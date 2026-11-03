#include "menus/easy_sleep_menu.h"
#include "globals.h"
#include "macros.h"
#include "audio_wrappers.h"
#include "syscalls.h"

#include "constants/audio.h"

#include "gba/display.h"
#include "gba/interrupt.h"
#include "gba/keys.h"

#include "structs/menus/pause_screen.h"

/**
 * @brief 7ed20 | 184 | Handles the easy sleep menu
 * 
 */
u32 EasySleepMenuHandler(void)
{
    u32 exit;
    u16 ie;

    exit = FALSE;
    switch (PAUSE_SCREEN_DATA.subMenuStage)
    {
        case 0:
            if (gChangedInput & KEY_A)
            {
                SoundPlay(SOUND_1FB);
                exit = TRUE;
                break;
            }

            if (gChangedInput & KEY_LEFT)
            {
                PAUSE_SCREEN_DATA.subMenuStage = 1;
                PAUSE_SCREEN_DATA.oam[1].xPosition = 60;
                SoundPlay(SOUND_1FA);
                break;
            }

            if (gChangedInput & (KEY_B | KEY_L | KEY_R))
                exit = TRUE;
            break;

        case 1:
            if (gChangedInput & KEY_A)
            {
                SoundPlay(SOUND_1FB);
                PAUSE_SCREEN_DATA.subMenuStage = 2;
                PAUSE_SCREEN_DATA.timer = 0;
                break;
            }

            if (gChangedInput & KEY_RIGHT)
            {
                PAUSE_SCREEN_DATA.subMenuStage = 0;
                PAUSE_SCREEN_DATA.oam[1].xPosition = 140;
                SoundPlay(SOUND_1FA);
                break;
            }

            if (gChangedInput & (KEY_B | KEY_L | KEY_R))
                exit = TRUE;
            break;

        case 2:
            PAUSE_SCREEN_DATA.timer++;
            if (PAUSE_SCREEN_DATA.timer > 30)
            {
                PAUSE_SCREEN_DATA.subMenuStage++;
                PAUSE_SCREEN_DATA.timer = 0;
            }
            break;

        case 3:
            PAUSE_SCREEN_DATA.dispcnt ^= DCNT_BLANK;
            PAUSE_SCREEN_DATA.subMenuStage++;
            break;

        case 4:
            WRITE_16(REG_KEY_CONTROL, KEY_CONTROL_ALL_INPUTS | KEY_CONTROL_ENABLE | KEY_SELECT | KEY_L | KEY_R);
            WRITE_16(REG_IME, FALSE);
            ie = READ_16(REG_IE);
            WRITE_16(REG_IE, IF_KEYPAD | IF_GAMEPAK);
            WRITE_16(REG_IME, TRUE);

            SoundBias0();
            SYSCALL(3); /* SYSCALL_Halt */
            SoundBias1();

            WRITE_16(REG_IME, FALSE);
            WRITE_16(REG_IE, ie);
            WRITE_16(REG_IME, TRUE);

            PAUSE_SCREEN_DATA.dispcnt ^= DCNT_BLANK;
            PAUSE_SCREEN_DATA.oam[1].xPosition = 140;
            PAUSE_SCREEN_DATA.subMenuStage++;
            break;

        case 5:
            if (gButtonInput == KEY_NONE)
                PAUSE_SCREEN_DATA.subMenuStage = 0;
            break;
    }

    if (exit)
    {
        PAUSE_SCREEN_DATA.subMenuStage = 0;
        PAUSE_SCREEN_DATA.timer = 0;
    }

    return exit;
}
