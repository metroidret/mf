#include "data/sprites/evir.h"

#include "globals.h"

#include "data/generic_data.h"
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

u8 EvirCheckInShootingRange(void)
{
    u8 nslr;

    nslr = NSLR_OUT_OF_RANGE;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return NSLR_OUT_OF_RANGE;

    if (gCurrentSprite.work1 > 0)
    {
        gCurrentSprite.work1--;
        return NSLR_OUT_OF_RANGE;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gCurrentSprite.health > 0)
        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(6.0f), BLOCK_TO_SUB_PIXEL(6.0f));

    return nslr;
}

void EvirSpawningFromX(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (--gCurrentSprite.workY > 0)
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = 2;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }
}

void EvirTurningIntoX(void)
{
    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1.4375f);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.625f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f), SPRITE_STATUS_X_FLIP);
    }
    else
    {
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.625f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f), SPRITE_STATUS_X_FLIP);
    }
}

void EvirInit(void)
{
    u8 slot;

    SpriteUtilTrySetAbsorbXFlag();

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.pOam = sEvirOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 0;

    if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.numberOfXToForm = 2;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0f);
    }
    else
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.hitboxBottom = -BLOCK_TO_SUB_PIXEL(0.375f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    }

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
        return;
    }

    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    SpriteUtilMakeSpriteFaceSamusXFlip();
    SpriteUtilChooseRandomXDirection();

    slot = SpriteSpawnSecondary(SSPRITE_EVIR_COLLISION, FALSE, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f),
        gCurrentSprite.xPosition, 0);
    if (slot == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        slot = SpriteSpawnSecondary(SSPRITE_EVIR_COLLISION, TRUE, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.375f), 0);
        if (slot == UCHAR_MAX)
        {
            gCurrentSprite.status = 0;
            return;
        }
    }
    else
    {
        slot = SpriteSpawnSecondary(SSPRITE_EVIR_COLLISION, TRUE, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.375f), 0);
        if (slot == UCHAR_MAX)
        {
            gCurrentSprite.status = 0;
            return;
        }
    }
}

void EvirShootingInit(void)
{
    gCurrentSprite.pose = 0x2a;
    gCurrentSprite.pOam = sEvirOam_Shooting;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 90;
}

void EvirShooting(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.pose = 1;
        return;
    }

    if (gCurrentSprite.currentAnimationFrame == 4 && gCurrentSprite.animationDurationCounter == 8)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteSpawnSecondary(SSPRITE_EVIR_PROJECTILE, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.125f),
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.4375f), SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_EVIR_PROJECTILE, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.125f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.4375f), 0);
        }
    }
    else if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 8 &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        SoundPlayNotAlreadyPlaying(SOUND_EVIR_SHOOTING);
    }
}

void EvirIdleInit(void)
{
    gCurrentSprite.pose = 2;
    gCurrentSprite.pOam = sEvirOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void EvirIdle(void)
{
    boolu8 turn;

    if (EvirCheckInShootingRange() != NSLR_OUT_OF_RANGE)
    {
        EvirShootingInit();
        return;
    }

    turn = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            turn = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f),
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                turn = TRUE;
            else if (MOD_AND(gFrameCounter8Bit, 8) == 0)
                gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.0625f);
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            turn = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.5f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                turn = TRUE;
            else if (MOD_AND(gFrameCounter8Bit, 8) == 0)
                gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.0625f);
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.125f),
            gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        else
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.03125f);
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.0f),
            gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        else
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.03125f);
    }

    if (turn)
    {
        gCurrentSprite.pose = 3;
    }
    else if (gCurrentSprite.currentAnimationFrame == 2 && gCurrentSprite.animationDurationCounter == 1 &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        SoundPlayNotAlreadyPlaying(SOUND_EVIR_IDLE);
    }
}

void EvirTurningAroundInit(void)
{
    gCurrentSprite.pose = 4;
    gCurrentSprite.pOam = sEvirOam_TurningAround1;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void EvirTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 5;
        gCurrentSprite.pOam = sEvirOam_TurningAround2;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
    }
}

void EvirTurningAroundSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void EvirCollisionInit(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[primary].status & SPRITE_STATUS_HIDDEN)
        gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.pose = 2;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.pOam = sEvirProjectileOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.roomSlot)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.375f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.375f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.875f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.875f);
    }
}

