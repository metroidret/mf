#include "sprites_AI/box_2.h"
#include "data/sprites/box_2.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/frame_data_pointers.h"
#include "data/sprite_pointers.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/samus.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

// BOX 2 values

#define BOX_2_CRAWLING_X_SPEED 1
#define BOX_2_FAST_RUNNING_X_SPEED 8
#define BOX_2_JUMPING_X_SPEED 12

enum Box2Pose {
    BOX_2_POSE_CRAWLING_INIT = 1,
    BOX_2_POSE_CRAWLING = 2,
    BOX_2_POSE_FINISHED_CRAWLING_INIT = 7,
    BOX_2_POSE_FINISH_CRAWLING = 8,
    BOX_2_POSE_WAITING_TO_RUN_INIT = 0x17,
    BOX_2_POSE_WAITING_TO_RUN = 0x18,
    BOX_2_POSE_SLOW_RUNNING_INIT = 0x19,
    BOX_2_POSE_SLOW_RUNNING = 0x1a,
    BOX_2_POSE_FAST_RUNNING_INIT = 0x1b,
    BOX_2_POSE_FAST_RUNNING = 0x1c,
    BOX_2_POSE_SKIDDING_INIT = 0x1d,
    BOX_2_POSE_SKIDDING = 0x1e,
    BOX_2_POSE_STOP_SKIDDING_INIT = 0x1f,
    BOX_2_POSE_STOP_SKIDDING = 0x20,
    BOX_2_POSE_STOPPING_TO_FIRE_MISSILES_INIT = 0x27,
    BOX_2_POSE_STOPPING_TO_FIRE_MISSILES = 0x28,
    BOX_2_POSE_LOWERING_TO_FIRE_MISSILES_INIT = 0x29,
    BOX_2_POSE_LOWERING_TO_FIRE_MISSILES = 0x2a,
    BOX_2_POSE_FIRING_MISSILES = 0x2c,
    BOX_2_POSE_DONE_FIRING_MISSILES = 0x2e,
    BOX_2_POSE_BONKING_INIT = 0x37,
    BOX_2_POSE_BONKING = 0x38,
    BOX_2_POSE_LANDING_INIT = 0x39,
    BOX_2_POSE_LANDING = 0x3a,
    BOX_2_POSE_JUMP_WARNING_INIT = 0x3b,
    BOX_2_POSE_JUMP_WARNING = 0x3c,
    BOX_2_POSE_JUMPING_INIT = 0x3d,
    BOX_2_POSE_JUMPING = 0x3e,
    BOX_2_POSE_DYING_INIT = 0x43,
    BOX_2_POSE_DYING = 0x44,
    BOX_2_POSE_EXPLODING_INIT = 0x45,
    BOX_2_POSE_EXPLODING = 0x46,
    BOX_2_POSE_BRAIN_RISING_INIT = 0x47,
    BOX_2_POSE_BRAIN_RISING = 0x48,
    BOX_2_POSE_BRAIN_FLOATING = 0x49,
    BOX_2_POSE_LANDING_FROM_BONK_INIT = 0x4b,
    BOX_2_POSE_LANDING_FROM_BONK = 0x4c,
};

#define BOX_2_PARTS_ALIVE work0
#define BOX_2_LEFT_LEG_ALIVE  (1 << 0)
#define BOX_2_RIGHT_LEG_ALIVE (1 << 1)
#define BOX_2_CENTER_ALIVE    (1 << 2)

#define BOX_2_ANIM_COUNTER work1
#define BOX_2_X_SPEED work1
#define BOX_2_TIMER work1

#define BOX_2_JUMP_COUNTER work2
#define BOX_2_TURNED_AROUND 0x80

#define BOX_2_Y_SPEED_IDX work4

// BOX 2 part values

#define BOX_2_PART_TIMER work1

// BOX 2 missile values

enum Box2MissilePose {
    BOX_2_MISSILE_POSE_MOVING = 0x18,
};

#define BOX_2_MISSILE_DURATION workY
#define BOX_2_MISSILE_IN_WATER work0
#define BOX_2_MISSILE_Y_SPEED work1

// BOX 2 brain top values

enum Box2BrainTopPose {
    BOX_2_BRAIN_TOP_POSE_FLOATING = 0x18,
    BOX_2_BRAIN_TOP_POSE_TRANSFORMING_INIT = 0x45,
    BOX_2_BRAIN_TOP_POSE_TRANSFORMING = 0x46,
};

#define BOX_2_BRAIN_TOP_MOSAIC_TIMER workY
#define BOX_2_BRAIN_TOP_FLOATING_TIMER work1
#define BOX_2_BRAIN_TOP_BRAIN_BOTTOM_SLOT work2
#define BOX_2_BRAIN_TOP_Y_SPEED_IDX work4

// gSubSpriteData1 values

#define BOX_2_FLASH_TIMER work0

/**
 * @brief 519ac | 68 | Syncs all the parts of BOX 2
 *
 */
void Box2SyncSubSprites(void)
{
    MultiSpriteDataInfo_T msdi;
    u16 oamIdx;

    msdi = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = msdi[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sBox2FrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sBox2FrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition +
        msdi[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition +
        msdi[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 51a14 | a4 | Moves BOX 2 horizontally
 *
 * @param speed X speed
 * @param collidedPose Pose to set if collided with wall
 * @return u8 bool, collided with wall
 */
boolu8 Box2XMovement(u16 speed, u8 collidedPose)
{
    boolu8 collided;

    collided = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.25f),
            gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1 + 23/32.f));
        if (gPreviousCollisionCheck != 0)
        {
            gCurrentSprite.pose = collidedPose;
            collided = TRUE;
        }
        else
        {
            gSubSpriteData1.xPosition += speed;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.25f),
            gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1 + 23/32.f));
        if (gPreviousCollisionCheck != 0)
        {
            gCurrentSprite.pose = collidedPose;
            collided = TRUE;
        }
        else
        {
            gSubSpriteData1.xPosition -= speed;
        }
    }

    return collided;
}

/**
 * @brief 51ab8 | 1f4 | Initializes BOX 2
 *
 */
void Box2Init(void)
{
    if (gEquipment.beamStatus & BF_WAVE_BEAM)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.625);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.75f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.75f);

    gCurrentSprite.BOX_2_PARTS_ALIVE = BOX_2_LEFT_LEG_ALIVE | BOX_2_RIGHT_LEG_ALIVE | BOX_2_CENTER_ALIVE;
    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.frozenPaletteRowOffset = 2;
    gCurrentSprite.roomSlot = BOX_2_PART_BRAIN;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.pOam = sBox2PartOam_Brain_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
    gSubSpriteData1.pMultiOam = sBox2MultiOam_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gSubSpriteData1.BOX_2_FLASH_TIMER = 0;

    gCurrentSprite.BOX_2_JUMP_COUNTER = 0;
    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.pose = BOX_2_POSE_WAITING_TO_RUN_INIT;

    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_FRONT_LEFT_LEG_COVER, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_FRONT_LEFT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_FRONT_RIGHT_LEG_COVER, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_FRONT_RIGHT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_MIDDLE_LEFT_LEG, gCurrentSprite.spritesetGfxSlot, 
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_MIDDLE_RIGHT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_CENTER, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_BOTTOM, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_LAUNCHER, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_BACK_LEFT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX_2_PART_BACK_RIGHT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);

    SpriteSpawnPrimary(PSPRITE_ELECTRIC_WATER_DAMAGE_BOX_2, gCurrentSprite.roomSlot,
        7, SSP_UNINFECTED_OR_BOSS, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
}

