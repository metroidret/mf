#include "data/sprites/yard.h"

#include "globals.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/power_bomb.h"
#include "structs/samus.h"
#include "structs/sprite.h"

enum YardProjectileDirection {
    YARD_PROJECTILE_DIRECTION_UP_LEFT,
    YARD_PROJECTILE_DIRECTION_DOWN_LEFT,
    YARD_PROJECTILE_DIRECTION_DOWN_RIGHT,
    YARD_PROJECTILE_DIRECTION_UP_RIGHT
};

boolu8 YardCheckShouldStartle(void)
{
    if (gCurrentPowerBomb.animationState != 0)
    {
        gCurrentSprite.pose = 0x18;

        if (gCurrentSprite.work0)
            gCurrentSprite.pOam = sYardOam_StartledVertical;
        else
            gCurrentSprite.pOam = sYardOam_StartledHorizontal;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work3 = 180;

        return TRUE;
    }

    return FALSE;
}

boolu8 YardCheckCollidingWithAir(void)
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

void YardUpdateHitbox(void)
{
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        if (gCurrentSprite.work0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.4375f);
                gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.4375f);
                gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.875f);
                gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
            }
            else
            {
                gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.4375f);
                gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.4375f);
                gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
                gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.875f);
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            {
                gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.25f);
                gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.875f);
                gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.4375f);
                gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.4375f);
            }
            else
            {
                gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.875f);
                gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
                gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.4375f);
                gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.4375f);
            }
        }
    }
    else
    {
        if (gCurrentSprite.work0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
                gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
                gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.0f);
                gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
            }
            else
            {
                gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
                gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
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
                gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
                gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            }
            else
            {
                gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
                gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
                gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
                gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            }
        }
    }
}

void YardSetCrawlingOam(void)
{
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        if (gCurrentSprite.work0)
            gCurrentSprite.pOam = sYardOam_UninfectedVertical;
        else
            gCurrentSprite.pOam = sYardOam_UninfectedHorizontal;
    }
    else
    {
        if (gCurrentSprite.work0)
            gCurrentSprite.pOam = sYardOam_CrawlingVertical;
        else
            gCurrentSprite.pOam = sYardOam_CrawlingHorizontal;
    }

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void YardSetTurningAroundOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sYardOam_TurningAroundVertical1;
    else
        gCurrentSprite.pOam = sYardOam_TurningAroundHorizontal1;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void YardSetTurningAroundSecondPartOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sYardOam_TurningAroundVertical2;
    else
        gCurrentSprite.pOam = sYardOam_TurningAroundHorizontal2;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void YardSetChargingOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sYardOam_ChargingVertical;
    else
        gCurrentSprite.pOam = sYardOam_ChargingHorizontal;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void YardSetShootingOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sYardOam_ShootingVertical;
    else
        gCurrentSprite.pOam = sYardOam_ShootingHorizontal;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void YardSetRecoilOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sYardOam_RecoilVertical;
    else
        gCurrentSprite.pOam = sYardOam_RecoilHorizontal;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void YardCheckShoot(void)
{
    u32 nsfb;

    if (gCurrentSprite.work1 > 0)
    {
        gCurrentSprite.work1--;
        return;
    }

    if (gCurrentSprite.work0)
        nsfb = SpriteUtilCheckSamusNearSpriteFrontBehindY(BLOCK_TO_SUB_PIXEL(10.0f), BLOCK_TO_SUB_PIXEL(10.0f),
            BLOCK_TO_SUB_PIXEL(10.0f));
    else
        nsfb = SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(10.0f), BLOCK_TO_SUB_PIXEL(10.0f),
            BLOCK_TO_SUB_PIXEL(10.0f));

    if (nsfb == NSFB_IN_FRONT)
    {
        gCurrentSprite.pose = 3;
    }
    else if (nsfb == NSFB_BEHIND)
    {
        gCurrentSprite.pose = 0x2a;
        YardSetChargingOam();

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_YARD_CHARGING);
    }
}

void YardCharging(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.work1 = 30;
        gCurrentSprite.pose = 0x2c;
        YardSetShootingOam();
    }
}

