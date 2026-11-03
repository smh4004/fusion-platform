#include "globals.h"
#include "macros.h"

// 0x080809F0
NAKED_FUNCTION
void EraseSramMenuHandler(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r6, #0\n\
	ldr r0, _08080A18 @ =gNonGameplayRam\n\
	ldrh r1, [r0, #4]\n\
	adds r1, #1\n\
	strh r1, [r0, #4]\n\
	ldr r1, _08080A1C @ =gSubGameMode1\n\
	movs r3, #0\n\
	ldrsh r2, [r1, r3]\n\
	adds r3, r0, #0\n\
	adds r5, r1, #0\n\
	cmp r2, #6\n\
	bls _08080A0C\n\
	b _08080AFA\n\
_08080A0C:\n\
	lsls r0, r2, #2\n\
	ldr r1, _08080A20 @ =_08080A24\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08080A18: .4byte gNonGameplayRam\n\
_08080A1C: .4byte gSubGameMode1\n\
_08080A20: .4byte _08080A24\n\
_08080A24: @ jump table\n\
	.4byte _08080A40 @ case 0\n\
	.4byte _08080A50 @ case 1\n\
	.4byte _08080A74 @ case 2\n\
	.4byte _08080AB0 @ case 3\n\
	.4byte _08080ABC @ case 4\n\
	.4byte _08080ACC @ case 5\n\
	.4byte _08080AE2 @ case 6\n\
_08080A40:\n\
	bl EraseSramMenuInit\n\
	ldr r1, _08080A4C @ =gSubGameMode1\n\
	ldrh r0, [r1]\n\
	b _08080AEA\n\
	.align 2, 0\n\
_08080A4C: .4byte gSubGameMode1\n\
_08080A50:\n\
	ldr r4, _08080A60 @ =gWrittenToBldy\n\
	ldrh r1, [r4]\n\
	adds r2, r1, #0\n\
	cmp r2, #0\n\
	beq _08080A64\n\
	subs r0, r1, #1\n\
	strh r0, [r4]\n\
	b _08080AFA\n\
	.align 2, 0\n\
_08080A60: .4byte gWrittenToBldy\n\
_08080A64:\n\
	movs r0, #0xef\n\
	strh r0, [r3, #6]\n\
	strb r1, [r3, #8]\n\
	ldrh r0, [r5]\n\
	adds r0, #1\n\
	strh r0, [r5]\n\
	strh r2, [r3, #4]\n\
	b _08080AFA\n\
_08080A74:\n\
	ldr r4, _08080A98 @ =gSubGameMode2\n\
	bl EraseSramProcessInput\n\
	strb r0, [r4]\n\
	lsls r0, r0, #0x18\n\
	asrs r2, r0, #0x18\n\
	cmp r2, #0\n\
	beq _08080AFA\n\
	ldr r1, _08080A9C @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strh r0, [r1, #4]\n\
	cmp r2, #1\n\
	bne _08080AA4\n\
	ldr r1, _08080AA0 @ =gSubGameMode1\n\
	movs r0, #5\n\
	strh r0, [r1]\n\
	b _08080AFA\n\
	.align 2, 0\n\
_08080A98: .4byte gSubGameMode2\n\
_08080A9C: .4byte gNonGameplayRam\n\
_08080AA0: .4byte gSubGameMode1\n\
_08080AA4:\n\
	ldr r1, _08080AAC @ =gSubGameMode1\n\
	movs r0, #3\n\
	strh r0, [r1]\n\
	b _08080AFA\n\
	.align 2, 0\n\
_08080AAC: .4byte gSubGameMode1\n\
_08080AB0:\n\
	ldrh r0, [r3, #4]\n\
	cmp r0, #0x28\n\
	bls _08080AFA\n\
	movs r1, #0\n\
	movs r0, #0xff\n\
	b _08080AD6\n\
_08080ABC:\n\
	ldr r1, _08080AC8 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bls _08080AEA\n\
	b _08080AF8\n\
	.align 2, 0\n\
_08080AC8: .4byte gWrittenToBldy\n\
_08080ACC:\n\
	ldrh r0, [r3, #4]\n\
	cmp r0, #0x28\n\
	bls _08080AFA\n\
	movs r1, #0\n\
	movs r0, #0xbf\n\
_08080AD6:\n\
	strh r0, [r3, #6]\n\
	strh r1, [r3, #4]\n\
	ldrh r0, [r5]\n\
	adds r0, #1\n\
	strh r0, [r5]\n\
	b _08080AFA\n\
_08080AE2:\n\
	ldr r1, _08080AF0 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _08080AF4\n\
_08080AEA:\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _08080AFA\n\
	.align 2, 0\n\
_08080AF0: .4byte gWrittenToBldy\n\
_08080AF4:\n\
	bl EraseSram\n\
_08080AF8:\n\
	movs r6, #1\n\
_08080AFA:\n\
	bl EraseSramProcessOam\n\
	bl ResetFreeOam\n\
	adds r0, r6, #0\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08080B0C
NAKED_FUNCTION
void EraseSramProcessInput(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	movs r4, #0\n\
	ldr r0, _08080B24 @ =gNonGameplayRam\n\
	ldrb r1, [r0, #1]\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08080B28\n\
	bl EraseSramApplyInput\n\
	b _08080B2E\n\
	.align 2, 0\n\
_08080B24: .4byte gNonGameplayRam\n\
_08080B28:\n\
	bl EraseSramCheckForInput\n\
	adds r4, r0, #0\n\
_08080B2E:\n\
	ldr r0, _08080B44 @ =gNonGameplayRam\n\
	ldr r3, _08080B48 @ =gWrittenToBldy\n\
	ldrh r1, [r3]\n\
	ldrb r2, [r0, #8]\n\
	adds r0, r1, #0\n\
	cmp r2, r0\n\
	beq _08080B50\n\
	cmp r2, r0\n\
	bls _08080B4C\n\
	adds r0, r1, #1\n\
	b _08080B4E\n\
	.align 2, 0\n\
_08080B44: .4byte gNonGameplayRam\n\
_08080B48: .4byte gWrittenToBldy\n\
_08080B4C:\n\
	subs r0, r1, #1\n\
_08080B4E:\n\
	strh r0, [r3]\n\
_08080B50:\n\
	bl EraseSramUpdateCursorPosition\n\
	adds r0, r4, #0\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

// 0x08080B5C
NAKED_FUNCTION
void EraseSramApplyInput(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r1, _08080B84 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x16]\n\
	adds r2, r1, #0\n\
	cmp r0, #2\n\
	beq _08080BE2\n\
	ldrb r1, [r2, #1]\n\
	movs r0, #0x7f\n\
	ands r0, r1\n\
	movs r3, #0\n\
	strb r0, [r2, #1]\n\
	strb r0, [r2]\n\
	ldrb r0, [r2, #1]\n\
	cmp r0, #1\n\
	beq _08080B9C\n\
	cmp r0, #1\n\
	bgt _08080B88\n\
	cmp r0, #0\n\
	beq _08080B92\n\
	b _08080BC6\n\
	.align 2, 0\n\
_08080B84: .4byte gNonGameplayRam\n\
_08080B88:\n\
	cmp r0, #2\n\
	beq _08080BB4\n\
	cmp r0, #3\n\
	beq _08080BBC\n\
	b _08080BC6\n\
_08080B92:\n\
	ldr r0, _08080B98 @ =0x0858B3B0\n\
	b _08080B9E\n\
	.align 2, 0\n\
_08080B98: .4byte sBlob_5822f0_58b3cc + 0x90c0\n\
_08080B9C:\n\
	ldr r0, _08080BB0 @ =0x0858B3B1\n\
_08080B9E:\n\
	ldrb r0, [r0]\n\
	adds r1, r2, #0\n\
	adds r1, #0x2e\n\
	strb r0, [r1]\n\
	adds r0, r2, #0\n\
	adds r0, #0x22\n\
	strb r3, [r0]\n\
	b _08080BC6\n\
	.align 2, 0\n\
_08080BB0: .4byte sBlob_5822f0_58b3cc + 0x90c1\n\
_08080BB4:\n\
	ldr r0, _08080BB8 @ =0x0858B3B2\n\
	b _08080BBE\n\
	.align 2, 0\n\
_08080BB8: .4byte sBlob_5822f0_58b3cc + 0x90c2\n\
_08080BBC:\n\
	ldr r0, _08080BE8 @ =0x0858B3B3\n\
_08080BBE:\n\
	ldrb r0, [r0]\n\
	adds r1, r2, #0\n\
	adds r1, #0x22\n\
	strb r0, [r1]\n\
_08080BC6:\n\
	adds r0, r2, #0\n\
	adds r0, #0x20\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r1, [r0]\n\
	adds r0, #0xb\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x16]\n\
	strb r1, [r2, #0x14]\n\
	strb r1, [r2, #0x15]\n\
_08080BE2:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080BE8: .4byte sBlob_5822f0_58b3cc + 0x90c3\n\
    .syntax divided\n");
}

// 0x08080BEC
NAKED_FUNCTION
void EraseSramCheckForInput(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	movs r4, #0\n\
	ldr r0, _08080C08 @ =gNonGameplayRam\n\
	ldrb r1, [r0]\n\
	adds r3, r0, #0\n\
	cmp r1, #1\n\
	beq _08080C3A\n\
	cmp r1, #1\n\
	bgt _08080C0C\n\
	cmp r1, #0\n\
	beq _08080C16\n\
	b _08080CCA\n\
	.align 2, 0\n\
_08080C08: .4byte gNonGameplayRam\n\
_08080C0C:\n\
	cmp r1, #2\n\
	beq _08080C62\n\
	cmp r1, #3\n\
	beq _08080C94\n\
	b _08080CCA\n\
_08080C16:\n\
	ldr r0, _08080C28 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08080C2C\n\
	movs r0, #0x81\n\
	b _08080CA2\n\
	.align 2, 0\n\
_08080C28: .4byte gChangedInput\n\
_08080C2C:\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08080CCA\n\
	movs r5, #2\n\
	movs r4, #1\n\
	b _08080CD0\n\
_08080C3A:\n\
	ldr r0, _08080C4C @ =gChangedInput\n\
	ldrh r2, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _08080C50\n\
	movs r0, #0x80\n\
	b _08080CA2\n\
	.align 2, 0\n\
_08080C4C: .4byte gChangedInput\n\
_08080C50:\n\
	ands r1, r2\n\
	cmp r1, #0\n\
	beq _08080CCA\n\
	movs r0, #0x82\n\
	strb r0, [r3, #1]\n\
	movs r4, #1\n\
	movs r0, #4\n\
	strb r0, [r3, #8]\n\
	b _08080CCA\n\
_08080C62:\n\
	ldr r0, _08080C74 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08080C78\n\
	movs r0, #0x83\n\
	b _08080CA2\n\
	.align 2, 0\n\
_08080C74: .4byte gChangedInput\n\
_08080C78:\n\
	movs r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08080CCA\n\
	movs r0, #0x80\n\
	strb r0, [r3, #1]\n\
	strb r5, [r3, #8]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	movs r4, #3\n\
	cmp r0, #0\n\
	beq _08080CCA\n\
	movs r4, #1\n\
	b _08080CCA\n\
_08080C94:\n\
	ldr r0, _08080CA8 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08080CAC\n\
	movs r0, #0x82\n\
_08080CA2:\n\
	strb r0, [r3, #1]\n\
	movs r4, #4\n\
	b _08080CCA\n\
	.align 2, 0\n\
_08080CA8: .4byte gChangedInput\n\
_08080CAC:\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08080CBA\n\
	movs r5, #1\n\
	movs r4, #2\n\
	b _08080CD0\n\
_08080CBA:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08080CCA\n\
	movs r0, #0x80\n\
	strb r0, [r3, #1]\n\
	movs r4, #3\n\
	strb r5, [r3, #8]\n\
_08080CCA:\n\
	movs r0, #0\n\
	cmp r0, #0\n\
	beq _08080CDA\n\
_08080CD0:\n\
	movs r1, #0\n\
	movs r0, #2\n\
	strb r0, [r3, #0x16]\n\
	strb r1, [r3, #0x14]\n\
	strb r1, [r3, #0x15]\n\
_08080CDA:\n\
	ldr r0, _08080CF4 @ =0x0858B3B4\n\
	lsls r1, r4, #1\n\
	adds r1, r1, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _08080CEA\n\
	bl SoundPlay\n\
_08080CEA:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08080CF4: .4byte sBlob_5822f0_58b3cc + 0x90c4\n\
    .syntax divided\n");
}

// 0x08080CF8
NAKED_FUNCTION
void EraseSramMenuInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #4\n\
	ldr r3, _08080E4C @ =0x04000208\n\
	movs r5, #0\n\
	strh r5, [r3]\n\
	ldr r2, _08080E50 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _08080E54 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _08080E58 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _08080E5C @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _08080E60 @ =EraseSramLoadingVBlank\n\
	bl CallbackSetVBlank\n\
	ldr r1, _08080E64 @ =0x04000050\n\
	movs r0, #0xbf\n\
	strh r0, [r1]\n\
	ldr r0, _08080E68 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _08080E6C @ =0x04000054\n\
	strh r1, [r0]\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r1, _08080E70 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	ldr r4, _08080E74 @ =gNonGameplayRam\n\
	str r4, [r1, #4]\n\
	ldr r0, _08080E78 @ =0x85000150\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	bl ClearGfxRam\n\
	ldr r0, _08080E7C @ =gNextOamSlot\n\
	strb r5, [r0]\n\
	bl ResetFreeOam\n\
	ldr r1, _08080E80 @ =0x03000011\n\
	ldrb r0, [r1]\n\
	strb r0, [r4, #2]\n\
	subs r0, #2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #4\n\
	bls _08080D66\n\
	movs r0, #2\n\
	strb r0, [r4, #2]\n\
	strb r5, [r1]\n\
_08080D66:\n\
	ldr r1, _08080E84 @ =0x04000006\n\
	ldrh r0, [r1]\n\
	subs r0, #0x15\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	ldr r2, _08080E88 @ =0x085823D0\n\
	ldr r3, _08080E8C @ =0x085822F0\n\
	ldr r4, _08080E90 @ =0x0858340C\n\
	cmp r0, #0x8b\n\
	bhi _08080D86\n\
_08080D7A:\n\
	ldrh r0, [r1]\n\
	subs r0, #0x15\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x8b\n\
	bls _08080D7A\n\
_08080D86:\n\
	ldr r0, _08080E70 @ =0x040000D4\n\
	str r2, [r0]\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #0x13\n\
	str r1, [r0, #4]\n\
	ldr r1, _08080E94 @ =0x80000100\n\
	str r1, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	str r3, [r0]\n\
	ldr r1, _08080E98 @ =0x05000200\n\
	str r1, [r0, #4]\n\
	ldr r1, _08080E9C @ =0x80000070\n\
	str r1, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
	ldr r1, _08080EA0 @ =0x06001000\n\
	adds r0, r4, #0\n\
	bl LZ77UncompVram\n\
	ldr r0, _08080EA4 @ =0x08582BBC\n\
	ldr r1, _08080EA8 @ =0x06012000\n\
	bl LZ77UncompVram\n\
	ldr r5, _08080EAC @ =0x0879C228\n\
	ldr r4, _08080E74 @ =gNonGameplayRam\n\
	ldrb r0, [r4, #2]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r5\n\
	ldr r0, [r0]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldrb r0, [r4, #2]\n\
	lsls r0, r0, #3\n\
	adds r1, r5, #4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r1, _08080EB0 @ =0x06011000\n\
	bl LZ77UncompVram\n\
	ldrb r0, [r4, #2]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r5\n\
	ldr r0, [r0]\n\
	ldr r1, _08080EB4 @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08080EB8 @ =0x0858ABE4\n\
	ldr r1, _08080EBC @ =0x0600D000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08080EC0 @ =0x0858ADF0\n\
	ldr r1, _08080EC4 @ =0x0600F000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08080EC8 @ =0x04000008\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	adds r0, #4\n\
	strh r1, [r0]\n\
	ldr r2, _08080ECC @ =0x0400000A\n\
	ldr r3, _08080ED0 @ =0x00001A01\n\
	adds r0, r3, #0\n\
	strh r0, [r2]\n\
	adds r2, #4\n\
	ldr r3, _08080ED4 @ =0x00001E03\n\
	adds r0, r3, #0\n\
	strh r0, [r2]\n\
	ldr r0, _08080ED8 @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	ldr r0, _08080EDC @ =0x04000052\n\
	strh r1, [r0]\n\
	ldr r0, _08080EE0 @ =gUnk_3000be3\n\
	strb r1, [r0]\n\
	ldr r0, _08080EE4 @ =gBg1XPosition\n\
	strh r1, [r0]\n\
	ldr r0, _08080EE8 @ =gBg1YPosition\n\
	strh r1, [r0]\n\
	ldr r0, _08080EEC @ =0x03001230\n\
	strh r1, [r0]\n\
	ldr r0, _08080EF0 @ =0x03001232\n\
	strh r1, [r0]\n\
	bl EraseSramResetOam\n\
	bl EraseSramProcessOam\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r2, #0xd0\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08080EF4 @ =EraseSramVBlank\n\
	bl CallbackSetVBlank\n\
	add sp, #4\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080E4C: .4byte 0x04000208\n\
_08080E50: .4byte 0x04000004\n\
_08080E54: .4byte 0x0000FFEF\n\
_08080E58: .4byte 0x04000200\n\
_08080E5C: .4byte 0x0000FFFD\n\
_08080E60: .4byte EraseSramLoadingVBlank\n\
_08080E64: .4byte 0x04000050\n\
_08080E68: .4byte gWrittenToBldy\n\
_08080E6C: .4byte 0x04000054\n\
_08080E70: .4byte 0x040000D4\n\
_08080E74: .4byte gNonGameplayRam\n\
_08080E78: .4byte 0x85000150\n\
_08080E7C: .4byte gNextOamSlot\n\
_08080E80: .4byte 0x03000011\n\
_08080E84: .4byte 0x04000006\n\
_08080E88: .4byte sBlob_5822f0_58b3cc + 0xe0\n\
_08080E8C: .4byte sBlob_5822f0_58b3cc\n\
_08080E90: .4byte sBlob_5822f0_58b3cc + 0x111c\n\
_08080E94: .4byte 0x80000100\n\
_08080E98: .4byte 0x05000200\n\
_08080E9C: .4byte 0x80000070\n\
_08080EA0: .4byte 0x06001000\n\
_08080EA4: .4byte sBlob_5822f0_58b3cc + 0x8cc\n\
_08080EA8: .4byte 0x06012000\n\
_08080EAC: .4byte sBlob_79c228_79c27c\n\
_08080EB0: .4byte 0x06011000\n\
_08080EB4: .4byte 0x06010000\n\
_08080EB8: .4byte sBlob_5822f0_58b3cc + 0x88f4\n\
_08080EBC: .4byte 0x0600D000\n\
_08080EC0: .4byte sBlob_5822f0_58b3cc + 0x8b00\n\
_08080EC4: .4byte 0x0600F000\n\
_08080EC8: .4byte 0x04000008\n\
_08080ECC: .4byte 0x0400000A\n\
_08080ED0: .4byte 0x00001A01\n\
_08080ED4: .4byte 0x00001E03\n\
_08080ED8: .4byte gWrittenToBldalpha_Evb\n\
_08080EDC: .4byte 0x04000052\n\
_08080EE0: .4byte gUnk_3000be3\n\
_08080EE4: .4byte gBg1XPosition\n\
_08080EE8: .4byte gBg1YPosition\n\
_08080EEC: .4byte 0x03001230\n\
_08080EF0: .4byte 0x03001232\n\
_08080EF4: .4byte EraseSramVBlank\n\
    .syntax divided\n");
}

// 0x08080EF8
NAKED_FUNCTION
void EraseSramResetOam(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r3, _08080F48 @ =gNonGameplayRam\n\
	movs r1, #0\n\
	strb r1, [r3]\n\
	movs r0, #0x80\n\
	strb r0, [r3, #1]\n\
	ldr r0, _08080F4C @ =0x0858B3B0\n\
	ldrb r0, [r0]\n\
	adds r2, r3, #0\n\
	adds r2, #0x2e\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x2c\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r1, [r0]\n\
	ldr r2, _08080F50 @ =0x0858B3BE\n\
	ldrb r0, [r2, #1]\n\
	strh r0, [r3, #0x24]\n\
	ldrb r0, [r2]\n\
	strh r0, [r3, #0x26]\n\
	movs r0, #1\n\
	strb r0, [r3, #0x16]\n\
	strb r1, [r3, #0x14]\n\
	strb r1, [r3, #0x15]\n\
	adds r0, r3, #0\n\
	adds r0, #0x22\n\
	strb r1, [r0]\n\
	subs r0, #2\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r1, [r0]\n\
	ldrb r0, [r2, #3]\n\
	strh r0, [r3, #0x18]\n\
	ldrb r0, [r2, #2]\n\
	strh r0, [r3, #0x1a]\n\
	bl EraseSramUpdateCursorPosition\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080F48: .4byte gNonGameplayRam\n\
_08080F4C: .4byte sBlob_5822f0_58b3cc + 0x90c0\n\
_08080F50: .4byte sBlob_5822f0_58b3cc + 0x90ce\n\
    .syntax divided\n");
}

// 0x08080F54
NAKED_FUNCTION
void EraseSramUpdateCursorPosition(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r4, _08080F94 @ =gNonGameplayRam\n\
	ldr r6, _08080F98 @ =0x0858B3BE\n\
	ldrb r2, [r4]\n\
	lsrs r2, r2, #1\n\
	lsls r2, r2, #1\n\
	adds r3, r6, #1\n\
	adds r3, r2, r3\n\
	ldr r5, _08080F9C @ =0x0858B3C2\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r1, r5, #1\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	ldrb r3, [r3]\n\
	adds r0, r0, r3\n\
	strh r0, [r4, #0xc]\n\
	adds r2, r2, r6\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	ldrb r2, [r2]\n\
	adds r0, r0, r2\n\
	strh r0, [r4, #0xe]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080F94: .4byte gNonGameplayRam\n\
_08080F98: .4byte sBlob_5822f0_58b3cc + 0x90ce\n\
_08080F9C: .4byte sBlob_5822f0_58b3cc + 0x90d2\n\
    .syntax divided\n");
}

// 0x08080FA0
NAKED_FUNCTION
void EraseSramVBlank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r1, _08080FF0 @ =0x040000D4\n\
	ldr r0, _08080FF4 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _08080FF8 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	subs r1, #0x80\n\
	ldr r0, _08080FFC @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x40\n\
	ldr r0, _08081000 @ =gBg1XPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08081004 @ =gBg1YPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #6\n\
	ldr r0, _08081008 @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _0808100C @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r2, _08081010 @ =gNonGameplayRam\n\
	ldrh r1, [r2, #6]\n\
	cmp r1, #0\n\
	beq _08080FEC\n\
	ldr r0, _08081014 @ =0x04000050\n\
	strh r1, [r0]\n\
	movs r0, #0\n\
	strh r0, [r2, #6]\n\
_08080FEC:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080FF0: .4byte 0x040000D4\n\
_08080FF4: .4byte gOamData\n\
_08080FF8: .4byte 0x84000100\n\
_08080FFC: .4byte gWrittenToBldy\n\
_08081000: .4byte gBg1XPosition\n\
_08081004: .4byte gBg1YPosition\n\
_08081008: .4byte 0x03001230\n\
_0808100C: .4byte 0x03001232\n\
_08081010: .4byte gNonGameplayRam\n\
_08081014: .4byte 0x04000050\n\
    .syntax divided\n");
}

// 0x08081018
NAKED_FUNCTION
void EraseSramLoadingVBlank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08081024
NAKED_FUNCTION
void EraseSramProcessOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	ldr r1, _0808114C @ =gNextOamSlot\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r5, _08081150 @ =gOamData\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	movs r6, #0\n\
	movs r4, #0\n\
_08081040:\n\
	lsls r0, r4, #1\n\
	adds r1, r0, r4\n\
	lsls r1, r1, #2\n\
	ldr r2, _08081154 @ =gNonGameplayRam\n\
	adds r3, r1, r2\n\
	ldrb r1, [r3, #0x16]\n\
	adds r2, r0, #0\n\
	adds r0, r4, #1\n\
	mov r8, r0\n\
	cmp r1, #0\n\
	beq _0808112C\n\
	adds r0, r1, #0\n\
	cmp r0, #0\n\
	beq _08081092\n\
	cmp r0, #0\n\
	blt _08081092\n\
	cmp r0, #6\n\
	bgt _08081092\n\
	ldr r1, _08081158 @ =0x0879C260\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r7, [r0]\n\
	ldrb r0, [r3, #0x15]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r7\n\
	ldrb r1, [r3, #0x14]\n\
	ldrb r0, [r0, #4]\n\
	cmp r1, r0\n\
	blo _08081092\n\
	movs r0, #0\n\
	strb r0, [r3, #0x14]\n\
	ldrb r0, [r3, #0x15]\n\
	adds r0, #1\n\
	strb r0, [r3, #0x15]\n\
	ldrb r0, [r3, #0x15]\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r7\n\
	ldrb r0, [r0, #4]\n\
	cmp r0, #0\n\
	bne _08081092\n\
	strb r0, [r3, #0x15]\n\
_08081092:\n\
	adds r2, r2, r4\n\
	lsls r2, r2, #2\n\
	ldr r1, _08081154 @ =gNonGameplayRam\n\
	adds r2, r2, r1\n\
	ldrb r0, [r2, #0x14]\n\
	adds r0, #1\n\
	strb r0, [r2, #0x14]\n\
	ldr r1, _0808115C @ =gBg1YPosition\n\
	ldrh r0, [r2, #0xc]\n\
	ldrh r1, [r1]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	mov sb, r0\n\
	ldr r1, _08081160 @ =gBg1XPosition\n\
	ldrh r0, [r2, #0xe]\n\
	ldrh r1, [r1]\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	ldrb r0, [r2, #0x15]\n\
	lsls r0, r0, #3\n\
	adds r7, r7, r0\n\
	ldr r3, [r7]\n\
	ldrh r0, [r3]\n\
	ldr r2, [sp]\n\
	adds r2, r2, r0\n\
	str r2, [sp]\n\
	adds r3, #2\n\
	adds r4, #1\n\
	mov r8, r4\n\
	cmp r6, r2\n\
	bge _0808112C\n\
	lsls r0, r1, #0x10\n\
	asrs r0, r0, #0x10\n\
	mov ip, r0\n\
	lsls r0, r6, #3\n\
	ldr r1, _08081150 @ =gOamData\n\
	adds r4, r0, r1\n\
	ldr r2, _08081164 @ =0x000001FF\n\
	mov sl, r2\n\
	ldr r0, [sp]\n\
	subs r6, r0, r6\n\
_080810E8:\n\
	ldrh r0, [r3]\n\
	adds r3, #2\n\
	strh r0, [r5]\n\
	adds r5, #2\n\
	add r0, sb\n\
	strb r0, [r4]\n\
	ldrh r1, [r3]\n\
	adds r3, #2\n\
	strh r1, [r5]\n\
	adds r5, #2\n\
	add r1, ip\n\
	mov r2, sl\n\
	ands r1, r2\n\
	ldrh r2, [r4, #2]\n\
	ldr r0, _08081168 @ =0xFFFFFE00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r4, #2]\n\
	ldrh r0, [r3]\n\
	strh r0, [r5]\n\
	adds r3, #2\n\
	ldrb r1, [r4, #5]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r4, #5]\n\
	adds r5, #4\n\
	adds r4, #8\n\
	subs r6, #1\n\
	cmp r6, #0\n\
	bne _080810E8\n\
	ldr r6, [sp]\n\
_0808112C:\n\
	mov r4, r8\n\
	cmp r4, #2\n\
	ble _08081040\n\
	mov r0, sp\n\
	ldrb r1, [r0]\n\
	ldr r0, _0808114C @ =gNextOamSlot\n\
	strb r1, [r0]\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0808114C: .4byte gNextOamSlot\n\
_08081150: .4byte gOamData\n\
_08081154: .4byte gNonGameplayRam\n\
_08081158: .4byte sBlob_79c228_79c27c + 0x38\n\
_0808115C: .4byte gBg1YPosition\n\
_08081160: .4byte gBg1XPosition\n\
_08081164: .4byte 0x000001FF\n\
_08081168: .4byte 0xFFFFFE00\n\
    .syntax divided\n");
}
