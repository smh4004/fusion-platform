#include "status_screen.h"
#include "globals.h"
#include "macros.h"

#include "constants/samus.h"
#include "constants/status_screen.h"

#include "gba/keys.h"

#include "structs/samus.h"

/**
 * @brief 7e678 | 34 | Handler for the status screen
 * 
 */
void StatusScreenHandler(void)
{
    if ((gChangedInput & (KEY_B | KEY_L | KEY_R)) && !gNonGameplayRam.pauseScreen.subMenuStage) 
    {
        gNonGameplayRam.pauseScreen.unk_28.unk_0 = 7;
        gNonGameplayRam.pauseScreen.timer = 0;
        gNonGameplayRam.pauseScreen.subMenuStage = 0;
    }
}

/**
 * @brief 7e6ac | a8 | Draws everything on the status screen menu
 * 
 */
void StatusScreenDrawEverything(void)
{
    StatusScreenDrawBeamOrSuit(STATUS_SECTION_BEAM, gEquipment.beamStatus);
    StatusScreenDrawMissileOrBomb(STATUS_SECTION_MISSILE, gEquipment.weaponsStatus);
    StatusScreenDrawBeamOrSuit(STATUS_SECTION_SUIT, gEquipment.suitMiscStatus);
    StatusScreenDrawMissileOrBomb(STATUS_SECTION_BOMB, gEquipment.weaponsStatus);
    StatusScreenDrawMisc(STATUS_SECTION_MISC, gEquipment.suitMiscStatus);
    StatusScreenDrawNumber(STATUS_SECTION_ENERGY_CURRENT, gEquipment.currentEnergy, 6, FALSE);
    StatusScreenDrawNumber(STATUS_SECTION_ENERGY_MAX, gEquipment.maxEnergy, 3, TRUE);

    if (gEquipment.weaponsStatus & MBF_MISSILES)
    {
        StatusScreenDrawNumber(STATUS_SECTION_MISSILES_CURRENT, gEquipment.currentMissiles, 6, FALSE);
        StatusScreenDrawNumber(STATUS_SECTION_MISSILES_MAX, gEquipment.maxMissiles, 3, TRUE);
    } 
    else
    {
        StatusScreenRemoveAmmoHeader(1);
    }

    if ((gEquipment.weaponsStatus & (MBF_BOMBS | MBF_POWER_BOMBS)) == (MBF_BOMBS | MBF_POWER_BOMBS))
    {
        StatusScreenDrawNumber(STATUS_SECTION_POWER_BOMBS_CURRENT, gEquipment.currentPowerBombs, 6, FALSE);
        StatusScreenDrawNumber(STATUS_SECTION_POWER_BOMBS_MAX, gEquipment.maxPowerBombs, 3, TRUE);
        return;
    }

    StatusScreenRemoveAmmoHeader(2);
}

// 0x0807E754
NAKED_FUNCTION
void StatusScreenDrawNumber(u8 section, u16 value, u8 palette, boolu8 isMax)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	str r1, [sp]\n\
	lsls r2, r2, #0x18\n\
	lsrs r2, r2, #0x18\n\
	mov r8, r2\n\
	lsls r3, r3, #0x18\n\
	lsrs r3, r3, #0x18\n\
	mov sl, r3\n\
	ldr r3, _0807E7D0 @ =0x0858217C\n\
	lsls r2, r0, #2\n\
	adds r2, r2, r0\n\
	adds r0, r2, r3\n\
	ldrb r1, [r0]\n\
	lsls r1, r1, #5\n\
	adds r0, r3, #2\n\
	adds r0, r2, r0\n\
	ldrb r4, [r0]\n\
	adds r1, r1, r4\n\
	lsls r1, r1, #1\n\
	ldr r0, _0807E7D4 @ =0x0600C800\n\
	adds r0, r0, r1\n\
	mov sb, r0\n\
	adds r3, #3\n\
	adds r2, r2, r3\n\
	ldrb r0, [r2]\n\
	subs r6, r0, r4\n\
	ldr r1, _0807E7D8 @ =0x08576180\n\
	lsls r0, r6, #1\n\
	adds r0, r0, r1\n\
	ldrh r4, [r0]\n\
	adds r6, #1\n\
	movs r7, #0\n\
	movs r5, #0\n\
	cmp r4, #0\n\
	ble _0807E808\n\
