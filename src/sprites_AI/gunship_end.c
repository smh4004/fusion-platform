#include "sprites_AI/gunship.h"
#include "globals.h"
#include "macros.h"
#include "music_wrappers.h"
#include "audio_wrappers.h"
#include "color_fading.h"
#include "sprite_util.h"
#include "event_checks.h"

#include "data/samus_data.h"

#include "data/sprites/gunship.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/samus.h"
#include "structs/sprite.h"

// sprite.h is deliberately not included: the original code called
// SpriteSpawnSecondary without a prototype, so its u16 arguments are passed
// without being narrowed. Including it changes GunshipEndSpawnBeams and
// GunshipEndEntering.

/**
 * @brief 56140 | 138 | Spawns the ending gunship's beams
 * 
 */
void GunshipEndSpawnBeams(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 4 + HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition;

    switch (gCurrentSprite.work2)
    {
        case 6:
            SpriteSpawnSecondary(SSPRITE_GUNSHIP_END_BEAM, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                yPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE - PIXEL_SIZE), xPosition, 0);
            SoundPlay(0xFD);
            break;

        case 9:
            SpriteSpawnSecondary(SSPRITE_GUNSHIP_END_BEAM, 1, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                yPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE), xPosition, 0);
            break;

        case 12:
            SpriteSpawnSecondary(SSPRITE_GUNSHIP_END_BEAM, 3, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                yPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), xPosition, 0);
            break;

        case 15:
            SpriteSpawnSecondary(SSPRITE_GUNSHIP_END_BEAM, 5, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                yPosition - BLOCK_SIZE * 2, xPosition, 0);
            break;

        case 18:
            SpriteSpawnSecondary(SSPRITE_GUNSHIP_END_BEAM, 7, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), xPosition, 0);
            break;

        case 21:
            SpriteSpawnSecondary(SSPRITE_GUNSHIP_END_BEAM, 9, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                yPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE), xPosition, 0);
            break;
    }
}

/**
 * @brief 56278 | 8c | Initializes the ending gunship
 * 
 */
void GunshipEndInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.bgPriority = 3;
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_WHOLE;

    gCurrentSprite.scaling = Q_8_8(.5625f);
    gCurrentSprite.rotation = 0;

    gCurrentSprite.work4 = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work1 = 60;

    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = 0x7F;
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(4);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(11);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.pose = 0x1;

    gCurrentSprite.pOam = sGunshipEndOam_39ec68;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
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

/**
 * @brief 56338 | b0 | Handles the ending gunship flying to the middle of the screen
 * 
 */
