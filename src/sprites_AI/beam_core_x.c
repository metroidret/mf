#include "data/sprites/beam_core_x.h"

#include "globals.h"
#include "macros.h"
#include "sprite_util.h"

#include "data/generic_data.h"
#include "data/projectile_data.h"
#include "data/sprite_data.h"
#include "data/sprites/core_x.h"
#include "data/sprites/message_banner.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/samus.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

void BeamCoreXTransformation(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (--gCurrentSprite.workY > 0)
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    }
    else
    {
        gCurrentSprite.pose = 0x1b;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
        ProjectileLoadEyeCoreXGraphics();
    }
}

void BeamCoreXTransformationInit(void)
{
    u8 shell;
    u8 eye;
    u8 eyeSlot;

    shell = 0;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1.4375f);
    gCurrentSprite.pose = 0x5a;
    gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_SAMUS_COLLIDING);
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.bgPriority = 2;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.pOam = sBeamCoreXAbilityOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.work0 = FALSE;

    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_CHARGE_BEAM_CORE_X:
            shell = SSPRITE_CHARGE_BEAM_CORE_X_SHELL;
            eye = SSPRITE_CHARGE_BEAM_CORE_X_EYE;
            break;

        case PSPRITE_WIDE_BEAM_CORE_X:
            shell = SSPRITE_WIDE_BEAM_CORE_X_SHELL;
            eye = SSPRITE_WIDE_BEAM_CORE_X_EYE;
            break;

        case PSPRITE_PLASMA_BEAM_CORE_X:
            shell = SSPRITE_PLASMA_BEAM_CORE_X_SHELL;
            eye = SSPRITE_PLASMA_BEAM_CORE_X_EYE;
            break;

        case PSPRITE_WAVE_BEAM_CORE_X:
            shell = SSPRITE_WAVE_BEAM_CORE_X_SHELL;
            eye = SSPRITE_WAVE_BEAM_CORE_X_EYE;
            break;

        case PSPRITE_ICE_BEAM_CORE_X:
            shell = SSPRITE_ICE_BEAM_CORE_X_SHELL;
            eye = SSPRITE_ICE_BEAM_CORE_X_EYE;
            gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
            break;

        default:
            gCurrentSprite.status = 0;
            return;
    }

    // Needed to produce matching ASM
    shell++; shell--;

    shell = SpriteSpawnSecondary(shell, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    if (shell == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
        return;
    }

    eyeSlot = SpriteSpawnSecondary(eye, shell, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    if (eyeSlot == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gSpriteData[shell].roomSlot = eyeSlot;
}

void BeamCoreXMovingInit(void)
{
    gCurrentSprite.pose = 0x1c;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 1;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 1;
}

void BeamCoreXMoving(void)
{
    if (!gCurrentSprite.work0)
    {
        SpriteUtilMoveBeamCoreX((u16)(gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.125f)), gSamusData.xPosition, 0xa,
            0x10, 2, 0xc0);
    }
}

void BeamCoreXMovingToTargetInit(void)
{
    gCurrentSprite.pose = 0x5d;
    gCurrentSprite.samusCollision = SSC_CORE_X_ABILITY;
    gCurrentSprite.health = 0;
    gCurrentSprite.drawOrder = 4;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 1;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 1;
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    CoreXMakeXParasitesFlee();
}

void BeamCoreXMovingToTarget(void)
{
    if (MOD_AND(gFrameCounter8Bit, 4) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    XParasiteMoveWithSound(gAbilityRestingYPosition, gAbilityRestingXPosition, 0x10, 0x18, 2, SOUND_X_PARASITE_MOVING);

    if (gCurrentSprite.yPosition < gAbilityRestingYPosition + BLOCK_TO_SUB_PIXEL(0.09375f) &&
        gCurrentSprite.yPosition > gAbilityRestingYPosition - BLOCK_TO_SUB_PIXEL(0.09375f))
    {
        if (gCurrentSprite.xPosition < gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(0.09375f) &&
            gCurrentSprite.xPosition > gAbilityRestingXPosition - BLOCK_TO_SUB_PIXEL(0.09375f))
        {
            if (gCurrentSprite.spriteId == PSPRITE_ICE_BEAM_CORE_X)
                gCurrentSprite.pose = 0x37;
            else
                gCurrentSprite.pose = 0x5e;

            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.work3 = 0;
            gCurrentSprite.work4 = 0;
        }
    }
}

void BeamCoreXRestingAtTarget(void)
{
    u8 offset;
    s16 movement;

    offset = gCurrentSprite.work4;
    movement = sCoreXIdleYSpeed[offset];

    if (movement == SHORT_MAX)
    {
        movement = sCoreXIdleYSpeed[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work4 = offset;
    gCurrentSprite.yPosition += movement;

    offset = gCurrentSprite.work3;
    movement = sCoreXIdleXSpeed[offset];

    if (movement == SHORT_MAX)
    {
        movement = sCoreXIdleXSpeed[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work3 = offset;
    gCurrentSprite.xPosition += movement;

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gPreventMovementTimer = SAMUS_ITEM_PMT;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.pose = 0x5f;
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
        gCurrentSprite.work2 = 0;
        gCurrentSprite.work3 = 1;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work4 = 1;
        gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
        gCurrentSprite.rotation = 0;
        gCurrentSprite.scaling = Q_8_8(1);
        gCurrentSprite.workY = 20;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sBeamCoreXAbilityOam_GettingAbsorbed;
        ParticleSet(gSamusData.yPosition + gSamusData.drawDistanceTop / 2, gSamusData.xPosition, PE_ABSORB_CORE_X);

        switch (gCurrentSprite.spriteId)
        {
            case PSPRITE_CHARGE_BEAM_CORE_X:
                EventCheckAdvance(EVENT_CHARGE_BEAM_ABILITY_RECOVERED);
                break;

            case PSPRITE_WIDE_BEAM_CORE_X:
                EventCheckAdvance(EVENT_WIDE_BEAM_ABILITY_RECOVERED);
                break;

            case PSPRITE_PLASMA_BEAM_CORE_X:
                EventCheckAdvance(EVENT_PLASMA_BEAM_ABILITY_RECOVERED);
                break;

            case PSPRITE_WAVE_BEAM_CORE_X:
                EventCheckAdvance(EVENT_WAVE_BEAM_ABILITY_RECOVERED);
                break;
        }

        SpriteUtilRefillSamus(400, 50, 10);
        gSamusEnvironmentalEffects[0].externalTimer = 48;
        SoundPlay(SOUND_X_PARASITE_GETTING_ABSORBED);
    }
    else if (MOD_AND(gFrameCounter8Bit, 64) == 0)
    {
        SoundPlay(SOUND_CORE_X_AURA);
    }
}

void BeamCoreXAbsorbed(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    XParasiteStickToSamus();

    if (gCurrentSprite.workY != 0)
    {
        gCurrentSprite.workY--;
    }
    else if (gCurrentSprite.scaling > Q_8_8(.3125f))
    {
        gCurrentSprite.scaling -= Q_8_8(.03125f);
    }
    else
    {
        gCurrentSprite.pose = 0x60;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.workY = 9;
    }
}

void BeamCoreXDisplayingMessage(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.workY > 0)
    {
        gCurrentSprite.workY--;
        if (gCurrentSprite.workY < sizeof(sMessageBannerGfx) / 512)
            SpriteLoadGfx(PSPRITE_MESSAGE_BANNER, 0, gCurrentSprite.workY);
        else if (gCurrentSprite.workY == sizeof(sMessageBannerGfx) / 512)
            SpriteLoadPal(PSPRITE_MESSAGE_BANNER, 0, ARRAY_SIZE(sMessageBannerPal) / 16);
    }
    else
    {
        gCurrentSprite.status = 0;
        SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, 0, 0, SSP_UNINFECTED_OR_BOSS, gAbilityRestingYPosition,
            gAbilityRestingXPosition, 0);
    }
}

void BeamCoreXWaitToFlee(void)
{
    if (MOD_AND(gFrameCounter8Bit, 4) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 3, BLOCK_SIZE * 3) != NSLR_OUT_OF_RANGE)
    {
        gCurrentSprite.pose = 0x38;
        gCurrentSprite.work1 = 180;
    }
}

void BeamCoreXFlee(void)
{
    u8 offset;
    s16 movement;

    if (MOD_AND(gFrameCounter8Bit, 4) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    offset = gCurrentSprite.work4;
    movement = sIceBeamAbilityFloatingYMovement[offset];

    if (movement == SHORT_MAX)
    {
        movement = sIceBeamAbilityFloatingYMovement[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work4 = offset;
    gCurrentSprite.yPosition += movement;
    gCurrentSprite.xPosition += 8;
    gCurrentSprite.yPosition += 1;

    if (--gCurrentSprite.work1 == 0)
    {
        EventCheckAdvance(EVENT_SA_X_DEFEATED);
        gCurrentSprite.status = 0;
        unk_372c(60, MUSIC_OPERATIONS_DECK, 10);
    }
}

void BeamCoreXShellInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 4;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
    gCurrentSprite.hitboxTop = -BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
    gCurrentSprite.hitboxRight = BLOCK_SIZE;
    gCurrentSprite.pOam = sBeamCoreXShellOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.pose = 1;
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
    gCurrentSprite.scaling = Q_8_8(1);

    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.rotation = Q_8_8(0.5f);
    else
        gCurrentSprite.rotation = 0;

    if (gCurrentSprite.spriteId == SSPRITE_ICE_BEAM_CORE_X_SHELL)
        gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
}

void BeamCoreXShellTransformation(void)
{
    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose == 0x1b)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = 2;
    }
}

void BeamCoreXShellIdle(void)
{
    u8 tmp;

    if (SPRITE_GET_ISFT(gCurrentSprite) == 1)
    {
        tmp = SpriteUtilCountPrimarySprites(PSPRITE_X_PARASITE_CORE_X_OR_PARASITE);
        if (tmp < 6)
        {
            SpriteSpawnNewXParasite(PSPRITE_X_PARASITE_CORE_X_OR_PARASITE, 0, 0, gCurrentSprite.primarySpriteRamSlot,
                SSP_X_ABSORBABLE_BY_SAMUS, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }
    }

    tmp = gCurrentSprite.roomSlot;
    if (gSpriteData[tmp].paletteRow != 0)
        gCurrentSprite.paletteRow = gSpriteData[tmp].paletteRow + 2;
    else
        gCurrentSprite.paletteRow = 0;
}

void BeamCoreXEyeInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.frozenPaletteRowOffset = 3;
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
    gCurrentSprite.scaling = Q_8_8(1);
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.pOam = sBeamCoreXEyeOam_Closed;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = 1;
    gCurrentSprite.work2 = 120;

    if (gCurrentSprite.xPosition > gSamusData.xPosition)
    {
        gCurrentSprite.rotation = Q_8_8(0.5f);
        gCurrentSprite.work1 = Q_8_8(0.5f);
    }
    else
    {
        gCurrentSprite.rotation = 0;
        gCurrentSprite.work1 = 0;
    }

    if (gCurrentSprite.spriteId == SSPRITE_ICE_BEAM_CORE_X_EYE)
        gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
}

void BeamCoreXEyeTransformation(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[primary].status & SPRITE_STATUS_MOSAIC)
    {
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
        gCurrentSprite.pose = 2;
    }
}

void BeamCoreXEyeHandleRotation(void)
{
#ifndef BUGFIX
    u8 intensity;
    s32 targetRotation;
#endif // !BUGFIX

    u8 primary;
    u8 shellSlot;

    s16 oamRotation;
    s16 targetY;
    s16 targetX;
    s16 spriteY;
    s16 spriteX;

    s16 distance;
    s16 sin;
    s16 cos;
    s16 yOffset;
    s16 xOffset;

#ifndef BUGFIX
    intensity = Q_8_8(1.f / 128);
#endif // !BUGFIX

    primary = gCurrentSprite.primarySpriteRamSlot;
    shellSlot = gCurrentSprite.roomSlot;

    oamRotation = gCurrentSprite.work1;
    targetY = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.125f);
    targetX = gSamusData.xPosition;
    spriteY = gSpriteData[primary].yPosition;
    spriteX = gSpriteData[primary].xPosition;

#ifdef BUGFIX
    oamRotation = SpriteUtilMakeSpriteRotateTowardsTarget(oamRotation, targetY, targetX, spriteY, spriteX);
#else // !BUGFIX
    // OVERSIGHT: This is copied from SpriteUtilMakeSpriteRotateTowardsTarget
    if (targetY < spriteY)
    {
        if (spriteX - BLOCK_SIZE < targetX && spriteX + BLOCK_SIZE > targetX)
        {
            targetRotation = Q_8_8(6.f / 8);
        }
        // BUG: Should be "else if"
        if (targetX > spriteX)
        {
            if (spriteY - targetY < BLOCK_SIZE)
                targetRotation = 0;
            else
                targetRotation = Q_8_8(7.f / 8);
        }
        else if (spriteY - targetY < BLOCK_SIZE)
        {
            targetRotation = Q_8_8(4.f / 8);
        }
        else
        {
            targetRotation = Q_8_8(5.f / 8);
        }
    }
    else
    {
        if (spriteX - BLOCK_SIZE < targetX && spriteX + BLOCK_SIZE > targetX)
        {
            targetRotation = Q_8_8(2.f / 8);
        }
        else if (targetX > spriteX)
        {
            if (targetY - spriteY < BLOCK_SIZE)
                targetRotation = 0;
            else
                targetRotation = Q_8_8(1.f / 8);
        }
        else if (targetY - spriteY < BLOCK_SIZE)
        {
            targetRotation = Q_8_8(4.f / 8);
        }
        else
        {
            targetRotation = Q_8_8(3.f / 8);
        }
    }

    if (targetRotation == 0)
    {
        if ((u16)(oamRotation - 1) < Q_8_8(0.5f) - 1)
            oamRotation -= intensity;
        else if (oamRotation >= Q_8_8(0.5f))
            oamRotation += intensity;
    }
    else if (targetRotation == Q_8_8(1.f / 8))
    {
        if ((u16)(oamRotation - Q_8_8(1.f / 8) - 1) < Q_8_8(0.5f) - 1)
            oamRotation -= intensity;
        else if ((u16)(oamRotation - Q_8_8(1.f / 8)) >= Q_8_8(0.5f))
            oamRotation += intensity;
    }
    else if (targetRotation == Q_8_8(2.f / 8))
    {
        if ((u16)(oamRotation - Q_8_8(2.f / 8) - 1) < Q_8_8(0.5f) - 1)
            oamRotation -= intensity;
        else if ((u16)(oamRotation - Q_8_8(2.f / 8)) >= Q_8_8(0.5f))
            oamRotation += intensity;
    }
    else if (targetRotation == Q_8_8(3.f / 8))
    {
        if ((u16)(oamRotation - Q_8_8(3.f / 8) - 1) < Q_8_8(0.5f) - 1)
            oamRotation -= intensity;
        else if ((u16)(oamRotation - Q_8_8(3.f / 8)) >= Q_8_8(0.5f))
            oamRotation += intensity;
    }
    else if (targetRotation == Q_8_8(4.f / 8))
    {
        if ((u16)(oamRotation - 1) < Q_8_8(0.5f) - 1)
            oamRotation += intensity;
        else if (oamRotation > Q_8_8(0.5f))
            oamRotation -= intensity;
    }
    else if (targetRotation == Q_8_8(5.f / 8))
    {
        if ((u16)(oamRotation - Q_8_8(1.f / 8) - 1) < Q_8_8(0.5f) - 1)
            oamRotation += intensity;
        else if ((u16)(oamRotation - Q_8_8(1.f / 8) - 1) >= Q_8_8(0.5f))
            oamRotation -= intensity;
    }
    else if (targetRotation == Q_8_8(6.f / 8))
    {
        if ((u16)(oamRotation - Q_8_8(2.f / 8) - 1) < Q_8_8(0.5f) - 1)
            oamRotation += intensity;
        else if ((u16)(oamRotation - Q_8_8(2.f / 8) - 1) >= Q_8_8(0.5f))
            oamRotation -= intensity;
    }
    else if (targetRotation == Q_8_8(7.f / 8))
    {
        if ((u16)(oamRotation - Q_8_8(3.f / 8) - 1) < Q_8_8(0.5f) - 1)
            oamRotation += intensity;
        else if ((u16)(oamRotation - Q_8_8(3.f / 8) - 1) >= Q_8_8(0.5f))
            oamRotation -= intensity;
    }
#endif

    gCurrentSprite.work1 = oamRotation;
    gSpriteData[shellSlot].rotation = oamRotation;
    gCurrentSprite.rotation = oamRotation;

    oamRotation &= UCHAR_MAX; // Prevent overflow when indexing sine table
    distance = HALF_BLOCK_SIZE;

    sin = SIN(oamRotation);
    if (sin < 0)
    {
        yOffset = Q_8_8_TO_INT(-sin * distance);
        gCurrentSprite.yPosition = spriteY - yOffset;
    }
    else
    {
        yOffset = Q_8_8_TO_INT(sin * distance);
        gCurrentSprite.yPosition = spriteY + yOffset;
    }

    cos = COS(oamRotation);
    if (cos < 0)
    {
        xOffset = Q_8_8_TO_INT(-cos * distance);
        gCurrentSprite.xPosition = spriteX - xOffset;
    }
    else
    {
        xOffset = Q_8_8_TO_INT(cos * distance);
        gCurrentSprite.xPosition = spriteX + xOffset;
    }

    if (gCurrentSprite.health == 0)
    {
        gCurrentSprite.status = 0;
        gSpriteData[shellSlot].status = 0;
        gSpriteData[primary].pose = 0x5c;
        ParticleSet(gSpriteData[primary].yPosition, gSpriteData[primary].xPosition, PE_0x2F);

        switch (gSpriteData[primary].spriteId)
        {
            case PSPRITE_CHARGE_BEAM_CORE_X:
            case PSPRITE_PLASMA_BEAM_CORE_X:
                PlayMusic(MUSIC_BOSS_TENSION, 6);
                break;

            case PSPRITE_WAVE_BEAM_CORE_X:
                PlayMusic(MUSIC_SECTOR_6, 0);
                break;
        }
    }
}

