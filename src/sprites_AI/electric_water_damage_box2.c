#include "globals.h"
#include "sprite.h"

#include "data/sprite_data.h"
#include "data/sprites/electric_water_damage_box2.h"

#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/event.h"

#include "structs/samus.h"
#include "structs/sprite.h"

#define ELECTRIC_WATER_DAMAGE_BOX2_POSE_DAMAGING_SAMUS 0x18
#define ELECTRIC_WATER_DAMAGE_BOX2_POSE_STOPPING 0x1A

void ElectricWaterDamageBox2Init(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sElectricWaterDamageBox2Oam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}


void ElectricWaterDamageBox2Idle(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gSamusUnderwaterFlag)
    {
        gCurrentSprite.pose = ELECTRIC_WATER_DAMAGE_BOX2_POSE_DAMAGING_SAMUS;
        gCurrentSprite.work1 = 0;
    }
}


void ElectricWaterDamageBox2DamagingSamus(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.yPosition = gSamusData.yPosition;
    gCurrentSprite.xPosition = gSamusData.xPosition;

    if ((gCurrentSprite.work1 & 3) == 0)
    {
        gCurrentSprite.samusCollision = SSC_YAMEBA;
    }
    else
    {
        gCurrentSprite.samusCollision = SSC_NONE;
    }

    gCurrentSprite.work1++;
    if (!gSamusUnderwaterFlag)
    {
        gCurrentSprite.pose = ELECTRIC_WATER_DAMAGE_BOX2_POSE_STOPPING;
        gCurrentSprite.pOam = sElectricWaterDamageBox2Oam_Stopping;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = SSC_NONE;
    }
}


void ElectricWaterDamageBox2Stopping(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.yPosition = gSamusData.yPosition;
    gCurrentSprite.xPosition = gSamusData.xPosition;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pOam = sElectricWaterDamageBox2Oam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
    }
}


void ElectricWaterDamageBox2(void) {
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ElectricWaterDamageBox2Init();
            break;

        case SPRITE_POSE_IDLE:
            ElectricWaterDamageBox2Idle();
            break;

        case ELECTRIC_WATER_DAMAGE_BOX2_POSE_DAMAGING_SAMUS:
            ElectricWaterDamageBox2DamagingSamus();
            break;

        case ELECTRIC_WATER_DAMAGE_BOX2_POSE_STOPPING:
            ElectricWaterDamageBox2Stopping();
            break;
    }

    if (gCurrentEventBasedEffect & EVENT_EFFECT_80)
    {
        gCurrentSprite.status = 0;
    }
}
