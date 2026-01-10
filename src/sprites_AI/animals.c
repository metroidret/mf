#include "sprites_AI/animals.h"

#include "event_checks.h"
#include "globals.h"
#include "samus.h"
#include "sprite.h"
#include "sprite_util.h"

#include "data/samus_data.h"
#include "data/sprites/animals.h"

#include "constants/audio.h"
#include "constants/sprite.h"

#include "structs/sprite.h"

enum DachoraPose {
    DACHORA_POSE_INIT = 0,
    DACHORA_POSE_IDLE_INIT = 1,
    DACHORA_POSE_IDLE = 2,
    DACHORA_POSE_TURNING_AROUND_INIT = 3,
    DACHORA_POSE_TURNING_AROUND = 4,
    DACHORA_POSE_TURNING_AROUND_SECOND_PART = 5,
    DACHORA_POSE_STANDING_INIT = 7,
    DACHORA_POSE_STANDING = 8,
    DACHORA_POSE_HEAD_MOVEMENT_INIT = 9,
    DACHORA_POSE_HEAD_MOVEMENT = 10,
    DACHORA_POSE_LEAVING_ENCLOSURE_INIT = 23,
    DACHORA_POSE_LEAVING_ENCLOSURE = 24,
    DACHORA_POSE_WALKING_TO_WAITING_SPOT_INIT = 25,
    DACHORA_POSE_WALKING_TO_WAITING_SPOT = 26,
    DACHORA_POSE_WAITING_FOR_OTHERS = 27,
    DACHORA_POSE_WAITING_TO_SPAWN_BABY = 28,
    DACHORA_POSE_WAITING_FOR_BABY = 29,
    DACHORA_POSE_BOWING = 30,
    DACHORA_POSE_WAITING_TO_RUN = 31,
    DACHORA_POSE_RUNNING = 32,
    DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_INIT = 55,
    DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING = 56,
    DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_SECOND_PART = 58,
};

boolu8 DachoraCheckDoHeadMovement(void)
{
    boolu8 do_head_movement;

    do_head_movement = 1;
    switch (gSpriteRandomNumber)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            gCurrentSprite.pose = DACHORA_POSE_STANDING_INIT;
            gCurrentSprite.work2 = 0;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            gCurrentSprite.pose = DACHORA_POSE_STANDING_INIT;
            gCurrentSprite.work2 = 1;
            break;
        case 8:
        case 9:
            gCurrentSprite.pose = DACHORA_POSE_STANDING_INIT;
            gCurrentSprite.work2 = 2;
            break;
        case 10:
        case 11:
        case 12:
            gCurrentSprite.pose = DACHORA_POSE_STANDING_INIT;
            gCurrentSprite.work2 = 3;
            break;
        default:
            do_head_movement = FALSE;
            break;
    }
    return do_head_movement;
}

void DachoraInit(void)
{
    boolu32 animals_released;

    animals_released = EventCheckAfter_AnimalsReleased();

    if (animals_released)
    {
        gCurrentSprite.status = SPRITE_STATUS_EXISTS;
    }
    else
    {
        gCurrentSprite.properties = gCurrentSprite.properties | SP_ALWAYS_ACTIVE;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 14;
        gCurrentSprite.bgPriority = 3;
        gCurrentSprite.drawDistanceTop = 48;
        gCurrentSprite.drawDistanceBottom = 8;
        gCurrentSprite.drawDistanceHorizontal = 32;
        gCurrentSprite.hitboxTop = -4;
        gCurrentSprite.hitboxBottom = 4;
        gCurrentSprite.hitboxLeft = -4;
        gCurrentSprite.hitboxRight = 4;
        gCurrentSprite.yPosition = gCurrentSprite.yPosition - 32;
        gCurrentSprite.workX = gCurrentSprite.xPosition;
        MakeSpriteFaceSamusXFlip();
        gCurrentSprite.pose = DACHORA_POSE_IDLE;
        gCurrentSprite.pOam = (struct FrameData*)0x0838451c;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = animals_released;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.work1 = 180;
    }
}

void DachoraIdleInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_IDLE;
    gCurrentSprite.pOam = (struct FrameData*)0x0838451c;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work1 = gSpriteRandomNumber * 4 + 60;
}

