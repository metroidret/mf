#include "sprites_AI/animals.h"
#include "data/sprites/animals.h"

#include "globals.h"
#include "macros.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/samus.h"

#include "structs/sprite.h"

// Dachora values

#define DACHORA_X_SPEED_CAP (PIXEL_TO_SUB_PIXEL(1) * 4)

enum DachoraPose {
    DACHORA_POSE_TURNING_AROUND_INIT = 3,
    DACHORA_POSE_TURNING_AROUND = 4,
    DACHORA_POSE_TURNING_AROUND_SECOND_PART = 5,
    DACHORA_POSE_STANDING_INIT = 7,
    DACHORA_POSE_STANDING = 8,
    DACHORA_POSE_HEAD_MOVEMENT_INIT = 9,
    DACHORA_POSE_HEAD_MOVEMENT = 0xa,
    DACHORA_POSE_LEAVING_ENCLOSURE_INIT = 0x17,
    DACHORA_POSE_LEAVING_ENCLOSURE = 0x18,
    DACHORA_POSE_WALKING_TO_WAITING_SPOT_INIT = 0x19,
    DACHORA_POSE_WALKING_TO_WAITING_SPOT = 0x1a,
    DACHORA_POSE_WAITING_FOR_OTHERS = 0x1b,
    DACHORA_POSE_WAITING_TO_SPAWN_BABY = 0x1c,
    DACHORA_POSE_WAITING_FOR_BABY = 0x1d,
    DACHORA_POSE_BOWING = 0x1e,
    DACHORA_POSE_WAITING_TO_RUN = 0x1f,
    DACHORA_POSE_RUNNING_AWAY = 0x20,
    DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_INIT = 0x37,
    DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING = 0x38,
    DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_SECOND_PART = 0x3a,
};

enum DachoraHeadMovement {
    DACHORA_HEAD_MOVEMENT_EAT,
    DACHORA_HEAD_MOVEMENT_BLINK,
    DACHORA_HEAD_MOVEMENT_TILT,
    DACHORA_HEAD_MOVEMENT_TURN,
};

#define DACHORA_TIMER work1
#define DACHORA_HEAD_MOVEMENT work2
#define DACHORA_X_SPEED work3
#define DACHORA_LEAVING_Y_SPEED_IDX work4

// Baby Dachora values

enum BabyDachoraPose {
    BABY_DACHORA_POSE_WALKING_TO_GATE = 1,
    BABY_DACHORA_POSE_LEAVING_ENCLOSURE = 2,
    BABY_DACHORA_POSE_WALKING_TO_WAITING_SPOT = 0x17,
    BABY_DACHORA_POSE_WAITING_TO_RUN = 0x18,
    BABY_DACHORA_POSE_RUNNING_AWAY = 0x19,
};

#define BABY_DACHORA_TIMER work1
#define BABY_DACHORA_LEAVING_Y_SPEED_IDX work4

// Etecoon values

#define ETECOON_X_SPEED_CAP (PIXEL_TO_SUB_PIXEL(1) * 4)

enum EtecoonPose {
    ETECOON_POSE_TURNING_AROUND_INIT = 3,
    ETECOON_POSE_TURNING_AROUND = 4,
    ETECOON_POSE_TURNING_AROUND_SECOND_PART = 5,
    ETECOON_POSE_STANDING_INIT = 7,
    ETECOON_POSE_STANDING = 8,
    ETECOON_POSE_FACING_FOREGROUND_INIT = 9,
    ETECOON_POSE_FACING_FOREGROUND = 0xa,
    ETECOON_POSE_LEAVING_ENCLOSURE_INIT = 0x17,
    ETECOON_POSE_LEAVING_ENCLOSURE = 0x18,
    ETECOON_POSE_WALKING_TO_WAITING_SPOT_INIT = 0x19,
    ETECOON_POSE_WALKING_TO_WAITING_SPOT = 0x1a,
    ETECOON_POSE_WAITING_FOR_OTHERS_INIT = 0x1b,
    ETECOON_POSE_WAITING_FOR_OTHERS = 0x1c,
    ETECOON_POSE_RUNNING_AWAY = 0x1d,
    ETECOON_POSE_JUMPING_TO_TIRE = 0x38,
    ETECOON_POSE_SWINGING_FROM_TIRE = 0x3a,
    ETECOON_POSE_FALLING_FROM_TIRE = 0x3c,
    ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_INIT = 0x3d,
    ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING = 0x3e,
    ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_SECOND_PART = 0x40,
};

enum EtecoonAction {
    ETECOON_ACTION_STAND,
    ETECOON_ACTION_TURN_HEAD,
    ETECOON_ACTION_JUMP_ON_GLASS,
    ETECOON_ACTION_JUMP_TO_TIRE,
};

#define ETECOON_TIRE_SLOT work0
#define ETECOON_TIMER work1
#define ETECOON_ACTION work2
#define ETECOON_X_SPEED work3
#define ETECOON_DOUBLE_SPEED work4
#define ETECOON_LEAVING_Y_SPEED_IDX work4

// Tire swing values

#define TIRE_STATUS_HAS_ETECOON (1 << 10)

// Habitation gate values

enum HabitationGatePose {
    HABITATION_GATE_OPENING = 0x18,
    HABITATION_GATE_OPENED = 0x1a,
};

#define HABITATION_GATE_SLOT gBossWork2


