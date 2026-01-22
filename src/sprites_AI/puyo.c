#include "data/sprites/puyo.h"

#include "globals.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/sprite.h"

void PuyoInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    SpriteUtilMakeSpriteFaceSamusXFlip();

    gCurrentSprite.drawDistanceTop = 16;
    gCurrentSprite.drawDistanceBottom = 0;
    gCurrentSprite.drawDistanceHorizontal = 16;
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.pOam = sPuyoOam_37ce44;
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
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }
}

void PuyoFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.pOam = sPuyoOam_37ce44;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void PuyoIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sPuyoOam_37ce6c;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void PuyoIdle(void)
{
    u16 speed;
    u32 nslr;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1 &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_PUYO_IDLE);

    SpriteUtilAlignYPositionOnSlopeAtOrigin();
    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.pose = 7;
            return;
        }

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.pose = 7;
            return;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.pose = 7;
            return;
        }

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.pose = 7;
            return;
        }
    }

    if (gCurrentSprite.currentAnimationFrame == 4 || gCurrentSprite.currentAnimationFrame == 5)
        speed = 4;
    else if (gCurrentSprite.currentAnimationFrame == 3)
        speed = 8;
    else
        speed = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += speed;
    else
        gCurrentSprite.xPosition -= speed;

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(6.0f), BLOCK_TO_SUB_PIXEL(6.0f));
        if (nslr == NSLR_LEFT)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.pose = 0x29;
        }
        else if (nslr == NSLR_RIGHT)
        {
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.pose = 0x29;
        }
        else
        {
            gCurrentSprite.pose = 7;
        }
    }
}

void PuyoWaitingInit(void)
{
    gCurrentSprite.pose = 8;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sPuyoOam_37ce44;
    gCurrentSprite.work1 = gSpriteRandomNumber / 4 + 1;
}

void PuyoWaiting(void)
{
    SpriteUtilAlignYPositionOnSlopeAtOrigin();
    if (gPreviousVerticalCollisionCheck == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
    }
    else if (SpriteUtilHasCurrentAnimationEnded())
    {
        if (--gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.pose = SPRITE_POSE_IDLE;
            gCurrentSprite.pOam = sPuyoOam_37ce6c;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
}

void PuyoJumpWarningInit(void)
{
    gCurrentSprite.pose = 0x2a;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sPuyoOam_37cea4;
}

void PuyoJumpWarning(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 0x2c;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sPuyoOam_37cec4;
        gCurrentSprite.work4 = 0;

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_PUYO_JUMP);
    }
}

void PuyoJumpingUp(void)
{
    u8 offset;
    s16 movement;
    u8 hitWall;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f), gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck == COLLISION_SOLID)
    {
        gCurrentSprite.pose = 0x2e;
        gCurrentSprite.work4 = 0;
    }
    else
    {
        if (gCurrentSprite.work4 >= ARRAY_SIZE(sPuyoJumpingUpSpeed) - 1)
        {
            gCurrentSprite.pose = 0x2e;
            gCurrentSprite.work4 = 0;
        }
        else
        {
            offset = gCurrentSprite.work4;
            movement = sPuyoJumpingUpSpeed[offset];
            if (movement == SHORT_MAX)
            {
                movement = sPuyoJumpingUpSpeed[offset - 1];
                gCurrentSprite.yPosition += movement;
            }
            else
            {
                offset++;
                gCurrentSprite.work4 = offset;
                gCurrentSprite.yPosition += movement;
            }
        }

        hitWall = FALSE;
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.125f),
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                hitWall++;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.125f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                hitWall++;
        }

        if (hitWall)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.pose = 0x2e;
            gCurrentSprite.work4 = 0;
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.03125f);
            else
                gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.03125f);
        }
    }
}

void PuyoJumpingDown(void)
{
    u32 blockTop;
    u8 offset;
    s16 movement;
    u8 hitWall;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = 0x30;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sPuyoOam_37ced4;

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_PUYO_LAND);
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sPuyoJumpingDownSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = sPuyoJumpingDownSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
            gCurrentSprite.yPosition += movement;
        }
    }

    hitWall = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.125f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
            hitWall++;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.125f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
            hitWall++;
    }

    if (hitWall)
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.03125f);
    else
        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.03125f);
}


void PuyoLanding(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = 7;
}

void Puyo(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_PUYO_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            PuyoInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            PuyoIdleInit();
        case SPRITE_POSE_IDLE:
            PuyoIdle();
            break;

        case 7:
            PuyoWaitingInit();
        case 8:
            PuyoWaiting();
            break;

        case 0x29:
            PuyoJumpWarningInit();
        case 0x2a:
            PuyoJumpWarning();
            break;

        case 0x2c:
            PuyoJumpingUp();
            break;

        case 0x2e:
            PuyoJumpingDown();
            break;

        case 0x30:
            PuyoLanding();
            break;

        case SPRITE_POSE_FALLING_INIT:
            PuyoFallingInit();
        case SPRITE_POSE_FALLING:
            SpriteUtilCurrentSpriteFall();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            PuyoInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
            break;
    }
}
