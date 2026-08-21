#include "data/sprites/zoro.h"

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

u8 ZoroCheckCollidingWithAir(void)
{
    u8 midair;

    midair = FALSE;

    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    midair = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    midair = TRUE;
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    midair = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    midair = TRUE;
            }
        }
    }

    return midair;
}

void ZoroSetHitboxAndDrawDistance(void)
{
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.9375f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.9375f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.9375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.9375f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.9375f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.9375f);
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
#ifdef BUGFIX
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.25f);
#else  // !BUGFIX
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.25f); // BUG: Should be negative
#endif // BUGFIX
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.9375f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.9375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.9375f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.9375f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.9375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.9375f);
        }
    }

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
}

void ZoroSetCrawlingOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sZoroOam_CrawlingVertical;
    else
        gCurrentSprite.pOam = sZoroOam_CrawlingHorizontal;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void ZoroSetTurningOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sZoroOam_TurningAroundVertical1;
    else
        gCurrentSprite.pOam = sZoroOam_TurningAroundHorizontal1;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void ZoroSetTurningAroundSecondPartOam(void)
{
    if (gCurrentSprite.work0)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.pOam = sZoroOam_TurningAroundVertical2;
    }
    else
    {
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.pOam = sZoroOam_TurningAroundHorizontal2;
    }

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void ZoroSetDeathPosition(void)
{
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
        else
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.5f);
        else
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
    }
}

void ZoroInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        SpriteUtilChooseRandomXDirection();
        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.work0 = FALSE;
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0625f),
                gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            {
                gCurrentSprite.work0 = FALSE;
                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1.0f);
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition - 0x24);
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    gCurrentSprite.work0 = TRUE;
                    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                    {
                        gCurrentSprite.work0 = TRUE;
                        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);
                        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                    }
                    else
                    {
                        gCurrentSprite.status = 0;
                        return;
                    }
                }
            }
        }
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    ZoroSetCrawlingOam();
    ZoroSetHitboxAndDrawDistance();
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
}

void ZoroCrawlingInit(void)
{
    ZoroSetCrawlingOam();
    gCurrentSprite.pose = 2;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_1);
}

u16 ZoroRedGetSpeed(void)
{
    u16 speed;
    u8 onScreen;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        onScreen = TRUE;
    else
        onScreen = FALSE;

    if (gCurrentSprite.health < GET_PSPRITE_HEALTH(PSPRITE_ZORO) / 2)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 1:
            case 2:
                speed = 1;
                break;

            case 4:
            case 5:
                speed = 2;
                break;

            case 3:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_2);
                speed = 4;
                break;

            case 0:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_1);

            default:
                speed = 0;
                break;
        }

        // Double animation speed
        gCurrentSprite.animationDurationCounter++;
    }
    else
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 1:
            case 2:
            case 4:
            case 5:
                speed = 1;
                break;

            case 3:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_2);
                speed = 2;
                break;

            case 0:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_1);

            default:
                speed = 0;
                break;
        }
    }

    return speed;
}

u16 ZoroBlueGetSpeed(void)
{
    u16 speed;
    u8 onScreen;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        onScreen = TRUE;
    else
        onScreen = FALSE;

    if (gCurrentSprite.health < GET_PSPRITE_HEALTH(PSPRITE_BLUE_ZORO) / 3)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 1:
            case 2:
                speed = 2;
                break;

            case 4:
            case 5:
                speed = 4;
                break;

            case 3:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_2);
                speed = 6;
                break;

            case 0:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_1);

            default:
                speed = 0;
                break;
        }

        // Triple animation speed
        gCurrentSprite.animationDurationCounter += 2;
    }
    else if (gCurrentSprite.health < GET_PSPRITE_HEALTH(PSPRITE_BLUE_ZORO) * 2 / 3)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 1:
            case 2:
                speed = 1;
                break;

            case 4:
            case 5:
                speed = 2;
                break;

            case 3:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_2);
                speed = 4;
                break;

            case 0:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_1);

            default:
                speed = 0;
                break;
        }

        // Double animation speed
        gCurrentSprite.animationDurationCounter++;
    }
    else
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 1:
            case 2:
            case 4:
            case 5:
                speed = 1;
                break;

            case 3:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_2);
                speed = 2;
                break;

            case 0:
                if (gCurrentSprite.animationDurationCounter == 1 && onScreen)
                    SoundPlayNotAlreadyPlaying(SOUND_ZORO_CRAWLING_1);

            default:
                speed = 0;
                break;
        }
    }
    return speed;
}

void ZoroCrawl(void)
{
    u8 turn;
    u16 speed;

    if (gCurrentSprite.spriteId == PSPRITE_BLUE_ZORO)
        speed = ZoroBlueGetSpeed();
    else
        speed = ZoroRedGetSpeed();

    if (ZoroCheckCollidingWithAir())
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
        return;
    }

    turn = FALSE;
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
                    gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
                        gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.xPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.xPosition -= speed;
                }
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.xPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
                if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    turn = TRUE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                        turn = TRUE;
                    else
                        gCurrentSprite.xPosition -= speed;
                }
            }
        }
    }

    if (turn)
        gCurrentSprite.pose = 3;
}

void ZoroTurningInit(void)
{
    gCurrentSprite.pose = 4;
    ZoroSetTurningOam();
}

void ZoroTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 5;
        ZoroSetTurningAroundSecondPartOam();
    }
}

void ZoroTurningAroundSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void ZoroFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.work4 = 0;
    ZoroSetCrawlingOam();
}

void ZoroFalling(void)
{
    u16 yCollisionPoint;
    u16 xCollisionPoint;
    u32 blockTop;
    u8 onWall;
    u8 offset;
    s16 movement;

    onWall = FALSE;
    yCollisionPoint = gCurrentSprite.yPosition;
    xCollisionPoint = gCurrentSprite.xPosition;

    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            xCollisionPoint -= PIXEL_SIZE;
        yCollisionPoint += gCurrentSprite.hitboxBottom;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            yCollisionPoint += gCurrentSprite.hitboxBottom;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yCollisionPoint, xCollisionPoint);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        if (gCurrentSprite.work0)
            onWall++;

        gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.work0 = FALSE;
        ZoroSetHitboxAndDrawDistance();

        if (onWall)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxRight;
            else
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxLeft;
        }

        gCurrentSprite.pose = SPRITE_POSE_IDLE;
        ZoroSetCrawlingOam();
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sSpritesFallingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
            gCurrentSprite.yPosition += movement;
        }
    }
}

void Zoro(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_BLUE_ZORO)
    {
        if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
            SoundPlayNotAlreadyPlaying(SOUND_BLUE_ZORO_HURT);
    }
    else
    {
        if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
            SoundPlayNotAlreadyPlaying(SOUND_RED_ZORO_HURT);
    }

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ZoroInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            ZoroCrawlingInit();

        case SPRITE_POSE_IDLE:
            ZoroCrawl();
            break;

        case 3:
            ZoroTurningInit();

        case 4:
            ZoroTurningAround();
            break;

        case 5:
            ZoroTurningAroundSecondPart();
            break;

        case SPRITE_POSE_FALLING_INIT:
            ZoroFallingInit();

        case SPRITE_POSE_FALLING:
            ZoroFalling();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            ZoroInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            ZoroSetDeathPosition();
            XParasiteInit();
            break;
    }
}
