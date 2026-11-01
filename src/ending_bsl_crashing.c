#include "globals.h"
#include "macros.h"

// 0x08094E84
NAKED_FUNCTION
void EndingHandler(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #4\n\
	movs r5, #0\n\
	ldr r4, _08094EA0 @ =gSubGameMode1\n\
	movs r1, #0\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #1\n\
	beq _08094ED4\n\
	cmp r0, #1\n\
	bgt _08094EA4\n\
	cmp r0, #0\n\
	beq _08094EAE\n\
	b _08094F6A\n\
	.align 2, 0\n\
_08094EA0: .4byte gSubGameMode1\n\
_08094EA4:\n\
	cmp r0, #2\n\
	beq _08094EE2\n\
	cmp r0, #3\n\
	beq _08094F00\n\
	b _08094F6A\n\
_08094EAE:\n\
	str r5, [sp]\n\
	ldr r1, _08094EC8 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	ldr r0, _08094ECC @ =gNonGameplayRam\n\
	str r0, [r1, #4]\n\
	ldr r0, _08094ED0 @ =0x85000150\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #1\n\
	strh r0, [r4]\n\
	b _08094F6A\n\
	.align 2, 0\n\
_08094EC8: .4byte 0x040000D4\n\
_08094ECC: .4byte gNonGameplayRam\n\
_08094ED0: .4byte 0x85000150\n\
_08094ED4:\n\
	bl EndingBslCrashing\n\
	cmp r0, #0\n\
	beq _08094F6A\n\
	movs r0, #2\n\
	strh r0, [r4]\n\
	b _08094F6A\n\
_08094EE2:\n\
	bl EndingInShip\n\
	cmp r0, #0\n\
	beq _08094F6A\n\
	ldr r0, _08094EF8 @ =gNonGameplayRam\n\
	ldr r1, _08094EFC @ =0x0000020E\n\
	adds r0, r0, r1\n\
	strh r5, [r0]\n\
	movs r0, #3\n\
	strh r0, [r4]\n\
	b _08094F6A\n\
	.align 2, 0\n\
_08094EF8: .4byte gNonGameplayRam\n\
_08094EFC: .4byte 0x0000020E\n\
_08094F00:\n\
	ldr r0, _08094F24 @ =gNonGameplayRam\n\
	ldr r1, _08094F28 @ =0x0000020E\n\
	adds r4, r0, r1\n\
	ldrh r0, [r4]\n\
	adds r0, #1\n\
	strh r0, [r4]\n\
	ldr r2, _08094F2C @ =gWrittenToBldy\n\
	ldrh r1, [r2]\n\
	cmp r1, #0xf\n\
	bhi _08094F30\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bne _08094F66\n\
	strh r5, [r4]\n\
	adds r0, r1, #1\n\
	strh r0, [r2]\n\
	b _08094F66\n\
	.align 2, 0\n\
_08094F24: .4byte gNonGameplayRam\n\
_08094F28: .4byte 0x0000020E\n\
_08094F2C: .4byte gWrittenToBldy\n\
_08094F30:\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bne _08094F40\n\
	movs r0, #0\n\
	bl Sram_ProcessEndingSave\n\
	b _08094F66\n\
_08094F40:\n\
	cmp r0, #2\n\
	bne _08094F4C\n\
	movs r0, #1\n\
	bl Sram_ProcessEndingSave\n\
	b _08094F66\n\
_08094F4C:\n\
	cmp r0, #3\n\
	bne _08094F58\n\
	movs r0, #2\n\
	bl Sram_ProcessEndingSave\n\
	b _08094F66\n\
_08094F58:\n\
	cmp r0, #4\n\
	bne _08094F66\n\
	movs r0, #3\n\
	bl Sram_ProcessEndingSave\n\
	strh r5, [r4]\n\
	movs r5, #1\n\
_08094F66:\n\
	bl SpecialCutsceneDrawAllOam\n\
_08094F6A:\n\
	adds r0, r5, #0\n\
	add sp, #4\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

// 0x08094F74
NAKED_FUNCTION
void EndingBslCrashingInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	sub sp, #4\n\
	ldr r3, _080950DC @ =0x04000208\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	ldr r2, _080950E0 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _080950E4 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _080950E8 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _080950EC @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _080950F0 @ =unk_99940\n\
	bl CallbackSetVBlank\n\
	movs r5, #0\n\
	str r5, [sp]\n\
	ldr r4, _080950F4 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r1, _080950F8 @ =gNonGameplayRam\n\
	mov r8, r1\n\
	str r1, [r4, #4]\n\
	ldr r0, _080950FC @ =0x85000150\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08095100 @ =0x086238F4\n\
	ldr r1, _08095104 @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095108 @ =0x08636C38\n\
	str r0, [r4]\n\
	ldr r0, _0809510C @ =0x05000200\n\
	str r0, [r4, #4]\n\
	ldr r6, _08095110 @ =0x84000080\n\
	str r6, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08095114 @ =0x0862B5F4\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095118 @ =0x08638C14\n\
	ldr r1, _0809511C @ =0x0600F000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095120 @ =0x08639BC4\n\
	ldr r1, _08095124 @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095128 @ =0x08637038\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	str r6, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809512C @ =gBg1XPosition\n\
	strh r5, [r0]\n\
	ldr r0, _08095130 @ =gBg1YPosition\n\
	movs r2, #8\n\
	strh r2, [r0]\n\
	ldr r0, _08095134 @ =0x0300122C\n\
	strh r5, [r0]\n\
	ldr r0, _08095138 @ =0x0300122E\n\
	strh r5, [r0]\n\
	ldr r0, _0809513C @ =0x03001230\n\
	strh r5, [r0]\n\
	ldr r0, _08095140 @ =0x03001232\n\
	strh r5, [r0]\n\
	ldr r0, _08095144 @ =0x04000010\n\
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
	ldr r1, _08095148 @ =0x04000008\n\
	ldr r3, _0809514C @ =0x00001C08\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r3, _08095150 @ =0x00001E01\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #4\n\
	ldr r3, _08095154 @ =0x00001F03\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x42\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	ldr r0, _08095158 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _0809515C @ =0x04000054\n\
	strh r1, [r0]\n\
	ldr r0, _08095160 @ =gWrittenToBldalpha_Eva\n\
	strh r2, [r0]\n\
	ldr r1, _08095164 @ =gWrittenToBldalpha_Evb\n\
	movs r0, #0xe\n\
	strh r0, [r1]\n\
	movs r1, #0x28\n\
	rsbs r1, r1, #0\n\
	movs r0, #5\n\
	movs r2, #0xc8\n\
	movs r3, #0\n\
	bl EndingBslCrashingSetupOam\n\
	movs r0, #4\n\
	movs r1, #0x80\n\
	movs r2, #0x48\n\
	movs r3, #1\n\
	bl EndingBslCrashingSetupOam\n\
	movs r0, #2\n\
	movs r1, #0xa4\n\
	movs r2, #0x28\n\
	movs r3, #1\n\
	bl EndingBslCrashingSetupOam\n\
	movs r0, #1\n\
	movs r1, #0xa4\n\
	movs r2, #0x28\n\
	movs r3, #1\n\
	bl EndingBslCrashingSetupOam\n\
	movs r0, #3\n\
	movs r1, #0x86\n\
	movs r2, #0x3c\n\
	movs r3, #1\n\
	bl EndingBslCrashingSetupOam\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	ldr r0, _08095168 @ =0x0863A19C\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	str r5, [sp]\n\
	mov r2, sp\n\
	str r2, [r4]\n\
	ldr r0, _0809516C @ =0x0600D000\n\
	str r0, [r4, #4]\n\
	ldr r0, _08095170 @ =0x85000400\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #5\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08095174 @ =EndingBslCrashingVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080950DC: .4byte 0x04000208\n\
_080950E0: .4byte 0x04000004\n\
_080950E4: .4byte 0x0000FFEF\n\
_080950E8: .4byte 0x04000200\n\
_080950EC: .4byte 0x0000FFFD\n\
_080950F0: .4byte unk_99940\n\
_080950F4: .4byte 0x040000D4\n\
_080950F8: .4byte gNonGameplayRam\n\
_080950FC: .4byte 0x85000150\n\
_08095100: .4byte 0x086238F4\n\
_08095104: .4byte 0x06010000\n\
_08095108: .4byte 0x08636C38\n\
_0809510C: .4byte 0x05000200\n\
_08095110: .4byte 0x84000080\n\
_08095114: .4byte 0x0862B5F4\n\
_08095118: .4byte 0x08638C14\n\
_0809511C: .4byte 0x0600F000\n\
_08095120: .4byte 0x08639BC4\n\
_08095124: .4byte 0x0600F800\n\
_08095128: .4byte 0x08637038\n\
_0809512C: .4byte gBg1XPosition\n\
_08095130: .4byte gBg1YPosition\n\
_08095134: .4byte 0x0300122C\n\
_08095138: .4byte 0x0300122E\n\
_0809513C: .4byte 0x03001230\n\
_08095140: .4byte 0x03001232\n\
_08095144: .4byte 0x04000010\n\
_08095148: .4byte 0x04000008\n\
_0809514C: .4byte 0x00001C08\n\
_08095150: .4byte 0x00001E01\n\
_08095154: .4byte 0x00001F03\n\
_08095158: .4byte gWrittenToBldy\n\
_0809515C: .4byte 0x04000054\n\
_08095160: .4byte gWrittenToBldalpha_Eva\n\
_08095164: .4byte gWrittenToBldalpha_Evb\n\
_08095168: .4byte 0x0863A19C\n\
_0809516C: .4byte 0x0600D000\n\
_08095170: .4byte 0x85000400\n\
_08095174: .4byte EndingBslCrashingVblank\n\
    .syntax divided\n");
}

// 0x08095178
NAKED_FUNCTION
void EndingShipFrontViewInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	ldr r3, _080952D4 @ =0x04000208\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	ldr r2, _080952D8 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _080952DC @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _080952E0 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _080952E4 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _080952E8 @ =unk_99940\n\
	bl CallbackSetVBlank\n\
	movs r5, #0\n\
	str r5, [sp]\n\
	ldr r4, _080952EC @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r6, _080952F0 @ =0x030016A0\n\
	str r6, [r4, #4]\n\
	ldr r0, _080952F4 @ =0x850000B4\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	add r1, sp, #4\n\
	strh r5, [r1]\n\
	str r1, [r4]\n\
	ldr r2, _080952F8 @ =0xFFFFFDF8\n\
	adds r0, r6, r2\n\
	str r0, [r4, #4]\n\
	ldr r2, _080952FC @ =0x8100007E\n\
	str r2, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	strh r5, [r1]\n\
	str r1, [r4]\n\
	ldr r1, _08095300 @ =0xFFFFFEF4\n\
	adds r0, r6, r1\n\
	str r0, [r4, #4]\n\
	str r2, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08095304 @ =0x08626738\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095308 @ =0x0863929C\n\
	ldr r1, _0809530C @ =0x0600F000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095310 @ =0x086395B8\n\
	ldr r1, _08095314 @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095318 @ =0x08636E38\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809531C @ =0x84000080\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08095320 @ =gBg1XPosition\n\
	strh r5, [r0]\n\
	ldr r0, _08095324 @ =gBg1YPosition\n\
	strh r5, [r0]\n\
	ldr r0, _08095328 @ =0x0300122C\n\
	strh r5, [r0]\n\
	ldr r3, _0809532C @ =0x0300122E\n\
	ldr r2, _08095330 @ =0x0000FFE2\n\
	adds r0, r2, #0\n\
	strh r0, [r3]\n\
	ldr r0, _08095334 @ =0x03001230\n\
	strh r5, [r0]\n\
	ldr r0, _08095338 @ =0x03001232\n\
	strh r5, [r0]\n\
	ldr r0, _0809533C @ =0x04000010\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	ldr r1, _08095340 @ =0x04000008\n\
	ldr r2, _08095344 @ =0x00001C08\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #4\n\
	ldr r2, _08095348 @ =0x00001E02\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _0809534C @ =0x00001F03\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x42\n\
	movs r0, #0xbf\n\
	strh r0, [r1]\n\
	ldr r0, _08095350 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _08095354 @ =0x04000054\n\
	strh r1, [r0]\n\
	ldr r0, _08095358 @ =gWrittenToBldalpha_Eva\n\
	strh r1, [r0]\n\
	ldr r0, _0809535C @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	ldr r2, _08095360 @ =0x04000052\n\
	lsls r0, r1, #8\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0\n\
	ldrsh r2, [r3, r0]\n\
	movs r0, #0xc\n\
	movs r1, #0\n\
	movs r3, #0\n\
	bl EndingBslCrashingSetupOam\n\
	movs r0, #0xa\n\
	movs r1, #0x78\n\
	movs r2, #0x6a\n\
	movs r3, #1\n\
	bl EndingBslCrashingSetupOam\n\
	movs r0, #0xb\n\
	movs r1, #0x78\n\
	movs r2, #0x40\n\
	movs r3, #0\n\
	bl EndingBslCrashingSetupOam\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	ldr r1, _08095364 @ =0xFFFFFDE4\n\
	adds r6, r6, r1\n\
	ldr r0, _08095368 @ =0x0863A19C\n\
	str r0, [r6]\n\
	str r5, [sp]\n\
	mov r2, sp\n\
	str r2, [r4]\n\
	ldr r0, _0809536C @ =0x0600D000\n\
	str r0, [r4, #4]\n\
	ldr r0, _08095370 @ =0x85000400\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08095374 @ =EndingShipFrontViewVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080952D4: .4byte 0x04000208\n\
_080952D8: .4byte 0x04000004\n\
_080952DC: .4byte 0x0000FFEF\n\
_080952E0: .4byte 0x04000200\n\
_080952E4: .4byte 0x0000FFFD\n\
_080952E8: .4byte unk_99940\n\
_080952EC: .4byte 0x040000D4\n\
_080952F0: .4byte 0x030016A0\n\
_080952F4: .4byte 0x850000B4\n\
_080952F8: .4byte 0xFFFFFDF8\n\
_080952FC: .4byte 0x8100007E\n\
_08095300: .4byte 0xFFFFFEF4\n\
_08095304: .4byte 0x08626738\n\
_08095308: .4byte 0x0863929C\n\
_0809530C: .4byte 0x0600F000\n\
_08095310: .4byte 0x086395B8\n\
_08095314: .4byte 0x0600F800\n\
_08095318: .4byte 0x08636E38\n\
_0809531C: .4byte 0x84000080\n\
_08095320: .4byte gBg1XPosition\n\
_08095324: .4byte gBg1YPosition\n\
_08095328: .4byte 0x0300122C\n\
_0809532C: .4byte 0x0300122E\n\
_08095330: .4byte 0x0000FFE2\n\
_08095334: .4byte 0x03001230\n\
_08095338: .4byte 0x03001232\n\
_0809533C: .4byte 0x04000010\n\
_08095340: .4byte 0x04000008\n\
_08095344: .4byte 0x00001C08\n\
_08095348: .4byte 0x00001E02\n\
_0809534C: .4byte 0x00001F03\n\
_08095350: .4byte gWrittenToBldy\n\
_08095354: .4byte 0x04000054\n\
_08095358: .4byte gWrittenToBldalpha_Eva\n\
_0809535C: .4byte gWrittenToBldalpha_Evb\n\
_08095360: .4byte 0x04000052\n\
_08095364: .4byte 0xFFFFFDE4\n\
_08095368: .4byte 0x0863A19C\n\
_0809536C: .4byte 0x0600D000\n\
_08095370: .4byte 0x85000400\n\
_08095374: .4byte EndingShipFrontViewVblank\n\
    .syntax divided\n");
}

// 0x08095378
NAKED_FUNCTION
void EndingBslCrashingProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r5, #0\n\
	ldr r2, _080953A4 @ =gNonGameplayRam\n\
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
	cmp r0, #9\n\
	bls _0809539A\n\
	b _08095634\n\
_0809539A:\n\
	lsls r0, r0, #2\n\
	ldr r1, _080953A8 @ =_080953AC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_080953A4: .4byte gNonGameplayRam\n\
_080953A8: .4byte _080953AC\n\
_080953AC: @ jump table\n\
	.4byte _080953D4 @ case 0\n\
	.4byte _08095418 @ case 1\n\
	.4byte _08095424 @ case 2\n\
	.4byte _0809548C @ case 3\n\
	.4byte _080954E4 @ case 4\n\
	.4byte _08095534 @ case 5\n\
	.4byte _08095556 @ case 6\n\
	.4byte _08095578 @ case 7\n\
	.4byte _0809559C @ case 8\n\
	.4byte _080955EC @ case 9\n\
_080953D4:\n\
	ldr r4, _080953F0 @ =gWrittenToBldy\n\
	ldrh r2, [r4]\n\
	cmp r2, #0\n\
	beq _080953F8\n\
	cmp r2, #0x10\n\
	bne _080953E6\n\
	ldr r0, _080953F4 @ =0x0000024B\n\
	bl SoundPlay_3b1c\n\
_080953E6:\n\
	ldrh r0, [r4]\n\
	subs r0, #1\n\
	strh r0, [r4]\n\
	b _080955DC\n\
	.align 2, 0\n\
_080953F0: .4byte gWrittenToBldy\n\
_080953F4: .4byte 0x0000024B\n\
_080953F8:\n\
	ldr r1, _08095414 @ =0x04000050\n\
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
	b _080955DA\n\
	.align 2, 0\n\
_08095414: .4byte 0x04000050\n\
_08095418:\n\
	movs r4, #0x84\n\
	lsls r4, r4, #2\n\
	adds r1, r3, r4\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	b _080955DC\n\
_08095424:\n\
	movs r6, #0x84\n\
	lsls r6, r6, #2\n\
	adds r4, r3, r6\n\
	ldrh r2, [r4]\n\
	cmp r2, #1\n\
	bne _08095458\n\
	ldr r0, _0809544C @ =gWrittenToBldalpha_Eva\n\
	movs r1, #0xa\n\
	strh r1, [r0]\n\
	ldr r0, _08095450 @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	movs r1, #0x88\n\
	lsls r1, r1, #1\n\
	adds r0, r3, r1\n\
	movs r1, #0\n\
	strb r2, [r0]\n\
	ldr r2, _08095454 @ =0x00000111\n\
	adds r0, r3, r2\n\
	strb r1, [r0]\n\
	b _080955DC\n\
	.align 2, 0\n\
_0809544C: .4byte gWrittenToBldalpha_Eva\n\
_08095450: .4byte gWrittenToBldalpha_Evb\n\
_08095454: .4byte 0x00000111\n\
_08095458:\n\
	cmp r2, #2\n\
	beq _0809545E\n\
	b _080955DC\n\
_0809545E:\n\
	ldr r1, _08095484 @ =0x04000050\n\
	ldr r6, _08095488 @ =0x00000842\n\
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
	b _080955DA\n\
	.align 2, 0\n\
_08095484: .4byte 0x04000050\n\
_08095488: .4byte 0x00000842\n\
_0809548C:\n\
	ldr r1, _080954B8 @ =0x00000111\n\
	adds r4, r3, r1\n\
	ldrb r2, [r4]\n\
	cmp r2, #0xe\n\
	bhi _080954BC\n\
	movs r6, #0x84\n\
	lsls r6, r6, #2\n\
	adds r1, r3, r6\n\
	ldrh r0, [r1]\n\
	cmp r0, #4\n\
	beq _080954A4\n\
	b _080955DC\n\
_080954A4:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r0, #0x88\n\
	lsls r0, r0, #1\n\
	adds r1, r3, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	adds r0, r2, #1\n\
	strb r0, [r4]\n\
	b _080955DC\n\
	.align 2, 0\n\
_080954B8: .4byte 0x00000111\n\
_080954BC:\n\
	movs r2, #0x84\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x14\n\
	beq _080954CA\n\
	b _080955DC\n\
_080954CA:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _080954E0 @ =gWrittenToBldy\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	movs r4, #0x85\n\
	lsls r4, r4, #2\n\
	adds r1, r3, r4\n\
	movs r0, #4\n\
	b _080955DA\n\
	.align 2, 0\n\
_080954E0: .4byte gWrittenToBldy\n\
_080954E4:\n\
	ldr r4, _0809550C @ =gWrittenToBldalpha_Eva\n\
	ldrh r2, [r4]\n\
	cmp r2, #0xf\n\
	bhi _08095514\n\
	movs r6, #0x84\n\
	lsls r6, r6, #2\n\
	adds r1, r3, r6\n\
	ldrh r0, [r1]\n\
	cmp r0, #6\n\
	bne _080955DC\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	adds r0, r2, #1\n\
	strh r0, [r4]\n\
	ldr r1, _08095510 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r1]\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _080955DC\n\
	.align 2, 0\n\
_0809550C: .4byte gWrittenToBldalpha_Eva\n\
_08095510: .4byte gWrittenToBldalpha_Evb\n\
_08095514:\n\
	ldr r1, _08095530 @ =0x04000050\n\
	movs r0, #0xbf\n\
	strh r0, [r1]\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	movs r0, #5\n\
	b _080955DA\n\
	.align 2, 0\n\
_08095530: .4byte 0x04000050\n\
_08095534:\n\
	movs r4, #0x84\n\
	lsls r4, r4, #2\n\
	adds r1, r3, r4\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xa\n\
	beq _08095542\n\
	b _08095634\n\
_08095542:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r6, #0x85\n\
	lsls r6, r6, #2\n\
	adds r1, r3, r6\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	bl EndingShipFrontViewInit\n\
	b _08095634\n\
_08095556:\n\
	ldr r1, _08095574 @ =0x04000050\n\
	movs r2, #0xc4\n\
	lsls r2, r2, #4\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r4, #0x84\n\
	lsls r4, r4, #2\n\
	adds r1, r3, r4\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r6, #0x85\n\
	lsls r6, r6, #2\n\
	adds r1, r3, r6\n\
	movs r0, #7\n\
	b _080955DA\n\
	.align 2, 0\n\
_08095574: .4byte 0x04000050\n\
_08095578:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xa8\n\
	bne _080955DC\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08095598 @ =gWrittenToBldy\n\
	movs r0, #2\n\
	strh r0, [r1]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	movs r0, #8\n\
	b _080955DA\n\
	.align 2, 0\n\
_08095598: .4byte gWrittenToBldy\n\
_0809559C:\n\
	movs r4, #0x84\n\
	lsls r4, r4, #2\n\
	adds r1, r3, r4\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	bne _080955DC\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _080955C8 @ =gWrittenToBldalpha_Eva\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _080955CC\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _080955DC\n\
	movs r0, #0xa\n\
	bl SpecialCutsceneDestroyOamOfType\n\
	b _080955DC\n\
	.align 2, 0\n\
_080955C8: .4byte gWrittenToBldalpha_Eva\n\
_080955CC:\n\
	ldr r1, _080955E8 @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	movs r6, #0x85\n\
	lsls r6, r6, #2\n\
	adds r1, r3, r6\n\
	movs r0, #9\n\
_080955DA:\n\
	strb r0, [r1]\n\
_080955DC:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	b _08095634\n\
	.align 2, 0\n\
_080955E8: .4byte 0x04000050\n\
_080955EC:\n\
	ldr r4, _0809560C @ =gWrittenToBldy\n\
	ldrh r2, [r4]\n\
	cmp r2, #0xf\n\
	bhi _08095610\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #4\n\
	bne _0809562C\n\
	adds r0, r2, #1\n\
	strh r0, [r4]\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	b _0809562C\n\
	.align 2, 0\n\
_0809560C: .4byte gWrittenToBldy\n\
_08095610:\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r2, r3, r1\n\
	ldrh r0, [r2]\n\
	cmp r0, #0x5a\n\
	bne _0809562C\n\
	movs r0, #0\n\
	movs r1, #0\n\
	strh r1, [r2]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	strb r0, [r1]\n\
	movs r5, #1\n\
_0809562C:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_08095634:\n\
	adds r0, r5, #0\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

// 0x0809563C
NAKED_FUNCTION
void EndingBslCrashing(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r4, _08095654 @ =gNonGameplayRam\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #1\n\
	beq _08095668\n\
	cmp r0, #1\n\
	bgt _08095658\n\
	cmp r0, #0\n\
	beq _08095662\n\
	b _080956BC\n\
	.align 2, 0\n\
_08095654: .4byte gNonGameplayRam\n\
_08095658:\n\
	cmp r0, #2\n\
	beq _08095680\n\
	cmp r0, #3\n\
	beq _0809569C\n\
	b _080956BC\n\
_08095662:\n\
	bl EndingBslCrashingInit\n\
	b _08095674\n\
_08095668:\n\
	bl SpecialCutsceneFadeIn\n\
	ldr r0, _0809567C @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _080956BC\n\
_08095674:\n\
	movs r0, #2\n\
	strh r0, [r4, #8]\n\
	b _080956BC\n\
	.align 2, 0\n\
_0809567C: .4byte gWrittenToBldy\n\
_08095680:\n\
	bl EndingBslCrashingProcess\n\
	cmp r0, #0\n\
	beq _080956BC\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	strb r5, [r0]\n\
	subs r1, #1\n\
	adds r0, r4, r1\n\
	strb r5, [r0]\n\
	movs r0, #3\n\
	strh r0, [r4, #8]\n\
	b _080956BC\n\
_0809569C:\n\
	ldr r1, _080956AC @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _080956B0\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _080956B4\n\
	.align 2, 0\n\
_080956AC: .4byte gWrittenToBldy\n\
_080956B0:\n\
	strh r5, [r4, #8]\n\
	movs r5, #1\n\
_080956B4:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_080956BC:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

// 0x080956C4
NAKED_FUNCTION
void EndingProcessFallingBsl(void)
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
	bne _080956E6\n\
	ldrh r0, [r4, #0xc]\n\
	strh r0, [r4]\n\
	ldrh r0, [r4, #0xe]\n\
	strh r0, [r4, #2]\n\
	strh r1, [r4, #0xa]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x14]\n\
	b _08095796\n\
_080956E6:\n\
	cmp r1, #1\n\
	bne _08095744\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r4, #0x12]\n\
	cmp r0, r3\n\
	bne _08095702\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #0\n\
	bne _08095702\n\
	strb r2, [r4, #0x12]\n\
_08095702:\n\
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
	ble _0809572E\n\
	movs r0, #0\n\
	strh r0, [r4, #0xa]\n\
	movs r0, #2\n\
	strb r0, [r4, #0x14]\n\
_0809572E:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #1\n\
	bne _0809573C\n\
	ldrh r0, [r4, #6]\n\
	subs r0, #1\n\
	strh r0, [r4, #6]\n\
	b _08095796\n\
_0809573C:\n\
	ldrh r0, [r4, #6]\n\
	subs r0, #2\n\
	strh r0, [r4, #6]\n\
	b _08095796\n\
_08095744:\n\
	cmp r1, #2\n\
	bne _08095770\n\
	movs r0, #3\n\
	strb r0, [r4, #0x14]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #1\n\
	bne _0809578A\n\
	ldr r0, _08095768 @ =0x086362B8\n\
	str r0, [r4, #0x1c]\n\
	strb r2, [r4, #0x12]\n\
	strb r2, [r4, #0x11]\n\
	ldr r0, _0809576C @ =gNonGameplayRam\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	strb r1, [r0]\n\
	b _08095796\n\
	.align 2, 0\n\
_08095768: .4byte 0x086362B8\n\
_0809576C: .4byte gNonGameplayRam\n\
_08095770:\n\
	cmp r1, #3\n\
	bne _08095796\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r4, #0x12]\n\
	cmp r0, r3\n\
	bne _08095796\n\
	ldrb r0, [r1, #0xc]\n\
	cmp r0, #0\n\
	bne _08095796\n\
_0809578A:\n\
	strb r2, [r4, #0x10]\n\
	ldrb r1, [r4, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r4, #0x18]\n\
_08095796:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0809579C
NAKED_FUNCTION
void unk_9579c(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	bne _080957C8\n\
	ldrb r0, [r2, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r2, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r2, #0x12]\n\
	cmp r0, r3\n\
	bne _080957C8\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080957C8\n\
	strb r1, [r2, #0x10]\n\
	ldrb r1, [r2, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2, #0x18]\n\
_080957C8:\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x080957CC
NAKED_FUNCTION
void EndingProcessLeavingSmallShip(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	adds r5, r0, #0\n\
	ldrh r0, [r5, #0xa]\n\
	adds r2, r0, #1\n\
	strh r2, [r5, #0xa]\n\
	ldrb r1, [r5, #0x14]\n\
	cmp r1, #0\n\
	bne _080957FC\n\
	ldrh r0, [r5, #0xc]\n\
	strh r0, [r5]\n\
	ldrh r0, [r5, #0xe]\n\
	strh r0, [r5, #2]\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x96\n\
	bne _0809582A\n\
	strh r1, [r5, #0xa]\n\
	ldrb r0, [r5, #0x18]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r5, #0x18]\n\
	movs r0, #1\n\
	strb r0, [r5, #0x14]\n\
	b _0809582A\n\
_080957FC:\n\
	cmp r1, #1\n\
	bne _0809582A\n\
	lsls r0, r2, #2\n\
	ldrh r4, [r5]\n\
	subs r4, r4, r0\n\
	strh r4, [r5, #0xc]\n\
	ldrh r0, [r5, #0xa]\n\
	movs r1, #3\n\
	bl __udivsi3\n\
	ldrh r1, [r5, #2]\n\
	adds r1, r1, r0\n\
	strh r1, [r5, #0xe]\n\
	lsls r4, r4, #0x10\n\
	cmp r4, #0\n\
	bge _0809582A\n\
	movs r0, #0\n\
	strb r0, [r5, #0x10]\n\
	ldrb r1, [r5, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r5, #0x18]\n\
_0809582A:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x08095830
NAKED_FUNCTION
void EndingProcessLeavingBigShip(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r3, r0, #0\n\
	ldrh r0, [r3, #0xa]\n\
	adds r2, r0, #1\n\
	strh r2, [r3, #0xa]\n\
	ldrb r1, [r3, #0x14]\n\
	cmp r1, #0\n\
	bne _08095860\n\
	ldrh r0, [r3, #0xc]\n\
	strh r0, [r3]\n\
	ldrh r0, [r3, #0xe]\n\
	strh r0, [r3, #2]\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xf0\n\
	bne _08095890\n\
	strh r1, [r3, #0xa]\n\
	ldrb r0, [r3, #0x18]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r3, #0x18]\n\
	movs r0, #1\n\
	strb r0, [r3, #0x14]\n\
	b _08095890\n\
_08095860:\n\
	cmp r1, #1\n\
	bne _08095890\n\
	lsls r2, r2, #2\n\
	ldrh r0, [r3]\n\
	adds r2, r2, r0\n\
	strh r2, [r3, #0xc]\n\
	ldrh r0, [r3, #0xa]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	ldrh r0, [r3, #2]\n\
	subs r0, r0, r1\n\
	strh r0, [r3, #0xe]\n\
	lsls r2, r2, #0x10\n\
	movs r0, #0x8c\n\
	lsls r0, r0, #0x11\n\
	cmp r2, r0\n\
	ble _08095890\n\
	movs r0, #0\n\
	strb r0, [r3, #0x10]\n\
	ldrb r1, [r3, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r3, #0x18]\n\
_08095890:\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x08095894
NAKED_FUNCTION
void EndingProcessFrontFacingShipThrusters(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #4\n\
	adds r5, r0, #0\n\
	ldrb r0, [r5, #0x14]\n\
	cmp r0, #0\n\
	bne _080958A8\n\
	ldrh r0, [r5, #0xe]\n\
	strh r0, [r5, #2]\n\
	movs r0, #1\n\
	strb r0, [r5, #0x14]\n\
_080958A8:\n\
	mov r4, sp\n\
	adds r4, #2\n\
	movs r0, #0xc\n\
	mov r1, sp\n\
	adds r2, r4, #0\n\
	bl EndingGetPositionAndSlotOfOamByType\n\
	ldrh r0, [r5, #2]\n\
	ldrh r1, [r4]\n\
	subs r0, r0, r1\n\
	strh r0, [r5, #0xe]\n\
	add sp, #4\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080958C8
NAKED_FUNCTION
void EndingProcessFrontFacingShip(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	ldrh r0, [r3, #0xa]\n\
	adds r0, #1\n\
	movs r4, #0\n\
	strh r0, [r3, #0xa]\n\
	ldrb r1, [r3, #0x14]\n\
	cmp r1, #0\n\
	bne _080958EA\n\
	ldrh r0, [r3, #0xe]\n\
	strh r0, [r3, #2]\n\
	strh r4, [r3, #0xa]\n\
	movs r0, #4\n\
	strb r0, [r3, #0x13]\n\
	movs r0, #1\n\
	strb r0, [r3, #0x14]\n\
	b _08095944\n\
_080958EA:\n\
	cmp r1, #1\n\
	bne _0809591C\n\
	ldrb r1, [r3, #0x13]\n\
	adds r1, #1\n\
	strb r1, [r3, #0x13]\n\
	ldr r2, _08095918 @ =0x080A4FA4\n\
	ldrb r0, [r3, #0x13]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x13\n\
	ldrh r2, [r3, #2]\n\
	adds r0, r0, r2\n\
	strh r0, [r3, #0xe]\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	cmp r1, #0x40\n\
	bne _08095944\n\
	movs r0, #2\n\
	strb r0, [r3, #0x14]\n\
	strh r4, [r3, #0xa]\n\
	b _08095944\n\
	.align 2, 0\n\
_08095918: .4byte 0x080A4FA4\n\
_0809591C:\n\
	cmp r1, #2\n\
	bne _08095944\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #2\n\
	bne _08095930\n\
	strh r4, [r3, #0xa]\n\
	ldrb r0, [r3, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r3, #0x13]\n\
_08095930:\n\
	ldr r1, _08095950 @ =0x080A4FA4\n\
	ldrb r0, [r3, #0x13]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x13\n\
	ldrh r1, [r3, #2]\n\
	adds r0, r0, r1\n\
	strh r0, [r3, #0xe]\n\
_08095944:\n\
	ldr r1, _08095954 @ =0x0300122E\n\
	ldrh r0, [r3, #0xe]\n\
	strh r0, [r1]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08095950: .4byte 0x080A4FA4\n\
_08095954: .4byte 0x0300122E\n\
    .syntax divided\n");
}

// 0x08095958
NAKED_FUNCTION
void EndingBslCrashingSetupOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov r8, r1\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	mov sb, r2\n\
	lsls r3, r3, #0x18\n\
	cmp r3, #0\n\
	bne _080959BC\n\
	movs r2, #0\n\
	ldr r1, _080959B8 @ =gNonGameplayRam\n\
	movs r3, #0x8b\n\
	lsls r3, r3, #2\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080959AA\n\
	adds r4, r1, #0\n\
_0809598A:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0x13\n\
	bgt _080959FA\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809598A\n\
_080959AA:\n\
	lsls r0, r2, #0x18\n\
	asrs r1, r0, #0x18\n\
	adds r7, r0, #0\n\
	cmp r1, #0x13\n\
	ble _08095A04\n\
	b _080959FA\n\
	.align 2, 0\n\
_080959B8: .4byte gNonGameplayRam\n\
_080959BC:\n\
	movs r2, #0x13\n\
	ldr r1, _08095A00 @ =gNonGameplayRam\n\
	movs r3, #0x9b\n\
	lsls r3, r3, #3\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _080959F2\n\
	adds r4, r1, #0\n\
	movs r3, #0x8b\n\
	lsls r3, r3, #2\n\
_080959D2:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0xff\n\
	lsls r1, r1, #0x18\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	blt _080959FA\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _080959D2\n\
_080959F2:\n\
	lsls r0, r2, #0x18\n\
	adds r7, r0, #0\n\
	cmp r7, #0\n\
	bge _08095A04\n\
_080959FA:\n\
	movs r0, #0x14\n\
	b _08095C3E\n\
	.align 2, 0\n\
_08095A00: .4byte gNonGameplayRam\n\
_08095A04:\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r2, _08095A94 @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r2]\n\
	asrs r1, r7, #0x18\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r5, r0, #2\n\
	ldr r0, _08095A98 @ =0x030016A0\n\
	mov ip, r0\n\
	adds r0, r5, r0\n\
	str r0, [r2, #4]\n\
	ldr r0, _08095A9C @ =0x85000009\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	ldr r0, _08095AA0 @ =0xFFFFFDE4\n\
	add r0, ip\n\
	adds r2, r5, r0\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	mov r3, r8\n\
	strh r3, [r0]\n\
	adds r1, #2\n\
	adds r0, r2, r1\n\
	mov r3, sb\n\
	strh r3, [r0]\n\
	adds r1, #2\n\
	adds r0, r2, r1\n\
	strb r6, [r0]\n\
	movs r3, #0x8d\n\
	lsls r3, r3, #2\n\
	adds r4, r2, r3\n\
	ldrb r1, [r4]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strb r1, [r4]\n\
	cmp r6, #1\n\
	bne _08095AB4\n\
	ldr r0, _08095AA4 @ =0x00000222\n\
	adds r1, r2, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	ldr r1, _08095AA8 @ =0x00000236\n\
	adds r2, r2, r1\n\
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
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08095AAC @ =0x08636020\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08095AB0 @ =EndingProcessFallingBsl\n\
	b _08095C3A\n\
	.align 2, 0\n\
_08095A94: .4byte 0x040000D4\n\
_08095A98: .4byte 0x030016A0\n\
_08095A9C: .4byte 0x85000009\n\
_08095AA0: .4byte 0xFFFFFDE4\n\
_08095AA4: .4byte 0x00000222\n\
_08095AA8: .4byte 0x00000236\n\
_08095AAC: .4byte 0x08636020\n\
_08095AB0: .4byte EndingProcessFallingBsl\n\
_08095AB4:\n\
	cmp r6, #2\n\
	bne _08095B14\n\
	ldr r3, _08095B04 @ =0x00000222\n\
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
	ldr r0, _08095B08 @ =0x00000236\n\
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
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08095B0C @ =0x08636038\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08095B10 @ =EndingProcessFallingBsl\n\
	b _08095C3A\n\
	.align 2, 0\n\
_08095B04: .4byte 0x00000222\n\
_08095B08: .4byte 0x00000236\n\
_08095B0C: .4byte 0x08636038\n\
_08095B10: .4byte EndingProcessFallingBsl\n\
_08095B14:\n\
	cmp r6, #3\n\
	bne _08095B4C\n\
	ldr r1, _08095B40 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08095B44 @ =0x08636050\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08095B48 @ =unk_9579c\n\
	b _08095C3A\n\
	.align 2, 0\n\
_08095B40: .4byte 0x00000236\n\
_08095B44: .4byte 0x08636050\n\
_08095B48: .4byte unk_9579c\n\
_08095B4C:\n\
	cmp r6, #4\n\
	bne _08095B88\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r4]\n\
	ldr r3, _08095B7C @ =0x00000236\n\
	adds r2, r2, r3\n\
	ldrb r1, [r2]\n\
	subs r0, #0xb\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08095B80 @ =0x08636288\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08095B84 @ =EndingProcessLeavingSmallShip\n\
	b _08095C3A\n\
	.align 2, 0\n\
_08095B7C: .4byte 0x00000236\n\
_08095B80: .4byte 0x08636288\n\
_08095B84: .4byte EndingProcessLeavingSmallShip\n\
_08095B88:\n\
	cmp r6, #5\n\
	bne _08095BB0\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r4]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08095BA8 @ =0x086362A0\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08095BAC @ =EndingProcessLeavingBigShip\n\
	b _08095C3A\n\
	.align 2, 0\n\
_08095BA8: .4byte 0x086362A0\n\
_08095BAC: .4byte EndingProcessLeavingBigShip\n\
_08095BB0:\n\
	cmp r6, #0xa\n\
	bne _08095BEC\n\
	movs r0, #0x19\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	movs r0, #8\n\
	orrs r1, r0\n\
	strb r1, [r4]\n\
	ldr r0, _08095BE0 @ =0x00000236\n\
	adds r2, r2, r0\n\
	ldrb r0, [r2]\n\
	movs r1, #0xc\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08095BE4 @ =0x086363A0\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08095BE8 @ =unk_95e20\n\
	b _08095C3A\n\
	.align 2, 0\n\
_08095BE0: .4byte 0x00000236\n\
_08095BE4: .4byte 0x086363A0\n\
_08095BE8: .4byte unk_95e20\n\
_08095BEC:\n\
	cmp r6, #0xb\n\
	bne _08095C1C\n\
	ldr r1, _08095C10 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r0, [r2]\n\
	movs r1, #0xc\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08095C14 @ =0x086363B8\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08095C18 @ =EndingProcessFrontFacingShipThrusters\n\
	b _08095C3A\n\
	.align 2, 0\n\
_08095C10: .4byte 0x00000236\n\
_08095C14: .4byte 0x086363B8\n\
_08095C18: .4byte EndingProcessFrontFacingShipThrusters\n\
_08095C1C:\n\
	cmp r6, #0xc\n\
	bne _08095C3C\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r4]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _08095C4C @ =0x086363A0\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _08095C50 @ =EndingProcessFrontFacingShip\n\
_08095C3A:\n\
	str r1, [r0]\n\
_08095C3C:\n\
	lsrs r0, r7, #0x18\n\
_08095C3E:\n\
	add sp, #4\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08095C4C: .4byte 0x086363A0\n\
_08095C50: .4byte EndingProcessFrontFacingShip\n\
    .syntax divided\n");
}

// 0x08095C54
NAKED_FUNCTION
void EndingBslCrashingVblank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r3, _08095CE0 @ =0x040000D4\n\
	ldr r0, _08095CE4 @ =gOamData\n\
	str r0, [r3]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r3, #4]\n\
	ldr r0, _08095CE8 @ =0x84000100\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	ldr r2, _08095CEC @ =0x04000052\n\
	ldr r0, _08095CF0 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _08095CF4 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08095CF8 @ =0x04000054\n\
	ldr r0, _08095CFC @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x40\n\
	ldr r0, _08095D00 @ =gBg1XPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095D04 @ =gBg1YPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095D08 @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095D0C @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095D10 @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095D14 @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _08095D18 @ =gNonGameplayRam\n\
	movs r0, #0x88\n\
	lsls r0, r0, #1\n\
	adds r2, r1, r0\n\
	ldrb r0, [r2]\n\
	cmp r0, #1\n\
	bne _08095CDA\n\
	movs r0, #0\n\
	strb r0, [r2]\n\
	ldr r2, _08095D1C @ =0x00000111\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #5\n\
	ldr r1, _08095D20 @ =0x08636A38\n\
	adds r0, r0, r1\n\
	str r0, [r3]\n\
	ldr r0, _08095D24 @ =0x05000120\n\
	str r0, [r3, #4]\n\
	ldr r0, _08095D28 @ =0x84000008\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
_08095CDA:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08095CE0: .4byte 0x040000D4\n\
_08095CE4: .4byte gOamData\n\
_08095CE8: .4byte 0x84000100\n\
_08095CEC: .4byte 0x04000052\n\
_08095CF0: .4byte gWrittenToBldalpha_Evb\n\
_08095CF4: .4byte gWrittenToBldalpha_Eva\n\
_08095CF8: .4byte 0x04000054\n\
_08095CFC: .4byte gWrittenToBldy\n\
_08095D00: .4byte gBg1XPosition\n\
_08095D04: .4byte gBg1YPosition\n\
_08095D08: .4byte 0x0300122C\n\
_08095D0C: .4byte 0x0300122E\n\
_08095D10: .4byte 0x03001230\n\
_08095D14: .4byte 0x03001232\n\
_08095D18: .4byte gNonGameplayRam\n\
_08095D1C: .4byte 0x00000111\n\
_08095D20: .4byte 0x08636A38\n\
_08095D24: .4byte 0x05000120\n\
_08095D28: .4byte 0x84000008\n\
    .syntax divided\n");
}

// 0x08095D2C
NAKED_FUNCTION
void EndingShipFrontViewVblank(void)
{
    asm(" .syntax unified\n\
	ldr r1, _08095D88 @ =0x040000D4\n\
	ldr r0, _08095D8C @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _08095D90 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r2, _08095D94 @ =0x04000052\n\
	ldr r0, _08095D98 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _08095D9C @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08095DA0 @ =0x04000054\n\
	ldr r0, _08095DA4 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x40\n\
	ldr r0, _08095DA8 @ =gBg1XPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095DAC @ =gBg1YPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095DB0 @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095DB4 @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095DB8 @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08095DBC @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_08095D88: .4byte 0x040000D4\n\
_08095D8C: .4byte gOamData\n\
_08095D90: .4byte 0x84000100\n\
_08095D94: .4byte 0x04000052\n\
_08095D98: .4byte gWrittenToBldalpha_Evb\n\
_08095D9C: .4byte gWrittenToBldalpha_Eva\n\
_08095DA0: .4byte 0x04000054\n\
_08095DA4: .4byte gWrittenToBldy\n\
_08095DA8: .4byte gBg1XPosition\n\
_08095DAC: .4byte gBg1YPosition\n\
_08095DB0: .4byte 0x0300122C\n\
_08095DB4: .4byte 0x0300122E\n\
_08095DB8: .4byte 0x03001230\n\
_08095DBC: .4byte 0x03001232\n\
    .syntax divided\n");
}

// 0x08095DC0
NAKED_FUNCTION
void EndingGetPositionAndSlotOfOamByType(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r1, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	movs r1, #0\n\
	ldr r7, _08095DF8 @ =gNonGameplayRam\n\
	movs r6, #0x8b\n\
	lsls r6, r6, #2\n\
_08095DD0:\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r3, r0, r7\n\
	adds r0, r3, r6\n\
	ldrb r0, [r0]\n\
	cmp r0, r5\n\
	bne _08095E00\n\
	movs r5, #0x8a\n\
	lsls r5, r5, #2\n\
	adds r0, r3, r5\n\
	ldrh r0, [r0]\n\
	strh r0, [r4]\n\
	ldr r4, _08095DFC @ =0x0000022A\n\
	adds r0, r3, r4\n\
	ldrh r0, [r0]\n\
	strh r0, [r2]\n\
	adds r0, r1, #0\n\
	b _08095E18\n\
	.align 2, 0\n\
_08095DF8: .4byte gNonGameplayRam\n\
_08095DFC: .4byte 0x0000022A\n\
_08095E00:\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0x13\n\
	bls _08095DD0\n\
	movs r5, #0x96\n\
	lsls r5, r5, #1\n\
	adds r0, r5, #0\n\
	strh r0, [r4]\n\
	movs r0, #0xc8\n\
	strh r0, [r2]\n\
	movs r0, #0x14\n\
_08095E18:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08095E20
NAKED_FUNCTION
void unk_95e20(void)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}