/**
 * @brief 51cac | 38 | Initializes BOX 2 to wait to run
 *
 */
void Box2WaitingToRunInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiOam_WaitingToRun;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_2_POSE_WAITING_TO_RUN;
    gCurrentSprite.BOX_2_ANIM_COUNTER = 0;

    SoundPlay(SOUND_BOX_WAIT_TO_RUN);
}

/**
 * @brief 51ce4 | 40 | Handles BOX 2 waiting to run
 *
 */
void Box2WaitingToRun(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        gCurrentSprite.BOX_2_ANIM_COUNTER++;
        if (gCurrentSprite.BOX_2_ANIM_COUNTER == 1)
            gCurrentSprite.pose = BOX_2_POSE_SLOW_RUNNING_INIT;
    }

    if (gCurrentSprite.BOX_2_JUMP_COUNTER > 0)
        gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
}

/**
 * @brief 51d24 | 54 | Initializes BOX 2 to slow run
 *
 */
void Box2SlowRunningInit(void)
{
    SpriteUtilMakeSpriteFaceSamusDirection();

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBox2MultiOam_SlowRunning_Right;
    else
        gSubSpriteData1.pMultiOam = sBox2MultiOam_SlowRunning_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_SLOW_RUNNING;
    gCurrentSprite.BOX_2_X_SPEED = 0;
}

/**
 * @brief 51d78 | a4 | Handles BOX 2 slow running
 *
 */
void Box2SlowRunning(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_279);

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.625f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.875f), PE_SPRITE_ENTER_OR_EXIT_WATER);
        }
        else
        {
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.625f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.875f), PE_SPRITE_ENTER_OR_EXIT_WATER);
        }
    }

    if (!Box2XMovement(gCurrentSprite.BOX_2_X_SPEED, BOX_2_POSE_BONKING_INIT))
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        {
            gCurrentSprite.BOX_2_X_SPEED++;
            if (gCurrentSprite.BOX_2_X_SPEED == 7)
                gCurrentSprite.pose = BOX_2_POSE_FAST_RUNNING_INIT;
        }

        if (gCurrentSprite.BOX_2_JUMP_COUNTER > 0)
            gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
    }
}

/**
 * @brief 51e1c | 4c | Initializes BOX 2 to fast run
 *
 */
void Box2FastRunningInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBox2MultiOam_FastRunning_Right;
    else
        gSubSpriteData1.pMultiOam = sBox2MultiOam_FastRunning_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_FAST_RUNNING;
    gCurrentSprite.BOX_2_TIMER = 10;
}

/**
 * @brief 51e68 | d8 | Handles BOX 2 fast running
 *
 */
void Box2FastRunning(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_279);

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.9375f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(2.5f), PE_SPRITE_ENTER_OR_EXIT_WATER);
        }
        else
        {
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.9375f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(2.5f), PE_SPRITE_ENTER_OR_EXIT_WATER);
        }
    }

    if (!Box2XMovement(BOX_2_FAST_RUNNING_X_SPEED, BOX_2_POSE_BONKING_INIT))
    {
        if (gCurrentSprite.BOX_2_TIMER > 0)
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.BOX_2_TIMER);
            return;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(3.125f) > gSamusData.xPosition)
                gCurrentSprite.pose = BOX_2_POSE_SKIDDING_INIT;
        }
        else
        {
            if (gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(3.125f) < gSamusData.xPosition)
                gCurrentSprite.pose = BOX_2_POSE_SKIDDING_INIT;
        }
    }

    if (gCurrentSprite.BOX_2_JUMP_COUNTER > 0)
        gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
}

/**
 * @brief 51f40 | 54 | Initializes BOX 2 to skid
 *
 */
void Box2SkiddingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBox2MultiOam_Skidding_Right;
    else
        gSubSpriteData1.pMultiOam = sBox2MultiOam_Skidding_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_SKIDDING;
    gCurrentSprite.BOX_2_X_SPEED = BLOCK_TO_SUB_PIXEL(0.125f) * 4;
    
    SoundPlay(SOUND_BOX_SKID);
}

/**
 * @brief 51f94 | 50 | Handles BOX 2 skidding
 *
 */
void Box2Skidding(void)
{
    u16 xSpeed;
    u8 collidePose;

    xSpeed = gCurrentSprite.BOX_2_X_SPEED / 4;
    if (xSpeed > 5)
        collidePose = BOX_2_POSE_BONKING_INIT;
    else
        collidePose = BOX_2_POSE_STOP_SKIDDING_INIT;
    
    if (!Box2XMovement(xSpeed, collidePose))
    {
        gCurrentSprite.BOX_2_X_SPEED--;
        if (gCurrentSprite.BOX_2_X_SPEED == 0)
            gCurrentSprite.pose = BOX_2_POSE_STOP_SKIDDING_INIT;

        if (gCurrentSprite.BOX_2_JUMP_COUNTER > 0)
            gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
    }
}

/**
 * @brief 51fe4 | 44 | Initializes BOX 2 to stop skidding
 *
 */
void Box2StopSkiddingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBox2MultiOam_StopSkidding_Right;
    else
        gSubSpriteData1.pMultiOam = sBox2MultiOam_StopSkidding_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_STOP_SKIDDING;
}

/**
 * @brief 52028 | 3c | Handles BOX 2 stopping skidding
 *
 */
void Box2StopSkidding(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
        gCurrentSprite.BOX_2_JUMP_COUNTER = 3;
    }
    else if (gCurrentSprite.BOX_2_JUMP_COUNTER > 0)
    {
        gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
    }
}

/**
 * @brief 52064 | 54 | Initializes BOX 2 to bonk
 *
 */
void Box2BonkingInit(void)
{
    gSubSpriteData1.yPosition -= BLOCK_TO_SUB_PIXEL(.25f);
    gSubSpriteData1.pMultiOam = sBox2MultiOam_Jumping;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_2_POSE_BONKING;
    gCurrentSprite.BOX_2_Y_SPEED_IDX = 0;
    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

    SoundPlay(SOUND_BOX_BONK);
    ScreenShakeStartHorizontal(CONVERT_SECONDS(1/3.f), 0x80 | 1);
}

/**
 * @brief 520b8 | f4 | Handles BOX 2 bonking
 *
 */
void Box2Bonking(void)
{
    s32 blockTop;
    u8 index;
    s16 ySpeed;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition);
    if (gPreviousVerticalCollisionCheck != 0)
    {
        gSubSpriteData1.yPosition = blockTop;
        gCurrentSprite.pose = BOX_2_POSE_LANDING_FROM_BONK_INIT;
        return;
    }

    index = gCurrentSprite.BOX_2_Y_SPEED_IDX;
    ySpeed = sBox2BonkingYSpeeds[index];
    if (ySpeed == SHORT_MAX)
    {
        ySpeed = sBox2BonkingYSpeeds[index - 1];
        gSubSpriteData1.yPosition += ySpeed;
    }
    else
    {
        index++;
        gCurrentSprite.BOX_2_Y_SPEED_IDX = index;
        gSubSpriteData1.yPosition += ySpeed;

        // Assumes that BOX enters the water on frame 16
        if (index == 16)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.8125),
                    gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1), PE_SPRITE_ENTER_OR_EXIT_WATER);
                ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.8125),
                    gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(2), PE_SPRITE_ENTER_OR_EXIT_WATER);
            }
            else
            {
                ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.8125),
                    gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(2), PE_SPRITE_ENTER_OR_EXIT_WATER);
                ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.8125),
                    gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1), PE_SPRITE_ENTER_OR_EXIT_WATER);
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.xPosition += BLOCK_TO_SUB_PIXEL(3/32.f);
    else
        gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(3/32.f);
}

