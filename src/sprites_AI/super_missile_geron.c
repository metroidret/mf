#include "sprites_AI/super_missile_geron.h"
#include "macros.h"
#include "globals.h"
#include "sprite_util.h"

#include "data/sprites/super_missile_geron.h"
#include "data/sprites/x_parasite.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/samus.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 41e84 | 12c | Iniializes a super missile geron
 * 
 */
void SuperMissileGeronInit(void)
{
    u8 spriteId;
    u16 geronBit;
    
    SpriteUtilTrySetAbsorbXFlag();

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        // All geron sprite ids are next to each other numerically, so doing spriteId - firstGeronId offsets the id to start at 0
        spriteId = gCurrentSprite.spriteId;
        spriteId -= PSPRITE_GERON_SUPER_MISSILE_1;

        // Get bit affected by the current geron
        geronBit = gSuperMissileGeronsDestroyed >> spriteId;

        if (geronBit & 1)
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.pose = SPRITE_POSE_IDLE;
    }

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

    gCurrentSprite.pOam = sSuperMissileGeronOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = BLOCK_SIZE - QUARTER_BLOCK_SIZE;
        return;
    }

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = BLOCK_SIZE - QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    spriteId = SpriteSpawnSecondary(SSPRITE_GERON_SUPER_MISSILE_STEM, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

    if (spriteId == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
        return;
    }

    GeronSetCollision(CAA_MAKE_SOLID_STOP_ENEMY);
}

/**
 * @brief 41fb0 | 20 | Initializes a super missile geron to be idle
 * 
 */
void SuperMissileGeronIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;

    gCurrentSprite.pOam = sSuperMissileGeronOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 41fd0 | 20 | Handles a super missile geron being idle
 * 
 */
void SuperMissileGeronIdle(void)
{
    return;
}

/**
 * @brief 41fd4 | 30 | Handles a super missile geron dying
 * 
 */
void SuperMissileGeronDying(void)
{
    u8 spriteId;
    u16 geronBit;

    // All geron sprite ids are next to each other numerically, so doing spriteId - firstGeronId offsets the id to start at 0
    spriteId = gCurrentSprite.spriteId;
    spriteId -= PSPRITE_GERON_SUPER_MISSILE_1;

    // Get bit affected by the current geron
    geronBit = 1 << spriteId;

    gSuperMissileGeronsDestroyed |= geronBit;

    GeronSetCollision(CAA_REMOVE_SOLID);
}

/**
 * @brief 42004 | b0 | Super missile geron AI
 * 
 */
void SuperMissileGeron(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 0x4)
        SoundPlayNotAlreadyPlaying(0x160);

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(SSPRITE_GERON_SUPER_MISSILE_STEM, gCurrentSprite.primarySpriteRamSlot);
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SuperMissileGeronInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            SuperMissileGeronIdleInit();

        case SPRITE_POSE_IDLE:
            SuperMissileGeronIdle();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteUtilUnfreezeSecondarySprites(SSPRITE_GERON_SUPER_MISSILE_STEM, gCurrentSprite.primarySpriteRamSlot);
            SuperMissileGeronDying();
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            SuperMissileGeronInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
    }
}

/**
 * @brief 420b4 | 13c | Super missile geron stem AI
 * 
 */
void SuperMissileGeronStem(void)
{
    u8 ramSlot;
    
    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdatePrimarySpriteFreezeTimerOfCurrent();
        return;
    }

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.pose = SPRITE_POSE_IDLE;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

            gCurrentSprite.drawOrder = 6;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

            gCurrentSprite.pOam = sSuperMissileGeronStemOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            break;

        case SPRITE_POSE_IDLE:
            if (gSpriteData[ramSlot].health == 0)
            {
                gCurrentSprite.pose = 0x18;

                gCurrentSprite.pOam = sSuperMissileGeronStemOam_Destroyed;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.health = 0;
                gCurrentSprite.ignoreSamusCollisionTimer = 1;
            }
            break;

        case 0x18:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;

            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.status = 0;
            }
            break;
    }

    if (gSpriteData[ramSlot].status & SPRITE_STATUS_MOSAIC)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }
}
