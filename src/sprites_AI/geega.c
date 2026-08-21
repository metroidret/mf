#include "data/sprites/geega.h"

#include "globals.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

void GeegaSpawningFromX(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (--gCurrentSprite.work1 > 0)
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.work1];
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = 1;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }
}

void GeegaInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.4375f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.4375f);
    gCurrentSprite.pOam = sGeegaOam_GoingUp;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.work1 = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        gCurrentSprite.pose = 1;
        gCurrentSprite.workY = gCurrentSprite.yPosition;
        gCurrentSprite.workX = gCurrentSprite.xPosition;
        gCurrentSprite.work1 = 0;
    }
}

void GeegaIdle(void)
{
    if (gCurrentSprite.work1 > 0)
    {
        gCurrentSprite.work1--;
    }
    else
    {
        if (gSamusData.yPosition < gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.9375f) &&
            SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(7.0f), BLOCK_TO_SUB_PIXEL(6.0f)) !=
                NSLR_OUT_OF_RANGE)
        {
            SpriteUtilMakeSpriteFaceSamusXFlip();
            gCurrentSprite.pose = 2;
            gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
            gCurrentSprite.work1 = 20;
        }
    }
}

void GeegaGoingUp(void)
{
    u16 y;
    u16 x;

    y = gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f);
    x = gCurrentSprite.xPosition;

    if (gCurrentSprite.work1 > 0)
    {
        gCurrentSprite.work1--;
        if (gCurrentSprite.work1 == 18)
        {
            SpriteDebrisInit(0, 0x11, y - BLOCK_TO_SUB_PIXEL(1.5f), x);
            SpriteDebrisInit(0, 0x12, y - BLOCK_TO_SUB_PIXEL(1.5f), x + BLOCK_TO_SUB_PIXEL(0.25f));
        }
        else if (gCurrentSprite.work1 == 12)
        {
            SpriteDebrisInit(0, 0x13, y - BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(0.25f));
            SpriteDebrisInit(0, 4, y - BLOCK_TO_SUB_PIXEL(1.0f), x);
        }
        else if (gCurrentSprite.work1 == 7)
        {
            SpriteDebrisInit(0, 0x11, y - BLOCK_TO_SUB_PIXEL(0.5f), x + BLOCK_TO_SUB_PIXEL(0.125f));
            SpriteDebrisInit(0, 0x12, y - BLOCK_TO_SUB_PIXEL(0.5f), x - BLOCK_TO_SUB_PIXEL(0.25f));
        }
        else if (gCurrentSprite.work1 == 3)
        {
            SpriteDebrisInit(0, 0x13, y, x - BLOCK_TO_SUB_PIXEL(0.125f));
            SpriteDebrisInit(0, 4, y, x + BLOCK_TO_SUB_PIXEL(0.25f));
        }
        else if (gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.scaling = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(0.9375f);
        }
    }
    else
    {
        if (gCurrentSprite.scaling < gCurrentSprite.yPosition)
        {
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.0625f);
        }
        else
        {
            gCurrentSprite.work1 = 20;
            gCurrentSprite.pOam = sGeegaOam_GoingForward;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pose = 0x18;
        }
    }
}

void GeegaGoingForward(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.09375f);
    else
        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.09375f);

    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
    {
        gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
        gCurrentSprite.pose = 1;
        gCurrentSprite.yPosition = gCurrentSprite.workY;
        gCurrentSprite.xPosition = gCurrentSprite.workX;
        gCurrentSprite.pOam = sGeegaOam_GoingUp;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work1 = 120;
    }
}

void Geega(void)
{
    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GeegaInit();
            break;

        case 1:
            GeegaIdle();
            break;

        case 2:
            GeegaGoingUp();
            break;

        case 0x18:
            GeegaGoingForward();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            GeegaInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            GeegaSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            break;
    }
}
