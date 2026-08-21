#include "data/sprites/sova.h"

#include "globals.h"

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

#define SOVA_CRAWLING_HITBOX_SIZE (BLOCK_TO_SUB_PIXEL(0.625f))

boolu8 SovaCheckCollidingWithAir(void)
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
        if (gCurrentSprite.work2)
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
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    midair = TRUE;
            }
        }
    }

    return midair;
}

void SovaUpdateHitbox(void)
{
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0f);
        }
    }
    else
    {
        if (gCurrentSprite.work2)
        {
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.4375f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.4375f);
        }
    }
}

void SovaSetCrawlingOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sSovaOam_CrawlingOnWall;
    else if (gCurrentSprite.work2)
        gCurrentSprite.pOam = sSovaOam_CrawlingOnCeiling;
    else
        gCurrentSprite.pOam = sSovaOam_CrawlingOnFlatGround;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void SovaTurningIntoX(void)
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
        if (gCurrentSprite.work2)
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.5f);
        else
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
    }
}

void SovaInit(void)
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
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
        gCurrentSprite.work2 = FALSE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.work0 = FALSE;
            gCurrentSprite.work3 = gSpriteRandomNumber * 4 + 70;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0625f),
                gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            {
                gCurrentSprite.work0 = FALSE;
                gCurrentSprite.yPosition -= BLOCK_SIZE;
                gCurrentSprite.work2 = TRUE;
                gCurrentSprite.work3 = gSpriteRandomNumber * 4 + 30;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5625f));
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    gCurrentSprite.work0 = TRUE;
                    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                    gCurrentSprite.work3 = gSpriteRandomNumber * 4 + 30;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                    {
                        gCurrentSprite.work0 = TRUE;
                        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);
                        gCurrentSprite.work3 = gSpriteRandomNumber * 4 + 30;
                    }
                    else
                    {
                        gCurrentSprite.status = 0;
                        return;
                    }
                }
            }
        }
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    SovaSetCrawlingOam();
    SovaUpdateHitbox();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
}

void SovaIdleInit(void)
{
    SovaSetCrawlingOam();
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
}

void SovaIdle(void)
{
    u8 turn;
    s16 speed;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    speed = 1;
    turn = FALSE;
    gCurrentSprite.work3--;

    if (gCurrentSprite.work0)
    {
        if (SovaCheckCollidingWithAir())
        {
            gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
            return;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // On right wall
            if (gCurrentSprite.work3 == 0)
            {
                // Drop falling flames periodically
                SpriteSpawnSecondary(SSPRITE_SOVA_FIRE, TRUE, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.3125f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.3125f), 0);
                gCurrentSprite.work3 = 160;
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_SOVA_DROPPING_FLAME);
            }
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                // Moving down
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + SOVA_CRAWLING_HITBOX_SIZE,
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn++; // Turn if it encountered a ledge
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + SOVA_CRAWLING_HITBOX_SIZE,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++; // Turn if it encountered a floor
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                // Moving up
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - SOVA_CRAWLING_HITBOX_SIZE,
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn++; // Turn if it encountered a ledge
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - SOVA_CRAWLING_HITBOX_SIZE,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++; // Turn if it encountered a ceiling
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
        else
        {
            // On left wall
            if (gCurrentSprite.work3 == 0)
            {
                // Drop falling flames periodically
                SpriteSpawnSecondary(SSPRITE_SOVA_FIRE, TRUE, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.3125f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.3125f), 0);
                gCurrentSprite.work3 = 160;
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_SOVA_DROPPING_FLAME);
            }
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                // Moving down
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + SOVA_CRAWLING_HITBOX_SIZE,
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn++; // Turn if it encountered a ledge
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + SOVA_CRAWLING_HITBOX_SIZE,
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++; // Turn if it encountered a floor
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                // Moving up
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - SOVA_CRAWLING_HITBOX_SIZE,
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn++; // Turn if it encountered a ledge
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - SOVA_CRAWLING_HITBOX_SIZE,
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++; // Turn if it encountered a ceiling
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.work2)
        {
            // On ceiling
            if (gCurrentSprite.work3 == 0)
            {
                // Drop falling flames periodically
                SpriteSpawnSecondary(SSPRITE_SOVA_FIRE, TRUE, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.3125f),
                    gCurrentSprite.xPosition, 0);
                gCurrentSprite.work3 = 160;
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_SOVA_DROPPING_FLAME);
            }

            if (SovaCheckCollidingWithAir())
            {
                gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
                return;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition + SOVA_CRAWLING_HITBOX_SIZE);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition + SOVA_CRAWLING_HITBOX_SIZE);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++;
                    else
                        gCurrentSprite.xPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition - SOVA_CRAWLING_HITBOX_SIZE);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - SOVA_CRAWLING_HITBOX_SIZE);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++;
                    else
                        gCurrentSprite.xPosition -= speed;
                }
            }
        }
        else
        {
            // Drop trailing flames periodically
            if (gCurrentSprite.work3 == 64 || gCurrentSprite.work3 == 32)
            {
                SpriteSpawnSecondary(SSPRITE_SOVA_FIRE, FALSE, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_SOVA_DROPPING_FLAME);
            }
            else if (gCurrentSprite.work3 == 0)
            {
                SpriteSpawnSecondary(SSPRITE_SOVA_FIRE, FALSE, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                gCurrentSprite.work3 = 210;
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_SOVA_DROPPING_FLAME);
            }
            SpriteUtilAlignYPositionOnSlopeAtOrigin();
            if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
            {
                // About to fall off a ledge
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
                    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
                        return;
                    }
                    else
                    {
                        gCurrentSprite.xPosition += speed;
                    }
                }
                else
                {
                    SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
                        return;
                    }
                    else
                    {
                        gCurrentSprite.xPosition -= speed;
                    }
                }
            }
            else
            {
                if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    // On flat ground
                    if (gCurrentSprite.pOam == sSovaOam_CrawlingOnSlope)
                    {
                        // Set on flat ground OAM and remove X flip if previously on slope
                        gCurrentSprite.pOam = sSovaOam_CrawlingOnFlatGround;
                        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
                    }
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                            gCurrentSprite.xPosition + SOVA_CRAWLING_HITBOX_SIZE);
                        if (gPreviousCollisionCheck == COLLISION_AIR)
                        {
                            turn++; // Turn if it encountered a ledge
                        }
                        else
                        {
                            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                                gCurrentSprite.xPosition + SOVA_CRAWLING_HITBOX_SIZE);
                            if (gPreviousCollisionCheck == COLLISION_SOLID)
                                turn++; // Turn if it encountered a wall
                        }
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                            gCurrentSprite.xPosition - SOVA_CRAWLING_HITBOX_SIZE);
                        if (gPreviousCollisionCheck == COLLISION_AIR)
                        {
                            turn++; // Turn if it encountered a ledge
                        }
                        else
                        {
                            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                                gCurrentSprite.xPosition - SOVA_CRAWLING_HITBOX_SIZE);
                            if (gPreviousCollisionCheck == COLLISION_SOLID)
                                turn++; // Turn if it encountered a wall
                        }
                    }
                }
                else
                {
                    // On slope, set on slope OAM and apply X flip on right slopes if previously on ground
                    // Assumes that ledges and walls are not encountered
                    if ((gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE ||
                            gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE) &&
                        gCurrentSprite.pOam == sSovaOam_CrawlingOnFlatGround)
                    {
                        gCurrentSprite.pOam = sSovaOam_CrawlingOnSlope;
                    }

                    if ((gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE ||
                            gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE) &&
                        gCurrentSprite.pOam == sSovaOam_CrawlingOnFlatGround)
                    {
                        gCurrentSprite.pOam = sSovaOam_CrawlingOnSlope;
                        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                    }
                }

                // Move forward if not turning
                if (!turn)
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        gCurrentSprite.xPosition += speed;
                    else
                        gCurrentSprite.xPosition -= speed;
                }
            }
        }
    }

    if (turn)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.pose = 7;
    }
}