void DachoraIdle(void)
{
    u16 var1;
    u16 var2;

    if (EventCheckAfter_AnimalsReleased())
    {
        if (gSpriteData[gBossWork2].pose == DACHORA_POSE_WALKING_TO_WAITING_SPOT)
        {
            var1 = gAbilityRestingXPosition - 256;
            if (gCurrentSprite.xPosition > var1 - 32 && gCurrentSprite.xPosition < var1 + 32)
            {
                gCurrentSprite.pose = DACHORA_POSE_LEAVING_ENCLOSURE_INIT;
                return;
            }
        }
    }
    else if (gCurrentSprite.xPosition > gAbilityRestingXPosition + 448 ||
        gCurrentSprite.xPosition < gAbilityRestingXPosition - 448)
    {
        if (gCurrentSprite.work1 != 0)
        {
            gCurrentSprite.work1--;
        }
        else if ((gFrameCounter8Bit & 31) == 0 && DachoraCheckDoHeadMovement())
        {
            return;
        }
    }

    var2 = gCurrentSprite.work3 >> 2;

    if (gCurrentSprite.work3 < 16)
        gCurrentSprite.work3++;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.workX + 896 >= gCurrentSprite.xPosition)
        {
            var1 = gCurrentSprite.xPosition;
            var1 = var1 + var2;
            gCurrentSprite.xPosition = var1;
            return;
        }
        gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        if (gCurrentSprite.workX - 896 > gCurrentSprite.xPosition)
        {
            gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_INIT;
        }
        else
        {
            gCurrentSprite.xPosition -= var2;
        }
    }
}

void DachoraStandingInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_STANDING;
    gCurrentSprite.pOam = (struct FrameData*)0x0838450c;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 11;
}

void DachoraStanding(void)
{
    gCurrentSprite.work1--;
    if (!gCurrentSprite.work1)
        gCurrentSprite.pose = DACHORA_POSE_HEAD_MOVEMENT_INIT;
}


void DachoraHeadMovementInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_HEAD_MOVEMENT;

    if (gCurrentSprite.work2 == 1)
    {
        gCurrentSprite.pOam = (struct FrameData*)0x083845c4;
    }
    else if (gCurrentSprite.work2 == 2)
    {
        gCurrentSprite.pOam = (struct FrameData*)0x083845e4;
    }
    else if (gCurrentSprite.work2 == 3)
    {
        gCurrentSprite.pOam = (struct FrameData*)0x083845fc;
    }
    else
    {
        gCurrentSprite.pOam = (struct FrameData*)0x08384584;
    }

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DachoraHeadMovement(void)
{
    if (!SpriteUtilHasCurrentAnimationEnded() || (gCurrentSprite.work2 == 1 && gSpriteRandomNumber > 12))
    {
        return;
    }

    if (gSpriteRandomNumber <= 2)
    {
        gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        gCurrentSprite.pose = DACHORA_POSE_IDLE_INIT;
    }
}

void DachoraTurningAroundInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND;
    gCurrentSprite.pOam = (struct FrameData*)0x08384554;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DachoraTurningAround(void)
{
    if (!SpriteUtilHasCurrentAnimationEnded())
    {
        return;
    }

    gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_SECOND_PART;
    gCurrentSprite.pOam = (struct FrameData*)0x0838456C;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;

    if (gCurrentSprite.drawOrder == 14)
    {
        gCurrentSprite.drawOrder = 15;
    }
    else
    {
        gCurrentSprite.drawOrder = 14;
    }
}

void DachoraTurningAroundSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded() != 0)
    {
        gCurrentSprite.pose = DACHORA_POSE_IDLE_INIT;
    }
}

void DachoraTurningAroundWhileLeavingInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING;
    gCurrentSprite.pOam = (struct FrameData*)0x08384554;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DachoraTurningAroundWhileLeaving(void)
{
    if (SpriteUtilHasCurrentAnimationEnded() != 0)
    {
        gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_SECOND_PART;
        gCurrentSprite.pOam = (struct FrameData*)0x0838456C;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }
}

void DachoraTurningAroundWhileLeavingSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded() != 0)
    {
        gCurrentSprite.pose = DACHORA_POSE_WALKING_TO_WAITING_SPOT_INIT;
    }
}

void DachoraLeavingEnclosureInit(void)
{
    gCurrentSprite.pose = DACHORA_POSE_LEAVING_ENCLOSURE;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.bgPriority = 2;
    gCurrentSprite.drawOrder = 4;
}

