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
extern const u8 sAddr_663e5c[];
extern const u8 sAddr_663e74[];

/**
 * @brief 9c938 | c0 | Processes the monologue text cursor
 * 
 */
void CutsceneMonologueProcessCursor(struct CutsceneMonologueOam* pOam)
{
    struct CutsceneData* pData;

    pData = &CUTSCENE_DATA;
    if (*pData->pText == CHAR_TERMINATOR)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
    else if (*pData->pText == CHAR_NEW_LINE)
    {
        goto set_position;
    }
    else if (*pData->pText == CHAR_NEW_PAGE)
    {
        goto new_page;
    }
    else if (*pData->pText == CHAR_NEXT_PAGE_ARROW)
    {
        if (pOam->stage == 0)
        {
            if (gChangedInput & KEY_A)
            {
                pOam->xPosition = 290;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
            }
            else
            {
                pOam->pOam = (const struct FrameData*)sAddr_663e74;
                pOam->xPosition = 118;
                pOam->yPosition = pData->textLine * 8 + 24;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->stage = 1;
            }
        }
        else if (pOam->stage == 1 && gChangedInput & KEY_A)
        {
        new_page:
            pOam->pOam = (const struct FrameData*)sAddr_663e5c;
            pOam->xPosition = 290;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->stage = 0;
        }
    }
    else
    {
    set_position:
        pOam->xPosition = pData->textColumn * 8 + (pData->u.monologue.textIndent + 12);
        pOam->yPosition = pData->textLine * 8 + 12;
    }
}

/**
 * @brief 9c9f8 | a4 | Processes the special characters of the monologue text
 * 
 */
boolu32 CutsceneMonologueProcessSpecialTextCharacters(void)
{
    boolu32 ended;

    ended = FALSE;

    if (gButtonInput & KEY_A)
        CUTSCENE_DATA.timer += 2;
    else
        CUTSCENE_DATA.timer += 1;

    if (*CUTSCENE_DATA.pText == CHAR_TERMINATOR)
    {
        CUTSCENE_DATA.timer = 0;
        CUTSCENE_DATA.textState = 100;
        ended = TRUE;
    }
    else if (*CUTSCENE_DATA.pText == CHAR_NEXT_PAGE_ARROW)
    {
        if (gChangedInput & KEY_A)
        {
            CUTSCENE_DATA.textState = 1;
            CUTSCENE_DATA.timer = 0;
        }
        else
        {
            CUTSCENE_DATA.timer = 0;
        }
    }
    else if ((*CUTSCENE_DATA.pText & 0xFF00) == 0xE100)
    {
        if ((*CUTSCENE_DATA.pText & 0xFF) <= CUTSCENE_DATA.timer)
        {
            CUTSCENE_DATA.textState = 1;
            CUTSCENE_DATA.timer = 0;
        }
    }
    else if (CUTSCENE_DATA.timer > 2)
    {
        CUTSCENE_DATA.textState = 1;
        CUTSCENE_DATA.timer = 0;
    }

    return ended;
}

/**
 * @brief 9ca9c | 1b0 | Draws the next character of the monologue text
 * 
 */
