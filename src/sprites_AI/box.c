#include "sprites_AI/box.h"

#include "globals.h"
#include "macros.h"

#include "data/sprites/box.h"
#include "data/frame_data_pointers.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/particle.h"

#include "structs/clipdata.h"
#include "structs/samus.h"

#define BOX_BRAIN_DRAW_ORDER 12

enum BoxPose {
    BOX_POSE_CRAWLING_INIT = 1,
    BOX_POSE_CRAWLING = 2,
    BOX_POSE_WAITING_TO_RUN_INIT = 0x17,
    BOX_POSE_WAITING_TO_RUN = 0x18,
    BOX_POSE_SLOW_RUN_INIT = 0x19,
    BOX_POSE_SLOW_RUN = 0x1a,
    BOX_POSE_FAST_RUN_INIT = 0x1b,
    BOX_POSE_FAST_RUN = 0x1c,
    BOX_POSE_SKIDDING_INIT = 0x1d,
    BOX_POSE_SKIDDING = 0x1e,
    BOX_POSE_STOP_SKIDDING_INIT = 0x1f,
    BOX_POSE_STOP_SKIDDING = 0x20,
    BOX_POSE_FINISHED_CRAWLING_INIT = 7,
    BOX_POSE_FINISHED_CRAWLING = 8,
    BOX_POSE_BONKING_INIT = 0x37,
    BOX_POSE_BONKING = 0x38,
    BOX_POSE_LANDING_FROM_BONK_INIT = 0x4b,
    BOX_POSE_LANDING_FROM_BONK = 0x4c,
    BOX_POSE_LANDING_INIT = 0x39,
    BOX_POSE_LANDING = 0x3a,
    BOX_POSE_JUMP_WARNING_INIT = 0x3b,
    BOX_POSE_JUMP_WARNING = 0x3c,
    BOX_POSE_JUMPING_INIT = 0x3d,
    BOX_POSE_JUMPING = 0x3e,
    BOX_POSE_STOPPING_TO_FIRE_BOMB_INIT = 0x27,
    BOX_POSE_STOPPING_TO_FIRE_BOMB = 0x28,
    BOX_POSE_LOWERING_TO_FIRE_BOMB_INIT = 0x29,
    BOX_POSE_LOWERING_TO_FIRE_BOMB = 0x2a,
    BOX_POSE_FIRING_BOMB = 0x2c,
    BOX_POSE_DONE_FIRING_BOMB = 0x2e,
    BOX_POSE_WAITING_TO_EMERGE_INIT = 0x3f,
    BOX_POSE_WAITING_TO_EMERGE = 0x40,
    BOX_POSE_FIRST_JUMP_INIT = 0x41,
    BOX_POSE_FIRST_JUMP = 0x42,
    BOX_POSE_DEFEATED_INIT = 0x43,
    BOX_POSE_DEFEATED = 0x44,
    BOX_POSE_MOVING_TO_FINAL_JUMP_INIT = 0x45,
    BOX_POSE_MOVING_TO_FINAL_JUMP = 0x46,
    BOX_POSE_WAITING_FOR_FINAL_JUMP_INIT = 0x47,
    BOX_POSE_WAITING_FOR_FINAL_JUMP = 0x48,
    BOX_POSE_CROUCHING_FOR_FINAL_JUMP_INIT = 0x49,
    BOX_POSE_CROUCHING_FOR_FINAL_JUMP = 0x4a,
    BOX_POSE_FINAL_JUMP_INIT = 0x4d,
    BOX_POSE_FINAL_JUMP = 0x4e,
};

void SpriteUtilUpdateSubSpriteData1Animation(void)
{
    gSubSpriteData1.animationDurationCounter++;
    if (gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].timer <
        gSubSpriteData1.animationDurationCounter)
    {
        gSubSpriteData1.animationDurationCounter = 1;
        gSubSpriteData1.currentAnimationFrame++;
        if (gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].timer == 0)
            gSubSpriteData1.currentAnimationFrame = 0;
    }
}

void SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position(void)
{
    MultiSpriteDataInfo_T pData;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    gCurrentSprite.yPosition =
        gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition =
        gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

void BoxSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;

    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];

    if (gCurrentSprite.pOam != sBoxFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sBoxFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition =
        gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition =
        gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

u8 BoxXMovement(u16 movement, u8 collidedPose)
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

void BoxInit(void)
{
    if (!EventCheckOn_BoxRumble())
    {
        gCurrentSprite.status = 0;
    }
    else
    {
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
        gCurrentSprite.drawOrder = BOX_BRAIN_DRAW_ORDER;
        gCurrentSprite.frozenPaletteRowOffset = 2;
        gCurrentSprite.roomSlot = BOX_PART_BRAIN;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.pOam = sBoxPartOam_BrainIdle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gSubSpriteData1.work0 = 0;

        gCurrentSprite.work2 = 0;
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.pose = BOX_POSE_WAITING_TO_EMERGE_INIT;

        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_FRONT_LEFT_LEG_COVER, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_FRONT_LEFT_LEG, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_FRONT_RIGHT_LEG_COVER, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_FRONT_RIGHT_LEG, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_MIDDLE_LEFT_LEG, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_MIDDLE_RIGHT_LEG, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_CENTER, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_CENTER_BOTTOM, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_LAUNCHER, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_BACK_LEFT_LEG, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_BOX_PART, BOX_PART_BACK_RIGHT_LEG, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    }
}

void BoxWaitingToEmergeInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_FinishedCrawling;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gSubSpriteData1.xPosition += BLOCK_TO_SUB_PIXEL(4.0f);

    gCurrentSprite.pose = BOX_POSE_WAITING_TO_EMERGE;
    gCurrentSprite.work1 = 0;

    SoundPlay_3b1c(SOUND_BOX_WAITING_TO_EMERGE);

    ScreenShakeStartHorizontal(40, 0x81);

    gCurrentSprite.work4 = 0;
}

void BoxWaitingToEmerge(void)
{
    u16 y;
    u16 x;

    if (++gCurrentSprite.work4 > 60)
    {
        SoundPlay_3b1c(SOUND_BOX_WAITING_TO_EMERGE);
        ScreenShakeStartHorizontal(40, 0x81);
        gCurrentSprite.work4 = 0;
    }

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    switch (gCurrentSprite.work1)
    {
        case 0:
            ParticleSet(y, x, PE_TAIL_EXPLOSION_SMOKE);
            break;

        case 4:
            ParticleSet(y, x, PE_0x2F);
            break;

        case 8:
            ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.4375f), x + BLOCK_TO_SUB_PIXEL(0.4375f), PE_TAIL_EXPLOSION_SMOKE);
            break;

        case 16:
            ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.5f), x - BLOCK_TO_SUB_PIXEL(0.5f), PE_0x2F);
            break;

        case 20:
            ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.4375f), x - BLOCK_TO_SUB_PIXEL(0.71875f), PE_TAIL_EXPLOSION_SMOKE);
            break;

        case 24:
            ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(1.0f), PE_0x2F);
            break;

        case 28:
            ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.375f), x, PE_0x2F);
            break;

        case 32:
            ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.40625f), x + BLOCK_TO_SUB_PIXEL(0.25f), PE_0x2F);
            break;

        case 36:
            gCurrentSprite.work1 = UCHAR_MAX;
    }

    gCurrentSprite.work1++;

    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(8.0f), BLOCK_TO_SUB_PIXEL(8.0f)) == NSLR_LEFT)
    {
        gCurrentSprite.pose = BOX_POSE_FIRST_JUMP_INIT;
        ParticleSet(y, x - BLOCK_TO_SUB_PIXEL(2.5f), PE_0x2F);
        PlayMusic(MUSIC_BOX_BATTLE, 7);
    }
}

void BoxFirstJumpInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Jumping;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_FIRST_JUMP;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;

    SoundPlay(SOUND_BOX_JUMP);
}

void BoxFirstJump(void)
{
    u8 offset;
    s16 movement;

    offset = gCurrentSprite.work4;
    movement = sBoxFirstJumpSpeed[gCurrentSprite.work4];

    if (movement == SHORT_MAX)
    {
        gCurrentSprite.pose = BOX_POSE_SLOW_RUN_INIT;
        ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(2.8125f), PE_0x35);
        SoundPlay(SOUND_BOX_LAND);
        ScreenShakeStartVertical(60, 0x81);
    }
    else
    {
        offset++;
        gCurrentSprite.work4 = offset;
        gSubSpriteData1.yPosition += movement;
        gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(0.15625f);
    }
}

void BoxWaitingToRunInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_WaitingToRun;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_WAITING_TO_RUN;
    gCurrentSprite.work1 = 0;

    SoundPlay(SOUND_BOX_WAIT_TO_RUN);
}

void BoxWaitingToRun(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded() && ++gCurrentSprite.work1 == 1)
        gCurrentSprite.pose = BOX_POSE_SLOW_RUN_INIT;

    if (gCurrentSprite.work2 != 0)
        gCurrentSprite.pose = BOX_POSE_JUMP_WARNING_INIT;
}

void BoxSlowRunningInit(void)
{
    SpriteUtilMakeSpriteFaceSamusDirection();

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_SlowRun_Right;
    else
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_SlowRun_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_SLOW_RUN;
    gCurrentSprite.work1 = 0;
}

void BoxSlowRun(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 1)
        SoundPlay(SOUND_BOX_FOOTSTEP);

    if (!BoxXMovement(gCurrentSprite.work1, BOX_POSE_BONKING_INIT))
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded() && ++gCurrentSprite.work1 == 7)
            gCurrentSprite.pose = BOX_POSE_FAST_RUN_INIT;

        if (gCurrentSprite.work2 != 0)
            gCurrentSprite.pose = BOX_POSE_JUMP_WARNING_INIT;
    }
}

void BoxFastRunInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_FastRun_Right;
    else
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_FastRun_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_POSE_FAST_RUN;
    gCurrentSprite.work1 = 10;
}

void BoxFastRun(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 1)
        SoundPlay(SOUND_BOX_FOOTSTEP);

    if (!BoxXMovement(8, BOX_POSE_BONKING_INIT))
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
                    gCurrentSprite.pose = BOX_POSE_SKIDDING_INIT;
            }
            else
            {
                if (gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(3.125f) < gSamusData.xPosition)
                    gCurrentSprite.pose = BOX_POSE_SKIDDING_INIT;
            }
        }
    }

    if (gCurrentSprite.work2 != 0)
        gCurrentSprite.pose = BOX_POSE_JUMP_WARNING_INIT;
}

void BoxSkiddingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Skidding_Right;
    else
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Skidding_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_POSE_SKIDDING;
    gCurrentSprite.work1 = 0x20;

    SoundPlay(SOUND_BOX_SKID);
}

void BoxSkidding(void)
{
    u8 collidedPose;

    if (gCurrentSprite.work1 / 4 > 5)
        collidedPose = BOX_POSE_BONKING_INIT;
    else
        collidedPose = BOX_POSE_STOP_SKIDDING_INIT;

    if (!BoxXMovement(gCurrentSprite.work1 / 4, collidedPose))
    {
        if (--gCurrentSprite.work1 == 0)
            gCurrentSprite.pose = BOX_POSE_STOP_SKIDDING_INIT;

        if (gCurrentSprite.work2 != 0)
            gCurrentSprite.pose = BOX_POSE_JUMP_WARNING_INIT;
    }
}

void BoxStopSkiddingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_StopSkidding_Right;
    else
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_StopSkidding_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_POSE_STOP_SKIDDING;
}

void BoxStopSkidding(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        gCurrentSprite.pose = BOX_POSE_JUMP_WARNING_INIT;
        gCurrentSprite.work2 = 3;
    }
    else
    {
        if (gCurrentSprite.work2 != 0)
            gCurrentSprite.pose = BOX_POSE_JUMP_WARNING_INIT;
    }
}

void BoxBonkingInit(void)
{
    gSubSpriteData1.yPosition -= BLOCK_TO_SUB_PIXEL(0.25f);
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Jumping;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_POSE_BONKING;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

    SoundPlay(SOUND_BOX_BONK);

    ScreenShakeStartHorizontal(20, 0x81);
}

void BoxBonking(void)
{
    u32 blockTop;
    u8 offset;
    s16 movement;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition);
    if (gPreviousVerticalCollisionCheck != 0)
    {
        gSubSpriteData1.yPosition = blockTop;
        gCurrentSprite.pose = BOX_POSE_LANDING_FROM_BONK_INIT;
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sBoxBonkingSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = sBoxBonkingSpeed[offset - 1];
            gSubSpriteData1.yPosition += movement;
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
            gSubSpriteData1.yPosition += movement;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gSubSpriteData1.xPosition += BLOCK_TO_SUB_PIXEL(0.09375f);
        else
            gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(0.09375f);
    }
}

void BoxLandingFromBonkInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Landing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_POSE_LANDING_FROM_BONK;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work4 = 0;

    SoundPlay(SOUND_BOX_LAND);
}

void BoxLandingFromBonk(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = BOX_POSE_WAITING_TO_RUN_INIT;
}

void BoxLandingInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Landing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_POSE_LANDING;
    gCurrentSprite.work4 = 0;

    SoundPlay(SOUND_BOX_LAND);
}

void BoxLanding(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gCurrentSprite.work2 == 0)
        {
            gCurrentSprite.pose = BOX_POSE_STOPPING_TO_FIRE_BOMB_INIT;
        }
        else
        {
            gCurrentSprite.work2--;
            if ((gCurrentSprite.work2 & 0x7f) == 0)
                gCurrentSprite.work2 = 0;

            gCurrentSprite.pose = BOX_POSE_JUMP_WARNING_INIT;
        }
    }
}

void BoxFinishedCrawlingInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_FinishedCrawling;
    gCurrentSprite.work1 = 2;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_FINISHED_CRAWLING;

    SoundPlay(SOUND_BOX_FINISH_CRAWLING);
}

void BoxFinishedCrawling(void)
{
    if (gCurrentSprite.work1 > 1)
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
            gCurrentSprite.work1--;
    }
    else
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        {
            if (SpriteUtilCheckSamusOnCeilingLadder())
            {
                gCurrentSprite.pose = BOX_POSE_JUMP_WARNING_INIT;
            }
            else
            {
                if (gCurrentSprite.work2 != 0)
                    gCurrentSprite.pose = BOX_POSE_JUMP_WARNING_INIT;
                else
                    gCurrentSprite.pose = BOX_POSE_SLOW_RUN_INIT;
            }
        }
    }
}

void BoxJumpWarningInit(void)
{
    u16 samusX;

    samusX = gSamusData.xPosition;
    if (gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.875f) < samusX &&
        gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.875f) > samusX)
    {
        BoxStoppingToFireBombInit();
    }
    else
    {
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_JumpWarning;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = BOX_POSE_JUMP_WARNING;
    }
}

void BoxJumpWarning(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = BOX_POSE_JUMPING_INIT;
}

void BoxJumpingInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Jumping;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_JUMPING;
    gCurrentSprite.work4 = 0;

    if ((gCurrentSprite.work2 & 0x80) == 0)
    {
        if (SpriteUtilCheckSamusOnCeilingLadder())
            SpriteUtilMakeSpriteFaceSamusDirection();
        else
            SpriteUtilMakeSpriteFaceAwayFromSamusDirection();

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(4.6875f),
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(4.6875f));
            if (gPreviousCollisionCheck != 0)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work2 = 0x83;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(4.6875f),
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(4.6875f));
            if (gPreviousCollisionCheck != 0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work2 = 0x83;
            }
        }
    }

    SoundPlay(SOUND_BOX_JUMP);
}

void BoxJumping(void)
{
    u8 offset;
    s16 movement;

    offset = gCurrentSprite.work4;
    movement = sBoxJumpingSpeed[offset];
    if (movement == SHORT_MAX)
    {
        gCurrentSprite.pose = BOX_POSE_LANDING_INIT;
    }
    else
    {
        offset++;
        gCurrentSprite.work4 = offset;
        gSubSpriteData1.yPosition += movement;
        BoxXMovement(0xc, BOX_POSE_BONKING_INIT);
    }
}

void BoxStoppingToFireBombInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_FinishedCrawling;
    gCurrentSprite.work1 = 3;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_STOPPING_TO_FIRE_BOMB;

    SoundPlay(SOUND_BOX_FINISH_CRAWLING);
}

void BoxStoppingToFireBomb(void)
{
    if (gCurrentSprite.work1 > 1)
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
            gCurrentSprite.work1--;
    }
    else
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
            gCurrentSprite.pose = BOX_POSE_LOWERING_TO_FIRE_BOMB_INIT;
    }
}

void BoxLoweringToFireBombInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_LoweringToFireBomb;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_LOWERING_TO_FIRE_BOMB;

    SoundPlay(SOUND_BOX_LOWER_TO_FIRE_BOMB);
}

void BoxLoweringToFireBomb(void)
{
    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gCurrentSprite.pose = BOX_POSE_FIRING_BOMB;
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_FiringBomb;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
    }
}

void BoxFiringBomb(void)
{
    u16 x;
    u16 y;

    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gCurrentSprite.pose = BOX_POSE_DONE_FIRING_BOMB;
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_DoneFiringBomb;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        SoundPlay(SOUND_BOX_DONE_FIRING_BOMB);
    }
    else
    {
        y = gCurrentSprite.yPosition;
        x = gCurrentSprite.xPosition;
        if (gSubSpriteData1.currentAnimationFrame == 1 && gSubSpriteData1.animationDurationCounter == 2)
        {
            if (x > gSamusData.xPosition)
            {
                SpriteSpawnSecondary(SSPRITE_BOX_BOMB, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, y - BLOCK_TO_SUB_PIXEL(1.5625f), x, 0);
            }
            else
            {
                SpriteSpawnSecondary(SSPRITE_BOX_BOMB, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, y - BLOCK_TO_SUB_PIXEL(1.5625f), x,
                    SPRITE_STATUS_FACING_RIGHT);
            }
        }
    }
}

void BoxDoneFiringBomb(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = BOX_POSE_WAITING_TO_RUN_INIT;
}

void BoxDefeatedInit(void)
{
    gCurrentSprite.pOam = sBoxPartOam_BrainIdle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.pose = BOX_POSE_DEFEATED;

    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
}

void BoxDefeated(void)
{
    u32 blockTop;

    if (gCurrentSprite.work1 == 0)
    {
        blockTop =
            SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition);
        if (gPreviousVerticalCollisionCheck != 0)
        {
            gSubSpriteData1.yPosition = blockTop;
            gCurrentSprite.work1++;
        }
        else
        {
            gSubSpriteData1.yPosition += BLOCK_TO_SUB_PIXEL(0.25f);
        }
    }
    else
    {
        if (++gCurrentSprite.work1 > 30)
            gCurrentSprite.pose = BOX_POSE_MOVING_TO_FINAL_JUMP_INIT;
    }
}

void BoxMovingToFinalJumpInit(void)
{
    u8 debrisRamSlot;

    gCurrentSprite.pOam = sBoxPartOam_BrainIdle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_MOVING_TO_FINAL_JUMP;

    debrisRamSlot = SpriteUtilFindPrimary(PSPRITE_BOX_DEBRIS);
    gCurrentSprite.workX = gSpriteData[debrisRamSlot].xPosition;
    gCurrentSprite.work2 = debrisRamSlot;

    if (gSubSpriteData1.xPosition > gCurrentSprite.workX)
    {
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Crawling_Left;
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Crawling_Right;
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    }

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
}

void BoxMovingToFinalJump(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 1)
        SoundPlay(SOUND_BOX_FOOTSTEP);

    if ((gFrameCounter8Bit & 7) == 0)
    {
        if ((gFrameCounter8Bit & 8) != 0)
            gCurrentSprite.paletteRow = 11;
        else
            gCurrentSprite.paletteRow = 0;
    }

    if ((gSubSpriteData1.xPosition & 0xfff8) == (gCurrentSprite.workX & 0xfff8))
    {
        gCurrentSprite.pose = BOX_POSE_WAITING_FOR_FINAL_JUMP_INIT;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gSubSpriteData1.xPosition += BLOCK_TO_SUB_PIXEL(0.03125f);
        else
            gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(0.03125f);
    }
}

void BoxWaitingForFinalJumpInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_WAITING_FOR_FINAL_JUMP;

    SoundPlay(SOUND_BOX_PREPARE_FOR_FINAL_JUMP);
}

void BoxWaitingForFinalJump(void)
{
    u16 xPosOnScreen;

    if ((gFrameCounter8Bit & 7) == 0)
    {
        if ((gFrameCounter8Bit & 8) != 0)
            gCurrentSprite.paletteRow = 11;
        else
            gCurrentSprite.paletteRow = 0;
    }

    xPosOnScreen = SUB_PIXEL_TO_PIXEL_(gCurrentSprite.xPosition) - SUB_PIXEL_TO_PIXEL_(gBg1XPosition);
    if (xPosOnScreen > 0x18 && xPosOnScreen < SCREEN_SIZE_X - 0x18)
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
            gCurrentSprite.pose = BOX_POSE_CROUCHING_FOR_FINAL_JUMP_INIT;
    }
}

void BoxCrouchingForFinalJumpInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_JumpWarning;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_CROUCHING_FOR_FINAL_JUMP;
}

void BoxCrouchingForFinalJump(void)
{
    if ((gFrameCounter8Bit & 7) == 0)
    {
        if ((gFrameCounter8Bit & 8) != 0)
            gCurrentSprite.paletteRow = 11;
        else
            gCurrentSprite.paletteRow = 0;
    }

    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        gCurrentSprite.pose = BOX_POSE_FINAL_JUMP_INIT;
        unk_36c4();
    }
}

void BoxFinalJumpInit(void)
{
    gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Jumping;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = BOX_POSE_FINAL_JUMP;
    gCurrentSprite.work1 = 30;

    SoundPlay(SOUND_BOX_FINAL_JUMP);
}

void BoxFinalJump(void)
{
    if ((gFrameCounter8Bit & 7) == 0)
    {
        if ((gFrameCounter8Bit & 8) != 0)
            gCurrentSprite.paletteRow = 11;
        else
            gCurrentSprite.paletteRow = 0;
    }

    gSubSpriteData1.yPosition -= BLOCK_TO_SUB_PIXEL(0.625f);
    if (--gCurrentSprite.work1 == 0)
    {
        gSpriteData[gCurrentSprite.work2].pose = 0x18;
        gCurrentSprite.status = 0;
    }
}

void BoxCrawlingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Crawling_Right;
    else
        gSubSpriteData1.pMultiOam = sBoxMultiSpriteData_Crawling_Left;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = BOX_POSE_CRAWLING;
}

void BoxCrawling(void)
{
    BoxXMovement(1, BOX_POSE_FINISHED_CRAWLING_INIT);
}

void BoxPartSetBoxWorkVar2(u8 ramSlot, u8 value)
{
    if (gSpriteData[ramSlot].work2 < value)
        gSpriteData[ramSlot].work2 = value;
}

void BoxPartCenterSetImmunity(u8 ramSlot)
{
    switch (gSpriteData[ramSlot].pose)
    {
        case BOX_POSE_LOWERING_TO_FIRE_BOMB_INIT:
        case BOX_POSE_LOWERING_TO_FIRE_BOMB:
        case BOX_POSE_FIRING_BOMB:
            if ((gSpriteData[ramSlot].work0 & 3) != 0)
                gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            else
                gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
            break;

        case BOX_POSE_WAITING_TO_EMERGE_INIT:
        case BOX_POSE_WAITING_TO_EMERGE:
        case BOX_POSE_FIRST_JUMP_INIT:
        case BOX_POSE_FIRST_JUMP:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            break;

        default:
            gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
            break;
    }
}

void BoxPartRemoveIgnoreProjectiles(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
}

void BoxPartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.pose = 2;

    if (gCurrentSprite.roomSlot < BOX_PART_BRAIN)
        gCurrentSprite.drawOrder = BOX_BRAIN_DRAW_ORDER - 1;
    else
        gCurrentSprite.drawOrder = BOX_BRAIN_DRAW_ORDER + 1;

    switch (gCurrentSprite.roomSlot)
    {
        case BOX_PART_FRONT_LEFT_LEG_COVER:
        case BOX_PART_FRONT_RIGHT_LEG_COVER:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.125f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.125f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.frozenPaletteRowOffset = 2;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            break;

        case BOX_PART_CENTER: {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.frozenPaletteRowOffset = 1;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            break;
        }
        case BOX_PART_LAUNCHER:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            break;

        case BOX_PART_FRONT_LEFT_LEG:
        case BOX_PART_FRONT_RIGHT_LEG:
        case BOX_PART_MIDDLE_LEFT_LEG:
        case BOX_PART_MIDDLE_RIGHT_LEG:
        case BOX_PART_CENTER_BOTTOM:
        case BOX_PART_BACK_LEFT_LEG:
        case BOX_PART_BACK_RIGHT_LEG:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }

    BoxSyncSubSprites();
}


void BoxPartFrontLeftLeg(void)
{
    u8 brainRamSlot;
    u16 y;
    u16 x;

    brainRamSlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[brainRamSlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    if (gSpriteData[brainRamSlot].pose == BOX_POSE_DEFEATED &&
        gCurrentSprite.pOam != sBoxPartOam_FrontLeftLegCoverSlightlyDamaged)
    {
        ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.9375f), x, PE_0x30);
        gCurrentSprite.pOam = sBoxPartOam_FrontLeftLegCoverSlightlyDamaged;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    if ((gSpriteData[brainRamSlot].work0 & 4) == 0 && (gFrameCounter8Bit & 7) == 0)
    {
        if ((gFrameCounter8Bit & 8) != 0)
            gCurrentSprite.paletteRow = 11;
        else
            gCurrentSprite.paletteRow = 0;
    }
}

void BoxPartFrontRightLeg(void)
{
    u8 brainRamSlot;
    u16 y;
    u16 x;

    brainRamSlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[brainRamSlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    if (gSpriteData[brainRamSlot].pose == BOX_POSE_DEFEATED &&
        gCurrentSprite.pOam != sBoxPartOam_FrontRightLegCoverSlightlyDamaged)
    {
        ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.9375f), x, PE_0x30);
        gCurrentSprite.pOam = sBoxPartOam_FrontRightLegCoverSlightlyDamaged;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    if ((gSpriteData[brainRamSlot].work0 & 4) == 0 && (gFrameCounter8Bit & 7) == 0)
    {
        if ((gFrameCounter8Bit & 8) != 0)
            gCurrentSprite.paletteRow = 11;
        else
            gCurrentSprite.paletteRow = 0;
    }
}

void BoxPartCenter(void)
{
    u8 brainRamSlot;
    u16 maxHealth;
    u16 y;
    u16 x;

    brainRamSlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[brainRamSlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    if ((gSpriteData[brainRamSlot].work0 & 4) == 0)
    {
        if ((gFrameCounter8Bit & 7) == 0)
        {
            if ((gFrameCounter8Bit & 8) != 0)
                gCurrentSprite.paletteRow = 12;
            else
                gCurrentSprite.paletteRow = 0;
        }

        return;
    }

    maxHealth = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    BoxPartCenterSetImmunity(brainRamSlot);

    if (gCurrentSprite.health == 0)
    {
        gSpriteData[brainRamSlot].work0 &= ~4;
        ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.78125f), x, PE_0x2F);
        gSpriteData[brainRamSlot].pose = BOX_POSE_DEFEATED_INIT;
    }
    else if (gCurrentSprite.health < maxHealth / 4)
    {
        if (gCurrentSprite.pOam != sBoxPartOam_CenterHeavilyDamaged)
        {
            gCurrentSprite.pOam = sBoxPartOam_CenterHeavilyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.5625f), x, PE_0x30);
        }
    }
    else if (gCurrentSprite.health < maxHealth / 2)
    {
        if (gCurrentSprite.pOam != sBoxPartOam_CenterModeratelyDamaged)
        {
            gCurrentSprite.pOam = sBoxPartOam_CenterModeratelyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.5625f), x, PE_0x30);
        }
    }
    else if (gCurrentSprite.health < maxHealth * 3 / 4)
    {
        if (gCurrentSprite.pOam != sBoxPartOam_CenterSlightlyDamaged)
        {
            gCurrentSprite.pOam = sBoxPartOam_CenterSlightlyDamaged;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.5625f), x, PE_0x30);
        }
    }

    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
    {
        BoxPartSetBoxWorkVar2(brainRamSlot, 2);
        SoundPlay(SOUND_BOX_DAMAGED);
    }
}

