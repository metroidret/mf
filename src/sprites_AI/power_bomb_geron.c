#include "sprites_AI/power_bomb_geron.h"
#include "macros.h"
#include "globals.h"
#include "sprite_util.h"

#include "data/sprites/power_bomb_geron.h"
#include "data/sprites/x_parasite.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/samus.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 421f0 | 130 | Initializes a power bomb geron
 * 
 */
void PowerBombGeronInit(void)
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
        // All geron sprite idsx are next to each other numerically, so doing spriteId - firstGeronId offsets the id to start at 0
        // For some reason this offsets to the super missile geron ids
        spriteId = gCurrentSprite.spriteId;
        spriteId -= PSPRITE_GERON_SUPER_MISSILE_1;

        // Get bit affected by the current geron
        geronBit = gPowerBombGeronsDestroyed >> spriteId;

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
    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

    gCurrentSprite.pOam = sPowerBombGeronOam_Idle;
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
        gCurrentSprite.hitboxLeft = -(BLOCK_SIZE - EIGHTH_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = BLOCK_SIZE - EIGHTH_BLOCK_SIZE;
    }
    else
    {
        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = BLOCK_SIZE - QUARTER_BLOCK_SIZE;

        spriteId = SpriteSpawnSecondary(SSPRITE_GERON_POWER_BOMB_STEM, gCurrentSprite.roomSlot,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

        if (spriteId == UCHAR_MAX)
        {
            gCurrentSprite.status = 0;
            return;
        }

        GeronSetCollision(CAA_MAKE_SOLID_STOP_ENEMY);
    }
}

/**
 * @brief 42320 | 20 | Initializes a power bomb geron to be idle
 * 
 */
void PowerBombGeronIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;

    gCurrentSprite.pOam = sPowerBombGeronOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 42340 | 20 | Handles a power bomb X geron being idle
 * 
 */
void PowerBombGeronIdle(void)
{
    if (gCurrentSprite.currentAnimationFrame == 36 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlayNotAlreadyPlaying(0x1B0);
}

/**
 * @brief 42360 | 30 | Handles a power bomb X geron dying
 * 
 */
void PowerBombGeronDying(void)
{
    u8 spriteId;
    u16 geronBit;

    // All geron sprite ids are next to each other numerically, so doing spriteId - firstGeronId offsets the id to start at 0
    // For some reason this offsets to the super missile geron ids
    spriteId = gCurrentSprite.spriteId - PSPRITE_GERON_SUPER_MISSILE_1;

    // Get bit affected by the current geron
    geronBit = 1 << spriteId;

    gPowerBombGeronsDestroyed |= geronBit;

    GeronSetCollision(CAA_REMOVE_SOLID);
}

/**
 * @brief 42390 | b0 | Power bomb geron AI
 * 
 */
void PowerBombGeron(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(0x160);

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(SSPRITE_GERON_POWER_BOMB_STEM, gCurrentSprite.primarySpriteRamSlot);
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            PowerBombGeronInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            PowerBombGeronIdleInit();

        case SPRITE_POSE_IDLE:
            PowerBombGeronIdle();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteUtilUnfreezeSecondarySprites(SSPRITE_GERON_POWER_BOMB_STEM, gCurrentSprite.primarySpriteRamSlot);
            PowerBombGeronDying();
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            PowerBombGeronInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            break;
    }
}

/**
 * @brief 42440 | 13c | Power bomb geron stem AI
 * 
 */
void PowerBombGeronStem(void)
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
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.drawOrder = 6;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

            gCurrentSprite.pOam = sPowerBombGeronStemOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            break;

        case SPRITE_POSE_IDLE:
            if (gSpriteData[ramSlot].health == 0)
            {
                gCurrentSprite.pose = 0x18;

                gCurrentSprite.pOam = sPowerBombGeronStemOam_Destroyed;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.health = 0;
                gCurrentSprite.ignoreSamusCollisionTimer = 1;
            }
            break;

        case 0x18:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;

            if (SpriteUtilHasCurrentAnimationEnded())
                gCurrentSprite.status = 0;
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
