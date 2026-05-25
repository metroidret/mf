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

void Box2StopSkidding(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
        gCurrentSprite.work2 = 3;
    }
    else
    {
        if (gCurrentSprite.work2 != 0)
            gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
    }
}

void Box2BonkingInit(void)
{
    gSubSpriteData1.yPosition -= BLOCK_TO_SUB_PIXEL(0.25f);
    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_Bonking;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX2_POSE_BONKING;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

    SoundPlay(SOUND_BOX_BONK);

    ScreenShakeStartHorizontal(20, 0x81);
}

void Box2Bonking(void)
{
    u32 blockTop;
    u8 offset;
    s16 movement;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition);
    if (gPreviousVerticalCollisionCheck != 0)
    {
        gSubSpriteData1.yPosition = blockTop;
        gCurrentSprite.pose = BOX2_POSE_LANDING_FROM_BONK_INIT;
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sBox2BonkingSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = sBox2BonkingSpeed[offset - 1];
            gSubSpriteData1.yPosition += movement;
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
            gSubSpriteData1.yPosition += movement;
            if (offset == 0x10)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.8125f),
                        gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.0f), PE_SPRITE_ENTER_OR_EXIT_WATER);
                    ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.8125f),
                        gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(2.0f), PE_SPRITE_ENTER_OR_EXIT_WATER);
                }
                else
                {
                    ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.8125f),
                        gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(2.0f), PE_SPRITE_ENTER_OR_EXIT_WATER);
                    ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.8125f),
                        gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.0f), PE_SPRITE_ENTER_OR_EXIT_WATER);
                }
            }
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gSubSpriteData1.xPosition += BLOCK_TO_SUB_PIXEL(0.09375f);
        else
            gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(0.09375f);
    }
}

void Box2LandingFromBonkInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_Landing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX2_POSE_LANDING_FROM_BONK;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work4 = 0;

    SoundPlay(SOUND_27A);
}

void Box2LandingFromBonk(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (gCurrentSprite.xPosition > gSamusData.xPosition)
                gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
            else
                gCurrentSprite.pose = BOX2_POSE_WAITING_TO_RUN_INIT;
        }
        else
        {
            if (gCurrentSprite.xPosition < gSamusData.xPosition)
                gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
            else
                gCurrentSprite.pose = BOX2_POSE_WAITING_TO_RUN_INIT;
        }
    }
}

void Box2LandingInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_Landing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX2_POSE_LANDING;
    gCurrentSprite.work4 = 0;

    SoundPlay(SOUND_27A);
}

void Box2Landing(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gCurrentSprite.work2 == 0)
        {
            gCurrentSprite.pose = BOX2_POSE_STOPPING_TO_FIRE_MISSILES_INIT;
        }
        else
        {
            gCurrentSprite.work2--;
            if ((gCurrentSprite.work2 & 0x7f) == 0)
                gCurrentSprite.work2 = 0;

            gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
        }
    }
}

void Box2FinishedCrawlingInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_FinishedCrawling;
    gCurrentSprite.work1 = 2;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX2_POSE_FINISH_CRAWLING;

    SoundPlay(SOUND_BOX_FINISH_CRAWLING);
}

void Box2FinishCrawling(void)
{
    if (gCurrentSprite.work1 > 1)
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
            gCurrentSprite.work1--;
    }
    else if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (SpriteUtilCheckSamusOnCeilingLadder())
            gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
        else if (gCurrentSprite.work2 != 0)
            gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING_INIT;
        else
            gCurrentSprite.pose = BOX2_POSE_SLOW_RUNNING_INIT;
    }
}

void Box2JumpWarningInit(void)
{
    u16 samusX;

    samusX = gSamusData.xPosition;
    if (gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.875f) < samusX &&
        gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.875f) > samusX)
    {
        Box2StoppingToFireMissilesInit();
    }
    else
    {
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_JumpWarning;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = BOX2_POSE_JUMP_WARNING;
    }
}

void Box2JumpWarning(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = BOX2_POSE_JUMPING_INIT;
}

void Box2JumpingInit(void)
{
    u8 colliding = 0;

    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_Bonking;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX2_POSE_JUMPING;
    gCurrentSprite.work4 = 0;

    if (!(gCurrentSprite.work2 & 0x80))
    {
        if (SpriteUtilCheckSamusOnCeilingLadder())
            SpriteUtilMakeSpriteFaceSamusDirection();
        else
            SpriteUtilMakeSpriteFaceAwayFromSamusDirection();

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(5.46875f));
            if (gPreviousCollisionCheck != 0)
                colliding++;

            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.875f));
            if (gPreviousCollisionCheck != 0)
                colliding++;

            if (colliding != 0)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work2 = 0x82;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(5.46875f));
            if (gPreviousCollisionCheck != 0)
                colliding++;

            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.875f));
            if (gPreviousCollisionCheck != 0)
                colliding++;

            if (colliding != 0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work2 = 0x82;
            }
        }
    }

    SoundPlay(SOUND_BOX_JUMP);
}

