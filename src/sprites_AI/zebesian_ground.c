#include "sprites_AI/zebesian_ground.h"
#include "data/sprites/zebesian_ground.h"

#include "gba/keys.h"
#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"

#include "structs/samus.h"
#include "structs/sprite.h"

enum ZebesianGroundPose {
    ZEBESIAN_GROUND_POSE_WALKING_INIT = 1,
    ZEBESIAN_GROUND_POSE_WALKING = 2,
    ZEBESIAN_GROUND_POSE_STANDING_INIT = 9,
    ZEBESIAN_GROUND_POSE_STANDING = 0xa,
    ZEBESIAN_GROUND_POSE_TURNING_AROUND_INIT = 3,
    ZEBESIAN_GROUND_POSE_TURNING_AROUND_1 = 4,
    ZEBESIAN_GROUND_POSE_TURNING_AROUND_2 = 5,
    ZEBESIAN_GROUND_POSE_JUMP_WARNING_INIT = 0x17,
    ZEBESIAN_GROUND_POSE_JUMP_WARNING = 0x18,
    ZEBESIAN_GROUND_POSE_JUMPING = 0x1a,
    ZEBESIAN_GROUND_POSE_LANDING_AFTER_JUMPING = 0x1c,
    ZEBESIAN_GROUND_POSE_SHOOTING_INIT = 0x29,
    ZEBESIAN_GROUND_POSE_SHOOTING = 0x2a,
    ZEBESIAN_GROUND_POSE_SHOOTING_END_INIT = 0x2b,
    ZEBESIAN_GROUND_POSE_SHOOTING_END = 0x2c,
};

enum ZebesianGroundBeamPose {
    ZEBESIAN_GROUND_BEAM_POSE_SPAWNING = 2,
    ZEBESIAN_GROUND_BEAM_POSE_EXTENDING = 0x18,
    ZEBESIAN_GROUND_BEAM_POSE_EXTENDED = 0x1a,
};

u8 ZebesianGroundCheckInRange(void)
{
    u32 nsfb;

    if (gSamusData.yPosition + gSamusData.drawDistanceTop / 2 > gCurrentSprite.yPosition)
    {
        // Samus's center is below the zebesian's feet
        return NSFB_OUT_OF_RANGE;
    }
    else
    {
        nsfb = SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(3.0f), BLOCK_TO_SUB_PIXEL(4.0f),
            BLOCK_TO_SUB_PIXEL(13.0f));
        if (nsfb == NSFB_IN_FRONT)
        {
            gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_JUMP_WARNING_INIT;
            gCurrentSprite.work2 = FALSE; // High jump
            gCurrentSprite.work1 = 0;
            return NSFB_IN_FRONT;
        }
        else
        {
            if (gCurrentSprite.work1 > 0)
            {
                if (--gCurrentSprite.work1 > 0)
                    return NSFB_OUT_OF_RANGE;
            }

            nsfb = SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(6.0f), BLOCK_TO_SUB_PIXEL(13.0f),
                BLOCK_TO_SUB_PIXEL(13.0f));
            if (nsfb == NSFB_IN_FRONT)
            {
                gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_SHOOTING_INIT;
            }
            else if (nsfb == NSFB_BEHIND)
            {
                gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_TURNING_AROUND_INIT;
                gCurrentSprite.work2 = TRUE; // Turn around shot
            }

            return nsfb;
        }
    }
}

boolu8 ZebesianGroundCheckCollidingWithAir(void)
{
    boolu8 cond = FALSE;

    cond = FALSE;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5625f));
    if (gPreviousCollisionCheck == 0)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5625f));
        if (gPreviousCollisionCheck == 0)
            cond = TRUE;
    }

    return cond;
}

void ZebesianGroundSetIdleHitbox(void)
{
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(3.0f);
    gCurrentSprite.hitboxBottom = 0;
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.875f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.875f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    }
}

void ZebesianGroundSetShootingHitbox(void)
{
    if (gCurrentSprite.work2)
    {
        // Crouching
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.0f);
    }
    else
    {
        // Standing
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(3.0f);
    }

    gCurrentSprite.hitboxBottom = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.75f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.75f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    }
}

void ZebesianGroundInit(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.work1 = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        if (gCurrentSprite.spriteId == PSPRITE_ZEBESIAN_PRE_AQUA)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
            {
                gCurrentSprite.status = 0;
                return;
            }

            gCurrentSprite.properties |= SP_CAN_ABSORB_X;
        }
        else
        {
            SpriteUtilTrySetAbsorbXFlag();
            if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
            {
                if (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
                {
                    gCurrentSprite.status = 0;
                    return;
                }

                gCurrentSprite.numberOfXToForm = 2;
            }
        }

        SpriteUtilChooseRandomXFlip();
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_WALKING;
        gCurrentSprite.work1 = 30;
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);
    gCurrentSprite.pOam = sZebesianGroundOam_Walking;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work2 = FALSE;

    ZebesianGroundSetIdleHitbox();
}

