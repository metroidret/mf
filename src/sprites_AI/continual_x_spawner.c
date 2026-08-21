#include "globals.h"
#include "sprite.h"
#include "x_parasite_util.h"

#include "data/sprites/shake_trigger.h"

#include "constants/sprite.h"

#include "structs/sprite.h"

void ContinualXSpawnerIdle(void)
{
    u16 xPosition;
    u16 yPosition;
    u8 tmp;
    u8 direction;
    u8 i;

    tmp = gFrameCounter8Bit & 3;
    if (tmp == 0)
    {
        xPosition = 1;
        yPosition = gSpriteRandomNumber * BLOCK_TO_PIXEL(.5f);
        direction = 0;
    }
    else if (tmp == 1)
    {
        xPosition = SCREEN_SIZE_X - BLOCK_TO_PIXEL(.125f);
        yPosition = gSpriteRandomNumber * BLOCK_TO_PIXEL(.5f);
        direction = 1;
    }
    else if (tmp == 2)
    {
        yPosition = 1;
        xPosition = gSpriteRandomNumber * BLOCK_TO_PIXEL(1);
        direction = 2;
    }
    else
    {
        yPosition = SCREEN_SIZE_Y - BLOCK_TO_PIXEL(.125f);
        xPosition = gSpriteRandomNumber * BLOCK_TO_PIXEL(1);
        direction = 3;
    }

    yPosition *= SUB_PIXEL_RATIO;
    xPosition *= SUB_PIXEL_RATIO;

    gCurrentSprite.yPosition = yPosition + gBg1YPosition;
    gCurrentSprite.xPosition = xPosition + gBg1XPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    tmp = FALSE;
    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if ((gSpriteData[i].status & SPRITE_STATUS_EXISTS) &&
            (gSpriteData[i].properties & SP_CAN_ABSORB_X) &&
            gSpriteData[i].health > 0 &&
            gSpriteData[i].freezeTimer == 0)
        {
            tmp += TRUE;
            break;
        }
    }

    if (tmp && CountPrimarySpritesThatCantAbsorbX() < 4)
    {
        if (direction == 0)
            xPosition -= BLOCK_SIZE;
        else if (direction == 1)
            xPosition += BLOCK_SIZE;
        else if (direction == 2)
            yPosition -= BLOCK_SIZE;
        else
            yPosition += BLOCK_SIZE;

        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, 0, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.spritesetSlotAndProperties, yPosition, xPosition, 0);
    }
}


void ContinualXSpawner(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.samusCollision = 0;
            gCurrentSprite.pose = SPRITE_POSE_IDLE;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.0625f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.0625f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.0625f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.pOam = sContinualXSpawnerGoldEnemyDoorLockOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;

            if (!gDebugFlag)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

            break;

        case SPRITE_POSE_IDLE:
            ContinualXSpawnerIdle();
            break;
    }
}