void BoxPartCenterBottom(void)
{
    u8 brainRamSlot;

    brainRamSlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[brainRamSlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    switch (gSpriteData[brainRamSlot].pose)
    {
        case BOX_POSE_FINISHED_CRAWLING:
        case BOX_POSE_WAITING_TO_RUN:
        case BOX_POSE_JUMP_WARNING:
            if (gCurrentSprite.pOam != sBoxPartOam_CenterBottomOpeningAndClosingRapidly)
            {
                gCurrentSprite.pOam = sBoxPartOam_CenterBottomOpeningAndClosingRapidly;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;

        case BOX_POSE_DEFEATED:
        case BOX_POSE_MOVING_TO_FINAL_JUMP_INIT:
        case BOX_POSE_MOVING_TO_FINAL_JUMP:
        case BOX_POSE_WAITING_FOR_FINAL_JUMP_INIT:
        case BOX_POSE_WAITING_FOR_FINAL_JUMP:
        case BOX_POSE_CROUCHING_FOR_FINAL_JUMP_INIT:
        case BOX_POSE_CROUCHING_FOR_FINAL_JUMP:
        case BOX_POSE_FINAL_JUMP_INIT:
        case BOX_POSE_FINAL_JUMP:
            if (gCurrentSprite.pOam != sBoxPartOam_CenterBottomOpeningAndClosingRapidly)
            {
                gCurrentSprite.pOam = sBoxPartOam_CenterBottomOpeningAndClosingRapidly;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }

            if ((gFrameCounter8Bit & 7) == 0)
            {
                if ((gFrameCounter8Bit & 8) != 0)
                    gCurrentSprite.paletteRow = 12;
                else
                    gCurrentSprite.paletteRow = 0;
            }
            break;

        default:
            if (gCurrentSprite.pOam != sBoxPartOam_CenterBottomIdle)
            {
                gCurrentSprite.pOam = sBoxPartOam_CenterBottomIdle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            break;
    }
}

void BoxPartDefault(void)
{
    u8 brainRamSlot;

    brainRamSlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[brainRamSlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    switch (gSpriteData[brainRamSlot].pose)
    {
        case BOX_POSE_DEFEATED:
        case BOX_POSE_MOVING_TO_FINAL_JUMP_INIT:
        case BOX_POSE_MOVING_TO_FINAL_JUMP:
        case BOX_POSE_WAITING_FOR_FINAL_JUMP_INIT:
        case BOX_POSE_WAITING_FOR_FINAL_JUMP:
        case BOX_POSE_CROUCHING_FOR_FINAL_JUMP_INIT:
        case BOX_POSE_CROUCHING_FOR_FINAL_JUMP:
        case BOX_POSE_FINAL_JUMP_INIT:
        case BOX_POSE_FINAL_JUMP:
            if ((gFrameCounter8Bit & 7) == 0)
            {
                if ((gFrameCounter8Bit & 8) != 0)
                    gCurrentSprite.paletteRow = 13;
                else
                    gCurrentSprite.paletteRow = 0;
            }
            break;
    }
}

void BoxMissileInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.pOam = sBoxMissileOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.rotation = Q_8_8(0.75f);
    gCurrentSprite.scaling = Q_8_8(1);
    gCurrentSprite.work1 = 0x24;
    gCurrentSprite.workY = 5 * 60;
    gCurrentSprite.pose = 2;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;

    SoundPlay(SOUND_BOX_MISSILE_LAUNCH);
}

void BoxMissileSpawning(void)
{
    u32 movement;

    if (gCurrentSprite.health == 0)
        gCurrentSprite.pose = 0x37;

    movement = gCurrentSprite.work1 / 2;
    gCurrentSprite.yPosition -= movement;
    if (movement < 3)
    {
        gCurrentSprite.rotation = SpriteUtilMakeSpriteRotateTowardsTarget(gCurrentSprite.rotation,
            gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.0f), gSamusData.xPosition, gCurrentSprite.yPosition,
            gCurrentSprite.xPosition);
    }

    gCurrentSprite.work1 -= 2;
    if (gCurrentSprite.work1 < 2)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.work2 = 0;
        gCurrentSprite.work3 = 1;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work4 = 1;
    }
}

void BoxMissileMoving(void)
{
    u16 targetYOffset;

    if (--gCurrentSprite.workY != 0 && gCurrentSprite.health != 0)
    {
        if (gCurrentSprite.roomSlot == 3)
            targetYOffset = BLOCK_TO_SUB_PIXEL(0.125f);
        else if (gCurrentSprite.roomSlot == 2)
            targetYOffset = BLOCK_TO_SUB_PIXEL(0.625f);
        else if (gCurrentSprite.roomSlot == 1)
            targetYOffset = BLOCK_TO_SUB_PIXEL(1.125f);
        else
            targetYOffset = BLOCK_TO_SUB_PIXEL(1.625f);

        SpriteUtilMoveTowardsTarget((u16)(gSamusData.yPosition - targetYOffset), gSamusData.xPosition,
            BLOCK_TO_SUB_PIXEL(0.375f), BLOCK_TO_SUB_PIXEL(0.625f), 2);

        gCurrentSprite.rotation = SpriteUtilMakeSpriteRotateTowardsTarget(gCurrentSprite.rotation,
            gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.0f), gSamusData.xPosition, gCurrentSprite.yPosition,
            gCurrentSprite.xPosition);

        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

        if (gPreviousCollisionCheck != 0)
            gCurrentSprite.pose = SPRITE_POSE_STOPPED;
    }
    else
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
    }
}

void BoxMissileExploding(void)
{
    gCurrentSprite.status = 0;
    ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x25);
    SoundPlay(SOUND_BOX_MISSILE_EXPLODE);
}

enum BoxBombMovementStage {
    BOX_BOMB_MOVEMENT_STAGE_LAUNCHING,
    BOX_BOMB_MOVEMENT_STAGE_FALLING_1,
    BOX_BOMB_MOVEMENT_STAGE_FIRST_BOUNCE,
    BOX_BOMB_MOVEMENT_STAGE_FALLING_2,
    BOX_BOMB_MOVEMENT_STAGE_SECOND_BOUNCE,
    BOX_BOMB_MOVEMENT_STAGE_FALLING_3,
    BOX_BOMB_MOVEMENT_STAGE_LANDED
};

void BoxBombInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -PIXEL_TO_SUB_PIXEL(7);
    gCurrentSprite.hitboxBottom = PIXEL_TO_SUB_PIXEL(7);
    gCurrentSprite.hitboxLeft = -PIXEL_TO_SUB_PIXEL(7);
    gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(7);
    gCurrentSprite.pOam = sBoxBombOam_Detonating;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.rotation = 0;
    gCurrentSprite.scaling = Q_8_8(1);
    gCurrentSprite.work2 = BOX_BOMB_MOVEMENT_STAGE_LAUNCHING; // Movement stage
    gCurrentSprite.work3 = PIXEL_TO_SUB_PIXEL(1.75f);         // X speed
    gCurrentSprite.work4 = 0;                                 // Y speed table index
    gCurrentSprite.pose = 2;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    SoundPlay(SOUND_BOX_BOMB_LAUNCH);
}

void BoxBombMoving(void)
{
    u32 blockTop;
    u8 offset;
    u16 movement;

    if (gCurrentSprite.health == 0)
    {
        gCurrentSprite.pose = 0x37;
        return;
    }

    if (gCurrentSprite.work2 == BOX_BOMB_MOVEMENT_STAGE_LAUNCHING)
    {
        offset = gCurrentSprite.work4;
        movement = sBoxBombLaunchingSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = 0;
            gCurrentSprite.work2 += 1;
            gCurrentSprite.work4 = 0;
        }
        else
        {
            gCurrentSprite.work4 += 1;
        }

        if (gCurrentSprite.work4 == 3)
            gCurrentSprite.work3 = 7;

        gCurrentSprite.yPosition += movement;
    }
    else if (gCurrentSprite.work2 == BOX_BOMB_MOVEMENT_STAGE_FIRST_BOUNCE)
    {
        offset = gCurrentSprite.work4;
        movement = sBoxBombFirstBounceSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = 0;
            gCurrentSprite.work2 += 1;
            gCurrentSprite.work4 = 0;
        }
        else
        {
            gCurrentSprite.work4 += 1;
        }

        gCurrentSprite.yPosition += movement;
    }
    else if (gCurrentSprite.work2 == BOX_BOMB_MOVEMENT_STAGE_SECOND_BOUNCE)
    {
        offset = gCurrentSprite.work4;
        movement = sBoxBombSecondBounceSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = 0;
            gCurrentSprite.work2 += 1;
            gCurrentSprite.work4 = 0;
        }
        else
        {
            gCurrentSprite.work4 += 1;
        }

        gCurrentSprite.yPosition += movement;
    }
    else if (gCurrentSprite.work2 == BOX_BOMB_MOVEMENT_STAGE_LANDED)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.work1 = 60;
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sBoxBombFallingSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = sBoxBombFallingSpeed[gCurrentSprite.work4 - 1];
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
        }

        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != 0)
        {
            gCurrentSprite.yPosition = blockTop - BLOCK_TO_SUB_PIXEL(0.5f);

            if (gCurrentSprite.work2 == 1)
                SoundPlay(SOUND_BOX_BOMB_BOUNCE);

            gCurrentSprite.work2 += 1;
            gCurrentSprite.work4 = 0;
            gCurrentSprite.work3 -= PIXEL_SIZE / 2;
        }
        else
        {
            gCurrentSprite.yPosition += movement;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.rotation += (BOX_BOMB_MOVEMENT_STAGE_LANDED - gCurrentSprite.work2) * Q_8_8(1. / 32);
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
        if (gPreviousCollisionCheck == 0)
            gCurrentSprite.xPosition += gCurrentSprite.work3;
    }
    else
    {
        gCurrentSprite.rotation += (BOX_BOMB_MOVEMENT_STAGE_LANDED - gCurrentSprite.work2) * -Q_8_8(1. / 32);
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
        if (gPreviousCollisionCheck == 0)
            gCurrentSprite.xPosition -= gCurrentSprite.work3;
    }
}

