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
extern const u8 sAddr_675098[];
extern const u8 sAddr_677874[];
extern const u8 sAddr_677914[];
extern const u8 sAddr_677c10[];
extern const u8 sAddr_677c30[];
extern const u8 sAddr_677c50[];
extern const u8 sAddr_677c70[];
extern const u8 sAddr_677c90[];
extern const u8 sAddr_67815c[];
extern const u8 sAddr_6788a8[];
extern const u8 sAddr_679280[];
extern const u8 sAddr_6792a8[];
extern const u8 sAddr_6792d0[];
extern const u8 sAddr_679350[];
extern const u8 sAddr_6793a0[];
extern const u8 sAddr_6793b0[];

/**
 * @brief 9a9a8 | 84 | Main handler for the secret conversation cutscene
 * 
 */
boolu32 CutsceneSecretConversation(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (CUTSCENE_OAM_DATA.stage)
    {
        case 0:
            CUTSCENE_OAM_DATA.stage = 1;
            CutsceneSecretConversationInit();
            break;

        case 1:
            if (gWrittenToBldy != 0)
                gWrittenToBldy--;
            else
                CUTSCENE_OAM_DATA.stage = 2;
            break;

        case 2:
            if (CutsceneSecretConversationProcess())
            {
                CUTSCENE_OAM_DATA.stage = 3;
                WRITE_16(REG_DISPCNT, DCNT_BG1 | DCNT_BG2 | DCNT_OBJ);
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
            }
            break;

        case 3:
            CutsceneFadeOut();
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 9aa2c | 138 | Setup for the secret conversation cutscene
 * 
 */
void CutsceneSecretConversationInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_9ae0c);

    WRITE_16(REG_DISPCNT, 0);

    LZ77UncompVram((const u32*)sAddr_67815c, VRAM_OBJ + 0x4000);
    DMA3_COPY_32((const u16*)sAddr_6788a8, PALRAM_OBJ + 0x100, 2 * PAL_ROW_SIZE / 4);

    LZ77UncompVram((const u32*)sAddr_675098, VRAM_BASE + 0x800);
    LZ77UncompVram((const u32*)sAddr_677914, VRAM_BASE + 0xC000);
    LZ77UncompVram((const u32*)sAddr_677c90, VRAM_BASE + 0xC800);
    DMA3_COPY_32((const u16*)sAddr_677874, PALRAM_BASE, 5 * PAL_ROW_SIZE / 4);
    DMA3_COPY_32((const u16*)sAddr_677c10, PALRAM_BASE + 0x1E0, PAL_ROW_SIZE / 4);

    CutsceneSecretConversationSetupOam(1, 120, 128);
    CutsceneSecretConversationSetupOam(2, 120, 128);
    CutsceneSecretConversationSetupOam(3, 120, 128);

    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 24, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 25, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_DISPCNT, DCNT_BG1 | DCNT_BG2 | DCNT_OBJ);

    gWrittenToBldy--;

    CutsceneDrawAllOam();
    CallbackSetVBlank(CutsceneSecretConversationVblank);
}

/**
 * @brief 9ab64 | 64 | Processes the secret conversation cutscene
 * 
 */
boolu32 CutsceneSecretConversationProcess(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (CUTSCENE_OAM_DATA.subStage)
    {
        case 0:
            CUTSCENE_OAM_DATA.timer++;
            if (CUTSCENE_OAM_DATA.timer > 29)
            {
                CUTSCENE_OAM_DATA.subStage = 1;
                CUTSCENE_OAM_DATA.timer = 0;
                CutsceneSecretConversationSetupOam(4, 120, 68);
                CutsceneProcessOam();
            }
            CutsceneDrawAllOam();
            break;

        case 1:
            CutsceneProcessOam();
            CutsceneDrawAllOam();
            break;

        case 2:
            CutsceneProcessOam();
            CutsceneDrawAllOam();
            ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 9abc8 | 10c | Sets up a secret conversation OAM
 * 
 */
u8 CutsceneSecretConversationSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_OAM_DATA.oam); slot++)
    {
        if (CUTSCENE_OAM_DATA.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(CUTSCENE_OAM_DATA.oam))
        return ARRAY_SIZE(CUTSCENE_OAM_DATA.oam);

    DMA3_FILL_32(0, &CUTSCENE_OAM_DATA.oam[slot], sizeof(struct CutsceneOam));

    CUTSCENE_OAM_DATA.oam[slot].xPosition = xPosition;
    CUTSCENE_OAM_DATA.oam[slot].yPosition = yPosition;
    CUTSCENE_OAM_DATA.oam[slot].type = type;
    CUTSCENE_OAM_DATA.oam[slot].enabled = TRUE;

    if (type == 1)
    {
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6793b0;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9db70;
    }
    else if (type == 2)
    {
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_679280;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneSecretConversationProcessNavigationPanel;
    }
    else if (type == 3)
    {
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6793a0;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = unk_9db70;
    }
    else if (type == 4)
    {
        CUTSCENE_OAM_DATA.oam[slot].pOam = (const struct FrameData*)sAddr_6792d0;
        CUTSCENE_OAM_DATA.oam[slot].pFunction = CutsceneSecretConversationProcessIncomingDispatch;
    }

    return slot;
}

/**
 * @brief 9acd4 | 20 | Processes the navigation panel
 * 
 */
void CutsceneSecretConversationProcessNavigationPanel(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->stage = 1;
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
        pOam->pOam = (const struct FrameData*)sAddr_6792a8;
    }
}

/**
 * @brief 9acf4 | 70 | Processes the incoming dispatch message
 * 
 */
void CutsceneSecretConversationProcessIncomingDispatch(struct CutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->stage == 0)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pOam->timer == 0)
        {
            SoundPlay(SOUND_22F);
            pOam->timer = 1;
        }

        if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->stage = 1;
            pOam->timer = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)sAddr_679350;
        }
    }
    else if (pOam->stage == 1)
    {
        pOam->timer++;
        if (pOam->timer == 180)
        {
            pOam->stage = 2;
            pOam->timer = 0;
            CUTSCENE_OAM_DATA.subStage = 2;
        }
    }
}

/**
 * @brief 9ad64 | a8 | V-blank for the secret conversation cutscene
 * 
 */
void CutsceneSecretConversationVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);
    WRITE_16(REG_BLDY, gWrittenToBldy);

    CUTSCENE_OAM_DATA.unk_11++;
    switch (CUTSCENE_OAM_DATA.unk_11)
    {
        case 7:
            DMA3_COPY_32((const u16*)sAddr_677c30, PALRAM_BASE + 0x1E0, PAL_ROW_SIZE / 4);
            break;

        case 14:
            DMA3_COPY_32((const u16*)sAddr_677c50, PALRAM_BASE + 0x1E0, PAL_ROW_SIZE / 4);
            break;

        case 21:
            DMA3_COPY_32((const u16*)sAddr_677c70, PALRAM_BASE + 0x1E0, PAL_ROW_SIZE / 4);
            break;

        case 28:
            DMA3_COPY_32((const u16*)sAddr_677c10, PALRAM_BASE + 0x1E0, PAL_ROW_SIZE / 4);
            CUTSCENE_OAM_DATA.unk_11 = 0;
            break;
    }
}

/**
 * @brief 9ae0c | c | V-blank that only updates the audio
 * 
 */
void unk_9ae0c(void)
{
    UpdateAudio();
}
