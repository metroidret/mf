#include "data/sprites/scientist.h"

#include "globals.h"

#include "data/sprite_data.h"
#include "data/sprites/beam_core_x.h"
#include "data/sprites/x_parasite.h"

#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/samus.h"
#include "structs/sprite.h"

void ScientistInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gEquipment.beamStatus & BF_WIDE_BEAM)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.875f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.3125f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.3125f);
    gCurrentSprite.pose = 2;
    gCurrentSprite.pOam = sScientistOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void ScientistIdle(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) >= 5)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.pOam = sScientistOam_TurningBody;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work1 = 60;

        SpriteUtilMakeSpriteFaceSamusXFlip();
    }
}

void ScientistTurning(void)
{
    if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.pose = 0x45;
}

void ScientistTransformingInit(void)
{
    gCurrentSprite.pose = 0x46;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_MOSAIC;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
}

void ScientistTransforming(void)
{
    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    gCurrentSprite.workY--;

    if (gCurrentSprite.workY < sizeof(sWideBeamCoreXGfx) / 512)
    {
        SpriteLoadGfx(PSPRITE_WIDE_BEAM_CORE_X, 0, gCurrentSprite.workY);

        if (gCurrentSprite.workY == 0)
        {
            gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
            gCurrentSprite.spriteId = PSPRITE_WIDE_BEAM_CORE_X;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        }
    }
    else if (gCurrentSprite.workY == sizeof(sWideBeamCoreXGfx) / 512)
    {
        SpriteLoadPal(PSPRITE_WIDE_BEAM_CORE_X, 0, ARRAY_SIZE(sWideBeamCoreXPal) / 16);
    }
}

void Scientist(void)
{
    gCurrentSprite.health = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            ScientistInit();
            break;

        case 2:
            ScientistIdle();
            break;

        case 0x18:
            ScientistTurning();
            break;

        case 0x45:
            ScientistTransformingInit();
        case 0x46:
            ScientistTransforming();
            break;
    }
}
