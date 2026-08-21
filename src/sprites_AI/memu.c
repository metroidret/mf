#include "data/sprites/memu.h"

#include "globals.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

void MemuInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.pOam = sMemuOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    SpriteUtilChooseRandomXDirection();
    if (gSpriteRandomNumber >= 9)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

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

void MemuIdleInit(void)
{
    u8 offset;

    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    offset = gSpriteRandomNumber * 4;
    gCurrentSprite.work3 = offset;
    gCurrentSprite.work4 = offset;
}

void MemuIdle(void)
{
    u8 offset;
    s16 movement;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    offset = gCurrentSprite.work4;
    movement = sMemuIdleYSpeed[offset];
    if (movement == SHORT_MAX)
    {
        movement = sMemuIdleYSpeed[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work4 = offset;
    gCurrentSprite.yPosition += movement;

    offset = gCurrentSprite.work3;
    movement = sMemuIdleXSpeed[gCurrentSprite.work3];
    if (movement == SHORT_MAX)
    {
        movement = sMemuIdleXSpeed[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work3 = offset;
    gCurrentSprite.xPosition += movement;

    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(8.0f), BLOCK_TO_SUB_PIXEL(8.0f)) !=
        NSLR_OUT_OF_RANGE)
        gCurrentSprite.pose = 0x17;
}

void MemuChasingSamusInit(void)
{
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 1;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 1;
    gCurrentSprite.workX = gSpriteRandomNumber & 3; // Unused
    gCurrentSprite.pose = 0x18;
    gCurrentSprite.scaling = 12;
    gCurrentSprite.pOam = sMemuOam_ChasingTarget;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    SpriteUtilMakeSpriteFaceSamusDirection();
    if (gCurrentSprite.yPosition > gSamusData.yPosition + gSamusData.drawDistanceTop)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
}

void MemuChasingSamus(void)
{
    u16 y;
    u16 x;
    u16 targetY;
    u16 targetX;
    u16 hitboxSize;
    u16 speedCap;
    u8 i;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;
    hitboxSize = BLOCK_TO_SUB_PIXEL(0.375f);

    // Push follower out of the way
    for (i = gCurrentSprite.primarySpriteRamSlot + 1; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;
        if (gSpriteData[i].properties & SP_SECONDARY_SPRITE)
            continue;
        if (!(gSpriteData[i].spriteId == PSPRITE_MEMU))
            continue;

        targetY = gSpriteData[i].yPosition;
        targetX = gSpriteData[i].xPosition;

        if (y + hitboxSize > targetY - hitboxSize && y - hitboxSize < targetY + hitboxSize &&
            x + hitboxSize > targetX - hitboxSize && x - hitboxSize < targetX + hitboxSize)
        {
            if (gSpriteData[i].freezeTimer == 0)
            {
                if (y > targetY)
                    gSpriteData[i].yPosition -= BLOCK_TO_SUB_PIXEL(0.0625f);
                else
                    gSpriteData[i].yPosition += BLOCK_TO_SUB_PIXEL(0.0625f);

                if (x > targetX)
                    gSpriteData[i].xPosition -= BLOCK_TO_SUB_PIXEL(0.0625f);
                else
                    gSpriteData[i].xPosition += BLOCK_TO_SUB_PIXEL(0.0625f);

                gSpriteData[i].status ^= SPRITE_STATUS_FACING_RIGHT;
                gSpriteData[i].status ^= SPRITE_STATUS_FACING_DOWN;
            }
            break;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
    }

    targetY = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.125f);
    targetX = gSamusData.xPosition;
    speedCap = 4;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Move right
        if (gCurrentSprite.work2 == 0)
        {
            if (gCurrentSprite.xPosition > targetX - BLOCK_TO_SUB_PIXEL(0.0625f))
            {
                gCurrentSprite.work2 = gCurrentSprite.work3;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work3 < speedCap)
                    gCurrentSprite.work3++;

                // Apply speed
                gCurrentSprite.xPosition += DIV_SHIFT(gCurrentSprite.work3, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
            {
                gCurrentSprite.xPosition += DIV_SHIFT(gCurrentSprite.work2, 4);
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work3 = 1;
            }
        }
    }
    else
    {
        // Move left
        if (gCurrentSprite.work2 == 0)
        {
            if (gCurrentSprite.xPosition < targetX + BLOCK_TO_SUB_PIXEL(0.0625f))
            {
                gCurrentSprite.work2 = gCurrentSprite.work3;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work3 < speedCap)
                    gCurrentSprite.work3++;

                // Apply speed
                gCurrentSprite.xPosition -= DIV_SHIFT(gCurrentSprite.work3, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
            {
                gCurrentSprite.xPosition -= DIV_SHIFT(gCurrentSprite.work2, 4);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work3 = 1;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        // Move down
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.yPosition > targetY - BLOCK_TO_SUB_PIXEL(0.0625f))
            {
                gCurrentSprite.work1 = gCurrentSprite.work4;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work4 < speedCap)
                    gCurrentSprite.work4++;

                // Apply speed
                gCurrentSprite.yPosition += DIV_SHIFT(gCurrentSprite.work4, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                gCurrentSprite.yPosition += DIV_SHIFT(gCurrentSprite.work1, 4);
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.work4 = 1;
            }
        }
    }
    else
    {
        // Move up
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.yPosition < targetY + BLOCK_TO_SUB_PIXEL(0.0625f))
            {
                gCurrentSprite.work1 = gCurrentSprite.work4;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work4 < speedCap)
                    gCurrentSprite.work4++;

                // Apply speed
                gCurrentSprite.yPosition -= DIV_SHIFT(gCurrentSprite.work4, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                gCurrentSprite.yPosition -= DIV_SHIFT(gCurrentSprite.work1, 4);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.work4 = 1;
            }
        }
    }

    if (--gCurrentSprite.scaling == 0)
    {
        gCurrentSprite.scaling = 12;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_MEMU_CHASING);
    }
}

void Memu(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_MEMU_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MemuInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            MemuIdleInit();
            break;

        case SPRITE_POSE_IDLE:
            MemuIdle();
            break;

        case 0x17:
            MemuChasingSamusInit();
        case 0x18:
            MemuChasingSamus();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            MemuInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            break;
    }
}
