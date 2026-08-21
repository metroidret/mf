#include "data/sprites/mimic.h"

#include "globals.h"

#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/sprite.h"

void MimicInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
        {
            gCurrentSprite.status = 0;
            return;
        }
    }

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_NONE;

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

void MimicIdleInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void MimicIdle(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    if ((u8)SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(3.0f), BLOCK_TO_SUB_PIXEL(3.0f)) !=
        NSLR_OUT_OF_RANGE)
        gCurrentSprite.pose = 0x17;
}

void MimicWakingUpInit(void)
{
    gCurrentSprite.pose = 0x18;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.properties &= ~SP_SOLID_FOR_PROJECTILES;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
}

void MimicWakingUp(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = 0x19;
}

void MimicFlyingInit(void)
{
    gCurrentSprite.pose = 0x1a;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.work1 = 60;
    gCurrentSprite.work2 = 60;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void MimicFlying(void)
{
    u8 offset;
    s16 movement;

    if (gCurrentSprite.work1 > 0)
    {
        gCurrentSprite.work1--;
        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.0625f);
        return;
    }

    offset = gCurrentSprite.work4;
    movement = sMimicFlyingYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sMimicFlyingYMovement[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work4 = offset;
    gCurrentSprite.yPosition += movement;

    if (--gCurrentSprite.work2 == 0)
        gCurrentSprite.pose = 0x1b;
}

void MimicFlyingAwayInit(void)
{
    gCurrentSprite.pose = 0x1c;
    gCurrentSprite.workY = 300;
    gCurrentSprite.workX = 0;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 1;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 1;
}

void MimicFlyingAway(void)
{
    u16 targetY;
    u16 targetX;

    targetY = gXParasiteTargetYPosition;
    targetX = gXParasiteTargetXPosition;

    switch (gCurrentSprite.workX)
    {
        case 1:
            targetY -= BLOCK_TO_SUB_PIXEL(1.125f);
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                targetX += BLOCK_TO_SUB_PIXEL(1.125f);
            else
                targetX -= BLOCK_TO_SUB_PIXEL(1.125f);
            break;

        case 3:
            targetY += BLOCK_TO_SUB_PIXEL(1.125f);
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                targetX -= BLOCK_TO_SUB_PIXEL(1.125f);
            else
                targetX += BLOCK_TO_SUB_PIXEL(1.125f);
            break;
    }

    unk_136ac(targetY, targetX, BLOCK_TO_SUB_PIXEL(0.0625f) * 4, BLOCK_TO_SUB_PIXEL(0.09375f) * 4, LOG2(4));

    if (--gCurrentSprite.workY == 0)
        gCurrentSprite.pose = 0x1e;
}

void MimicLeaving(void)
{
    u32 movement;

    if (gCurrentSprite.work3 < BLOCK_TO_SUB_PIXEL(0.390625f) * 8)
        gCurrentSprite.work3++;

    movement = DIV_SHIFT(gCurrentSprite.work3, 8);
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.xPosition += movement;
    else
        gCurrentSprite.xPosition -= movement;

    if (gCurrentSprite.work4 < BLOCK_TO_SUB_PIXEL(0.390625f) * 8)
        gCurrentSprite.work4++;

    movement = DIV_SHIFT(gCurrentSprite.work4, 8);
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gCurrentSprite.yPosition += movement;
    else
        gCurrentSprite.yPosition -= movement;

    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
        gCurrentSprite.status = 0;
}

void MimicEnergyTank(void)
{
    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MimicInit();
            gCurrentSprite.pOam = sMimicEnergyTankOam_Idle;
            break;

        case SPRITE_POSE_IDLE_INIT:
            gCurrentSprite.pOam = sMimicEnergyTankOam_Idle;
            MimicIdleInit();
        case SPRITE_POSE_IDLE:
            MimicIdle();
            return;

        case 0x17:
            gCurrentSprite.pOam = sMimicEnergyTankOam_WakingUp;
            MimicWakingUpInit();
        case 0x18:
            MimicWakingUp();
            break;

        case 0x19:
            gCurrentSprite.pOam = sMimicEnergyTankOam_Flying;
            MimicFlyingInit();
        case 0x1A:
            MimicFlying();
            break;

        case 0x1B:
            MimicFlyingAwayInit();
        case 0x1C:
            MimicFlyingAway();
            break;

        case 0x1E:
            MimicLeaving();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            MimicInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
            break;
    }
}

void MimicMissileTank(void)
{
    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MimicInit();
            gCurrentSprite.pOam = sMimicMissileTankOam_Idle;
            break;

        case SPRITE_POSE_IDLE_INIT:
            gCurrentSprite.pOam = sMimicMissileTankOam_Idle;
            MimicIdleInit();
        case SPRITE_POSE_IDLE:
            MimicIdle();
            break;

        case 0x17:
            gCurrentSprite.pOam = sMimicMissileTankOam_WakingUp;
            MimicWakingUpInit();
        case 0x18:
            MimicWakingUp();
            break;

        case 0x19:
            gCurrentSprite.pOam = sMimicMissileTankOam_Flying;
            MimicFlyingInit();
        case 0x1A:
            MimicFlying();
            break;

        case 0x1B:
            MimicFlyingAwayInit();
        case 0x1C:
            MimicFlyingAway();
            break;

        case 0x1E:
            MimicLeaving();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            MimicInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
            break;
    }
}
