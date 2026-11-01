#include "globals.h"
#include "macros.h"

// 0x0809A9A8
NAKED_FUNCTION
void CutsceneSecretConversation(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r4, _0809A9C0 @ =gNonGameplayRam\n\
	ldrh r0, [r4]\n\
	cmp r0, #1\n\
	beq _0809A9D8\n\
	cmp r0, #1\n\
	bgt _0809A9C4\n\
	cmp r0, #0\n\
	beq _0809A9CE\n\
	b _0809AA20\n\
	.align 2, 0\n\
_0809A9C0: .4byte gNonGameplayRam\n\
_0809A9C4:\n\
	cmp r0, #2\n\
	beq _0809A9F2\n\
	cmp r0, #3\n\
	beq _0809AA12\n\
	b _0809AA20\n\
_0809A9CE:\n\
	movs r0, #1\n\
	strh r0, [r4]\n\
	bl CutsceneSecretConversationInit\n\
	b _0809AA20\n\
_0809A9D8:\n\
	ldr r1, _0809A9E8 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _0809A9EC\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	b _0809AA20\n\
	.align 2, 0\n\
_0809A9E8: .4byte gWrittenToBldy\n\
_0809A9EC:\n\
	movs r0, #2\n\
	strh r0, [r4]\n\
	b _0809AA20\n\
_0809A9F2:\n\
	bl CutsceneSecretConversationProcess\n\
	cmp r0, #0\n\
	beq _0809AA20\n\
	movs r0, #3\n\
	strh r0, [r4]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r2, #0xb0\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x50\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	b _0809AA20\n\
_0809AA12:\n\
	bl CutsceneFadeOut\n\
	ldr r0, _0809AA28 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0x10\n\
	bne _0809AA20\n\
	movs r5, #1\n\
_0809AA20:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809AA28: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809AA2C
NAKED_FUNCTION
void CutsceneSecretConversationInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r3, _0809AAF4 @ =0x04000208\n\
	movs r4, #0\n\
	strh r4, [r3]\n\
	ldr r2, _0809AAF8 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809AAFC @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _0809AB00 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809AB04 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _0809AB08 @ =unk_9ae0c\n\
	bl CallbackSetVBlank\n\
	movs r5, #0x80\n\
	lsls r5, r5, #0x13\n\
	strh r4, [r5]\n\
	ldr r0, _0809AB0C @ =0x0867815C\n\
	ldr r1, _0809AB10 @ =0x06014000\n\
	bl LZ77UncompVram\n\
	ldr r4, _0809AB14 @ =0x040000D4\n\
	ldr r0, _0809AB18 @ =0x086788A8\n\
	str r0, [r4]\n\
	ldr r0, _0809AB1C @ =0x05000300\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809AB20 @ =0x84000010\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809AB24 @ =0x08675098\n\
	ldr r1, _0809AB28 @ =0x06000800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809AB2C @ =0x08677914\n\
	ldr r1, _0809AB30 @ =0x0600C000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809AB34 @ =0x08677C90\n\
	ldr r1, _0809AB38 @ =0x0600C800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809AB3C @ =0x08677874\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809AB40 @ =0x84000028\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809AB44 @ =0x08677C10\n\
	str r0, [r4]\n\
	ldr r0, _0809AB48 @ =0x050001E0\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809AB4C @ =0x84000008\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r0, #1\n\
	movs r1, #0x78\n\
	movs r2, #0x80\n\
	bl CutsceneSecretConversationSetupOam\n\
	movs r0, #2\n\
	movs r1, #0x78\n\
	movs r2, #0x80\n\
	bl CutsceneSecretConversationSetupOam\n\
	movs r0, #3\n\
	movs r1, #0x78\n\
	movs r2, #0x80\n\
	bl CutsceneSecretConversationSetupOam\n\
	ldr r1, _0809AB50 @ =0x0400000A\n\
	ldr r2, _0809AB54 @ =0x00001802\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _0809AB58 @ =0x00001903\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r1, #0xb0\n\
	lsls r1, r1, #5\n\
	adds r0, r1, #0\n\
	strh r0, [r5]\n\
	ldr r1, _0809AB5C @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	bl CutsceneDrawAllOam\n\
	ldr r0, _0809AB60 @ =CutsceneSecretConversationVblank\n\
	bl CallbackSetVBlank\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809AAF4: .4byte 0x04000208\n\
_0809AAF8: .4byte 0x04000004\n\
_0809AAFC: .4byte 0x0000FFEF\n\
_0809AB00: .4byte 0x04000200\n\
_0809AB04: .4byte 0x0000FFFD\n\
_0809AB08: .4byte unk_9ae0c\n\
_0809AB0C: .4byte 0x0867815C\n\
_0809AB10: .4byte 0x06014000\n\
_0809AB14: .4byte 0x040000D4\n\
_0809AB18: .4byte 0x086788A8\n\
_0809AB1C: .4byte 0x05000300\n\
_0809AB20: .4byte 0x84000010\n\
_0809AB24: .4byte 0x08675098\n\
_0809AB28: .4byte 0x06000800\n\
_0809AB2C: .4byte 0x08677914\n\
_0809AB30: .4byte 0x0600C000\n\
_0809AB34: .4byte 0x08677C90\n\
_0809AB38: .4byte 0x0600C800\n\
_0809AB3C: .4byte 0x08677874\n\
_0809AB40: .4byte 0x84000028\n\
_0809AB44: .4byte 0x08677C10\n\
_0809AB48: .4byte 0x050001E0\n\
_0809AB4C: .4byte 0x84000008\n\
_0809AB50: .4byte 0x0400000A\n\
_0809AB54: .4byte 0x00001802\n\
_0809AB58: .4byte 0x00001903\n\
_0809AB5C: .4byte gWrittenToBldy\n\
_0809AB60: .4byte CutsceneSecretConversationVblank\n\
    .syntax divided\n");
}

