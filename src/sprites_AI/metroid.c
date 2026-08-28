#include "sprites_AI/metroid.h"
#include "data/sprites/metroid.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"

#include "constants/audio.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

enum MetroidPose {
    METROID_POSE_FLOATING_NEAR_SA_X = 0x18,
    METROID_POSE_FLOATING_TOWARD_SA_X = 0x1a,
    METROID_POSE_SWAYING = 0x1c,
};

enum MetroidSaX {
    METROID_SA_X_NONE,
    METROID_SA_X_BOTTOM,
    METROID_SA_X_MIDDLE,
    METROID_SA_X_TOP
};

#define METROID_SA_X work0
#define METROID_X_SPEED_IDX work3
#define METROID_Y_SPEED_IDX work4

/**
 * @brief 4eaec | 228 | Initializes a metroid
 * 
 */
void MetroidInit(void)
{
    s32 prop;
    u16 samusY;
    u16 spriteY;
    u8 randNum;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.0625);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625);

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = MOD_AND(gSpriteRandomNumber, 4);
    prop = gCurrentSprite.spritesetSlotAndProperties & SSP_PROPERTY_MASK;

    if (EventCheckOn_RestrictedLabExplosion())
    {
        gCurrentSprite.samusCollision = SSC_KNOCKS_BACK_SAMUS;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.drawOrder = 3;
        gCurrentSprite.bgPriority = 1;
        gCurrentSprite.pose = METROID_POSE_FLOATING_NEAR_SA_X;
        gCurrentSprite.pOam = sMetroidOam_Idle;
        gCurrentSprite.workY = CONVERT_SECONDS(3);

#ifdef BUGFIX
        samusY = BLOCK_TO_SUB_PIXEL(sAreaDoorPointers[gCurrentArea][gLastDoorUsed].yEnd);
#else // !BUGFIX
        // BUG: If Samus jumps through the door, one of the first two conditions below
        // can be true for multiple Metroids, resulting in them having the same behavior
        samusY = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(.0625);
#endif // BUGFIX
        spriteY = gCurrentSprite.yPosition;

        if (samusY - BLOCK_TO_SUB_PIXEL(5) < spriteY)
        {
            gCurrentSprite.METROID_SA_X = METROID_SA_X_BOTTOM;
            gCurrentSprite.METROID_Y_SPEED_IDX = ARRAY_SIZE(sMetroidSwayingYSpeeds) / 2;
            gCurrentSprite.METROID_X_SPEED_IDX = 0;
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(3);
        }
        else if (samusY - BLOCK_TO_SUB_PIXEL(6) < spriteY)
        {
            gCurrentSprite.METROID_SA_X = METROID_SA_X_MIDDLE;
            gCurrentSprite.METROID_Y_SPEED_IDX = 0;
            gCurrentSprite.METROID_X_SPEED_IDX = ARRAY_SIZE(sMetroidSwayingXSpeeds) * 3 / 4;
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(3);
        }
        else if (samusY - BLOCK_TO_SUB_PIXEL(7) < spriteY)
        {
            gCurrentSprite.METROID_SA_X = METROID_SA_X_TOP;
            gCurrentSprite.METROID_Y_SPEED_IDX = ARRAY_SIZE(sMetroidSwayingYSpeeds) * 3 / 4;
            gCurrentSprite.METROID_X_SPEED_IDX = ARRAY_SIZE(sMetroidSwayingXSpeeds) / 2;
        }
        else
        {
            randNum = gSpriteRandomNumber * 4;
            gCurrentSprite.METROID_X_SPEED_IDX = randNum;
            gCurrentSprite.METROID_Y_SPEED_IDX = randNum;
            gCurrentSprite.METROID_SA_X = METROID_SA_X_NONE;
            gCurrentSprite.pose = METROID_POSE_SWAYING;
        }
    }
    else
    {
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.bgPriority = 3;
        gCurrentSprite.drawOrder = 12;
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
        
        randNum = gSpriteRandomNumber * 2;
        gCurrentSprite.METROID_X_SPEED_IDX = randNum;
        gCurrentSprite.METROID_Y_SPEED_IDX = randNum;

        SpriteUtilChooseRandomXDirection();

        if (gSpriteRandomNumber & 1)
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
        else
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

        if (prop == SSP_UNINFECTED_OR_BOSS)
        {
            // Smaller metroid in background
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.pOam = sMetroidOam_Background;
        }
        else
        {
            gCurrentSprite.pOam = sMetroidOam_Idle;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                gCurrentSprite.yPosition += gSpriteRandomNumber;
            else
                gCurrentSprite.yPosition -= gSpriteRandomNumber;
    
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += gSpriteRandomNumber * 2;
            else
                gCurrentSprite.xPosition -= gSpriteRandomNumber * 2;
        }
    }
}