void BoxBombLanded(void)
{
    if (gCurrentSprite.health == 0)
    {
        gCurrentSprite.pose = 0x37;
    }
    else
    {
        if (--gCurrentSprite.work1 == 0)
        {
            SpriteSpawnSecondary(SSPRITE_BOX_FIRE, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                gCurrentSprite.xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_BOX_FIRE, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                gCurrentSprite.xPosition, SPRITE_STATUS_FACING_RIGHT);

            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x22);
            gCurrentSprite.status = 0;
            SoundPlay(SOUND_BOX_BOMB_EXPLODE);
        }
    }
}

void BoxBombExploding(void)
{
    ParticleSet(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f), gCurrentSprite.xPosition, PE_0x32);
    gCurrentSprite.status = 0;
    SoundPlay(SOUND_BOX_BOMB_DESTROYED);
}

void BoxFireInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(6.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.pOam = sBoxFireOam_MovingHigh;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.pose = 2;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
}

void BoxFireMovingHigh(void)
{
    u16 hitboxTop;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
        case 1:
        case 2:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
            break;

        case 3:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
            break;

        case 4:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            if (gCurrentSprite.animationDurationCounter == 1)
                SoundPlay(SOUND_BOX_FIRE_TRANSITION_TO_HIGH);
            break;

        case 6:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(3.0f);
            break;

        case 27:
            if (gCurrentSprite.animationDurationCounter == 1)
                SoundPlay(SOUND_BOX_FIRE_TRANSITION_TO_LOW);

        case 28:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(5.5f);
            break;

        case 8:
        case 29:
        case 30:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(5.0f);
            break;

        case 31:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(4.5f);
            break;

        case 7:
        case 32:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(4.0f);
            break;

        case 33:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(3.5f);
            break;

        case 5:
        case 34:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(2.0f);
            break;

        case 35:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            break;

        default:
            hitboxTop = -BLOCK_TO_SUB_PIXEL(6.0f);
            break;
    }

    gCurrentSprite.hitboxTop = hitboxTop;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sBoxFireOam_MovingLow;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.work1 = 60;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.75f);
    }

    if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
        if (gPreviousCollisionCheck != 0)
            gCurrentSprite.status = 0;
        else
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.046875f);
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
        if (gPreviousCollisionCheck != 0)
            gCurrentSprite.status = 0;
        else
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.046875f);
    }
}

void BoxFireMovingLow(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pOam = sBoxFireOam_MovingHigh;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 2;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    }

    if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
        if (gPreviousCollisionCheck != 0)
            gCurrentSprite.status = 0;
        else
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.046875f);
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
        if (gPreviousCollisionCheck != 0)
            gCurrentSprite.status = 0;
        else
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.046875f);
    }
}

void BoxSpawnFallingDebris(void)
{
    u16 y;
    u16 x;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    SpriteSpawnSecondary(SSPRITE_BOX_FALLING_DEBRIS, 0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, y, x - BLOCK_TO_SUB_PIXEL(3.625f), 0);
    SpriteSpawnSecondary(SSPRITE_BOX_FALLING_DEBRIS, 1, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, y, x + BLOCK_TO_SUB_PIXEL(2.96875f), 0);
    SpriteSpawnSecondary(SSPRITE_BOX_FALLING_DEBRIS, 2, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, y, x - BLOCK_TO_SUB_PIXEL(5.34375f), 0);
    SpriteSpawnSecondary(SSPRITE_BOX_FALLING_DEBRIS, 3, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, y, x - BLOCK_TO_SUB_PIXEL(2.5f), 0);
    SpriteSpawnSecondary(SSPRITE_BOX_FALLING_DEBRIS, 4, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, y, x - BLOCK_TO_SUB_PIXEL(4.09375f), 0);
    SpriteSpawnSecondary(SSPRITE_BOX_FALLING_DEBRIS, 5, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, y, x + BLOCK_TO_SUB_PIXEL(3.4375f), 0);
    SpriteSpawnSecondary(SSPRITE_BOX_FALLING_DEBRIS, 6, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, y, x - BLOCK_TO_SUB_PIXEL(1.25f), 0);
    SpriteSpawnSecondary(SSPRITE_BOX_FALLING_DEBRIS, 7, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, y, x - BLOCK_TO_SUB_PIXEL(4.5625f), 0);
    SpriteSpawnSecondary(SSPRITE_BOX_FALLING_DEBRIS, 8, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, y, x + BLOCK_TO_SUB_PIXEL(2.1875f), 0);
}

void BoxSetDebrisClipdata(u8 caa)
{
    u16 y;
    u16 x;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(3.5f), x + BLOCK_TO_SUB_PIXEL(0.5f));

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y - BLOCK_TO_SUB_PIXEL(3.5f), x - BLOCK_TO_SUB_PIXEL(0.5f));
}

void BoxDebrisInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(4);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(3.75f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
    gCurrentSprite.pOam = sBoxDebrisOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = 1;
    gCurrentSprite.properties |= 8;
    gCurrentSprite.drawOrder = 0xc;
    gCurrentSprite.samusCollision = SSC_SOLID;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.5f);

    if (EventCheckAfter_BoxDefeated())
    {
        gCurrentSprite.pose = 0x1e;
        gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
        if (gPreviousCollisionCheck == 0)
        {
            gCurrentSprite.status = 0;
        }
        else
        {
            BoxSetDebrisClipdata(CAA_MAKE_SOLID);
            BoxSpawnFallingDebris();
        }
    }
    else
    {
        gCurrentSprite.pose = 2;
        if (gPreviousCollisionCheck != 0)
            gCurrentSprite.status = 0;
    }
}

void BoxDebrisIdle(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
}

void BoxDebrisFallingInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
    gCurrentSprite.pose = 0x1a;
}

void BoxDebrisWaitToFall(void)
{
    u16 xPosOnScreen;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    xPosOnScreen = SUB_PIXEL_TO_PIXEL_(gCurrentSprite.xPosition) - SUB_PIXEL_TO_PIXEL_(gBg1XPosition);
    if (xPosOnScreen > 0x20 && xPosOnScreen < SCREEN_SIZE_X - 0x20)
    {
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work4 = 0;
        gCurrentSprite.pose = 0x1c;

        ScreenShakeStartHorizontal(40, 0x81);
        ScreenShakeStartVertical(40, 0x81);

        BoxSpawnFallingDebris();
        SoundPlay_3b1c(SOUND_BOX_DEBRIS_FALLING);
    }
}

