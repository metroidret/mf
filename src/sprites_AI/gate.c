#include "data/sprites/gate.h"

#include "globals.h"

#include "data/generic_data.h"
#include "data/samus_data.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

enum GateType {
    GATE_TYPE_LEFT_THIN = 1,
    GATE_TYPE_RIGHT_THIN,
    GATE_TYPE_LEFT_WIDE,
    GATE_TYPE_RIGHT_WIDE,
    GATE_TYPE_HABITATION
};

void GateSetCollision(u8 caa)
{
    u16 y;
    u16 x;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(0.5), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(1.5), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(2.5), x);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(3.5), x);
}

void GateInit(void)
{
    u8 type;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    switch (gCurrentSprite.spritesetSlotAndProperties)
    {
        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_LEFT_THIN:
            type = GATE_TYPE_LEFT_THIN;
            gCurrentSprite.pOam = sGateOam_ClosedThin;
            break;

        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_RIGHT_THIN:
            type = GATE_TYPE_RIGHT_THIN;
            gCurrentSprite.pOam = sGateOam_ClosedThin;
            break;

        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_LEFT_WIDE:
            type = GATE_TYPE_LEFT_WIDE;
            gCurrentSprite.pOam = sGateOam_ClosedWide;
            break;

        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_RIGHT_WIDE:
            type = GATE_TYPE_RIGHT_WIDE;
            gCurrentSprite.pOam = sGateOam_ClosedWide;
            break;

        default:
            type = GATE_TYPE_HABITATION;
            if (EventCheckAfter_AnimalsReleased())
            {
                gCurrentSprite.pose = 0x1a;
                gCurrentSprite.pOam = sGateOam_OpenedThin;
                return;
            }
            gCurrentSprite.pOam = sGateOam_ClosedThin;
            gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
            gCurrentSprite.workY = 210;
            break;
    }

    GateSetCollision(CAA_MAKE_SOLID);

    if (type < GATE_TYPE_HABITATION)
    {
        type = SpriteSpawnSecondary(SSPRITE_GATE_SWITCH, type, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        if (type == UCHAR_MAX)
            gCurrentSprite.status = 0;
    }
}

void GateClosed(void)
{
    switch (gCurrentSprite.spritesetSlotAndProperties)
    {
        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_LEFT_THIN:
        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_RIGHT_THIN:
        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_LEFT_WIDE:
        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_RIGHT_WIDE:
            break;

        default:
            if (EventCheckAfter_AnimalsReleased())
            {
                if (--gCurrentSprite.workY == 0)
                    gCurrentSprite.pose = 0x17;
            }
            break;
    }
}

void GateOpeningInit(void)
{
    GateSetCollision(CAA_REMOVE_SOLID);

    gCurrentSprite.pose = 0x18;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    switch (gCurrentSprite.spritesetSlotAndProperties)
    {
        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_LEFT_THIN:
        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_RIGHT_THIN:
            gCurrentSprite.pOam = sGateOam_OpeningThin;
            SoundPlay(SOUND_114);
            break;

        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_LEFT_WIDE:
        case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_RIGHT_WIDE:
            gCurrentSprite.pOam = sGateOam_OpeningWide;
            SoundPlay(SOUND_115);
            break;

        default:
            gCurrentSprite.pOam = sGateOam_OpeningThin;
            SoundPlay(SOUND_114);
            break;
    }
}

void GateOpening(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        switch (gCurrentSprite.spritesetSlotAndProperties)
        {
            case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_LEFT_THIN:
            case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_RIGHT_THIN:
                gCurrentSprite.pOam = sGateOam_OpenedThin;
                break;

            case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_LEFT_WIDE:
            case SSP_UNINFECTED_OR_BOSS | GATE_TYPE_RIGHT_WIDE:
                gCurrentSprite.pOam = sGateOam_OpenedWide;
                break;

            default:
                gCurrentSprite.pOam = sGateOam_OpenedThin;
                break;
        }
    }
}

void GateSwitchInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_SOLID;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
    gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 3);
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    switch (gCurrentSprite.roomSlot)
    {
        case GATE_TYPE_LEFT_THIN:
        case GATE_TYPE_LEFT_WIDE:
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.3125f);
            gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(1.8125f);
            gCurrentSprite.pOam = sGateSwitchOam_IdleLeft;
            break;

        case GATE_TYPE_RIGHT_THIN:
        case GATE_TYPE_RIGHT_WIDE:
            gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(1.8125f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.3125f);
            gCurrentSprite.pOam = sGateSwitchOam_IdleRight;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

void GateSwitchIdle(void)
{
    if (gCurrentSprite.health == 0)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = SSC_NONE;

        switch (gCurrentSprite.roomSlot)
        {
            case GATE_TYPE_LEFT_THIN:
            case GATE_TYPE_LEFT_WIDE:
                gCurrentSprite.pOam = sGateSwitchOam_PressingLeft;
                break;

            case GATE_TYPE_RIGHT_THIN:
            case GATE_TYPE_RIGHT_WIDE:
                gCurrentSprite.pOam = sGateSwitchOam_PressingRight;
                break;

            default:
                gCurrentSprite.status = 0;
                break;
        }
    }
}

void GateSwitchPressing(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose = 0x17;

        switch (gCurrentSprite.roomSlot)
        {
            case GATE_TYPE_LEFT_THIN:
            case GATE_TYPE_LEFT_WIDE:
                gCurrentSprite.pOam = sGateSwitchOam_PressedLeft;
                break;

            case GATE_TYPE_RIGHT_THIN:
            case GATE_TYPE_RIGHT_WIDE:
                gCurrentSprite.pOam = sGateSwitchOam_PressedRight;
                break;

            default:
                gCurrentSprite.status = 0;
                break;
        }
    }
}

void GateSwitchPressed(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
}

void Gate(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GateInit();
            break;

        case SPRITE_POSE_IDLE:
            GateClosed();
            break;

        case 0x17:
            GateOpeningInit();
            break;

        case 0x18:
            GateOpening();
            break;
    }
}

void GateSwitch(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GateSwitchInit();
            break;

        case SPRITE_POSE_IDLE:
            GateSwitchIdle();
            break;

        case 0x18:
            GateSwitchPressing();
            break;

        case 0x1a:
            GateSwitchPressed();
            break;
    }
}
