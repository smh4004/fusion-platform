#include "special_cutscene.h"
#include "new_file_intro.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "syscalls.h"
#include "text.h"
#include "init_helpers.h"
#include "oam.h"
#include "audio_wrappers.h"
#include "music_wrappers.h"

#include "constants/audio.h"
#include "constants/text.h"

#include "data/generic_data.h"
#include "data/intro_data.h"

/**
 * @brief 97dd0 | d8 | Checks if the monologue ended, and handles waiting and page changes
 * 
 */
boolu32 NewFileIntroCheckMonologueEnded(void)
{
    boolu32 ended;
    const u16* pText;
    const u16* pNext;

    ended = FALSE;
    INTRO_DATA.unk_20C++;
    pText = INTRO_DATA.pText;

    if (*pText == CHAR_TERMINATOR)
    {
        INTRO_DATA.unk_20C = 0;
        INTRO_DATA.unk_213 = 100;
        ended = TRUE;
    }
    else if (*pText == CHAR_NEXT_PAGE_ARROW)
    {
        INTRO_DATA.unk_20C = 0;
        if (INTRO_DATA.unk_218 == 1)
        {
            pNext = &pText[1];
            INTRO_DATA.pText = pNext;
            INTRO_DATA.unk_213 = INTRO_DATA.unk_218;
            if (pText[1] == CHAR_NEW_PAGE)
            {
                INTRO_DATA.unk_218 = 2;
            }
            else if (pText[1] == CHAR_TERMINATOR)
            {
                INTRO_DATA.unk_218 = 3;
            }
            else if (pText[1] == CHAR_NEXT_PAGE_ARROW)
            {
                INTRO_DATA.unk_218 = 4;
                INTRO_DATA.pText = &pNext[1];
                if (pNext[1] == CHAR_TERMINATOR)
                    INTRO_DATA.unk_218 = 3;
            }
            else
            {
                INTRO_DATA.unk_218 = 0;
            }
        }
    }
    else if ((*pText & 0xFF00) == 0xE100)
    {
        if ((*pText & 0xFF) <= INTRO_DATA.unk_20C)
        {
            INTRO_DATA.unk_213 = 1;
            INTRO_DATA.unk_20C = 0;
        }
    }
    else if (INTRO_DATA.unk_20C > 2)
    {
        INTRO_DATA.unk_213 = 1;
        INTRO_DATA.unk_20C = 0;
    }

    return ended;
}

/**
 * @brief 97ea8 | d8 | Checks if the monologue ended, and handles waiting and page changes
 * 
 */
boolu32 EndingCheckMonologueEnded(void)
{
    boolu32 ended;
    const u16* pText;
    const u16* pNext;

    ended = FALSE;
    INTRO_DATA.unk_20C++;
    pText = INTRO_DATA.pText;

    if (*pText == CHAR_TERMINATOR)
    {
        INTRO_DATA.unk_20C = 0;
        INTRO_DATA.unk_213 = 100;
        ended = TRUE;
    }
    else if (*pText == CHAR_NEXT_PAGE_ARROW)
    {
        INTRO_DATA.unk_20C = 0;
        if (INTRO_DATA.unk_218 == 1)
        {
            pNext = &pText[1];
            INTRO_DATA.pText = pNext;
            INTRO_DATA.unk_213 = INTRO_DATA.unk_218;
            if (pText[1] == CHAR_NEW_PAGE)
            {
                INTRO_DATA.unk_218 = 2;
            }
            else if (pText[1] == CHAR_TERMINATOR)
            {
                INTRO_DATA.unk_218 = 3;
            }
            else if (pText[1] == CHAR_NEXT_PAGE_ARROW)
            {
                INTRO_DATA.unk_218 = 4;
                INTRO_DATA.pText = &pNext[1];
                if (pNext[1] == CHAR_TERMINATOR)
                    INTRO_DATA.unk_218 = 3;
            }
            else
            {
                INTRO_DATA.unk_218 = 0;
            }
        }
    }
    else if ((*pText & 0xFF00) == 0xE100)
    {
        if ((*pText & 0xFF) <= INTRO_DATA.unk_20C)
        {
            INTRO_DATA.unk_213 = 1;
            INTRO_DATA.unk_20C = 0;
        }
    }
    else if (INTRO_DATA.unk_20C > 3)
    {
        INTRO_DATA.unk_213 = 1;
        INTRO_DATA.unk_20C = 0;
    }

    return ended;
}

/**
 * @brief 97f80 | 1d8 | Draws the next character of a monologue
 * 
 */
void SpecialCutsceneProcessMonologue(void)
{
    u16 i;
    u32* dst;
    u32 width;

    if (*INTRO_DATA.pText == CHAR_TERMINATOR)
        return;

    if (*INTRO_DATA.pText == CHAR_NEW_LINE)
    {
        for (i = INTRO_DATA.unk_C + 1; i < 28; i++)
            INTRO_DATA.unk_14[i + (INTRO_DATA.unk_E / 2) * 28] |= 0xFF;

        INTRO_DATA.unk_C = 0;
        INTRO_DATA.unk_E += 2;
        INTRO_DATA.pText++;
        INTRO_DATA.unk_212 = 0;
    }
    else if (*INTRO_DATA.pText == CHAR_NEW_PAGE)
    {
        DMA3_FILL_32(0, VRAM_BASE, 0x4800);
        INTRO_DATA.unk_12 = 0;
        INTRO_DATA.unk_10 = 0;
        INTRO_DATA.unk_E = 0;
        INTRO_DATA.unk_C = 0;
        INTRO_DATA.pText++;
        INTRO_DATA.unk_212 = 0;
        DMA3_FILL_32(0, INTRO_DATA.unk_14, 0xFC);
        DMA3_FILL_32(0, &INTRO_DATA.unk_110, 0xFC);
        DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0x4800, 0x800 / 4);
    }
    else if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW)
    {
        INTRO_DATA.unk_C++;
    }
    else if ((*INTRO_DATA.pText & 0xFF00) == 0xE100)
    {
        INTRO_DATA.pText++;
    }
    else
    {
        dst = (u32*)(INTRO_DATA.unk_C * 32 + INTRO_DATA.unk_E * 1024 + VRAM_BASE);
        width = TextGetCharacterWidth(*INTRO_DATA.pText);
        TextDrawCharacter(*INTRO_DATA.pText, dst, width, INTRO_DATA.unk_212, 0);

        if (INTRO_DATA.unk_C < 28)
        {
            INTRO_DATA.unk_14[(INTRO_DATA.unk_E / 2) * 28 + INTRO_DATA.unk_C] = 4;
            INTRO_DATA.unk_212 += width;

            while (INTRO_DATA.unk_212 >= 8)
            {
                INTRO_DATA.unk_212 -= 8;
                INTRO_DATA.unk_C++;
                if (INTRO_DATA.unk_C >= 28)
                    break;

                if (INTRO_DATA.unk_212 != 0)
                    INTRO_DATA.unk_14[(INTRO_DATA.unk_E / 2) * 28 + INTRO_DATA.unk_C] = 4;
            }
        }

        INTRO_DATA.pText++;
    }
}