void BeamCoreXEyeClosed(void)
{
    BeamCoreXEyeHandleRotation();

    if (--gCurrentSprite.work2 == 0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pOam = sBeamCoreXEyeOam_Opening;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x18;
    }
}

void BeamCoreXEyeOpening(void)
{
    BeamCoreXEyeHandleRotation();

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pOam = sBeamCoreXEyeOam_Opened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.work2 = 160;
    }
}

void BeamCoreXEyeOpened(void)
{
    u8 primary;
    u8 beamSpriteId;
    u8 firstBeam;
    u8 secondBeam;
    u8 thirdBeam;

    u16 y;
    u16 x;
    u8 rotation;
    u16 xFlip;
    u8 direction;

    primary = gCurrentSprite.primarySpriteRamSlot;

    if (SPRITE_GET_ISFT(gCurrentSprite) >= 5)
    {
        ParticleSet(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f), gCurrentSprite.xPosition, PE_0x2F);
        gCurrentSprite.work2 = 1;
    }

    BeamCoreXEyeHandleRotation();

    if (gCurrentSprite.work2 == 110)
    {
        gCurrentSprite.pOam = sBeamCoreXEyeOam_Charging1;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
    else if (gCurrentSprite.work2 == 60)
    {
        gCurrentSprite.pOam = sBeamCoreXEyeOam_Charging2;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SpriteSpawnSecondary(SSPRITE_4D, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
            gSpriteData[gCurrentSprite.roomSlot].roomSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
    else if (gCurrentSprite.work2 < 60 && MOD_AND(gCurrentSprite.work2, 4) == 0)
    {
        if (gCurrentSprite.work2 & 4)
            gSpriteData[primary].paletteRow = 2;
        else
            gSpriteData[primary].paletteRow = 0;
    }

    if (--gCurrentSprite.work2 == 0)
    {
        gCurrentSprite.pOam = sBeamCoreXEyeOam_Opened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        if (SPRITE_GET_ISFT(gCurrentSprite) == 5)
        {
            gCurrentSprite.work2 = 1;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        }
        else
        {
            gCurrentSprite.work2 = 30;
        }

        gCurrentSprite.pose = 0x1c;
        gSpriteData[primary].work0++;
        gSpriteData[primary].paletteRow = 0;
        y = gCurrentSprite.yPosition;
        x = gCurrentSprite.xPosition;
        rotation = gCurrentSprite.work1;

        if (rotation < Q_8_8(1.f / 4) || rotation >= Q_8_8(3.f / 4))
            xFlip = SPRITE_STATUS_X_FLIP;
        else
            xFlip = 0;

        if (rotation > Q_8_8(1.f / 16) && rotation <= Q_8_8(3.f / 16))
            direction = ACD_DIAGONAL_DOWN;
        else if (rotation > Q_8_8(3.f / 16) && rotation <= Q_8_8(5.f / 16))
            direction = ACD_DOWN;
        else if (rotation > Q_8_8(5.f / 16) && rotation <= Q_8_8(7.f / 16))
            direction = ACD_DIAGONAL_DOWN;
        else if (rotation > Q_8_8(7.f / 16) && rotation <= Q_8_8(9.f / 16))
            direction = ACD_FORWARD;
        else if (rotation > Q_8_8(9.f / 16) && rotation <= Q_8_8(11.f / 16))
            direction = ACD_DIAGONAL_UP;
        else if (rotation > Q_8_8(11.f / 16) && rotation <= Q_8_8(13.f / 16))
            direction = ACD_UP;
        else if (rotation > Q_8_8(13.f / 16) && rotation <= Q_8_8(15.f / 16))
            direction = ACD_DIAGONAL_UP;
        else
            direction = ACD_FORWARD;

        switch (gSpriteData[primary].spriteId)
        {
            case PSPRITE_CHARGE_BEAM_CORE_X:
                beamSpriteId = SSPRITE_BEAM_CORE_X_CHARGE_BEAM;
                break;

            case PSPRITE_WIDE_BEAM_CORE_X:
                beamSpriteId = SSPRITE_BEAM_CORE_X_WIDE_BEAM;
                break;

            case PSPRITE_PLASMA_BEAM_CORE_X:
                beamSpriteId = SSPRITE_BEAM_CORE_X_PLASMA_BEAM;
                break;

            case PSPRITE_WAVE_BEAM_CORE_X:
                beamSpriteId = SSPRITE_BEAM_CORE_X_WAVE_BEAM;
                break;

            case PSPRITE_ICE_BEAM_CORE_X:
                beamSpriteId = SSPRITE_BEAM_CORE_X_ICE_BEAM;
                break;

            default:
                return;
        }

        firstBeam = SpriteSpawnSecondary(beamSpriteId, 0, 10, primary, y, x, xFlip);
        if (firstBeam == UCHAR_MAX)
            return;
        gSpriteData[firstBeam].work0 = direction;
        gSpriteData[firstBeam].work1 = 0;

        secondBeam = SpriteSpawnSecondary(beamSpriteId, 1, 10, firstBeam, y, x, xFlip);
        if (secondBeam == UCHAR_MAX)
        {
            gSpriteData[firstBeam].status = 0;
            return;
        }
        gSpriteData[secondBeam].work0 = direction;
        gSpriteData[secondBeam].work1 = 0;

        thirdBeam = SpriteSpawnSecondary(beamSpriteId, 2, 10, firstBeam, y, x, xFlip);
        if (thirdBeam == UCHAR_MAX)
        {
            gSpriteData[firstBeam].status = 0;
            gSpriteData[secondBeam].status = 0;
            return;
        }
        gSpriteData[thirdBeam].work0 = direction;
        gSpriteData[thirdBeam].work1 = 0;
    }
}

void BeamCoreXEyeShooting(void)
{
    if (!(gCurrentSprite.status & SPRITE_STATUS_IGNORE_PROJECTILES) && SPRITE_GET_ISFT(gCurrentSprite) >= 5)
    {
        ParticleSet(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f), gCurrentSprite.xPosition, PE_0x2F);
        gCurrentSprite.work2 = 1;
    }

    if (--gCurrentSprite.work2 == 0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pOam = sBeamCoreXEyeOam_Closing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x1e;
        gSpriteData[gCurrentSprite.primarySpriteRamSlot].work0 = FALSE;
    }
}

void BeamCoreXEyeClosing(void)
{
    BeamCoreXEyeHandleRotation();

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = 2;
        gCurrentSprite.work2 = 100;
        gCurrentSprite.pOam = sBeamCoreXEyeOam_Closed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    }
}

void BeamCoreXGlowingInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 2;
    gCurrentSprite.frozenPaletteRowOffset = 3;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.pOam = sBeamCoreXGlowingOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 60;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = 2;

    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].spriteId == SSPRITE_ICE_BEAM_CORE_X_EYE)
        gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
}

void BeamCoreXGlowingIdle(void)
{
    u8 eye;

    eye = gCurrentSprite.primarySpriteRamSlot;

    if (!(gSpriteData[eye].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
    }
    else
    {
        gCurrentSprite.yPosition = gSpriteData[eye].yPosition;
        gCurrentSprite.xPosition = gSpriteData[eye].xPosition;

        if (--gCurrentSprite.work1 == 0)
            gCurrentSprite.status = 0;
    }
}

void BeamCoreX(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x59:
            BeamCoreXTransformationInit();

        case 0x5a:
            BeamCoreXTransformation();
            break;

        case 0x1b:
            BeamCoreXMovingInit();

        case 0x1c:
            BeamCoreXMoving();
            break;

        case 0x5c:
            BeamCoreXMovingToTargetInit();
            break;

        case 0x5d:
            BeamCoreXMovingToTarget();
            break;

        case 0x5e:
            BeamCoreXRestingAtTarget();
            break;

        case 0x5f:
            BeamCoreXAbsorbed();
            break;

        case 0x60:
            BeamCoreXDisplayingMessage();
            break;

        case 0x37:
            BeamCoreXWaitToFlee();
            break;

        case 0x38:
            BeamCoreXFlee();
            break;
    }
}

