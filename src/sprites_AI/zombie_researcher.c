#include "sprites_AI/zombie_researcher.h"
#include "macros.h"
#include "globals.h"

#include "data/sprites/zombie_researcher.h"
#include "data/sprites/x_parasite.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/samus.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 220ec | 58 | Checks if samus is in range to lunge
 * 
 */
static void ZombieCheckSamusInRange(void)
{
    u32 nslr;

    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(PIXEL_TO_SUB_PIXEL(22.5), PIXEL_TO_SUB_PIXEL(32.5));

    if (nslr != NSLR_OUT_OF_RANGE)
    {
        // Check in front
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP) 
        {
            if (nslr == NSLR_LEFT)
                return;
        }
        else
        {
            if (nslr == NSLR_RIGHT)
                return;
        }
        gCurrentSprite.pose = ZOMBIE_POSE_LUNGING_START;

        gCurrentSprite.pOam = sZombieOam_StartLunging;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;
    }
}

/**
 * @brief 22144 | 34 | Sets a zombie to be waiting for a X to form
 * 
 */
static void ZombieSetWaitingToForm(void)
{
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = ZOMBIE_POSE_WAITING_TO_FORM;

    gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_TO_SUB_PIXEL(6);
    gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
}

/**
 * @brief 22178 | 1c | Sets the hitboxes when standing up
 * 
 */
static void ZombieSetStandingHitbox(void)
{
    gCurrentSprite.hitboxTop = -PIXEL_TO_SUB_PIXEL(0x1a);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -PIXEL_TO_SUB_PIXEL(6);
    gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(6);
}

/**
 * @brief 22194 | 34 | Initializes a zombie to be dead
 * 
 */
static void ZombieDyingInit(void)
{
    gCurrentSprite.pOam = sZombieOam_Dying;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;

    gCurrentSprite.work1 = 180;
    gCurrentSprite.pose = SPRITE_POSE_DYING;
}

/**
 * @brief 221c8 | 88 | Handles a zombie dying
 * 
 */
static void ZombieDying(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.work1 == 140)
    {
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition, 0);
    }

    if (--gCurrentSprite.work1 == 0) {
        gCurrentSprite.pOam = sZombieOam_TurningIntoBlob;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        ZombieSetWaitingToForm();

        gCurrentSprite.numberOfXToForm = 1;
        gCurrentSprite.paletteRow = 0;
    }
}

/**
 * @brief 22250 | dc | Initializes a zombie sprite
 * 
 */
static void ZombieInit(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED) {
        if (SPRITE_IS_INFECTED(gCurrentSprite))
        {
            gCurrentSprite.pOam = sZombieOam_Idle;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.pose = ZOMBIE_POSE_IDLE;
            ZombieSetStandingHitbox();
            gCurrentSprite.work1 = 0;
        }
        else
        {
            gCurrentSprite.pOam = sZombieOam_Blob;
            gCurrentSprite.properties |= SP_CAN_ABSORB_X;
            ZombieSetWaitingToForm();
        }
        SpriteUtilChooseRandomXFlip();
    }
    else
    {
        gCurrentSprite.pOam = sZombieOam_FormingFromBlob;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = ZOMBIE_POSE_FORMING;

        gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -PIXEL_TO_SUB_PIXEL(6);
        gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(6);

        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.drawDistanceTop = 0x20;
    gCurrentSprite.drawDistanceBottom = 0;
    gCurrentSprite.drawDistanceHorizontal = 0x10;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
}

/**
 * @brief 2232c | 130 | Handles a zombie waiting to form
 * 
 */
static void ZombieWaitingToForm(void)
{
    if (gCurrentSprite.pOam == sZombieOam_TurningIntoBlob)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sZombieOam_Blob;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.properties |= SP_CAN_ABSORB_X;
        }
    }
    else
    {
        SpriteUtilAlignYPositionOnSlopeAtOrigin();
        if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
        {
            // Falling
            gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
        }
        else if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            // On solid ground, not slope
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    // On ledge or downwards slope ahead
                    gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        // Hit wall or upwards slope
                        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
                    // Move very slowly
                    else if (gSpriteRandomNumber == 0 && (gFrameCounter16Bit & 1))
                        gCurrentSprite.xPosition += PIXEL_SIZE;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                    else if (gSpriteRandomNumber == 0 && (gFrameCounter16Bit & 1))
                        gCurrentSprite.xPosition -= PIXEL_SIZE;
                }
            }
        }
    }
}

