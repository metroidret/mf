#include "data/sprites/kago.h"

#include "globals.h"

#include "data/generic_data.h"
#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

#define KAGO_POSE_IDLE_SHORT 2
#define KAGO_POSE_IDLE_TALL 0x18

#define KAGO_INSECT_POSE_JUMP_WARNING 2
#define KAGO_INSECT_POSE_JUMPING 0x18

void KagoSetCollision(u8 caa)
{
    u16 y;
    u16 x;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    SpriteUtilCheckCollisionAtPosition(y - BLOCK_TO_SUB_PIXEL(1.5f), x + BLOCK_TO_SUB_PIXEL(1.5f));
    if (gPreviousCollisionCheck == COLLISION_SOLID)
    {
        SpriteUtilCheckCollisionAtPosition(y - BLOCK_TO_SUB_PIXEL(1.5f), x - BLOCK_TO_SUB_PIXEL(1.5f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(1.5f), x + HALF_BLOCK_SIZE);
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(1.5f), x - HALF_BLOCK_SIZE);
        }
    }
}

void KagoPlaySound(void)
{
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        SoundPlayNotAlreadyPlaying(SOUND_KAGO_IDLE_SHORT);
        gCurrentSprite.work2 = 40;
    }
    else if (gCurrentSprite.work1 == 4)
    {
        SoundPlayNotAlreadyPlaying(SOUND_KAGO_IDLE_TALL_4);
        gCurrentSprite.work2 = 72;
    }
    else if (gCurrentSprite.work1 == 3)
    {
        SoundPlayNotAlreadyPlaying(SOUND_KAGO_IDLE_TALL_3);
        gCurrentSprite.work2 = 56;
    }
    else if (gCurrentSprite.work1 == 2)
    {
        SoundPlayNotAlreadyPlaying(SOUND_KAGO_IDLE_TALL_2);
        gCurrentSprite.work2 = 30;
    }
    else if (gCurrentSprite.work1 == 1)
    {
        SoundPlayNotAlreadyPlaying(SOUND_KAGO_IDLE_TALL_1);
        gCurrentSprite.work2 = 18;
    }
    else
    {
        SoundPlayNotAlreadyPlaying(SOUND_KAGO_IDLE_TALL_0);
        gCurrentSprite.work2 = 12;
    }
}

void KagoTurningIntoX(void)
{
    SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.4375f),
        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.1875f), SPRITE_STATUS_X_FLIP);
    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.4375f);
    gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.1875f);
}

void KagoInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_SOLID;
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
        gCurrentSprite.hitboxBottom = 16;
        gCurrentSprite.pOam = sKagoOam_IdleShort;
    }
    else
    {
        gCurrentSprite.properties &= ~SP_SOLID_FOR_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
        gCurrentSprite.frozenPaletteRowOffset = 1;
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(3.5f);
        gCurrentSprite.hitboxBottom = 0xc0;
        gCurrentSprite.pOam = sKagoOam_IdleTallVerySlow;
    }

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.work1 = 4;
    // BUG: work2 is uninitialized
    gCurrentSprite.work3 = FALSE;
    gCurrentSprite.work4 = 0;

    KagoPlaySound();

    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.875f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
        SoundPlayNotAlreadyPlaying(SOUND_KAGO_MUTATING);
    }
    else
    {
        gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
        if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
        {
            gCurrentSprite.pose = KAGO_POSE_IDLE_SHORT;
        }
        else
        {
            gCurrentSprite.pose = KAGO_POSE_IDLE_TALL;
            gCurrentSprite.yPosition -= BLOCK_SIZE * 3;
        }
    }
}

void KagoSpawningFromX(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    if (--gCurrentSprite.workY > 0)
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
        if (gCurrentSprite.workY < 24)
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.125f);
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
        gCurrentSprite.pose = KAGO_POSE_IDLE_TALL;
    }
}

void KagoIdleShort(void)
{
    if (--gCurrentSprite.work2 == 0)
        KagoPlaySound();
}

void KagoIdleTall(void)
{
    if (--gCurrentSprite.work2 == 0)
        KagoPlaySound();
}