_0807E7AC:\n\
	ldr r0, [sp]\n\
	adds r1, r4, #0\n\
	bl __divsi3\n\
	movs r1, #0xa\n\
	bl __modsi3\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	bne _0807E7E0\n\
	cmp r7, #0\n\
	bne _0807E7DC\n\
	movs r2, #0x8c\n\
	mov r3, sl\n\
	cmp r3, #0\n\
	beq _0807E7E4\n\
	b _0807E7F6\n\
	.align 2, 0\n\
_0807E7D0: .4byte 0x0858217C\n\
_0807E7D4: .4byte 0x0600C800\n\
_0807E7D8: .4byte 0x08576180\n\
_0807E7DC:\n\
	movs r2, #0x80\n\
	b _0807E7E8\n\
_0807E7E0:\n\
	movs r7, #1\n\
	adds r2, #0x80\n\
_0807E7E4:\n\
	cmp r2, #0\n\
	beq _0807E7F6\n\
_0807E7E8:\n\
	lsls r1, r5, #1\n\
	add r1, sb\n\
	mov r3, r8\n\
	lsls r0, r3, #0xc\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	b _0807E7F8\n\
_0807E7F6:\n\
	subs r5, #1\n\
_0807E7F8:\n\
	adds r0, r4, #0\n\
	movs r1, #0xa\n\
	bl __divsi3\n\
	adds r4, r0, #0\n\
	adds r5, #1\n\
	cmp r4, #0\n\
	bgt _0807E7AC\n\
_0807E808:\n\
	cmp r6, r5\n\
	beq _0807E822\n\
	mov r0, r8\n\
	lsls r2, r0, #0xc\n\
	movs r0, #0x8c\n\
	orrs r2, r0\n\
	lsls r0, r5, #1\n\
	add r0, sb\n\
_0807E818:\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	adds r5, #1\n\
	cmp r6, r5\n\
	bne _0807E818\n\
