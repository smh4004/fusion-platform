#include "globals.h"
#include "macros.h"

// 0x0809A328
NAKED_FUNCTION
void CutsceneInternalMonologue(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	movs r5, #0\n\
	ldr r4, _0809A344 @ =gNonGameplayRam\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #1\n\
	beq _0809A35E\n\
	cmp r0, #1\n\
	bgt _0809A348\n\
	cmp r0, #0\n\
	beq _0809A352\n\
	b _0809A39E\n\
	.align 2, 0\n\
_0809A344: .4byte gNonGameplayRam\n\
_0809A348:\n\
	cmp r0, #2\n\
	beq _0809A378\n\
	cmp r0, #3\n\
	beq _0809A390\n\
	b _0809A39E\n\
_0809A352:\n\
	movs r0, #1\n\
	strh r0, [r4, #8]\n\
	adds r0, r1, #0\n\
	bl CutsceneInternalMonologueInit\n\
	b _0809A39E\n\
_0809A35E:\n\
	bl CutsceneMonologueFadeIn\n\
	ldr r0, _0809A374 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809A39E\n\
	ldrh r0, [r4, #8]\n\
	adds r0, #1\n\
	strh r0, [r4, #8]\n\
	b _0809A39E\n\
	.align 2, 0\n\
_0809A374: .4byte gWrittenToBldy\n\
_0809A378:\n\
	bl CutsceneInternalMonologueProcess\n\
	cmp r0, #0\n\
	beq _0809A39E\n\
	movs r0, #3\n\
	strh r0, [r4, #8]\n\
	ldr r1, _0809A38C @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	b _0809A39E\n\
	.align 2, 0\n\
_0809A38C: .4byte 0x04000050\n\
_0809A390:\n\
	bl CutsceneMonologueFadeOut\n\
	ldr r0, _0809A3A8 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0x10\n\
	bne _0809A39E\n\
	movs r5, #1\n\
_0809A39E:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809A3A8: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809A3AC
NAKED_FUNCTION
void CutsceneInternalMonologueInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	ldr r3, _0809A484 @ =0x04000208\n\
	movs r6, #0\n\
	strh r6, [r3]\n\
	ldr r2, _0809A488 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809A48C @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _0809A490 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809A494 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _0809A498 @ =unk_9a63c\n\
	bl CallbackSetVBlank\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x13\n\
	mov r8, r0\n\
	strh r6, [r0]\n\
	ldr r0, _0809A49C @ =0x0865FB5C\n\
	ldr r1, _0809A4A0 @ =0x06017C00\n\
	bl LZ77UncompVram\n\
	ldr r4, _0809A4A4 @ =0x040000D4\n\
	ldr r0, _0809A4A8 @ =0x086638A0\n\
	str r0, [r4]\n\
	ldr r0, _0809A4AC @ =0x050003E0\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809A4B0 @ =0x84000008\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809A4B4 @ =0x08662804\n\
	movs r5, #0x80\n\
	lsls r5, r5, #0x12\n\
	adds r1, r5, #0\n\
	bl LZ77UncompWram\n\
	str r5, [r4]\n\
	ldr r0, _0809A4B8 @ =0x0600C800\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809A4BC @ =0x84000200\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809A4C0 @ =0x086636A0\n\
	str r0, [r4]\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #0x13\n\
	str r1, [r4, #4]\n\
	ldr r0, _0809A4C4 @ =0x84000080\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	strh r6, [r1]\n\
	ldr r1, _0809A4C8 @ =0x04000012\n\
	movs r0, #4\n\
	strh r0, [r1]\n\
	subs r1, #0xa\n\
	ldr r2, _0809A4CC @ =0x00001908\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r1, #0x88\n\
	lsls r1, r1, #5\n\
	adds r0, r1, #0\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
	ldr r1, _0809A4D0 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
	movs r1, #0xc\n\
	movs r2, #0x10\n\
	bl CutsceneInternalMonologueSetupOam\n\
	ldr r2, _0809A4D4 @ =gNonGameplayRam\n\
	ldr r0, _0809A4D8 @ =gCurrentCutscene\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	strh r0, [r2, #0xa]\n\
	ldr r1, _0809A4DC @ =0x0879C5A4\n\
	ldr r0, _0809A4E0 @ =0x03000011\n\
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
	ldr r0, _0809A4E4 @ =CutsceneInternalMonologueVblank\n\
	bl CallbackSetVBlank\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809A484: .4byte 0x04000208\n\
_0809A488: .4byte 0x04000004\n\
_0809A48C: .4byte 0x0000FFEF\n\
_0809A490: .4byte 0x04000200\n\
_0809A494: .4byte 0x0000FFFD\n\
_0809A498: .4byte unk_9a63c\n\
_0809A49C: .4byte 0x0865FB5C\n\
_0809A4A0: .4byte 0x06017C00\n\
_0809A4A4: .4byte 0x040000D4\n\
_0809A4A8: .4byte 0x086638A0\n\
_0809A4AC: .4byte 0x050003E0\n\
_0809A4B0: .4byte 0x84000008\n\
_0809A4B4: .4byte 0x08662804\n\
_0809A4B8: .4byte 0x0600C800\n\
_0809A4BC: .4byte 0x84000200\n\
_0809A4C0: .4byte 0x086636A0\n\
_0809A4C4: .4byte 0x84000080\n\
_0809A4C8: .4byte 0x04000012\n\
_0809A4CC: .4byte 0x00001908\n\
_0809A4D0: .4byte gWrittenToBldy\n\
_0809A4D4: .4byte gNonGameplayRam\n\
_0809A4D8: .4byte gCurrentCutscene\n\
_0809A4DC: .4byte 0x0879C5A4\n\
_0809A4E0: .4byte 0x03000011\n\
_0809A4E4: .4byte CutsceneInternalMonologueVblank\n\
    .syntax divided\n");
}

// 0x0809A4E8
NAKED_FUNCTION
void CutsceneInternalMonologueProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	bl CutsceneMonologueProcessSpecialTextCharacters\n\
	adds r4, r0, #0\n\
	ldr r1, _0809A500 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x17]\n\
	cmp r0, #0\n\
	beq _0809A504\n\
	cmp r0, #1\n\
	beq _0809A50A\n\
	b _0809A512\n\
	.align 2, 0\n\
_0809A500: .4byte gNonGameplayRam\n\
_0809A504:\n\
	movs r0, #0x64\n\
	strb r0, [r1, #0x17]\n\
	b _0809A512\n\
_0809A50A:\n\
	movs r0, #0x64\n\
	strb r0, [r1, #0x17]\n\
	bl CutsceneMonologueProcessText\n\
_0809A512:\n\
	bl CutsceneMonologueProcessOam\n\
	bl CutsceneMonologueDrawAllOam\n\
	adds r0, r4, #0\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809A524
NAKED_FUNCTION
void CutsceneInternalMonologueSetupOam(void)
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
	ldr r1, _0809A570 @ =gNonGameplayRam\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0809A566\n\
	adds r3, r1, #0\n\
	adds r1, r2, #0\n\
_0809A54C:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #4\n\
	bhi _0809A56A\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809A54C\n\
_0809A566:\n\
	cmp r4, #4\n\
	bls _0809A574\n\
_0809A56A:\n\
	movs r0, #5\n\
	b _0809A5DC\n\
	.align 2, 0\n\
_0809A570: .4byte gNonGameplayRam\n\
_0809A574:\n\
	adds r0, r4, #0\n\
	bl CutsceneMonologueResetOam\n\
	ldr r5, _0809A5E8 @ =gNonGameplayRam\n\
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
	ldr r0, _0809A5EC @ =0x00000219\n\
	adds r1, r2, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	cmp r6, #1\n\
	bne _0809A5DA\n\
	ldr r0, _0809A5F0 @ =0x0000021F\n\
	adds r1, r2, r0\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	ldr r0, _0809A5F4 @ =0x00000221\n\
	adds r1, r2, r0\n\
	movs r0, #0xf\n\
	strb r0, [r1]\n\
	ldr r0, _0809A5F8 @ =0x00000222\n\
	adds r1, r2, r0\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #2\n\
	strh r0, [r1]\n\
	movs r1, #0x89\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	adds r0, r3, r0\n\
	ldr r1, _0809A5FC @ =0x08663E5C\n\
	str r1, [r0]\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	adds r0, r3, r0\n\
	ldr r1, _0809A600 @ =CutsceneMonologueProcessCursor\n\
	str r1, [r0]\n\
_0809A5DA:\n\
	adds r0, r4, #0\n\
_0809A5DC:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809A5E8: .4byte gNonGameplayRam\n\
_0809A5EC: .4byte 0x00000219\n\
_0809A5F0: .4byte 0x0000021F\n\
_0809A5F4: .4byte 0x00000221\n\
_0809A5F8: .4byte 0x00000222\n\
_0809A5FC: .4byte 0x08663E5C\n\
_0809A600: .4byte CutsceneMonologueProcessCursor\n\
    .syntax divided\n");
}

// 0x0809A604
NAKED_FUNCTION
void CutsceneInternalMonologueVblank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r1, _0809A628 @ =0x040000D4\n\
	ldr r0, _0809A62C @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809A630 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	bl unk_9cc4c\n\
	ldr r1, _0809A634 @ =0x04000054\n\
	ldr r0, _0809A638 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809A628: .4byte 0x040000D4\n\
_0809A62C: .4byte gOamData\n\
_0809A630: .4byte 0x84000100\n\
_0809A634: .4byte 0x04000054\n\
_0809A638: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809A63C
NAKED_FUNCTION
void unk_9a63c(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}