/**
 * @brief 521ac | 40 | Initializes BOX 2 to land from bonk
 *
 */
void Box2LandingFromBonkInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiOam_Landing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_2_POSE_LANDING_FROM_BONK;
    gCurrentSprite.BOX_2_JUMP_COUNTER = 0;
    gCurrentSprite.BOX_2_Y_SPEED_IDX = 0;

    SoundPlay(SOUND_27A);
}

/**
 * @brief 521ec | 58 | Handles BOX 2 landing from bonk
 *
 */
void Box2LandingFromBonk(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (gCurrentSprite.xPosition > gSamusData.xPosition)
                gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
            else
                gCurrentSprite.pose = BOX_2_POSE_WAITING_TO_RUN_INIT;
        }
        else
        {
            if (gCurrentSprite.xPosition < gSamusData.xPosition)
                gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
            else
                gCurrentSprite.pose = BOX_2_POSE_WAITING_TO_RUN_INIT;
        }
    }
}

/**
 * @brief 52244 | 38 | Initializes BOX 2 to land
 *
 */
void Box2LandingInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiOam_Landing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_LANDING;
    gCurrentSprite.BOX_2_Y_SPEED_IDX = 0;

    SoundPlay(SOUND_27A);
}

/**
 * @brief 5227c | 38 | Handles BOX 2 landing
 *
 */
void Box2Landing(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gCurrentSprite.BOX_2_JUMP_COUNTER == 0)
        {
            gCurrentSprite.pose = BOX_2_POSE_STOPPING_TO_FIRE_MISSILES_INIT;
        }
        else
        {
            gCurrentSprite.BOX_2_JUMP_COUNTER--;
            if ((gCurrentSprite.BOX_2_JUMP_COUNTER & 0x7F) == 0)
                gCurrentSprite.BOX_2_JUMP_COUNTER = 0;

            gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
        }
    }
}

/**
 * @brief 522b4 | 3c | Initializes BOX 2 to finish crawling
 *
 */
void Box2FinishedCrawlingInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiOam_StoppingToFireMissiles;
    gCurrentSprite.BOX_2_ANIM_COUNTER = 2;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_FINISH_CRAWLING;

    SoundPlay(SOUND_BOX_FINISH_CRAWLING);
}

/**
 * @brief 522f0 | 5c | Handles BOX 2 finishing crawling
 *
 */
void Box2FinishCrawling(void)
{
    if (gCurrentSprite.BOX_2_ANIM_COUNTER > 1)
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
            gCurrentSprite.BOX_2_ANIM_COUNTER--;
    }
    else if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (SpriteUtilCheckSamusOnCeilingLadder())
            gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
        else if (gCurrentSprite.BOX_2_JUMP_COUNTER > 0)
            gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING_INIT;
        else
            gCurrentSprite.pose = BOX_2_POSE_SLOW_RUNNING_INIT;
    }
}

/**
 * @brief 5234c | 4c | Initializes BOX 2 to do a jump warning
 *
 */
void Box2JumpWarningInit(void)
{
    u16 samusX;

    samusX = gSamusData.xPosition;
    if (gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.875f) < samusX &&
        gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.875f) > samusX)
    {
        Box2StoppingToFireMissilesInit();
        return;
    }

    gSubSpriteData1.pMultiOam = sBox2MultiOam_JumpWarning;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_JUMP_WARNING;
}

/**
 * @brief 52398 | 1c | Handles BOX 2 doing a jump warning
 *
 */
void Box2JumpWarning(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = BOX_2_POSE_JUMPING_INIT;
}

/**
 * @brief 523b4 | 120 | Initializes BOX 2 to jump
 *
 */
void Box2JumpingInit(void)
{
    u8 turnAround;

    turnAround = FALSE;

    gSubSpriteData1.pMultiOam = sBox2MultiOam_Jumping;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_JUMPING;
    gCurrentSprite.BOX_2_Y_SPEED_IDX = 0;

    if (!(gCurrentSprite.BOX_2_JUMP_COUNTER & BOX_2_TURNED_AROUND))
    {
        if (SpriteUtilCheckSamusOnCeilingLadder())
            SpriteUtilMakeSpriteFaceSamusDirection();
        else
            SpriteUtilMakeSpriteFaceAwayFromSamusDirection();

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.5f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(5 + 15/32.f));
            if (gPreviousCollisionCheck != 0)
                turnAround++;

            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.5f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.875f));
            if (gPreviousCollisionCheck != 0)
                turnAround++;

            if (turnAround) {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.BOX_2_JUMP_COUNTER = BOX_2_TURNED_AROUND | 2;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.5f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(5 + 15/32.f));
            if (gPreviousCollisionCheck != 0)
                turnAround++;

            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.5f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.875f));
            if (gPreviousCollisionCheck != 0)
                turnAround++;

            if (turnAround)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.BOX_2_JUMP_COUNTER = BOX_2_TURNED_AROUND | 2;
            }
        }
    }

    SoundPlay(SOUND_BOX_JUMP);
}

/**
 * @brief 524d4 | a4 | Handles BOX 2 jumping
 *
 */
void Box2Jumping(void)
{
    u8 index;
    s16 ySpeed;

    index = gCurrentSprite.BOX_2_Y_SPEED_IDX;
    ySpeed = sBox2JumpingYSpeeds[index];
    if (ySpeed == SHORT_MAX)
    {
        gCurrentSprite.pose = BOX_2_POSE_LANDING_INIT;
        return;
    }

    index++;
    gCurrentSprite.BOX_2_Y_SPEED_IDX = index;
    gSubSpriteData1.yPosition += ySpeed;

    // Assumes BOX enters the water on frame 23
    if (index == 23)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.25f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1), PE_SPRITE_ENTER_OR_EXIT_WATER);
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.25f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(2), PE_SPRITE_ENTER_OR_EXIT_WATER);
        }
        else
        {
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.25f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(2), PE_SPRITE_ENTER_OR_EXIT_WATER);
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(.25f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1), PE_SPRITE_ENTER_OR_EXIT_WATER);
        }
    }

    Box2XMovement(BOX_2_JUMPING_X_SPEED, BOX_2_POSE_BONKING_INIT);
}

/**
 * @brief 52578 | 3c | Initializes BOX 2 to stop to fire missiles
 *
 */
void Box2StoppingToFireMissilesInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiOam_StoppingToFireMissiles;
    gCurrentSprite.BOX_2_ANIM_COUNTER = 3;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_STOPPING_TO_FIRE_MISSILES;

    SoundPlay(SOUND_BOX_FINISH_CRAWLING);
}

/**
 * @brief 525b4 | 3c | Handles BOX 2 stopping to fire missiles
 *
 */
void Box2StoppingToFireMissiles(void)
{
    if (gCurrentSprite.BOX_2_ANIM_COUNTER > 1)
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
            gCurrentSprite.BOX_2_ANIM_COUNTER--;
    }
    else
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
            gCurrentSprite.pose = BOX_2_POSE_LOWERING_TO_FIRE_MISSILES_INIT;
    }
}

/**
 * @brief 525f0 | 30 | Initializes BOX 2 to lower to fire missiles
 *
 */
void Box2LoweringToFireMissilesInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiOam_LoweringToFireMissiles;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_LOWERING_TO_FIRE_MISSILES;

    SoundPlay(SOUND_BOX_LOWER_TO_FIRE_BOMB);
}

