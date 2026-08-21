#include "data/sprites/geruta.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"

#include "structs/samus.h"
#include "structs/sprite.h"

#define SS_GERUTA_FACING_DOWN SPRITE_STATUS_SAMUS_COLLIDING

#define GERUTA_IDLE_UPWARD_MOVEMENT_OFFSET 36

enum GerutaPose {
    GERUTA_POSE_TURNING_AROUND_INIT = 3,
    GERUTA_POSE_TURNING_AROUND = 4,
    GERUTA_POSE_ATTACK_WARNING_INIT = 0x29,
    GERUTA_POSE_ATTACK_WARNING = 0x2a,
    GERUTA_POSE_ATTACKING = 0x2c,
};

u8 GerutaYMovement(u16 movement)
{
    if (gCurrentSprite.status & SS_GERUTA_FACING_DOWN)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.yPosition += movement;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.yPosition -= movement;
    }

    return FALSE;
}

u8 GerutaXMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
            gCurrentSprite.xPosition + BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE,
            gCurrentSprite.xPosition + BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition += movement;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
            gCurrentSprite.xPosition - BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE,
            gCurrentSprite.xPosition - BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition -= movement;
    }

    return FALSE;
}

void GerutaSetIdleHitboxes(void)
{
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.0f);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    }
}

void GerutaSetAttackingHitboxes(void)
{
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.625f);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.25f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.25f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    }
}

void GerutaUpdateLungingAnimation(void)
{
    if ((u8)SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(3.5f), BLOCK_TO_SUB_PIXEL(3.0f)) !=
        NSLR_OUT_OF_RANGE)
    {
        // Samus is near, set swiping animation
        if (gCurrentSprite.pOam != sGerutaOam_Swiping)
        {
            gCurrentSprite.pOam = sGerutaOam_Swiping;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
        else
        {
            // Play swiping sound on a specific frame
            if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 4)
                SoundPlayNotAlreadyPlaying(SOUND_GERUTA_SWIPING);
        }
    }
    else if (gCurrentSprite.pOam == sGerutaOam_Swiping)
    {
        // Samus is not near
        // Play swiping sound on a specific frame
        if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 4)
            SoundPlayNotAlreadyPlaying(SOUND_GERUTA_SWIPING);

        // Wait for swiping animation to end and set lunging animation
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sGerutaOam_Lunging;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
}

void GerutaInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    SpriteUtilMakeSpriteFaceSamusXFlip();

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);

    GerutaSetIdleHitboxes();

    gCurrentSprite.pOam = sGerutaOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }
}

void GerutaIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGerutaOam_Idle;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work4 = 0;
}

void GerutaIdle(void)
{
    u8 offset;
    s16 movement;
    u8 nslr;
    u16 target;
    u16 tmp;
    u16 distance;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    // Touch floor check
    if (gCurrentSprite.work4 < GERUTA_IDLE_UPWARD_MOVEMENT_OFFSET)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            gCurrentSprite.work4 = GERUTA_IDLE_UPWARD_MOVEMENT_OFFSET;
    }

    // Update Y position
    offset = gCurrentSprite.work4;
    movement = sGerutaIdleYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sGerutaIdleYMovement[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work4 = offset;
    gCurrentSprite.yPosition += movement;

    // Update X position, turn around if hit wall
    if (GerutaXMovement(BLOCK_TO_SUB_PIXEL(0.015625f)))
    {
        gCurrentSprite.pose = GERUTA_POSE_TURNING_AROUND_INIT;
        return;
    }

    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(6), BLOCK_TO_SUB_PIXEL(6));
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (nslr != NSLR_RIGHT)
            nslr = NSLR_OUT_OF_RANGE;
    }
    else
    {
        if (nslr != NSLR_LEFT)
            nslr = NSLR_OUT_OF_RANGE;
    }

    if (nslr != NSLR_OUT_OF_RANGE)
    {
        // Geruta sees Samus
        gCurrentSprite.status &= ~SS_GERUTA_FACING_DOWN;
        target = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.125f);
        tmp = gCurrentSprite.yPosition;
        if (target > tmp + BLOCK_TO_SUB_PIXEL(1.5625f))
        {
            // Samus is below the geruta, it can't see through the floor
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                if (gCurrentSprite.work4 > 61)
                    gCurrentSprite.pose = GERUTA_POSE_TURNING_AROUND_INIT;

                return;
            }
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE),
                gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                if (gCurrentSprite.work4 > 61)
                    gCurrentSprite.pose = GERUTA_POSE_TURNING_AROUND_INIT;

                return;
            }

            gCurrentSprite.work2 = 0;
            gCurrentSprite.status |= SS_GERUTA_FACING_DOWN;
        }
        else if (target < tmp - BLOCK_TO_SUB_PIXEL(1.5625f))
        {
            // Samus is above the geruta, it can't see through the ceiling
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                if (gCurrentSprite.work4 > 61)
                    gCurrentSprite.pose = GERUTA_POSE_TURNING_AROUND_INIT;

                return;
            }
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                if (gCurrentSprite.work4 > 61)
                    gCurrentSprite.pose = GERUTA_POSE_TURNING_AROUND_INIT;

                return;
            }
            gCurrentSprite.work2 = 1;
        }
        else
        {
            // Samus is in the same level as the geruta
            gCurrentSprite.work2 = 2;
        }

        gCurrentSprite.workY = tmp;
        gCurrentSprite.workX = target;

        // Distance between Samus and geruta
        target = gSamusData.xPosition;
        tmp = gCurrentSprite.xPosition;
        SET_ABS_SUB(tmp, tmp, target);

        // Set lunging speed when lunging diagonally depending on how far Samus is
        if (tmp > BLOCK_TO_SUB_PIXEL(4.6875f))
            gCurrentSprite.work3 = BLOCK_TO_SUB_PIXEL(0.125f);
        else if (tmp > BLOCK_TO_SUB_PIXEL(2.5f))
            gCurrentSprite.work3 = BLOCK_TO_SUB_PIXEL(0.09375f);
        else
            gCurrentSprite.work3 = BLOCK_TO_SUB_PIXEL(0.0625f);

        gCurrentSprite.pose = GERUTA_POSE_ATTACK_WARNING_INIT;
    }
    else
    {
        // Geruta doesn't see Samus
        if (gCurrentSprite.work4 > 61)
            gCurrentSprite.pose = GERUTA_POSE_TURNING_AROUND_INIT;
    }
}