void ZebesianGroundSpawningFromX(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (--gCurrentSprite.work1 > 0)
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.work1];
    }
    else if (gCurrentSprite.spriteId == PSPRITE_ZEBESIAN_PRE_AQUA)
    {
        gCurrentSprite.spritesetGfxSlot = 0;
        gCurrentSprite.spriteId = PSPRITE_ZEBESIAN_AQUA;
        gCurrentSprite.properties &= ~SP_CAN_ABSORB_X;
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1.0f);
    }
    else
    {
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_WALKING;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
}

void ZebesianPreAquaTurningintoX(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE_AQUA_ZEBESIAN, gCurrentSprite.spriteId, 0,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.spritesetSlotAndProperties,
            gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f), gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f),
            SPRITE_STATUS_X_FLIP);
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE_AQUA_ZEBESIAN, gCurrentSprite.spriteId, 0,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.spritesetSlotAndProperties,
            gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.375f), gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.25f),
            0);
    }
    else
    {
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE_AQUA_ZEBESIAN, gCurrentSprite.spriteId, 0,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.spritesetSlotAndProperties,
            gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f), gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            SPRITE_STATUS_X_FLIP);
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE_AQUA_ZEBESIAN, gCurrentSprite.spriteId, 0,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.spritesetSlotAndProperties,
            gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.375f), gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.25f),
            0);
    }

    gCurrentSprite.status = 0;
}

void ZebesianGroundTurningIntoX(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_GOLD_ZEBESIAN)
    {
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.4375f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.375f), SPRITE_STATUS_X_FLIP);
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.875f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.375f), 0);
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.3125f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.1875f), SPRITE_STATUS_X_FLIP);
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.75f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.1875f), 0);

        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(2.1875f);
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f),
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f), SPRITE_STATUS_X_FLIP);

            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.25f);
        }
        else
        {
            SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f), SPRITE_STATUS_X_FLIP);

            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.25f);
        }

        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(2.375f);
    }
}

void ZebesianGroundFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.pOam = sZebesianGroundOam_Falling;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    ZebesianGroundSetIdleHitbox();
}

void ZebesianGroundIdleInit(void)
{
    gCurrentSprite.pOam = sZebesianGroundOam_Walking;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_WALKING;

    ZebesianGroundSetIdleHitbox();

    gCurrentSprite.workX = gCurrentSprite.xPosition;
}

void ZebesianGroundIdle(void)
{
    u32 action;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    action = 0;

    if (ZebesianGroundCheckCollidingWithAir())
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
        return;
    }

    SpriteUtilAlignYPositionOnSlopeAtOrigin();
    if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
    {
        // On flat ground
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
            if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
            {
                // On a ledge
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.5f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    // Can't cross 2 block gaps or larger
                    action = 1;
                }
                else
                {
                    // Jump across a 1 block gap
                    action = 2;
                }
            }
            else
            {
                // Not On a ledge
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                {
                    // Hit a wall at its feet
                    action = 1;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.5f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                    {
                        // Hit a wall at its head
                        action = 1;
                    }
                    else
                    {
                        // Move forward
                        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.0625f);
                    }
                }
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
            {
                // On a ledge
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.5f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    // Can't cross 2 block gaps or larger
                    action = 1;
                }
                else
                {
                    // Jump across a 1 block gap
                    action = 2;
                }
            }
            else
            {
                // Not On a ledge
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                {
                    // Hit a wall at its feet
                    action = 1;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.5f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                    {
                        // Hit a wall at its head
                        action = 1;
                    }
                    else
                    {
                        // Move forward
                        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.0625f);
                    }
                }
            }
        }
    }
    else
    {
        // On slope, move forward
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.0625f);
        else
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.0625f);
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        if (gCurrentSprite.currentAnimationFrame == 2 && gCurrentSprite.animationDurationCounter == 1)
            SoundPlay(SOUND_ZEBESIAN_GROUND_FOOTSTEPS);
        else if (gCurrentSprite.currentAnimationFrame == 6 && gCurrentSprite.animationDurationCounter == 1)
            SoundPlay(SOUND_ZEBESIAN_GROUND_FOOTSTEPS);
    }

    if (!ZebesianGroundCheckInRange())
    {
        if (action == 1)
        {
            gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_STANDING_INIT; // No turn around shot
        }
        else if (action == 2)
        {
            gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_JUMP_WARNING_INIT;
            gCurrentSprite.work2 = TRUE; // Low jump or turn around shot
        }
        else if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                if (gCurrentSprite.workX + BLOCK_TO_SUB_PIXEL(4.0f) < gCurrentSprite.xPosition)
                    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_STANDING_INIT;
            }
            else
            {
                if (gCurrentSprite.workX - BLOCK_TO_SUB_PIXEL(4.0f) > gCurrentSprite.xPosition)
                    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_STANDING_INIT;
            }
        }
    }
}