void DachoraLeavingEnclosure(void)
{
    s16 offset;
    u8 index;

    index = gCurrentSprite.work4;
    offset = sAnimalsEnclosure_38188c[index];

    if (offset == SHORT_MAX)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.pose = DACHORA_POSE_WALKING_TO_WAITING_SPOT;
        else
            gCurrentSprite.pose = DACHORA_POSE_TURNING_AROUND_WHILE_LEAVING_INIT;
    }
    else
    {
        gCurrentSprite.work4++;
        gCurrentSprite.yPosition += offset;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += PIXEL_SIZE;
        else
            gCurrentSprite.xPosition -= PIXEL_SIZE;
    }
}

void DachoraWalkingToWaitingSpotInit(void)
{
    gCurrentSprite.pOam = (struct FrameData*)0x0838451C;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = DACHORA_POSE_WALKING_TO_WAITING_SPOT;
}

void DachoraWalkingToWaitingSpot(void)
{
    if (gCurrentSprite.xPosition < gAbilityRestingXPosition - 192)
    {
        gCurrentSprite.xPosition += 4;
    }
    else
    {
        gCurrentSprite.pOam = (struct FrameData*)0x083846CC;
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
    {
        SoundPlay(SOUND_122);
    }

    for (count = 0, i = 0; i < 24; i++)
    {
        if (gSpriteData[i].status & SPRITE_STATUS_EXISTS && !(gSpriteData[i].properties & SP_SECONDARY_SPRITE) &&
            gSpriteData[i].spriteId == PSPRITE_ETECOON && gSpriteData[i].pose == DACHORA_POSE_WAITING_TO_SPAWN_BABY)
            count++;
    }

    if (count == 3)
    {
        gCurrentSprite.pose = DACHORA_POSE_WAITING_TO_SPAWN_BABY;
        gCurrentSprite.work1 = 60;
    }
}

void DachoraWaitingToSpawnBaby(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_122);
    }

    gCurrentSprite.work1--;
    if (gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = DACHORA_POSE_WAITING_FOR_BABY;
        SpriteSpawnSecondary(105, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition - 32, gCurrentSprite.xPosition - 192, 64);
        gCurrentSprite.work1 = 120;
    }
}

void DachoraWaitingForBaby(void)
{
    u32 var;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_122);
    }

    var = --gCurrentSprite.work1;
    if (var == 0)
    {
        gCurrentSprite.pose = DACHORA_POSE_BOWING;
        gPreventMovementTimer = var;
        sSamusSetPoseFunctionPointer[gSamusData.unk_0](59);
        gCurrentSprite.work1 = 60;
        gCurrentSprite.work2 = 1;
    }
}

void DachoraBowing(void)
{
    u32 var1, var2;

    if (gCurrentSprite.work1 != 0)
    {
        var1 = --gCurrentSprite.work1;
        if (var1 == 0)
        {
            gCurrentSprite.pOam = (struct FrameData*)0x08384584;
            gCurrentSprite.animationDurationCounter = var1;
            gCurrentSprite.currentAnimationFrame = var1;
            SoundPlay(SOUND_123);
        }
        else if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        {
            SoundPlay(SOUND_123);
        }
    }
    else if (SpriteUtilHasCurrentAnimationEnded())
    {
        var2 = --gCurrentSprite.work2;
        if (var2 == 0)
        {
            gCurrentSprite.pose = DACHORA_POSE_WAITING_TO_RUN;
            gCurrentSprite.work1 = 60;
            gCurrentSprite.pOam = (struct FrameData*)0x083846CC;
            gCurrentSprite.animationDurationCounter = var2;
            gCurrentSprite.currentAnimationFrame = var2;
        }
    }
}

void DachoraWaitingToRun(void)
{
    u32 var;

    var = --gCurrentSprite.work1;
    if (var == 0)
    {
        *(&gCurrentSprite.work1 - 10) = 32;
        gCurrentSprite.pOam = (struct FrameData*)0x0838451C;
        gCurrentSprite.animationDurationCounter = var;
        gCurrentSprite.currentAnimationFrame = var;
        SoundPlay_3b1c(SOUND_124);
    }
}

void DachoraRunning(void)
{
    u16 temp;

    gCurrentSprite.xPosition += 14;
    gCurrentSprite.animationDurationCounter += 2;
    temp = gCurrentSprite.status & SPRITE_STATUS_ONSCREEN;
    if (temp == 0)
    {
        gCurrentSprite.status = temp;
    }
}

