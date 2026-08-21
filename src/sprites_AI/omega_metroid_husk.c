#include "data/sprites/omega_metroid_husk.h"

#include "globals.h"

#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_debris.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/sprite.h"
#include "structs/sprite_debris.h"

void OmegaMetroidHuskSetInvisibleWallCollision(u8 caa)
{
    u16 y;
    u16 x;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(14.f);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(0.5f), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(1.5f), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(2.5f), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(3.5f), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(4.5f), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(5.5f), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(6.5f), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(7.5f), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(8.5f), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(0.5f), x - BLOCK_TO_SUB_PIXEL(1.f));
}

void OmegaMetroidHuskInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(5.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.pose = 1;
    gCurrentSprite.pOam = sOmegaMetroidHuskOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void OmegaMetroidHuskWaitingForSamus(void)
{
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(10.f), BLOCK_TO_SUB_PIXEL(5.875f)) !=
        NSLR_OUT_OF_RANGE)
    {
        gCurrentSprite.pose = 2;
        gDisableScrolling = 2;
        OmegaMetroidHuskSetInvisibleWallCollision(CAA_MAKE_SOLID);
    }
}

void OmegaMetroidHuskWaitForOmegaMetroidToSpawn(void)
{
    u16 y;
    u16 x;

    if (gSamusData.yPosition > gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.f) &&
        gSamusData.xPosition < gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(10.f))
    {
        y = gCurrentSprite.yPosition;
        x = gCurrentSprite.xPosition;

        gCurrentSprite.pose = 8;
        gSpriteData[gCurrentSprite.primarySpriteRamSlot].work4 = 0;

        ScreenShakeStartHorizontal(60, 0x81);

        ParticleSet(y - BLOCK_TO_SUB_PIXEL(5.f), x + BLOCK_TO_SUB_PIXEL(1.f), PE_0x2F);
        ParticleSet(y - BLOCK_TO_SUB_PIXEL(3.f), x + BLOCK_TO_SUB_PIXEL(0.78125f), PE_0x30);
        ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.5f), x + BLOCK_TO_SUB_PIXEL(1.125f), PE_0x30);

        SpriteDebrisInit(0, DEBRIS_TYPE_HOPPING_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(7.03125f),
            x + BLOCK_TO_SUB_PIXEL(1.0f));
        SpriteDebrisInit(0, DEBRIS_TYPE_HOPPING_FAST_LEFT, y - BLOCK_TO_SUB_PIXEL(6.375f),
            x + BLOCK_TO_SUB_PIXEL(0.5f));
        SpriteDebrisInit(0, DEBRIS_TYPE_LIGHT_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(5.875f),
            x + BLOCK_TO_SUB_PIXEL(0.65625f));
        SpriteDebrisInit(0, DEBRIS_TYPE_HEAVY_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(5.15625f),
            x + BLOCK_TO_SUB_PIXEL(0.5625f));
        SpriteDebrisInit(0, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(4.6875f),
            x + BLOCK_TO_SUB_PIXEL(0.75f));
        SpriteDebrisInit(0, DEBRIS_TYPE_HOPPING_FAST_LEFT, y - BLOCK_TO_SUB_PIXEL(3.75f),
            x + BLOCK_TO_SUB_PIXEL(0.90625f));
        SpriteDebrisInit(0, DEBRIS_TYPE_LIGHT_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(3.125f),
            x + BLOCK_TO_SUB_PIXEL(0.9375f));
        SpriteDebrisInit(0, DEBRIS_TYPE_HOPPING_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(2.1875f),
            x + BLOCK_TO_SUB_PIXEL(0.75f));

        SoundPlay_3b1c(SOUND_218);
    }
}

void OmegaMetroidHuskGettingCrushedInit(void)
{
    gCurrentSprite.pose = 0x18;
    gCurrentSprite.pOam = sOmegaMetroidHuskOam_GettingCrushed;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    SoundPlay(SOUND_225);
}

void OmegaMetroidHuskGettingCrushed(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.pOam = sOmegaMetroidHuskOam_Crushed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work1 = 60;
    }
}

void OmegaMetroidHuskWaiting(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x1c;
        gCurrentSprite.work1 = 30;
    }
}

void OmegaMetroidHuskDisappearing(void)
{
    if ((gCurrentSprite.work1 & 1) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.status = 0;
}

void OmegaMetroidHusk(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            OmegaMetroidHuskInit();
            break;

        case 1:
            OmegaMetroidHuskWaitingForSamus();
            break;

        case 2:
            OmegaMetroidHuskWaitForOmegaMetroidToSpawn();
            break;

        case 0x17:
            OmegaMetroidHuskGettingCrushedInit();
            break;

        case 0x18:
            OmegaMetroidHuskGettingCrushed();
            break;

        case 0x1a:
            OmegaMetroidHuskWaiting();
            break;

        case 0x1c:
            OmegaMetroidHuskDisappearing();
            break;
    }
}