/**
 * @brief 4ed14 | 64 | Handles a metroid swaying
 * 
 */
void MetroidSwaying(void)
{
    u8 index;
    s16 yDistance;
    s16 xDistance;

    index = gCurrentSprite.METROID_Y_SPEED_IDX;
    yDistance = sMetroidSwayingYSpeeds[index];
    if (yDistance == SHORT_MAX)
    {
        yDistance = sMetroidSwayingYSpeeds[0];
        index = 0;
    }
    gCurrentSprite.METROID_Y_SPEED_IDX = index + 1;
    gCurrentSprite.yPosition += yDistance;

    index = gCurrentSprite.METROID_X_SPEED_IDX;
    xDistance = sMetroidSwayingXSpeeds[index];
    if (xDistance == SHORT_MAX)
    {
        xDistance = sMetroidSwayingXSpeeds[0];
        index = 0;
    }
    gCurrentSprite.METROID_X_SPEED_IDX = index + 1;
    gCurrentSprite.xPosition += xDistance;
}

/**
 * @brief 4ed78 | 2e4 | Handles a metroid floating in tube
 * 
 */
void MetroidFloatingInTube(void)
{
    boolu8 changeDirection;
    u8 index;
    s16 yDistance;
    u16 screenY;
    s16 xDistance;
    u16 screenX;

    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    changeDirection = FALSE;

    if ((gCurrentSprite.spritesetSlotAndProperties & SSP_PROPERTY_MASK) == SSP_UNINFECTED_OR_BOSS)
    {
        index = gCurrentSprite.METROID_Y_SPEED_IDX;
        yDistance = sMetroidBackgroundFloatingYSpeeds[index];
        if (yDistance == SHORT_MAX)
        {
            if (gSpriteRandomNumber < SPRITE_RNG_PROB(.25f))
                gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
    
            gCurrentSprite.METROID_Y_SPEED_IDX = 0;
        }
        else
        {
            gCurrentSprite.METROID_Y_SPEED_IDX++;

            screenY = SUB_PIXEL_TO_PIXEL(gCurrentSprite.yPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition);
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            {
                if (screenY > SCREEN_Y_MIDDLE + 8)
                    changeDirection += TRUE;
            }
            else
            {
                if (screenY < SCREEN_Y_MIDDLE - 20)
                    changeDirection += TRUE;
            }
    
            if (changeDirection)
            {
                gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
                if (gCurrentSprite.drawOrder == 12)
                    gCurrentSprite.drawOrder = 13;
                else
                    gCurrentSprite.drawOrder = 12;
            }
    
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                gCurrentSprite.yPosition += yDistance;
            else
                gCurrentSprite.yPosition -= yDistance;
        }

        index = gCurrentSprite.METROID_X_SPEED_IDX;
        xDistance = sMetroidBackgroundFloatingXSpeeds[index];
        if (xDistance == SHORT_MAX)
        {
            if (gSpriteRandomNumber < SPRITE_RNG_PROB(.25f))
                gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

            gCurrentSprite.METROID_X_SPEED_IDX = 0;
        }
        else
        {
            gCurrentSprite.METROID_X_SPEED_IDX++;
    
            screenX = SUB_PIXEL_TO_PIXEL(gCurrentSprite.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
            if (screenX < SCREEN_X_MIDDLE)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (screenX > SCREEN_X_MIDDLE - 56)
                        changeDirection += TRUE;
                }
                else
                {
                    if (screenX < SCREEN_X_MIDDLE - 80)
                        changeDirection += TRUE;
                }
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (screenX > SCREEN_X_MIDDLE + 80)
                        changeDirection += TRUE;
                }
                else
                {
                    if (screenX < SCREEN_X_MIDDLE + 56)
                        changeDirection += TRUE;
                }
            }
    
            if (changeDirection)
            {
                gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    
                if (gCurrentSprite.drawOrder == 12)
                    gCurrentSprite.drawOrder = 13;
                else
                    gCurrentSprite.drawOrder = 12;
            }
    
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += xDistance;
            else
                gCurrentSprite.xPosition -= xDistance;
        }
    }
    else
    {
        index = gCurrentSprite.METROID_Y_SPEED_IDX;
        yDistance = sMetroidFloatingYSpeeds[index];
        if (yDistance == SHORT_MAX)
        {
            if (gSpriteRandomNumber < SPRITE_RNG_PROB(.25f))
                gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;

            gCurrentSprite.METROID_Y_SPEED_IDX = 0;
        }
        else
        {
            gCurrentSprite.METROID_Y_SPEED_IDX++;

            screenY = SUB_PIXEL_TO_PIXEL(gCurrentSprite.yPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition);
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            {
                if (screenY > SCREEN_Y_MIDDLE + 20)
                    changeDirection += TRUE;
            }
            else
            {
                if (screenY < SCREEN_Y_MIDDLE - 50)
                    changeDirection += TRUE;
            }
    
            if (changeDirection)
            {
                gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
    
                if (gCurrentSprite.drawOrder == 12)
                    gCurrentSprite.drawOrder = 13;
                else
                    gCurrentSprite.drawOrder = 12;
            }
    
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                gCurrentSprite.yPosition += yDistance;
            else
                gCurrentSprite.yPosition -= yDistance;
        }

        index = gCurrentSprite.METROID_X_SPEED_IDX;
        xDistance = sMetroidFloatingXSpeeds[index];
        if (xDistance == SHORT_MAX)
        {
            if (gSpriteRandomNumber < SPRITE_RNG_PROB(.25f))
                gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

            gCurrentSprite.METROID_X_SPEED_IDX = 0;
        }
        else
        {
            gCurrentSprite.METROID_X_SPEED_IDX++;

            screenX = SUB_PIXEL_TO_PIXEL(gCurrentSprite.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (screenX > SCREEN_X_MIDDLE + 20)
                    changeDirection += TRUE;
            }
            else
            {
                if (screenX < SCREEN_X_MIDDLE - 20)
                    changeDirection += TRUE;
            }
    
            if (changeDirection)
            {
                gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    
                if (gCurrentSprite.drawOrder == 12)
                    gCurrentSprite.drawOrder = 13;
                else
                    gCurrentSprite.drawOrder = 12;
            }
    
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += xDistance;
            else
                gCurrentSprite.xPosition -= xDistance;
        }
    }
}

