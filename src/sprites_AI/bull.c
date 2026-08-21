#include "data/sprites/bull.h"

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

void BullInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.pOam = sBullOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work2 = FALSE; // Smoke active flag
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    SpriteUtilChooseRandomXFlip();
    SpriteUtilChooseRandomXDirection();

    if (gSpriteRandomNumber >= 9)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

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

void BullIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sBullOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 3;
}

void BullIdle(void)
{
    u8 collided;

    collided = FALSE;

    if (--gCurrentSprite.work1 > 0)
        return;

    gCurrentSprite.work1 = 3;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            collided++;
        }
        else
        {
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.0625f);
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            collided++;
        }
        else
        {
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.0625f);
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop,
            gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            collided++;
        }
        else
        {
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.0625f);
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottom,
            gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            collided++;
        }
        else
        {
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.0625f);
        }
    }

    if (collided && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_BULL_BOUNCING);
}

void Bull(void)
{
    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    if (SPRITE_GET_ISFT(gCurrentSprite) == 4 && gCurrentSprite.pose != SPRITE_POSE_UNINITIALIZED &&
        !gCurrentSprite.work2)
    {
        SpriteSpawnSecondary(SSPRITE_BULL_SMOKE, 0, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        SoundPlayNotAlreadyPlaying(SOUND_BULL_RELEASING_SMOKE);
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            BullInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            BullIdleInit();
            break;

        case SPRITE_POSE_IDLE:
            BullIdle();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            BullInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            break;
    }
}

void BullSmoke(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.bgPriority = 1;
        gCurrentSprite.drawOrder = 3;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.pOam = sBullSmokeOam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2.5f);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2.5f);
        gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        gSpriteData[primary].work2 = TRUE;
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame <= 1 || gCurrentSprite.currentAnimationFrame >= 4)
            gCurrentSprite.ignoreSamusCollisionTimer = 1;

        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.status = 0;
            gSpriteData[primary].work2 = FALSE;
        }
    }
}