void EvirCollisionIdle(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[primary].status & SPRITE_STATUS_HIDDEN)
        gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;

    if (gCurrentSprite.health == 0)
    {
        if (gSpriteData[primary].pose < SPRITE_POSE_DYING_INIT)
        {
            gSpriteData[primary].pose = SPRITE_POSE_DYING_INIT;
            gSpriteData[primary].ignoreSamusCollisionTimer = 1;
            gSpriteData[primary].health = 0;
            gSpriteData[primary].properties |= SP_DESTROYED;
            gSpriteData[primary].freezeTimer = 0;
            gSpriteData[primary].paletteRow = 0;
            gCurrentSprite.status = 0;

            return;
        }
    }

    if (gCurrentSprite.roomSlot)
    {
        gCurrentSprite.yPosition = gSpriteData[primary].yPosition - BLOCK_TO_SUB_PIXEL(0.5f);
        if (gSpriteData[primary].status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition = gSpriteData[primary].xPosition - BLOCK_TO_SUB_PIXEL(0.375f);
        else
            gCurrentSprite.xPosition = gSpriteData[primary].xPosition + BLOCK_TO_SUB_PIXEL(0.375f);
    }
    else
    {
        gCurrentSprite.yPosition = gSpriteData[primary].yPosition - BLOCK_TO_SUB_PIXEL(1.5f);
        gCurrentSprite.xPosition = gSpriteData[primary].xPosition;
    }

    switch (gSpriteData[primary].pose)
    {
        case SPRITE_POSE_DYING_INIT:
        case SPRITE_POSE_DYING:
            gCurrentSprite.status = 0;
            return;
    }

    if (gSpriteData[primary].status & SPRITE_STATUS_MOSAIC)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
}

void EvirProjectileInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.properties |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.pOam = sEvirProjectileOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.scaling = 0x40;
    gCurrentSprite.work2 = Q_8_8(1.f / 4);
    gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = 1;
    gCurrentSprite.workY = gCurrentSprite.yPosition;
    gCurrentSprite.workX = gCurrentSprite.xPosition;
}

void EvirProjectileMovingInit(void)
{
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
}

void EvirProjectileMoving(void)
{
    s16 distance;
    u32 angle;
    s16 sin, cos;
    u16 yOffset, xOffset;

    if (gCurrentSprite.health == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
        return;
    }

    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.work2 -= 4;
    else
        gCurrentSprite.work2 += 4;

    if (MOD_AND(gFrameCounter8Bit, 2) != 0)
        gCurrentSprite.scaling += 1;

    distance = gCurrentSprite.scaling;
    angle = gCurrentSprite.work2;

    sin = SIN(angle);
    if (sin < 0)
    {
        yOffset = Q_8_8_TO_INT(-sin * distance);
        gCurrentSprite.yPosition = gCurrentSprite.workY - yOffset;
    }
    else
    {
        yOffset = Q_8_8_TO_INT(sin * distance);
        gCurrentSprite.yPosition = gCurrentSprite.workY + yOffset;
    }

    cos = COS(angle);
    if (cos < 0)
    {
        xOffset = Q_8_8_TO_INT(-cos * distance);
        gCurrentSprite.xPosition = gCurrentSprite.workX - xOffset;
    }
    else
    {
        xOffset = Q_8_8_TO_INT(cos * distance);
        gCurrentSprite.xPosition = gCurrentSprite.workX + xOffset;
    }
}

void EvirProjectileExplodingInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.pose = 0x38;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pOam = sEvirProjectileOam_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
}

void EvirProjectileExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

void Evir(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_EVIR_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(SSPRITE_EVIR_COLLISION, gCurrentSprite.primarySpriteRamSlot);
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            EvirInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            EvirIdleInit();
        case SPRITE_POSE_IDLE:
            EvirIdle();
            break;

        case 0x29:
            EvirShootingInit();
        case 0x2a:
            EvirShooting();
            break;

        case 3:
            EvirTurningAroundInit();
        case 4:
            EvirTurningAround();
            break;

        case 5:
            EvirTurningAroundSecondPart();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteUtilUnfreezeSecondarySprites(SSPRITE_EVIR_COLLISION, gCurrentSprite.primarySpriteRamSlot);
            SpriteDyingInit();
        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            EvirInit();
        case SPRITE_POSE_SPAWNING_FROM_X:
            EvirSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            EvirTurningIntoX();
            XParasiteInit();
            break;
    }
}

void EvirCollision(void)
{
    if (SPRITE_GET_ISFT(gSpriteData[gCurrentSprite.primarySpriteRamSlot]) < SPRITE_GET_ISFT(gCurrentSprite))
    {
        SPRITE_CLEAR_AND_SET_ISFT(gSpriteData[gCurrentSprite.primarySpriteRamSlot],
            (gCurrentSprite.invincibilityStunFlashTimer + 1) & 0x7f);
    }

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdatePrimarySpriteFreezeTimerOfCurrent();
    }
    else
    {
        switch (gCurrentSprite.pose)
        {
            case 0:
                EvirCollisionInit();
            default:
                EvirCollisionIdle();
                break;
        }
    }
}

void EvirProjectile(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            EvirProjectileInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            EvirProjectileMovingInit();
        case SPRITE_POSE_IDLE:
            EvirProjectileMoving();
            break;

        case 0x38:
            EvirProjectileExploding();
            break;

        default:
            EvirProjectileExplodingInit();
            break;
    }
}
