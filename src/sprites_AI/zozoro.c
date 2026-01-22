#include "sprites_AI/zozoro.h"

#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"
#include "data/sprites/zozoro.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/sprite.h"

#define ZOZORO_LOOKAHEAD_DISTANCE BLOCK_TO_SUB_PIXEL(0.75f)

enum ZozoroPose {
    ZOZORO_POSE_TURNING_AROUND_INIT = 3,
    ZOZORO_POSE_TURNING_AROUND = 4,
};

/**
 * @brief 4fd44 | a0 | Checks if a zozoro is colliding with air
 *
 * @return u8 bool, in air
 */
static boolu8 ZozoroCheckCollidingWithAir(void)
{
    boolu8 midair = FALSE;

    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    midair = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    midair = TRUE;
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    midair = TRUE;
            }
        }
    }

    return midair;
}

/**
 * @brief 4fde4 | 90 | Updates the hitbox of a zozoro
 *
 */
static void ZozoroUpdateHitbox(void)
{
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.625f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.625f);
        }
    }

    gCurrentSprite.drawDistanceTop = 24;
    gCurrentSprite.drawDistanceBottom = 24;
    gCurrentSprite.drawDistanceHorizontal = 24;
}

/**
 * @brief 4fe74 | 30 | Sets the crawling oam for a zozoro
 *

 */
static void ZozoroSetCrawlingOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sZozoroOam_CrawlingWall;
    else
        gCurrentSprite.pOam = sZozoroOam_CrawlingGround;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 4fea4 | 30 | Sets the turning around oam for a zozoro
 *

 */
static void ZozoroSetTurningAroundOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sZozoroOam_TurningAroundWall;
    else
        gCurrentSprite.pOam = sZozoroOam_TurningAroundGround;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 4fed4 | 48 | Handles a zozoro turning into an X
 *
 */
static void ZozoroTurningIntoX(void)
{
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
        else
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.5f);
        else
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
    }
}

/**
 * @brief 4ff1c | 17c | Initializes a zozoro sprite
 *
 */
static void ZozoroInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();

    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        SpriteUtilChooseRandomXDirection();

        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        // Stick to a surface
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            // On floor
            gCurrentSprite.work0 = FALSE;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0625f),
                gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            {
                // On ceiling
                gCurrentSprite.work0 = FALSE;
                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

                gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1.0f);

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5625f));
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    // On left wall
                    gCurrentSprite.work0 = TRUE;

                    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.5f);

                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                    {
                        // On right wall
                        gCurrentSprite.work0 = TRUE;
                        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;

                        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);

                        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                    }
                    else
                    {
                        // Midair, delete
                        gCurrentSprite.status = 0;
                        return;
                    }
                }
            }
        }
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    ZozoroSetCrawlingOam();
    ZozoroUpdateHitbox();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
}

/**
 * @brief 50098 | 28 | Initializes a zozoro to be idle
 *
 */
static void ZozoroIdleInit(void)
{
    ZozoroSetCrawlingOam();
    gCurrentSprite.pose = SPRITE_POSE_IDLE;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_1);
}

/**
 * @brief 500c0 | 3b0 | Handles a zozoro being idle
 *
 * @return u8 Garbage
 */
