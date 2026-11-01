#include "save_file.h"
#include "globals.h"
#include "macros.h"
#include "dma.h"
#include "sram_misc.h"
#include "sram/sram.h"

#include "data/generic_data.h"
#include "data/sram_pointers.h"
#include "data/menus/pause_screen_misc_data.h"

#include "structs/save_file.h"

/**
 * @brief 7eea4 | 18 | Reads all of flash sram into ewram and ram
 * 
 */
void Sram_ReadAll(void)
{
    Sram_ReadHeader();
    unk_7fb84();
    SramRead_MostRecentSaveFile();
    SramRead_Language();
}

/**
 * @brief 7eebc | 6c | Writes the sram header
 * 
 */
void Sram_WriteHeader(void)
{
    s32 i;
    u32* ptr;
    s32 checksum;
    struct SramHeader* pHeader;

    pHeader = &gSram.header;
    pHeader->unk_8 = 0x30;
    pHeader->unk_9 = 0x31;
    pHeader->unk_A = gSramHeaderUnk_3000010;
    pHeader->unk_B = 2;

    for (i = 0; i < SRAM_VERSION_TEXT_SIZE; i++)
        pHeader->versionText[i] = sSramHeaderVersionText[i];

    pHeader->checksum = 0;
    pHeader->notChecksum = -1;

    ptr = (u32*)&gSram.header;
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SramHeader, 4, u32) - 1; i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pHeader->checksum = checksum;
    pHeader->notChecksum = ~checksum;
    unk_c98();
}