/**
 * @brief 52620 | 30 | Handles BOX 2 lowering to fire missiles
 *
 */
void Box2LoweringToFireMissiles(void)
{
    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gCurrentSprite.pose = BOX_2_POSE_FIRING_MISSILES;
        gSubSpriteData1.pMultiOam = sBox2MultiOam_FiringMissiles;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
    }
}

/**
 * @brief 52650 | 108 | Handles BOX 2 firing missiles
 *
 */
void Box2FiringMissiles(void)
{
    u16 frame;
    u8 counter;
    u16 yPosition;
    u16 xPosition;

    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gCurrentSprite.pose = BOX_2_POSE_DONE_FIRING_MISSILES;
        gSubSpriteData1.pMultiOam = sBox2MultiOam_DoneFiringMissiles;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        SoundPlay(SOUND_BOX_DONE_FIRING_BOMB);
        return;
    }

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gSubSpriteData1.currentAnimationFrame == 0 && gSubSpriteData1.animationDurationCounter == 8)
    {
        SpriteSpawnSecondary(SSPRITE_BOX_2_MISSILE, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            yPosition - BLOCK_TO_SUB_PIXEL(2.1875f), xPosition - BLOCK_TO_SUB_PIXEL(.75f), 0);
    }
    else if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 8)
    {
        SpriteSpawnSecondary(SSPRITE_BOX_2_MISSILE, 1, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            yPosition - BLOCK_TO_SUB_PIXEL(2.25f), xPosition - BLOCK_TO_SUB_PIXEL(.375f), 0);
    }
    else if (gSubSpriteData1.currentAnimationFrame == 6 && gSubSpriteData1.animationDurationCounter == 8)
    {
        SpriteSpawnSecondary(SSPRITE_BOX_2_MISSILE, 2, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            yPosition - BLOCK_TO_SUB_PIXEL(2.25f), xPosition + BLOCK_TO_SUB_PIXEL(.375f), 0);
    }
    else if (gSubSpriteData1.currentAnimationFrame == 9 && gSubSpriteData1.animationDurationCounter == 8)
    {
        SpriteSpawnSecondary(SSPRITE_BOX_2_MISSILE, 3, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            yPosition - BLOCK_TO_SUB_PIXEL(2.1875f), xPosition + BLOCK_TO_SUB_PIXEL(.75f), 0);
    }
}

/**
 * @brief 52758 | 1c | Handles BOX 2 done firing missiles
 *
 */
void Box2DoneFiringMissiles(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = BOX_2_POSE_WAITING_TO_RUN_INIT;
}

/**
 * @brief 52774 | 38 | Initializes BOX 2 to die
 *
 */
void Box2DyingInit(void)
{
    gCurrentSprite.pOam = sBox2PartOam_Brain_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.BOX_2_Y_SPEED_IDX = 0;
    gCurrentSprite.pose = BOX_2_POSE_DYING;

    gSubSpriteData1.pMultiOam = sBox2MultiOam_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
}

/**
 * @brief 527ac | 3c | Handles BOX 2 dying
 *
 */
void Box2Dying(void)
{
    s32 blockTop;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition);
    if (gPreviousVerticalCollisionCheck != 0)
    {
        gSubSpriteData1.yPosition = blockTop;
        gCurrentSprite.pose = BOX_2_POSE_EXPLODING_INIT;
    }
    else
    {
        gSubSpriteData1.yPosition += BLOCK_TO_SUB_PIXEL(.25f);    
    }
}

/**
 * @brief 527e8 | 30 | Initializes BOX 2 to explode
 *
 */
void Box2ExplodingInit(void)
{
    gCurrentSprite.pOam = sBox2PartOam_Brain_Shaking;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_EXPLODING;

    gSubSpriteData1.pMultiOam = sBox2MultiOam_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
}

/**
 * @brief 52818 | 60 | Handles BOX 2 exploding
 *
 */
void Box2Exploding(void)
{
    u16 screenX;

    if (!(gFrameCounter8Bit & 7))
    {
        if (gCurrentSprite.paletteRow == 0)
            gCurrentSprite.paletteRow = 11;
        else
            gCurrentSprite.paletteRow = 0;
    }

    screenX = SUB_PIXEL_TO_PIXEL(gCurrentSprite.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);
    if (screenX >= 25 && screenX <= SCREEN_SIZE_X - 25 && SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = BOX_2_POSE_BRAIN_RISING_INIT;
}

/**
 * @brief 52878 | 34 | Initializes BOX 2 to have the brain rise
 *
 */
void Box2BrainRisingInit(void)
{
    gCurrentSprite.pOam = sBox2PartOam_Center_NoBrain;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_BRAIN_RISING;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.BOX_2_TIMER = 0;

    RoomEffectStartStopEventBased(EVENT_EFFECT_BOX2_ROOM);
}

/**
 * @brief 528ac | 218 | Handles BOX 2 brain rising
 *
 */
void Box2BrainRising(void)
{
    u8 slot;
    u16 xPosition;
    u16 yPosition;

    if (!(gFrameCounter8Bit & 1))
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    
    switch (gCurrentSprite.BOX_2_TIMER)
    {
        case CONVERT_SECONDS(0):
            slot = SpriteSpawnSecondary(SSPRITE_BOX_2_BRAIN_TOP, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
            gSpriteData[slot].primarySpriteRamSlot = slot;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(1.125f), xPosition, PE_0x30);
            SoundPlay_3b1c(SOUND_26E);
            break;

        case CONVERT_SECONDS(1/60.f):
            ParticleSet(yPosition, xPosition + BLOCK_TO_SUB_PIXEL(1.25f), PE_0x35);
            break;

        case CONVERT_SECONDS(2/15.f):
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(2 + 3/32.f), xPosition + BLOCK_TO_SUB_PIXEL(1.75f), PE_0x30);
            break;

        case CONVERT_SECONDS(4/15.f):
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(2 + 3/32.f), xPosition - BLOCK_TO_SUB_PIXEL(1.75f), PE_0x30);
            break;

        case CONVERT_SECONDS(.5f):
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.3125f), xPosition - BLOCK_TO_SUB_PIXEL(5/32.f), PE_0x35);
            break;

        case CONVERT_SECONDS(19/30.f):
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(1.4375f), xPosition + BLOCK_TO_SUB_PIXEL(2.25f), PE_0x2F);
            break;

        case CONVERT_SECONDS(23/30.f):
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(1.4375f), xPosition - BLOCK_TO_SUB_PIXEL(2.25f), PE_0x2F);
            break;

        case CONVERT_SECONDS(1.1f):
            gCurrentSprite.pose = BOX_2_POSE_BRAIN_FLOATING;
            gCurrentSprite.BOX_2_TIMER = CONVERT_SECONDS(1);
            gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
            return;
        
    }

    APPLY_DELTA_TIME_INC(gCurrentSprite.BOX_2_TIMER);
}

/**
 * @brief 52ac4 | 20 | Handles BOX 2 brain floating
 *
 */
void Box2BrainFloating(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.BOX_2_TIMER);
    if (gCurrentSprite.BOX_2_TIMER == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 52ae4 | 44 | Initializes BOX 2 to crawl
 *
 */
void Box2CrawlingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBox2MultiOam_Crawling_Right;
    else
        gSubSpriteData1.pMultiOam = sBox2MultiOam_Crawling_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_2_POSE_CRAWLING;
}

/**
 * @brief 52b28 | 10 | Handles BOX 2 crawling
 *
 */
