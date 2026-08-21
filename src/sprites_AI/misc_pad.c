#include "data/sprites/misc_pad.h"

#include "globals.h"
#include "macros.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/message_banner.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

void MiscPadInit(void)
{
    u8 inactive;
    u8 ramSlot;

    inactive = FALSE;

    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.bgPriority = 1;

    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_PUMP_CONTROL_PAD:
            inactive = EventCheckOn_EnteredPumpControlUnit();
            break;

        case PSPRITE_BOILER_CONTROL_PAD:
            inactive = EventCheckOn_Meltdown();
            if (inactive == MELTDOWN_DURING)
            {
                SpriteSpawnPrimary(PSPRITE_SCIENTIST, gCurrentSprite.roomSlot, 0, SSP_UNINFECTED_OR_BOSS,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                inactive = FALSE;
            }
            break;

        case PSPRITE_AUXILARY_POWER_PAD:
            inactive = EventCheckOn_SpaceJumpRecovered();
            break;

        case PSPRITE_HABITAION_PAD:
            inactive = EventCheckOn_NavigationRoomLeavingPyr2();
            gAbilityRestingXPosition = gCurrentSprite.xPosition;
            break;

        default:
            gCurrentSprite.status = 0;
            return;
    }

    SpriteSpawnSecondary(SSPRITE_33, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

    if (inactive)
        gCurrentSprite.work2 = TRUE;
    else
        gCurrentSprite.work2 = FALSE;

    if (gCurrentSprite.spriteId == PSPRITE_HABITAION_PAD)
    {
        SpriteSpawnSecondary(SSPRITE_68, 0, 4, gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(4.0f), 0);
        ramSlot = SpriteSpawnSecondary(SSPRITE_67, 0, 4, gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(4.0f), 0);
        gBossWork2 = ramSlot;
    }
}

void MiscPadIdleInit(void)
{
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 1;

    if (gCurrentSprite.work2 == FALSE)
    {
        if (gCurrentSprite.spriteId == PSPRITE_HABITAION_PAD)
            gCurrentSprite.pOam = sHabitationPadOam_SwitchPressed;
        else
            gCurrentSprite.pOam = sControlPadOam_SwitchPressed;

        gCurrentSprite.pose = 0x46;
    }
    else
    {
        if (gCurrentSprite.spriteId == PSPRITE_HABITAION_PAD)
            gCurrentSprite.pOam = sHabitationPadOam_SwitchUnpressed;
        else
            gCurrentSprite.pOam = sControlPadOam_SwitchUnpressed;

        gCurrentSprite.pose = 2;
    }
}

void MiscPadIdle(void)
{
    if (NavPadDetectSamus())
    {
        if (--gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.spriteId == PSPRITE_HABITAION_PAD)
                gCurrentSprite.pOam = sHabitationPadOam_PressingSwitch;
            else
                gCurrentSprite.pOam = sControlPadOam_PressingSwitch;

            gCurrentSprite.pose = 0x18;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            SoundPlay(0x101);
        }
    }
    else
    {
        gCurrentSprite.work1 = 1;
    }
}

void MiscPadPressingSwitch(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        if (gCurrentSprite.spriteId == PSPRITE_HABITAION_PAD)
            gCurrentSprite.pOam = sHabitationPadOam_SwitchPressed;
        else
            gCurrentSprite.pOam = sControlPadOam_SwitchPressed;

        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

void MiscPadSwitchPressed(void)
{
    if (NavPadDetectSamus())
    {
        if (!SpriteUtilCheckSamusMorphed())
        {
            gSamusData.xPosition = gCurrentSprite.xPosition;
            if (gSamusData.invincibilityTimer > 0)
                gSamusData.invincibilityTimer = 0;

            SAMUS_SET_POSE(SPOSE_ON_NAVIGATION_PAD);
            gCurrentSprite.pose = 0x38;
            gCurrentSprite.work1 = 20;
        }
    }
    else
    {
        if (gCurrentSprite.spriteId == PSPRITE_HABITAION_PAD)
            gCurrentSprite.pOam = sHabitationPadOam_ReleasingSwitch;
        else
            gCurrentSprite.pOam = sControlPadOam_ReleasingSwitch;

        gCurrentSprite.pose = 0x1c;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        SoundPlay(0x102);
    }
}

void MiscPadReleasingSwitch(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
        MiscPadIdleInit();
}

void MiscPadSamusInteracting(void)
{
    if (gCurrentSprite.work1 > 0)
    {
        if (--gCurrentSprite.work1 == 0)
            SoundPlay(SOUND_103);

        if (gCurrentSprite.work1 < sizeof(sMessageBannerGfx) / 512)
            SpriteLoadGfx(PSPRITE_MESSAGE_BANNER, 2, gCurrentSprite.work1);
        else if (gCurrentSprite.work1 == sizeof(sMessageBannerGfx) / 512)
            SpriteLoadPal(PSPRITE_MESSAGE_BANNER, 2, ARRAY_SIZE(sMessageBannerPal) / 16);
    }
    else if (gSamusData.pose == SPOSE_ON_NAVIGATION_PAD && gSamusData.currentAnimationFrame >= 14)
    {
        gCurrentSprite.pose = 0x3a;
        gCurrentSprite.work1 = 30;
    }
}

void MiscPadSpawnMessageBanner(void)
{
    u8 type;

    type = 0;

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x1e;

        switch (gCurrentSprite.spriteId)
        {
            case PSPRITE_PUMP_CONTROL_PAD:
                EventCheckAdvance(EVENT_WATER_LEVEL_LOWERED);
                type = 6;
                break;

            case PSPRITE_BOILER_CONTROL_PAD:
                EventCheckAdvance(EVENT_COOLING_UNIT_OPERATIONAL);
                type = 7;
                break;

            case PSPRITE_AUXILARY_POWER_PAD:
                EventCheckAdvance(EVENT_AUXILARY_POWER_ENGAGED);
                type = 9;
                break;

            case PSPRITE_HABITAION_PAD:
                EventCheckAdvance(EVENT_ANIMALS_RELEASED);
                type = 8;
                break;
        }

        if (type != 0)
        {
            gPreventMovementTimer = SAMUS_ITEM_PMT;
            SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, type, 2, SSP_UNINFECTED_OR_BOSS, gXParasiteTargetYPosition,
                gXParasiteTargetXPosition, 0);
        }
    }
}