boolu8 DachoraCheckDoHeadMovement(void)
{
    boolu8 doMovement;

    doMovement = TRUE;

    switch (gSpriteRandomNumber)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            gCurrentSprite.pose = DACHORA_POSE_STANDING_INIT;
            gCurrentSprite.DACHORA_HEAD_MOVEMENT = DACHORA_HEAD_MOVEMENT_EAT;
            break;

        case 4:
        case 5:
        case 6:
        case 7:
            gCurrentSprite.pose = DACHORA_POSE_STANDING_INIT;
            gCurrentSprite.DACHORA_HEAD_MOVEMENT = DACHORA_HEAD_MOVEMENT_BLINK;
            break;

        case 8:
        case 9:
            gCurrentSprite.pose = DACHORA_POSE_STANDING_INIT;
            gCurrentSprite.DACHORA_HEAD_MOVEMENT = DACHORA_HEAD_MOVEMENT_TILT;
            break;

        case 10:
        case 11:
        case 12:
            gCurrentSprite.pose = DACHORA_POSE_STANDING_INIT;
            gCurrentSprite.DACHORA_HEAD_MOVEMENT = DACHORA_HEAD_MOVEMENT_TURN;
            break;

        default:
            doMovement = FALSE;
            break;
    }

    return doMovement;
}

void DachoraInit(void)
{
    if (EventCheckAfter_AnimalsReleased())
    {
        gCurrentSprite.status = 0;
    }
    else
    {
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 14;
        gCurrentSprite.bgPriority = 3;

        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
        gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);

        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.0625);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625);

        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(.5f);
        gCurrentSprite.workX = gCurrentSprite.xPosition;
        SpriteUtilMakeSpriteFaceSamusXFlip();
        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        gCurrentSprite.pOam = sDachoraOam_Running;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.DACHORA_X_SPEED = 0;
        gCurrentSprite.DACHORA_TIMER = CONVERT_SECONDS(3);
    }
}

void DachoraIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sDachoraOam_Running;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.DACHORA_X_SPEED = 0;
    gCurrentSprite.DACHORA_TIMER = CONVERT_SECONDS(1) + gSpriteRandomNumber * 4;
}

void DachoraIdle(void)
{
    u16 targetX;
    s16 distance;

    if (EventCheckAfter_AnimalsReleased())
    {
        if (gSpriteData[HABITATION_GATE_SLOT].pose == HABITATION_GATE_OPENED)
        {
            targetX = gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(4);
            if (gCurrentSprite.xPosition > targetX - BLOCK_TO_SUB_PIXEL(.5f) &&
                gCurrentSprite.xPosition < targetX + BLOCK_TO_SUB_PIXEL(.5f))
            {
                gCurrentSprite.pose = DACHORA_POSE_LEAVING_ENCLOSURE_INIT;
                return;
            }
        }
    }
    else if (gCurrentSprite.xPosition > gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(7) ||
        gCurrentSprite.xPosition < gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(7))
    {
        if (gCurrentSprite.DACHORA_TIMER > 0)
            gCurrentSprite.DACHORA_TIMER--;
        else if (!(gFrameCounter8Bit & 0x1f) && DachoraCheckDoHeadMovement())
            return;
    }

    distance = DIV_SHIFT(gCurrentSprite.DACHORA_X_SPEED, 4);

    if (gCurrentSprite.DACHORA_X_SPEED < DACHORA_X_SPEED_CAP)
        gCurrentSprite.DACHORA_X_SPEED++;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.workX + BLOCK_TO_SUB_PIXEL(14) >= gCurrentSprite.xPosition)
            gCurrentSprite.xPosition += distance;
        else
            gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        if (gCurrentSprite.workX - BLOCK_TO_SUB_PIXEL(14) > gCurrentSprite.xPosition)
            gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_INIT;
        else
            gCurrentSprite.xPosition -= distance;
    }
}

void DachoraStandingInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_STANDING;
    gCurrentSprite.pOam = sDachoraOam_Standing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.DACHORA_TIMER = CONVERT_SECONDS(11/60.f);
}

void DachoraStanding(void)
{
    gCurrentSprite.DACHORA_TIMER--;
    if (gCurrentSprite.DACHORA_TIMER == 0)
        gCurrentSprite.pose = DACHORA_POSE_HEAD_MOVEMENT_INIT;
}

void DachoraHeadMovementInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_HEAD_MOVEMENT;

    if (gCurrentSprite.DACHORA_HEAD_MOVEMENT == DACHORA_HEAD_MOVEMENT_BLINK)
        gCurrentSprite.pOam = sDachoraOam_Blinking;
    else if (gCurrentSprite.DACHORA_HEAD_MOVEMENT == DACHORA_HEAD_MOVEMENT_TILT)
        gCurrentSprite.pOam = sDachoraOam_TiltingHead;
    else if (gCurrentSprite.DACHORA_HEAD_MOVEMENT == DACHORA_HEAD_MOVEMENT_TURN)
        gCurrentSprite.pOam = sDachoraOam_TurningHead;
    else // DACHORA_HEAD_MOVEMENT_EAT
        gCurrentSprite.pOam = sDachoraOam_Bowing;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DachoraHeadMovement(void)
{
    if (!SpriteUtilHasCurrentAnimationEnded())
        return;
    
    if (gCurrentSprite.DACHORA_HEAD_MOVEMENT == DACHORA_HEAD_MOVEMENT_BLINK &&
        gSpriteRandomNumber > SPRITE_RNG_PROB(.75f))
    {
        return;
    }

    if (gSpriteRandomNumber < SPRITE_RNG_PROB(3/16.f))
        gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_INIT;
    else
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void DachoraTurningAroundInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND;
    gCurrentSprite.pOam = sDachoraOam_Turning_Start;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DachoraTurningAround(void)
{
    if (!SpriteUtilHasCurrentAnimationEnded())
        return;

    gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_SECOND_PART;
    gCurrentSprite.pOam = sDachoraOam_Turning_End;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;

    if (gCurrentSprite.drawOrder == 14)
        gCurrentSprite.drawOrder = 15;
    else
        gCurrentSprite.drawOrder = 14;
}

void DachoraTurningAroundSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void DachoraTurningAroundWhileLeavingInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING;
    gCurrentSprite.pOam = sDachoraOam_Turning_Start;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DachoraTurningAroundWhileLeaving(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_SECOND_PART;
        gCurrentSprite.pOam = sDachoraOam_Turning_End;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }
}

void DachoraTurningAroundWhileLeavingSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = DACHORA_POSE_WALKING_TO_WAITING_SPOT_INIT;
}

void DachoraLeavingEnclosureInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_LEAVING_ENCLOSURE;
    gCurrentSprite.DACHORA_LEAVING_Y_SPEED_IDX = 0;
    gCurrentSprite.bgPriority = 2;
    gCurrentSprite.drawOrder = 4;
}

void DachoraLeavingEnclosure(void)
{
    u8 index;
    s16 distance;

    index = gCurrentSprite.DACHORA_LEAVING_Y_SPEED_IDX;
    distance = sAnimalsLeavingEnclosureYSpeeds[index];
    if (distance == SHORT_MAX)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.pose = DACHORA_POSE_WALKING_TO_WAITING_SPOT;
        else
            gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_INIT;
    }
    else
    {
        gCurrentSprite.DACHORA_LEAVING_Y_SPEED_IDX++;
        gCurrentSprite.yPosition += distance;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.0625f);
        else
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(.0625f);
    }
}

void DachoraWalkingToWaitingSpotInit(void)
{
    gCurrentSprite.pOam = sDachoraOam_Running;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = DACHORA_POSE_WALKING_TO_WAITING_SPOT;
}

void DachoraWalkingToWaitingSpot(void)
{
    if (gCurrentSprite.xPosition < gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(3))
    {
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.0625f);
    }
    else
    {
        gCurrentSprite.pOam = sDachoraOam_Waiting;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = DACHORA_POSE_WAITING_FOR_OTHERS;
    }
}

void DachoraWaitingForOthers(void)
{
    u8 count;
    u8 i;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlay(SOUND_122);

    // Check if the 3 etecoons are in position and waiting
    count = 0;
    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;

        if (gSpriteData[i].properties & SP_SECONDARY_SPRITE)
            continue;
        
        if (gSpriteData[i].spriteId != PSPRITE_ETECOON)
            continue;
        
        if (gSpriteData[i].pose == DACHORA_POSE_WAITING_TO_SPAWN_BABY)
            count++;
    }

    if (count == 3)
    {
        gCurrentSprite.pose = DACHORA_POSE_WAITING_TO_SPAWN_BABY;
        gCurrentSprite.DACHORA_TIMER = CONVERT_SECONDS(1);
    }
}

void DachoraWaitingToSpawnBaby(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlay(SOUND_122);

    gCurrentSprite.DACHORA_TIMER--;
    if (gCurrentSprite.DACHORA_TIMER == 0)
    {
        gCurrentSprite.pose = DACHORA_POSE_WAITING_FOR_BABY;
        SpriteSpawnSecondary(SSPRITE_BABY_DACHORA, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(.5f), gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(3), SPRITE_STATUS_X_FLIP);
        gCurrentSprite.DACHORA_TIMER = CONVERT_SECONDS(2);
    }
}

void DachoraWaitingForBaby(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlay(SOUND_122);

    gCurrentSprite.DACHORA_TIMER--;
    if (gCurrentSprite.DACHORA_TIMER == 0)
    {
        gCurrentSprite.pose = DACHORA_POSE_BOWING;
        gPreventMovementTimer = 0;
        SAMUS_SET_POSE(SPOSE_UNLOCKING_HABITATIONS_DECK);
        gCurrentSprite.DACHORA_TIMER = CONVERT_SECONDS(1);
        gCurrentSprite.work2 = 1;
    }
}

void DachoraBowing(void)
{
    if (gCurrentSprite.DACHORA_TIMER > 0)
    {
        gCurrentSprite.DACHORA_TIMER--;
        if (gCurrentSprite.DACHORA_TIMER == 0)
        {
            gCurrentSprite.pOam = sDachoraOam_Bowing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            SoundPlay(SOUND_123);
        }
        else if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        {
            SoundPlay(SOUND_122);
        }
    }
    else if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.work2--;
        if (gCurrentSprite.work2 == 0)
        {
            gCurrentSprite.pose = DACHORA_POSE_WAITING_TO_RUN;
            gCurrentSprite.DACHORA_TIMER = CONVERT_SECONDS(1);
            gCurrentSprite.pOam = sDachoraOam_Waiting;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
}

void DachoraWaitingToRunAway(void)
{
    gCurrentSprite.DACHORA_TIMER--;
    if (gCurrentSprite.DACHORA_TIMER == 0)
    {
        gCurrentSprite.pose = DACHORA_POSE_RUNNING_AWAY;
        gCurrentSprite.pOam = sDachoraOam_Running;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        SoundPlay_3b1c(SOUND_124);
    }
}

void DachoraRunningAway(void)
{
    gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(7/32.f);
    gCurrentSprite.animationDurationCounter += 2;
    
    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
        gCurrentSprite.status = 0;
}

void BabyDachoraInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.bgPriority = 3;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625f);

    gCurrentSprite.pOam = sBabyDachoraOam_Walking;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = BABY_DACHORA_POSE_WALKING_TO_GATE;
    gCurrentSprite.BABY_DACHORA_TIMER = CONVERT_SECONDS(8/15.f);
}

