#include "data/sprites/zeela.h"

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

boolu8 ZeelaCheckCollidingWithAir(void)
{
    boolu8 midair;

    midair = FALSE;

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

void ZeelaUpdateHitbox(void)
{
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0f);
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.625f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.625f);
        }
    }
}

void ZeelaSetCrawlingOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sZeelaOam_CrawlingVertical;
    else
        gCurrentSprite.pOam = sZeelaOam_CrawlingHorizontal;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void ZeelaSetFallingOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sZeelaOam_FallingVertical;
    else
        gCurrentSprite.pOam = sZeelaOam_FallingHorizontal;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void ZeelaShootProjectiles(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        if (++gCurrentSprite.work2 >= 4)
            gCurrentSprite.work2 = 0;
        return;
    }

    if (gCurrentSprite.work2 > 0)
        return;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1 &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_ZEELA_SHOOTING);

    if (gCurrentSprite.currentAnimationFrame == 1 && gCurrentSprite.animationDurationCounter == 8)
    {
        if (gCurrentSprite.work0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                SpriteSpawnSecondary(SSPRITE_ZEELA_PROJECTILE, 3, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.8125f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.9375f), SPRITE_STATUS_X_FLIP);
            else
                SpriteSpawnSecondary(SSPRITE_ZEELA_PROJECTILE, 2, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.8125f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.9375f), SPRITE_STATUS_X_FLIP);
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                SpriteSpawnSecondary(SSPRITE_ZEELA_PROJECTILE, 1, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.9375f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.8125f), SPRITE_STATUS_X_FLIP);
            else
                SpriteSpawnSecondary(SSPRITE_ZEELA_PROJECTILE, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.9375f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.8125f), SPRITE_STATUS_X_FLIP);
        }
    }
    else if (gCurrentSprite.currentAnimationFrame == 2 && gCurrentSprite.animationDurationCounter == 8)
    {
        if (gCurrentSprite.work0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                SpriteSpawnSecondary(SSPRITE_ZEELA_PROJECTILE, 3, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.8125f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.9375f), 0);
            else
                SpriteSpawnSecondary(SSPRITE_ZEELA_PROJECTILE, 2, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.8125f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.9375f), 0);
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                SpriteSpawnSecondary(SSPRITE_ZEELA_PROJECTILE, 1, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.9375f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.8125f), 0);
            else
                SpriteSpawnSecondary(SSPRITE_ZEELA_PROJECTILE, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.9375f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.8125f), 0);
        }
    }
}

void ZeelaTurningIntoX(void)
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

void ZeelaInit(void)
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
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.work0 = FALSE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0625f),
                gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            {
                gCurrentSprite.work0 = FALSE;
                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1.0f);
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

    ZeelaSetCrawlingOam();
    ZeelaUpdateHitbox();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
}

void ZeelaIdleInit(void)
{
    ZeelaSetCrawlingOam();
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
}

void ZeelaIdle(void)
{
    boolu8 turn;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    ZeelaShootProjectiles();

    if (ZeelaCheckCollidingWithAir())
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
        return;
    }

    turn = FALSE;
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.875f),
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.875f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.875f),
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.875f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
                }
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.875f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.875f),
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.875f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.875f),
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.875f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.875f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.875f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.875f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
                }
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.875f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.875f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.875f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.875f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
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

void ZeelaTurningAroundInit(void)
{
    gCurrentSprite.pose = 8;
    ZeelaSetFallingOam();
}

void ZeelaTurningAround(void)
{
    if (ZeelaCheckCollidingWithAir())
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
    else if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void ZeelaFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.work4 = 0;
    ZeelaSetFallingOam();
}

void ZeelaFalling(void)
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
            xCollisionPoint -= PIXEL_SIZE;
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

        gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.work0 = FALSE;
        ZeelaUpdateHitbox();

        if (onWall)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxRight;
            else
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxLeft;
        }

        gCurrentSprite.pose = 8;
        ZeelaSetFallingOam();
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

void ZeelaProjectileInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.pOam = sZeelaProjectileOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.pose = 2;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 3;
}

void ZeelaProjectileMoving(void)
{
    u8 offset;
    s16 movement;

    gCurrentClipdataAffectingAction = CAA_ENEMY_PROJECTILE;
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
        return;
    }

    offset = gCurrentSprite.work4;
    movement = sZeelaProjectileMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sZeelaProjectileMovement[offset - 1];
    }
    else
    {
        offset++;
        gCurrentSprite.work4 = offset;
    }

    if (gCurrentSprite.roomSlot >= 2)
    {
        if (gCurrentSprite.roomSlot == 3)
            gCurrentSprite.xPosition += movement;
        else
            gCurrentSprite.xPosition -= movement;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.09375f);
        else
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.09375f);
    }
    else
    {
        if (gCurrentSprite.roomSlot != 0)
            gCurrentSprite.yPosition -= movement;
        else
            gCurrentSprite.yPosition += movement;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.09375f);
        else
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.09375f);
    }
}

void ZeelaProjectileExplodingInit(void)
{
    gCurrentSprite.pose = 0x38;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.bgPriority = 1;

    if (MOD_AND(gSpriteRandomNumber, 2) != 0)
        gCurrentSprite.pOam = sZeelaProjectileOam_Exploding1;
    else
        gCurrentSprite.pOam = sZeelaProjectileOam_Exploding2;
}

void ZeelaProjectileExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

void Zeela(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_ZEELA_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZeelaInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            ZeelaIdleInit();
        case SPRITE_POSE_IDLE:
            ZeelaIdle();
            break;

        case 7:
            ZeelaTurningAroundInit();
        case 8:
            ZeelaTurningAround();
            break;

        case SPRITE_POSE_FALLING_INIT:
            ZeelaFallingInit();
        case SPRITE_POSE_FALLING:
            ZeelaFalling();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            ZeelaInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            ZeelaTurningIntoX();
            XParasiteInit();
            break;
    }
}

void ZeelaProjectile(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZeelaProjectileInit();
        case 2:
            ZeelaProjectileMoving();
            break;

        case 0x38:
            ZeelaProjectileExploding();
            break;

        default:
            ZeelaProjectileExplodingInit();
            break;
    }
}
