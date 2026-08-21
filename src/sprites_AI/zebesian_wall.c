#include "data/sprites/zebesian_wall.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

#define ZEBESIAN_WALL_CRAWLING_INIT 1
#define ZEBESIAN_WALL_CRAWLING 2
#define ZEBESIAN_WALL_TURNING_AROUND_INIT 0x19
#define ZEBESIAN_WALL_TURNING_AROUND 0x1a
#define ZEBESIAN_WALL_JUMPING 0x1c
#define ZEBESIAN_WALL_IDLE_INIT 7
#define ZEBESIAN_WALL_IDLE 8
#define ZEBESIAN_WALL_SHOOTING_INIT 0x29
#define ZEBESIAN_WALL_SHOOTING 0x2a

void ZebesianWallSetSideHitboxes(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.25f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.25f);
    }
}

void ZebesianWallDecideRandomAction(void)
{
    switch (gSpriteRandomNumber)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            // 1/4 chance to crawl up
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = ZEBESIAN_WALL_CRAWLING_INIT;
            break;

        case 4:
        case 5:
        case 6:
        case 7:
            // 1/4 chance to crawl down
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = ZEBESIAN_WALL_CRAWLING_INIT;
            break;

        case 8:
        case 9:
            // 1/8 chance to turn around and jump
            gCurrentSprite.pose = ZEBESIAN_WALL_TURNING_AROUND_INIT;
            break;

        case 10:
        case 11:
        case 12:
            // 3/16 chance to shoot
            gCurrentSprite.pose = ZEBESIAN_WALL_SHOOTING_INIT;
            break;

        default:
            // 3/16 chance to idle
            gCurrentSprite.pose = ZEBESIAN_WALL_IDLE_INIT;
            break;
    }
}

void ZebesianWallInit(void)
{
    // BUG: work1 uninitialized
    SpriteUtilTrySetAbsorbXFlag();
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);
    gCurrentSprite.pOam = sZebesianWallOam_Crawling;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workX = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        gCurrentSprite.bgPriority = 1;
        gCurrentSprite.pose = ZEBESIAN_WALL_CRAWLING;
        gCurrentSprite.workY = gCurrentSprite.yPosition;
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + BLOCK_SIZE);

        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            // Place zebesian on right wall
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
        }
        else
        {
            // Place zebesian on left wall
            gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
        }

        SpriteUtilChooseRandomXDirection();
    }
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.numberOfXToForm = 2;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.75f);
    }
    else
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
    }

    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.25f);
    ZebesianWallSetSideHitboxes();
}

void ZebesianWallFormingFromX(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (--gCurrentSprite.workX > 0)
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workX];
    }
    else
    {
        gCurrentSprite.pose = 2;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
}

void ZebesianWallDeath(void)
{
    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.125f);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.625f);
    else
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.625f);

    SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.875f),
        gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);
}

void ZebesianWallMovingVerticallyInit(void)
{
    gCurrentSprite.pOam = sZebesianWallOam_Crawling;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 64;
    gCurrentSprite.pose = ZEBESIAN_WALL_CRAWLING;
}

void ZebesianWallMoveVertically(void)
{
    u32 action;

    action = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.workY + BLOCK_SIZE * 2 > gCurrentSprite.yPosition)
        {
            if (--gCurrentSprite.work1 > 0)
                gCurrentSprite.yPosition += PIXEL_SIZE / 4;
            else
                action = TRUE;
        }
        else
        {
            action = TRUE;
        }
    }
    else
    {
        if (gCurrentSprite.workY - BLOCK_SIZE * 3 < gCurrentSprite.yPosition)
        {
            if (--gCurrentSprite.work1 > 0)
                gCurrentSprite.yPosition -= PIXEL_SIZE / 4;
            else
                action = TRUE;
        }
        else
        {
            action = TRUE;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
    {
        if (action)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        if (action)
            ZebesianWallDecideRandomAction();
    }
}

void ZebesianWallTurningAroundInit(void)
{
    gCurrentSprite.pOam = sZebesianWallOam_TurningAround;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = ZEBESIAN_WALL_TURNING_AROUND;
}

void ZebesianWallTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sZebesianWallOam_Jumping;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x1c;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.work4 = 0;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += BLOCK_SIZE * 2;
        else
            gCurrentSprite.xPosition -= BLOCK_SIZE * 2;

        ZebesianWallSetSideHitboxes();
        SoundPlayNotAlreadyPlaying(SOUND_ZEBESIAN_WALL_JUMP);
    }
}

