#include "data/sprites/data_pad.h"

#include "globals.h"
#include "macros.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/event.h"
#include "structs/samus.h"
#include "structs/sprite.h"

void DataPadInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.hitboxTop = -4;
    gCurrentSprite.hitboxBottom = 4;
    gCurrentSprite.hitboxLeft = -4;
    gCurrentSprite.hitboxRight = 4;
    gCurrentSprite.bgPriority = 1;

    if (EventCheckDownloadedDataItem(FALSE))
        gCurrentSprite.work2 = TRUE;
    else
        gCurrentSprite.work2 = FALSE;

    SpriteSpawnSecondary(SSPRITE_DATA_PAD_CENTER, 0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_DATA_PAD_SIDES, 0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
}

void DataPadIdleInit(void)
{
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 1;

    if (gCurrentSprite.work2)
    {
        gCurrentSprite.pOam = sDataPadOam_Unpressed;
        gCurrentSprite.pose = 2;
    }
    else
    {
        gCurrentSprite.pOam = sDataPadOam_Pressed;
        gCurrentSprite.pose = 0x1e;
    }
}

void DataPadIdle(void)
{
    if (NavPadDetectSamus())
    {
        if (--gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.pose = 0x18;
            gCurrentSprite.pOam = sDataPadOam_Pressing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            SoundPlay(SOUND_101);
        }
    }
    else
    {
        gCurrentSprite.work1 = 1;
    }
}

void DataPadPressingSwitch(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.pOam = sDataPadOam_Pressed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

void DataPadSwitchPressed(void)
{
    if (NavPadDetectSamus())
    {
        if (!SpriteUtilCheckSamusMorphed())
        {
            gSamusData.xPosition = gCurrentSprite.xPosition;

            if (gSamusData.invincibilityTimer > 0)
                gSamusData.invincibilityTimer = 0;

            SAMUS_SET_POSE(SPOSE_ON_SAVE_PAD);
            gCurrentSprite.pose = 0x38;
            gCurrentSprite.work1 = 30;
        }
    }
    else
    {
        gCurrentSprite.pose = 0x1c;
        gCurrentSprite.pOam = sDataPadOam_Depressing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(SOUND_102);
    }
}

void DataPadReleasingSwitch(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
        DataPadIdleInit();
}

void DataPadLockingSamus(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x3a;
        gCurrentSprite.work1 = 120;
        EventCheckDownloadedDataItem(TRUE);
        gDoorUnlockTimer = CONVERT_SECONDS(1.0f);
        SAMUS_SET_POSE(SPOSE_DOWNLOADING_ABILITY);
    }
}

void DataPadDownloadingData(void)
{
    if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.pose = 0x1e;
}

void DataPadCenterInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.hitboxTop = -4;
    gCurrentSprite.hitboxBottom = 4;
    gCurrentSprite.hitboxLeft = -4;
    gCurrentSprite.hitboxRight = 4;
    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.pose = 2;
    gCurrentSprite.work1 = 30;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].work2)
        gCurrentSprite.pOam = sDataPadCenterOam_Online;
    else
        gCurrentSprite.pOam = sDataPadCenterOam_Offline;
}

void DataPadCenterIdle(void)
{
    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose == 0x38)
    {
        if (--gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.pose = 0x18;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pOam = sDataPadCenterOam_DownloadingData;
            SoundPlay(SOUND_10A);
        }
    }
}

void DataPadCenterEngaging(void)
{
    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose == 0x1e)
    {
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sDataPadCenterOam_Online;
        gCurrentSprite.work1 = 0x14;
    }
}

void DataPadCenterDownloadingData(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x1c;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sDataPadCenterOam_Offline;
    }
}

void DataPadSidesInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.hitboxTop = -4;
    gCurrentSprite.hitboxBottom = 4;
    gCurrentSprite.hitboxLeft = -4;
    gCurrentSprite.hitboxRight = 4;
    gCurrentSprite.drawOrder = 13;
    gCurrentSprite.pose = 2;
    gCurrentSprite.pOam = sDataPadSidesOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DataPadSidesIdle(void)
{
    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose == 0x38)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sDataPadSidesOam_Engaging;
        SoundPlay(SOUND_108);
    }
}

void DataPadSidesEngaging(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sDataPadSidesOam_DownloadingData;
    }
}

void DataPadSidesDownloadingData(void)
{
    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose == 0x1e)
    {
        gCurrentSprite.work1 = 20;
        gCurrentSprite.pose = 0x1c;
        SAMUS_SET_POSE(SPOSE_FACING_FOREGROUND);
        gSamusData.lastWallTouchedMidAir = 10;
        gPreventMovementTimer = SAMUS_ITEM_PMT;
    }
}

void DataPadSidesDoneDownloadingData(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x1e;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sDataPadSidesOam_Disengaging;
        SoundPlay(SOUND_109);
    }
}

void DataPadSidesDisengaging(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x46;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sDataPadSidesOam_Idle;
        TrySpawnMessageBanner(0);
    }
}

void DataPad(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            DataPadInit();

        case 1:
            DataPadIdleInit();
            break;

        case 2:
            DataPadIdle();
            break;

        case 0x18:
            DataPadPressingSwitch();
            break;

        case 0x1a:
            DataPadSwitchPressed();
            break;

        case 0x1c:
            DataPadReleasingSwitch();
            break;

        case 0x38:
            DataPadLockingSamus();
            break;

        case 0x3a:
            DataPadDownloadingData();
            break;
    }
}

void DataPadCenter(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            DataPadCenterInit();

        case 2:
            DataPadCenterIdle();
            break;

        case 0x18:
            DataPadCenterEngaging();
            break;

        case 0x1a:
            DataPadCenterDownloadingData();
            break;
    }
}

void DataPadSides(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            DataPadSidesInit();

        case 2:
            DataPadSidesIdle();
            break;

        case 0x18:
            DataPadSidesEngaging();
            break;

        case 0x1a:
            DataPadSidesDownloadingData();
            break;

        case 0x1c:
            DataPadSidesDoneDownloadingData();
            break;

        case 0x1e:
            DataPadSidesDisengaging();
            break;
    }
}