void ZebesianGroundTurningAroundInit(void)
{
    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_TURNING_AROUND_1;
    gCurrentSprite.pOam = sZebesianGroundOam_TurningAround;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void ZebesianGroundTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_TURNING_AROUND_2;
        gCurrentSprite.pOam = sZebesianGroundOam_TurningAroundSecondPart;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }
}

void ZebesianGroundTurningAroundSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        if (gCurrentSprite.work2)
        {
            gCurrentSprite.work2 = FALSE;
            gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_SHOOTING_INIT;
        }
        else
        {
            gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_WALKING_INIT;
        }
    }
}

void ZebesianGroundJumpWarningInit(void)
{
    gCurrentSprite.pOam = sZebesianGroundOam_StartJumping;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_JUMP_WARNING;
}

void ZebesianGroundJumpWarning(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.pOam = sZebesianGroundOam_Jumping;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_JUMPING;
        gCurrentSprite.work4 = 0;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.5f);

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_ZEBESIAN_GROUND_JUMP);
    }
}

// void ZebesianGroundLandingInit(void); // need to do this so the compiler won't throw a warning for some reason

void ZebesianGroundJumping(void)
{
    u32 collided;
    s16 movement;

    collided = FALSE;

    // Check if hit wall, and move forward if not collided
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collided = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.25f),
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                collided = TRUE;
            else
                gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.15625f);
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collided = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.25f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                collided = TRUE;
            else
                gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.15625f);
        }
    }

    if (gCurrentSprite.work2)
    {
        movement = sZebesianGroundJumpingSpeedLow[gCurrentSprite.work4 / 2];
        gCurrentSprite.yPosition += movement;
        if (gCurrentSprite.work4 < ARRAY_SIZE(sZebesianGroundJumpingSpeedLow) * 2 - 1)
            gCurrentSprite.work4++;
    }
    else
    {
        movement = sZebesianGroundJumpingSpeedHigh[gCurrentSprite.work4 / 4];
        gCurrentSprite.yPosition += movement;
        if (gCurrentSprite.work4 < ARRAY_SIZE(sZebesianGroundJumpingSpeedHigh) * 4 - 1)
            gCurrentSprite.work4++;
    }

    if (movement > 0)
    {
        // Moving down, check if touching floor
        u32 blockTop =
            SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = blockTop;
            ZebesianGroundLandingInit();
        }
        else if (!collided)
        {
            // Not hit a wall
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                collided = TRUE;
            }
            else
            {
                blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
                if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                    collided = TRUE;
            }

            if (collided)
            {
                gCurrentSprite.yPosition = blockTop;
                ZebesianGroundLandingInit();
            }
        }
    }
    else
    {
        // Moving up, check if hitting ceiling
        collided = FALSE;
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop,
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collided = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop,
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                collided = TRUE;
        }

        if (collided)
        {
            // Hit ceiling
            ZebesianGroundFallingInit();
        }
    }
}

void ZebesianGroundLandingInit(void)
{
    gCurrentSprite.pOam = sZebesianGroundOam_Landing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_LANDING_AFTER_JUMPING;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_ZEBESIAN_GROUND_LANDING);
}

void ZebesianGroundLanding(void)
{
    u32 hitWall;

    hitWall = FALSE;

    if (!SpriteUtilHasCurrentAnimationNearlyEnded())
        return;

    if (gCurrentSprite.work2)
    {
        // After a low jump over a 1 block gap
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_WALKING_INIT;
        return;
    }

    // After a high jump attack
    if (ZebesianGroundCheckInRange())
        return;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
        {
            hitWall = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.5f),
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                hitWall = TRUE;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
        {
            hitWall = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.5f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                hitWall = TRUE;
        }
    }

    if (hitWall)
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_TURNING_AROUND_INIT;
    else
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_WALKING_INIT;
}

void ZebesianGroundWaitingInit(void)
{
    gCurrentSprite.pOam = sZebesianGroundOam_Standing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_LANDED;

    ZebesianGroundSetIdleHitbox();
}

