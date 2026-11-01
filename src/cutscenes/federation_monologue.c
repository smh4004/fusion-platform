#include "globals.h"
#include "macros.h"

// 0x0809A648
NAKED_FUNCTION
void CutsceneFederationMonologue(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	movs r5, #0\n\
	ldr r4, _0809A664 @ =gNonGameplayRam\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #1\n\
	beq _0809A67E\n\
	cmp r0, #1\n\
	bgt _0809A668\n\
	cmp r0, #0\n\
	beq _0809A672\n\
	b _0809A6BE\n\
	.align 2, 0\n\
_0809A664: .4byte gNonGameplayRam\n\
_0809A668:\n\
	cmp r0, #2\n\
	beq _0809A698\n\
	cmp r0, #3\n\
	beq _0809A6B0\n\
	b _0809A6BE\n\
_0809A672:\n\
	movs r0, #1\n\
	strh r0, [r4, #8]\n\
	adds r0, r1, #0\n\
	bl CutsceneFederationMonologueInit\n\
	b _0809A6BE\n\
_0809A67E:\n\
	bl CutsceneMonologueFadeIn\n\
	ldr r0, _0809A694 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809A6BE\n\
	ldrh r0, [r4, #8]\n\
	adds r0, #1\n\
	strh r0, [r4, #8]\n\
	b _0809A6BE\n\
	.align 2, 0\n\
_0809A694: .4byte gWrittenToBldy\n\
_0809A698:\n\
	bl CutsceneFederationMonologueProcess\n\
	cmp r0, #0\n\
	beq _0809A6BE\n\
	movs r0, #3\n\
	strh r0, [r4, #8]\n\
	ldr r1, _0809A6AC @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	b _0809A6BE\n\
	.align 2, 0\n\
_0809A6AC: .4byte 0x04000050\n\
_0809A6B0:\n\
	bl CutsceneMonologueFadeOut\n\
	ldr r0, _0809A6C8 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0x10\n\
	bne _0809A6BE\n\
	movs r5, #1\n\
_0809A6BE:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809A6C8: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809A6CC
NAKED_FUNCTION
void CutsceneFederationMonologueInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	ldr r3, _0809A7CC @ =0x04000208\n\
	movs r6, #0\n\
	strh r6, [r3]\n\
	ldr r2, _0809A7D0 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809A7D4 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _0809A7D8 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809A7DC @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _0809A7E0 @ =unk_9a99c\n\
	bl CallbackSetVBlank\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x13\n\
	mov r8, r0\n\
	strh r6, [r0]\n\
	ldr r0, _0809A7E4 @ =0x0865FB5C\n\
	ldr r1, _0809A7E8 @ =0x06017C00\n\
	bl LZ77UncompVram\n\
	ldr r4, _0809A7EC @ =0x040000D4\n\
	ldr r0, _0809A7F0 @ =0x086638A0\n\
	str r0, [r4]\n\
	ldr r0, _0809A7F4 @ =0x050003E0\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809A7F8 @ =0x84000008\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809A7FC @ =0x086724C0\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809A800 @ =0x08674AD8\n\
	ldr r1, _0809A804 @ =0x0600D000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809A808 @ =0x08662804\n\
	movs r5, #0x80\n\
	lsls r5, r5, #0x12\n\
	adds r1, r5, #0\n\
	bl LZ77UncompWram\n\
	str r5, [r4]\n\
	ldr r0, _0809A80C @ =0x0600C800\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809A810 @ =0x84000200\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809A814 @ =0x08674958\n\
	str r0, [r4]\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #0x13\n\
	str r1, [r4, #4]\n\
	ldr r0, _0809A818 @ =0x84000060\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809A81C @ =0x08663820\n\
	str r0, [r4]\n\
	ldr r0, _0809A820 @ =0x05000180\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809A824 @ =0x84000020\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	strh r6, [r1]\n\
	ldr r1, _0809A828 @ =0x04000012\n\
	movs r0, #4\n\
	strh r0, [r1]\n\
	subs r1, #0xa\n\
	ldr r2, _0809A82C @ =0x00001908\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #4\n\
	adds r2, #0xfb\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r1, #0xa8\n\
	lsls r1, r1, #5\n\
	adds r0, r1, #0\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
	ldr r1, _0809A830 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
	movs r1, #0xc\n\
	movs r2, #0x10\n\
	bl CutsceneFederationMonologueSetupOam\n\
	ldr r2, _0809A834 @ =gNonGameplayRam\n\
	ldr r0, _0809A838 @ =gCurrentCutscene\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	strh r0, [r2, #0xa]\n\
	ldr r1, _0809A83C @ =0x0879C5A4\n\
	ldr r0, _0809A840 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldrh r1, [r2, #0xa]\n\
	ldr r0, [r0]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r0, [r1]\n\
	str r0, [r2, #0xc]\n\
	bl CutsceneMonologueDrawAllOam\n\
	ldr r0, _0809A844 @ =CutsceneFederationMonologueVblank\n\
	bl CallbackSetVBlank\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809A7CC: .4byte 0x04000208\n\
_0809A7D0: .4byte 0x04000004\n\
_0809A7D4: .4byte 0x0000FFEF\n\
_0809A7D8: .4byte 0x04000200\n\
_0809A7DC: .4byte 0x0000FFFD\n\
_0809A7E0: .4byte unk_9a99c\n\
_0809A7E4: .4byte 0x0865FB5C\n\
_0809A7E8: .4byte 0x06017C00\n\
_0809A7EC: .4byte 0x040000D4\n\
_0809A7F0: .4byte 0x086638A0\n\
_0809A7F4: .4byte 0x050003E0\n\
_0809A7F8: .4byte 0x84000008\n\
_0809A7FC: .4byte 0x086724C0\n\
_0809A800: .4byte 0x08674AD8\n\
_0809A804: .4byte 0x0600D000\n\
_0809A808: .4byte 0x08662804\n\
_0809A80C: .4byte 0x0600C800\n\
_0809A810: .4byte 0x84000200\n\
_0809A814: .4byte 0x08674958\n\
_0809A818: .4byte 0x84000060\n\
_0809A81C: .4byte 0x08663820\n\
_0809A820: .4byte 0x05000180\n\
_0809A824: .4byte 0x84000020\n\
_0809A828: .4byte 0x04000012\n\
_0809A82C: .4byte 0x00001908\n\
_0809A830: .4byte gWrittenToBldy\n\
_0809A834: .4byte gNonGameplayRam\n\
_0809A838: .4byte gCurrentCutscene\n\
_0809A83C: .4byte 0x0879C5A4\n\
_0809A840: .4byte 0x03000011\n\
_0809A844: .4byte CutsceneFederationMonologueVblank\n\
    .syntax divided\n");
}

// 0x0809A848
NAKED_FUNCTION
void CutsceneFederationMonologueProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	bl CutsceneMonologueProcessSpecialTextCharacters\n\
	adds r4, r0, #0\n\
	ldr r1, _0809A860 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x17]\n\
	cmp r0, #0\n\
	beq _0809A864\n\
	cmp r0, #1\n\
	beq _0809A86A\n\
	b _0809A872\n\
	.align 2, 0\n\
_0809A860: .4byte gNonGameplayRam\n\
_0809A864:\n\
	movs r0, #0x64\n\
	strb r0, [r1, #0x17]\n\
	b _0809A872\n\
_0809A86A:\n\
	movs r0, #0x64\n\
	strb r0, [r1, #0x17]\n\
	bl CutsceneMonologueProcessText\n\
_0809A872:\n\
	bl CutsceneMonologueProcessOam\n\
	bl CutsceneMonologueDrawAllOam\n\
	adds r0, r4, #0\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809A884
NAKED_FUNCTION
void CutsceneFederationMonologueSetupOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r7, r1, #0x10\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	mov r8, r2\n\
	movs r4, #0\n\
	ldr r1, _0809A8D0 @ =gNonGameplayRam\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0809A8C6\n\
	adds r3, r1, #0\n\
	adds r1, r2, #0\n\
_0809A8AC:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #4\n\
	bhi _0809A8CA\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809A8AC\n\
_0809A8C6:\n\
	cmp r4, #4\n\
	bls _0809A8D4\n\
_0809A8CA:\n\
	movs r0, #5\n\
	b _0809A93C\n\
	.align 2, 0\n\
_0809A8D0: .4byte gNonGameplayRam\n\
_0809A8D4:\n\
	adds r0, r4, #0\n\
	bl CutsceneMonologueResetOam\n\
	ldr r5, _0809A948 @ =gNonGameplayRam\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r4\n\
	lsls r3, r0, #3\n\
	adds r2, r3, r5\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	strh r7, [r0]\n\
	adds r1, #2\n\
	adds r0, r2, r1\n\
	mov r1, r8\n\
	strh r1, [r0]\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	strb r6, [r0]\n\
	ldr r0, _0809A94C @ =0x00000219\n\
	adds r1, r2, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	cmp r6, #1\n\
	bne _0809A93A\n\
	ldr r0, _0809A950 @ =0x0000021F\n\
	adds r1, r2, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r0, _0809A954 @ =0x00000221\n\
	adds r1, r2, r0\n\
	movs r0, #0xf\n\
	strb r0, [r1]\n\
	ldr r0, _0809A958 @ =0x00000222\n\
	adds r1, r2, r0\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #2\n\
	strh r0, [r1]\n\
	movs r1, #0x89\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	adds r0, r3, r0\n\
	ldr r1, _0809A95C @ =0x08663E5C\n\
	str r1, [r0]\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	adds r0, r3, r0\n\
	ldr r1, _0809A960 @ =CutsceneMonologueProcessCursor\n\
	str r1, [r0]\n\
_0809A93A:\n\
	adds r0, r4, #0\n\
_0809A93C:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809A948: .4byte gNonGameplayRam\n\
_0809A94C: .4byte 0x00000219\n\
_0809A950: .4byte 0x0000021F\n\
_0809A954: .4byte 0x00000221\n\
_0809A958: .4byte 0x00000222\n\
_0809A95C: .4byte 0x08663E5C\n\
_0809A960: .4byte CutsceneMonologueProcessCursor\n\
    .syntax divided\n");
}

// 0x0809A964
NAKED_FUNCTION
void CutsceneFederationMonologueVblank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r1, _0809A988 @ =0x040000D4\n\
	ldr r0, _0809A98C @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809A990 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	bl unk_9cc4c\n\
	ldr r1, _0809A994 @ =0x04000054\n\
	ldr r0, _0809A998 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809A988: .4byte 0x040000D4\n\
_0809A98C: .4byte gOamData\n\
_0809A990: .4byte 0x84000100\n\
_0809A994: .4byte 0x04000054\n\
_0809A998: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809A99C
NAKED_FUNCTION
void unk_9a99c(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}