void YardShooting(void)
{
    boolu8 startled;

    startled = YardCheckShouldStartle();

    if (startled)
        return;

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x2e;
        YardSetRecoilOam();
        return;
    }

    if (gCurrentSprite.work1 == 15)
    {
        if (gCurrentSprite.work0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                    SpriteSpawnSecondary(SSPRITE_YARD_PROJECTILE, YARD_PROJECTILE_DIRECTION_UP_LEFT,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.3125f), 0);
                else
                    SpriteSpawnSecondary(SSPRITE_YARD_PROJECTILE, YARD_PROJECTILE_DIRECTION_DOWN_LEFT,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.3125f), 0);
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                    SpriteSpawnSecondary(SSPRITE_YARD_PROJECTILE, YARD_PROJECTILE_DIRECTION_UP_RIGHT,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.3125f), 0);
                else
                    SpriteSpawnSecondary(SSPRITE_YARD_PROJECTILE, YARD_PROJECTILE_DIRECTION_DOWN_RIGHT,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.3125f), 0);
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                    SpriteSpawnSecondary(SSPRITE_YARD_PROJECTILE, YARD_PROJECTILE_DIRECTION_DOWN_LEFT,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.3125f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f), 0);
                else
                    SpriteSpawnSecondary(SSPRITE_YARD_PROJECTILE, YARD_PROJECTILE_DIRECTION_DOWN_RIGHT,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.3125f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f), 0);
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                    SpriteSpawnSecondary(SSPRITE_YARD_PROJECTILE, YARD_PROJECTILE_DIRECTION_UP_LEFT,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.3125f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f), 0);
                else
                    SpriteSpawnSecondary(SSPRITE_YARD_PROJECTILE, YARD_PROJECTILE_DIRECTION_UP_RIGHT,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.3125f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f), 0);
            }
        }

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_YARD_SHOOTING);
    }
}

void YardRecoil(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.pose = 3;
        gCurrentSprite.work1 = 120;
    }
}

void YardTurningIntoX(void)
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

void YardInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_ROTATION_SCALING_SINGLE;
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
        if (!gCurrentSprite.work0 && !(gCurrentSprite.status & SPRITE_STATUS_Y_FLIP))
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
        }
    }
    else
    {
        SpriteUtilChooseRandomXDirection();
        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
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
                        gCurrentSprite.work0 = TRUE;
                        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);

                        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
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

    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        gCurrentSprite.drawOrder = 12;
        gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
    }
    else
    {
        gCurrentSprite.drawOrder = 4;
        gCurrentSprite.properties &= ~SP_SOLID_FOR_PROJECTILES;
    }

    YardSetCrawlingOam();
    YardUpdateHitbox();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);
}

void YardCheckRoll(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 1 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        if (gCurrentSprite.work0 || gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            // On wall or ceiling, make it fall
            gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
        }
        else
        {
            SpriteUtilMakeSpriteFaceAwayFromSamusDirection();
            gCurrentSprite.pose = 0x38;
            // NOTE: Speed is capped to half a pixel per frame when rolling down a slope
            gCurrentSprite.work1 = PIXEL_TO_VELOCITY(1.875);

            if (!(gCurrentSprite.status & SPRITE_STATUS_ROTATION_SCALING_SINGLE))
            {
                gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
                gCurrentSprite.rotation = 0;
                gCurrentSprite.scaling = Q_8_8(1);
            }
        }
    }
}