void BabyDachoraWalkingToGate(void)
{
    gCurrentSprite.BABY_DACHORA_TIMER--;
    if (gCurrentSprite.BABY_DACHORA_TIMER > 0)
    {
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.0625f);
    }
    else
    {
        gCurrentSprite.pose = BABY_DACHORA_POSE_LEAVING_ENCLOSURE;
        gCurrentSprite.BABY_DACHORA_LEAVING_Y_SPEED_IDX = 0;
    }
}

void BabyDachoraLeavingEnclosure(void)
{
    u8 index;
    s16 distance;

    index = gCurrentSprite.BABY_DACHORA_LEAVING_Y_SPEED_IDX;
    distance = sAnimalsLeavingEnclosureYSpeeds[index];
    if (distance == SHORT_MAX)
    {
        gCurrentSprite.pose = BABY_DACHORA_POSE_WALKING_TO_WAITING_SPOT;
        gCurrentSprite.BABY_DACHORA_TIMER = CONVERT_SECONDS(2/3.f);
        gCurrentSprite.bgPriority = 2;
    }
    else
    {
        gCurrentSprite.BABY_DACHORA_LEAVING_Y_SPEED_IDX = index + 1;
        gCurrentSprite.yPosition += distance;
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.0625f);   
    }
}

void BabyDachoraWalkingToWaitingSpot(void)
{
    gCurrentSprite.BABY_DACHORA_TIMER--;
    if (gCurrentSprite.BABY_DACHORA_TIMER > 0)
    {
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(1/32.f);
    }
    else
    {
        gCurrentSprite.pose = BABY_DACHORA_POSE_WAITING_TO_RUN;
        gCurrentSprite.drawOrder = 5;
        gCurrentSprite.pOam = sBabyDachoraOam_Waiting;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

void BabyDachoraWaitingToRunAway(void)
{
    u8 i;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;

        if (gSpriteData[i].properties & SP_SECONDARY_SPRITE)
            continue;

        if (gSpriteData[i].spriteId != PSPRITE_DACHORA)
            continue;

        if (gSpriteData[i].pose == DACHORA_POSE_RUNNING_AWAY)
        {
            gCurrentSprite.pose = BABY_DACHORA_POSE_RUNNING_AWAY;
            gCurrentSprite.BABY_DACHORA_TIMER = CONVERT_SECONDS(1.5f);
        }
    }
}

void BabyDachoraRunningAway(void)
{
    if (gCurrentSprite.BABY_DACHORA_TIMER > 0)
    {
        gCurrentSprite.BABY_DACHORA_TIMER--;
        if (gCurrentSprite.BABY_DACHORA_TIMER == 0)
        {
            gCurrentSprite.pOam = sBabyDachoraOam_Walking;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.125f);
        gCurrentSprite.animationDurationCounter += 4;

        if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
        {
            // Turn Samus to look toward baby dachora
            gSamusData.currentAnimationFrame++;
            gCurrentSprite.status = 0;
        }
    }
}

boolu8 EtecoonCheckGrabTireSwing(void)
{
    u16 thisY;
    u16 thisX;
    u16 thisTop;
    u16 thisBottom;
    u16 thisLeft;
    u16 thisRight;

    u8 i;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    thisY = gCurrentSprite.yPosition;
    thisX = gCurrentSprite.xPosition;
    thisTop = thisY + gCurrentSprite.hitboxTop;
    thisBottom = thisY + gCurrentSprite.hitboxBottom;
    thisLeft = thisX + gCurrentSprite.hitboxLeft;
    thisRight = thisX + gCurrentSprite.hitboxRight;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;
        
        if (gSpriteData[i].properties & SP_SECONDARY_SPRITE)
            continue;

        if (gSpriteData[i].spriteId != PSPRITE_TIRE_SWING)
            continue;

        if (gSpriteData[i].status & TIRE_STATUS_HAS_ETECOON)
            continue;

        spriteY = gSpriteData[i].yPosition;
        spriteX = gSpriteData[i].xPosition;
        spriteTop = spriteY + gSpriteData[i].hitboxTop;
        spriteBottom = spriteY + gSpriteData[i].hitboxBottom;
        spriteLeft = spriteX + gSpriteData[i].hitboxLeft;
        spriteRight = spriteX + gSpriteData[i].hitboxRight;
        
        if (SpriteUtilCheckObjectsTouching(thisTop, thisBottom, thisLeft, thisRight,
            spriteTop, spriteBottom, spriteLeft, spriteRight))
        {
            gSpriteData[i].status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.ETECOON_TIRE_SLOT = i;
            return TRUE;
        }
    }

    return FALSE;
}

boolu8 EtecoonCheckFaceForeground(void)
{
    boolu8 faceForeground = TRUE;

    switch (gSpriteRandomNumber)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            gCurrentSprite.pose = ETECOON_POSE_STANDING_INIT;
            gCurrentSprite.ETECOON_ACTION = ETECOON_ACTION_STAND;
            break;

        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            gCurrentSprite.pose = ETECOON_POSE_STANDING_INIT;
            gCurrentSprite.ETECOON_ACTION = ETECOON_ACTION_TURN_HEAD;
            break;

        case 9:
        case 10:
        case 11:
        case 12:
            gCurrentSprite.pose = ETECOON_POSE_STANDING_INIT;
            gCurrentSprite.ETECOON_ACTION = ETECOON_ACTION_JUMP_ON_GLASS;
            break;

        default:
            faceForeground = FALSE;
    }

    return faceForeground;
}

