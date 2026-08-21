#include "data/sprites/chozo_statue.h"

#include "globals.h"

#include "data/generic_data.h"
#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/beam_core_x.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

void ChozoStatueSetCollision(u8 caa)
{
    u16 y;
    u16 x;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(0.5f), x);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(1.5f), x);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(2.5f), x);

    if (MOD_AND(gCurrentSprite.spritesetSlotAndProperties, 2) == 0)
    {
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(0.5f), x + BLOCK_SIZE);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(1.5f), x + BLOCK_SIZE);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(2.5f), x + BLOCK_SIZE);
    }
    else
    {
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(0.5f), x - BLOCK_SIZE);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(1.5f), x - BLOCK_SIZE);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(2.5f), x - BLOCK_SIZE);
    }
}

void ChozoStatueInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gEquipment.beamStatus & BF_CHARGE_BEAM)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(3.0f);
    gCurrentSprite.hitboxBottom = 0;

    if (MOD_AND(gCurrentSprite.spritesetSlotAndProperties, 2) == 0)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    }

    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sChozoStatueOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    SpriteSpawnSecondary(SSPRITE_FAKE_CHOZO_BALL, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition,
        gCurrentSprite.status & SPRITE_STATUS_X_FLIP);
    ChozoStatueSetCollision(CAA_MAKE_SOLID);
}

void ChozoStatueIdle(void)
{
    // Empty
}

void ChozoStatueTransformingInit(void)
{
    gCurrentSprite.pose = 0x46;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_MOSAIC;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    ChozoStatueSetCollision(CAA_REMOVE_SOLID);
    PlayMusic(MUSIC_CHOZO_STATUE_CORE_X_BATTLE, 7);
}

void ChozoStatueTransforming(void)
{
    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    gCurrentSprite.workY--;

    if (gCurrentSprite.workY < sizeof(sChargeBeamCoreXGfx) / 512)
    {
        SpriteLoadGfx(PSPRITE_CHARGE_BEAM_CORE_X, 0, gCurrentSprite.workY);

        if (gCurrentSprite.workY == 0)
        {
            gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
            gCurrentSprite.spriteId = PSPRITE_CHARGE_BEAM_CORE_X;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        }
    }
    else if (gCurrentSprite.workY == sizeof(sChargeBeamCoreXGfx) / 512)
    {
        SpriteLoadPal(PSPRITE_CHARGE_BEAM_CORE_X, 0, ARRAY_SIZE(sChargeBeamCoreXPal) / 16);
    }
}

void FakeChozoBallInit(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.8125f);
    gCurrentSprite.hitboxBottom = -BLOCK_TO_SUB_PIXEL(1.8125f);

    if (!(gSpriteData[primary].status & SPRITE_STATUS_X_FLIP))
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
        gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.5f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    }

    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sFakeChozoBallOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void FakeChozoBallIdle(void)
{
    if (gCurrentSprite.health == 0)
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
}

void FakeChozoBallExposedInit(void)
{
    gCurrentSprite.health++;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.pOam = sFakeChozoBallOam_Exposed;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 60;
    gCurrentSprite.pose = 0x38;
}

void FakeChozoBallExposed(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x3a;
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose = 0x45;
    }
}

void FakeChozoBallTransformation(void)
{
    u8 primary;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    primary = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[primary].pose == 0x46 && gSpriteData[primary].workY <= 20)
        gCurrentSprite.status = 0;
}

void ChozoStatue(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ChozoStatueInit();
            break;

        case SPRITE_POSE_IDLE:
            ChozoStatueIdle();
            break;

        case 0x45:
            ChozoStatueTransformingInit();

        case 0x46:
            ChozoStatueTransforming();
            break;
    }
}

void FakeChozoBall(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            FakeChozoBallInit();
            break;

        case SPRITE_POSE_IDLE:
            FakeChozoBallIdle();
            break;

        case SPRITE_POSE_STOPPED:
            FakeChozoBallExposedInit();
            break;

        case 0x38:
            FakeChozoBallExposed();
            break;

        case 0x3a:
            FakeChozoBallTransformation();
            break;
    }
}