void CutsceneMonologueProcessText(void)
{
    u16 i;
    u32* dst;
    u32 width;

    if (*CUTSCENE_DATA.pText == CHAR_TERMINATOR)
        return;

    if (*CUTSCENE_DATA.pText == CHAR_NEW_LINE)
    {
        for (i = CUTSCENE_DATA.textColumn + 1; i < 28; i++)
            CUTSCENE_DATA.u.monologue.characterFade[i + (CUTSCENE_DATA.textLine / 2) * 28] |= 0xFF;

        CUTSCENE_DATA.textColumn = 0;
        CUTSCENE_DATA.textLine += 2;
        CUTSCENE_DATA.pText++;
        CUTSCENE_DATA.u.monologue.textIndent = 0;
    }
    else if (*CUTSCENE_DATA.pText == CHAR_NEW_PAGE)
    {
        DMA3_FILL_32(0, VRAM_BASE + 0x8000, 0x4800);
        CUTSCENE_DATA.fadeLine = 0;
        CUTSCENE_DATA.fadeColumn = 0;
        CUTSCENE_DATA.textLine = 0;
        CUTSCENE_DATA.textColumn = 0;
        CUTSCENE_DATA.pText++;
        CUTSCENE_DATA.u.monologue.textIndent = 0;
        DMA3_FILL_32(0, CUTSCENE_DATA.u.monologue.characterFade, sizeof(CUTSCENE_DATA.u.monologue.characterFade));
        DMA3_FILL_32(0, CUTSCENE_DATA.u.monologue.characterFadeTimer, sizeof(CUTSCENE_DATA.u.monologue.characterFadeTimer));
        DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xC800, 0x800 / 4);
    }
    else if (*CUTSCENE_DATA.pText == CHAR_NEXT_PAGE_ARROW || (*CUTSCENE_DATA.pText & 0xFF00) == 0xE100)
    {
        CUTSCENE_DATA.pText++;
    }
    else
    {
        dst = (u32*)(CUTSCENE_DATA.textColumn * 32 + CUTSCENE_DATA.textLine * 1024 + VRAM_BASE + 0x8000);
        width = TextGetCharacterWidth(*CUTSCENE_DATA.pText);
        TextDrawCharacter(*CUTSCENE_DATA.pText, dst, width, CUTSCENE_DATA.u.monologue.textIndent, 0);

        if (CUTSCENE_DATA.textColumn < 28)
        {
            CUTSCENE_DATA.u.monologue.characterFade[(CUTSCENE_DATA.textLine / 2) * 28 + CUTSCENE_DATA.textColumn] = 4;
            CUTSCENE_DATA.u.monologue.textIndent += width;

            while (CUTSCENE_DATA.u.monologue.textIndent >= 8)
            {
                CUTSCENE_DATA.u.monologue.textIndent -= 8;
                CUTSCENE_DATA.textColumn++;
                if (CUTSCENE_DATA.textColumn >= 28)
                    break;

                if (CUTSCENE_DATA.u.monologue.textIndent != 0)
                    CUTSCENE_DATA.u.monologue.characterFade[(CUTSCENE_DATA.textLine / 2) * 28 + CUTSCENE_DATA.textColumn] = 4;
            }
        }

        CUTSCENE_DATA.pText++;
    }
}