void EtecoonInit(void)
{
    if (EventCheckAfter_AnimalsReleased())
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 15;
    gCurrentSprite.bgPriority = 3;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    
    gCurrentSprite.hitboxTop = - BLOCK_TO_SUB_PIXEL(1);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.1875f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.1875f);

    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(.5f);
    gCurrentSprite.workX = gCurrentSprite.xPosition;
    SpriteUtilMakeSpriteFaceSamusXFlip();
    gCurrentSprite.ETECOON_TIRE_SLOT = UCHAR_MAX;

    if ((gSpriteRandomNumber & 1) && EtecoonCheckFaceForeground())
    {
        EtecoonFacingForegroundInit();
    }
    else
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
        gCurrentSprite.pOam = sEtecoonOam_Running;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.ETECOON_X_SPEED = 0;
        gCurrentSprite.ETECOON_TIMER = CONVERT_SECONDS(1 + 41/60.f) + (gSpriteRandomNumber * 4);
    }
}

void EtecoonIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sEtecoonOam_Running;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.ETECOON_X_SPEED = 0;
    gCurrentSprite.ETECOON_TIMER = CONVERT_SECONDS(29/60.f) + MUL_SHIFT(gSpriteRandomNumber, 4);
    gCurrentSprite.ETECOON_TIRE_SLOT = UCHAR_MAX;

    if (gSpriteRandomNumber > SPRITE_RNG_PROB(.5f))
        gCurrentSprite.ETECOON_DOUBLE_SPEED = FALSE;
    else
        gCurrentSprite.ETECOON_DOUBLE_SPEED = TRUE;
}

void EtecoonIdle(void)
{
    u16 targetX;
    u32 distance;

    if (EventCheckAfter_AnimalsReleased())
    {
        gCurrentSprite.ETECOON_DOUBLE_SPEED = TRUE;

        if (gSpriteData[HABITATION_GATE_SLOT].pose == HABITATION_GATE_OPENED)
        {
            targetX = gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(4);
            if (gCurrentSprite.xPosition > targetX - BLOCK_TO_SUB_PIXEL(.5f) &&
                gCurrentSprite.xPosition < targetX + BLOCK_TO_SUB_PIXEL(.5f))
            {
                gCurrentSprite.pose = ETECOON_POSE_LEAVING_ENCLOSURE_INIT;
                return;
            }
        }
    }
    else if (gCurrentSprite.xPosition > gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(7) ||
        gCurrentSprite.xPosition < gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(7))
    {
        if (gCurrentSprite.ETECOON_TIMER > 0)
        {
            gCurrentSprite.ETECOON_TIMER--;
        }
        else if (EtecoonCheckGrabTireSwing())
        {
            gCurrentSprite.pose = ETECOON_POSE_STANDING_INIT;
            gCurrentSprite.ETECOON_ACTION = ETECOON_ACTION_JUMP_TO_TIRE;
            return;
        }
        else if (!(gFrameCounter8Bit & 0x1F) && EtecoonCheckFaceForeground())
        {
            return;
        }
    }

    if (gCurrentSprite.ETECOON_DOUBLE_SPEED)
    {
        distance = DIV_SHIFT(gCurrentSprite.ETECOON_X_SPEED, 4);

        if (gCurrentSprite.ETECOON_X_SPEED < ETECOON_X_SPEED_CAP * 2)
            gCurrentSprite.ETECOON_X_SPEED += 2;

        gCurrentSprite.animationDurationCounter++;
    }
    else
    {
        distance = DIV_SHIFT(gCurrentSprite.ETECOON_X_SPEED, 4);

        if (gCurrentSprite.ETECOON_X_SPEED < ETECOON_X_SPEED_CAP)
            gCurrentSprite.ETECOON_X_SPEED++;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.workX + BLOCK_TO_SUB_PIXEL(14) < gCurrentSprite.xPosition)
            gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_INIT;
        else
            gCurrentSprite.xPosition += distance;
    }
    else
    {
        if (gCurrentSprite.workX - BLOCK_TO_SUB_PIXEL(14) > gCurrentSprite.xPosition)
            gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_INIT;
        else
            gCurrentSprite.xPosition -= distance;
    }
}

void EtecoonStandingInit(void)
{
    gCurrentSprite.pose = ETECOON_POSE_STANDING;
    gCurrentSprite.pOam = sEtecoonOam_Standing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.ETECOON_TIMER = CONVERT_SECONDS(11/60.f);
}

void EtecoonStanding(void)
{
    if (gCurrentSprite.pOam == sEtecoonOam_Standing)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sEtecoonOam_Standing_Foreground_Still;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        gCurrentSprite.ETECOON_TIMER--;
        if (gCurrentSprite.ETECOON_TIMER == 0)
            gCurrentSprite.pose = ETECOON_POSE_FACING_FOREGROUND_INIT;
    }
}

void EtecoonFacingForegroundInit(void)
{
    gCurrentSprite.pose = ETECOON_POSE_FACING_FOREGROUND;

    if (gCurrentSprite.ETECOON_ACTION == ETECOON_ACTION_TURN_HEAD)
        gCurrentSprite.pOam = sEtecoonOam_TurningHead;
    else if (gCurrentSprite.ETECOON_ACTION == ETECOON_ACTION_JUMP_ON_GLASS)
        gCurrentSprite.pOam = sEtecoonOam_JumpingOnGlass;
    else if (gCurrentSprite.ETECOON_ACTION == ETECOON_ACTION_JUMP_TO_TIRE)
        gCurrentSprite.pOam = sEtecoonOam_JumpingToTire;
    else // ETECOON_ACTION_STAND
        gCurrentSprite.pOam = sEtecoonOam_Standing_Foreground;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.ETECOON_TIMER = gSpriteRandomNumber / 4;
}

