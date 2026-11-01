#include "globals.h"
#include "macros.h"

// 0x0809994C
NAKED_FUNCTION
void CutsceneHandler(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r4, _08099964 @ =gSubGameMode1\n\
	movs r1, #0\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #1\n\
	beq _0809997A\n\
	cmp r0, #1\n\
	bgt _08099968\n\
	cmp r0, #0\n\
	beq _08099972\n\
	b _080999BA\n\
	.align 2, 0\n\
_08099964: .4byte gSubGameMode1\n\
_08099968:\n\
	cmp r0, #2\n\
	beq _08099992\n\
	cmp r0, #3\n\
	beq _080999A0\n\
	b _080999BA\n\
_08099972:\n\
	bl CutsceneInit\n\
	movs r0, #2\n\
	b _080999B8\n\
_0809997A:\n\
	ldr r1, _08099988 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _0809998C\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	b _080999BA\n\
	.align 2, 0\n\
_08099988: .4byte gWrittenToBldy\n\
_0809998C:\n\
	ldrh r0, [r4]\n\
	adds r0, #1\n\
	b _080999B8\n\
_08099992:\n\
	bl CutsceneProcess\n\
	cmp r0, #0\n\
	beq _080999BA\n\
	ldrh r0, [r4]\n\
	adds r0, #1\n\
	b _080999B8\n\
_080999A0:\n\
	ldr r1, _080999B0 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _080999B4\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _080999BA\n\
	.align 2, 0\n\
_080999B0: .4byte gWrittenToBldy\n\
_080999B4:\n\
	movs r5, #1\n\
	movs r0, #0\n\
_080999B8:\n\
	strh r0, [r4]\n\
_080999BA:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080999C4
NAKED_FUNCTION
void CutsceneInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #4\n\
	ldr r3, _08099A90 @ =0x04000208\n\
	movs r5, #0\n\
	strh r5, [r3]\n\
	ldr r2, _08099A94 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _08099A98 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _08099A9C @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _08099AA0 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _08099AA4 @ =unk_99af8\n\
	bl CallbackSetVBlank\n\
	ldr r1, _08099AA8 @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	ldr r0, _08099AAC @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _08099AB0 @ =0x04000054\n\
	strh r1, [r0]\n\
	ldr r4, _08099AB4 @ =0x040000D4\n\
	ldr r0, _08099AB8 @ =0x06010000\n\
	str r0, [r4]\n\
	ldr r0, _08099ABC @ =0x0201C000\n\
	str r0, [r4, #4]\n\
	ldr r0, _08099AC0 @ =0x84002000\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08099AC4 @ =gNextOamSlot\n\
	strb r5, [r0]\n\
	bl ResetFreeOam\n\
	movs r1, #0\n\
	str r1, [sp]\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r0, _08099AC8 @ =gNonGameplayRam\n\
	str r0, [r4, #4]\n\
	ldr r0, _08099ACC @ =0x85000150\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08099AD0 @ =0x00007FFF\n\
	str r0, [sp]\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #0x13\n\
	str r2, [r4, #4]\n\
	ldr r0, _08099AD4 @ =0x85000080\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	strh r1, [r2]\n\
	str r1, [sp]\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	ldr r0, _08099AD8 @ =0x85004000\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08099ADC @ =0x0400000E\n\
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
	subs r0, #0x1e\n\
	strh r1, [r0]\n\
	ldr r0, _08099AE0 @ =CutsceneVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #4\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08099A90: .4byte 0x04000208\n\
_08099A94: .4byte 0x04000004\n\
_08099A98: .4byte 0x0000FFEF\n\
_08099A9C: .4byte 0x04000200\n\
_08099AA0: .4byte 0x0000FFFD\n\
_08099AA4: .4byte unk_99af8\n\
_08099AA8: .4byte 0x04000050\n\
_08099AAC: .4byte gWrittenToBldy\n\
_08099AB0: .4byte 0x04000054\n\
_08099AB4: .4byte 0x040000D4\n\
_08099AB8: .4byte 0x06010000\n\
_08099ABC: .4byte 0x0201C000\n\
_08099AC0: .4byte 0x84002000\n\
_08099AC4: .4byte gNextOamSlot\n\
_08099AC8: .4byte gNonGameplayRam\n\
_08099ACC: .4byte 0x85000150\n\
_08099AD0: .4byte 0x00007FFF\n\
_08099AD4: .4byte 0x85000080\n\
_08099AD8: .4byte 0x85004000\n\
_08099ADC: .4byte 0x0400000E\n\
_08099AE0: .4byte CutsceneVblank\n\
    .syntax divided\n");
}

// 0x08099AE4
NAKED_FUNCTION
void CutsceneVblank(void)
{
    asm(" .syntax unified\n\
	ldr r0, _08099AF0 @ =0x04000054\n\
	ldr r1, _08099AF4 @ =gWrittenToBldy\n\
	ldrh r1, [r1]\n\
	strh r1, [r0]\n\
	bx lr\n\
	.align 2, 0\n\
_08099AF0: .4byte 0x04000054\n\
_08099AF4: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x08099AF8
NAKED_FUNCTION
void unk_99af8(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}