void GerutaTurningAroundInit(void)
{
    gCurrentSprite.pose = GERUTA_POSE_TURNING_AROUND;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGerutaOam_TurningAround;
}

void GerutaTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        // BUG: Hitbox isn't updated after turning around
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
#ifdef BUGFIX
        GerutaSetIdleHitboxes();
#endif // BUGFIX
    }
}

void GerutaAttackWarningInit(void)
{
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGerutaOam_AttackWarning;
    gCurrentSprite.pose = GERUTA_POSE_ATTACK_WARNING;

    GerutaSetAttackingHitboxes();
}

void GerutaAttackWarning(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerutaOam_Lunging;
        gCurrentSprite.pose = GERUTA_POSE_ATTACKING;
        gCurrentSprite.work1 = 3 * 60;
    }
}

void GerutaAttacking(void)
{
    u8 stopAttack;

    GerutaUpdateLungingAnimation();
    stopAttack = FALSE;

    if (gCurrentSprite.work2 == 0)
    {
        // Lunging diagonally downwards/upwards
        if (GerutaXMovement(gCurrentSprite.work3))
            stopAttack++;

        if (gCurrentSprite.status & SS_GERUTA_FACING_DOWN)
        {
            // Lunge upwards if Samus is above
            if (gCurrentSprite.yPosition >= gCurrentSprite.workX)
                gCurrentSprite.status &= ~SS_GERUTA_FACING_DOWN;
        }
        else
        {
            // Stop lunging if it's above where it started lunging
            if (gCurrentSprite.yPosition <= gCurrentSprite.workY)
                stopAttack++;
        }

        if (GerutaYMovement(BLOCK_TO_SUB_PIXEL(0.0625f)))
            stopAttack++;
    }
    else if (gCurrentSprite.work2 == 1)
    {
        // Lunging diagonally upwards
        if (GerutaXMovement(gCurrentSprite.work3))
            stopAttack++;
        if (gCurrentSprite.yPosition <= gCurrentSprite.workX)
            stopAttack++;
        if (GerutaYMovement(BLOCK_TO_SUB_PIXEL(0.0625f)))
            stopAttack++;
    }
    else
    {
        // Lunging straight
        if (GerutaXMovement(BLOCK_TO_SUB_PIXEL(0.125f)))
            stopAttack++;
    }

    // Stop lunging after 3 seconds of lunging
    if (--gCurrentSprite.work1 == 0)
        stopAttack++;

    if (stopAttack)
    {
        // Turn if facing away from Samus
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gCurrentSprite.xPosition > gSamusData.xPosition)
                gCurrentSprite.pose = GERUTA_POSE_TURNING_AROUND_INIT;
            else
                gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
        }
        else
        {
            if (gCurrentSprite.xPosition < gSamusData.xPosition)
                gCurrentSprite.pose = GERUTA_POSE_TURNING_AROUND_INIT;
            else
                gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
        }

        GerutaSetIdleHitboxes();
    }
}

void Geruta(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_GERUTA_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GerutaInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            GerutaIdleInit();
        case SPRITE_POSE_IDLE:
            GerutaIdle();
            break;

        case GERUTA_POSE_TURNING_AROUND_INIT:
            GerutaTurningAroundInit();
        case GERUTA_POSE_TURNING_AROUND:
            GerutaTurningAround();
            break;

        case GERUTA_POSE_ATTACK_WARNING_INIT:
            GerutaAttackWarningInit();
        case GERUTA_POSE_ATTACK_WARNING:
            GerutaAttackWarning();
            break;

        case GERUTA_POSE_ATTACKING:
            GerutaAttacking();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            GerutaInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            break;
    }
}
