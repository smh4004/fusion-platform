#include "menus/file_select.h"
#include "gba.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "init_helpers.h"
#include "music_wrappers.h"
#include "audio_wrappers.h"
#include "syscalls.h"

#include "audio/track_internal.h"

#include "data/menus/file_select_data.h"

#include "constants/audio.h"
#include "constants/game_state.h"

#include "structs/save_file.h"

// TODO move to the save file header once that code is decompiled
void Sram_WriteFileInfo(void);

/**
 * @brief 9e598 | 1b8 | TODO
 * 
 */
s32 FileSelectHandler(void)
{
    s32 result;

    result = 0;

    switch (gSubGameMode1)
    {
        case 0:
            FileSelectInit();
            if (gSaveFilesInfo[0].corruptionFlag == 0 && gSaveFilesInfo[1].corruptionFlag == 0 &&
                gSaveFilesInfo[2].corruptionFlag == 0)
            {
                FileSelectSetupOam(1, 15, (s16)(gMostRecentSaveFile * 16 + 49), 0);
                WRITE_16(REG_BG1HOFS, 2);
                gSubGameMode1 = 1;
            }
            else
            {
                WRITE_16(REG_BG1HOFS, -48);
                WRITE_16(REG_BG1VOFS, 48);
                gSubGameMode1 = 5;
            }
            break;

        case 1:
            FILE_SELECT_DATA.stage++;
            if (FILE_SELECT_DATA.stage == 1)
            {
                FileSelectDrawText(1);
            }
            else if (FILE_SELECT_DATA.stage == 2)
            {
                FileSelectDrawFileInfo(0);
            }
            else if (FILE_SELECT_DATA.stage == 3)
            {
                FileSelectDrawFileInfo(1);
            }
            else if (FILE_SELECT_DATA.stage == 4)
            {
                FileSelectDrawFileInfo(2);
                FILE_SELECT_DATA.stage = 0;
                gWrittenToBldy = 14;
                gSubGameMode1 = 2;
            }
            break;

        case 2:
            FileSelectDrawAllOam();
            if (gWrittenToBldy != 0)
                gWrittenToBldy--;
            else
                gSubGameMode1++;
            break;

        case 3:
            FILE_SELECT_DATA.result = FileSelectInput();
            if (FILE_SELECT_DATA.result)
            {
                gSubGameMode1++;
                FadeMusic(20);
            }
            break;

        case 4:
            if (gWrittenToBldy < BLDY_MAX_VALUE)
            {
                gWrittenToBldy++;
            }
            else
            {
                result = FILE_SELECT_DATA.result;
                gSubGameMode1 = 0;
            }
            break;

        case 5:
            if (FileSelectProcessCorruptedFile())
            {
                WRITE_16(REG_BG1HOFS, 2);
                WRITE_16(REG_BG1VOFS, -6);
                FileSelectSetupOam(1, 15, (s16)(gMostRecentSaveFile * 16 + 49), 0);
                gSubGameMode1 = 3;
            }
            break;
    }

    return result;
}

/**
 * @brief 9e750 | 290 | TODO
 * 
 */
void FileSelectInit(void)
{
    u32 zero;
    u32 i;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVBlank(unk_9eaa4);

    WRITE_16(REG_DISPCNT, 0);
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

    ClearGfxRam();
    gNextOamSlot = 0;
    ResetFreeOam();

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRam, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED, sizeof(gNonGameplayRam) / sizeof(u32)));

    WRITE_16(REG_BG3CNT, 0);
    WRITE_16(REG_BG2CNT, 0);
    WRITE_16(REG_BG1CNT, 0);
    WRITE_16(REG_BG0CNT, 0);

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, -6);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    LZ77UncompVram((const void*)0x8742fb4, VRAM_BASE);
    LZ77UncompVram((const void*)0x87470e0, VRAM_BASE + 0xF800);
    DMA3_COPY_32((const void*)0x87476a0, PALRAM_BASE, PAL_SIZE / sizeof(u32));

    LZ77UncompVram((const void*)0x873cfac, VRAM_BASE + 0xE000);
    LZ77UncompVram((const void*)0x873d380, EWRAM_BASE);
    DMA3_COPY_32(EWRAM_BASE, VRAM_BASE + 0xE800, 0x800 / sizeof(u32));
    LZ77UncompVram((const void*)0x873d5ec, VRAM_BASE + 0xF000);

    DMA3_COPY_32((const void*)0x873db84, PALRAM_BASE, 0x20 / sizeof(u32));
    DMA3_COPY_32(sFileSelectBackdropColors, PALRAM_BASE, 8 / sizeof(u32));
    DMA3_COPY_32(&sFileSelectBackdropColors[4], PALRAM_BASE + 0x1C, 4 / sizeof(u32));
    SET_BACKDROP_COLOR(0);

    for (i = 0; i < 0x100; i += 2)
        *(u16*)(EWRAM_BASE + 0x800 + i) = (*(u16*)(EWRAM_BASE + 0x340 + i) & 0xFFF) | 0x1000;

    LZ77UncompVram((const void*)0x873dc20, VRAM_OBJ);
    DMA3_COPY_32((const void*)0x8740d08, PALRAM_OBJ, PAL_SIZE / sizeof(u32));

    FILE_SELECT_DATA.textId = 0;
    FILE_SELECT_DATA.pText = sFileSelectTextPointers[gLanguage][0];

    Sram_WriteFileInfo();
    FILE_SELECT_DATA.currentFile = gMostRecentSaveFile;

    FileSelectSetupOam(9, 102, 116, 1);
    FileSelectSetupOam(6, 142, 116, 1);
    FileSelectSetupOam(7, 132, 48, 1);
    FileSelectDrawAllOam();

    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 28, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 29, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));

    WRITE_16(REG_DISPCNT, DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
    CallbackSetVBlank(FileSelectVblank);
}

/**
 * @brief 9e9e0 | c4 | TODO
 * 
 */
void FileSelectVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / sizeof(u32));
    WRITE_16(REG_BLDY, gWrittenToBldy);

    switch (FILE_SELECT_DATA.bgToggle)
    {
        case 0:
            break;

        case 1:
            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG0);
            FILE_SELECT_DATA.bgToggle = 0;
            break;

        case 3:
            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_BG1);
            FILE_SELECT_DATA.bgToggle = 0;
            break;

        case 2:
            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG0);
            FILE_SELECT_DATA.bgToggle = 0;
            break;

        case 4:
            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~DCNT_BG1);
            FILE_SELECT_DATA.bgToggle = 0;
            break;

        case 5:
            WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) & ~(DCNT_BG0 | DCNT_BG1));
            FILE_SELECT_DATA.bgToggle = 0;
            break;

        default:
            FILE_SELECT_DATA.bgToggle = 0;
    }
}

/**
 * @brief 9eaa4 | c | TODO
 * 
 */
void unk_9eaa4(void)
{
    UpdateAudio();
}

// 0x0809EAB0
NAKED_FUNCTION
u8 FileSelectInput(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	movs r7, #0\n\
	bl FileSelectProcessOam\n\
	ldr r0, _0809EAD4 @ =gNonGameplayRam\n\
	movs r1, #0xa\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0x22\n\
	bls _0809EAC8\n\
	bl _0809F50A\n\
_0809EAC8:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0809EAD8 @ =_0809EADC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0809EAD4: .4byte gNonGameplayRam\n\
_0809EAD8: .4byte _0809EADC\n\
_0809EADC: @ jump table\n\
	.4byte _0809EB68 @ case 0\n\
	.4byte _0809EBB0 @ case 1\n\
	.4byte _0809EC88 @ case 2\n\
	.4byte _0809ECF8 @ case 3\n\
	.4byte _0809ECC8 @ case 4\n\
	.4byte _0809ED9A @ case 5\n\
	.4byte _0809EF3C @ case 6\n\
	.4byte _0809EDB8 @ case 7\n\
	.4byte _0809EF24 @ case 8\n\
	.4byte _0809EDD4 @ case 9\n\
	.4byte _0809EE42 @ case 10\n\
	.4byte _0809EE82 @ case 11\n\
	.4byte _0809EEA0 @ case 12\n\
	.4byte _0809EEDE @ case 13\n\
	.4byte _0809EF24 @ case 14\n\
	.4byte _0809EF3C @ case 15\n\
	.4byte _0809EF54 @ case 16\n\
	.4byte _0809EFE0 @ case 17\n\
	.4byte _0809F042 @ case 18\n\
	.4byte _0809F068 @ case 19\n\
	.4byte _0809F0E4 @ case 20\n\
	.4byte _0809F124 @ case 21\n\
	.4byte _0809F162 @ case 22\n\
	.4byte _0809F1A2 @ case 23\n\
	.4byte _0809F1EC @ case 24\n\
	.4byte _0809F24A @ case 25\n\
	.4byte _0809F2B6 @ case 26\n\
	.4byte _0809F2E4 @ case 27\n\
	.4byte _0809F374 @ case 28\n\
	.4byte _0809F3B2 @ case 29\n\
	.4byte _0809F3EA @ case 30\n\
	.4byte _0809F418 @ case 31\n\
	.4byte _0809F446 @ case 32\n\
	.4byte _0809F4AA @ case 33\n\
	.4byte _0809F508 @ case 34\n\
_0809EB68:\n\
	ldr r0, _0809EB8C @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809EB94\n\
	ldr r1, _0809EB90 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xd]\n\
	cmp r0, #3\n\
	bne _0809EB80\n\
	bl _0809F50A\n\