void BeamCoreXShell(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.yPosition = gSpriteData[primary].yPosition;
    gCurrentSprite.xPosition = gSpriteData[primary].xPosition;

    if (gSpriteData[primary].status & SPRITE_STATUS_MOSAIC)
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;

    switch (gCurrentSprite.pose)
    {
        case 0:
            BeamCoreXShellInit();
            break;

        case 1:
            BeamCoreXShellTransformation();
            break;

        case 2:
            BeamCoreXShellIdle();
            break;
    }
}

void BeamCoreXEye(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            BeamCoreXEyeInit();

        case 1:
            BeamCoreXEyeTransformation();
            break;

        case 2:
            BeamCoreXEyeClosed();
            break;

        case 0x18:
            BeamCoreXEyeOpening();
            break;

        case 0x1a:
            BeamCoreXEyeOpened();
            break;

        case 0x1c:
            BeamCoreXEyeShooting();
            break;

        case 0x1e:
            BeamCoreXEyeClosing();
            break;
    }
}

void BeamCoreXGlowing(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            BeamCoreXGlowingInit();

        case 2:
            BeamCoreXGlowingIdle();
            break;
    }
}

void CoreXChargeBeamInit(void)
{
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.1875f);

    if (gCurrentSprite.roomSlot > 0)
    {
        switch (gCurrentSprite.work0)
        {
            case ACD_DIAGONAL_DOWN:
                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

            case ACD_DIAGONAL_UP:
                gCurrentSprite.pOam = sChargeBeamOam_SingleDiagonal;
                break;

            case ACD_DOWN:
                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

            case ACD_UP:
                gCurrentSprite.pOam = sChargeBeamOam_SingleVertical;
                break;

            case ACD_FORWARD:
            default:
                gCurrentSprite.pOam = sChargeBeamOam_SingleHorizontal;
                break;
        }
    }
    else
    {
        SoundPlay(SOUND_CHARGE_BEAM_FIRE);
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        switch (gCurrentSprite.work0)
        {
            case ACD_DIAGONAL_DOWN:
                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

            case ACD_DIAGONAL_UP:
                gCurrentSprite.pOam = sChargeBeamOam_DoubleDiagonal;
                break;

            case ACD_DOWN:
                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

            case ACD_UP:
                gCurrentSprite.pOam = sChargeBeamOam_DoubleVertical;
                break;

            case ACD_FORWARD:
            default:
                gCurrentSprite.pOam = sChargeBeamOam_DoubleHorizontal;
                break;
        }
    }
}

