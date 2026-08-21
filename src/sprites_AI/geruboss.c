#include "data/sprites/geruboss.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"

#include "structs/samus.h"
#include "structs/sprite.h"

enum GerubossPose {
    GERUBOSS_POSE_STALLING = 8,
    GERUBOSS_POSE_CHARGING_INIT = 0x29,
    GERUBOSS_POSE_CHARGING = 0x2a,
    GERUBOSS_POSE_GOING_DOWN = 0x2c,
    GERUBOSS_POSE_CHANGING_DIRECTION = 0x2e,
    GERUBOSS_POSE_GOING_UP = 0x30,
    GERUBOSS_POSE_GRABBING_CEILING = 0x32,
};

#define SS_GERUBOSS_FACING_DOWN SPRITE_STATUS_SAMUS_COLLIDING

boolu8 GerubossYMovement(u16 movement)
{
    if (gCurrentSprite.status & SS_GERUBOSS_FACING_DOWN)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.yPosition += movement;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.yPosition -= movement;
    }

    return FALSE;
}

boolu8 GerubossXMovement(u16 movement)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition += movement;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            return TRUE;

        gCurrentSprite.xPosition -= movement;
    }

    return FALSE;
}

void GerubossTurningIntoX(void)
{
    SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.125f),
        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5625f), SPRITE_STATUS_X_FLIP);

    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.5625f);
}

void GerubossInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    SpriteUtilMakeSpriteFaceSamusDirection();

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.875f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.875f);
    gCurrentSprite.pOam = sGerubossOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }
}

void GerubossIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGerubossOam_Idle;
    gCurrentSprite.work1 = 48;
}

void GerubossIdle(void)
{
    u8 nslr;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5625f),
        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
    if (gPreviousCollisionCheck != COLLISION_SOLID)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5625f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
        if (gPreviousCollisionCheck != COLLISION_SOLID)
        {
            SpriteUtilMakeSpriteFaceSamusDirection();
            gCurrentSprite.pose = GERUBOSS_POSE_CHARGING_INIT;
            return;
        }
    }

    if (SPRITE_GET_ISFT(gCurrentSprite) != 0)
    {
        gCurrentSprite.pose = GERUBOSS_POSE_STALLING;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerubossOam_Stalling;
        gCurrentSprite.work1 = 90;

        SoundPlayNotAlreadyPlaying(SOUND_GERUBOSS_STALL);

        return;
    }

    if (gCurrentSprite.work1 > 0)
    {
        gCurrentSprite.work1--;
    }
    else if (gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.125f) >= gCurrentSprite.yPosition)
    {
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(8.0f), BLOCK_TO_SUB_PIXEL(5.0f));
        if (nslr == NSLR_RIGHT)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = GERUBOSS_POSE_CHARGING_INIT;
        }
        else if (nslr == NSLR_LEFT)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = GERUBOSS_POSE_CHARGING_INIT;
        }
    }
}

void GerubossStalling(void)
{
    if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void GerubossChargingInit(void)
{
    gCurrentSprite.pose = GERUBOSS_POSE_CHARGING;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGerubossOam_Charging;

    SoundPlayNotAlreadyPlaying(SOUND_GERUBOSS_CHARGE);
}

void GerubossCharging(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = GERUBOSS_POSE_GOING_DOWN;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerubossOam_StartGoingDown;
        gCurrentSprite.status |= SS_GERUBOSS_FACING_DOWN;
        gCurrentSprite.work1 = 24;

        SoundPlayNotAlreadyPlaying(SOUND_GERUBOSS_START_MOVING);
    }
}

void GerubossGoingDown(void)
{
    if (gCurrentSprite.work1 > 0)
    {
        if (--gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pOam = sGerubossOam_GoingDown;
            gCurrentSprite.work2 = 0;
        }
    }
    else
    {
        if (MOD_AND(gCurrentSprite.work2, 16) == 0)
            SoundPlay(SOUND_GERUBOSS_MOVING);

        gCurrentSprite.work2++;
    }

    GerubossXMovement(BLOCK_TO_SUB_PIXEL(0.03125f));

    if (GerubossYMovement(BLOCK_TO_SUB_PIXEL(0.1875f)))
    {
        gCurrentSprite.pose = GERUBOSS_POSE_CHANGING_DIRECTION;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerubossOam_TiltingUp;
    }
}

void GerubossChangingDirection(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = GERUBOSS_POSE_GOING_UP;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerubossOam_StartGoingUp;
        gCurrentSprite.status &= ~SS_GERUBOSS_FACING_DOWN;
        gCurrentSprite.work1 = 24;

        SoundPlayNotAlreadyPlaying(SOUND_GERUBOSS_START_MOVING);
    }
}

void GerubossGoingUp(void)
{
    if (gCurrentSprite.work1 > 0)
    {
        if (--gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pOam = sGerubossOam_GoingUp;
            gCurrentSprite.work2 = 0;
        }
    }
    else
    {
        if ((gCurrentSprite.work2 & 0xf) == 0)
            SoundPlay(SOUND_GERUBOSS_MOVING);

        gCurrentSprite.work2++;
    }

    GerubossXMovement(BLOCK_TO_SUB_PIXEL(0.03125f));

    if (GerubossYMovement(BLOCK_TO_SUB_PIXEL(0.1875f)))
    {
        gCurrentSprite.pose = GERUBOSS_POSE_GRABBING_CEILING;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGerubossOam_GrabbingCeiling;
    }
}

void GerubossGrabbingCeiling(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void Geruboss(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_GERUBOSS_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GerubossInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            GerubossIdleInit();
        case SPRITE_POSE_IDLE:
            GerubossIdle();
            break;

        case GERUBOSS_POSE_STALLING:
            GerubossStalling();
            break;

        case GERUBOSS_POSE_CHARGING_INIT:
            GerubossChargingInit();
        case GERUBOSS_POSE_CHARGING:
            GerubossCharging();
            break;

        case GERUBOSS_POSE_GOING_DOWN:
            GerubossGoingDown();
            break;

        case GERUBOSS_POSE_CHANGING_DIRECTION:
            GerubossChangingDirection();
            break;

        case GERUBOSS_POSE_GOING_UP:
            GerubossGoingUp();
            break;

        case GERUBOSS_POSE_GRABBING_CEILING:
            GerubossGrabbingCeiling();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            GerubossInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            GerubossTurningIntoX();
            XParasiteInit();
            break;
    }
}