void Box2Crawling(void)
{
    Box2XMovement(BOX_2_CRAWLING_X_SPEED, BOX_2_POSE_FINISHED_CRAWLING_INIT);
}

/**
 * @brief 52b38 | 28 | Sets BOX 2's jump counter
 *
 * @param primarySlot Sprite data RAM slot of BOX 2
 * @param jumps The number of jumps to set
 */
void Box2PartSetBoxJumpCounter(u8 primarySlot, u8 jumps)
{
    if (gSpriteData[primarySlot].BOX_2_JUMP_COUNTER < jumps)
        gSpriteData[primarySlot].BOX_2_JUMP_COUNTER = jumps;
}

/**
 * @brief 52b60 | e0 | Updates projectile immunity on BOX 2's center
 *
 * @param primarySlot Sprite data RAM slot of BOX 2
 */
void Box2PartCenterUpdateImmunity(u8 primarySlot)
{
    switch (gSpriteData[primarySlot].pose)
    {
        case BOX_2_POSE_LOWERING_TO_FIRE_MISSILES_INIT:
        case BOX_2_POSE_LOWERING_TO_FIRE_MISSILES:
        case BOX_2_POSE_FIRING_MISSILES:
        case BOX_2_POSE_DONE_FIRING_MISSILES:
            if (gSpriteData[primarySlot].BOX_2_PARTS_ALIVE & (BOX_2_LEFT_LEG_ALIVE | BOX_2_RIGHT_LEG_ALIVE))
                gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            else
                gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;                
            break;

        // Leftover poses from BOX 1
        case 0x3F:
        case 0x40:
        case 0x41:
        case 0x42:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            break;

        default:
            gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
            break;
    }
}

/**
 * @brief 52c40 | 14 | Removes ignore projectile status on a BOX 2 leg
 *
 * @param primarySlot Sprite data RAM slot of BOX 2 (unused)
 */
void Box2PartLegRemoveIgnoreProjectiles(u8 primarySlot)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
}

/**
 * @brief 52c54 | 1b8 | Initializes a BOX 2 part
 *
 */
void Box2PartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);

    gCurrentSprite.pose = SPRITE_POSE_IDLE;

    if (gCurrentSprite.roomSlot <= BOX_2_PART_CENTER)
        gCurrentSprite.drawOrder = 11;
    else
        gCurrentSprite.drawOrder = 13;

    switch (gCurrentSprite.roomSlot)
    {
        case BOX_2_PART_FRONT_LEFT_LEG_COVER:
        case BOX_2_PART_FRONT_RIGHT_LEG_COVER:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.125);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.125);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.5f);

            gCurrentSprite.frozenPaletteRowOffset = 2;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            Box2SyncSubSprites();

            // Offset the right leg's animation from the left leg
            if (gCurrentSprite.roomSlot == BOX_2_PART_FRONT_RIGHT_LEG_COVER)
                gCurrentSprite.currentAnimationFrame = 7;
            break;

        case BOX_2_PART_CENTER:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.75f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.5f);

            gCurrentSprite.frozenPaletteRowOffset = 1;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

            gCurrentSprite.pOam = sBox2PartOam_Center_Undamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case BOX_2_PART_LAUNCHER:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1);

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            Box2SyncSubSprites();
            break;

        case BOX_2_PART_FRONT_LEFT_LEG:
        case BOX_2_PART_FRONT_RIGHT_LEG:
        case BOX_2_PART_MIDDLE_LEFT_LEG:
        case BOX_2_PART_MIDDLE_RIGHT_LEG:
        case BOX_2_PART_BOTTOM:
        case BOX_2_PART_BACK_LEFT_LEG:
        case BOX_2_PART_BACK_RIGHT_LEG:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.0625);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625);

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            Box2SyncSubSprites();
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }
}

/**
 * @brief 52e0c | 19c | Handles BOX 2's front left leg
 *
 */
void Box2PartFrontLeftLeg(void)
{
    u8 primarySlot;
    u16 maxHealth;
    u16 yPosition;
    u16 xPosition;

    primarySlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[primarySlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }
    
    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    maxHealth = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gSpriteData[primarySlot].pose == BOX_2_POSE_EXPLODING)
    {
        gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
        ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(25/32.f), xPosition, PE_0x2F);
        return;
    }

    Box2PartLegRemoveIgnoreProjectiles(primarySlot);

    if (gCurrentSprite.properties & SP_DESTROYED)
    {
        if (gCurrentSprite.health > 0)
        {
            if (gSpriteData[primarySlot].BOX_2_PARTS_ALIVE & BOX_2_RIGHT_LEG_ALIVE)
            {
                gCurrentSprite.BOX_2_PART_TIMER++;
                if (!(gCurrentSprite.BOX_2_PART_TIMER & 0x1F))
                    ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.75f), xPosition, PE_TAIL_EXPLOSION_SMOKE);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(25/32.f), xPosition, PE_0x2F);
            }

            return;
        }
    }

    if (gCurrentSprite.health == 0)
    {
        gSpriteData[primarySlot].BOX_2_PARTS_ALIVE &= ~BOX_2_LEFT_LEG_ALIVE;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.health = UCHAR_MAX;
        gCurrentSprite.BOX_2_PART_TIMER = 0;
        ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(25/32.f), xPosition, PE_0x2F);
        Box2PartSetBoxJumpCounter(primarySlot, 1);
    }
    else if (gCurrentSprite.health < maxHealth / 4)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_FrontLeftLegCover_SeverelyDamaged)
        {
            gCurrentSprite.pOam = sBox2PartOam_FrontLeftLegCover_SeverelyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_EXPLOSION_SMOKE);
            Box2PartSetBoxJumpCounter(primarySlot, 1);
        }
    }
    else if (gCurrentSprite.health < maxHealth / 2)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_FrontLeftLegCover_ModeratelyDamaged)
        {
            gCurrentSprite.pOam = sBox2PartOam_FrontLeftLegCover_ModeratelyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_EXPLOSION_SMOKE);
            Box2PartSetBoxJumpCounter(primarySlot, 1);
        }
    }
    else if (gCurrentSprite.health < maxHealth * 3 / 4)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_FrontLeftLegCover_SlightlyDamaged)
        {
            gCurrentSprite.pOam = sBox2PartOam_FrontLeftLegCover_SlightlyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_EXPLOSION_SMOKE);
            Box2PartSetBoxJumpCounter(primarySlot, 1);
        }
    }
}

/**
 * @brief 52fa8 | 1a0 | Handles BOX 2's front right leg
 *
 */
