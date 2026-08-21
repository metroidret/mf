#include "data/sprites/skultera.h"

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

enum SkulteraSize {
    SKULTERA_SIZE_SMALL_HIDDEN,
    SKULTERA_SIZE_SMALL,
    SKULTERA_SIZE_LARGE
};

void SkulteraSetSidesHitboxes(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
        {
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.625f);
        }
        else
        {
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
        }
    }
    else
    {
        if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
        {
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.375f);
        }
        else
        {
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
        }
    }
}

u8 SkulteraXMovement(u16 movement)
{
    u16 xBoundary;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
            xBoundary = gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.875f);
        else
            xBoundary = gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.625f);

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f), xBoundary);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition += movement;
    }
    else
    {
        if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
            xBoundary = gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.875f);
        else
            xBoundary = gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.625f);

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f), xBoundary);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition -= movement;
    }

    return FALSE;
}

void SkulteraTurningIntoX(void)
{
    if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
    {
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.75f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.25f), 0);
    }
    else
    {
        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
    }
}

void SkulteraInit(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        if (SPRITE_IS_INFECTED(gCurrentSprite))
        {
            if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
                gCurrentSprite.work0 = SKULTERA_SIZE_SMALL_HIDDEN;
            else
                gCurrentSprite.work0 = SKULTERA_SIZE_SMALL;
        }
        else
        {
            gCurrentSprite.status = 0;
            return;
        }

        SpriteUtilChooseRandomXFlip();
        gCurrentSprite.pose = 1;
    }
    else
    {
        gCurrentSprite.work0++;
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
    {
        gCurrentSprite.properties &= ~SP_CAN_ABSORB_X;
        gCurrentSprite.pOam = sSkulteraOam_IdleLarge;
        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2.5f);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
        gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
        gCurrentSprite.frozenPaletteRowOffset = 1;
        gCurrentSprite.spriteId = PSPRITE_SKULTERA_LARGE;
    }
    else
    {
        gCurrentSprite.pOam = sSkulteraOam_IdleSmall;
        if (gCurrentSprite.spriteId != PSPRITE_SKULTERA_SMALL_2)
            gCurrentSprite.properties |= SP_CAN_ABSORB_X;
        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
        gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
        gCurrentSprite.numberOfXToForm = 1;
    }

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    SkulteraSetSidesHitboxes();
}

void SkulteraIdleInit(void)
{
    gCurrentSprite.workX = gCurrentSprite.xPosition;
    gCurrentSprite.pose = 2;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
    {
        gCurrentSprite.pOam = sSkulteraOam_IdleLarge;
        gCurrentSprite.work1 = 3;
    }
    else
    {
        gCurrentSprite.pOam = sSkulteraOam_IdleSmall;
        gCurrentSprite.work1 = 4;
    }
}

void SkulteraIdle(void)
{
    u32 nslr;

    if (--gCurrentSprite.work1 == 0)
    {
        if (SkulteraXMovement(4))
        {
            gCurrentSprite.pose = 3;
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                if (gCurrentSprite.workX + BLOCK_TO_SUB_PIXEL(8.0f) < gCurrentSprite.xPosition)
                    gCurrentSprite.pose = 3;
            }
            else
            {
                if (gCurrentSprite.workX - BLOCK_TO_SUB_PIXEL(8.0f) > gCurrentSprite.xPosition)
                    gCurrentSprite.pose = 3;
            }

            if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
                gCurrentSprite.work1 = 3;
            else
                gCurrentSprite.work1 = 4;
        }
    }

    if (!gSamusUnderwaterFlag)
        return;

    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(10.0f), BLOCK_TO_SUB_PIXEL(1.0f)) !=
        NSLR_OUT_OF_RANGE)
        return;

    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(3.0f), BLOCK_TO_SUB_PIXEL(5.0f));

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (nslr == NSLR_RIGHT)
            gCurrentSprite.pose = 0x29;
        else if (nslr == NSLR_LEFT)
            gCurrentSprite.pose = 3;
    }
    else
    {
        if (nslr == NSLR_LEFT)
            gCurrentSprite.pose = 0x29;
        else if (nslr == NSLR_RIGHT)
            gCurrentSprite.pose = 3;
    }
}

void SkulteraChasingSamusInit(void)
{
    gCurrentSprite.pose = 0x2a;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
        gCurrentSprite.pOam = sSkulteraOam_ChasingLarge;
    else
        gCurrentSprite.pOam = sSkulteraOam_ChasingSmall;
}

void SkulteraChasingSamus(void)
{
    u16 targetY;
    u16 spriteCenterY;
    u32 nslr;

    targetY = gSamusData.yPosition + gSamusData.drawDistanceTop / 2;
    spriteCenterY = gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f);

    if (spriteCenterY - BLOCK_TO_SUB_PIXEL(1.0f) > targetY)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f),
            gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR && gCurrentAffectingClipdata.hazard == HAZARD_WATER)
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.03125f);
    }
    else if (spriteCenterY + BLOCK_TO_SUB_PIXEL(1.0f) < targetY)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.03125f);
    }

    if (--gCurrentSprite.work1 == 0)
    {
        if (SkulteraXMovement(4))
        {
            gCurrentSprite.pose = 3;
        }
        else
        {
            if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
                gCurrentSprite.work1 = 2;
            else
                gCurrentSprite.work1 = 3;
        }
    }

    if (!gSamusUnderwaterFlag)
    {
        gCurrentSprite.pose = 1;
        return;
    }

    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(10.0f), BLOCK_TO_SUB_PIXEL(1.0f)) !=
        NSLR_OUT_OF_RANGE)
        return;

    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(3.0f), BLOCK_TO_SUB_PIXEL(5.0f));
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (nslr == NSLR_RIGHT)
            return;
        else if (nslr == NSLR_LEFT)
            gCurrentSprite.pose = 3;
        else
            gCurrentSprite.pose = 1;
    }
    else
    {
        if (nslr == NSLR_LEFT)
            return;
        else if (nslr == NSLR_RIGHT)
            gCurrentSprite.pose = 3;
        else
            gCurrentSprite.pose = 1;
    }
}

void SkulteraTurningAroundInit(void)
{
    gCurrentSprite.pose = 4;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
    {
        gCurrentSprite.pOam = sSkulteraOam_TurningAroundLarge;
        if (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN) && gSamusUnderwaterFlag &&
            gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_SKULTERA_LARGE_TURNING);
    }
    else
    {
        gCurrentSprite.pOam = sSkulteraOam_TurningAroundSmall;
        if (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN) && gSamusUnderwaterFlag &&
            gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_SKULTERA_SMALL_TURNING);
    }
}

void SkulteraTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        SkulteraIdleInit();
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
        SkulteraSetSidesHitboxes();
    }
}

void Skultera(void)
{
    if (gCurrentSprite.work0 == SKULTERA_SIZE_LARGE)
    {
        if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
            SoundPlayNotAlreadyPlaying(SOUND_SKULTERA_LARGE_HURT);
    }
    else
    {
        if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
            SoundPlayNotAlreadyPlaying(SOUND_SKULTERA_SMALL_HURT);
    }

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SkulteraInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            SkulteraIdleInit();
            break;

        case SPRITE_POSE_IDLE:
            SkulteraIdle();
            break;

        case 3:
            SkulteraTurningAroundInit();
        case 4:
            SkulteraTurningAround();
            break;

        case 0x29:
            SkulteraChasingSamusInit();
        case 0x2a:
            SkulteraChasingSamus();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            SkulteraInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            SkulteraTurningIntoX();
            XParasiteInit();
            break;
    }
}