void CoreXChargeBeam(void)
{
    if (gCurrentSprite.roomSlot != 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN &&
            gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose >= SPRITE_POSE_STOPPED)
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        gCurrentClipdataAffectingAction = CAA_BEAM;
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

        if (gPreviousCollisionCheck != COLLISION_AIR)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN &&
                gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose < SPRITE_POSE_STOPPED)
                gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose = SPRITE_POSE_STOPPED;

            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_CHARGE_BEAM_HIT);
            gCurrentSprite.status = 0;
            return;
        }

        if (gCurrentSprite.pose <= 2)
            SpriteUtilMoveEyeCoreXBeamPart();
    }

    switch (gCurrentSprite.pose)
    {
        case 0:
            CoreXChargeBeamInit();
            gCurrentSprite.pose++;
            break;

        case 1:
            SpriteUtilMoveEyeCoreXBeam(0x10);
            gCurrentSprite.pose++;
            break;

        case 2:
            gCurrentSprite.pose++;

        case 3:
            SpriteUtilMoveEyeCoreXBeam(0x18);
            break;

        case SPRITE_POSE_STOPPED:
            gCurrentSprite.pose++;
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }
}

void CoreXWideBeamInit(void)
{
    SoundPlay(SOUND_WIDE_BEAM_FIRE);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    switch (gCurrentSprite.work0)
    {
        case ACD_DIAGONAL_DOWN:
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            gCurrentSprite.pOam = sWideBeamOam_Diagonal;
            break;

        case ACD_DIAGONAL_UP:
            gCurrentSprite.pOam = sWideBeamOam_Diagonal;
            break;

        case ACD_DOWN:
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

        case ACD_UP:
            gCurrentSprite.pOam = sWideBeamOam_Vertical;
            break;

        case ACD_FORWARD:
        default:
            gCurrentSprite.pOam = sWideBeamOam_Horizontal;
            break;
    }
}