void Box2PartFrontRightLeg(void)
{
    u8 primarySlot;
    u16 maxHealth;
    u16 yPosition;
    u16 xPosition;

    primarySlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[primarySlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }
    
    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    maxHealth = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gSpriteData[primarySlot].pose == BOX_2_POSE_EXPLODING)
    {
        gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
        ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(25/32.f), xPosition, PE_0x2F);
        return;
    }

    Box2PartLegRemoveIgnoreProjectiles(primarySlot);

    if (gCurrentSprite.properties & SP_DESTROYED)
    {
        if (gCurrentSprite.health > 0)
        {
            if (gSpriteData[primarySlot].BOX_2_PARTS_ALIVE & BOX_2_LEFT_LEG_ALIVE)
            {
                gCurrentSprite.BOX_2_PART_TIMER++;
                if (!(gCurrentSprite.BOX_2_PART_TIMER & 0x1F))
                    ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.75f), xPosition, PE_TAIL_EXPLOSION_SMOKE);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(25/32.f), xPosition, PE_0x2F);
            }

            return;
        }
    }

    if (gCurrentSprite.health == 0)
    {
        gSpriteData[primarySlot].BOX_2_PARTS_ALIVE &= ~BOX_2_RIGHT_LEG_ALIVE;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.health = UCHAR_MAX;
        gCurrentSprite.BOX_2_PART_TIMER = 0;
        ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(25/32.f), xPosition, PE_0x2F);
        Box2PartSetBoxJumpCounter(primarySlot, 1);
    }
    else if (gCurrentSprite.health < maxHealth / 4)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_FrontRightLegCover_SeverelyDamaged)
        {
            gCurrentSprite.pOam = sBox2PartOam_FrontRightLegCover_SeverelyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_EXPLOSION_SMOKE);
            Box2PartSetBoxJumpCounter(primarySlot, 1);
        }
    }
    else if (gCurrentSprite.health < maxHealth / 2)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_FrontRightLegCover_ModeratelyDamaged)
        {
            gCurrentSprite.pOam = sBox2PartOam_FrontRightLegCover_ModeratelyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_EXPLOSION_SMOKE);
            Box2PartSetBoxJumpCounter(primarySlot, 1);
        }
    }
    else if (gCurrentSprite.health < maxHealth * 3 / 4)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_FrontRightLegCover_SlightlyDamaged)
        {
            gCurrentSprite.pOam = sBox2PartOam_FrontRightLegCover_SlightlyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_EXPLOSION_SMOKE);
            Box2PartSetBoxJumpCounter(primarySlot, 1);
        }
    }
}

/**
 * @brief 53148 | 140 | Handles BOX 2's center
 *
 */
void Box2PartCenter(void)
{
    u8 primarySlot;
    u16 maxHealth;
    u16 yPosition;
    u16 xPosition;

    primarySlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[primarySlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    maxHealth = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    Box2PartCenterUpdateImmunity(primarySlot);

    if (gCurrentSprite.health == 0)
    {
        gSpriteData[primarySlot].BOX_2_PARTS_ALIVE &= ~BOX_2_CENTER_ALIVE;
        ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(25/32.f), xPosition, PE_0x2F);
        gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
        gSpriteData[primarySlot].pose = BOX_2_POSE_DYING_INIT;
    }
    else if (gCurrentSprite.health < maxHealth / 4)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_Center_SeverelyDamaged)
        {
            gCurrentSprite.pOam = sBox2PartOam_Center_SeverelyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_0x30);
        } 
    }
    else if (gCurrentSprite.health < maxHealth / 2)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_Center_ModeratelyDamaged)
        {
            gCurrentSprite.pOam = sBox2PartOam_Center_ModeratelyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_0x30);
        } 
    }
    else if (gCurrentSprite.health < maxHealth * 3 / 4)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_Center_SlightlyDamaged)
        {
            gCurrentSprite.pOam = sBox2PartOam_Center_SlightlyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_0x30);
        } 
    }
    else if (gCurrentSprite.health < maxHealth)
    {
        if (gCurrentSprite.pOam != sBox2PartOam_Center_Exposed)
        {
            gCurrentSprite.frozenPaletteRowOffset = 2;
            gCurrentSprite.pOam = sBox2PartOam_Center_Exposed;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5625f), xPosition, PE_0x30);
        }
    }

    if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) == 4)
    {
        Box2PartSetBoxJumpCounter(primarySlot, 2);
        SoundPlay(SOUND_BOX_DAMAGED);
    }
}

/**
 * @brief 53288 | c4 | Handles BOX 2's bottom
 *
 */
void Box2PartBottom(void)
{
    u8 primarySlot;

    primarySlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[primarySlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    switch (gSpriteData[primarySlot].pose)
    {
        case BOX_2_POSE_JUMP_WARNING:
        case BOX_2_POSE_FINISH_CRAWLING:
        case BOX_2_POSE_WAITING_TO_RUN:
            if (gCurrentSprite.pOam != sBox2PartOam_Bottom_OpeningAndClosing)
            {
                gCurrentSprite.pOam = sBox2PartOam_Bottom_OpeningAndClosing;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;
        
        case BOX_2_POSE_EXPLODING:
            if (gCurrentSprite.pOam != sBox2PartOam_Bottom_OpeningAndClosing)
            {
                gCurrentSprite.pOam = sBox2PartOam_Bottom_OpeningAndClosing;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }

            if (!(gFrameCounter8Bit & 7))
            {
                if (gCurrentSprite.paletteRow == 0)
                    gCurrentSprite.paletteRow = 12;
                else
                    gCurrentSprite.paletteRow = 0;
            }
            break;
        
        case BOX_2_POSE_BRAIN_RISING:
            gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
            break;
        
        default:
            if (gCurrentSprite.pOam != sBox2PartOam_Bottom_Idle)
            {
                gCurrentSprite.pOam = sBox2PartOam_Bottom_Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;
    }
}

/**
 * @brief 5334c | ac | Default handler for a BOX 2 part
 *
 */
void Box2PartDefault(void)
{
    u8 primarySlot;

    primarySlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[primarySlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    switch (gSpriteData[primarySlot].pose)
    {
        case BOX_2_POSE_EXPLODING:
            if (!(gFrameCounter8Bit & 7))
            {
                if (gCurrentSprite.paletteRow == 0)
                    gCurrentSprite.paletteRow = 13;
                else
                    gCurrentSprite.paletteRow = 0;
            }
            break;

        case BOX_2_POSE_BRAIN_RISING_INIT:
            gCurrentSprite.paletteRow = 0;
            return;

        case BOX_2_POSE_BRAIN_RISING:
            if (!(gFrameCounter8Bit & 1))
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            break;

        case BOX_2_POSE_BRAIN_FLOATING:
            gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
            break;
    }
}

/**
 * @brief 533f8 | ac | Initializes a BOX 2 missile
 *
 */
void Box2MissileInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.125f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.125f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.125f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.125f);
        
    gCurrentSprite.pOam = sBox2PartOam_Missile;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.rotation = Q_8_8(.75f);
    gCurrentSprite.scaling = Q_8_8(1);
    gCurrentSprite.BOX_2_MISSILE_Y_SPEED = BLOCK_TO_SUB_PIXEL(9/32.f) * 2;
    gCurrentSprite.BOX_2_MISSILE_DURATION = CONVERT_SECONDS(5);
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.BOX_2_MISSILE_IN_WATER = FALSE;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;

    SoundPlay(SOUND_BOX_MISSILE_LAUNCH);
}

/**
 * @brief 534a4 | 88 | Handles a BOX 2 missile launching
 *
 */
void Box2MissileLaunching(void)
{
    u8 ySpeed;

    if (gCurrentSprite.health == 0)
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;

    ySpeed = gCurrentSprite.BOX_2_MISSILE_Y_SPEED / 2;
    gCurrentSprite.yPosition -= ySpeed;
    if (ySpeed <= 2)
    {
        gCurrentSprite.rotation = SpriteUtilMakeSpriteRotateTowardsTarget(gCurrentSprite.rotation,
            gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1), gSamusData.xPosition,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    }

    gCurrentSprite.BOX_2_MISSILE_Y_SPEED -= 2;
    if (gCurrentSprite.BOX_2_MISSILE_Y_SPEED < 2)
    {
        gCurrentSprite.pose = BOX_2_MISSILE_POSE_MOVING;
        gCurrentSprite.SPRITE_X_SPEED_DEC = 0;
        gCurrentSprite.SPRITE_X_SPEED_INC = 1;
        gCurrentSprite.SPRITE_Y_SPEED_DEC = 0;
        gCurrentSprite.SPRITE_Y_SPEED_INC = 1;
    }
}

/**
 * @brief 5352c | d4 | Handles a BOX 2 missile moving
 *
 */
void Box2MissileMoving(void)
{
    u16 yOffset;
    u16 yPosition;

    gCurrentSprite.BOX_2_MISSILE_DURATION--;
    if (gCurrentSprite.BOX_2_MISSILE_DURATION == 0 || gCurrentSprite.health == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
        return;
    }

    // Each missile targets a slightly different Y position
    if (gCurrentSprite.roomSlot == 3)
        yOffset = BLOCK_TO_SUB_PIXEL(.125f);
    else if (gCurrentSprite.roomSlot == 2)
        yOffset = BLOCK_TO_SUB_PIXEL(.625f);
    else if (gCurrentSprite.roomSlot == 1)
        yOffset = BLOCK_TO_SUB_PIXEL(1.125f);
    else
        yOffset = BLOCK_TO_SUB_PIXEL(1.625f);

    yPosition = gSamusData.yPosition - yOffset;
    SpriteUtilMoveTowardsTarget(yPosition, gSamusData.xPosition,
        BLOCK_TO_SUB_PIXEL(3/32.f) * 4, BLOCK_TO_SUB_PIXEL(5/32.f) * 4, LOG2(4));

    gCurrentSprite.rotation = SpriteUtilMakeSpriteRotateTowardsTarget(gCurrentSprite.rotation,
        gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1), gSamusData.xPosition,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck != 0)
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;

    if (gCurrentAffectingClipdata.hazard == HAZARD_WATER)
    {
        if (!gCurrentSprite.BOX_2_MISSILE_IN_WATER)
        {
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x39);
            gCurrentSprite.BOX_2_MISSILE_IN_WATER = TRUE;
        }
    }
    else
    {
        if (gCurrentSprite.BOX_2_MISSILE_IN_WATER)
        {
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x39);
            gCurrentSprite.BOX_2_MISSILE_IN_WATER = FALSE;
        }
    }
}