void EtecoonFacingForeground(void)
{
    u8 tireSlot;

    tireSlot = gCurrentSprite.ETECOON_TIRE_SLOT;

    if (gCurrentSprite.ETECOON_ACTION == ETECOON_ACTION_JUMP_TO_TIRE && tireSlot != UCHAR_MAX &&
        gCurrentSprite.currentAnimationFrame == 3 && gCurrentSprite.animationDurationCounter == 6)
    {
        gCurrentSprite.pose = ETECOON_POSE_JUMPING_TO_TIRE;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sEtecoonOam_Hanging_Start;

        gSpriteData[tireSlot].animationDurationCounter = 0;
        gSpriteData[tireSlot].currentAnimationFrame = 0;
        gSpriteData[tireSlot].pOam = sTireSwingOam_Bobbing_Fast;
        gCurrentSprite.xPosition = gSpriteData[tireSlot].xPosition;
    }
    else if (SpriteUtilHasCurrentAnimationEnded())
    {
        if ((gCurrentSprite.ETECOON_ACTION == ETECOON_ACTION_JUMP_ON_GLASS ||
            gCurrentSprite.ETECOON_ACTION == ETECOON_ACTION_STAND) && gCurrentSprite.ETECOON_TIMER > 0)
        {
            gCurrentSprite.ETECOON_TIMER--;
        }
        else
        {
            gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_SECOND_PART;
            gCurrentSprite.pOam = sEtecoonOam_Standing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
    
            if (gSpriteRandomNumber < SPRITE_RNG_PROB(.4375f))
                gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
        }
    }
}

void EtecoonTurningAroundInit(void)
{
    gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND;
    gCurrentSprite.pOam = sEtecoonOam_Turning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void EtecoonTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_SECOND_PART;
        gCurrentSprite.pOam = sEtecoonOam_Turning;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;

        if (gCurrentSprite.drawOrder == 14)
            gCurrentSprite.drawOrder = 15;
        else
            gCurrentSprite.drawOrder = 14;
    }
}

void EtecoonTurningAroundSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void EtecoonJumpingToTire(void)
{
    u8 tireSlot;

    tireSlot = gCurrentSprite.ETECOON_TIRE_SLOT;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = ETECOON_POSE_SWINGING_FROM_TIRE;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sEtecoonOam_Hanging;
        gCurrentSprite.ETECOON_TIMER = gSpriteRandomNumber / 2;

        gSpriteData[tireSlot].animationDurationCounter = 0;
        gSpriteData[tireSlot].currentAnimationFrame = 0;
        gSpriteData[tireSlot].pOam = sTireSwingOam_Bobbing_Slow;
    }
}

void EtecoonSwingingFromTire(void)
{
    u8 tireSlot;

    tireSlot = gCurrentSprite.ETECOON_TIRE_SLOT;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        if (gCurrentSprite.ETECOON_TIMER > 0)
        {
            gCurrentSprite.ETECOON_TIMER--;
            if (gSpriteRandomNumber & 1)
                gCurrentSprite.pOam = sEtecoonOam_Hanging;
            else
                gCurrentSprite.pOam = sEtecoonOam_HangingAndTurning;

            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
        else
        {
            gCurrentSprite.pose = ETECOON_POSE_FALLING_FROM_TIRE;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pOam = sEtecoonOam_FallingFromTire;

            gSpriteData[tireSlot].animationDurationCounter = 0;
            gSpriteData[tireSlot].currentAnimationFrame = 0;
            gSpriteData[tireSlot].pOam = sTireSwingOam_EtecoonLeaving;
        }
    }
}

void EtecoonFallingFromTire(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_SECOND_PART;
        gCurrentSprite.pOam = sEtecoonOam_Standing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        if (gSpriteRandomNumber < SPRITE_RNG_PROB(.4375f))
            gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }
}

void EtecoonTurningAroundWhileLeavingInit(void)
{
    gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING;
    gCurrentSprite.pOam = sEtecoonOam_Turning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void EtecoonTurningAroundWhileLeaving(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_SECOND_PART;
        gCurrentSprite.pOam = sEtecoonOam_Turning;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }
}

void EtecoonTurningAroundWhileLeavingSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = ETECOON_POSE_WALKING_TO_WAITING_SPOT_INIT;
}

void EtecoonLeavingEnclosureInit(void)
{
    gCurrentSprite.pose = ETECOON_POSE_LEAVING_ENCLOSURE;
    gCurrentSprite.ETECOON_LEAVING_Y_SPEED_IDX = 0;
    gCurrentSprite.bgPriority = 2;
    gCurrentSprite.drawOrder = 4;
}

#define TWO_PIXEL_MASK (~PIXEL_TO_SUB_PIXEL(2) + ONE_SUB_PIXEL)

