#include "data/sprites/toxic_gas.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/samus.h"

#include "structs/samus.h"
#include "structs/sprite.h"

void ToxicGasInit(void)
{
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pOam = sToxicGasOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(3);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(3);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(2.75f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.75f);
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE | SPRITE_STATUS_DOUBLE_SIZE;
    gCurrentSprite.scaling = Q_8_8(1.999f);
    gCurrentSprite.work1 = 0;
    gCurrentSprite.bgPriority = 1;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
}

void ToxicGasIdle(void)
{
    u16 spawnY;
    u16 spawnX;

    gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    if (gCurrentSprite.work1 > 0)
    {
        gCurrentSprite.scaling += Q_8_8(1.f / 128);
        if (gCurrentSprite.scaling >= Q_8_8(1.999f))
            gCurrentSprite.work1--;
    }
    else
    {
        gCurrentSprite.scaling -= Q_8_8(1.f / 128);
        if (gCurrentSprite.scaling < Q_8_8(1.8f))
            gCurrentSprite.work1++;
    }

    if (SPRITE_GET_ISFT(gCurrentSprite) == 1)
    {
        spawnY = gCurrentSprite.yPosition + BLOCK_SIZE;
        spawnX = gCurrentSprite.xPosition + BLOCK_SIZE;
        SpriteSpawnSecondary(SSPRITE_TOXIC_GAS_EXPLOSION, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, spawnY, spawnX, 0);
        SoundPlay(SOUND_TOXIC_GAS_EXPLODE);
    }
}

void ToxicGas(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
        ToxicGasInit();

    ToxicGasIdle();
}

void ToxicGasExplosion(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.pose == 0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.bgPriority = 1;
        gCurrentSprite.drawOrder = 3;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.pOam = sToxicGasExplosionOam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(4);
        gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(4);
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(2.f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.f);
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
        gCurrentSprite.work1 = 16;
        gSpriteData[primary].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    else
    {
        if (gCurrentSprite.work1 > 0)
            gCurrentSprite.work1--;
        else
            gCurrentSprite.ignoreSamusCollisionTimer = 1;

        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.status = 0;
            gSpriteData[primary].status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        }
    }
}