/**
 * @brief 53600 | 24 | Handles a BOX 2 missile exploding
 *
 */
void Box2MissileExploding(void)
{
    gCurrentSprite.status = 0;
    ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x25);
    SoundPlay(SOUND_BOX_MISSILE_EXPLODE);
}

/**
 * @brief 53624 | a4 | Initializes the BOX 2 brain top
 *
 */
void Box2BrainTopInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.5f);
    
    gCurrentSprite.pOam = sBox2PartOam_Brain_Floating;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.BOX_2_BRAIN_TOP_FLOATING_TIMER = CONVERT_SECONDS(1.5f);
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    gCurrentSprite.BOX_2_BRAIN_TOP_BRAIN_BOTTOM_SLOT = SpriteSpawnSecondary(SSPRITE_BOX_2_BRAIN_BOTTOM, 0,
        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
}

/**
 * @brief 536c8 | 80 | Handles the BOX 2 brain top rising
 *
 */
void Box2BrainTopRising(void)
{
    if (!(gFrameCounter8Bit & 7))
    {
        if (gCurrentSprite.paletteRow == 0)
            gCurrentSprite.paletteRow = 11;
        else
            gCurrentSprite.paletteRow = 0;

        gSpriteData[gCurrentSprite.BOX_2_BRAIN_TOP_BRAIN_BOTTOM_SLOT].paletteRow = gCurrentSprite.paletteRow;
    }
    
    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.BOX_2_BRAIN_TOP_FLOATING_TIMER) == 0)
    {
        gCurrentSprite.pose = BOX_2_BRAIN_TOP_POSE_FLOATING;
        gCurrentSprite.BOX_2_BRAIN_TOP_FLOATING_TIMER = CONVERT_SECONDS(1);
        gCurrentSprite.BOX_2_BRAIN_TOP_Y_SPEED_IDX = 0;
    }
    else
    {
        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1/32.f);
    }
}

/**
 * @brief 53748 | b0 | Handles the BOX 2 brain top floating
 *
 */
void Box2BrainTopFloating(void)
{
    u8 index;
    s16 ySpeed;
    
    if (!(gFrameCounter8Bit & 7))
    {
        if (gCurrentSprite.paletteRow == 0)
            gCurrentSprite.paletteRow = 11;
        else
            gCurrentSprite.paletteRow = 0;

        gSpriteData[gCurrentSprite.BOX_2_BRAIN_TOP_BRAIN_BOTTOM_SLOT].paletteRow = gCurrentSprite.paletteRow;
    }
    
    index = gCurrentSprite.BOX_2_BRAIN_TOP_Y_SPEED_IDX;
    ySpeed = sBox2BrainYSpeeds[index];
    if (ySpeed == SHORT_MAX)
    {
        ySpeed = sBox2BrainYSpeeds[0];
        index = 0;
    }
    gCurrentSprite.BOX_2_BRAIN_TOP_Y_SPEED_IDX = index + 1;
    gCurrentSprite.yPosition += ySpeed;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.BOX_2_BRAIN_TOP_FLOATING_TIMER);
    if (gCurrentSprite.BOX_2_BRAIN_TOP_FLOATING_TIMER == 0)
    {
        gCurrentSprite.pose = BOX_2_BRAIN_TOP_POSE_TRANSFORMING_INIT;
        gCurrentSprite.paletteRow = 0;
        gSpriteData[gCurrentSprite.BOX_2_BRAIN_TOP_BRAIN_BOTTOM_SLOT].paletteRow = 0;
    }
}

/**
 * @brief 537f8 | 2c | Initializes the BOX 2 brain top to transform
 *
 */
void Box2BrainTopTransformingInit(void)
{
    gCurrentSprite.pose = BOX_2_BRAIN_TOP_POSE_TRANSFORMING;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC | SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.BOX_2_BRAIN_TOP_MOSAIC_TIMER = CONVERT_SECONDS(11/15.f);
    // This line is unnecessary, but included to produce matching ASM
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
}

/**
 * @brief 53824 | 78 | Handles the BOX 2 brain top transforming
 *
 */
void Box2BrainTopTransforming(void)
{
    u8 spriteId;

    spriteId = PSPRITE_WAVE_BEAM_CORE_X;
    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.BOX_2_BRAIN_TOP_MOSAIC_TIMER];
    gCurrentSprite.BOX_2_BRAIN_TOP_MOSAIC_TIMER--;

    if (gCurrentSprite.BOX_2_BRAIN_TOP_MOSAIC_TIMER < CONVERT_SECONDS(1/3.f))
    {
        SpriteLoadGfx(spriteId, 0, gCurrentSprite.BOX_2_BRAIN_TOP_MOSAIC_TIMER);

        if (gCurrentSprite.BOX_2_BRAIN_TOP_MOSAIC_TIMER == 0)
        {
            gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
            gCurrentSprite.spriteId = spriteId;
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(1.4375f);
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties &= ~SP_SECONDARY_SPRITE;
        }
    }
    else if (gCurrentSprite.BOX_2_BRAIN_TOP_MOSAIC_TIMER == CONVERT_SECONDS(1/3.f))
    {
        SpriteLoadPal(spriteId, 0, 5);
    }
}

/**
 * @brief 5389c | 80 | Initializes the BOX 2 brain bottom
 *
 */
void Box2BrainBottomInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.drawOrder = 3;
    
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625f);

    gCurrentSprite.pOam = sBox2PartOam_BrainBottom;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.samusCollision = SSC_NONE;
}

/**
 * @brief 5391c | 60 | Handles the BOX 2 brain bottom being idle
 *
 */
