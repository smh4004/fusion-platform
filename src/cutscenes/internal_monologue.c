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
extern const u8 sBlob_6638a0_68101c[];
extern const u8 sAddr_663e5c[];
extern const u8 sAddr_65fb5c[];
extern const u8 sAddr_6636a0[];

/**
 * @brief 9a328 | 84 | Main handler for the internal monologue cutscenes
 * 
 */
boolu32 CutsceneInternalMonologue(u8 param_1)
{
    boolu32 ended;

    ended = FALSE;

    switch (CUTSCENE_DATA.stage)
    {
        case 0:
            CUTSCENE_DATA.stage = 1;
            CutsceneInternalMonologueInit(param_1);
            break;

        case 1:
            CutsceneMonologueFadeIn();
            if (gWrittenToBldy == 0)
                CUTSCENE_DATA.stage++;
            break;

        case 2:
            if (CutsceneInternalMonologueProcess())
            {
                CUTSCENE_DATA.stage = 3;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
            }
            break;

        case 3:
            CutsceneMonologueFadeOut();
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 9a3ac | 13c | Setup for the internal monologue cutscenes
 * 
 */
void CutsceneInternalMonologueInit(u8 param_1)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_9a63c);

    WRITE_16(REG_DISPCNT, 0);

    LZ77UncompVram((const u32*)sAddr_65fb5c, VRAM_OBJ + 0x7C00);
    DMA3_COPY_32((const u16*)(&sBlob_6638a0_68101c), PALRAM_OBJ + 0x1E0, PAL_ROW_SIZE / 4);

    LZ77UncompWram(sIntroTilemap_662804, EWRAM_BASE);
    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xC800, 0x800 / 4);
    DMA3_COPY_32((const u16*)sAddr_6636a0, PALRAM_BASE, 16 * PAL_ROW_SIZE / 4);
    WRITE_16(PALRAM_BASE, 0);

    WRITE_16(REG_BG0VOFS, 4);
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 25, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_DISPCNT, DCNT_BG0 | DCNT_OBJ);

    gWrittenToBldy--;

    CutsceneInternalMonologueSetupOam(1, 12, 16);

    CUTSCENE_DATA.unk_A = gCurrentCutscene - 1;
    CUTSCENE_DATA.pText = sMonologueTextPointers[gLanguage][CUTSCENE_DATA.unk_A];

    CutsceneMonologueDrawAllOam();
    CallbackSetVBlank(CutsceneInternalMonologueVblank);
}

/**
 * @brief 9a4e8 | 3c | Processes the internal monologue cutscenes
 * 
 */
boolu32 CutsceneInternalMonologueProcess(void)
{
    boolu32 ended;

    ended = CutsceneMonologueProcessSpecialTextCharacters();

    switch (CUTSCENE_DATA.textState)
    {
        case 0:
            CUTSCENE_DATA.textState = 100;
            break;

        case 1:
            CUTSCENE_DATA.textState = 100;
            CutsceneMonologueProcessText();
            break;
    }

    CutsceneMonologueProcessOam();
    CutsceneMonologueDrawAllOam();

    return ended;
}

/**
 * @brief 9a524 | e0 | Sets up an internal monologue OAM
 * 
 */
u8 CutsceneInternalMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_DATA.u.monologue.oam); slot++)
    {
        if (CUTSCENE_DATA.u.monologue.oam[slot].type == 0)
            break;
    }

    if (slot >= ARRAY_SIZE(CUTSCENE_DATA.u.monologue.oam))
        return ARRAY_SIZE(CUTSCENE_DATA.u.monologue.oam);

    CutsceneMonologueResetOam(slot);

    CUTSCENE_DATA.u.monologue.oam[slot].xPosition = xPosition;
    CUTSCENE_DATA.u.monologue.oam[slot].yPosition = yPosition;
    CUTSCENE_DATA.u.monologue.oam[slot].type = type;
    CUTSCENE_DATA.u.monologue.oam[slot].enabled = TRUE;

    if (type == 1)
    {
        CUTSCENE_DATA.u.monologue.oam[slot].priority = 2;
        CUTSCENE_DATA.u.monologue.oam[slot].paletteOffset = 15;
        CUTSCENE_DATA.u.monologue.oam[slot].tileOffset = 0x3E0;
        CUTSCENE_DATA.u.monologue.oam[slot].pOam = (const struct FrameData*)sAddr_663e5c;
        CUTSCENE_DATA.u.monologue.oam[slot].pFunction = CutsceneMonologueProcessCursor;
    }

    return slot;
}

/**
 * @brief 9a604 | 38 | V-blank for the internal monologue cutscenes
 * 
 */
void CutsceneInternalMonologueVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);
    unk_9cc4c();
    WRITE_16(REG_BLDY, gWrittenToBldy);
}

/**
 * @brief 9a63c | c | V-blank that only updates the audio
 * 
 */
void unk_9a63c(void)
{
    UpdateAudio();
}
