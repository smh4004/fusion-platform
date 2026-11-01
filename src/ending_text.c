#include "globals.h"
#include "macros.h"

// 0x080A1480
NAKED_FUNCTION
void EndingDrawIgtAndCompletionPercentage(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	movs r1, #0\n\
	ldr r0, _080A1548 @ =gInGameTimer\n\
	ldrb r4, [r0]\n\
	ldr r7, _080A154C @ =0x0874E650\n\
	ldr r2, _080A1550 @ =0x0874E8D0\n\
	mov ip, r2\n\
	ldr r5, _080A1554 @ =gNonGameplayRam\n\
	mov r8, r5\n\
	cmp r4, #9\n\
	ble _080A14A4\n\
_080A149C:\n\
	subs r4, #0xa\n\
	adds r1, #1\n\
	cmp r4, #9\n\
	bgt _080A149C\n\
_080A14A4:\n\
	movs r6, #0\n\
	ldrb r5, [r0, #1]\n\
	lsls r4, r4, #6\n\
	mov sb, r4\n\
	cmp r5, #9\n\
	ble _080A14B8\n\
_080A14B0:\n\
	subs r5, #0xa\n\
	adds r6, #1\n\
	cmp r5, #9\n\
	bgt _080A14B0\n\
_080A14B8:\n\
	cmp r1, #0\n\
	beq _080A14DC\n\
	lsls r3, r1, #6\n\
	ldr r0, _080A1558 @ =0x040000D4\n\
	adds r1, r3, r7\n\
	str r1, [r0]\n\
	ldr r1, _080A155C @ =0x06010000\n\
	str r1, [r0, #4]\n\
	ldr r2, _080A1560 @ =0x80000020\n\
	str r2, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	mov r4, ip\n\
	adds r1, r3, r4\n\
	str r1, [r0]\n\
	ldr r1, _080A1564 @ =0x06010400\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
_080A14DC:\n\
	mov r3, sb\n\
	ldr r0, _080A1558 @ =0x040000D4\n\
	adds r1, r3, r7\n\
	str r1, [r0]\n\
	ldr r1, _080A1568 @ =0x06010040\n\
	str r1, [r0, #4]\n\
	ldr r2, _080A1560 @ =0x80000020\n\
	str r2, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	mov r4, ip\n\
	adds r1, r3, r4\n\
	str r1, [r0]\n\
	ldr r1, _080A156C @ =0x06010440\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	lsls r3, r6, #6\n\
	adds r1, r3, r7\n\
	str r1, [r0]\n\
	ldr r1, _080A1570 @ =0x060100A0\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	adds r1, r3, r4\n\
	str r1, [r0]\n\
	ldr r1, _080A1574 @ =0x060104A0\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	lsls r3, r5, #6\n\
	adds r1, r3, r7\n\
	str r1, [r0]\n\
	ldr r1, _080A1578 @ =0x060100E0\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	adds r1, r3, r4\n\
	str r1, [r0]\n\
	ldr r1, _080A157C @ =0x060104E0\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
	movs r1, #0\n\
	movs r4, #0\n\
	mov r0, r8\n\
	adds r0, #0x9a\n\
	ldrb r6, [r0]\n\
	cmp r6, #0x63\n\
	ble _080A1584\n\
_080A153E:\n\
	subs r6, #0x64\n\
	adds r1, #1\n\
	cmp r6, #0x63\n\
	bgt _080A153E\n\
	b _080A1584\n\
	.align 2, 0\n\
_080A1548: .4byte gInGameTimer\n\
_080A154C: .4byte 0x0874E650\n\
_080A1550: .4byte 0x0874E8D0\n\
_080A1554: .4byte gNonGameplayRam\n\
_080A1558: .4byte 0x040000D4\n\
_080A155C: .4byte 0x06010000\n\
_080A1560: .4byte 0x80000020\n\
_080A1564: .4byte 0x06010400\n\
_080A1568: .4byte 0x06010040\n\
_080A156C: .4byte 0x06010440\n\
_080A1570: .4byte 0x060100A0\n\
_080A1574: .4byte 0x060104A0\n\
_080A1578: .4byte 0x060100E0\n\
_080A157C: .4byte 0x060104E0\n\
_080A1580:\n\
	subs r6, #0xa\n\
	adds r4, #1\n\
_080A1584:\n\
	cmp r6, #9\n\
	bgt _080A1580\n\
	cmp r1, #0\n\
	beq _080A15C0\n\
	lsls r3, r1, #6\n\
	ldr r0, _080A15B0 @ =0x040000D4\n\
	adds r1, r3, r7\n\
	str r1, [r0]\n\
	ldr r1, _080A15B4 @ =0x06010120\n\
	str r1, [r0, #4]\n\
	ldr r2, _080A15B8 @ =0x80000020\n\
	str r2, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	mov r5, ip\n\
	adds r1, r3, r5\n\
	str r1, [r0]\n\
	ldr r1, _080A15BC @ =0x06010520\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
	b _080A15C4\n\
	.align 2, 0\n\
_080A15B0: .4byte 0x040000D4\n\
_080A15B4: .4byte 0x06010120\n\
_080A15B8: .4byte 0x80000020\n\
_080A15BC: .4byte 0x06010520\n\
_080A15C0:\n\
	cmp r4, #0\n\
	beq _080A15E4\n\
_080A15C4:\n\
	lsls r3, r4, #6\n\
	ldr r0, _080A1610 @ =0x040000D4\n\
	adds r1, r3, r7\n\
	str r1, [r0]\n\
	ldr r1, _080A1614 @ =0x06010160\n\
	str r1, [r0, #4]\n\
	ldr r2, _080A1618 @ =0x80000020\n\
	str r2, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	mov r4, ip\n\
	adds r1, r3, r4\n\
	str r1, [r0]\n\
	ldr r1, _080A161C @ =0x06010560\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
_080A15E4:\n\
	lsls r3, r6, #6\n\
	ldr r0, _080A1610 @ =0x040000D4\n\
	adds r1, r3, r7\n\
	str r1, [r0]\n\
	ldr r1, _080A1620 @ =0x060101A0\n\
	str r1, [r0, #4]\n\
	ldr r2, _080A1618 @ =0x80000020\n\
	str r2, [r0, #8]\n\
	ldr r1, [r0, #8]\n\
	mov r5, ip\n\
	adds r1, r3, r5\n\
	str r1, [r0]\n\
	ldr r1, _080A1624 @ =0x060105A0\n\
	str r1, [r0, #4]\n\
	str r2, [r0, #8]\n\
	ldr r0, [r0, #8]\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A1610: .4byte 0x040000D4\n\
_080A1614: .4byte 0x06010160\n\
_080A1618: .4byte 0x80000020\n\
_080A161C: .4byte 0x06010560\n\
_080A1620: .4byte 0x060101A0\n\
_080A1624: .4byte 0x060105A0\n\
    .syntax divided\n");
}

// 0x080A1628
NAKED_FUNCTION
void EndingImageUpdateLettersSpawnDelay(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r3, r0, #0\n\
	ldr r1, _080A1660 @ =gNonGameplayRam\n\
	movs r2, #0x92\n\
	lsls r2, r2, #1\n\
	adds r0, r1, r2\n\
	adds r2, r3, r0\n\
	ldrb r0, [r2]\n\
	cmp r0, #0\n\
	beq _080A165A\n\
	movs r4, #0xa1\n\
	lsls r4, r4, #1\n\
	adds r0, r1, r4\n\
	adds r1, r3, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _080A165A\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080A165A\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
_080A165A:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A1660: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x080A1664
NAKED_FUNCTION
void EndingImageLoadTextOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r1, r0, #0\n\
	ldr r0, _080A1680 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #4\n\
	beq _080A175C\n\
	cmp r0, #4\n\
	bgt _080A1684\n\
	cmp r0, #3\n\
	beq _080A1692\n\
	b _080A1A28\n\
	.align 2, 0\n\
_080A1680: .4byte 0x03000011\n\
_080A1684:\n\
	cmp r0, #5\n\
	bne _080A168A\n\
	b _080A1828\n\
_080A168A:\n\
	cmp r0, #6\n\
	bne _080A1690\n\
	b _080A195C\n\
_080A1690:\n\
	b _080A1A28\n\
_080A1692:\n\
	cmp r1, #0\n\
	bne _080A16F8\n\
	ldr r1, _080A16F0 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x13\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A16F4 @ =0x0874DE94\n\
	movs r0, #0x95\n\
	lsls r0, r0, #1\n\
	adds r4, r5, r0\n\
	movs r1, #0xb3\n\
	lsls r1, r1, #1\n\
	adds r6, r5, r1\n\
	adds r0, #0x60\n\
	adds r0, r0, r5\n\
	mov ip, r0\n\
_080A16BA:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0xc\n\
	ble _080A16BA\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A16F0: .4byte gNonGameplayRam\n\
_080A16F4: .4byte 0x0874DE94\n\
_080A16F8:\n\
	ldr r1, _080A1754 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x14\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A1758 @ =0x0874DF30\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A171C:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0xd\n\
	ble _080A171C\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A1754: .4byte gNonGameplayRam\n\
_080A1758: .4byte 0x0874DF30\n\
_080A175C:\n\
	cmp r1, #0\n\
	bne _080A17C4\n\
	ldr r1, _080A17BC @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x16\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A17C0 @ =0x0874E020\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A1784:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0xf\n\
	ble _080A1784\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A17BC: .4byte gNonGameplayRam\n\
_080A17C0: .4byte 0x0874E020\n\
_080A17C4:\n\
	ldr r1, _080A1820 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x1a\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A1824 @ =0x0874E0E0\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A17E8:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0x13\n\
	ble _080A17E8\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A1820: .4byte gNonGameplayRam\n\
_080A1824: .4byte 0x0874E0E0\n\
_080A1828:\n\
	cmp r1, #0\n\
	bne _080A1890\n\
	ldr r1, _080A1888 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x18\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A188C @ =0x0874E218\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A1850:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0x11\n\
	ble _080A1850\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A1888: .4byte gNonGameplayRam\n\
_080A188C: .4byte 0x0874E218\n\
_080A1890:\n\
	cmp r1, #1\n\
	bne _080A18F8\n\
	ldr r1, _080A18F0 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x11\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A18F4 @ =0x0874E2F0\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A18B8:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0xa\n\
	ble _080A18B8\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A18F0: .4byte gNonGameplayRam\n\
_080A18F4: .4byte 0x0874E2F0\n\
_080A18F8:\n\
	ldr r1, _080A1954 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x17\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A1958 @ =0x0874E374\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A191C:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0x10\n\
	ble _080A191C\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A1954: .4byte gNonGameplayRam\n\
_080A1958: .4byte 0x0874E374\n\
_080A195C:\n\
	cmp r1, #0\n\
	bne _080A19C4\n\
	ldr r1, _080A19BC @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x15\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A19C0 @ =0x0874E488\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A1984:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0xe\n\
	ble _080A1984\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A19BC: .4byte gNonGameplayRam\n\
_080A19C0: .4byte 0x0874E488\n\
_080A19C4:\n\
	ldr r1, _080A1A20 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x19\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A1A24 @ =0x0874E53C\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A19E8:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0x12\n\
	ble _080A19E8\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A1A20: .4byte gNonGameplayRam\n\
_080A1A24: .4byte 0x0874E53C\n\
_080A1A28:\n\
	cmp r1, #0\n\
	bne _080A1A90\n\
	ldr r1, _080A1A88 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0xf\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A1A8C @ =0x0874DC90\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A1A50:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #8\n\
	ble _080A1A50\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A1A88: .4byte gNonGameplayRam\n\
_080A1A8C: .4byte 0x0874DC90\n\
_080A1A90:\n\
	cmp r1, #1\n\
	bne _080A1AF8\n\
	ldr r1, _080A1AF0 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x11\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A1AF4 @ =0x0874DCFC\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A1AB8:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0xa\n\
	ble _080A1AB8\n\
	b _080A1B50\n\
	.align 2, 0\n\
_080A1AF0: .4byte gNonGameplayRam\n\
_080A1AF4: .4byte 0x0874DCFC\n\
_080A1AF8:\n\
	ldr r1, _080A1B58 @ =gNonGameplayRam\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	movs r0, #0x17\n\
	strb r0, [r2]\n\
	movs r3, #0\n\
	adds r5, r1, #0\n\
	movs r7, #0x18\n\
	ldr r2, _080A1B5C @ =0x0874DD80\n\
	movs r1, #0x95\n\
	lsls r1, r1, #1\n\
	adds r4, r5, r1\n\
	movs r0, #0xb3\n\
	lsls r0, r0, #1\n\
	adds r6, r5, r0\n\
	adds r1, #0x60\n\
	adds r1, r1, r5\n\
	mov ip, r1\n\
_080A1B1C:\n\
	ldrb r0, [r2]\n\
	strb r0, [r4]\n\
	ldrb r0, [r2, #1]\n\
	strb r0, [r4, #0x1e]\n\
	ldrb r0, [r2, #2]\n\
	strb r0, [r6]\n\
	ldrh r0, [r2, #4]\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r1, #0x3c]\n\
	movs r1, #0xfc\n\
	lsls r1, r1, #1\n\
	adds r0, r5, r1\n\
	adds r0, r7, r0\n\
	ldr r1, [r2, #8]\n\
	str r1, [r0]\n\
	adds r7, #4\n\
	movs r0, #2\n\
	add ip, r0\n\
	adds r2, #0xc\n\
	adds r4, #1\n\
	adds r6, #1\n\
	adds r3, #1\n\
	cmp r3, #0x10\n\
	ble _080A1B1C\n\
_080A1B50:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A1B58: .4byte gNonGameplayRam\n\
_080A1B5C: .4byte 0x0874DD80\n\
    .syntax divided\n");
}

// 0x080A1B60
NAKED_FUNCTION
void EndingImageDisplayLinePermanently(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r6, r0, #0\n\
	ldr r0, _080A1B7C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #4\n\
	beq _080A1BA4\n\
	cmp r0, #4\n\
	bgt _080A1B80\n\
	cmp r0, #3\n\
	beq _080A1B8A\n\
	b _080A1BEC\n\
	.align 2, 0\n\
_080A1B7C: .4byte 0x03000011\n\
_080A1B80:\n\
	cmp r0, #5\n\
	beq _080A1BBC\n\
	cmp r0, #6\n\
	beq _080A1BD4\n\
	b _080A1BEC\n\
_080A1B8A:\n\
	ldr r0, _080A1B9C @ =gNonGameplayRam\n\
	mov ip, r0\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	adds r1, r6, r1\n\
	ldr r5, _080A1BA0 @ =0x0874DE4C\n\
	b _080A1BFA\n\
	.align 2, 0\n\
_080A1B9C: .4byte gNonGameplayRam\n\
_080A1BA0: .4byte 0x0874DE4C\n\
_080A1BA4:\n\
	ldr r0, _080A1BB4 @ =gNonGameplayRam\n\
	mov ip, r0\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	adds r1, r6, r1\n\
	ldr r5, _080A1BB8 @ =0x0874DFD8\n\
	b _080A1BFA\n\
	.align 2, 0\n\
_080A1BB4: .4byte gNonGameplayRam\n\
_080A1BB8: .4byte 0x0874DFD8\n\
_080A1BBC:\n\
	ldr r0, _080A1BCC @ =gNonGameplayRam\n\
	mov ip, r0\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	adds r1, r6, r1\n\
	ldr r5, _080A1BD0 @ =0x0874E1D0\n\
	b _080A1BFA\n\
	.align 2, 0\n\
_080A1BCC: .4byte gNonGameplayRam\n\
_080A1BD0: .4byte 0x0874E1D0\n\
_080A1BD4:\n\
	ldr r0, _080A1BE4 @ =gNonGameplayRam\n\
	mov ip, r0\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	adds r1, r6, r1\n\
	ldr r5, _080A1BE8 @ =0x0874E440\n\
	b _080A1BFA\n\
	.align 2, 0\n\
_080A1BE4: .4byte gNonGameplayRam\n\
_080A1BE8: .4byte 0x0874E440\n\
_080A1BEC:\n\
	ldr r0, _080A1C7C @ =gNonGameplayRam\n\
	mov ip, r0\n\
	movs r1, #0x92\n\
	lsls r1, r1, #1\n\
	add r1, ip\n\
	adds r1, r6, r1\n\
	ldr r5, _080A1C80 @ =0x0874DC48\n\
_080A1BFA:\n\
	lsls r3, r6, #1\n\
	adds r4, r3, r6\n\
	lsls r4, r4, #2\n\
	adds r2, r4, r5\n\
	ldrb r0, [r2]\n\
	strb r0, [r1]\n\
	movs r0, #0xa1\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	adds r0, r6, r0\n\
	ldrb r1, [r2, #1]\n\
	strb r1, [r0]\n\
	movs r0, #0xb0\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	adds r0, r6, r0\n\
	ldrb r1, [r2, #2]\n\
	strb r1, [r0]\n\
	movs r0, #0xbf\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	adds r0, r3, r0\n\
	ldrh r1, [r2, #4]\n\
	strh r1, [r0]\n\
	movs r0, #0xdd\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	adds r3, r3, r0\n\
	ldrh r0, [r2, #6]\n\
	strh r0, [r3]\n\
	lsls r1, r6, #2\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #1\n\
	add r0, ip\n\
	adds r1, r1, r0\n\
	adds r5, #8\n\
	adds r4, r4, r5\n\
	ldr r0, [r4]\n\
	str r0, [r1]\n\
	mov r1, ip\n\
	movs r3, #0\n\
	adds r2, r1, #0\n\
	adds r2, #0x9b\n\
	ldrb r0, [r2]\n\
	subs r0, #6\n\
	cmp r3, r0\n\
	bge _080A1C70\n\
	movs r5, #0\n\
	adds r4, r2, #0\n\
	movs r0, #0x95\n\
	lsls r0, r0, #1\n\
	adds r2, r1, r0\n\
_080A1C62:\n\
	strb r5, [r2]\n\
	adds r2, #1\n\
	adds r3, #1\n\
	ldrb r0, [r4]\n\
	subs r0, #6\n\
	cmp r3, r0\n\
	blt _080A1C62\n\
_080A1C70:\n\
	adds r1, #0x9b\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080A1C7C: .4byte gNonGameplayRam\n\
_080A1C80: .4byte 0x0874DC48\n\
    .syntax divided\n");
}