void CoreXWideBeam(void)
{
    if (gCurrentSprite.roomSlot != 0 && gCurrentSprite.pose < 9)
        SpriteUtilMoveEyeCoreXBeamPart();

    gCurrentClipdataAffectingAction = CAA_BEAM;
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck != COLLISION_AIR)
    {
        ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_WIDE_BEAM_HIT);
        gCurrentSprite.status = 0;
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case 0:
            CoreXWideBeamInit();
            gCurrentSprite.pose++;
            break;

        case 1:
            SpriteUtilMoveEyeCoreXBeam(0x10);
            gCurrentSprite.pose++;
            break;

        default:
            if (gCurrentSprite.pose < 9)
                gCurrentSprite.pose++;
            SpriteUtilMoveEyeCoreXBeam(0x18);
            break;
    }
}

void CoreXPlasmaBeaminit(void)
{
    SoundPlay(SOUND_PLASMA_BEAM_FIRE);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.1875f);
    gCurrentSprite.status &= 0xfffb;

    switch (gCurrentSprite.work0)
    {
        case ACD_DIAGONAL_DOWN:
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            gCurrentSprite.pOam = sPlasmaBeamOam_Diagonal;
            break;

        case ACD_DIAGONAL_UP:
            gCurrentSprite.pOam = sPlasmaBeamOam_Diagonal;
            break;

        case ACD_DOWN:
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

        case ACD_UP:
            gCurrentSprite.pOam = sPlasmaBeamOam_Vertical;
            break;

        case ACD_FORWARD:
        default:
            gCurrentSprite.pOam = sPlasmaBeamOam_Horizontal;
            break;
    }
}