_0807E822:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x0807E834
NAKED_FUNCTION
void StatusScreenDrawBeamOrSuit(u8 section, u8 value)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x18\n\
	lsls r0, r0, #0x18\n\
	lsrs r7, r0, #0x18\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	str r1, [sp]\n\
	movs r0, #0\n\
	mov sb, r0\n\
	movs r2, #0\n\
	ldr r0, _0807E964 @ =0x0857617A\n\
	adds r1, r7, r0\n\
	ldrb r1, [r1]\n\
	cmp sb, r1\n\
	bge _0807E8F8\n\
	ldr r1, _0807E968 @ =0x0858217C\n\
	lsls r3, r7, #2\n\
	mov sl, r3\n\
	adds r5, r3, r7\n\
	ldr r0, _0807E96C @ =0x085821B3\n\
	adds r0, #2\n\
	adds r0, r5, r0\n\
	ldrb r0, [r0]\n\
	str r0, [sp, #8]\n\
	adds r0, r1, #3\n\
	adds r6, r5, r0\n\
	str r6, [sp, #0x14]\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	adds r0, #1\n\
	str r0, [sp, #4]\n\
	adds r1, #2\n\
	adds r1, r5, r1\n\
	ldrb r0, [r1]\n\
	mov r8, r0\n\
	str r5, [sp, #0xc]\n\
	str r1, [sp, #0x10]\n\
_0807E886:\n\
	ldr r1, [sp, #4]\n\
	adds r0, r1, r2\n\
	lsls r0, r0, #5\n\
	add r0, r8\n\
	mov ip, r0\n\
	ldr r3, _0807E96C @ =0x085821B3\n\
	adds r0, r5, r3\n\
	ldrb r0, [r0]\n\
	adds r0, #1\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #5\n\
	ldr r1, [sp, #8]\n\
	adds r6, r0, r1\n\
	ldr r0, _0807E970 @ =0x0879BEA8\n\
	add r0, sl\n\
	ldr r0, [r0]\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	ldr r3, [sp]\n\
	ands r0, r3\n\
	adds r2, #1\n\
	cmp r0, #0\n\
	beq _0807E8EE\n\
	mov sb, r2\n\
	ldr r1, [sp, #0x14]\n\
	ldrb r0, [r1]\n\
	mov r2, r8\n\
	subs r0, r0, r2\n\
	mov r2, sb\n\
	cmp r0, #0\n\
	blt _0807E8EE\n\
	ldr r3, [sp, #0xc]\n\
	ldr r1, _0807E974 @ =0x0858217F\n\
	adds r0, r3, r1\n\
	ldrb r1, [r0]\n\
	ldr r3, [sp, #0x10]\n\
	ldrb r0, [r3]\n\
	subs r1, r1, r0\n\
	lsls r0, r6, #1\n\
	ldr r6, _0807E978 @ =0x0600C800\n\
	adds r4, r0, r6\n\
	mov r3, ip\n\
	lsls r0, r3, #1\n\
	adds r3, r0, r6\n\
	adds r1, #1\n\
_0807E8E0:\n\
	ldrh r0, [r4]\n\
	strh r0, [r3]\n\
	adds r4, #2\n\
	adds r3, #2\n\
	subs r1, #1\n\
	cmp r1, #0\n\
	bne _0807E8E0\n\
_0807E8EE:\n\
	ldr r6, _0807E964 @ =0x0857617A\n\
	adds r0, r7, r6\n\
	ldrb r0, [r0]\n\
	cmp r2, r0\n\
	blt _0807E886\n\
_0807E8F8:\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	beq _0807E954\n\
	ldr r3, _0807E968 @ =0x0858217C\n\
	lsls r2, r7, #2\n\
	adds r2, r2, r7\n\
	adds r0, r2, r3\n\
	mov r1, sb\n\
	adds r1, #1\n\
	ldrb r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #5\n\
	adds r0, r3, #2\n\
	adds r0, r2, r0\n\
	ldrb r4, [r0]\n\
	adds r1, r1, r4\n\
	mov ip, r1\n\
	ldr r1, _0807E96C @ =0x085821B3\n\
	adds r0, r1, #1\n\
	adds r0, r2, r0\n\
	ldrb r0, [r0]\n\
	adds r1, #2\n\
	adds r1, r2, r1\n\
	lsls r0, r0, #5\n\
	ldrb r1, [r1]\n\
	adds r6, r0, r1\n\
	adds r3, #3\n\
	adds r2, r2, r3\n\
	ldrb r0, [r2]\n\
	subs r1, r0, r4\n\
	cmp r1, #0\n\
	blt _0807E954\n\
	lsls r0, r6, #1\n\
	ldr r2, _0807E978 @ =0x0600C800\n\
	adds r4, r0, r2\n\
	mov r3, ip\n\
	lsls r0, r3, #1\n\
	adds r3, r0, r2\n\
	adds r1, #1\n\
_0807E946:\n\
	ldrh r0, [r4]\n\
	strh r0, [r3]\n\
	adds r4, #2\n\
	adds r3, #2\n\
	subs r1, #1\n\
	cmp r1, #0\n\
	bne _0807E946\n\
_0807E954:\n\
	add sp, #0x18\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807E964: .4byte 0x0857617A\n\
_0807E968: .4byte 0x0858217C\n\
_0807E96C: .4byte 0x085821B3\n\
_0807E970: .4byte 0x0879BEA8\n\
_0807E974: .4byte 0x0858217F\n\
_0807E978: .4byte 0x0600C800\n\
    .syntax divided\n");
}

// 0x0807E97C
NAKED_FUNCTION
void StatusScreenDrawMissileOrBomb(u8 section, u8 value)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x18\n\
	lsls r0, r0, #0x18\n\
	lsrs r7, r0, #0x18\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	str r1, [sp]\n\
	movs r0, #1\n\
	rsbs r0, r0, #0\n\
	str r0, [sp, #4]\n\
	movs r2, #0\n\
	ldr r0, _0807EA30 @ =0x0857617A\n\
	adds r1, r7, r0\n\
	ldrb r1, [r1]\n\
	cmp r2, r1\n\
	bge _0807EA5C\n\
	ldr r1, _0807EA34 @ =0x0858217C\n\
	lsls r3, r7, #2\n\
	mov sl, r3\n\
	adds r5, r3, r7\n\
	ldr r0, _0807EA38 @ =0x085821B3\n\
	adds r0, #2\n\
	adds r0, r5, r0\n\
	ldrb r0, [r0]\n\
	str r0, [sp, #8]\n\
	adds r0, r1, #3\n\
	adds r0, r5, r0\n\
	str r0, [sp, #0x14]\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	adds r1, #2\n\
	adds r1, r5, r1\n\
	ldrb r6, [r1]\n\
	mov sb, r6\n\
	str r5, [sp, #0xc]\n\
	str r1, [sp, #0x10]\n\
	lsls r0, r0, #5\n\
	mov ip, r0\n\
_0807E9D0:\n\
	mov r0, ip\n\
	add r0, sb\n\
	mov r8, r0\n\
	ldr r1, _0807EA38 @ =0x085821B3\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #5\n\
	ldr r3, [sp, #8]\n\
	adds r6, r0, r3\n\
	ldr r0, _0807EA3C @ =0x0879BEA8\n\
	add r0, sl\n\
	ldr r0, [r0]\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	ldr r1, [sp]\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807EA48\n\
	str r2, [sp, #4]\n\
	ldr r3, [sp, #0x14]\n\
	ldrb r0, [r3]\n\
	mov r1, sb\n\
	subs r0, r0, r1\n\
	cmp r0, #0\n\
	blt _0807EA4C\n\
	ldr r0, _0807EA40 @ =0x0858217F\n\
	ldr r3, [sp, #0xc]\n\
	adds r0, r3, r0\n\
	ldrb r1, [r0]\n\
	ldr r3, [sp, #0x10]\n\
	ldrb r0, [r3]\n\
	subs r1, r1, r0\n\
	lsls r0, r6, #1\n\
	ldr r6, _0807EA44 @ =0x0600C800\n\
	adds r4, r0, r6\n\
	mov r3, r8\n\
	lsls r0, r3, #1\n\
	adds r3, r0, r6\n\
	adds r1, #1\n\
_0807EA20:\n\
	ldrh r0, [r4]\n\
	strh r0, [r3]\n\
	adds r4, #2\n\
	adds r3, #2\n\
	subs r1, #1\n\
	cmp r1, #0\n\
	bne _0807EA20\n\
	b _0807EA4C\n\
	.align 2, 0\n\
_0807EA30: .4byte 0x0857617A\n\
_0807EA34: .4byte 0x0858217C\n\
_0807EA38: .4byte 0x085821B3\n\
_0807EA3C: .4byte 0x0879BEA8\n\
_0807EA40: .4byte 0x0858217F\n\
_0807EA44: .4byte 0x0600C800\n\
_0807EA48:\n\
	cmp r2, #0\n\
	beq _0807EAB8\n\
_0807EA4C:\n\
	movs r6, #0x20\n\
	add ip, r6\n\
	adds r2, #1\n\
	ldr r1, _0807EAC8 @ =0x0857617A\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r2, r0\n\
	blt _0807E9D0\n\
_0807EA5C:\n\
	ldr r2, [sp, #4]\n\
	cmp r2, #0\n\
	blt _0807EAB8\n\
	ldr r3, _0807EACC @ =0x0858217C\n\
	lsls r2, r7, #2\n\
	adds r2, r2, r7\n\
	adds r0, r2, r3\n\
	ldr r1, [sp, #4]\n\
	adds r1, #1\n\
	ldrb r0, [r0]\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #5\n\
	adds r0, r3, #2\n\
	adds r0, r2, r0\n\
	ldrb r4, [r0]\n\
	adds r1, r1, r4\n\
	mov r8, r1\n\
	ldr r1, _0807EAD0 @ =0x085821B3\n\
	adds r0, r1, #1\n\
	adds r0, r2, r0\n\
	ldrb r0, [r0]\n\
	adds r1, #2\n\
	adds r1, r2, r1\n\
	lsls r0, r0, #5\n\
	ldrb r1, [r1]\n\
	adds r6, r0, r1\n\
	adds r3, #3\n\
	adds r2, r2, r3\n\
	ldrb r0, [r2]\n\
	subs r1, r0, r4\n\
	cmp r1, #0\n\
	blt _0807EAB8\n\
	lsls r0, r6, #1\n\
	ldr r3, _0807EAD4 @ =0x0600C800\n\
	adds r4, r0, r3\n\
	mov r6, r8\n\
	lsls r0, r6, #1\n\
	adds r3, r0, r3\n\
	adds r1, #1\n\
_0807EAAA:\n\
	ldrh r0, [r4]\n\
	strh r0, [r3]\n\
	adds r4, #2\n\
	adds r3, #2\n\
	subs r1, #1\n\
	cmp r1, #0\n\
	bne _0807EAAA\n\
_0807EAB8:\n\
	add sp, #0x18\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807EAC8: .4byte 0x0857617A\n\
_0807EACC: .4byte 0x0858217C\n\
_0807EAD0: .4byte 0x085821B3\n\
_0807EAD4: .4byte 0x0600C800\n\
    .syntax divided\n");
}

// 0x0807EAD8
NAKED_FUNCTION
void StatusScreenDrawMisc(u8 section, u8 value)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x24\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r8, r0\n\
	lsls r1, r1, #0x18\n\
	lsrs r1, r1, #0x18\n\
	str r1, [sp]\n\
	movs r0, #0\n\
	str r0, [sp, #4]\n\
	movs r4, #0\n\
	ldr r0, _0807EBF8 @ =0x0857617A\n\
	mov r2, r8\n\
	adds r1, r2, r0\n\
	ldrb r1, [r1]\n\
	cmp r4, r1\n\
	bge _0807EB9C\n\
	ldr r1, _0807EBFC @ =0x0858217C\n\
	lsls r2, r2, #2\n\
	mov sb, r2\n\
	add r2, r8\n\
	ldr r3, _0807EC00 @ =0x085821B3\n\
	mov sl, r3\n\
	mov r0, sl\n\
	adds r0, #2\n\
	adds r0, r2, r0\n\
	ldrb r0, [r0]\n\
	str r0, [sp, #0xc]\n\
	adds r0, r1, #3\n\
	adds r6, r2, r0\n\
	str r6, [sp, #0x1c]\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	adds r0, #1\n\
	str r0, [sp, #8]\n\
	adds r1, #2\n\
	adds r1, r2, r1\n\
	ldrb r7, [r1]\n\
	str r2, [sp, #0x10]\n\
	mov ip, r1\n\
_0807EB30:\n\
	ldr r1, [sp, #8]\n\
	adds r0, r1, r4\n\
	lsls r0, r0, #5\n\
	adds r6, r0, r7\n\
	mov r3, sl\n\
	adds r0, r2, r3\n\
	ldrb r0, [r0]\n\
	adds r0, #1\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #5\n\
	ldr r1, [sp, #0xc]\n\
	adds r3, r0, r1\n\
	ldr r0, _0807EC04 @ =0x0879BEA8\n\
	add r0, sb\n\
	ldr r0, [r0]\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0]\n\
	ldr r1, [sp]\n\
	ands r0, r1\n\
	adds r5, r4, #1\n\
	cmp r0, #0\n\
	beq _0807EB90\n\
	str r5, [sp, #4]\n\
	ldr r4, [sp, #0x1c]\n\
	ldrb r0, [r4]\n\
	subs r0, r0, r7\n\
	cmp r0, #0\n\
	blt _0807EB90\n\
	ldr r1, [sp, #0x10]\n\
	ldr r4, _0807EC08 @ =0x0858217F\n\
	adds r0, r1, r4\n\
	ldrb r1, [r0]\n\
	mov r4, ip\n\
	ldrb r0, [r4]\n\
	subs r1, r1, r0\n\
	lsls r0, r3, #1\n\
	ldr r3, _0807EC0C @ =0x0600C800\n\
	adds r4, r0, r3\n\
	lsls r0, r6, #1\n\
	adds r3, r0, r3\n\
	adds r1, #1\n\
_0807EB82:\n\
	ldrh r0, [r4]\n\
	strh r0, [r3]\n\
	adds r4, #2\n\
	adds r3, #2\n\
	subs r1, #1\n\
	cmp r1, #0\n\
	bne _0807EB82\n\
_0807EB90:\n\
	adds r4, r5, #0\n\
	ldr r0, _0807EBF8 @ =0x0857617A\n\
	add r0, r8\n\
	ldrb r0, [r0]\n\
	cmp r4, r0\n\
	blt _0807EB30\n\
_0807EB9C:\n\
	ldr r4, [sp, #4]\n\
	cmp r4, #0\n\
	beq _0807EC6C\n\
	movs r4, #0\n\
	ldr r1, _0807EBFC @ =0x0858217C\n\
	mov r6, r8\n\
	lsls r6, r6, #2\n\
	str r6, [sp, #0x14]\n\
	adds r7, r6, #0\n\
	add r7, r8\n\
	adds r2, r1, #2\n\
	adds r0, r7, r2\n\
	mov ip, r0\n\
	ldr r0, _0807EC00 @ =0x085821B3\n\
	adds r0, #2\n\
	adds r0, r0, r7\n\
	mov sl, r0\n\
	adds r2, r7, r1\n\
	mov sb, r2\n\
	ldr r0, _0807EC00 @ =0x085821B3\n\
	adds r0, #1\n\
	adds r0, r7, r0\n\
	str r0, [sp, #0x18]\n\
	ldr r3, _0807EC08 @ =0x0858217F\n\
	adds r3, r7, r3\n\
	str r3, [sp, #0x20]\n\
_0807EBD0:\n\
	cmp r4, #0\n\
	bne _0807EC10\n\
	ldr r6, [sp, #4]\n\
	adds r6, #1\n\
	str r6, [sp, #4]\n\
	mov r1, sb\n\
	ldrb r0, [r1]\n\
	adds r0, r0, r6\n\
	lsls r0, r0, #5\n\
	mov r2, ip\n\
	ldrb r2, [r2]\n\
	adds r6, r0, r2\n\
	ldr r3, [sp, #0x18]\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #5\n\
	mov r1, sl\n\
	ldrb r1, [r1]\n\
	adds r3, r0, r1\n\
	b _0807EC2A\n\
	.align 2, 0\n\
_0807EBF8: .4byte 0x0857617A\n\
_0807EBFC: .4byte 0x0858217C\n\
_0807EC00: .4byte 0x085821B3\n\
_0807EC04: .4byte 0x0879BEA8\n\
_0807EC08: .4byte 0x0858217F\n\
_0807EC0C: .4byte 0x0600C800\n\
_0807EC10:\n\
	mov r2, sb\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #5\n\
	mov r3, ip\n\
	ldrb r3, [r3]\n\
	adds r6, r0, r3\n\
	ldr r1, _0807EC7C @ =0x085821B3\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #5\n\
	mov r2, sl\n\
	ldrb r2, [r2]\n\
	adds r3, r0, r2\n\
_0807EC2A:\n\
	ldr r0, [sp, #0x20]\n\
	ldrb r1, [r0]\n\
	mov r2, ip\n\
	ldrb r0, [r2]\n\
	subs r1, r1, r0\n\
	adds r5, r4, #1\n\
	cmp r1, #0\n\
	blt _0807EC66\n\
	ldr r1, [sp, #0x14]\n\
	add r1, r8\n\
	ldr r4, _0807EC80 @ =0x0858217F\n\
	adds r0, r1, r4\n\
	ldrb r2, [r0]\n\
	ldr r0, _0807EC84 @ =0x0858217E\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1]\n\
	subs r2, r2, r0\n\
	lsls r0, r3, #1\n\
	ldr r1, _0807EC88 @ =0x0600C800\n\
	adds r4, r0, r1\n\
	lsls r0, r6, #1\n\
	adds r3, r0, r1\n\
	adds r1, r2, #1\n\
_0807EC58:\n\
	ldrh r0, [r4]\n\
	strh r0, [r3]\n\
	adds r4, #2\n\
	adds r3, #2\n\
	subs r1, #1\n\
	cmp r1, #0\n\
	bne _0807EC58\n\
_0807EC66:\n\
	adds r4, r5, #0\n\
	cmp r4, #1\n\
	ble _0807EBD0\n\
_0807EC6C:\n\
	add sp, #0x24\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807EC7C: .4byte 0x085821B3\n\
_0807EC80: .4byte 0x0858217F\n\
_0807EC84: .4byte 0x0858217E\n\
_0807EC88: .4byte 0x0600C800\n\
    .syntax divided\n");
}

// 0x0807EC8C
NAKED_FUNCTION
void StatusScreenRemoveAmmoHeader(u8 position)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _0807ECA2\n\
	movs r1, #1\n\
	b _0807ECA8\n\
_0807ECA2:\n\
	cmp r0, #2\n\
	bne _0807ED0A\n\
	movs r1, #2\n\
_0807ECA8:\n\
	ldr r0, _0807ED18 @ =0x0600C800\n\
	mov r8, r0\n\
	movs r3, #0\n\
	lsls r1, r1, #2\n\
	ldr r5, _0807ED1C @ =0x085821D6\n\
	adds r0, r1, r5\n\
	ldrb r0, [r0]\n\
	mov sl, r0\n\
	ldrb r7, [r5, #2]\n\
	ldrb r0, [r5, #3]\n\
	subs r0, r0, r7\n\
	mov sb, r0\n\
	adds r0, r5, #2\n\
	adds r1, r1, r0\n\
	ldrb r1, [r1]\n\
	mov ip, r1\n\
_0807ECC8:\n\
	mov r1, sl\n\
	adds r0, r1, r3\n\
	lsls r0, r0, #5\n\
	mov r2, ip\n\
	adds r4, r0, r2\n\
	ldrb r0, [r5]\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #5\n\
	adds r2, r0, r7\n\
	adds r6, r3, #1\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	blt _0807ED04\n\
	ldrb r1, [r5, #3]\n\
	ldrb r0, [r5, #2]\n\
	subs r1, r1, r0\n\
	lsls r0, r2, #1\n\
	ldr r2, _0807ED18 @ =0x0600C800\n\
	adds r3, r0, r2\n\
	lsls r0, r4, #1\n\
	mov r4, r8\n\
	adds r2, r0, r4\n\
	adds r1, #1\n\
_0807ECF6:\n\
	ldrh r0, [r3]\n\
	strh r0, [r2]\n\
	adds r3, #2\n\
	adds r2, #2\n\
	subs r1, #1\n\
	cmp r1, #0\n\
	bne _0807ECF6\n\
_0807ED04:\n\
	adds r3, r6, #0\n\
	cmp r3, #1\n\
	ble _0807ECC8\n\
_0807ED0A:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807ED18: .4byte 0x0600C800\n\
_0807ED1C: .4byte 0x085821D6\n\
    .syntax divided\n");
}
