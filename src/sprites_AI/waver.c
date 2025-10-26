#include "globals.h"
#include "macros.h"
#include "sprite_util.h"

#include "data/sprites/waver.h"
#include "data/sprites/x_parasite.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_debris.h"

#include "structs/samus.h"
#include "structs/sprite.h"

#define WAVER_POSE_CHARGING 0x2a
#define WAVER_POSE_CRASHING_INIT 0x2b
#define WAVER_POSE_CRASHING 0x2c
#define WAVER_POSE_BACKING_OUT 0x2e
#define WAVER_POSE_BACKING_OUT_SECOND_PART 0x30
#define WAVER_POSE_TURNING_AFTER_BACKING_OUT 0x32

/**
 * @brief 26c7c | 2c | Checks if samus is in range of the waver to charge
 * 
 */
u8 WaverCheckSamusInRange(void)
{
    return gCurrentSprite.health != 0 &&
        SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(.625f), BLOCK_TO_SUB_PIXEL(6.25f), BLOCK_SIZE * 1) == NSFB_IN_FRONT;
}

/**
 * @brief 26ca8 | 30 | Sets the graphics for a flying waver
 * 
 */
void WaverSetFlyingGraphics(void)
{
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gCurrentSprite.pOam = sWaverOam_FlyingDown;
    else
        gCurrentSprite.pOam = sWaverOam_FlyingUp;
}

/**
 * @brief 26cd8 | c0 | Initializes a waver sprite
 * 
 */
void WaverInit(void)
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
        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        if ((gSpriteRandomNumber & 1) != 0)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
    }

    gCurrentSprite.drawDistanceTop = 16;
    gCurrentSprite.drawDistanceBottom = 16;
    gCurrentSprite.drawDistanceHorizontal = 16;

    gCurrentSprite.hitboxTop = -PIXEL_TO_SUB_PIXEL(8);
    gCurrentSprite.hitboxBottom = PIXEL_TO_SUB_PIXEL(8);
    gCurrentSprite.hitboxLeft = -PIXEL_TO_SUB_PIXEL(8);
    gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(8);

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.work4 = 6 * 8;

    WaverSetFlyingGraphics();
    SpriteUtilChooseRandomXFlip();
}

/**
 * @brief 26d98 | 18 | Initializes a waver to be flying
 * 
 */
void WaverFlyingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    WaverSetFlyingGraphics();
}

/**
 * @brief 26db0 | 1b0 | Handles a waver flying
 * 
 */
void WaverFlying(void)
{
    u8 touchedFloorCeiling;
    s16 movement;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    touchedFloorCeiling = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottom, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            touchedFloorCeiling = TRUE;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            touchedFloorCeiling = TRUE;
    }

    if (WaverCheckSamusInRange())
    {
        gCurrentSprite.pOam = sWaverOam_Charging;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = WAVER_POSE_CHARGING;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.work1 = 20;
        SoundPlayNotAlreadyPlaying(SOUND_WAVER_CHARGING);
        return;
    }

    movement = sWaverFlyingYMovement[DIV_SHIFT(gCurrentSprite.work4, 8)];

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (!touchedFloorCeiling)
            gCurrentSprite.yPosition += movement;

        if (gCurrentSprite.work4 >= ARRAY_SIZE(sWaverFlyingYMovement) * 8 - 1)
        {
            gCurrentSprite.work4 = 0;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sWaverOam_FlyingDown && SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sWaverOam_FlyingUp;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }

        if (!touchedFloorCeiling)
            gCurrentSprite.yPosition -= movement;

        if (gCurrentSprite.work4 >= ARRAY_SIZE(sWaverFlyingYMovement) * 8 - 1)
        {
            gCurrentSprite.work4 = 0;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.pOam = sWaverOam_FlyingDown;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }

    gCurrentSprite.work4++;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
        else
            gCurrentSprite.xPosition += PIXEL_TO_SUB_PIXEL(1);
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        else
            gCurrentSprite.xPosition -= PIXEL_TO_SUB_PIXEL(1);
    }
}

/**
 * @brief 26f60 | f4 | Handles a waver charging
 * 
 */
void WaverCharging(void)
{
    u16 movement;
    
    movement = DIV_SHIFT(gCurrentSprite.work3, 8) + 6;

    if (gCurrentSprite.work3 < 40)
        gCurrentSprite.work3++;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.pose = WAVER_POSE_CRASHING_INIT;
            SpriteSpawnSecondary(SSPRITE_WAVER_DEBRIS, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(SOUND_WAVER_CRASHING);

            return;
        }
        else
        {
            gCurrentSprite.xPosition += movement;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.pose = WAVER_POSE_CRASHING_INIT;
            SpriteSpawnSecondary(SSPRITE_WAVER_DEBRIS, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);

            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(SOUND_WAVER_CRASHING);

            return;
        }
        else
        {
            gCurrentSprite.xPosition -= movement;
        }
    }

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.work1 = 20;

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_WAVER_CHARGING);
    }
}