/**
 * @brief 4f05c | c0 | Handles a metroid floating near SA-X
 * 
 */
void MetroidFloatingNearSaX(void)
{
    u8 index;
    s16 yDistance;
    s16 xDistance;

    index = gCurrentSprite.METROID_Y_SPEED_IDX;
    yDistance = sMetroidSwayingYSpeeds[index];
    if (yDistance == SHORT_MAX)
    {
        yDistance = sMetroidSwayingYSpeeds[0];
        index = 0;
    }
    gCurrentSprite.METROID_Y_SPEED_IDX = index + 1;
    gCurrentSprite.yPosition += yDistance;

    index = gCurrentSprite.METROID_X_SPEED_IDX;
    xDistance = sMetroidSwayingXSpeeds[index];
    if (xDistance == SHORT_MAX)
    {
        xDistance = sMetroidSwayingXSpeeds[0];
        index = 0;
    }
    gCurrentSprite.METROID_X_SPEED_IDX = index + 1;
    gCurrentSprite.xPosition += xDistance;

    gCurrentSprite.workY--;
    if (gCurrentSprite.workY == 0)
    {
        gCurrentSprite.pose = METROID_POSE_FLOATING_TOWARD_SA_X;

        gCurrentSprite.SPRITE_X_SPEED_DEC = 0;
        gCurrentSprite.SPRITE_X_SPEED_INC = 1;
        gCurrentSprite.SPRITE_Y_SPEED_DEC = 0;
        gCurrentSprite.SPRITE_Y_SPEED_INC = 1;

        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;

        if (gCurrentSprite.METROID_SA_X == METROID_SA_X_BOTTOM)
            SoundPlay(SOUND_23A);
    }
}

