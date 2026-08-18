#include "sprites_AI/zebesian_aqua.h"
#include "data/sprites/zebesian_aqua.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

enum ZebesianAquaPose {
    ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT = 3,
    ZEBESIAN_AQUA_POSE_TURNING_AROUND = 4,
    ZEBESIAN_AQUA_POSE_SHOOTING_INIT = 0x29,
    ZEBESIAN_AQUA_POSE_SHOOTING = 0x2a,
    ZEBESIAN_AQUA_POSE_LUNGE_INIT = 0x2b,
    ZEBESIAN_AQUA_POSE_LUNGE = 0x2c,
};

#define ZEBESIAN_AQUA_LUNGE_DELAY work1

/**
 * @brief 4c744 | 8c | Moves an aqua zebesian horizontally
 * 
 * @param distance The amount to move
 * @return u8 bool, collided with solid
 */
boolu8 ZebesianAquaXMovement(u16 distance)
{
    u16 xPos;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.work0 == 2)
            xPos = gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(.875f);
        else
            xPos = gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(.625f);

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPos);
        if (gPreviousCollisionCheck != 0x11)
        {
            gCurrentSprite.xPosition = gCurrentSprite.xPosition + distance;
            return FALSE;
        }

        return TRUE;
    }
    else
    {
        if (gCurrentSprite.work0 == 2)
            xPos = gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(.875f);
        else
            xPos = gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(.625f);
    
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPos);
        if (gPreviousCollisionCheck != 0x11)
        {
            gCurrentSprite.xPosition = gCurrentSprite.xPosition - distance;
            return FALSE;
        }
    
        return TRUE;
    }
}

/**
 * @brief 4c7d0 | 40 | Handles an aqua zebesian turning into an X parasite
 * 
 */
void ZebesianAquaTurningIntoX(void)
{
    SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.spritesetSlotAndProperties,
        gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.25f),
        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(.25f), 0);

    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(.5f);
}

/**
 * @brief 4c810 | a4 | Initializes an aqua zebesian
 * 
 */
void ZebesianAquaInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sZebesianAquaOam_Idle;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.75f);
    gCurrentSprite.hitboxBottom = -BLOCK_TO_SUB_PIXEL(.125f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1);

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    
    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = CONVERT_SECONDS(11/15.f);
    }
    else
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }
}

/**
 * @brief 4c8b4 | 2c | Initializes an aqua zebesian to be idle
 * 
 */
void ZebesianAquaIdleInit(void)
{
    gCurrentSprite.workX = gCurrentSprite.xPosition;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pOam = sZebesianAquaOam_Idle;
}

/**
 * @brief 4c8e0 | 184 | Handles an aqua zebesian being idle
 * 
 */
void ZebesianAquaIdle(void)
{
    u16 spriteY;
    u16 samusY;
    s32 nslr;
    u8 pose;

    if (ZebesianAquaXMovement(BLOCK_TO_SUB_PIXEL(3/32.f)))
    {
        gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        // Stay within 8 blocks of where idle started
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gCurrentSprite.workX + BLOCK_TO_SUB_PIXEL(8) < gCurrentSprite.xPosition)
                gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT;
        }
        else
        {
            if (gCurrentSprite.workX - BLOCK_TO_SUB_PIXEL(8) > gCurrentSprite.xPosition)
                gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT;
        }
    }

    if (!(gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT))
    {
        samusY =gSamusData.yPosition + (gSamusData.drawDistanceTop / 2);
        spriteY = gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(.5f);

        if (spriteY - BLOCK_TO_SUB_PIXEL(1) > samusY)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f), gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == 0 && gCurrentAffectingClipdata.hazard == HAZARD_WATER)
                gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1/32.f);
        }
        else if (spriteY + BLOCK_TO_SUB_PIXEL(1) < samusY)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == 0)
                gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(1/32.f);
        }
    }

    if (gSamusUnderwaterFlag && SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(2.5f), BLOCK_TO_SUB_PIXEL(3.125f)) == NSLR_OUT_OF_RANGE)
    {
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(2.5f), BLOCK_TO_SUB_PIXEL(6.25f));

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (nslr == NSLR_RIGHT)
            {
                // Facing Samus
                if (gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT)
                    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_SHOOTING_INIT;
                else
                    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_LUNGE_INIT;
            }
            else if (nslr == NSLR_LEFT)
            {
                // Facing away
                if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
                    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT;
            }
        }
        else
        {
            if (nslr == NSLR_LEFT)
            {
                // Facing Samus
                if (gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT)
                    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_SHOOTING_INIT;
                else
                    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_LUNGE_INIT;
            }
            else if (nslr == NSLR_RIGHT)
            {
                // Facing away
                if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
                    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT;
            }
        }
    }
}

/**
 * @brief 4ca64 | 18 | Initializes an aqua zebesian to lunge
 * 
 */
void ZebesianAquaLungeInit(void)
{
    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_LUNGE;
    gCurrentSprite.ZEBESIAN_AQUA_LUNGE_DELAY = CONVERT_SECONDS(.5f);
}

/**
 * @brief 4ca7c | a0 | Handles an aqua zebesian lunging
 * 
 */