/**
 * @brief 27054 | 18 | Initializes a waver to be crashing
 * 
 */
void WaverCrashingInit(void)
{
    gCurrentSprite.pose = WAVER_POSE_CRASHING;
    gCurrentSprite.work1 = 60;
}

/**
 * @brief 2706c | 30 | Handles a waver crashing
 * 
 */
void WaverCrashing(void)
{
    gCurrentSprite.animationDurationCounter--; // Freeze animation

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = WAVER_POSE_BACKING_OUT;
        gCurrentSprite.work1 = 68;
    }
}

/**
 * @brief 2709c | 54 | Handles a waver backing out
 * 
 */
void WaverBackingOut(void)
{
    gCurrentSprite.animationDurationCounter--; // Freeze animation

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = WAVER_POSE_BACKING_OUT_SECOND_PART;
        gCurrentSprite.pOam = sWaverOam_BackingOut;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    } 
    else if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.xPosition -= PIXEL_TO_SUB_PIXEL(0.25f);
    }
    else
    {
        gCurrentSprite.xPosition += PIXEL_TO_SUB_PIXEL(0.25f);
    }
}

/**
 * @brief 270f0 | 34 | Checks if the backing out animation ended
 * 
 */
void WaverCheckBackingOutAnimEnded(void)
{
    if (SpriteUtilHasCurrentAnimationEnded()) 
    {
        gCurrentSprite.pose = WAVER_POSE_TURNING_AFTER_BACKING_OUT;
        gCurrentSprite.pOam = sWaverOam_BackingOut;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }
}

/**
 * @brief 27124 | 1c | Checks if the turning around animation has nearly ended
 * 
 */
void WaverCheckTurningAnimNearEnded(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = 1;
}

/**
 * @brief 27140 | 84 | Initializes a waver debris sprite
 * 
 */
void WaverDebrisInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.drawDistanceTop = 16;
    gCurrentSprite.drawDistanceBottom = 16;
    gCurrentSprite.drawDistanceHorizontal = 16;

    gCurrentSprite.hitboxTop = -PIXEL_TO_SUB_PIXEL(8);
    gCurrentSprite.hitboxBottom = PIXEL_TO_SUB_PIXEL(1);
    gCurrentSprite.hitboxLeft = -PIXEL_TO_SUB_PIXEL(10);
    gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(10);

    gCurrentSprite.pOam = sWaverDebrisOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 16;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.pose = 2;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 3;
}

/**
 * @brief 271c4 | 9c | Handles a waver debris falling
 * 
 */
void WaverDebrisFalling(void)
{
    u8 offset;
    s16 movement;

    if (gCurrentSprite.work1 == 0) 
    {
        SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != 0) 
        {
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_HEAVY_DUST_1);
            gCurrentSprite.status = 0;
            return;
        }
    } 
    else
    {
        gCurrentSprite.work1--;
    }

    offset = gCurrentSprite.work4;
    movement = sWaverDebrisFallingSpeed[offset];

    if (movement == SHORT_MAX) 
    {
        movement = sWaverDebrisFallingSpeed[offset - 1];
        gCurrentSprite.yPosition += movement;
    } 
    else 
    {
        offset++;
        gCurrentSprite.work4 = offset;
        gCurrentSprite.yPosition += movement;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += PIXEL_SIZE;
    else
        gCurrentSprite.xPosition -= PIXEL_SIZE;
}

/**
 * @brief 27260 | 1c | Handles a waver debris exploding
 * 
 */
void WaverDebrisExploding(void)
{
    ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x25);
    gCurrentSprite.status = 0;
}

/**
 * @brief 2727c | 20c | Waver AI
 * 
 */
void Waver(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_WAVER_HURT);

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            WaverInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            WaverFlyingInit();

        case SPRITE_POSE_IDLE:
            WaverFlying();
            break;

        case WAVER_POSE_CHARGING:
            WaverCharging();
            break;

        case WAVER_POSE_CRASHING_INIT:
            WaverCrashingInit();
            
        case WAVER_POSE_CRASHING:
            WaverCrashing();
            break;
            
        case WAVER_POSE_BACKING_OUT:
            WaverBackingOut();
            break;
            
        case WAVER_POSE_BACKING_OUT_SECOND_PART:
            WaverCheckBackingOutAnimEnded();
            break;
            
        case WAVER_POSE_TURNING_AFTER_BACKING_OUT:
            WaverCheckTurningAnimNearEnded();
            break;
            
        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
            
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;
            
        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            WaverInit();
            
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;
            
        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            break;
    }
}

/**
 * @brief 27488 | 30 | Waver explosion AI
 * 
 */
void WaverExplosion(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose) 
    {
        case SPRITE_POSE_UNINITIALIZED:
            WaverDebrisInit();

        case SPRITE_POSE_IDLE:
            WaverDebrisFalling();
            break;

        default:
            WaverDebrisExploding();
            break;
    }
}
