#include "data/sprites/genesis.h"

#include "globals.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/sprite.h"

enum GenesisPose {
    GENESIS_POSE_TURNING_AROUND_INIT = 3,
    GENESIS_POSE_TURNING_AROUND_1 = 4,
    GENESIS_POSE_TURNING_AROUND_2 = 5,
    GENESIS_POSE_WAITING_INIT = 7,
    GENESIS_POSE_WAITING = 8,
    GENESIS_POSE_REACHED_WALL_INIT = 9,
    GENESIS_POSE_REACHED_WALL = 0xa,
    GENESIS_POSE_SPITTING = 0x2a,
};

void GenesisInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    SpriteUtilMakeSpriteFaceSamusXFlip();

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.f);
    gCurrentSprite.pOam = sGenesisOam_Walking;
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
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }
}

void GenesisIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gSpriteRandomNumber & 1)
        gCurrentSprite.pOam = sGenesisOam_Walking;
    else
        gCurrentSprite.pOam = sGenesisOam_Running;
}

void GenesisIdle(void)
{
    u16 speed;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1 &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_GENESIS_FOOTSTEPS);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.125f));
        if (gPreviousCollisionCheck != COLLISION_AIR)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.125f));
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
            {
                gCurrentSprite.pose = GENESIS_POSE_REACHED_WALL_INIT;
                return;
            }
        }
        else
        {
            gCurrentSprite.pose = GENESIS_POSE_REACHED_WALL_INIT;
            return;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.125f));
        if (gPreviousCollisionCheck != COLLISION_AIR)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.125f));
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
            {
                gCurrentSprite.pose = GENESIS_POSE_REACHED_WALL_INIT;
                return;
            }
        }
        else
        {
            gCurrentSprite.pose = GENESIS_POSE_REACHED_WALL_INIT;
            return;
        }
    }

    if (gCurrentSprite.pOam == sGenesisOam_Running)
        speed = BLOCK_TO_SUB_PIXEL(0.03125f);
    else
        speed = BLOCK_TO_SUB_PIXEL(0.015625f);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += speed;
    else
        gCurrentSprite.xPosition -= speed;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        switch (gSpriteRandomNumber)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                gCurrentSprite.pose = GENESIS_POSE_SPITTING;
                gCurrentSprite.pOam = sGenesisOam_Skidding;
                break;

            case 8:
            case 9:
                gCurrentSprite.pose = GENESIS_POSE_REACHED_WALL;
                gCurrentSprite.pOam = sGenesisOam_Skidding;
                break;

            case 10:
            case 11:
            case 12:
                gCurrentSprite.pOam = sGenesisOam_Running;
                break;

            case 13:
            case 14:
            case 15:
                gCurrentSprite.pOam = sGenesisOam_Walking;
                break;
        }
    }
}

void GenesisWaitingInit(void)
{
    gCurrentSprite.pose = GENESIS_POSE_WAITING;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGenesisOam_Skidding;
}

void GenesisWaiting(void)
{
    if (gCurrentSprite.pOam == sGenesisOam_Skidding)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pOam = sGenesisOam_Waiting;
        }
    }
    else
    {
        if (SpriteUtilHasCurrentAnimationNearlyEnded())
            gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }
}

void GenesisReachedWallInit(void)
{
    gCurrentSprite.pose = GENESIS_POSE_REACHED_WALL;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGenesisOam_Skidding;
}

void GenesisReachedWall(void)
{
    if (gCurrentSprite.pOam == sGenesisOam_Skidding)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pOam = sGenesisOam_Waiting;
        }
    }
    else
    {
        if (SpriteUtilHasCurrentAnimationNearlyEnded())
            gCurrentSprite.pose = GENESIS_POSE_TURNING_AROUND_INIT;
    }
}

void GenesisTurningAroundInit(void)
{
    gCurrentSprite.pose = GENESIS_POSE_TURNING_AROUND_1;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGenesisOam_TurningAround;
}

void GenesisTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sGenesisOam_TurningAround;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.pose = GENESIS_POSE_TURNING_AROUND_2;
    }
}

void GenesisTurningAroundSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void GenesisSpitting(void)
{
    if (gCurrentSprite.pOam == sGenesisOam_Skidding)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pOam = sGenesisOam_Spitting;

            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(SOUND_GENESIS_SPITTING);
        }
    }
    else
    {
        if (SpriteUtilHasCurrentAnimationNearlyEnded())
        {
            if (gSpriteRandomNumber < 12)
                gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
            else
                gCurrentSprite.pose = GENESIS_POSE_TURNING_AROUND_INIT;
        }
        else if (gCurrentSprite.currentAnimationFrame == 17 && gCurrentSprite.animationDurationCounter == 6)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                SpriteSpawnSecondary(SSPRITE_GENESIS_SPIT, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.875f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.375f), 0);
            else
                SpriteSpawnSecondary(SSPRITE_GENESIS_SPIT, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.875f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.375f), 0);
        }
    }
}

void GenesisSpitInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sGenesisSpitOam_Hanging;
    gCurrentSprite.work1 = 6;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
}

void GenesisSpitHanging(void)
{
    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.015625f);

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING;
        gCurrentSprite.work4 = 0;
    }
}

void GenesisSpitSplashingInit(void)
{
    gCurrentSprite.pOam = sGenesisSpitOam_Splashing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_LANDED;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_GENESIS_SPIT_SPLASHING);
}

void GenesisSpitSplashing(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

void Genesis(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_GENESIS_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GenesisInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            GenesisIdleInit();
        case SPRITE_POSE_IDLE:
            GenesisIdle();
            break;

        case GENESIS_POSE_WAITING_INIT:
            GenesisWaitingInit();
        case GENESIS_POSE_WAITING:
            GenesisWaiting();
            break;

        case GENESIS_POSE_REACHED_WALL_INIT:
            GenesisReachedWallInit();
        case GENESIS_POSE_REACHED_WALL:
            GenesisReachedWall();
            break;

        case GENESIS_POSE_TURNING_AROUND_INIT:
            GenesisTurningAroundInit();
        case GENESIS_POSE_TURNING_AROUND_1:
            GenesisTurningAround();
            break;

        case GENESIS_POSE_TURNING_AROUND_2:
            GenesisTurningAroundSecondPart();
            break;

        case GENESIS_POSE_SPITTING:
            GenesisSpitting();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            GenesisInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
            break;
    }
}

void GenesisSpit(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GenesisSpitInit();
            break;

        case SPRITE_POSE_IDLE:
            GenesisSpitHanging();
            break;

        case SPRITE_POSE_LANDED_INIT:
        case SPRITE_POSE_STOPPED:
            GenesisSpitSplashingInit();
        case SPRITE_POSE_LANDED:
            GenesisSpitSplashing();
            break;

        case SPRITE_POSE_FALLING:
            SpriteUtilCurrentSpriteFall();
            break;
    }
}
