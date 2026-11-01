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

// 0x0809C1C8
NAKED_FUNCTION
boolu32 CutsceneBslExploding(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r6, #0\n\
	ldr r4, _0809C1E0 @ =gNonGameplayRam\n\
	ldrh r0, [r4]\n\
	cmp r0, #1\n\
	beq _0809C1F8\n\
	cmp r0, #1\n\
	bgt _0809C1E4\n\
	cmp r0, #0\n\
	beq _0809C1EE\n\
	b _0809C246\n\
	.align 2, 0\n\
_0809C1E0: .4byte gNonGameplayRam\n\
_0809C1E4:\n\
	cmp r0, #2\n\
	beq _0809C220\n\
	cmp r0, #3\n\
	beq _0809C238\n\
	b _0809C246\n\
_0809C1EE:\n\
	movs r0, #1\n\
	strh r0, [r4]\n\
	bl CutsceneBslExplodingInit\n\
	b _0809C246\n\
_0809C1F8:\n\
	ldr r5, _0809C218 @ =gWrittenToBldy\n\
	ldrh r0, [r5]\n\
	cmp r0, #0x10\n\
	bne _0809C206\n\
	ldr r0, _0809C21C @ =0x00000247\n\
	bl SoundPlay_3b1c\n\
_0809C206:\n\
	bl CutsceneFadeIn\n\
	ldrh r0, [r5]\n\
	cmp r0, #0\n\
	bne _0809C246\n\
	ldrh r0, [r4]\n\
	adds r0, #1\n\
	strh r0, [r4]\n\
	b _0809C246\n\
	.align 2, 0\n\
_0809C218: .4byte gWrittenToBldy\n\
_0809C21C: .4byte 0x00000247\n\
_0809C220:\n\
	bl CutsceneBslExplodingProcess\n\
	cmp r0, #0\n\
	beq _0809C246\n\
	movs r0, #3\n\
	strh r0, [r4]\n\
	ldr r1, _0809C234 @ =0x04000050\n\
	movs r0, #0xbf\n\
	strh r0, [r1]\n\
	b _0809C246\n\
	.align 2, 0\n\
_0809C234: .4byte 0x04000050\n\
_0809C238:\n\
	bl CutsceneFadeOut\n\
	ldr r0, _0809C250 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0x10\n\
	bne _0809C246\n\
	movs r6, #1\n\
_0809C246:\n\
	adds r0, r6, #0\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809C250: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809C254
NAKED_FUNCTION
void CutsceneBslExplodingInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	ldr r3, _0809C360 @ =0x04000208\n\
	movs r5, #0\n\
	strh r5, [r3]\n\
	ldr r2, _0809C364 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809C368 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _0809C36C @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809C370 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _0809C374 @ =unk_9c92c\n\
	bl CallbackSetVBlank\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x13\n\
	mov r8, r0\n\
	strh r5, [r0]\n\
	ldr r0, _0809C378 @ =0x0867D7CC\n\
	ldr r1, _0809C37C @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r4, _0809C380 @ =0x040000D4\n\
	ldr r0, _0809C384 @ =0x0868121C\n\
	str r0, [r4]\n\
	ldr r0, _0809C388 @ =0x05000200\n\
	str r0, [r4, #4]\n\
	ldr r6, _0809C38C @ =0x84000080\n\
	str r6, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809C390 @ =0x08679420\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C394 @ =0x08681A1C\n\
	ldr r1, _0809C398 @ =0x0600E000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C39C @ =0x086820A4\n\
	ldr r1, _0809C3A0 @ =0x0600E800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C3A4 @ =0x086827A8\n\
	ldr r1, _0809C3A8 @ =0x0600F000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C3AC @ =0x08682BFC\n\
	ldr r1, _0809C3B0 @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809C3B4 @ =0x0868259C\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	str r6, [r4, #8]\n\
	ldr r1, [r4, #8]\n\
	strh r5, [r0]\n\
	ldr r1, _0809C3B8 @ =0x04000008\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _0809C3BC @ =0x00001D03\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	adds r2, #0xfd\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _0809C3C0 @ =0x00001F03\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #5\n\
	adds r0, r1, #0\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
	ldr r0, _0809C3C4 @ =gWrittenToBldy\n\
	movs r2, #0x10\n\
	strh r2, [r0]\n\
	ldr r1, _0809C3C8 @ =gWrittenToBldalpha_Eva\n\
	movs r0, #8\n\
	strh r0, [r1]\n\
	ldr r0, _0809C3CC @ =gWrittenToBldalpha_Evb\n\
	strh r2, [r0]\n\
	movs r0, #1\n\
	movs r1, #0\n\
	movs r2, #0\n\
	movs r3, #0\n\
	bl CutsceneBslExplodingSetupOam\n\
	movs r0, #0x14\n\
	movs r1, #0x70\n\
	movs r2, #0x58\n\
	movs r3, #0\n\
	bl CutsceneBslExplodingSetupOam\n\
	ldr r0, _0809C3D0 @ =gNonGameplayRam\n\
	movs r1, #0\n\
	strh r1, [r0, #0xa]\n\
	strh r1, [r0, #0xc]\n\
	movs r1, #0xc\n\
	ldrsh r0, [r0, r1]\n\
	lsls r0, r0, #5\n\
	ldr r1, _0809C3D4 @ =0x0868101C\n\
	adds r0, r0, r1\n\
	str r0, [r4]\n\
	ldr r0, _0809C3D8 @ =0x05000120\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809C3DC @ =0x84000008\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	bl CutsceneDrawAllOam\n\
	ldr r0, _0809C3E0 @ =CutsceneBslExplodingVblank\n\
	bl CallbackSetVBlank\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809C360: .4byte 0x04000208\n\
_0809C364: .4byte 0x04000004\n\
_0809C368: .4byte 0x0000FFEF\n\
_0809C36C: .4byte 0x04000200\n\
_0809C370: .4byte 0x0000FFFD\n\
_0809C374: .4byte unk_9c92c\n\
_0809C378: .4byte 0x0867D7CC\n\
_0809C37C: .4byte 0x06010000\n\
_0809C380: .4byte 0x040000D4\n\
_0809C384: .4byte 0x0868121C\n\
_0809C388: .4byte 0x05000200\n\
_0809C38C: .4byte 0x84000080\n\
_0809C390: .4byte 0x08679420\n\
_0809C394: .4byte 0x08681A1C\n\
_0809C398: .4byte 0x0600E000\n\
_0809C39C: .4byte 0x086820A4\n\
_0809C3A0: .4byte 0x0600E800\n\
_0809C3A4: .4byte 0x086827A8\n\
_0809C3A8: .4byte 0x0600F000\n\
_0809C3AC: .4byte 0x08682BFC\n\
_0809C3B0: .4byte 0x0600F800\n\
_0809C3B4: .4byte 0x0868259C\n\
_0809C3B8: .4byte 0x04000008\n\
_0809C3BC: .4byte 0x00001D03\n\
_0809C3C0: .4byte 0x00001F03\n\
_0809C3C4: .4byte gWrittenToBldy\n\
_0809C3C8: .4byte gWrittenToBldalpha_Eva\n\
_0809C3CC: .4byte gWrittenToBldalpha_Evb\n\
_0809C3D0: .4byte gNonGameplayRam\n\
_0809C3D4: .4byte 0x0868101C\n\
_0809C3D8: .4byte 0x05000120\n\
_0809C3DC: .4byte 0x84000008\n\
_0809C3E0: .4byte CutsceneBslExplodingVblank\n\
    .syntax divided\n");
}

// 0x0809C3E4
NAKED_FUNCTION
boolu32 CutsceneBslExplodingProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r1, _0809C404 @ =gNonGameplayRam\n\
	ldrh r0, [r1, #8]\n\
	adds r0, #1\n\
	strh r0, [r1, #8]\n\
	ldrb r0, [r1, #0x10]\n\
	adds r4, r1, #0\n\
	cmp r0, #6\n\
	bls _0809C3FA\n\
	b _0809C5E2\n\
_0809C3FA:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0809C408 @ =_0809C40C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0809C404: .4byte gNonGameplayRam\n\
_0809C408: .4byte _0809C40C\n\
_0809C40C: @ jump table\n\
	.4byte _0809C428 @ case 0\n\
	.4byte _0809C432 @ case 1\n\
	.4byte _0809C464 @ case 2\n\
	.4byte _0809C4CC @ case 3\n\
	.4byte _0809C4FC @ case 4\n\
	.4byte _0809C52C @ case 5\n\
	.4byte _0809C5B4 @ case 6\n\
_0809C428:\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x10]\n\
	b _0809C5E2\n\
_0809C432:\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #0xf\n\
	beq _0809C43A\n\
	b _0809C5E2\n\
_0809C43A:\n\
	ldr r1, _0809C45C @ =0x04000050\n\
	ldr r2, _0809C460 @ =0x00001C44\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #3\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	movs r0, #2\n\
	strb r0, [r4, #0x10]\n\
	b _0809C5E2\n\
	.align 2, 0\n\
_0809C45C: .4byte 0x04000050\n\
_0809C460: .4byte 0x00001C44\n\
_0809C464:\n\
	ldr r2, _0809C484 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #0xf\n\
	bhi _0809C48C\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #1\n\
	bne _0809C47A\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	adds r0, r1, #2\n\
	strh r0, [r2]\n\
_0809C47A:\n\
	ldr r1, _0809C488 @ =gWrittenToBldy\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	b _0809C5E2\n\
	.align 2, 0\n\
_0809C484: .4byte gWrittenToBldalpha_Eva\n\
_0809C488: .4byte gWrittenToBldy\n\
_0809C48C:\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #0x28\n\
	beq _0809C494\n\
	b _0809C5E2\n\
_0809C494:\n\
	ldr r1, _0809C4C8 @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	subs r1, #0x50\n\
	movs r2, #0x90\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
	bl CutsceneDestroyOamOfType\n\
	movs r0, #0x14\n\
	bl CutsceneDestroyOamOfType\n\
	movs r0, #0x15\n\
	movs r1, #0x78\n\
	movs r2, #0x5a\n\
	movs r3, #1\n\
	bl CutsceneBslExplodingSetupOam\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	movs r0, #3\n\
	strb r0, [r4, #0x10]\n\
	b _0809C5E2\n\
	.align 2, 0\n\
_0809C4C8: .4byte 0x04000050\n\
_0809C4CC:\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #1\n\
	beq _0809C4D4\n\
	b _0809C5E2\n\
_0809C4D4:\n\
	ldr r1, _0809C4F0 @ =gWrittenToBldy\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0809C4F4 @ =gWrittenToBldalpha_Eva\n\
	movs r1, #0xa\n\
	strh r1, [r0]\n\
	ldr r0, _0809C4F8 @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	movs r0, #4\n\
	strb r0, [r4, #0x10]\n\
	b _0809C5E2\n\
	.align 2, 0\n\
_0809C4F0: .4byte gWrittenToBldy\n\
_0809C4F4: .4byte gWrittenToBldalpha_Eva\n\
_0809C4F8: .4byte gWrittenToBldalpha_Evb\n\
_0809C4FC:\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #0x3c\n\
	bne _0809C5E2\n\
	ldr r1, _0809C524 @ =0x04000050\n\
	ldr r3, _0809C528 @ =0x00001E41\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	movs r0, #5\n\
	strb r0, [r4, #0x10]\n\
	b _0809C5E2\n\
	.align 2, 0\n\
_0809C524: .4byte 0x04000050\n\
_0809C528: .4byte 0x00001E41\n\
_0809C52C:\n\
	ldrh r1, [r4, #0xc]\n\
	movs r2, #0xc\n\
	ldrsh r0, [r4, r2]\n\
	cmp r0, #0xe\n\
	bgt _0809C59A\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #4\n\
	bne _0809C5E2\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	movs r0, #1\n\
	strh r0, [r4, #0xa]\n\
	adds r0, r1, #1\n\
	strh r0, [r4, #0xc]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bne _0809C570\n\
	movs r0, #0x16\n\
	movs r1, #0x78\n\
	movs r2, #0x60\n\
	movs r3, #0\n\
	bl CutsceneBslExplodingSetupOam\n\
	movs r0, #0x16\n\
	movs r1, #0x5f\n\
	movs r2, #0x50\n\
	movs r3, #0\n\
	bl CutsceneBslExplodingSetupOam\n\
	movs r0, #0x16\n\
	movs r1, #0x8c\n\
	movs r2, #0x69\n\
	b _0809C592\n\
_0809C570:\n\
	cmp r0, #2\n\
	bne _0809C588\n\
	movs r0, #0x16\n\
	movs r1, #0x78\n\
	movs r2, #0x54\n\
	movs r3, #0\n\
	bl CutsceneBslExplodingSetupOam\n\
	movs r0, #0x16\n\
	movs r1, #0x91\n\
	movs r2, #0x55\n\
	b _0809C592\n\
_0809C588:\n\
	cmp r0, #3\n\
	bne _0809C5E2\n\
	movs r0, #0x16\n\
	movs r1, #0x60\n\
	movs r2, #0x6a\n\
_0809C592:\n\
	movs r3, #0\n\
	bl CutsceneBslExplodingSetupOam\n\
	b _0809C5E2\n\
_0809C59A:\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #0xf\n\
	bne _0809C5E2\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	ldr r1, _0809C5B0 @ =gWrittenToBldy\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	movs r0, #6\n\
	strb r0, [r4, #0x10]\n\
	b _0809C5E2\n\
	.align 2, 0\n\
_0809C5B0: .4byte gWrittenToBldy\n\
_0809C5B4:\n\
	ldr r2, _0809C5CC @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #0xf\n\
	bhi _0809C5D0\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #6\n\
	bne _0809C5E2\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	adds r0, r1, #1\n\
	strh r0, [r2]\n\
	b _0809C5E2\n\
	.align 2, 0\n\
_0809C5CC: .4byte gWrittenToBldalpha_Eva\n\
_0809C5D0:\n\
	ldr r0, _0809C5F4 @ =0x04000050\n\
	movs r1, #0xbf\n\
	strh r1, [r0]\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #0x10\n\
	bne _0809C5E2\n\
	movs r0, #0\n\
	strh r0, [r4, #8]\n\
	movs r5, #1\n\
_0809C5E2:\n\
	bl CutsceneProcessOam\n\
	bl CutsceneDrawAllOam\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809C5F4: .4byte 0x04000050\n\
    .syntax divided\n");
}

// 0x0809C5F8
NAKED_FUNCTION
void CutsceneBslExplodingProcessScrolling(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r2, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x1e\n\
	bne _0809C614\n\
	movs r0, #0\n\
	strb r0, [r2, #0x13]\n\
	ldrh r0, [r2]\n\
	subs r0, #1\n\
	strh r0, [r2]\n\
_0809C614:\n\
	ldr r1, _0809C620 @ =0x0400001C\n\
	ldrh r0, [r2]\n\
	strh r0, [r1]\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809C620: .4byte 0x0400001C\n\
    .syntax divided\n");
}

// 0x0809C624
NAKED_FUNCTION
void CutsceneBslExplodingProcessBslFar(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r2, r0, #0\n\
	ldrb r1, [r2, #0x14]\n\
	cmp r1, #0\n\
	bne _0809C654\n\
	ldr r3, _0809C64C @ =gNonGameplayRam\n\
	ldrb r0, [r3, #0x10]\n\
	cmp r0, #5\n\
	bne _0809C67A\n\
	movs r4, #0xc\n\
	ldrsh r0, [r3, r4]\n\
	cmp r0, #5\n\
	bne _0809C67A\n\
	strb r1, [r2, #0x12]\n\
	strb r1, [r2, #0x11]\n\
	ldr r0, _0809C650 @ =0x08680ECC\n\
	str r0, [r2, #0x1c]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
	b _0809C67A\n\
	.align 2, 0\n\
_0809C64C: .4byte gNonGameplayRam\n\
_0809C650: .4byte 0x08680ECC\n\
_0809C654:\n\
	cmp r1, #1\n\
	bne _0809C67A\n\
	ldrb r0, [r2, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r2, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r2, #0x12]\n\
	cmp r0, r3\n\
	bne _0809C67A\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809C67A\n\
	strb r1, [r2, #0x10]\n\
	ldrb r1, [r2, #0x16]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2, #0x16]\n\
_0809C67A:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0809C680
NAKED_FUNCTION
void CutsceneBslExplodingProcessExplosions(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r2, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r2, #0x12]\n\
	cmp r0, r3\n\
	bne _0809C6A6\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _0809C6A6\n\
	strb r1, [r2, #0x10]\n\
	ldrb r1, [r2, #0x16]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2, #0x16]\n\
_0809C6A6:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809C6AC
NAKED_FUNCTION
u8 CutsceneBslExplodingSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov r8, r1\n\
	lsls r2, r2, #0x10\n\
	lsrs r7, r2, #0x10\n\
	lsls r3, r3, #0x18\n\
	cmp r3, #0\n\
	bne _0809C708\n\
	movs r2, #0\n\
	ldr r1, _0809C704 @ =gNonGameplayRam\n\
	adds r0, r1, #0\n\
	adds r0, #0x28\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0809C6F8\n\
	adds r3, r1, #0\n\
_0809C6D8:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0xf\n\
	bgt _0809C742\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	adds r0, #0x28\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809C6D8\n\
_0809C6F8:\n\
	lsls r0, r2, #0x18\n\
	asrs r1, r0, #0x18\n\
	adds r6, r0, #0\n\
	cmp r1, #0xf\n\
	ble _0809C74C\n\
	b _0809C742\n\
	.align 2, 0\n\
_0809C704: .4byte gNonGameplayRam\n\
_0809C708:\n\
	movs r2, #0xf\n\
	ldr r1, _0809C748 @ =gNonGameplayRam\n\
	movs r3, #0x91\n\
	lsls r3, r3, #2\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0809C73A\n\
	adds r3, r1, #0\n\
_0809C71A:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0xff\n\
	lsls r1, r1, #0x18\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	blt _0809C742\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	adds r0, #0x28\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809C71A\n\
_0809C73A:\n\
	lsls r0, r2, #0x18\n\
	adds r6, r0, #0\n\
	cmp r6, #0\n\
	bge _0809C74C\n\
_0809C742:\n\
	movs r0, #0x10\n\
	b _0809C83A\n\
	.align 2, 0\n\
_0809C748: .4byte gNonGameplayRam\n\
_0809C74C:\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r2, _0809C7A0 @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r2]\n\
	asrs r1, r6, #0x18\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r4, r0, #2\n\
	ldr r0, _0809C7A4 @ =0x0300149C\n\
	mov ip, r0\n\
	adds r0, r4, r0\n\
	str r0, [r2, #4]\n\
	ldr r0, _0809C7A8 @ =0x85000009\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	mov r0, ip\n\
	subs r0, #0x18\n\
	adds r2, r4, r0\n\
	mov r1, r8\n\
	strh r1, [r2, #0x18]\n\
	strh r7, [r2, #0x1a]\n\
	adds r0, r2, #0\n\
	adds r0, #0x28\n\
	strb r5, [r0]\n\
	adds r3, r2, #0\n\
	adds r3, #0x2e\n\
	ldrb r1, [r3]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strb r1, [r3]\n\
	cmp r5, #1\n\
	bne _0809C7B0\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r3]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809C7AC @ =CutsceneBslExplodingProcessScrolling\n\
	b _0809C836\n\
	.align 2, 0\n\
_0809C7A0: .4byte 0x040000D4\n\
_0809C7A4: .4byte 0x0300149C\n\
_0809C7A8: .4byte 0x85000009\n\
_0809C7AC: .4byte CutsceneBslExplodingProcessScrolling\n\
_0809C7B0:\n\
	cmp r5, #0x14\n\
	bne _0809C7E0\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _0809C7D8 @ =0x08680FFC\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809C7DC @ =unk_9db70\n\
	b _0809C836\n\
	.align 2, 0\n\
_0809C7D8: .4byte 0x08680FFC\n\
_0809C7DC: .4byte unk_9db70\n\
_0809C7E0:\n\
	cmp r5, #0x15\n\
	bne _0809C810\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _0809C808 @ =0x0868100C\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809C80C @ =CutsceneBslExplodingProcessBslFar\n\
	b _0809C836\n\
	.align 2, 0\n\
_0809C808: .4byte 0x0868100C\n\
_0809C80C: .4byte CutsceneBslExplodingProcessBslFar\n\
_0809C810:\n\
	cmp r5, #0x16\n\
	bne _0809C838\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _0809C848 @ =0x08680ECC\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809C84C @ =CutsceneBslExplodingProcessExplosions\n\
_0809C836:\n\
	str r1, [r0]\n\
_0809C838:\n\
	lsrs r0, r6, #0x18\n\
_0809C83A:\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809C848: .4byte 0x08680ECC\n\
_0809C84C: .4byte CutsceneBslExplodingProcessExplosions\n\
    .syntax divided\n");
}

// 0x0809C850
NAKED_FUNCTION
u8 CutsceneBslExplodingGetOamInfoByType(u8 type, s16* pXPosition, s16* pYPosition, s16* pScaling)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r1, #0\n\
	adds r5, r2, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	movs r2, #0\n\
	ldr r7, _0809C880 @ =gNonGameplayRam\n\
_0809C85E:\n\
	lsls r0, r2, #3\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r1, r0, r7\n\
	adds r0, r1, #0\n\
	adds r0, #0x28\n\
	ldrb r0, [r0]\n\
	cmp r0, r6\n\
	bne _0809C884\n\
	ldrh r0, [r1, #0x18]\n\
	strh r0, [r4]\n\
	ldrh r0, [r1, #0x1a]\n\
	strh r0, [r5]\n\
	ldrh r0, [r1, #0x1c]\n\
	strh r0, [r3]\n\
	adds r0, r2, #0\n\
	b _0809C8A2\n\
	.align 2, 0\n\
_0809C880: .4byte gNonGameplayRam\n\
_0809C884:\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r2, r0, #0x18\n\
	cmp r2, #0xf\n\
	bls _0809C85E\n\
	movs r1, #0x96\n\
	lsls r1, r1, #1\n\
	adds r0, r1, #0\n\
	strh r0, [r4]\n\
	movs r0, #0xc8\n\
	strh r0, [r5]\n\
	subs r1, #0x2c\n\
	adds r0, r1, #0\n\
	strh r0, [r3]\n\
	movs r0, #0\n\
_0809C8A2:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

// 0x0809C8A8
NAKED_FUNCTION
void CutsceneBslExplodingVblank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r3, _0809C8FC @ =0x040000D4\n\
	ldr r0, _0809C900 @ =gOamData\n\
	str r0, [r3]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r3, #4]\n\
	ldr r0, _0809C904 @ =0x84000100\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	ldr r2, _0809C908 @ =0x04000052\n\
	ldr r0, _0809C90C @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _0809C910 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _0809C914 @ =0x04000054\n\
	ldr r0, _0809C918 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0809C91C @ =gNonGameplayRam\n\
	movs r2, #0xa\n\
	ldrsh r0, [r1, r2]\n\
	cmp r0, #1\n\
	bne _0809C8F8\n\
	movs r0, #0\n\
	strh r0, [r1, #0xa]\n\
	movs r2, #0xc\n\
	ldrsh r0, [r1, r2]\n\
	lsls r0, r0, #5\n\
	ldr r1, _0809C920 @ =0x0868101C\n\
	adds r0, r0, r1\n\
	str r0, [r3]\n\
	ldr r0, _0809C924 @ =0x05000120\n\
	str r0, [r3, #4]\n\
	ldr r0, _0809C928 @ =0x84000008\n\
	str r0, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
_0809C8F8:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809C8FC: .4byte 0x040000D4\n\
_0809C900: .4byte gOamData\n\
_0809C904: .4byte 0x84000100\n\
_0809C908: .4byte 0x04000052\n\
_0809C90C: .4byte gWrittenToBldalpha_Evb\n\
_0809C910: .4byte gWrittenToBldalpha_Eva\n\
_0809C914: .4byte 0x04000054\n\
_0809C918: .4byte gWrittenToBldy\n\
_0809C91C: .4byte gNonGameplayRam\n\
_0809C920: .4byte 0x0868101C\n\
_0809C924: .4byte 0x05000120\n\
_0809C928: .4byte 0x84000008\n\
    .syntax divided\n");
}

// 0x0809C92C
NAKED_FUNCTION
void unk_9c92c(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}