/**
 * @brief 4f11c | 348 | Handles a metroid floating toward SA-X
 * 
 */
void MetroidFloatingTowardSaX(void)
{
    u16 spriteY;
    u16 spriteX;
    s32 offset;
    u8 i;

    u8 randNum;
    u16 targetY;
    u16 targetX;
    u32 ySpeedCap;
    u32 xSpeedCap;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    offset = BLOCK_TO_SUB_PIXEL(.25f);

    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING))
    {
        for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
        {
            if ((gSpriteData[i].status & SPRITE_STATUS_EXISTS) &&
                !(gSpriteData[i].properties & SP_SECONDARY_SPRITE) &&
                (gSpriteData[i].spriteId == PSPRITE_SA_X_LAB))
            {
                targetY = gSpriteData[i].yPosition;
                targetX = gSpriteData[i].xPosition;
                
                if (spriteY + offset > targetY - BLOCK_TO_SUB_PIXEL(1.875f) && spriteY - offset < targetY &&
                    spriteX + offset > targetX - BLOCK_TO_SUB_PIXEL(.3125f) && spriteX - offset < targetX + BLOCK_TO_SUB_PIXEL(.3125f))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                    gCurrentSprite.SPRITE_X_SPEED_DEC = 0;
                    gCurrentSprite.SPRITE_X_SPEED_INC = 1;
                    gCurrentSprite.SPRITE_Y_SPEED_DEC = 0;
                    gCurrentSprite.SPRITE_Y_SPEED_INC = 1;

                    if (gSpriteData[i].pose == SPRITE_POSE_IDLE)
                    {
                        gSpriteData[i].pose = METROID_POSE_FLOATING_NEAR_SA_X;
                        SoundPlay(SOUND_23B);
                    }
                }
            }
        }
    }

    randNum = gSpriteRandomNumber;

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (gCurrentSprite.METROID_SA_X == METROID_SA_X_BOTTOM)
        {
            targetY = gXParasiteTargetYPosition - BLOCK_TO_SUB_PIXEL(1.25f) - randNum;
            targetX = gXParasiteTargetXPosition - BLOCK_TO_SUB_PIXEL(.5f) + randNum;
        }
        else if (gCurrentSprite.METROID_SA_X == METROID_SA_X_MIDDLE)
        {
            targetY = gXParasiteTargetYPosition - BLOCK_TO_SUB_PIXEL(25/32.f) - randNum;
            targetX = gXParasiteTargetXPosition + BLOCK_TO_SUB_PIXEL(.125f) - randNum;
        }
        else // METROID_SA_X_TOP
        {
            targetY = gXParasiteTargetYPosition - BLOCK_TO_SUB_PIXEL(1.875f) + randNum;
            targetX = gXParasiteTargetXPosition + BLOCK_TO_SUB_PIXEL(.5f) - randNum;
        }

        ySpeedCap = 10;
        xSpeedCap = 10;
    }
    else
    {
        if (gCurrentSprite.METROID_SA_X == METROID_SA_X_BOTTOM)
        {
            targetY = gXParasiteTargetYPosition - BLOCK_TO_SUB_PIXEL(1.125f);
            targetX = gXParasiteTargetXPosition - BLOCK_TO_SUB_PIXEL(.5625f);
        }
        else if (gCurrentSprite.METROID_SA_X == METROID_SA_X_MIDDLE)
        {
            targetY = gXParasiteTargetYPosition - BLOCK_TO_SUB_PIXEL(25/32.f);
            targetX = gXParasiteTargetXPosition + BLOCK_TO_SUB_PIXEL(.125f);
        }
        else // METROID_SA_X_TOP
        {
            targetY = gXParasiteTargetYPosition - BLOCK_TO_SUB_PIXEL(1.5625f);
            targetX = gXParasiteTargetXPosition + BLOCK_TO_SUB_PIXEL(15/32.f);
        }

        ySpeedCap = 20;
        xSpeedCap = 30;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.SPRITE_X_SPEED_DEC == 0)
        {
            if (gCurrentSprite.xPosition <= targetX - 4)
            {
                if (gCurrentSprite.SPRITE_X_SPEED_INC < xSpeedCap)
                    gCurrentSprite.SPRITE_X_SPEED_INC++;

                gCurrentSprite.xPosition += DIV_SHIFT(gCurrentSprite.SPRITE_X_SPEED_INC, 4);
            }
            else
            {
                gCurrentSprite.SPRITE_X_SPEED_DEC = gCurrentSprite.SPRITE_X_SPEED_INC;
            }
        }
        else
        {
            if (--gCurrentSprite.SPRITE_X_SPEED_DEC > 0)
            {
                gCurrentSprite.xPosition += DIV_SHIFT(gCurrentSprite.SPRITE_X_SPEED_DEC, 4);
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.SPRITE_X_SPEED_INC = 1;
            }
        }
    }
    else
    {
        if (gCurrentSprite.SPRITE_X_SPEED_DEC == 0)
        {
            if (gCurrentSprite.xPosition < targetX + 4)
            {
                gCurrentSprite.SPRITE_X_SPEED_DEC = gCurrentSprite.SPRITE_X_SPEED_INC;
            }
            else
            {
                if (gCurrentSprite.SPRITE_X_SPEED_INC < xSpeedCap)
                    gCurrentSprite.SPRITE_X_SPEED_INC++;
    
                gCurrentSprite.xPosition -= DIV_SHIFT(gCurrentSprite.SPRITE_X_SPEED_INC, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.SPRITE_X_SPEED_DEC > 0)
            {
                gCurrentSprite.xPosition -= DIV_SHIFT(gCurrentSprite.SPRITE_X_SPEED_DEC, 4);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.SPRITE_X_SPEED_INC = 1;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.SPRITE_Y_SPEED_DEC == 0)
        {
            if (gCurrentSprite.yPosition <= targetY - 4)
            {
                if (gCurrentSprite.SPRITE_Y_SPEED_INC < ySpeedCap)
                    gCurrentSprite.SPRITE_Y_SPEED_INC++;

                gCurrentSprite.yPosition += DIV_SHIFT(gCurrentSprite.SPRITE_Y_SPEED_INC, 4);
            }
            else
            {
                gCurrentSprite.SPRITE_Y_SPEED_DEC = gCurrentSprite.SPRITE_Y_SPEED_INC;
            }
        }
        else
        {
            if (--gCurrentSprite.SPRITE_Y_SPEED_DEC > 0)
            {
                gCurrentSprite.yPosition += DIV_SHIFT(gCurrentSprite.SPRITE_Y_SPEED_DEC, 4);
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.SPRITE_Y_SPEED_INC = 1;
            }
        }
    }
    else
    {
        if (gCurrentSprite.SPRITE_Y_SPEED_DEC == 0)
        {
            if (gCurrentSprite.yPosition < targetY + 4)
            {
                gCurrentSprite.SPRITE_Y_SPEED_DEC = gCurrentSprite.SPRITE_Y_SPEED_INC;
            }
            else
            {
                if (gCurrentSprite.SPRITE_Y_SPEED_INC < ySpeedCap)
                    gCurrentSprite.SPRITE_Y_SPEED_INC++;
    
                gCurrentSprite.yPosition -= DIV_SHIFT(gCurrentSprite.SPRITE_Y_SPEED_INC, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.SPRITE_Y_SPEED_DEC > 0)
            {
                gCurrentSprite.yPosition -= DIV_SHIFT(gCurrentSprite.SPRITE_Y_SPEED_DEC, 4);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.SPRITE_Y_SPEED_INC = 1;
            }
        }
    }
}

/**
 * @brief 4f464 | b4 | Metroid AI
 * 
 */
void Metroid(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MetroidInit();
            break;

        case SPRITE_POSE_IDLE:
            MetroidFloatingInTube();
            break;

        case METROID_POSE_FLOATING_NEAR_SA_X:
            MetroidFloatingNearSaX();
            break;

        case METROID_POSE_FLOATING_TOWARD_SA_X:
            MetroidFloatingTowardSaX();
            break;

        case METROID_POSE_SWAYING:
            MetroidSwaying();
            break;
    }
}