void KagoDyingInit(void)
{
    if (gCurrentSprite.work3)
        KagoSetCollision(CAA_REMOVE_SOLID);

    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.pose = SPRITE_POSE_DYING;
    gCurrentSprite.work1 = X_PARASITE_MOSAIC_MAX_INDEX;

    SoundPlayNotAlreadyPlaying(SOUND_SPRITE_TRANSFORMING_INTO_X);
    SpriteDying();
}

void KagoInsectExplodingInit(void)
{
    gCurrentSprite.pOam = sKagoInsectOam_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_EXPLODING;
    gCurrentSprite.samusCollision = SSC_NONE;
    SoundPlayNotAlreadyPlaying(SOUND_KAGO_INSECT_EXPLODING);
}

void KagoInsectExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

void KagoInsectInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.pOam = sKagoInsectOam_Midair;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.hitboxBottom = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.3125f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.3125f);
    gCurrentSprite.pose = 0x18;
    gCurrentSprite.work3 = DIV_SHIFT(gSpriteRandomNumber, 4) + 5;
    gCurrentSprite.work4 = 0;

    if (gSpriteRandomNumber >= 8)
        gCurrentSprite.work2 = TRUE;
    else
        gCurrentSprite.work2 = FALSE;

    SpriteUtilChooseRandomXFlip();
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.workY = 20;
}

void KagoInsectJumpWarningInit(void)
{
    gCurrentSprite.pose = KAGO_INSECT_POSE_JUMP_WARNING;
    gCurrentSprite.pOam = sKagoInsectOam_JumpWarning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void KagoInsectJumpingInit(void)
{
    gCurrentSprite.pose = KAGO_INSECT_POSE_JUMPING;
    gCurrentSprite.pOam = sKagoInsectOam_Midair;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work3 = 5;
    gCurrentSprite.work4 = 0;

    if (MOD_AND(gSpriteRandomNumber, 2))
        gCurrentSprite.work2 = TRUE;
    else
        gCurrentSprite.work2 = FALSE;

    if (gCurrentSprite.xPosition > gSamusData.xPosition)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.work3 = 0;
    }
    else
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_X_FLIP))
            gCurrentSprite.work3 = 0;
    }

    SoundPlayNotAlreadyPlaying(SOUND_KAGO_INSECT_JUMPING);
}

void KagoInsectFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.pOam = sKagoInsectOam_Midair;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work4 = 0;
}

void KagoInsectJumpWarning(void)
{
    if (gCurrentSprite.health == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
        return;
    }

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            KagoInsectFallingInit();
            return;
        }
    }

    if (SpriteUtilHasCurrentAnimationEnded())
        KagoInsectJumpingInit();
}

void KagoInsectJumping(void)
{
    s16 xMovement;
    s16 yMovement;
    u32 blockTop;
    u8 collision;

    if (gCurrentSprite.health == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
        return;
    }

    collision = FALSE;
    xMovement = gCurrentSprite.work3;

    if (xMovement == 0)
    {
        if (gCurrentSprite.work4 == 16)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.pOam = sKagoInsectOam_TurningAround;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
        else if (gCurrentSprite.work4 == 22)
        {
            gCurrentSprite.pOam = sKagoInsectOam_Midair;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
        yMovement = sKagoInsectLowJumpVelocity[gCurrentSprite.work4 / 4];
    }
    else
    {
        yMovement = sKagoInsectMediumJumpVelocity[gCurrentSprite.work4 / 4];
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRight + BLOCK_TO_SUB_PIXEL(0.0625));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.0625);
                gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pOam = sKagoInsectOam_TurningAround;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            else
            {
                if (yMovement > 0)
                    gCurrentSprite.xPosition += xMovement - BLOCK_TO_SUB_PIXEL(0.046875f);
                else
                    gCurrentSprite.xPosition += xMovement;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft - BLOCK_TO_SUB_PIXEL(0.0625));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.0625);
                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pOam = sKagoInsectOam_TurningAround;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            else
            {
                if (yMovement > 0)
                    gCurrentSprite.xPosition -= xMovement - BLOCK_TO_SUB_PIXEL(0.046875f);
                else
                    gCurrentSprite.xPosition -= xMovement;
            }
        }
    }

    gCurrentSprite.yPosition += yMovement;
    if (gCurrentSprite.work4 < ARRAY_SIZE(sKagoInsectLowJumpVelocity) * 4 - 1)
        gCurrentSprite.work4++;

    if (yMovement > 0)
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = blockTop;
            KagoInsectJumpWarningInit();
        }
        else if (!collision)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                collision = TRUE;
            }
            else
            {
                blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
                if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                    collision = TRUE;
            }

            if (collision)
            {
                gCurrentSprite.yPosition = blockTop;
                KagoInsectJumpWarningInit();
            }
        }
    }
    else
    {
        collision = FALSE;
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collision = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                collision = TRUE;
        }

        if (collision)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.0625);
            else
                gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.0625);

            KagoInsectFallingInit();
        }
    }
}