void GunshipEndMovingUp(void)
{
    u8 inPlace;
    u16 distance;

    if (gCurrentSprite.work1 != 0)
    {
        gCurrentSprite.work1--;

        if (gCurrentSprite.work1 == 0)
            SoundPlay_3b1c(0x249);
    }

    inPlace = 0;

    // Move towards the middle of the screen
    distance = SUB_PIXEL_TO_PIXEL(gCurrentSprite.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);

    if (distance < 112)
        gCurrentSprite.xPosition++;
    else if (distance > 128)
        gCurrentSprite.xPosition--;
    else
        inPlace = 1;

    distance = SUB_PIXEL_TO_PIXEL(gCurrentSprite.yPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition);

    if (distance < 44)
        gCurrentSprite.yPosition++;
    else if (distance > 60)
        gCurrentSprite.yPosition--;
    else
        inPlace++;

    if (inPlace > 1)
    {
        gCurrentSprite.bgPriority = 2;
        gCurrentSprite.pose = 0x17;
        gCurrentSprite.work1 = 60;
        gCurrentSprite.work4 = 0;
        gCurrentSprite.work3 = 0;
    }
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

/**
 * @brief 56444 | 158 | Handles the ending gunship descending into the hangar
 * 
 */
void GunshipEndEntering(void)
{
    u8 offset;
    s16 movement;
    u8 bottomSlot;

    offset = gCurrentSprite.work4;
    movement = sGunshipEndEnteringYMovement[offset];

    if (movement == SHORT_MAX)
    {
        movement = sGunshipEndEnteringYMovement[0];
        offset = 0;
    }

    gCurrentSprite.work4 = offset + 1;
    gCurrentSprite.yPosition += movement;

    // Grow from far away to full size while descending
    gCurrentSprite.scaling = sGunshipEnd_39ac90[DIV_SHIFT(gCurrentSprite.work1, 4)];

    if (gCurrentSprite.work1 < 112)
    {
        gCurrentSprite.work1++;

        if (MOD_AND(gCurrentSprite.work1, 2))
            gCurrentSprite.yPosition++;

        return;
    }

    gCurrentSprite.status &= ~SPRITE_STATUS_ROTATION_SCALING_WHOLE;
    gCurrentSprite.pose = 0x1A;

    gCurrentSprite.pOam = sGunshipEndOam_39eb48;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.work2 = 0;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    bottomSlot = SpriteSpawnSecondary(SSPRITE_7A, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    gCurrentSprite.work4 = bottomSlot;

    gSpriteData[bottomSlot].status &= ~SPRITE_STATUS_NOT_DRAWN;

    gSpriteData[bottomSlot].pOam = sGunshipEndOam_39ec30;
    gSpriteData[bottomSlot].animationDurationCounter = 0;
    gSpriteData[bottomSlot].currentAnimationFrame = 0;

    gSpriteData[bottomSlot].properties |= SP_ALWAYS_ACTIVE;
    gSpriteData[bottomSlot].drawOrder = 14;
    gSpriteData[bottomSlot].samusCollision = SSC_NONE;

    gSpriteData[bottomSlot].drawDistanceTop = BLOCK_TO_PIXEL(.25f);
    gSpriteData[bottomSlot].drawDistanceBottom = BLOCK_TO_PIXEL(3.5f);
    gSpriteData[bottomSlot].drawDistanceHorizontal = BLOCK_TO_PIXEL(3);

    gSpriteData[bottomSlot].hitboxTop = -PIXEL_SIZE;
    gSpriteData[bottomSlot].hitboxBottom = PIXEL_SIZE;
    gSpriteData[bottomSlot].hitboxLeft = -PIXEL_SIZE;
    gSpriteData[bottomSlot].hitboxRight = PIXEL_SIZE;

    gSpriteData[bottomSlot].pose = SPRITE_POSE_IDLE;
    gSpriteData[bottomSlot].work1 = 0;
    gSpriteData[bottomSlot].work2 = 0;
    gSpriteData[bottomSlot].work3 = 0;
}

/**
 * @brief 5659c | a8 | Handles the ending gunship waiting for Samus to board
 * 
 */
void GunshipEndWaitingForSamus(void)
{
    if (gCurrentSprite.work2 <= 35)
    {
        gCurrentSprite.work2++;
        GunshipEndSpawnBeams();
        return;
    }

    if (gCurrentSprite.xPosition - HALF_BLOCK_SIZE < gSamusData.xPosition &&
        gCurrentSprite.xPosition + HALF_BLOCK_SIZE > gSamusData.xPosition &&
        gSamusData.yPosition == BLOCK_SIZE * 11 - ONE_SUB_PIXEL && !SpriteUtilCheckSamusMorphed())
    {
        if (gSamusData.invincibilityTimer != 0)
            gSamusData.invincibilityTimer = 0;

        SAMUS_SET_POSE(SPOSE_ON_SAVE_PAD);

        gSamusData.yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 4 + HALF_BLOCK_SIZE;
        gSamusData.xPosition = gCurrentSprite.xPosition;

        gCurrentSprite.pose = 0x37;
        gCurrentSprite.work1 = 30;
        gCurrentSprite.drawOrder = 4;

        EventCheckAdvance(EVENT_ESCAPED_ON_SHIP);
        return;
    }

    gCurrentSprite.drawOrder = 12;
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

/**
 * @brief 566a8 | 90 | Handles the ending gunship's engine starting (part 1)
 * 
 */
void GunshipEndStartingEngine1(void)
{
    u8 bottomSlot;
    const u16* pal;

    bottomSlot = gCurrentSprite.work4;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x3A;

        gCurrentSprite.pOam = sGunshipEndOam_39ec68;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.work1 = 60;
        gCurrentSprite.work2 = 0;
        gCurrentSprite.work4 = 0;

        gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_WHOLE;
        gCurrentSprite.scaling = Q_8_8(1);
        gCurrentSprite.rotation = 0;

        gSpriteData[bottomSlot].status = 0;

        pal = &sGunshipFlashingPal[11];
        DMA3_COPY_16(pal, PALRAM_OBJ + 0x136, 5);
        SoundPlay_3b1c(0x24A);
    }
}

/**
 * @brief 56738 | cc | Handles the ending gunship's engine starting (part 2)
 * 
 */
void GunshipEndStartingEngine2(void)
{
    u8 offset;
    s16 movement;

    offset = gCurrentSprite.work4;
    movement = sGunshipEnd_39abc4[offset];

    if (movement == SHORT_MAX)
    {
        movement = sGunshipEnd_39abc4[0];
        offset = 0;
    }

    gCurrentSprite.work4 = offset + 1;
    gCurrentSprite.yPosition += movement;

    if (gCurrentSprite.work2 == 0)
    {
        gCurrentSprite.work1--;

        if (gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.pOam = sGunshipEndOam_39ec08;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.work1 = 60;
            gCurrentSprite.work2 = 1;
        }
    }
    else if (gCurrentSprite.work2 == 1)
    {
        gCurrentSprite.work1--;

        if (gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.pOam = sGunshipEndOam_39ec78;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.work1 = 90;
            gCurrentSprite.work2 = 2;
        }
    }
    else
    {
        gCurrentSprite.work1--;

        if (gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.pose = 0x3B;
            gCurrentSprite.work1 = 0;
            gCurrentSprite.work2 = 0;
            gCurrentSprite.work3 = 0;
            gCurrentSprite.status |= SPRITE_STATUS_DOUBLE_SIZE;
        }
    }
}

/**
 * @brief 56804 | 94 | Handles the ending gunship taking off
 * 
 */
void GunshipEndTakingOff(void)
{
    u8 offset;

    if (gCurrentSprite.work1 >= 64)
    {
        gCurrentSprite.yPosition -= EIGHTH_BLOCK_SIZE;
        gCurrentSprite.pose = 0x3C;
        ColorFadingStartFinalEscape();
    }
    else if (gCurrentSprite.work1 >= 56)
    {
        gCurrentSprite.yPosition -= EIGHTH_BLOCK_SIZE;
        gCurrentSprite.work1 += 4;
    }
    else if (gCurrentSprite.work1 >= 48)
    {
        gCurrentSprite.yPosition -= ONE_SUB_PIXEL * 2;
        gCurrentSprite.work1 += 4;
    }
    else if (gCurrentSprite.work1 >= 32)
    {
        gCurrentSprite.yPosition -= ONE_SUB_PIXEL;
        gCurrentSprite.work1 += 2;
    }
    else
    {
        gCurrentSprite.work1++;
    }

    gCurrentSprite.scaling = sGunshipEndTakingOffScaling[gCurrentSprite.work1];

    if (gCurrentSprite.work1 >= 32)
    {
        offset = DIV_SHIFT(gCurrentSprite.work1 - 32, 4);
        gCurrentSprite.rotation = sGunshipEndTakingOffRotation[offset];
    }
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

/**
 * @brief 56910 | 74 | Initializes an ending gunship beam
 * 
 */
void GunshiEndpBeamInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.25f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.25f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.pOam = sGunshipEndOam_39ebb8;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.drawOrder = 13;
    gCurrentSprite.work1 = 9;
}

/**
 * @brief 56984 | 70 | Handles an ending gunship beam moving down
 * 
 */
void GunshipEndBeamMovingDown(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.roomSlot != 0)
    {
        // Room slot is reused as a delay before the beam starts cycling
        gCurrentSprite.roomSlot--;
        gCurrentSprite.yPosition += PIXEL_SIZE;
        return;
    }

    gCurrentSprite.work1--;

    if (gCurrentSprite.work1 != 0)
    {
        gCurrentSprite.yPosition += PIXEL_SIZE;
    }
    else
    {
        gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
        gCurrentSprite.work1 = 9;
    }

    if (gSpriteData[ramSlot].pose == 0x37)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.drawOrder = 5;
    }
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