void MiscPadAfterInteraction(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_HABITAION_PAD)
    {
        if (gSamusData.pose == SPOSE_UNLOCKING_HABITATIONS_DECK)
            gCurrentSprite.pose = 0x20;
        else
            gPreventMovementTimer = SAMUS_ITEM_PMT;
    }
}

void MiscPadInactive(void)
{
    // Empty
}

void MiscPadWaitForWideBeamCoreX(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_BOILER_CONTROL_PAD && EventCheckOn_Meltdown() == MELTDOWN_CAN_BE_STOPPED &&
        SpriteUtilCountPrimarySprites(PSPRITE_WIDE_BEAM_CORE_X) == 0 && gPreventMovementTimer == 0)
    {
        gCurrentSprite.work2 = TRUE;
        gCurrentSprite.pose = 0x1c;
        gCurrentSprite.pOam = sControlPadOam_ReleasingSwitch;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        SoundPlay(SOUND_102);
    }
}

void MiscPadConsoleInit(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.drawOrder = 13;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gSpriteData[primary].spriteId == PSPRITE_BOILER_CONTROL_PAD)
    {
        if (EventCheckOn_Meltdown())
        {
            gCurrentSprite.pOam = sControlPadConsoleOam_Inactive;
            gCurrentSprite.pose = 2;
        }
        else
        {
            gCurrentSprite.pOam = sControlPadConsoleOam_Active;
            gCurrentSprite.pose = 0x18;
        }
    }
    else if (gSpriteData[primary].work2)
    {
        if (gSpriteData[primary].spriteId == PSPRITE_HABITAION_PAD)
            gCurrentSprite.pOam = sHabitationPadConsoleOam_Inactive;
        else
            gCurrentSprite.pOam = sControlPadConsoleOam_Inactive;

        gCurrentSprite.pose = 2;
    }
    else
    {
        if (gSpriteData[primary].spriteId == PSPRITE_HABITAION_PAD)
            gCurrentSprite.pOam = sHabitationPadConsoleOam_Active;
        else
            gCurrentSprite.pOam = sControlPadConsoleOam_Active;

        gCurrentSprite.pose = 0x18;
    }
}

void MiscPadConsoleIdle(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[primary].pose == 0x3a)
    {
        if (gSpriteData[primary].spriteId == PSPRITE_HABITAION_PAD)
            gCurrentSprite.pOam = sHabitationPadConsoleOam_Active;
        else
            gCurrentSprite.pOam = sControlPadConsoleOam_Active;

        gCurrentSprite.pose = 0x18;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

void MiscPad(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            MiscPadInit();
        case 1:
            MiscPadIdleInit();
            break;

        case 2:
            MiscPadIdle();
            break;

        case 0x18:
            MiscPadPressingSwitch();
            break;

        case 0x1a:
            MiscPadSwitchPressed();
            break;

        case 0x1c:
            MiscPadReleasingSwitch();
            break;

        case 0x1e:
            MiscPadAfterInteraction();
            break;

        case 0x20:
            MiscPadInactive();
            break;

        case 0x38:
            MiscPadSamusInteracting();
            break;

        case 0x3a:
            MiscPadSpawnMessageBanner();
            break;

        case 0x46:
            MiscPadWaitForWideBeamCoreX();
            break;
    }
}

void MiscPadConsole(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            MiscPadConsoleInit();
            break;

        case 2:
            MiscPadConsoleIdle();
            break;
    }
}