void BoxDebrisFalling(void)
{
    u32 blockTop;
    u16 y;
    u16 x;
    u8 offset;
    s16 movement;
    u32 work1;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.work1++;
    work1 = gCurrentSprite.work1;
    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(y, x);
    if (gPreviousVerticalCollisionCheck != 0)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = 0x1e;

        ScreenShakeStartVertical(30, 0x81);
        ParticleSet(y, x, PE_SMOKE);
        ParticleSet(y, x + BLOCK_TO_SUB_PIXEL(0.5f), PE_SMOKE);

        EventCheckAdvance(EVENT_BOX_DEFEATED);
        BoxSetDebrisClipdata(CAA_MAKE_SOLID);
        PlayMusic(MUSIC_BOSS_TENSION, 6);
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sSpritesFallingSpeedFast[offset];
        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeedFast[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
            gCurrentSprite.yPosition += movement;
        }
        if ((work1 & 0xf) == 0)
            ParticleSet(y, x, PE_TAIL_EXPLOSION);
        else if (((work1 + 4) & 0xf) == 0)
            ParticleSet(y - BLOCK_TO_SUB_PIXEL(2.5f), x + BLOCK_TO_SUB_PIXEL(0.625f), PE_0x33);
        else if (((work1 + 8) & 0xf) == 0)
            ParticleSet(y - BLOCK_TO_SUB_PIXEL(2.03125f), x - BLOCK_TO_SUB_PIXEL(0.625f), PE_0x33);
    }
}

void BoxFallingDebrisInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    switch (gCurrentSprite.roomSlot)
    {
        case 0:
            gCurrentSprite.pOam = sBoxFallingDebrisOam_0;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.125f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0625f);
            gCurrentSprite.drawOrder = 11;
            gCurrentSprite.samusCollision = SSC_SOLID;
            gCurrentSprite.health = 1;
            gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
            gCurrentSprite.work1 = 30;
            break;

        case 1:
            gCurrentSprite.pOam = sBoxFallingDebrisOam_1;
            gCurrentSprite.drawOrder = 10;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.work1 = 60;
            if (!EventCheckAfter_BoxDefeated())
                gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(3.0f);
            break;

        case 2:
            gCurrentSprite.pOam = sBoxFallingDebrisOam_2;
            gCurrentSprite.drawOrder = 10;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
            gCurrentSprite.work1 = 40;
            break;

        case 3:
            gCurrentSprite.pOam = sBoxFallingDebrisOam_3;
            gCurrentSprite.drawOrder = 10;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
            gCurrentSprite.work1 = 80;
            break;

        case 4:
            gCurrentSprite.pOam = sBoxFallingDebrisOam_4;
            gCurrentSprite.drawOrder = 9;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.work1 = 100;
            break;

        case 5:
            gCurrentSprite.pOam = sBoxFallingDebrisOam_5;
            gCurrentSprite.drawOrder = 9;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.work1 = 120;
            if (!EventCheckAfter_BoxDefeated())
                gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(3.0f);
            break;

        case 6:
            gCurrentSprite.pOam = sBoxFallingDebrisOam_6;
            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
            gCurrentSprite.work1 = 10;
            break;

        case 7:
            gCurrentSprite.pOam = sBoxFallingDebrisOam_7;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
            gCurrentSprite.work1 = 20;
            break;

        case 8:
            gCurrentSprite.pOam = sBoxFallingDebrisOam_8;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.work1 = 60;
            if (!EventCheckAfter_BoxDefeated())
                gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(3.0f);
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }

    if (EventCheckAfter_BoxDefeated())
        gCurrentSprite.pose = 0x1e;
    else
        gCurrentSprite.pose = 2;
}