void CoreXPlasmaBeam(void)
{
    if (gCurrentSprite.roomSlot != 0 && gCurrentSprite.pose < 9)
        SpriteUtilMoveEyeCoreXBeamPart();

    gCurrentClipdataAffectingAction = CAA_BEAM;
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck != COLLISION_AIR)
    {
        ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_PLASMA_BEAM_HIT);
        gCurrentSprite.status = 0;
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case 0:
            CoreXPlasmaBeaminit();
            gCurrentSprite.pose++;
            break;

        case 1:
            SpriteUtilMoveEyeCoreXBeam(0x10);
            gCurrentSprite.pose++;
            break;

        default:
            if (gCurrentSprite.pose < 9)
                gCurrentSprite.pose++;
            SpriteUtilMoveEyeCoreXBeam(0x18);
            break;
    }
}

void CoreXWaveIceBeamInit(void)
{
    if (gCurrentSprite.spriteId == SSPRITE_BEAM_CORE_X_ICE_BEAM)
        SoundPlay(SOUND_ICE_BEAM_FIRE);
    else
        SoundPlay(SOUND_WAVE_BEAM_FIRE);

    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.drawOrder = 1;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    switch (gCurrentSprite.work0)
    {
        case ACD_DIAGONAL_DOWN:
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            if (gCurrentSprite.spriteId == SSPRITE_BEAM_CORE_X_ICE_BEAM)
                gCurrentSprite.pOam = sIceBeamOam_Diagonal;
            else
                gCurrentSprite.pOam = sWaveBeamOam_Diagonal;
            break;

        case ACD_DIAGONAL_UP:
            if (gCurrentSprite.spriteId == SSPRITE_BEAM_CORE_X_ICE_BEAM)
                gCurrentSprite.pOam = sIceBeamOam_Diagonal;
            else
                gCurrentSprite.pOam = sWaveBeamOam_Diagonal;
            break;

        case ACD_DOWN:
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

        case ACD_UP:
            if (gCurrentSprite.spriteId == SSPRITE_BEAM_CORE_X_ICE_BEAM)
                gCurrentSprite.pOam = sIceBeamOam_Vertical;
            else
                gCurrentSprite.pOam = sWaveBeamOam_Vertical;
            break;

        case ACD_FORWARD:
        default:
            if (gCurrentSprite.spriteId == SSPRITE_BEAM_CORE_X_ICE_BEAM)
                gCurrentSprite.pOam = sIceBeamOam_Horizontal;
            else
                gCurrentSprite.pOam = sWaveBeamOam_Horizontal;
            break;
    }
}

void CoreXWaveIceBeam(void)
{
    if (gCurrentSprite.roomSlot != 0)
        SpriteUtilMoveEyeCoreXWaveBeamPart();

    gCurrentClipdataAffectingAction = CAA_BEAM;
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    switch (gCurrentSprite.pose)
    {
        case 0:
            CoreXWaveIceBeamInit();
            gCurrentSprite.pose++;
            break;

        case 1:
            SpriteUtilMoveEyeCoreXBeam(0x10);
            gCurrentSprite.pose++;
            break;

        default:
            SpriteUtilMoveEyeCoreXBeam(0x18);
            break;
    }

    // Possibly a leftover when converting Samus's wave beam handler to core-X
    gCurrentSprite.work1++;
}
