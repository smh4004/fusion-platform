#include "sprites_AI/gunship.h"
#include "globals.h"
#include "macros.h"
#include "music_wrappers.h"
#include "audio_wrappers.h"

#include "data/sprites/gunship.h"

#include "constants/audio.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/samus.h"
#include "structs/sprite.h"

// 0x08056140
NAKED_FUNCTION
void GunshipEndSpawnBeams(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	sub sp, #0xc\n\
	ldr r0, _08056170 @ =gCurrentSprite\n\
	movs r2, #0x90\n\
	lsls r2, r2, #1\n\
	adds r1, r2, #0\n\
	ldrh r2, [r0, #2]\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #0x10\n\
	lsrs r4, r1, #0x10\n\
	ldrh r5, [r0, #4]\n\
	adds r1, r0, #0\n\
	adds r1, #0x2f\n\
	ldrb r1, [r1]\n\
	subs r1, #6\n\
	adds r3, r0, #0\n\
	cmp r1, #0xf\n\
	bls _08056166\n\
	b _08056270\n\
_08056166:\n\
	lsls r0, r1, #2\n\
	ldr r1, _08056174 @ =_08056178\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08056170: .4byte gCurrentSprite\n\
_08056174: .4byte _08056178\n\
_08056178: @ jump table\n\
	.4byte _080561B8 @ case 0\n\
	.4byte _08056270 @ case 1\n\
	.4byte _08056270 @ case 2\n\
	.4byte _080561DC @ case 3\n\
	.4byte _08056270 @ case 4\n\
	.4byte _08056270 @ case 5\n\
	.4byte _080561FA @ case 6\n\
	.4byte _08056270 @ case 7\n\
	.4byte _08056270 @ case 8\n\
	.4byte _08056218 @ case 9\n\
	.4byte _08056270 @ case 10\n\
	.4byte _08056270 @ case 11\n\
	.4byte _08056236 @ case 12\n\
	.4byte _08056270 @ case 13\n\
	.4byte _08056270 @ case 14\n\
	.4byte _08056254 @ case 15\n\
_080561B8:\n\
	ldrb r2, [r3, #0x1f]\n\
	adds r0, r3, #0\n\
	adds r0, #0x23\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	subs r0, #0xcc\n\
	str r0, [sp]\n\
	str r5, [sp, #4]\n\
	movs r0, #0\n\
	str r0, [sp, #8]\n\
	movs r0, #0x79\n\
	movs r1, #0\n\
	bl SpriteSpawnSecondary\n\
	movs r0, #0xfd\n\
	bl SoundPlay\n\
	b _08056270\n\
_080561DC:\n\
	ldrb r2, [r3, #0x1f]\n\
	adds r0, r3, #0\n\
	adds r0, #0x23\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	subs r0, #0xb0\n\
	str r0, [sp]\n\
	str r5, [sp, #4]\n\
	movs r0, #0\n\
	str r0, [sp, #8]\n\
	movs r0, #0x79\n\
	movs r1, #1\n\
	bl SpriteSpawnSecondary\n\
	b _08056270\n\
_080561FA:\n\
	ldrb r2, [r3, #0x1f]\n\
	adds r0, r3, #0\n\
	adds r0, #0x23\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	subs r0, #0x98\n\
	str r0, [sp]\n\
	str r5, [sp, #4]\n\
	movs r0, #0\n\
	str r0, [sp, #8]\n\
	movs r0, #0x79\n\
	movs r1, #3\n\
	bl SpriteSpawnSecondary\n\
	b _08056270\n\
_08056218:\n\
	ldrb r2, [r3, #0x1f]\n\
	adds r0, r3, #0\n\
	adds r0, #0x23\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	subs r0, #0x80\n\
	str r0, [sp]\n\
	str r5, [sp, #4]\n\
	movs r0, #0\n\
	str r0, [sp, #8]\n\
	movs r0, #0x79\n\
	movs r1, #5\n\
	bl SpriteSpawnSecondary\n\
	b _08056270\n\
_08056236:\n\
	ldrb r2, [r3, #0x1f]\n\
	adds r0, r3, #0\n\
	adds r0, #0x23\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	subs r0, #0x68\n\
	str r0, [sp]\n\
	str r5, [sp, #4]\n\
	movs r0, #0\n\
	str r0, [sp, #8]\n\
	movs r0, #0x79\n\
	movs r1, #7\n\
	bl SpriteSpawnSecondary\n\
	b _08056270\n\
_08056254:\n\
	ldrb r2, [r3, #0x1f]\n\
	adds r0, r3, #0\n\
	adds r0, #0x23\n\
	ldrb r3, [r0]\n\
	adds r0, r4, #0\n\
	subs r0, #0x50\n\
	str r0, [sp]\n\
	str r5, [sp, #4]\n\
	movs r0, #0\n\
	str r0, [sp, #8]\n\
	movs r0, #0x79\n\
	movs r1, #9\n\
	bl SpriteSpawnSecondary\n\
_08056270:\n\
	add sp, #0xc\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x08056278
NAKED_FUNCTION
void GunshipEndInit(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	ldr r0, _080562F4 @ =gCurrentSprite\n\
	mov ip, r0\n\
	ldrh r0, [r0]\n\
	ldr r1, _080562F8 @ =0x0000FFFB\n\
	ands r1, r0\n\
	movs r2, #0\n\
	movs r3, #0\n\
	mov r4, ip\n\
	adds r4, #0x22\n\
	movs r0, #0xc\n\
	strb r0, [r4]\n\
	subs r4, #1\n\
	movs r0, #3\n\
	strb r0, [r4]\n\
	movs r0, #8\n\
	orrs r1, r0\n\
	mov r4, ip\n\
	strh r1, [r4]\n\
	movs r0, #0x90\n\
	strh r0, [r4, #0x12]\n\
	mov r0, ip\n\
	adds r0, #0x2b\n\
	strb r2, [r0]\n\
	adds r0, #6\n\
	strb r2, [r0]\n\
	subs r0, #1\n\
	strb r2, [r0]\n\
	mov r1, ip\n\
	adds r1, #0x2e\n\
	movs r0, #0x3c\n\
	strb r0, [r1]\n\
	mov r0, ip\n\
	adds r0, #0x25\n\
	strb r2, [r0]\n\
	subs r1, #7\n\
	movs r0, #0x7f\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	movs r0, #0x40\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	movs r0, #0xb0\n\
	strb r0, [r1]\n\
	ldr r1, _080562FC @ =0x0000FFFC\n\
	strh r1, [r4, #0xa]\n\
	movs r0, #4\n\
	strh r0, [r4, #0xc]\n\
	strh r1, [r4, #0xe]\n\
	strh r0, [r4, #0x10]\n\
	mov r1, ip\n\
	adds r1, #0x24\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	ldr r0, _08056300 @ =sBlob_39ab62_39f4b0 + 0x4106\n\
	str r0, [r4, #0x18]\n\
	strb r2, [r4, #0x1c]\n\
	strh r3, [r4, #0x16]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080562F4: .4byte gCurrentSprite\n\
_080562F8: .4byte 0x0000FFFB\n\
_080562FC: .4byte 0x0000FFFC\n\
_08056300: .4byte sBlob_39ab62_39f4b0 + 0x4106\n\
    .syntax divided\n");
}

/**
 * @brief 56304 | 34 | Handles the ending gunship waiting before take-off
 * 
 */
void GunshipEndWaiting(void)
{
    gCurrentSprite.work1--;

    if (gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
        PlayMusic(MUSIC_FINAL_ORDER, 14);
        gCurrentSprite.work1 = 30;
    }
}

// 0x08056338
NAKED_FUNCTION
void GunshipEndMovingUp(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	ldr r0, _08056374 @ =gCurrentSprite\n\
	adds r1, r0, #0\n\
	adds r1, #0x2e\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _08056356\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _08056356\n\
	ldr r0, _08056378 @ =0x00000249\n\
	bl SoundPlay_3b1c\n\
_08056356:\n\
	movs r4, #0\n\
	ldr r3, _08056374 @ =gCurrentSprite\n\
	ldrh r2, [r3, #4]\n\
	lsrs r0, r2, #2\n\
	ldr r1, _0805637C @ =gBg1XPosition\n\
	ldrh r1, [r1]\n\
	lsrs r1, r1, #2\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x6f\n\
	bhi _08056380\n\
	adds r0, r2, #1\n\
	strh r0, [r3, #4]\n\
	b _0805638C\n\
	.align 2, 0\n\
_08056374: .4byte gCurrentSprite\n\
_08056378: .4byte 0x00000249\n\
_0805637C: .4byte gBg1XPosition\n\
_08056380:\n\
	cmp r0, #0x80\n\
	bls _0805638A\n\
	subs r0, r2, #1\n\
	strh r0, [r3, #4]\n\
	b _0805638C\n\
_0805638A:\n\
	movs r4, #1\n\
_0805638C:\n\
	ldrh r2, [r3, #2]\n\
	lsrs r0, r2, #2\n\
	ldr r1, _080563A8 @ =gBg1YPosition\n\
	ldrh r1, [r1]\n\
	lsrs r1, r1, #2\n\
	subs r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x2b\n\
	bhi _080563AC\n\
	adds r0, r2, #1\n\
	strh r0, [r3, #2]\n\
	b _080563BC\n\
	.align 2, 0\n\
_080563A8: .4byte gBg1YPosition\n\
_080563AC:\n\
	cmp r0, #0x3c\n\
	bls _080563B6\n\
	subs r0, r2, #1\n\
	strh r0, [r3, #2]\n\
	b _080563BC\n\
_080563B6:\n\
	adds r0, r4, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
_080563BC:\n\
	cmp r4, #1\n\
	bls _080563E0\n\
	adds r1, r3, #0\n\
	adds r1, #0x21\n\
	movs r2, #0\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	adds r1, #3\n\
	movs r0, #0x17\n\
	strb r0, [r1]\n\
	adds r1, #0xa\n\
	movs r0, #0x3c\n\
	strb r0, [r1]\n\
	adds r0, r3, #0\n\
	adds r0, #0x31\n\
	strb r2, [r0]\n\
	subs r0, #1\n\
	strb r2, [r0]\n\
_080563E0:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

/**
 * @brief 563e8 | 5c | Handles the ending gunship hovering before it lands
 * 
 */
void GunshipEndWaitingToEnter(void)
{
    u8 offset;
    s16 movement;

    offset = gCurrentSprite.work4;
    movement = sGunshipEndEnteringYMovement[offset];

    if (movement == SHORT_MAX)
    {
        movement = sGunshipEndEnteringYMovement[0];
        offset = 0;
    }

    gCurrentSprite.work4 = offset + 1;
    gCurrentSprite.yPosition += movement;

    gCurrentSprite.work1--;

    if (gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.work1 = 0;
    }
}

// 0x08056444
NAKED_FUNCTION
void GunshipEndEntering(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #0xc\n\
	ldr r0, _080564B0 @ =gCurrentSprite\n\
	mov ip, r0\n\
	movs r1, #0x31\n\
	add r1, ip\n\
	mov r8, r1\n\
	ldrb r2, [r1]\n\
	ldr r4, _080564B4 @ =sGunshipEndEnteringYMovement\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r4\n\
	ldrh r3, [r0]\n\
	movs r5, #0\n\
	ldrsh r1, [r0, r5]\n\
	ldr r0, _080564B8 @ =0x00007FFF\n\
	cmp r1, r0\n\
	bne _0805646E\n\
	ldrh r3, [r4]\n\
	movs r2, #0\n\
_0805646E:\n\
	adds r0, r2, #1\n\
	movs r7, #0\n\
	mov r6, r8\n\
	strb r0, [r6]\n\
	mov r1, ip\n\
	ldrh r0, [r1, #2]\n\
	adds r4, r0, r3\n\
	movs r5, #0\n\
	strh r4, [r1, #2]\n\
	ldr r2, _080564BC @ =sBlob_39ab62_39f4b0 + 0x12E\n\
	mov r6, ip\n\
	adds r6, #0x2e\n\
	ldrb r3, [r6]\n\
	lsls r1, r3, #0x18\n\
	lsrs r0, r1, #0x1a\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	mov r2, ip\n\
	strh r0, [r2, #0x12]\n\
	lsrs r1, r1, #0x18\n\
	cmp r1, #0x6f\n\
	bhi _080564C0\n\
	adds r0, r3, #1\n\
	strb r0, [r6]\n\
	movs r1, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08056576\n\
	adds r0, r4, #1\n\
	strh r0, [r2, #2]\n\
	b _08056576\n\
	.align 2, 0\n\
_080564B0: .4byte gCurrentSprite\n\
_080564B4: .4byte sGunshipEndEnteringYMovement\n\
_080564B8: .4byte 0x00007FFF\n\
_080564BC: .4byte sBlob_39ab62_39f4b0 + 0x12E\n\
_080564C0:\n\
	mov r3, ip\n\
	ldrh r1, [r3]\n\
	ldr r0, _08056584 @ =0x0000FFF7\n\
	ands r0, r1\n\
	strh r0, [r3]\n\
	mov r1, ip\n\
	adds r1, #0x24\n\
	movs r0, #0x1a\n\
	strb r0, [r1]\n\
	ldr r0, _08056588 @ =sBlob_39ab62_39f4b0 + 0x3FE6\n\
	str r0, [r3, #0x18]\n\
	strb r5, [r3, #0x1c]\n\
	strh r7, [r3, #0x16]\n\
	mov r0, ip\n\
	adds r0, #0x2f\n\
	strb r5, [r0]\n\
	adds r1, #0x10\n\
	ldrb r0, [r1]\n\
	movs r4, #1\n\
	orrs r0, r4\n\
	strb r0, [r1]\n\
	ldrb r1, [r3, #0x1e]\n\
	ldrb r2, [r3, #0x1f]\n\
	mov r0, ip\n\
	adds r0, #0x23\n\
	ldrb r3, [r0]\n\
	mov r6, ip\n\
	ldrh r0, [r6, #2]\n\
	str r0, [sp]\n\
	ldrh r0, [r6, #4]\n\
	str r0, [sp, #4]\n\
	str r7, [sp, #8]\n\
	movs r0, #0x7a\n\
	bl SpriteSpawnSecondary\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r1, r8\n\
	strb r0, [r1]\n\
	ldr r2, _0805658C @ =gSpriteData\n\
	lsls r1, r0, #3\n\
	subs r1, r1, r0\n\
	lsls r1, r1, #3\n\
	adds r3, r1, r2\n\
	mov ip, r3\n\
	ldrh r3, [r3]\n\
	ldr r0, _08056590 @ =0x0000FFFB\n\
	ands r0, r3\n\
	mov r6, ip\n\
	strh r0, [r6]\n\
	adds r2, #0x18\n\
	adds r1, r1, r2\n\
	ldr r0, _08056594 @ =sBlob_39ab62_39f4b0 + 0x40CE\n\
	str r0, [r1]\n\
	strb r5, [r6, #0x1c]\n\
	strh r7, [r6, #0x16]\n\
	mov r1, ip\n\
	adds r1, #0x34\n\
	ldrb r0, [r1]\n\
	orrs r0, r4\n\
	strb r0, [r1]\n\
	subs r1, #0x12\n\
	movs r0, #0xe\n\
	strb r0, [r1]\n\
	mov r0, ip\n\
	adds r0, #0x25\n\
	strb r5, [r0]\n\
	adds r0, #2\n\
	movs r2, #4\n\
	strb r2, [r0]\n\
	adds r1, #6\n\
	movs r0, #0x38\n\
	strb r0, [r1]\n\
	adds r1, #1\n\
	movs r0, #0x30\n\
	strb r0, [r1]\n\
	ldr r0, _08056598 @ =0x0000FFFC\n\
	strh r0, [r6, #0xa]\n\
	strh r2, [r6, #0xc]\n\
	strh r0, [r6, #0xe]\n\
	strh r2, [r6, #0x10]\n\
	subs r1, #5\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	mov r0, ip\n\
	adds r0, #0x2e\n\
	strb r5, [r0]\n\
	adds r0, #1\n\
	strb r5, [r0]\n\
	adds r0, #1\n\
	strb r5, [r0]\n\
_08056576:\n\
	add sp, #0xc\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08056584: .4byte 0x0000FFF7\n\
_08056588: .4byte sBlob_39ab62_39f4b0 + 0x3FE6\n\
_0805658C: .4byte gSpriteData\n\
_08056590: .4byte 0x0000FFFB\n\
_08056594: .4byte sBlob_39ab62_39f4b0 + 0x40CE\n\
_08056598: .4byte 0x0000FFFC\n\
    .syntax divided\n");
}

// 0x0805659C
NAKED_FUNCTION
void GunshipEndWaitingForSamus(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r4, _080565B4 @ =gCurrentSprite\n\
	adds r1, r4, #0\n\
	adds r1, #0x2f\n\
	ldrb r0, [r1]\n\
	cmp r0, #0x23\n\
	bhi _080565B8\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	bl GunshipEndSpawnBeams\n\
	b _08056638\n\
	.align 2, 0\n\
_080565B4: .4byte gCurrentSprite\n\
_080565B8:\n\
	ldrh r2, [r4, #4]\n\
	adds r0, r2, #0\n\
	subs r0, #0x20\n\
	ldr r5, _08056624 @ =gSamusData\n\
	ldrh r1, [r5, #0x16]\n\
	cmp r0, r1\n\
	bge _08056630\n\
	adds r0, #0x40\n\
	cmp r0, r1\n\
	ble _08056630\n\
	ldrh r1, [r5, #0x18]\n\
	ldr r0, _08056628 @ =0x000002BF\n\
	cmp r1, r0\n\
	bne _08056630\n\
	bl SpriteUtilCheckSamusMorphed\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	bne _08056630\n\
	ldrb r0, [r5, #5]\n\
	cmp r0, #0\n\
	beq _080565E6\n\
	strb r1, [r5, #5]\n\
_080565E6:\n\
	ldr r1, _0805662C @ =sSamusSetPoseFunctionPointer\n\
	ldrb r0, [r5]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	movs r0, #0x20\n\
	bl _call_via_r1\n\
	movs r1, #0x90\n\
	lsls r1, r1, #1\n\
	adds r0, r1, #0\n\
	ldrh r1, [r4, #2]\n\
	adds r0, r0, r1\n\
	strh r0, [r5, #0x18]\n\
	ldrh r0, [r4, #4]\n\
	strh r0, [r5, #0x16]\n\
	adds r1, r4, #0\n\
	adds r1, #0x24\n\
	movs r0, #0x37\n\
	strb r0, [r1]\n\
	adds r1, #0xa\n\
	movs r0, #0x1e\n\
	strb r0, [r1]\n\
	subs r1, #0xc\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	movs r0, #0x6d\n\
	bl EventCheckAdvance\n\
	b _08056638\n\
	.align 2, 0\n\
_08056624: .4byte gSamusData\n\
_08056628: .4byte 0x000002BF\n\
_0805662C: .4byte sSamusSetPoseFunctionPointer\n\
_08056630:\n\
	ldr r0, _08056640 @ =gCurrentSprite\n\
	adds r0, #0x22\n\
	movs r1, #0xc\n\
	strb r1, [r0]\n\
_08056638:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08056640: .4byte gCurrentSprite\n\
    .syntax divided\n");
}

/**
 * @brief 56644 | 28 | Handles the ending gunship locking Samus
 * 
 */
void GunshipEndLockingSamus(void)
{
    gCurrentSprite.work1--;

    if (gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x38;
        gCurrentSprite.work1 = 60 - 1;
    }
}

/**
 * @brief 5666c | 3c | Handles the ending gunship pulling Samus up
 * 
 */
void GunshipEndMovingSamusUp(void)
{
    gCurrentSprite.work1--;

    if (gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x39;
        gDisableDrawingSamusAndScrollingFlag = TRUE;
    }
    else
    {
        gSamusData.yPosition -= PIXEL_SIZE;
    }
}

// 0x080566A8
NAKED_FUNCTION
void GunshipEndStartingEngine1(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r4, _08056718 @ =gCurrentSprite\n\
	adds r6, r4, #0\n\
	adds r6, #0x31\n\
	ldrb r5, [r6]\n\
	bl SpriteUtilHasCurrentAnimationEnded\n\
	cmp r0, #0\n\
	beq _08056712\n\
	adds r1, r4, #0\n\
	adds r1, #0x24\n\
	movs r3, #0\n\
	movs r0, #0x3a\n\
	strb r0, [r1]\n\
	ldr r0, _0805671C @ =sBlob_39ab62_39f4b0 + 0x4106\n\
	str r0, [r4, #0x18]\n\
	strb r3, [r4, #0x1c]\n\
	movs r2, #0\n\
	strh r3, [r4, #0x16]\n\
	adds r1, #0xa\n\
	movs r0, #0x3c\n\
	strb r0, [r1]\n\
	adds r0, r4, #0\n\
	adds r0, #0x2f\n\
	strb r2, [r0]\n\
	strb r2, [r6]\n\
	ldrh r0, [r4]\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strh r0, [r4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r4, #0x12]\n\
	adds r0, r4, #0\n\
	adds r0, #0x2b\n\
	strb r2, [r0]\n\
	ldr r1, _08056720 @ =gSpriteData\n\
	lsls r0, r5, #3\n\
	subs r0, r0, r5\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r1\n\
	strh r3, [r0]\n\
	ldr r0, _08056724 @ =0x082F474E\n\
	ldr r1, _08056728 @ =0x040000D4\n\
	str r0, [r1]\n\
	ldr r0, _0805672C @ =0x05000336\n\
	str r0, [r1, #4]\n\
	ldr r0, _08056730 @ =0x80000005\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r0, _08056734 @ =0x0000024A\n\
	bl SoundPlay_3b1c\n\
_08056712:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08056718: .4byte gCurrentSprite\n\
_0805671C: .4byte sBlob_39ab62_39f4b0 + 0x4106\n\
_08056720: .4byte gSpriteData\n\
_08056724: .4byte 0x082F474E\n\
_08056728: .4byte 0x040000D4\n\
_0805672C: .4byte 0x05000336\n\
_08056730: .4byte 0x80000005\n\
_08056734: .4byte 0x0000024A\n\
    .syntax divided\n");
}

// 0x08056738
NAKED_FUNCTION
void GunshipEndStartingEngine2(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	ldr r2, _08056794 @ =gCurrentSprite\n\
	movs r0, #0x31\n\
	adds r0, r0, r2\n\
	mov ip, r0\n\
	ldrb r3, [r0]\n\
	ldr r5, _08056798 @ =sBlob_39ab62_39f4b0 + 0x62\n\
	lsls r0, r3, #1\n\
	adds r0, r0, r5\n\
	ldrh r4, [r0]\n\
	movs r6, #0\n\
	ldrsh r1, [r0, r6]\n\
	ldr r0, _0805679C @ =0x00007FFF\n\
	cmp r1, r0\n\
	bne _0805675A\n\
	ldrh r4, [r5]\n\
	movs r3, #0\n\
_0805675A:\n\
	adds r0, r3, #1\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	ldrh r0, [r2, #2]\n\
	adds r0, r0, r4\n\
	movs r4, #0\n\
	strh r0, [r2, #2]\n\
	adds r5, r2, #0\n\
	adds r5, #0x2f\n\
	ldrb r1, [r5]\n\
	cmp r1, #0\n\
	bne _080567A4\n\
	adds r3, r2, #0\n\
	adds r3, #0x2e\n\
	ldrb r0, [r3]\n\
	subs r0, #1\n\
	strb r0, [r3]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080567FE\n\
	ldr r0, _080567A0 @ =sBlob_39ab62_39f4b0 + 0x40A6\n\
	str r0, [r2, #0x18]\n\
	strb r4, [r2, #0x1c]\n\
	strh r1, [r2, #0x16]\n\
	movs r0, #0x3c\n\
	strb r0, [r3]\n\
	movs r0, #1\n\
	strb r0, [r5]\n\
	b _080567FE\n\
	.align 2, 0\n\
_08056794: .4byte gCurrentSprite\n\
_08056798: .4byte sBlob_39ab62_39f4b0 + 0x62\n\
_0805679C: .4byte 0x00007FFF\n\
_080567A0: .4byte sBlob_39ab62_39f4b0 + 0x40A6\n\
_080567A4:\n\
	cmp r1, #1\n\
	bne _080567D0\n\
	adds r3, r2, #0\n\
	adds r3, #0x2e\n\
	ldrb r0, [r3]\n\
	subs r0, #1\n\
	strb r0, [r3]\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	bne _080567FE\n\
	ldr r0, _080567CC @ =sBlob_39ab62_39f4b0 + 0x4116\n\
	str r0, [r2, #0x18]\n\
	strb r4, [r2, #0x1c]\n\
	strh r1, [r2, #0x16]\n\
	movs r0, #0x5a\n\
	strb r0, [r3]\n\
	movs r0, #2\n\
	strb r0, [r5]\n\
	b _080567FE\n\
	.align 2, 0\n\
_080567CC: .4byte sBlob_39ab62_39f4b0 + 0x4116\n\
_080567D0:\n\
	adds r3, r2, #0\n\
	adds r3, #0x2e\n\
	ldrb r0, [r3]\n\
	subs r0, #1\n\
	strb r0, [r3]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _080567FE\n\
	adds r1, r2, #0\n\
	adds r1, #0x24\n\
	movs r0, #0x3b\n\
	strb r0, [r1]\n\
	strb r4, [r3]\n\
	strb r4, [r5]\n\
	adds r0, r2, #0\n\
	adds r0, #0x30\n\
	strb r4, [r0]\n\
	ldrh r0, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #7\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
_080567FE:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x08056804
NAKED_FUNCTION
void GunshipEndTakingOff(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r1, _08056828 @ =gCurrentSprite\n\
	adds r3, r1, #0\n\
	adds r3, #0x2e\n\
	ldrb r2, [r3]\n\
	adds r0, r2, #0\n\
	cmp r0, #0x3f\n\
	bls _0805682C\n\
	ldrh r0, [r1, #2]\n\
	subs r0, #8\n\
	strh r0, [r1, #2]\n\
	adds r1, #0x24\n\
	movs r0, #0x3c\n\
	strb r0, [r1]\n\
	bl ColorFadingStartFinalEscape\n\
	b _0805685A\n\
	.align 2, 0\n\
_08056828: .4byte gCurrentSprite\n\
_0805682C:\n\
	cmp r0, #0x37\n\
	bls _0805683A\n\
	ldrh r0, [r1, #2]\n\
	subs r0, #8\n\
	strh r0, [r1, #2]\n\
	adds r0, r2, #4\n\
	b _08056858\n\
_0805683A:\n\
	cmp r0, #0x2f\n\
	bls _08056848\n\
	ldrh r0, [r1, #2]\n\
	subs r0, #2\n\
	strh r0, [r1, #2]\n\
	adds r0, r2, #4\n\
	b _08056858\n\
_08056848:\n\
	cmp r0, #0x1f\n\
	bls _08056856\n\
	ldrh r0, [r1, #2]\n\
	subs r0, #1\n\
	strh r0, [r1, #2]\n\
	adds r0, r2, #2\n\
	b _08056858\n\
_08056856:\n\
	adds r0, r2, #1\n\
_08056858:\n\
	strb r0, [r3]\n\
_0805685A:\n\
	ldr r3, _0805688C @ =gCurrentSprite\n\
	ldr r1, _08056890 @ =sBlob_39ab62_39f4b0 + 0x16E\n\
	adds r2, r3, #0\n\
	adds r2, #0x2e\n\
	ldrb r0, [r2]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	strh r0, [r3, #0x12]\n\
	ldrb r0, [r2]\n\
	cmp r0, #0x1f\n\
	bls _08056886\n\
	subs r0, #0x20\n\
	asrs r0, r0, #2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldr r1, _08056894 @ =sBlob_39ab62_39f4b0 + 0x122\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x2b\n\
	strb r1, [r0]\n\
_08056886:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0805688C: .4byte gCurrentSprite\n\
_08056890: .4byte sBlob_39ab62_39f4b0 + 0x16E\n\
_08056894: .4byte sBlob_39ab62_39f4b0 + 0x122\n\
    .syntax divided\n");
}

/**
 * @brief 56898 | 4 | Empty pose handler
 * 
 */
void GunshipEndDone(void)
{
    return;
}

/**
 * @brief 5689c | 74 | Handles the ending gunship bottom flashing
 * 
 */
void GunshipEndBottomIdle(void)
{
    u32 offset;
    const u16* pal;

    gCurrentSprite.work3++;

    if (MOD_AND(gCurrentSprite.work3, 8) != 0)
        return;

    offset = gCurrentSprite.work1 * 16;
    pal = &sGunshipFlashingPal[offset + 11];

    DMA3_COPY_16(pal, PALRAM_OBJ + 0x136, 5);

    if (gCurrentSprite.work2 != 0)
    {
        if (gCurrentSprite.work1 != 0)
        {
            gCurrentSprite.work1--;
        }
        else
        {
            gCurrentSprite.work2 = 0;
            gCurrentSprite.work1 = 1;
        }
    }
    else
    {
        if (gCurrentSprite.work1 > 5)
        {
            gCurrentSprite.work2 = 1;
            gCurrentSprite.work1 = 5;
        }
        else
        {
            gCurrentSprite.work1++;
        }
    }
}

// 0x08056910
NAKED_FUNCTION
void GunshiEndpBeamInit(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	ldr r0, _08056974 @ =gCurrentSprite\n\
	mov ip, r0\n\
	ldrh r1, [r0]\n\
	ldr r0, _08056978 @ =0x0000FFFB\n\
	ands r0, r1\n\
	movs r3, #0\n\
	movs r4, #0\n\
	mov r1, ip\n\
	strh r0, [r1]\n\
	mov r2, ip\n\
	adds r2, #0x34\n\
	ldrb r1, [r2]\n\
	movs r0, #1\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x25\n\
	strb r3, [r0]\n\
	adds r0, #2\n\
	movs r1, #4\n\
	strb r1, [r0]\n\
	adds r0, #1\n\
	strb r1, [r0]\n\
	subs r2, #0xb\n\
	movs r0, #0x10\n\
	strb r0, [r2]\n\
	ldr r0, _0805697C @ =0x0000FFFC\n\
	mov r2, ip\n\
	strh r0, [r2, #0xa]\n\
	strh r1, [r2, #0xc]\n\
	strh r0, [r2, #0xe]\n\
	strh r1, [r2, #0x10]\n\
	ldr r0, _08056980 @ =sBlob_39ab62_39f4b0 + 0x4056\n\
	str r0, [r2, #0x18]\n\
	strb r3, [r2, #0x1c]\n\
	strh r4, [r2, #0x16]\n\
	mov r1, ip\n\
	adds r1, #0x24\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	subs r1, #2\n\
	movs r0, #0xd\n\
	strb r0, [r1]\n\
	adds r1, #0xc\n\
	movs r0, #9\n\
	strb r0, [r1]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08056974: .4byte gCurrentSprite\n\
_08056978: .4byte 0x0000FFFB\n\
_0805697C: .4byte 0x0000FFFC\n\
_08056980: .4byte sBlob_39ab62_39f4b0 + 0x4056\n\
    .syntax divided\n");
}

// 0x08056984
NAKED_FUNCTION
void GunshipEndBeamMovingDown(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r1, _080569A4 @ =gCurrentSprite\n\
	adds r0, r1, #0\n\
	adds r0, #0x23\n\
	ldrb r3, [r0]\n\
	ldrb r0, [r1, #0x1e]\n\
	adds r2, r1, #0\n\
	cmp r0, #0\n\
	beq _080569A8\n\
	subs r0, #1\n\
	strb r0, [r2, #0x1e]\n\
	ldrh r0, [r2, #2]\n\
	adds r0, #4\n\
	strh r0, [r2, #2]\n\
	b _080569EA\n\
	.align 2, 0\n\
_080569A4: .4byte gCurrentSprite\n\
_080569A8:\n\
	adds r1, r2, #0\n\
	adds r1, #0x2e\n\
	ldrb r0, [r1]\n\
	subs r0, #1\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	cmp r0, #0\n\
	beq _080569C0\n\
	ldrh r0, [r2, #2]\n\
	adds r0, #4\n\
	strh r0, [r2, #2]\n\
	b _080569CA\n\
_080569C0:\n\
	ldrh r0, [r2, #2]\n\
	subs r0, #0x20\n\
	strh r0, [r2, #2]\n\
	movs r0, #9\n\
	strb r0, [r1]\n\
_080569CA:\n\
	ldr r0, _080569F0 @ =gSpriteData\n\
	lsls r1, r3, #3\n\
	subs r1, r1, r3\n\
	lsls r1, r1, #3\n\
	adds r1, r1, r0\n\
	adds r1, #0x24\n\
	ldrb r0, [r1]\n\
	cmp r0, #0x37\n\
	bne _080569EA\n\
	adds r1, r2, #0\n\
	adds r1, #0x24\n\
	movs r0, #0x18\n\
	strb r0, [r1]\n\
	subs r1, #2\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
_080569EA:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080569F0: .4byte gSpriteData\n\
    .syntax divided\n");
}

/**
 * @brief 569f4 | 54 | Handles the ending gunship beam moving up
 * 
 */
void GunshipEndBeamMovingUp(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.work1++;

    if (gCurrentSprite.work1 > 8)
    {
        gCurrentSprite.work1 = 0;
        gCurrentSprite.yPosition += HALF_BLOCK_SIZE;
    }
    else
    {
        gCurrentSprite.yPosition -= PIXEL_SIZE;
    }

    if (gSpriteData[ramSlot].pose == 0x39)
        gCurrentSprite.status = 0;
}

/**
 * @brief 56a48 | 168 | Gunship end AI
 * 
 */
void GunshipEnd(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GunshipEndInit();
            break;

        case 0x1:
            GunshipEndWaiting();
            break;

        case SPRITE_POSE_IDLE:
            GunshipEndMovingUp();
            break;

        case 0x17:
            GunshipEndWaitingToEnter();
            break;

        case 0x18:
            GunshipEndEntering();
            break;

        case 0x1A:
            GunshipEndWaitingForSamus();
            break;

        case 0x37:
            GunshipEndLockingSamus();
            break;

        case 0x38:
            GunshipEndMovingSamusUp();
            break;

        case 0x39:
            GunshipEndStartingEngine1();
            break;

        case 0x3A:
            GunshipEndStartingEngine2();
            break;

        case 0x3B:
            GunshipEndTakingOff();
            break;

        case 0x3C:
            GunshipEndDone();
    }
}

/**
 * @brief 56bb0 | 20 | Gunship end bottom AI
 * 
 */
void GunshipEndBottom(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.pose == SPRITE_POSE_IDLE)
        GunshipEndBottomIdle();
}

/**
 * @brief 56bd0 | 54 | Gunship end beam AI
 * 
 */
void GunshipEndBeam(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GunshiEndpBeamInit();

        case SPRITE_POSE_IDLE:
            GunshipEndBeamMovingDown();
            break;

        case 0x18:
            GunshipEndBeamMovingUp();
            break;
    }

    if (gCurrentSprite.roomSlot == 0 && gCurrentSprite.status == 0)
        SoundStop(0xFD);
}
