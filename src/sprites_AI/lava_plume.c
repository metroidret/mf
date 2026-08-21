#include "sprites_AI/lava_plume.h"
#include "macros.h"
#include "globals.h"

#include "data/sprite_data.h"
#include "data/sprites/lava_plume.h"

#include "constants/clipdata.h"
#include "constants/sprite.h"

#include "structs/sprite.h"

enum LavaPlumePose {
    LAVA_PLUME_POSE_GO_UP_INIT = 1,
    LAVA_PLUME_POSE_GO_UP,

    LAVA_PLUME_POSE_STOP_INIT = 23,
    LAVA_PLUME_POSE_STOP,

    LAVA_PLUME_POSE_IDLE = 26
};

enum LavaPlumeWarningPose {
    LAVA_PLUME_WARNING_POSE_IDLE = 2
};

#define GET_IDLE_TIMER() (CONVERT_SECONDS(2.f) + gSpriteRandomNumber * 4)

static void LavaPlumeInit(void)
{
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(6.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.f);

    gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(2.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.25f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.25f);

    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(.45f);
    gCurrentSprite.workY = gCurrentSprite.yPosition;
    gCurrentSprite.workX = gCurrentSprite.xPosition;

    gCurrentSprite.pose = LAVA_PLUME_POSE_IDLE;

    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.work2 = GET_IDLE_TIMER();

    gCurrentSprite.pOam = sLavaPlumeOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

static void LavaPlumeGoUpInit(void)
{
    gCurrentSprite.pOam = sLavaPlumeOam_GoingUp;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.work1 = CONVERT_SECONDS(.5f);

    gCurrentSprite.pose = LAVA_PLUME_POSE_GO_UP;

    SpriteSpawnSecondary(SSPRITE_LAVA_PLUME_WARNING, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(.45f), gCurrentSprite.xPosition, 0);
}

static void LavaPlumeGoUp(void)
{
    if (gCurrentSprite.work1 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work1);

        if (gCurrentSprite.work1 != 0)
            return;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(0x184);        
    }
    else
    {
        if (gCurrentSprite.workY - BLOCK_TO_SUB_PIXEL(1.f) > gCurrentSprite.yPosition)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.pose = LAVA_PLUME_POSE_STOP_INIT;
                return;
            }
        }

        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(.225f);
        if (SpriteUtilHasCurrentAnimationEnded())
            gCurrentSprite.pose = LAVA_PLUME_POSE_STOP_INIT;
    }
}

static void LavaPlumeStopFromSamusContact(void)
{
    SoundStop(0x184);
}

static void LavaPlumeStopInit(void)
{
    gCurrentSprite.pOam = sLavaPlumeOam_Stopping;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = LAVA_PLUME_POSE_STOP;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x185);
}

static void LavaPlumeStop(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = LAVA_PLUME_POSE_IDLE;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

        gCurrentSprite.work2 = CONVERT_SECONDS(2.f) + gSpriteRandomNumber * 4;

        gCurrentSprite.pOam = sLavaPlumeOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

static void LavaPlumeIdle(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);

    if (gCurrentSprite.work2 == 0)
    {
        gCurrentSprite.pose = LAVA_PLUME_POSE_GO_UP_INIT;
        gCurrentSprite.yPosition = gCurrentSprite.workY;
        gCurrentSprite.xPosition = gCurrentSprite.workX;
    }
}

static void LavaPlumeWarningInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.pose = LAVA_PLUME_WARNING_POSE_IDLE;

    gCurrentSprite.pOam = sLavaPlumeWarningOam_Idle1;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

static void LavaPlumeWarningIdle(void)
{
    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose == LAVA_PLUME_POSE_STOP)
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(.25f + 1.f / 60)))
        return;

    if (gSpriteRandomNumber >= SPRITE_RNG_PROB(.5f))
    {
        if (gCurrentSprite.pOam != sLavaPlumeWarningOam_Idle2)
        {
            gCurrentSprite.pOam = sLavaPlumeWarningOam_Idle2;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        if (gCurrentSprite.pOam != sLavaPlumeWarningOam_Idle1)
        {
            gCurrentSprite.pOam = sLavaPlumeWarningOam_Idle1;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
}

void LavaPlume(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            LavaPlumeInit();
            break;

        case LAVA_PLUME_POSE_GO_UP_INIT:
            LavaPlumeGoUpInit();
            break;

        case LAVA_PLUME_POSE_GO_UP:
            LavaPlumeGoUp();
            break;
            
        case SPRITE_POSE_STOPPED:
            LavaPlumeStopFromSamusContact();
            
        case LAVA_PLUME_POSE_STOP_INIT:
            LavaPlumeStopInit();
            
        case LAVA_PLUME_POSE_STOP:
            LavaPlumeStop();
            break;

        case LAVA_PLUME_POSE_IDLE:
            LavaPlumeIdle();
            break;
    }
}

void LavaPlumeWarning(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            LavaPlumeWarningInit();

        case LAVA_PLUME_WARNING_POSE_IDLE:
            LavaPlumeWarningIdle();
            break;
    }
}
