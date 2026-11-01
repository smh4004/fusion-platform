#include "globals.h"
#include "macros.h"

// 0x0809741C
NAKED_FUNCTION
void DiedFromSr388CollisionHandler(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #4\n\
	movs r5, #0\n\
	ldr r4, _08097438 @ =gSubGameMode1\n\
	movs r1, #0\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #1\n\
	beq _08097468\n\
	cmp r0, #1\n\
	bgt _0809743C\n\
	cmp r0, #0\n\
	beq _08097442\n\
	b _080974B8\n\
	.align 2, 0\n\
_08097438: .4byte gSubGameMode1\n\
_0809743C:\n\
	cmp r0, #2\n\
	beq _08097488\n\
	b _080974B8\n\
_08097442:\n\
	str r5, [sp]\n\
	ldr r1, _0809745C @ =0x040000D4\n\
	mov r2, sp\n\
	str r2, [r1]\n\
	ldr r0, _08097460 @ =gNonGameplayRam\n\
	str r0, [r1, #4]\n\
	ldr r0, _08097464 @ =0x85000150\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #1\n\
	strh r0, [r4]\n\
	b _080974B8\n\
	.align 2, 0\n\
_0809745C: .4byte 0x040000D4\n\
_08097460: .4byte gNonGameplayRam\n\
_08097464: .4byte 0x85000150\n\
_08097468:\n\
	bl DiedOnSr388Collision\n\
	cmp r0, #0\n\
	beq _080974B8\n\
	ldr r0, _08097480 @ =gNonGameplayRam\n\
	ldr r1, _08097484 @ =0x0000020E\n\
	adds r0, r0, r1\n\
	strh r5, [r0]\n\
	movs r0, #2\n\
	strh r0, [r4]\n\
	b _080974B8\n\
	.align 2, 0\n\
_08097480: .4byte gNonGameplayRam\n\
_08097484: .4byte 0x0000020E\n\
_08097488:\n\
	ldr r0, _080974A0 @ =gNonGameplayRam\n\
	ldr r2, _080974A4 @ =0x0000020E\n\
	adds r1, r0, r2\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	bne _080974B0\n\
	ldr r1, _080974A8 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _080974AC\n\
	adds r0, #1\n\
	b _080974B2\n\
	.align 2, 0\n\
_080974A0: .4byte gNonGameplayRam\n\
_080974A4: .4byte 0x0000020E\n\
_080974A8: .4byte gWrittenToBldy\n\
_080974AC:\n\
	movs r5, #1\n\
	b _080974B4\n\
_080974B0:\n\
	subs r0, #1\n\
_080974B2:\n\
	strh r0, [r1]\n\
_080974B4:\n\
	bl SpecialCutsceneDrawAllOam\n\
_080974B8:\n\
	adds r0, r5, #0\n\
	add sp, #4\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080974C4
NAKED_FUNCTION
void DiedOnSr388CollisionInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	sub sp, #4\n\
	ldr r3, _08097618 @ =0x04000208\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	ldr r2, _0809761C @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _08097620 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _08097624 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _08097628 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _0809762C @ =unk_99940\n\
	bl CallbackSetVBlank\n\
	movs r5, #0\n\
	str r5, [sp]\n\
	ldr r4, _08097630 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r1, _08097634 @ =gNonGameplayRam\n\
	mov r8, r1\n\
	str r1, [r4, #4]\n\
	ldr r0, _08097638 @ =0x85000150\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809763C @ =0x086238F4\n\
	ldr r1, _08097640 @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08097644 @ =0x08636C38\n\
	str r0, [r4]\n\
	ldr r0, _08097648 @ =0x05000200\n\
	str r0, [r4, #4]\n\
	ldr r6, _0809764C @ =0x84000080\n\
	str r6, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08097650 @ =0x0862B5F4\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _08097654 @ =0x08638C14\n\
	ldr r1, _08097658 @ =0x0600F000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809765C @ =0x08639BC4\n\
	ldr r1, _08097660 @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _08097664 @ =0x08637038\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	str r6, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08097668 @ =gBg1XPosition\n\
	strh r5, [r0]\n\
	ldr r0, _0809766C @ =gBg1YPosition\n\
	movs r2, #8\n\
	strh r2, [r0]\n\
	ldr r0, _08097670 @ =0x0300122C\n\
	strh r5, [r0]\n\
	ldr r0, _08097674 @ =0x0300122E\n\
	strh r5, [r0]\n\
	ldr r0, _08097678 @ =0x03001230\n\
	strh r5, [r0]\n\
	ldr r0, _0809767C @ =0x03001232\n\
	strh r5, [r0]\n\
	ldr r0, _08097680 @ =0x04000010\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	ldr r1, _08097684 @ =0x04000008\n\
	ldr r3, _08097688 @ =0x00001C08\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r3, _0809768C @ =0x00001E01\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #4\n\
	ldr r3, _08097690 @ =0x00001F03\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x42\n\
	movs r0, #0xbf\n\
	strh r0, [r1]\n\
	ldr r0, _08097694 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _08097698 @ =0x04000054\n\
	strh r1, [r0]\n\
	ldr r0, _0809769C @ =gWrittenToBldalpha_Eva\n\
	strh r2, [r0]\n\
	ldr r1, _080976A0 @ =gWrittenToBldalpha_Evb\n\
	movs r0, #0xe\n\
	strh r0, [r1]\n\
	ldr r0, _080976A4 @ =0x0000024D\n\
	bl SoundPlay_3b1c\n\
	movs r0, #2\n\
	movs r1, #0xa4\n\
	movs r2, #0x28\n\
	movs r3, #1\n\
	bl DiedOnSr388CollisionSetupOam\n\
	movs r0, #1\n\
	movs r1, #0xa4\n\
	movs r2, #0x28\n\
	movs r3, #1\n\
	bl DiedOnSr388CollisionSetupOam\n\
	movs r0, #3\n\
	movs r1, #0x86\n\
	movs r2, #0x3c\n\
	movs r3, #1\n\
	bl DiedOnSr388CollisionSetupOam\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	ldr r0, _080976A8 @ =0x0863A19C\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	str r5, [sp]\n\
	mov r2, sp\n\
	str r2, [r4]\n\
	ldr r0, _080976AC @ =0x0600D000\n\
	str r0, [r4, #4]\n\
	ldr r0, _080976B0 @ =0x85000400\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #5\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	ldr r0, _080976B4 @ =DiedOnSr388CollisionVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08097618: .4byte 0x04000208\n\
_0809761C: .4byte 0x04000004\n\
_08097620: .4byte 0x0000FFEF\n\
_08097624: .4byte 0x04000200\n\
_08097628: .4byte 0x0000FFFD\n\
_0809762C: .4byte unk_99940\n\
_08097630: .4byte 0x040000D4\n\
_08097634: .4byte gNonGameplayRam\n\
_08097638: .4byte 0x85000150\n\
_0809763C: .4byte 0x086238F4\n\
_08097640: .4byte 0x06010000\n\
_08097644: .4byte 0x08636C38\n\
_08097648: .4byte 0x05000200\n\
_0809764C: .4byte 0x84000080\n\
_08097650: .4byte 0x0862B5F4\n\
_08097654: .4byte 0x08638C14\n\
_08097658: .4byte 0x0600F000\n\
_0809765C: .4byte 0x08639BC4\n\
_08097660: .4byte 0x0600F800\n\
_08097664: .4byte 0x08637038\n\
_08097668: .4byte gBg1XPosition\n\
_0809766C: .4byte gBg1YPosition\n\
_08097670: .4byte 0x0300122C\n\
_08097674: .4byte 0x0300122E\n\
_08097678: .4byte 0x03001230\n\
_0809767C: .4byte 0x03001232\n\
_08097680: .4byte 0x04000010\n\
_08097684: .4byte 0x04000008\n\
_08097688: .4byte 0x00001C08\n\
_0809768C: .4byte 0x00001E01\n\
_08097690: .4byte 0x00001F03\n\
_08097694: .4byte gWrittenToBldy\n\
_08097698: .4byte 0x04000054\n\
_0809769C: .4byte gWrittenToBldalpha_Eva\n\
_080976A0: .4byte gWrittenToBldalpha_Evb\n\
_080976A4: .4byte 0x0000024D\n\
_080976A8: .4byte 0x0863A19C\n\
_080976AC: .4byte 0x0600D000\n\
_080976B0: .4byte 0x85000400\n\
_080976B4: .4byte DiedOnSr388CollisionVblank\n\
    .syntax divided\n");
}

// 0x080976B8
NAKED_FUNCTION
void DiedOnSr388CollisionProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r5, #0\n\
	ldr r2, _080976E4 @ =gNonGameplayRam\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	adds r1, #1\n\
	strh r1, [r0]\n\
	movs r4, #0x85\n\
	lsls r4, r4, #2\n\
	adds r0, r2, r4\n\
	ldrb r0, [r0]\n\
	adds r3, r2, #0\n\
	cmp r0, #4\n\
	bls _080976DA\n\
	b _08097862\n\
_080976DA:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080976E8 @ =_080976EC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080976E4: .4byte gNonGameplayRam\n\
_080976E8: .4byte _080976EC\n\
_080976EC: @ jump table\n\
	.4byte _08097700 @ case 0\n\
	.4byte _08097734 @ case 1\n\
	.4byte _08097740 @ case 2\n\
	.4byte _080977A8 @ case 3\n\
	.4byte _08097808 @ case 4\n\
_08097700:\n\
	ldr r1, _08097710 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	beq _08097714\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	b _080977F8\n\
	.align 2, 0\n\
_08097710: .4byte gWrittenToBldy\n\
_08097714:\n\
	ldr r1, _08097730 @ =0x04000050\n\
	movs r6, #0xc4\n\
	lsls r6, r6, #4\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	strh r2, [r0]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	movs r0, #1\n\
	b _080977F6\n\
	.align 2, 0\n\
_08097730: .4byte 0x04000050\n\
_08097734:\n\
	movs r4, #0x84\n\
	lsls r4, r4, #2\n\
	adds r1, r3, r4\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	b _080977F8\n\
_08097740:\n\
	movs r6, #0x84\n\
	lsls r6, r6, #2\n\
	adds r4, r3, r6\n\
	ldrh r2, [r4]\n\
	cmp r2, #1\n\
	bne _08097774\n\
	ldr r0, _08097768 @ =gWrittenToBldalpha_Eva\n\
	movs r1, #0xa\n\
	strh r1, [r0]\n\
	ldr r0, _0809776C @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	movs r1, #0x88\n\
	lsls r1, r1, #1\n\
	adds r0, r3, r1\n\
	movs r1, #0\n\
	strb r2, [r0]\n\
	ldr r2, _08097770 @ =0x00000111\n\
	adds r0, r3, r2\n\
	strb r1, [r0]\n\
	b _080977F8\n\
	.align 2, 0\n\
_08097768: .4byte gWrittenToBldalpha_Eva\n\
_0809776C: .4byte gWrittenToBldalpha_Evb\n\
_08097770: .4byte 0x00000111\n\
_08097774:\n\
	cmp r2, #2\n\
	bne _080977F8\n\
	ldr r1, _080977A0 @ =0x04000050\n\
	ldr r6, _080977A4 @ =0x00000842\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r6, #0x80\n\
	lsls r6, r6, #2\n\
	adds r1, r6, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0\n\
	strh r0, [r4]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	movs r0, #3\n\
	b _080977F6\n\
	.align 2, 0\n\
_080977A0: .4byte 0x04000050\n\
_080977A4: .4byte 0x00000842\n\
_080977A8:\n\
	ldr r1, _080977D4 @ =0x00000111\n\
	adds r4, r3, r1\n\
	ldrb r2, [r4]\n\
	cmp r2, #0xe\n\
	bhi _080977D8\n\
	movs r6, #0x84\n\
	lsls r6, r6, #2\n\
	adds r1, r3, r6\n\
	ldrh r0, [r1]\n\
	cmp r0, #4\n\
	bne _080977F8\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r0, #0x88\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r0, r2, #1\n\
	strb r0, [r4]\n\
	b _080977F8\n\
	.align 2, 0\n\
_080977D4: .4byte 0x00000111\n\
_080977D8:\n\
	movs r2, #0x84\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bne _080977F8\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08097804 @ =gWrittenToBldy\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	movs r4, #0x85\n\
	lsls r4, r4, #2\n\
	adds r1, r3, r4\n\
	movs r0, #4\n\
_080977F6:\n\
	strb r0, [r1]\n\
_080977F8:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	b _08097862\n\
	.align 2, 0\n\
_08097804: .4byte gWrittenToBldy\n\
_08097808:\n\
	ldr r4, _08097830 @ =gWrittenToBldalpha_Eva\n\
	ldrh r2, [r4]\n\
	cmp r2, #0xf\n\
	bhi _08097838\n\
	movs r6, #0x84\n\
	lsls r6, r6, #2\n\
	adds r1, r3, r6\n\
	ldrh r0, [r1]\n\
	cmp r0, #6\n\
	bne _0809785A\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	adds r0, r2, #1\n\
	strh r0, [r4]\n\
	ldr r1, _08097834 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r1]\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _0809785A\n\
	.align 2, 0\n\
_08097830: .4byte gWrittenToBldalpha_Eva\n\
_08097834: .4byte gWrittenToBldalpha_Evb\n\
_08097838:\n\
	ldr r0, _0809786C @ =0x04000050\n\
	movs r1, #0xbf\n\
	strh r1, [r0]\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r2, r3, r0\n\
	ldrh r0, [r2]\n\
	cmp r0, #0xf\n\
	bne _0809785A\n\
	movs r0, #0\n\
	movs r1, #0\n\
	strh r1, [r2]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	strb r0, [r1]\n\
	movs r5, #1\n\
_0809785A:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_08097862:\n\
	adds r0, r5, #0\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809786C: .4byte 0x04000050\n\
    .syntax divided\n");
}

// 0x08097870
NAKED_FUNCTION
void DiedOnSr388Collision(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r4, _08097888 @ =gNonGameplayRam\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #1\n\
	beq _0809789C\n\
	cmp r0, #1\n\
	bgt _0809788C\n\
	cmp r0, #0\n\
	beq _08097896\n\
	b _080978F0\n\
	.align 2, 0\n\
_08097888: .4byte gNonGameplayRam\n\
_0809788C:\n\
	cmp r0, #2\n\
	beq _080978B4\n\
	cmp r0, #3\n\
	beq _080978D0\n\
	b _080978F0\n\
_08097896:\n\
	bl DiedOnSr388CollisionInit\n\
	b _080978A8\n\
_0809789C:\n\
	bl SpecialCutsceneFadeIn\n\
	ldr r0, _080978B0 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _080978F0\n\
_080978A8:\n\
	movs r0, #2\n\
	strh r0, [r4, #8]\n\
	b _080978F0\n\
	.align 2, 0\n\
_080978B0: .4byte gWrittenToBldy\n\
_080978B4:\n\
	bl DiedOnSr388CollisionProcess\n\
	cmp r0, #0\n\
	beq _080978F0\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	strb r5, [r0]\n\
	subs r1, #1\n\
	adds r0, r4, r1\n\
	strb r5, [r0]\n\
	movs r0, #3\n\
	strh r0, [r4, #8]\n\
	b _080978F0\n\
_080978D0:\n\
	ldr r1, _080978E0 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _080978E4\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _080978E8\n\
	.align 2, 0\n\
_080978E0: .4byte gWrittenToBldy\n\
_080978E4:\n\
	strh r5, [r4, #8]\n\
	movs r5, #1\n\
_080978E8:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_080978F0:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

// 0x080978F8
NAKED_FUNCTION
void DiedOnSr388CollisionProcessFallingBsl(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrh r0, [r4, #0xa]\n\
	adds r0, #1\n\
	movs r2, #0\n\
	strh r0, [r4, #0xa]\n\
	ldrb r1, [r4, #0x14]\n\
	cmp r1, #0\n\
	bne _0809791A\n\
	ldrh r0, [r4, #0xc]\n\
	strh r0, [r4]\n\
	ldrh r0, [r4, #0xe]\n\
	strh r0, [r4, #2]\n\
	strh r1, [r4, #0xa]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x14]\n\
	b _080979CA\n\
_0809791A:\n\
	cmp r1, #1\n\
	bne _08097978\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r4, #0x12]\n\
	cmp r0, r3\n\
	bne _08097936\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #0\n\
	bne _08097936\n\
	strb r2, [r4, #0x12]\n\
_08097936:\n\
	ldrh r0, [r4, #0xa]\n\
	movs r1, #5\n\
	bl __udivsi3\n\
	ldrh r1, [r4]\n\
	subs r1, r1, r0\n\
	strh r1, [r4, #0xc]\n\
	ldrh r0, [r4, #0xa]\n\
	movs r1, #5\n\
	bl __udivsi3\n\
	ldrh r1, [r4, #2]\n\
	adds r1, r1, r0\n\
	strh r1, [r4, #0xe]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	cmp r1, #0x50\n\
	ble _08097962\n\
	movs r0, #0\n\
	strh r0, [r4, #0xa]\n\
	movs r0, #2\n\
	strb r0, [r4, #0x14]\n\
_08097962:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #1\n\
	bne _08097970\n\
	ldrh r0, [r4, #6]\n\
	subs r0, #1\n\
	strh r0, [r4, #6]\n\
	b _080979CA\n\
_08097970:\n\
	ldrh r0, [r4, #6]\n\
	subs r0, #2\n\
	strh r0, [r4, #6]\n\
	b _080979CA\n\
_08097978:\n\
	cmp r1, #2\n\
	bne _080979A4\n\
	movs r0, #3\n\
	strb r0, [r4, #0x14]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #1\n\
	bne _080979BE\n\
	ldr r0, _0809799C @ =0x086362B8\n\
	str r0, [r4, #0x1c]\n\
	strb r2, [r4, #0x12]\n\
	strb r2, [r4, #0x11]\n\
	ldr r0, _080979A0 @ =gNonGameplayRam\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	strb r1, [r0]\n\
	b _080979CA\n\
	.align 2, 0\n\
_0809799C: .4byte 0x086362B8\n\
_080979A0: .4byte gNonGameplayRam\n\
_080979A4:\n\
	cmp r1, #3\n\
	bne _080979CA\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r4, #0x12]\n\
	cmp r0, r3\n\
	bne _080979CA\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #0\n\
	bne _080979CA\n\
_080979BE:\n\
	strb r2, [r4, #0x10]\n\
	ldrb r1, [r4, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r4, #0x18]\n\
_080979CA:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x080979D0
NAKED_FUNCTION
void unk_979d0(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	bne _080979FC\n\
	ldrb r0, [r2, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r2, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r2, #0x12]\n\
	cmp r0, r3\n\
	bne _080979FC\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080979FC\n\
	strb r1, [r2, #0x10]\n\
	ldrb r1, [r2, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2, #0x18]\n\
_080979FC:\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x08097A00
NAKED_FUNCTION
void DiedOnSr388CollisionSetupOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r7, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov r8, r1\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	mov sb, r2\n\
	lsls r3, r3, #0x18\n\
	cmp r3, #0\n\
	bne _08097A64\n\
	movs r2, #0\n\
	ldr r1, _08097A60 @ =gNonGameplayRam\n\
	movs r3, #0x8b\n\
	lsls r3, r3, #2\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08097A52\n\
	adds r4, r1, #0\n\
_08097A32:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0x13\n\
	bgt _08097AA2\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08097A32\n\
_08097A52:\n\
	lsls r0, r2, #0x18\n\
	asrs r1, r0, #0x18\n\
	mov ip, r0\n\
	cmp r1, #0x13\n\
	ble _08097AAC\n\
	b _08097AA2\n\
	.align 2, 0\n\
_08097A60: .4byte gNonGameplayRam\n\
_08097A64:\n\
	movs r2, #0x13\n\
	ldr r1, _08097AA8 @ =gNonGameplayRam\n\
	movs r3, #0x9b\n\
	lsls r3, r3, #3\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08097A9A\n\
	adds r4, r1, #0\n\
	movs r3, #0x8b\n\
	lsls r3, r3, #2\n\
_08097A7A:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0xff\n\
	lsls r1, r1, #0x18\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	blt _08097AA2\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08097A7A\n\
_08097A9A:\n\
	lsls r0, r2, #0x18\n\
	mov ip, r0\n\
	cmp r0, #0\n\
	bge _08097AAC\n\
_08097AA2:\n\
	movs r0, #0x14\n\
	b _08097BE6\n\
	.align 2, 0\n\
_08097AA8: .4byte gNonGameplayRam\n\
_08097AAC:\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r2, _08097B3C @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r2]\n\
	mov r0, ip\n\
	asrs r1, r0, #0x18\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r5, r0, #2\n\
	ldr r6, _08097B40 @ =0x030016A0\n\
	adds r0, r5, r6\n\
	str r0, [r2, #4]\n\
	ldr r0, _08097B44 @ =0x85000009\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	ldr r1, _08097B48 @ =0xFFFFFDE4\n\
	adds r0, r6, r1\n\
	adds r2, r5, r0\n\
	movs r3, #0x8a\n\
	lsls r3, r3, #2\n\
	adds r0, r2, r3\n\
	mov r1, r8\n\
	strh r1, [r0]\n\
	adds r3, #2\n\
	adds r0, r2, r3\n\
	mov r1, sb\n\
	strh r1, [r0]\n\
	adds r3, #2\n\
	adds r0, r2, r3\n\
	strb r7, [r0]\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r4, r2, r0\n\
	ldrb r0, [r4]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	cmp r7, #1\n\
	bne _08097B58\n\
	subs r3, #0xa\n\
	adds r1, r2, r3\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	ldr r0, _08097B4C @ =0x00000236\n\
	adds r2, r2, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r4]\n\
	movs r0, #7\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	adds r0, r6, #0\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08097B50 @ =0x08636020\n\
	str r1, [r0]\n\
	adds r0, r6, #0\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08097B54 @ =DiedOnSr388CollisionProcessFallingBsl\n\
	b _08097BE0\n\
	.align 2, 0\n\
_08097B3C: .4byte 0x040000D4\n\
_08097B40: .4byte 0x030016A0\n\
_08097B44: .4byte 0x85000009\n\
_08097B48: .4byte 0xFFFFFDE4\n\
_08097B4C: .4byte 0x00000236\n\
_08097B50: .4byte 0x08636020\n\
_08097B54: .4byte DiedOnSr388CollisionProcessFallingBsl\n\
_08097B58:\n\
	cmp r7, #2\n\
	bne _08097BB8\n\
	ldr r3, _08097BA8 @ =0x00000222\n\
	adds r1, r2, r3\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	strh r0, [r1]\n\
	ldrb r1, [r4]\n\
	movs r0, #0x19\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r3, #8\n\
	orrs r0, r3\n\
	strb r0, [r4]\n\
	ldr r0, _08097BAC @ =0x00000236\n\
	adds r2, r2, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	orrs r0, r3\n\
	strb r0, [r2]\n\
	ldrb r1, [r4]\n\
	movs r0, #7\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	adds r0, r6, #0\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08097BB0 @ =0x08636038\n\
	str r1, [r0]\n\
	adds r0, r6, #0\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08097BB4 @ =DiedOnSr388CollisionProcessFallingBsl\n\
	b _08097BE0\n\
	.align 2, 0\n\
_08097BA8: .4byte 0x00000222\n\
_08097BAC: .4byte 0x00000236\n\
_08097BB0: .4byte 0x08636038\n\
_08097BB4: .4byte DiedOnSr388CollisionProcessFallingBsl\n\
_08097BB8:\n\
	cmp r7, #3\n\
	bne _08097BE2\n\
	ldr r1, _08097BF4 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r6, #0\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08097BF8 @ =0x08636050\n\
	str r1, [r0]\n\
	adds r0, r6, #0\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08097BFC @ =unk_979d0\n\
_08097BE0:\n\
	str r1, [r0]\n\
_08097BE2:\n\
	mov r3, ip\n\
	lsrs r0, r3, #0x18\n\
_08097BE6:\n\
	add sp, #4\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08097BF4: .4byte 0x00000236\n\
_08097BF8: .4byte 0x08636050\n\
_08097BFC: .4byte unk_979d0\n\
    .syntax divided\n");
}

// 0x08097C00
NAKED_FUNCTION
void DiedOnSr388CollisionVblank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r3, _08097C8C @ =0x040000D4\n\
	ldr r0, _08097C90 @ =gOamData\n\
	str r0, [r3]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r3, #4]\n\
	ldr r0, _08097C94 @ =0x84000100\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	ldr r2, _08097C98 @ =0x04000052\n\
	ldr r0, _08097C9C @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _08097CA0 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08097CA4 @ =0x04000054\n\
	ldr r0, _08097CA8 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x40\n\
	ldr r0, _08097CAC @ =gBg1XPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097CB0 @ =gBg1YPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097CB4 @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097CB8 @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097CBC @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097CC0 @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _08097CC4 @ =gNonGameplayRam\n\
	movs r0, #0x88\n\
	lsls r0, r0, #1\n\
	adds r2, r1, r0\n\
	ldrb r0, [r2]\n\
	cmp r0, #1\n\
	bne _08097C86\n\
	movs r0, #0\n\
	strb r0, [r2]\n\
	ldr r2, _08097CC8 @ =0x00000111\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #5\n\
	ldr r1, _08097CCC @ =0x08636A38\n\
	adds r0, r0, r1\n\
	str r0, [r3]\n\
	ldr r0, _08097CD0 @ =0x05000120\n\
	str r0, [r3, #4]\n\
	ldr r0, _08097CD4 @ =0x84000008\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
_08097C86:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08097C8C: .4byte 0x040000D4\n\
_08097C90: .4byte gOamData\n\
_08097C94: .4byte 0x84000100\n\
_08097C98: .4byte 0x04000052\n\
_08097C9C: .4byte gWrittenToBldalpha_Evb\n\
_08097CA0: .4byte gWrittenToBldalpha_Eva\n\
_08097CA4: .4byte 0x04000054\n\
_08097CA8: .4byte gWrittenToBldy\n\
_08097CAC: .4byte gBg1XPosition\n\
_08097CB0: .4byte gBg1YPosition\n\
_08097CB4: .4byte 0x0300122C\n\
_08097CB8: .4byte 0x0300122E\n\
_08097CBC: .4byte 0x03001230\n\
_08097CC0: .4byte 0x03001232\n\
_08097CC4: .4byte gNonGameplayRam\n\
_08097CC8: .4byte 0x00000111\n\
_08097CCC: .4byte 0x08636A38\n\
_08097CD0: .4byte 0x05000120\n\
_08097CD4: .4byte 0x84000008\n\
    .syntax divided\n");
}

// 0x08097CD8
NAKED_FUNCTION
void DiedOnSr388CollisionVblank_Unused(void)
{
    asm(" .syntax unified\n\
	ldr r1, _08097D34 @ =0x040000D4\n\
	ldr r0, _08097D38 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _08097D3C @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r2, _08097D40 @ =0x04000052\n\
	ldr r0, _08097D44 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _08097D48 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08097D4C @ =0x04000054\n\
	ldr r0, _08097D50 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x40\n\
	ldr r0, _08097D54 @ =gBg1XPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097D58 @ =gBg1YPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097D5C @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097D60 @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097D64 @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097D68 @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_08097D34: .4byte 0x040000D4\n\
_08097D38: .4byte gOamData\n\
_08097D3C: .4byte 0x84000100\n\
_08097D40: .4byte 0x04000052\n\
_08097D44: .4byte gWrittenToBldalpha_Evb\n\
_08097D48: .4byte gWrittenToBldalpha_Eva\n\
_08097D4C: .4byte 0x04000054\n\
_08097D50: .4byte gWrittenToBldy\n\
_08097D54: .4byte gBg1XPosition\n\
_08097D58: .4byte gBg1YPosition\n\
_08097D5C: .4byte 0x0300122C\n\
_08097D60: .4byte 0x0300122E\n\
_08097D64: .4byte 0x03001230\n\
_08097D68: .4byte 0x03001232\n\
    .syntax divided\n");
}

// 0x08097D6C
NAKED_FUNCTION
void DiedOnSr388CollisionGetPositionAndSlotOfOamByType(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r1, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	movs r1, #0\n\
	ldr r7, _08097DA4 @ =gNonGameplayRam\n\
	movs r6, #0x8b\n\
	lsls r6, r6, #2\n\
_08097D7C:\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r3, r0, r7\n\
	adds r0, r3, r6\n\
	ldrb r0, [r0]\n\
	cmp r0, r5\n\
	bne _08097DAC\n\
	movs r5, #0x8a\n\
	lsls r5, r5, #2\n\
	adds r0, r3, r5\n\
	ldrh r0, [r0]\n\
	strh r0, [r4]\n\
	ldr r4, _08097DA8 @ =0x0000022A\n\
	adds r0, r3, r4\n\
	ldrh r0, [r0]\n\
	strh r0, [r2]\n\
	adds r0, r1, #0\n\
	b _08097DC4\n\
	.align 2, 0\n\
_08097DA4: .4byte gNonGameplayRam\n\
_08097DA8: .4byte 0x0000022A\n\
_08097DAC:\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0x13\n\
	bls _08097D7C\n\
	movs r5, #0x96\n\
	lsls r5, r5, #1\n\
	adds r0, r5, #0\n\
	strh r0, [r4]\n\
	movs r0, #0xc8\n\
	strh r0, [r2]\n\
	movs r0, #0x14\n\
_08097DC4:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08097DCC
NAKED_FUNCTION
void unk_97dcc(void)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}
