#include "cutscene.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "syscalls.h"
#include "init_helpers.h"
#include "oam.h"
#include "text.h"
#include "audio_wrappers.h"
#include "music_wrappers.h"
#include "audio/track_internal.h"
#include "new_file_intro.h"

#include "constants/audio.h"
#include "constants/text.h"

#include "data/audio.h"
#include "data/generic_data.h"
#include "data/intro_data.h"
#include "data/sprite_data.h"
#include "data/haze_data.h"

// 0x0809D0A0
NAKED_FUNCTION
void unk_9d0a0(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	ldr r1, _0809D0E4 @ =0x040000D4\n\
	ldr r0, _0809D0E8 @ =0x02001000\n\
	str r0, [r1]\n\
	ldr r0, _0809D0EC @ =0x02002000\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809D0F0 @ =0x84000054\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r3, _0809D0F4 @ =gNonGameplayRam\n\
	ldrh r0, [r3, #0xe]\n\
	ldrh r2, [r3, #0xa]\n\
	subs r1, r0, r2\n\
	lsls r1, r1, #0x10\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r7, r0, #0x10\n\
	lsrs r2, r1, #0x10\n\
	asrs r0, r1, #0x10\n\
	cmp r0, #0\n\
	bge _0809D0F8\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	movs r1, #0xa\n\
	ldrsh r0, [r3, r1]\n\
	lsls r0, r0, #1\n\
	movs r2, #0\n\
	cmp r5, r0\n\
	ble _0809D0FA\n\
	movs r2, #0xa1\n\
	b _0809D0FA\n\
	.align 2, 0\n\
_0809D0E4: .4byte 0x040000D4\n\
_0809D0E8: .4byte 0x02001000\n\
_0809D0EC: .4byte 0x02002000\n\
_0809D0F0: .4byte 0x84000054\n\
_0809D0F4: .4byte gNonGameplayRam\n\
_0809D0F8:\n\
	movs r5, #0\n\
_0809D0FA:\n\
	lsls r0, r7, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x9f\n\
	ble _0809D104\n\
	movs r7, #0xa0\n\
_0809D104:\n\
	ldr r0, _0809D1B8 @ =0x083E3294\n\
	movs r4, #0xa\n\
	ldrsh r1, [r3, r4]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r0\n\
	ldr r1, [r1]\n\
	mov ip, r1\n\
	ldr r4, _0809D1BC @ =0x02001000\n\
	movs r6, #0\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	lsls r2, r7, #0x10\n\
	cmp r6, r0\n\
	bge _0809D138\n\
	movs r7, #0\n\
	adds r1, r0, #0\n\
_0809D124:\n\
	strh r7, [r4]\n\
	adds r4, #2\n\
	lsls r0, r6, #0x10\n\
	movs r3, #0x80\n\
	lsls r3, r3, #9\n\
	adds r0, r0, r3\n\
	lsrs r6, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, r1\n\
	blt _0809D124\n\
_0809D138:\n\
	lsls r0, r6, #0x10\n\
	asrs r1, r2, #0x10\n\
	cmp r0, r2\n\
	bgt _0809D192\n\
	ldr r0, _0809D1C0 @ =gNonGameplayRam\n\
	mov r8, r0\n\
	adds r7, r1, #0\n\
_0809D146:\n\
	lsls r0, r5, #2\n\
	add r0, ip\n\
	mov r2, r8\n\
	ldrh r1, [r2, #0xc]\n\
	ldrh r2, [r0, #2]\n\
	adds r2, r1, r2\n\
	lsls r2, r2, #0x10\n\
	ldrh r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r3, r1, #0x10\n\
	lsrs r1, r2, #0x10\n\
	cmp r2, #0\n\
	bge _0809D164\n\
	movs r1, #0\n\
_0809D164:\n\
	lsls r0, r3, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xf0\n\
	ble _0809D16E\n\
	movs r3, #0xf0\n\
_0809D16E:\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #8\n\
	lsls r0, r3, #0x10\n\
	asrs r0, r0, #0x10\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	adds r4, #2\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	lsls r0, r6, #0x10\n\
	movs r3, #0x80\n\
	lsls r3, r3, #9\n\
	adds r0, r0, r3\n\
	lsrs r6, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, r7\n\
	ble _0809D146\n\
_0809D192:\n\
	lsls r1, r6, #0x10\n\
	asrs r0, r1, #0x10\n\
	cmp r0, #0x9f\n\
	bgt _0809D1AC\n\
	movs r2, #0\n\
_0809D19C:\n\
	strh r2, [r4]\n\
	adds r4, #2\n\
	movs r0, #0x80\n\
	lsls r0, r0, #9\n\
	adds r1, r1, r0\n\
	asrs r0, r1, #0x10\n\
	cmp r0, #0x9f\n\
	ble _0809D19C\n\
_0809D1AC:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D1B8: .4byte 0x083E3294\n\
_0809D1BC: .4byte 0x02001000\n\
_0809D1C0: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809D1C4
NAKED_FUNCTION
void unk_9d1c4(void)
{
    asm(" .syntax unified\n\
	ldr r0, _0809D1D8 @ =0x04000006\n\
	ldrh r0, [r0]\n\
	ldr r1, _0809D1DC @ =0x04000040\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0xf\n\
	ldr r2, _0809D1E0 @ =0x02002000\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_0809D1D8: .4byte 0x04000006\n\
_0809D1DC: .4byte 0x04000040\n\
_0809D1E0: .4byte 0x02002000\n\
    .syntax divided\n");
}

// 0x0809D1E4
NAKED_FUNCTION
void CutsceneMonologueDestroyOamOfType(u8 type)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	movs r3, #0\n\
	ldr r6, _0809D214 @ =gNonGameplayRam\n\
	movs r7, #2\n\
	rsbs r7, r7, #0\n\
	movs r5, #0\n\
_0809D1F4:\n\
	lsls r0, r3, #3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #2\n\
	adds r2, r0, r6\n\
	adds r1, r2, #0\n\
	adds r1, #0x28\n\
	ldrb r0, [r1]\n\
	cmp r0, r4\n\
	bne _0809D218\n\
	strb r5, [r1]\n\
	adds r2, #0x2e\n\
	ldrb r1, [r2]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _0809D222\n\
	.align 2, 0\n\
_0809D214: .4byte gNonGameplayRam\n\
_0809D218:\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0xf\n\
	bls _0809D1F4\n\
_0809D222:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0809D228
NAKED_FUNCTION
void CutsceneFadeIn(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl CutsceneProcessOam\n\
	bl CutsceneDrawAllOam\n\
	ldr r1, _0809D244 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _0809D23E\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
_0809D23E:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D244: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809D248
NAKED_FUNCTION
void CutsceneFadeOut(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl CutsceneProcessOam\n\
	bl CutsceneDrawAllOam\n\
	ldr r1, _0809D264 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _0809D25E\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
_0809D25E:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D264: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809D268
NAKED_FUNCTION
void CutsceneDestroyOamOfType(u8 type)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	movs r3, #0\n\
	ldr r6, _0809D298 @ =gNonGameplayRam\n\
	movs r7, #2\n\
	rsbs r7, r7, #0\n\
	movs r5, #0\n\
_0809D278:\n\
	lsls r0, r3, #3\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #2\n\
	adds r2, r0, r6\n\
	adds r1, r2, #0\n\
	adds r1, #0x28\n\
	ldrb r0, [r1]\n\
	cmp r0, r4\n\
	bne _0809D29C\n\
	strb r5, [r1]\n\
	adds r2, #0x2e\n\
	ldrb r1, [r2]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	b _0809D2A6\n\
	.align 2, 0\n\
_0809D298: .4byte gNonGameplayRam\n\
_0809D29C:\n\
	adds r0, r3, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	cmp r3, #0xf\n\
	bls _0809D278\n\
_0809D2A6:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0809D2AC
NAKED_FUNCTION
void CutsceneProcessOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r1, _0809D2F0 @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strb r0, [r1, #0x12]\n\
	movs r5, #0\n\
	adds r4, r1, #0\n\
_0809D2B8:\n\
	lsls r0, r5, #3\n\
	adds r0, r0, r5\n\
	lsls r2, r0, #2\n\
	adds r0, r2, r4\n\
	adds r0, #0x28\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0809D2E0\n\
	adds r1, r4, #0\n\
	adds r1, #0x38\n\
	adds r1, r2, r1\n\
	adds r0, r4, #0\n\
	adds r0, #0x18\n\
	adds r0, r2, r0\n\
	ldr r1, [r1]\n\
	bl _call_via_r1\n\
	ldrb r0, [r4, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x12]\n\
_0809D2E0:\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	cmp r5, #0xf\n\
	bls _0809D2B8\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D2F0: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809D2F4
NAKED_FUNCTION
void CutsceneDrawAllOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r4, #0\n\
	ldr r5, _0809D334 @ =gNonGameplayRam\n\
	adds r6, r5, #0\n\
	adds r6, #0x18\n\
_0809D2FE:\n\
	lsls r0, r4, #3\n\
	adds r0, r0, r4\n\
	lsls r1, r0, #2\n\
	adds r0, r1, r5\n\
	adds r0, #0x2e\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x1f\n\
	cmp r0, #0\n\
	beq _0809D316\n\
	adds r0, r1, r6\n\
	bl CutsceneDrawOam\n\
_0809D316:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #0xf\n\
	bls _0809D2FE\n\
	bl ResetFreeOam\n\
	ldr r0, _0809D338 @ =gNextOamSlot\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldr r0, _0809D33C @ =0x03001238\n\
	strb r1, [r0]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D334: .4byte gNonGameplayRam\n\
_0809D338: .4byte gNextOamSlot\n\
_0809D33C: .4byte 0x03001238\n\
    .syntax divided\n");
}

// 0x0809D340
NAKED_FUNCTION
void CutsceneDrawOam(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x2c\n\
	mov r8, r0\n\
	ldr r3, _0809D438 @ =gNextOamSlot\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #3\n\
	ldr r2, _0809D43C @ =gOamData\n\
	adds r0, r0, r2\n\
	mov ip, r0\n\
	mov r0, r8\n\
	ldrb r5, [r0, #0x11]\n\
	lsls r1, r5, #3\n\
	ldr r0, [r0, #0x1c]\n\
	adds r4, r0, r1\n\
	ldrb r0, [r4, #4]\n\
	mov r1, r8\n\
	ldrb r1, [r1, #0x12]\n\
	cmp r0, r1\n\
	bne _0809D37A\n\
	adds r0, r5, #1\n\
	movs r1, #0\n\
	mov r2, r8\n\
	strb r0, [r2, #0x11]\n\
	strb r1, [r2, #0x12]\n\
	adds r4, #8\n\
_0809D37A:\n\
	ldrb r1, [r4, #4]\n\
	cmp r1, #0\n\
	bne _0809D38A\n\
	mov r3, r8\n\
	ldrb r0, [r3, #0x11]\n\
	lsls r0, r0, #3\n\
	subs r4, r4, r0\n\
	strb r1, [r3, #0x11]\n\
_0809D38A:\n\
	ldr r4, [r4]\n\
	mov sl, r4\n\
	ldrh r4, [r4]\n\
	str r4, [sp, #0x18]\n\
	movs r0, #2\n\
	add sl, r0\n\
	mov r2, r8\n\
	ldrb r1, [r2, #0x16]\n\
	lsls r0, r1, #0x1d\n\
	lsrs r0, r0, #0x1e\n\
	cmp r0, #0\n\
	beq _0809D3A4\n\
	b _0809D504\n\
_0809D3A4:\n\
	movs r3, #0\n\
	str r3, [sp, #0x14]\n\
	cmp r3, r4\n\
	blt _0809D3AE\n\
	b _0809DB26\n\
_0809D3AE:\n\
	ldr r4, _0809D440 @ =0x000001FF\n\
	adds r6, r4, #0\n\
	movs r0, #3\n\
	mov sb, r0\n\
_0809D3B6:\n\
	mov r1, sl\n\
	ldrh r5, [r1]\n\
	movs r2, #2\n\
	add sl, r2\n\
	mov r3, sl\n\
	ldrh r7, [r3]\n\
	add sl, r2\n\
	mov r4, ip\n\
	strh r5, [r4]\n\
	add ip, r2\n\
	mov r0, ip\n\
	strh r7, [r0]\n\
	add ip, r2\n\
	mov r1, sl\n\
	ldrh r0, [r1]\n\
	mov r2, ip\n\
	strh r0, [r2]\n\
	movs r3, #2\n\
	add sl, r3\n\
	add ip, r3\n\
	ldr r4, _0809D438 @ =gNextOamSlot\n\
	ldrb r0, [r4]\n\
	ldr r1, [sp, #0x14]\n\
	adds r3, r0, r1\n\
	mov r2, r8\n\
	ldrb r0, [r2, #0x16]\n\
	lsls r0, r0, #0x19\n\
	lsrs r1, r0, #0x1f\n\
	cmp r1, #1\n\
	bne _0809D448\n\
	lsls r4, r3, #3\n\
	ldr r3, _0809D43C @ =gOamData\n\
	adds r2, r4, r3\n\
	ldrb r3, [r2, #3]\n\
	lsls r0, r3, #0x1b\n\
	lsrs r0, r0, #0x1f\n\
	eors r0, r1\n\
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
	ldr r0, _0809D444 @ =0x0863A184\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #3\n\
	adds r0, r7, r0\n\
	mov r2, r8\n\
	ldrh r1, [r2]\n\
	subs r0, r1, r0\n\
	ands r0, r6\n\
	str r0, [sp]\n\
	ldrh r0, [r2, #2]\n\
	adds r5, r5, r0\n\
	movs r0, #0xff\n\
	ands r5, r0\n\
	str r5, [sp, #4]\n\
	b _0809D45E\n\
	.align 2, 0\n\
_0809D438: .4byte gNextOamSlot\n\
_0809D43C: .4byte gOamData\n\
_0809D440: .4byte 0x000001FF\n\
_0809D444: .4byte 0x0863A184\n\
_0809D448:\n\
	mov r4, r8\n\
	ldrh r0, [r4, #2]\n\
	adds r5, r5, r0\n\
	movs r0, #0xff\n\
	ands r5, r0\n\
	str r5, [sp, #4]\n\
	ldrh r0, [r4]\n\
	adds r0, r7, r0\n\
	ands r0, r6\n\
	str r0, [sp]\n\
	lsls r4, r3, #3\n\
_0809D45E:\n\
	ldr r0, _0809D4F4 @ =gOamData\n\
	adds r3, r4, r0\n\
	mov r1, sp\n\
	ldrb r1, [r1, #4]\n\
	strb r1, [r3]\n\
	ldr r2, [sp]\n\
	ands r2, r6\n\
	ldrh r1, [r3, #2]\n\
	ldr r0, _0809D4F8 @ =0xFFFFFE00\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strh r0, [r3, #2]\n\
	mov r4, r8\n\
	ldrb r0, [r4, #0x18]\n\
	lsls r0, r0, #0x1c\n\
	lsrs r0, r0, #0x1e\n\
	mov r1, sb\n\
	ands r0, r1\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r3, #5]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r3, #5]\n\
	lsrs r2, r1, #4\n\
	ldrb r0, [r4, #0x18]\n\
	lsrs r0, r0, #4\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #4\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	orrs r1, r2\n\
	strb r1, [r3, #5]\n\
	ldrh r5, [r3, #4]\n\
	lsls r2, r5, #0x16\n\
	lsrs r2, r2, #0x16\n\
	ldrb r4, [r4, #0x17]\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0x18]\n\
	movs r1, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	orrs r0, r4\n\
	adds r2, r2, r0\n\
	ldr r4, _0809D4FC @ =0x000003FF\n\
	adds r0, r4, #0\n\
	ands r2, r0\n\
	ldr r0, _0809D500 @ =0xFFFFFC00\n\
	ands r0, r5\n\
	orrs r0, r2\n\
	strh r0, [r3, #4]\n\
	mov r0, r8\n\
	ldrb r1, [r0, #0x16]\n\
	lsls r1, r1, #0x1b\n\
	lsrs r1, r1, #0x1e\n\
	mov r2, sb\n\
	ands r1, r2\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r3, #1]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, #1]\n\
	movs r3, #2\n\
	add ip, r3\n\
	ldr r4, [sp, #0x14]\n\
	adds r4, #1\n\
	str r4, [sp, #0x14]\n\
	ldr r0, [sp, #0x18]\n\
	cmp r4, r0\n\
	bge _0809D4F2\n\
	b _0809D3B6\n\
_0809D4F2:\n\
	b _0809DB26\n\
	.align 2, 0\n\
_0809D4F4: .4byte gOamData\n\
_0809D4F8: .4byte 0xFFFFFE00\n\
_0809D4FC: .4byte 0x000003FF\n\
_0809D500: .4byte 0xFFFFFC00\n\
_0809D504:\n\
	cmp r0, #1\n\
	beq _0809D50A\n\
	b _0809D7D4\n\
_0809D50A:\n\
	mov r2, r8\n\
	ldrh r0, [r2]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp]\n\
	ldrh r0, [r2, #2]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #4]\n\
	lsls r0, r1, #0x19\n\
	cmp r0, #0\n\
	blt _0809D52C\n\
	ldrh r3, [r2, #4]\n\
	str r3, [sp, #0xc]\n\
	b _0809D538\n\
_0809D52C:\n\
	mov r4, r8\n\
	ldrh r0, [r4, #4]\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0xc]\n\
_0809D538:\n\
	lsls r0, r1, #0x18\n\
	cmp r0, #0\n\
	blt _0809D544\n\
	mov r0, r8\n\
	ldrh r0, [r0, #4]\n\
	b _0809D54E\n\
_0809D544:\n\
	mov r1, r8\n\
	ldrh r0, [r1, #4]\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
_0809D54E:\n\
	str r0, [sp, #0x10]\n\
	movs r2, #0\n\
	b _0809D782\n\
_0809D554:\n\
	mov r4, sl\n\
	ldrh r5, [r4]\n\
	movs r0, #2\n\
	add sl, r0\n\
	mov r1, sl\n\
	ldrh r7, [r1]\n\
	add sl, r0\n\
	mov r2, ip\n\
	strh r5, [r2]\n\
	add ip, r0\n\
	mov r3, ip\n\
	strh r7, [r3]\n\
	add ip, r0\n\
	mov r4, sl\n\
	ldrh r0, [r4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	movs r2, #2\n\
	add sl, r2\n\
	add ip, r2\n\
	ldr r3, _0809D7AC @ =gNextOamSlot\n\
	ldrb r0, [r3]\n\
	ldr r4, [sp, #0x14]\n\
	adds r3, r0, r4\n\
	lsls r0, r3, #3\n\
	ldr r1, _0809D7B0 @ =gOamData\n\
	adds r6, r0, r1\n\
	ldrb r2, [r6, #3]\n\
	mov sb, r2\n\
	mov r3, sb\n\
	lsrs r1, r3, #6\n\
	ldrb r0, [r6, #1]\n\
	lsrs r0, r0, #6\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldr r4, _0809D7B4 @ =0x0863A184\n\
	adds r0, r1, r4\n\
	ldrb r2, [r0]\n\
	ldr r0, _0809D7B8 @ =0x0863A190\n\
	adds r1, r1, r0\n\
	ldrb r3, [r1]\n\
	ldr r1, [sp, #4]\n\
	adds r5, r5, r1\n\
	movs r0, #0xff\n\
	ands r5, r0\n\
	ldr r0, [sp]\n\
	adds r4, r7, r0\n\
	ldr r1, _0809D7BC @ =0x000001FF\n\
	adds r0, r1, #0\n\
	ands r4, r0\n\
	ldr r0, [sp]\n\
	subs r1, r4, r0\n\
	lsls r2, r2, #2\n\
	str r2, [sp, #0x1c]\n\
	adds r1, r2, r1\n\
	ldr r0, [sp, #4]\n\
	subs r2, r5, r0\n\
	lsls r3, r3, #2\n\
	str r3, [sp, #0x20]\n\
	adds r2, r3, r2\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r3, [sp, #0xc]\n\
	lsls r0, r3, #0x10\n\
	asrs r3, r0, #0x10\n\
	adds r0, r1, #0\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #8]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	ldr r1, [sp, #0x10]\n\
	lsls r0, r1, #0x10\n\
	asrs r7, r0, #0x10\n\
	adds r0, r2, #0\n\
	muls r0, r7, r0\n\
	asrs r0, r0, #8\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	mov r1, sb\n\
	lsls r0, r1, #0x1b\n\
	cmp r0, #0\n\
	bge _0809D612\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r6, #3]\n\
	rsbs r0, r3, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0xc]\n\
_0809D612:\n\
	ldrb r1, [r6, #3]\n\
	lsls r0, r1, #0x1a\n\
	cmp r0, #0\n\
	bge _0809D62A\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r6, #3]\n\
	rsbs r0, r7, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x10]\n\
_0809D62A:\n\
	lsls r1, r4, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r3, [sp, #8]\n\
	lsls r0, r3, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r4, r1, #0x10\n\
	lsls r1, r5, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r5, r1, #0x10\n\
	ldr r0, [sp]\n\
	subs r4, r4, r0\n\
	ldr r1, [sp, #0x1c]\n\
	adds r4, r1, r4\n\
	ldr r2, [sp, #4]\n\
	subs r3, r5, r2\n\
	ldr r0, [sp, #0x20]\n\
	adds r3, r0, r3\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	mov r2, r8\n\
	ldrb r1, [r2, #0x15]\n\
	adds r0, r1, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r2, _0809D7C0 @ =0x080A4FA4\n\
	adds r0, r0, r2\n\
	movs r2, #0\n\
	ldrsh r5, [r0, r2]\n\
	adds r2, r4, #0\n\
	muls r2, r5, r2\n\
	lsls r3, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	lsls r1, r1, #1\n\
	ldr r0, _0809D7C0 @ =0x080A4FA4\n\
	adds r1, r1, r0\n\
	movs r0, #0\n\
	ldrsh r1, [r1, r0]\n\
	adds r0, r3, #0\n\
	muls r0, r1, r0\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #8\n\
	adds r0, r4, #0\n\
	muls r0, r1, r0\n\
	adds r1, r3, #0\n\
	muls r1, r5, r1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	asrs r2, r2, #0x10\n\
	ldr r1, [sp, #0x1c]\n\
	subs r2, r2, r1\n\
	asrs r0, r0, #0x10\n\
	ldr r3, [sp, #0x20]\n\
	subs r0, r0, r3\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	ldr r4, [sp, #4]\n\
	adds r0, r5, r4\n\
	subs r0, #0x40\n\
	strb r0, [r6]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	ldr r0, [sp]\n\
	adds r2, r2, r0\n\
	subs r2, #0x40\n\
	ldr r0, _0809D7BC @ =0x000001FF\n\
	ands r2, r0\n\
	ldrh r1, [r6, #2]\n\
	ldr r0, _0809D7C4 @ =0xFFFFFE00\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strh r0, [r6, #2]\n\
	ldrb r1, [r6, #1]\n\
	movs r0, #4\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strb r0, [r6, #1]\n\
	ldr r2, _0809D7C8 @ =0x03001238\n\
	ldrb r1, [r2]\n\
	movs r2, #0x10\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809D6E8\n\
	ldrb r0, [r6, #3]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	strb r0, [r6, #3]\n\
_0809D6E8:\n\
	ldr r3, _0809D7C8 @ =0x03001238\n\
	ldrb r1, [r3]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809D6FA\n\
	ldrb r0, [r6, #3]\n\
	orrs r0, r2\n\
	strb r0, [r6, #3]\n\
_0809D6FA:\n\
	ldr r4, _0809D7C8 @ =0x03001238\n\
	ldrb r0, [r4]\n\
	movs r1, #7\n\
	ands r1, r0\n\
	lsls r1, r1, #1\n\
	ldrb r2, [r6, #3]\n\
	movs r0, #0xf\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r6, #3]\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0x18]\n\
	lsls r0, r0, #0x1c\n\
	lsrs r0, r0, #0x1e\n\
	movs r2, #3\n\
	ands r0, r2\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r6, #5]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r6, #5]\n\
	lsrs r2, r1, #4\n\
	mov r3, r8\n\
	ldrb r0, [r3, #0x18]\n\
	lsrs r0, r0, #4\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #4\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	orrs r1, r2\n\
	strb r1, [r6, #5]\n\
	ldrh r4, [r6, #4]\n\
	lsls r2, r4, #0x16\n\
	lsrs r2, r2, #0x16\n\
	ldrb r3, [r3, #0x17]\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0x18]\n\
	movs r1, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	orrs r0, r3\n\
	adds r2, r2, r0\n\
	ldr r3, _0809D7CC @ =0x000003FF\n\
	adds r0, r3, #0\n\
	ands r2, r0\n\
	ldr r0, _0809D7D0 @ =0xFFFFFC00\n\
	ands r0, r4\n\
	orrs r0, r2\n\
	strh r0, [r6, #4]\n\
	mov r4, r8\n\
	ldrb r1, [r4, #0x16]\n\
	lsls r1, r1, #0x1b\n\
	lsrs r1, r1, #0x1e\n\
	movs r0, #3\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r6, #1]\n\
	subs r0, #0x10\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r6, #1]\n\
	movs r1, #2\n\
	add ip, r1\n\
	ldr r2, [sp, #0x14]\n\
	adds r2, #1\n\
_0809D782:\n\
	str r2, [sp, #0x14]\n\
	ldr r3, [sp, #0x18]\n\
	cmp r2, r3\n\
	bge _0809D78C\n\
	b _0809D554\n\
_0809D78C:\n\
	ldr r4, _0809D7C8 @ =0x03001238\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r7, r0, #0x18\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0x15]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r2, _0809D7C0 @ =0x080A4FA4\n\
	adds r0, r0, r2\n\
	movs r3, #0\n\
	ldrsh r5, [r0, r3]\n\
	ldr r0, [sp, #0xc]\n\
	lsls r4, r0, #0x10\n\
	b _0809DA7E\n\
	.align 2, 0\n\
_0809D7AC: .4byte gNextOamSlot\n\
_0809D7B0: .4byte gOamData\n\
_0809D7B4: .4byte 0x0863A184\n\
_0809D7B8: .4byte 0x0863A190\n\
_0809D7BC: .4byte 0x000001FF\n\
_0809D7C0: .4byte 0x080A4FA4\n\
_0809D7C4: .4byte 0xFFFFFE00\n\
_0809D7C8: .4byte 0x03001238\n\
_0809D7CC: .4byte 0x000003FF\n\
_0809D7D0: .4byte 0xFFFFFC00\n\
_0809D7D4:\n\
	cmp r0, #3\n\
	beq _0809D7DA\n\
	b _0809DB26\n\
_0809D7DA:\n\
	mov r3, r8\n\
	ldrh r0, [r3]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp]\n\
	ldrh r0, [r3, #2]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #4]\n\
	lsls r0, r1, #0x19\n\
	cmp r0, #0\n\
	blt _0809D7FC\n\
	ldrh r4, [r3, #4]\n\
	str r4, [sp, #0xc]\n\
	b _0809D808\n\
_0809D7FC:\n\
	mov r2, r8\n\
	ldrh r0, [r2, #4]\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0xc]\n\
_0809D808:\n\
	lsls r0, r1, #0x18\n\
	cmp r0, #0\n\
	blt _0809D816\n\
	mov r3, r8\n\
	ldrh r3, [r3, #4]\n\
	str r3, [sp, #0x10]\n\
	b _0809D822\n\
_0809D816:\n\
	mov r4, r8\n\
	ldrh r0, [r4, #4]\n\
	rsbs r0, r0, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x10]\n\
_0809D822:\n\
	movs r0, #0\n\
	str r0, [sp, #0x14]\n\
	ldr r1, [sp, #0x18]\n\
	cmp r0, r1\n\
	blt _0809D82E\n\
	b _0809DA62\n\
_0809D82E:\n\
	mov r2, sl\n\
	ldrh r5, [r2]\n\
	movs r3, #2\n\
	add sl, r3\n\
	mov r4, sl\n\
	ldrh r7, [r4]\n\
	add sl, r3\n\
	mov r0, ip\n\
	strh r5, [r0]\n\
	add ip, r3\n\
	mov r1, ip\n\
	strh r7, [r1]\n\
	add ip, r3\n\
	mov r2, sl\n\
	ldrh r0, [r2]\n\
	mov r3, ip\n\
	strh r0, [r3]\n\
	movs r4, #2\n\
	add sl, r4\n\
	add ip, r4\n\
	ldr r1, _0809DB48 @ =gNextOamSlot\n\
	ldrb r0, [r1]\n\
	ldr r2, [sp, #0x14]\n\
	adds r3, r0, r2\n\
	lsls r0, r3, #3\n\
	ldr r3, _0809DB4C @ =gOamData\n\
	adds r6, r0, r3\n\
	ldrb r4, [r6, #3]\n\
	mov sb, r4\n\
	mov r0, sb\n\
	lsrs r1, r0, #6\n\
	ldrb r0, [r6, #1]\n\
	lsrs r0, r0, #6\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	ldr r2, _0809DB50 @ =0x0863A184\n\
	adds r0, r1, r2\n\
	ldrb r2, [r0]\n\
	ldr r3, _0809DB54 @ =0x0863A190\n\
	adds r1, r1, r3\n\
	ldrb r3, [r1]\n\
	ldr r4, [sp, #4]\n\
	adds r5, r5, r4\n\
	movs r0, #0xff\n\
	ands r5, r0\n\
	ldr r0, [sp]\n\
	adds r4, r7, r0\n\
	ldr r1, _0809DB58 @ =0x000001FF\n\
	adds r0, r1, #0\n\
	ands r4, r0\n\
	ldr r0, [sp]\n\
	subs r1, r4, r0\n\
	lsls r2, r2, #2\n\
	str r2, [sp, #0x24]\n\
	adds r1, r2, r1\n\
	ldr r0, [sp, #4]\n\
	subs r2, r5, r0\n\
	lsls r3, r3, #2\n\
	str r3, [sp, #0x28]\n\
	adds r2, r3, r2\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r3, [sp, #0xc]\n\
	lsls r0, r3, #0x10\n\
	asrs r3, r0, #0x10\n\
	adds r0, r1, #0\n\
	muls r0, r3, r0\n\
	asrs r0, r0, #8\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #8]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	ldr r1, [sp, #0x10]\n\
	lsls r0, r1, #0x10\n\
	asrs r7, r0, #0x10\n\
	adds r0, r2, #0\n\
	muls r0, r7, r0\n\
	asrs r0, r0, #8\n\
	subs r0, r0, r2\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	mov r1, sb\n\
	lsls r0, r1, #0x1b\n\
	cmp r0, #0\n\
	bge _0809D8EC\n\
	movs r0, #0x11\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r6, #3]\n\
	rsbs r0, r3, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0xc]\n\
_0809D8EC:\n\
	ldrb r1, [r6, #3]\n\
	lsls r0, r1, #0x1a\n\
	cmp r0, #0\n\
	bge _0809D904\n\
	movs r0, #0x21\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r6, #3]\n\
	rsbs r0, r7, #0\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	str r0, [sp, #0x10]\n\
_0809D904:\n\
	lsls r1, r4, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldr r3, [sp, #8]\n\
	lsls r0, r3, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r4, r1, #0x10\n\
	lsls r1, r5, #0x10\n\
	asrs r1, r1, #0x10\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #0x10\n\
	lsrs r5, r1, #0x10\n\
	ldr r0, [sp]\n\
	subs r4, r4, r0\n\
	ldr r1, [sp, #0x24]\n\
	adds r4, r1, r4\n\
	ldr r2, [sp, #4]\n\
	subs r3, r5, r2\n\
	ldr r0, [sp, #0x28]\n\
	adds r3, r0, r3\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	mov r2, r8\n\
	ldrb r1, [r2, #0x15]\n\
	adds r0, r1, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r2, _0809DB5C @ =0x080A4FA4\n\
	adds r0, r0, r2\n\
	movs r2, #0\n\
	ldrsh r5, [r0, r2]\n\
	adds r2, r4, #0\n\
	muls r2, r5, r2\n\
	lsls r3, r3, #0x10\n\
	asrs r3, r3, #0x10\n\
	lsls r1, r1, #1\n\
	ldr r0, _0809DB5C @ =0x080A4FA4\n\
	adds r1, r1, r0\n\
	movs r0, #0\n\
	ldrsh r1, [r1, r0]\n\
	adds r0, r3, #0\n\
	muls r0, r1, r0\n\
	subs r2, r2, r0\n\
	lsls r2, r2, #8\n\
	adds r0, r4, #0\n\
	muls r0, r1, r0\n\
	adds r1, r3, #0\n\
	muls r1, r5, r1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #8\n\
	ldr r3, [sp, #0x24]\n\
	lsls r1, r3, #1\n\
	asrs r2, r2, #0x10\n\
	subs r2, r2, r1\n\
	ldr r4, [sp, #0x28]\n\
	lsls r1, r4, #1\n\
	asrs r0, r0, #0x10\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	ldr r1, [sp, #4]\n\
	adds r0, r5, r1\n\
	subs r0, #0x40\n\
	strb r0, [r6]\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	ldr r3, [sp]\n\
	adds r2, r2, r3\n\
	subs r2, #0x40\n\
	ldr r0, _0809DB58 @ =0x000001FF\n\
	ands r2, r0\n\
	ldrh r1, [r6, #2]\n\
	ldr r0, _0809DB60 @ =0xFFFFFE00\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strh r0, [r6, #2]\n\
	ldrb r0, [r6, #1]\n\
	movs r5, #3\n\
	orrs r0, r5\n\
	strb r0, [r6, #1]\n\
	ldr r4, _0809DB64 @ =0x03001238\n\
	ldrb r1, [r4]\n\
	movs r2, #0x10\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809D9C0\n\
	ldrb r0, [r6, #3]\n\
	movs r1, #0x20\n\
	orrs r0, r1\n\
	strb r0, [r6, #3]\n\
_0809D9C0:\n\
	ldr r0, _0809DB64 @ =0x03001238\n\
	ldrb r1, [r0]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809D9D2\n\
	ldrb r0, [r6, #3]\n\
	orrs r0, r2\n\
	strb r0, [r6, #3]\n\
_0809D9D2:\n\
	ldr r1, _0809DB64 @ =0x03001238\n\
	ldrb r0, [r1]\n\
	movs r1, #7\n\
	ands r1, r0\n\
	lsls r1, r1, #1\n\
	ldrb r2, [r6, #3]\n\
	movs r0, #0xf\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r6, #3]\n\
	mov r2, r8\n\
	ldrb r0, [r2, #0x18]\n\
	lsls r0, r0, #0x1c\n\
	lsrs r0, r0, #0x1e\n\
	ands r0, r5\n\
	lsls r0, r0, #2\n\
	ldrb r2, [r6, #5]\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r1, r2\n\
	orrs r1, r0\n\
	strb r1, [r6, #5]\n\
	lsrs r2, r1, #4\n\
	mov r3, r8\n\
	ldrb r0, [r3, #0x18]\n\
	lsrs r0, r0, #4\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #4\n\
	movs r0, #0xf\n\
	ands r1, r0\n\
	orrs r1, r2\n\
	strb r1, [r6, #5]\n\
	ldrh r4, [r6, #4]\n\
	lsls r2, r4, #0x16\n\
	lsrs r2, r2, #0x16\n\
	ldrb r3, [r3, #0x17]\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0x18]\n\
	movs r1, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #8\n\
	orrs r0, r3\n\
	adds r2, r2, r0\n\
	ldr r3, _0809DB68 @ =0x000003FF\n\
	adds r0, r3, #0\n\
	ands r2, r0\n\
	ldr r0, _0809DB6C @ =0xFFFFFC00\n\
	ands r0, r4\n\
	orrs r0, r2\n\
	strh r0, [r6, #4]\n\
	mov r4, r8\n\
	ldrb r1, [r4, #0x16]\n\
	lsls r1, r1, #0x1b\n\
	lsrs r1, r1, #0x1e\n\
	ands r1, r5\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r6, #1]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r6, #1]\n\
	movs r0, #2\n\
	add ip, r0\n\
	ldr r1, [sp, #0x14]\n\
	adds r1, #1\n\
	str r1, [sp, #0x14]\n\
	ldr r2, [sp, #0x18]\n\
	cmp r1, r2\n\
	bge _0809DA62\n\
	b _0809D82E\n\
_0809DA62:\n\
	ldr r3, _0809DB64 @ =0x03001238\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #0x1a\n\
	lsrs r7, r0, #0x18\n\
	mov r4, r8\n\
	ldrb r0, [r4, #0x15]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r1, _0809DB5C @ =0x080A4FA4\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	ldrsh r5, [r0, r2]\n\
	ldr r3, [sp, #0xc]\n\
	lsls r4, r3, #0x10\n\
_0809DA7E:\n\
	asrs r4, r4, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl FixedMultiplication\n\
	ldr r6, _0809DB4C @ =gOamData\n\
	lsls r1, r7, #3\n\
	adds r1, r1, r6\n\
	strh r0, [r1, #6]\n\
	mov r1, r8\n\
	ldrb r0, [r1, #0x15]\n\
	lsls r0, r0, #1\n\
	ldr r2, _0809DB5C @ =0x080A4FA4\n\
	adds r0, r0, r2\n\
	movs r3, #0\n\
	ldrsh r5, [r0, r3]\n\
	adds r0, r4, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r5, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #1\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	strh r0, [r1, #6]\n\
	mov r4, r8\n\
	ldrb r0, [r4, #0x15]\n\
	lsls r0, r0, #1\n\
	ldr r1, _0809DB5C @ =0x080A4FA4\n\
	adds r0, r0, r1\n\
	ldrh r4, [r0]\n\
	rsbs r4, r4, #0\n\
	lsls r4, r4, #0x10\n\
	asrs r4, r4, #0x10\n\
	ldr r2, [sp, #0x10]\n\
	lsls r5, r2, #0x10\n\
	asrs r5, r5, #0x10\n\
	adds r0, r5, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #2\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	strh r0, [r1, #6]\n\
	mov r3, r8\n\
	ldrb r0, [r3, #0x15]\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	ldr r4, _0809DB5C @ =0x080A4FA4\n\
	adds r0, r0, r4\n\
	movs r1, #0\n\
	ldrsh r4, [r0, r1]\n\
	adds r0, r5, #0\n\
	bl FixedInverse\n\
	adds r1, r0, #0\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	adds r0, r4, #0\n\
	bl FixedMultiplication\n\
	adds r1, r7, #3\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r6\n\
	strh r0, [r1, #6]\n\
	ldr r2, _0809DB64 @ =0x03001238\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
_0809DB26:\n\
	ldr r0, _0809DB48 @ =gNextOamSlot\n\
	ldrb r1, [r0]\n\
	ldr r3, [sp, #0x18]\n\
	adds r1, r1, r3\n\
	strb r1, [r0]\n\
	mov r4, r8\n\
	ldrb r0, [r4, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x12]\n\
	add sp, #0x2c\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809DB48: .4byte gNextOamSlot\n\
_0809DB4C: .4byte gOamData\n\
_0809DB50: .4byte 0x0863A184\n\
_0809DB54: .4byte 0x0863A190\n\
_0809DB58: .4byte 0x000001FF\n\
_0809DB5C: .4byte 0x080A4FA4\n\
_0809DB60: .4byte 0xFFFFFE00\n\
_0809DB64: .4byte 0x03001238\n\
_0809DB68: .4byte 0x000003FF\n\
_0809DB6C: .4byte 0xFFFFFC00\n\
    .syntax divided\n");
}

// 0x0809DB70
NAKED_FUNCTION
void unk_9db70(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}
