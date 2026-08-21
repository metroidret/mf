#include "data/sprites/electric_water.h"

#include "globals.h"

#include "data/generic_data.h"
#include "data/samus_data.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

void ElectricWaterDamageInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.0f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sElectricWaterDamageOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void ElectricWaterDamageIdle(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gSamusUnderwaterFlag)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.work1 = 0;
    }
}

void ElectricWaterDamageDamagingSamus(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.yPosition = gSamusData.yPosition;
    gCurrentSprite.xPosition = gSamusData.xPosition;

    if (MOD_AND(gCurrentSprite.work1, 32) == 0)
        gCurrentSprite.samusCollision = SSC_YAMEBA;
    else
        gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.work1++;

    if (!gSamusUnderwaterFlag)
    {
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.pOam = sElectricWaterDamageOam_Stopping;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = 0;
    }
}

void ElectricWaterDamageStopping(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.yPosition = gSamusData.yPosition;
    gCurrentSprite.xPosition = gSamusData.xPosition;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pOam = sElectricWaterDamageOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = 0;
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
    }
}

void ElectricWireInit(void)
{
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(3);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sElectricWireOam;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x80);
    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
    }

    if (EventCheckAfter_WaterLowered())
    {
        SoundPlay(SOUND_ELECTRIC_WIRE);
        gCurrentSprite.pose = 0x18;
    }
    else
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
    }
}

void ElectricWireIdle(void)
{
    if (gWaterLowered && gCurrentSprite.currentAnimationFrame == 0)
    {
        SoundPlay(SOUND_ELECTRIC_WIRE);
        gCurrentSprite.pose = 0x18;
    }
}

void ElectricWaterInit(void)
{
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_SUB_PIXEL(2.0f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(7.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(7.5f);
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sElectricWaterOam;

    SoundPlay(SOUND_ELECTRIC_WATER);
}

void ElectricWaterIdle(void)
{
    gCurrentSprite.yPosition = gEffectYPosition + HALF_BLOCK_SIZE;
}

void ElectricWaterDamage(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ElectricWaterDamageInit();
            break;

        case SPRITE_POSE_IDLE:
            ElectricWaterDamageIdle();
            break;

        case 0x18:
            ElectricWaterDamageDamagingSamus();
            break;

        case 0x1a:
            ElectricWaterDamageStopping();
            break;
    }

    if (gWaterLowered)
        gCurrentSprite.status = 0;
}

void ElectricWire(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ElectricWireInit();
            break;

        case SPRITE_POSE_IDLE:
            ElectricWireIdle();
            break;
    }
}

void ElectricWater(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ElectricWaterInit();

        case SPRITE_POSE_IDLE:
            ElectricWaterIdle();
            break;
    }

    if (gWaterLowered)
        gCurrentSprite.status = 0;
}
