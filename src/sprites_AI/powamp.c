#include "sprites_AI/powamp.h"
#include "data/sprites/powamp.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"

#include "constants/audio.h"

#include "structs/sprite.h"

enum PowampPose {
    POWAMP_POSE_EXTENDING_INIT = 0x17,
    POWAMP_POSE_EXTENDING = 0x18,
    POWAMP_POSE_EXTENDED_INIT = 0x19,
    POWAMP_POSE_EXTENDED = 0x1a,
    POWAMP_POSE_RETRACTING_INIT = 0x1b,
    POWAMP_POSE_RETRACTING = 0x1c,
};

#define POWAMP_SAMUS_NEAR() SpriteUtilCheckSamusNearSpriteAboveBelowSeparateRanges( \
    BLOCK_TO_SUB_PIXEL(5), BLOCK_TO_SUB_PIXEL(3), BLOCK_TO_SUB_PIXEL(5))

/**
 * @brief 4f8d8 | bc | Initializes a powamp
 * 
 */
void PowampInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_E;
    
    gCurrentSprite.pOam = sPowampOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    
    if (gCurrentSprite.properties & SPRITE_STATUS_ONSCREEN)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.125f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.75f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.75f);
    }
    else
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.8125f);
        gCurrentSprite.hitboxBottom = -BLOCK_TO_SUB_PIXEL(.3125f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.625f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.625f);
    }
    
    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = CONVERT_SECONDS(11/15.f);
    }
    else
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
    }
}

/**
 * @brief 4f994 | 20 | Initializes a powamp to be idle
 * 
 */
void PowampIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.pOam = sPowampOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 4f9b4 | 34 | Handles a powamp being idle
 * 
 */
void PowampIdle(void)
{
    if (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN) && POWAMP_SAMUS_NEAR())
    {
        gCurrentSprite.pose = POWAMP_POSE_EXTENDING_INIT;
    }
}

/**
 * @brief 4f9e8 | 34 | Initializes a powamp to extend
 * 
 */
void PowampExtendingInit(void)
{
    gCurrentSprite.pose = POWAMP_POSE_EXTENDING;
    gCurrentSprite.pOam = sPowampOam_Extending;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_1CE);
}

/**
 * @brief 4fa1c | 30 | Handles a powamp extending
 * 
 */
void PowampExtending(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 4)
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.1875);

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = POWAMP_POSE_EXTENDED_INIT;
}

/**
 * @brief 4fa4c | 20 | Initializes a powamp to be extended
 * 
 */
void PowampExtendedInit(void)
{
    gCurrentSprite.pose = POWAMP_POSE_EXTENDED;
    gCurrentSprite.pOam = sPowampOam_Extended;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 4fa6c | 24 | Handles a powamp being extended
 * 
 */
void PowampExtended(void)
{
    if (!POWAMP_SAMUS_NEAR())
    {
        gCurrentSprite.pose = POWAMP_POSE_RETRACTING_INIT;
    }
}

/**
 * @brief 4fa90 | 38 | Initializes a powamp to retract
 * 
 */
void PowampRetractingInit(void)
{
    gCurrentSprite.pose = POWAMP_POSE_RETRACTING;
    gCurrentSprite.pOam = sPowampOam_Retracting;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_1CF);
}

/**
 * @brief 4fac8 | 68 | Handles a powamp retracting
 * 
 */
void PowampRetracting(void)
{
    if (POWAMP_SAMUS_NEAR())
    {
        gCurrentSprite.pose = POWAMP_POSE_EXTENDED;
        gCurrentSprite.pOam = sPowampOam_Extended;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.1875f);
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame == 2 && gCurrentSprite.animationDurationCounter == 4)
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.8125f);

        if (SpriteUtilHasCurrentAnimationNearlyEnded())
            gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }
}

/**
 * @brief 4fb30 | 214 | Powamp AI
 * 
 */
void Powamp(void)
{
    if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_1D0);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            PowampInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            PowampIdleInit();

        case SPRITE_POSE_IDLE:
            PowampIdle();
            break;

        case POWAMP_POSE_EXTENDING_INIT:
            PowampExtendingInit();

        case POWAMP_POSE_EXTENDING:
            PowampExtending();
            break;

        case POWAMP_POSE_EXTENDED_INIT:
            PowampExtendedInit();

        case POWAMP_POSE_EXTENDED:
            PowampExtended();
            break;

        case POWAMP_POSE_RETRACTING_INIT:
            PowampRetractingInit();

        case POWAMP_POSE_RETRACTING:
            PowampRetracting();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            PowampInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(.75f);
            break;
    }
}