static u8 ZozoroIdle(void)
{
    s16 speed;
    u8 turn;

    speed = BLOCK_TO_SUB_PIXEL(1.f / 64);
    turn = FALSE;

    if (ZozoroCheckCollidingWithAir())
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
        return;
    }

    // Panic if less than max health
    if (gCurrentSprite.health < GET_PSPRITE_HEALTH(gCurrentSprite.spriteId))
    {
        // Drop if not on ground
        if (gCurrentSprite.work0)
        {
            gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
            return;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
            return;
        }

        // On ground, double speed
        speed = BLOCK_TO_SUB_PIXEL(1.f / 32);
        gCurrentSprite.animationDurationCounter += 1;
    }

    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // On right wall
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            {
                // Moving down
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + ZOZORO_LOOKAHEAD_DISTANCE,
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    // Turn if encountered a ledge
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + ZOZORO_LOOKAHEAD_DISTANCE,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.f / 16));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                    {
                        // Turn if encountered a wall
                        turn++;
                    }
                    else
                    {
                        gCurrentSprite.yPosition += speed;
                    }
                }
            }
            else
            {
                // Moving up
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - ZOZORO_LOOKAHEAD_DISTANCE,
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    // Turn if encountered a ledge
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - ZOZORO_LOOKAHEAD_DISTANCE,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.f / 16));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                    {
                        // Turn if encountered a wall
                        turn++;
                    }
                    else
                    {
                        gCurrentSprite.yPosition -= speed;
                    }
                }
            }
        }
        else
        {
            // On left wall
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            {
                // Moving down
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + ZOZORO_LOOKAHEAD_DISTANCE,
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.f / 16));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    // Turn if encountered a ledge
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + ZOZORO_LOOKAHEAD_DISTANCE,
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                    {
                        // Turn if encountered a wall
                        turn++;
                    }
                    else
                    {
                        gCurrentSprite.yPosition += speed;
                    }
                }
            }
            else
            {
                // Moving up
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - ZOZORO_LOOKAHEAD_DISTANCE,
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.f / 16));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    // Turn if encountered a ledge
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - ZOZORO_LOOKAHEAD_DISTANCE,
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                    {
                        // Turn if encountered a wall
                        turn++;
                    }
                    else
                    {
                        gCurrentSprite.yPosition -= speed;
                    }
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            // On ceiling
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.f / 16),
                    gCurrentSprite.xPosition + ZOZORO_LOOKAHEAD_DISTANCE);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    // Turn if encountered a ledge
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition + ZOZORO_LOOKAHEAD_DISTANCE);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                    {
                        // Turn if encountered a wall
                        turn++;
                    }
                    else
                    {
                        gCurrentSprite.xPosition += speed;
                    }
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.f / 16),
                    gCurrentSprite.xPosition - ZOZORO_LOOKAHEAD_DISTANCE);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    // Turn if encountered a ledge
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - ZOZORO_LOOKAHEAD_DISTANCE);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                    {
                        // Turn if encountered a wall
                        turn++;
                    }
                    else
                    {
                        gCurrentSprite.xPosition -= speed;
                    }
                }
            }
        }
        else
        {
            // On floor
            SpriteUtilAlignYPositionOnSlopeAtOrigin();
            if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
            {
                // Went from downwards slope to flat ground
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));

                    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
                        return;
                    }

                    if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE ||
                        gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
                    {
                        gCurrentSprite.yPosition = SpriteUtilCheckVerticalCollisionAtPosition(
                            gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f), gCurrentSprite.xPosition);
                    }
                }
                else
                {
                    SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));

                    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
                        return;
                    }

                    if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE ||
                        gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
                    {
                        gCurrentSprite.yPosition = SpriteUtilCheckVerticalCollisionAtPosition(
                            gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f), gCurrentSprite.xPosition);
                    }
                }
            }
            else
            {
                if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    // On flat ground
                    // Set on ground animation
                    if (gCurrentSprite.pOam != sZozoroOam_CrawlingGround)
                    {
                        gCurrentSprite.pOam = sZozoroOam_CrawlingGround;
                        gCurrentSprite.animationDurationCounter = 0;
                        gCurrentSprite.currentAnimationFrame = 0;
                    }

                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                            gCurrentSprite.xPosition + ZOZORO_LOOKAHEAD_DISTANCE);
                        if (gPreviousCollisionCheck == COLLISION_AIR)
                        {
                            // Turn if encountered a ledge
                            turn++;
                        }
                        else
                        {
                            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
                                gCurrentSprite.xPosition + ZOZORO_LOOKAHEAD_DISTANCE);
                            if (gPreviousCollisionCheck == COLLISION_SOLID)
                            {
                                // Turn if encountered a wall
                                turn++;
                            }
                        }
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                            gCurrentSprite.xPosition - ZOZORO_LOOKAHEAD_DISTANCE);
                        if (gPreviousCollisionCheck == COLLISION_AIR)
                        {
                            // Turn if encountered a ledge
                            turn++;
                        }
                        else
                        {
                            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
                                gCurrentSprite.xPosition - ZOZORO_LOOKAHEAD_DISTANCE);
                            if (gPreviousCollisionCheck == COLLISION_SOLID)
                            {
                                // Turn if encountered a wall
                                turn++;
                            }
                        }
                    }
                }
                else
                {
                    // On slope
                    // Set on slope animation
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                    {
                        if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
                        {
                            if (gCurrentSprite.pOam != sZozoroOam_CrawlingSlightDownwardsSlope)
                            {
                                gCurrentSprite.pOam = sZozoroOam_CrawlingSlightDownwardsSlope;
                                gCurrentSprite.animationDurationCounter = 0;
                                gCurrentSprite.currentAnimationFrame = 0;
                            }
                        }
                        else if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE)
                        {
                            if (gCurrentSprite.pOam != sZozoroOam_CrawlingSteepDownwardsSlope)
                            {
                                gCurrentSprite.pOam = sZozoroOam_CrawlingSteepDownwardsSlope;
                                gCurrentSprite.animationDurationCounter = 0;
                                gCurrentSprite.currentAnimationFrame = 0;
                            }
                        }
                        else if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
                        {
                            if (gCurrentSprite.pOam != sZozoroOam_CrawlingSlightUpwardsSlope)
                            {
                                gCurrentSprite.pOam = sZozoroOam_CrawlingSlightUpwardsSlope;
                                gCurrentSprite.animationDurationCounter = 0;
                                gCurrentSprite.currentAnimationFrame = 0;
                            }
                        }
                        else if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE)
                        {
                            if (gCurrentSprite.pOam != sZozoroOam_CrawlingSteepUpwardsSlope)
                            {
                                gCurrentSprite.pOam = sZozoroOam_CrawlingSteepUpwardsSlope;
                                gCurrentSprite.animationDurationCounter = 0;
                                gCurrentSprite.currentAnimationFrame = 0;
                            }
                        }
                    }
                    else
                    {
                        if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
                        {
                            if (gCurrentSprite.pOam != sZozoroOam_CrawlingSlightDownwardsSlope)
                            {
                                gCurrentSprite.pOam = sZozoroOam_CrawlingSlightDownwardsSlope;
                                gCurrentSprite.animationDurationCounter = 0;
                                gCurrentSprite.currentAnimationFrame = 0;
                            }
                        }
                        else if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE)
                        {
                            if (gCurrentSprite.pOam != sZozoroOam_CrawlingSteepDownwardsSlope)
                            {
                                gCurrentSprite.pOam = sZozoroOam_CrawlingSteepDownwardsSlope;
                                gCurrentSprite.animationDurationCounter = 0;
                                gCurrentSprite.currentAnimationFrame = 0;
                            }
                        }
                        else if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
                        {
                            if (gCurrentSprite.pOam != sZozoroOam_CrawlingSlightUpwardsSlope)
                            {
                                gCurrentSprite.pOam = sZozoroOam_CrawlingSlightUpwardsSlope;
                                gCurrentSprite.animationDurationCounter = 0;
                                gCurrentSprite.currentAnimationFrame = 0;
                            }
                        }
                        else if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE)
                        {
                            if (gCurrentSprite.pOam != sZozoroOam_CrawlingSteepUpwardsSlope)
                            {
                                gCurrentSprite.pOam = sZozoroOam_CrawlingSteepUpwardsSlope;
                                gCurrentSprite.animationDurationCounter = 0;
                                gCurrentSprite.currentAnimationFrame = 0;
                            }
                        }
                    }
                }
            }

            if (!turn)
                SpriteUtilMoveXPosForwardOnSlopeXFlip(speed);
        }
    }

    if (turn)
        gCurrentSprite.pose = ZOZORO_POSE_TURNING_AROUND_INIT;
}