_0809EB80:\n\
	cmp r0, #4\n\
	beq _0809EBA2\n\
	movs r0, #1\n\
	strh r0, [r1, #0xa]\n\
	bl _0809F50A\n\
	.align 2, 0\n\
_0809EB8C: .4byte gChangedInput\n\
_0809EB90: .4byte gNonGameplayRam\n\
_0809EB94:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0809EBA0\n\
	bl _0809F50A\n\
_0809EBA0:\n\
	ldr r1, _0809EBAC @ =gNonGameplayRam\n\
_0809EBA2:\n\
	movs r0, #0x22\n\
	strh r0, [r1, #0xa]\n\
	bl _0809F50A\n\
	.align 2, 0\n\
_0809EBAC: .4byte gNonGameplayRam\n\
_0809EBB0:\n\
	ldr r1, _0809EBE8 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r1, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r4, r1, #0\n\
	cmp r0, #1\n\
	bne _0809EBF4\n\
	strh r0, [r4, #8]\n\
	ldr r1, _0809EBEC @ =0x0879EC68\n\
	ldr r0, _0809EBF0 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #4]\n\
	movs r0, #2\n\
	bl FileSelectDrawText\n\
	movs r0, #0xb\n\
	movs r1, #0x52\n\
	movs r2, #0x76\n\
	b _0809F2FC\n\
	.align 2, 0\n\
_0809EBE8: .4byte gNonGameplayRam\n\
_0809EBEC: .4byte 0x0879EC68\n\
_0809EBF0: .4byte 0x03000011\n\
_0809EBF4:\n\
	cmp r0, #0xc\n\
	beq _0809EBFC\n\
	bl _0809F50A\n\
_0809EBFC:\n\
	ldr r2, _0809EC34 @ =0x03000B94\n\
	ldrb r1, [r4, #0xd]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r2\n\
	movs r0, #0x10\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #1\n\
	beq _0809EC1E\n\
	movs r0, #0x11\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #1\n\
	beq _0809EC1E\n\
	ldrb r0, [r1]\n\
	cmp r0, #1\n\
	bne _0809EC48\n\
_0809EC1E:\n\
	ldr r1, _0809EC38 @ =0x040000D4\n\
	ldr r0, _0809EC3C @ =0x02000340\n\
	str r0, [r1]\n\
	ldr r0, _0809EC40 @ =0x0600EB40\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809EC44 @ =0x84000040\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #3\n\
	b _0809EC5A\n\
	.align 2, 0\n\
_0809EC34: .4byte 0x03000B94\n\
_0809EC38: .4byte 0x040000D4\n\
_0809EC3C: .4byte 0x02000340\n\
_0809EC40: .4byte 0x0600EB40\n\
_0809EC44: .4byte 0x84000040\n\
_0809EC48:\n\
	ldr r1, _0809EC78 @ =0x040000D4\n\
	ldr r0, _0809EC7C @ =0x02000800\n\
	str r0, [r1]\n\
	ldr r0, _0809EC80 @ =0x0600EB40\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809EC84 @ =0x84000040\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #2\n\
_0809EC5A:\n\
	strh r0, [r4, #0xa]\n\
	movs r0, #0\n\
	strb r0, [r4, #0xc]\n\
	strb r0, [r4, #0xe]\n\
	movs r0, #2\n\
	movs r1, #0x16\n\
	movs r2, #0x67\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	movs r0, #3\n\
	strb r0, [r4, #0x11]\n\
	bl _0809F50A\n\
	.align 2, 0\n\
_0809EC78: .4byte 0x040000D4\n\
_0809EC7C: .4byte 0x02000800\n\
_0809EC80: .4byte 0x0600EB40\n\
_0809EC84: .4byte 0x84000040\n\
_0809EC88:\n\
	ldr r0, _0809ECBC @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0809ED04\n\
	movs r4, #9\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0809ECA2\n\
	bl _0809F50A\n\
_0809ECA2:\n\
	ldr r2, _0809ECC0 @ =0x03000B94\n\
	ldr r3, _0809ECC4 @ =gNonGameplayRam\n\
	ldrb r1, [r3, #0xd]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0, #0x10]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	beq _0809ED74\n\
	b _0809ED54\n\
	.align 2, 0\n\
_0809ECBC: .4byte gChangedInput\n\
_0809ECC0: .4byte 0x03000B94\n\
_0809ECC4: .4byte gNonGameplayRam\n\
_0809ECC8:\n\
	ldr r4, _0809ECE8 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809ECEC\n\
	movs r0, #2\n\
	bl FileSelectDestroyOamOfType\n\
	movs r0, #4\n\
	strb r0, [r4, #0x11]\n\
	bl _0809F50A\n\
	.align 2, 0\n\
_0809ECE8: .4byte gNonGameplayRam\n\
_0809ECEC:\n\
	cmp r0, #0xc\n\
	beq _0809ECF4\n\
	bl _0809F50A\n\
_0809ECF4:\n\
	bl _0809F502\n\
_0809ECF8:\n\
	ldr r0, _0809ED10 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809ED18\n\
_0809ED04:\n\
	ldr r1, _0809ED14 @ =gNonGameplayRam\n\
	movs r0, #4\n\
	strh r0, [r1, #0xa]\n\
	bl _0809F50A\n\
	.align 2, 0\n\
_0809ED10: .4byte gChangedInput\n\
_0809ED14: .4byte gNonGameplayRam\n\
_0809ED18:\n\
	movs r4, #9\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0809ED26\n\
	bl _0809F50A\n\
_0809ED26:\n\
	ldr r3, _0809ED5C @ =gNonGameplayRam\n\
	ldrb r0, [r3, #0xe]\n\
	cmp r0, #0\n\
	bne _0809ED82\n\
	ldr r2, _0809ED60 @ =0x03000B94\n\
	ldrb r1, [r3, #0xd]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r2\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _0809ED64\n\
	movs r0, #0x10\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #1\n\
	beq _0809ED74\n\
	movs r0, #0x11\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #1\n\
	beq _0809ED54\n\
	bl _0809F50A\n\
_0809ED54:\n\
	movs r0, #5\n\
	strh r0, [r3, #0xa]\n\
	bl _0809F50A\n\
	.align 2, 0\n\
_0809ED5C: .4byte gNonGameplayRam\n\
_0809ED60: .4byte 0x03000B94\n\
_0809ED64:\n\
	cmp r0, #1\n\
	beq _0809ED6C\n\
	bl _0809F50A\n\
_0809ED6C:\n\
	movs r0, #0x10\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #1\n\
	bne _0809ED7A\n\
_0809ED74:\n\
	strh r4, [r3, #0xa]\n\
	bl _0809F50A\n\
_0809ED7A:\n\
	movs r0, #7\n\
	strh r0, [r3, #0xa]\n\
	bl _0809F50A\n\
_0809ED82:\n\
	cmp r0, #1\n\
	bne _0809ED8C\n\
	movs r1, #0\n\
	movs r0, #0x10\n\
	b _0809EF1E\n\
_0809ED8C:\n\
	cmp r0, #2\n\
	beq _0809ED94\n\
	bl _0809F50A\n\
_0809ED94:\n\
	movs r0, #0x1b\n\
	strh r0, [r3, #0xa]\n\
	b _0809F50A\n\
_0809ED9A:\n\
	ldr r2, _0809EDB4 @ =gNonGameplayRam\n\
	ldrb r0, [r2, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r2, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x2a\n\
	beq _0809EDAC\n\
	b _0809F50A\n\
_0809EDAC:\n\
	movs r1, #0\n\
	movs r0, #6\n\
	b _0809F4A4\n\
	.align 2, 0\n\
_0809EDB4: .4byte gNonGameplayRam\n\
_0809EDB8:\n\
	ldr r2, _0809EDD0 @ =gNonGameplayRam\n\
	ldrb r0, [r2, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r2, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x2a\n\
	beq _0809EDCA\n\
	b _0809F50A\n\
_0809EDCA:\n\
	movs r1, #0\n\
	movs r0, #8\n\
	b _0809F4A4\n\
	.align 2, 0\n\
_0809EDD0: .4byte gNonGameplayRam\n\
_0809EDD4:\n\
	ldr r4, _0809EDF4 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809EDF8\n\
	movs r0, #0x17\n\
	movs r1, #0x9c\n\
	movs r2, #0x78\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	b _0809F3CA\n\
	.align 2, 0\n\
_0809EDF4: .4byte gNonGameplayRam\n\
_0809EDF8:\n\
	cmp r0, #2\n\
	bne _0809EDFE\n\
	b _0809F4D8\n\
_0809EDFE:\n\
	cmp r0, #3\n\
	bne _0809EE24\n\
	movs r0, #0x18\n\
	strh r0, [r4, #8]\n\
	ldr r1, _0809EE1C @ =0x0879EC68\n\
	ldr r0, _0809EE20 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x60]\n\
	str r0, [r4, #4]\n\
	b _0809F32C\n\
	.align 2, 0\n\
_0809EE1C: .4byte 0x0879EC68\n\
_0809EE20: .4byte 0x03000011\n\
_0809EE24:\n\
	cmp r0, #0xc\n\
	beq _0809EE2A\n\
	b _0809F50A\n\
_0809EE2A:\n\
	strb r1, [r4, #0xc]\n\
	movs r0, #0xa\n\
	strh r0, [r4, #0xa]\n\
	movs r0, #0x18\n\
	movs r1, #0x66\n\
	movs r2, #0x69\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	movs r0, #1\n\
	strb r0, [r4, #0x11]\n\
	b _0809F50A\n\
_0809EE42:\n\
	ldr r0, _0809EE58 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809EE60\n\
	ldr r1, _0809EE5C @ =gNonGameplayRam\n\
	movs r0, #0xb\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809EE58: .4byte gChangedInput\n\
_0809EE5C: .4byte gNonGameplayRam\n\
_0809EE60:\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0809EE6A\n\
	b _0809F50A\n\
_0809EE6A:\n\
	ldr r1, _0809EE78 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x10]\n\
	cmp r0, #0\n\
	bne _0809EE7C\n\
	movs r0, #0xc\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809EE78: .4byte gNonGameplayRam\n\
_0809EE7C:\n\
	movs r0, #0xd\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
_0809EE82:\n\
	ldr r4, _0809EE9C @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	beq _0809EE96\n\
	b _0809F3DA\n\
_0809EE96:\n\
	movs r0, #0x18\n\
	b _0809F3C6\n\
	.align 2, 0\n\
_0809EE9C: .4byte gNonGameplayRam\n\
_0809EEA0:\n\
	ldr r3, _0809EED0 @ =gNonGameplayRam\n\
	ldrb r0, [r3, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r3, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x2a\n\
	beq _0809EEB2\n\
	b _0809F50A\n\
_0809EEB2:\n\
	movs r0, #0\n\
	strb r0, [r3, #0xc]\n\
	ldr r2, _0809EED4 @ =0x03000B94\n\
	ldrb r1, [r3, #0xd]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _0809EED8\n\
	movs r0, #0xe\n\
	strh r0, [r3, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809EED0: .4byte gNonGameplayRam\n\
_0809EED4: .4byte 0x03000B94\n\
_0809EED8:\n\
	movs r0, #0xf\n\
	strh r0, [r3, #0xa]\n\
	b _0809F50A\n\
_0809EEDE:\n\
	ldr r3, _0809EF0C @ =gNonGameplayRam\n\
	ldrb r0, [r3, #0xc]\n\
	adds r0, #1\n\
	movs r4, #0\n\
	strb r0, [r3, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809EF14\n\
	ldr r2, _0809EF10 @ =0x03000B94\n\
	ldrb r1, [r3, #0xd]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	strb r4, [r0]\n\
	ldrb r1, [r3, #0xd]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	strb r4, [r0, #0x11]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809EF0C: .4byte gNonGameplayRam\n\
_0809EF10: .4byte 0x03000B94\n\
_0809EF14:\n\
	cmp r0, #0x2a\n\
	beq _0809EF1A\n\
	b _0809F50A\n\
_0809EF1A:\n\
	movs r1, #0\n\
	movs r0, #0xf\n\
_0809EF1E:\n\
	strh r0, [r3, #0xa]\n\
	strb r1, [r3, #0xc]\n\
	b _0809F50A\n\
_0809EF24:\n\
	ldr r0, _0809EF34 @ =0x03000B8D\n\
	ldr r1, _0809EF38 @ =gNonGameplayRam\n\
	ldrb r1, [r1, #0xd]\n\
	strb r1, [r0]\n\
	bl Sram_CheckLoadSaveFile\n\
	movs r7, #2\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809EF34: .4byte 0x03000B8D\n\
_0809EF38: .4byte gNonGameplayRam\n\
_0809EF3C:\n\
	ldr r0, _0809EF4C @ =0x03000B8D\n\
	ldr r1, _0809EF50 @ =gNonGameplayRam\n\
	ldrb r1, [r1, #0xd]\n\
	strb r1, [r0]\n\
	bl Sram_CheckLoadSaveFile\n\
	movs r7, #1\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809EF4C: .4byte 0x03000B8D\n\
_0809EF50: .4byte gNonGameplayRam\n\
_0809EF54:\n\
	ldr r2, _0809EF6C @ =gNonGameplayRam\n\
	ldrb r0, [r2, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r2, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809EF70\n\
	movs r0, #2\n\
	strb r0, [r2, #0x11]\n\
	movs r0, #0xc\n\
	b _0809F2F8\n\
	.align 2, 0\n\
_0809EF6C: .4byte gNonGameplayRam\n\
_0809EF70:\n\
	cmp r0, #2\n\
	bne _0809EF7A\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	b _0809F4DA\n\
_0809EF7A:\n\
	cmp r0, #3\n\
	bne _0809EFA0\n\
	movs r0, #2\n\
	strh r0, [r2, #8]\n\
	ldr r1, _0809EF98 @ =0x0879EC68\n\
	ldr r0, _0809EF9C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r2, #4]\n\
	b _0809F32C\n\
	.align 2, 0\n\
_0809EF98: .4byte 0x0879EC68\n\
_0809EF9C: .4byte 0x03000011\n\
_0809EFA0:\n\
	cmp r0, #0xc\n\
	beq _0809EFA6\n\
	b _0809F50A\n\
_0809EFA6:\n\
	movs r0, #0\n\
	movs r1, #0x11\n\
	strh r1, [r2, #0xa]\n\
	strb r0, [r2, #0xc]\n\
	strb r0, [r2, #0xf]\n\
	ldrb r0, [r2, #0xd]\n\
	cmp r0, #0\n\
	bne _0809EFC8\n\
	movs r0, #1\n\
	strb r0, [r2, #0xf]\n\
	movs r0, #3\n\
	movs r1, #0x84\n\
	movs r2, #0x30\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	b _0809EFD4\n\
_0809EFC8:\n\
	movs r0, #3\n\
	movs r1, #0x84\n\
	movs r2, #0x30\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
_0809EFD4:\n\
	ldr r1, _0809EFDC @ =gNonGameplayRam\n\
	movs r0, #1\n\
	strb r0, [r1, #0x11]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809EFDC: .4byte gNonGameplayRam\n\
_0809EFE0:\n\
	ldr r0, _0809EFF4 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809EFFC\n\
	ldr r1, _0809EFF8 @ =gNonGameplayRam\n\
	movs r0, #0x12\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809EFF4: .4byte gChangedInput\n\
_0809EFF8: .4byte gNonGameplayRam\n\
_0809EFFC:\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0809F006\n\
	b _0809F50A\n\
_0809F006:\n\
	ldr r2, _0809F034 @ =0x03000B94\n\
	ldr r3, _0809F038 @ =gNonGameplayRam\n\
	ldrb r1, [r3, #0xf]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r2\n\
	movs r0, #0x10\n\
	ldrsb r0, [r1, r0]\n\
	adds r4, r3, #0\n\
	cmp r0, #1\n\
	beq _0809F02C\n\
	movs r0, #0x11\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #1\n\
	beq _0809F02C\n\
	ldrb r0, [r1]\n\
	cmp r0, #1\n\
	bne _0809F03C\n\
_0809F02C:\n\
	movs r0, #0x13\n\
	strh r0, [r4, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F034: .4byte 0x03000B94\n\
_0809F038: .4byte gNonGameplayRam\n\
_0809F03C:\n\
	movs r0, #0x14\n\
	strh r0, [r3, #0xa]\n\
	b _0809F50A\n\
_0809F042:\n\
	ldr r4, _0809F058 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F05C\n\
	movs r0, #3\n\
	b _0809F3C6\n\
	.align 2, 0\n\
_0809F058: .4byte gNonGameplayRam\n\
_0809F05C:\n\
	cmp r0, #0xc\n\
	beq _0809F062\n\
	b _0809F50A\n\
_0809F062:\n\
	movs r0, #0\n\
	strb r0, [r4, #0xc]\n\
	b _0809F3E4\n\
_0809F068:\n\
	ldr r2, _0809F084 @ =gNonGameplayRam\n\
	ldrb r0, [r2, #0xc]\n\
	adds r0, #1\n\
	movs r3, #0\n\
	strb r0, [r2, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F088\n\
	movs r0, #2\n\
	strb r0, [r2, #0x11]\n\
	str r3, [sp]\n\
	b _0809F4DA\n\
	.align 2, 0\n\
_0809F084: .4byte gNonGameplayRam\n\
_0809F088:\n\
	cmp r0, #2\n\
	bne _0809F0B0\n\
	movs r0, #3\n\
	strh r0, [r2, #8]\n\
	ldr r1, _0809F0A8 @ =0x0879EC68\n\
	ldr r0, _0809F0AC @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0xc]\n\
	str r0, [r2, #4]\n\
	b _0809F32C\n\
	.align 2, 0\n\
_0809F0A8: .4byte 0x0879EC68\n\
_0809F0AC: .4byte 0x03000011\n\
_0809F0B0:\n\
	cmp r0, #4\n\
	beq _0809F0B6\n\
	b _0809F50A\n\
_0809F0B6:\n\
	movs r1, #1\n\
	strb r1, [r2, #0x11]\n\
	strb r3, [r2, #0xc]\n\
	movs r0, #0x16\n\
	strh r0, [r2, #0xa]\n\
	strb r1, [r2, #0x10]\n\
	ldr r1, _0809F0DC @ =0x0873DBB0\n\
	ldr r0, _0809F0E0 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #1\n\
	adds r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #4\n\
	movs r2, #0x91\n\
	b _0809F2FC\n\
	.align 2, 0\n\
_0809F0DC: .4byte 0x0873DBB0\n\
_0809F0E0: .4byte 0x03000011\n\
_0809F0E4:\n\
	ldr r2, _0809F120 @ =gNonGameplayRam\n\
	ldrb r0, [r2, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r2, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F0F6\n\
	b _0809F25A\n\
_0809F0F6:\n\
	cmp r0, #2\n\
	bne _0809F0FC\n\
	b _0809F278\n\
_0809F0FC:\n\
	cmp r0, #3\n\
	bne _0809F102\n\
	b _0809F286\n\
_0809F102:\n\
	cmp r0, #4\n\
	bne _0809F108\n\
	b _0809F294\n\
_0809F108:\n\
	cmp r0, #6\n\
	bne _0809F10E\n\
	b _0809F2A2\n\
_0809F10E:\n\
	cmp r0, #0xc\n\
	beq _0809F114\n\
	b _0809F50A\n\
_0809F114:\n\
	movs r0, #0\n\
	strb r0, [r2, #0xc]\n\
	movs r0, #0x15\n\
	strh r0, [r2, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F120: .4byte gNonGameplayRam\n\
_0809F124:\n\
	ldr r1, _0809F148 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xc]\n\
	adds r0, #1\n\
	movs r2, #0\n\
	strb r0, [r1, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F14C\n\
	movs r0, #5\n\
	strb r0, [r1, #0x11]\n\
	movs r0, #2\n\
	bl FileSelectDestroyOamOfType\n\
	movs r0, #3\n\
	bl FileSelectDestroyOamOfType\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F148: .4byte gNonGameplayRam\n\
_0809F14C:\n\
	cmp r0, #4\n\
	bne _0809F152\n\
	b _0809F50A\n\
_0809F152:\n\
	cmp r0, #0xc\n\
	beq _0809F158\n\
	b _0809F50A\n\
_0809F158:\n\
	strb r2, [r1, #0xf]\n\
	strb r2, [r1, #0xe]\n\
	strb r2, [r1, #0xc]\n\
	strh r2, [r1, #0xa]\n\
	b _0809F50A\n\
_0809F162:\n\
	ldr r0, _0809F178 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809F180\n\
	ldr r1, _0809F17C @ =gNonGameplayRam\n\
	movs r0, #0x17\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F178: .4byte gChangedInput\n\
_0809F17C: .4byte gNonGameplayRam\n\
_0809F180:\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0809F18A\n\
	b _0809F50A\n\
_0809F18A:\n\
	ldr r1, _0809F198 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x10]\n\
	cmp r0, #0\n\
	bne _0809F19C\n\
	movs r0, #0x19\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F198: .4byte gNonGameplayRam\n\
_0809F19C:\n\
	movs r0, #0x18\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
_0809F1A2:\n\
	ldr r4, _0809F1B8 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F1BC\n\
	movs r0, #4\n\
	b _0809F3C6\n\
	.align 2, 0\n\
_0809F1B8: .4byte gNonGameplayRam\n\
_0809F1BC:\n\
	cmp r0, #2\n\
	bne _0809F1C6\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	b _0809F4DA\n\
_0809F1C6:\n\
	cmp r0, #3\n\
	bne _0809F234\n\
	movs r0, #2\n\
	strh r0, [r4, #8]\n\
	ldr r1, _0809F1E4 @ =0x0879EC68\n\
	ldr r0, _0809F1E8 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #4]\n\
	b _0809F32C\n\
	.align 2, 0\n\
_0809F1E4: .4byte 0x0879EC68\n\
_0809F1E8: .4byte 0x03000011\n\
_0809F1EC:\n\
	ldr r4, _0809F200 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #9\n\
	bne _0809F204\n\
	movs r0, #4\n\
	b _0809F3C6\n\
	.align 2, 0\n\
_0809F200: .4byte gNonGameplayRam\n\
_0809F204:\n\
	cmp r0, #0xa\n\
	bne _0809F20E\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	b _0809F4DA\n\
_0809F20E:\n\
	cmp r0, #0xb\n\
	bne _0809F234\n\
	movs r0, #2\n\
	strh r0, [r4, #8]\n\
	ldr r1, _0809F22C @ =0x0879EC68\n\
	ldr r0, _0809F230 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #4]\n\
	b _0809F32C\n\
	.align 2, 0\n\
_0809F22C: .4byte 0x0879EC68\n\
_0809F230: .4byte 0x03000011\n\
_0809F234:\n\
	cmp r0, #0xc\n\
	beq _0809F23A\n\
	b _0809F50A\n\
_0809F23A:\n\
	movs r0, #1\n\
	strb r0, [r4, #0x11]\n\
	movs r1, #0\n\
	movs r0, #0x11\n\
	strh r0, [r4, #0xa]\n\
	strb r1, [r4, #0xc]\n\
	strb r1, [r4, #0x10]\n\
	b _0809F50A\n\
_0809F24A:\n\
	ldr r2, _0809F26C @ =gNonGameplayRam\n\
	ldrb r0, [r2, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r2, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F274\n\
_0809F25A:\n\
	ldr r0, _0809F270 @ =0x03000B8D\n\
	ldrb r1, [r2, #0xd]\n\
	strb r1, [r0]\n\
	ldrb r0, [r2, #0xf]\n\
	movs r1, #0\n\
	bl Sram_CopyFile\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F26C: .4byte gNonGameplayRam\n\
_0809F270: .4byte 0x03000B8D\n\
_0809F274:\n\
	cmp r0, #2\n\
	bne _0809F282\n\
_0809F278:\n\
	ldrb r0, [r2, #0xf]\n\
	movs r1, #1\n\
	bl Sram_CopyFile\n\
	b _0809F50A\n\
_0809F282:\n\
	cmp r0, #3\n\
	bne _0809F290\n\
_0809F286:\n\
	ldrb r0, [r2, #0xf]\n\
	movs r1, #2\n\
	bl Sram_CopyFile\n\
	b _0809F50A\n\
_0809F290:\n\
	cmp r0, #4\n\
	bne _0809F29E\n\
_0809F294:\n\
	ldrb r0, [r2, #0xf]\n\
	movs r1, #3\n\
	bl Sram_CopyFile\n\
	b _0809F50A\n\
_0809F29E:\n\
	cmp r0, #0xb\n\
	bne _0809F2AA\n\
_0809F2A2:\n\
	ldrb r0, [r2, #0xf]\n\
	bl FileSelectDrawFileInfo\n\
	b _0809F50A\n\
_0809F2AA:\n\
	cmp r0, #0xc\n\
	beq _0809F2B0\n\
	b _0809F50A\n\
_0809F2B0:\n\
	movs r1, #0\n\
	movs r0, #0x1a\n\
	b _0809F4A4\n\
_0809F2B6:\n\
	ldr r4, _0809F2D8 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F2DC\n\
	movs r0, #2\n\
	bl FileSelectDestroyOamOfType\n\
	movs r0, #3\n\
	bl FileSelectDestroyOamOfType\n\
	movs r0, #4\n\
	b _0809F4C4\n\
	.align 2, 0\n\
_0809F2D8: .4byte gNonGameplayRam\n\
_0809F2DC:\n\
	cmp r0, #2\n\
	bne _0809F2E2\n\
	b _0809F4D8\n\
_0809F2E2:\n\
	b _0809F4F8\n\
_0809F2E4:\n\
	ldr r5, _0809F304 @ =gNonGameplayRam\n\
	ldrb r0, [r5, #0xc]\n\
	adds r0, #1\n\
	movs r6, #0\n\
	strb r0, [r5, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F308\n\
	movs r0, #0xd\n\
_0809F2F8:\n\
	movs r1, #0x9c\n\
	movs r2, #0x78\n\
_0809F2FC:\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F304: .4byte gNonGameplayRam\n\
_0809F308:\n\
	cmp r0, #2\n\
	bne _0809F310\n\
	str r6, [sp]\n\
	b _0809F4DA\n\
_0809F310:\n\
	cmp r0, #3\n\
	bne _0809F33C\n\
	movs r0, #4\n\
	strh r0, [r5, #8]\n\
	ldr r1, _0809F334 @ =0x0879EC68\n\
	ldr r0, _0809F338 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x10]\n\
	str r0, [r5, #4]\n\
_0809F32C:\n\
	movs r0, #3\n\
	bl FileSelectDrawText\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F334: .4byte 0x0879EC68\n\
_0809F338: .4byte 0x03000011\n\
_0809F33C:\n\
	cmp r0, #0xc\n\
	beq _0809F342\n\
	b _0809F50A\n\
_0809F342:\n\
	movs r4, #1\n\
	strb r4, [r5, #0x10]\n\
	ldr r1, _0809F36C @ =0x0873DBBE\n\
	ldr r0, _0809F370 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #1\n\
	adds r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #5\n\
	movs r2, #0x91\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	strb r4, [r5, #0x11]\n\
	strb r6, [r5, #0xc]\n\
	movs r0, #0x1c\n\
	strh r0, [r5, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F36C: .4byte 0x0873DBBE\n\
_0809F370: .4byte 0x03000011\n\
_0809F374:\n\
	ldr r0, _0809F388 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809F390\n\
	ldr r1, _0809F38C @ =gNonGameplayRam\n\
	movs r0, #0x1d\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F388: .4byte gChangedInput\n\
_0809F38C: .4byte gNonGameplayRam\n\
_0809F390:\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0809F39A\n\
	b _0809F50A\n\
_0809F39A:\n\
	ldr r1, _0809F3A8 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x10]\n\
	cmp r0, #0\n\
	bne _0809F3AC\n\
	movs r0, #0x20\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F3A8: .4byte gNonGameplayRam\n\
_0809F3AC:\n\
	movs r0, #0x1e\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
_0809F3B2:\n\
	ldr r4, _0809F3D0 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F3D4\n\
	movs r0, #5\n\
_0809F3C6:\n\
	bl FileSelectDestroyOamOfType\n\
_0809F3CA:\n\
	movs r0, #2\n\
	strb r0, [r4, #0x11]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F3D0: .4byte gNonGameplayRam\n\
_0809F3D4:\n\
	cmp r0, #2\n\
	bne _0809F3DA\n\
	b _0809F4D8\n\
_0809F3DA:\n\
	cmp r0, #0xc\n\
	beq _0809F3E0\n\
	b _0809F50A\n\
_0809F3E0:\n\
	strb r1, [r4, #0xc]\n\
	strb r1, [r4, #0x10]\n\
_0809F3E4:\n\
	movs r0, #3\n\
	strh r0, [r4, #0xa]\n\
	b _0809F50A\n\
_0809F3EA:\n\
	ldr r4, _0809F414 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	movs r5, #0\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #8\n\
	beq _0809F3FE\n\
	b _0809F50A\n\
_0809F3FE:\n\
	movs r0, #5\n\
	bl FileSelectDestroyOamOfType\n\
	movs r0, #2\n\
	strb r0, [r4, #0x11]\n\
	strb r5, [r4, #0xc]\n\
	strb r5, [r4, #0x10]\n\
	movs r0, #0x1f\n\
	strh r0, [r4, #0xa]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F414: .4byte gNonGameplayRam\n\
_0809F418:\n\
	ldr r1, _0809F434 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xc]\n\
	adds r0, #1\n\
	movs r2, #0\n\
	strb r0, [r1, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #6\n\
	beq _0809F50A\n\
	cmp r0, #0xb\n\
	bne _0809F438\n\
	str r2, [sp]\n\
	b _0809F4DA\n\
	.align 2, 0\n\
_0809F434: .4byte gNonGameplayRam\n\
_0809F438:\n\
	cmp r0, #0xc\n\
	bne _0809F50A\n\
	strb r2, [r1, #0xc]\n\
	strb r2, [r1, #0x10]\n\
	movs r0, #3\n\
	strh r0, [r1, #0xa]\n\
	b _0809F50A\n\
_0809F446:\n\
	ldr r2, _0809F464 @ =gNonGameplayRam\n\
	ldrb r0, [r2, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r2, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F46C\n\
	ldr r1, _0809F468 @ =0x03000B8D\n\
	ldrb r0, [r2, #0xd]\n\
	strb r0, [r1]\n\
	movs r0, #0\n\
	bl Sram_EraseFile\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F464: .4byte gNonGameplayRam\n\
_0809F468: .4byte 0x03000B8D\n\
_0809F46C:\n\
	cmp r0, #2\n\
	bne _0809F478\n\
	movs r0, #1\n\
	bl Sram_EraseFile\n\
	b _0809F50A\n\
_0809F478:\n\
	cmp r0, #3\n\
	bne _0809F484\n\
	movs r0, #2\n\
	bl Sram_EraseFile\n\
	b _0809F50A\n\
_0809F484:\n\
	cmp r0, #4\n\
	bne _0809F490\n\
	movs r0, #3\n\
	bl Sram_EraseFile\n\
	b _0809F50A\n\
_0809F490:\n\
	cmp r0, #0xb\n\
	bne _0809F49C\n\
	ldrb r0, [r2, #0xd]\n\
	bl FileSelectDrawFileInfo\n\
	b _0809F50A\n\
_0809F49C:\n\
	cmp r0, #0xc\n\
	bne _0809F50A\n\
	movs r1, #0\n\
	movs r0, #0x21\n\
_0809F4A4:\n\
	strh r0, [r2, #0xa]\n\
	strb r1, [r2, #0xc]\n\
	b _0809F50A\n\
_0809F4AA:\n\
	ldr r4, _0809F4D0 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809F4D4\n\
	movs r0, #2\n\
	bl FileSelectDestroyOamOfType\n\
	movs r0, #5\n\
_0809F4C4:\n\
	bl FileSelectDestroyOamOfType\n\
	movs r0, #5\n\
	strb r0, [r4, #0x11]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F4D0: .4byte gNonGameplayRam\n\
_0809F4D4:\n\
	cmp r0, #2\n\
	bne _0809F4F8\n\
_0809F4D8:\n\
	str r1, [sp]\n\
_0809F4DA:\n\
	ldr r1, _0809F4EC @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	ldr r0, _0809F4F0 @ =0x0600C800\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809F4F4 @ =0x85000600\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	b _0809F50A\n\
	.align 2, 0\n\
_0809F4EC: .4byte 0x040000D4\n\
_0809F4F0: .4byte 0x0600C800\n\
_0809F4F4: .4byte 0x85000600\n\
_0809F4F8:\n\
	cmp r0, #0xc\n\
	bne _0809F50A\n\
	strb r1, [r4, #0x10]\n\
	strb r1, [r4, #0xf]\n\
	strb r1, [r4, #0xe]\n\
_0809F502:\n\
	strb r1, [r4, #0xc]\n\
	strh r1, [r4, #0xa]\n\
	b _0809F50A\n\
_0809F508:\n\
	movs r7, #3\n\
_0809F50A:\n\
	bl FileSelectDrawAllOam\n\
	adds r0, r7, #0\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

// 0x0809F518
NAKED_FUNCTION
u8 FileSelectSetupOam(u32 type, u32 xPosition, u32 yPosition, u32 unused)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov sb, r1\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	mov r8, r2\n\
	movs r4, #0x16\n\
	ldr r1, _0809F574 @ =gNonGameplayRam\n\
	movs r2, #0x9a\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0, #0x1c]\n\
	adds r5, r1, #0\n\
	cmp r0, #0\n\
	beq _0809F564\n\
	adds r6, r5, #0\n\
_0809F546:\n\
	lsls r0, r4, #0x18\n\
	movs r1, #0xff\n\
	lsls r1, r1, #0x18\n\
	adds r0, r0, r1\n\
	lsrs r4, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	blt _0809F56E\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r6\n\
	ldrb r0, [r0, #0x1c]\n\
	cmp r0, #0\n\
	bne _0809F546\n\
_0809F564:\n\
	lsls r0, r4, #0x18\n\
	asrs r2, r0, #0x18\n\
	adds r6, r0, #0\n\
	cmp r2, #0\n\
	bge _0809F578\n\
_0809F56E:\n\
	movs r0, #0x17\n\
	b _0809F91A\n\
	.align 2, 0\n\
_0809F574: .4byte gNonGameplayRam\n\
_0809F578:\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r1, _0809F5C4 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	lsls r4, r0, #2\n\
	ldr r2, _0809F5C8 @ =0x0300149C\n\
	mov ip, r2\n\
	adds r0, r4, r2\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809F5CC @ =0x85000007\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	mov r0, ip\n\
	subs r0, #0x18\n\
	adds r1, r4, r0\n\
	movs r7, #0\n\
	mov r0, sb\n\
	strh r0, [r1, #0x18]\n\
	mov r2, r8\n\
	strh r2, [r1, #0x1a]\n\
	strb r3, [r1, #0x1c]\n\
	movs r2, #1\n\
	strb r2, [r1, #0x1d]\n\
	cmp r3, #1\n\
	bne _0809F5D8\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F5D0 @ =0x08740A48\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F5D4 @ =FileSelectProcessSamusHead\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F5C4: .4byte 0x040000D4\n\
_0809F5C8: .4byte 0x0300149C\n\
_0809F5CC: .4byte 0x85000007\n\
_0809F5D0: .4byte 0x08740A48\n\
_0809F5D4: .4byte FileSelectProcessSamusHead\n\
_0809F5D8:\n\
	cmp r3, #2\n\
	bne _0809F5F8\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F5F0 @ =0x08740B48\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F5F4 @ =FileSelectProcessCursor\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F5F0: .4byte 0x08740B48\n\
_0809F5F4: .4byte FileSelectProcessCursor\n\
_0809F5F8:\n\
	cmp r3, #3\n\
	bne _0809F620\n\
	adds r0, r1, #0\n\
	adds r0, #0x23\n\
	strb r2, [r0]\n\
	strb r7, [r1, #0x1d]\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F618 @ =0x08740AB8\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F61C @ =FileSelectProcessDeleteArrow\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F618: .4byte 0x08740AB8\n\
_0809F61C: .4byte FileSelectProcessDeleteArrow\n\
_0809F620:\n\
	cmp r3, #4\n\
	bne _0809F640\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F638 @ =0x08740B48\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F63C @ =unk_9fddc\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F638: .4byte 0x08740B48\n\
_0809F63C: .4byte unk_9fddc\n\
_0809F640:\n\
	cmp r3, #5\n\
	bne _0809F660\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F658 @ =0x08740B48\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F65C @ =unk_9ff00\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F658: .4byte 0x08740B48\n\
_0809F65C: .4byte unk_9ff00\n\
_0809F660:\n\
	cmp r3, #6\n\
	bne _0809F688\n\
	adds r1, #0x23\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F680 @ =0x087407E0\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F684 @ =FileSelectProcessAudioLogos\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F680: .4byte 0x087407E0\n\
_0809F684: .4byte FileSelectProcessAudioLogos\n\
_0809F688:\n\
	cmp r3, #7\n\
	bne _0809F6BC\n\
	adds r1, #0x23\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	mov r1, ip\n\
	adds r1, #0x14\n\
	adds r1, r4, r1\n\
	ldr r2, _0809F6B0 @ =0x0879E890\n\
	ldr r0, _0809F6B4 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F6B8 @ =FileSelectProcessFileOverlay\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F6B0: .4byte 0x0879E890\n\
_0809F6B4: .4byte 0x03000B8D\n\
_0809F6B8: .4byte FileSelectProcessFileOverlay\n\
_0809F6BC:\n\
	cmp r3, #8\n\
	bne _0809F6E4\n\
	adds r1, #0x23\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F6DC @ =0x087408E0\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F6E0 @ =unk_a016c\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F6DC: .4byte 0x087408E0\n\
_0809F6E0: .4byte unk_a016c\n\
_0809F6E4:\n\
	cmp r3, #9\n\
	bne _0809F70C\n\
	strb r7, [r1, #0x1d]\n\
	adds r1, #0x23\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F704 @ =0x087408F0\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F708 @ =FileSelectProcessAudioSelect\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F704: .4byte 0x087408F0\n\
_0809F708: .4byte FileSelectProcessAudioSelect\n\
_0809F70C:\n\
	cmp r3, #0xa\n\
	bne _0809F72C\n\
	mov r0, ip\n\
	adds r0, #0x14\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F724 @ =0x08740880\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x18\n\
	adds r0, r4, r0\n\
	ldr r1, _0809F728 @ =unk_a01cc\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F724: .4byte 0x08740880\n\
_0809F728: .4byte unk_a01cc\n\
_0809F72C:\n\
	cmp r3, #0xb\n\
	bne _0809F76C\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	ldr r3, _0809F760 @ =gNonGameplayRam\n\
	asrs r0, r6, #0x18\n\
	lsls r1, r0, #3\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r0, r1, r3\n\
	adds r0, #0x23\n\
	movs r2, #2\n\
	strb r2, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x2c\n\
	adds r0, r1, r0\n\
	ldr r2, _0809F764 @ =0x08740918\n\
	str r2, [r0]\n\
	adds r3, #0x30\n\
	adds r1, r1, r3\n\
	ldr r0, _0809F768 @ =FileSelectProcessFileActionPanel\n\
	str r0, [r1]\n\
	b _0809F918\n\
	.align 2, 0\n\
_0809F760: .4byte gNonGameplayRam\n\
_0809F764: .4byte 0x08740918\n\
_0809F768: .4byte FileSelectProcessFileActionPanel\n\
_0809F76C:\n\
	cmp r3, #0xc\n\
	bne _0809F7AC\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	ldr r3, _0809F7A0 @ =gNonGameplayRam\n\
	asrs r0, r6, #0x18\n\
	lsls r1, r0, #3\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r0, r1, r3\n\
	adds r0, #0x23\n\
	movs r2, #1\n\
	strb r2, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x2c\n\
	adds r0, r1, r0\n\
	ldr r2, _0809F7A4 @ =0x08740978\n\
	str r2, [r0]\n\
	adds r3, #0x30\n\
	adds r1, r1, r3\n\
	ldr r0, _0809F7A8 @ =FileSelectProcessCopyFilePanel\n\
	str r0, [r1]\n\
	b _0809F918\n\
	.align 2, 0\n\
_0809F7A0: .4byte gNonGameplayRam\n\
_0809F7A4: .4byte 0x08740978\n\
_0809F7A8: .4byte FileSelectProcessCopyFilePanel\n\
_0809F7AC:\n\
	cmp r3, #0xd\n\
	bne _0809F7EC\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	ldr r3, _0809F7E0 @ =gNonGameplayRam\n\
	asrs r0, r6, #0x18\n\
	lsls r1, r0, #3\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r0, r1, r3\n\
	adds r0, #0x23\n\
	movs r2, #1\n\
	strb r2, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x2c\n\
	adds r0, r1, r0\n\
	ldr r2, _0809F7E4 @ =0x08740978\n\
	str r2, [r0]\n\
	adds r3, #0x30\n\
	adds r1, r1, r3\n\
	ldr r0, _0809F7E8 @ =FileSelectProcessEraseFilePanel\n\
	str r0, [r1]\n\
	b _0809F918\n\
	.align 2, 0\n\
_0809F7E0: .4byte gNonGameplayRam\n\
_0809F7E4: .4byte 0x08740978\n\
_0809F7E8: .4byte FileSelectProcessEraseFilePanel\n\
_0809F7EC:\n\
	cmp r3, #0xe\n\
	bne _0809F810\n\
	asrs r1, r6, #0x18\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r5\n\
	adds r1, #0x23\n\
	movs r2, #3\n\
	strb r2, [r1]\n\
	adds r1, r5, #0\n\
	adds r1, #0x30\n\
	adds r0, r0, r1\n\
	ldr r1, _0809F80C @ =unk_a0518\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F80C: .4byte unk_a0518\n\
_0809F810:\n\
	cmp r3, #0xf\n\
	bne _0809F834\n\
	asrs r1, r6, #0x18\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r5\n\
	adds r1, #0x23\n\
	movs r2, #3\n\
	strb r2, [r1]\n\
	adds r1, r5, #0\n\
	adds r1, #0x30\n\
	adds r0, r0, r1\n\
	ldr r1, _0809F830 @ =unk_a0518\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F830: .4byte unk_a0518\n\
_0809F834:\n\
	cmp r3, #0x10\n\
	bne _0809F858\n\
	asrs r1, r6, #0x18\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r5\n\
	adds r1, #0x23\n\
	movs r2, #3\n\
	strb r2, [r1]\n\
	adds r1, r5, #0\n\
	adds r1, #0x30\n\
	adds r0, r0, r1\n\
	ldr r1, _0809F854 @ =unk_a0518\n\
	b _0809F916\n\
	.align 2, 0\n\
_0809F854: .4byte unk_a0518\n\
_0809F858:\n\
	cmp r3, #0x11\n\
	bne _0809F87C\n\
	asrs r0, r6, #0x18\n\
	lsls r1, r0, #3\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r0, r1, r5\n\
	adds r0, #0x23\n\
	movs r2, #2\n\
	strb r2, [r0]\n\
	adds r0, r5, #0\n\
	adds r0, #0x2c\n\
	adds r0, r1, r0\n\
	ldr r2, _0809F878 @ =0x087409A0\n\
	b _0809F8A0\n\
	.align 2, 0\n\
_0809F878: .4byte 0x087409A0\n\
_0809F87C:\n\
	cmp r3, #0x14\n\
	beq _0809F888\n\
	cmp r3, #0x15\n\
	beq _0809F888\n\
	cmp r3, #0x16\n\
	bne _0809F8B8\n\
_0809F888:\n\
	asrs r0, r6, #0x18\n\
	lsls r1, r0, #3\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r0, r1, r5\n\
	adds r0, #0x23\n\
	movs r2, #3\n\
	strb r2, [r0]\n\
	adds r0, r5, #0\n\
	adds r0, #0x2c\n\
	adds r0, r1, r0\n\
	ldr r2, _0809F8B0 @ =0x08740B98\n\
_0809F8A0:\n\
	str r2, [r0]\n\
	adds r0, r5, #0\n\
	adds r0, #0x30\n\
	adds r1, r1, r0\n\
	ldr r0, _0809F8B4 @ =unk_a0518\n\
	str r0, [r1]\n\
	b _0809F918\n\
	.align 2, 0\n\
_0809F8B0: .4byte 0x08740B98\n\
_0809F8B4: .4byte unk_a0518\n\
_0809F8B8:\n\
	cmp r3, #0x17\n\
	bne _0809F8F8\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	ldr r3, _0809F8EC @ =gNonGameplayRam\n\
	asrs r0, r6, #0x18\n\
	lsls r1, r0, #3\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r0, r1, r3\n\
	adds r0, #0x23\n\
	movs r2, #1\n\
	strb r2, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x2c\n\
	adds r0, r1, r0\n\
	ldr r2, _0809F8F0 @ =0x08740978\n\
	str r2, [r0]\n\
	adds r3, #0x30\n\
	adds r1, r1, r3\n\
	ldr r0, _0809F8F4 @ =unk_a039c\n\
	str r0, [r1]\n\
	b _0809F918\n\
	.align 2, 0\n\
_0809F8EC: .4byte gNonGameplayRam\n\
_0809F8F0: .4byte 0x08740978\n\
_0809F8F4: .4byte unk_a039c\n\
_0809F8F8:\n\
	cmp r3, #0x18\n\
	bne _0809F918\n\
	asrs r1, r6, #0x18\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r1, r5, #0\n\
	adds r1, #0x2c\n\
	adds r1, r0, r1\n\
	ldr r2, _0809F928 @ =0x08740B48\n\
	str r2, [r1]\n\
	adds r1, r5, #0\n\
	adds r1, #0x30\n\
	adds r0, r0, r1\n\
	ldr r1, _0809F92C @ =unk_a0424\n\
_0809F916:\n\
	str r1, [r0]\n\
_0809F918:\n\
	lsrs r0, r6, #0x18\n\
_0809F91A:\n\
	add sp, #4\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809F928: .4byte 0x08740B48\n\
_0809F92C: .4byte unk_a0424\n\
    .syntax divided\n");
}

/**
 * @brief 9f930 | 1a4 | TODO
 * 
 */
void FileSelectProcessSamusHead(struct FileSelectOam* pOam)
{
    const struct FrameData* pFrame;
    s32 menuState;

    if (pOam->action == 0)
    {
        if (gChangedInput & KEY_UP)
        {
            switch (FILE_SELECT_DATA.currentFile)
            {
                case 1:
                case 2:
                    pOam->xPosition = 15;
                    pOam->yPosition -= 16;
                    FILE_SELECT_DATA.currentFile--;
                    SoundPlay(0x1F9);
                    break;

                case 3:
                    pOam->xPosition = 15;
                    pOam->yPosition -= 37;
                    FILE_SELECT_DATA.currentFile--;
                    SoundPlay(0x1F9);
                    break;

                case 4:
                    pOam->xPosition = 15;
                    pOam->yPosition -= 40;
                    FILE_SELECT_DATA.currentFile--;
                    SoundPlay(0x1F9);
                    break;
            }
        }
        else if (gChangedInput & KEY_DOWN)
        {
            switch (FILE_SELECT_DATA.currentFile)
            {
                case 0:
                case 1:
                    pOam->xPosition = 15;
                    pOam->yPosition += 16;
                    FILE_SELECT_DATA.currentFile++;
                    SoundPlay(0x1F9);
                    break;

                case 2:
                    pOam->xPosition = 15;
                    pOam->yPosition += 37;
                    FILE_SELECT_DATA.currentFile++;
                    SoundPlay(0x1F9);
                    break;

                case 3:
                    pOam->xPosition = 15;
                    pOam->yPosition += 40;
                    FILE_SELECT_DATA.currentFile++;
                    SoundPlay(0x1F9);
                    break;
            }
        }

        if (FILE_SELECT_DATA.currentFile != 3 && gChangedInput & (KEY_A | KEY_START))
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->action = 100;
            SoundPlay(0x1FB);
        }
    }
    else if (pOam->action == 1)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->action = 100;
        }

        if (FILE_SELECT_DATA.stage == 11)
            pOam->action = 100;
    }
    else if (pOam->action == 100)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter)
            menuState = FILE_SELECT_DATA.menuState;
        else
            menuState = FILE_SELECT_DATA.menuState;
        if (menuState == 0)
        {
            pOam->animationDurationCounter = menuState;
            pOam->currentAnimationFrame = menuState;
            pOam->pOam = (const struct FrameData*)0x8740a48;
            pOam->action = menuState;
        }
        else if (menuState == 5 || menuState == 7 || menuState == 12 || menuState == 13)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x8740a70;
            pOam->action = 200;
        }
    }
    else
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
            pOam->animationDurationCounter = 0;
    }
}

/**
 * @brief 9fad4 | 1bc | TODO
 * 
 */
void FileSelectProcessCursor(struct FileSelectOam* pOam)
{
    const struct FrameData* pFrame;
    u32 cancel;
    s32 menuState;

    if (pOam->action == 0)
    {
        menuState = FILE_SELECT_DATA.menuState;
        if (menuState == 2)
        {
            if (gChangedInput & KEY_B)
            {
                pOam->action = 100;
                return;
            }

            if (!(gChangedInput & (KEY_A | KEY_START)))
                return;

            if (gSaveFilesInfo[FILE_SELECT_DATA.currentFile].completedGame == TRUE)
                SoundPlay(0x1FB);
            else
                SoundPlay(0x1FE);

            FILE_SELECT_DATA.unk_E = 0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x8740b70;
            pOam->action = 100;
        }
        else if (menuState == 3)
        {
            if (gChangedInput & KEY_UP)
            {
                if (FILE_SELECT_DATA.unk_E != 0)
                {
                    FILE_SELECT_DATA.unk_E--;
                    pOam->yPosition -= 16;
                    SoundPlay(0x1F9);
                }
            }
            else if (gChangedInput & KEY_DOWN)
            {
                if (FILE_SELECT_DATA.unk_E <= 1)
                {
                    FILE_SELECT_DATA.unk_E++;
                    pOam->yPosition += 16;
                    SoundPlay(0x1F9);
                }
            }

            if ((cancel = gChangedInput & KEY_B))
            {
                pOam->action = 100;
                return;
            }

            if (gChangedInput & (KEY_A | KEY_START))
            {
                pOam->animationDurationCounter = cancel;
                pOam->currentAnimationFrame = cancel;
                pOam->pOam = (const struct FrameData*)0x8740b70;
                if (FILE_SELECT_DATA.unk_E == 0)
                {
                    pOam->action = 100;
                    if (gSaveFilesInfo[FILE_SELECT_DATA.currentFile].completedGame == TRUE)
                        SoundPlay(0x1FB);
                    else
                        SoundPlay(0x1FE);
                }
                else
                {
                    SoundPlay(0x1FB);
                    pOam->action = 1;
                }
            }
        }
    }
    else if (pOam->action == 1)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->action = 100;
        }

        if (FILE_SELECT_DATA.stage == 11)
            pOam->action = 100;
    }
    else
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
            pOam->animationDurationCounter = 0;

        if (FILE_SELECT_DATA.menuState == 3)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x8740b48;
            pOam->action = 0;
        }
    }
}

// 0x0809FC90
NAKED_FUNCTION
void FileSelectProcessDeleteArrow(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r0, #0\n\
	movs r7, #0\n\
	movs r6, #0\n\
	ldrb r0, [r4, #9]\n\
	cmp r0, #0\n\
	bne _0809FD7C\n\
	movs r0, #1\n\
	strb r0, [r4, #5]\n\
	ldr r1, _0809FCD0 @ =gChangedInput\n\
	ldrh r2, [r1]\n\
	movs r0, #0x40\n\
	ands r0, r2\n\
	mov ip, r1\n\
	cmp r0, #0\n\
	beq _0809FCDC\n\
	ldr r0, _0809FCD4 @ =gNonGameplayRam\n\
	ldrb r1, [r0, #0xf]\n\
	adds r5, r0, #0\n\
	cmp r1, #0\n\
	beq _0809FCC0\n\
	subs r0, r1, #1\n\
	strb r0, [r5, #0xf]\n\
	movs r6, #1\n\
_0809FCC0:\n\
	ldrb r0, [r5, #0xf]\n\
	ldrb r1, [r5, #0xd]\n\
	cmp r1, r0\n\
	bne _0809FD12\n\
	cmp r1, #0\n\
	bne _0809FCD8\n\
	adds r0, #1\n\
	b _0809FD00\n\
	.align 2, 0\n\
_0809FCD0: .4byte gChangedInput\n\
_0809FCD4: .4byte gNonGameplayRam\n\
_0809FCD8:\n\
	subs r0, #1\n\
	b _0809FD0E\n\
_0809FCDC:\n\
	movs r0, #0x80\n\
	ands r0, r2\n\
	ldr r5, _0809FD08 @ =gNonGameplayRam\n\
	cmp r0, #0\n\
	beq _0809FD12\n\
	ldrb r0, [r5, #0xf]\n\
	cmp r0, #1\n\
	bhi _0809FCF2\n\
	adds r0, #1\n\
	strb r0, [r5, #0xf]\n\
	movs r6, #1\n\
_0809FCF2:\n\
	ldrb r0, [r5, #0xf]\n\
	ldrb r1, [r5, #0xd]\n\
	cmp r1, r0\n\
	bne _0809FD12\n\
	cmp r1, #2\n\
	bne _0809FD0C\n\
	subs r0, #1\n\
_0809FD00:\n\
	strb r0, [r5, #0xf]\n\
	movs r6, #0\n\
	b _0809FD12\n\
	.align 2, 0\n\
_0809FD08: .4byte gNonGameplayRam\n\
_0809FD0C:\n\
	adds r0, #1\n\
_0809FD0E:\n\
	strb r0, [r5, #0xf]\n\
	movs r6, #1\n\
_0809FD12:\n\
	ldr r3, _0809FD70 @ =0x0879E8A4\n\
	adds r2, r5, #0\n\
	ldrb r1, [r2, #0xd]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r2, [r2, #0xf]\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	ldr r0, [r0]\n\
	str r0, [r4, #0x14]\n\
	mov r0, ip\n\
	ldrh r1, [r0]\n\
	movs r0, #2\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r2, #0\n\
	bne _0809FD88\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809FDA4\n\
	strb r2, [r4, #7]\n\
	strb r2, [r4, #6]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	ldr r2, _0809FD74 @ =0x03000B94\n\
	ldrb r1, [r5, #0xf]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r2, r0, r2\n\
	movs r0, #0x10\n\
	ldrsb r0, [r2, r0]\n\
	cmp r0, #1\n\
	beq _0809FD6A\n\
	movs r0, #0x11\n\
	ldrsb r0, [r2, r0]\n\
	cmp r0, #1\n\
	beq _0809FD6A\n\
	ldrb r0, [r2]\n\
	cmp r0, #1\n\
	bne _0809FD78\n\
_0809FD6A:\n\
	movs r7, #1\n\
	b _0809FDA4\n\
	.align 2, 0\n\
_0809FD70: .4byte 0x0879E8A4\n\
_0809FD74: .4byte 0x03000B94\n\
_0809FD78:\n\
	movs r7, #2\n\
	b _0809FDA4\n\
_0809FD7C:\n\
	cmp r0, #1\n\
	bne _0809FD94\n\
	ldr r0, _0809FD90 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #0xb\n\
	bne _0809FDA4\n\
_0809FD88:\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
	b _0809FDA4\n\
	.align 2, 0\n\
_0809FD90: .4byte gNonGameplayRam\n\
_0809FD94:\n\
	ldr r0, _0809FDBC @ =gNonGameplayRam\n\
	movs r1, #0xa\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0x11\n\
	bne _0809FDA4\n\
	strb r7, [r4, #7]\n\
	strb r7, [r4, #6]\n\
	strb r7, [r4, #9]\n\
_0809FDA4:\n\
	cmp r6, #0\n\
	beq _0809FDAE\n\
	ldr r0, _0809FDC0 @ =0x000001F9\n\
	bl SoundPlay\n\
_0809FDAE:\n\
	cmp r7, #1\n\
	bne _0809FDC8\n\
	ldr r0, _0809FDC4 @ =0x000001FB\n\
	bl SoundPlay\n\
	b _0809FDD2\n\
	.align 2, 0\n\
_0809FDBC: .4byte gNonGameplayRam\n\
_0809FDC0: .4byte 0x000001F9\n\
_0809FDC4: .4byte 0x000001FB\n\
_0809FDC8:\n\
	cmp r7, #2\n\
	bne _0809FDD2\n\
	ldr r0, _0809FDD8 @ =0x00000207\n\
	bl SoundPlay\n\
_0809FDD2:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809FDD8: .4byte 0x00000207\n\
    .syntax divided\n");
}

/**
 * @brief 9fddc | 124 | TODO
 * 
 */
void unk_9fddc(struct FileSelectOam* pOam)
{
    const struct FrameData* pFrame;
    u16 cancel;
    u8 action;

    action = pOam->action;
    if (action == 0)
    {
        if (FILE_SELECT_DATA.unk_10 == 0)
        {
            if (gChangedInput & KEY_RIGHT)
            {
                FILE_SELECT_DATA.unk_10 = 1;
                pOam->xPosition = sFileSelectCopyArrowXPositions[gLanguage][1];
                SoundPlay(0x1FA);
            }
        }
        else if (FILE_SELECT_DATA.unk_10 == 1)
        {
            if (gChangedInput & KEY_LEFT)
            {
                FILE_SELECT_DATA.unk_10 = action;
                pOam->xPosition = sFileSelectCopyArrowXPositions[gLanguage][0];
                SoundPlay(0x1FA);
            }
        }

        if ((cancel = gChangedInput & KEY_B))
        {
            pOam->action = 100;
        }
        else if (gChangedInput & (KEY_A | KEY_START))
        {
            pOam->animationDurationCounter = cancel;
            pOam->currentAnimationFrame = cancel;
            if (FILE_SELECT_DATA.unk_10 == 0)
            {
                SoundPlay(0x207);
                pOam->pOam = (const struct FrameData*)0x8740b70;
                pOam->action = 1;
            }
            else
            {
                SoundPlay(0x1FB);
                pOam->pOam = (const struct FrameData*)0x8740b70;
                pOam->action = 1;
            }
        }
    }
    else if (action == 1)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
            pOam->animationDurationCounter = 0;

        if (FILE_SELECT_DATA.stage == 11)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->action = 100;
        }
    }
    else
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
            pOam->animationDurationCounter = 0;
    }
}

/**
 * @brief 9ff00 | 124 | TODO
 * 
 */
void unk_9ff00(struct FileSelectOam* pOam)
{
    const struct FrameData* pFrame;
    u16 cancel;
    u8 action;

    action = pOam->action;
    if (action == 0)
    {
        if (FILE_SELECT_DATA.unk_10 == 0)
        {
            if (gChangedInput & KEY_RIGHT)
            {
                FILE_SELECT_DATA.unk_10 = 1;
                pOam->xPosition = sFileSelectEraseArrowXPositions[gLanguage][1];
                SoundPlay(0x1FA);
            }
        }
        else if (FILE_SELECT_DATA.unk_10 == 1)
        {
            if (gChangedInput & KEY_LEFT)
            {
                FILE_SELECT_DATA.unk_10 = action;
                pOam->xPosition = sFileSelectEraseArrowXPositions[gLanguage][0];
                SoundPlay(0x1FA);
            }
        }

        if ((cancel = gChangedInput & KEY_B))
        {
            pOam->action = 100;
        }
        else if (gChangedInput & (KEY_A | KEY_START))
        {
            pOam->animationDurationCounter = cancel;
            pOam->currentAnimationFrame = cancel;
            if (FILE_SELECT_DATA.unk_10 == 0)
            {
                SoundPlay(0x208);
                pOam->pOam = (const struct FrameData*)0x8740b70;
                pOam->action = 1;
            }
            else
            {
                SoundPlay(0x1FB);
                pOam->pOam = (const struct FrameData*)0x8740b70;
                pOam->action = 1;
            }
        }
    }
    else if (action == 1)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
            pOam->animationDurationCounter = 0;

        if (FILE_SELECT_DATA.stage == 11)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->action = 100;
        }
    }
    else
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
            pOam->animationDurationCounter = 0;
    }
}

/**
 * @brief a0024 | c0 | TODO
 * 
 */
void FileSelectProcessAudioLogos(struct FileSelectOam* pOam)
{
    if (FILE_SELECT_DATA.currentFile == 3)
    {
        if (pOam->action == 0)
        {
            pOam->pOam = (const struct FrameData*)0x87407c0;
            if (gChangedInput & KEY_RIGHT)
            {
                pOam->action = 1;
                pOam->pOam = (const struct FrameData*)0x87407d0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                DoSoundAction(0x2000000);
                SoundPlay(0x206);
            }
        }
        else if (pOam->action == 1)
        {
            pOam->pOam = (const struct FrameData*)0x87407d0;
            if (gChangedInput & KEY_LEFT)
            {
                pOam->action = 0;
                pOam->pOam = (const struct FrameData*)0x87407c0;
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                DoSoundAction(0x1000000);
                SoundPlay(0x1FA);
            }
        }
    }
    else
    {
        if (pOam->action == 0)
        {
            pOam->pOam = (const struct FrameData*)0x87407e0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }
        else if (pOam->action == 1)
        {
            pOam->pOam = (const struct FrameData*)0x87407f0;
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }
    }
}

/**
 * @brief a00e4 | 60 | TODO
 * 
 */
void FileSelectProcessAudioSelect(struct FileSelectOam* pOam)
{
    if (FILE_SELECT_DATA.currentFile == 3)
    {
        pOam->isDrawn = TRUE;
        if (pOam->action == 0)
        {
            if (gChangedInput & KEY_RIGHT)
            {
                pOam->action = 1;
                pOam->xPosition = 170;
            }
        }
        else if (pOam->action == 1)
        {
            if (gChangedInput & KEY_LEFT)
            {
                pOam->action = 0;
                pOam->xPosition = 102;
            }
        }
    }
    else
    {
        pOam->animationDurationCounter = 0;
        pOam->currentAnimationFrame = 0;
        pOam->isDrawn = FALSE;
    }
}

/**
 * @brief a0144 | 28 | TODO
 * 
 */
void FileSelectProcessFileOverlay(struct FileSelectOam* pOam)
{
    if (FILE_SELECT_DATA.menuState == 0)
        pOam->pOam = sFileSelectFileOverlayOamPointers[FILE_SELECT_DATA.currentFile];
}

/**
 * @brief a016c | 60 | TODO
 * 
 */
void unk_a016c(struct FileSelectOam* pOam)
{
    s32 menuState;
    u32 file;

    menuState = FILE_SELECT_DATA.menuState;
    if (menuState != 0)
        return;

    pOam->pOam = (const struct FrameData*)0x87408e0;
    file = FILE_SELECT_DATA.currentFile;
    if (file <= 2)
    {
        pOam->isDrawn = TRUE;
        if (file == 0)
            pOam->yPosition = 49;
        else if (file == 1)
            pOam->yPosition = 65;
        else if (file == 2)
            pOam->yPosition = 81;

        if (gChangedInput & (KEY_A | KEY_START))
            pOam->pOam = (const struct FrameData*)0x87408d0;
    }
    else
    {
        pOam->isDrawn = menuState;
    }
}

/**
 * @brief a01cc | 4 | TODO
 * 
 */
void unk_a01cc(struct FileSelectOam* pOam)
{
    return;
}

/**
 * @brief a01d0 | 9c | TODO
 * 
 */
void FileSelectProcessFileActionPanel(struct FileSelectOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->action == 0)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x8740940;
            pOam->action = 1;
        }
    }
    else if (pOam->action == 1)
    {
        switch (FILE_SELECT_DATA.menuState)
        {
            case 4:
            case 21:
            case 26:
            case 33:
                SoundPlay(0x1FD);
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = (const struct FrameData*)0x8740950;
                pOam->action = 2;
                break;
        }
    }
    else if (pOam->action == 2)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->isDrawn = FALSE;
        }
    }
}

/**
 * @brief a026c | 98 | TODO
 * 
 */
void FileSelectProcessCopyFilePanel(struct FileSelectOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->action == 0)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x87409a0;
            pOam->action = 1;
        }
    }
    else if (pOam->action == 1)
    {
        switch (FILE_SELECT_DATA.menuState)
        {
            case 18:
            case 21:
            case 26:
                SoundPlay(0x1FD);
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = (const struct FrameData*)0x87409b0;
                pOam->action = 2;
                break;
        }
    }
    else if (pOam->action == 2)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->isDrawn = FALSE;
        }
    }
}

/**
 * @brief a0304 | 98 | TODO
 * 
 */
void FileSelectProcessEraseFilePanel(struct FileSelectOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->action == 0)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x87409a0;
            pOam->action = 1;
        }
    }
    else if (pOam->action == 1)
    {
        switch (FILE_SELECT_DATA.menuState)
        {
            case 29:
            case 31:
            case 33:
                SoundPlay(0x1FD);
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = (const struct FrameData*)0x87409b0;
                pOam->action = 2;
                break;
        }
    }
    else if (pOam->action == 2)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->isDrawn = FALSE;
        }
    }
}

/**
 * @brief a039c | 88 | TODO
 * 
 */
void unk_a039c(struct FileSelectOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->action == 0)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->pOam = (const struct FrameData*)0x87409a0;
            pOam->action = 1;
        }
    }
    else if (pOam->action == 1)
    {
        switch (FILE_SELECT_DATA.menuState)
        {
            case 11:
                SoundPlay(0x1FD);
                pOam->animationDurationCounter = 0;
                pOam->currentAnimationFrame = 0;
                pOam->pOam = (const struct FrameData*)0x87409b0;
                pOam->action = 2;
                break;
        }
    }
    else if (pOam->action == 2)
    {
        pFrame = &pOam->pOam[pOam->currentAnimationFrame];
        if (pFrame->timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
        {
            pOam->type = 0;
            pOam->isDrawn = FALSE;
        }
    }
}

// 0x080A0424
NAKED_FUNCTION
void unk_a0424(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r2, [r4, #9]\n\
	cmp r2, #0\n\
	bne _080A04C4\n\
	ldr r3, _080A0454 @ =gNonGameplayRam\n\
	ldrb r0, [r3, #0x10]\n\
	cmp r0, #0\n\
	bne _080A045C\n\
	ldr r0, _080A0458 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A047A\n\
	movs r0, #1\n\
	strb r0, [r3, #0x10]\n\
	movs r0, #0x79\n\
	strh r0, [r4, #2]\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	b _080A047A\n\
	.align 2, 0\n\
_080A0454: .4byte gNonGameplayRam\n\
_080A0458: .4byte gChangedInput\n\
_080A045C:\n\
	cmp r0, #1\n\
	bne _080A047A\n\
	ldr r0, _080A04AC @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A047A\n\
	strb r2, [r3, #0x10]\n\
	movs r0, #0x69\n\
	strh r0, [r4, #2]\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
_080A047A:\n\
	ldr r0, _080A04AC @ =gChangedInput\n\
	ldrh r2, [r0]\n\
	movs r0, #2\n\
	ands r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	bne _080A04EE\n\
	movs r0, #9\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080A0510\n\
	strb r1, [r4, #7]\n\
	strb r1, [r4, #6]\n\
	movs r0, #0xff\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	ldr r0, _080A04B0 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0x10]\n\
	cmp r0, #0\n\
	bne _080A04B8\n\
	ldr r0, _080A04B4 @ =0x08740B70\n\
	str r0, [r4, #0x14]\n\
	b _080A04EE\n\
	.align 2, 0\n\
_080A04AC: .4byte gChangedInput\n\
_080A04B0: .4byte gNonGameplayRam\n\
_080A04B4: .4byte 0x08740B70\n\
_080A04B8:\n\
	ldr r0, _080A04C0 @ =0x08740B70\n\
	str r0, [r4, #0x14]\n\
	b _080A04EE\n\
	.align 2, 0\n\
_080A04C0: .4byte 0x08740B70\n\
_080A04C4:\n\
	cmp r2, #1\n\
	bne _080A04F8\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _080A04E0\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080A04E0\n\
	strb r1, [r4, #7]\n\
_080A04E0:\n\
	ldr r0, _080A04F4 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #0xb\n\
	bne _080A0510\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
_080A04EE:\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
	b _080A0510\n\
	.align 2, 0\n\
_080A04F4: .4byte gNonGameplayRam\n\
_080A04F8:\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _080A0510\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080A0510\n\
	strb r1, [r4, #7]\n\
_080A0510:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

/**
 * @brief a0518 | 4 | TODO
 * 
 */
void unk_a0518(struct FileSelectOam* pOam)
{
    return;
}

// 0x080A051C
NAKED_FUNCTION
void FileSelectDrawFileInfo(u8 file)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x50\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov sl, r0\n\
	lsls r0, r0, #2\n\
	add r0, sl\n\
	lsls r0, r0, #2\n\
	ldr r1, _080A0548 @ =0x03000B94\n\
	adds r0, r0, r1\n\
	mov sb, r0\n\
	adds r2, r1, #0\n\
	mov r0, sl\n\
	cmp r0, #0\n\
	bne _080A0550\n\
	ldr r7, _080A054C @ =0x060088C0\n\
	b _080A0562\n\
	.align 2, 0\n\
_080A0548: .4byte 0x03000B94\n\
_080A054C: .4byte 0x060088C0\n\
_080A0550:\n\
	mov r1, sl\n\
	cmp r1, #1\n\
	bne _080A0560\n\
	ldr r7, _080A055C @ =0x060090C0\n\
	b _080A0562\n\
	.align 2, 0\n\
_080A055C: .4byte 0x060090C0\n\
_080A0560:\n\
	ldr r7, _080A05A8 @ =0x060098C0\n\
_080A0562:\n\
	str r7, [sp, #0x38]\n\
	ldr r5, _080A05AC @ =gNonGameplayRam\n\
	movs r1, #0\n\
	movs r0, #0\n\
	strh r0, [r5]\n\
	strb r1, [r5, #0x13]\n\
	mov r3, sb\n\
	ldrb r4, [r3]\n\
	mov r0, sl\n\
	lsls r0, r0, #2\n\
	str r0, [sp, #0x40]\n\
	cmp r4, #0\n\
	beq _080A057E\n\
	b _080A0694\n\
_080A057E:\n\
	add r0, sl\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r2\n\
	movs r0, #0x10\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #1\n\
	beq _080A0594\n\
	movs r0, #0x11\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #1\n\
	bne _080A05B0\n\
_080A0594:\n\
	movs r2, #0xa8\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #0x63\n\
	strh r0, [r1]\n\
	movs r3, #0xa7\n\
	lsls r3, r3, #2\n\
	adds r3, r3, r5\n\
	mov sb, r3\n\
	b _080A0694\n\
	.align 2, 0\n\
_080A05A8: .4byte 0x060098C0\n\
_080A05AC: .4byte gNonGameplayRam\n\
_080A05B0:\n\
	mov r0, sl\n\
	adds r0, #0xe\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	bl FileSelectDestroyOamOfType\n\
	mov r0, sl\n\
	adds r0, #0x14\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	bl FileSelectDestroyOamOfType\n\
	str r4, [sp, #0x34]\n\
	ldr r0, _080A061C @ =0x040000D4\n\
	add r1, sp, #0x34\n\
	str r1, [r0]\n\
	str r7, [r0, #4]\n\
	ldr r2, _080A0620 @ =0x850000C0\n\
	str r2, [r0, #8]\n\
	ldr r3, [r0, #8]\n\
	str r4, [sp, #0x34]\n\
	str r1, [r0]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #3\n\
	adds r1, r7, r3\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
	ldr r1, _080A0624 @ =0x0879EC84\n\
	ldr r0, _080A0628 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r4, [r0]\n\
	movs r0, #8\n\
	strh r0, [r5]\n\
	ldrh r0, [r4]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	bne _080A060A\n\
	b _080A0A08\n\
_080A060A:\n\
	mov r8, r5\n\
	mov sb, r1\n\
_080A060E:\n\
	cmp r0, #0x5a\n\
	bne _080A062C\n\
	ldrh r0, [r4]\n\
	bl TextGetCharacterWidth\n\
	adds r5, r0, #2\n\
	b _080A063C\n\
	.align 2, 0\n\
_080A061C: .4byte 0x040000D4\n\
_080A0620: .4byte 0x850000C0\n\
_080A0624: .4byte 0x0879EC84\n\
_080A0628: .4byte 0x03000011\n\
_080A062C:\n\
	cmp r0, #0x40\n\
	bne _080A063A\n\
	mov r0, r8\n\
	ldrb r1, [r0, #0x13]\n\
	movs r0, #8\n\
	subs r5, r0, r1\n\
	b _080A063C\n\
_080A063A:\n\
	movs r5, #8\n\
_080A063C:\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	lsls r0, r0, #5\n\
	ldr r2, [sp, #0x38]\n\
	adds r7, r0, r2\n\
	ldrh r0, [r4]\n\
	lsls r2, r5, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldrb r3, [r1, #0x13]\n\
	movs r1, #0\n\
	str r1, [sp]\n\
	adds r1, r7, #0\n\
	bl TextDrawCharacter\n\
	mov r3, r8\n\
	ldrb r0, [r3, #0x13]\n\
	adds r0, r0, r5\n\
	strb r0, [r3, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r6, r4, #2\n\
	cmp r0, #7\n\
	bls _080A0686\n\
	ldr r5, _080A0690 @ =gNonGameplayRam\n\
	ldrb r4, [r5, #0x13]\n\
	ldrh r3, [r5]\n\
_080A0670:\n\
	adds r2, r4, #0\n\
	subs r2, #8\n\
	adds r4, r2, #0\n\
	adds r1, r3, #1\n\
	adds r3, r1, #0\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bhi _080A0670\n\
	strh r1, [r5]\n\
	strb r2, [r5, #0x13]\n\
_080A0686:\n\
	adds r4, r6, #0\n\
	ldrh r0, [r4]\n\
	cmp r0, sb\n\
	bne _080A060E\n\
	b _080A0A08\n\
	.align 2, 0\n\
_080A0690: .4byte gNonGameplayRam\n\
_080A0694:\n\
	ldr r0, _080A07F4 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	movs r0, #0xfa\n\
	lsls r0, r0, #2\n\
	mov r2, sb\n\
	ldrh r1, [r2, #4]\n\
	bl DivArmDiv\n\
	add r4, sp, #0x14\n\
	str r0, [sp, #0x14]\n\
	mov r3, sb\n\
	ldrh r1, [r3, #4]\n\
	movs r0, #0x64\n\
	bl DivArmDiv\n\
	add r5, sp, #0x24\n\
	str r0, [r4, #4]\n\
	str r0, [sp, #0x24]\n\
	ldr r1, [r4, #4]\n\
	movs r0, #0xa\n\
	bl DivArmMod\n\
	str r0, [r4, #4]\n\
	str r0, [r5, #4]\n\
	mov r0, sb\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #0xa\n\
	bl DivArmDiv\n\
	adds r1, r0, #0\n\
	str r1, [r4, #8]\n\
	movs r0, #0xa\n\
	bl DivArmMod\n\
	str r0, [r4, #8]\n\
	mov r2, sb\n\
	ldrh r1, [r2, #4]\n\
	str r1, [r4, #0xc]\n\
	movs r0, #0xa\n\
	bl DivArmMod\n\
	str r0, [r4, #0xc]\n\
	movs r6, #2\n\
	mov r3, sl\n\
	adds r3, #0xe\n\
	str r3, [sp, #0x44]\n\
	mov r0, sl\n\
	adds r0, #0x14\n\
	str r0, [sp, #0x4c]\n\
	add r1, sp, #0x34\n\
	mov ip, r1\n\
	mov r8, r5\n\
	mov r2, sl\n\
	lsls r2, r2, #4\n\
	str r2, [sp, #0x48]\n\
	ldr r1, _080A07F8 @ =0x040000D4\n\
	ldr r4, _080A07FC @ =0x84000008\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	ldr r5, _080A0800 @ =0x08682FAC\n\
_080A0710:\n\
	lsls r0, r6, #2\n\
	add r0, sp\n\
	adds r0, #0x14\n\
	ldr r0, [r0]\n\
	adds r0, #0x50\n\
	lsls r0, r0, #5\n\
	adds r3, r0, r5\n\
	str r3, [r1]\n\
	str r7, [r1, #4]\n\
	str r4, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	adds r0, r3, r2\n\
	str r0, [r1]\n\
	adds r0, r7, r2\n\
	str r0, [r1, #4]\n\
	str r4, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	adds r7, #0x20\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #3\n\
	bls _080A0710\n\
	movs r1, #0\n\
	str r1, [sp, #0x34]\n\
	ldr r5, _080A07F8 @ =0x040000D4\n\
	mov r3, ip\n\
	str r3, [r5]\n\
	str r7, [r5, #4]\n\
	ldr r0, _080A0804 @ =0x85000080\n\
	str r0, [r5, #8]\n\
	ldr r2, [r5, #8]\n\
	str r1, [sp, #0x34]\n\
	str r3, [r5]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #3\n\
	adds r4, r7, r1\n\
	str r4, [r5, #4]\n\
	str r0, [r5, #8]\n\
	ldr r0, [r5, #8]\n\
	mov r2, r8\n\
	ldr r1, [r2, #4]\n\
	movs r0, #2\n\
	bl DivArmMod\n\
	mov r3, r8\n\
	str r0, [r3, #4]\n\
	mov r0, sb\n\
	ldrh r1, [r0, #6]\n\
	movs r0, #0x64\n\
	bl DivArmDiv\n\
	adds r1, r0, #0\n\
	mov r2, r8\n\
	str r1, [r2, #8]\n\
	movs r0, #0xa\n\
	bl DivArmMod\n\
	adds r1, r0, #0\n\
	mov r3, r8\n\
	str r1, [r3, #0xc]\n\
	movs r0, #2\n\
	bl DivArmMod\n\
	mov r1, r8\n\
	str r0, [r1, #0xc]\n\
	adds r3, r7, #0\n\
	adds r7, r4, #0\n\
	movs r6, #0\n\
	ldr r0, [sp, #0x24]\n\
	ldr r1, [r1, #4]\n\
	subs r0, r0, r1\n\
	cmp r6, r0\n\
	bge _080A07D2\n\
	adds r2, r5, #0\n\
	mov r4, r8\n\
	ldr r0, _080A0808 @ =0x0873DB64\n\
	mov ip, r0\n\
	ldr r5, _080A07FC @ =0x84000008\n\
_080A07AE:\n\
	cmp r6, #0xa\n\
	bne _080A07B6\n\
	ldr r1, _080A080C @ =0xFFFFFB60\n\
	adds r7, r7, r1\n\
_080A07B6:\n\
	mov r0, ip\n\
	str r0, [r2]\n\
	str r7, [r2, #4]\n\
	str r5, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	adds r7, #0x20\n\
	adds r0, r6, #2\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r0, [sp, #0x24]\n\
	ldr r1, [r4, #4]\n\
	subs r0, r0, r1\n\
	cmp r6, r0\n\
	blt _080A07AE\n\
_080A07D2:\n\
	mov r1, r8\n\
	ldr r0, [r1, #4]\n\
	cmp r0, #1\n\
	bne _080A082A\n\
	cmp r6, #0xa\n\
	bne _080A07E2\n\
	ldr r2, _080A080C @ =0xFFFFFB60\n\
	adds r7, r7, r2\n\
_080A07E2:\n\
	mov r0, r8\n\
	ldr r1, [r0, #8]\n\
	ldr r0, [sp, #0x24]\n\
	cmp r1, r0\n\
	bne _080A0814\n\
	ldr r1, _080A07F8 @ =0x040000D4\n\
	ldr r0, _080A0810 @ =0x0873DB04\n\
	b _080A0818\n\
	.align 2, 0\n\
_080A07F4: .4byte 0x03000011\n\
_080A07F8: .4byte 0x040000D4\n\
_080A07FC: .4byte 0x84000008\n\
_080A0800: .4byte 0x08682FAC\n\
_080A0804: .4byte 0x85000080\n\
_080A0808: .4byte 0x0873DB64\n\
_080A080C: .4byte 0xFFFFFB60\n\
_080A0810: .4byte 0x0873DB04\n\
_080A0814:\n\
	ldr r1, _080A0A18 @ =0x040000D4\n\
	ldr r0, _080A0A1C @ =0x0873DB44\n\
_080A0818:\n\
	str r0, [r1]\n\
	str r7, [r1, #4]\n\
	ldr r0, _080A0A20 @ =0x84000008\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	adds r0, r6, #2\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	adds r7, #0x20\n\
_080A082A:\n\
	mov r1, r8\n\
	ldr r0, [r1, #8]\n\
	ldr r1, [r1, #0xc]\n\
	subs r0, r0, r1\n\
	adds r3, #0xc0\n\
	str r3, [sp, #0x3c]\n\
	cmp r6, r0\n\
	bge _080A0866\n\
	ldr r2, _080A0A24 @ =0xFFFFFB60\n\
	mov ip, r2\n\
	ldr r2, _080A0A18 @ =0x040000D4\n\
	mov r3, r8\n\
	ldr r5, _080A0A28 @ =0x0873DB24\n\
	ldr r4, _080A0A20 @ =0x84000008\n\
_080A0846:\n\
	cmp r6, #0xa\n\
	bne _080A084C\n\
	add r7, ip\n\
_080A084C:\n\
	str r5, [r2]\n\
	str r7, [r2, #4]\n\
	str r4, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	adds r7, #0x20\n\
	adds r0, r6, #2\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	ldr r0, [r3, #8]\n\
	ldr r1, [r3, #0xc]\n\
	subs r0, r0, r1\n\
	cmp r6, r0\n\
	blt _080A0846\n\
_080A0866:\n\
	mov r3, r8\n\
	ldr r0, [r3, #0xc]\n\
	cmp r0, #1\n\
	bne _080A088A\n\
	ldr r0, [r3, #8]\n\
	cmp r6, r0\n\
	bge _080A088A\n\
	cmp r6, #0xa\n\
	bne _080A087C\n\
	ldr r0, _080A0A24 @ =0xFFFFFB60\n\
	adds r7, r7, r0\n\
_080A087C:\n\
	ldr r1, _080A0A18 @ =0x040000D4\n\
	ldr r0, _080A0A2C @ =0x0873DAE4\n\
	str r0, [r1]\n\
	str r7, [r1, #4]\n\
	ldr r0, _080A0A20 @ =0x84000008\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
_080A088A:\n\
	ldr r7, [sp, #0x3c]\n\
	mov r2, sb\n\
	ldrb r1, [r2, #0xd]\n\
	movs r0, #0xa\n\
	bl DivArmDiv\n\
	adds r1, r0, #0\n\
	str r1, [sp, #4]\n\
	movs r0, #0xa\n\
	bl DivArmMod\n\
	str r0, [sp, #4]\n\
	mov r3, sb\n\
	ldrb r1, [r3, #0xd]\n\
	str r1, [sp, #8]\n\
	movs r0, #0xa\n\
	bl DivArmMod\n\
	str r0, [sp, #8]\n\
	movs r6, #0\n\
	ldr r5, _080A0A30 @ =0x08682FAC\n\
	ldr r1, _080A0A18 @ =0x040000D4\n\
	ldr r4, _080A0A20 @ =0x84000008\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
_080A08BC:\n\
	lsls r0, r6, #2\n\
	add r0, sp\n\
	adds r0, #4\n\
	ldr r0, [r0]\n\
	adds r0, #0x50\n\
	lsls r0, r0, #5\n\
	adds r3, r0, r5\n\
	str r3, [r1]\n\
	str r7, [r1, #4]\n\
	str r4, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	adds r0, r3, r2\n\
	str r0, [r1]\n\
	adds r0, r7, r2\n\
	str r0, [r1, #4]\n\
	str r4, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	adds r7, #0x20\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #1\n\
	bls _080A08BC\n\
	ldr r6, _080A0A34 @ =gNonGameplayRam\n\
	movs r4, #0\n\
	movs r0, #0xa\n\
	strh r0, [r6]\n\
	lsls r0, r0, #5\n\
	ldr r1, [sp, #0x38]\n\
	adds r7, r1, r0\n\
	movs r0, #0x5a\n\
	bl TextGetCharacterWidth\n\
	adds r5, r0, #3\n\
	lsls r2, r5, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldrb r3, [r6, #0x13]\n\
	str r4, [sp]\n\
	movs r0, #0x5a\n\
	adds r1, r7, #0\n\
	bl TextDrawCharacter\n\
	ldrb r0, [r6, #0x13]\n\
	adds r2, r0, r5\n\
	strb r2, [r6, #0x13]\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _080A0938\n\
	adds r5, r6, #0\n\
	ldrh r4, [r5]\n\
_080A0922:\n\
	adds r3, r2, #0\n\
	subs r3, #8\n\
	adds r2, r3, #0\n\
	adds r1, r4, #1\n\
	adds r4, r1, #0\n\
	lsls r0, r3, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bhi _080A0922\n\
	strh r1, [r5]\n\
	strb r3, [r5, #0x13]\n\
_080A0938:\n\
	mov r2, sb\n\
	ldrb r1, [r2, #0xe]\n\
	movs r0, #0xa\n\
	bl DivArmDiv\n\
	adds r1, r0, #0\n\
	str r1, [sp, #4]\n\
	movs r0, #0xa\n\
	bl DivArmMod\n\
	str r0, [sp, #4]\n\
	mov r3, sb\n\
	ldrb r1, [r3, #0xe]\n\
	str r1, [sp, #8]\n\
	movs r0, #0xa\n\
	bl DivArmMod\n\
	str r0, [sp, #8]\n\
	movs r6, #0\n\
	ldr r0, _080A0A34 @ =gNonGameplayRam\n\
	mov r8, r0\n\
_080A0962:\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	lsls r0, r0, #5\n\
	ldr r2, [sp, #0x38]\n\
	adds r7, r0, r2\n\
	lsls r0, r6, #2\n\
	add r0, sp\n\
	adds r0, #4\n\
	ldr r0, [r0]\n\
	adds r0, #0x50\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	ldrb r3, [r1, #0x13]\n\
	movs r1, #0\n\
	str r1, [sp]\n\
	adds r1, r7, #0\n\
	movs r2, #8\n\
	bl TextDrawCharacter\n\
	mov r3, r8\n\
	ldrb r0, [r3, #0x13]\n\
	adds r0, #8\n\
	strb r0, [r3, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r6, #1\n\
	cmp r0, #7\n\
	bls _080A09B6\n\
	ldr r5, _080A0A34 @ =gNonGameplayRam\n\
	ldrb r4, [r5, #0x13]\n\
	ldrh r3, [r5]\n\
_080A09A0:\n\
	adds r2, r4, #0\n\
	subs r2, #8\n\
	adds r4, r2, #0\n\
	adds r1, r3, #1\n\
	adds r3, r1, #0\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bhi _080A09A0\n\
	strh r1, [r5]\n\
	strb r2, [r5, #0x13]\n\
_080A09B6:\n\
	lsls r0, r6, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #1\n\
	bls _080A0962\n\
	ldr r0, [sp, #0x44]\n\
	lsls r4, r0, #0x18\n\
	lsrs r4, r4, #0x18\n\
	adds r0, r4, #0\n\
	bl FileSelectDestroyOamOfType\n\
	ldr r2, [sp, #0x48]\n\
	adds r2, #0x20\n\
	mov r1, sb\n\
	ldrb r3, [r1, #2]\n\
	adds r0, r4, #0\n\
	movs r1, #0x9d\n\
	bl FileSelectSetUpAreaNameOam\n\
	ldr r2, [sp, #0x4c]\n\
	lsls r0, r2, #0x18\n\
	lsrs r4, r0, #0x18\n\
	adds r0, r4, #0\n\
	bl FileSelectDestroyOamOfType\n\
	ldr r1, _080A0A38 @ =0x03000B94\n\
	ldr r0, [sp, #0x40]\n\
	add r0, sl\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0, #0x10]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _080A0A08\n\
	ldr r2, [sp, #0x48]\n\
	adds r2, #0x28\n\
	adds r0, r4, #0\n\
	movs r1, #0xdc\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
_080A0A08:\n\
	add sp, #0x50\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A0A18: .4byte 0x040000D4\n\
_080A0A1C: .4byte 0x0873DB44\n\
_080A0A20: .4byte 0x84000008\n\
_080A0A24: .4byte 0xFFFFFB60\n\
_080A0A28: .4byte 0x0873DB24\n\
_080A0A2C: .4byte 0x0873DAE4\n\
_080A0A30: .4byte 0x08682FAC\n\
_080A0A34: .4byte gNonGameplayRam\n\
_080A0A38: .4byte 0x03000B94\n\
    .syntax divided\n");
}

// 0x080A0A3C
NAKED_FUNCTION
void FileSelectDrawText(u8 textId)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	ldr r0, _080A0A74 @ =gNonGameplayRam\n\
	movs r2, #0\n\
	movs r1, #0\n\
	strh r1, [r0, #2]\n\
	strh r1, [r0]\n\
	strb r2, [r0, #0x13]\n\
	ldrh r1, [r0, #8]\n\
	adds r2, r0, #0\n\
	cmp r1, #0x18\n\
	bne _080A0A80\n\
	ldr r1, _080A0A78 @ =0x0879E928\n\
	ldr r0, _080A0A7C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r7, [r0, #0x14]\n\
	b _080A0A98\n\
	.align 2, 0\n\
_080A0A74: .4byte gNonGameplayRam\n\
_080A0A78: .4byte 0x0879E928\n\
_080A0A7C: .4byte 0x03000011\n\
_080A0A80:\n\
	ldr r1, _080A0AA4 @ =0x0879E928\n\
	ldr r0, _080A0AA8 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldrh r1, [r2, #8]\n\
	ldr r0, [r0]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r7, [r1]\n\
_080A0A98:\n\
	cmp r3, #1\n\
	bne _080A0AB0\n\
	ldr r0, _080A0AAC @ =0x06008000\n\
	mov sb, r0\n\
	movs r4, #6\n\
	b _080A0AC6\n\
	.align 2, 0\n\
_080A0AA4: .4byte 0x0879E928\n\
_080A0AA8: .4byte 0x03000011\n\
_080A0AAC: .4byte 0x06008000\n\
_080A0AB0:\n\
	cmp r3, #2\n\
	bne _080A0ABC\n\
	ldr r0, _080A0AB8 @ =0x0600B000\n\
	b _080A0AC2\n\
	.align 2, 0\n\
_080A0AB8: .4byte 0x0600B000\n\
_080A0ABC:\n\
	cmp r3, #3\n\
	bne _080A0AC8\n\
	ldr r0, _080A0AFC @ =0x0600C800\n\
_080A0AC2:\n\
	mov sb, r0\n\
	movs r4, #0\n\
_080A0AC6:\n\
	mov r8, r4\n\
_080A0AC8:\n\
	adds r6, r2, #0\n\
	ldr r0, [r6, #4]\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	beq _080A0B6E\n\
	mov sl, r1\n\
_080A0AD8:\n\
	ldr r1, [r6, #4]\n\
	ldrh r0, [r1]\n\
	movs r2, #0xfe\n\
	lsls r2, r2, #8\n\
	cmp r0, r2\n\
	bne _080A0B00\n\
	movs r1, #0\n\
	movs r0, #0\n\
	strh r0, [r6]\n\
	ldrh r0, [r6, #2]\n\
	adds r0, #2\n\
	strh r0, [r6, #2]\n\
	strb r1, [r6, #0x13]\n\
	adds r7, #2\n\
	movs r4, #0\n\
	mov r8, r4\n\
	b _080A0B5E\n\
	.align 2, 0\n\
_080A0AFC: .4byte 0x0600C800\n\
_080A0B00:\n\
	ldrh r4, [r6]\n\
	lsls r4, r4, #5\n\
	ldrh r0, [r6, #2]\n\
	lsls r0, r0, #0xa\n\
	adds r4, r4, r0\n\
	add r4, sb\n\
	ldrh r0, [r7]\n\
	lsls r0, r0, #5\n\
	adds r4, r4, r0\n\
	str r4, [sp, #4]\n\
	ldrh r0, [r1]\n\
	bl TextGetCharacterWidth\n\
	adds r5, r0, #0\n\
	ldr r0, [r6, #4]\n\
	ldrh r0, [r0]\n\
	lsls r2, r5, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldrb r3, [r6, #0x13]\n\
	mov r4, r8\n\
	lsls r1, r4, #0x18\n\
	lsrs r1, r1, #0x18\n\
	str r1, [sp]\n\
	ldr r1, [sp, #4]\n\
	bl TextDrawCharacter\n\
	ldrb r0, [r6, #0x13]\n\
	adds r0, r0, r5\n\
	strb r0, [r6, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _080A0B5E\n\
	ldr r5, _080A0B80 @ =gNonGameplayRam\n\
	ldrb r4, [r5, #0x13]\n\
	ldrh r3, [r5]\n\
_080A0B48:\n\
	adds r2, r4, #0\n\
	subs r2, #8\n\
	adds r4, r2, #0\n\
	adds r1, r3, #1\n\
	adds r3, r1, #0\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bhi _080A0B48\n\
	strh r1, [r5]\n\
	strb r2, [r5, #0x13]\n\
_080A0B5E:\n\
	ldr r1, _080A0B80 @ =gNonGameplayRam\n\
	ldr r2, [r1, #4]\n\
	adds r0, r2, #2\n\
	str r0, [r1, #4]\n\
	adds r6, r1, #0\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, sl\n\
	bne _080A0AD8\n\
_080A0B6E:\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A0B80: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x080A0B84
NAKED_FUNCTION
boolu32 FileSelectProcessCorruptedFile(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #4\n\
	movs r5, #0\n\
	bl FileSelectProcessOam\n\
	ldr r0, _080A0BA4 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0x14]\n\
	cmp r0, #7\n\
	bls _080A0B98\n\
	b _080A0DF0\n\
_080A0B98:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080A0BA8 @ =_080A0BAC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080A0BA4: .4byte gNonGameplayRam\n\
_080A0BA8: .4byte _080A0BAC\n\
_080A0BAC: @ jump table\n\
	.4byte _080A0BCC @ case 0\n\
	.4byte _080A0C64 @ case 1\n\
	.4byte _080A0C8A @ case 2\n\
	.4byte _080A0CCC @ case 3\n\
	.4byte _080A0CF8 @ case 4\n\
	.4byte _080A0D60 @ case 5\n\
	.4byte _080A0DA4 @ case 6\n\
	.4byte _080A0DE8 @ case 7\n\
_080A0BCC:\n\
	ldr r1, _080A0BE4 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r1, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _080A0BE8\n\
	movs r0, #1\n\
	bl FileSelectDrawText\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0BE4: .4byte gNonGameplayRam\n\
_080A0BE8:\n\
	cmp r0, #2\n\
	bne _080A0C08\n\
	ldr r0, _080A0BFC @ =0x03000B94\n\
	ldrb r0, [r0, #1]\n\
	cmp r0, #0\n\
	bne _080A0C00\n\
	movs r0, #0\n\
	bl FileSelectDrawFileInfo\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0BFC: .4byte 0x03000B94\n\
_080A0C00:\n\
	movs r0, #0\n\
	bl FileSelectDrawFileCorruptedText\n\
	b _080A0DF0\n\
_080A0C08:\n\
	cmp r0, #3\n\
	bne _080A0C28\n\
	ldr r0, _080A0C1C @ =0x03000B94\n\
	ldrb r0, [r0, #0x15]\n\
	cmp r0, #0\n\
	bne _080A0C20\n\
	movs r0, #1\n\
	bl FileSelectDrawFileInfo\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0C1C: .4byte 0x03000B94\n\
_080A0C20:\n\
	movs r0, #1\n\
	bl FileSelectDrawFileCorruptedText\n\
	b _080A0DF0\n\
_080A0C28:\n\
	cmp r0, #4\n\
	beq _080A0C2E\n\
	b _080A0DF0\n\
_080A0C2E:\n\
	ldr r0, _080A0C40 @ =0x03000B94\n\
	adds r0, #0x29\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080A0C44\n\
	movs r0, #2\n\
	bl FileSelectDrawFileInfo\n\
	b _080A0C4A\n\
	.align 2, 0\n\
_080A0C40: .4byte 0x03000B94\n\
_080A0C44:\n\
	movs r0, #2\n\
	bl FileSelectDrawFileCorruptedText\n\
_080A0C4A:\n\
	ldr r2, _080A0C5C @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strb r0, [r2, #0xc]\n\
	ldr r1, _080A0C60 @ =gWrittenToBldy\n\
	movs r0, #0xe\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0C5C: .4byte gNonGameplayRam\n\
_080A0C60: .4byte gWrittenToBldy\n\
_080A0C64:\n\
	ldr r1, _080A0C74 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _080A0C78\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0C74: .4byte gWrittenToBldy\n\
_080A0C78:\n\
	ldr r1, _080A0C80 @ =gNonGameplayRam\n\
	movs r0, #2\n\
	strb r0, [r1, #0x14]\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0C80: .4byte gNonGameplayRam\n\
_080A0C84:\n\
	movs r0, #3\n\
	strb r0, [r4, #0x14]\n\
	b _080A0CB4\n\
_080A0C8A:\n\
	ldr r0, _080A0CC4 @ =gNonGameplayRam\n\
	ldrb r1, [r0, #0x15]\n\
	adds r4, r0, #0\n\
	cmp r1, #2\n\
	bhi _080A0CB4\n\
	ldr r3, _080A0CC8 @ =0x03000B94\n\
	adds r2, r4, #0\n\
_080A0C98:\n\
	ldrb r1, [r2, #0x15]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0, #1]\n\
	cmp r0, #0\n\
	bne _080A0C84\n\
	adds r0, r1, #1\n\
	strb r0, [r4, #0x15]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bls _080A0C98\n\
_080A0CB4:\n\
	ldrb r0, [r4, #0x15]\n\
	cmp r0, #3\n\
	beq _080A0CBC\n\
	b _080A0DF0\n\
_080A0CBC:\n\
	movs r0, #7\n\
	strb r0, [r4, #0x14]\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0CC4: .4byte gNonGameplayRam\n\
_080A0CC8: .4byte 0x03000B94\n\
_080A0CCC:\n\
	ldr r1, _080A0CF4 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r1, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xa\n\
	beq _080A0CDE\n\
	b _080A0DF0\n\
_080A0CDE:\n\
	movs r0, #4\n\
	strb r0, [r1, #0x14]\n\
	movs r0, #0\n\
	strb r0, [r1, #0xc]\n\
	movs r0, #0x11\n\
	movs r1, #0x7a\n\
	movs r2, #0x44\n\
	movs r3, #0\n\
	bl FileSelectSetupOam\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0CF4: .4byte gNonGameplayRam\n\
_080A0CF8:\n\
	ldr r2, _080A0D14 @ =0x03000B94\n\
	ldr r1, _080A0D18 @ =gNonGameplayRam\n\
	ldrb r3, [r1, #0x15]\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0, #1]\n\
	adds r4, r1, #0\n\
	cmp r0, #1\n\
	bne _080A0D1C\n\
	adds r0, r3, #5\n\
	b _080A0D20\n\
	.align 2, 0\n\
_080A0D14: .4byte 0x03000B94\n\
_080A0D18: .4byte gNonGameplayRam\n\
_080A0D1C:\n\
	adds r0, r3, #0\n\
	adds r0, #8\n\
_080A0D20:\n\
	strh r0, [r4, #8]\n\
	ldr r1, _080A0D58 @ =0x0879EC68\n\
	ldr r0, _080A0D5C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldrh r1, [r4, #8]\n\
	ldr r0, [r0]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	str r0, [r4, #4]\n\
	movs r0, #2\n\
	bl FileSelectDrawCorruptionText\n\
	movs r0, #0xa\n\
	movs r1, #0x78\n\
	movs r2, #0x64\n\
	movs r3, #0\n\
	bl FileSelectSetupOam\n\
	movs r0, #3\n\
	strb r0, [r4, #0x11]\n\
	movs r0, #5\n\
	strb r0, [r4, #0x14]\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0D58: .4byte 0x0879EC68\n\
_080A0D5C: .4byte 0x03000011\n\
_080A0D60:\n\
	ldr r0, _080A0D98 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A0DF0\n\
	movs r0, #0xa\n\
	bl FileSelectDestroyOamOfType\n\
	movs r0, #0x11\n\
	bl FileSelectDestroyOamOfType\n\
	ldr r0, _080A0D9C @ =0x000001FB\n\
	bl SoundPlay\n\
	ldr r4, _080A0DA0 @ =gNonGameplayRam\n\
	movs r0, #4\n\
	strb r0, [r4, #0x11]\n\
	ldrb r0, [r4, #0x15]\n\
	bl Sram_SetCurrentFile\n\
	ldrb r0, [r4, #0x15]\n\
	bl FileSelectDrawFileInfo\n\
	movs r0, #6\n\
	strb r0, [r4, #0x14]\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0D98: .4byte gChangedInput\n\
_080A0D9C: .4byte 0x000001FB\n\
_080A0DA0: .4byte gNonGameplayRam\n\
_080A0DA4:\n\
	ldr r1, _080A0DCC @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xc]\n\
	adds r0, #1\n\
	movs r2, #0\n\
	strb r0, [r1, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _080A0DDC\n\
	str r2, [sp]\n\
	ldr r1, _080A0DD0 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	ldr r0, _080A0DD4 @ =0x0600B000\n\
	str r0, [r1, #4]\n\
	ldr r0, _080A0DD8 @ =0x85000600\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	b _080A0DF0\n\
	.align 2, 0\n\
_080A0DCC: .4byte gNonGameplayRam\n\
_080A0DD0: .4byte 0x040000D4\n\
_080A0DD4: .4byte 0x0600B000\n\
_080A0DD8: .4byte 0x85000600\n\
_080A0DDC:\n\
	cmp r0, #0xa\n\
	bne _080A0DF0\n\
	movs r0, #2\n\
	strb r0, [r1, #0x14]\n\
	strb r2, [r1, #0xc]\n\
	b _080A0DF0\n\
_080A0DE8:\n\
	ldr r1, _080A0E00 @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strb r0, [r1, #0xc]\n\
	movs r5, #1\n\
_080A0DF0:\n\
	bl FileSelectDrawAllOam\n\
	adds r0, r5, #0\n\
	add sp, #4\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_080A0E00: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x080A0E04
NAKED_FUNCTION
void FileSelectDrawFileCorruptedText(u8 file)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #8\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080A0E20\n\
	ldr r6, _080A0E1C @ =0x060088C0\n\
	b _080A0E2E\n\
	.align 2, 0\n\
_080A0E1C: .4byte 0x060088C0\n\
_080A0E20:\n\
	cmp r0, #1\n\
	bne _080A0E2C\n\
	ldr r6, _080A0E28 @ =0x060090C0\n\
	b _080A0E2E\n\
	.align 2, 0\n\
_080A0E28: .4byte 0x060090C0\n\
_080A0E2C:\n\
	ldr r6, _080A0E90 @ =0x060098C0\n\
_080A0E2E:\n\
	mov r8, r6\n\
	ldr r4, _080A0E94 @ =gNonGameplayRam\n\
	movs r0, #0\n\
	movs r1, #0\n\
	strh r1, [r4]\n\
	strb r0, [r4, #0x13]\n\
	str r1, [sp, #4]\n\
	ldr r0, _080A0E98 @ =0x040000D4\n\
	add r2, sp, #4\n\
	str r2, [r0]\n\
	str r6, [r0, #4]\n\
	ldr r2, _080A0E9C @ =0x850000C0\n\
	str r2, [r0, #8]\n\
	ldr r3, [r0, #8]\n\
	str r1, [sp, #4]\n\
	add r3, sp, #4\n\
	str r3, [r0]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #3\n\
	adds r1, r6, r3\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
	ldr r1, _080A0EA0 @ =0x0879EC84\n\
	ldr r0, _080A0EA4 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r5, [r0]\n\
	movs r0, #8\n\
	strh r0, [r4]\n\
	ldrh r0, [r5]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	beq _080A0F04\n\
	adds r7, r4, #0\n\
	mov sb, r1\n\
_080A0E80:\n\
	cmp r0, #0x5a\n\
	bne _080A0EA8\n\
	ldrh r0, [r5]\n\
	bl TextGetCharacterWidth\n\
	adds r4, r0, #3\n\
	b _080A0EB6\n\
	.align 2, 0\n\
_080A0E90: .4byte 0x060098C0\n\
_080A0E94: .4byte gNonGameplayRam\n\
_080A0E98: .4byte 0x040000D4\n\
_080A0E9C: .4byte 0x850000C0\n\
_080A0EA0: .4byte 0x0879EC84\n\
_080A0EA4: .4byte 0x03000011\n\
_080A0EA8:\n\
	cmp r0, #0x40\n\
	bne _080A0EB4\n\
	ldrb r1, [r7, #0x13]\n\
	movs r0, #8\n\
	subs r4, r0, r1\n\
	b _080A0EB6\n\
_080A0EB4:\n\
	movs r4, #8\n\
_080A0EB6:\n\
	ldrh r0, [r7]\n\
	lsls r0, r0, #5\n\
	mov r1, r8\n\
	adds r6, r0, r1\n\
	ldrh r0, [r5]\n\
	lsls r2, r4, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldrb r3, [r7, #0x13]\n\
	movs r1, #0\n\
	str r1, [sp]\n\
	adds r1, r6, #0\n\
	bl TextDrawCharacter\n\
	ldrb r0, [r7, #0x13]\n\
	adds r0, r0, r4\n\
	strb r0, [r7, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r6, r5, #2\n\
	cmp r0, #7\n\
	bls _080A0EFC\n\
	ldr r5, _080A0F14 @ =gNonGameplayRam\n\
	ldrb r4, [r5, #0x13]\n\
	ldrh r3, [r5]\n\
_080A0EE6:\n\
	adds r2, r4, #0\n\
	subs r2, #8\n\
	adds r4, r2, #0\n\
	adds r1, r3, #1\n\
	adds r3, r1, #0\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bhi _080A0EE6\n\
	strh r1, [r5]\n\
	strb r2, [r5, #0x13]\n\
_080A0EFC:\n\
	adds r5, r6, #0\n\
	ldrh r0, [r5]\n\
	cmp r0, sb\n\
	bne _080A0E80\n\
_080A0F04:\n\
	add sp, #8\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A0F14: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x080A0F18
NAKED_FUNCTION
void FileSelectDrawCorruptionText(u8 textId)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	adds r4, r3, #0\n\
	ldr r0, _080A0F40 @ =gNonGameplayRam\n\
	movs r2, #0\n\
	movs r1, #0\n\
	strh r1, [r0, #2]\n\
	strh r1, [r0]\n\
	strb r2, [r0, #0x13]\n\
	cmp r3, #1\n\
	bne _080A0F48\n\
	ldr r7, _080A0F44 @ =0x06008000\n\
	b _080A0F5A\n\
	.align 2, 0\n\
_080A0F40: .4byte gNonGameplayRam\n\
_080A0F44: .4byte 0x06008000\n\
_080A0F48:\n\
	cmp r3, #2\n\
	bne _080A0F54\n\
	ldr r7, _080A0F50 @ =0x0600B000\n\
	b _080A0F5A\n\
	.align 2, 0\n\
_080A0F50: .4byte 0x0600B000\n\
_080A0F54:\n\
	cmp r4, #3\n\
	bne _080A0F5A\n\
	ldr r7, _080A0F8C @ =0x0600C800\n\
_080A0F5A:\n\
	adds r6, r0, #0\n\
	ldr r0, [r6, #4]\n\
	ldrh r0, [r0]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	beq _080A0FF2\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	mov sl, r0\n\
	movs r0, #0\n\
	mov sb, r0\n\
	mov r8, r1\n\
_080A0F74:\n\
	ldr r1, [r6, #4]\n\
	ldrh r0, [r1]\n\
	cmp r0, sl\n\
	bne _080A0F90\n\
	movs r0, #0\n\
	strh r0, [r6]\n\
	ldrh r0, [r6, #2]\n\
	adds r0, #2\n\
	strh r0, [r6, #2]\n\
	mov r0, sb\n\
	strb r0, [r6, #0x13]\n\
	b _080A0FE2\n\
	.align 2, 0\n\
_080A0F8C: .4byte 0x0600C800\n\
_080A0F90:\n\
	ldrh r4, [r6]\n\
	lsls r4, r4, #5\n\
	ldrh r0, [r6, #2]\n\
	lsls r0, r0, #0xa\n\
	adds r4, r4, r0\n\
	adds r4, r4, r7\n\
	ldrh r0, [r1]\n\
	bl TextGetCharacterWidth\n\
	adds r5, r0, #0\n\
	ldr r0, [r6, #4]\n\
	ldrh r0, [r0]\n\
	lsls r2, r5, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldrb r3, [r6, #0x13]\n\
	movs r1, #0\n\
	str r1, [sp]\n\
	adds r1, r4, #0\n\
	bl TextDrawCharacter\n\
	ldrb r0, [r6, #0x13]\n\
	adds r0, r0, r5\n\
	strb r0, [r6, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _080A0FE2\n\
	ldr r5, _080A1004 @ =gNonGameplayRam\n\
	ldrb r4, [r5, #0x13]\n\
	ldrh r3, [r5]\n\
_080A0FCC:\n\
	adds r2, r4, #0\n\
	subs r2, #8\n\
	adds r4, r2, #0\n\
	adds r1, r3, #1\n\
	adds r3, r1, #0\n\
	lsls r0, r2, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bhi _080A0FCC\n\
	strh r1, [r5]\n\
	strb r2, [r5, #0x13]\n\
_080A0FE2:\n\
	ldr r1, _080A1004 @ =gNonGameplayRam\n\
	ldr r2, [r1, #4]\n\
	adds r0, r2, #2\n\
	str r0, [r1, #4]\n\
	adds r6, r1, #0\n\
	ldrh r0, [r2, #2]\n\
	cmp r0, r8\n\
	bne _080A0F74\n\
_080A0FF2:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A1004: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

/**
 * @brief a1008 | 34 | TODO
 * 
 */
void FileSelectDestroyOamOfType(u8 type)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(FILE_SELECT_DATA.oam); i++)
    {
        if (FILE_SELECT_DATA.oam[i].type == type)
        {
            FILE_SELECT_DATA.oam[i].type = 0;
            FILE_SELECT_DATA.oam[i].isDrawn = FALSE;
            return;
        }
    }
}

/**
 * @brief a103c | 190 | TODO
 * 
 */
void FileSelectSetUpAreaNameOam(u8 type, s16 xPosition, s16 yPosition, s16 area)
{
    u8 slot;

    slot = FileSelectSetupOam(type, xPosition, yPosition, 1);

    switch (area)
    {
        case 1:
            FILE_SELECT_DATA.oam[slot].pOam = sFileSelectAreaNameOamPointers[gLanguage][1];
            break;

        case 2:
            FILE_SELECT_DATA.oam[slot].pOam = sFileSelectAreaNameOamPointers[gLanguage][2];
            break;

        case 3:
            FILE_SELECT_DATA.oam[slot].pOam = sFileSelectAreaNameOamPointers[gLanguage][3];
            break;

        case 4:
            FILE_SELECT_DATA.oam[slot].pOam = sFileSelectAreaNameOamPointers[gLanguage][4];
            break;

        case 5:
            FILE_SELECT_DATA.oam[slot].pOam = sFileSelectAreaNameOamPointers[gLanguage][5];
            break;

        case 6:
            FILE_SELECT_DATA.oam[slot].pOam = sFileSelectAreaNameOamPointers[gLanguage][6];
            break;

        case 0:
        default:
            FILE_SELECT_DATA.oam[slot].pOam = sFileSelectAreaNameOamPointers[gLanguage][0];
            break;
    }
}

/**
 * @brief a11cc | 3c | TODO
 * 
 */
void FileSelectProcessOam(void)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(FILE_SELECT_DATA.oam); i++)
    {
        if (FILE_SELECT_DATA.oam[i].type != 0)
            FILE_SELECT_DATA.oam[i].pHandler(&FILE_SELECT_DATA.oam[i]);
    }
}

/**
 * @brief a1208 | 40 | TODO
 * 
 */
void FileSelectDrawAllOam(void)
{
    u8 i;

    for (i = 0; i < ARRAY_SIZE(FILE_SELECT_DATA.oam); i++)
    {
        if (FILE_SELECT_DATA.oam[i].isDrawn)
            FileSelectDrawOam(&FILE_SELECT_DATA.oam[i]);
    }

    ResetFreeOam();
    gNextOamSlot = 0;
}

/**
 * @brief a1248 | 188 | TODO
 * 
 */
void FileSelectDrawOam(struct FileSelectOam* pOam)
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
            x = MOD_AND(-(sFileSelectOamXFlipOffsets[shape][size] * 8 + part2) + pOam->xPosition, 512);
            y = MOD_AND(part1 + pOam->yPosition, 256);
        }
        else
        {
            y = MOD_AND(part1 + pOam->yPosition, 256);
            x = MOD_AND(part2 + pOam->xPosition, 512);
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
 * @brief a13d0 | 10 | TODO
 * 
 */
boolu32 SetLanguage(u8 unused)
{
    gLanguage = LANGUAGE_ENGLISH;
    return TRUE;
}

/**
 * @brief a13e0 | 98 | TODO
 * 
 */
void unk_a13e0(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    WRITE_16(REG_DISPCNT, 0);
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);
    gWrittenToBldy = BLDY_MAX_VALUE;
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);

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
    CallbackSetVBlank(unk_a1478);
}

/**
 * @brief a1478 | 4 | TODO
 * 
 */
void unk_a1478(void)
{
    return;
}

/**
 * @brief a147c | 4 | TODO
 * 
 */
boolu32 unk_a147c(void)
{
    return TRUE;
}