void Box2Jumping(void)
{
    u8 offset;
    s16 movement;

    offset = gCurrentSprite.work4;
    movement = sBox2JumpingSpeed[offset];
    if (movement == SHORT_MAX)
    {
        gCurrentSprite.pose = BOX2_POSE_LANDING_INIT;
    }
    else
    {
        offset++;
        gCurrentSprite.work4 = offset;
        gSubSpriteData1.yPosition += movement;
        if (offset == 0x17)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
                    gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.0f), PE_SPRITE_ENTER_OR_EXIT_WATER);
                ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
                    gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(2.0f), PE_SPRITE_ENTER_OR_EXIT_WATER);
            }
            else
            {
                ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
                    gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(2.0f), PE_SPRITE_ENTER_OR_EXIT_WATER);
                ParticleSet(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
                    gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.0f), PE_SPRITE_ENTER_OR_EXIT_WATER);
            }
        }
        Box2XMovement(0xc, BOX2_POSE_BONKING_INIT);
    }
}

void Box2StoppingToFireMissilesInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_FinishedCrawling;
    gCurrentSprite.work1 = 3;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX2_POSE_STOPPING_TO_FIRE_MISSILES;

    SoundPlay(SOUND_BOX_FINISH_CRAWLING);
}

void Box2StoppingToFireMissiles(void)
{
    if (gCurrentSprite.work1 > 1)
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
            gCurrentSprite.work1--;
    }
    else if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        gCurrentSprite.pose = BOX2_POSE_LOWERING_TO_FIRE_MISSILES_INIT;
    }
}

void Box2LoweringToFireMissilesInit(void)
{
    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_LoweringToFireMissiles;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX2_POSE_LOWERING_TO_FIRE_MISSILES;

    SoundPlay(SOUND_BOX_LOWER_TO_FIRE_BOMB);
}

void Box2LoweringToFireMissiles(void)
{
    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gCurrentSprite.pose = BOX2_POSE_FIRING_MISSILES;
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_FiringMissiles;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
    }
}

void Box2FiringMissiles(void)
{
    u32 ended;
    u16 y;
    u16 x;
    u32 packed;
    u32 *p;

    ended = SpriteUtilHasSubSprite1AnimationEnded();
    if (ended)
    {
        gCurrentSprite.pose = BOX2_POSE_DONE_FIRING_MISSILES;
        gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_DoneFiringMissiles;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        SoundPlay(SOUND_BOX_DONE_FIRING_BOMB);
        return;
    }

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;
    p = (u32*)&gSubSpriteData1;
    packed = p[1] & 0x00FFFFFF;

    if (packed == 0x00080000)
    {
        SpriteSpawnSecondary(SSPRITE_BOX_2_MISSILE, 0, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, y - 0x8c, x - 0x30, ended);
    }
    else if (packed == 0x00080003)
    {
        SpriteSpawnSecondary(SSPRITE_BOX_2_MISSILE, 1, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, y - 0x90, x - 0x18, ended);
    }
    else if (packed == 0x00080006)
    {
        SpriteSpawnSecondary(SSPRITE_BOX_2_MISSILE, 2, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, y - 0x90, x + 0x18, ended);
    }
    else if (packed == 0x00080009)
    {
        SpriteSpawnSecondary(SSPRITE_BOX_2_MISSILE, 3, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, y - 0x8c, x + 0x30, ended);
    }
}

void Box2DoneFiringMissiles(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = BOX2_POSE_WAITING_TO_RUN_INIT;
}

void Box2DyingInit(void)
{
    gCurrentSprite.pOam = sBox2Oam_BrainIdle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.pose = BOX2_POSE_DYING;

    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
}

void Box2Dying(void)
{
    u32 blockTop;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition);
    if (gPreviousVerticalCollisionCheck != 0)
    {
        gSubSpriteData1.yPosition = blockTop;
        gCurrentSprite.pose = BOX2_POSE_EXPLODING_INIT;
    }
    else
    {
        gSubSpriteData1.yPosition += BLOCK_TO_SUB_PIXEL(0.25f);
    }
}

void Box2ExplodingInit(void)
{
    gCurrentSprite.pOam = sBox2Oam_BrainExploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX2_POSE_EXPLODING;

    gSubSpriteData1.pMultiOam = sBox2MultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
}

void Box2Exploding(void)
{
    u16 onscreenX;

    if ((gFrameCounter8Bit & 7) == 0)
    {
        if (gCurrentSprite.paletteRow == 0)
            gCurrentSprite.paletteRow = 0xb;
        else
            gCurrentSprite.paletteRow = 0;
    }

    onscreenX = (gCurrentSprite.xPosition >> 2) - (gBg1XPosition >> 2);
    if ((u16)(onscreenX - 0x19) <= 0xBE)
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
            gCurrentSprite.pose = BOX2_POSE_BRAIN_RISING_INIT;
    }
}

void Box2BrainRisingInit(void)
{
    gCurrentSprite.pOam = sBox2Oam_BrainRising;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX2_POSE_BRAIN_RISING;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.work1 = 0;

    RoomEffectStartStopEventBased(3);
}
