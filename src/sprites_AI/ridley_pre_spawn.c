#include "data/sprites/ridley_pre_spawn.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/ridley.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/samus.h"
#include "structs/sprite.h"

void RidleyPreSpawnInit(void)
{
    if (gEquipment.suitMiscStatus & SMF_SCREW_ATTACK)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.drawDistanceTop = 88;
    gCurrentSprite.drawDistanceBottom = 8;
    gCurrentSprite.drawDistanceHorizontal = 56;
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(4.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
    gCurrentSprite.pOam = sRidleyPreSpawnOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = 1;
}

void RidleyPreSpawnWaitingForSamus(void)
{
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(5.f), BLOCK_TO_SUB_PIXEL(5.f)) == NSLR_RIGHT)
    {
        gCurrentSprite.pose = 2;
        gCurrentSprite.pOam = sRidleyPreSpawnOam_OpeningEye;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work1 = CONVERT_SECONDS(2 + 2.f / 3);

        SoundPlay(SOUND_1DC);
    }
}

void RidleyPreSpawnOpeningEye(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.pOam = sRidleyPreSpawnOam_ClosingEye;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

void RidleyPreSpawnClosingEye(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.pOam = sRidleyPreSpawnOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work1 = CONVERT_SECONDS(1.f);
    }
}

void RidleyPreSpawnEyeClosed(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x1c;
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
        PlayMusic(MUSIC_NEO_RIDLEY_BATTLE, 7);
    }
}

void RidleyPreSpawnTurningIntoRidley(void)
{
    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    gCurrentSprite.workY--;

    // Load Ridley graphics, one chunk at a time
    if (gCurrentSprite.workY < sizeof(sRidleyGfx) / 512)
    {
        SpriteLoadGfx(PSPRITE_RIDLEY, 0, gCurrentSprite.workY);
        if (gCurrentSprite.workY == 0)
        {
            // Turn into Ridley
            gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
            gCurrentSprite.spriteId = PSPRITE_RIDLEY;
            gCurrentSprite.status |= (SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
        }
    }
    else if (gCurrentSprite.workY == sizeof(sRidleyGfx) / 512)
    {
        SpriteLoadPal(PSPRITE_RIDLEY, 0, ARRAY_SIZE(sRidleyPal) / 16);
    }
}

void RidleyPreSpawn(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            RidleyPreSpawnInit();
            break;

        case 1:
            RidleyPreSpawnWaitingForSamus();
            break;

        case 2:
            RidleyPreSpawnOpeningEye();
            break;

        case 0x18:
            RidleyPreSpawnClosingEye();
            break;

        case 0x1a:
            RidleyPreSpawnEyeClosed();
            break;

        case 0x1c:
            RidleyPreSpawnTurningIntoRidley();
            break;
    }
}