// 0x0807EF28
NAKED_FUNCTION
void Sram_ReadHeader(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #4\n\
	bl SramTestFlash\n\
	ldr r0, _0807EFA0 @ =0x03000B8E\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0807EF42\n\
	bl ReadSramHeaderToEwram\n\
_0807EF42:\n\
	movs r0, #0\n\
	bl Sram_VerifyHeader\n\
	adds r6, r0, #0\n\
	movs r0, #1\n\
	bl Sram_VerifyHeader\n\
	mov sb, r0\n\
	movs r0, #2\n\
	bl Sram_VerifyHeader\n\
	mov r8, r0\n\
	cmp r6, #0\n\
	beq _0807F00C\n\
	mov r0, sp\n\
	ldr r1, _0807EFA4 @ =0x0000FFFF\n\
	adds r2, r1, #0\n\
	strh r2, [r0]\n\
	ldr r4, _0807EFA8 @ =0x040000D4\n\
	str r0, [r4]\n\
	ldr r5, _0807EFAC @ =0x02038000\n\
	str r5, [r4, #4]\n\
	ldr r1, _0807EFB0 @ =0x81000040\n\
	str r1, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	beq _0807EFD8\n\
	mov r0, sp\n\
	strh r2, [r0]\n\
	str r0, [r4]\n\
	ldr r0, _0807EFB4 @ =0x0203F100\n\
	str r0, [r4, #4]\n\
	str r1, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	beq _0807EFBC\n\
	mov r0, sp\n\
	strh r2, [r0]\n\
	str r0, [r4]\n\
	ldr r0, _0807EFB8 @ =0x02038080\n\
	str r0, [r4, #4]\n\
	str r1, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	b _0807F034\n\
	.align 2, 0\n\
_0807EFA0: .4byte 0x03000B8E\n\
_0807EFA4: .4byte 0x0000FFFF\n\
_0807EFA8: .4byte 0x040000D4\n\
_0807EFAC: .4byte 0x02038000\n\
_0807EFB0: .4byte 0x81000040\n\
_0807EFB4: .4byte 0x0203F100\n\
_0807EFB8: .4byte 0x02038080\n\
_0807EFBC:\n\
	ldr r0, _0807EFD0 @ =0x02038080\n\
	str r0, [r4]\n\
	str r5, [r4, #4]\n\
	ldr r0, _0807EFD4 @ =0x80000040\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r6, #0\n\
	bl unk_c98\n\
	b _0807F034\n\
	.align 2, 0\n\
_0807EFD0: .4byte 0x02038080\n\
_0807EFD4: .4byte 0x80000040\n\
_0807EFD8:\n\
	ldr r0, _0807F000 @ =0x0203F100\n\
	str r0, [r4]\n\
	str r5, [r4, #4]\n\
	ldr r7, _0807F004 @ =0x80000040\n\
	str r7, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r6, #0\n\
	bl unk_c98\n\
	mov r1, sb\n\
	cmp r1, #0\n\
	beq _0807F034\n\
	str r5, [r4]\n\
	ldr r0, _0807F008 @ =0x02038080\n\
	str r0, [r4, #4]\n\
	str r7, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	bl unk_cd8\n\
	b _0807F034\n\
	.align 2, 0\n\
_0807F000: .4byte 0x0203F100\n\
_0807F004: .4byte 0x80000040\n\
_0807F008: .4byte 0x02038080\n\
_0807F00C:\n\
	ldr r4, _0807F040 @ =0x040000D4\n\
	ldr r7, _0807F044 @ =0x02038000\n\
	str r7, [r4]\n\
	ldr r0, _0807F048 @ =0x02038080\n\
	str r0, [r4, #4]\n\
	ldr r5, _0807F04C @ =0x80000040\n\
	str r5, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	bl unk_cd8\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	beq _0807F034\n\
	str r7, [r4]\n\
	ldr r0, _0807F050 @ =0x0203F100\n\
	str r0, [r4, #4]\n\
	str r5, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	bl unk_cf0\n\
_0807F034:\n\
	cmp r6, #0\n\
	bne _0807F058\n\
	ldr r0, _0807F054 @ =0x03000010\n\
	strb r6, [r0]\n\
	b _0807F066\n\
	.align 2, 0\n\
_0807F040: .4byte 0x040000D4\n\
_0807F044: .4byte 0x02038000\n\
_0807F048: .4byte 0x02038080\n\
_0807F04C: .4byte 0x80000040\n\
_0807F050: .4byte 0x0203F100\n\
_0807F054: .4byte 0x03000010\n\
_0807F058:\n\
	bl EraseSram\n\
	ldr r1, _0807F074 @ =0x03000010\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	bl Sram_WriteHeader\n\
_0807F066:\n\
	add sp, #4\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807F074: .4byte 0x03000010\n\
    .syntax divided\n");
}

// 0x0807F078
NAKED_FUNCTION
u32 Sram_VerifyHeader(u8 header)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	movs r4, #0\n\
	ldr r1, _0807F0EC @ =0x0203F100\n\
	cmp r0, #2\n\
	beq _0807F08E\n\
	ldr r1, _0807F0F0 @ =0x02038000\n\
	cmp r0, #1\n\
	bne _0807F08E\n\
	adds r1, #0x80\n\
_0807F08E:\n\
	movs r2, #0\n\
	ldr r7, [r1]\n\
	adds r5, r1, #0\n\
	adds r5, #0xc\n\
	ldr r0, [r1, #4]\n\
	mov ip, r0\n\
	movs r3, #7\n\
_0807F09C:\n\
	ldm r1!, {r0}\n\
	adds r2, r2, r0\n\
	ldm r1!, {r0}\n\
	adds r2, r2, r0\n\
	ldm r1!, {r0}\n\
	adds r2, r2, r0\n\
	ldm r1!, {r0}\n\
	adds r2, r2, r0\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _0807F09C\n\
	cmp r7, r2\n\
	beq _0807F0BA\n\
	movs r0, #1\n\
	orrs r4, r0\n\
_0807F0BA:\n\
	movs r3, #0\n\
	adds r2, r5, #0\n\
	ldr r6, _0807F0F4 @ =0x08582248\n\
	movs r5, #2\n\
_0807F0C2:\n\
	adds r0, r2, r3\n\
	adds r1, r3, r6\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _0807F0D0\n\
	orrs r4, r5\n\
_0807F0D0:\n\
	adds r3, #1\n\
	cmp r3, #0x13\n\
	ble _0807F0C2\n\
	mov r1, ip\n\
	mvns r0, r1\n\
	cmp r7, r0\n\
	beq _0807F0E2\n\
	movs r0, #4\n\
	orrs r4, r0\n\
_0807F0E2:\n\
	adds r0, r4, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0807F0EC: .4byte 0x0203F100\n\
_0807F0F0: .4byte 0x02038000\n\
_0807F0F4: .4byte 0x08582248\n\
    .syntax divided\n");
}

// 0x0807F0F8
NAKED_FUNCTION
void Sram_ProcessIntroSave(u8 stage)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	adds r3, r1, #0\n\
	ldr r6, _0807F128 @ =0x03000B94\n\
	ldr r4, _0807F12C @ =0x03000B8D\n\
	ldrb r0, [r4]\n\
	lsls r2, r0, #2\n\
	adds r0, r2, r0\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r6\n\
	ldrb r5, [r0, #0xf]\n\
	cmp r5, #0\n\
	beq _0807F17C\n\
	cmp r1, #2\n\
	bgt _0807F130\n\
	cmp r1, #1\n\
	blt _0807F120\n\
	b _0807F222\n\
_0807F120:\n\
	cmp r1, #0\n\
	beq _0807F136\n\
	b _0807F21C\n\
	.align 2, 0\n\
_0807F128: .4byte 0x03000B94\n\
_0807F12C: .4byte 0x03000B8D\n\
_0807F130:\n\
	cmp r1, #3\n\
	beq _0807F158\n\
	b _0807F21C\n\
_0807F136:\n\
	ldr r1, _0807F150 @ =gDisableSoftReset\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r0, _0807F154 @ =0x03000014\n\
	movs r2, #1\n\
	strb r2, [r0, #1]\n\
	ldrb r1, [r4]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r6\n\
	strb r2, [r0, #0x11]\n\
	b _0807F222\n\
	.align 2, 0\n\
_0807F150: .4byte gDisableSoftReset\n\
_0807F154: .4byte 0x03000014\n\
_0807F158:\n\
	ldr r0, _0807F174 @ =0x0858225C\n\
	adds r0, r2, r0\n\
	ldr r1, [r0]\n\
	ldr r0, _0807F178 @ =0x08582268\n\
	adds r0, r2, r0\n\
	ldr r2, [r0]\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	b _0807F21C\n\
	.align 2, 0\n\
_0807F174: .4byte 0x0858225C\n\
_0807F178: .4byte 0x08582268\n\
_0807F17C:\n\
	cmp r1, #1\n\
	beq _0807F1E4\n\
	cmp r1, #1\n\
	bgt _0807F18A\n\
	cmp r1, #0\n\
	beq _0807F194\n\
	b _0807F21C\n\
_0807F18A:\n\
	cmp r3, #2\n\
	beq _0807F1EA\n\
	cmp r3, #3\n\
	beq _0807F1F0\n\
	b _0807F21C\n\
_0807F194:\n\
	ldr r1, _0807F1D8 @ =gDisableSoftReset\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r3, _0807F1DC @ =0x03000014\n\
	movs r2, #1\n\
	strb r2, [r3, #1]\n\
	ldrb r1, [r4]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r6\n\
	strb r2, [r0, #0x11]\n\
	ldrb r1, [r4]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r6\n\
	ldrb r0, [r0, #0x10]\n\
	strb r0, [r3]\n\
	ldr r1, _0807F1E0 @ =0x0858225C\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #2\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	movs r1, #0\n\
	bl BitFill\n\
	b _0807F222\n\
	.align 2, 0\n\
_0807F1D8: .4byte gDisableSoftReset\n\
_0807F1DC: .4byte 0x03000014\n\
_0807F1E0: .4byte 0x0858225C\n\
_0807F1E4:\n\
	bl Sram_WriteHeaderAndGameInfo\n\
	b _0807F222\n\
_0807F1EA:\n\
	bl WriteMostRecentFileToSram\n\
	b _0807F222\n\
_0807F1F0:\n\
	ldr r0, _0807F210 @ =0x0858225C\n\
	adds r0, r2, r0\n\
	ldr r1, [r0]\n\
	ldr r0, _0807F214 @ =0x08582268\n\
	adds r0, r2, r0\n\
	ldr r2, [r0]\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r0, _0807F218 @ =gDisableSoftReset\n\
	strb r5, [r0]\n\
	b _0807F222\n\
	.align 2, 0\n\
_0807F210: .4byte 0x0858225C\n\
_0807F214: .4byte 0x08582268\n\
_0807F218: .4byte gDisableSoftReset\n\
_0807F21C:\n\
	ldr r1, _0807F22C @ =gDisableSoftReset\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_0807F222:\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807F22C: .4byte gDisableSoftReset\n\
    .syntax divided\n");
}

// 0x0807F230
NAKED_FUNCTION
void Sram_WriteHeaderAndGameInfo(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r5, _0807F2A0 @ =0x0858225C\n\
	ldr r4, _0807F2A4 @ =0x03000B8D\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	ldr r6, [r0]\n\
	ldr r1, _0807F2A8 @ =0x08582200\n\
	adds r0, r6, #0\n\
	bl Sram_StringCopy_MetroidEpisode4A\n\
	movs r0, #0\n\
	str r0, [r6, #0x10]\n\
	subs r0, #1\n\
	str r0, [r6, #0x14]\n\
	ldr r1, _0807F2AC @ =0x03000014\n\
	ldrb r0, [r1, #1]\n\
	strb r0, [r6, #0x19]\n\
	ldrb r0, [r1]\n\
	strb r0, [r6, #0x18]\n\
	adds r0, r6, #0\n\
	adds r0, #0xf0\n\
	ldr r1, _0807F2B0 @ =0x085821F8\n\
	bl Sram_StringCopy_SAVE_END\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	ldr r2, [r0]\n\
	movs r1, #0\n\
	movs r3, #0x8f\n\
_0807F26E:\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _0807F26E\n\
	str r1, [r6, #0x10]\n\
	mvns r0, r1\n\
	str r0, [r6, #0x14]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807F2A0: .4byte 0x0858225C\n\
_0807F2A4: .4byte 0x03000B8D\n\
_0807F2A8: .4byte 0x08582200\n\
_0807F2AC: .4byte 0x03000014\n\
_0807F2B0: .4byte 0x085821F8\n\
    .syntax divided\n");
}

// 0x0807F2B4
NAKED_FUNCTION
void Sram_ProcessEndingSave(u8 stage)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #1\n\
	beq _0807F2DA\n\
	cmp r1, #1\n\
	bgt _0807F2CA\n\
	cmp r1, #0\n\
	beq _0807F2D4\n\
	b _0807F330\n\
_0807F2CA:\n\
	cmp r1, #2\n\
	beq _0807F2E8\n\
	cmp r1, #3\n\
	beq _0807F310\n\
	b _0807F330\n\
_0807F2D4:\n\
	bl ReadMostRecentFileToEwram\n\
	b _0807F330\n\
_0807F2DA:\n\
	ldr r0, _0807F2E4 @ =0x03000014\n\
	strb r1, [r0]\n\
	bl Sram_CopyGameCompletion\n\
	b _0807F330\n\
	.align 2, 0\n\
_0807F2E4: .4byte 0x03000014\n\
_0807F2E8:\n\
	bl WriteMostRecentFileToSram\n\
	ldr r2, _0807F304 @ =0x03000B94\n\
	ldr r0, _0807F308 @ =0x03000B8D\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r1, _0807F30C @ =0x03000014\n\
	ldrb r1, [r1]\n\
	strb r1, [r0, #0x10]\n\
	b _0807F330\n\
	.align 2, 0\n\
_0807F304: .4byte 0x03000B94\n\
_0807F308: .4byte 0x03000B8D\n\
_0807F30C: .4byte 0x03000014\n\
_0807F310:\n\
	ldr r1, _0807F338 @ =0x0858225C\n\
	ldr r0, _0807F33C @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r1\n\
	ldr r1, [r1]\n\
	ldr r2, _0807F340 @ =0x08582268\n\
	adds r0, r0, r2\n\
	ldr r2, [r0]\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
_0807F330:\n\
	add sp, #4\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807F338: .4byte 0x0858225C\n\
_0807F33C: .4byte 0x03000B8D\n\
_0807F340: .4byte 0x08582268\n\
    .syntax divided\n");
}

/**
 * @brief 7f344 | 68 | Copies the game completion flag to the current save file and updates its checksum
 * 
 */
void Sram_CopyGameCompletion(void)
{
    s32 i;
    u32* ptr;
    s32 checksum;
    struct SaveFile* pFile;

    pFile = (struct SaveFile*)sSaveDataEwramPointers[gMostRecentSaveFile];
    pFile->checksum = 0;
    pFile->notChecksum = -1;
    pFile->gameCompletion.completedGame = gGameCompletion.completedGame;

    ptr = (u32*)sSaveDataEwramPointers[gMostRecentSaveFile];
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32) - 1; i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

// 0x0807F3AC
NAKED_FUNCTION
void Sram_QuickSave(u8 stage)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r1, r0, #0\n\
	cmp r0, #1\n\
	beq _0807F3E8\n\
	cmp r0, #1\n\
	bgt _0807F3C4\n\
	cmp r0, #0\n\
	beq _0807F3CE\n\
	b _0807F434\n\
_0807F3C4:\n\
	cmp r1, #2\n\
	beq _0807F3F2\n\
	cmp r1, #3\n\
	beq _0807F414\n\
	b _0807F434\n\
_0807F3CE:\n\
	ldr r0, _0807F3E0 @ =gDisableSoftReset\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	ldr r0, _0807F3E4 @ =0x03000B90\n\
	strb r1, [r0]\n\
	bl WriteMostRecentFileBackupToSram\n\
	b _0807F43A\n\
	.align 2, 0\n\
_0807F3E0: .4byte gDisableSoftReset\n\
_0807F3E4: .4byte 0x03000B90\n\
_0807F3E8:\n\
	bl SramWrite_WorldData\n\
	bl SramWrite_ToEwram\n\
	b _0807F43A\n\
_0807F3F2:\n\
	bl WriteMostRecentFileToSram\n\
	ldr r2, _0807F40C @ =0x03000B94\n\
	ldr r0, _0807F410 @ =0x03000B8D\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	movs r1, #1\n\
	strb r1, [r0]\n\
	b _0807F43A\n\
	.align 2, 0\n\
_0807F40C: .4byte 0x03000B94\n\
_0807F410: .4byte 0x03000B8D\n\
_0807F414:\n\
	ldr r1, _0807F440 @ =0x0858225C\n\
	ldr r0, _0807F444 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r1\n\
	ldr r1, [r1]\n\
	ldr r2, _0807F448 @ =0x08582268\n\
	adds r0, r0, r2\n\
	ldr r2, [r0]\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
_0807F434:\n\
	ldr r1, _0807F44C @ =gDisableSoftReset\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_0807F43A:\n\
	add sp, #4\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807F440: .4byte 0x0858225C\n\
_0807F444: .4byte 0x03000B8D\n\
_0807F448: .4byte 0x08582268\n\
_0807F44C: .4byte gDisableSoftReset\n\
    .syntax divided\n");
}

// 0x0807F450
NAKED_FUNCTION
void SramWrite_ToEwram(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x38\n\
	ldr r4, _0807F6F8 @ =gMusicInfo\n\
	ldrh r1, [r4, #0x1c]\n\
	ldr r0, _0807F6FC @ =0xFFFF0000\n\
	ands r0, r5\n\
	orrs r0, r1\n\
	ldrh r1, [r4, #0x1e]\n\
	lsls r1, r1, #0x10\n\
	ldr r3, _0807F700 @ =0x0000FFFF\n\
	ands r0, r3\n\
	adds r5, r0, #0\n\
	orrs r5, r1\n\
	adds r0, r4, #0\n\
	adds r0, #0x20\n\
	ldrb r0, [r0]\n\
	ldr r2, _0807F704 @ =0xFFFFFF00\n\
	ands r2, r6\n\
	orrs r2, r0\n\
	adds r0, r4, #0\n\
	adds r0, #0x21\n\
	ldrb r1, [r0]\n\
	lsls r1, r1, #8\n\
	ldr r0, _0807F708 @ =0xFFFF00FF\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	ldrh r1, [r4, #2]\n\
	lsls r1, r1, #0x10\n\
	ands r0, r3\n\
	adds r6, r0, #0\n\
	orrs r6, r1\n\
	ldr r1, _0807F70C @ =0x0858225C\n\
	ldr r0, _0807F710 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r4, [r0]\n\
	ldr r1, _0807F714 @ =0x08582200\n\
	adds r0, r4, #0\n\
	bl Sram_StringCopy_MetroidEpisode4A\n\
	movs r0, #0\n\
	str r0, [r4, #0x10]\n\
	subs r0, #1\n\
	str r0, [r4, #0x14]\n\
	ldr r0, _0807F718 @ =0x03000014\n\
	ldr r0, [r0]\n\
	str r0, [r4, #0x18]\n\
	ldr r0, _0807F71C @ =0x03000B90\n\
	ldrb r0, [r0]\n\
	strb r0, [r4, #0x1c]\n\
	ldr r0, _0807F720 @ =gCurrentArea\n\
	ldrb r0, [r0]\n\
	strb r0, [r4, #0x1d]\n\
	ldr r0, _0807F724 @ =gCurrentRoom\n\
	ldrb r0, [r0]\n\
	strb r0, [r4, #0x1e]\n\
	ldr r0, _0807F728 @ =gLastDoorUsed\n\
	ldrb r0, [r0]\n\
	strb r0, [r4, #0x1f]\n\
	ldr r0, _0807F72C @ =gAbilityCount\n\
	ldrb r1, [r0]\n\
	adds r0, r4, #0\n\
	adds r0, #0x20\n\
	strb r1, [r0]\n\
	ldr r0, _0807F730 @ =gEventCounter\n\
	ldrb r0, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0x21\n\
	strb r0, [r1]\n\
	ldr r0, _0807F734 @ =gPreviousNavigationConversation\n\
	ldrb r0, [r0]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	ldr r0, _0807F738 @ =gPreviousCutscene\n\
	ldrb r0, [r0]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	ldr r0, _0807F73C @ =0x03000031\n\
	ldrb r1, [r0]\n\
	adds r0, r4, #0\n\
	adds r0, #0x24\n\
	strb r1, [r0]\n\
	ldr r0, _0807F740 @ =0x03000032\n\
	ldrb r0, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	strb r0, [r1]\n\
	ldr r0, _0807F744 @ =gSoundEventCounter\n\
	ldrh r0, [r0]\n\
	strh r0, [r4, #0x26]\n\
	ldr r0, _0807F748 @ =gPreviousSoundEvent\n\
	ldrh r0, [r0]\n\
	strh r0, [r4, #0x28]\n\
	ldr r0, _0807F74C @ =0x0300004D\n\
	ldrb r0, [r0]\n\
	adds r1, #5\n\
	strb r0, [r1]\n\
	ldr r0, _0807F750 @ =gSecurityHatchLevelBackup\n\
	ldrb r0, [r0]\n\
	adds r1, #1\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	ldr r0, _0807F754 @ =0x03000124\n\
	ldm r0!, {r2, r3, r7}\n\
	stm r1!, {r2, r3, r7}\n\
	ldm r0!, {r2, r3}\n\
	stm r1!, {r2, r3}\n\
	ldr r0, _0807F758 @ =0x03001224\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	adds r0, #0x40\n\
	strh r1, [r0]\n\
	ldr r0, _0807F75C @ =0x03001226\n\
	ldrh r0, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0x42\n\
	strh r0, [r1]\n\
	ldr r0, _0807F760 @ =gBg1XPosition\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	adds r0, #0x44\n\
	strh r1, [r0]\n\
	ldr r0, _0807F764 @ =gBg1YPosition\n\
	ldrh r0, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0x46\n\
	strh r0, [r1]\n\
	ldr r0, _0807F768 @ =0x0300122C\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	adds r0, #0x48\n\
	strh r1, [r0]\n\
	ldr r0, _0807F76C @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0x4a\n\
	strh r0, [r1]\n\
	ldr r0, _0807F770 @ =0x03001230\n\
	ldrh r1, [r0]\n\
	adds r0, r4, #0\n\
	adds r0, #0x4c\n\
	strh r1, [r0]\n\
	ldr r0, _0807F774 @ =0x03001232\n\
	ldrh r0, [r0]\n\
	adds r1, r4, #0\n\
	adds r1, #0x4e\n\
	strh r0, [r1]\n\
	movs r3, #0\n\
	adds r2, r4, #0\n\
	adds r2, #0x50\n\
	ldr r7, _0807F778 @ =0x03000033\n\
_0807F588:\n\
	adds r0, r2, r3\n\
	adds r1, r3, r7\n\
	ldrb r1, [r1]\n\
	strb r1, [r0]\n\
	adds r3, #1\n\
	cmp r3, #7\n\
	ble _0807F588\n\
	movs r3, #0\n\
	movs r7, #0x60\n\
	adds r7, r7, r4\n\
	mov ip, r7\n\
	movs r0, #0x8c\n\
	adds r0, r0, r4\n\
	mov r8, r0\n\
	movs r1, #0x98\n\
	adds r1, r1, r4\n\
	mov sb, r1\n\
	movs r2, #0xa4\n\
	adds r2, r2, r4\n\
	mov sl, r2\n\
	adds r7, r4, #0\n\
	adds r7, #0xb4\n\
	str r7, [sp]\n\
	adds r0, r4, #0\n\
	adds r0, #0xc4\n\
	str r0, [sp, #4]\n\
	adds r1, r4, #0\n\
	adds r1, #0xd4\n\
	str r1, [sp, #8]\n\
	adds r2, r4, #0\n\
	adds r2, #0xd6\n\
	str r2, [sp, #0xc]\n\
	adds r7, #0x24\n\
	str r7, [sp, #0x10]\n\
	adds r0, #0x16\n\
	str r0, [sp, #0x14]\n\
	adds r1, #8\n\
	str r1, [sp, #0x18]\n\
	adds r2, #8\n\
	str r2, [sp, #0x1c]\n\
	adds r7, #8\n\
	str r7, [sp, #0x20]\n\
	adds r0, #8\n\
	str r0, [sp, #0x24]\n\
	adds r1, #7\n\
	str r1, [sp, #0x28]\n\
	adds r2, #6\n\
	str r2, [sp, #0x2c]\n\
	adds r7, #8\n\
	str r7, [sp, #0x30]\n\
	adds r0, #0xe\n\
	str r0, [sp, #0x34]\n\
	subs r2, #0x8c\n\
	ldr r7, _0807F77C @ =0x0300003B\n\
_0807F5F4:\n\
	adds r0, r2, r3\n\
	adds r1, r3, r7\n\
	ldrb r1, [r1]\n\
	strb r1, [r0]\n\
	adds r3, #1\n\
	cmp r3, #7\n\
	ble _0807F5F4\n\
	mov r1, ip\n\
	ldr r0, _0807F780 @ =gSamusData\n\
	ldm r0!, {r2, r3, r7}\n\
	stm r1!, {r2, r3, r7}\n\
	ldm r0!, {r2, r3, r7}\n\
	stm r1!, {r2, r3, r7}\n\
	ldm r0!, {r2, r3, r7}\n\
	stm r1!, {r2, r3, r7}\n\
	ldm r0!, {r2, r3}\n\
	stm r1!, {r2, r3}\n\
	mov r1, r8\n\
	ldr r0, _0807F784 @ =gSamusAnimationInfo\n\
	ldm r0!, {r2, r3, r7}\n\
	stm r1!, {r2, r3, r7}\n\
	mov r1, sb\n\
	ldr r0, _0807F788 @ =0x030012E4\n\
	ldm r0!, {r2, r3, r7}\n\
	stm r1!, {r2, r3, r7}\n\
	mov r1, sl\n\
	ldr r0, _0807F78C @ =0x030012F0\n\
	ldm r0!, {r2, r3, r7}\n\
	stm r1!, {r2, r3, r7}\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r1, [sp]\n\
	ldr r0, _0807F78C @ =0x030012F0\n\
	adds r0, #0x10\n\
	ldm r0!, {r2, r3, r7}\n\
	stm r1!, {r2, r3, r7}\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r1, [sp, #4]\n\
	ldr r0, _0807F790 @ =gEquipment\n\
	ldm r0!, {r2, r3, r7}\n\
	stm r1!, {r2, r3, r7}\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r7, _0807F794 @ =gPreventMovementTimer\n\
	ldrh r0, [r7]\n\
	ldr r1, [sp, #8]\n\
	strh r0, [r1]\n\
	ldr r2, _0807F798 @ =gDisableDrawingSamusAndScrollingFlag\n\
	ldrb r0, [r2]\n\
	ldr r3, [sp, #0xc]\n\
	strb r0, [r3]\n\
	ldr r7, _0807F79C @ =gAtmosphericStabilizersOnline\n\
	ldrh r0, [r7]\n\
	ldr r1, [sp, #0x10]\n\
	strh r0, [r1]\n\
	ldr r2, _0807F7A0 @ =gMissileGeronsDestroyed\n\
	ldrh r0, [r2]\n\
	ldr r3, [sp, #0x14]\n\
	strh r0, [r3]\n\
	ldr r7, _0807F7A4 @ =gSuperMissileGeronsDestroyed\n\
	ldrh r0, [r7]\n\
	ldr r1, [sp, #0x18]\n\
	strh r0, [r1]\n\
	ldr r2, _0807F7A8 @ =gPowerBombGeronsDestroyed\n\
	ldrh r0, [r2]\n\
	ldr r3, [sp, #0x1c]\n\
	strh r0, [r3]\n\
	ldr r7, _0807F7AC @ =gGadorasDestroyed\n\
	ldrh r0, [r7]\n\
	ldr r1, [sp, #0x20]\n\
	strh r0, [r1]\n\
	ldr r2, _0807F7B0 @ =gMissileHatchDestroyed\n\
	ldrb r0, [r2]\n\
	ldr r3, [sp, #0x24]\n\
	strb r0, [r3]\n\
	ldr r7, _0807F7B4 @ =gWaterLowered\n\
	ldrb r0, [r7]\n\
	ldr r1, [sp, #0x28]\n\
	strb r0, [r1]\n\
	ldr r2, _0807F7B8 @ =gInGameTimer\n\
	ldr r0, [r2]\n\
	ldr r3, [sp, #0x2c]\n\
	str r0, [r3]\n\
	ldr r7, [sp, #0x30]\n\
	str r5, [r7]\n\
	str r6, [r7, #4]\n\
	ldr r0, [sp, #0x34]\n\
	ldr r1, _0807F7BC @ =0x085821F8\n\
	bl Sram_StringCopy_SAVE_END\n\
	ldr r1, _0807F70C @ =0x0858225C\n\
	ldr r0, _0807F710 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	movs r1, #0\n\
	movs r3, #0x8f\n\
_0807F6BA:\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r2!, {r0}\n\
	adds r1, r1, r0\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _0807F6BA\n\
	str r1, [r4, #0x10]\n\
	mvns r0, r1\n\
	str r0, [r4, #0x14]\n\
	add sp, #0x38\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807F6F8: .4byte gMusicInfo\n\
_0807F6FC: .4byte 0xFFFF0000\n\
_0807F700: .4byte 0x0000FFFF\n\
_0807F704: .4byte 0xFFFFFF00\n\
_0807F708: .4byte 0xFFFF00FF\n\
_0807F70C: .4byte 0x0858225C\n\
_0807F710: .4byte 0x03000B8D\n\
_0807F714: .4byte 0x08582200\n\
_0807F718: .4byte 0x03000014\n\
_0807F71C: .4byte 0x03000B90\n\
_0807F720: .4byte gCurrentArea\n\
_0807F724: .4byte gCurrentRoom\n\
_0807F728: .4byte gLastDoorUsed\n\
_0807F72C: .4byte gAbilityCount\n\
_0807F730: .4byte gEventCounter\n\
_0807F734: .4byte gPreviousNavigationConversation\n\
_0807F738: .4byte gPreviousCutscene\n\
_0807F73C: .4byte 0x03000031\n\
_0807F740: .4byte 0x03000032\n\
_0807F744: .4byte gSoundEventCounter\n\
_0807F748: .4byte gPreviousSoundEvent\n\
_0807F74C: .4byte 0x0300004D\n\
_0807F750: .4byte gSecurityHatchLevelBackup\n\
_0807F754: .4byte 0x03000124\n\
_0807F758: .4byte 0x03001224\n\
_0807F75C: .4byte 0x03001226\n\
_0807F760: .4byte gBg1XPosition\n\
_0807F764: .4byte gBg1YPosition\n\
_0807F768: .4byte 0x0300122C\n\
_0807F76C: .4byte 0x0300122E\n\
_0807F770: .4byte 0x03001230\n\
_0807F774: .4byte 0x03001232\n\
_0807F778: .4byte 0x03000033\n\
_0807F77C: .4byte 0x0300003B\n\
_0807F780: .4byte gSamusData\n\
_0807F784: .4byte gSamusAnimationInfo\n\
_0807F788: .4byte 0x030012E4\n\
_0807F78C: .4byte 0x030012F0\n\
_0807F790: .4byte gEquipment\n\
_0807F794: .4byte gPreventMovementTimer\n\
_0807F798: .4byte gDisableDrawingSamusAndScrollingFlag\n\
_0807F79C: .4byte gAtmosphericStabilizersOnline\n\
_0807F7A0: .4byte gMissileGeronsDestroyed\n\
_0807F7A4: .4byte gSuperMissileGeronsDestroyed\n\
_0807F7A8: .4byte gPowerBombGeronsDestroyed\n\
_0807F7AC: .4byte gGadorasDestroyed\n\
_0807F7B0: .4byte gMissileHatchDestroyed\n\
_0807F7B4: .4byte gWaterLowered\n\
_0807F7B8: .4byte gInGameTimer\n\
_0807F7BC: .4byte 0x085821F8\n\
    .syntax divided\n");
}

// 0x0807F7C0
NAKED_FUNCTION
void SramRead_FromEwram(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x2c\n\
	ldr r1, _0807F9F8 @ =0x0858225C\n\
	ldr r0, _0807F9FC @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	ldr r1, _0807FA00 @ =0x03000014\n\
	ldr r0, [r2, #0x18]\n\
	str r0, [r1]\n\
	ldr r1, _0807FA04 @ =0x03000B90\n\
	ldrb r0, [r2, #0x1c]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA08 @ =gCurrentArea\n\
	ldrb r0, [r2, #0x1d]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA0C @ =gCurrentRoom\n\
	ldrb r0, [r2, #0x1e]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA10 @ =gLastDoorUsed\n\
	ldrb r0, [r2, #0x1f]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA14 @ =gAbilityCount\n\
	adds r0, r2, #0\n\
	adds r0, #0x20\n\
	ldrb r0, [r0]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA18 @ =gEventCounter\n\
	adds r0, r2, #0\n\
	adds r0, #0x21\n\
	ldrb r0, [r0]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA1C @ =gPreviousNavigationConversation\n\
	adds r0, r2, #0\n\
	adds r0, #0x22\n\
	ldrb r0, [r0]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA20 @ =gPreviousCutscene\n\
	adds r0, r2, #0\n\
	adds r0, #0x23\n\
	ldrb r0, [r0]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA24 @ =0x03000031\n\
	adds r0, r2, #0\n\
	adds r0, #0x24\n\
	ldrb r0, [r0]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA28 @ =0x03000032\n\
	adds r0, r2, #0\n\
	adds r0, #0x25\n\
	ldrb r0, [r0]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA2C @ =gSoundEventCounter\n\
	ldrh r0, [r2, #0x26]\n\
	strh r0, [r1]\n\
	ldr r1, _0807FA30 @ =gPreviousSoundEvent\n\
	ldrh r0, [r2, #0x28]\n\
	strh r0, [r1]\n\
	ldr r1, _0807FA34 @ =0x0300004D\n\
	adds r0, r2, #0\n\
	adds r0, #0x2a\n\
	ldrb r0, [r0]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA38 @ =gSecurityHatchLevelBackup\n\
	adds r0, r2, #0\n\
	adds r0, #0x2b\n\
	ldrb r0, [r0]\n\
	strb r0, [r1]\n\
	ldr r1, _0807FA3C @ =0x03000124\n\
	adds r0, r2, #0\n\
	adds r0, #0x2c\n\
	ldm r0!, {r3, r4, r5}\n\
	stm r1!, {r3, r4, r5}\n\
	ldm r0!, {r3, r4}\n\
	stm r1!, {r3, r4}\n\
	ldr r1, _0807FA40 @ =0x03001224\n\
	adds r0, r2, #0\n\
	adds r0, #0x40\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0807FA44 @ =0x03001226\n\
	adds r0, r2, #0\n\
	adds r0, #0x42\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0807FA48 @ =gBg1XPosition\n\
	adds r0, r2, #0\n\
	adds r0, #0x44\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0807FA4C @ =gBg1YPosition\n\
	adds r0, r2, #0\n\
	adds r0, #0x46\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0807FA50 @ =0x0300122C\n\
	adds r0, r2, #0\n\
	adds r0, #0x48\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0807FA54 @ =0x0300122E\n\
	adds r0, r2, #0\n\
	adds r0, #0x4a\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0807FA58 @ =0x03001230\n\
	adds r0, r2, #0\n\
	adds r0, #0x4c\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0807FA5C @ =0x03001232\n\
	adds r0, r2, #0\n\
	adds r0, #0x4e\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	movs r3, #0\n\
	ldr r5, _0807FA60 @ =gMusicInfo\n\
	mov ip, r5\n\
	ldr r5, _0807FA64 @ =0x03000033\n\
	adds r4, r2, #0\n\
	adds r4, #0x50\n\
_0807F8BC:\n\
	adds r0, r3, r5\n\
	adds r1, r4, r3\n\
	ldrb r1, [r1]\n\
	strb r1, [r0]\n\
	adds r3, #1\n\
	cmp r3, #7\n\
	ble _0807F8BC\n\
	movs r3, #0\n\
	adds r5, r2, #0\n\
	adds r5, #0x60\n\
	adds r6, r2, #0\n\
	adds r6, #0x8c\n\
	adds r7, r2, #0\n\
	adds r7, #0x98\n\
	movs r0, #0xa4\n\
	adds r0, r0, r2\n\
	mov r8, r0\n\
	movs r1, #0xb4\n\
	adds r1, r1, r2\n\
	mov sb, r1\n\
	movs r4, #0xc4\n\
	adds r4, r4, r2\n\
	mov sl, r4\n\
	adds r0, r2, #0\n\
	adds r0, #0xd4\n\
	str r0, [sp]\n\
	adds r1, r2, #0\n\
	adds r1, #0xd6\n\
	str r1, [sp, #4]\n\
	adds r4, r2, #0\n\
	adds r4, #0xd8\n\
	str r4, [sp, #8]\n\
	adds r0, #6\n\
	str r0, [sp, #0xc]\n\
	adds r1, #6\n\
	str r1, [sp, #0x10]\n\
	adds r4, #6\n\
	str r4, [sp, #0x14]\n\
	adds r0, #6\n\
	str r0, [sp, #0x18]\n\
	adds r1, #6\n\
	str r1, [sp, #0x1c]\n\
	adds r4, #5\n\
	str r4, [sp, #0x20]\n\
	adds r0, #4\n\
	str r0, [sp, #0x24]\n\
	adds r1, #6\n\
	str r1, [sp, #0x28]\n\
	ldr r4, _0807FA68 @ =0x0300003B\n\
	adds r2, #0x58\n\
_0807F920:\n\
	adds r0, r3, r4\n\
	adds r1, r2, r3\n\
	ldrb r1, [r1]\n\
	strb r1, [r0]\n\
	adds r3, #1\n\
	cmp r3, #7\n\
	ble _0807F920\n\
	ldr r1, _0807FA6C @ =gSamusData\n\
	adds r0, r5, #0\n\
	ldm r0!, {r2, r3, r4}\n\
	stm r1!, {r2, r3, r4}\n\
	ldm r0!, {r2, r3, r5}\n\
	stm r1!, {r2, r3, r5}\n\
	ldm r0!, {r2, r4, r5}\n\
	stm r1!, {r2, r4, r5}\n\
	ldm r0!, {r3, r4}\n\
	stm r1!, {r3, r4}\n\
	ldr r1, _0807FA70 @ =gSamusAnimationInfo\n\
	adds r0, r6, #0\n\
	ldm r0!, {r2, r3, r5}\n\
	stm r1!, {r2, r3, r5}\n\
	ldr r1, _0807FA74 @ =0x030012E4\n\
	adds r0, r7, #0\n\
	ldm r0!, {r2, r4, r5}\n\
	stm r1!, {r2, r4, r5}\n\
	ldr r1, _0807FA78 @ =0x030012F0\n\
	mov r0, r8\n\
	ldm r0!, {r3, r4, r5}\n\
	stm r1!, {r3, r4, r5}\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r1, _0807FA78 @ =0x030012F0\n\
	adds r1, #0x10\n\
	mov r0, sb\n\
	ldm r0!, {r2, r3, r4}\n\
	stm r1!, {r2, r3, r4}\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r1, _0807FA7C @ =gEquipment\n\
	mov r0, sl\n\
	ldm r0!, {r2, r3, r5}\n\
	stm r1!, {r2, r3, r5}\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r4, [sp]\n\
	ldrh r0, [r4]\n\
	ldr r5, _0807FA80 @ =gPreventMovementTimer\n\
	strh r0, [r5]\n\
	ldr r1, [sp, #4]\n\
	ldrb r0, [r1]\n\
	ldr r2, _0807FA84 @ =gDisableDrawingSamusAndScrollingFlag\n\
	strb r0, [r2]\n\
	ldr r3, [sp, #8]\n\
	ldrh r0, [r3]\n\
	ldr r4, _0807FA88 @ =gAtmosphericStabilizersOnline\n\
	strh r0, [r4]\n\
	ldr r5, [sp, #0xc]\n\
	ldrh r0, [r5]\n\
	ldr r1, _0807FA8C @ =gMissileGeronsDestroyed\n\
	strh r0, [r1]\n\
	ldr r2, [sp, #0x10]\n\
	ldrh r0, [r2]\n\
	ldr r3, _0807FA90 @ =gSuperMissileGeronsDestroyed\n\
	strh r0, [r3]\n\
	ldr r4, [sp, #0x14]\n\
	ldrh r0, [r4]\n\
	ldr r5, _0807FA94 @ =gPowerBombGeronsDestroyed\n\
	strh r0, [r5]\n\
	ldr r1, [sp, #0x18]\n\
	ldrh r0, [r1]\n\
	ldr r2, _0807FA98 @ =gGadorasDestroyed\n\
	strh r0, [r2]\n\
	ldr r3, [sp, #0x1c]\n\
	ldrb r0, [r3]\n\
	ldr r4, _0807FA9C @ =gMissileHatchDestroyed\n\
	strb r0, [r4]\n\
	ldr r5, [sp, #0x20]\n\
	ldrb r0, [r5]\n\
	ldr r1, _0807FAA0 @ =gWaterLowered\n\
	strb r0, [r1]\n\
	ldr r2, [sp, #0x24]\n\
	ldr r0, [r2]\n\
	ldr r3, _0807FAA4 @ =gInGameTimer\n\
	str r0, [r3]\n\
	ldr r4, [sp, #0x28]\n\
	ldr r0, [r4]\n\
	ldr r1, [r4, #4]\n\
	mov r5, ip\n\
	strh r0, [r5, #0x1c]\n\
	lsrs r2, r0, #0x10\n\
	strh r2, [r5, #0x1e]\n\
	mov r2, ip\n\
	adds r2, #0x20\n\
	strb r1, [r2]\n\
	lsrs r2, r1, #8\n\
	mov r3, ip\n\
	adds r3, #0x21\n\
	strb r2, [r3]\n\
	lsrs r0, r1, #0x10\n\
	strh r0, [r5, #2]\n\
	add sp, #0x2c\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807F9F8: .4byte 0x0858225C\n\
_0807F9FC: .4byte 0x03000B8D\n\
_0807FA00: .4byte 0x03000014\n\
_0807FA04: .4byte 0x03000B90\n\
_0807FA08: .4byte gCurrentArea\n\
_0807FA0C: .4byte gCurrentRoom\n\
_0807FA10: .4byte gLastDoorUsed\n\
_0807FA14: .4byte gAbilityCount\n\
_0807FA18: .4byte gEventCounter\n\
_0807FA1C: .4byte gPreviousNavigationConversation\n\
_0807FA20: .4byte gPreviousCutscene\n\
_0807FA24: .4byte 0x03000031\n\
_0807FA28: .4byte 0x03000032\n\
_0807FA2C: .4byte gSoundEventCounter\n\
_0807FA30: .4byte gPreviousSoundEvent\n\
_0807FA34: .4byte 0x0300004D\n\
_0807FA38: .4byte gSecurityHatchLevelBackup\n\
_0807FA3C: .4byte 0x03000124\n\
_0807FA40: .4byte 0x03001224\n\
_0807FA44: .4byte 0x03001226\n\
_0807FA48: .4byte gBg1XPosition\n\
_0807FA4C: .4byte gBg1YPosition\n\
_0807FA50: .4byte 0x0300122C\n\
_0807FA54: .4byte 0x0300122E\n\
_0807FA58: .4byte 0x03001230\n\
_0807FA5C: .4byte 0x03001232\n\
_0807FA60: .4byte gMusicInfo\n\
_0807FA64: .4byte 0x03000033\n\
_0807FA68: .4byte 0x0300003B\n\
_0807FA6C: .4byte gSamusData\n\
_0807FA70: .4byte gSamusAnimationInfo\n\
_0807FA74: .4byte 0x030012E4\n\
_0807FA78: .4byte 0x030012F0\n\
_0807FA7C: .4byte gEquipment\n\
_0807FA80: .4byte gPreventMovementTimer\n\
_0807FA84: .4byte gDisableDrawingSamusAndScrollingFlag\n\
_0807FA88: .4byte gAtmosphericStabilizersOnline\n\
_0807FA8C: .4byte gMissileGeronsDestroyed\n\
_0807FA90: .4byte gSuperMissileGeronsDestroyed\n\
_0807FA94: .4byte gPowerBombGeronsDestroyed\n\
_0807FA98: .4byte gGadorasDestroyed\n\
_0807FA9C: .4byte gMissileHatchDestroyed\n\
_0807FAA0: .4byte gWaterLowered\n\
_0807FAA4: .4byte gInGameTimer\n\
    .syntax divided\n");
}

/**
 * @brief 7faa8 | 1c | Copies the MetroidEpisode4A text
 * 
 */
void Sram_StringCopy_MetroidEpisode4A(u8* dst, const u8* src)
{
    s32 i;

    for (i = 0; i < SRAM_TEXT_SIZE; i++)
        dst[i] = src[i];
}

/**
 * @brief 7fac4 | 1c | Copies the SAVE_END text
 * 
 */
void Sram_StringCopy_SAVE_END(u8* dst, const u8* src)
{
    s32 i;

    for (i = 0; i < SRAM_END_TEXT_SIZE; i++)
        dst[i] = src[i];
}

/**
 * @brief 7fae0 | 68 | Tests that flash sram can be written to
 * 
 */
void SramTestFlash(void)
{
    u32 result;
    s32 i;
    u8 buffer[SRAM_TEXT_SIZE];

    result = 0;
    gSramCorruptFlag = result;

    result |= SramWriteChecked((u8*)sSramTestFlashText, (u8*)SRAM_BASE + 0x7FE0, SRAM_TEXT_SIZE) != NULL;
    SramWriteUnchecked((u8*)SRAM_BASE + 0x7FE0, buffer, SRAM_TEXT_SIZE);

    for (i = 0; i < SRAM_TEXT_SIZE; i++)
        buffer[i]++;

    if (SramWriteChecked(buffer, (u8*)SRAM_BASE + 0x7FE0, SRAM_TEXT_SIZE) != NULL)
        result |= 2;

    gSramCorruptFlag = result != 0;
}

/**
 * @brief 7fb48 | 3c | Backs up the current save file (unused)
 * 
 */
void Sram_BackupCurrentFile_Unused(void)
{
    DmaTransfer(3, sSaveDataEwramPointers[gMostRecentSaveFile], (void*)sSaveDataEwramBackupPointers[gMostRecentSaveFile],
        sizeof(struct SaveFile), 16);
    WriteMostRecentFileBackupToSram();
}

// 0x0807FB84
NAKED_FUNCTION
void unk_7fb84(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x1c\n\
	add r0, sp, #4\n\
	movs r1, #0\n\
	movs r2, #0x14\n\
	bl memset\n\
	ldr r2, _0807FC1C @ =0x03000B94\n\
	movs r5, #2\n\
_0807FB9E:\n\
	adds r1, r2, #0\n\
	add r0, sp, #4\n\
	ldm r0!, {r3, r4, r6}\n\
	stm r1!, {r3, r4, r6}\n\
	ldm r0!, {r3, r4}\n\
	stm r1!, {r3, r4}\n\
	adds r2, #0x14\n\
	subs r5, #1\n\
	cmp r5, #0\n\
	bge _0807FB9E\n\
	ldr r4, _0807FC20 @ =0x03000B8D\n\
	movs r1, #0\n\
	strb r1, [r4]\n\
	ldr r0, _0807FC24 @ =gIsLoadingFile\n\
	strb r1, [r0]\n\
	ldr r0, _0807FC28 @ =0x03000B8E\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0807FBC8\n\
	bl ReadAllFilesToEwram\n\
_0807FBC8:\n\
	movs r5, #0\n\
	adds r7, r4, #0\n\
	movs r6, #0x10\n\
	ldr r0, _0807FC1C @ =0x03000B94\n\
	str r0, [sp, #0x18]\n\
	ldr r1, _0807FC2C @ =0x0858225C\n\
	mov sl, r1\n\
	ldr r3, _0807FC30 @ =0x0000FFFF\n\
	mov sb, r3\n\
	movs r4, #0x90\n\
	lsls r4, r4, #5\n\
	mov r8, r4\n\
_0807FBE0:\n\
	strb r5, [r7]\n\
	bl unk_7fd10\n\
	ldrb r0, [r7]\n\
	lsls r2, r0, #2\n\
	adds r0, r2, r0\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807FC1C @ =0x03000B94\n\
	adds r0, r0, r1\n\
	ldrb r4, [r0, #1]\n\
	cmp r4, #0\n\
	bne _0807FC38\n\
	mov r3, sl\n\
	adds r0, r2, r3\n\
	ldr r1, [r0]\n\
	ldr r4, _0807FC34 @ =0x08582268\n\
	adds r0, r2, r4\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	bl DmaTransfer\n\
	bl WriteMostRecentFileBackupToSram\n\
	movs r0, #1\n\
	ldr r1, [sp, #0x18]\n\
	strb r0, [r1]\n\
	b _0807FCE6\n\
	.align 2, 0\n\
_0807FC1C: .4byte 0x03000B94\n\
_0807FC20: .4byte 0x03000B8D\n\
_0807FC24: .4byte gIsLoadingFile\n\
_0807FC28: .4byte 0x03000B8E\n\
_0807FC2C: .4byte 0x0858225C\n\
_0807FC30: .4byte 0x0000FFFF\n\
_0807FC34: .4byte 0x08582268\n\
_0807FC38:\n\
	cmp r4, #1\n\
	bne _0807FC60\n\
	ldr r3, _0807FC5C @ =0x08582268\n\
	adds r0, r2, r3\n\
	ldr r1, [r0]\n\
	mov r3, sl\n\
	adds r0, r2, r3\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	bl DmaTransfer\n\
	ldr r0, [sp, #0x18]\n\
	strb r4, [r0]\n\
	b _0807FCE6\n\
	.align 2, 0\n\
_0807FC5C: .4byte 0x08582268\n\
_0807FC60:\n\
	cmp r4, #2\n\
	bne _0807FC94\n\
	mov r1, sl\n\
	adds r0, r2, r1\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	mov r1, sb\n\
	mov r3, r8\n\
	bl BitFill\n\
	ldrb r0, [r7]\n\
	lsls r0, r0, #2\n\
	ldr r3, _0807FC90 @ =0x08582268\n\
	adds r0, r0, r3\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	mov r1, sb\n\
	mov r3, r8\n\
	bl BitFill\n\
	b _0807FCE6\n\
	.align 2, 0\n\
_0807FC90: .4byte 0x08582268\n\
_0807FC94:\n\
	cmp r4, #3\n\
	bne _0807FCE4\n\
	mov r4, sl\n\
	adds r0, r2, r4\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	mov r1, sb\n\
	mov r3, r8\n\
	bl BitFill\n\
	bl WriteMostRecentFileToSram\n\
	ldrb r0, [r7]\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807FCDC @ =0x08582268\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	mov r1, sb\n\
	mov r3, r8\n\
	bl BitFill\n\
	bl WriteMostRecentFileBackupToSram\n\
	ldrb r1, [r7]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r3, _0807FCE0 @ =0x03000B94\n\
	adds r0, r0, r3\n\
	movs r1, #0\n\
	strb r1, [r0, #1]\n\
	b _0807FCE6\n\
	.align 2, 0\n\
_0807FCDC: .4byte 0x08582268\n\
_0807FCE0: .4byte 0x03000B94\n\
_0807FCE4:\n\
	b _0807FCE4\n\
_0807FCE6:\n\
	ldr r4, [sp, #0x18]\n\
	adds r4, #0x14\n\
	str r4, [sp, #0x18]\n\
	adds r5, #1\n\
	cmp r5, #2\n\
	bgt _0807FCF4\n\
	b _0807FBE0\n\
_0807FCF4:\n\
	movs r1, #0\n\
	ldr r0, _0807FD0C @ =0x03000B8D\n\
	strb r1, [r0]\n\
	add sp, #0x1c\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807FD0C: .4byte 0x03000B8D\n\
    .syntax divided\n");
}

// 0x0807FD10
NAKED_FUNCTION
void unk_7fd10(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r0, #0\n\
	bl unk_7fdb0\n\
	adds r4, r0, #0\n\
	movs r0, #1\n\
	bl unk_7fdb0\n\
	adds r2, r0, #0\n\
	cmp r4, #0\n\
	bne _0807FD40\n\
	ldr r2, _0807FD38 @ =0x03000B94\n\
	ldr r0, _0807FD3C @ =0x03000B8D\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	strb r4, [r0, #1]\n\
	b _0807FDAA\n\
	.align 2, 0\n\
_0807FD38: .4byte 0x03000B94\n\
_0807FD3C: .4byte 0x03000B8D\n\
_0807FD40:\n\
	cmp r4, #1\n\
	bne _0807FD6C\n\
	ldr r5, _0807FD64 @ =0x03000B94\n\
	ldr r3, _0807FD68 @ =0x03000B8D\n\
	ldrb r1, [r3]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	strb r4, [r0, #1]\n\
	cmp r2, #0\n\
	beq _0807FDAA\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	b _0807FDA6\n\
	.align 2, 0\n\
_0807FD64: .4byte 0x03000B94\n\
_0807FD68: .4byte 0x03000B8D\n\
_0807FD6C:\n\
	ldr r4, _0807FD90 @ =0x03000B94\n\
	ldr r3, _0807FD94 @ =0x03000B8D\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	movs r0, #3\n\
	strb r0, [r1, #1]\n\
	cmp r2, #0\n\
	bne _0807FD98\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	movs r0, #1\n\
	b _0807FDA8\n\
	.align 2, 0\n\
_0807FD90: .4byte 0x03000B94\n\
_0807FD94: .4byte 0x03000B8D\n\
_0807FD98:\n\
	cmp r2, #1\n\
	bne _0807FDAA\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
_0807FDA6:\n\
	movs r0, #2\n\
_0807FDA8:\n\
	strb r0, [r1, #1]\n\
_0807FDAA:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0807FDB0
NAKED_FUNCTION
u32 unk_7fdb0(u8 useBackup)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	movs r5, #0\n\
	movs r7, #0\n\
	cmp r0, #0\n\
	bne _0807FDC8\n\
	ldr r1, _0807FDC4 @ =0x0858225C\n\
	b _0807FDCA\n\
	.align 2, 0\n\
_0807FDC4: .4byte 0x0858225C\n\
_0807FDC8:\n\
	ldr r1, _0807FE50 @ =0x08582268\n\
_0807FDCA:\n\
	ldr r0, _0807FE54 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r4, [r0]\n\
	adds r3, r4, #0\n\
	movs r1, #0\n\
	ldr r6, [r4, #0x10]\n\
	movs r2, #0x8f\n\
_0807FDDC:\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bge _0807FDDC\n\
	cmp r6, r1\n\
	bne _0807FE0E\n\
	ldr r0, [r4, #0x14]\n\
	mvns r0, r0\n\
	cmp r6, r0\n\
	beq _0807FE12\n\
_0807FE0E:\n\
	movs r0, #1\n\
	orrs r5, r0\n\
_0807FE12:\n\
	movs r2, #0\n\
	ldr r6, _0807FE58 @ =0x08582200\n\
	movs r3, #1\n\
_0807FE18:\n\
	adds r0, r2, r6\n\
	adds r1, r4, r2\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _0807FE26\n\
	orrs r7, r3\n\
_0807FE26:\n\
	adds r2, #1\n\
	cmp r2, #0xf\n\
	ble _0807FE18\n\
	adds r0, r7, #0\n\
	adds r5, r5, r0\n\
	cmp r5, #1\n\
	ble _0807FE46\n\
	ldr r1, _0807FE5C @ =0x0000FFFF\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	adds r2, r4, #0\n\
	bl BitFill\n\
_0807FE46:\n\
	adds r0, r5, #0\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0807FE50: .4byte 0x08582268\n\
_0807FE54: .4byte 0x03000B8D\n\
_0807FE58: .4byte 0x08582200\n\
_0807FE5C: .4byte 0x0000FFFF\n\
    .syntax divided\n");
}

// 0x0807FE60
NAKED_FUNCTION
void SramLoad_CurrentSave(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r0, _0807FE8C @ =gIsLoadingFile\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0807FE88\n\
	bl SramRead_FromEwram\n\
	bl SramRead_WorldData\n\
	ldr r0, _0807FE90 @ =gSamusData\n\
	movs r2, #0\n\
	movs r1, #0x3d\n\
	strb r1, [r0, #1]\n\
	adds r1, r0, #0\n\
	adds r1, #0x21\n\
	strb r2, [r1]\n\
	adds r0, #0x22\n\
	strb r2, [r0]\n\
_0807FE88:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807FE8C: .4byte gIsLoadingFile\n\
_0807FE90: .4byte gSamusData\n\
    .syntax divided\n");
}

/**
 * @brief 7fe94 | 10 | Loads the current save file (unused)
 * 
 */
void SramLoad_CurrentSave_Unused(void)
{
    SramRead_FromEwram();
    SramRead_WorldData();
}

// 0x0807FEA4
NAKED_FUNCTION
void SramWrite_WorldData(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #4\n\
	ldr r1, _0807FF5C @ =0x08582274\n\
	ldr r0, _0807FF60 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	ldr r1, _0807FF64 @ =0x02037C00\n\
	movs r4, #0xe0\n\
	lsls r4, r4, #2\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	mov r2, r8\n\
	adds r3, r4, #0\n\
	bl DmaTransfer\n\
	adds r7, r4, #0\n\
	movs r5, #0\n\
_0807FED2:\n\
	ldr r0, _0807FF68 @ =0x03000033\n\
	adds r0, r5, r0\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r4, r0, r1\n\
	movs r0, #3\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _0807FEEA\n\
	ldr r0, _0807FF6C @ =0x0000FFFC\n\
	ands r4, r0\n\
	adds r4, #4\n\
_0807FEEA:\n\
	cmp r4, #0\n\
	beq _0807FF0E\n\
	adds r1, r5, #0\n\
	cmp r5, #0\n\
	beq _0807FEF6\n\
	adds r1, r5, #1\n\
_0807FEF6:\n\
	lsls r1, r1, #9\n\
	ldr r0, _0807FF70 @ =0x02036000\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	adds r2, r0, r7\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	adds r3, r4, #0\n\
	bl DmaTransfer\n\
	adds r7, r7, r4\n\
_0807FF0E:\n\
	adds r5, #1\n\
	cmp r5, #7\n\
	ble _0807FED2\n\
	movs r7, #0xc8\n\
	lsls r7, r7, #4\n\
	movs r5, #0\n\
_0807FF1A:\n\
	ldr r0, _0807FF74 @ =0x0300003B\n\
	adds r0, r5, r0\n\
	ldrb r0, [r0]\n\
	lsls r4, r0, #2\n\
	adds r6, r5, #1\n\
	cmp r4, #0\n\
	beq _0807FF48\n\
	adds r1, r5, #0\n\
	cmp r1, #0\n\
	beq _0807FF30\n\
	adds r1, r6, #0\n\
_0807FF30:\n\
	lsls r1, r1, #8\n\
	ldr r0, _0807FF78 @ =0x02037200\n\
	adds r1, r1, r0\n\
	mov r0, r8\n\
	adds r2, r0, r7\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	adds r3, r4, #0\n\
	bl DmaTransfer\n\
	adds r7, r7, r4\n\
_0807FF48:\n\
	adds r5, r6, #0\n\
	cmp r5, #7\n\
	ble _0807FF1A\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807FF5C: .4byte 0x08582274\n\
_0807FF60: .4byte 0x03000B8D\n\
_0807FF64: .4byte 0x02037C00\n\
_0807FF68: .4byte 0x03000033\n\
_0807FF6C: .4byte 0x0000FFFC\n\
_0807FF70: .4byte 0x02036000\n\
_0807FF74: .4byte 0x0300003B\n\
_0807FF78: .4byte 0x02037200\n\
    .syntax divided\n");
}

// 0x0807FF7C
NAKED_FUNCTION
void SramRead_WorldData(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #4\n\
	ldr r1, _08080044 @ =0x08582274\n\
	ldr r0, _08080048 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov r8, r0\n\
	ldr r2, _0808004C @ =0x02037C00\n\
	movs r5, #0xe0\n\
	lsls r5, r5, #2\n\
	movs r4, #0x10\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	mov r1, r8\n\
	adds r3, r5, #0\n\
	bl DmaTransfer\n\
	ldr r1, _08080050 @ =0x0000FFFF\n\
	ldr r2, _08080054 @ =0x02036000\n\
	movs r3, #0xd8\n\
	lsls r3, r3, #5\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	bl BitFill\n\
	adds r7, r5, #0\n\
	movs r5, #0\n\
_0807FFBA:\n\
	ldr r0, _08080058 @ =0x03000033\n\
	adds r0, r5, r0\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r4, r0, r1\n\
	movs r0, #3\n\
	ands r0, r4\n\
	cmp r0, #0\n\
	beq _0807FFD2\n\
	ldr r0, _0808005C @ =0x0000FFFC\n\
	ands r4, r0\n\
	adds r4, #4\n\
_0807FFD2:\n\
	cmp r4, #0\n\
	beq _0807FFF6\n\
	adds r2, r5, #0\n\
	cmp r5, #0\n\
	beq _0807FFDE\n\
	adds r2, r5, #1\n\
_0807FFDE:\n\
	mov r0, r8\n\
	adds r1, r0, r7\n\
	lsls r2, r2, #9\n\
	ldr r0, _08080054 @ =0x02036000\n\
	adds r2, r2, r0\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	adds r3, r4, #0\n\
	bl DmaTransfer\n\
	adds r7, r7, r4\n\
_0807FFF6:\n\
	adds r5, #1\n\
	cmp r5, #7\n\
	ble _0807FFBA\n\
	movs r7, #0xc8\n\
	lsls r7, r7, #4\n\
	movs r5, #0\n\
_08080002:\n\
	ldr r0, _08080060 @ =0x0300003B\n\
	adds r0, r5, r0\n\
	ldrb r0, [r0]\n\
	lsls r4, r0, #2\n\
	adds r6, r5, #1\n\
	cmp r4, #0\n\
	beq _08080030\n\
	adds r2, r5, #0\n\
	cmp r2, #0\n\
	beq _08080018\n\
	adds r2, r6, #0\n\
_08080018:\n\
	mov r0, r8\n\
	adds r1, r0, r7\n\
	lsls r2, r2, #8\n\
	ldr r0, _08080064 @ =0x02037200\n\
	adds r2, r2, r0\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	adds r3, r4, #0\n\
	bl DmaTransfer\n\
	adds r7, r7, r4\n\
_08080030:\n\
	adds r5, r6, #0\n\
	cmp r5, #7\n\
	ble _08080002\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080044: .4byte 0x08582274\n\
_08080048: .4byte 0x03000B8D\n\
_0808004C: .4byte 0x02037C00\n\
_08080050: .4byte 0x0000FFFF\n\
_08080054: .4byte 0x02036000\n\
_08080058: .4byte 0x03000033\n\
_0808005C: .4byte 0x0000FFFC\n\
_08080060: .4byte 0x0300003B\n\
_08080064: .4byte 0x02037200\n\
    .syntax divided\n");
}

// 0x08080068
NAKED_FUNCTION
void SramWrite_MostRecentSaveFile(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r5, _080800E4 @ =0x0203F000\n\
	adds r3, r5, #0\n\
	movs r1, #0\n\
	movs r0, #0x1e\n\
	strb r0, [r5]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
	strh r1, [r5, #2]\n\
	ldr r0, _080800E8 @ =0x0000FFFF\n\
	strh r0, [r5, #4]\n\
	ldr r0, _080800EC @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	strb r0, [r5, #0x16]\n\
	ldr r2, _080800F0 @ =0x08582288\n\
	adds r1, r5, #6\n\
	movs r4, #0xf\n\
_0808008C:\n\
	ldrb r0, [r2]\n\
	strb r0, [r1]\n\
	ldrb r0, [r2, #0x10]\n\
	strb r0, [r1, #0x11]\n\
	adds r2, #1\n\
	adds r1, #1\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _0808008C\n\
	movs r1, #0\n\
	movs r4, #7\n\
_080800A2:\n\
	ldrh r0, [r3]\n\
	adds r0, r1, r0\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r3]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r2, [r3]\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r3]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r3, #2\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _080800A2\n\
	strh r1, [r5, #2]\n\
	ldr r2, _080800E8 @ =0x0000FFFF\n\
	adds r0, r2, #0\n\
	subs r0, r0, r1\n\
	strh r0, [r5, #4]\n\
	bl unk_dd4\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080800E4: .4byte 0x0203F000\n\
_080800E8: .4byte 0x0000FFFF\n\
_080800EC: .4byte 0x03000B8D\n\
_080800F0: .4byte 0x08582288\n\
    .syntax divided\n");
}

// 0x080800F4
NAKED_FUNCTION
void SramRead_MostRecentSaveFile(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	ldr r0, _08080194 @ =0x0203F000\n\
	mov ip, r0\n\
	ldrb r0, [r0]\n\
	movs r1, #0x1e\n\
	eors r0, r1\n\
	rsbs r1, r0, #0\n\
	orrs r1, r0\n\
	lsrs r4, r1, #0x1f\n\
	ldr r6, _08080198 @ =0x03000B8D\n\
	cmp r4, #0\n\
	bne _080801A0\n\
	mov r1, ip\n\
	movs r3, #0\n\
	ldrh r5, [r1, #2]\n\
	movs r2, #7\n\
_08080116:\n\
	ldrh r0, [r1]\n\
	adds r0, r3, r0\n\
	lsls r0, r0, #0x10\n\
	adds r1, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r3, [r1]\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #0x10\n\
	adds r1, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r3, [r1]\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #0x10\n\
	adds r1, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r3, [r1]\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	adds r1, #2\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bge _08080116\n\
	cmp r5, r3\n\
	beq _0808014A\n\
	movs r4, #2\n\
_0808014A:\n\
	cmp r4, #0\n\
	bne _080801A0\n\
	movs r2, #0\n\
	ldr r0, _0808019C @ =0x08582288\n\
	mov r3, ip\n\
	ldrb r1, [r3, #6]\n\
	adds r3, r0, #0\n\
	ldrb r0, [r3]\n\
	cmp r1, r0\n\
	bne _080801A0\n\
_0808015E:\n\
	mov r0, ip\n\
	adds r0, #0x17\n\
	adds r0, r0, r2\n\
	adds r1, r3, #0\n\
	adds r1, #0x10\n\
	adds r1, r2, r1\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bne _080801A0\n\
	adds r2, #1\n\
	cmp r2, #0xf\n\
	bgt _0808018A\n\
	mov r0, ip\n\
	adds r0, #6\n\
	adds r0, r0, r2\n\
	adds r1, r2, r3\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _0808015E\n\
	movs r4, #3\n\
_0808018A:\n\
	cmp r4, #0\n\
	bne _080801A0\n\
	mov r1, ip\n\
	ldrb r0, [r1, #0x16]\n\
	b _080801BA\n\
	.align 2, 0\n\
_08080194: .4byte 0x0203F000\n\
_08080198: .4byte 0x03000B8D\n\
_0808019C: .4byte 0x08582288\n\
_080801A0:\n\
	mov r1, sp\n\
	ldr r2, _080801C4 @ =0x0000FFFF\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r1, _080801C8 @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r1]\n\
	ldr r0, _080801CC @ =0x0203F000\n\
	str r0, [r1, #4]\n\
	ldr r0, _080801D0 @ =0x81000020\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #0\n\
_080801BA:\n\
	strb r0, [r6]\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080801C4: .4byte 0x0000FFFF\n\
_080801C8: .4byte 0x040000D4\n\
_080801CC: .4byte 0x0203F000\n\
_080801D0: .4byte 0x81000020\n\
    .syntax divided\n");
}

// 0x080801D4
NAKED_FUNCTION
void SramWrite_Language(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r5, _08080254 @ =0x0203F040\n\
	adds r3, r5, #0\n\
	movs r1, #0\n\
	movs r0, #0x1f\n\
	strb r0, [r5]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
	strh r1, [r5, #2]\n\
	ldr r0, _08080258 @ =0x0000FFFF\n\
	strh r0, [r5, #4]\n\
	ldr r0, _0808025C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	strb r0, [r5, #0x16]\n\
	ldr r2, _08080260 @ =0x085822A8\n\
	adds r1, r5, #6\n\
	movs r4, #0xf\n\
_080801F8:\n\
	ldrb r0, [r2]\n\
	strb r0, [r1]\n\
	ldrb r0, [r2, #0x10]\n\
	strb r0, [r1, #0x11]\n\
	adds r2, #1\n\
	adds r1, #1\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _080801F8\n\
	movs r1, #0\n\
	movs r4, #7\n\
_0808020E:\n\
	ldrh r0, [r3]\n\
	adds r0, r1, r0\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r3]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r2, [r3]\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r3]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r3, #2\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _0808020E\n\
	strh r1, [r5, #2]\n\
	ldr r2, _08080258 @ =0x0000FFFF\n\
	adds r0, r2, #0\n\
	subs r0, r0, r1\n\
	strh r0, [r5, #4]\n\
	movs r0, #0\n\
	bl unk_dec\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080254: .4byte 0x0203F040\n\
_08080258: .4byte 0x0000FFFF\n\
_0808025C: .4byte 0x03000011\n\
_08080260: .4byte 0x085822A8\n\
    .syntax divided\n");
}

// 0x08080264
NAKED_FUNCTION
void SramRead_Language(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	movs r0, #0\n\
	mov r8, r0\n\
	ldr r1, _080802E8 @ =0x08582280\n\
	mov sb, r1\n\
	ldr r6, _080802EC @ =0x040000D4\n\
	ldr r2, _080802F0 @ =0x81000020\n\
	mov sl, r2\n\
_0808027E:\n\
	mov r1, r8\n\
	lsls r0, r1, #2\n\
	add r0, sb\n\
	ldr r5, [r0]\n\
	adds r2, r5, #0\n\
	ldrb r1, [r5]\n\
	movs r0, #0x1f\n\
	eors r1, r0\n\
	rsbs r0, r1, #0\n\
	orrs r0, r1\n\
	lsrs r4, r0, #0x1f\n\
	cmp r4, #0\n\
	bne _08080326\n\
	movs r1, #0\n\
	ldrh r7, [r5, #2]\n\
	movs r3, #7\n\
_0808029E:\n\
	ldrh r0, [r2]\n\
	adds r0, r1, r0\n\
	lsls r0, r0, #0x10\n\
	adds r2, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r2]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	adds r2, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r2]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	adds r2, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r2]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r2, #2\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _0808029E\n\
	cmp r7, r1\n\
	beq _080802D2\n\
	movs r4, #2\n\
_080802D2:\n\
	cmp r4, #0\n\
	bne _08080326\n\
	movs r3, #0\n\
	ldr r0, _080802F4 @ =0x085822A8\n\
	ldrb r1, [r5, #6]\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2]\n\
	cmp r1, r0\n\
	beq _080802FC\n\
	b _08080324\n\
	.align 2, 0\n\
_080802E8: .4byte 0x08582280\n\
_080802EC: .4byte 0x040000D4\n\
_080802F0: .4byte 0x81000020\n\
_080802F4: .4byte 0x085822A8\n\
_080802F8:\n\
	movs r4, #4\n\
	b _08080326\n\
_080802FC:\n\
	adds r0, r5, #0\n\
	adds r0, #0x17\n\
	adds r0, r0, r3\n\
	adds r1, r2, #0\n\
	adds r1, #0x10\n\
	adds r1, r3, r1\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bne _080802F8\n\
	adds r3, #1\n\
	cmp r3, #0xf\n\
	bgt _08080326\n\
	adds r0, r5, #6\n\
	adds r0, r0, r3\n\
	adds r1, r3, r2\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _080802FC\n\
_08080324:\n\
	movs r4, #3\n\
_08080326:\n\
	mov r1, r8\n\
	cmp r1, #0\n\
	bne _0808034C\n\
	cmp r4, #0\n\
	bne _08080384\n\
	mov r2, sb\n\
	ldr r0, [r2]\n\
	str r0, [r6]\n\
	ldr r0, [r2, #4]\n\
	str r0, [r6, #4]\n\
	ldr r0, _08080348 @ =0x80000020\n\
	str r0, [r6, #8]\n\
	ldr r0, [r6, #8]\n\
	movs r0, #1\n\
	bl unk_dec\n\
	b _08080390\n\
	.align 2, 0\n\
_08080348: .4byte 0x80000020\n\
_0808034C:\n\
	cmp r4, #0\n\
	beq _080803A0\n\
	mov r0, sp\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	str r0, [r6]\n\
	mov r2, sb\n\
	ldr r0, [r2]\n\
	str r0, [r6, #4]\n\
	mov r0, sl\n\
	str r0, [r6, #8]\n\
	ldr r0, [r6, #8]\n\
	movs r0, #0\n\
	bl unk_dec\n\
	mov r0, sp\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	str r0, [r6]\n\
	mov r2, sb\n\
	ldr r0, [r2, #4]\n\
	str r0, [r6, #4]\n\
	mov r0, sl\n\
	str r0, [r6, #8]\n\
	ldr r0, [r6, #8]\n\
	movs r0, #1\n\
	bl unk_dec\n\
_08080384:\n\
	movs r1, #1\n\
	add r8, r1\n\
	mov r2, r8\n\
	cmp r2, #1\n\
	bgt _08080390\n\
	b _0808027E\n\
_08080390:\n\
	cmp r4, #0\n\
	bne _080803C8\n\
	ldr r1, _0808039C @ =0x03000011\n\
	ldrb r0, [r5, #0x16]\n\
	b _080803CC\n\
	.align 2, 0\n\
_0808039C: .4byte 0x03000011\n\
_080803A0:\n\
	ldr r1, _080803BC @ =0x040000D4\n\
	ldr r2, _080803C0 @ =0x08582280\n\
	ldr r0, [r2, #4]\n\
	str r0, [r1]\n\
	ldr r0, [r2]\n\
	str r0, [r1, #4]\n\
	ldr r0, _080803C4 @ =0x80000020\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #0\n\
	bl unk_dec\n\
	b _08080390\n\
	.align 2, 0\n\
_080803BC: .4byte 0x040000D4\n\
_080803C0: .4byte 0x08582280\n\
_080803C4: .4byte 0x80000020\n\
_080803C8:\n\
	ldr r1, _080803E0 @ =0x03000011\n\
	movs r0, #0\n\
_080803CC:\n\
	strb r0, [r1]\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080803E0: .4byte 0x03000011\n\
    .syntax divided\n");
}

// 0x080803E4
NAKED_FUNCTION
void Sram_InitSaveFile(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	ldr r2, _080804C8 @ =0x02037C00\n\
	movs r3, #0xe0\n\
	lsls r3, r3, #2\n\
	movs r4, #0x10\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	movs r1, #0\n\
	bl BitFill\n\
	ldr r5, _080804CC @ =0x0000FFFF\n\
	ldr r2, _080804D0 @ =0x02036000\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	adds r1, r5, #0\n\
	bl BitFill\n\
	ldr r2, _080804D4 @ =0x02037200\n\
	movs r3, #0x90\n\
	lsls r3, r3, #4\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	adds r1, r5, #0\n\
	bl BitFill\n\
	movs r1, #0\n\
	ldr r4, _080804D8 @ =0x03000033\n\
	movs r2, #0\n\
	ldr r3, _080804DC @ =0x0300003B\n\
_08080424:\n\
	adds r0, r1, r4\n\
	strb r2, [r0]\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	adds r1, #1\n\
	cmp r1, #7\n\
	ble _08080424\n\
	ldr r1, _080804E0 @ =gInGameTimer\n\
	ldr r0, _080804E4 @ =0x085822D4\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r1, _080804E8 @ =gDisableDrawingSamusAndScrollingFlag\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	movs r0, #0\n\
	bl EventSet\n\
	ldr r0, _080804EC @ =gPreviousNavigationConversation\n\
	movs r3, #0xff\n\
	strb r3, [r0]\n\
	ldr r0, _080804F0 @ =gPreviousSoundEvent\n\
	movs r1, #0xff\n\
	strh r1, [r0]\n\
	ldr r2, _080804F4 @ =gEquipment\n\
	ldrb r0, [r2, #0xd]\n\
	orrs r0, r3\n\
	strb r0, [r2, #0xd]\n\
	ldr r0, _080804F8 @ =gSecurityHatchLevel\n\
	strb r1, [r0]\n\
	ldr r0, _080804FC @ =gSecurityHatchLevelBackup\n\
	strb r1, [r0]\n\
	movs r1, #0\n\
	strb r1, [r2, #0xe]\n\
	ldr r0, _08080500 @ =gAbilityCount\n\
	strb r1, [r0]\n\
	ldr r0, _08080504 @ =gCurrentArea\n\
	strb r1, [r0]\n\
	ldr r0, _08080508 @ =gPreviousArea\n\
	strb r1, [r0]\n\
	ldr r0, _0808050C @ =gCurrentRoom\n\
	strb r1, [r0]\n\
	ldr r0, _08080510 @ =gLastDoorUsed\n\
	strb r1, [r0]\n\
	ldr r0, _08080514 @ =0x0300004C\n\
	strb r1, [r0]\n\
	ldr r0, _08080518 @ =0x0300004D\n\
	strb r1, [r0]\n\
	ldr r0, _0808051C @ =0x0879B894\n\
	ldr r2, [r0]\n\
	ldrb r0, [r2, #2]\n\
	movs r6, #7\n\
	ldrsb r6, [r2, r6]\n\
	ldr r3, _08080520 @ =gPreviousXPosition\n\
	ldr r4, _08080524 @ =gSamusData\n\
	lsls r1, r0, #6\n\
	adds r0, r6, #0\n\
	adds r0, #8\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	movs r5, #0\n\
	strh r1, [r4, #0x16]\n\
	strh r1, [r3]\n\
	ldrb r0, [r2, #5]\n\
	adds r0, #1\n\
	movs r6, #8\n\
	ldrsb r6, [r2, r6]\n\
	ldr r2, _08080528 @ =gPreviousYPosition\n\
	lsls r0, r0, #6\n\
	lsls r1, r6, #2\n\
	adds r0, r0, r1\n\
	subs r0, #1\n\
	strh r0, [r4, #0x18]\n\
	strh r0, [r2]\n\
	bl MinimapLoadInitial\n\
	ldr r0, _0808052C @ =gIsLoadingFile\n\
	strb r5, [r0]\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080804C8: .4byte 0x02037C00\n\
_080804CC: .4byte 0x0000FFFF\n\
_080804D0: .4byte 0x02036000\n\
_080804D4: .4byte 0x02037200\n\
_080804D8: .4byte 0x03000033\n\
_080804DC: .4byte 0x0300003B\n\
_080804E0: .4byte gInGameTimer\n\
_080804E4: .4byte 0x085822D4\n\
_080804E8: .4byte gDisableDrawingSamusAndScrollingFlag\n\
_080804EC: .4byte gPreviousNavigationConversation\n\
_080804F0: .4byte gPreviousSoundEvent\n\
_080804F4: .4byte gEquipment\n\
_080804F8: .4byte gSecurityHatchLevel\n\
_080804FC: .4byte gSecurityHatchLevelBackup\n\
_08080500: .4byte gAbilityCount\n\
_08080504: .4byte gCurrentArea\n\
_08080508: .4byte gPreviousArea\n\
_0808050C: .4byte gCurrentRoom\n\
_08080510: .4byte gLastDoorUsed\n\
_08080514: .4byte 0x0300004C\n\
_08080518: .4byte 0x0300004D\n\
_0808051C: .4byte 0x0879B894\n\
_08080520: .4byte gPreviousXPosition\n\
_08080524: .4byte gSamusData\n\
_08080528: .4byte gPreviousYPosition\n\
_0808052C: .4byte gIsLoadingFile\n\
    .syntax divided\n");
}

// 0x08080530
NAKED_FUNCTION
void Sram_ResetForDemo(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #4\n\
	ldr r1, _080805F0 @ =gBootDebugOptions\n\
	ldr r0, _080805F4 @ =0x085822E4\n\
	ldm r0!, {r2, r3, r4}\n\
	stm r1!, {r2, r3, r4}\n\
	ldr r2, _080805F8 @ =gButtonAssignments\n\
	ldr r0, _080805FC @ =0x085822C8\n\
	ldr r1, [r0, #4]\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	ldr r5, _08080600 @ =0x0000FFFF\n\
	ldr r2, _08080604 @ =0x02037C00\n\
	movs r3, #0xe0\n\
	lsls r3, r3, #2\n\
	movs r4, #0x10\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	adds r1, r5, #0\n\
	bl BitFill\n\
	ldr r2, _08080608 @ =0x02036000\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	adds r1, r5, #0\n\
	bl BitFill\n\
	ldr r2, _0808060C @ =0x02037200\n\
	movs r3, #0x90\n\
	lsls r3, r3, #4\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	adds r1, r5, #0\n\
	bl BitFill\n\
	movs r1, #0\n\
	ldr r4, _08080610 @ =0x03000033\n\
	movs r2, #0\n\
	ldr r3, _08080614 @ =0x0300003B\n\
_08080584:\n\
	adds r0, r1, r4\n\
	strb r2, [r0]\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	adds r1, #1\n\
	cmp r1, #7\n\
	ble _08080584\n\
	ldr r1, _08080618 @ =gInGameTimer\n\
	ldr r0, _0808061C @ =0x085822D4\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r0, _08080620 @ =gDisableDrawingSamusAndScrollingFlag\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldr r2, _08080624 @ =gPreviousNavigationConversation\n\
	movs r0, #0xff\n\
	strb r0, [r2]\n\
	ldr r2, _08080628 @ =gPreviousSoundEvent\n\
	movs r0, #0xff\n\
	strh r0, [r2]\n\
	ldr r0, _0808062C @ =0x0300004C\n\
	strb r1, [r0]\n\
	ldr r0, _08080630 @ =0x0300004D\n\
	strb r1, [r0]\n\
	ldr r0, _08080634 @ =gIsLoadingFile\n\
	strb r1, [r0]\n\
	ldr r0, _08080638 @ =gUnk_3000be3\n\
	strb r1, [r0]\n\
	ldr r0, _0808063C @ =0x03000018\n\
	strb r1, [r0]\n\
	ldr r0, _08080640 @ =gDisableSoftReset\n\
	strb r1, [r0]\n\
	ldr r2, _08080644 @ =gMaxInGameTimeFlag\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	ldr r0, _08080648 @ =0x03000022\n\
	strb r1, [r0]\n\
	ldr r0, _0808064C @ =gSkipDoorTransition\n\
	strb r1, [r0]\n\
	ldr r0, _08080650 @ =gPauseScreenFlag\n\
	strb r1, [r0]\n\
	ldr r0, _08080654 @ =0x03000B85\n\
	strb r1, [r0]\n\
	ldr r0, _08080658 @ =0x0300002B\n\
	strb r1, [r0]\n\
	ldr r0, _0808065C @ =gSamusDoorPositionOffset\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	ldr r0, _08080660 @ =gDebugFlag\n\
	strb r1, [r0]\n\
	add sp, #4\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080805F0: .4byte gBootDebugOptions\n\
_080805F4: .4byte 0x085822E4\n\
_080805F8: .4byte gButtonAssignments\n\
_080805FC: .4byte 0x085822C8\n\
_08080600: .4byte 0x0000FFFF\n\
_08080604: .4byte 0x02037C00\n\
_08080608: .4byte 0x02036000\n\
_0808060C: .4byte 0x02037200\n\
_08080610: .4byte 0x03000033\n\
_08080614: .4byte 0x0300003B\n\
_08080618: .4byte gInGameTimer\n\
_0808061C: .4byte 0x085822D4\n\
_08080620: .4byte gDisableDrawingSamusAndScrollingFlag\n\
_08080624: .4byte gPreviousNavigationConversation\n\
_08080628: .4byte gPreviousSoundEvent\n\
_0808062C: .4byte 0x0300004C\n\
_08080630: .4byte 0x0300004D\n\
_08080634: .4byte gIsLoadingFile\n\
_08080638: .4byte gUnk_3000be3\n\
_0808063C: .4byte 0x03000018\n\
_08080640: .4byte gDisableSoftReset\n\
_08080644: .4byte gMaxInGameTimeFlag\n\
_08080648: .4byte 0x03000022\n\
_0808064C: .4byte gSkipDoorTransition\n\
_08080650: .4byte gPauseScreenFlag\n\
_08080654: .4byte 0x03000B85\n\
_08080658: .4byte 0x0300002B\n\
_0808065C: .4byte gSamusDoorPositionOffset\n\
_08080660: .4byte gDebugFlag\n\
    .syntax divided\n");
}

// 0x08080664
NAKED_FUNCTION
void Sram_CheckLoadSaveFile(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r2, _080806BC @ =gButtonAssignments\n\
	ldr r0, _080806C0 @ =0x085822C8\n\
	ldr r1, [r0, #4]\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	str r1, [r2, #4]\n\
	ldr r1, _080806C4 @ =gBootDebugOptions\n\
	ldr r0, _080806C8 @ =0x085822E4\n\
	ldm r0!, {r2, r3, r4}\n\
	stm r1!, {r2, r3, r4}\n\
	ldr r2, _080806CC @ =gIsLoadingFile\n\
	ldr r6, _080806D0 @ =0x03000B94\n\
	ldr r4, _080806D4 @ =0x03000B8D\n\
	ldrb r1, [r4]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r6\n\
	ldrb r0, [r0]\n\
	strb r0, [r2]\n\
	lsls r0, r0, #0x18\n\
	asrs r5, r0, #0x18\n\
	cmp r5, #0\n\
	bne _080806DC\n\
	bl Sram_InitSaveFile\n\
	ldr r2, _080806D8 @ =0x03000014\n\
	ldrb r1, [r4]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r6\n\
	ldrb r0, [r0, #0x10]\n\
	strb r0, [r2]\n\
	ldrb r1, [r4]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r6\n\
	ldrb r0, [r0, #0x11]\n\
	strb r0, [r2, #1]\n\
	strb r5, [r2, #2]\n\
	b _080806E0\n\
	.align 2, 0\n\
_080806BC: .4byte gButtonAssignments\n\
_080806C0: .4byte 0x085822C8\n\
_080806C4: .4byte gBootDebugOptions\n\
_080806C8: .4byte 0x085822E4\n\
_080806CC: .4byte gIsLoadingFile\n\
_080806D0: .4byte 0x03000B94\n\
_080806D4: .4byte 0x03000B8D\n\
_080806D8: .4byte 0x03000014\n\
_080806DC:\n\
	bl SramLoad_CurrentSave\n\
_080806E0:\n\
	ldr r0, _08080718 @ =gUnk_3000be3\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldr r0, _0808071C @ =0x03000018\n\
	strb r1, [r0]\n\
	ldr r0, _08080720 @ =gDisableSoftReset\n\
	strb r1, [r0]\n\
	ldr r0, _08080724 @ =gMaxInGameTimeFlag\n\
	strb r1, [r0]\n\
	ldr r0, _08080728 @ =0x03000022\n\
	strb r1, [r0]\n\
	ldr r0, _0808072C @ =gSkipDoorTransition\n\
	strb r1, [r0]\n\
	ldr r0, _08080730 @ =gPauseScreenFlag\n\
	strb r1, [r0]\n\
	ldr r0, _08080734 @ =0x03000B85\n\
	strb r1, [r0]\n\
	ldr r0, _08080738 @ =0x0300002B\n\
	strb r1, [r0]\n\
	ldr r0, _0808073C @ =gSamusDoorPositionOffset\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	ldr r0, _08080740 @ =gDebugFlag\n\
	strb r1, [r0]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080718: .4byte gUnk_3000be3\n\
_0808071C: .4byte 0x03000018\n\
_08080720: .4byte gDisableSoftReset\n\
_08080724: .4byte gMaxInGameTimeFlag\n\
_08080728: .4byte 0x03000022\n\
_0808072C: .4byte gSkipDoorTransition\n\
_08080730: .4byte gPauseScreenFlag\n\
_08080734: .4byte 0x03000B85\n\
_08080738: .4byte 0x0300002B\n\
_0808073C: .4byte gSamusDoorPositionOffset\n\
_08080740: .4byte gDebugFlag\n\
    .syntax divided\n");
}

// 0x08080744
NAKED_FUNCTION
void Sram_EraseFile(u8 stage)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #0x18\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	adds r5, r4, #0\n\
	add r0, sp, #4\n\
	movs r1, #0\n\
	movs r2, #0x14\n\
	bl memset\n\
	cmp r4, #0\n\
	bne _08080798\n\
	ldr r1, _08080784 @ =gDisableSoftReset\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r2, _08080788 @ =0x03000B94\n\
	ldr r3, _0808078C @ =0x03000B8D\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	add r0, sp, #4\n\
	ldm r0!, {r2, r4, r5}\n\
	stm r1!, {r2, r4, r5}\n\
	ldm r0!, {r2, r4}\n\
	stm r1!, {r2, r4}\n\
	ldr r1, _08080790 @ =0x0000FFFF\n\
	ldr r2, _08080794 @ =0x0858225C\n\
	ldrb r0, [r3]\n\
	b _080807AE\n\
	.align 2, 0\n\
_08080784: .4byte gDisableSoftReset\n\
_08080788: .4byte 0x03000B94\n\
_0808078C: .4byte 0x03000B8D\n\
_08080790: .4byte 0x0000FFFF\n\
_08080794: .4byte 0x0858225C\n\
_08080798:\n\
	cmp r4, #1\n\
	bne _080807A2\n\
	bl WriteMostRecentFileToSram\n\
	b _080807DE\n\
_080807A2:\n\
	cmp r4, #2\n\
	bne _080807D0\n\
	ldr r1, _080807C4 @ =0x0000FFFF\n\
	ldr r2, _080807C8 @ =0x08582268\n\
	ldr r0, _080807CC @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
_080807AE:\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r2, [r0]\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl BitFill\n\
	b _080807DE\n\
	.align 2, 0\n\
_080807C4: .4byte 0x0000FFFF\n\
_080807C8: .4byte 0x08582268\n\
_080807CC: .4byte 0x03000B8D\n\
_080807D0:\n\
	cmp r5, #3\n\
	bne _080807D8\n\
	bl WriteMostRecentFileBackupToSram\n\
_080807D8:\n\
	ldr r1, _080807E8 @ =gDisableSoftReset\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_080807DE:\n\
	add sp, #0x18\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080807E8: .4byte gDisableSoftReset\n\
    .syntax divided\n");
}

// 0x080807EC
NAKED_FUNCTION
void Sram_CopyFile(u8 dst, u8 stage)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	adds r2, r6, #0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	adds r0, r1, #0\n\
	cmp r1, #0\n\
	bne _08080844\n\
	ldr r1, _08080834 @ =gDisableSoftReset\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r4, _08080838 @ =0x03000B94\n\
	lsls r3, r6, #2\n\
	adds r1, r3, r6\n\
	lsls r1, r1, #2\n\
	ldr r5, _0808083C @ =0x03000B8D\n\
	ldrb r2, [r5]\n\
	lsls r0, r2, #2\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r4\n\
	adds r0, r0, r4\n\
	ldm r0!, {r2, r4, r6}\n\
	stm r1!, {r2, r4, r6}\n\
	ldm r0!, {r2, r4}\n\
	stm r1!, {r2, r4}\n\
	ldr r2, _08080840 @ =0x0858225C\n\
	ldrb r0, [r5]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r1, [r0]\n\
	adds r3, r3, r2\n\
	ldr r2, [r3]\n\
	b _08080872\n\
	.align 2, 0\n\
_08080834: .4byte gDisableSoftReset\n\
_08080838: .4byte 0x03000B94\n\
_0808083C: .4byte 0x03000B8D\n\
_08080840: .4byte 0x0858225C\n\
_08080844:\n\
	cmp r1, #1\n\
	bne _0808085C\n\
	ldr r4, _08080858 @ =0x03000B8D\n\
	ldrb r5, [r4]\n\
	strb r6, [r4]\n\
	bl WriteMostRecentFileToSram\n\
	strb r5, [r4]\n\
	b _080808A2\n\
	.align 2, 0\n\
_08080858: .4byte 0x03000B8D\n\
_0808085C:\n\
	cmp r1, #2\n\
	bne _0808088C\n\
	ldr r2, _08080884 @ =0x08582268\n\
	ldr r0, _08080888 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r1, [r0]\n\
	lsls r0, r6, #2\n\
	adds r0, r0, r2\n\
	ldr r2, [r0]\n\
_08080872:\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	b _080808A2\n\
	.align 2, 0\n\
_08080884: .4byte 0x08582268\n\
_08080888: .4byte 0x03000B8D\n\
_0808088C:\n\
	cmp r0, #3\n\
	bne _0808089C\n\
	ldr r4, _080808AC @ =0x03000B8D\n\
	ldrb r5, [r4]\n\
	strb r2, [r4]\n\
	bl WriteMostRecentFileBackupToSram\n\
	strb r5, [r4]\n\
_0808089C:\n\
	ldr r1, _080808B0 @ =gDisableSoftReset\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_080808A2:\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080808AC: .4byte 0x03000B8D\n\
_080808B0: .4byte gDisableSoftReset\n\
    .syntax divided\n");
}

// 0x080808B4
NAKED_FUNCTION
void Sram_WriteFileInfo(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	movs r4, #0\n\
	movs r3, #0\n\
	ldr r2, _08080948 @ =0x03000B94\n\
_080808BC:\n\
	lsls r1, r4, #2\n\
	ldrb r0, [r2]\n\
	cmp r0, #1\n\
	bne _0808091A\n\
	ldr r0, _0808094C @ =0x0858225C\n\
	adds r0, r1, r0\n\
	ldr r1, [r0]\n\
	ldrb r0, [r1, #0x1d]\n\
	strb r0, [r2, #2]\n\
	adds r0, r1, #0\n\
	adds r0, #0x21\n\
	ldrb r0, [r0]\n\
	strb r0, [r2, #3]\n\
	adds r0, r1, #0\n\
	adds r0, #0xc4\n\
	ldrh r0, [r0]\n\
	strh r0, [r2, #4]\n\
	adds r0, r1, #0\n\
	adds r0, #0xc6\n\
	ldrh r0, [r0]\n\
	strh r0, [r2, #6]\n\
	adds r0, r1, #0\n\
	adds r0, #0xc8\n\
	ldrh r0, [r0]\n\
	strh r0, [r2, #8]\n\
	adds r0, r1, #0\n\
	adds r0, #0xca\n\
	ldrh r0, [r0]\n\
	strh r0, [r2, #0xa]\n\
	adds r0, r1, #0\n\
	adds r0, #0xcf\n\
	ldrb r0, [r0]\n\
	strb r0, [r2, #0xc]\n\
	adds r0, r1, #0\n\
	adds r0, #0xe4\n\
	ldrb r0, [r0]\n\
	strb r0, [r2, #0xd]\n\
	adds r0, r1, #0\n\
	adds r0, #0xe5\n\
	ldrb r0, [r0]\n\
	strb r0, [r2, #0xe]\n\
	ldrb r0, [r1, #0x1c]\n\
	strb r0, [r2, #0xf]\n\
	ldrb r0, [r1, #0x18]\n\
	strb r0, [r2, #0x10]\n\
	ldrb r0, [r1, #0x19]\n\
	strb r0, [r2, #0x11]\n\
_0808091A:\n\
	ldrb r0, [r2]\n\
	cmp r0, #0\n\
	beq _08080926\n\
	ldrb r0, [r2, #0xf]\n\
	cmp r0, #0\n\
	bne _0808093A\n\
_08080926:\n\
	strb r3, [r2]\n\
	strb r3, [r2, #2]\n\
	strb r3, [r2, #3]\n\
	strh r3, [r2, #4]\n\
	strh r3, [r2, #6]\n\
	strh r3, [r2, #8]\n\
	strh r3, [r2, #0xa]\n\
	strb r3, [r2, #0xc]\n\
	strb r3, [r2, #0xd]\n\
	strb r3, [r2, #0xe]\n\
_0808093A:\n\
	adds r2, #0x14\n\
	adds r4, #1\n\
	cmp r4, #2\n\
	ble _080808BC\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080948: .4byte 0x03000B94\n\
_0808094C: .4byte 0x0858225C\n\
    .syntax divided\n");
}

/**
 * @brief 80950 | c | V-blank code while loading a file
 * 
 */
void Sram_LoadingfileVblank(void)
{
    vu8 c;

    c = 0;
}

// 0x0808095C
NAKED_FUNCTION
void Sram_AfterLoadingFileVblank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08080968
NAKED_FUNCTION
u32 Sram_ChecLoadSaveFileWithBlank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r0, _08080988 @ =Sram_AfterLoadingFileVblank\n\
	bl CallbackSetVBlank\n\
	bl Sram_CheckLoadSaveFile\n\
	ldr r0, _0808098C @ =Sram_LoadingfileVblank\n\
	bl CallbackSetVBlank\n\
	ldr r0, _08080990 @ =gIsLoadingFile\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08080988: .4byte Sram_AfterLoadingFileVblank\n\
_0808098C: .4byte Sram_LoadingfileVblank\n\
_08080990: .4byte gIsLoadingFile\n\
    .syntax divided\n");
}

/**
 * @brief 80994 | 5c | Writes a file to flash sram if it was flagged as corrupted
 * 
 */
void Sram_SetCurrentFile(u8 file)
{
    u8 previousFile;

    previousFile = gMostRecentSaveFile;
    gMostRecentSaveFile = file;

    switch (gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag)
    {
        case 1:
            WriteMostRecentFileToSram();
            break;

        case 2:
            WriteMostRecentFileToSram();
            WriteMostRecentFileBackupToSram();
        case 0:
            break;
    }

    gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 0;
    gMostRecentSaveFile = previousFile;
}