void ZebesianGroundWaiting(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_WALKING_INIT;
}

void ZebesianGroundStandingInit(void)
{
    gCurrentSprite.pOam = sZebesianGroundOam_Standing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_STANDING;
    gCurrentSprite.work2 = gSpriteRandomNumber / 4 + 2; // Number of times to loop animation
}

void ZebesianGroundStanding(void)
{
    if (ZebesianGroundCheckInRange())
        return;

    if (!SpriteUtilHasCurrentAnimationNearlyEnded())
        return;

    if (--gCurrentSprite.work2 == 0)
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_TURNING_AROUND_INIT;
}

void ZebesianGroundShootingInit(void)
{
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_SHOOTING;
    gCurrentSprite.work1 = CONVERT_SECONDS(1 + 1.f / 6); // Amount of time to wait after shooting

    if (SpriteUtilCheckSamusCrouchingOrMorphed())
    {
        gCurrentSprite.work2 = TRUE;
        gCurrentSprite.pOam = sZebesianGroundOam_ShootingWhileCrouching;
    }
    else
    {
        gCurrentSprite.work2 = FALSE;
        gCurrentSprite.pOam = sZebesianGroundOam_ShootingWhileStanding;
    }

    ZebesianGroundSetShootingHitbox();
}

void ZebesianGroundShooting(void)
{
    if (gCurrentSprite.work2)
    {
        // Crouching
        if (gCurrentSprite.currentAnimationFrame == 6 && gCurrentSprite.animationDurationCounter == 1)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteSpawnSecondary(SSPRITE_ZEBESIAN_GROUND_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.25f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.375f), SPRITE_STATUS_X_FLIP);
                SpriteSpawnSecondary(SSPRITE_ZEBESIAN_GROUND_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.75f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.375f), SPRITE_STATUS_X_FLIP);
            }
            else
            {
                SpriteSpawnSecondary(SSPRITE_ZEBESIAN_GROUND_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.25f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.375f), 0);
                SpriteSpawnSecondary(SSPRITE_ZEBESIAN_GROUND_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.75f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.375f), 0);
            }
        }
    }
    else
    {
        // Standing
        if (gCurrentSprite.currentAnimationFrame == 7 && gCurrentSprite.animationDurationCounter == 1)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteSpawnSecondary(SSPRITE_ZEBESIAN_GROUND_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.875f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.5f), SPRITE_STATUS_X_FLIP);
                SpriteSpawnSecondary(SSPRITE_ZEBESIAN_GROUND_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.625f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.25f), SPRITE_STATUS_X_FLIP);
            }
            else
            {
                SpriteSpawnSecondary(SSPRITE_ZEBESIAN_GROUND_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.875f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.5f), 0);
                SpriteSpawnSecondary(SSPRITE_ZEBESIAN_GROUND_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.625f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.25f), 0);
            }
        }
    }

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_SHOOTING_END_INIT;
}

void ZebesianGroundShootingEndInit(void)
{
    gCurrentSprite.pOam = sZebesianGroundOam_Standing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_SHOOTING_END;

    ZebesianGroundSetIdleHitbox();
}

void ZebesianGroundShootingEnd(void)
{
    u32 nsfb;

    // Basically uses the same checks as the checks from ZebesianGroundCheckInRange()
    if (gSamusData.yPosition + gSamusData.drawDistanceTop / 2 > gCurrentSprite.yPosition)
    {
        // Samus's center is below the zebesian's feet
        gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_WALKING_INIT;
    }
    else
    {
        nsfb = SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(3.0f), BLOCK_TO_SUB_PIXEL(4.0f),
            BLOCK_TO_SUB_PIXEL(13.0f));
        if (nsfb == NSFB_IN_FRONT)
        {
            gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_JUMP_WARNING_INIT;
            gCurrentSprite.work2 = FALSE; // High jump
            gCurrentSprite.work1 = 0;
        }
        else
        {
            if (gCurrentSprite.work1 > 0)
                gCurrentSprite.work1--;

            nsfb = SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(6.0f), BLOCK_TO_SUB_PIXEL(13.0f),
                BLOCK_TO_SUB_PIXEL(13.0f));
            if (nsfb == NSFB_IN_FRONT)
            {
                if (gCurrentSprite.work1 == 0)
                    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_SHOOTING_INIT;
            }
            else if (nsfb == NSFB_BEHIND)
            {
                if (gCurrentSprite.work1 == 0)
                {
                    gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_TURNING_AROUND_INIT;
                    gCurrentSprite.work2 = TRUE; // Turn around shot
                }
            }
            else
            {
                gCurrentSprite.pose = ZEBESIAN_GROUND_POSE_WALKING_INIT;
            }
        }
    }
}

void ZebesianGroundBeamInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(3);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.pOam = sZebesianGroundBeamOam_Spawning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ZEBESIAN_GROUND_BEAM_POSE_SPAWNING;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.bgPriority = 1;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.25f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
        gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.25f);
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_ZEBESIAN_BEAM);
}

void ZebesianGroundBeamSpawning(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sZebesianGroundBeamOam_Extending;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = ZEBESIAN_GROUND_BEAM_POSE_EXTENDING;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
        }
        else
        {
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.5f);
        }
    }
}

void ZebesianGroundBeamExtending(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sZebesianGroundBeamOam_Extended;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = ZEBESIAN_GROUND_BEAM_POSE_EXTENDED;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.5f);
        }
        else
        {
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.5f);
            gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.5f);
        }
    }
}

boolu8 ZebesianGroundCheckSkipMovement(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_ZEBESIAN_PRE_AQUA && gFrameCounter8Bit & 1)
    {
        // Half animation speed
        gCurrentSprite.animationDurationCounter--;
        return TRUE;
    }

    return FALSE;
}

void ZebesianGround(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_ZEBESIAN_HURT);

    gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZebesianGroundInit();
            break;

        case ZEBESIAN_GROUND_POSE_WALKING_INIT:
            ZebesianGroundIdleInit();
        case ZEBESIAN_GROUND_POSE_WALKING:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundIdle();
            break;

        case SPRITE_POSE_LANDED_INIT:
            ZebesianGroundWaitingInit();
        case SPRITE_POSE_LANDED:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundWaiting();
            break;

        case ZEBESIAN_GROUND_POSE_STANDING_INIT:
            ZebesianGroundStandingInit();
        case ZEBESIAN_GROUND_POSE_STANDING:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundStanding();
            break;

        case ZEBESIAN_GROUND_POSE_TURNING_AROUND_INIT:
            ZebesianGroundTurningAroundInit();
        case ZEBESIAN_GROUND_POSE_TURNING_AROUND_1:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundTurningAround();
            break;

        case ZEBESIAN_GROUND_POSE_TURNING_AROUND_2:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundTurningAroundSecondPart();
            break;

        case SPRITE_POSE_FALLING_INIT:
            ZebesianGroundFallingInit();
        case SPRITE_POSE_FALLING:
            if (ZebesianGroundCheckSkipMovement())
                return;
            SpriteUtilCurrentSpriteFall();
            break;

        case ZEBESIAN_GROUND_POSE_JUMP_WARNING_INIT:
            ZebesianGroundJumpWarningInit();
        case ZEBESIAN_GROUND_POSE_JUMP_WARNING:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundJumpWarning();
            break;

        case ZEBESIAN_GROUND_POSE_JUMPING:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundJumping();
            break;

        case ZEBESIAN_GROUND_POSE_LANDING_AFTER_JUMPING:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundLanding();
            break;

        case ZEBESIAN_GROUND_POSE_SHOOTING_INIT:
            ZebesianGroundShootingInit();
        case ZEBESIAN_GROUND_POSE_SHOOTING:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundShooting();
            break;

        case ZEBESIAN_GROUND_POSE_SHOOTING_END_INIT:
            ZebesianGroundShootingEndInit();
        case ZEBESIAN_GROUND_POSE_SHOOTING_END:
            if (ZebesianGroundCheckSkipMovement())
                return;
            ZebesianGroundShootingEnd();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            ZebesianGroundInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            ZebesianGroundSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            if (gCurrentSprite.spriteId == PSPRITE_ZEBESIAN_PRE_AQUA)
            {
                ZebesianPreAquaTurningintoX();
            }
            else
            {
                ZebesianGroundTurningIntoX();
                XParasiteInit();
            }
            break;
    }

    if (gCurrentSprite.spriteId == PSPRITE_GOLD_ZEBESIAN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (!(gSamusData.direction & KEY_RIGHT))
                gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        }
        else
        {
            if ((gSamusData.direction & KEY_RIGHT))
                gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        }
    }
}

void ZebesianGroundBeam(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZebesianGroundBeamInit();
            break;

        case ZEBESIAN_GROUND_BEAM_POSE_SPAWNING:
            ZebesianGroundBeamSpawning();
            break;

        case ZEBESIAN_GROUND_BEAM_POSE_EXTENDING:
            ZebesianGroundBeamExtending();
            break;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.15625f);
    else
        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.15625f);
}
