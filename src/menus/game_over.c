#include "globals.h"
#include "macros.h"

// 0x0809DEB4
NAKED_FUNCTION
void GameOverHandler(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r4, _0809DECC @ =gSubGameMode1\n\
	movs r1, #0\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #1\n\
	beq _0809DEE4\n\
	cmp r0, #1\n\
	bgt _0809DED0\n\
	cmp r0, #0\n\
	beq _0809DEDA\n\
	b _0809DF4C\n\
	.align 2, 0\n\
_0809DECC: .4byte gSubGameMode1\n\
_0809DED0:\n\
	cmp r0, #2\n\
	beq _0809DF02\n\
	cmp r0, #3\n\
	beq _0809DF1C\n\
	b _0809DF4C\n\
_0809DEDA:\n\
	bl GameOverInit\n\
	movs r0, #1\n\
	strh r0, [r4]\n\
	b _0809DF4C\n\
_0809DEE4:\n\
	bl GameOverDrawAllOam\n\
	ldr r1, _0809DEF4 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _0809DEF8\n\
	subs r0, #1\n\
	b _0809DF4A\n\
	.align 2, 0\n\
_0809DEF4: .4byte gWrittenToBldy\n\
_0809DEF8:\n\
	movs r0, #3\n\
	movs r1, #0\n\
	bl PlayMusic\n\
	b _0809DF10\n\
_0809DF02:\n\
	bl GameOverAfterOptionDelay\n\
	cmp r0, #0\n\
	beq _0809DF4C\n\
	ldr r1, _0809DF18 @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
_0809DF10:\n\
	ldrh r0, [r4]\n\
	adds r0, #1\n\
	strh r0, [r4]\n\
	b _0809DF4C\n\
	.align 2, 0\n\
_0809DF18: .4byte 0x04000050\n\
_0809DF1C:\n\
	bl GameOverDrawAllOam\n\
	ldr r1, _0809DF2C @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _0809DF30\n\
	adds r0, #1\n\
	b _0809DF4A\n\
	.align 2, 0\n\
_0809DF2C: .4byte gWrittenToBldy\n\
_0809DF30:\n\
	ldr r0, _0809DF3C @ =gNonGameplayRam\n\
	ldrb r0, [r0, #3]\n\
	cmp r0, #1\n\
	bne _0809DF40\n\
	movs r5, #1\n\
	b _0809DF46\n\
	.align 2, 0\n\
_0809DF3C: .4byte gNonGameplayRam\n\
_0809DF40:\n\
	cmp r0, #2\n\
	bne _0809DF46\n\
	movs r5, #2\n\
_0809DF46:\n\
	ldr r1, _0809DF54 @ =gSubGameMode1\n\
	movs r0, #0\n\
_0809DF4A:\n\
	strh r0, [r1]\n\
_0809DF4C:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809DF54: .4byte gSubGameMode1\n\
    .syntax divided\n");
}

// 0x0809DF58
NAKED_FUNCTION
void GameOverInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	ldr r3, _0809E0A0 @ =0x04000208\n\
	movs r5, #0\n\
	strh r5, [r3]\n\
	ldr r2, _0809E0A4 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809E0A8 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _0809E0AC @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809E0B0 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _0809E0B4 @ =unk_9e58c\n\
	bl CallbackSetVBlank\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x13\n\
	mov sl, r0\n\
	strh r5, [r0]\n\
	movs r4, #0\n\
	str r4, [sp]\n\
	ldr r7, _0809E0B8 @ =0x040000D4\n\
	mov r1, sp\n\
	str r1, [r7]\n\
	ldr r0, _0809E0BC @ =gNonGameplayRam\n\
	str r0, [r7, #4]\n\
	ldr r0, _0809E0C0 @ =0x85000150\n\
	str r0, [r7, #8]\n\
	ldr r0, [r7, #8]\n\
	ldr r1, _0809E0C4 @ =0x04000050\n\
	movs r0, #0xbf\n\
	strh r0, [r1]\n\
	ldr r0, _0809E0C8 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _0809E0CC @ =0x04000054\n\
	strh r1, [r0]\n\
	ldr r6, _0809E0D0 @ =0x06010000\n\
	str r6, [r7]\n\
	ldr r0, _0809E0D4 @ =0x0201C000\n\
	str r0, [r7, #4]\n\
	ldr r0, _0809E0D8 @ =0x84002000\n\
	str r0, [r7, #8]\n\
	ldr r0, [r7, #8]\n\
	bl ClearGfxRam\n\
	ldr r0, _0809E0DC @ =gNextOamSlot\n\
	strb r5, [r0]\n\
	bl ResetFreeOam\n\
	ldr r0, _0809E0E0 @ =0x0400000E\n\
	mov sb, r0\n\
	strh r4, [r0]\n\
	subs r0, #2\n\
	strh r4, [r0]\n\
	ldr r1, _0809E0E4 @ =0x0400000A\n\
	mov r8, r1\n\
	strh r4, [r1]\n\
	subs r0, #4\n\
	strh r4, [r0]\n\
	adds r0, #8\n\
	strh r4, [r0]\n\
	adds r0, #2\n\
	strh r4, [r0]\n\
	adds r0, #2\n\
	strh r4, [r0]\n\
	adds r0, #2\n\
	strh r4, [r0]\n\
	adds r0, #2\n\
	strh r4, [r0]\n\
	adds r0, #2\n\
	strh r4, [r0]\n\
	adds r0, #2\n\
	strh r4, [r0]\n\
	adds r0, #2\n\
	strh r4, [r0]\n\
	ldr r0, _0809E0E8 @ =0x08739A78\n\
	adds r1, r6, #0\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809E0EC @ =0x0873C4E4\n\
	str r0, [r7]\n\
	ldr r0, _0809E0F0 @ =0x05000200\n\
	str r0, [r7, #4]\n\
	ldr r5, _0809E0F4 @ =0x84000080\n\
	str r5, [r7, #8]\n\
	ldr r0, [r7, #8]\n\
	ldr r0, _0809E0F8 @ =0x0873422C\n\
	movs r4, #0xc0\n\
	lsls r4, r4, #0x13\n\
	adds r1, r4, #0\n\
	bl LZ77UncompVram\n\
	ldr r1, _0809E0FC @ =0x03000011\n\
	movs r0, #0\n\
	ldrsb r0, [r1, r0]\n\
	cmp r0, #1\n\
	ble _0809E042\n\
	ldr r0, _0809E100 @ =0x0879E874\n\
	ldrb r1, [r1]\n\
	lsls r1, r1, #0x18\n\
	asrs r1, r1, #0x18\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	adds r1, r4, #0\n\
	bl LZ77UncompVram\n\
_0809E042:\n\
	ldr r0, _0809E104 @ =0x0873C6E4\n\
	ldr r1, _0809E108 @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809E10C @ =0x0873CCA8\n\
	ldr r1, _0809E110 @ =0x0600F000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809E114 @ =0x0873C2E4\n\
	str r0, [r7]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r7, #4]\n\
	str r5, [r7, #8]\n\
	ldr r0, [r7, #8]\n\
	ldr r1, _0809E118 @ =0x00001E02\n\
	adds r0, r1, #0\n\
	mov r1, r8\n\
	strh r0, [r1]\n\
	ldr r1, _0809E11C @ =0x00001F03\n\
	adds r0, r1, #0\n\
	mov r1, sb\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
	movs r1, #0x2b\n\
	movs r2, #0x6f\n\
	bl GameOverSetupOam\n\
	bl GameOverDrawAllOam\n\
	movs r1, #0xd0\n\
	lsls r1, r1, #5\n\
	adds r0, r1, #0\n\
	mov r1, sl\n\
	strh r0, [r1]\n\
	ldr r0, _0809E120 @ =GameOverVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809E0A0: .4byte 0x04000208\n\
_0809E0A4: .4byte 0x04000004\n\
_0809E0A8: .4byte 0x0000FFEF\n\
_0809E0AC: .4byte 0x04000200\n\
_0809E0B0: .4byte 0x0000FFFD\n\
_0809E0B4: .4byte unk_9e58c\n\
_0809E0B8: .4byte 0x040000D4\n\
_0809E0BC: .4byte gNonGameplayRam\n\
_0809E0C0: .4byte 0x85000150\n\
_0809E0C4: .4byte 0x04000050\n\
_0809E0C8: .4byte gWrittenToBldy\n\
_0809E0CC: .4byte 0x04000054\n\
_0809E0D0: .4byte 0x06010000\n\
_0809E0D4: .4byte 0x0201C000\n\
_0809E0D8: .4byte 0x84002000\n\
_0809E0DC: .4byte gNextOamSlot\n\
_0809E0E0: .4byte 0x0400000E\n\
_0809E0E4: .4byte 0x0400000A\n\
_0809E0E8: .4byte 0x08739A78\n\
_0809E0EC: .4byte 0x0873C4E4\n\
_0809E0F0: .4byte 0x05000200\n\
_0809E0F4: .4byte 0x84000080\n\
_0809E0F8: .4byte 0x0873422C\n\
_0809E0FC: .4byte 0x03000011\n\
_0809E100: .4byte 0x0879E874\n\
_0809E104: .4byte 0x0873C6E4\n\
_0809E108: .4byte 0x0600F800\n\
_0809E10C: .4byte 0x0873CCA8\n\
_0809E110: .4byte 0x0600F000\n\
_0809E114: .4byte 0x0873C2E4\n\
_0809E118: .4byte 0x00001E02\n\
_0809E11C: .4byte 0x00001F03\n\
_0809E120: .4byte GameOverVblank\n\
    .syntax divided\n");
}

// 0x0809E124
NAKED_FUNCTION
void GameOverAfterOptionDelay(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	movs r4, #0\n\
	bl GameOverProcessOam\n\
	bl GameOverDrawAllOam\n\
	ldr r1, _0809E154 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #1]\n\
	cmp r0, #1\n\
	bne _0809E14A\n\
	ldrb r0, [r1, #2]\n\
	adds r0, #1\n\
	strb r0, [r1, #2]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x1e\n\
	bne _0809E14A\n\
	strb r4, [r1, #2]\n\
	movs r4, #1\n\
_0809E14A:\n\
	adds r0, r4, #0\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809E154: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809E158
NAKED_FUNCTION
void GameOverSetupOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r7, r1, #0x10\n\
	lsls r2, r2, #0x10\n\
	lsrs r6, r2, #0x10\n\
	movs r4, #0\n\
	ldr r1, _0809E190 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #8]\n\
	cmp r0, #0\n\
	beq _0809E188\n\
_0809E170:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #2\n\
	bhi _0809E18C\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0, #8]\n\
	cmp r0, #0\n\
	bne _0809E170\n\
_0809E188:\n\
	cmp r4, #2\n\
	bls _0809E194\n\
_0809E18C:\n\
	movs r0, #3\n\
	b _0809E1F6\n\
	.align 2, 0\n\
_0809E190: .4byte gNonGameplayRam\n\
_0809E194:\n\
	adds r0, r4, #0\n\
	bl GameOverResetOam\n\
	ldr r3, _0809E1CC @ =gNonGameplayRam\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r4\n\
	lsls r2, r0, #3\n\
	adds r1, r2, r3\n\
	strh r7, [r1, #4]\n\
	strh r6, [r1, #6]\n\
	strb r5, [r1, #8]\n\
	movs r0, #1\n\
	strb r0, [r1, #9]\n\
	cmp r5, #1\n\
	bne _0809E1D8\n\
	movs r0, #3\n\
	strb r0, [r1, #0xf]\n\
	adds r0, r3, #0\n\
	adds r0, #0x14\n\
	adds r0, r2, r0\n\
	ldr r1, _0809E1D0 @ =0x0879E868\n\
	ldr r1, [r1]\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x18\n\
	adds r0, r2, r0\n\
	ldr r1, _0809E1D4 @ =GameOverProcessCursor\n\
	b _0809E1F2\n\
	.align 2, 0\n\
_0809E1CC: .4byte gNonGameplayRam\n\
_0809E1D0: .4byte 0x0879E868\n\
_0809E1D4: .4byte GameOverProcessCursor\n\
_0809E1D8:\n\
	cmp r5, #2\n\
	bne _0809E1F4\n\
	movs r0, #3\n\
	strb r0, [r1, #0xf]\n\
	adds r0, r3, #0\n\
	adds r0, #0x14\n\
	adds r0, r2, r0\n\
	ldr r1, _0809E1FC @ =0x0873C274\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x18\n\
	adds r0, r2, r0\n\
	ldr r1, _0809E200 @ =unk_9e2cc\n\
_0809E1F2:\n\
	str r1, [r0]\n\
_0809E1F4:\n\
	adds r0, r4, #0\n\
_0809E1F6:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809E1FC: .4byte 0x0873C274\n\
_0809E200: .4byte unk_9e2cc\n\
    .syntax divided\n");
}

// 0x0809E204
NAKED_FUNCTION
void GameOverProcessCursor(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #9]\n\
	cmp r0, #0\n\
	bne _0809E2BC\n\
	ldr r0, _0809E230 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809E238\n\
	movs r1, #2\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #0x6f\n\
	beq _0809E252\n\
	movs r0, #0x6f\n\
	strh r0, [r4, #2]\n\
	ldr r0, _0809E234 @ =0x000001F9\n\
	bl SoundPlay\n\
	b _0809E252\n\
	.align 2, 0\n\
_0809E230: .4byte gChangedInput\n\
_0809E234: .4byte 0x000001F9\n\
_0809E238:\n\
	movs r0, #0x80\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809E252\n\
	movs r1, #2\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #0x88\n\
	beq _0809E252\n\
	movs r0, #0x88\n\
	strh r0, [r4, #2]\n\
	ldr r0, _0809E280 @ =0x000001F9\n\
	bl SoundPlay\n\
_0809E252:\n\
	ldr r0, _0809E284 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #9\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809E2BC\n\
	movs r1, #2\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #0x6f\n\
	bne _0809E290\n\
	movs r0, #0xff\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	movs r0, #0xa\n\
	bl FadeMusic\n\
	ldr r0, _0809E288 @ =0x0879E868\n\
	ldr r0, [r0, #4]\n\
	str r0, [r4, #0x10]\n\
	ldr r1, _0809E28C @ =gNonGameplayRam\n\
	movs r0, #1\n\
	b _0809E2AC\n\
	.align 2, 0\n\
_0809E280: .4byte 0x000001F9\n\
_0809E284: .4byte gChangedInput\n\
_0809E288: .4byte 0x0879E868\n\
_0809E28C: .4byte gNonGameplayRam\n\
_0809E290:\n\
	cmp r0, #0x88\n\
	bne _0809E2AE\n\
	movs r0, #0xff\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	movs r0, #0xa\n\
	bl FadeMusic\n\
	ldr r0, _0809E2C4 @ =0x0879E868\n\
	ldr r0, [r0, #8]\n\
	str r0, [r4, #0x10]\n\
	ldr r1, _0809E2C8 @ =gNonGameplayRam\n\
	movs r0, #2\n\
_0809E2AC:\n\
	strb r0, [r1, #3]\n\
_0809E2AE:\n\
	ldr r0, _0809E2C8 @ =gNonGameplayRam\n\
	movs r1, #0\n\
	movs r2, #1\n\
	strb r2, [r0, #1]\n\
	strb r1, [r4, #6]\n\
	strb r1, [r4, #7]\n\
	strb r2, [r4, #9]\n\
_0809E2BC:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809E2C4: .4byte 0x0879E868\n\
_0809E2C8: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809E2CC
NAKED_FUNCTION
void unk_9e2cc(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #4\n\
	adds r5, r0, #0\n\
	mov r4, sp\n\
	adds r4, #2\n\
	movs r0, #1\n\
	mov r1, sp\n\
	adds r2, r4, #0\n\
	bl GameOverGetPositionAndSlotOfOamByType\n\
	mov r0, sp\n\
	ldrh r0, [r0]\n\
	strh r0, [r5]\n\
	ldrh r0, [r4]\n\
	strh r0, [r5, #2]\n\
	add sp, #4\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809E2F4
NAKED_FUNCTION
void GameOverResetOam(void)
{
    asm(" .syntax unified\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldr r2, _0809E318 @ =gNonGameplayRam\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r2\n\
	movs r0, #0\n\
	strb r0, [r1, #0xa]\n\
	strb r0, [r1, #0xb]\n\
	strb r0, [r1, #0xc]\n\
	strb r0, [r1, #0xd]\n\
	strb r0, [r1, #0xe]\n\
	strb r0, [r1, #0xf]\n\
	strb r0, [r1, #0x10]\n\
	strb r0, [r1, #0x11]\n\
	strh r0, [r1, #0x12]\n\
	bx lr\n\
	.align 2, 0\n\
_0809E318: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809E31C
NAKED_FUNCTION
void GameOverProcessOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r4, #0\n\
	ldr r5, _0809E350 @ =gNonGameplayRam\n\
	adds r6, r5, #4\n\
_0809E324:\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r4\n\
	lsls r2, r0, #3\n\
	adds r0, r2, r5\n\
	ldrb r0, [r0, #8]\n\
	cmp r0, #0\n\
	beq _0809E340\n\
	adds r1, r5, #0\n\
	adds r1, #0x18\n\
	adds r1, r2, r1\n\
	adds r0, r2, r6\n\
	ldr r1, [r1]\n\
	bl _call_via_r1\n\
_0809E340:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #2\n\
	bls _0809E324\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809E350: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809E354
NAKED_FUNCTION
void GameOverDrawAllOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r4, #0\n\
	ldr r5, _0809E38C @ =gNonGameplayRam\n\
	adds r6, r5, #4\n\
_0809E35C:\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r4\n\
	lsls r1, r0, #3\n\
	adds r0, r1, r5\n\
	ldrb r0, [r0, #9]\n\
	cmp r0, #0\n\
	beq _0809E370\n\
	adds r0, r1, r6\n\
	bl GameOverDrawOam\n\
_0809E370:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #2\n\
	bls _0809E35C\n\
	bl ResetFreeOam\n\
	ldr r1, _0809E390 @ =gNextOamSlot\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809E38C: .4byte gNonGameplayRam\n\
_0809E390: .4byte gNextOamSlot\n\
    .syntax divided\n");
}

// 0x0809E394
NAKED_FUNCTION
void GameOverDrawOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r5, r0, #0\n\
	ldr r2, _0809E454 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #3\n\
	ldr r1, _0809E458 @ =gOamData\n\
	adds r7, r0, r1\n\
	ldrb r4, [r5, #6]\n\
	lsls r1, r4, #3\n\
	ldr r0, [r5, #0x10]\n\
	adds r3, r0, r1\n\
	ldrb r0, [r3, #4]\n\
	ldrb r2, [r5, #7]\n\
	cmp r0, r2\n\
	bne _0809E3C4\n\
	adds r0, r4, #1\n\
	movs r1, #0\n\
	strb r0, [r5, #6]\n\
	strb r1, [r5, #7]\n\
	adds r3, #8\n\
_0809E3C4:\n\
	ldrb r1, [r3, #4]\n\
	cmp r1, #0\n\
	bne _0809E3D2\n\
	ldrb r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	subs r3, r3, r0\n\
	strb r1, [r5, #6]\n\
_0809E3D2:\n\
	ldr r6, [r3]\n\
	ldrh r3, [r6]\n\
	mov sl, r3\n\
	adds r6, #2\n\
	movs r4, #0\n\
	mov sb, r4\n\
	cmp sb, sl\n\
	blt _0809E3E4\n\
	b _0809E4E8\n\
_0809E3E4:\n\
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
	ldr r2, _0809E454 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	mov r4, sb\n\
	adds r3, r0, r4\n\
	ldrb r1, [r5, #0xc]\n\
	cmp r1, #1\n\
	bne _0809E464\n\
	lsls r4, r3, #3\n\
	ldr r0, _0809E458 @ =gOamData\n\
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
	ldr r2, _0809E45C @ =0x08734220\n\
	adds r1, r1, r2\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #3\n\
	add r0, ip\n\
	ldrh r1, [r5]\n\
	subs r2, r1, r0\n\
	ldr r3, _0809E460 @ =0x000001FF\n\
	ands r2, r3\n\
	ldrh r0, [r5, #2]\n\
	mov r3, r8\n\
	adds r1, r3, r0\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	b _0809E47A\n\
	.align 2, 0\n\
_0809E454: .4byte gNextOamSlot\n\
_0809E458: .4byte gOamData\n\
_0809E45C: .4byte 0x08734220\n\
_0809E460: .4byte 0x000001FF\n\
_0809E464:\n\
	ldrh r0, [r5, #2]\n\
	mov r4, r8\n\
	adds r1, r4, r0\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	ldrh r0, [r5]\n\
	mov r4, ip\n\
	adds r2, r4, r0\n\
	ldr r0, _0809E504 @ =0x000001FF\n\
	ands r2, r0\n\
	lsls r4, r3, #3\n\
_0809E47A:\n\
	ldr r0, _0809E508 @ =gOamData\n\
	adds r3, r4, r0\n\
	strb r1, [r3]\n\
	ldr r1, _0809E504 @ =0x000001FF\n\
	ands r2, r1\n\
	ldrh r1, [r3, #2]\n\
	ldr r0, _0809E50C @ =0xFFFFFE00\n\
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
	ldr r4, _0809E510 @ =0x000003FF\n\
	adds r0, r4, #0\n\
	ands r1, r0\n\
	ldr r0, _0809E514 @ =0xFFFFFC00\n\
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
	bge _0809E4E8\n\
	b _0809E3E4\n\
_0809E4E8:\n\
	ldr r2, _0809E518 @ =gNextOamSlot\n\
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
_0809E504: .4byte 0x000001FF\n\
_0809E508: .4byte gOamData\n\
_0809E50C: .4byte 0xFFFFFE00\n\
_0809E510: .4byte 0x000003FF\n\
_0809E514: .4byte 0xFFFFFC00\n\
_0809E518: .4byte gNextOamSlot\n\
    .syntax divided\n");
}

// 0x0809E51C
NAKED_FUNCTION
void GameOverGetPositionAndSlotOfOamByType(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r1, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	movs r1, #0\n\
	ldr r6, _0809E540 @ =gNonGameplayRam\n\
_0809E528:\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r3, r0, r6\n\
	ldrb r0, [r3, #8]\n\
	cmp r0, r5\n\
	bne _0809E544\n\
	ldrh r0, [r3, #4]\n\
	strh r0, [r4]\n\
	ldrh r0, [r3, #6]\n\
	b _0809E558\n\
	.align 2, 0\n\
_0809E540: .4byte gNonGameplayRam\n\
_0809E544:\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #2\n\
	bls _0809E528\n\
	movs r1, #0x96\n\
	lsls r1, r1, #1\n\
	adds r0, r1, #0\n\
	strh r0, [r4]\n\
	movs r0, #0xc8\n\
_0809E558:\n\
	strh r0, [r2]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0809E560
NAKED_FUNCTION
void GameOverVblank(void)
{
    asm(" .syntax unified\n\
	ldr r1, _0809E57C @ =0x040000D4\n\
	ldr r0, _0809E580 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809E584 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	subs r1, #0x80\n\
	ldr r0, _0809E588 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_0809E57C: .4byte 0x040000D4\n\
_0809E580: .4byte gOamData\n\
_0809E584: .4byte 0x84000100\n\
_0809E588: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809E58C
NAKED_FUNCTION
void unk_9e58c(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}