void EtecoonLeavingEnclosure(void)
{
    u8 index;
    s16 distance;
    u16 mask;
    u16 spriteRoundedX;
    u16 targetRoundedX;

    index = gCurrentSprite.ETECOON_LEAVING_Y_SPEED_IDX;
    distance = sAnimalsLeavingEnclosureYSpeeds[index];
    if (distance == SHORT_MAX)
    {
        // Get X positions rounded down to nearest 2-pixel increment
        spriteRoundedX = gCurrentSprite.xPosition & TWO_PIXEL_MASK;
        if (gCurrentSprite.workX == gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(1))
            targetRoundedX = (gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(4)) & TWO_PIXEL_MASK;
        else if (gCurrentSprite.workX == gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(5))
            targetRoundedX = (gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(5)) & TWO_PIXEL_MASK;
        else
            targetRoundedX = (gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(6)) & TWO_PIXEL_MASK;

        if (spriteRoundedX < targetRoundedX)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.pose = ETECOON_POSE_WALKING_TO_WAITING_SPOT;
            else
                gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_INIT;
        }
        else if (spriteRoundedX > targetRoundedX)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_INIT;
            else
                gCurrentSprite.pose = ETECOON_POSE_WALKING_TO_WAITING_SPOT;
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.pose = ETECOON_POSE_WAITING_FOR_OTHERS_INIT;
            else
                gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_INIT;
        }
    }
    else
    {
        index++;
        gCurrentSprite.ETECOON_LEAVING_Y_SPEED_IDX = index;
        gCurrentSprite.yPosition += distance;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.0625f);
        else
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(.0625f);
    }
}

void EtecoonWalkingToWaitingSpotInit(void)
{
    gCurrentSprite.pOam = sEtecoonOam_Running;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ETECOON_POSE_WALKING_TO_WAITING_SPOT;
}

void EtecoonWalkingToWaitingSpot(void)
{
    u16 spriteRoundedX;
    s32 targetXPos;
    u16 targetRoundedX;

    // Get X positions rounded down to nearest 2-pixel increment
    spriteRoundedX = gCurrentSprite.xPosition & TWO_PIXEL_MASK;
    if (gCurrentSprite.workX == gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(1))
        targetRoundedX = (gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(4)) & TWO_PIXEL_MASK;
    else if (gCurrentSprite.workX == gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(5))
        targetRoundedX = (gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(5)) & TWO_PIXEL_MASK;
    else
        targetRoundedX = (gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(6)) & TWO_PIXEL_MASK;

    if (spriteRoundedX < targetRoundedX)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.0625f);
        else
            gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_INIT;
    }
    else if (spriteRoundedX > targetRoundedX)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_INIT;
        else
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(.0625f);
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.pose = ETECOON_POSE_WAITING_FOR_OTHERS_INIT;
        else
            gCurrentSprite.pose = ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_INIT;
    }
}

void EtecoonWaitingForOthersInit(void)
{
    gCurrentSprite.pOam = sEtecoonOam_Waiting;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ETECOON_POSE_WAITING_FOR_OTHERS;
}

void EtecoonWaitingForOthers(void)
{
    u8 i;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlayNotAlreadyPlaying(SOUND_121);

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;

        if (gSpriteData[i].properties & SP_SECONDARY_SPRITE)
            continue;

        if (gSpriteData[i].spriteId != PSPRITE_DACHORA)
            continue;

        if (gSpriteData[i].pose == DACHORA_POSE_RUNNING_AWAY)
        {
            gCurrentSprite.pose = ETECOON_POSE_RUNNING_AWAY;
            gCurrentSprite.ETECOON_TIMER = CONVERT_SECONDS(1/3.f);
        }
    }
}

void EtecoonRunningAway(void)
{
    if (gCurrentSprite.ETECOON_TIMER > 0)
    {
        gCurrentSprite.ETECOON_TIMER--;
        if (gCurrentSprite.ETECOON_TIMER == 0)
        {
            gCurrentSprite.pOam = sEtecoonOam_Running;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(.25f);
        gCurrentSprite.animationDurationCounter += 2;

        if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
            gCurrentSprite.status = 0;
    }
}

void TireSwingInit(void)
{
    gCurrentSprite.drawOrder = 13;
    gCurrentSprite.bgPriority = 3;
    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(.5f);
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625f);

    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sTireSwingOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void TireSwingIdle(void)
{
    if ((gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN) &&
        gCurrentSprite.pOam == sTireSwingOam_EtecoonLeaving && SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sTireSwingOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    }
}

void Dachora(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            DachoraInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            DachoraIdleInit();

        case SPRITE_POSE_IDLE:
            DachoraIdle();
            break;

        case DACHORA_POSE_TURNING_AROUND_INIT:
            DachoraTurningAroundInit();

        case DACHORA_POSE_TURNING_AROUND:
            DachoraTurningAround();
            break;

        case DACHORA_POSE_TURNING_AROUND_SECOND_PART:
            DachoraTurningAroundSecondPart();
            break;

        case DACHORA_POSE_STANDING_INIT:
            DachoraStandingInit();

        case DACHORA_POSE_STANDING:
            DachoraStanding();
            break;

        case DACHORA_POSE_HEAD_MOVEMENT_INIT:
            DachoraHeadMovementInit();

        case DACHORA_POSE_HEAD_MOVEMENT:
            DachoraHeadMovement();
            break;

        case DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_INIT:
            DachoraTurningAroundWhileLeavingInit();

        case DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING:
            DachoraTurningAroundWhileLeaving();
            break;

        case DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_SECOND_PART:
            DachoraTurningAroundWhileLeavingSecondPart();
            break;

        case DACHORA_POSE_LEAVING_ENCLOSURE_INIT:
            DachoraLeavingEnclosureInit();

        case DACHORA_POSE_LEAVING_ENCLOSURE:
            DachoraLeavingEnclosure();
            break;

        case DACHORA_POSE_WALKING_TO_WAITING_SPOT_INIT:
            DachoraWalkingToWaitingSpotInit();

        case DACHORA_POSE_WALKING_TO_WAITING_SPOT:
            DachoraWalkingToWaitingSpot();
            break;

        case DACHORA_POSE_WAITING_FOR_OTHERS:
            DachoraWaitingForOthers();
            break;

        case DACHORA_POSE_WAITING_TO_SPAWN_BABY:
            DachoraWaitingToSpawnBaby();
            break;

        case DACHORA_POSE_WAITING_FOR_BABY:
            DachoraWaitingForBaby();
            break;

        case DACHORA_POSE_BOWING:
            DachoraBowing();
            break;

        case DACHORA_POSE_WAITING_TO_RUN:
            DachoraWaitingToRunAway();
            break;

        case DACHORA_POSE_RUNNING_AWAY:
            DachoraRunningAway();
            break;
    }
}