void BoxFallingDebrisFalling(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.work1 > 0)
    {
        gCurrentSprite.work1--;
    }
    else
    {
        u16 y;
        u16 x;
        u8 work2;
        u8 roomSlot;

        gCurrentSprite.work2++;
        work2 = gCurrentSprite.work2;
        y = gCurrentSprite.yPosition;
        x = gCurrentSprite.xPosition;
        roomSlot = gCurrentSprite.roomSlot;

        if (gCurrentSprite.work3 < UCHAR_MAX)
            gCurrentSprite.work3++;

        if (gCurrentSprite.work3 > 50)
        {
            u32 blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(y, x);
            if (gPreviousVerticalCollisionCheck != 0)
            {
                gCurrentSprite.yPosition = blockTop;
                gCurrentSprite.pose = 0x1e;
                if (roomSlot == 0)
                {
                    ScreenShakeStartVertical(30, 0x81);
                    ParticleSet(y, x - BLOCK_TO_SUB_PIXEL(0.5f), PE_SMOKE);
                    ParticleSet(y, x + BLOCK_TO_SUB_PIXEL(0.5f), PE_SMOKE);
                }
                else if (roomSlot == 1 || roomSlot == 6)
                {
                    ParticleSet(y, x, PE_SMOKE);
                }
                else if (roomSlot == 2 || roomSlot == 3 || roomSlot == 7)
                {
                    ParticleSet(y, x - BLOCK_TO_SUB_PIXEL(0.25f), PE_HEAVY_DUST_1);
                    ParticleSet(y, x + BLOCK_TO_SUB_PIXEL(0.25f), PE_HEAVY_DUST_1);
                }
                else
                {
                    ParticleSet(y, x, PE_HEAVY_DUST_1);
                }

                return;
            }
        }

        if (roomSlot == 0)
        {
            u8 offset;
            s16 movement;

            if ((work2 & 0xf) == 0)
                ParticleSet(y, x, PE_SMOKE);
            else if (((work2 + 4) & 0xf) == 0)
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(2.5f), x + BLOCK_TO_SUB_PIXEL(0.78125f), PE_TAIL_EXPLOSION_SMOKE);
            else if (((work2 + 8) & 0xf) == 0)
                ParticleSet(y, x - BLOCK_TO_SUB_PIXEL(0.5f), PE_0x33);

            offset = gCurrentSprite.work4;
            movement = sSpritesFallingSpeedFast[offset];
            if (movement == SHORT_MAX)
            {
                movement = sSpritesFallingSpeedFast[offset - 1];
                gCurrentSprite.yPosition += movement;
            }
            else
            {
                offset++;
                gCurrentSprite.work4 = offset;
                gCurrentSprite.yPosition += movement;
            }
        }
        else if (roomSlot == 1 || roomSlot == 6)
        {
            u8 offset;
            s16 movement;

            if ((work2 & 0x1f) == 0)
                ParticleSet(y, x, PE_HEAVY_DUST_1);

            offset = gCurrentSprite.work4;
            movement = sSpritesFallingSpeedQuickAcceleration[offset];
            if (movement == SHORT_MAX)
            {
                movement = sSpritesFallingSpeedQuickAcceleration[offset - 1];
                gCurrentSprite.yPosition += movement;
            }
            else
            {
                offset++;
                gCurrentSprite.work4 = offset;
                gCurrentSprite.yPosition += movement;
            }
        }
        else if (roomSlot == 2 || roomSlot == 3 || roomSlot == 7)
        {
            u8 offset;
            s16 movement;

            if (((work2 + 7) & 0x1f) == 0)
                ParticleSet(y, x, PE_0x33);

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
        else
        {
            u8 offset;
            s16 movement;

            offset = gCurrentSprite.work4;
            movement = sSpritesFallingSpeedSlow[offset];

            if (movement == SHORT_MAX)
            {
                movement = sSpritesFallingSpeedSlow[offset - 1];
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
}

void Box(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            BoxInit();
            break;

        case BOX_POSE_CRAWLING_INIT:
            BoxCrawlingInit();
        case BOX_POSE_CRAWLING:
            BoxCrawling();
            break;

        case BOX_POSE_WAITING_TO_RUN_INIT:
            BoxWaitingToRunInit();
        case BOX_POSE_WAITING_TO_RUN:
            BoxWaitingToRun();
            break;

        case BOX_POSE_SLOW_RUN_INIT:
            BoxSlowRunningInit();
        case BOX_POSE_SLOW_RUN:
            BoxSlowRun();
            break;

        case BOX_POSE_FAST_RUN_INIT:
            BoxFastRunInit();
        case BOX_POSE_FAST_RUN:
            BoxFastRun();
            break;

        case BOX_POSE_SKIDDING_INIT:
            BoxSkiddingInit();
        case BOX_POSE_SKIDDING:
            BoxSkidding();
            break;

        case BOX_POSE_STOP_SKIDDING_INIT:
            BoxStopSkiddingInit();
        case BOX_POSE_STOP_SKIDDING:
            BoxStopSkidding();
            break;

        case BOX_POSE_FINISHED_CRAWLING_INIT:
            BoxFinishedCrawlingInit();
        case BOX_POSE_FINISHED_CRAWLING:
            BoxFinishedCrawling();
            break;

        case BOX_POSE_BONKING_INIT:
            BoxBonkingInit();
        case BOX_POSE_BONKING:
            BoxBonking();
            break;

        case BOX_POSE_LANDING_FROM_BONK_INIT:
            BoxLandingFromBonkInit();
        case BOX_POSE_LANDING_FROM_BONK:
            BoxLandingFromBonk();
            break;

        case BOX_POSE_LANDING_INIT:
            BoxLandingInit();
        case BOX_POSE_LANDING:
            BoxLanding();
            break;

        case BOX_POSE_JUMP_WARNING_INIT:
            BoxJumpWarningInit();
        case BOX_POSE_JUMP_WARNING:
            BoxJumpWarning();
            break;

        case BOX_POSE_JUMPING_INIT:
            BoxJumpingInit();
        case BOX_POSE_JUMPING:
            BoxJumping();
            break;

        case BOX_POSE_STOPPING_TO_FIRE_BOMB_INIT:
            BoxStoppingToFireBombInit();
        case BOX_POSE_STOPPING_TO_FIRE_BOMB:
            BoxStoppingToFireBomb();
            break;

        case BOX_POSE_LOWERING_TO_FIRE_BOMB_INIT:
            BoxLoweringToFireBombInit();
        case BOX_POSE_LOWERING_TO_FIRE_BOMB:
            BoxLoweringToFireBomb();
            break;

        case BOX_POSE_FIRING_BOMB:
            BoxFiringBomb();
            break;

        case BOX_POSE_DONE_FIRING_BOMB:
            BoxDoneFiringBomb();
            break;

        case BOX_POSE_WAITING_TO_EMERGE_INIT:
            BoxWaitingToEmergeInit();
        case BOX_POSE_WAITING_TO_EMERGE:
            BoxWaitingToEmerge();
            break;

        case BOX_POSE_FIRST_JUMP_INIT:
            BoxFirstJumpInit();
        case BOX_POSE_FIRST_JUMP:
            BoxFirstJump();
            break;

        case BOX_POSE_DEFEATED_INIT:
            BoxDefeatedInit();
        case BOX_POSE_DEFEATED:
            BoxDefeated();
            break;

        case BOX_POSE_MOVING_TO_FINAL_JUMP_INIT:
            BoxMovingToFinalJumpInit();
        case BOX_POSE_MOVING_TO_FINAL_JUMP:
            BoxMovingToFinalJump();
            break;

        case BOX_POSE_WAITING_FOR_FINAL_JUMP_INIT:
            BoxWaitingForFinalJumpInit();
        case BOX_POSE_WAITING_FOR_FINAL_JUMP:
            BoxWaitingForFinalJump();
            break;

        case BOX_POSE_CROUCHING_FOR_FINAL_JUMP_INIT:
            BoxCrouchingForFinalJumpInit();
        case BOX_POSE_CROUCHING_FOR_FINAL_JUMP:
            BoxCrouchingForFinalJump();
            break;

        case BOX_POSE_FINAL_JUMP_INIT:
            BoxFinalJumpInit();
        case BOX_POSE_FINAL_JUMP:
            BoxFinalJump();
    }
    SpriteUtilUpdateSubSpriteData1Animation();
    SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
}

void BoxPart(void)
{
    if (gCurrentSprite.pose == 0)
    {
        BoxPartInit();
        return;
    }

    switch (gCurrentSprite.roomSlot)
    {
        case BOX_PART_FRONT_LEFT_LEG_COVER:
            if (SPRITE_GET_ISFT(gCurrentSprite) < (gSubSpriteData1.work0 & 0x7f))
                gCurrentSprite.invincibilityStunFlashTimer = gSubSpriteData1.work0;

            BoxPartFrontLeftLeg();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case BOX_PART_FRONT_RIGHT_LEG_COVER:
            if (SPRITE_GET_ISFT(gCurrentSprite) < (gSubSpriteData1.work0 & 0x7f))
                gCurrentSprite.invincibilityStunFlashTimer = gSubSpriteData1.work0;

            BoxPartFrontRightLeg();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case BOX_PART_CENTER:
            gSubSpriteData1.work0 = gCurrentSprite.invincibilityStunFlashTimer;
            BoxPartCenter();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case BOX_PART_CENTER_BOTTOM:
            if (SPRITE_GET_ISFT(gCurrentSprite) < (gSubSpriteData1.work0 & 0x7f))
                gCurrentSprite.invincibilityStunFlashTimer = gSubSpriteData1.work0;

            BoxPartCenterBottom();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        default:
            if (SPRITE_GET_ISFT(gCurrentSprite) < (gSubSpriteData1.work0 & 0x7f))
                gCurrentSprite.invincibilityStunFlashTimer = gSubSpriteData1.work0;

            BoxPartDefault();
            BoxSyncSubSprites();
            break;
    }
}

void BoxMissile(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            BoxMissileInit();
            break;

        case 2:
            BoxMissileSpawning();
            break;

        case 0x18:
            BoxMissileMoving();
            break;

        case SPRITE_POSE_STOPPED:
            BoxMissileExploding();
            break;
    }
}

void BoxBomb(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            BoxBombInit();
            break;

        case 2:
            BoxBombMoving();
            break;

        case 0x18:
            BoxBombLanded();
            break;

        case SPRITE_POSE_STOPPED:
            BoxBombExploding();
            break;
    }
}

void BoxFire(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            BoxFireInit();
        case 2:
            BoxFireMovingHigh();
            break;

        case 0x18:
            BoxFireMovingLow();
            break;
    }
}

void BoxDebris(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            BoxDebrisInit();
            break;

        case 2:
            BoxDebrisIdle();
            break;

        case 0x18:
            BoxDebrisFallingInit();
            break;

        case 0x1a:
            BoxDebrisWaitToFall();
            break;

        case 0x1c:
            BoxDebrisFalling();
            break;
    }
}

void BoxFallingDebris(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            BoxFallingDebrisInit();
            break;

        case 2:
            BoxFallingDebrisFalling();
            break;
    }
}