void Box2BrainBottomIdle(void)
{
    u8 primarySlot;

    primarySlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.yPosition = gSpriteData[primarySlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[primarySlot].xPosition;

    if (gSpriteData[primarySlot].status & SPRITE_STATUS_MOSAIC)
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;

    if (gSpriteData[primarySlot].pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
        gCurrentSprite.status = 0;
}

/**
 * @brief 5397c | 220 | BOX 2 AI
 *
 */
void Box2(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            Box2Init();
            break;
        
        case BOX_2_POSE_CRAWLING_INIT:
            Box2CrawlingInit();
        
        case BOX_2_POSE_CRAWLING:
            Box2Crawling();
            break;
        
        case BOX_2_POSE_WAITING_TO_RUN_INIT:
            Box2WaitingToRunInit();
        
        case BOX_2_POSE_WAITING_TO_RUN:
            Box2WaitingToRun();
            break;
        
        case BOX_2_POSE_SLOW_RUNNING_INIT:
            Box2SlowRunningInit();
        
        case BOX_2_POSE_SLOW_RUNNING:
            Box2SlowRunning();
            break;
        
        case BOX_2_POSE_FAST_RUNNING_INIT:
            Box2FastRunningInit();
        
        case BOX_2_POSE_FAST_RUNNING:
            Box2FastRunning();
            break;
        
        case BOX_2_POSE_SKIDDING_INIT:
            Box2SkiddingInit();
        
        case BOX_2_POSE_SKIDDING:
            Box2Skidding();
            break;
        
        case BOX_2_POSE_STOP_SKIDDING_INIT:
            Box2StopSkiddingInit();
        
        case BOX_2_POSE_STOP_SKIDDING:
            Box2StopSkidding();
            break;
        
        case BOX_2_POSE_FINISHED_CRAWLING_INIT:
            Box2FinishedCrawlingInit();
        
        case BOX_2_POSE_FINISH_CRAWLING:
            Box2FinishCrawling();
            break;
        
        case BOX_2_POSE_BONKING_INIT:
            Box2BonkingInit();
        
        case BOX_2_POSE_BONKING:
            Box2Bonking();
            break;
        
        case BOX_2_POSE_LANDING_FROM_BONK_INIT:
            Box2LandingFromBonkInit();
        
        case BOX_2_POSE_LANDING_FROM_BONK:
            Box2LandingFromBonk();
            break;
        
        case BOX_2_POSE_LANDING_INIT:
            Box2LandingInit();
        
        case BOX_2_POSE_LANDING:
            Box2Landing();
            break;
        
        case BOX_2_POSE_JUMP_WARNING_INIT:
            Box2JumpWarningInit();
        
        case BOX_2_POSE_JUMP_WARNING:
            Box2JumpWarning();
            break;
        
        case BOX_2_POSE_JUMPING_INIT:
            Box2JumpingInit();
        
        case BOX_2_POSE_JUMPING:
            Box2Jumping();
            break;
        
        case BOX_2_POSE_STOPPING_TO_FIRE_MISSILES_INIT:
            Box2StoppingToFireMissilesInit();
        
        case BOX_2_POSE_STOPPING_TO_FIRE_MISSILES:
            Box2StoppingToFireMissiles();
            break;
        
        case BOX_2_POSE_LOWERING_TO_FIRE_MISSILES_INIT:
            Box2LoweringToFireMissilesInit();
        
        case BOX_2_POSE_LOWERING_TO_FIRE_MISSILES:
            Box2LoweringToFireMissiles();
            break;
        
        case BOX_2_POSE_FIRING_MISSILES:
            Box2FiringMissiles();
            break;
        
        case BOX_2_POSE_DONE_FIRING_MISSILES:
            Box2DoneFiringMissiles();
            break;
        
        case BOX_2_POSE_DYING_INIT:
            Box2DyingInit();
        
        case BOX_2_POSE_DYING:
            Box2Dying();
            break;
        
        case BOX_2_POSE_EXPLODING_INIT:
            Box2ExplodingInit();
        
        case BOX_2_POSE_EXPLODING:
            Box2Exploding();
            break;
        
        case BOX_2_POSE_BRAIN_RISING_INIT:
            Box2BrainRisingInit();
        
        case BOX_2_POSE_BRAIN_RISING:
            Box2BrainRising();
            break;
        
        case BOX_2_POSE_BRAIN_FLOATING:
            Box2BrainFloating();
            break;
    }

    SpriteUtilUpdateSubSpriteData1Animation();
    SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
}

/**
 * @brief 53b9c | f0 | BOX 2 part AI
 *
 */
void Box2Part(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        Box2PartInit();
        return;
    }

    switch (gCurrentSprite.roomSlot)
    {
        case BOX_2_PART_FRONT_LEFT_LEG_COVER:
            if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) < (gSubSpriteData1.BOX_2_FLASH_TIMER & 0x7F))
                gCurrentSprite.invincibilityStunFlashTimer = gSubSpriteData1.BOX_2_FLASH_TIMER;

            Box2PartFrontLeftLeg();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case BOX_2_PART_FRONT_RIGHT_LEG_COVER:
            if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) < (gSubSpriteData1.BOX_2_FLASH_TIMER & 0x7F))
                gCurrentSprite.invincibilityStunFlashTimer = gSubSpriteData1.BOX_2_FLASH_TIMER;

            Box2PartFrontRightLeg();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case BOX_2_PART_CENTER:
            gSubSpriteData1.BOX_2_FLASH_TIMER = gCurrentSprite.invincibilityStunFlashTimer;
            Box2PartCenter();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case BOX_2_PART_BOTTOM:
            if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) < (gSubSpriteData1.BOX_2_FLASH_TIMER & 0x7F))
                gCurrentSprite.invincibilityStunFlashTimer = gSubSpriteData1.BOX_2_FLASH_TIMER;

            Box2PartBottom();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        default:
            if ((gCurrentSprite.invincibilityStunFlashTimer & 0x7F) < (gSubSpriteData1.BOX_2_FLASH_TIMER & 0x7F))
                gCurrentSprite.invincibilityStunFlashTimer = gSubSpriteData1.BOX_2_FLASH_TIMER;

            Box2PartDefault();
            Box2SyncSubSprites();
            break;
    }
}

/**
 * @brief 53c8c | 40 | BOX 2 missile AI
 *
 */
void Box2Missile(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            Box2MissileInit();
            break;

        case SPRITE_POSE_IDLE:
            Box2MissileLaunching();
            break;

        case BOX_2_MISSILE_POSE_MOVING:
            Box2MissileMoving();
            break;
        
        case SPRITE_POSE_STOPPED:
            Box2MissileExploding();
            break;
    }
}

/**
 * @brief 53ccc | 48 | BOX 2 brain top AI
 *
 */
void Box2BrainTop(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            Box2BrainTopInit();
            break;

        case SPRITE_POSE_IDLE:
            Box2BrainTopRising();
            break;

        case BOX_2_BRAIN_TOP_POSE_FLOATING:
            Box2BrainTopFloating();
            break;

        case BOX_2_BRAIN_TOP_POSE_TRANSFORMING_INIT:
            Box2BrainTopTransformingInit();

        case BOX_2_BRAIN_TOP_POSE_TRANSFORMING:
            Box2BrainTopTransforming();
            break;
    }
}

/**
 * @brief 53d14 | 24 | BOX 2 brain bottom AI
 *
 */
void Box2BrainBottom(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
        Box2BrainBottomInit();

    Box2BrainBottomIdle();
}