void ZebesianWallJumping(void)
{
    u8 offset;
    s16 yMovement;
    s16 xMovement;

    offset = gCurrentSprite.work4;
    yMovement = sZebesianWallJumpYVelocity[offset];
    xMovement = sZebesianWallJumpXVelocity[offset];

    gCurrentSprite.yPosition += yMovement;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += xMovement;
    else
        gCurrentSprite.xPosition -= xMovement;

    offset++;
    gCurrentSprite.work4 = offset;

    if (sZebesianWallJumpYVelocity[offset] == SHORT_MAX)
        ZebesianWallDecideRandomAction();
}

void ZebesianWallIdleInit(void)
{
    gCurrentSprite.pOam = sZebesianWallOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 8;
}

void ZebesianWallIdle(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
        ZebesianWallDecideRandomAction();
}

void ZebesianWallShootingInit(void)
{
    gCurrentSprite.pOam = sZebesianWallOam_Shooting;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x2a;
}

void ZebesianWallShooting(void)
{
    if (gCurrentSprite.currentAnimationFrame == 19 && gCurrentSprite.animationDurationCounter == 1)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteSpawnSecondary(SSPRITE_ZEBESIAN_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(2.125f), SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ZEBESIAN_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(2.125f), 0);
        }
    }

    if (SpriteUtilHasCurrentAnimationEnded())
        ZebesianWallDecideRandomAction();
}

void ZebesianBeamInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(3);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.pOam = sZebesianWallBeamOam_Spawning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 2;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.bgPriority = 1;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
        gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.25f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.25f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
    }

    SoundPlayNotAlreadyPlaying(SOUND_ZEBESIAN_BEAM);
}

void ZebesianBeamSpawning(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sZebesianWallBeamOam_Extending;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x18;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.5f);
        }
        else
        {
            gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
        }
    }
}

void ZebesianBeamExtending(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sZebesianWallBeamOam_Extended;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x1a;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.5f);
            gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.5f);
        }
        else
        {
            gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.5f);
        }
    }
}

void ZebesianWall(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_ZEBESIAN_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZebesianWallInit();
            break;

        case ZEBESIAN_WALL_CRAWLING_INIT:
            ZebesianWallMovingVerticallyInit();

        case ZEBESIAN_WALL_CRAWLING:
            ZebesianWallMoveVertically();
            break;

        case ZEBESIAN_WALL_TURNING_AROUND_INIT:
            ZebesianWallTurningAroundInit();

        case ZEBESIAN_WALL_TURNING_AROUND:
            ZebesianWallTurningAround();
            break;

        case ZEBESIAN_WALL_JUMPING:
            ZebesianWallJumping();
            break;

        case ZEBESIAN_WALL_IDLE_INIT:
            ZebesianWallIdleInit();

        case ZEBESIAN_WALL_IDLE:
            ZebesianWallIdle();
            break;

        case ZEBESIAN_WALL_SHOOTING_INIT:
            ZebesianWallShootingInit();

        case ZEBESIAN_WALL_SHOOTING:
            ZebesianWallShooting();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            ZebesianWallInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            ZebesianWallFormingFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            ZebesianWallDeath();
            XParasiteInit();
            break;
    }
}

void ZebesianBeam(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZebesianBeamInit();
            break;

        case 2:
            ZebesianBeamSpawning();
            break;

        case 0x18:
            ZebesianBeamExtending();
            break;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition -= PIXEL_TO_SUB_PIXEL(2.5);
    else
        gCurrentSprite.xPosition += PIXEL_TO_SUB_PIXEL(2.5);
}