void KagoInsectFalling(void)
{
    u8 collision;
    u8 offset;
    s16 movement;
    u32 blockTop;

    if (gCurrentSprite.health == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
        return;
    }

    collision = FALSE;
    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        collision++;
    }
    else
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            collision++;
        }
        else
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                collision++;
        }
    }

    if (collision)
    {
        gCurrentSprite.yPosition = blockTop;
        KagoInsectJumpWarningInit();
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sSpritesFallingSpeedQuickAcceleration[offset];
        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeedQuickAcceleration[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
            gCurrentSprite.yPosition += movement;
        }
    }
}

void Kago(void)
{
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.875f);
        if (SPRITE_GET_ISFT(gCurrentSprite) == 1)
            SoundPlayNotAlreadyPlaying(SOUND_KAGO_HIT_SHORT);
    }
    else
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.125f);
        if (gCurrentSprite.work4 > 0)
        {
            if (--gCurrentSprite.work4 == 0)
                gCurrentSprite.pOam = sKagoOam_IdleTallVerySlow;
        }
        else if (SPRITE_GET_ISFT(gCurrentSprite) == 1 && gCurrentSprite.pOam == sKagoOam_IdleTallVerySlow)
        {
            gCurrentSprite.pOam = sKagoOam_IdleTallFast;
            gCurrentSprite.work4 = 60;
        }
    }

    if (gCurrentSprite.freezeTimer > 0)
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.875f);
        if (!gCurrentSprite.work3 && gCurrentSprite.pose == KAGO_POSE_IDLE_TALL)
        {
            gCurrentSprite.work3 = TRUE;
            KagoSetCollision(CAA_MAKE_SOLID);
        }

        SpriteUtilUpdateFreezeTimer();
        if (gCurrentSprite.freezeTimer == 0 && gCurrentSprite.work3 && gCurrentSprite.pose == KAGO_POSE_IDLE_TALL)
        {
            gCurrentSprite.work3 = FALSE;
            KagoSetCollision(CAA_REMOVE_SOLID);
        }

        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            KagoInit();
            break;

        case KAGO_POSE_IDLE_SHORT:
            KagoIdleShort();
            break;

        case KAGO_POSE_IDLE_TALL:
            KagoIdleTall();
            break;

        case SPRITE_POSE_DYING_INIT:
            KagoDyingInit();
            break;

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            KagoInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            KagoSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            KagoTurningIntoX();
            XParasiteInit();
            break;
    }

    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
        unk_120ac(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.46875f), gCurrentSprite.xPosition);
}

void KagoInsect(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            KagoInsectInit();
            break;

        case KAGO_INSECT_POSE_JUMP_WARNING:
            KagoInsectJumpWarning();
            break;

        case KAGO_INSECT_POSE_JUMPING:
            KagoInsectJumping();
            break;

        case SPRITE_POSE_FALLING:
            KagoInsectFalling();
            break;

        case SPRITE_POSE_STOPPED:
            KagoInsectExplodingInit();

        case SPRITE_POSE_EXPLODING:
            KagoInsectExploding();
            break;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_IGNORE_PROJECTILES && gCurrentSprite.workY > 0)
    {
        if (--gCurrentSprite.workY == 0)
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
}
