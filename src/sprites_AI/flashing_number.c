#include "sprites_AI/flashing_number.h"

#include "constants/connection.h"
#include "constants/sprite.h"

#include "structs/sprite.h"

#include "data/sprites/flashing_number.h"

void BigFlashingNumber(void)
{
    u8 slot;
    u8 flashingSector;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
            gCurrentSprite.pose++;
        
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0.f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
        
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.f / 16);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.f / 16);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.f / 16);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.f / 16);
        
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 16;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        
            slot = MOD_AND(gCurrentSprite.spritesetSlotAndProperties, 16);
            flashingSector = GetFlashingSectorNumber();
            flashingSector += AREA_NORMAL_LAST;
        
            if (slot != flashingSector)
            {
                gCurrentSprite.status = 0;
                return;
            }
        
            if (slot == AREA_NORMAL_LAST + AREA_SECTOR_1)
                gCurrentSprite.pOam = sBigFlashingNumberOam_Sector1;
            else if (slot == AREA_NORMAL_LAST + AREA_SECTOR_2)
                gCurrentSprite.pOam = sBigFlashingNumberOam_Sector2;
            else if (slot == AREA_NORMAL_LAST + AREA_SECTOR_3)
                gCurrentSprite.pOam = sBigFlashingNumberOam_Sector3;
            else if (slot == AREA_NORMAL_LAST + AREA_SECTOR_4)
                gCurrentSprite.pOam = sBigFlashingNumberOam_Sector4;
            else if (slot == AREA_NORMAL_LAST + AREA_SECTOR_5)
                gCurrentSprite.pOam = sBigFlashingNumberOam_Sector5;
            else if (slot == AREA_NORMAL_LAST + AREA_SECTOR_6)
                gCurrentSprite.pOam = sBigFlashingNumberOam_Sector6;
            else
                gCurrentSprite.status = 0;
    }
}

void FlashingNumber(void)
{
    u8 slot;
    u8 flashingSector;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
            gCurrentSprite.pose++;
        
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0.f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
        
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.f / 16);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.f / 16);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.f / 16);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.f / 16);
        
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 16;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        
            slot = MOD_AND(gCurrentSprite.spritesetSlotAndProperties, 8);
            flashingSector = GetFlashingSectorNumber();
        
            if (slot != flashingSector)
            {
                gCurrentSprite.status = 0;
                return;
            }
        
            if (slot == AREA_SECTOR_1)
                gCurrentSprite.pOam = sFlashingNumberOam_Sector1;
            else if (slot == AREA_SECTOR_2)
                gCurrentSprite.pOam = sFlashingNumberOam_Sector2;
            else if (slot == AREA_SECTOR_3)
                gCurrentSprite.pOam = sFlashingNumberOam_Sector3;
            else if (slot == AREA_SECTOR_4)
                gCurrentSprite.pOam = sFlashingNumberOam_Sector4;
            else if (slot == AREA_SECTOR_5)
                gCurrentSprite.pOam = sFlashingNumberOam_Sector5;
            else if (slot == AREA_SECTOR_6)
                gCurrentSprite.pOam = sFlashingNumberOam_Sector6;
            else
                gCurrentSprite.status = 0;
    }
}