void BabyDachora(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            BabyDachoraInit();
            break;

        case BABY_DACHORA_POSE_WALKING_TO_GATE:
            BabyDachoraWalkingToGate();
            break;

        case BABY_DACHORA_POSE_LEAVING_ENCLOSURE:
            BabyDachoraLeavingEnclosure();
            break;

        case BABY_DACHORA_POSE_WALKING_TO_WAITING_SPOT:
            BabyDachoraWalkingToWaitingSpot();
            break;

        case BABY_DACHORA_POSE_WAITING_TO_RUN:
            BabyDachoraWaitingToRunAway();
            break;

        case BABY_DACHORA_POSE_RUNNING_AWAY:
            BabyDachoraRunningAway();
            break;
    }
}

void Etecoon(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            EtecoonInit();
            break;
        
        case SPRITE_POSE_IDLE_INIT:
            EtecoonIdleInit();
        
        case SPRITE_POSE_IDLE:
            EtecoonIdle();
            break;
        
        case ETECOON_POSE_TURNING_AROUND_INIT:
            EtecoonTurningAroundInit();
        
        case ETECOON_POSE_TURNING_AROUND:
            EtecoonTurningAround();
            break;
        
        case ETECOON_POSE_TURNING_AROUND_SECOND_PART:
            EtecoonTurningAroundSecondPart();
            break;
        
        case ETECOON_POSE_STANDING_INIT:
            EtecoonStandingInit();
        
        case ETECOON_POSE_STANDING:
            EtecoonStanding();
            break;
        
        case ETECOON_POSE_FACING_FOREGROUND_INIT:
            EtecoonFacingForegroundInit();
        
        case ETECOON_POSE_FACING_FOREGROUND:
            EtecoonFacingForeground();
            break;
        
        case ETECOON_POSE_JUMPING_TO_TIRE:
            EtecoonJumpingToTire();
            break;
        
        case ETECOON_POSE_SWINGING_FROM_TIRE:
            EtecoonSwingingFromTire();
            break;
        
        case ETECOON_POSE_FALLING_FROM_TIRE:
            EtecoonFallingFromTire();
            break;
        
        case ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_INIT:
            EtecoonTurningAroundWhileLeavingInit();
        
        case ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING:
            EtecoonTurningAroundWhileLeaving();
            break;
        
        case ETECOON_POSE_TURNING_AROUND_WHILE_LEAVING_SECOND_PART:
            EtecoonTurningAroundWhileLeavingSecondPart();
            break;
        
        case ETECOON_POSE_LEAVING_ENCLOSURE_INIT:
            EtecoonLeavingEnclosureInit();
        
        case ETECOON_POSE_LEAVING_ENCLOSURE:
            EtecoonLeavingEnclosure();
            break;
        
        case ETECOON_POSE_WALKING_TO_WAITING_SPOT_INIT:
            EtecoonWalkingToWaitingSpotInit();
        
        case ETECOON_POSE_WALKING_TO_WAITING_SPOT:
            EtecoonWalkingToWaitingSpot();
            break;
        
        case ETECOON_POSE_WAITING_FOR_OTHERS_INIT:
            EtecoonWaitingForOthersInit();
        
        case ETECOON_POSE_WAITING_FOR_OTHERS:
            EtecoonWaitingForOthers();
            break;

        case ETECOON_POSE_RUNNING_AWAY:
            EtecoonRunningAway();
            break;
    }
}

void TireSwing(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            TireSwingInit();
            break;

        case SPRITE_POSE_IDLE:
            TireSwingIdle();
            break;
    }
}

void HabitationGateLight(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            if (EventCheckAfter_AnimalsReleased())
            {
                gCurrentSprite.pOam = sHabitationGateLightOam_Flashing;
            }
            else
            {
                gCurrentSprite.pOam = sHabitationGateLightOam_Idle;
                gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
            }

            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.drawOrder = 12;
            gCurrentSprite.bgPriority = 2;
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.samusCollision = SSC_NONE;
            
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625f);
            
            gCurrentSprite.pose = SPRITE_POSE_IDLE;
            break;

        case SPRITE_POSE_IDLE:
            if (EventCheckAfter_AnimalsReleased())
            {
                gCurrentSprite.pOam = sHabitationGateLightOam_Flashing;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = HABITATION_GATE_OPENING;
            }
            break;
    }
}

void HabitationGate(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.drawOrder = 13;
            gCurrentSprite.bgPriority = 3;
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.samusCollision = SSC_NONE;
            
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625f);

            gCurrentSprite.pOam = sHabitationGateOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (EventCheckAfter_AnimalsReleased())
            {
                gCurrentSprite.status = 0;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pose = SPRITE_POSE_IDLE;
                gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
            }
            break;

        case SPRITE_POSE_IDLE:
            if (EventCheckAfter_AnimalsReleased())
            {
                gCurrentSprite.pOam = sHabitationGateOam_Opening;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = HABITATION_GATE_OPENING;
            }
            break;

        case HABITATION_GATE_OPENING:
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pose = HABITATION_GATE_OPENED;
            }
            break;
    }
}
