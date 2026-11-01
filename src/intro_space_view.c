#include "globals.h"
#include "macros.h"

// 0x08093980
NAKED_FUNCTION
void IntroSpaceViewInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	ldr r3, _08093B10 @ =0x04000208\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	ldr r2, _08093B14 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _08093B18 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _08093B1C @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _08093B20 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _08093B24 @ =unk_99940\n\
	bl CallbackSetVBlank\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x11\n\
	bl DoSoundAction\n\
	bl StopAllMusicAndSounds\n\
	movs r6, #0\n\
	str r6, [sp]\n\
	ldr r4, _08093B28 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r0, _08093B2C @ =gNonGameplayRam\n\
	str r0, [r4, #4]\n\
	ldr r0, _08093B30 @ =0x85000150\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08093B34 @ =0x086101B8\n\
	ldr r1, _08093B38 @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08093B3C @ =0x08612F48\n\
	str r0, [r4]\n\
	ldr r0, _08093B40 @ =0x05000200\n\
	str r0, [r4, #4]\n\
	ldr r0, _08093B44 @ =0x84000080\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08093B48 @ =0x0860BCA4\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _08093B4C @ =0x0860B670\n\
	ldr r5, _08093B50 @ =0x02010000\n\
	adds r1, r5, #0\n\
	bl LZ77UncompWram\n\
	str r5, [r4]\n\
	ldr r0, _08093B54 @ =0x0600E800\n\
	str r0, [r4, #4]\n\
	ldr r0, _08093B58 @ =0x84000200\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	add r1, sp, #4\n\
	ldr r2, _08093B5C @ =0x000001FF\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	str r1, [r4]\n\
	ldr r0, _08093B60 @ =0x0600F000\n\
	str r0, [r4, #4]\n\
	ldr r0, _08093B64 @ =0x81000400\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08093B68 @ =0x0860B148\n\
	ldr r1, _08093B6C @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _08093B70 @ =0x08612E48\n\
	str r0, [r4]\n\
	ldr r0, _08093B74 @ =0x05000100\n\
	str r0, [r4, #4]\n\
	ldr r0, _08093B78 @ =0x84000040\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	strh r6, [r0]\n\
	ldr r0, _08093B7C @ =0x08598898\n\
	ldr r1, _08093B80 @ =0x0600E000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08093B84 @ =0x04000010\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	ldr r0, _08093B88 @ =gBg1XPosition\n\
	strh r6, [r0]\n\
	ldr r0, _08093B8C @ =gBg1YPosition\n\
	strh r6, [r0]\n\
	ldr r0, _08093B90 @ =0x0300122C\n\
	strh r6, [r0]\n\
	ldr r0, _08093B94 @ =0x0300122E\n\
	strh r6, [r0]\n\
	ldr r0, _08093B98 @ =0x03001230\n\
	strh r6, [r0]\n\
	ldr r0, _08093B9C @ =0x03001232\n\
	strh r6, [r0]\n\
	ldr r1, _08093BA0 @ =0x04000008\n\
	ldr r2, _08093BA4 @ =0x00001C08\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #4\n\
	ldr r2, _08093BA8 @ =0x00005D02\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _08093BAC @ =0x00001F03\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
	movs r1, #0\n\
	movs r2, #0\n\
	movs r3, #1\n\
	bl IntroSpaceViewSetupOam\n\
	movs r1, #0xf0\n\
	rsbs r1, r1, #0\n\
	movs r2, #0x6e\n\
	rsbs r2, r2, #0\n\
	movs r0, #2\n\
	movs r3, #1\n\
	bl IntroSpaceViewSetupOam\n\
	movs r5, #0\n\
_08093AA4:\n\
	bl SpecialCutsceneGetRandomNumber\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x18\n\
	bl SpecialCutsceneGetRandomNumber\n\
	adds r2, r0, #0\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	movs r0, #5\n\
	adds r1, r4, #0\n\
	movs r3, #1\n\
	bl IntroSpaceViewSetupOam\n\
	adds r0, r5, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r5, r0, #0x10\n\
	cmp r5, #9\n\
	bls _08093AA4\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	ldr r1, _08093B2C @ =gNonGameplayRam\n\
	ldr r0, _08093BB0 @ =0x0863A19C\n\
	str r0, [r1]\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r1, _08093B28 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	ldr r0, _08093BB4 @ =0x0600D000\n\
	str r0, [r1, #4]\n\
	ldr r0, _08093BB8 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	subs r1, #0xd4\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08093BBC @ =IntroSpaceViewVblank\n\
	bl CallbackSetVBlank\n\
	movs r0, #0x60\n\
	movs r1, #0xf\n\
	bl PlayMusic\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08093B10: .4byte 0x04000208\n\
_08093B14: .4byte 0x04000004\n\
_08093B18: .4byte 0x0000FFEF\n\
_08093B1C: .4byte 0x04000200\n\
_08093B20: .4byte 0x0000FFFD\n\
_08093B24: .4byte unk_99940\n\
_08093B28: .4byte 0x040000D4\n\
_08093B2C: .4byte gNonGameplayRam\n\
_08093B30: .4byte 0x85000150\n\
_08093B34: .4byte 0x086101B8\n\
_08093B38: .4byte 0x06010000\n\
_08093B3C: .4byte 0x08612F48\n\
_08093B40: .4byte 0x05000200\n\
_08093B44: .4byte 0x84000080\n\
_08093B48: .4byte 0x0860BCA4\n\
_08093B4C: .4byte 0x0860B670\n\
_08093B50: .4byte 0x02010000\n\
_08093B54: .4byte 0x0600E800\n\
_08093B58: .4byte 0x84000200\n\
_08093B5C: .4byte 0x000001FF\n\
_08093B60: .4byte 0x0600F000\n\
_08093B64: .4byte 0x81000400\n\
_08093B68: .4byte 0x0860B148\n\
_08093B6C: .4byte 0x0600F800\n\
_08093B70: .4byte 0x08612E48\n\
_08093B74: .4byte 0x05000100\n\
_08093B78: .4byte 0x84000040\n\
_08093B7C: .4byte 0x08598898\n\
_08093B80: .4byte 0x0600E000\n\
_08093B84: .4byte 0x04000010\n\
_08093B88: .4byte gBg1XPosition\n\
_08093B8C: .4byte gBg1YPosition\n\
_08093B90: .4byte 0x0300122C\n\
_08093B94: .4byte 0x0300122E\n\
_08093B98: .4byte 0x03001230\n\
_08093B9C: .4byte 0x03001232\n\
_08093BA0: .4byte 0x04000008\n\
_08093BA4: .4byte 0x00001C08\n\
_08093BA8: .4byte 0x00005D02\n\
_08093BAC: .4byte 0x00001F03\n\
_08093BB0: .4byte 0x0863A19C\n\
_08093BB4: .4byte 0x0600D000\n\
_08093BB8: .4byte 0x85000400\n\
_08093BBC: .4byte IntroSpaceViewVblank\n\
    .syntax divided\n");
}

// 0x08093BC0
NAKED_FUNCTION
void IntroSpaceViewPartProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	movs r7, #0\n\
	ldr r2, _08093BF0 @ =gNonGameplayRam\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	adds r1, #1\n\
	strh r1, [r0]\n\
	movs r3, #0x85\n\
	lsls r3, r3, #2\n\
	adds r0, r2, r3\n\
	ldrb r0, [r0]\n\
	adds r4, r2, #0\n\
	cmp r0, #7\n\
	bls _08093BE4\n\
	b _08093F38\n\
_08093BE4:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08093BF4 @ =_08093BF8\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08093BF0: .4byte gNonGameplayRam\n\
_08093BF4: .4byte _08093BF8\n\
_08093BF8: @ jump table\n\
	.4byte _08093C18 @ case 0\n\
	.4byte _08093C7C @ case 1\n\
	.4byte _08093CB8 @ case 2\n\
	.4byte _08093CEC @ case 3\n\
	.4byte _08093D54 @ case 4\n\
	.4byte _08093D98 @ case 5\n\
	.4byte _08093E5C @ case 6\n\
	.4byte _08093F18 @ case 7\n\
_08093C18:\n\
	ldr r2, _08093C28 @ =gWrittenToBldy\n\
	ldrh r0, [r2]\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	beq _08093C2C\n\
	subs r0, #1\n\
	strh r0, [r2]\n\
	b _08093C3E\n\
	.align 2, 0\n\
_08093C28: .4byte gWrittenToBldy\n\
_08093C2C:\n\
	movs r5, #0x84\n\
	lsls r5, r5, #2\n\
	adds r0, r4, r5\n\
	strh r1, [r0]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r4, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_08093C3E:\n\
	bl SpecialCutsceneGetRandomNumber\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x3f\n\
	bls _08093C4C\n\
	b _08093F00\n\
_08093C4C:\n\
	ldr r0, _08093C74 @ =gNonGameplayRam\n\
	ldr r1, _08093C78 @ =0x00000215\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xd\n\
	bls _08093C5A\n\
	b _08093F00\n\
_08093C5A:\n\
	bl SpecialCutsceneGetRandomNumber\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x18\n\
	bl SpecialCutsceneGetRandomNumber\n\
	adds r2, r0, #0\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	movs r0, #5\n\
	adds r1, r4, #0\n\
	b _08093D40\n\
	.align 2, 0\n\
_08093C74: .4byte gNonGameplayRam\n\
_08093C78: .4byte 0x00000215\n\
_08093C7C:\n\
	movs r2, #0x84\n\
	lsls r2, r2, #2\n\
	adds r1, r4, r2\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x1e\n\
	bne _08093CA2\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r0, #4\n\
	movs r1, #0x78\n\
	movs r2, #0x4a\n\
	movs r3, #0\n\
	bl IntroSpaceViewSetupOam\n\
	movs r3, #0x85\n\
	lsls r3, r3, #2\n\
	adds r1, r4, r3\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
_08093CA2:\n\
	bl SpecialCutsceneGetRandomNumber\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bge _08093CAE\n\
	b _08093F00\n\
_08093CAE:\n\
	ldr r5, _08093CB4 @ =0x00000215\n\
	adds r0, r4, r5\n\
	b _08093D2A\n\
	.align 2, 0\n\
_08093CB4: .4byte 0x00000215\n\
_08093CB8:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldrh r1, [r2]\n\
	subs r0, #0x30\n\
	cmp r1, r0\n\
	bne _08093CD4\n\
	movs r0, #0\n\
	strh r0, [r2]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r4, r2\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
_08093CD4:\n\
	bl SpecialCutsceneGetRandomNumber\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bge _08093CE0\n\
	b _08093F00\n\
_08093CE0:\n\
	ldr r3, _08093CE8 @ =0x00000215\n\
	adds r0, r4, r3\n\
	b _08093D2A\n\
	.align 2, 0\n\
_08093CE8: .4byte 0x00000215\n\
_08093CEC:\n\
	movs r5, #0x84\n\
	lsls r5, r5, #2\n\
	adds r2, r4, r5\n\
	ldrh r1, [r2]\n\
	cmp r1, #0x1e\n\
	bne _08093D04\n\
	ldr r0, _08093D00 @ =0x000001E9\n\
	bl SoundPlay\n\
	b _08093D18\n\
	.align 2, 0\n\
_08093D00: .4byte 0x000001E9\n\
_08093D04:\n\
	ldr r0, _08093D48 @ =0x0000041A\n\
	cmp r1, r0\n\
	bne _08093D18\n\
	movs r0, #0\n\
	strh r0, [r2]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r4, r0\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
_08093D18:\n\
	bl SpecialCutsceneGetRandomNumber\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bge _08093D24\n\
	b _08093F00\n\
_08093D24:\n\
	ldr r0, _08093D4C @ =gNonGameplayRam\n\
	ldr r1, _08093D50 @ =0x00000215\n\
	adds r0, r0, r1\n\
_08093D2A:\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xb\n\
	bls _08093D32\n\
	b _08093F00\n\
_08093D32:\n\
	bl SpecialCutsceneGetRandomNumber\n\
	adds r2, r0, #0\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	movs r0, #5\n\
	movs r1, #0\n\
_08093D40:\n\
	movs r3, #1\n\
	bl IntroSpaceViewSetupOam\n\
	b _08093F00\n\
	.align 2, 0\n\
_08093D48: .4byte 0x0000041A\n\
_08093D4C: .4byte gNonGameplayRam\n\
_08093D50: .4byte 0x00000215\n\
_08093D54:\n\
	ldr r4, _08093D84 @ =gWrittenToBldy\n\
	ldrh r0, [r4]\n\
	cmp r0, #0xf\n\
	bhi _08093D94\n\
	cmp r0, #0\n\
	bne _08093D7A\n\
	ldr r2, _08093D88 @ =0x080A8CDC\n\
	ldr r0, _08093D8C @ =0x080A8D3C\n\
	ldr r3, _08093D90 @ =0x00000F5C\n\
	adds r0, r0, r3\n\
	ldrh r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	movs r1, #0xa\n\
	bl ApplyMusicSoundFading\n\
_08093D7A:\n\
	ldrh r0, [r4]\n\
	adds r0, #2\n\
	strh r0, [r4]\n\
	b _08093F00\n\
	.align 2, 0\n\
_08093D84: .4byte gWrittenToBldy\n\
_08093D88: .4byte 0x080A8CDC\n\
_08093D8C: .4byte 0x080A8D3C\n\
_08093D90: .4byte 0x00000F5C\n\
_08093D94:\n\
	movs r7, #1\n\
	b _08093F00\n\
_08093D98:\n\
	movs r5, #0x84\n\
	lsls r5, r5, #2\n\
	adds r3, r4, r5\n\
	ldrh r0, [r3]\n\
	cmp r0, #5\n\
	bhi _08093DC4\n\
	ldr r2, _08093DBC @ =0x0879C41C\n\
	adds r1, r0, #0\n\
	subs r1, #1\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	lsls r1, r1, #0xc\n\
	ldr r2, _08093DC0 @ =0x06008000\n\
	adds r1, r1, r2\n\
	bl LZ77UncompVram\n\
	b _08093F00\n\
	.align 2, 0\n\
_08093DBC: .4byte 0x0879C41C\n\
_08093DC0: .4byte 0x06008000\n\
_08093DC4:\n\
	cmp r0, #6\n\
	bne _08093E28\n\
	ldr r0, _08093E00 @ =0x08658BE0\n\
	ldr r1, _08093E04 @ =0x0600E000\n\
	bl LZ77UncompVram\n\
	ldr r1, _08093E08 @ =0x040000D4\n\
	ldr r0, _08093E0C @ =0x086591E4\n\
	str r0, [r1]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _08093E10 @ =0x84000040\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r0, _08093E14 @ =gWrittenToBldalpha_Eva\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	ldr r2, _08093E18 @ =gWrittenToBldalpha_Evb\n\
	movs r0, #0x10\n\
	strh r0, [r2]\n\
	ldr r0, _08093E1C @ =0x04000014\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	ldr r1, _08093E20 @ =0x0400000A\n\
	ldr r3, _08093E24 @ =0x00001C08\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	b _08093F00\n\
	.align 2, 0\n\
_08093E00: .4byte 0x08658BE0\n\
_08093E04: .4byte 0x0600E000\n\
_08093E08: .4byte 0x040000D4\n\
_08093E0C: .4byte 0x086591E4\n\
_08093E10: .4byte 0x84000040\n\
_08093E14: .4byte gWrittenToBldalpha_Eva\n\
_08093E18: .4byte gWrittenToBldalpha_Evb\n\
_08093E1C: .4byte 0x04000014\n\
_08093E20: .4byte 0x0400000A\n\
_08093E24: .4byte 0x00001C08\n\
_08093E28:\n\
	cmp r0, #7\n\
	bne _08093F00\n\
	ldr r1, _08093E54 @ =0x04000050\n\
	ldr r5, _08093E58 @ =0x00003C42\n\
	adds r0, r5, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r5, #0x80\n\
	lsls r5, r5, #2\n\
	adds r1, r5, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r4, r0\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	b _08093F00\n\
	.align 2, 0\n\
_08093E54: .4byte 0x04000050\n\
_08093E58: .4byte 0x00003C42\n\
_08093E5C:\n\
	movs r2, #0x84\n\
	lsls r2, r2, #2\n\
	adds r1, r4, r2\n\
	ldrh r0, [r1]\n\
	cmp r0, #4\n\
	bne _08093F00\n\
	movs r2, #0\n\
	strh r2, [r1]\n\
	ldr r6, _08093EC0 @ =gWrittenToBldalpha_Eva\n\
	ldrh r0, [r6]\n\
	cmp r0, #0xf\n\
	bhi _08093EDC\n\
	cmp r0, #0\n\
	bne _08093EB0\n\
	ldr r5, _08093EC4 @ =0x080A8CDC\n\
	ldr r4, _08093EC8 @ =0x080A8D3C\n\
	ldr r3, _08093ECC @ =0x00000F4C\n\
	adds r0, r4, r3\n\
	ldrh r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	ldr r0, [r0]\n\
	movs r1, #0x3c\n\
	bl ApplyMusicSoundFading\n\
	ldr r0, _08093ED0 @ =0x00000F54\n\
	adds r4, r4, r0\n\
	ldrh r1, [r4]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	ldr r0, [r0]\n\
	movs r1, #0x3c\n\
	bl ApplyMusicSoundFading\n\
	ldr r0, _08093ED4 @ =0x000001EB\n\
	movs r1, #0x3c\n\
	bl PlayFadingSound\n\
_08093EB0:\n\
	ldrh r0, [r6]\n\
	adds r0, #1\n\
	strh r0, [r6]\n\
	ldr r1, _08093ED8 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r1]\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	b _08093F00\n\
	.align 2, 0\n\
_08093EC0: .4byte gWrittenToBldalpha_Eva\n\
_08093EC4: .4byte 0x080A8CDC\n\
_08093EC8: .4byte 0x080A8D3C\n\
_08093ECC: .4byte 0x00000F4C\n\
_08093ED0: .4byte 0x00000F54\n\
_08093ED4: .4byte 0x000001EB\n\
_08093ED8: .4byte gWrittenToBldalpha_Evb\n\
_08093EDC:\n\
	str r2, [sp]\n\
	ldr r1, _08093F0C @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r1]\n\
	movs r5, #0x87\n\
	lsls r5, r5, #2\n\
	adds r0, r4, r5\n\
	str r0, [r1, #4]\n\
	ldr r0, _08093F10 @ =0x850000B4\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r4, r0\n\
	movs r0, #7\n\
	strb r0, [r1]\n\
	ldr r0, _08093F14 @ =gWrittenToBldy\n\
	strh r2, [r0]\n\
_08093F00:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	b _08093F38\n\
	.align 2, 0\n\
_08093F0C: .4byte 0x040000D4\n\
_08093F10: .4byte 0x850000B4\n\
_08093F14: .4byte gWrittenToBldy\n\
_08093F18:\n\
	movs r2, #0x84\n\
	lsls r2, r2, #2\n\
	adds r1, r4, r2\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x96\n\
	bne _08093F38\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r3, #0x85\n\
	lsls r3, r3, #2\n\
	adds r1, r4, r3\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	ldr r1, _08093F48 @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
_08093F38:\n\
	bl IntroProcessText\n\
	adds r0, r7, #0\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08093F48: .4byte 0x04000050\n\
    .syntax divided\n");
}

// 0x08093F4C
NAKED_FUNCTION
void IntroFlyingViewInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	sub sp, #4\n\
	ldr r3, _0809407C @ =0x04000208\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	ldr r2, _08094080 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _08094084 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _08094088 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809408C @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _08094090 @ =unk_99940\n\
	bl CallbackSetVBlank\n\
	movs r5, #0\n\
	str r5, [sp]\n\
	ldr r4, _08094094 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r1, _08094098 @ =0x030016A0\n\
	mov r8, r1\n\
	str r1, [r4, #4]\n\
	ldr r0, _0809409C @ =0x850000B4\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _080940A0 @ =0x086101B8\n\
	ldr r1, _080940A4 @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r0, _080940A8 @ =0x08612F48\n\
	str r0, [r4]\n\
	ldr r0, _080940AC @ =0x05000200\n\
	str r0, [r4, #4]\n\
	ldr r6, _080940B0 @ =0x84000080\n\
	str r6, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _080940B4 @ =0x08605D08\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _080940B8 @ =0x08609220\n\
	ldr r1, _080940BC @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _080940C0 @ =0x08598898\n\
	ldr r1, _080940C4 @ =0x0600E000\n\
	bl LZ77UncompVram\n\
	ldr r0, _080940C8 @ =0x08609020\n\
	str r0, [r4]\n\
	movs r1, #0xa0\n\
	lsls r1, r1, #0x13\n\
	str r1, [r4, #4]\n\
	str r6, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _080940CC @ =0x08598A8C\n\
	str r0, [r4]\n\
	ldr r0, _080940D0 @ =0x050001E0\n\
	str r0, [r4, #4]\n\
	ldr r0, _080940D4 @ =0x84000008\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	strh r5, [r1]\n\
	ldr r0, _080940D8 @ =0x04000010\n\
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
	ldr r0, _080940DC @ =gBg1XPosition\n\
	strh r5, [r0]\n\
	ldr r0, _080940E0 @ =gBg1YPosition\n\
	strh r5, [r0]\n\
	ldr r0, _080940E4 @ =0x0300122C\n\
	strh r5, [r0]\n\
	ldr r0, _080940E8 @ =0x0300122E\n\
	strh r5, [r0]\n\
	ldr r0, _080940EC @ =0x03001230\n\
	strh r5, [r0]\n\
	ldr r0, _080940F0 @ =0x03001232\n\
	strh r5, [r0]\n\
	ldr r1, _080940F4 @ =0x04000008\n\
	ldr r2, _080940F8 @ =0x00001C08\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #6\n\
	ldr r2, _080940FC @ =0x00001F03\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r0, #0xa\n\
	movs r1, #0x91\n\
	movs r2, #0x8c\n\
	movs r3, #0\n\
	bl IntroSpaceViewSetupOam\n\
	movs r0, #0xb\n\
	movs r1, #0x8c\n\
	movs r2, #0x50\n\
	movs r3, #0\n\
	bl IntroSpaceViewSetupOam\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	ldr r0, _08094100 @ =0xFFFFFDE4\n\
	add r8, r0\n\
	ldr r0, _08094104 @ =0x0863A19C\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	str r5, [sp]\n\
	mov r2, sp\n\
	str r2, [r4]\n\
	ldr r0, _08094108 @ =0x0600D000\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809410C @ =0x85000400\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r2, #0xc8\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08094110 @ =IntroSpaceViewVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809407C: .4byte 0x04000208\n\
_08094080: .4byte 0x04000004\n\
_08094084: .4byte 0x0000FFEF\n\
_08094088: .4byte 0x04000200\n\
_0809408C: .4byte 0x0000FFFD\n\
_08094090: .4byte unk_99940\n\
_08094094: .4byte 0x040000D4\n\
_08094098: .4byte 0x030016A0\n\
_0809409C: .4byte 0x850000B4\n\
_080940A0: .4byte 0x086101B8\n\
_080940A4: .4byte 0x06010000\n\
_080940A8: .4byte 0x08612F48\n\
_080940AC: .4byte 0x05000200\n\
_080940B0: .4byte 0x84000080\n\
_080940B4: .4byte 0x08605D08\n\
_080940B8: .4byte 0x08609220\n\
_080940BC: .4byte 0x0600F800\n\
_080940C0: .4byte 0x08598898\n\
_080940C4: .4byte 0x0600E000\n\
_080940C8: .4byte 0x08609020\n\
_080940CC: .4byte 0x08598A8C\n\
_080940D0: .4byte 0x050001E0\n\
_080940D4: .4byte 0x84000008\n\
_080940D8: .4byte 0x04000010\n\
_080940DC: .4byte gBg1XPosition\n\
_080940E0: .4byte gBg1YPosition\n\
_080940E4: .4byte 0x0300122C\n\
_080940E8: .4byte 0x0300122E\n\
_080940EC: .4byte 0x03001230\n\
_080940F0: .4byte 0x03001232\n\
_080940F4: .4byte 0x04000008\n\
_080940F8: .4byte 0x00001C08\n\
_080940FC: .4byte 0x00001F03\n\
_08094100: .4byte 0xFFFFFDE4\n\
_08094104: .4byte 0x0863A19C\n\
_08094108: .4byte 0x0600D000\n\
_0809410C: .4byte 0x85000400\n\
_08094110: .4byte IntroSpaceViewVblank\n\
    .syntax divided\n");
}

// 0x08094114
NAKED_FUNCTION
void IntroFlyingViewProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r4, _0809413C @ =gNonGameplayRam\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r4, r0\n\
	ldrh r0, [r1]\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldrb r0, [r2]\n\
	cmp r0, #1\n\
	beq _0809417C\n\
	cmp r0, #1\n\
	bgt _08094140\n\
	cmp r0, #0\n\
	beq _08094146\n\
	b _080941F6\n\
	.align 2, 0\n\
_0809413C: .4byte gNonGameplayRam\n\
_08094140:\n\
	cmp r0, #2\n\
	beq _080941D8\n\
	b _080941F6\n\
_08094146:\n\
	ldr r4, _0809416C @ =gWrittenToBldy\n\
	ldrh r0, [r4]\n\
	cmp r0, #0\n\
	beq _08094174\n\
	cmp r0, #0x10\n\
	bne _08094164\n\
	movs r0, #0xf6\n\
	lsls r0, r0, #1\n\
	movs r1, #0\n\
	bl PlayFadingSound\n\
	ldr r0, _08094170 @ =0x000001ED\n\
	movs r1, #0\n\
	bl PlayFadingSound\n\
_08094164:\n\
	ldrh r0, [r4]\n\
	subs r0, #2\n\
	strh r0, [r4]\n\
	b _080941C6\n\
	.align 2, 0\n\
_0809416C: .4byte gWrittenToBldy\n\
_08094170: .4byte 0x000001ED\n\
_08094174:\n\
	strh r5, [r1]\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	b _080941C6\n\
_0809417C:\n\
	bl SpecialCutsceneGetRandomNumber\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	blt _080941AE\n\
	ldr r1, _080941D0 @ =0x00000215\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #9\n\
	bhi _080941AE\n\
	bl SpecialCutsceneGetRandomNumber\n\
	adds r4, r0, #0\n\
	lsls r4, r4, #0x18\n\
	lsrs r4, r4, #0x18\n\
	bl SpecialCutsceneGetRandomNumber\n\
	adds r2, r0, #0\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	movs r0, #0x10\n\
	adds r1, r4, #0\n\
	movs r3, #0\n\
	bl IntroSpaceViewSetupOam\n\
_080941AE:\n\
	ldr r0, _080941D4 @ =gNonGameplayRam\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r2, r0, r1\n\
	ldrh r1, [r2]\n\
	movs r0, #0x96\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bne _080941C6\n\
	movs r0, #0\n\
	strh r0, [r2]\n\
	movs r5, #1\n\
_080941C6:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	b _080941F6\n\
	.align 2, 0\n\
_080941D0: .4byte 0x00000215\n\
_080941D4: .4byte gNonGameplayRam\n\
_080941D8:\n\
	ldr r1, _080941E8 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _080941EC\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _080941EE\n\
	.align 2, 0\n\
_080941E8: .4byte gWrittenToBldy\n\
_080941EC:\n\
	movs r5, #1\n\
_080941EE:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_080941F6:\n\
	bl IntroProcessText\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08094204
NAKED_FUNCTION
void IntroSpaceView(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	movs r4, #0\n\
	ldr r0, _08094220 @ =gNonGameplayRam\n\
	ldrh r1, [r0, #8]\n\
	adds r2, r0, #0\n\
	cmp r1, #7\n\
	bls _08094214\n\
	b _0809431E\n\
_08094214:\n\
	lsls r0, r1, #2\n\
	ldr r1, _08094224 @ =_08094228\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08094220: .4byte gNonGameplayRam\n\
_08094224: .4byte _08094228\n\
_08094228: @ jump table\n\
	.4byte _08094248 @ case 0\n\
	.4byte _08094258 @ case 1\n\
	.4byte _08094274 @ case 2\n\
	.4byte _0809429C @ case 3\n\
	.4byte _080942BC @ case 4\n\
	.4byte _080942CC @ case 5\n\
	.4byte _080942D2 @ case 6\n\
	.4byte _080942FC @ case 7\n\
_08094248:\n\
	bl IntroSpaceViewInit\n\
	ldr r1, _08094254 @ =gNonGameplayRam\n\
	movs r0, #1\n\
	strh r0, [r1, #8]\n\
	b _0809431E\n\
	.align 2, 0\n\
_08094254: .4byte gNonGameplayRam\n\
_08094258:\n\
	bl SpecialCutsceneFadeIn\n\
	ldr r0, _0809426C @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809431E\n\
	ldr r1, _08094270 @ =gNonGameplayRam\n\
	movs r0, #2\n\
	strh r0, [r1, #8]\n\
	b _0809431E\n\
	.align 2, 0\n\
_0809426C: .4byte gWrittenToBldy\n\
_08094270: .4byte gNonGameplayRam\n\
_08094274:\n\
	bl IntroSpaceViewPartProcess\n\
	cmp r0, #0\n\
	beq _0809431E\n\
	ldr r1, _08094294 @ =gNonGameplayRam\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	movs r2, #0\n\
	strb r2, [r0]\n\
	ldr r3, _08094298 @ =0x00000213\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	movs r0, #3\n\
	strh r0, [r1, #8]\n\
	b _0809431E\n\
	.align 2, 0\n\
_08094294: .4byte gNonGameplayRam\n\
_08094298: .4byte 0x00000213\n\
_0809429C:\n\
	ldr r1, _080942AC @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _080942B0\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _080942B4\n\
	.align 2, 0\n\
_080942AC: .4byte gWrittenToBldy\n\
_080942B0:\n\
	movs r0, #4\n\
	strh r0, [r2, #8]\n\
_080942B4:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_080942BC:\n\
	bl IntroFlyingViewInit\n\
	ldr r1, _080942C8 @ =gNonGameplayRam\n\
	movs r0, #6\n\
	strh r0, [r1, #8]\n\
	b _0809431E\n\
	.align 2, 0\n\
_080942C8: .4byte gNonGameplayRam\n\
_080942CC:\n\
	movs r0, #6\n\
	strh r0, [r2, #8]\n\
	b _0809431E\n\
_080942D2:\n\
	bl IntroFlyingViewProcess\n\
	cmp r0, #0\n\
	beq _0809431E\n\
	ldr r2, _080942F4 @ =gNonGameplayRam\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r3, _080942F8 @ =0x00000213\n\
	adds r1, r2, r3\n\
	strb r0, [r1]\n\
	strh r0, [r2, #8]\n\
	movs r4, #1\n\
	b _0809431E\n\
	.align 2, 0\n\
_080942F4: .4byte gNonGameplayRam\n\
_080942F8: .4byte 0x00000213\n\
_080942FC:\n\
	ldr r1, _0809430C @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _08094310\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _08094316\n\
	.align 2, 0\n\
_0809430C: .4byte gWrittenToBldy\n\
_08094310:\n\
	movs r0, #0\n\
	strh r0, [r2, #8]\n\
	movs r4, #1\n\
_08094316:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_0809431E:\n\
	adds r0, r4, #0\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08094328
NAKED_FUNCTION
void IntroProcessSpaceViewScrolling(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r1, r0, #0\n\
	ldrb r0, [r1, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r1, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x1e\n\
	bne _08094346\n\
	movs r0, #0\n\
	strb r0, [r1, #0x12]\n\
	ldr r1, _0809434C @ =0x03001230\n\
	ldrh r0, [r1]\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
_08094346:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809434C: .4byte 0x03001230\n\
    .syntax divided\n");
}

// 0x08094350
NAKED_FUNCTION
void IntroProcessBslShipSideways(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r5, r0, #0\n\
	ldrh r1, [r5, #0xc]\n\
	movs r6, #0\n\
	strh r1, [r5, #4]\n\
	ldrb r0, [r5, #0x14]\n\
	cmp r0, #0\n\
	bne _08094380\n\
	strh r1, [r5]\n\
	ldrh r0, [r5, #0xe]\n\
	strh r0, [r5, #2]\n\
	ldr r0, _0809437C @ =gNonGameplayRam\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	beq _08094376\n\
	b _080944D6\n\
_08094376:\n\
	movs r0, #1\n\
	b _080944D4\n\
	.align 2, 0\n\
_0809437C: .4byte gNonGameplayRam\n\
_08094380:\n\
	cmp r0, #1\n\
	bne _080943E2\n\
	ldrh r0, [r5, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r5, #0xa]\n\
	lsls r0, r0, #0x10\n\
	movs r1, #0xc3\n\
	lsls r1, r1, #0x12\n\
	cmp r0, r1\n\
	bne _080943A2\n\
	movs r1, #0x82\n\
	lsls r1, r1, #1\n\
	movs r0, #3\n\
	movs r2, #0x6e\n\
	movs r3, #0\n\
	bl IntroSpaceViewSetupOam\n\
_080943A2:\n\
	movs r2, #0\n\
	ldrsh r0, [r5, r2]\n\
	movs r1, #0x3c\n\
	subs r1, r1, r0\n\
	ldrh r0, [r5, #0xa]\n\
	lsls r0, r0, #1\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #0xb\n\
	ldrh r3, [r5]\n\
	adds r2, r0, r3\n\
	strh r2, [r5, #0xc]\n\
	movs r4, #2\n\
	ldrsh r0, [r5, r4]\n\
	movs r1, #0xa\n\
	subs r1, r1, r0\n\
	ldrh r0, [r5, #0xa]\n\
	lsls r0, r0, #1\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #0xb\n\
	ldrh r7, [r5, #2]\n\
	adds r1, r0, r7\n\
	strh r1, [r5, #0xe]\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x1d\n\
	bgt _080943D8\n\
	b _080944D6\n\
_080943D8:\n\
	strh r6, [r5, #0xa]\n\
	strh r2, [r5]\n\
	strh r1, [r5, #2]\n\
	movs r0, #2\n\
	b _080944D4\n\
_080943E2:\n\
	cmp r0, #2\n\
	bne _08094408\n\
	ldrh r0, [r5, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r5, #0xa]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bne _080944D6\n\
	strh r6, [r5, #0xa]\n\
	movs r0, #4\n\
	strh r0, [r5, #2]\n\
	strh r1, [r5, #4]\n\
	ldrh r0, [r5, #0xe]\n\
	strh r0, [r5, #8]\n\
	movs r0, #0\n\
	strb r0, [r5, #0x13]\n\
	movs r0, #3\n\
	b _080944D4\n\
_08094408:\n\
	cmp r0, #3\n\
	bne _08094480\n\
	movs r0, #0\n\
	ldrsh r3, [r5, r0]\n\
	ldr r2, _08094478 @ =0x080A4FA4\n\
	ldrb r1, [r5, #0x13]\n\
	adds r0, r1, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	movs r4, #0\n\
	ldrsh r0, [r0, r4]\n\
	adds r4, r3, #0\n\
	muls r4, r0, r4\n\
	movs r7, #2\n\
	ldrsh r3, [r5, r7]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r2\n\
	movs r7, #0\n\
	ldrsh r0, [r1, r7]\n\
	muls r3, r0, r3\n\
	movs r1, #0\n\
	ldrsh r0, [r2, r1]\n\
	adds r1, r4, #0\n\
	muls r1, r0, r1\n\
	adds r2, #0x80\n\
	movs r4, #0\n\
	ldrsh r0, [r2, r4]\n\
	muls r0, r3, r0\n\
	adds r1, r1, r0\n\
	ldrh r0, [r5, #0xa]\n\
	lsrs r0, r0, #2\n\
	ldrh r7, [r5]\n\
	adds r0, r0, r7\n\
	strh r0, [r5, #0xc]\n\
	asrs r1, r1, #0x10\n\
	ldrh r0, [r5, #8]\n\
	adds r1, r1, r0\n\
	strh r1, [r5, #0xe]\n\
	ldrb r0, [r5, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r5, #0x13]\n\
	ldrh r0, [r5, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r5, #0xa]\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0x3c\n\
	beq _080944D6\n\
	ldr r0, _0809447C @ =0x00007530\n\
	cmp r1, r0\n\
	bne _080944D6\n\
	strh r6, [r5, #0xa]\n\
	movs r0, #4\n\
	b _080944D4\n\
	.align 2, 0\n\
_08094478: .4byte 0x080A4FA4\n\
_0809447C: .4byte 0x00007530\n\
_08094480:\n\
	cmp r0, #4\n\
	bne _08094490\n\
	movs r0, #5\n\
	strb r0, [r5, #0x14]\n\
	strh r1, [r5]\n\
	ldrh r0, [r5, #0xe]\n\
	strh r0, [r5, #2]\n\
	b _080944D6\n\
_08094490:\n\
	cmp r0, #5\n\
	bne _080944D6\n\
	ldrh r0, [r5, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r5, #0xa]\n\
	movs r2, #0\n\
	ldrsh r1, [r5, r2]\n\
	movs r0, #0x82\n\
	lsls r0, r0, #2\n\
	subs r0, r0, r1\n\
	ldrh r1, [r5, #0xa]\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #0xa\n\
	ldrh r3, [r5]\n\
	adds r2, r0, r3\n\
	strh r2, [r5, #0xc]\n\
	movs r4, #2\n\
	ldrsh r1, [r5, r4]\n\
	movs r0, #0x64\n\
	subs r0, r0, r1\n\
	ldrh r1, [r5, #0xa]\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #0xa\n\
	ldrh r7, [r5, #2]\n\
	adds r3, r0, r7\n\
	strh r3, [r5, #0xe]\n\
	lsls r1, r2, #0x10\n\
	ldr r0, _08094544 @ =0x02070000\n\
	cmp r1, r0\n\
	ble _080944D6\n\
	strh r6, [r5, #0xa]\n\
	strh r2, [r5]\n\
	strh r3, [r5, #2]\n\
	movs r0, #6\n\
_080944D4:\n\
	strb r0, [r5, #0x14]\n\
_080944D6:\n\
	ldr r0, _08094548 @ =0x0300122C\n\
	ldrh r2, [r5, #0xc]\n\
	strh r2, [r0]\n\
	ldr r1, _0809454C @ =0x0300122E\n\
	ldrh r0, [r5, #0xe]\n\
	strh r0, [r1]\n\
	lsls r0, r2, #0x10\n\
	asrs r0, r0, #0x10\n\
	movs r1, #0x78\n\
	rsbs r1, r1, #0\n\
	cmp r0, r1\n\
	blt _08094584\n\
	ldrb r0, [r5, #4]\n\
	subs r0, r2, r0\n\
	ldrb r2, [r5, #0x11]\n\
	adds r1, r0, r2\n\
	movs r4, #0\n\
	strb r1, [r5, #0x11]\n\
	ldrb r2, [r5, #0x1a]\n\
	lsrs r0, r2, #4\n\
	cmp r0, #0\n\
	bne _08094558\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _08094584\n\
	adds r0, r1, #0\n\
	subs r0, #8\n\
	strb r0, [r5, #0x11]\n\
	ldrb r1, [r5, #0x12]\n\
	lsls r1, r1, #1\n\
	ldr r0, _08094550 @ =0x02010800\n\
	adds r0, r1, r0\n\
	ldr r2, _08094554 @ =0x0600F000\n\
	adds r1, r1, r2\n\
	movs r2, #1\n\
	movs r3, #0x14\n\
	bl Dma3Transfer_Unused2\n\
	ldrb r0, [r5, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r5, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x20\n\
	bne _08094584\n\
	strb r4, [r5, #0x12]\n\
	ldrb r0, [r5, #0x1a]\n\
	movs r1, #0xf\n\
	ands r1, r0\n\
	movs r0, #0x10\n\
	orrs r1, r0\n\
	strb r1, [r5, #0x1a]\n\
	b _08094584\n\
	.align 2, 0\n\
_08094544: .4byte 0x02070000\n\
_08094548: .4byte 0x0300122C\n\
_0809454C: .4byte 0x0300122E\n\
_08094550: .4byte 0x02010800\n\
_08094554: .4byte 0x0600F000\n\
_08094558:\n\
	cmp r0, #1\n\
	bne _08094584\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _08094584\n\
	adds r0, r1, #0\n\
	subs r0, #8\n\
	strb r0, [r5, #0x11]\n\
	ldrb r0, [r5, #0x12]\n\
	adds r0, #1\n\
	strb r0, [r5, #0x12]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x20\n\
	bne _08094584\n\
	strb r4, [r5, #0x12]\n\
	movs r0, #0xf\n\
	ands r0, r2\n\
	movs r1, #0xa0\n\
	orrs r0, r1\n\
	strb r0, [r5, #0x1a]\n\
_08094584:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809458C
NAKED_FUNCTION
void IntroProcessSamusSHipEntering(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	movs r4, #0\n\
	ldrb r0, [r6, #0x14]\n\
	cmp r0, #0\n\
	bne _080945BC\n\
	movs r0, #0x64\n\
	strh r0, [r6]\n\
	movs r0, #0x1e\n\
	strh r0, [r6, #2]\n\
	ldrh r0, [r6, #0xc]\n\
	strh r0, [r6, #4]\n\
	ldrh r0, [r6, #0xe]\n\
	subs r0, #0x1e\n\
	strh r0, [r6, #8]\n\
	movs r0, #0x40\n\
	strb r0, [r6, #0x13]\n\
	movs r0, #1\n\
	strb r0, [r6, #0x14]\n\
	movs r0, #0xf5\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	b _08094676\n\
_080945BC:\n\
	cmp r0, #1\n\
	bne _080945DE\n\
	ldrb r1, [r6, #0x13]\n\
	adds r1, #1\n\
	strb r1, [r6, #0x13]\n\
	ldrh r0, [r6, #6]\n\
	subs r0, #2\n\
	strh r0, [r6, #6]\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	cmp r1, #0x80\n\
	bne _08094676\n\
	movs r0, #2\n\
	strb r0, [r6, #0x14]\n\
	adds r0, #0xfe\n\
	strh r0, [r6, #6]\n\
	b _08094676\n\
_080945DE:\n\
	cmp r0, #2\n\
	bne _080945FA\n\
	strh r4, [r6]\n\
	movs r0, #8\n\
	strh r0, [r6, #2]\n\
	ldrh r0, [r6, #0xc]\n\
	strh r0, [r6, #4]\n\
	ldrh r0, [r6, #0xe]\n\
	strh r0, [r6, #8]\n\
	movs r0, #0x80\n\
	strb r0, [r6, #0x13]\n\
	movs r0, #3\n\
	strb r0, [r6, #0x14]\n\
	b _08094676\n\
_080945FA:\n\
	cmp r0, #3\n\
	bne _08094612\n\
	ldrb r0, [r6, #0x13]\n\
	adds r0, #2\n\
	strb r0, [r6, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xc0\n\
	bne _08094676\n\
	movs r0, #4\n\
	strb r0, [r6, #0x14]\n\
	b _08094676\n\
_08094612:\n\
	cmp r0, #4\n\
	bne _08094634\n\
	ldrb r0, [r6, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r6, #0x13]\n\
	ldrh r0, [r6, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r6, #0xa]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #8\n\
	bne _08094676\n\
	strh r4, [r6, #0xa]\n\
	ldrh r0, [r6, #4]\n\
	subs r0, #1\n\
	strh r0, [r6, #4]\n\
	b _08094676\n\
_08094634:\n\
	cmp r0, #5\n\
	bne _0809465A\n\
	ldrh r2, [r6, #0xc]\n\
	movs r1, #0x8c\n\
	lsls r1, r1, #1\n\
	adds r0, r1, #0\n\
	subs r0, r0, r2\n\
	strh r0, [r6]\n\
	movs r1, #0x3c\n\
	strh r1, [r6, #2]\n\
	adds r2, r2, r0\n\
	strh r2, [r6, #4]\n\
	ldrh r0, [r6, #0xe]\n\
	strh r0, [r6, #8]\n\
	movs r0, #0x80\n\
	strb r0, [r6, #0x13]\n\
	movs r0, #6\n\
	strb r0, [r6, #0x14]\n\
	b _08094676\n\
_0809465A:\n\
	cmp r0, #6\n\
	bne _08094676\n\
	ldrb r0, [r6, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r6, #0x13]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08094676\n\
	strb r4, [r6, #0x10]\n\
	ldrb r1, [r6, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r6, #0x18]\n\
_08094676:\n\
	movs r2, #0\n\
	ldrsh r3, [r6, r2]\n\
	ldr r2, _080946D4 @ =0x080A4FA4\n\
	ldrb r1, [r6, #0x13]\n\
	adds r0, r1, #0\n\
	adds r0, #0x40\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	movs r4, #0\n\
	ldrsh r0, [r0, r4]\n\
	adds r5, r3, #0\n\
	muls r5, r0, r5\n\
	movs r0, #2\n\
	ldrsh r3, [r6, r0]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r2\n\
	movs r4, #0\n\
	ldrsh r0, [r1, r4]\n\
	adds r4, r3, #0\n\
	muls r4, r0, r4\n\
	adds r0, r2, #0\n\
	adds r0, #0x80\n\
	movs r1, #0\n\
	ldrsh r3, [r0, r1]\n\
	adds r1, r5, #0\n\
	muls r1, r3, r1\n\
	movs r0, #0\n\
	ldrsh r2, [r2, r0]\n\
	adds r0, r4, #0\n\
	muls r0, r2, r0\n\
	subs r1, r1, r0\n\
	adds r0, r5, #0\n\
	muls r0, r2, r0\n\
	adds r2, r4, #0\n\
	muls r2, r3, r2\n\
	adds r0, r0, r2\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r6, #4]\n\
	adds r1, r1, r2\n\
	strh r1, [r6, #0xc]\n\
	asrs r0, r0, #0x10\n\
	ldrh r4, [r6, #8]\n\
	adds r0, r0, r4\n\
	strh r0, [r6, #0xe]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080946D4: .4byte 0x080A4FA4\n\
    .syntax divided\n");
}

// 0x080946D8
NAKED_FUNCTION
void IntroProcessSplashText(void)
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
	bne _080946FE\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _080946FE\n\
	strb r1, [r2, #0x10]\n\
	ldrb r1, [r2, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r2, #0x18]\n\
_080946FE:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08094704
NAKED_FUNCTION
void IntroProcessSpaceViewParticle(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0x14]\n\
	cmp r0, #0\n\
	bne _08094740\n\
	bl SpecialCutsceneGetRandomNumber\n\
	movs r1, #7\n\
	ands r1, r0\n\
	adds r1, #1\n\
	strh r1, [r4, #8]\n\
	bl SpecialCutsceneGetRandomNumber\n\
	movs r1, #3\n\
	ands r1, r0\n\
	strh r1, [r4, #4]\n\
	ldr r1, _0809473C @ =0x0879C394\n\
	movs r2, #4\n\
	ldrsh r0, [r4, r2]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r4, #0x1c]\n\
	ldrh r0, [r4, #0xc]\n\
	strh r0, [r4]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x14]\n\
	b _08094792\n\
	.align 2, 0\n\
_0809473C: .4byte 0x0879C394\n\
_08094740:\n\
	cmp r0, #1\n\
	bne _08094792\n\
	ldrh r0, [r4, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r4, #0xa]\n\
	movs r0, #8\n\
	ldrsh r1, [r4, r0]\n\
	ldrh r0, [r4, #0xa]\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #4\n\
	ldrh r1, [r4]\n\
	adds r0, r0, r1\n\
	strh r0, [r4, #0xc]\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #8\n\
	bne _08094792\n\
	movs r0, #0\n\
	strb r0, [r4, #0x13]\n\
	ldrh r1, [r4, #4]\n\
	movs r2, #4\n\
	ldrsh r0, [r4, r2]\n\
	cmp r0, #4\n\
	bgt _0809477A\n\
	adds r0, r1, #1\n\
	b _0809477C\n\
_0809477A:\n\
	movs r0, #0\n\
_0809477C:\n\
	strh r0, [r4, #4]\n\
	ldr r1, _080947B4 @ =0x0879C394\n\
	movs r2, #4\n\
	ldrsh r0, [r4, r2]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r4, #0x1c]\n\
	movs r0, #0\n\
	strb r0, [r4, #0x12]\n\
	strb r0, [r4, #0x11]\n\
_08094792:\n\
	movs r1, #0xc\n\
	ldrsh r0, [r4, r1]\n\
	cmp r0, #0xef\n\
	bgt _080947A2\n\
	movs r2, #0xe\n\
	ldrsh r0, [r4, r2]\n\
	cmp r0, #0x9f\n\
	ble _080947AE\n\
_080947A2:\n\
	movs r0, #0\n\
	strb r0, [r4, #0x10]\n\
	ldrb r1, [r4, #0x18]\n\
	subs r0, #2\n\
	ands r0, r1\n\
	strb r0, [r4, #0x18]\n\
_080947AE:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080947B4: .4byte 0x0879C394\n\
    .syntax divided\n");
}

// 0x080947B8
NAKED_FUNCTION
void IntroProcessIdleShipBackview(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	bne _080947D2\n\
	strh r0, [r2, #0xa]\n\
	ldrh r0, [r2, #0xc]\n\
	strh r0, [r2]\n\
	ldrh r0, [r2, #0xe]\n\
	strh r0, [r2, #2]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
	b _080947F0\n\
_080947D2:\n\
	cmp r0, #1\n\
	bne _080947F0\n\
	ldrb r0, [r2, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r2, #0x13]\n\
	ldr r1, _080947F4 @ =0x080A4FA4\n\
	ldrb r0, [r2, #0x13]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x15\n\
	ldrh r1, [r2, #2]\n\
	adds r0, r0, r1\n\
	strh r0, [r2, #0xe]\n\
_080947F0:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080947F4: .4byte 0x080A4FA4\n\
    .syntax divided\n");
}

// 0x080947F8
NAKED_FUNCTION
void IntroProcessBslShipSpawning_2(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	adds r4, r0, #0\n\
	ldrb r5, [r4, #0x14]\n\
	cmp r5, #0\n\
	bne _08094854\n\
	ldrh r1, [r4, #0xc]\n\
	adds r1, #0x7a\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	movs r0, #0xe\n\
	ldrsh r2, [r4, r0]\n\
	movs r0, #0xc\n\
	movs r3, #0\n\
	bl IntroSpaceViewSetupOam\n\
	ldrh r1, [r4, #0xc]\n\
	adds r1, #0x32\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4, #0xe]\n\
	adds r2, #1\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r0, #0xd\n\
	movs r3, #0\n\
	bl IntroSpaceViewSetupOam\n\
	ldrh r1, [r4, #0xc]\n\
	adds r1, #0x24\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	movs r0, #0xe\n\
	ldrsh r2, [r4, r0]\n\
	movs r0, #0xe\n\
	movs r3, #0\n\
	bl IntroSpaceViewSetupOam\n\
	movs r0, #0xc\n\
	ldrsh r1, [r4, r0]\n\
	movs r0, #0xe\n\
	ldrsh r2, [r4, r0]\n\
	movs r0, #0xf\n\
	movs r3, #0\n\
	bl IntroSpaceViewSetupOam\n\
	strb r5, [r4, #0x10]\n\
_08094854:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809485C
NAKED_FUNCTION
void IntroProcessBslShipBackview(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r2, r0, #0\n\
	ldrb r3, [r2, #0x14]\n\
	cmp r3, #0\n\
	bne _080948BA\n\
	ldrb r0, [r2, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r2, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x14\n\
	bne _0809492C\n\
	ldrh r0, [r2]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strh r0, [r2]\n\
	strb r1, [r2, #0x13]\n\
	ldrh r0, [r2, #0xa]\n\
	cmp r0, #4\n\
	bne _08094886\n\
	strh r3, [r2, #0xa]\n\
_08094886:\n\
	ldrh r0, [r2, #0xa]\n\
	adds r1, r0, #0\n\
	adds r3, r0, #0\n\
	cmp r1, #1\n\
	bhi _08094896\n\
	ldrh r0, [r2, #0xe]\n\
	adds r0, #1\n\
	b _0809489E\n\
_08094896:\n\
	cmp r1, #3\n\
	bhi _080948A0\n\
	ldrh r0, [r2, #0xe]\n\
	subs r0, #1\n\
_0809489E:\n\
	strh r0, [r2, #0xe]\n\
_080948A0:\n\
	movs r0, #0\n\
	ldrsh r1, [r2, r0]\n\
	movs r0, #0x96\n\
	lsls r0, r0, #1\n\
	cmp r1, r0\n\
	bne _080948B4\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
	strb r1, [r2, #0x13]\n\
_080948B4:\n\
	adds r0, r3, #1\n\
	strh r0, [r2, #0xa]\n\
	b _0809492C\n\
_080948BA:\n\
	cmp r3, #1\n\
	bne _080948CE\n\
	ldrh r0, [r2, #0xc]\n\
	movs r1, #0\n\
	strh r0, [r2]\n\
	ldrh r0, [r2, #0xe]\n\
	strh r0, [r2, #2]\n\
	strh r1, [r2, #0xa]\n\
	movs r0, #2\n\
	b _0809492A\n\
_080948CE:\n\
	cmp r3, #2\n\
	bne _0809492C\n\
	ldrb r0, [r2, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r2, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _080948EA\n\
	ldrh r0, [r2, #0xa]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strh r0, [r2, #0xa]\n\
	strb r1, [r2, #0x13]\n\
_080948EA:\n\
	movs r4, #0\n\
	ldrsh r1, [r2, r4]\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #2\n\
	subs r0, r0, r1\n\
	ldrh r1, [r2, #0xa]\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #0xc\n\
	ldrh r1, [r2]\n\
	adds r3, r0, r1\n\
	strh r3, [r2, #0xc]\n\
	movs r4, #4\n\
	ldrsh r0, [r2, r4]\n\
	movs r4, #2\n\
	ldrsh r1, [r2, r4]\n\
	subs r0, r0, r1\n\
	ldrh r1, [r2, #0xa]\n\
	muls r0, r1, r0\n\
	asrs r0, r0, #0xb\n\
	ldrh r1, [r2, #2]\n\
	adds r4, r0, r1\n\
	strh r4, [r2, #0xe]\n\
	lsls r1, r3, #0x10\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x11\n\
	cmp r1, r0\n\
	ble _0809492C\n\
	movs r0, #0\n\
	strh r0, [r2, #0xa]\n\
	strh r3, [r2]\n\
	strh r4, [r2, #2]\n\
	movs r0, #3\n\
_0809492A:\n\
	strb r0, [r2, #0x14]\n\
_0809492C:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08094934
NAKED_FUNCTION
void IntroProcessIdleDepthParticle(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldrh r1, [r6, #0xa]\n\
	strh r1, [r6, #4]\n\
	ldrb r0, [r6, #0x14]\n\
	cmp r0, #0\n\
	bne _0809495E\n\
	movs r1, #0xc\n\
	ldrsh r0, [r6, r1]\n\
	subs r0, #0x78\n\
	movs r1, #0x64\n\
	muls r0, r1, r0\n\
	strh r0, [r6]\n\
	movs r2, #0xe\n\
	ldrsh r0, [r6, r2]\n\
	subs r0, #0x50\n\
	muls r0, r1, r0\n\
	strh r0, [r6, #2]\n\
	movs r0, #1\n\
	strb r0, [r6, #0x14]\n\
	b _080949EA\n\
_0809495E:\n\
	lsls r0, r1, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x63\n\
	bgt _080949DC\n\
	cmp r0, #0x19\n\
	bne _08094974\n\
	ldr r0, _08094970 @ =0x0860AC18\n\
	b _08094986\n\
	.align 2, 0\n\
_08094970: .4byte 0x0860AC18\n\
_08094974:\n\
	cmp r0, #0x32\n\
	bne _08094980\n\
	ldr r0, _0809497C @ =0x0860AC28\n\
	b _08094986\n\
	.align 2, 0\n\
_0809497C: .4byte 0x0860AC28\n\
_08094980:\n\
	cmp r0, #0x46\n\
	bne _08094988\n\
	ldr r0, _080949D8 @ =0x0860AC38\n\
_08094986:\n\
	str r0, [r6, #0x1c]\n\
_08094988:\n\
	movs r0, #4\n\
	ldrsh r4, [r6, r0]\n\
	rsbs r4, r4, #0\n\
	adds r4, #0x64\n\
	movs r1, #0\n\
	ldrsh r0, [r6, r1]\n\
	adds r1, r4, #0\n\
	bl __divsi3\n\
	adds r5, r0, #0\n\
	adds r0, #0x78\n\
	strh r0, [r6, #0xc]\n\
	movs r2, #2\n\
	ldrsh r0, [r6, r2]\n\
	adds r1, r4, #0\n\
	bl __divsi3\n\
	adds r1, r0, #0\n\
	adds r1, #0x50\n\
	strh r1, [r6, #0xe]\n\
	adds r5, #0x80\n\
	lsls r5, r5, #0x10\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x11\n\
	cmp r5, r0\n\
	bhi _080949CC\n\
	lsls r0, r1, #0x10\n\
	asrs r1, r0, #0x10\n\
	cmp r1, #0xa8\n\
	bgt _080949CC\n\
	movs r0, #8\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bge _080949EA\n\
_080949CC:\n\
	movs r0, #0\n\
	strb r0, [r6, #0x10]\n\
	ldrb r1, [r6, #0x18]\n\
	subs r0, #2\n\
	b _080949E6\n\
	.align 2, 0\n\
_080949D8: .4byte 0x0860AC38\n\
_080949DC:\n\
	movs r0, #0\n\
	strb r0, [r6, #0x10]\n\
	ldrb r1, [r6, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
_080949E6:\n\
	ands r0, r1\n\
	strb r0, [r6, #0x18]\n\
_080949EA:\n\
	ldrh r0, [r6, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r6, #0xa]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080949F8
NAKED_FUNCTION
void IntroSpaceViewSetupOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov sb, r1\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	mov sl, r2\n\
	lsls r3, r3, #0x18\n\
	cmp r3, #0\n\
	bne _08094A60\n\
	movs r2, #0\n\
	ldr r0, _08094A5C @ =gNonGameplayRam\n\
	movs r3, #0x8b\n\
	lsls r3, r3, #2\n\
	adds r1, r0, r3\n\
	ldrb r1, [r1]\n\
	mov r8, r0\n\
	cmp r1, #0\n\
	beq _08094A4E\n\
	mov r4, r8\n\
_08094A2E:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0x13\n\
	bgt _08094AA0\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08094A2E\n\
_08094A4E:\n\
	lsls r0, r2, #0x18\n\
	asrs r1, r0, #0x18\n\
	mov ip, r0\n\
	cmp r1, #0x13\n\
	ble _08094AA8\n\
	b _08094AA0\n\
	.align 2, 0\n\
_08094A5C: .4byte gNonGameplayRam\n\
_08094A60:\n\
	movs r2, #0x13\n\
	ldr r0, _08094AA4 @ =gNonGameplayRam\n\
	movs r3, #0x9b\n\
	lsls r3, r3, #3\n\
	adds r1, r0, r3\n\
	ldrb r1, [r1]\n\
	mov r8, r0\n\
	cmp r1, #0\n\
	beq _08094A98\n\
	mov r4, r8\n\
	movs r3, #0x8b\n\
	lsls r3, r3, #2\n\
_08094A78:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0xff\n\
	lsls r1, r1, #0x18\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	blt _08094AA0\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08094A78\n\
_08094A98:\n\
	lsls r0, r2, #0x18\n\
	mov ip, r0\n\
	cmp r0, #0\n\
	bge _08094AA8\n\
_08094AA0:\n\
	movs r0, #0x14\n\
	b _08094DD0\n\
	.align 2, 0\n\
_08094AA4: .4byte gNonGameplayRam\n\
_08094AA8:\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r2, _08094B10 @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r2]\n\
	mov r0, ip\n\
	asrs r1, r0, #0x18\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r4, r0, #2\n\
	ldr r3, _08094B14 @ =0x030016A0\n\
	adds r0, r4, r3\n\
	str r0, [r2, #4]\n\
	ldr r0, _08094B18 @ =0x85000009\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	ldr r1, _08094B1C @ =0xFFFFFDE4\n\
	adds r0, r3, r1\n\
	adds r2, r4, r0\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	movs r7, #0\n\
	mov r1, sb\n\
	strh r1, [r0]\n\
	ldr r1, _08094B20 @ =0x0000022A\n\
	adds r0, r2, r1\n\
	mov r1, sl\n\
	strh r1, [r0]\n\
	movs r1, #0x8b\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	strb r6, [r0]\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r5, r2, r0\n\
	ldrb r1, [r5]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strb r1, [r5]\n\
	cmp r6, #1\n\
	bne _08094B28\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r5]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08094B24 @ =IntroProcessSpaceViewScrolling\n\
	str r1, [r0]\n\
	b _08094DCC\n\
	.align 2, 0\n\
_08094B10: .4byte 0x040000D4\n\
_08094B14: .4byte 0x030016A0\n\
_08094B18: .4byte 0x85000009\n\
_08094B1C: .4byte 0xFFFFFDE4\n\
_08094B20: .4byte 0x0000022A\n\
_08094B24: .4byte IntroProcessSpaceViewScrolling\n\
_08094B28:\n\
	cmp r6, #2\n\
	bne _08094B44\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r5]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08094B40 @ =IntroProcessBslShipSideways\n\
	str r1, [r0]\n\
	b _08094DCC\n\
	.align 2, 0\n\
_08094B40: .4byte IntroProcessBslShipSideways\n\
_08094B44:\n\
	cmp r6, #3\n\
	bne _08094B90\n\
	ldr r0, _08094B80 @ =0x00000222\n\
	adds r1, r2, r0\n\
	subs r0, #0xa2\n\
	strh r0, [r1]\n\
	ldr r1, _08094B84 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r0, [r5]\n\
	movs r1, #6\n\
	orrs r0, r1\n\
	strb r0, [r5]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08094B88 @ =0x0860AC98\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08094B8C @ =IntroProcessSamusSHipEntering\n\
	str r1, [r0]\n\
	b _08094DCC\n\
	.align 2, 0\n\
_08094B80: .4byte 0x00000222\n\
_08094B84: .4byte 0x00000236\n\
_08094B88: .4byte 0x0860AC98\n\
_08094B8C: .4byte IntroProcessSamusSHipEntering\n\
_08094B90:\n\
	cmp r6, #4\n\
	bne _08094BB4\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08094BAC @ =0x0860AF10\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08094BB0 @ =IntroProcessSplashText\n\
	str r1, [r0]\n\
	b _08094DCC\n\
	.align 2, 0\n\
_08094BAC: .4byte 0x0860AF10\n\
_08094BB0: .4byte IntroProcessSplashText\n\
_08094BB4:\n\
	cmp r6, #5\n\
	bne _08094BE8\n\
	ldr r0, _08094BDC @ =0x00000236\n\
	adds r2, r2, r0\n\
	ldrb r0, [r2]\n\
	movs r1, #0xc\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08094BE0 @ =0x0860AC38\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08094BE4 @ =IntroProcessSpaceViewParticle\n\
	str r1, [r0]\n\
	b _08094DCC\n\
	.align 2, 0\n\
_08094BDC: .4byte 0x00000236\n\
_08094BE0: .4byte 0x0860AC38\n\
_08094BE4: .4byte IntroProcessSpaceViewParticle\n\
_08094BE8:\n\
	cmp r6, #0xa\n\
	bne _08094C54\n\
	movs r1, #0x87\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	mov r1, sb\n\
	strh r1, [r0]\n\
	ldr r1, _08094C40 @ =0x0000021E\n\
	adds r0, r2, r1\n\
	mov r1, sl\n\
	strh r1, [r0]\n\
	ldr r0, _08094C44 @ =0x00000222\n\
	adds r1, r2, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r1]\n\
	ldr r1, _08094C48 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r5]\n\
	movs r0, #7\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r5]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08094C4C @ =0x0860ACD0\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08094C50 @ =IntroProcessIdleShipBackview\n\
	str r1, [r0]\n\
	b _08094DCC\n\
	.align 2, 0\n\
_08094C40: .4byte 0x0000021E\n\
_08094C44: .4byte 0x00000222\n\
_08094C48: .4byte 0x00000236\n\
_08094C4C: .4byte 0x0860ACD0\n\
_08094C50: .4byte IntroProcessIdleShipBackview\n\
_08094C54:\n\
	cmp r6, #0xb\n\
	bne _08094C80\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r5]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08094C78 @ =0x0860ACD0\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08094C7C @ =IntroProcessBslShipSpawning_2\n\
	str r1, [r0]\n\
	b _08094DCC\n\
	.align 2, 0\n\
_08094C78: .4byte 0x0860ACD0\n\
_08094C7C: .4byte IntroProcessBslShipSpawning_2\n\
_08094C80:\n\
	cmp r6, #0xc\n\
	bne _08094CB8\n\
	movs r0, #0x88\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _08094CAC @ =0x0000FFD8\n\
	strh r0, [r1]\n\
	ldr r1, _08094CB0 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08094CB4 @ =0x0860AD28\n\
	b _08094D18\n\
	.align 2, 0\n\
_08094CAC: .4byte 0x0000FFD8\n\
_08094CB0: .4byte 0x00000236\n\
_08094CB4: .4byte 0x0860AD28\n\
_08094CB8:\n\
	cmp r6, #0xd\n\
	bne _08094CF0\n\
	movs r0, #0x88\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _08094CE4 @ =0x0000FFE2\n\
	strh r0, [r1]\n\
	ldr r1, _08094CE8 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08094CEC @ =0x0860AD18\n\
	b _08094D18\n\
	.align 2, 0\n\
_08094CE4: .4byte 0x0000FFE2\n\
_08094CE8: .4byte 0x00000236\n\
_08094CEC: .4byte 0x0860AD18\n\
_08094CF0:\n\
	cmp r6, #0xe\n\
	bne _08094D38\n\
	movs r0, #0x88\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _08094D28 @ =0x0000FFEC\n\
	strh r0, [r1]\n\
	ldr r1, _08094D2C @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08094D30 @ =0x0860AD08\n\
_08094D18:\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08094D34 @ =IntroProcessBslShipBackview\n\
	str r1, [r0]\n\
	b _08094DCC\n\
	.align 2, 0\n\
_08094D28: .4byte 0x0000FFEC\n\
_08094D2C: .4byte 0x00000236\n\
_08094D30: .4byte 0x0860AD08\n\
_08094D34: .4byte IntroProcessBslShipBackview\n\
_08094D38:\n\
	cmp r6, #0xf\n\
	bne _08094D90\n\
	mov r3, ip\n\
	asrs r0, r3, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	mov r0, r8\n\
	adds r3, r2, r0\n\
	movs r0, #0x88\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	ldr r0, _08094D80 @ =0x0000FFF6\n\
	strh r0, [r1]\n\
	ldr r1, _08094D84 @ =0x00000236\n\
	adds r3, r3, r1\n\
	ldrb r1, [r3]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r0, r2, r0\n\
	ldr r1, _08094D88 @ =0x0860ACF8\n\
	str r1, [r0]\n\
	movs r0, #0x8f\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r2, r2, r0\n\
	ldr r0, _08094D8C @ =IntroProcessBslShipBackview\n\
	b _08094DCA\n\
	.align 2, 0\n\
_08094D80: .4byte 0x0000FFF6\n\
_08094D84: .4byte 0x00000236\n\
_08094D88: .4byte 0x0860ACF8\n\
_08094D8C: .4byte IntroProcessBslShipBackview\n\
_08094D90:\n\
	cmp r6, #0x10\n\
	bne _08094DCC\n\
	mov r3, ip\n\
	asrs r0, r3, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	mov r0, r8\n\
	adds r3, r2, r0\n\
	ldr r1, _08094DE0 @ =0x00000236\n\
	adds r3, r3, r1\n\
	ldrb r1, [r3]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r0, r2, r0\n\
	ldr r1, _08094DE4 @ =0x0860AC08\n\
	str r1, [r0]\n\
	movs r0, #0x8f\n\
	lsls r0, r0, #2\n\
	add r0, r8\n\
	adds r2, r2, r0\n\
	ldr r0, _08094DE8 @ =IntroProcessIdleDepthParticle\n\
_08094DCA:\n\
	str r0, [r2]\n\
_08094DCC:\n\
	mov r3, ip\n\
	lsrs r0, r3, #0x18\n\
_08094DD0:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08094DE0: .4byte 0x00000236\n\
_08094DE4: .4byte 0x0860AC08\n\
_08094DE8: .4byte IntroProcessIdleDepthParticle\n\
    .syntax divided\n");
}

// 0x08094DEC
NAKED_FUNCTION
void IntroSpaceViewVblank(void)
{
    asm(" .syntax unified\n\
	ldr r1, _08094E48 @ =0x040000D4\n\
	ldr r0, _08094E4C @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _08094E50 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r2, _08094E54 @ =0x04000052\n\
	ldr r0, _08094E58 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _08094E5C @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08094E60 @ =0x04000054\n\
	ldr r0, _08094E64 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x40\n\
	ldr r0, _08094E68 @ =gBg1XPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08094E6C @ =gBg1YPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08094E70 @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08094E74 @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08094E78 @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08094E7C @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_08094E48: .4byte 0x040000D4\n\
_08094E4C: .4byte gOamData\n\
_08094E50: .4byte 0x84000100\n\
_08094E54: .4byte 0x04000052\n\
_08094E58: .4byte gWrittenToBldalpha_Evb\n\
_08094E5C: .4byte gWrittenToBldalpha_Eva\n\
_08094E60: .4byte 0x04000054\n\
_08094E64: .4byte gWrittenToBldy\n\
_08094E68: .4byte gBg1XPosition\n\
_08094E6C: .4byte gBg1YPosition\n\
_08094E70: .4byte 0x0300122C\n\
_08094E74: .4byte 0x0300122E\n\
_08094E78: .4byte 0x03001230\n\
_08094E7C: .4byte 0x03001232\n\
    .syntax divided\n");
}

// 0x08094E80
NAKED_FUNCTION
void unk_94e80(void)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}