// 0x0809CC4C
NAKED_FUNCTION
void unk_9cc4c(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	ldr r1, _0809CC8C @ =gNonGameplayRam\n\
	ldrh r6, [r1, #4]\n\
	ldrh r0, [r1, #6]\n\
	lsrs r7, r0, #1\n\
	ldrh r0, [r1, #2]\n\
	lsrs r0, r0, #1\n\
	str r1, [sp, #4]\n\
	cmp r7, r0\n\
	bls _0809CC6C\n\
	b _0809CD70\n\
_0809CC6C:\n\
	str r1, [sp]\n\
_0809CC6E:\n\
	ldr r2, [sp]\n\
	ldr r0, [r2, #0xc]\n\
	ldrh r0, [r0]\n\
	movs r3, #0xfc\n\
	lsls r3, r3, #8\n\
	cmp r0, r3\n\
	bne _0809CC90\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x1b\n\
	bhi _0809CCAA\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	mov ip, r0\n\
	b _0809CCAE\n\
	.align 2, 0\n\
_0809CC8C: .4byte gNonGameplayRam\n\
_0809CC90:\n\
	ldrh r0, [r1, #2]\n\
	lsrs r0, r0, #1\n\
	cmp r7, r0\n\
	bne _0809CCAA\n\
	ldr r1, [sp]\n\
	ldrh r0, [r1]\n\
	movs r2, #0x1c\n\
	mov ip, r2\n\
	cmp r0, #0x1b\n\
	bhi _0809CCAE\n\
	adds r3, r0, #0\n\
	mov ip, r3\n\
	b _0809CCAE\n\
_0809CCAA:\n\
	movs r5, #0x1c\n\
	mov ip, r5\n\
_0809CCAE:\n\
	adds r0, r7, #1\n\
	str r0, [sp, #8]\n\
	cmp r6, ip\n\
	bhs _0809CD5C\n\
	ldr r1, _0809CD24 @ =gNonGameplayRam\n\
	mov r8, r1\n\
	lsls r0, r7, #3\n\
	subs r0, r0, r7\n\
	lsls r0, r0, #2\n\
	mov sl, r0\n\
	ldr r2, _0809CD28 @ =0x00000FFF\n\
	mov sb, r2\n\
_0809CCC6:\n\
	mov r3, sl\n\
	adds r2, r6, r3\n\
	ldr r5, _0809CD2C @ =0x0300159C\n\
	adds r1, r2, r5\n\
	ldrb r0, [r1]\n\
	cmp r0, #5\n\
	bne _0809CD4E\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r0, [sp, #4]\n\
	adds r0, #0x1c\n\
	adds r2, r2, r0\n\
	ldrb r0, [r2]\n\
	subs r1, r0, #1\n\
	strb r1, [r2]\n\
	lsls r0, r1, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	ble _0809CD38\n\
	lsls r2, r6, #1\n\
	lsls r0, r7, #7\n\
	adds r2, r2, r0\n\
	ldr r0, _0809CD30 @ =0x0600C842\n\
	adds r0, r2, r0\n\
	str r0, [sp, #0xc]\n\
	ldr r1, _0809CD34 @ =0x0600C882\n\
	adds r2, r2, r1\n\
	ldrh r3, [r0]\n\
	ldrh r4, [r2]\n\
	lsrs r0, r3, #0xc\n\
	lsrs r1, r4, #0xc\n\
	subs r0, #1\n\
	lsls r0, r0, #0x10\n\
	subs r1, #1\n\
	lsls r1, r1, #0x10\n\
	lsrs r0, r0, #4\n\
	mov r5, sb\n\
	ands r3, r5\n\
	orrs r0, r3\n\
	ldr r3, [sp, #0xc]\n\
	strh r0, [r3]\n\
	lsrs r1, r1, #4\n\
	ands r4, r5\n\
	orrs r1, r4\n\
	strh r1, [r2]\n\
	b _0809CD52\n\
	.align 2, 0\n\
_0809CD24: .4byte gNonGameplayRam\n\
_0809CD28: .4byte 0x00000FFF\n\
_0809CD2C: .4byte 0x0300159C\n\
_0809CD30: .4byte 0x0600C842\n\
_0809CD34: .4byte 0x0600C882\n\
_0809CD38:\n\
	cmp r0, #0\n\
	bne _0809CD46\n\
	lsls r0, r7, #1\n\
	mov r5, r8\n\
	strh r0, [r5, #6]\n\
	strh r6, [r5, #4]\n\
	b _0809CD52\n\
_0809CD46:\n\
	movs r0, #0xff\n\
	orrs r1, r0\n\
	strb r1, [r2]\n\
	b _0809CD5C\n\
_0809CD4E:\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0809CD52:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	cmp r6, ip\n\
	blo _0809CCC6\n\
_0809CD5C:\n\
	movs r6, #0\n\
	ldr r1, [sp, #8]\n\
	lsls r0, r1, #0x10\n\
	lsrs r7, r0, #0x10\n\
	ldr r1, [sp, #4]\n\
	ldrh r0, [r1, #2]\n\
	lsrs r0, r0, #1\n\
	cmp r7, r0\n\
	bhi _0809CD70\n\
	b _0809CC6E\n\
_0809CD70:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

/**
 * @brief 9cd80 | 58 | Fades in a monologue cutscene
 * 
 */
void CutsceneMonologueFadeIn(void)
{
    CutsceneMonologueProcessOam();
    CutsceneMonologueDrawAllOam();

    if (gWrittenToBldy != 0)
    {
        if (gWrittenToBldy > 11)
        {
            CUTSCENE_DATA.unk_16++;
            if (CUTSCENE_DATA.unk_16 == 3)
            {
                CUTSCENE_DATA.unk_16 = 0;
                gWrittenToBldy--;
            }
        }
        else if (gWrittenToBldy > 6)
        {
            CUTSCENE_DATA.unk_16++;
            if (CUTSCENE_DATA.unk_16 == 2)
            {
                CUTSCENE_DATA.unk_16 = 0;
                gWrittenToBldy--;
            }
        }
        else
        {
            gWrittenToBldy--;
        }
    }
}

/**
 * @brief 9cdd8 | 58 | Fades out a monologue cutscene
 * 
 */
void CutsceneMonologueFadeOut(void)
{
    CutsceneMonologueProcessOam();
    CutsceneMonologueDrawAllOam();

    if (gWrittenToBldy < BLDY_MAX_VALUE)
    {
        if (gWrittenToBldy < 6)
        {
            CUTSCENE_DATA.unk_16++;
            if (CUTSCENE_DATA.unk_16 == 3)
            {
                CUTSCENE_DATA.unk_16 = 0;
                gWrittenToBldy++;
            }
        }
        else if (gWrittenToBldy < 11)
        {
            CUTSCENE_DATA.unk_16++;
            if (CUTSCENE_DATA.unk_16 == 2)
            {
                CUTSCENE_DATA.unk_16 = 0;
                gWrittenToBldy++;
            }
        }
        else
        {
            gWrittenToBldy++;
        }
    }
}

/**
 * @brief 9ce30 | 44 | Processes the monologue OAM
 * 
 */
void CutsceneMonologueProcessOam(void)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(CUTSCENE_DATA.u.monologue.oam); i++)
    {
        if (CUTSCENE_DATA.u.monologue.oam[i].type != 0)
            CUTSCENE_DATA.u.monologue.oam[i].pFunction(&CUTSCENE_DATA.u.monologue.oam[i]);
    }
}

/**
 * @brief 9ce74 | 4c | Draws all the monologue OAM
 * 
 */
void CutsceneMonologueDrawAllOam(void)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(CUTSCENE_DATA.u.monologue.oam); i++)
    {
        if (CUTSCENE_DATA.u.monologue.oam[i].enabled)
            CutsceneMnologueDrawOam(&CUTSCENE_DATA.u.monologue.oam[i]);
    }

    ResetFreeOam();
    gNextOamSlot = 0;
}

// 0x0809CEC0
NAKED_FUNCTION
void CutsceneMnologueDrawOam(struct CutsceneMonologueOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r5, r0, #0\n\
	ldr r2, _0809CF80 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #3\n\
	ldr r1, _0809CF84 @ =gOamData\n\
	adds r7, r0, r1\n\
	ldrb r4, [r5, #6]\n\
	lsls r1, r4, #3\n\
	ldr r0, [r5, #0x10]\n\
	adds r3, r0, r1\n\
	ldrb r0, [r3, #4]\n\
	ldrb r2, [r5, #7]\n\
	cmp r0, r2\n\
	bne _0809CEF0\n\
	adds r0, r4, #1\n\
	movs r1, #0\n\
	strb r0, [r5, #6]\n\
	strb r1, [r5, #7]\n\
	adds r3, #8\n\
_0809CEF0:\n\
	ldrb r1, [r3, #4]\n\
	cmp r1, #0\n\
	bne _0809CEFE\n\
	ldrb r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	subs r3, r3, r0\n\
	strb r1, [r5, #6]\n\
_0809CEFE:\n\
	ldr r6, [r3]\n\
	ldrh r3, [r6]\n\
	mov sl, r3\n\
	adds r6, #2\n\
	movs r4, #0\n\
	mov sb, r4\n\
	cmp sb, sl\n\
	blt _0809CF10\n\
	b _0809D014\n\
_0809CF10:\n\
	ldrh r0, [r6]\n\
	mov r8, r0\n\
	adds r6, #2\n\
	ldrh r1, [r6]\n\
	mov ip, r1\n\
	adds r6, #2\n\
	strh r0, [r7]\n\
	adds r7, #2\n\
	strh r1, [r7]\n\
	adds r7, #2\n\
	ldrh r0, [r6]\n\
	strh r0, [r7]\n\
	adds r6, #2\n\
	adds r7, #2\n\
	ldr r2, _0809CF80 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	mov r4, sb\n\
	adds r3, r0, r4\n\
	ldrb r1, [r5, #0xc]\n\
	cmp r1, #1\n\
	bne _0809CF90\n\
	lsls r4, r3, #3\n\
	ldr r0, _0809CF84 @ =gOamData\n\
	adds r2, r4, r0\n\
	ldrb r3, [r2, #3]\n\
	lsls r0, r3, #0x1b\n\
	lsrs r0, r0, #0x1f\n\
	eors r0, r1\n\
	movs r1, #1\n\
	ands r0, r1\n\
	lsls r0, r0, #4\n\
	movs r1, #0x11\n\
	rsbs r1, r1, #0\n\
	ands r1, r3\n\
	orrs r1, r0\n\
	strb r1, [r2, #3]\n\
	lsrs r1, r1, #6\n\
	ldrb r0, [r2, #1]\n\
	lsrs r0, r0, #6\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldr r2, _0809CF88 @ =0x0868279C\n\
	adds r1, r1, r2\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #3\n\
	add r0, ip\n\
	ldrh r1, [r5]\n\
	subs r2, r1, r0\n\
	ldr r3, _0809CF8C @ =0x000001FF\n\
	ands r2, r3\n\
	ldrh r0, [r5, #2]\n\
	mov r3, r8\n\
	adds r1, r3, r0\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	b _0809CFA6\n\
	.align 2, 0\n\
_0809CF80: .4byte gNextOamSlot\n\
_0809CF84: .4byte gOamData\n\
_0809CF88: .4byte sCutsceneBslFirePal + 0x1780\n\
_0809CF8C: .4byte 0x000001FF\n\
_0809CF90:\n\
	ldrh r0, [r5, #2]\n\
	mov r4, r8\n\
	adds r1, r4, r0\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	ldrh r0, [r5]\n\
	mov r4, ip\n\
	adds r2, r4, r0\n\
	ldr r0, _0809D030 @ =0x000001FF\n\
	ands r2, r0\n\
	lsls r4, r3, #3\n\
_0809CFA6:\n\
	ldr r0, _0809D034 @ =gOamData\n\
	adds r3, r4, r0\n\
	strb r1, [r3]\n\
	ldr r1, _0809D030 @ =0x000001FF\n\
	ands r2, r1\n\
	ldrh r1, [r3, #2]\n\
	ldr r0, _0809D038 @ =0xFFFFFE00\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strh r0, [r3, #2]\n\
	ldrb r1, [r5, #0xb]\n\
	movs r2, #3\n\
	ands r1, r2\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r3, #5]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, #5]\n\
	lsrs r2, r0, #4\n\
	ldrb r4, [r5, #0xd]\n\
	adds r2, r2, r4\n\
	lsls r2, r2, #4\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3, #5]\n\
	ldrh r2, [r3, #4]\n\
	lsls r1, r2, #0x16\n\
	lsrs r1, r1, #0x16\n\
	ldrh r0, [r5, #0xe]\n\
	adds r1, r1, r0\n\
	ldr r4, _0809D03C @ =0x000003FF\n\
	adds r0, r4, #0\n\
	ands r1, r0\n\
	ldr r0, _0809D040 @ =0xFFFFFC00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #4]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #3\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r3, #1]\n\
	subs r0, #0x10\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, #1]\n\
	adds r7, #2\n\
	movs r1, #1\n\
	add sb, r1\n\
	cmp sb, sl\n\
	bge _0809D014\n\
	b _0809CF10\n\
_0809D014:\n\
	ldr r2, _0809D044 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	add r0, sl\n\
	strb r0, [r2]\n\
	ldrb r0, [r5, #7]\n\
	adds r0, #1\n\
	strb r0, [r5, #7]\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D030: .4byte 0x000001FF\n\
_0809D034: .4byte gOamData\n\
_0809D038: .4byte 0xFFFFFE00\n\
_0809D03C: .4byte 0x000003FF\n\
_0809D040: .4byte 0xFFFFFC00\n\
_0809D044: .4byte gNextOamSlot\n\
    .syntax divided\n");
}

/**
 * @brief 9d048 | 54 | Resets a monologue OAM
 * 
 */
void CutsceneMonologueResetOam(u8 slot)
{
    CUTSCENE_DATA.u.monologue.oam[slot].currentAnimationFrame = 0;
    CUTSCENE_DATA.u.monologue.oam[slot].animationDurationCounter = 0;
    CUTSCENE_DATA.u.monologue.oam[slot].stage = 0;
    CUTSCENE_DATA.u.monologue.oam[slot].objMode = 0;
    CUTSCENE_DATA.u.monologue.oam[slot].priority = 0;
    CUTSCENE_DATA.u.monologue.oam[slot].xFlip = 0;
    CUTSCENE_DATA.u.monologue.oam[slot].paletteOffset = 0;
    CUTSCENE_DATA.u.monologue.oam[slot].tileOffset = 0;
}

/**
 * @brief 9d09c | 4 | Empty function
 * 
 */
void unk_9d09c(struct CutsceneMonologueOam* pOam)
{
    return;
}
