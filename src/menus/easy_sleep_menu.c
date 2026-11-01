#include "globals.h"
#include "macros.h"

// 0x0807ED20
NAKED_FUNCTION
void EasySleepMenuHandler(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	movs r7, #0\n\
	ldr r0, _0807ED40 @ =gNonGameplayRam\n\
	ldrb r1, [r0, #7]\n\
	adds r3, r0, #0\n\
	cmp r1, #5\n\
	bls _0807ED36\n\
	b _0807EE82\n\
_0807ED36:\n\
	lsls r0, r1, #2\n\
	ldr r1, _0807ED44 @ =_0807ED48\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0807ED40: .4byte gNonGameplayRam\n\
_0807ED44: .4byte _0807ED48\n\
_0807ED48: @ jump table\n\
	.4byte _0807ED60 @ case 0\n\
	.4byte _0807ED90 @ case 1\n\
	.4byte _0807EDE4 @ case 2\n\
	.4byte _0807EDFE @ case 3\n\
	.4byte _0807EE12 @ case 4\n\
	.4byte _0807EE78 @ case 5\n\
_0807ED60:\n\
	ldr r0, _0807ED78 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807ED80\n\
	ldr r0, _0807ED7C @ =0x000001FB\n\
	bl SoundPlay\n\
	movs r7, #1\n\
	b _0807EE86\n\
	.align 2, 0\n\
_0807ED78: .4byte gChangedInput\n\
_0807ED7C: .4byte 0x000001FB\n\
_0807ED80:\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807EDD4\n\
	movs r0, #1\n\
	strb r0, [r3, #7]\n\
	movs r0, #0x3c\n\
	b _0807EDC8\n\
_0807ED90:\n\
	ldr r0, _0807EDB0 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r2, #1\n\
	ands r2, r1\n\
	cmp r2, #0\n\
	beq _0807EDBC\n\
	ldr r0, _0807EDB4 @ =0x000001FB\n\
	bl SoundPlay\n\
	ldr r1, _0807EDB8 @ =gNonGameplayRam\n\
	movs r2, #0\n\
	movs r0, #2\n\
	strb r0, [r1, #7]\n\
	strb r2, [r1, #6]\n\
	b _0807EE82\n\
	.align 2, 0\n\
_0807EDB0: .4byte gChangedInput\n\
_0807EDB4: .4byte 0x000001FB\n\
_0807EDB8: .4byte gNonGameplayRam\n\
_0807EDBC:\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807EDD4\n\
	strb r2, [r3, #7]\n\
	movs r0, #0x8c\n\
_0807EDC8:\n\
	strh r0, [r3, #0x3a]\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	b _0807EE82\n\
_0807EDD4:\n\
	ldr r0, _0807EDE0 @ =0x00000302\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807EE82\n\
	movs r7, #1\n\
	b _0807EE86\n\
	.align 2, 0\n\
_0807EDE0: .4byte 0x00000302\n\
_0807EDE4:\n\
	ldrb r0, [r3, #6]\n\
	adds r0, #1\n\
	strb r0, [r3, #6]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x1e\n\
	bls _0807EE82\n\
	ldrb r0, [r3, #7]\n\
	adds r0, #1\n\
	strb r0, [r3, #7]\n\
	movs r0, #0\n\
	strb r0, [r3, #6]\n\
	b _0807EE82\n\
_0807EDFE:\n\
	movs r0, #0x9a\n\
	lsls r0, r0, #2\n\
	adds r2, r3, r0\n\
	ldrh r0, [r2]\n\
	movs r1, #0x80\n\
	eors r0, r1\n\
	strh r0, [r2]\n\
	ldrb r0, [r3, #7]\n\
	adds r0, #1\n\
	b _0807EE80\n\
_0807EE12:\n\
	ldr r1, _0807EE64 @ =0x04000132\n\
	ldr r2, _0807EE68 @ =0x0000C304\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r6, _0807EE6C @ =0x04000208\n\
	movs r0, #0\n\
	mov sb, r0\n\
	strh r0, [r6]\n\
	ldr r5, _0807EE70 @ =0x04000200\n\
	ldrh r4, [r5]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #6\n\
	adds r0, r1, #0\n\
	strh r0, [r5]\n\
	movs r2, #1\n\
	mov r8, r2\n\
	strh r2, [r6]\n\
	bl SoundBias0\n\
	svc #3\n\
	bl SoundBias1\n\
	mov r0, sb\n\
	strh r0, [r6]\n\
	strh r4, [r5]\n\
	mov r1, r8\n\
	strh r1, [r6]\n\
	ldr r2, _0807EE74 @ =gNonGameplayRam\n\
	movs r0, #0x9a\n\
	lsls r0, r0, #2\n\
	adds r3, r2, r0\n\
	ldrh r0, [r3]\n\
	movs r1, #0x80\n\
	eors r0, r1\n\
	strh r0, [r3]\n\
	movs r0, #0x8c\n\
	strh r0, [r2, #0x3a]\n\
	ldrb r0, [r2, #7]\n\
	adds r0, #1\n\
	strb r0, [r2, #7]\n\
	b _0807EE82\n\
	.align 2, 0\n\
_0807EE64: .4byte 0x04000132\n\
_0807EE68: .4byte 0x0000C304\n\
_0807EE6C: .4byte 0x04000208\n\
_0807EE70: .4byte 0x04000200\n\
_0807EE74: .4byte gNonGameplayRam\n\
_0807EE78:\n\
	ldr r0, _0807EE9C @ =gButtonInput\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _0807EE82\n\
_0807EE80:\n\
	strb r0, [r3, #7]\n\
_0807EE82:\n\
	cmp r7, #0\n\
	beq _0807EE8E\n\
_0807EE86:\n\
	ldr r1, _0807EEA0 @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strb r0, [r1, #7]\n\
	strb r0, [r1, #6]\n\
_0807EE8E:\n\
	adds r0, r7, #0\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0807EE9C: .4byte gButtonInput\n\
_0807EEA0: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}