void SovaTurningAroundInit(void)
{
    gCurrentSprite.pose = 8;
    gCurrentSprite.work1 = CONVERT_SECONDS(0.5f); // Stop for half of a second
}

void SovaTurningAround(void)
{
    if (SovaCheckCollidingWithAir())
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
    else if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void SovaFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.work4 = 0;
}

void SovaFalling(void)
{
    u16 yCollisionPoint;
    u16 xCollisionPoint;
    u32 blockTop;
    u8 onWall;
    u8 offset;
    s16 movement;

    onWall = FALSE;
    yCollisionPoint = gCurrentSprite.yPosition;
    xCollisionPoint = gCurrentSprite.xPosition;

    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            xCollisionPoint -= BLOCK_TO_SUB_PIXEL(0.0625f);
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
        gCurrentSprite.yPosition = blockTop;

        if (gCurrentSprite.work0)
            onWall++;

        gCurrentSprite.pose = 7;
        gCurrentSprite.work0 = FALSE;
        gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.work2 = FALSE;

        SovaSetCrawlingOam();
        SovaUpdateHitbox();

        if (onWall)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxRight;
            else
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxLeft;
        }
    }
    else
    {
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

void SovaFireInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 5;

    if (gCurrentSprite.roomSlot)
    {
        // Falling flame
        gCurrentSprite.pOam = sSovaFallingFlameOam_Falling;
        gCurrentSprite.pose = SPRITE_POSE_FALLING;
        gCurrentSprite.work4 = 0;
    }
    else
    {
        // Flame on ground
        gCurrentSprite.pOam = sSovaGroundFlameOam_Big;
        gCurrentSprite.pose = 2;
        gCurrentSprite.work1 = 50;
    }
}

void SovaFireBig(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.4375f);
        gCurrentSprite.pOam = sSovaGroundFlameOam_Small;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.work1 = 50;
    }
}

void SovaFireSmall(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.25f);
        gCurrentSprite.pOam = sSovaGroundFlameOam_Disappearing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.work1 = 30;
    }
}

void SovaFireDisappearing(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (MOD_AND(gCurrentSprite.work1, 2) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.status = 0;
}

void SovaFireExplodingInit(void)
{
    gCurrentSprite.pOam = sSovaFallingFlameOam_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_LANDED;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_SOVA_FALLING_FLAME_EXPLODING);
}

void SovaFireExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

void Sova(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_SOVA_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SovaInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            SovaIdleInit();
        case SPRITE_POSE_IDLE:
            SovaIdle();
            break;

        case 7:
            SovaTurningAroundInit();
        case 8:
            SovaTurningAround();
            break;

        case SPRITE_POSE_FALLING_INIT:
            SovaFallingInit();
        case SPRITE_POSE_FALLING:
            SovaFalling();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            SovaInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            SovaTurningIntoX();
            XParasiteInit();
            break;
    }
}

void SovaFire(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SovaFireInit();
            break;

        case 2:
            SovaFireBig();
            break;

        case 0x18:
            SovaFireSmall();
            break;

        case 0x1a:
            SovaFireDisappearing();
            break;

        case SPRITE_POSE_FALLING:
            SpriteUtilCurrentSpriteFall();
            break;

        case SPRITE_POSE_LANDED_INIT:
            SovaFireExplodingInit();
        case SPRITE_POSE_LANDED:
            SovaFireExploding();
            break;
    }
}