/**
 * @brief 50470 | 18 | Initializes a zozoro to be turning around
 *
 */
static void ZozoroTurningAroundInit(void)
{
    gCurrentSprite.pose = ZOZORO_POSE_TURNING_AROUND;
    ZozoroSetTurningAroundOam();
}

/**
 * @brief 50488 | 48 | Handles a zozoro turning around
 *
 */
static void ZozoroTurningAround(void)
{
    // Flip if in middle of animation
    if (gCurrentSprite.currentAnimationFrame == 1 && gCurrentSprite.animationDurationCounter == 3)
    {
        if (gCurrentSprite.work0)
            gCurrentSprite.status ^= SPRITE_STATUS_Y_FLIP;
        else
            gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

/**
 * @brief 504d0 | 20 | Initializes a zozoro to be falling
 *
 */
static void ZozoroFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.work4 = 0;
    ZozoroSetCrawlingOam();
}

/**
 * @brief 504f0 | 100 | Handles a zozoro falling
 *
 */
static void ZozoroFalling(void)
{
    u32 blockTop;
    u8 vertical;
    u16 yCollisionPoint;
    u16 xCollisionPoint;
    u8 offset;
    s16 movement;

    vertical = FALSE;
    yCollisionPoint = gCurrentSprite.yPosition;
    xCollisionPoint = gCurrentSprite.xPosition;

    // Check if hit ground
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            xCollisionPoint -= BLOCK_TO_SUB_PIXEL(1.f / 16);
        yCollisionPoint += gCurrentSprite.hitboxBottom;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            yCollisionPoint += gCurrentSprite.hitboxBottom;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yCollisionPoint, xCollisionPoint);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Hit ground
        gCurrentSprite.yPosition = blockTop;

        if (gCurrentSprite.work0)
            vertical++;

        gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.work0 = FALSE;

        ZozoroUpdateHitbox();

        if (vertical)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxRight;
            else
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxLeft;
        }

        // Set crawling and don't play start crawling sound
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
        ZozoroSetCrawlingOam();
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
 * @brief 505f0 | 204 | Zozoro AI
 *
 */
void Zozoro(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_ZOZORO_HURT);

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZozoroInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            ZozoroIdleInit();

        case SPRITE_POSE_IDLE:
            ZozoroIdle();
            break;

        case ZOZORO_POSE_TURNING_AROUND_INIT:
            ZozoroTurningAroundInit();

        case ZOZORO_POSE_TURNING_AROUND:
            ZozoroTurningAround();
            break;

        case SPRITE_POSE_FALLING_INIT:
            ZozoroFallingInit();

        case SPRITE_POSE_FALLING:
            ZozoroFalling();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            ZozoroInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            ZozoroTurningIntoX();
            XParasiteInit();
            break;
    }
}
