#include "data/sprites/missile_geron.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

void GeronSetCollision(u8 caa)
{
    u16 y;
    u16 x;

    y = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    x = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_SIZE, x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y, x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y + BLOCK_SIZE, x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y + 2 * BLOCK_SIZE, x);
}

void MissileGeronInit(void)
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
        // All geron sprite IDs are next to each other numerically, so doing spriteId - firstGeronId offsets the ID to
        // start at 0
        spriteId = gCurrentSprite.spriteId;
        spriteId -= PSPRITE_GERON_MISSILE_1;

        // Get bit affected by the current geron
        geronBit = gMissileGeronsDestroyed >> spriteId;

        if (geronBit & 1)
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.pose = SPRITE_POSE_IDLE;
    }

    gCurrentSprite.drawDistanceTop = 16;
    gCurrentSprite.drawDistanceBottom = 16;
    gCurrentSprite.drawDistanceHorizontal = 16;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

    gCurrentSprite.pOam = sMissileGeronOam_Idle;
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
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
        return;
    }

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.625f);

    spriteId =
        SpriteSpawnSecondary(SSPRITE_GERON_MISSILE_STEM, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

    if (spriteId == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
        return;
    }

    GeronSetCollision(CAA_MAKE_SOLID_STOP_ENEMY);
}

void MissileGeronIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;

    gCurrentSprite.pOam = sMissileGeronOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void MissileGeronIdle(void)
{
    return;
}

void MissileGeronDeath(void)
{
    u8 spriteId;
    u16 geronBit;

    // All geron sprite IDs are next to each other numerically, so doing spriteId - firstGeronId offsets the ID to start
    // at 0
    spriteId = gCurrentSprite.spriteId;
    spriteId -= PSPRITE_GERON_MISSILE_1;

    // Get bit affected by the current geron
    geronBit = 1 << spriteId;

    gMissileGeronsDestroyed |= geronBit;

    GeronSetCollision(CAA_REMOVE_SOLID);
}

void MissileGeron(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 0x4)
        SoundPlayNotAlreadyPlaying(SOUND_GERON_HURT);

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(SSPRITE_GERON_MISSILE_STEM, gCurrentSprite.primarySpriteRamSlot);
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MissileGeronInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            MissileGeronIdleInit();

        case SPRITE_POSE_IDLE:
            MissileGeronIdle();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteUtilUnfreezeSecondarySprites(SSPRITE_GERON_MISSILE_STEM, gCurrentSprite.primarySpriteRamSlot);
            MissileGeronDeath();
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            MissileGeronInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            break;
    }
}

void MissileGeronStem(void)
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

            gCurrentSprite.pOam = sMissileGeronStemOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            break;

        case SPRITE_POSE_IDLE:
            if (gSpriteData[ramSlot].health == 0)
            {
                gCurrentSprite.pose = 0x18;

                gCurrentSprite.pOam = sMissileGeronStemOam_Destroyed;
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
