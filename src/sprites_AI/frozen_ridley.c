#include "data/sprites/frozen_ridley.h"

#include "globals.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/core_x.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

void FrozenRidleySetCollision(u32 caa)
{
    u16 y;
    u16 x;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y + BLOCK_TO_SUB_PIXEL(0.5f), x);
}

void FrozenRidleyInit(void)
{
    u8 state;

    gCurrentSprite.bgPriority = 3;
    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
    gCurrentSprite.drawDistanceTop = 88;
    gCurrentSprite.drawDistanceBottom = 24;
    gCurrentSprite.drawDistanceHorizontal = 72;
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(5.625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    state = EventCheckOn_PowerOutage();
    if (state == POWER_OUTAGE_DURING)
    {
        gCurrentSprite.health = 1;
        gCurrentSprite.pOam = sFrozenRidleyOam_Idle;
        gCurrentSprite.pose = 1;
        gCurrentSprite.samusCollision = SSC_SOLID;
        FrozenRidleySetCollision(CAA_MAKE_SOLID);
    }
    else if (state == POWER_OUTAGE_AFTER)
    {
        gCurrentSprite.pOam = sFrozenRidleyOam_Crumbled;
        gCurrentSprite.pose = 8;
        gCurrentSprite.samusCollision = SSC_NONE;
    }
    else
    {
        gCurrentSprite.health = 1;
        gCurrentSprite.pOam = sFrozenRidleyOam_Idle;
        gCurrentSprite.pose = 8;
        gCurrentSprite.samusCollision = SSC_SOLID;
        FrozenRidleySetCollision(CAA_MAKE_SOLID);
    }
}

void FrozenRidleyWaitForSamus(void)
{
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(5.0f), BLOCK_TO_SUB_PIXEL(5.0f)) == NSLR_LEFT)
    {
        gCurrentSprite.pose = 2;
        gCurrentSprite.pOam = sFrozenRidleyOam_OpeningEye;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work1 = 160;

        SoundPlay(SOUND_234);
    }
}

void FrozenRidleySpawningX(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.pOam = sFrozenRidleyOam_ClosingEye;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        SpriteSpawnSecondary(SSPRITE_FROZEN_RIDLEY_X, 0, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.5f), gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            0);
    }
}

void FrozenRidleyClosingEye(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.pOam = sFrozenRidleyOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work1 = 60;
    }
}

void FrozenRidleyXSpawning(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x1c;
        gCurrentSprite.pOam = sFrozenRidleyOam_Crumbling;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.health = 0;

        SoundPlay(SOUND_235);
    }
}

void FrozenRidleyCrumbling(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 8;
        gCurrentSprite.pOam = sFrozenRidleyOam_Crumbled;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        FrozenRidleySetCollision(CAA_REMOVE_SOLID);
    }
    else if (gCurrentSprite.currentAnimationFrame == 4 && gCurrentSprite.animationDurationCounter == 1)
    {
        ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_OUTWARD_ICE_EXPLOSION);
    }
}

void FrozenRidleyXInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.work1 = X_PARASITE_MOSAIC_MAX_INDEX;
    gCurrentSprite.drawDistanceTop = 16;
    gCurrentSprite.drawDistanceBottom = 16;
    gCurrentSprite.drawDistanceHorizontal = 16;
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sCoreXAbilityOam_Idle;
    gCurrentSprite.samusCollision = 0;
    gCurrentSprite.pose = 2;

    SoundPlay(SOUND_236);
}

void FrozenRidleyXRidleySpawning(void)
{
    if (MOD_AND(gCurrentSprite.work1, 2) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
        gCurrentSprite.work2 = 30;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.work4 = 0;
    }

    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.work1];
}

void FrozenRidleyXFlyingAway(void)
{
    u8 offset;
    s16 movement;

    if (MOD_AND(gCurrentSprite.work1, 2) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.work1--;
    if (gCurrentSprite.work2 > 0)
    {
        gCurrentSprite.work2--;
    }
    else
    {
        gCurrentSprite.xPosition += ++gCurrentSprite.work3 / 4;
        offset = gCurrentSprite.work4;
        movement = sFrozenRidleyXFlyingAwayYMovement[offset];
        if (movement == SHORT_MAX)
        {
            movement = sFrozenRidleyXFlyingAwayYMovement[gCurrentSprite.work4 - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
            gCurrentSprite.yPosition += movement;
        }
    }
}

void FrozenRidley(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            FrozenRidleyInit();
            break;

        case 1:
            FrozenRidleyWaitForSamus();
            break;

        case 2:
            FrozenRidleySpawningX();
            break;

        case 0x18:
            FrozenRidleyClosingEye();
            break;

        case 0x1a:
            FrozenRidleyXSpawning();
            break;

        case 0x1c:
            FrozenRidleyCrumbling();
            break;
    }
}

void FrozenRidleyX(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            FrozenRidleyXInit();
            break;

        case 2:
            FrozenRidleyXRidleySpawning();
            break;

        case 0x18:
            FrozenRidleyXFlyingAway();
            break;
    }
}