// 0x0809AB64
NAKED_FUNCTION
void CutsceneSecretConversationProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	movs r4, #0\n\
	ldr r1, _0809AB7C @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x10]\n\
	cmp r0, #1\n\
	beq _0809ABAA\n\
	cmp r0, #1\n\
	bgt _0809AB80\n\
	cmp r0, #0\n\
	beq _0809AB86\n\
	b _0809ABBE\n\
	.align 2, 0\n\
_0809AB7C: .4byte gNonGameplayRam\n\
_0809AB80:\n\
	cmp r0, #2\n\
	beq _0809ABB4\n\
	b _0809ABBE\n\
_0809AB86:\n\
	ldrh r0, [r1, #8]\n\
	adds r0, #1\n\
	strh r0, [r1, #8]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x1d\n\
	bls _0809ABAE\n\
	movs r0, #1\n\
	strb r0, [r1, #0x10]\n\
	strh r4, [r1, #8]\n\
	movs r0, #4\n\
	movs r1, #0x78\n\
	movs r2, #0x44\n\
	bl CutsceneSecretConversationSetupOam\n\
	bl CutsceneProcessOam\n\
	b _0809ABAE\n\
_0809ABAA:\n\
	bl CutsceneProcessOam\n\
_0809ABAE:\n\
	bl CutsceneDrawAllOam\n\
	b _0809ABBE\n\
_0809ABB4:\n\
	bl CutsceneProcessOam\n\
	bl CutsceneDrawAllOam\n\
	movs r4, #1\n\
_0809ABBE:\n\
	adds r0, r4, #0\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809ABC8
NAKED_FUNCTION
void CutsceneSecretConversationSetupOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r7, r1, #0x10\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	movs r5, #0\n\
	ldr r1, _0809ABE0 @ =gNonGameplayRam\n\
	adds r0, r1, #0\n\
	b _0809ABF6\n\
	.align 2, 0\n\
_0809ABE0: .4byte gNonGameplayRam\n\
_0809ABE4:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0xf\n\
	bhi _0809AC02\n\
	lsls r0, r5, #3\n\
	adds r0, r0, r5\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
_0809ABF6:\n\
	adds r0, #0x28\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809ABE4\n\
	cmp r5, #0xf\n\
	bls _0809AC06\n\
_0809AC02:\n\
	movs r0, #0x10\n\
	b _0809ACC2\n\
_0809AC06:\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r1, _0809AC54 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	lsls r0, r5, #3\n\
	adds r0, r0, r5\n\
	lsls r4, r0, #2\n\
	ldr r3, _0809AC58 @ =0x0300149C\n\
	adds r0, r4, r3\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809AC5C @ =0x85000009\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	adds r0, r3, #0\n\
	subs r0, #0x18\n\
	adds r0, r4, r0\n\
	strh r7, [r0, #0x18]\n\
	strh r2, [r0, #0x1a]\n\
	adds r1, r0, #0\n\
	adds r1, #0x28\n\
	strb r6, [r1]\n\
	adds r0, #0x2e\n\
	ldrb r1, [r0]\n\
	movs r2, #1\n\
	orrs r1, r2\n\
	strb r1, [r0]\n\
	cmp r6, #1\n\
	bne _0809AC68\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _0809AC60 @ =0x086793B0\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809AC64 @ =unk_9db70\n\
	b _0809ACBE\n\
	.align 2, 0\n\
_0809AC54: .4byte 0x040000D4\n\
_0809AC58: .4byte 0x0300149C\n\
_0809AC5C: .4byte 0x85000009\n\
_0809AC60: .4byte 0x086793B0\n\
_0809AC64: .4byte unk_9db70\n\
_0809AC68:\n\
	cmp r6, #2\n\
	bne _0809AC88\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _0809AC80 @ =0x08679280\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809AC84 @ =CutsceneSecretConversationProcessNavigationPanel\n\
	b _0809ACBE\n\
	.align 2, 0\n\
_0809AC80: .4byte 0x08679280\n\
_0809AC84: .4byte CutsceneSecretConversationProcessNavigationPanel\n\
_0809AC88:\n\
	cmp r6, #3\n\
	bne _0809ACA8\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _0809ACA0 @ =0x086793A0\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809ACA4 @ =unk_9db70\n\
	b _0809ACBE\n\
	.align 2, 0\n\
_0809ACA0: .4byte 0x086793A0\n\
_0809ACA4: .4byte unk_9db70\n\
_0809ACA8:\n\
	cmp r6, #4\n\
	bne _0809ACC0\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _0809ACCC @ =0x086792D0\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809ACD0 @ =CutsceneSecretConversationProcessIncomingDispatch\n\
_0809ACBE:\n\
	str r1, [r0]\n\
_0809ACC0:\n\
	adds r0, r5, #0\n\
_0809ACC2:\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809ACCC: .4byte 0x086792D0\n\
_0809ACD0: .4byte CutsceneSecretConversationProcessIncomingDispatch\n\
    .syntax divided\n");
}

// 0x0809ACD4
NAKED_FUNCTION
void CutsceneSecretConversationProcessNavigationPanel(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r1, [r2, #0x14]\n\
	cmp r1, #0\n\
	bne _0809ACEA\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
	strb r1, [r2, #0x12]\n\
	strb r1, [r2, #0x11]\n\
	ldr r0, _0809ACF0 @ =0x086792A8\n\
	str r0, [r2, #0x1c]\n\
_0809ACEA:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809ACF0: .4byte 0x086792A8\n\
    .syntax divided\n");
}

// 0x0809ACF4
NAKED_FUNCTION
void CutsceneSecretConversationProcessIncomingDispatch(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #0x14]\n\
	cmp r5, #0\n\
	bne _0809AD3C\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x1c]\n\
	adds r6, r1, r0\n\
	ldrb r0, [r4, #0x13]\n\
	cmp r0, #0\n\
	bne _0809AD16\n\
	ldr r0, _0809AD34 @ =0x0000022F\n\
	bl SoundPlay\n\
	movs r0, #1\n\
	strb r0, [r4, #0x13]\n\
_0809AD16:\n\
	ldrb r0, [r6, #4]\n\
	ldrb r1, [r4, #0x12]\n\
	cmp r0, r1\n\
	bne _0809AD5A\n\
	ldrb r0, [r6, #0xc]\n\
	cmp r0, #0\n\
	bne _0809AD5A\n\
	movs r0, #1\n\
	strb r0, [r4, #0x14]\n\
	strb r5, [r4, #0x13]\n\
	strb r5, [r4, #0x12]\n\
	strb r5, [r4, #0x11]\n\
	ldr r0, _0809AD38 @ =0x08679350\n\
	str r0, [r4, #0x1c]\n\
	b _0809AD5A\n\
	.align 2, 0\n\
_0809AD34: .4byte 0x0000022F\n\
_0809AD38: .4byte 0x08679350\n\
_0809AD3C:\n\
	cmp r5, #1\n\
	bne _0809AD5A\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xb4\n\
	bne _0809AD5A\n\
	movs r0, #2\n\
	strb r0, [r4, #0x14]\n\
	movs r1, #0\n\
	strb r1, [r4, #0x13]\n\
	ldr r1, _0809AD60 @ =gNonGameplayRam\n\
	strb r0, [r1, #0x10]\n\
_0809AD5A:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809AD60: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809AD64
NAKED_FUNCTION
void CutsceneSecretConversationVblank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r2, _0809AD98 @ =0x040000D4\n\
	ldr r0, _0809AD9C @ =gOamData\n\
	str r0, [r2]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r2, #4]\n\
	ldr r0, _0809ADA0 @ =0x84000100\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	ldr r1, _0809ADA4 @ =0x04000054\n\
	ldr r0, _0809ADA8 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0809ADAC @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x11]\n\
	adds r0, #1\n\
	strb r0, [r1, #0x11]\n\
	ldrb r0, [r1, #0x11]\n\
	cmp r0, #0xe\n\
	beq _0809ADC4\n\
	cmp r0, #0xe\n\
	bgt _0809ADB0\n\
	cmp r0, #7\n\
	beq _0809ADBA\n\
	b _0809ADFA\n\
	.align 2, 0\n\
_0809AD98: .4byte 0x040000D4\n\
_0809AD9C: .4byte gOamData\n\
_0809ADA0: .4byte 0x84000100\n\
_0809ADA4: .4byte 0x04000054\n\
_0809ADA8: .4byte gWrittenToBldy\n\
_0809ADAC: .4byte gNonGameplayRam\n\
_0809ADB0:\n\
	cmp r0, #0x15\n\
	beq _0809ADCC\n\
	cmp r0, #0x1c\n\
	beq _0809ADE8\n\
	b _0809ADFA\n\
_0809ADBA:\n\
	ldr r0, _0809ADC0 @ =0x08677C30\n\
	b _0809ADCE\n\
	.align 2, 0\n\
_0809ADC0: .4byte 0x08677C30\n\
_0809ADC4:\n\
	ldr r0, _0809ADC8 @ =0x08677C50\n\
	b _0809ADCE\n\
	.align 2, 0\n\
_0809ADC8: .4byte 0x08677C50\n\
_0809ADCC:\n\
	ldr r0, _0809ADDC @ =0x08677C70\n\
_0809ADCE:\n\
	str r0, [r2]\n\
	ldr r0, _0809ADE0 @ =0x050001E0\n\
	str r0, [r2, #4]\n\
	ldr r0, _0809ADE4 @ =0x84000008\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	b _0809ADFA\n\
	.align 2, 0\n\
_0809ADDC: .4byte 0x08677C70\n\
_0809ADE0: .4byte 0x050001E0\n\
_0809ADE4: .4byte 0x84000008\n\
_0809ADE8:\n\
	ldr r0, _0809AE00 @ =0x08677C10\n\
	str r0, [r2]\n\
	ldr r0, _0809AE04 @ =0x050001E0\n\
	str r0, [r2, #4]\n\
	ldr r0, _0809AE08 @ =0x84000008\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	movs r0, #0\n\
	strb r0, [r1, #0x11]\n\
_0809ADFA:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809AE00: .4byte 0x08677C10\n\
_0809AE04: .4byte 0x050001E0\n\
_0809AE08: .4byte 0x84000008\n\
    .syntax divided\n");
}

// 0x0809AE0C
NAKED_FUNCTION
void unk_9ae0c(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}
