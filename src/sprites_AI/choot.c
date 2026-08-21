#include "data/sprites/choot.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"

#include "structs/samus.h"
#include "structs/sprite.h"

void ChootSetOpenHitbox(void)
{
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.9375f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.9375f);
}

void ChootSetClosedHitbox(void)
{
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
}

void ChootInit(void)
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
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);

    ChootSetOpenHitbox();

    gCurrentSprite.pOam = sChootOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    {
    }
}

void ChootIdleInit(void)
{
    gCurrentSprite.pose = 2;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sChootOam_Idle;
}

void ChootIdle(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
    if (gPreviousCollisionCheck != COLLISION_SOLID)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
        if (gPreviousCollisionCheck != COLLISION_SOLID)
        {
            gCurrentSprite.pose = 0x29;
            return;
        }
    }

    if (gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.125f) <= gCurrentSprite.yPosition &&
        (u8)SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(5.0f), BLOCK_TO_SUB_PIXEL(4.0f)) !=
            NSLR_OUT_OF_RANGE)
    {
        gCurrentSprite.pose = 0x29;
    }
}

void ChootLaunchingInit(void)
{
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sChootOam_Launching;
    gCurrentSprite.pose = 0x2a;
}

void ChootLaunching(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = 0x2b;
}

void ChootGoingUpInit(void)
{
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sChootOam_Jumping;
    gCurrentSprite.pose = 0x2c;
    gCurrentSprite.work4 = 0;

    ChootSetClosedHitbox();

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_CHOOT_JUMP);
}

void ChootGoingUp(void)
{
    u8 offset;
    s16 movement;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.75f),
        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
    if (gPreviousCollisionCheck == COLLISION_SOLID)
    {
        gCurrentSprite.pose = 0x2d;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.75f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.pose = 0x2d;
        }
        else
        {
            offset = gCurrentSprite.work4;
            movement = sChootJumpVelocity[offset];
            if (movement == SHORT_MAX)
            {
                gCurrentSprite.pose = 0x2d;
            }
            else
            {
                offset++;
                gCurrentSprite.work4 = offset;
                gCurrentSprite.yPosition += movement;
                return;
            }
        }
    }
}

void ChootOpeningInit(void)
{
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sChootOam_Opening;
    gCurrentSprite.pose = 0x2e;

    ChootSetOpenHitbox();
}

void ChootOpening(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = 0x2f;
}

void ChootGoingDownInit(void)
{
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sChootOam_FloatingDown;
    gCurrentSprite.pose = 0x30;
    gCurrentSprite.work1 = 0;
}

void ChootGoingDown(void)
{
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.75f));
    if (gPreviousCollisionCheck == COLLISION_SOLID)
    {
        gCurrentSprite.pose = 1;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.75f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.pose = 1;
        }
        else
        {
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
            if (MOD_AND(gCurrentSprite.work1, 64) == 0)
            {
                SpriteSpawnSecondary(SSPRITE_CHOOT_SPIT, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition, 0);
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_CHOOT_SPIT);
            }
            gCurrentSprite.work1++;
        }
    }
}

void ChootSpitInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sChootSpitOam_Spawning;
    gCurrentSprite.work1 = 8;
    gCurrentSprite.pose = 2;
}

void ChootSpitSpawning(void)
{
    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.015625f);

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sChootSpitOam_Falling;
        gCurrentSprite.pose = SPRITE_POSE_FALLING;
        gCurrentSprite.work4 = 0;
    }
}

void ChootSpitExplodingInit(void)
{
#ifdef BUGFIX
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
#else // !BUGFIX
    // BUG: Center of spit should be checked for collision, not one block to the right
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
#endif // BUGFIX
    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        gCurrentSprite.pOam = sChootSpitOam_ExplodingOnGround;
    else
        gCurrentSprite.pOam = sChootSpitOam_ExplodingMidair;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_LANDED;
}

void ChootSpitExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

void Choot(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_CHOOT_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case 0:
            ChootInit();
            break;

        case 1:
            ChootIdleInit();
        case 2:
            ChootIdle();
            break;

        case 0x29:
            ChootLaunchingInit();
        case 0x2a:
            ChootLaunching();
            break;

        case 0x2b:
            ChootGoingUpInit();
        case 0x2c:
            ChootGoingUp();
            break;

        case 0x2d:
            ChootOpeningInit();
        case 0x2e:
            ChootOpening();
            break;

        case 0x2f:
            ChootGoingDownInit();
        case 0x30:
            ChootGoingDown();
            break;

        case 0x57:
            SpriteDyingInit();
        case 0x58:
            SpriteDying();
            break;

        case 0x59:
            ChootInit();
        case 0x5a:
            SpriteSpawningFromX();
            break;

        case 0x5b:
            XParasiteInit();
            break;
    }
}

void ChootSpit(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            ChootSpitInit();
            break;

        case 2:
            ChootSpitSpawning();
            break;

        case SPRITE_POSE_LANDED_INIT:
        case SPRITE_POSE_STOPPED:
            ChootSpitExplodingInit();
        case SPRITE_POSE_LANDED:
            ChootSpitExploding();
            break;

        case SPRITE_POSE_FALLING:
            SpriteUtilCurrentSpriteFall();
            break;
    }
}