void YardRolling(void)
{
    boolu8 notSlowingDown;
    u16 rotationDelta;

    YardCheckRoll();
    notSlowingDown = FALSE;
    SpriteUtilAlignYPositionOnSlopeAtOrigin();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        // On a ledge
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            // Check block below bottom-left
            SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
                return;
            }

            // Adjust Y position if on slope
            if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE ||
                gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
                gCurrentSprite.yPosition = SpriteUtilCheckVerticalCollisionAtPosition(
                    gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
        }
        else
        {
            // Check block below bottom-right
            SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
                return;
            }

            // Adjust Y position if on slope
            if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE ||
                gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
                gCurrentSprite.yPosition = SpriteUtilCheckVerticalCollisionAtPosition(
                    gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
        }
    }
    else if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
    {
        // On flat ground
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            // Check block below bottom-right
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousCollisionCheck != COLLISION_AIR)
            {
                // Still on ground or slope, check block above bottom-right
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                if (gPreviousCollisionCheck == COLLISION_SOLID)
                {
                    // Hit a wall
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    return;
                }
            }
            else
            {
                // Encountered a ledge
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                return;
            }
        }
        else
        {
            // Check block below bottom-left
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousCollisionCheck != COLLISION_AIR)
            {
                // Still on ground or slope, check block above bottom-left
#ifdef BUGFIX
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
#else // !BUGFIX
                // BUG: Y position should be subtracted by one pixel
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
#endif // BUGFIX
                if (gPreviousCollisionCheck == COLLISION_SOLID)
                {
                    // Hit a wall
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    return;
                }
            }
            else
            {
                // Encountered a ledge
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                return;
            }
        }
    }
    else
    {
        // On slope
        if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE ||
            gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                // Rolling up a slope
                if (gCurrentSprite.work1 == PIXEL_TO_VELOCITY(1. / 32))
                {
                    // Start to roll down a slope, don't decelerate
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    notSlowingDown = TRUE;
                }
                // Decelerate
            }
            else
            {
                // Don't decelerate when rolling down a slope
                notSlowingDown = TRUE;
            }
        }
        else if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE ||
            gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                // Rolling up a slope
                if (gCurrentSprite.work1 == PIXEL_TO_VELOCITY(1. / 32))
                {
                    // Start to roll down a slope, don't decelerate
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    notSlowingDown = TRUE;
                }
                // Decelerate
            }
            else
            {
                // Don't decelerate when rolling down a slope
                notSlowingDown = TRUE;
            }
        }
    }

    if (!notSlowingDown)
    {
        // Slow down by 1/32 of a pixel per frame
        if (--gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
            return;
        }
    }
    else
    {
        // Cap speed at 1/2 of a pixel per frame when rolling down a slope
        if (gCurrentSprite.work1 < PIXEL_TO_VELOCITY(0.5))
            gCurrentSprite.work1 = PIXEL_TO_VELOCITY(0.5);
    }

    rotationDelta = VELOCITY_TO_SUB_PIXEL(gCurrentSprite.work1);
    SpriteUtilMoveXPosForwardOnSlopeDirection(rotationDelta);

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.rotation += rotationDelta;
    else
        gCurrentSprite.rotation -= rotationDelta;

    if (MOD_AND(gFrameCounter8Bit, 32) == 0)
        SoundPlayNotAlreadyPlaying(SOUND_YARD_ROLLING);
}

void YardStartled(void)
{
    if (YardCheckCollidingWithAir())
    {
        gCurrentSprite.pose = 0x15;
    }
    else if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
        gCurrentSprite.work1 = 120;
    }
}

void YardIdleInit(void)
{
    YardSetCrawlingOam();
    gCurrentSprite.pose = 2;
}

void YardIdle(void)
{
    u16 y, x, top, bottom, left, right;
    u16 otherY, otherX, otherTop, otherBottom, otherLeft, otherRight;
    u8 i;
    u16 speed;
    u8 turn;

    speed = 1;
    turn = FALSE;

    if (YardCheckCollidingWithAir())
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
        return;
    }

    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        YardCheckRoll();
        return;
    }

    if (YardCheckShouldStartle())
        return;

    // Turn around if touching another yard
    if (gCurrentSprite.work2 == 0)
    {
        y = gCurrentSprite.yPosition;
        x = gCurrentSprite.xPosition;
        top = y + gCurrentSprite.hitboxTop;
        bottom = y + gCurrentSprite.hitboxBottom;
        left = x + gCurrentSprite.hitboxLeft;
        right = x + gCurrentSprite.hitboxRight;

        for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
        {
            if (i == gCurrentSprite.primarySpriteRamSlot)
                continue;
            if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
                continue;
            if (!(gSpriteData[i].spriteId == PSPRITE_YARD))
                continue;
            if (gSpriteData[i].properties & (SP_SECONDARY_SPRITE | SP_CAN_ABSORB_X))
                continue;
            if (gSpriteData[i].pose >= SPRITE_POSE_TURNING_INTO_X)
                continue;

            otherY = gSpriteData[i].yPosition;
            otherX = gSpriteData[i].xPosition;
            otherTop = otherY + gSpriteData[i].hitboxTop;
            otherBottom = otherY + gSpriteData[i].hitboxBottom;
            otherLeft = otherX + gSpriteData[i].hitboxLeft;
            otherRight = otherX + gSpriteData[i].hitboxRight;

            if (SpriteUtilCheckObjectsTouching(top, bottom, left, right, otherTop, otherBottom, otherLeft, otherRight))
            {
                gCurrentSprite.work2 = 120;
                gCurrentSprite.pose = 3;
                return;
            }
        }
    }
    else
    {
        gCurrentSprite.work2--;
    }

    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.75f),
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.75f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++;
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.75f),
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.75f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++;
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.75f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.75f),
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++;
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.75f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.75f),
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++;
                    else
                        gCurrentSprite.yPosition -= speed;
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
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++;
                    else
                        gCurrentSprite.xPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    turn++;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn++;
                    else
                        gCurrentSprite.xPosition -= speed;
                }
            }
        }
        else
        {
            SpriteUtilAlignYPositionOnSlopeAtOrigin();
            if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    {
                        turn++;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
                        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                            turn++;
                        else
                            gCurrentSprite.xPosition += speed;
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    {
                        turn++;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
                        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                            turn++;
                        else
                            gCurrentSprite.xPosition -= speed;
                    }
                }
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.xPosition += speed;
                else
                    gCurrentSprite.xPosition -= speed;
            }
        }
    }

    if (turn)
        gCurrentSprite.pose = 3;

    YardCheckShoot();
}