// 0x08098158
NAKED_FUNCTION
void unk_98158(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	ldr r1, _08098198 @ =gNonGameplayRam\n\
	ldrh r6, [r1, #0x10]\n\
	ldrh r0, [r1, #0x12]\n\
	lsrs r7, r0, #1\n\
	ldrh r0, [r1, #0xe]\n\
	lsrs r0, r0, #1\n\
	str r1, [sp, #8]\n\
	cmp r7, r0\n\
	bls _08098178\n\
	b _0809827C\n\
_08098178:\n\
	str r1, [sp]\n\
_0809817A:\n\
	ldr r2, [sp]\n\
	ldr r0, [r2]\n\
	ldrh r0, [r0]\n\
	movs r3, #0xfc\n\
	lsls r3, r3, #8\n\
	cmp r0, r3\n\
	bne _0809819C\n\
	ldrh r0, [r1, #0xc]\n\
	cmp r0, #0x1b\n\
	bhi _080981B6\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	mov ip, r0\n\
	b _080981BA\n\
	.align 2, 0\n\
_08098198: .4byte gNonGameplayRam\n\
_0809819C:\n\
	ldrh r0, [r1, #0xe]\n\
	lsrs r0, r0, #1\n\
	cmp r7, r0\n\
	bne _080981B6\n\
	ldr r1, [sp]\n\
	ldrh r0, [r1, #0xc]\n\
	movs r2, #0x1c\n\
	mov ip, r2\n\
	cmp r0, #0x1b\n\
	bhi _080981BA\n\
	adds r3, r0, #0\n\
	mov ip, r3\n\
	b _080981BA\n\
_080981B6:\n\
	movs r5, #0x1c\n\
	mov ip, r5\n\
_080981BA:\n\
	adds r0, r7, #1\n\
	str r0, [sp, #4]\n\
	cmp r6, ip\n\
	bhs _08098268\n\
	ldr r1, _08098230 @ =gNonGameplayRam\n\
	mov r8, r1\n\
	lsls r0, r7, #3\n\
	subs r0, r0, r7\n\
	lsls r0, r0, #2\n\
	mov sl, r0\n\
	ldr r2, _08098234 @ =0x00000FFF\n\
	mov sb, r2\n\
_080981D2:\n\
	mov r3, sl\n\
	adds r2, r6, r3\n\
	ldr r5, _08098238 @ =0x03001594\n\
	adds r1, r2, r5\n\
	ldrb r0, [r1]\n\
	cmp r0, #5\n\
	bne _0809825A\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r0, [sp, #8]\n\
	adds r0, #0x14\n\
	adds r2, r2, r0\n\
	ldrb r0, [r2]\n\
	subs r1, r0, #1\n\
	strb r1, [r2]\n\
	lsls r0, r1, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	ble _08098244\n\
	lsls r2, r6, #1\n\
	lsls r0, r7, #7\n\
	adds r2, r2, r0\n\
	ldr r0, _0809823C @ =0x06004842\n\
	adds r0, r2, r0\n\
	str r0, [sp, #0xc]\n\
	ldr r1, _08098240 @ =0x06004882\n\
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
	b _0809825E\n\
	.align 2, 0\n\
_08098230: .4byte gNonGameplayRam\n\
_08098234: .4byte 0x00000FFF\n\
_08098238: .4byte 0x03001594\n\
_0809823C: .4byte 0x06004842\n\
_08098240: .4byte 0x06004882\n\
_08098244:\n\
	cmp r0, #0\n\
	bne _08098252\n\
	mov r5, r8\n\
	strh r6, [r5, #0x10]\n\
	lsls r0, r7, #1\n\
	strh r0, [r5, #0x12]\n\
	b _0809825E\n\
_08098252:\n\
	movs r0, #0xff\n\
	orrs r1, r0\n\
	strb r1, [r2]\n\
	b _08098268\n\
_0809825A:\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0809825E:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	cmp r6, ip\n\
	blo _080981D2\n\
_08098268:\n\
	movs r6, #0\n\
	ldr r1, [sp, #4]\n\
	lsls r0, r1, #0x10\n\
	lsrs r7, r0, #0x10\n\
	ldr r1, [sp, #8]\n\
	ldrh r0, [r1, #0xe]\n\
	lsrs r0, r0, #1\n\
	cmp r7, r0\n\
	bhi _0809827C\n\
	b _0809817A\n\
_0809827C:\n\
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

// 0x0809828C
NAKED_FUNCTION
void EndingProcessAdamText(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #8\n\
	movs r7, #0\n\
	ldr r5, _080982E8 @ =gNonGameplayRam\n\
	movs r0, #0x83\n\
	lsls r0, r0, #2\n\
	adds r6, r5, r0\n\
	ldrh r0, [r6]\n\
	adds r2, r0, #1\n\
	movs r1, #0\n\
	mov sb, r1\n\
	strh r2, [r6]\n\
	ldr r3, [r5]\n\
	ldrh r4, [r3]\n\
	adds r1, r4, #0\n\
	movs r0, #0xff\n\
	lsls r0, r0, #8\n\
	mov ip, r0\n\
	cmp r1, ip\n\
	bne _080982FC\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xf\n\
	bhi _080982C4\n\
	b _08098492\n\
_080982C4:\n\
	strh r7, [r6]\n\
	str r7, [sp, #4]\n\
	ldr r1, _080982EC @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _080982F0 @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _080982F4 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	strh r7, [r5, #0xe]\n\
	strh r7, [r5, #0xc]\n\
	ldr r1, _080982F8 @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sb\n\
	strb r1, [r0]\n\
	movs r7, #1\n\
	b _08098492\n\
	.align 2, 0\n\
_080982E8: .4byte gNonGameplayRam\n\
_080982EC: .4byte 0x040000D4\n\
_080982F0: .4byte 0x0600D000\n\
_080982F4: .4byte 0x85000400\n\
_080982F8: .4byte 0x00000212\n\
_080982FC:\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0809836C\n\
	ldrh r0, [r5, #0xe]\n\
	cmp r0, #1\n\
	bhi _0809832C\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	bhi _08098314\n\
	b _08098492\n\
_08098314:\n\
	strh r7, [r6]\n\
	movs r0, #2\n\
	strh r0, [r5, #0xe]\n\
	strh r7, [r5, #0xc]\n\
	ldr r1, _08098328 @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sb\n\
	strb r1, [r0]\n\
	b _08098408\n\
	.align 2, 0\n\
_08098328: .4byte 0x00000212\n\
_0809832C:\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x7d\n\
	bhi _08098336\n\
	b _08098492\n\
_08098336:\n\
	strh r7, [r6]\n\
	strh r7, [r5, #0xe]\n\
	strh r7, [r5, #0xc]\n\
	ldr r1, _0809835C @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sb\n\
	strb r1, [r0]\n\
	adds r0, r3, #2\n\
	str r0, [r5]\n\
	str r7, [sp, #4]\n\
	ldr r1, _08098360 @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _08098364 @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _08098368 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	b _08098492\n\
	.align 2, 0\n\
_0809835C: .4byte 0x00000212\n\
_08098360: .4byte 0x040000D4\n\
_08098364: .4byte 0x0600D000\n\
_08098368: .4byte 0x85000400\n\
_0809836C:\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #8\n\
	mov r8, r0\n\
	cmp r1, r8\n\
	bne _080983B8\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xf\n\
	bhi _08098380\n\
	b _08098492\n\
_08098380:\n\
	strh r7, [r6]\n\
	str r7, [sp, #4]\n\
	ldr r1, _080983A8 @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _080983AC @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _080983B0 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	strh r7, [r5, #0xe]\n\
	strh r7, [r5, #0xc]\n\
	adds r0, r3, #2\n\
	str r0, [r5]\n\
	ldr r1, _080983B4 @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sb\n\
	strb r1, [r0]\n\
	b _08098492\n\
	.align 2, 0\n\
_080983A8: .4byte 0x040000D4\n\
_080983AC: .4byte 0x0600D000\n\
_080983B0: .4byte 0x85000400\n\
_080983B4: .4byte 0x00000212\n\
_080983B8:\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _080983EE\n\
	strh r7, [r6]\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #1\n\
	bne _08098492\n\
	adds r0, r3, #2\n\
	str r0, [r5]\n\
	ldrh r0, [r3, #2]\n\
	cmp r0, r8\n\
	bne _080983DE\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	b _08098492\n\
_080983DE:\n\
	cmp r0, ip\n\
	bne _080983E8\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	b _08098492\n\
_080983E8:\n\
	mov r0, sb\n\
	strb r0, [r1]\n\
	b _08098492\n\
_080983EE:\n\
	mov r0, ip\n\
	ands r0, r4\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	bne _0809840E\n\
	movs r1, #0xff\n\
	ands r1, r4\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r1, r0\n\
	bhi _08098492\n\
	strh r7, [r6]\n\
_08098408:\n\
	adds r0, r3, #2\n\
	str r0, [r5]\n\
	b _08098492\n\
_0809840E:\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	bls _08098492\n\
	strh r7, [r6]\n\
	ldrh r4, [r5, #0xc]\n\
	lsls r4, r4, #5\n\
	ldrh r0, [r5, #0xe]\n\
	lsls r0, r0, #0xa\n\
	adds r4, r4, r0\n\
	ldr r1, _080984A4 @ =0x0600D000\n\
	adds r4, r4, r1\n\
	ldrh r0, [r3]\n\
	bl TextGetCharacterWidth\n\
	mov r8, r0\n\
	ldr r0, [r5]\n\
	ldrh r0, [r0]\n\
	mov r1, r8\n\
	lsls r2, r1, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldr r1, _080984A8 @ =0x00000212\n\
	adds r6, r5, r1\n\
	ldrb r3, [r6]\n\
	str r7, [sp]\n\
	adds r1, r4, #0\n\
	bl TextDrawCharacter\n\
	ldr r1, [r5]\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x40\n\
	beq _08098454\n\
	movs r1, #1\n\
	bl PlayCharacterAppearingSound\n\
_08098454:\n\
	ldrh r0, [r5, #0xc]\n\
	adds r4, r5, #0\n\
	cmp r0, #0x1f\n\
	bhi _0809848C\n\
	ldrb r0, [r6]\n\
	add r0, r8\n\
	strb r0, [r6]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _0809848C\n\
	adds r3, r4, #0\n\
	adds r2, r6, #0\n\
_0809846E:\n\
	ldrb r0, [r2]\n\
	adds r1, r0, #0\n\
	subs r1, #8\n\
	strb r1, [r2]\n\
	ldrh r0, [r3, #0xc]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xc]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x1f\n\
	bhi _0809848C\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bhi _0809846E\n\
_0809848C:\n\
	ldr r0, [r4]\n\
	adds r0, #2\n\
	str r0, [r4]\n\
_08098492:\n\
	adds r0, r7, #0\n\
	add sp, #8\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080984A4: .4byte 0x0600D000\n\
_080984A8: .4byte 0x00000212\n\
    .syntax divided\n");
}

// 0x080984AC
NAKED_FUNCTION
void IntroProcessText(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	movs r0, #0\n\
	mov r8, r0\n\
	ldr r5, _08098514 @ =gNonGameplayRam\n\
	movs r1, #0x83\n\
	lsls r1, r1, #2\n\
	adds r7, r5, r1\n\
	ldrh r0, [r7]\n\
	adds r2, r0, #1\n\
	movs r0, #0\n\
	mov sl, r0\n\
	strh r2, [r7]\n\
	ldr r6, [r5]\n\
	ldrh r4, [r6]\n\
	adds r3, r4, #0\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	mov ip, r1\n\
	cmp r3, ip\n\
	bne _08098528\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xc\n\
	bhi _080984E8\n\
	b _080986D2\n\
_080984E8:\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	mov r1, r8\n\
	str r1, [sp, #4]\n\
	ldr r1, _08098518 @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _0809851C @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _08098520 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	mov r1, r8\n\
	strh r1, [r5, #0xe]\n\
	strh r1, [r5, #0xc]\n\
	ldr r1, _08098524 @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sl\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	mov r8, r0\n\
	b _080986D2\n\
	.align 2, 0\n\
_08098514: .4byte gNonGameplayRam\n\
_08098518: .4byte 0x040000D4\n\
_0809851C: .4byte 0x0600D000\n\
_08098520: .4byte 0x85000400\n\
_08098524: .4byte 0x00000212\n\
_08098528:\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r3, r0\n\
	bne _0809859C\n\
	ldrh r0, [r5, #0xe]\n\
	cmp r0, #1\n\
	bhi _08098558\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #2\n\
	bhi _08098540\n\
	b _080986D2\n\
_08098540:\n\
	mov r1, r8\n\
	strh r1, [r7]\n\
	movs r0, #2\n\
	strh r0, [r5, #0xe]\n\
	strh r1, [r5, #0xc]\n\
	ldr r1, _08098554 @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sl\n\
	strb r1, [r0]\n\
	b _08098654\n\
	.align 2, 0\n\
_08098554: .4byte 0x00000212\n\
_08098558:\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x7a\n\
	bhi _08098562\n\
	b _080986D2\n\
_08098562:\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	strh r0, [r5, #0xe]\n\
	strh r0, [r5, #0xc]\n\
	ldr r1, _0809858C @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sl\n\
	strb r1, [r0]\n\
	adds r0, r6, #2\n\
	str r0, [r5]\n\
	mov r0, r8\n\
	str r0, [sp, #4]\n\
	ldr r1, _08098590 @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _08098594 @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _08098598 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	b _080986D2\n\
	.align 2, 0\n\
_0809858C: .4byte 0x00000212\n\
_08098590: .4byte 0x040000D4\n\
_08098594: .4byte 0x0600D000\n\
_08098598: .4byte 0x85000400\n\
_0809859C:\n\
	movs r1, #0xfd\n\
	lsls r1, r1, #8\n\
	mov sb, r1\n\
	cmp r3, sb\n\
	bne _080985EC\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xc\n\
	bhi _080985B0\n\
	b _080986D2\n\
_080985B0:\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	mov r1, r8\n\
	str r1, [sp, #4]\n\
	ldr r1, _080985DC @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _080985E0 @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _080985E4 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	mov r1, r8\n\
	strh r1, [r5, #0xe]\n\
	strh r1, [r5, #0xc]\n\
	adds r0, r6, #2\n\
	str r0, [r5]\n\
	ldr r1, _080985E8 @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sl\n\
	strb r1, [r0]\n\
	b _080986D2\n\
	.align 2, 0\n\
_080985DC: .4byte 0x040000D4\n\
_080985E0: .4byte 0x0600D000\n\
_080985E4: .4byte 0x85000400\n\
_080985E8: .4byte 0x00000212\n\
_080985EC:\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r3, r0\n\
	bne _08098638\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r2, r5, r1\n\
	ldrb r0, [r2]\n\
	cmp r0, #1\n\
	bne _080986D2\n\
	adds r1, r6, #2\n\
	str r1, [r5]\n\
	ldrh r0, [r6, #2]\n\
	cmp r0, sb\n\
	bne _08098614\n\
	movs r0, #2\n\
	strb r0, [r2]\n\
	b _080986D2\n\
_08098614:\n\
	cmp r0, ip\n\
	beq _08098626\n\
	cmp r0, r3\n\
	bne _08098632\n\
	adds r0, r1, #2\n\
	str r0, [r5]\n\
	ldrh r0, [r1, #2]\n\
	cmp r0, ip\n\
	bne _0809862C\n\
_08098626:\n\
	movs r0, #3\n\
	strb r0, [r2]\n\
	b _080986D2\n\
_0809862C:\n\
	movs r0, #4\n\
	strb r0, [r2]\n\
	b _080986D2\n\
_08098632:\n\
	mov r0, sl\n\
	strb r0, [r2]\n\
	b _080986D2\n\
_08098638:\n\
	mov r0, ip\n\
	ands r0, r4\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	bne _0809865A\n\
	movs r1, #0xff\n\
	ands r1, r4\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r1, r0\n\
	bhi _080986D2\n\
	mov r1, r8\n\
	strh r1, [r7]\n\
_08098654:\n\
	adds r0, r6, #2\n\
	str r0, [r5]\n\
	b _080986D2\n\
_0809865A:\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #2\n\
	bls _080986D2\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	ldrh r4, [r5, #0xc]\n\
	lsls r4, r4, #5\n\
	ldrh r0, [r5, #0xe]\n\
	lsls r0, r0, #0xa\n\
	adds r4, r4, r0\n\
	ldr r1, _080986E4 @ =0x0600D000\n\
	adds r4, r4, r1\n\
	ldrh r0, [r6]\n\
	bl TextGetCharacterWidth\n\
	adds r7, r0, #0\n\
	ldr r0, [r5]\n\
	ldrh r0, [r0]\n\
	lsls r2, r7, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldr r1, _080986E8 @ =0x00000212\n\
	adds r6, r5, r1\n\
	ldrb r3, [r6]\n\
	mov r1, r8\n\
	str r1, [sp]\n\
	adds r1, r4, #0\n\
	bl TextDrawCharacter\n\
	ldrh r0, [r5, #0xc]\n\
	cmp r0, #0x1f\n\
	bhi _080986CA\n\
	ldrb r0, [r6]\n\
	adds r0, r0, r7\n\
	strb r0, [r6]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _080986CA\n\
	adds r3, r5, #0\n\
	adds r2, r6, #0\n\
_080986AC:\n\
	ldrb r0, [r2]\n\
	adds r1, r0, #0\n\
	subs r1, #8\n\
	strb r1, [r2]\n\
	ldrh r0, [r3, #0xc]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xc]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x1f\n\
	bhi _080986CA\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bhi _080986AC\n\
_080986CA:\n\
	ldr r1, _080986EC @ =gNonGameplayRam\n\
	ldr r0, [r1]\n\
	adds r0, #2\n\
	str r0, [r1]\n\
_080986D2:\n\
	mov r0, r8\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080986E4: .4byte 0x0600D000\n\
_080986E8: .4byte 0x00000212\n\
_080986EC: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x080986F0
NAKED_FUNCTION
void NewFileIntroProcessAdamText(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	movs r0, #0\n\
	mov r8, r0\n\
	ldr r5, _08098758 @ =gNonGameplayRam\n\
	movs r1, #0x83\n\
	lsls r1, r1, #2\n\
	adds r7, r5, r1\n\
	ldrh r0, [r7]\n\
	adds r2, r0, #1\n\
	movs r0, #0\n\
	mov sl, r0\n\
	strh r2, [r7]\n\
	ldr r6, [r5]\n\
	ldrh r4, [r6]\n\
	adds r3, r4, #0\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	mov ip, r1\n\
	cmp r3, ip\n\
	bne _0809876C\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xc\n\
	bhi _0809872C\n\
	b _08098924\n\
_0809872C:\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	mov r1, r8\n\
	str r1, [sp, #4]\n\
	ldr r1, _0809875C @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _08098760 @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _08098764 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	mov r1, r8\n\
	strh r1, [r5, #0xe]\n\
	strh r1, [r5, #0xc]\n\
	ldr r1, _08098768 @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sl\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	mov r8, r0\n\
	b _08098924\n\
	.align 2, 0\n\
_08098758: .4byte gNonGameplayRam\n\
_0809875C: .4byte 0x040000D4\n\
_08098760: .4byte 0x0600D000\n\
_08098764: .4byte 0x85000400\n\
_08098768: .4byte 0x00000212\n\
_0809876C:\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r3, r0\n\
	bne _080987E0\n\
	ldrh r0, [r5, #0xe]\n\
	cmp r0, #1\n\
	bhi _0809879C\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #2\n\
	bhi _08098784\n\
	b _08098924\n\
_08098784:\n\
	mov r1, r8\n\
	strh r1, [r7]\n\
	movs r0, #2\n\
	strh r0, [r5, #0xe]\n\
	strh r1, [r5, #0xc]\n\
	ldr r1, _08098798 @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sl\n\
	strb r1, [r0]\n\
	b _08098898\n\
	.align 2, 0\n\
_08098798: .4byte 0x00000212\n\
_0809879C:\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x7a\n\
	bhi _080987A6\n\
	b _08098924\n\
_080987A6:\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	strh r0, [r5, #0xe]\n\
	strh r0, [r5, #0xc]\n\
	ldr r1, _080987D0 @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sl\n\
	strb r1, [r0]\n\
	adds r0, r6, #2\n\
	str r0, [r5]\n\
	mov r0, r8\n\
	str r0, [sp, #4]\n\
	ldr r1, _080987D4 @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _080987D8 @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _080987DC @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	b _08098924\n\
	.align 2, 0\n\
_080987D0: .4byte 0x00000212\n\
_080987D4: .4byte 0x040000D4\n\
_080987D8: .4byte 0x0600D000\n\
_080987DC: .4byte 0x85000400\n\
_080987E0:\n\
	movs r1, #0xfd\n\
	lsls r1, r1, #8\n\
	mov sb, r1\n\
	cmp r3, sb\n\
	bne _08098830\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xc\n\
	bhi _080987F4\n\
	b _08098924\n\
_080987F4:\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	mov r1, r8\n\
	str r1, [sp, #4]\n\
	ldr r1, _08098820 @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _08098824 @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _08098828 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	mov r1, r8\n\
	strh r1, [r5, #0xe]\n\
	strh r1, [r5, #0xc]\n\
	adds r0, r6, #2\n\
	str r0, [r5]\n\
	ldr r1, _0809882C @ =0x00000212\n\
	adds r0, r5, r1\n\
	mov r1, sl\n\
	strb r1, [r0]\n\
	b _08098924\n\
	.align 2, 0\n\
_08098820: .4byte 0x040000D4\n\
_08098824: .4byte 0x0600D000\n\
_08098828: .4byte 0x85000400\n\
_0809882C: .4byte 0x00000212\n\
_08098830:\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r3, r0\n\
	bne _0809887C\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r2, r5, r1\n\
	ldrb r0, [r2]\n\
	cmp r0, #1\n\
	bne _08098924\n\
	adds r1, r6, #2\n\
	str r1, [r5]\n\
	ldrh r0, [r6, #2]\n\
	cmp r0, sb\n\
	bne _08098858\n\
	movs r0, #2\n\
	strb r0, [r2]\n\
	b _08098924\n\
_08098858:\n\
	cmp r0, ip\n\
	beq _0809886A\n\
	cmp r0, r3\n\
	bne _08098876\n\
	adds r0, r1, #2\n\
	str r0, [r5]\n\
	ldrh r0, [r1, #2]\n\
	cmp r0, ip\n\
	bne _08098870\n\
_0809886A:\n\
	movs r0, #3\n\
	strb r0, [r2]\n\
	b _08098924\n\
_08098870:\n\
	movs r0, #4\n\
	strb r0, [r2]\n\
	b _08098924\n\
_08098876:\n\
	mov r0, sl\n\
	strb r0, [r2]\n\
	b _08098924\n\
_0809887C:\n\
	mov r0, ip\n\
	ands r0, r4\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	bne _0809889E\n\
	movs r1, #0xff\n\
	ands r1, r4\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r1, r0\n\
	bhi _08098924\n\
	mov r1, r8\n\
	strh r1, [r7]\n\
_08098898:\n\
	adds r0, r6, #2\n\
	str r0, [r5]\n\
	b _08098924\n\
_0809889E:\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #2\n\
	bls _08098924\n\
	mov r0, r8\n\
	strh r0, [r7]\n\
	ldrh r4, [r5, #0xc]\n\
	lsls r4, r4, #5\n\
	ldrh r0, [r5, #0xe]\n\
	lsls r0, r0, #0xa\n\
	adds r4, r4, r0\n\
	ldr r1, _08098938 @ =0x0600D000\n\
	adds r4, r4, r1\n\
	ldrh r0, [r6]\n\
	bl TextGetCharacterWidth\n\
	adds r7, r0, #0\n\
	ldr r0, [r5]\n\
	ldrh r0, [r0]\n\
	lsls r2, r7, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldr r1, _0809893C @ =0x00000212\n\
	adds r6, r5, r1\n\
	ldrb r3, [r6]\n\
	mov r1, r8\n\
	str r1, [sp]\n\
	adds r1, r4, #0\n\
	bl TextDrawCharacter\n\
	ldr r1, [r5]\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x40\n\
	beq _080988E6\n\
	movs r1, #1\n\
	bl PlayCharacterAppearingSound\n\
_080988E6:\n\
	ldrh r0, [r5, #0xc]\n\
	adds r4, r5, #0\n\
	cmp r0, #0x1f\n\
	bhi _0809891E\n\
	ldrb r0, [r6]\n\
	adds r0, r0, r7\n\
	strb r0, [r6]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _0809891E\n\
	adds r3, r4, #0\n\
	adds r2, r6, #0\n\
_08098900:\n\
	ldrb r0, [r2]\n\
	adds r1, r0, #0\n\
	subs r1, #8\n\
	strb r1, [r2]\n\
	ldrh r0, [r3, #0xc]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xc]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x1f\n\
	bhi _0809891E\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bhi _08098900\n\
_0809891E:\n\
	ldr r0, [r4]\n\
	adds r0, #2\n\
	str r0, [r4]\n\
_08098924:\n\
	mov r0, r8\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08098938: .4byte 0x0600D000\n\
_0809893C: .4byte 0x00000212\n\
    .syntax divided\n");
}

/**
 * @brief 98940 | 40 | Transfers several 0x400 byte blocks with DMA 3
 * 
 */
void Dma3Transfer_Unused1(void* src, void* dst, u32 size, u16 count)
{
    u16 i;

    size <<= 21;

    for (i = 0; i < count; i++)
    {
        DMA_SET(3, src, dst, C_32_2_16(DMA_ENABLE | DMA_32BIT, size >> 18));
        src += 0x400;
        dst += 0x400;
    }
}

/**
 * @brief 98980 | 3c | Transfers several 0x40 byte blocks with DMA 3
 * 
 */
void Dma3Transfer_Unused2(void* src, void* dst, u32 size, u16 count)
{
    u16 i;

    size <<= 17;
    for (i = 0; i < count; i++)
    {
        DMA_SET(3, src, dst, C_32_2_16(DMA_ENABLE, size >> 17));
        src += 0x40;
        dst += 0x40;
    }
}

/**
 * @brief 989bc | 48 | Clears several 0x400 byte blocks with DMA 3
 * 
 */
void Dma3Clear_Unused(void* dst, u32 size, u16 count)
{
    u16 i;
    vu32 zero;

    size <<= 21;

    for (i = 0; i < count; i++)
    {
        zero = 0;
        DMA_SET(3, &zero, dst, C_32_2_16(DMA_ENABLE | DMA_SRC_FIXED | DMA_32BIT, size >> 18));
        dst += 0x400;
    }
}

// 0x08098A04
NAKED_FUNCTION
void unk_98a04(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	movs r3, #0\n\
	ldr r0, _08098A48 @ =gNonGameplayRam\n\
	mov ip, r0\n\
	movs r7, #0x88\n\
	lsls r7, r7, #1\n\
	add r7, ip\n\
	movs r6, #0x96\n\
	lsls r6, r6, #1\n\
	add r6, ip\n\
	movs r5, #0xb2\n\
	lsls r5, r5, #1\n\
	add r5, ip\n\
	movs r4, #0xa4\n\
	lsls r4, r4, #1\n\
	add r4, ip\n\
_08098A24:\n\
	adds r0, r3, r7\n\
	adds r1, r3, r6\n\
	ldrb r2, [r1]\n\
	ldrb r0, [r0]\n\
	cmp r0, r2\n\
	bhi _08098A50\n\
	movs r2, #0\n\
	strb r2, [r1]\n\
	adds r1, r3, r5\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r1, r3, r4\n\
	ldrb r0, [r1]\n\
	cmp r0, #0x25\n\
	bhi _08098A4C\n\
	adds r0, #1\n\
	b _08098A52\n\
	.align 2, 0\n\
_08098A48: .4byte gNonGameplayRam\n\
_08098A4C:\n\
	strb r2, [r1]\n\
	b _08098A54\n\
_08098A50:\n\
	adds r0, r2, #1\n\
_08098A52:\n\
	strb r0, [r1]\n\
_08098A54:\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #3\n\
	bls _08098A24\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	movs r2, #0x9b\n\
	lsls r2, r2, #1\n\
	add r2, ip\n\
	ldrb r1, [r2]\n\
	ldrb r0, [r0]\n\
	cmp r0, r1\n\
	bhi _08098A96\n\
	movs r3, #0\n\
	strb r3, [r2]\n\
	movs r1, #0xb7\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	movs r1, #0xa9\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	ldrb r0, [r1]\n\
	cmp r0, #0xe\n\
	bhi _08098A92\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _08098A9A\n\
_08098A92:\n\
	strb r3, [r1]\n\
	b _08098A9A\n\
_08098A96:\n\
	adds r0, r1, #1\n\
	strb r0, [r2]\n\
_08098A9A:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x08098AA0
NAKED_FUNCTION
void NewFileIntroSamusGettingCuredSetupWindow(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	ldr r1, _08098AE4 @ =0x040000D4\n\
	ldr r0, _08098AE8 @ =0x02001000\n\
	str r0, [r1]\n\
	ldr r0, _08098AEC @ =0x02002000\n\
	str r0, [r1, #4]\n\
	ldr r0, _08098AF0 @ =0x84000058\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r1, _08098AF4 @ =gNonGameplayRam\n\
	ldr r2, _08098AF8 @ =0x000001F5\n\
	adds r0, r1, r2\n\
	ldrb r2, [r0]\n\
	ldr r3, _08098AFC @ =0x000001F3\n\
	adds r0, r1, r3\n\
	ldrb r3, [r0]\n\
	subs r0, r2, r3\n\
	lsls r0, r0, #0x10\n\
	adds r7, r2, r3\n\
	lsrs r2, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	bge _08098B00\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	lsls r0, r3, #1\n\
	movs r2, #0\n\
	cmp r5, r0\n\
	ble _08098B02\n\
	movs r2, #0xa1\n\
	b _08098B02\n\
	.align 2, 0\n\
_08098AE4: .4byte 0x040000D4\n\
_08098AE8: .4byte 0x02001000\n\
_08098AEC: .4byte 0x02002000\n\
_08098AF0: .4byte 0x84000058\n\
_08098AF4: .4byte gNonGameplayRam\n\
_08098AF8: .4byte 0x000001F5\n\
_08098AFC: .4byte 0x000001F3\n\
_08098B00:\n\
	movs r5, #0\n\
_08098B02:\n\
	cmp r7, #0x9f\n\
	ble _08098B08\n\
	movs r7, #0xa0\n\
_08098B08:\n\
	ldr r0, _08098BBC @ =0x083E3294\n\
	ldr r6, _08098BC0 @ =0x000001F3\n\
	adds r1, r1, r6\n\
	ldrb r1, [r1]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	mov ip, r1\n\
	ldr r4, _08098BC4 @ =0x02001000\n\
	movs r6, #0\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	lsls r1, r7, #0x10\n\
	cmp r6, r0\n\
	bge _08098B3E\n\
	movs r2, #0\n\
	adds r3, r0, #0\n\
_08098B2A:\n\
	strh r2, [r4]\n\
	adds r4, #2\n\
	lsls r0, r6, #0x10\n\
	movs r6, #0x80\n\
	lsls r6, r6, #9\n\
	adds r0, r0, r6\n\
	lsrs r6, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, r3\n\
	blt _08098B2A\n\
_08098B3E:\n\
	lsls r0, r6, #0x10\n\
	asrs r3, r1, #0x10\n\
	cmp r0, r1\n\
	bgt _08098B98\n\
	ldr r0, _08098BC8 @ =0x03001678\n\
	mov r8, r0\n\
	adds r7, r3, #0\n\
_08098B4C:\n\
	mov r1, r8\n\
	ldrb r2, [r1]\n\
	lsls r0, r5, #2\n\
	add r0, ip\n\
	ldrh r1, [r0, #2]\n\
	adds r1, r2, r1\n\
	lsls r1, r1, #0x10\n\
	ldrh r0, [r0]\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	lsrs r3, r1, #0x10\n\
	cmp r1, #0\n\
	bge _08098B6A\n\
	movs r3, #0\n\
_08098B6A:\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xf0\n\
	ble _08098B74\n\
	movs r2, #0xf0\n\
_08098B74:\n\
	lsls r1, r3, #0x10\n\
	asrs r1, r1, #8\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r4, #2\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	lsls r0, r6, #0x10\n\
	movs r2, #0x80\n\
	lsls r2, r2, #9\n\
	adds r0, r0, r2\n\
	lsrs r6, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, r7\n\
	ble _08098B4C\n\
_08098B98:\n\
	lsls r1, r6, #0x10\n\
	asrs r0, r1, #0x10\n\
	cmp r0, #0x9f\n\
	bgt _08098BB2\n\
	movs r2, #0\n\
_08098BA2:\n\
	strh r2, [r4]\n\
	adds r4, #2\n\
	movs r3, #0x80\n\
	lsls r3, r3, #9\n\
	adds r1, r1, r3\n\
	asrs r0, r1, #0x10\n\
	cmp r0, #0x9f\n\
	ble _08098BA2\n\
_08098BB2:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08098BBC: .4byte 0x083E3294\n\
_08098BC0: .4byte 0x000001F3\n\
_08098BC4: .4byte 0x02001000\n\
_08098BC8: .4byte 0x03001678\n\
    .syntax divided\n");
}

/**
 * @brief 98bcc | 20 | Fades in a special cutscene
 * 
 */
void SpecialCutsceneFadeIn(void)
{
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    if (gWrittenToBldy != 0)
        gWrittenToBldy--;
}

/**
 * @brief 98bec | 20 | Fades out a special cutscene
 * 
 */
void SpecialCutsceneFadOut(void)
{
    SpecialCutsceneProcessOam();
    SpecialCutsceneDrawAllOam();
    if (gWrittenToBldy < BLDY_MAX_VALUE)
        gWrittenToBldy++;
}

/**
 * @brief 98c0c | 2c | Processes the new file intro text cursor
 * 
 */
void NewFileIntroProcessTextCursor(struct SpecialCutsceneOam* pOam)
{
    if (*INTRO_DATA.pText == CHAR_NEXT_PAGE_ARROW)
    {
        pOam->xPosition = 235;
        pOam->yPosition = 152;
    }
    else
    {
        pOam->xPosition = 260;
    }
}

/**
 * @brief 98c38 | 34 | Disables the drawing of every special cutscene OAM
 * 
 */
void SpecialCutsceneClearOam(void)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(INTRO_DATA.oam); i++)
        INTRO_DATA.oam[i].unk_18_0 = 0;
}

/**
 * @brief 98c6c | 3c | Enables the drawing of every active special cutscene OAM
 * 
 */
void SpecialCutsceneEnableOam(void)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(INTRO_DATA.oam); i++)
    {
        if (INTRO_DATA.oam[i].type != 0)
            INTRO_DATA.oam[i].unk_18_0 = 1;
    }
}

/**
 * @brief 98ca8 | 4c | Destroys the first special cutscene OAM of a type
 * 
 */
void SpecialCutsceneDestroyOamOfType(u8 type)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(INTRO_DATA.oam); i++)
    {
        if (INTRO_DATA.oam[i].type == type)
        {
            INTRO_DATA.oam[i].type = 0;
            INTRO_DATA.oam[i].unk_18_0 = 0;
            break;
        }
    }
}

/**
 * @brief 98cf4 | 58 | Processes every special cutscene OAM
 * 
 */
void SpecialCutsceneProcessOam(void)
{
    u8 i;

    INTRO_DATA.unk_215 = 0;
    for (i = 0; i < ARRAY_SIZE(INTRO_DATA.oam); i++)
    {
        if (INTRO_DATA.oam[i].type != 0)
        {
            ((void (*)(struct SpecialCutsceneOam*))INTRO_DATA.oam[i].pFunction)(&INTRO_DATA.oam[i]);
            INTRO_DATA.unk_215++;
        }
    }
}

/**
 * @brief 98d4c | 54 | Draws every special cutscene OAM
 * 
 */
void SpecialCutsceneDrawAllOam(void)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(INTRO_DATA.oam); i++)
    {
        if (INTRO_DATA.oam[i].unk_18_0)
            SpecialCutsceneDrawOam(&INTRO_DATA.oam[i]);
    }

    ResetFreeOam();
    gNextOamSlot = 0;
    gUnk_3001238 = 0;
}

// 0x08098DA0
NAKED_FUNCTION
void SpecialCutsceneDrawOam(struct SpecialCutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x38\n\
	mov sb, r0\n\
	ldr r3, _08098E9C @ =gNextOamSlot\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #3\n\
	ldr r2, _08098EA0 @ =gOamData\n\
	adds r0, r0, r2\n\
	mov ip, r0\n\
	mov r0, sb\n\
	ldrb r5, [r0, #0x11]\n\
	lsls r1, r5, #3\n\
	ldr r0, [r0, #0x1c]\n\
	adds r4, r0, r1\n\
	ldrb r0, [r4, #4]\n\
	mov r1, sb\n\
	ldrb r1, [r1, #0x12]\n\
	cmp r0, r1\n\
	bne _08098DDA\n\
	adds r0, r5, #1\n\
	movs r1, #0\n\
	mov r2, sb\n\
	strb r0, [r2, #0x11]\n\
	strb r1, [r2, #0x12]\n\
	adds r4, #8\n\
_08098DDA:\n\
	ldrb r1, [r4, #4]\n\
	cmp r1, #0\n\
	bne _08098DEA\n\
	mov r3, sb\n\
	ldrb r0, [r3, #0x11]\n\
	lsls r0, r0, #3\n\
	subs r4, r4, r0\n\
	strb r1, [r3, #0x11]\n\
_08098DEA:\n\
	ldr r4, [r4]\n\
	mov sl, r4\n\
	ldrh r4, [r4]\n\
	str r4, [sp, #0x20]\n\
	movs r5, #2\n\
	add sl, r5\n\
	mov r0, sb\n\
	ldrb r1, [r0, #0x18]\n\
	lsls r0, r1, #0x1d\n\
	lsrs r0, r0, #0x1e\n\
	cmp r0, #0\n\
	beq _08098E04\n\
	b _08098F78\n\
_08098E04:\n\
	movs r1, #0\n\
	str r1, [sp, #0x1c]\n\
	cmp r1, r4\n\
	blt _08098E10\n\
	bl _0809975A\n\
_08098E10:\n\
	ldr r2, _08098EA4 @ =0x000001FF\n\
	adds r7, r2, #0\n\
	movs r3, #3\n\
	mov r8, r3\n\
_08098E18:\n\
	mov r4, sl\n\
	ldrh r6, [r4]\n\
	movs r5, #2\n\
	add sl, r5\n\
	mov r0, sl\n\
	ldrh r5, [r0]\n\
	movs r1, #2\n\
	add sl, r1\n\
	mov r2, ip\n\
	strh r6, [r2]\n\
	add ip, r1\n\
	mov r3, ip\n\
	strh r5, [r3]\n\
	add ip, r1\n\
	mov r4, sl\n\
	ldrh r0, [r4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	movs r2, #2\n\
	add sl, r2\n\
	add ip, r2\n\
	ldr r3, _08098E9C @ =gNextOamSlot\n\
	ldrb r0, [r3]\n\
	ldr r4, [sp, #0x1c]\n\
	adds r3, r0, r4\n\
	mov r1, sb\n\
	ldrb r0, [r1, #0x18]\n\
	lsls r0, r0, #0x19\n\
	lsrs r1, r0, #0x1f\n\
	cmp r1, #1\n\
	bne _08098EAC\n\
	lsls r4, r3, #3\n\
	ldr r3, _08098EA0 @ =gOamData\n\
	adds r2, r4, r3\n\
	ldrb r3, [r2, #3]\n\
	lsls r0, r3, #0x1b\n\
	lsrs r0, r0, #0x1f\n\
	eors r0, r1\n\
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
	ldr r0, _08098EA8 @ =0x0863A184\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #3\n\
	adds r0, r5, r0\n\
	mov r2, sb\n\
	ldrh r1, [r2, #0xc]\n\
	subs r0, r1, r0\n\
	ands r0, r7\n\
	str r0, [sp]\n\
	ldrh r0, [r2, #0xe]\n\
	adds r6, r6, r0\n\
	movs r0, #0xff\n\
	ands r6, r0\n\
	str r6, [sp, #4]\n\
	b _08098EC2\n\
	.align 2, 0\n\
_08098E9C: .4byte gNextOamSlot\n\
_08098EA0: .4byte gOamData\n\
_08098EA4: .4byte 0x000001FF\n\
_08098EA8: .4byte 0x0863A184\n\
_08098EAC:\n\
	mov r4, sb\n\
	ldrh r0, [r4, #0xe]\n\
	adds r6, r6, r0\n\
	movs r0, #0xff\n\
	ands r6, r0\n\
	str r6, [sp, #4]\n\
	ldrh r0, [r4, #0xc]\n\
	adds r5, r5, r0\n\
	ands r5, r7\n\
	str r5, [sp]\n\
	lsls r4, r3, #3\n\
_08098EC2:\n\
	ldr r5, _08098F68 @ =gOamData\n\
	adds r3, r4, r5\n\
	mov r0, sp\n\
	ldrb r0, [r0, #4]\n\
	strb r0, [r3]\n\
	ldr r1, [sp]\n\
	ands r1, r7\n\
	str r1, [sp]\n\
	ldrh r1, [r3, #2]\n\
	ldr r0, _08098F6C @ =0xFFFFFE00\n\
	ands r0, r1\n\
	ldr r2, [sp]\n\
	orrs r0, r2\n\
	strh r0, [r3, #2]\n\
	mov r4, sb\n\
	ldrb r0, [r4, #0x1a]\n\
	lsls r0, r0, #0x1c\n\
	lsrs r0, r0, #0x1e\n\
	mov r5, r8\n\
	ands r0, r5\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r3, #5]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r3, #5]\n\
	lsrs r2, r1, #4\n\
	ldrb r0, [r4, #0x1a]\n\
	lsrs r0, r0, #4\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #4\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	orrs r1, r2\n\
	strb r1, [r3, #5]\n\
	ldrh r2, [r3, #4]\n\
	lsls r1, r2, #0x16\n\
	lsrs r1, r1, #0x16\n\
	ldr r0, [r4, #0x18]\n\
	lsls r0, r0, #0xe\n\
	lsrs r0, r0, #0x16\n\
	adds r1, r1, r0\n\
	ldr r4, _08098F70 @ =0x000003FF\n\
	adds r0, r4, #0\n\
	ands r1, r0\n\
	ldr r0, _08098F74 @ =0xFFFFFC00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #4]\n\
	mov r5, sb\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r0, r0, #0x1e\n\
	mov r1, r8\n\
	ands r0, r1\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r3, #1]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r3, #1]\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r0, r0, #0x1f\n\
	lsls r0, r0, #4\n\
	movs r2, #0x11\n\
	rsbs r2, r2, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r3, #1]\n\
	movs r3, #2\n\
	add ip, r3\n\
	ldr r4, [sp, #0x1c]\n\
	adds r4, #1\n\
	str r4, [sp, #0x1c]\n\
	ldr r5, [sp, #0x20]\n\
	cmp r4, r5\n\
	bge _08098F64\n\
	b _08098E18\n\
_08098F64:\n\
	b _0809975A\n\
	.align 2, 0\n\
_08098F68: .4byte gOamData\n\
_08098F6C: .4byte 0xFFFFFE00\n\
_08098F70: .4byte 0x000003FF\n\
_08098F74: .4byte 0xFFFFFC00\n\
_08098F78:\n\
	cmp r0, #1\n\
	beq _08098F7E\n\
	b _08099400\n\
_08098F7E:\n\
	mov r2, sb\n\
	ldrh r0, [r2, #0xc]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp]\n\
	ldrh r0, [r2, #0xe]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #4]\n\
	lsls r0, r1, #0x19\n\
	cmp r0, #0\n\
	blt _08098FA0\n\
	ldrh r3, [r2, #6]\n\
	str r3, [sp, #0x14]\n\
	b _08098FAC\n\
_08098FA0:\n\
	mov r4, sb\n\
	ldrh r0, [r4, #6]\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x14]\n\
_08098FAC:\n\
	lsls r0, r1, #0x18\n\
	cmp r0, #0\n\
	blt _08098FBA\n\
	mov r5, sb\n\
	ldrh r5, [r5, #6]\n\
	str r5, [sp, #0x18]\n\
	b _08098FC6\n\
_08098FBA:\n\
	mov r1, sb\n\
	ldrh r0, [r1, #6]\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x18]\n\
_08098FC6:\n\
	movs r2, #0\n\
	str r2, [sp, #0x28]\n\
	movs r3, #0\n\
	str r3, [sp, #0x1c]\n\
	ldr r4, [sp, #0x14]\n\
	lsls r4, r4, #0x10\n\
	str r4, [sp, #0x34]\n\
	ldr r5, [sp, #0x20]\n\
	cmp r3, r5\n\
	blt _08098FDC\n\
	b _0809925C\n\
_08098FDC:\n\
	mov r0, sl\n\
	ldrh r6, [r0]\n\
	movs r1, #2\n\
	add sl, r1\n\
	mov r2, sl\n\
	ldrh r5, [r2]\n\
	add sl, r1\n\
	mov r3, ip\n\
	strh r6, [r3]\n\
	add ip, r1\n\
	mov r4, ip\n\
	strh r5, [r4]\n\
	add ip, r1\n\
	mov r1, sl\n\
	ldrh r0, [r1]\n\
	mov r2, ip\n\
	strh r0, [r2]\n\
	movs r3, #2\n\
	add sl, r3\n\
	add ip, r3\n\
	ldr r4, _08099098 @ =gNextOamSlot\n\
	ldrb r0, [r4]\n\
	ldr r1, [sp, #0x1c]\n\
	adds r3, r0, r1\n\
	lsls r0, r3, #3\n\
	ldr r2, _0809909C @ =gOamData\n\
	adds r0, r0, r2\n\
	mov r8, r0\n\
	ldrb r7, [r0, #3]\n\
	lsrs r1, r7, #6\n\
	ldrb r0, [r0, #1]\n\
	lsrs r0, r0, #6\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldr r4, _080990A0 @ =0x0863A184\n\
	adds r0, r1, r4\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	str r0, [sp, #8]\n\
	ldr r0, _080990A4 @ =0x0863A190\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #2\n\
	str r0, [sp, #0xc]\n\
	ldr r1, [sp, #4]\n\
	adds r6, r6, r1\n\
	movs r0, #0xff\n\
	ands r6, r0\n\
	ldr r2, [sp]\n\
	adds r4, r5, r2\n\
	ldr r5, _080990A8 @ =0x000001FF\n\
	adds r0, r5, #0\n\
	ands r4, r0\n\
	subs r1, r4, r2\n\
	ldr r0, [sp, #8]\n\
	adds r1, r0, r1\n\
	ldr r5, [sp, #4]\n\
	subs r2, r6, r5\n\
	ldr r0, [sp, #0xc]\n\
	adds r2, r0, r2\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r5, [sp, #0x34]\n\
	asrs r0, r5, #0x10\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #8\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x10]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	ldr r1, [sp, #0x18]\n\
	lsls r0, r1, #0x10\n\
	asrs r0, r0, #0x10\n\
	muls r0, r2, r0\n\
	asrs r0, r0, #8\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	lsls r0, r7, #0x1b\n\
	cmp r0, #0\n\
	bge _080990AC\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r7\n\
	mov r5, r8\n\
	strb r0, [r5, #3]\n\
	movs r0, #1\n\
	str r0, [sp, #0x28]\n\
	movs r1, #1\n\
	str r1, [sp, #0x24]\n\
	b _080990B0\n\
	.align 2, 0\n\
_08099098: .4byte gNextOamSlot\n\
_0809909C: .4byte gOamData\n\
_080990A0: .4byte 0x0863A184\n\
_080990A4: .4byte 0x0863A190\n\
_080990A8: .4byte 0x000001FF\n\
_080990AC:\n\
	movs r5, #0\n\
	str r5, [sp, #0x24]\n\
_080990B0:\n\
	lsls r0, r3, #3\n\
	ldr r1, _080993E4 @ =gOamData\n\
	adds r7, r0, r1\n\
	ldrb r1, [r7, #3]\n\
	lsls r0, r1, #0x1a\n\
	cmp r0, #0\n\
	bge _080990D0\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r7, #3]\n\
	ldr r3, [sp, #0x18]\n\
	lsls r0, r3, #0x10\n\
	rsbs r0, r0, #0\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x18]\n\
_080990D0:\n\
	lsls r1, r4, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r4, [sp, #0x10]\n\
	lsls r0, r4, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r4, r1, #0x10\n\
	lsls r1, r6, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r6, r1, #0x10\n\
	ldr r5, [sp]\n\
	subs r4, r4, r5\n\
	ldr r0, [sp, #8]\n\
	mov r8, r0\n\
	add r4, r8\n\
	ldr r1, [sp, #4]\n\
	subs r3, r6, r1\n\
	ldr r6, [sp, #0xc]\n\
	adds r3, r6, r3\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	mov r2, sb\n\
	ldrb r1, [r2, #0x15]\n\
	adds r0, r1, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r5, _080993E8 @ =0x080A4FA4\n\
	adds r0, r0, r5\n\
	movs r2, #0\n\
	ldrsh r5, [r0, r2]\n\
	adds r2, r4, #0\n\
	muls r2, r5, r2\n\
	lsls r3, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	lsls r1, r1, #1\n\
	ldr r0, _080993E8 @ =0x080A4FA4\n\
	adds r1, r1, r0\n\
	movs r0, #0\n\
	ldrsh r1, [r1, r0]\n\
	adds r0, r3, #0\n\
	muls r0, r1, r0\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #8\n\
	adds r0, r4, #0\n\
	muls r0, r1, r0\n\
	adds r1, r3, #0\n\
	muls r1, r5, r1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	asrs r2, r2, #0x10\n\
	mov r1, r8\n\
	subs r2, r2, r1\n\
	asrs r0, r0, #0x10\n\
	subs r0, r0, r6\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	ldr r3, [sp, #4]\n\
	adds r0, r6, r3\n\
	subs r0, #0x40\n\
	strb r0, [r7]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	ldr r4, [sp]\n\
	adds r2, r2, r4\n\
	subs r2, #0x40\n\
	ldr r4, _080993EC @ =0x000001FF\n\
	ands r2, r4\n\
	ldrh r0, [r7, #2]\n\
	ldr r1, _080993F0 @ =0xFFFFFE00\n\
	adds r3, r1, #0\n\
	ands r3, r0\n\
	orrs r3, r2\n\
	strh r3, [r7, #2]\n\
	ldr r5, [sp, #0x24]\n\
	cmp r5, #1\n\
	bne _08099180\n\
	lsls r0, r3, #0x17\n\
	lsrs r0, r0, #0x17\n\
	subs r0, #1\n\
	ands r0, r4\n\
	ands r3, r1\n\
	orrs r3, r0\n\
	strh r3, [r7, #2]\n\
_08099180:\n\
	ldrb r1, [r7, #1]\n\
	movs r0, #4\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r3, #1\n\
	orrs r0, r3\n\
	strb r0, [r7, #1]\n\
	ldr r1, _080993F4 @ =0x03001238\n\
	ldrb r0, [r1]\n\
	ldr r2, [sp, #0x24]\n\
	adds r0, r0, r2\n\
	movs r1, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080991A6\n\
	ldrb r0, [r7, #3]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	strb r0, [r7, #3]\n\
_080991A6:\n\
	ldr r4, _080993F4 @ =0x03001238\n\
	ldrb r0, [r4]\n\
	ldr r5, [sp, #0x24]\n\
	adds r0, r0, r5\n\
	movs r1, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080991BE\n\
	ldrb r0, [r7, #3]\n\
	movs r1, #0x10\n\
	orrs r0, r1\n\
	strb r0, [r7, #3]\n\
_080991BE:\n\
	ldr r0, _080993F4 @ =0x03001238\n\
	ldrb r1, [r0]\n\
	ldr r2, [sp, #0x24]\n\
	adds r1, r1, r2\n\
	movs r0, #7\n\
	ands r1, r0\n\
	lsls r1, r1, #1\n\
	ldrb r2, [r7, #3]\n\
	subs r0, #0x16\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r7, #3]\n\
	mov r4, sb\n\
	ldrb r0, [r4, #0x1a]\n\
	lsls r0, r0, #0x1c\n\
	lsrs r0, r0, #0x1e\n\
	movs r5, #3\n\
	ands r0, r5\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r7, #5]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r7, #5]\n\
	lsrs r2, r1, #4\n\
	ldrb r0, [r4, #0x1a]\n\
	lsrs r0, r0, #4\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #4\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	orrs r1, r2\n\
	strb r1, [r7, #5]\n\
	ldrh r2, [r7, #4]\n\
	lsls r1, r2, #0x16\n\
	lsrs r1, r1, #0x16\n\
	ldr r0, [r4, #0x18]\n\
	lsls r0, r0, #0xe\n\
	lsrs r0, r0, #0x16\n\
	adds r1, r1, r0\n\
	ldr r4, _080993F8 @ =0x000003FF\n\
	adds r0, r4, #0\n\
	ands r1, r0\n\
	ldr r0, _080993FC @ =0xFFFFFC00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r7, #4]\n\
	mov r5, sb\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r0, r0, #0x1e\n\
	movs r1, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r7, #1]\n\
	subs r1, #0x10\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r7, #1]\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r0, r0, #0x1f\n\
	ands r0, r3\n\
	lsls r0, r0, #4\n\
	movs r2, #0x11\n\
	rsbs r2, r2, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r7, #1]\n\
	movs r3, #2\n\
	add ip, r3\n\
	ldr r4, [sp, #0x1c]\n\
	adds r4, #1\n\
	str r4, [sp, #0x1c]\n\
	ldr r5, [sp, #0x20]\n\
	cmp r4, r5\n\
	bge _0809925C\n\
	b _08098FDC\n\
_0809925C:\n\
	ldr r1, _080993F4 @ =0x03001238\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r7, r0, #0x18\n\
	mov r2, sb\n\
	ldrb r0, [r2, #0x15]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r3, _080993E8 @ =0x080A4FA4\n\
	adds r0, r0, r3\n\
	movs r5, #0\n\
	ldrsh r4, [r0, r5]\n\
	ldr r0, [sp, #0x34]\n\
	asrs r0, r0, #0x10\n\
	mov sl, r0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	ldr r1, _080993E4 @ =gOamData\n\
	mov r8, r1\n\
	lsls r1, r7, #3\n\
	add r1, r8\n\
	strh r0, [r1, #6]\n\
	mov r2, sb\n\
	ldrb r0, [r2, #0x15]\n\
	lsls r0, r0, #1\n\
	ldr r3, _080993E8 @ =0x080A4FA4\n\
	adds r0, r0, r3\n\
	movs r5, #0\n\
	ldrsh r4, [r0, r5]\n\
	mov r0, sl\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #1\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	strh r0, [r1, #6]\n\
	mov r1, sb\n\
	ldrb r0, [r1, #0x15]\n\
	lsls r0, r0, #1\n\
	ldr r2, _080993E8 @ =0x080A4FA4\n\
	adds r0, r0, r2\n\
	ldrh r4, [r0]\n\
	rsbs r4, r4, #0\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	ldr r3, [sp, #0x18]\n\
	lsls r0, r3, #0x10\n\
	asrs r6, r0, #0x10\n\
	adds r0, r6, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #2\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	strh r0, [r1, #6]\n\
	mov r4, sb\n\
	ldrb r0, [r4, #0x15]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r5, _080993E8 @ =0x080A4FA4\n\
	adds r0, r0, r5\n\
	movs r1, #0\n\
	ldrsh r4, [r0, r1]\n\
	adds r0, r6, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #3\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	strh r0, [r1, #6]\n\
	ldr r2, _080993F4 @ =0x03001238\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
	ldr r3, [sp, #0x28]\n\
	cmp r3, #1\n\
	beq _08099328\n\
	b _0809975A\n\
_08099328:\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r7, r0, #0x18\n\
	mov r4, sb\n\
	ldrb r0, [r4, #0x15]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	movs r1, #0\n\
	ldrsh r5, [r0, r1]\n\
	mov r2, sl\n\
	rsbs r4, r2, #0\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl FixedMultiplication\n\
	lsls r1, r7, #3\n\
	add r1, r8\n\
	strh r0, [r1, #6]\n\
	mov r3, sb\n\
	ldrb r0, [r3, #0x15]\n\
	lsls r0, r0, #1\n\
	ldr r5, _080993E8 @ =0x080A4FA4\n\
	adds r0, r0, r5\n\
	movs r1, #0\n\
	ldrsh r5, [r0, r1]\n\
	adds r0, r4, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #1\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	strh r0, [r1, #6]\n\
	mov r2, sb\n\
	ldrb r0, [r2, #0x15]\n\
	lsls r0, r0, #1\n\
	ldr r3, _080993E8 @ =0x080A4FA4\n\
	adds r0, r0, r3\n\
	ldrh r4, [r0]\n\
	rsbs r4, r4, #0\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	adds r0, r6, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #2\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	strh r0, [r1, #6]\n\
	mov r4, sb\n\
	ldrb r0, [r4, #0x15]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r5, _080993E8 @ =0x080A4FA4\n\
	adds r0, r0, r5\n\
	movs r1, #0\n\
	ldrsh r4, [r0, r1]\n\
	adds r0, r6, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #3\n\
	lsls r1, r1, #3\n\
	add r1, r8\n\
	strh r0, [r1, #6]\n\
	ldr r2, _080993F4 @ =0x03001238\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
	b _0809975A\n\
	.align 2, 0\n\
_080993E4: .4byte gOamData\n\
_080993E8: .4byte 0x080A4FA4\n\
_080993EC: .4byte 0x000001FF\n\
_080993F0: .4byte 0xFFFFFE00\n\
_080993F4: .4byte 0x03001238\n\
_080993F8: .4byte 0x000003FF\n\
_080993FC: .4byte 0xFFFFFC00\n\
_08099400:\n\
	cmp r0, #3\n\
	beq _08099406\n\
	b _0809975A\n\
_08099406:\n\
	mov r3, sb\n\
	ldrh r0, [r3, #0xc]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp]\n\
	ldrh r0, [r3, #0xe]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #4]\n\
	lsls r0, r1, #0x19\n\
	cmp r0, #0\n\
	blt _08099428\n\
	ldrh r4, [r3, #6]\n\
	str r4, [sp, #0x14]\n\
	b _08099434\n\
_08099428:\n\
	mov r5, sb\n\
	ldrh r0, [r5, #6]\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x14]\n\
_08099434:\n\
	lsls r0, r1, #0x18\n\
	cmp r0, #0\n\
	blt _08099440\n\
	mov r0, sb\n\
	ldrh r0, [r0, #6]\n\
	b _0809944A\n\
_08099440:\n\
	mov r1, sb\n\
	ldrh r0, [r1, #6]\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
_0809944A:\n\
	str r0, [sp, #0x18]\n\
	movs r2, #0\n\
	str r2, [sp, #0x1c]\n\
	ldr r3, [sp, #0x20]\n\
	cmp r2, r3\n\
	blt _08099458\n\
	b _08099696\n\
_08099458:\n\
	mov r4, sl\n\
	ldrh r6, [r4]\n\
	movs r5, #2\n\
	add sl, r5\n\
	mov r0, sl\n\
	ldrh r5, [r0]\n\
	movs r1, #2\n\
	add sl, r1\n\
	mov r2, ip\n\
	strh r6, [r2]\n\
	add ip, r1\n\
	mov r3, ip\n\
	strh r5, [r3]\n\
	add ip, r1\n\
	mov r4, sl\n\
	ldrh r0, [r4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	movs r2, #2\n\
	add sl, r2\n\
	add ip, r2\n\
	ldr r3, _0809977C @ =gNextOamSlot\n\
	ldrb r0, [r3]\n\
	ldr r4, [sp, #0x1c]\n\
	adds r3, r0, r4\n\
	lsls r0, r3, #3\n\
	ldr r1, _08099780 @ =gOamData\n\
	adds r7, r0, r1\n\
	ldrb r2, [r7, #3]\n\
	mov r8, r2\n\
	mov r3, r8\n\
	lsrs r1, r3, #6\n\
	ldrb r0, [r7, #1]\n\
	lsrs r0, r0, #6\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldr r4, _08099784 @ =0x0863A184\n\
	adds r0, r1, r4\n\
	ldrb r2, [r0]\n\
	ldr r0, _08099788 @ =0x0863A190\n\
	adds r1, r1, r0\n\
	ldrb r3, [r1]\n\
	ldr r1, [sp, #4]\n\
	adds r6, r6, r1\n\
	movs r0, #0xff\n\
	ands r6, r0\n\
	ldr r0, [sp]\n\
	adds r4, r5, r0\n\
	ldr r1, _0809978C @ =0x000001FF\n\
	adds r0, r1, #0\n\
	ands r4, r0\n\
	ldr r5, [sp]\n\
	subs r1, r4, r5\n\
	lsls r2, r2, #2\n\
	str r2, [sp, #0x2c]\n\
	adds r1, r2, r1\n\
	ldr r0, [sp, #4]\n\
	subs r2, r6, r0\n\
	lsls r3, r3, #2\n\
	str r3, [sp, #0x30]\n\
	adds r2, r3, r2\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r3, [sp, #0x14]\n\
	lsls r0, r3, #0x10\n\
	asrs r3, r0, #0x10\n\
	adds r0, r1, #0\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x10]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	ldr r5, [sp, #0x18]\n\
	lsls r0, r5, #0x10\n\
	asrs r5, r0, #0x10\n\
	adds r0, r2, #0\n\
	muls r0, r5, r0\n\
	asrs r0, r0, #8\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	mov r1, r8\n\
	lsls r0, r1, #0x1b\n\
	cmp r0, #0\n\
	bge _08099518\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r7, #3]\n\
	rsbs r0, r3, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x14]\n\
_08099518:\n\
	ldrb r1, [r7, #3]\n\
	lsls r0, r1, #0x1a\n\
	cmp r0, #0\n\
	bge _08099530\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r7, #3]\n\
	rsbs r0, r5, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x18]\n\
_08099530:\n\
	lsls r1, r4, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r3, [sp, #0x10]\n\
	lsls r0, r3, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r4, r1, #0x10\n\
	lsls r1, r6, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r6, r1, #0x10\n\
	ldr r5, [sp]\n\
	subs r4, r4, r5\n\
	ldr r0, [sp, #0x2c]\n\
	adds r4, r0, r4\n\
	ldr r1, [sp, #4]\n\
	subs r3, r6, r1\n\
	ldr r2, [sp, #0x30]\n\
	adds r3, r2, r3\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	mov r5, sb\n\
	ldrb r1, [r5, #0x15]\n\
	adds r0, r1, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r2, _08099790 @ =0x080A4FA4\n\
	adds r0, r0, r2\n\
	movs r2, #0\n\
	ldrsh r5, [r0, r2]\n\
	adds r2, r4, #0\n\
	muls r2, r5, r2\n\
	lsls r3, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	lsls r1, r1, #1\n\
	ldr r0, _08099790 @ =0x080A4FA4\n\
	adds r1, r1, r0\n\
	movs r0, #0\n\
	ldrsh r1, [r1, r0]\n\
	adds r0, r3, #0\n\
	muls r0, r1, r0\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #8\n\
	adds r0, r4, #0\n\
	muls r0, r1, r0\n\
	adds r1, r3, #0\n\
	muls r1, r5, r1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	ldr r3, [sp, #0x2c]\n\
	lsls r1, r3, #1\n\
	asrs r2, r2, #0x10\n\
	subs r2, r2, r1\n\
	ldr r4, [sp, #0x30]\n\
	lsls r1, r4, #1\n\
	asrs r0, r0, #0x10\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	ldr r5, [sp, #4]\n\
	adds r0, r6, r5\n\
	subs r0, #0x40\n\
	strb r0, [r7]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	ldr r0, [sp]\n\
	adds r2, r2, r0\n\
	subs r2, #0x40\n\
	ldr r0, _0809978C @ =0x000001FF\n\
	ands r2, r0\n\
	ldrh r1, [r7, #2]\n\
	ldr r0, _08099794 @ =0xFFFFFE00\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strh r0, [r7, #2]\n\
	ldrb r0, [r7, #1]\n\
	movs r3, #3\n\
	orrs r0, r3\n\
	strb r0, [r7, #1]\n\
	ldr r2, _08099798 @ =0x03001238\n\
	ldrb r1, [r2]\n\
	movs r2, #0x10\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080995EC\n\
	ldrb r0, [r7, #3]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	strb r0, [r7, #3]\n\
_080995EC:\n\
	ldr r4, _08099798 @ =0x03001238\n\
	ldrb r1, [r4]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080995FE\n\
	ldrb r0, [r7, #3]\n\
	orrs r0, r2\n\
	strb r0, [r7, #3]\n\
_080995FE:\n\
	ldr r5, _08099798 @ =0x03001238\n\
	ldrb r0, [r5]\n\
	movs r1, #7\n\
	ands r1, r0\n\
	lsls r1, r1, #1\n\
	ldrb r2, [r7, #3]\n\
	movs r0, #0xf\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r7, #3]\n\
	mov r1, sb\n\
	ldrb r0, [r1, #0x1a]\n\
	lsls r0, r0, #0x1c\n\
	lsrs r0, r0, #0x1e\n\
	ands r0, r3\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r7, #5]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r7, #5]\n\
	lsrs r2, r1, #4\n\
	mov r4, sb\n\
	ldrb r0, [r4, #0x1a]\n\
	lsrs r0, r0, #4\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #4\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	orrs r1, r2\n\
	strb r1, [r7, #5]\n\
	ldrh r2, [r7, #4]\n\
	lsls r1, r2, #0x16\n\
	lsrs r1, r1, #0x16\n\
	ldr r0, [r4, #0x18]\n\
	lsls r0, r0, #0xe\n\
	lsrs r0, r0, #0x16\n\
	adds r1, r1, r0\n\
	ldr r5, _0809979C @ =0x000003FF\n\
	adds r0, r5, #0\n\
	ands r1, r0\n\
	ldr r0, _080997A0 @ =0xFFFFFC00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r7, #4]\n\
	ldrb r0, [r4, #0x18]\n\
	lsls r0, r0, #0x1b\n\
	lsrs r0, r0, #0x1e\n\
	ands r0, r3\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r7, #1]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r7, #1]\n\
	ldrb r0, [r4, #0x18]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r0, r0, #0x1f\n\
	lsls r0, r0, #4\n\
	movs r2, #0x11\n\
	rsbs r2, r2, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r7, #1]\n\
	movs r3, #2\n\
	add ip, r3\n\
	ldr r4, [sp, #0x1c]\n\
	adds r4, #1\n\
	str r4, [sp, #0x1c]\n\
	ldr r5, [sp, #0x20]\n\
	cmp r4, r5\n\
	bge _08099696\n\
	b _08099458\n\
_08099696:\n\
	ldr r1, _08099798 @ =0x03001238\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r7, r0, #0x18\n\
	mov r2, sb\n\
	ldrb r0, [r2, #0x15]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r3, _08099790 @ =0x080A4FA4\n\
	adds r0, r0, r3\n\
	movs r4, #0\n\
	ldrsh r5, [r0, r4]\n\
	ldr r0, [sp, #0x14]\n\
	lsls r4, r0, #0x10\n\
	asrs r4, r4, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl FixedMultiplication\n\
	ldr r6, _08099780 @ =gOamData\n\
	lsls r1, r7, #3\n\
	adds r1, r1, r6\n\
	strh r0, [r1, #6]\n\
	mov r1, sb\n\
	ldrb r0, [r1, #0x15]\n\
	lsls r0, r0, #1\n\
	ldr r2, _08099790 @ =0x080A4FA4\n\
	adds r0, r0, r2\n\
	movs r3, #0\n\
	ldrsh r5, [r0, r3]\n\
	adds r0, r4, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #1\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	strh r0, [r1, #6]\n\
	mov r4, sb\n\
	ldrb r0, [r4, #0x15]\n\
	lsls r0, r0, #1\n\
	ldr r5, _08099790 @ =0x080A4FA4\n\
	adds r0, r0, r5\n\
	ldrh r4, [r0]\n\
	rsbs r4, r4, #0\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	ldr r0, [sp, #0x18]\n\
	lsls r5, r0, #0x10\n\
	asrs r5, r5, #0x10\n\
	adds r0, r5, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #2\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	strh r0, [r1, #6]\n\
	mov r1, sb\n\
	ldrb r0, [r1, #0x15]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r2, _08099790 @ =0x080A4FA4\n\
	adds r0, r0, r2\n\
	movs r3, #0\n\
	ldrsh r4, [r0, r3]\n\
	adds r0, r5, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #3\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	strh r0, [r1, #6]\n\
	ldr r4, _08099798 @ =0x03001238\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	strb r0, [r4]\n\
_0809975A:\n\
	ldr r0, _0809977C @ =gNextOamSlot\n\
	ldrb r1, [r0]\n\
	ldr r5, [sp, #0x20]\n\
	adds r1, r1, r5\n\
	strb r1, [r0]\n\
	mov r1, sb\n\
	ldrb r0, [r1, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r1, #0x12]\n\
	add sp, #0x38\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809977C: .4byte gNextOamSlot\n\
_08099780: .4byte gOamData\n\
_08099784: .4byte 0x0863A184\n\
_08099788: .4byte 0x0863A190\n\
_0809978C: .4byte 0x000001FF\n\
_08099790: .4byte 0x080A4FA4\n\
_08099794: .4byte 0xFFFFFE00\n\
_08099798: .4byte 0x03001238\n\
_0809979C: .4byte 0x000003FF\n\
_080997A0: .4byte 0xFFFFFC00\n\
    .syntax divided\n");
}

// 0x080997A4
NAKED_FUNCTION
void NewFileIntroInit(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	sub sp, #4\n\
	ldr r3, _08099864 @ =0x04000208\n\
	movs r4, #0\n\
	strh r4, [r3]\n\
	ldr r2, _08099868 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809986C @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _08099870 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _08099874 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _08099878 @ =unk_99940\n\
	bl CallbackSetVBlank\n\
	ldr r1, _0809987C @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	ldr r0, _08099880 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _08099884 @ =0x04000054\n\
	strh r1, [r0]\n\
	ldr r0, _08099888 @ =gNextOamSlot\n\
	strb r4, [r0]\n\
	bl ResetFreeOam\n\
	movs r2, #0\n\
	str r2, [sp]\n\
	ldr r1, _0809988C @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	ldr r0, _08099890 @ =gNonGameplayRam\n\
	str r0, [r1, #4]\n\
	ldr r0, _08099894 @ =0x85000150\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r0, _08099898 @ =0x00007FFF\n\
	str r0, [sp]\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	movs r3, #0xa0\n\
	lsls r3, r3, #0x13\n\
	str r3, [r1, #4]\n\
	ldr r0, _0809989C @ =0x85000080\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	strh r2, [r3]\n\
	str r2, [sp]\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _080998A0 @ =0x85004000\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r0, _080998A4 @ =0x0400000E\n\
	strh r2, [r0]\n\
	subs r0, #2\n\
	strh r2, [r0]\n\
	subs r0, #2\n\
	strh r2, [r0]\n\
	subs r0, #2\n\
	strh r2, [r0]\n\
	adds r0, #8\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	strh r2, [r0]\n\
	subs r0, #0x1e\n\
	strh r2, [r0]\n\
	ldr r0, _080998A8 @ =NewFileIntroVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #4\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08099864: .4byte 0x04000208\n\
_08099868: .4byte 0x04000004\n\
_0809986C: .4byte 0x0000FFEF\n\
_08099870: .4byte 0x04000200\n\
_08099874: .4byte 0x0000FFFD\n\
_08099878: .4byte unk_99940\n\
_0809987C: .4byte 0x04000050\n\
_08099880: .4byte gWrittenToBldy\n\
_08099884: .4byte 0x04000054\n\
_08099888: .4byte gNextOamSlot\n\
_0809988C: .4byte 0x040000D4\n\
_08099890: .4byte gNonGameplayRam\n\
_08099894: .4byte 0x85000150\n\
_08099898: .4byte 0x00007FFF\n\
_0809989C: .4byte 0x85000080\n\
_080998A0: .4byte 0x85004000\n\
_080998A4: .4byte 0x0400000E\n\
_080998A8: .4byte NewFileIntroVblank\n\
    .syntax divided\n");
}

// 0x080998AC
NAKED_FUNCTION
u8 SpecialCutsceneGetRandomNumber(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	ldr r3, _080998E0 @ =0x03005404\n\
	ldrh r1, [r3]\n\
	lsls r0, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r2, _080998E4 @ =gFrameCounter8Bit\n\
	ldr r4, _080998E8 @ =0x00003573\n\
	adds r0, r4, #0\n\
	ldrb r2, [r2]\n\
	adds r0, r0, r2\n\
	adds r1, r1, r0\n\
	strh r1, [r3]\n\
	ldr r2, _080998EC @ =sRandomNumberTable\n\
	ldr r0, _080998F0 @ =gFrameCounter16Bit\n\
	ldrh r1, [r0]\n\
	movs r0, #0x1f\n\
	ands r0, r1\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r3, #1]\n\
	adds r0, r0, r1\n\
	strb r0, [r3, #1]\n\
	ldrb r0, [r3, #1]\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080998E0: .4byte 0x03005404\n\
_080998E4: .4byte gFrameCounter8Bit\n\
_080998E8: .4byte 0x00003573\n\
_080998EC: .4byte sRandomNumberTable\n\
_080998F0: .4byte gFrameCounter16Bit\n\
    .syntax divided\n");
}

// 0x080998F4
NAKED_FUNCTION
void NewFileIntroVblank(void)
{
    asm(" .syntax unified\n\
	ldr r1, _08099920 @ =0x040000D4\n\
	ldr r0, _08099924 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _08099928 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r2, _0809992C @ =0x04000052\n\
	ldr r0, _08099930 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _08099934 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08099938 @ =0x04000054\n\
	ldr r0, _0809993C @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_08099920: .4byte 0x040000D4\n\
_08099924: .4byte gOamData\n\
_08099928: .4byte 0x84000100\n\
_0809992C: .4byte 0x04000052\n\
_08099930: .4byte gWrittenToBldalpha_Evb\n\
_08099934: .4byte gWrittenToBldalpha_Eva\n\
_08099938: .4byte 0x04000054\n\
_0809993C: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x08099940
NAKED_FUNCTION
void unk_99940(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}