void ZebesianAquaLunge(void)
{
    s32 nslr;

    gCurrentSprite.animationDurationCounter += 4;

    if (gCurrentSprite.ZEBESIAN_AQUA_LUNGE_DELAY > 0)
    {
        gCurrentSprite.ZEBESIAN_AQUA_LUNGE_DELAY--;
        if (gCurrentSprite.ZEBESIAN_AQUA_LUNGE_DELAY == 0)
            SoundPlayNotAlreadyPlaying(SOUND_1BD);
        else
            return;
    }

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck == 0)
        gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(1/32.f);

    if (!ZebesianAquaXMovement(BLOCK_TO_SUB_PIXEL(.25f)))
    {
        if (gSamusUnderwaterFlag && SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(5), BLOCK_TO_SUB_PIXEL(7 + 1/32.f)) == NSLR_OUT_OF_RANGE)
        {
            nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(5), BLOCK_TO_SUB_PIXEL(10));
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                if (nslr == NSLR_LEFT)
                    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT;
            }
            else
            {
                if (nslr == NSLR_RIGHT)
                    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT;
            }
        }
    }
    else
    {
        gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT;
    }
}

/**
 * @brief 4cb1c | 20 | Initializes an aqua zebesian to be shooting
 * 
 */
void ZebesianAquaShootingInit(void)
{
    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_SHOOTING;
    
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    
    gCurrentSprite.pOam = sZebesianAquaOam_Shooting;
}

/**
 * @brief 4cb3c | 138 | Handles an aqua zebesian shooting
 * 
 */
void ZebesianAquaShooting(void)
{
    u16 spriteY;
    u16 samusY;

    samusY = gSamusData.yPosition + (gSamusData.drawDistanceTop / 2);
    spriteY = gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f);
    
    if (spriteY - BLOCK_TO_SUB_PIXEL(1) > samusY)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f), gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0 && gCurrentAffectingClipdata.hazard == HAZARD_WATER)
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1/64.f);
    }
    else if (spriteY + BLOCK_TO_SUB_PIXEL(.5f) < samusY)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == 0)
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(1/64.f);
    }

    ZebesianAquaXMovement(BLOCK_TO_SUB_PIXEL(.125f));

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }
    else if (gCurrentSprite.currentAnimationFrame == 7 && gCurrentSprite.animationDurationCounter == 1)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteSpawnSecondary(SSPRITE_ZEBESIAN_AQUA_PROJECTILE, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1), gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.75f), SPRITE_STATUS_X_FLIP);
            SpriteSpawnSecondary(SSPRITE_ZEBESIAN_AQUA_PROJECTILE, 1, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                 gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(.6875f), gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(.5f), SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ZEBESIAN_AQUA_PROJECTILE, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                 gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1), gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.75f), 0);
            SpriteSpawnSecondary(SSPRITE_ZEBESIAN_AQUA_PROJECTILE, 1, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                 gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(.6875f), gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(.5f), 0);
        }
    }
}

/**
 * @brief 4cc74 | 20 | Initializes an aqua zebesian to be turning around
 * 
 */
void ZebesianAquaTurningAroundInit(void)
{
    gCurrentSprite.pose = ZEBESIAN_AQUA_POSE_TURNING_AROUND;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pOam = sZebesianAquaOam_TurningAround;
}

/**
 * @brief 4cc94 | bc | Handles an aqua zebesian turning around
 * 
 */
void ZebesianAquaTurningAround(void)
{
    u16 samusY;
    u16 spriteY;

    if (!(gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT))
    {
        samusY = gSamusData.yPosition + (gSamusData.drawDistanceTop / 2);
        spriteY = gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f);
        
        if (spriteY - BLOCK_TO_SUB_PIXEL(1) > samusY)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == 0)
                gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(1/32.f);
        }
        else if (spriteY + BLOCK_TO_SUB_PIXEL(.5f) < samusY)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f), gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == 0 && gCurrentAffectingClipdata.hazard == HAZARD_WATER)
                gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1/32.f);
        }
    }

    if (gCurrentSprite.currentAnimationFrame == 1 && gCurrentSprite.animationDurationCounter == 4)
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

/**
 * @brief 4cd50 | a4 | Initializes an aqua zebesian projectile
 * 
 */
void ZebesianAquaProjectileInit(void)
{
    gCurrentSprite.status = gCurrentSprite.status & ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.1875f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.1875f);

    gCurrentSprite.pOam = sZebesianAquaProjectileOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.bgPriority = 1;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = 0;
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.375f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.375f);
        gCurrentSprite.hitboxRight = 0;
    }

    if (gCurrentSprite.roomSlot == 0)
        SoundPlayNotAlreadyPlaying(SOUND_1BC);
}

/**
 * @brief 4cdf4 | 210 | Aqua zebesian AI
 * 
 */
void ZebesianAqua(void)
{
    if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_ZEBESIAN_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }
    
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZebesianAquaInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            ZebesianAquaIdleInit();
            break;

        case SPRITE_POSE_IDLE:
            ZebesianAquaIdle();
            break;

        case ZEBESIAN_AQUA_POSE_TURNING_AROUND_INIT:
            ZebesianAquaTurningAroundInit();

        case ZEBESIAN_AQUA_POSE_TURNING_AROUND:
            ZebesianAquaTurningAround();
            break;

        case ZEBESIAN_AQUA_POSE_SHOOTING_INIT:
            ZebesianAquaShootingInit();

        case ZEBESIAN_AQUA_POSE_SHOOTING:
            ZebesianAquaShooting();
            break;

        case ZEBESIAN_AQUA_POSE_LUNGE_INIT:
            ZebesianAquaLungeInit();

        case ZEBESIAN_AQUA_POSE_LUNGE:
            ZebesianAquaLunge();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            ZebesianAquaInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            ZebesianAquaTurningIntoX();
            XParasiteInit();
            break;
    }
}

/**
 * @brief 4d004 | 34 | Aqua zebesian projectile AI
 * 
 */
void ZebesianAquaProjectile(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
        ZebesianAquaProjectileInit();

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.25f);
    else
        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(.25f);
}