void YardTurningAroundInit(void)
{
    gCurrentSprite.pose = 4;
    YardSetTurningAroundOam();
}

void YardTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 5;

        YardSetTurningAroundSecondPartOam();

        if (gCurrentSprite.work0)
            gCurrentSprite.status ^= SPRITE_STATUS_Y_FLIP;
        else
            gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;

        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
}

void YardTurningAroundSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = 1;
}

void YardFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.work4 = 0;
    YardSetCrawlingOam();
}

void YardFalling(void)
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

        gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.work0 = FALSE;
        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        YardUpdateHitbox();
        YardSetCrawlingOam();

        if (onWall)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxRight;
            else
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxLeft;
        }

        if (gCurrentSprite.properties & SPRITE_STATUS_ONSCREEN)
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_HEAVY_DUST_2);
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sSpritesFallingSpeedSlow[offset];
        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeedSlow[offset - 1];
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

void YardProjectileInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.pOam = sYardProjectileOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
}

void YardProjectileMoving(void)
{
    if (gCurrentSprite.roomSlot == YARD_PROJECTILE_DIRECTION_UP_LEFT)
    {
        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.046875f);
        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.046875f);
    }
    else if (gCurrentSprite.roomSlot == YARD_PROJECTILE_DIRECTION_DOWN_LEFT)
    {
        gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.046875f);
        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.046875f);
    }
    else if (gCurrentSprite.roomSlot == YARD_PROJECTILE_DIRECTION_DOWN_RIGHT)
    {
        gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.046875f);
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.046875f);
    }
    else if (gCurrentSprite.roomSlot == YARD_PROJECTILE_DIRECTION_UP_RIGHT)
    {
        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.046875f);
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.046875f);
    }
}

void YardProjectileExplodingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_EXPLODING;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pOam = sYardProjectileOam_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void YardProjectileExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

void Yard(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_YARD_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            YardInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            YardIdleInit();
        case SPRITE_POSE_IDLE:
            YardIdle();
            break;

        case 0x18:
            YardStartled();
            break;

        case 3:
            YardTurningAroundInit();
        case 4:
            YardTurningAround();
            break;

        case 5:
            YardTurningAroundSecondPart();
            break;

        case SPRITE_POSE_FALLING_INIT:
            YardFallingInit();
        case SPRITE_POSE_FALLING:
            YardFalling();
            break;

        case 0x2a:
            YardCharging();
            break;

        case 0x2c:
            YardShooting();
            break;

        case 0x2e:
            YardRecoil();
            break;

        case 0x38:
            YardRolling();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            YardInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            YardTurningIntoX();
            XParasiteInit();
            break;
    }
}

void YardProjectile(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            YardProjectileInit();
        case SPRITE_POSE_IDLE:
            YardProjectileMoving();
            break;

        case SPRITE_POSE_EXPLODING:
            YardProjectileExploding();
            break;

        default:
            YardProjectileExplodingInit();
            break;
    }
}