/**
 * @brief 2245c | 7c | Handles a zombie forming
 * 
 */
static void ZombieForming(void)
{
    if (gCurrentSprite.currentAnimationFrame == 17 && gCurrentSprite.animationDurationCounter == 2)
    {
        gCurrentSprite.hitboxTop = -PIXEL_TO_SUB_PIXEL(0x1a);
    }
    else if (gCurrentSprite.currentAnimationFrame == 13 && gCurrentSprite.animationDurationCounter == 2)
    {
        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    }
    else if (gCurrentSprite.currentAnimationFrame == 7 && gCurrentSprite.animationDurationCounter == 3)
    {
        SpriteUtilMakeSpriteFaceSamusXFlip();
        SoundPlayNotAlreadyPlaying(SOUND_ZOMBIE_FORMING);
    }

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.hitboxLeft = -PIXEL_TO_SUB_PIXEL(6);
        gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(6);
        gCurrentSprite.pose = ZOMBIE_POSE_IDLE_INIT;
    }
}

/**
 * @brief 224d8 | 24 | Initializes a zombie to be idle
 * 
 */
static void ZombieIdleInit(void)
{
    gCurrentSprite.pOam = sZombieOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = ZOMBIE_POSE_IDLE;
    ZombieSetStandingHitbox();
}

/**
 * @brief 224fc | 3c | Handles a zombie being idle
 * 
 */
static void ZombieIdle(void)
{
    SpriteUtilAlignYPositionOnSlopeAtOrigin();
    if (gPreviousVerticalCollisionCheck == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
    }
    else
    {
        if (SpriteUtilHasCurrentAnimationNearlyEnded())
            gCurrentSprite.pose = ZOMBIE_POSE_MOVING_INIT;

        ZombieCheckSamusInRange();
    }
}

/**
 * @brief 22538 | 1c | Initializes a zombie to move
 * 
 */
static void ZombieMovingInit(void)
{
    gCurrentSprite.pOam = sZombieOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = ZOMBIE_POSE_MOVING;
}

/**
 * @brief 22554 | f8 | Handles a zombie moving
 * 
 */
static void ZombieMoving(void)
{
    // Check if falling
    SpriteUtilAlignYPositionOnSlopeAtOrigin();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
        else
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);

        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
            return;
        }
    }
    else if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // Check if on ledge
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
            if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
            {
                gCurrentSprite.pose = ZOMBIE_POSE_TURNING_INIT;
                return;
            }
            // Check if hit wall
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
            {
                gCurrentSprite.pose = ZOMBIE_POSE_TURNING_INIT;
                return;
            }
            gCurrentSprite.xPosition += PIXEL_SIZE / 4;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
            if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
            {
                gCurrentSprite.pose = ZOMBIE_POSE_TURNING_INIT;
                return;
            }
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
            {
                gCurrentSprite.pose = ZOMBIE_POSE_TURNING_INIT;
                return;
            }
            gCurrentSprite.xPosition -= PIXEL_SIZE / 4;
        }
    }
    ZombieCheckSamusInRange();
}

/**
 * @brief 2264c | 1c | Initializes a zombie to be turning around
 * 
 */
static void ZombieTurningInit(void)
{
    gCurrentSprite.pOam = sZombieOam_Turning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = ZOMBIE_POSE_TURNING;
}

/**
 * @brief 22668 | 2c | Handles a zombie turning around
 * 
 */
static void ZombieTurning(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = ZOMBIE_POSE_TURNING_END;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }
}

/**
 * @brief 22694 | 1c | Handles the end of a zombie turning around
 * 
 */