void BabyDachoraInit(void)
{
    gCurrentSprite.status &= 0xFFFB;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.bgPriority = 3;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTop = 16;
    gCurrentSprite.drawDistanceBottom = 0;
    gCurrentSprite.drawDistanceHorizontal = 8;
    gCurrentSprite.hitboxTop = -4;
    gCurrentSprite.hitboxBottom = 4;
    gCurrentSprite.hitboxLeft = -4;
    gCurrentSprite.hitboxRight = 4;
    gCurrentSprite.pOam = (struct FrameData*)0x0838462C;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = DACHORA_POSE_IDLE_INIT;
    gCurrentSprite.work1 = 32;
}

void BabyDachoraWalkingToGate(void)
{
    u8 var;

    var = --gCurrentSprite.work1;
    if (var != 0)
    {
        gCurrentSprite.xPosition += 4;
    }
    else
    {
        gCurrentSprite.pose = DACHORA_POSE_IDLE;
        gCurrentSprite.work4 = var;
    }
}

void BabyDachoraLeavingEnclosure(void)
{
    u8 var;

    var = gCurrentSprite.work4;

    if (sAnimalsEnclosure_38188c[var] == SHORT_MAX)
    {
        gCurrentSprite.pose = DACHORA_POSE_LEAVING_ENCLOSURE_INIT;
        gCurrentSprite.work1 = 40;
        gCurrentSprite.bgPriority = 2;
    }
    else
    {
        gCurrentSprite.work4 = var + 1;
        gCurrentSprite.yPosition += sAnimalsEnclosure_38188c[var];
        gCurrentSprite.xPosition += 4;
    }
}

void BabyDachoraWalkingToWaitingSpot(void)
{
    u8 var;

    var = --gCurrentSprite.work1;
    if (var)
    {
        gCurrentSprite.xPosition += 2;
    }
    else
    {
        gCurrentSprite.pose = DACHORA_POSE_LEAVING_ENCLOSURE;
        gCurrentSprite.drawOrder = 5;
        gCurrentSprite.pOam = (struct FrameData*)0x083846F4;
        gCurrentSprite.animationDurationCounter = var;
        gCurrentSprite.currentAnimationFrame = var;
    }
}

void BabyDachoraWaitingToRun(void)
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

        if (gSpriteData[i].pose == DACHORA_POSE_RUNNING)
        {
            gCurrentSprite.pose = DACHORA_POSE_WALKING_TO_WAITING_SPOT_INIT;
            gCurrentSprite.work1 = 90;
        }
    }
}

void BabyDachoraRunning(void)
{
    u16 var1, var2;

    if (gCurrentSprite.work1 != 0)
    {
        var1 = --gCurrentSprite.work1;
        if (var1 == 0)
        {
            gCurrentSprite.pOam = (struct FrameData*)0x0838462C;
            gCurrentSprite.animationDurationCounter = var1;
            gCurrentSprite.currentAnimationFrame = var1;
        }
    }
    else
    {
        gCurrentSprite.xPosition += 8;
        gCurrentSprite.animationDurationCounter += 4;

        var2 = gCurrentSprite.status & SPRITE_STATUS_ONSCREEN;
        if (var2 == 0)
        {
            gSamusData.currentAnimationFrame++;
            gCurrentSprite.status = var2;
        }
    }
}

// Etecoon stuff here

// TireSwing stuff here

void Dachora(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    switch (gCurrentSprite.pose)
    {
        case DACHORA_POSE_INIT:
            DachoraInit();
            break;
        case DACHORA_POSE_IDLE_INIT:
            DachoraIdleInit();
        case DACHORA_POSE_IDLE:
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
            DachoraWaitingToRun();
            break;
        case DACHORA_POSE_RUNNING:
            DachoraRunning();
            break;
    }
}

void BabyDachora(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    switch (gCurrentSprite.pose)
    {
        case 0:
            BabyDachoraInit();
            break;
        case 1:
            BabyDachoraWalkingToGate();
            break;
        case 2:
            BabyDachoraLeavingEnclosure();
            break;
        case 23:
            BabyDachoraWalkingToWaitingSpot();
            break;
        case 24:
            BabyDachoraWaitingToRun();
            break;
        case 25:
            BabyDachoraRunning();
        default:
            break;
    }
}
