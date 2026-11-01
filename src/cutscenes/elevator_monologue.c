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

// 0x08099B04
NAKED_FUNCTION
boolu32 CutsceneProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	movs r4, #0\n\
	ldr r0, _08099B1C @ =gCurrentCutscene\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	cmp r0, #0xb\n\
	bhi _08099BA0\n\
	lsls r0, r0, #2\n\
	ldr r1, _08099B20 @ =_08099B24\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08099B1C: .4byte gCurrentCutscene\n\
_08099B20: .4byte _08099B24\n\
_08099B24: @ jump table\n\
	.4byte _08099B54 @ case 0\n\
	.4byte _08099B5C @ case 1\n\
	.4byte _08099B64 @ case 2\n\
	.4byte _08099B6C @ case 3\n\
	.4byte _08099B74 @ case 4\n\
	.4byte _08099B7C @ case 5\n\
	.4byte _08099B84 @ case 6\n\
	.4byte _08099B54 @ case 7\n\
	.4byte _08099B8C @ case 8\n\
	.4byte _08099B92 @ case 9\n\
	.4byte _08099B92 @ case 10\n\
	.4byte _08099B98 @ case 11\n\
_08099B54:\n\
	movs r0, #0\n\
	bl CutsceneInternalMonologue\n\
	b _08099B9C\n\
_08099B5C:\n\
	movs r0, #0\n\
	bl CutsceneElevatorMonologue\n\
	b _08099B9C\n\
_08099B64:\n\
	movs r0, #0\n\
	bl CutsceneElevatorMonologue\n\
	b _08099B9C\n\
_08099B6C:\n\
	movs r0, #0\n\
	bl CutsceneElevatorMonologue\n\
	b _08099B9C\n\
_08099B74:\n\
	movs r0, #1\n\
	bl CutsceneElevatorMonologue\n\
	b _08099B9C\n\
_08099B7C:\n\
	movs r0, #0\n\
	bl CutsceneElevatorMonologue\n\
	b _08099B9C\n\
_08099B84:\n\
	movs r0, #0\n\
	bl CutsceneFederationMonologue\n\
	b _08099B9C\n\
_08099B8C:\n\
	bl CutsceneSecretConversation\n\
	b _08099B9C\n\
_08099B92:\n\
	bl CutsceneRestrictedLabDetaching\n\
	b _08099B9C\n\
_08099B98:\n\
	bl CutsceneBslExploding\n\
_08099B9C:\n\
	cmp r0, #0\n\
	beq _08099BA2\n\
_08099BA0:\n\
	movs r4, #1\n\
_08099BA2:\n\
	adds r0, r4, #0\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08099BAC
NAKED_FUNCTION
boolu32 CutsceneElevatorMonologue(u8 param_1)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	movs r5, #0\n\
	ldr r4, _08099BC8 @ =gNonGameplayRam\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #1\n\
	beq _08099BE2\n\
	cmp r0, #1\n\
	bgt _08099BCC\n\
	cmp r0, #0\n\
	beq _08099BD6\n\
	b _08099C2A\n\
	.align 2, 0\n\
_08099BC8: .4byte gNonGameplayRam\n\
_08099BCC:\n\
	cmp r0, #2\n\
	beq _08099BFC\n\
	cmp r0, #3\n\
	beq _08099C1C\n\
	b _08099C2A\n\