static void ZombieTurningEnd(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.pose = ZOMBIE_POSE_IDLE_INIT;
    }
}

/**
 * @brief 226b0 | 34 | Initializes a zombie to lunge
 * 
 */
static void ZombieLungingStart(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sZombieOam_Lunging;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = ZOMBIE_POSE_LUNGING;
        SoundPlayNotAlreadyPlaying(SOUND_ZOMBIE_LUNGE);
    }
}

/**
 * @brief 226e4 | 11c | Handles a zombie lunging
 * 
 */
static void ZombieLunging(void)
{
    s16 velocity;

    // Check if falling
    SpriteUtilAlignYPositionOnSlopeAtOrigin();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
        else
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);

        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
            return;
        }
    }
    else
    {
        velocity = sZombieLungingVelocity[gCurrentSprite.currentAnimationFrame];
        if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                // Check if on ledge
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    // Check if hit wall
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                        gCurrentSprite.xPosition += velocity;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                        gCurrentSprite.xPosition -= velocity;
                }
            }
        }
    }

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sZombieOam_EndLunging;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = ZOMBIE_POSE_LUNGING_END;
    }
}

/**
 * @brief 22800 | 1c | Handles the end of a zombie lunging
 * 
 */
static void ZombieLungingEnd(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.pose = ZOMBIE_POSE_IDLE_INIT;
    }
}

/**
 * @brief 2281c | 3c | Initializes a zombie to be falling
 * 
 */
static void ZombieFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.work4 = 0;

    if (!(gCurrentSprite.properties & SP_CAN_ABSORB_X))
    {
        gCurrentSprite.pOam = sZombieOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        ZombieSetStandingHitbox();
    }
}

/**
 * @brief 22858 | 88 | Handles a zombie falling
 * 
 */
static void ZombieFalling(void)
{
    u32 blockTop;
    u8 offset;
    s16 movement;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Touched the ground
        gCurrentSprite.yPosition = blockTop;
        if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
            gCurrentSprite.pose = ZOMBIE_POSE_WAITING_TO_FORM;
        else
            gCurrentSprite.pose = ZOMBIE_POSE_IDLE_INIT;
    }
    else
    {
        // Falling
        offset = gCurrentSprite.work4;
        movement = sSpritesFallingSpeed[offset];
        
        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed[offset - 1];
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

/**
 * @brief 228e0 | 21c | Zombie AI
 * 
 */
void Zombie(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_ZOMBIE_HURT);

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose) {
        case SPRITE_POSE_UNINITIALIZED:
            ZombieInit();
            break;

        case ZOMBIE_POSE_MOVING_INIT:
            ZombieMovingInit();

        case ZOMBIE_POSE_MOVING:
            ZombieMoving();
            break;

        case ZOMBIE_POSE_IDLE_INIT:
            ZombieIdleInit();

        case ZOMBIE_POSE_IDLE:
            ZombieIdle();
            break;

        case ZOMBIE_POSE_TURNING_INIT:
            ZombieTurningInit();

        case ZOMBIE_POSE_TURNING:
            ZombieTurning();
            break;

        case ZOMBIE_POSE_TURNING_END:
            ZombieTurningEnd();
            break;

        case ZOMBIE_POSE_WAITING_TO_FORM:
            ZombieWaitingToForm();
            break;

        case ZOMBIE_POSE_FORMING:
            ZombieForming();
            break;

        case ZOMBIE_POSE_LUNGING_START:
            ZombieLungingStart();
            break;

        case ZOMBIE_POSE_LUNGING:
            ZombieLunging();
            break;

        case ZOMBIE_POSE_LUNGING_END:
            ZombieLungingEnd();
            break;

        case SPRITE_POSE_FALLING_INIT:
            ZombieFallingInit();

        case SPRITE_POSE_FALLING:
            ZombieFalling();
            break;

        case SPRITE_POSE_DYING_INIT:
            ZombieDyingInit();

        case SPRITE_POSE_DYING:
            ZombieDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            ZombieInit();
            break;
    }
}
