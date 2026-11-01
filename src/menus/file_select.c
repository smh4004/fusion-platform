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

// 0x0809E598
NAKED_FUNCTION
s8 FileSelectHandler(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r0, _0809E5B4 @ =gSubGameMode1\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	adds r2, r0, #0\n\
	cmp r1, #5\n\
	bls _0809E5AA\n\
	b _0809E738\n\
_0809E5AA:\n\
	lsls r0, r1, #2\n\
	ldr r1, _0809E5B8 @ =_0809E5BC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0809E5B4: .4byte gSubGameMode1\n\
_0809E5B8: .4byte _0809E5BC\n\
_0809E5BC: @ jump table\n\
	.4byte _0809E5D4 @ case 0\n\
	.4byte _0809E644 @ case 1\n\
	.4byte _0809E69C @ case 2\n\
	.4byte _0809E6BC @ case 3\n\
	.4byte _0809E6E4 @ case 4\n\
	.4byte _0809E704 @ case 5\n\
_0809E5D4:\n\
	bl FileSelectInit\n\
	ldr r1, _0809E614 @ =0x03000B94\n\
	ldrb r0, [r1, #1]\n\
	cmp r0, #0\n\
	bne _0809E624\n\
	ldrb r0, [r1, #0x15]\n\
	cmp r0, #0\n\
	bne _0809E624\n\
	adds r0, r1, #0\n\
	adds r0, #0x29\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809E624\n\
	ldr r0, _0809E618 @ =0x03000B8D\n\
	ldrb r2, [r0]\n\
	lsls r2, r2, #0x14\n\
	movs r0, #0xc4\n\
	lsls r0, r0, #0xe\n\
	adds r2, r2, r0\n\
	asrs r2, r2, #0x10\n\
	movs r0, #1\n\
	movs r1, #0xf\n\
	movs r3, #0\n\
	bl FileSelectSetupOam\n\
	ldr r1, _0809E61C @ =0x04000014\n\
	movs r0, #2\n\
	strh r0, [r1]\n\
	ldr r1, _0809E620 @ =gSubGameMode1\n\
	movs r0, #1\n\
	b _0809E736\n\
	.align 2, 0\n\
_0809E614: .4byte 0x03000B94\n\
_0809E618: .4byte 0x03000B8D\n\
_0809E61C: .4byte 0x04000014\n\
_0809E620: .4byte gSubGameMode1\n\
_0809E624:\n\
	ldr r1, _0809E638 @ =0x04000014\n\
	ldr r2, _0809E63C @ =0x0000FFD0\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	movs r0, #0x30\n\
	strh r0, [r1]\n\
	ldr r1, _0809E640 @ =gSubGameMode1\n\
	movs r0, #5\n\
	b _0809E736\n\
	.align 2, 0\n\
_0809E638: .4byte 0x04000014\n\
_0809E63C: .4byte 0x0000FFD0\n\
_0809E640: .4byte gSubGameMode1\n\
_0809E644:\n\
	ldr r4, _0809E65C @ =gNonGameplayRam\n\
	ldrb r0, [r4, #0xc]\n\
	adds r0, #1\n\
	strb r0, [r4, #0xc]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809E660\n\
	movs r0, #1\n\
	bl FileSelectDrawText\n\
	b _0809E738\n\
	.align 2, 0\n\
_0809E65C: .4byte gNonGameplayRam\n\
_0809E660:\n\
	cmp r0, #2\n\
	bne _0809E66C\n\
	movs r0, #0\n\
	bl FileSelectDrawFileInfo\n\
	b _0809E738\n\
_0809E66C:\n\
	cmp r0, #3\n\
	bne _0809E678\n\
	movs r0, #1\n\
	bl FileSelectDrawFileInfo\n\
	b _0809E738\n\
_0809E678:\n\
	cmp r0, #4\n\
	bne _0809E738\n\
	movs r0, #2\n\
	bl FileSelectDrawFileInfo\n\
	movs r0, #0\n\
	strb r0, [r4, #0xc]\n\
	ldr r1, _0809E694 @ =gWrittenToBldy\n\
	movs r0, #0xe\n\
	strh r0, [r1]\n\
	ldr r1, _0809E698 @ =gSubGameMode1\n\
	movs r0, #2\n\
	b _0809E736\n\
	.align 2, 0\n\
_0809E694: .4byte gWrittenToBldy\n\
_0809E698: .4byte gSubGameMode1\n\
_0809E69C:\n\
	bl FileSelectDrawAllOam\n\
	ldr r1, _0809E6AC @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _0809E6B0\n\
	subs r0, #1\n\
	b _0809E736\n\
	.align 2, 0\n\
_0809E6AC: .4byte gWrittenToBldy\n\
_0809E6B0:\n\
	ldr r1, _0809E6B8 @ =gSubGameMode1\n\
	ldrh r0, [r1]\n\
	adds r0, #1\n\
	b _0809E736\n\
	.align 2, 0\n\
_0809E6B8: .4byte gSubGameMode1\n\
_0809E6BC:\n\
	bl FileSelectInput\n\
	ldr r1, _0809E6DC @ =gNonGameplayRam\n\
	strb r0, [r1, #0x12]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _0809E738\n\
	ldr r1, _0809E6E0 @ =gSubGameMode1\n\
	ldrh r0, [r1]\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	movs r0, #0x14\n\
	bl FadeMusic\n\
	b _0809E738\n\
	.align 2, 0\n\
_0809E6DC: .4byte gNonGameplayRam\n\
_0809E6E0: .4byte gSubGameMode1\n\
_0809E6E4:\n\
	ldr r1, _0809E6F0 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _0809E6F4\n\
	adds r0, #1\n\
	b _0809E736\n\
	.align 2, 0\n\
_0809E6F0: .4byte gWrittenToBldy\n\
_0809E6F4:\n\
	ldr r0, _0809E700 @ =gNonGameplayRam\n\
	movs r5, #0x12\n\
	ldrsb r5, [r0, r5]\n\
	movs r0, #0\n\
	strh r0, [r2]\n\
	b _0809E738\n\
	.align 2, 0\n\
_0809E700: .4byte gNonGameplayRam\n\
_0809E704:\n\
	bl FileSelectProcessCorruptedFile\n\
	cmp r0, #0\n\
	beq _0809E738\n\
	ldr r1, _0809E740 @ =0x04000014\n\
	movs r0, #2\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _0809E744 @ =0x0000FFFA\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0809E748 @ =0x03000B8D\n\
	ldrb r2, [r0]\n\
	lsls r2, r2, #0x14\n\
	movs r0, #0xc4\n\
	lsls r0, r0, #0xe\n\
	adds r2, r2, r0\n\
	asrs r2, r2, #0x10\n\
	movs r0, #1\n\
	movs r1, #0xf\n\
	movs r3, #0\n\
	bl FileSelectSetupOam\n\
	ldr r1, _0809E74C @ =gSubGameMode1\n\
	movs r0, #3\n\
_0809E736:\n\
	strh r0, [r1]\n\
_0809E738:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809E740: .4byte 0x04000014\n\
_0809E744: .4byte 0x0000FFFA\n\
_0809E748: .4byte 0x03000B8D\n\
_0809E74C: .4byte gSubGameMode1\n\
    .syntax divided\n");
}

// 0x0809E750
NAKED_FUNCTION
void FileSelectInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #4\n\
	ldr r3, _0809E920 @ =0x04000208\n\
	movs r4, #0\n\
	strh r4, [r3]\n\
	ldr r2, _0809E924 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809E928 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _0809E92C @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809E930 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _0809E934 @ =unk_9eaa4\n\
	bl CallbackSetVBlank\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x13\n\
	strh r4, [r0]\n\
	ldr r1, _0809E938 @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	ldr r0, _0809E93C @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _0809E940 @ =0x04000054\n\
	strh r1, [r0]\n\
	bl ClearGfxRam\n\
	ldr r0, _0809E944 @ =gNextOamSlot\n\
	strb r4, [r0]\n\
	bl ResetFreeOam\n\
	movs r6, #0\n\
	str r6, [sp]\n\
	ldr r4, _0809E948 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r0, _0809E94C @ =gNonGameplayRam\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809E950 @ =0x85000150\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809E954 @ =0x0400000E\n\
	strh r6, [r0]\n\
	subs r0, #2\n\
	strh r6, [r0]\n\
	subs r0, #2\n\
	strh r6, [r0]\n\
	subs r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #8\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	ldr r1, _0809E958 @ =0x04000016\n\
	ldr r2, _0809E95C @ =0x0000FFFA\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0809E960 @ =0x04000018\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	ldr r0, _0809E964 @ =0x08742FB4\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809E968 @ =0x087470E0\n\
	ldr r1, _0809E96C @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809E970 @ =0x087476A0\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	mov r8, r0\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809E974 @ =0x84000080\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809E978 @ =0x0873CFAC\n\
	ldr r1, _0809E97C @ =0x0600E000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809E980 @ =0x0873D380\n\
	movs r5, #0x80\n\
	lsls r5, r5, #0x12\n\
	adds r1, r5, #0\n\
	bl LZ77UncompVram\n\
	str r5, [r4]\n\
	ldr r0, _0809E984 @ =0x0600E800\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809E988 @ =0x84000200\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809E98C @ =0x0873D5EC\n\
	ldr r1, _0809E990 @ =0x0600F000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809E994 @ =0x0873DB84\n\
	str r0, [r4]\n\
	mov r2, r8\n\
	str r2, [r4, #4]\n\
	ldr r0, _0809E998 @ =0x84000008\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r1, _0809E99C @ =0x0873DAC4\n\
	str r1, [r4]\n\
	str r2, [r4, #4]\n\
	ldr r0, _0809E9A0 @ =0x84000002\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	adds r1, #8\n\
	str r1, [r4]\n\
	ldr r0, _0809E9A4 @ =0x0500001C\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809E9A8 @ =0x84000001\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	strh r6, [r2]\n\
	movs r3, #0\n\
	ldr r7, _0809E9AC @ =0x02000800\n\
	ldr r5, _0809E9B0 @ =0x02000340\n\
	ldr r6, _0809E9B4 @ =0x00000FFF\n\
	movs r0, #0x80\n\
	lsls r0, r0, #5\n\
	adds r4, r0, #0\n\
_0809E86A:\n\
	adds r2, r3, r7\n\
	adds r0, r3, r5\n\
	ldrh r1, [r0]\n\
	adds r0, r6, #0\n\
	ands r0, r1\n\
	orrs r0, r4\n\
	strh r0, [r2]\n\
	adds r3, #2\n\
	cmp r3, #0xff\n\
	bls _0809E86A\n\
	ldr r0, _0809E9B8 @ =0x0873DC20\n\
	ldr r1, _0809E9BC @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r1, _0809E948 @ =0x040000D4\n\
	ldr r0, _0809E9C0 @ =0x08740D08\n\
	str r0, [r1]\n\
	ldr r0, _0809E9C4 @ =0x05000200\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809E974 @ =0x84000080\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r4, _0809E94C @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	ldr r1, _0809E9C8 @ =0x0879EC68\n\
	ldr r0, _0809E9CC @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0]\n\
	str r0, [r4, #4]\n\
	bl Sram_WriteFileInfo\n\
	ldr r0, _0809E9D0 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	strb r0, [r4, #0xd]\n\
	movs r0, #9\n\
	movs r1, #0x66\n\
	movs r2, #0x74\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	movs r0, #6\n\
	movs r1, #0x8e\n\
	movs r2, #0x74\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	movs r0, #7\n\
	movs r1, #0x84\n\
	movs r2, #0x30\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	bl FileSelectDrawAllOam\n\
	ldr r1, _0809E954 @ =0x0400000E\n\
	ldr r2, _0809E9D4 @ =0x00001F03\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	subs r1, #2\n\
	ldr r2, _0809E9D8 @ =0x00001C0A\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	subs r1, #2\n\
	adds r2, #0xff\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	subs r1, #2\n\
	adds r2, #0xff\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	subs r1, #8\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0809E9DC @ =FileSelectVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809E920: .4byte 0x04000208\n\
_0809E924: .4byte 0x04000004\n\
_0809E928: .4byte 0x0000FFEF\n\
_0809E92C: .4byte 0x04000200\n\
_0809E930: .4byte 0x0000FFFD\n\
_0809E934: .4byte unk_9eaa4\n\
_0809E938: .4byte 0x04000050\n\
_0809E93C: .4byte gWrittenToBldy\n\
_0809E940: .4byte 0x04000054\n\
_0809E944: .4byte gNextOamSlot\n\
_0809E948: .4byte 0x040000D4\n\
_0809E94C: .4byte gNonGameplayRam\n\
_0809E950: .4byte 0x85000150\n\
_0809E954: .4byte 0x0400000E\n\
_0809E958: .4byte 0x04000016\n\
_0809E95C: .4byte 0x0000FFFA\n\
_0809E960: .4byte 0x04000018\n\
_0809E964: .4byte 0x08742FB4\n\
_0809E968: .4byte 0x087470E0\n\
_0809E96C: .4byte 0x0600F800\n\
_0809E970: .4byte 0x087476A0\n\
_0809E974: .4byte 0x84000080\n\
_0809E978: .4byte 0x0873CFAC\n\
_0809E97C: .4byte 0x0600E000\n\
_0809E980: .4byte 0x0873D380\n\
_0809E984: .4byte 0x0600E800\n\
_0809E988: .4byte 0x84000200\n\
_0809E98C: .4byte 0x0873D5EC\n\
_0809E990: .4byte 0x0600F000\n\
_0809E994: .4byte 0x0873DB84\n\
_0809E998: .4byte 0x84000008\n\
_0809E99C: .4byte 0x0873DAC4\n\
_0809E9A0: .4byte 0x84000002\n\
_0809E9A4: .4byte 0x0500001C\n\
_0809E9A8: .4byte 0x84000001\n\
_0809E9AC: .4byte 0x02000800\n\
_0809E9B0: .4byte 0x02000340\n\
_0809E9B4: .4byte 0x00000FFF\n\
_0809E9B8: .4byte 0x0873DC20\n\
_0809E9BC: .4byte 0x06010000\n\
_0809E9C0: .4byte 0x08740D08\n\
_0809E9C4: .4byte 0x05000200\n\
_0809E9C8: .4byte 0x0879EC68\n\
_0809E9CC: .4byte 0x03000011\n\
_0809E9D0: .4byte 0x03000B8D\n\
_0809E9D4: .4byte 0x00001F03\n\
_0809E9D8: .4byte 0x00001C0A\n\
_0809E9DC: .4byte FileSelectVblank\n\
    .syntax divided\n");
}

// 0x0809E9E0
NAKED_FUNCTION
void FileSelectVblank(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	ldr r1, _0809EA10 @ =0x040000D4\n\
	ldr r0, _0809EA14 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809EA18 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	subs r1, #0x80\n\
	ldr r0, _0809EA1C @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0809EA20 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x11]\n\
	adds r3, r1, #0\n\
	cmp r0, #5\n\
	bhi _0809EA98\n\
	lsls r0, r0, #2\n\
	ldr r1, _0809EA24 @ =_0809EA28\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0809EA10: .4byte 0x040000D4\n\
_0809EA14: .4byte gOamData\n\
_0809EA18: .4byte 0x84000100\n\
_0809EA1C: .4byte gWrittenToBldy\n\
_0809EA20: .4byte gNonGameplayRam\n\
_0809EA24: .4byte _0809EA28\n\
_0809EA28: @ jump table\n\
	.4byte _0809EA9C @ case 0\n\
	.4byte _0809EA40 @ case 1\n\
	.4byte _0809EA60 @ case 2\n\
	.4byte _0809EA50 @ case 3\n\
	.4byte _0809EA70 @ case 4\n\
	.4byte _0809EA80 @ case 5\n\
_0809EA40:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r4, #0x80\n\
	lsls r4, r4, #1\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	b _0809EA8A\n\
_0809EA50:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r4, #0x80\n\
	lsls r4, r4, #2\n\
	adds r1, r4, #0\n\
	orrs r0, r1\n\
	b _0809EA8A\n\
_0809EA60:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809EA6C @ =0x0000FEFF\n\
	b _0809EA88\n\
	.align 2, 0\n\
_0809EA6C: .4byte 0x0000FEFF\n\
_0809EA70:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809EA7C @ =0x0000FDFF\n\
	b _0809EA88\n\
	.align 2, 0\n\
_0809EA7C: .4byte 0x0000FDFF\n\
_0809EA80:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809EA94 @ =0x0000FCFF\n\
_0809EA88:\n\
	ands r0, r1\n\
_0809EA8A:\n\
	strh r0, [r2]\n\
	movs r0, #0\n\
	strb r0, [r3, #0x11]\n\
	b _0809EA9C\n\
	.align 2, 0\n\
_0809EA94: .4byte 0x0000FCFF\n\
_0809EA98:\n\
	movs r0, #0\n\
	strb r0, [r1, #0x11]\n\
_0809EA9C:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809EAA4
NAKED_FUNCTION
void unk_9eaa4(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
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
u8 FileSelectSetupOam(u8 type, u16 xPosition, u16 yPosition, u8 unused)
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

// 0x0809F930
NAKED_FUNCTION
void FileSelectProcessSamusHead(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #9]\n\
	cmp r0, #0\n\
	bne _0809FA2C\n\
	ldr r0, _0809F958 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809F994\n\
	ldr r1, _0809F95C @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xd]\n\
	cmp r0, #3\n\
	beq _0809F974\n\
	cmp r0, #3\n\
	ble _0809F960\n\
	cmp r0, #4\n\
	beq _0809F984\n\
	b _0809F9F6\n\
	.align 2, 0\n\
_0809F958: .4byte gChangedInput\n\
_0809F95C: .4byte gNonGameplayRam\n\
_0809F960:\n\
	cmp r0, #1\n\
	blt _0809F9F6\n\
	movs r0, #0xf\n\
	strh r0, [r4]\n\
	ldrh r0, [r4, #2]\n\
	subs r0, #0x10\n\
	strh r0, [r4, #2]\n\
	ldrb r0, [r1, #0xd]\n\
	subs r0, #1\n\
	b _0809F9D0\n\
_0809F974:\n\
	movs r0, #0xf\n\
	strh r0, [r4]\n\
	ldrh r0, [r4, #2]\n\
	subs r0, #0x25\n\
	strh r0, [r4, #2]\n\
	ldrb r0, [r1, #0xd]\n\
	subs r0, #1\n\
	b _0809F9D0\n\
_0809F984:\n\
	movs r0, #0xf\n\
	strh r0, [r4]\n\
	ldrh r0, [r4, #2]\n\
	subs r0, #0x28\n\
	strh r0, [r4, #2]\n\
	ldrb r0, [r1, #0xd]\n\
	subs r0, #1\n\
	b _0809F9D0\n\
_0809F994:\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809F9F6\n\
	ldr r1, _0809F9B0 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xd]\n\
	cmp r0, #2\n\
	beq _0809F9C2\n\
	cmp r0, #2\n\
	ble _0809F9B4\n\
	cmp r0, #3\n\
	beq _0809F9E0\n\
	b _0809F9F6\n\
	.align 2, 0\n\
_0809F9B0: .4byte gNonGameplayRam\n\
_0809F9B4:\n\
	cmp r0, #0\n\
	blt _0809F9F6\n\
	movs r0, #0xf\n\
	strh r0, [r4]\n\
	ldrh r0, [r4, #2]\n\
	adds r0, #0x10\n\
	b _0809F9CA\n\
_0809F9C2:\n\
	movs r0, #0xf\n\
	strh r0, [r4]\n\
	ldrh r0, [r4, #2]\n\
	adds r0, #0x25\n\
_0809F9CA:\n\
	strh r0, [r4, #2]\n\
	ldrb r0, [r1, #0xd]\n\
	adds r0, #1\n\
_0809F9D0:\n\
	strb r0, [r1, #0xd]\n\
	ldr r0, _0809F9DC @ =0x000001F9\n\
	bl SoundPlay\n\
	b _0809F9F6\n\
	.align 2, 0\n\
_0809F9DC: .4byte 0x000001F9\n\
_0809F9E0:\n\
	movs r0, #0xf\n\
	strh r0, [r4]\n\
	ldrh r0, [r4, #2]\n\
	adds r0, #0x28\n\
	strh r0, [r4, #2]\n\
	ldrb r0, [r1, #0xd]\n\
	adds r0, #1\n\
	strb r0, [r1, #0xd]\n\
	ldr r0, _0809FA1C @ =0x000001F9\n\
	bl SoundPlay\n\
_0809F9F6:\n\
	ldr r0, _0809FA20 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0xd]\n\
	cmp r0, #3\n\
	beq _0809FACC\n\
	ldr r0, _0809FA24 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809FACC\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
	ldr r0, _0809FA28 @ =0x000001FB\n\
	bl SoundPlay\n\
	b _0809FACC\n\
	.align 2, 0\n\
_0809FA1C: .4byte 0x000001F9\n\
_0809FA20: .4byte gNonGameplayRam\n\
_0809FA24: .4byte gChangedInput\n\
_0809FA28: .4byte 0x000001FB\n\
_0809FA2C:\n\
	cmp r0, #1\n\
	bne _0809FA60\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _0809FA4C\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809FA4C\n\
	strb r1, [r4, #7]\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
_0809FA4C:\n\
	ldr r0, _0809FA5C @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #0xb\n\
	bne _0809FACC\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
	b _0809FACC\n\
	.align 2, 0\n\
_0809FA5C: .4byte gNonGameplayRam\n\
_0809FA60:\n\
	cmp r0, #0x64\n\
	bne _0809FAB4\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r1, [r4, #7]\n\
	ldr r0, _0809FA88 @ =gNonGameplayRam\n\
	movs r2, #0xa\n\
	ldrsh r1, [r0, r2]\n\
	cmp r1, #0\n\
	bne _0809FA90\n\
	strb r1, [r4, #7]\n\
	strb r1, [r4, #6]\n\
	ldr r0, _0809FA8C @ =0x08740A48\n\
	str r0, [r4, #0x14]\n\
	strb r1, [r4, #9]\n\
	b _0809FACC\n\
	.align 2, 0\n\
_0809FA88: .4byte gNonGameplayRam\n\
_0809FA8C: .4byte 0x08740A48\n\
_0809FA90:\n\
	cmp r1, #5\n\
	beq _0809FAA0\n\
	cmp r1, #7\n\
	beq _0809FAA0\n\
	cmp r1, #0xc\n\
	beq _0809FAA0\n\
	cmp r1, #0xd\n\
	bne _0809FACC\n\
_0809FAA0:\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
	ldr r0, _0809FAB0 @ =0x08740A70\n\
	str r0, [r4, #0x14]\n\
	movs r0, #0xc8\n\
	strb r0, [r4, #9]\n\
	b _0809FACC\n\
	.align 2, 0\n\
_0809FAB0: .4byte 0x08740A70\n\
_0809FAB4:\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _0809FACC\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809FACC\n\
	strb r1, [r4, #7]\n\
_0809FACC:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809FAD4
NAKED_FUNCTION
void FileSelectProcessCursor(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #9]\n\
	cmp r0, #0\n\
	beq _0809FAE0\n\
	b _0809FC20\n\
_0809FAE0:\n\
	ldr r3, _0809FB20 @ =gNonGameplayRam\n\
	movs r0, #0xa\n\
	ldrsh r1, [r3, r0]\n\
	cmp r1, #2\n\
	bne _0809FB50\n\
	ldr r0, _0809FB24 @ =gChangedInput\n\
	ldrh r2, [r0]\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _0809FAF6\n\
	b _0809FC48\n\
_0809FAF6:\n\
	movs r0, #9\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	bne _0809FB00\n\
	b _0809FC82\n\
_0809FB00:\n\
	ldr r2, _0809FB28 @ =0x03000B94\n\
	ldrb r1, [r3, #0xd]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0, #0x10]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809FB30\n\
	ldr r0, _0809FB2C @ =0x000001FB\n\
	bl SoundPlay\n\
	b _0809FB38\n\
	.align 2, 0\n\
_0809FB20: .4byte gNonGameplayRam\n\
_0809FB24: .4byte gChangedInput\n\
_0809FB28: .4byte 0x03000B94\n\
_0809FB2C: .4byte 0x000001FB\n\
_0809FB30:\n\
	movs r0, #0xff\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
_0809FB38:\n\
	ldr r1, _0809FB48 @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strb r0, [r1, #0xe]\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
	ldr r0, _0809FB4C @ =0x08740B70\n\
	str r0, [r4, #0x14]\n\
	b _0809FC48\n\
	.align 2, 0\n\
_0809FB48: .4byte gNonGameplayRam\n\
_0809FB4C: .4byte 0x08740B70\n\
_0809FB50:\n\
	cmp r1, #3\n\
	beq _0809FB56\n\
	b _0809FC82\n\
_0809FB56:\n\
	ldr r0, _0809FB7C @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809FB84\n\
	ldrb r0, [r3, #0xe]\n\
	cmp r0, #0\n\
	beq _0809FBA2\n\
	subs r0, #1\n\
	strb r0, [r3, #0xe]\n\
	ldrh r0, [r4, #2]\n\
	subs r0, #0x10\n\
	strh r0, [r4, #2]\n\
	ldr r0, _0809FB80 @ =0x000001F9\n\
	bl SoundPlay\n\
	b _0809FBA2\n\
	.align 2, 0\n\
_0809FB7C: .4byte gChangedInput\n\
_0809FB80: .4byte 0x000001F9\n\
_0809FB84:\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809FBA2\n\
	ldrb r0, [r3, #0xe]\n\
	cmp r0, #1\n\
	bhi _0809FBA2\n\
	adds r0, #1\n\
	strb r0, [r3, #0xe]\n\
	ldrh r0, [r4, #2]\n\
	adds r0, #0x10\n\
	strh r0, [r4, #2]\n\
	ldr r0, _0809FBEC @ =0x000001F9\n\
	bl SoundPlay\n\
_0809FBA2:\n\
	ldr r0, _0809FBF0 @ =gChangedInput\n\
	ldrh r2, [r0]\n\
	movs r0, #2\n\
	ands r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	bne _0809FC48\n\
	movs r0, #9\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0809FC82\n\
	strb r1, [r4, #7]\n\
	strb r1, [r4, #6]\n\
	ldr r0, _0809FBF4 @ =0x08740B70\n\
	str r0, [r4, #0x14]\n\
	ldr r1, _0809FBF8 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xe]\n\
	cmp r0, #0\n\
	bne _0809FC0E\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
	ldr r2, _0809FBFC @ =0x03000B94\n\
	ldrb r1, [r1, #0xd]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0, #0x10]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0809FC04\n\
	ldr r0, _0809FC00 @ =0x000001FB\n\
	bl SoundPlay\n\
	b _0809FC82\n\
	.align 2, 0\n\
_0809FBEC: .4byte 0x000001F9\n\
_0809FBF0: .4byte gChangedInput\n\
_0809FBF4: .4byte 0x08740B70\n\
_0809FBF8: .4byte gNonGameplayRam\n\
_0809FBFC: .4byte 0x03000B94\n\
_0809FC00: .4byte 0x000001FB\n\
_0809FC04:\n\
	movs r0, #0xff\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	b _0809FC82\n\
_0809FC0E:\n\
	ldr r0, _0809FC1C @ =0x000001FB\n\
	bl SoundPlay\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _0809FC82\n\
	.align 2, 0\n\
_0809FC1C: .4byte 0x000001FB\n\
_0809FC20:\n\
	cmp r0, #1\n\
	bne _0809FC54\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _0809FC40\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809FC40\n\
	strb r1, [r4, #7]\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
_0809FC40:\n\
	ldr r0, _0809FC50 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #0xb\n\
	bne _0809FC82\n\
_0809FC48:\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
	b _0809FC82\n\
	.align 2, 0\n\
_0809FC50: .4byte gNonGameplayRam\n\
_0809FC54:\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _0809FC6C\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809FC6C\n\
	strb r1, [r4, #7]\n\
_0809FC6C:\n\
	ldr r0, _0809FC88 @ =gNonGameplayRam\n\
	movs r1, #0xa\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #3\n\
	bne _0809FC82\n\
	movs r1, #0\n\
	strb r1, [r4, #7]\n\
	strb r1, [r4, #6]\n\
	ldr r0, _0809FC8C @ =0x08740B48\n\
	str r0, [r4, #0x14]\n\
	strb r1, [r4, #9]\n\
_0809FC82:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809FC88: .4byte gNonGameplayRam\n\
_0809FC8C: .4byte 0x08740B48\n\
    .syntax divided\n");
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

// 0x0809FDDC
NAKED_FUNCTION
void unk_9fddc(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r2, [r4, #9]\n\
	cmp r2, #0\n\
	bne _0809FEAC\n\
	ldr r3, _0809FE1C @ =gNonGameplayRam\n\
	ldrb r0, [r3, #0x10]\n\
	cmp r0, #0\n\
	bne _0809FE2C\n\
	ldr r0, _0809FE20 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809FE58\n\
	movs r0, #1\n\
	strb r0, [r3, #0x10]\n\
	ldr r1, _0809FE24 @ =0x0873DBB0\n\
	ldr r0, _0809FE28 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #1\n\
	adds r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	strh r0, [r4]\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	b _0809FE58\n\
	.align 2, 0\n\
_0809FE1C: .4byte gNonGameplayRam\n\
_0809FE20: .4byte gChangedInput\n\
_0809FE24: .4byte 0x0873DBB0\n\
_0809FE28: .4byte 0x03000011\n\
_0809FE2C:\n\
	cmp r0, #1\n\
	bne _0809FE58\n\
	ldr r0, _0809FE80 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809FE58\n\
	strb r2, [r3, #0x10]\n\
	ldr r1, _0809FE84 @ =0x0873DBB0\n\
	ldr r0, _0809FE88 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	strh r0, [r4]\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
_0809FE58:\n\
	ldr r0, _0809FE80 @ =gChangedInput\n\
	ldrh r2, [r0]\n\
	movs r0, #2\n\
	ands r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	bne _0809FED6\n\
	movs r0, #9\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0809FEF8\n\
	strb r1, [r4, #7]\n\
	strb r1, [r4, #6]\n\
	ldr r0, _0809FE8C @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0x10]\n\
	cmp r0, #0\n\
	bne _0809FE94\n\
	ldr r0, _0809FE90 @ =0x00000207\n\
	b _0809FE96\n\
	.align 2, 0\n\
_0809FE80: .4byte gChangedInput\n\
_0809FE84: .4byte 0x0873DBB0\n\
_0809FE88: .4byte 0x03000011\n\
_0809FE8C: .4byte gNonGameplayRam\n\
_0809FE90: .4byte 0x00000207\n\
_0809FE94:\n\
	ldr r0, _0809FEA4 @ =0x000001FB\n\
_0809FE96:\n\
	bl SoundPlay\n\
	ldr r0, _0809FEA8 @ =0x08740B70\n\
	str r0, [r4, #0x14]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _0809FEF8\n\
	.align 2, 0\n\
_0809FEA4: .4byte 0x000001FB\n\
_0809FEA8: .4byte 0x08740B70\n\
_0809FEAC:\n\
	cmp r2, #1\n\
	bne _0809FEE0\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _0809FEC8\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809FEC8\n\
	strb r1, [r4, #7]\n\
_0809FEC8:\n\
	ldr r0, _0809FEDC @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #0xb\n\
	bne _0809FEF8\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
_0809FED6:\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
	b _0809FEF8\n\
	.align 2, 0\n\
_0809FEDC: .4byte gNonGameplayRam\n\
_0809FEE0:\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _0809FEF8\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809FEF8\n\
	strb r1, [r4, #7]\n\
_0809FEF8:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809FF00
NAKED_FUNCTION
void unk_9ff00(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r2, [r4, #9]\n\
	cmp r2, #0\n\
	bne _0809FFD0\n\
	ldr r3, _0809FF40 @ =gNonGameplayRam\n\
	ldrb r0, [r3, #0x10]\n\
	cmp r0, #0\n\
	bne _0809FF50\n\
	ldr r0, _0809FF44 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809FF7C\n\
	movs r0, #1\n\
	strb r0, [r3, #0x10]\n\
	ldr r1, _0809FF48 @ =0x0873DBBE\n\
	ldr r0, _0809FF4C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #1\n\
	adds r1, #1\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	strh r0, [r4]\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	b _0809FF7C\n\
	.align 2, 0\n\
_0809FF40: .4byte gNonGameplayRam\n\
_0809FF44: .4byte gChangedInput\n\
_0809FF48: .4byte 0x0873DBBE\n\
_0809FF4C: .4byte 0x03000011\n\
_0809FF50:\n\
	cmp r0, #1\n\
	bne _0809FF7C\n\
	ldr r0, _0809FFA8 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809FF7C\n\
	strb r2, [r3, #0x10]\n\
	ldr r1, _0809FFAC @ =0x0873DBBE\n\
	ldr r0, _0809FFB0 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	strh r0, [r4]\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
_0809FF7C:\n\
	ldr r0, _0809FFA8 @ =gChangedInput\n\
	ldrh r2, [r0]\n\
	movs r0, #2\n\
	ands r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	bne _0809FFFA\n\
	movs r0, #9\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _080A001C\n\
	strb r1, [r4, #7]\n\
	strb r1, [r4, #6]\n\
	ldr r0, _0809FFB4 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0x10]\n\
	cmp r0, #0\n\
	bne _0809FFB8\n\
	movs r0, #0x82\n\
	lsls r0, r0, #2\n\
	b _0809FFBA\n\
	.align 2, 0\n\
_0809FFA8: .4byte gChangedInput\n\
_0809FFAC: .4byte 0x0873DBBE\n\
_0809FFB0: .4byte 0x03000011\n\
_0809FFB4: .4byte gNonGameplayRam\n\
_0809FFB8:\n\
	ldr r0, _0809FFC8 @ =0x000001FB\n\
_0809FFBA:\n\
	bl SoundPlay\n\
	ldr r0, _0809FFCC @ =0x08740B70\n\
	str r0, [r4, #0x14]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _080A001C\n\
	.align 2, 0\n\
_0809FFC8: .4byte 0x000001FB\n\
_0809FFCC: .4byte 0x08740B70\n\
_0809FFD0:\n\
	cmp r2, #1\n\
	bne _080A0004\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _0809FFEC\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809FFEC\n\
	strb r1, [r4, #7]\n\
_0809FFEC:\n\
	ldr r0, _080A0000 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0xc]\n\
	cmp r0, #0xb\n\
	bne _080A001C\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
_0809FFFA:\n\
	movs r0, #0x64\n\
	strb r0, [r4, #9]\n\
	b _080A001C\n\
	.align 2, 0\n\
_080A0000: .4byte gNonGameplayRam\n\
_080A0004:\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _080A001C\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080A001C\n\
	strb r1, [r4, #7]\n\
_080A001C:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080A0024
NAKED_FUNCTION
void FileSelectProcessAudioLogos(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _080A0064 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0xd]\n\
	cmp r0, #3\n\
	bne _080A00B8\n\
	ldrb r3, [r2, #9]\n\
	cmp r3, #0\n\
	bne _080A0078\n\
	ldr r0, _080A0068 @ =0x087407C0\n\
	str r0, [r2, #0x14]\n\
	ldr r0, _080A006C @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A00DA\n\
	movs r0, #1\n\
	strb r0, [r2, #9]\n\
	ldr r0, _080A0070 @ =0x087407D0\n\
	str r0, [r2, #0x14]\n\
	strb r3, [r2, #7]\n\
	strb r3, [r2, #6]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x12\n\
	bl DoSoundAction\n\
	ldr r0, _080A0074 @ =0x00000206\n\
	bl SoundPlay\n\
	b _080A00DA\n\
	.align 2, 0\n\
_080A0064: .4byte gNonGameplayRam\n\
_080A0068: .4byte 0x087407C0\n\
_080A006C: .4byte gChangedInput\n\
_080A0070: .4byte 0x087407D0\n\
_080A0074: .4byte 0x00000206\n\
_080A0078:\n\
	cmp r3, #1\n\
	bne _080A00DA\n\
	ldr r0, _080A00AC @ =0x087407D0\n\
	str r0, [r2, #0x14]\n\
	ldr r0, _080A00B0 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A00DA\n\
	movs r1, #0\n\
	strb r1, [r2, #9]\n\
	ldr r0, _080A00B4 @ =0x087407C0\n\
	str r0, [r2, #0x14]\n\
	strb r1, [r2, #7]\n\
	strb r1, [r2, #6]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x11\n\
	bl DoSoundAction\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	b _080A00DA\n\
	.align 2, 0\n\
_080A00AC: .4byte 0x087407D0\n\
_080A00B0: .4byte gChangedInput\n\
_080A00B4: .4byte 0x087407C0\n\
_080A00B8:\n\
	ldrb r1, [r2, #9]\n\
	cmp r1, #0\n\
	bne _080A00CC\n\
	ldr r0, _080A00C8 @ =0x087407E0\n\
	str r0, [r2, #0x14]\n\
	strb r1, [r2, #7]\n\
	strb r1, [r2, #6]\n\
	b _080A00DA\n\
	.align 2, 0\n\
_080A00C8: .4byte 0x087407E0\n\
_080A00CC:\n\
	cmp r1, #1\n\
	bne _080A00DA\n\
	ldr r0, _080A00E0 @ =0x087407F0\n\
	str r0, [r2, #0x14]\n\
	movs r0, #0\n\
	strb r0, [r2, #7]\n\
	strb r0, [r2, #6]\n\
_080A00DA:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A00E0: .4byte 0x087407F0\n\
    .syntax divided\n");
}

// 0x080A00E4
NAKED_FUNCTION
void FileSelectProcessAudioSelect(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r0, _080A0110 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #0xd]\n\
	cmp r0, #3\n\
	bne _080A0138\n\
	movs r3, #1\n\
	strb r3, [r2, #5]\n\
	ldrb r0, [r2, #9]\n\
	cmp r0, #0\n\
	bne _080A0118\n\
	ldr r0, _080A0114 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A0140\n\
	strb r3, [r2, #9]\n\
	movs r0, #0xaa\n\
	strh r0, [r2]\n\
	b _080A0140\n\
	.align 2, 0\n\
_080A0110: .4byte gNonGameplayRam\n\
_080A0114: .4byte gChangedInput\n\
_080A0118:\n\
	cmp r0, #1\n\
	bne _080A0140\n\
	ldr r0, _080A0134 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A0140\n\
	movs r0, #0\n\
	strb r0, [r2, #9]\n\
	movs r0, #0x66\n\
	strh r0, [r2]\n\
	b _080A0140\n\
	.align 2, 0\n\
_080A0134: .4byte gChangedInput\n\
_080A0138:\n\
	movs r0, #0\n\
	strb r0, [r2, #7]\n\
	strb r0, [r2, #6]\n\
	strb r0, [r2, #5]\n\
_080A0140:\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x080A0144
NAKED_FUNCTION
void FileSelectProcessFileOverlay(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r1, _080A0164 @ =gNonGameplayRam\n\
	movs r3, #0xa\n\
	ldrsh r0, [r1, r3]\n\
	cmp r0, #0\n\
	bne _080A015E\n\
	ldr r0, _080A0168 @ =0x0879E890\n\
	ldrb r1, [r1, #0xd]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	str r0, [r2, #0x14]\n\
_080A015E:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A0164: .4byte gNonGameplayRam\n\
_080A0168: .4byte 0x0879E890\n\
    .syntax divided\n");
}

// 0x080A016C
NAKED_FUNCTION
void unk_a016c(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r1, _080A0190 @ =gNonGameplayRam\n\
	movs r0, #0xa\n\
	ldrsh r3, [r1, r0]\n\
	cmp r3, #0\n\
	bne _080A01C6\n\
	ldr r0, _080A0194 @ =0x087408E0\n\
	str r0, [r2, #0x14]\n\
	ldrb r1, [r1, #0xd]\n\
	cmp r1, #2\n\
	bhi _080A01C4\n\
	movs r0, #1\n\
	strb r0, [r2, #5]\n\
	cmp r1, #0\n\
	bne _080A0198\n\
	movs r0, #0x31\n\
	b _080A01A6\n\
	.align 2, 0\n\
_080A0190: .4byte gNonGameplayRam\n\
_080A0194: .4byte 0x087408E0\n\
_080A0198:\n\
	cmp r1, #1\n\
	bne _080A01A0\n\
	movs r0, #0x41\n\
	b _080A01A6\n\
_080A01A0:\n\
	cmp r1, #2\n\
	bne _080A01A8\n\
	movs r0, #0x51\n\
_080A01A6:\n\
	strh r0, [r2, #2]\n\
_080A01A8:\n\
	ldr r0, _080A01BC @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080A01C6\n\
	ldr r0, _080A01C0 @ =0x087408D0\n\
	str r0, [r2, #0x14]\n\
	b _080A01C6\n\
	.align 2, 0\n\
_080A01BC: .4byte gChangedInput\n\
_080A01C0: .4byte 0x087408D0\n\
_080A01C4:\n\
	strb r3, [r2, #5]\n\
_080A01C6:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080A01CC
NAKED_FUNCTION
void unk_a01cc(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080A01D0
NAKED_FUNCTION
void FileSelectProcessFileActionPanel(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r2, [r4, #9]\n\
	cmp r2, #0\n\
	bne _080A0204\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r4, #7]\n\
	cmp r0, r3\n\
	bne _080A0266\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #0\n\
	bne _080A0266\n\
	strb r2, [r4, #7]\n\
	strb r2, [r4, #6]\n\
	ldr r0, _080A0200 @ =0x08740940\n\
	str r0, [r4, #0x14]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _080A0266\n\
	.align 2, 0\n\
_080A0200: .4byte 0x08740940\n\
_080A0204:\n\
	cmp r2, #1\n\
	bne _080A0248\n\
	ldr r0, _080A021C @ =gNonGameplayRam\n\
	movs r1, #0xa\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0x15\n\
	beq _080A0228\n\
	cmp r0, #0x15\n\
	bgt _080A0220\n\
	cmp r0, #4\n\
	beq _080A0228\n\
	b _080A0266\n\
	.align 2, 0\n\
_080A021C: .4byte gNonGameplayRam\n\
_080A0220:\n\
	cmp r0, #0x1a\n\
	beq _080A0228\n\
	cmp r0, #0x21\n\
	bne _080A0266\n\
_080A0228:\n\
	ldr r0, _080A0240 @ =0x000001FD\n\
	bl SoundPlay\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
	ldr r0, _080A0244 @ =0x08740950\n\
	str r0, [r4, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r4, #9]\n\
	b _080A0266\n\
	.align 2, 0\n\
_080A0240: .4byte 0x000001FD\n\
_080A0244: .4byte 0x08740950\n\
_080A0248:\n\
	cmp r2, #2\n\
	bne _080A0266\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _080A0266\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080A0266\n\
	strb r1, [r4, #4]\n\
	strb r1, [r4, #5]\n\
_080A0266:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x080A026C
NAKED_FUNCTION
void FileSelectProcessCopyFilePanel(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r2, [r4, #9]\n\
	cmp r2, #0\n\
	bne _080A02A0\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r4, #7]\n\
	cmp r0, r3\n\
	bne _080A02FE\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #0\n\
	bne _080A02FE\n\
	strb r2, [r4, #7]\n\
	strb r2, [r4, #6]\n\
	ldr r0, _080A029C @ =0x087409A0\n\
	str r0, [r4, #0x14]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _080A02FE\n\
	.align 2, 0\n\
_080A029C: .4byte 0x087409A0\n\
_080A02A0:\n\
	cmp r2, #1\n\
	bne _080A02E0\n\
	ldr r0, _080A02B8 @ =gNonGameplayRam\n\
	movs r1, #0xa\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0x15\n\
	beq _080A02C0\n\
	cmp r0, #0x15\n\
	bgt _080A02BC\n\
	cmp r0, #0x12\n\
	beq _080A02C0\n\
	b _080A02FE\n\
	.align 2, 0\n\
_080A02B8: .4byte gNonGameplayRam\n\
_080A02BC:\n\
	cmp r0, #0x1a\n\
	bne _080A02FE\n\
_080A02C0:\n\
	ldr r0, _080A02D8 @ =0x000001FD\n\
	bl SoundPlay\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
	ldr r0, _080A02DC @ =0x087409B0\n\
	str r0, [r4, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r4, #9]\n\
	b _080A02FE\n\
	.align 2, 0\n\
_080A02D8: .4byte 0x000001FD\n\
_080A02DC: .4byte 0x087409B0\n\
_080A02E0:\n\
	cmp r2, #2\n\
	bne _080A02FE\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _080A02FE\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080A02FE\n\
	strb r1, [r4, #4]\n\
	strb r1, [r4, #5]\n\
_080A02FE:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x080A0304
NAKED_FUNCTION
void FileSelectProcessEraseFilePanel(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r2, [r4, #9]\n\
	cmp r2, #0\n\
	bne _080A0338\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r4, #7]\n\
	cmp r0, r3\n\
	bne _080A0396\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #0\n\
	bne _080A0396\n\
	strb r2, [r4, #7]\n\
	strb r2, [r4, #6]\n\
	ldr r0, _080A0334 @ =0x087409A0\n\
	str r0, [r4, #0x14]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _080A0396\n\
	.align 2, 0\n\
_080A0334: .4byte 0x087409A0\n\
_080A0338:\n\
	cmp r2, #1\n\
	bne _080A0378\n\
	ldr r0, _080A0350 @ =gNonGameplayRam\n\
	movs r1, #0xa\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0x1f\n\
	beq _080A0358\n\
	cmp r0, #0x1f\n\
	bgt _080A0354\n\
	cmp r0, #0x1d\n\
	beq _080A0358\n\
	b _080A0396\n\
	.align 2, 0\n\
_080A0350: .4byte gNonGameplayRam\n\
_080A0354:\n\
	cmp r0, #0x21\n\
	bne _080A0396\n\
_080A0358:\n\
	ldr r0, _080A0370 @ =0x000001FD\n\
	bl SoundPlay\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
	ldr r0, _080A0374 @ =0x087409B0\n\
	str r0, [r4, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r4, #9]\n\
	b _080A0396\n\
	.align 2, 0\n\
_080A0370: .4byte 0x000001FD\n\
_080A0374: .4byte 0x087409B0\n\
_080A0378:\n\
	cmp r2, #2\n\
	bne _080A0396\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _080A0396\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080A0396\n\
	strb r1, [r4, #4]\n\
	strb r1, [r4, #5]\n\
_080A0396:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x080A039C
NAKED_FUNCTION
void unk_a039c(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r2, [r4, #9]\n\
	cmp r2, #0\n\
	bne _080A03D0\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r4, #7]\n\
	cmp r0, r3\n\
	bne _080A041E\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #0\n\
	bne _080A041E\n\
	strb r2, [r4, #7]\n\
	strb r2, [r4, #6]\n\
	ldr r0, _080A03CC @ =0x087409A0\n\
	str r0, [r4, #0x14]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _080A041E\n\
	.align 2, 0\n\
_080A03CC: .4byte 0x087409A0\n\
_080A03D0:\n\
	cmp r2, #1\n\
	bne _080A0400\n\
	ldr r0, _080A03F4 @ =gNonGameplayRam\n\
	movs r1, #0xa\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, #0xb\n\
	bne _080A041E\n\
	ldr r0, _080A03F8 @ =0x000001FD\n\
	bl SoundPlay\n\
	movs r0, #0\n\
	strb r0, [r4, #7]\n\
	strb r0, [r4, #6]\n\
	ldr r0, _080A03FC @ =0x087409B0\n\
	str r0, [r4, #0x14]\n\
	movs r0, #2\n\
	strb r0, [r4, #9]\n\
	b _080A041E\n\
	.align 2, 0\n\
_080A03F4: .4byte gNonGameplayRam\n\
_080A03F8: .4byte 0x000001FD\n\
_080A03FC: .4byte 0x087409B0\n\
_080A0400:\n\
	cmp r2, #2\n\
	bne _080A041E\n\
	ldrb r0, [r4, #6]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x14]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r2, [r4, #7]\n\
	cmp r0, r2\n\
	bne _080A041E\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080A041E\n\
	strb r1, [r4, #4]\n\
	strb r1, [r4, #5]\n\
_080A041E:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
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

// 0x080A0518
NAKED_FUNCTION
void unk_a0518(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
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
u8 FileSelectProcessCorruptedFile(void)
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

// 0x080A1008
NAKED_FUNCTION
void FileSelectDestroyOamOfType(u8 type)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	movs r2, #0\n\
	ldr r5, _080A1028 @ =gNonGameplayRam\n\
	movs r3, #0\n\
_080A1014:\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r5\n\
	ldrb r0, [r1, #0x1c]\n\
	cmp r0, r4\n\
	bne _080A102C\n\
	strb r3, [r1, #0x1c]\n\
	strb r3, [r1, #0x1d]\n\
	b _080A1036\n\
	.align 2, 0\n\
_080A1028: .4byte gNonGameplayRam\n\
_080A102C:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0x16\n\
	bls _080A1014\n\
_080A1036:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x080A103C
NAKED_FUNCTION
void FileSelectSetUpAreaNameOam(u8 type, s16 xPosition, s16 yPosition, s16 area)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r3, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r4, r4, #0x10\n\
	lsrs r4, r4, #0x10\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #1\n\
	bl FileSelectSetupOam\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	lsls r4, r4, #0x10\n\
	asrs r0, r4, #0x10\n\
	cmp r0, #6\n\
	bls _080A1064\n\
	b _080A1198\n\
_080A1064:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080A1070 @ =_080A1074\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080A1070: .4byte _080A1074\n\
_080A1074: @ jump table\n\
	.4byte _080A1198 @ case 0\n\
	.4byte _080A1090 @ case 1\n\
	.4byte _080A10BC @ case 2\n\
	.4byte _080A10E8 @ case 3\n\
	.4byte _080A1114 @ case 4\n\
	.4byte _080A1140 @ case 5\n\
	.4byte _080A116C @ case 6\n\
_080A1090:\n\
	ldr r0, _080A10B0 @ =gNonGameplayRam\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #2\n\
	adds r0, #0x2c\n\
	adds r1, r1, r0\n\
	ldr r3, _080A10B4 @ =0x0879E944\n\
	ldr r0, _080A10B8 @ =0x03000011\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r3, #4\n\
	b _080A11B2\n\
	.align 2, 0\n\
_080A10B0: .4byte gNonGameplayRam\n\
_080A10B4: .4byte 0x0879E944\n\
_080A10B8: .4byte 0x03000011\n\
_080A10BC:\n\
	ldr r0, _080A10DC @ =gNonGameplayRam\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #2\n\
	adds r0, #0x2c\n\
	adds r1, r1, r0\n\
	ldr r3, _080A10E0 @ =0x0879E944\n\
	ldr r0, _080A10E4 @ =0x03000011\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r3, #8\n\
	b _080A11B2\n\
	.align 2, 0\n\
_080A10DC: .4byte gNonGameplayRam\n\
_080A10E0: .4byte 0x0879E944\n\
_080A10E4: .4byte 0x03000011\n\
_080A10E8:\n\
	ldr r0, _080A1108 @ =gNonGameplayRam\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #2\n\
	adds r0, #0x2c\n\
	adds r1, r1, r0\n\
	ldr r3, _080A110C @ =0x0879E944\n\
	ldr r0, _080A1110 @ =0x03000011\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r3, #0xc\n\
	b _080A11B2\n\
	.align 2, 0\n\
_080A1108: .4byte gNonGameplayRam\n\
_080A110C: .4byte 0x0879E944\n\
_080A1110: .4byte 0x03000011\n\
_080A1114:\n\
	ldr r0, _080A1134 @ =gNonGameplayRam\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #2\n\
	adds r0, #0x2c\n\
	adds r1, r1, r0\n\
	ldr r3, _080A1138 @ =0x0879E944\n\
	ldr r0, _080A113C @ =0x03000011\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r3, #0x10\n\
	b _080A11B2\n\
	.align 2, 0\n\
_080A1134: .4byte gNonGameplayRam\n\
_080A1138: .4byte 0x0879E944\n\
_080A113C: .4byte 0x03000011\n\
_080A1140:\n\
	ldr r0, _080A1160 @ =gNonGameplayRam\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #2\n\
	adds r0, #0x2c\n\
	adds r1, r1, r0\n\
	ldr r3, _080A1164 @ =0x0879E944\n\
	ldr r0, _080A1168 @ =0x03000011\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r3, #0x14\n\
	b _080A11B2\n\
	.align 2, 0\n\
_080A1160: .4byte gNonGameplayRam\n\
_080A1164: .4byte 0x0879E944\n\
_080A1168: .4byte 0x03000011\n\
_080A116C:\n\
	ldr r0, _080A118C @ =gNonGameplayRam\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #2\n\
	adds r0, #0x2c\n\
	adds r1, r1, r0\n\
	ldr r3, _080A1190 @ =0x0879E944\n\
	ldr r0, _080A1194 @ =0x03000011\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r3, #0x18\n\
	b _080A11B2\n\
	.align 2, 0\n\
_080A118C: .4byte gNonGameplayRam\n\
_080A1190: .4byte 0x0879E944\n\
_080A1194: .4byte 0x03000011\n\
_080A1198:\n\
	ldr r0, _080A11C0 @ =gNonGameplayRam\n\
	lsls r1, r2, #3\n\
	subs r1, r1, r2\n\
	lsls r1, r1, #2\n\
	adds r0, #0x2c\n\
	adds r1, r1, r0\n\
	ldr r3, _080A11C4 @ =0x0879E944\n\
	ldr r0, _080A11C8 @ =0x03000011\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	lsls r0, r2, #3\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #2\n\
_080A11B2:\n\
	adds r0, r0, r3\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A11C0: .4byte gNonGameplayRam\n\
_080A11C4: .4byte 0x0879E944\n\
_080A11C8: .4byte 0x03000011\n\
    .syntax divided\n");
}

// 0x080A11CC
NAKED_FUNCTION
void FileSelectProcessOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r4, #0\n\
	ldr r5, _080A1204 @ =gNonGameplayRam\n\
	adds r6, r5, #0\n\
	adds r6, #0x18\n\
_080A11D6:\n\
	lsls r0, r4, #3\n\
	subs r0, r0, r4\n\
	lsls r2, r0, #2\n\
	adds r0, r2, r5\n\
	ldrb r0, [r0, #0x1c]\n\
	cmp r0, #0\n\
	beq _080A11F2\n\
	adds r1, r5, #0\n\
	adds r1, #0x30\n\
	adds r1, r2, r1\n\
	adds r0, r2, r6\n\
	ldr r1, [r1]\n\
	bl _call_via_r1\n\
_080A11F2:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0x16\n\
	bls _080A11D6\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A1204: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x080A1208
NAKED_FUNCTION
void FileSelectDrawAllOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r4, #0\n\
	ldr r5, _080A1240 @ =gNonGameplayRam\n\
	adds r6, r5, #0\n\
	adds r6, #0x18\n\
_080A1212:\n\
	lsls r0, r4, #3\n\
	subs r0, r0, r4\n\
	lsls r1, r0, #2\n\
	adds r0, r1, r5\n\
	ldrb r0, [r0, #0x1d]\n\
	cmp r0, #0\n\
	beq _080A1226\n\
	adds r0, r1, r6\n\
	bl FileSelectDrawOam\n\
_080A1226:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0x16\n\
	bls _080A1212\n\
	bl ResetFreeOam\n\
	ldr r1, _080A1244 @ =gNextOamSlot\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A1240: .4byte gNonGameplayRam\n\
_080A1244: .4byte gNextOamSlot\n\
    .syntax divided\n");
}

// 0x080A1248
NAKED_FUNCTION
void FileSelectDrawOam(struct FileSelectOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r5, r0, #0\n\
	ldr r2, _080A1308 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #3\n\
	ldr r1, _080A130C @ =gOamData\n\
	adds r7, r0, r1\n\
	ldrb r4, [r5, #6]\n\
	lsls r1, r4, #3\n\
	ldr r0, [r5, #0x14]\n\
	adds r3, r0, r1\n\
	ldrb r0, [r3, #4]\n\
	ldrb r2, [r5, #7]\n\
	cmp r0, r2\n\
	bne _080A1278\n\
	adds r0, r4, #1\n\
	movs r1, #0\n\
	strb r0, [r5, #6]\n\
	strb r1, [r5, #7]\n\
	adds r3, #8\n\
_080A1278:\n\
	ldrb r1, [r3, #4]\n\
	cmp r1, #0\n\
	bne _080A1286\n\
	ldrb r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	subs r3, r3, r0\n\
	strb r1, [r5, #6]\n\
_080A1286:\n\
	ldr r6, [r3]\n\
	ldrh r3, [r6]\n\
	mov sl, r3\n\
	adds r6, #2\n\
	movs r4, #0\n\
	mov sb, r4\n\
	cmp sb, sl\n\
	blt _080A1298\n\
	b _080A139C\n\
_080A1298:\n\
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
	ldr r2, _080A1308 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	mov r4, sb\n\
	adds r3, r0, r4\n\
	ldrb r1, [r5, #0xc]\n\
	cmp r1, #1\n\
	bne _080A1318\n\
	lsls r4, r3, #3\n\
	ldr r0, _080A130C @ =gOamData\n\
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
	ldr r2, _080A1310 @ =0x0873DBA4\n\
	adds r1, r1, r2\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #3\n\
	add r0, ip\n\
	ldrh r1, [r5]\n\
	subs r2, r1, r0\n\
	ldr r3, _080A1314 @ =0x000001FF\n\
	ands r2, r3\n\
	ldrh r0, [r5, #2]\n\
	mov r3, r8\n\
	adds r1, r3, r0\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	b _080A132E\n\
	.align 2, 0\n\
_080A1308: .4byte gNextOamSlot\n\
_080A130C: .4byte gOamData\n\
_080A1310: .4byte 0x0873DBA4\n\
_080A1314: .4byte 0x000001FF\n\
_080A1318:\n\
	ldrh r0, [r5, #2]\n\
	mov r4, r8\n\
	adds r1, r4, r0\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	ldrh r0, [r5]\n\
	mov r4, ip\n\
	adds r2, r4, r0\n\
	ldr r0, _080A13B8 @ =0x000001FF\n\
	ands r2, r0\n\
	lsls r4, r3, #3\n\
_080A132E:\n\
	ldr r0, _080A13BC @ =gOamData\n\
	adds r3, r4, r0\n\
	strb r1, [r3]\n\
	ldr r1, _080A13B8 @ =0x000001FF\n\
	ands r2, r1\n\
	ldrh r1, [r3, #2]\n\
	ldr r0, _080A13C0 @ =0xFFFFFE00\n\
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
	ldr r4, _080A13C4 @ =0x000003FF\n\
	adds r0, r4, #0\n\
	ands r1, r0\n\
	ldr r0, _080A13C8 @ =0xFFFFFC00\n\
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
	bge _080A139C\n\
	b _080A1298\n\
_080A139C:\n\
	ldr r2, _080A13CC @ =gNextOamSlot\n\
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
_080A13B8: .4byte 0x000001FF\n\
_080A13BC: .4byte gOamData\n\
_080A13C0: .4byte 0xFFFFFE00\n\
_080A13C4: .4byte 0x000003FF\n\
_080A13C8: .4byte 0xFFFFFC00\n\
_080A13CC: .4byte gNextOamSlot\n\
    .syntax divided\n");
}

// 0x080A13D0
NAKED_FUNCTION
boolu32 SetLanguage(u8 unused)
{
    asm(" .syntax unified\n\
	ldr r1, _080A13DC @ =0x03000011\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	movs r0, #1\n\
	bx lr\n\
	.align 2, 0\n\
_080A13DC: .4byte 0x03000011\n\
    .syntax divided\n");
}

// 0x080A13E0
NAKED_FUNCTION
void unk_a13e0(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	ldr r4, _080A1454 @ =0x04000208\n\
	movs r1, #0\n\
	strh r1, [r4]\n\
	ldr r3, _080A1458 @ =0x04000004\n\
	ldrh r2, [r3]\n\
	ldr r0, _080A145C @ =0x0000FFEF\n\
	ands r0, r2\n\
	strh r0, [r3]\n\
	ldr r3, _080A1460 @ =0x04000200\n\
	ldrh r2, [r3]\n\
	ldr r0, _080A1464 @ =0x0000FFFD\n\
	ands r0, r2\n\
	strh r0, [r3]\n\
	movs r0, #1\n\
	strh r0, [r4]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #0x13\n\
	strh r1, [r3]\n\
	ldr r2, _080A1468 @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r2]\n\
	ldr r0, _080A146C @ =gWrittenToBldy\n\
	movs r2, #0x10\n\
	strh r2, [r0]\n\
	ldr r0, _080A1470 @ =0x04000054\n\
	strh r2, [r0]\n\
	subs r0, #0x46\n\
	strh r1, [r0]\n\
	subs r0, #2\n\
	strh r1, [r0]\n\
	subs r0, #2\n\
	strh r1, [r0]\n\
	subs r0, #2\n\
	strh r1, [r0]\n\
	adds r0, #8\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	strh r1, [r3]\n\
	ldr r0, _080A1474 @ =unk_a1478\n\
	bl CallbackSetVBlank\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A1454: .4byte 0x04000208\n\
_080A1458: .4byte 0x04000004\n\
_080A145C: .4byte 0x0000FFEF\n\
_080A1460: .4byte 0x04000200\n\
_080A1464: .4byte 0x0000FFFD\n\
_080A1468: .4byte 0x04000050\n\
_080A146C: .4byte gWrittenToBldy\n\
_080A1470: .4byte 0x04000054\n\
_080A1474: .4byte unk_a1478\n\
    .syntax divided\n");
}

// 0x080A1478
NAKED_FUNCTION
void unk_a1478(void)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080A147C
NAKED_FUNCTION
boolu32 unk_a147c(void)
{
    asm(" .syntax unified\n\
	movs r0, #1\n\
	bx lr\n\
    .syntax divided\n");
}