_08099BD6:\n\
	movs r0, #1\n\
	strh r0, [r4, #8]\n\
	adds r0, r1, #0\n\
	bl CutsceneElevatorMonologueInit\n\
	b _08099C2A\n\
_08099BE2:\n\
	bl CutsceneMonologueFadeIn\n\
	ldr r0, _08099BF8 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _08099C2A\n\
	ldrh r0, [r4, #8]\n\
	adds r0, #1\n\
	strh r0, [r4, #8]\n\
	b _08099C2A\n\
	.align 2, 0\n\
_08099BF8: .4byte gWrittenToBldy\n\
_08099BFC:\n\
	bl CutsceneElevatorMonologueProcess\n\
	cmp r0, #0\n\
	beq _08099C2A\n\
	movs r0, #3\n\
	strh r0, [r4, #8]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r2, #0xa8\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x50\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	b _08099C2A\n\
_08099C1C:\n\
	bl CutsceneMonologueFadeOut\n\
	ldr r0, _08099C34 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0x10\n\
	bne _08099C2A\n\
	movs r5, #1\n\
_08099C2A:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08099C34: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x08099C38
NAKED_FUNCTION
void CutsceneElevatorMonologueInit(u8 param_1)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6}\n\
	mov r8, r0\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r8, r0\n\
	ldr r3, _08099D84 @ =0x04000208\n\
	movs r4, #0\n\
	strh r4, [r3]\n\
	ldr r2, _08099D88 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _08099D8C @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _08099D90 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _08099D94 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _08099D98 @ =unk_9a31c\n\
	bl CallbackSetVBlank\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	mov sb, r1\n\
	strh r4, [r1]\n\
	ldr r1, _08099D9C @ =0x0879C514\n\
	ldr r6, _08099DA0 @ =gCurrentCutscene\n\
	ldrb r0, [r6]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r1, _08099DA4 @ =0x06012000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08099DA8 @ =0x0865FB5C\n\
	ldr r1, _08099DAC @ =0x06017C00\n\
	bl LZ77UncompVram\n\
	ldr r4, _08099DB0 @ =0x040000D4\n\
	ldr r0, _08099DB4 @ =0x086638A0\n\
	str r0, [r4]\n\
	ldr r0, _08099DB8 @ =0x050003E0\n\
	str r0, [r4, #4]\n\
	ldr r0, _08099DBC @ =0x84000008\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r1, _08099DC0 @ =0x0879C4CC\n\
	ldrb r0, [r6]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r4]\n\
	ldr r0, _08099DC4 @ =0x05000200\n\
	str r0, [r4, #4]\n\
	ldr r0, _08099DC8 @ =0x84000030\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r1, _08099DCC @ =0x0879C4F0\n\
	ldrb r0, [r6]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r1, _08099DD0 @ =0x0879C538\n\
	ldrb r0, [r6]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r1, _08099DD4 @ =0x0600D000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08099DD8 @ =0x08662804\n\
	movs r5, #0x80\n\
	lsls r5, r5, #0x12\n\
	adds r1, r5, #0\n\
	bl LZ77UncompWram\n\
	ldr r0, _08099DDC @ =0x08663598\n\
	ldr r1, _08099DE0 @ =0x0600D800\n\
	bl LZ77UncompVram\n\
	str r5, [r4]\n\
	ldr r0, _08099DE4 @ =0x0600C800\n\
	str r0, [r4, #4]\n\
	ldr r0, _08099DE8 @ =0x84000200\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08099DEC @ =0x086636A0\n\
	str r0, [r4]\n\
	movs r2, #0xa0\n\
	lsls r2, r2, #0x13\n\
	str r2, [r4, #4]\n\
	ldr r0, _08099DF0 @ =0x84000080\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r1, _08099DF4 @ =0x0879C4A8\n\
	ldrb r0, [r6]\n\
	subs r0, #1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r4]\n\
	str r2, [r4, #4]\n\
	ldr r0, _08099DF8 @ =0x84000058\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r1, _08099DFC @ =0x04000012\n\
	movs r0, #4\n\
	strh r0, [r1]\n\
	subs r1, #0xa\n\
	ldr r2, _08099E00 @ =0x00001908\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _08099E04 @ =0x00001B01\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	subs r2, #0xfe\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r1, #0xa8\n\
	lsls r1, r1, #5\n\
	adds r0, r1, #0\n\
	mov r2, sb\n\
	strh r0, [r2]\n\
	ldr r1, _08099E08 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
	movs r1, #0xc\n\
	movs r2, #0x10\n\
	bl CutsceneElevatorMonologueSetupOam\n\
	movs r0, #2\n\
	movs r1, #0x78\n\
	movs r2, #0x78\n\
	bl CutsceneElevatorMonologueSetupOam\n\
	movs r0, #3\n\
	movs r1, #0x78\n\
	movs r2, #0x78\n\
	bl CutsceneElevatorMonologueSetupOam\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	bne _08099E0C\n\
	movs r0, #4\n\
	movs r1, #0x78\n\
	movs r2, #0x68\n\
	bl CutsceneElevatorMonologueSetupOam\n\
	b _08099E16\n\
	.align 2, 0\n\
_08099D84: .4byte 0x04000208\n\
_08099D88: .4byte 0x04000004\n\
_08099D8C: .4byte 0x0000FFEF\n\
_08099D90: .4byte 0x04000200\n\
_08099D94: .4byte 0x0000FFFD\n\
_08099D98: .4byte unk_9a31c\n\
_08099D9C: .4byte 0x0879C514\n\
_08099DA0: .4byte gCurrentCutscene\n\
_08099DA4: .4byte 0x06012000\n\
_08099DA8: .4byte 0x0865FB5C\n\
_08099DAC: .4byte 0x06017C00\n\
_08099DB0: .4byte 0x040000D4\n\
_08099DB4: .4byte 0x086638A0\n\
_08099DB8: .4byte 0x050003E0\n\
_08099DBC: .4byte 0x84000008\n\
_08099DC0: .4byte 0x0879C4CC\n\
_08099DC4: .4byte 0x05000200\n\
_08099DC8: .4byte 0x84000030\n\
_08099DCC: .4byte 0x0879C4F0\n\
_08099DD0: .4byte 0x0879C538\n\
_08099DD4: .4byte 0x0600D000\n\
_08099DD8: .4byte 0x08662804\n\
_08099DDC: .4byte 0x08663598\n\
_08099DE0: .4byte 0x0600D800\n\
_08099DE4: .4byte 0x0600C800\n\
_08099DE8: .4byte 0x84000200\n\
_08099DEC: .4byte 0x086636A0\n\
_08099DF0: .4byte 0x84000080\n\
_08099DF4: .4byte 0x0879C4A8\n\
_08099DF8: .4byte 0x84000058\n\
_08099DFC: .4byte 0x04000012\n\
_08099E00: .4byte 0x00001908\n\
_08099E04: .4byte 0x00001B01\n\
_08099E08: .4byte gWrittenToBldy\n\
_08099E0C:\n\
	movs r0, #5\n\
	movs r1, #0x78\n\
	movs r2, #0x68\n\
	bl CutsceneElevatorMonologueSetupOam\n\
_08099E16:\n\
	ldr r2, _08099E50 @ =gNonGameplayRam\n\
	ldr r0, _08099E54 @ =gCurrentCutscene\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	strh r0, [r2, #0xa]\n\
	ldr r1, _08099E58 @ =0x0879C5A4\n\
	ldr r0, _08099E5C @ =0x03000011\n\
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
	ldr r0, _08099E60 @ =CutsceneElevatorMonologueVblank\n\
	bl CallbackSetVBlank\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08099E50: .4byte gNonGameplayRam\n\
_08099E54: .4byte gCurrentCutscene\n\
_08099E58: .4byte 0x0879C5A4\n\
_08099E5C: .4byte 0x03000011\n\
_08099E60: .4byte CutsceneElevatorMonologueVblank\n\
    .syntax divided\n");
}

// 0x08099E64
NAKED_FUNCTION
boolu32 CutsceneElevatorMonologueProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	bl CutsceneMonologueProcessSpecialTextCharacters\n\
	adds r4, r0, #0\n\
	ldr r1, _08099E7C @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x17]\n\
	cmp r0, #0\n\
	beq _08099E80\n\
	cmp r0, #1\n\
	beq _08099E86\n\
	b _08099E8E\n\
	.align 2, 0\n\
_08099E7C: .4byte gNonGameplayRam\n\
_08099E80:\n\
	movs r0, #0x64\n\
	strb r0, [r1, #0x17]\n\
	b _08099E8E\n\
_08099E86:\n\
	movs r0, #0x64\n\
	strb r0, [r1, #0x17]\n\
	bl CutsceneMonologueProcessText\n\
_08099E8E:\n\
	bl CutsceneMonologueProcessOam\n\
	bl CutsceneMonologueDrawAllOam\n\
	adds r0, r4, #0\n\
	pop {r4}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08099EA0
NAKED_FUNCTION
u8 CutsceneElevatorMonologueSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r7, r1, #0x10\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	mov r8, r2\n\
	movs r6, #0\n\
	ldr r1, _08099EEC @ =gNonGameplayRam\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _08099EE2\n\
	adds r3, r1, #0\n\
	adds r1, r2, #0\n\
_08099EC8:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r6, r0, #0x18\n\
	cmp r6, #4\n\
	bhi _08099EE6\n\
	lsls r0, r6, #1\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r3\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08099EC8\n\
_08099EE2:\n\
	cmp r6, #4\n\
	bls _08099EF0\n\
_08099EE6:\n\
	movs r0, #5\n\
	b _0809A06C\n\
	.align 2, 0\n\
_08099EEC: .4byte gNonGameplayRam\n\
_08099EF0:\n\
	adds r0, r6, #0\n\
	bl CutsceneMonologueResetOam\n\
	ldr r3, _08099F50 @ =gNonGameplayRam\n\
	lsls r0, r6, #1\n\
	adds r0, r0, r6\n\
	lsls r5, r0, #3\n\
	adds r2, r5, r3\n\
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
	strb r4, [r0]\n\
	ldr r0, _08099F54 @ =0x00000219\n\
	adds r1, r2, r0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	cmp r4, #1\n\
	bne _08099F68\n\
	ldr r0, _08099F58 @ =0x00000221\n\
	adds r1, r2, r0\n\
	movs r0, #0xf\n\
	strb r0, [r1]\n\
	ldr r0, _08099F5C @ =0x00000222\n\
	adds r1, r2, r0\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #2\n\
	strh r0, [r1]\n\
	movs r1, #0x89\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	adds r0, r5, r0\n\
	ldr r1, _08099F60 @ =0x08663E5C\n\
	str r1, [r0]\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	adds r0, r5, r0\n\
	ldr r1, _08099F64 @ =CutsceneMonologueProcessCursor\n\
	b _0809A068\n\
	.align 2, 0\n\
_08099F50: .4byte gNonGameplayRam\n\
_08099F54: .4byte 0x00000219\n\
_08099F58: .4byte 0x00000221\n\
_08099F5C: .4byte 0x00000222\n\
_08099F60: .4byte 0x08663E5C\n\
_08099F64: .4byte CutsceneMonologueProcessCursor\n\
_08099F68:\n\
	cmp r4, #2\n\
	bne _08099FA8\n\
	ldr r0, _08099F98 @ =0x0000021F\n\
	adds r1, r2, r0\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	movs r0, #0x89\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	adds r1, r5, r1\n\
	ldr r2, _08099F9C @ =0x0879C55C\n\
	ldr r0, _08099FA0 @ =gCurrentCutscene\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	adds r0, r5, r0\n\
	ldr r1, _08099FA4 @ =unk_9d09c\n\
	b _0809A068\n\
	.align 2, 0\n\
_08099F98: .4byte 0x0000021F\n\
_08099F9C: .4byte 0x0879C55C\n\
_08099FA0: .4byte gCurrentCutscene\n\
_08099FA4: .4byte unk_9d09c\n\
_08099FA8:\n\
	cmp r4, #3\n\
	bne _08099FF4\n\
	ldr r0, _08099FE0 @ =0x0000021E\n\
	adds r1, r2, r0\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	ldr r1, _08099FE4 @ =0x0000021F\n\
	adds r0, r2, r1\n\
	strb r4, [r0]\n\
	movs r0, #0x89\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	adds r1, r5, r1\n\
	ldr r2, _08099FE8 @ =0x0879C55C\n\
	ldr r0, _08099FEC @ =gCurrentCutscene\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	adds r0, r5, r0\n\
	ldr r1, _08099FF0 @ =unk_9d09c\n\
	b _0809A068\n\
	.align 2, 0\n\
_08099FE0: .4byte 0x0000021E\n\
_08099FE4: .4byte 0x0000021F\n\
_08099FE8: .4byte 0x0879C55C\n\
_08099FEC: .4byte gCurrentCutscene\n\
_08099FF0: .4byte unk_9d09c\n\
_08099FF4:\n\
	cmp r4, #4\n\
	bne _0809A038\n\
	ldr r0, _0809A028 @ =0x0000021F\n\
	adds r1, r2, r0\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	movs r1, #0x89\n\
	lsls r1, r1, #2\n\
	adds r2, r3, r1\n\
	adds r2, r5, r2\n\
	ldr r1, _0809A02C @ =0x0879C55C\n\
	ldr r0, _0809A030 @ =gCurrentCutscene\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	lsls r0, r0, #3\n\
	adds r1, #4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	adds r0, r5, r0\n\
	ldr r1, _0809A034 @ =CutsceneProcessElevatorScrolling\n\
	b _0809A068\n\
	.align 2, 0\n\
_0809A028: .4byte 0x0000021F\n\
_0809A02C: .4byte 0x0879C55C\n\
_0809A030: .4byte gCurrentCutscene\n\
_0809A034: .4byte CutsceneProcessElevatorScrolling\n\
_0809A038:\n\
	cmp r4, #5\n\
	bne _0809A06A\n\
	ldr r0, _0809A078 @ =0x0000021F\n\
	adds r1, r2, r0\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	movs r1, #0x89\n\
	lsls r1, r1, #2\n\
	adds r2, r3, r1\n\
	adds r2, r5, r2\n\
	ldr r1, _0809A07C @ =0x0879C55C\n\
	ldr r0, _0809A080 @ =gCurrentCutscene\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	lsls r0, r0, #3\n\
	adds r1, #4\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	adds r0, r5, r0\n\
	ldr r1, _0809A084 @ =unk_9a1a8\n\
_0809A068:\n\
	str r1, [r0]\n\
_0809A06A:\n\
	adds r0, r6, #0\n\
_0809A06C:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809A078: .4byte 0x0000021F\n\
_0809A07C: .4byte 0x0879C55C\n\
_0809A080: .4byte gCurrentCutscene\n\
_0809A084: .4byte unk_9a1a8\n\
    .syntax divided\n");
}

// 0x0809A088
NAKED_FUNCTION
void CutsceneProcessElevatorScrolling(struct CutsceneMonologueOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldrh r0, [r4, #2]\n\
	adds r0, #2\n\
	movs r5, #0\n\
	strh r0, [r4, #2]\n\
	ldr r3, _0809A0F8 @ =0x0400001A\n\
	ldr r2, _0809A0FC @ =gNonGameplayRam\n\
	ldrh r0, [r2, #0x12]\n\
	subs r0, #1\n\
	strh r0, [r2, #0x12]\n\
	ldr r6, _0809A100 @ =0x0000FFFF\n\
	adds r1, r6, #0\n\
	ands r0, r1\n\
	strh r0, [r3]\n\
	ldrb r3, [r4, #9]\n\
	adds r6, r2, #0\n\
	cmp r3, #0\n\
	bne _0809A124\n\
	ldr r0, _0809A104 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809A19A\n\
	ldr r0, _0809A108 @ =gWrittenToBldalpha_Eva\n\
	strh r3, [r0]\n\
	ldr r0, _0809A10C @ =gWrittenToBldalpha_Evb\n\
	movs r2, #0x10\n\
	strh r2, [r0]\n\
	ldr r0, _0809A110 @ =0x04000048\n\
	strh r3, [r0]\n\
	ldr r1, _0809A114 @ =0x0400004A\n\
	ldr r5, _0809A118 @ =0x0000331D\n\
	adds r0, r5, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0809A11C @ =0x04000016\n\
	strh r3, [r6, #0x14]\n\
	strh r3, [r0]\n\
	adds r0, #0x3c\n\
	lsls r2, r2, #8\n\
	strh r2, [r0]\n\
	adds r1, #6\n\
	ldr r6, _0809A120 @ =0x00001042\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r3, #0x82\n\
	lsls r3, r3, #8\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _0809A19A\n\
	.align 2, 0\n\
_0809A0F8: .4byte 0x0400001A\n\
_0809A0FC: .4byte gNonGameplayRam\n\
_0809A100: .4byte 0x0000FFFF\n\
_0809A104: .4byte gWrittenToBldy\n\
_0809A108: .4byte gWrittenToBldalpha_Eva\n\
_0809A10C: .4byte gWrittenToBldalpha_Evb\n\
_0809A110: .4byte 0x04000048\n\
_0809A114: .4byte 0x0400004A\n\
_0809A118: .4byte 0x0000331D\n\
_0809A11C: .4byte 0x04000016\n\
_0809A120: .4byte 0x00001042\n\
_0809A124:\n\
	cmp r3, #1\n\
	bne _0809A164\n\
	ldr r2, _0809A138 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #0xa\n\
	bne _0809A13C\n\
	movs r0, #2\n\
	strb r0, [r4, #9]\n\
	strb r5, [r4, #8]\n\
	b _0809A14E\n\
	.align 2, 0\n\
_0809A138: .4byte gWrittenToBldalpha_Eva\n\
_0809A13C:\n\
	ldrb r0, [r4, #8]\n\
	cmp r0, #3\n\
	bls _0809A14A\n\
	strb r5, [r4, #8]\n\
	adds r0, r1, #1\n\
	strh r0, [r2]\n\
	b _0809A14E\n\
_0809A14A:\n\
	adds r0, #1\n\
	strb r0, [r4, #8]\n\
_0809A14E:\n\
	ldr r0, _0809A15C @ =0x04000016\n\
	ldrh r1, [r6, #0x14]\n\
	subs r1, #3\n\
	strh r1, [r6, #0x14]\n\
	ldr r5, _0809A160 @ =0x0000FFFF\n\
	adds r2, r5, #0\n\
	b _0809A196\n\
	.align 2, 0\n\
_0809A15C: .4byte 0x04000016\n\
_0809A160: .4byte 0x0000FFFF\n\
_0809A164:\n\
	ldr r2, _0809A174 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #4\n\
	bne _0809A178\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	strb r5, [r4, #8]\n\
	b _0809A18A\n\
	.align 2, 0\n\
_0809A174: .4byte gWrittenToBldalpha_Eva\n\
_0809A178:\n\
	ldrb r0, [r4, #8]\n\
	cmp r0, #3\n\
	bls _0809A186\n\
	strb r5, [r4, #8]\n\
	subs r0, r1, #1\n\
	strh r0, [r2]\n\
	b _0809A18A\n\
_0809A186:\n\
	adds r0, #1\n\
	strb r0, [r4, #8]\n\
_0809A18A:\n\
	ldr r0, _0809A1A0 @ =0x04000016\n\
	ldrh r1, [r6, #0x14]\n\
	subs r1, #3\n\
	strh r1, [r6, #0x14]\n\
	ldr r6, _0809A1A4 @ =0x0000FFFF\n\
	adds r2, r6, #0\n\
_0809A196:\n\
	ands r1, r2\n\
	strh r1, [r0]\n\
_0809A19A:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809A1A0: .4byte 0x04000016\n\
_0809A1A4: .4byte 0x0000FFFF\n\
    .syntax divided\n");
}

// 0x0809A1A8
NAKED_FUNCTION
void unk_9a1a8(struct CutsceneMonologueOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldrh r0, [r4, #2]\n\
	subs r0, #2\n\
	movs r5, #0\n\
	strh r0, [r4, #2]\n\
	ldr r3, _0809A218 @ =0x0400001A\n\
	ldr r2, _0809A21C @ =gNonGameplayRam\n\
	ldrh r0, [r2, #0x12]\n\
	adds r0, #1\n\
	strh r0, [r2, #0x12]\n\
	ldr r6, _0809A220 @ =0x0000FFFF\n\
	adds r1, r6, #0\n\
	ands r0, r1\n\
	strh r0, [r3]\n\
	ldrb r3, [r4, #9]\n\
	adds r6, r2, #0\n\
	cmp r3, #0\n\
	bne _0809A244\n\
	ldr r0, _0809A224 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809A2BA\n\
	ldr r0, _0809A228 @ =gWrittenToBldalpha_Eva\n\
	strh r3, [r0]\n\
	ldr r0, _0809A22C @ =gWrittenToBldalpha_Evb\n\
	movs r2, #0x10\n\
	strh r2, [r0]\n\
	ldr r0, _0809A230 @ =0x04000048\n\
	strh r3, [r0]\n\
	ldr r1, _0809A234 @ =0x0400004A\n\
	ldr r5, _0809A238 @ =0x0000331D\n\
	adds r0, r5, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0809A23C @ =0x04000016\n\
	strh r3, [r6, #0x14]\n\
	strh r3, [r0]\n\
	adds r0, #0x3c\n\
	lsls r2, r2, #8\n\
	strh r2, [r0]\n\
	adds r1, #6\n\
	ldr r6, _0809A240 @ =0x00001042\n\
	adds r0, r6, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r3, #0x82\n\
	lsls r3, r3, #8\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	b _0809A2BA\n\
	.align 2, 0\n\
_0809A218: .4byte 0x0400001A\n\
_0809A21C: .4byte gNonGameplayRam\n\
_0809A220: .4byte 0x0000FFFF\n\
_0809A224: .4byte gWrittenToBldy\n\
_0809A228: .4byte gWrittenToBldalpha_Eva\n\
_0809A22C: .4byte gWrittenToBldalpha_Evb\n\
_0809A230: .4byte 0x04000048\n\
_0809A234: .4byte 0x0400004A\n\
_0809A238: .4byte 0x0000331D\n\
_0809A23C: .4byte 0x04000016\n\
_0809A240: .4byte 0x00001042\n\
_0809A244:\n\
	cmp r3, #1\n\
	bne _0809A284\n\
	ldr r2, _0809A258 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #0xa\n\
	bne _0809A25C\n\
	movs r0, #2\n\
	strb r0, [r4, #9]\n\
	strb r5, [r4, #8]\n\
	b _0809A26E\n\
	.align 2, 0\n\
_0809A258: .4byte gWrittenToBldalpha_Eva\n\
_0809A25C:\n\
	ldrb r0, [r4, #8]\n\
	cmp r0, #3\n\
	bls _0809A26A\n\
	strb r5, [r4, #8]\n\
	adds r0, r1, #1\n\
	strh r0, [r2]\n\
	b _0809A26E\n\
_0809A26A:\n\
	adds r0, #1\n\
	strb r0, [r4, #8]\n\
_0809A26E:\n\
	ldr r0, _0809A27C @ =0x04000016\n\
	ldrh r1, [r6, #0x14]\n\
	adds r1, #3\n\
	strh r1, [r6, #0x14]\n\
	ldr r5, _0809A280 @ =0x0000FFFF\n\
	adds r2, r5, #0\n\
	b _0809A2B6\n\
	.align 2, 0\n\
_0809A27C: .4byte 0x04000016\n\
_0809A280: .4byte 0x0000FFFF\n\
_0809A284:\n\
	ldr r2, _0809A294 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r2]\n\
	cmp r1, #4\n\
	bne _0809A298\n\
	movs r0, #1\n\
	strb r0, [r4, #9]\n\
	strb r5, [r4, #8]\n\
	b _0809A2AA\n\
	.align 2, 0\n\
_0809A294: .4byte gWrittenToBldalpha_Eva\n\
_0809A298:\n\
	ldrb r0, [r4, #8]\n\
	cmp r0, #3\n\
	bls _0809A2A6\n\
	strb r5, [r4, #8]\n\
	subs r0, r1, #1\n\
	strh r0, [r2]\n\
	b _0809A2AA\n\
_0809A2A6:\n\
	adds r0, #1\n\
	strb r0, [r4, #8]\n\
_0809A2AA:\n\
	ldr r0, _0809A2C0 @ =0x04000016\n\
	ldrh r1, [r6, #0x14]\n\
	adds r1, #3\n\
	strh r1, [r6, #0x14]\n\
	ldr r6, _0809A2C4 @ =0x0000FFFF\n\
	adds r2, r6, #0\n\
_0809A2B6:\n\
	ands r1, r2\n\
	strh r1, [r0]\n\
_0809A2BA:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809A2C0: .4byte 0x04000016\n\
_0809A2C4: .4byte 0x0000FFFF\n\
    .syntax divided\n");
}

// 0x0809A2C8
NAKED_FUNCTION
void CutsceneElevatorMonologueVblank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r1, _0809A2FC @ =0x040000D4\n\
	ldr r0, _0809A300 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809A304 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	bl unk_9cc4c\n\
	ldr r2, _0809A308 @ =0x04000052\n\
	ldr r0, _0809A30C @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _0809A310 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _0809A314 @ =0x04000054\n\
	ldr r0, _0809A318 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809A2FC: .4byte 0x040000D4\n\
_0809A300: .4byte gOamData\n\
_0809A304: .4byte 0x84000100\n\
_0809A308: .4byte 0x04000052\n\
_0809A30C: .4byte gWrittenToBldalpha_Evb\n\
_0809A310: .4byte gWrittenToBldalpha_Eva\n\
_0809A314: .4byte 0x04000054\n\
_0809A318: .4byte gWrittenToBldy\n\
    .syntax divided\n");
}

// 0x0809A31C
NAKED_FUNCTION
void unk_9a31c(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl UpdateAudio\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}
