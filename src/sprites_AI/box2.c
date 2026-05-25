#include "sprites_AI/box2.h"

#include "globals.h"
#include "macros.h"
#include "x_parasite_util.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/box.h"
#include "data/sprites/box2.h"
#include "data/sprites/shake_trigger.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/samus.h"
#include "structs/sprite.h"

/**
 * @brief 519ac | 68 | Syncs the sub-sprite copy with the master sprite for Box2
 *
 */
void Box2SyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;

    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];

    if (gCurrentSprite.pOam != sBox2FrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sBox2FrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition =
        gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition =
        gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

u8 Box2XMovement(u16 movement, u8 collidedPose)
{
    u8 collided;

    collided = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
            gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.71875f));
        if (gPreviousCollisionCheck != 0)
        {
            gCurrentSprite.pose = collidedPose;
            collided = TRUE;
        }
        else
        {
            gSubSpriteData1.xPosition += movement;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
            gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.71875f));
        if (gPreviousCollisionCheck != 0)
        {
            gCurrentSprite.pose = collidedPose;
            collided = TRUE;
        }
        else
        {
            gSubSpriteData1.xPosition -= movement;
        }
    }

    return collided;
}

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
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.work0 = 7;
    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.frozenPaletteRowOffset = 2;
    gCurrentSprite.roomSlot = BOX2_PART_BRAIN;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.pOam = sBox2Oam_BrainIdle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gSubSpriteData1.work0 = 0;

    gCurrentSprite.work2 = 0;
    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.pose = BOX2_POSE_WAITING_TO_RUN_INIT;

    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_FRONT_LEFT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_DEFAULT_1, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_FRONT_RIGHT_LEG, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_DEFAULT_3, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_DEFAULT_4, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_DEFAULT_5, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_TOP_SHELL, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_BOTTOM_SHELL, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_DEFAULT_9, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_DEFAULT_10, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_BOX_2_PART, BOX2_PART_DEFAULT_11, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);

    SpriteSpawnPrimary(PSPRITE_ELECTRIC_WATER_DAMAGE_BOX_2, gCurrentSprite.roomSlot, 7, 0x10,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
}

void Box2WaitingToRunInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_WaitingToRun;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX2_POSE_WAITING_TO_RUN;
    gCurrentSprite.work1 = 0;

    SoundPlay(SOUND_BOX_WAIT_TO_RUN);
}

void Box2WaitingToRun(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded() && ++gCurrentSprite.work1 == 1)
        gCurrentSprite.pose = BOX2_POSE_SLOW_RUNNING_INIT;

    if (gCurrentSprite.work2 != 0)
        gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
}

void Box2SlowRunningInit(void)
{
    SpriteUtilMakeSpriteFaceSamusDirection();

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_SlowRunning_Right;
    else
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_SlowRunning_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX2_POSE_SLOW_RUNNING;
    gCurrentSprite.work1 = 0;
}

void Box2SlowRunning(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_279);
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.625f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.875f), PE_SPRITE_ENTER_OR_EXIT_WATER);
        else
            ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.625f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.875f), PE_SPRITE_ENTER_OR_EXIT_WATER);
    }

    if (!Box2XMovement(gCurrentSprite.work1, BOX2_POSE_BONKING_INIT))
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded() && ++gCurrentSprite.work1 == 7)
            gCurrentSprite.pose = BOX2_POSE_FAST_RUNNING_INIT;

        if (gCurrentSprite.work2 != 0)
            gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
    }
}

void Box2FastRunningInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_FastRunning_Right;
    else
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_FastRunning_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX2_POSE_FAST_RUNNING;
    gCurrentSprite.work1 = 10;
}

void Box2FastRunning(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_279);
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            ParticleSet(gSubSpriteData1.yPosition - 0x3c,
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(2.5f), PE_SPRITE_ENTER_OR_EXIT_WATER);
        else
            ParticleSet(gSubSpriteData1.yPosition - 0x3c,
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(2.5f), PE_SPRITE_ENTER_OR_EXIT_WATER);
    }

    if (!Box2XMovement(8, BOX2_POSE_BONKING_INIT))
    {
        if (gCurrentSprite.work1 != 0)
        {
            gCurrentSprite.work1--;
            return;
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(3.125f) > gSamusData.xPosition)
                    gCurrentSprite.pose = BOX2_POSE_SKIDDING_INIT;
            }
            else
            {
                if (gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(3.125f) < gSamusData.xPosition)
                    gCurrentSprite.pose = BOX2_POSE_SKIDDING_INIT;
            }
        }
    }

    if (gCurrentSprite.work2 != 0)
        gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
}

void Box2SkiddingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_Skidding_Right;
    else
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_Skidding_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX2_POSE_SKIDDING;
    gCurrentSprite.work1 = 0x20;

    SoundPlay(SOUND_BOX_SKID);
}

void Box2Skidding(void)
{
    u8 collidedPose;

    if (gCurrentSprite.work1 / 4 > 5)
        collidedPose = BOX2_POSE_BONKING_INIT;
    else
        collidedPose = BOX2_POSE_STOP_SKIDDING_INIT;

    if (!Box2XMovement(gCurrentSprite.work1 / 4, collidedPose))
    {
        if (--gCurrentSprite.work1 == 0)
            gCurrentSprite.pose = BOX2_POSE_STOP_SKIDDING_INIT;

        if (gCurrentSprite.work2 != 0)
            gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
    }
}

void Box2StopSkiddingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_StopSkidding_Right;
    else
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_StopSkidding_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX2_POSE_STOP_SKIDDING;
}
