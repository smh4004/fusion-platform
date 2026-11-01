#include "globals.h"
#include "macros.h"

// 0x0809C938
NAKED_FUNCTION
void CutsceneMonologueProcessCursor(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r3, _0809C954 @ =gNonGameplayRam\n\
	ldr r0, [r3, #0xc]\n\
	ldrh r1, [r0]\n\
	movs r0, #0xff\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0809C958\n\
	movs r0, #0\n\
	strb r0, [r2, #4]\n\
	strb r0, [r2, #5]\n\
	b _0809C9F4\n\
	.align 2, 0\n\
_0809C954: .4byte gNonGameplayRam\n\
_0809C958:\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	beq _0809C9E0\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	beq _0809C9C2\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0809C9E0\n\
	ldrb r1, [r2, #9]\n\
	cmp r1, #0\n\
	bne _0809C9B4\n\
	ldr r0, _0809C990 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809C994\n\
	movs r1, #0\n\
	movs r0, #0x91\n\
	lsls r0, r0, #1\n\
	strh r0, [r2]\n\
	strb r1, [r2, #7]\n\
	strb r1, [r2, #6]\n\
	b _0809C9F4\n\
	.align 2, 0\n\
_0809C990: .4byte gChangedInput\n\
_0809C994:\n\
	ldr r0, _0809C9B0 @ =0x08663E74\n\
	str r0, [r2, #0x10]\n\
	movs r1, #0\n\
	movs r0, #0x76\n\
	strh r0, [r2]\n\
	ldrh r0, [r3, #2]\n\
	lsls r0, r0, #3\n\
	adds r0, #0x18\n\
	strh r0, [r2, #2]\n\
	strb r1, [r2, #7]\n\
	strb r1, [r2, #6]\n\
	movs r0, #1\n\
	strb r0, [r2, #9]\n\
	b _0809C9F4\n\
	.align 2, 0\n\
_0809C9B0: .4byte 0x08663E74\n\
_0809C9B4:\n\
	cmp r1, #1\n\
	bne _0809C9F4\n\
	ldr r0, _0809C9D8 @ =gChangedInput\n\
	ldrh r0, [r0]\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0809C9F4\n\
_0809C9C2:\n\
	ldr r0, _0809C9DC @ =0x08663E5C\n\
	str r0, [r2, #0x10]\n\
	movs r1, #0\n\
	movs r0, #0x91\n\
	lsls r0, r0, #1\n\
	strh r0, [r2]\n\
	strb r1, [r2, #7]\n\
	strb r1, [r2, #6]\n\
	strb r1, [r2, #9]\n\
	b _0809C9F4\n\
	.align 2, 0\n\
_0809C9D8: .4byte gChangedInput\n\
_0809C9DC: .4byte 0x08663E5C\n\
_0809C9E0:\n\
	ldrh r0, [r3]\n\
	lsls r0, r0, #3\n\
	ldrb r1, [r3, #0x18]\n\
	adds r1, #0xc\n\
	adds r0, r0, r1\n\
	strh r0, [r2]\n\
	ldrh r0, [r3, #2]\n\
	lsls r0, r0, #3\n\
	adds r0, #0xc\n\
	strh r0, [r2, #2]\n\
_0809C9F4:\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0809C9F8
NAKED_FUNCTION
void CutsceneMonologueProcessSpecialTextCharacters(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r6, #0\n\
	ldr r0, _0809CA10 @ =gButtonInput\n\
	ldrh r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0809CA18\n\
	ldr r1, _0809CA14 @ =gNonGameplayRam\n\
	ldrh r0, [r1, #0x10]\n\
	adds r0, #2\n\
	b _0809CA1E\n\
	.align 2, 0\n\
_0809CA10: .4byte gButtonInput\n\
_0809CA14: .4byte gNonGameplayRam\n\
_0809CA18:\n\
	ldr r1, _0809CA40 @ =gNonGameplayRam\n\
	ldrh r0, [r1, #0x10]\n\
	adds r0, #1\n\
_0809CA1E:\n\
	strh r0, [r1, #0x10]\n\
	adds r5, r1, #0\n\
	adds r3, r5, #0\n\
	ldr r0, [r3, #0xc]\n\
	ldrh r2, [r0]\n\
	adds r1, r2, #0\n\
	movs r4, #0xff\n\
	lsls r4, r4, #8\n\
	cmp r1, r4\n\
	bne _0809CA44\n\
	movs r0, #0\n\
	strh r0, [r3, #0x10]\n\
	movs r0, #0x64\n\
	strb r0, [r3, #0x17]\n\
	movs r6, #1\n\
	b _0809CA92\n\
	.align 2, 0\n\
_0809CA40: .4byte gNonGameplayRam\n\
_0809CA44:\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0809CA64\n\
	ldr r0, _0809CA60 @ =gChangedInput\n\
	ldrh r0, [r0]\n\
	movs r1, #1\n\
	ands r1, r0\n\
	cmp r1, #0\n\
	beq _0809CA80\n\
	movs r1, #0\n\
	movs r0, #1\n\
	b _0809CA7E\n\
	.align 2, 0\n\
_0809CA60: .4byte gChangedInput\n\
_0809CA64:\n\
	adds r0, r4, #0\n\
	ands r0, r2\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	bne _0809CA84\n\
	movs r0, #0xff\n\
	ands r0, r2\n\
	ldrh r1, [r3, #0x10]\n\
	cmp r0, r1\n\
	bhi _0809CA92\n\
	movs r1, #0\n\
	movs r0, #1\n\
_0809CA7E:\n\
	strb r0, [r3, #0x17]\n\
_0809CA80:\n\
	strh r1, [r3, #0x10]\n\
	b _0809CA92\n\
_0809CA84:\n\
	ldrh r0, [r5, #0x10]\n\
	cmp r0, #2\n\
	bls _0809CA92\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r5, #0x17]\n\
	strh r1, [r5, #0x10]\n\
_0809CA92:\n\
	adds r0, r6, #0\n\
	pop {r4, r5, r6}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0809CA9C
NAKED_FUNCTION
void CutsceneMonologueProcessText(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	ldr r5, _0809CB04 @ =gNonGameplayRam\n\
	ldr r2, [r5, #0xc]\n\
	ldrh r3, [r2]\n\
	adds r1, r3, #0\n\
	movs r6, #0xff\n\
	lsls r6, r6, #8\n\
	adds r4, r5, #0\n\
	cmp r1, r6\n\
	bne _0809CAB4\n\
	b _0809CC3A\n\
_0809CAB4:\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0809CB08\n\
	ldrh r0, [r4]\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r2, #0x1b\n\
	bhi _0809CAEC\n\
	adds r6, r4, #0\n\
	adds r5, #0x1c\n\
	movs r3, #0xff\n\
_0809CACE:\n\
	ldrh r1, [r6, #2]\n\
	lsrs r1, r1, #1\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r2, r0\n\
	adds r0, r0, r5\n\
	ldrb r1, [r0]\n\
	orrs r1, r3\n\
	strb r1, [r0]\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r2, #0x1b\n\
	bls _0809CACE\n\
_0809CAEC:\n\
	movs r1, #0\n\
	movs r0, #0\n\
	strh r0, [r4]\n\
	ldrh r0, [r4, #2]\n\
	adds r0, #2\n\
	strh r0, [r4, #2]\n\
	ldr r0, [r4, #0xc]\n\
	adds r0, #2\n\
	str r0, [r4, #0xc]\n\
	strb r1, [r4, #0x18]\n\
	b _0809CC3A\n\
	.align 2, 0\n\
_0809CB04: .4byte gNonGameplayRam\n\
_0809CB08:\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0809CB84\n\
	movs r2, #0\n\
	str r2, [sp, #4]\n\
	ldr r1, _0809CB6C @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _0809CB70 @ =0x06008000\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809CB74 @ =0x85001200\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r3, #0\n\
	strh r2, [r4, #6]\n\
	strh r2, [r4, #4]\n\
	strh r2, [r4, #2]\n\
	strh r2, [r4]\n\
	ldr r0, [r4, #0xc]\n\
	adds r0, #2\n\
	str r0, [r4, #0xc]\n\
	strb r3, [r4, #0x18]\n\
	str r2, [sp, #4]\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x1c\n\
	str r0, [r1, #4]\n\
	ldr r3, _0809CB78 @ =0x8500003F\n\
	str r3, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	str r2, [sp, #4]\n\
	add r2, sp, #4\n\
	str r2, [r1]\n\
	movs r2, #0x8c\n\
	lsls r2, r2, #1\n\
	adds r0, r4, r2\n\
	str r0, [r1, #4]\n\
	str r3, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x12\n\
	str r0, [r1]\n\
	ldr r0, _0809CB7C @ =0x0600C800\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809CB80 @ =0x84000200\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	b _0809CC3A\n\
	.align 2, 0\n\
_0809CB6C: .4byte 0x040000D4\n\
_0809CB70: .4byte 0x06008000\n\
_0809CB74: .4byte 0x85001200\n\
_0809CB78: .4byte 0x8500003F\n\
_0809CB7C: .4byte 0x0600C800\n\
_0809CB80: .4byte 0x84000200\n\
_0809CB84:\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	beq _0809CB98\n\
	adds r0, r6, #0\n\
	ands r0, r3\n\
	movs r1, #0xe1\n\
	lsls r1, r1, #8\n\
	cmp r0, r1\n\
	bne _0809CB9E\n\
_0809CB98:\n\
	adds r0, r2, #2\n\
	str r0, [r4, #0xc]\n\
	b _0809CC3A\n\
_0809CB9E:\n\
	ldrh r4, [r5]\n\
	lsls r4, r4, #5\n\
	ldrh r0, [r5, #2]\n\
	lsls r0, r0, #0xa\n\
	adds r4, r4, r0\n\
	ldr r0, _0809CC44 @ =0x06008000\n\
	adds r4, r4, r0\n\
	ldrh r0, [r2]\n\
	bl TextGetCharacterWidth\n\
	adds r6, r0, #0\n\
	ldr r0, [r5, #0xc]\n\
	ldrh r0, [r0]\n\
	lsls r2, r6, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ldrb r3, [r5, #0x18]\n\
	movs r1, #0\n\
	str r1, [sp]\n\
	adds r1, r4, #0\n\
	bl TextDrawCharacter\n\
	ldrh r0, [r5]\n\
	cmp r0, #0x1b\n\
	bhi _0809CC32\n\
	ldrh r1, [r5, #2]\n\
	lsrs r1, r1, #1\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldrh r1, [r5]\n\
	adds r0, r0, r1\n\
	adds r1, r5, #0\n\
	adds r1, #0x1c\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	strb r1, [r0]\n\
	ldrb r0, [r5, #0x18]\n\
	adds r0, r0, r6\n\
	strb r0, [r5, #0x18]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r4, r5, #0\n\
	cmp r0, #7\n\
	bls _0809CC32\n\
	adds r2, r4, #0\n\
_0809CBF8:\n\
	ldrb r0, [r2, #0x18]\n\
	adds r1, r0, #0\n\
	subs r1, #8\n\
	strb r1, [r2, #0x18]\n\
	ldrh r0, [r2]\n\
	adds r0, #1\n\
	strh r0, [r2]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x1b\n\
	bhi _0809CC32\n\
	lsls r0, r1, #0x18\n\
	cmp r0, #0\n\
	beq _0809CC2C\n\
	ldrh r1, [r2, #2]\n\
	lsrs r1, r1, #1\n\
	lsls r0, r1, #3\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldrh r1, [r2]\n\
	adds r0, r0, r1\n\
	adds r1, r2, #0\n\
	adds r1, #0x1c\n\
	adds r0, r0, r1\n\
	movs r1, #4\n\
	strb r1, [r0]\n\
_0809CC2C:\n\
	ldrb r0, [r2, #0x18]\n\
	cmp r0, #7\n\
	bhi _0809CBF8\n\
_0809CC32:\n\
	ldr r1, _0809CC48 @ =gNonGameplayRam\n\
	ldr r0, [r1, #0xc]\n\
	adds r0, #2\n\
	str r0, [r1, #0xc]\n\
_0809CC3A:\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809CC44: .4byte 0x06008000\n\
_0809CC48: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809CC4C
NAKED_FUNCTION
void unk_9cc4c(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x10\n\
	ldr r1, _0809CC8C @ =gNonGameplayRam\n\
	ldrh r6, [r1, #4]\n\
	ldrh r0, [r1, #6]\n\
	lsrs r7, r0, #1\n\
	ldrh r0, [r1, #2]\n\
	lsrs r0, r0, #1\n\
	str r1, [sp, #4]\n\
	cmp r7, r0\n\
	bls _0809CC6C\n\
	b _0809CD70\n\
_0809CC6C:\n\
	str r1, [sp]\n\
_0809CC6E:\n\
	ldr r2, [sp]\n\
	ldr r0, [r2, #0xc]\n\
	ldrh r0, [r0]\n\
	movs r3, #0xfc\n\
	lsls r3, r3, #8\n\
	cmp r0, r3\n\
	bne _0809CC90\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x1b\n\
	bhi _0809CCAA\n\
	adds r0, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	mov ip, r0\n\
	b _0809CCAE\n\
	.align 2, 0\n\
_0809CC8C: .4byte gNonGameplayRam\n\
_0809CC90:\n\
	ldrh r0, [r1, #2]\n\
	lsrs r0, r0, #1\n\
	cmp r7, r0\n\
	bne _0809CCAA\n\
	ldr r1, [sp]\n\
	ldrh r0, [r1]\n\
	movs r2, #0x1c\n\
	mov ip, r2\n\
	cmp r0, #0x1b\n\
	bhi _0809CCAE\n\
	adds r3, r0, #0\n\
	mov ip, r3\n\
	b _0809CCAE\n\
_0809CCAA:\n\
	movs r5, #0x1c\n\
	mov ip, r5\n\
_0809CCAE:\n\
	adds r0, r7, #1\n\
	str r0, [sp, #8]\n\
	cmp r6, ip\n\
	bhs _0809CD5C\n\
	ldr r1, _0809CD24 @ =gNonGameplayRam\n\
	mov r8, r1\n\
	lsls r0, r7, #3\n\
	subs r0, r0, r7\n\
	lsls r0, r0, #2\n\
	mov sl, r0\n\
	ldr r2, _0809CD28 @ =0x00000FFF\n\
	mov sb, r2\n\
_0809CCC6:\n\
	mov r3, sl\n\
	adds r2, r6, r3\n\
	ldr r5, _0809CD2C @ =0x0300159C\n\
	adds r1, r2, r5\n\
	ldrb r0, [r1]\n\
	cmp r0, #5\n\
	bne _0809CD4E\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r0, [sp, #4]\n\
	adds r0, #0x1c\n\
	adds r2, r2, r0\n\
	ldrb r0, [r2]\n\
	subs r1, r0, #1\n\
	strb r1, [r2]\n\
	lsls r0, r1, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	ble _0809CD38\n\
	lsls r2, r6, #1\n\
	lsls r0, r7, #7\n\
	adds r2, r2, r0\n\
	ldr r0, _0809CD30 @ =0x0600C842\n\
	adds r0, r2, r0\n\
	str r0, [sp, #0xc]\n\
	ldr r1, _0809CD34 @ =0x0600C882\n\
	adds r2, r2, r1\n\
	ldrh r3, [r0]\n\
	ldrh r4, [r2]\n\
	lsrs r0, r3, #0xc\n\
	lsrs r1, r4, #0xc\n\
	subs r0, #1\n\
	lsls r0, r0, #0x10\n\
	subs r1, #1\n\
	lsls r1, r1, #0x10\n\
	lsrs r0, r0, #4\n\
	mov r5, sb\n\
	ands r3, r5\n\
	orrs r0, r3\n\
	ldr r3, [sp, #0xc]\n\
	strh r0, [r3]\n\
	lsrs r1, r1, #4\n\
	ands r4, r5\n\
	orrs r1, r4\n\
	strh r1, [r2]\n\
	b _0809CD52\n\
	.align 2, 0\n\
_0809CD24: .4byte gNonGameplayRam\n\
_0809CD28: .4byte 0x00000FFF\n\
_0809CD2C: .4byte 0x0300159C\n\
_0809CD30: .4byte 0x0600C842\n\
_0809CD34: .4byte 0x0600C882\n\
_0809CD38:\n\
	cmp r0, #0\n\
	bne _0809CD46\n\
	lsls r0, r7, #1\n\
	mov r5, r8\n\
	strh r0, [r5, #6]\n\
	strh r6, [r5, #4]\n\
	b _0809CD52\n\
_0809CD46:\n\
	movs r0, #0xff\n\
	orrs r1, r0\n\
	strb r1, [r2]\n\
	b _0809CD5C\n\
_0809CD4E:\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
_0809CD52:\n\
	adds r0, r6, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r6, r0, #0x10\n\
	cmp r6, ip\n\
	blo _0809CCC6\n\
_0809CD5C:\n\
	movs r6, #0\n\
	ldr r1, [sp, #8]\n\
	lsls r0, r1, #0x10\n\
	lsrs r7, r0, #0x10\n\
	ldr r1, [sp, #4]\n\
	ldrh r0, [r1, #2]\n\
	lsrs r0, r0, #1\n\
	cmp r7, r0\n\
	bhi _0809CD70\n\
	b _0809CC6E\n\
_0809CD70:\n\
	add sp, #0x10\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0809CD80
NAKED_FUNCTION
void CutsceneMonologueFadeIn(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl CutsceneMonologueProcessOam\n\
	bl CutsceneMonologueDrawAllOam\n\
	ldr r3, _0809CDAC @ =gWrittenToBldy\n\
	ldrh r2, [r3]\n\
	adds r0, r2, #0\n\
	cmp r0, #0\n\
	beq _0809CDD0\n\
	cmp r0, #0xb\n\
	bls _0809CDB4\n\
	ldr r1, _0809CDB0 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x16]\n\
	adds r0, #1\n\
	strb r0, [r1, #0x16]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bne _0809CDD0\n\
	b _0809CDC8\n\
	.align 2, 0\n\
_0809CDAC: .4byte gWrittenToBldy\n\
_0809CDB0: .4byte gNonGameplayRam\n\
_0809CDB4:\n\
	cmp r0, #6\n\
	bls _0809CDCC\n\
	ldr r1, _0809CDD4 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x16]\n\
	adds r0, #1\n\
	strb r0, [r1, #0x16]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _0809CDD0\n\
_0809CDC8:\n\
	movs r0, #0\n\
	strb r0, [r1, #0x16]\n\
_0809CDCC:\n\
	subs r0, r2, #1\n\
	strh r0, [r3]\n\
_0809CDD0:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809CDD4: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809CDD8
NAKED_FUNCTION
void CutsceneMonologueFadeOut(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	bl CutsceneMonologueProcessOam\n\
	bl CutsceneMonologueDrawAllOam\n\
	ldr r3, _0809CE04 @ =gWrittenToBldy\n\
	ldrh r2, [r3]\n\
	adds r0, r2, #0\n\
	cmp r0, #0xf\n\
	bhi _0809CE28\n\
	cmp r0, #5\n\
	bhi _0809CE0C\n\
	ldr r1, _0809CE08 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x16]\n\
	adds r0, #1\n\
	strb r0, [r1, #0x16]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bne _0809CE28\n\
	b _0809CE20\n\
	.align 2, 0\n\
_0809CE04: .4byte gWrittenToBldy\n\
_0809CE08: .4byte gNonGameplayRam\n\
_0809CE0C:\n\
	cmp r0, #0xa\n\
	bhi _0809CE24\n\
	ldr r1, _0809CE2C @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0x16]\n\
	adds r0, #1\n\
	strb r0, [r1, #0x16]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _0809CE28\n\
_0809CE20:\n\
	movs r0, #0\n\
	strb r0, [r1, #0x16]\n\
_0809CE24:\n\
	adds r0, r2, #1\n\
	strh r0, [r3]\n\
_0809CE28:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809CE2C: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809CE30
NAKED_FUNCTION
void CutsceneMonologueProcessOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r4, #0\n\
	ldr r5, _0809CE70 @ =gNonGameplayRam\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r6, r5, r0\n\
_0809CE3C:\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r4\n\
	lsls r2, r0, #3\n\
	adds r0, r2, r5\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0809CE60\n\
	movs r0, #0x8a\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	adds r1, r2, r1\n\
	adds r0, r2, r6\n\
	ldr r1, [r1]\n\
	bl _call_via_r1\n\
_0809CE60:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #4\n\
	bls _0809CE3C\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809CE70: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0809CE74
NAKED_FUNCTION
void CutsceneMonologueDrawAllOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	movs r4, #0\n\
	ldr r5, _0809CEB4 @ =gNonGameplayRam\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r6, r5, r0\n\
_0809CE80:\n\
	lsls r0, r4, #1\n\
	adds r0, r0, r4\n\
	lsls r1, r0, #3\n\
	adds r0, r1, r5\n\
	ldr r2, _0809CEB8 @ =0x00000219\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0809CE98\n\
	adds r0, r1, r6\n\
	bl CutsceneMnologueDrawOam\n\
_0809CE98:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	cmp r4, #4\n\
	bls _0809CE80\n\
	bl ResetFreeOam\n\
	ldr r1, _0809CEBC @ =gNextOamSlot\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809CEB4: .4byte gNonGameplayRam\n\
_0809CEB8: .4byte 0x00000219\n\
_0809CEBC: .4byte gNextOamSlot\n\
    .syntax divided\n");
}

// 0x0809CEC0
NAKED_FUNCTION
void CutsceneMnologueDrawOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	adds r5, r0, #0\n\
	ldr r2, _0809CF80 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #3\n\
	ldr r1, _0809CF84 @ =gOamData\n\
	adds r7, r0, r1\n\
	ldrb r4, [r5, #6]\n\
	lsls r1, r4, #3\n\
	ldr r0, [r5, #0x10]\n\
	adds r3, r0, r1\n\
	ldrb r0, [r3, #4]\n\
	ldrb r2, [r5, #7]\n\
	cmp r0, r2\n\
	bne _0809CEF0\n\
	adds r0, r4, #1\n\
	movs r1, #0\n\
	strb r0, [r5, #6]\n\
	strb r1, [r5, #7]\n\
	adds r3, #8\n\
_0809CEF0:\n\
	ldrb r1, [r3, #4]\n\
	cmp r1, #0\n\
	bne _0809CEFE\n\
	ldrb r0, [r5, #6]\n\
	lsls r0, r0, #3\n\
	subs r3, r3, r0\n\
	strb r1, [r5, #6]\n\
_0809CEFE:\n\
	ldr r6, [r3]\n\
	ldrh r3, [r6]\n\
	mov sl, r3\n\
	adds r6, #2\n\
	movs r4, #0\n\
	mov sb, r4\n\
	cmp sb, sl\n\
	blt _0809CF10\n\
	b _0809D014\n\
_0809CF10:\n\
	ldrh r0, [r6]\n\
	mov r8, r0\n\
	adds r6, #2\n\
	ldrh r1, [r6]\n\
	mov ip, r1\n\
	adds r6, #2\n\
	strh r0, [r7]\n\
	adds r7, #2\n\
	strh r1, [r7]\n\
	adds r7, #2\n\
	ldrh r0, [r6]\n\
	strh r0, [r7]\n\
	adds r6, #2\n\
	adds r7, #2\n\
	ldr r2, _0809CF80 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	mov r4, sb\n\
	adds r3, r0, r4\n\
	ldrb r1, [r5, #0xc]\n\
	cmp r1, #1\n\
	bne _0809CF90\n\
	lsls r4, r3, #3\n\
	ldr r0, _0809CF84 @ =gOamData\n\
	adds r2, r4, r0\n\
	ldrb r3, [r2, #3]\n\
	lsls r0, r3, #0x1b\n\
	lsrs r0, r0, #0x1f\n\
	eors r0, r1\n\
	movs r1, #1\n\
	ands r0, r1\n\
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
	ldr r2, _0809CF88 @ =0x0868279C\n\
	adds r1, r1, r2\n\
	ldrb r0, [r1]\n\
	lsls r0, r0, #3\n\
	add r0, ip\n\
	ldrh r1, [r5]\n\
	subs r2, r1, r0\n\
	ldr r3, _0809CF8C @ =0x000001FF\n\
	ands r2, r3\n\
	ldrh r0, [r5, #2]\n\
	mov r3, r8\n\
	adds r1, r3, r0\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	b _0809CFA6\n\
	.align 2, 0\n\
_0809CF80: .4byte gNextOamSlot\n\
_0809CF84: .4byte gOamData\n\
_0809CF88: .4byte 0x0868279C\n\
_0809CF8C: .4byte 0x000001FF\n\
_0809CF90:\n\
	ldrh r0, [r5, #2]\n\
	mov r4, r8\n\
	adds r1, r4, r0\n\
	movs r0, #0xff\n\
	ands r1, r0\n\
	ldrh r0, [r5]\n\
	mov r4, ip\n\
	adds r2, r4, r0\n\
	ldr r0, _0809D030 @ =0x000001FF\n\
	ands r2, r0\n\
	lsls r4, r3, #3\n\
_0809CFA6:\n\
	ldr r0, _0809D034 @ =gOamData\n\
	adds r3, r4, r0\n\
	strb r1, [r3]\n\
	ldr r1, _0809D030 @ =0x000001FF\n\
	ands r2, r1\n\
	ldrh r1, [r3, #2]\n\
	ldr r0, _0809D038 @ =0xFFFFFE00\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strh r0, [r3, #2]\n\
	ldrb r1, [r5, #0xb]\n\
	movs r2, #3\n\
	ands r1, r2\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r3, #5]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, #5]\n\
	lsrs r2, r0, #4\n\
	ldrb r4, [r5, #0xd]\n\
	adds r2, r2, r4\n\
	lsls r2, r2, #4\n\
	movs r1, #0xf\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3, #5]\n\
	ldrh r2, [r3, #4]\n\
	lsls r1, r2, #0x16\n\
	lsrs r1, r1, #0x16\n\
	ldrh r0, [r5, #0xe]\n\
	adds r1, r1, r0\n\
	ldr r4, _0809D03C @ =0x000003FF\n\
	adds r0, r4, #0\n\
	ands r1, r0\n\
	ldr r0, _0809D040 @ =0xFFFFFC00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r3, #4]\n\
	ldrb r1, [r5, #0xa]\n\
	movs r0, #3\n\
	ands r1, r0\n\
	lsls r1, r1, #2\n\
	ldrb r2, [r3, #1]\n\
	subs r0, #0x10\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, #1]\n\
	adds r7, #2\n\
	movs r1, #1\n\
	add sb, r1\n\
	cmp sb, sl\n\
	bge _0809D014\n\
	b _0809CF10\n\
_0809D014:\n\
	ldr r2, _0809D044 @ =gNextOamSlot\n\
	ldrb r0, [r2]\n\
	add r0, sl\n\
	strb r0, [r2]\n\
	ldrb r0, [r5, #7]\n\
	adds r0, #1\n\
	strb r0, [r5, #7]\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809D030: .4byte 0x000001FF\n\
_0809D034: .4byte gOamData\n\
_0809D038: .4byte 0xFFFFFE00\n\
_0809D03C: .4byte 0x000003FF\n\
_0809D040: .4byte 0xFFFFFC00\n\
_0809D044: .4byte gNextOamSlot\n\
    .syntax divided\n");
}

// 0x0809D048
NAKED_FUNCTION
void CutsceneMonologueResetOam(void)
{
    asm(" .syntax unified\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldr r2, _0809D08C @ =gNonGameplayRam\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r2\n\
	ldr r2, _0809D090 @ =0x0000021A\n\
	adds r0, r1, r2\n\
	movs r2, #0\n\
	strb r2, [r0]\n\
	ldr r3, _0809D094 @ =0x0000021B\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	adds r3, #2\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	adds r3, #1\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	adds r3, #1\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	adds r3, #1\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	adds r3, #1\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	ldr r0, _0809D098 @ =0x00000222\n\
	adds r1, r1, r0\n\
	strh r2, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_0809D08C: .4byte gNonGameplayRam\n\
_0809D090: .4byte 0x0000021A\n\
_0809D094: .4byte 0x0000021B\n\
_0809D098: .4byte 0x00000222\n\
    .syntax divided\n");
}

// 0x0809D09C
NAKED_FUNCTION
void unk_9d09c(void)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}
