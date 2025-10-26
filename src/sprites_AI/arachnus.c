#include "sprites_AI/arachnus.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/arachnus.h"
#include "data/sprites/core_x.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_debris.h"

#include "structs/samus.h"
#include "structs/sprite.h"
#include "structs/sprite_debris.h"

void ArachnusSetStandingHitbox(void)
{
    gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-32);
    gCurrentSprite.hitboxBottom = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-8);
        gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(32);
    }
    else
    {
        gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-32);
        gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(8);
    }
}

void ArachnusShootingFireInit(void)
{
    gCurrentSprite.pose = ARACHNUS_POSE_SHOOTING_FIRE;
    gCurrentSprite.pOam = sArachnusOam_ShootingFire;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.status &= ~SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM;
    gCurrentSprite.status ^=
        SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM_ATTACK_TYPE; // Swap attack types when hit by normal beam
    SpriteUtilSetSecondarySpriteOamPointer(sArachnusShellOam_ShootingFire);
}

void ArachnusScreamingInit(void)
{
    gCurrentSprite.pose = ARACHNUS_POSE_SCREAMING;
    gCurrentSprite.pOam = sArachnusOam_Screaming;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-56);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-18);
    gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(18);
    SpriteUtilSetSecondarySpriteOamPointer(sArachnusShellOam_Screaming);

    SoundPlay(SOUND_ARACHNUS_SCREAM);
}

void ArachnusDyingInit(void)
{
    gCurrentSprite.pose = ARACHNUS_POSE_DYING;

    if (gCurrentSprite.pOam != sArachnusOam_Screaming)
    {
        gCurrentSprite.pOam = sArachnusOam_Screaming;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-56);
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-18);
        gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(18);
        SpriteUtilSetSecondarySpriteOamPointer(sArachnusShellOam_Screaming);
    }

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 1;
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    gCurrentSprite.workX = 1;

    SoundPlay(SOUND_ARACHNUS_DYING);
}

void ArachnusRollingInit(void)
{
    u8 shellSpriteSlot;

    gCurrentSprite.pose = ARACHNUS_POSE_ROLLING;
    gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
    ARACHNUS_ROLLING_SPEED_INDEX = 0;
    gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-8);
    gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(8);

    if (gCurrentSprite.status & SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM;
        gCurrentSprite.status ^=
            SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM_ATTACK_TYPE; // Swap attack types when hit by normal beam
    }

    SpriteUtilSetSecondarySpriteOamPointer(sArachnusOam_Curling);
    shellSpriteSlot = ARACHNUS_SHELL_SLOT;
    gSpriteData[shellSpriteSlot].hitboxTop = PIXEL_TO_SUB_PIXEL(-24);
    gSpriteData[shellSpriteSlot].hitboxBottom = 0;
    gSpriteData[shellSpriteSlot].hitboxLeft = PIXEL_TO_SUB_PIXEL(-16);
    gSpriteData[shellSpriteSlot].hitboxRight = PIXEL_TO_SUB_PIXEL(16);

    SoundPlay(SOUND_ARACHNUS_CURL);
}

void ArachnusSlashingInit(void)
{
    gCurrentSprite.pose = ARACHNUS_POSE_SLASHING;
    gCurrentSprite.pOam = sArachnusOam_Slashing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.status &= ~SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM;
    SpriteUtilSetSecondarySpriteOamPointer(sArachnusShellOam_Slashing);

    SoundPlay(SOUND_ARACHNUS_SLASH_WARNING);
}

void ArachnusSlashing(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.currentAnimationFrame < 16)
        {
            gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(40);
        }
        else if (gCurrentSprite.currentAnimationFrame < 18)
        {
            gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(24);
        }
        else if (gCurrentSprite.currentAnimationFrame < 24)
        {
            gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(48);

            if (gCurrentSprite.currentAnimationFrame == 18 && gCurrentSprite.animationDurationCounter == 3)
            {
                SpriteSpawnSecondary(SSPRITE_ARACHNUS_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + PIXEL_TO_SUB_PIXEL(4),
                    gCurrentSprite.xPosition + PIXEL_TO_SUB_PIXEL(35), SPRITE_STATUS_X_FLIP);
                SoundPlay(SOUND_ARACHNUS_SLASH);
            }
        }
        else
        {
            gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(32);
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame < 16)
        {
            gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-40);
        }
        else if (gCurrentSprite.currentAnimationFrame < 18)
        {
            gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-24);
        }
        else if (gCurrentSprite.currentAnimationFrame < 24)
        {
            gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-48);

            if (gCurrentSprite.currentAnimationFrame == 18 && gCurrentSprite.animationDurationCounter == 3)
            {
                SpriteSpawnSecondary(SSPRITE_ARACHNUS_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + PIXEL_TO_SUB_PIXEL(4),
                    gCurrentSprite.xPosition - PIXEL_TO_SUB_PIXEL(35), 0);
                SoundPlay(SOUND_ARACHNUS_SLASH);
            }
        }
        else
        {
            gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-32);
        }
    }
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.pose = ARACHNUS_POSE_WALKING_INIT;
        ARACHNUS_ATTACK_TIMER = 120;
    }
}

void ArachnusRolling(void)
{
    u8 shellSpriteSlot;
    u16 speed;
    u32 hitWall;
    u16 xPosition;
    u16 yPosition;

    shellSpriteSlot = ARACHNUS_SHELL_SLOT;

    if (gSpriteData[shellSpriteSlot].pOam == sArachnusOam_Curling)
    {
        if (SpriteUtilHasAnimationEnded(shellSpriteSlot))
        {
            SpriteUtilSetSecondarySpriteOamPointer(sArachnusOam_Rolling);
            gSpriteData[shellSpriteSlot].status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
            gSpriteData[shellSpriteSlot].rotation = 0;
            gSpriteData[shellSpriteSlot].scaling = Q_8_8(1);
        }
    }
    else
    {
        speed = sArachnusRollingSpeed[DIV_SHIFT(ARACHNUS_ROLLING_SPEED_INDEX, 4)];

        if (ARACHNUS_ROLLING_SPEED_INDEX < ARRAY_SIZE(sArachnusRollingSpeed) * 4 - 1)
            ARACHNUS_ROLLING_SPEED_INDEX++;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gSpriteData[shellSpriteSlot].yPosition - PIXEL_TO_SUB_PIXEL(18),
                gSpriteData[shellSpriteSlot].xPosition + gSpriteData[shellSpriteSlot].hitboxRight);

            if (gPreviousCollisionCheck & 0xF)
            {
                hitWall = TRUE;
            }
            else
            {
                gCurrentSprite.xPosition += speed;
                xPosition = gCurrentSprite.xPosition;
                yPosition = gCurrentSprite.yPosition;
                gSpriteData[shellSpriteSlot].xPosition += speed;
                speed = ARACHNUS_ROLLING_SPEED_INDEX / 2;

                if (speed > Q_8_8(0.0625f))
                    speed = Q_8_8(0.0625f);

                gSpriteData[shellSpriteSlot].rotation += speed;

                if (gSpriteRandomNumber > 12)
                {
                    if (MOD_AND(gSpriteRandomNumber, 2) != 0)
                    {
                        SpriteDebrisInit(0, DEBRIS_TYPE_HOPPING_FAST_LEFT, yPosition - PIXEL_TO_SUB_PIXEL(4),
                            xPosition + MOD_AND(gFrameCounter8Bit, HALF_BLOCK_SIZE));
                    }
                    else
                    {
                        SpriteDebrisInit(0, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_LEFT, yPosition,
                            xPosition + MOD_AND(gFrameCounter8Bit, HALF_BLOCK_SIZE));
                    }
                }

                // BUG: hitWall uninitialized
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gSpriteData[shellSpriteSlot].yPosition - PIXEL_TO_SUB_PIXEL(18),
                gSpriteData[shellSpriteSlot].xPosition + gSpriteData[shellSpriteSlot].hitboxLeft);

            if (gPreviousCollisionCheck & 0xF)
            {
                hitWall = TRUE;
            }
            else
            {
                gCurrentSprite.xPosition -= speed;
                xPosition = gCurrentSprite.xPosition;
                yPosition = gCurrentSprite.yPosition;
                gSpriteData[shellSpriteSlot].xPosition -= speed;
                speed = ARACHNUS_ROLLING_SPEED_INDEX / 2;

                if (speed > Q_8_8(0.0625f))
                    speed = Q_8_8(0.0625f);

                gSpriteData[shellSpriteSlot].rotation -= speed;

                if (gSpriteRandomNumber > 12)
                {
                    if (MOD_AND(gSpriteRandomNumber, 2) != 0)
                    {
                        SpriteDebrisInit(0, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_FAST_RIGHT,
                            yPosition - PIXEL_TO_SUB_PIXEL(4), xPosition - MOD_AND(gFrameCounter8Bit, HALF_BLOCK_SIZE));
                    }
                    else
                    {
                        SpriteDebrisInit(0, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_RIGHT, yPosition,
                            xPosition - MOD_AND(gFrameCounter8Bit, HALF_BLOCK_SIZE));
                    }
                }

                hitWall = FALSE;
            }
        }

        if (hitWall)
        {
            gCurrentSprite.pose = ARACHNUS_POSE_BONKING;
            ARACHNUS_FALLING_SPEED_INDEX = 0;
            ScreenShakeStartHorizontal(40, 0x81);
            SoundPlay(SOUND_ARACHNUS_BONK);
        }
        else if (MOD_AND(gFrameCounter8Bit, 16) == 0)
        {
            SoundPlay(SOUND_ARACHNUS_ROLLING);
        }
    }
}

void ArachnusBonking(void)
{
    u8 shellSpriteSlot;
    u8 offset;
    u16 movement;
    u16 xSpeed;

    shellSpriteSlot = ARACHNUS_SHELL_SLOT;

    if (gSpriteData[shellSpriteSlot].pOam == sArachnusOam_Uncurling)
    {
        if (SpriteUtilHasAnimationNearlyEnded(shellSpriteSlot))
        {
            gCurrentSprite.pose = ARACHNUS_POSE_IDLE_INIT;
            ARACHNUS_ATTACK_TIMER = UCHAR_MAX; // End of bonk
        }
    }
    else
    {
        offset = ARACHNUS_FALLING_SPEED_INDEX;
        movement = sArachnusBonkingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sArachnusBonkingSpeed[offset - 1];
        }
        else
        {
            offset++;
            ARACHNUS_FALLING_SPEED_INDEX = offset;
        }

        gCurrentSprite.yPosition += movement;
        gSpriteData[shellSpriteSlot].yPosition += movement;

        if (ARACHNUS_FALLING_SPEED_INDEX < 12)
            xSpeed = PIXEL_TO_SUB_PIXEL(2);
        else if (ARACHNUS_FALLING_SPEED_INDEX <= 20)
            xSpeed = PIXEL_TO_SUB_PIXEL(1);
        else
            xSpeed = 0;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.xPosition -= xSpeed;
            gSpriteData[shellSpriteSlot].xPosition -= xSpeed;
            gSpriteData[shellSpriteSlot].rotation -= xSpeed / 2;
        }
        else
        {
            gCurrentSprite.xPosition += xSpeed;
            gSpriteData[shellSpriteSlot].xPosition += xSpeed;
            gSpriteData[shellSpriteSlot].rotation += xSpeed / 2;
        }

        if (ARACHNUS_FALLING_SPEED_INDEX == 0x22)
        {
            SpriteUtilSetSecondarySpriteOamPointer(sArachnusOam_Uncurling);
            gSpriteData[shellSpriteSlot].status &= ~SPRITE_STATUS_ROTATION_SCALING_SINGLE;
            SoundPlay(SOUND_ARACHNUS_UNCURL);
        }
    }
}

void ArachnusScreaming(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        // Retaliate after screaming
        if (SpriteUtilCountSecondarySprites(SSPRITE_ARACHNUS_FIRE_BALL) != 0)
        {
            if (gSpriteRandomNumber < 8)
                ArachnusSlashingInit();
            else
                ArachnusRollingInit();
        }
        else
        {
            if (gSpriteRandomNumber > 10)
                ArachnusSlashingInit();
            else if (gSpriteRandomNumber > 6)
                ArachnusRollingInit();
            else
                ArachnusShootingFireInit();
        }
    }
}

void ArachnusDying(void)
{
    u16 x;
    u16 y;

    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    gCurrentSprite.workY--;
    y = gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(40);
    x = gCurrentSprite.xPosition;

    if (gCurrentSprite.workX != 0)
    {
        switch (gCurrentSprite.workY)
        {
            case 40:
                ParticleSet(y - PIXEL_TO_SUB_PIXEL(4), x, PE_0x25);
                ParticleSet(y + PIXEL_TO_SUB_PIXEL(4), x, PE_0x26);
                return;

            case 30:
                ParticleSet(y - PIXEL_TO_SUB_PIXEL(8), x + PIXEL_TO_SUB_PIXEL(7), PE_0x25);
                return;

            case 20:
                ParticleSet(y + PIXEL_TO_SUB_PIXEL(16), x - PIXEL_TO_SUB_PIXEL(4), PE_0x26);
                return;

            case 10:
                ParticleSet(y - PIXEL_TO_SUB_PIXEL(16), x + PIXEL_TO_SUB_PIXEL(7), PE_0x25);
                return;

            case 0:
                gCurrentSprite.workX = 0;
                gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
                return;
        }
    }
    else
    {
        switch (gCurrentSprite.workY)
        {
            case 40:
                ParticleSet(y - PIXEL_TO_SUB_PIXEL(16), x - PIXEL_TO_SUB_PIXEL(4), PE_0x26);
                ParticleSet(y + PIXEL_TO_SUB_PIXEL(8), x - PIXEL_TO_SUB_PIXEL(4), PE_0x25);
                break;

            case 30:
                ParticleSet(y - PIXEL_TO_SUB_PIXEL(8), x + PIXEL_TO_SUB_PIXEL(7), PE_0x26);
                ParticleSet(y + PIXEL_TO_SUB_PIXEL(16), x + PIXEL_TO_SUB_PIXEL(8), PE_0x25);
                break;

            case 20:
                ParticleSet(y - PIXEL_TO_SUB_PIXEL(8), x - PIXEL_TO_SUB_PIXEL(4), PE_0x26);
                ParticleSet(y + PIXEL_TO_SUB_PIXEL(16), x - PIXEL_TO_SUB_PIXEL(4), PE_0x25);
                break;

            case 10:
                ParticleSet(y - PIXEL_TO_SUB_PIXEL(16), x + PIXEL_TO_SUB_PIXEL(7), PE_0x26);
                ParticleSet(y + PIXEL_TO_SUB_PIXEL(8), x + PIXEL_TO_SUB_PIXEL(8), PE_0x25);
                break;

            case 0:
                gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
                gCurrentSprite.spriteId = gCoreXFormationSpriteId;
                break;
        }

        if (gCurrentSprite.workY < sizeof(sMorphBallCoreXGfx) / 512)
            SpriteLoadGfx(gCoreXFormationSpriteId, 0, gCurrentSprite.workY);
        else if (gCurrentSprite.workY == sizeof(sMorphBallCoreXGfx) / 512)
            SpriteLoadPal(gCoreXFormationSpriteId, 0, ARRAY_SIZE(sMorphBallCoreXPal) / 16);
    }
}

void ArachnusShootingFire(void)
{
    if (gCurrentSprite.currentAnimationFrame == 3 && gCurrentSprite.animationDurationCounter == 1)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteSpawnSecondary(SSPRITE_ARACHNUS_FIRE_BALL, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(32),
                gCurrentSprite.xPosition + PIXEL_TO_SUB_PIXEL(16), SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ARACHNUS_FIRE_BALL, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(32),
                gCurrentSprite.xPosition - PIXEL_TO_SUB_PIXEL(16), 0);
        }

        SoundPlay(SOUND_ARACHNUS_SHOOT_FIRE);
    }

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        gCurrentSprite.pose = ARACHNUS_POSE_WALKING_INIT;
        ARACHNUS_ATTACK_TIMER = 120;
    }
}

void ArachnusDetermineAttack(void)
{
    if (ARACHNUS_ATTACK_TIMER > 0)
    {
        if (ARACHNUS_ATTACK_TIMER == UCHAR_MAX)
        {
            // Bonk ended
            ArachnusSlashingInit();
        }
        ARACHNUS_ATTACK_TIMER--;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM)
        {
            // Hit by normal beam
            if (SpriteUtilCountSecondarySprites(SSPRITE_ARACHNUS_FIRE_BALL) == 0 &&
                !(gCurrentSprite.status & SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM_ATTACK_TYPE))
                ArachnusShootingFireInit();
            else
                ArachnusRollingInit();
        }
        else
        {
            if (SpriteUtilCheckSamusHangingOnLedge())
                ArachnusRollingInit();
            else if (SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(3), BLOCK_TO_SUB_PIXEL(6),
                         BLOCK_TO_SUB_PIXEL(6)) == NSFB_IN_FRONT)
                ArachnusSlashingInit();
            else if (SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(3), BLOCK_TO_SUB_PIXEL(8),
                         BLOCK_TO_SUB_PIXEL(8)) == NSFB_IN_FRONT)
                ArachnusRollingInit();
        }
    }
}

void ArachnusCoreXTransformation(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.workY--;

    if (gCurrentSprite.workY > 0)
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = ARACHNUS_POSE_IDLE_INIT;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }
}

void ArachnusInit(void)
{
    u8 ramSlot;

    gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTop = 64;
    gCurrentSprite.drawDistanceBottom = 0;
    gCurrentSprite.drawDistanceHorizontal = 64;
    ARACHNUS_ATTACK_TIMER = 100;

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.yPosition += PIXEL_TO_SUB_PIXEL(25);
        gCurrentSprite.bgPriority = 2;
        gCurrentSprite.drawOrder = 4;
        gCurrentSprite.status &=
            ~(SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM | SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM_ATTACK_TYPE);
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        gCurrentSprite.pose = ARACHNUS_POSE_IDLE;
    }

    gCurrentSprite.pOam = sArachnusOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    ArachnusSetStandingHitbox();

    ramSlot = SpriteSpawnSecondary(SSPRITE_ARACHNUS_SHELL, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);

    if (ramSlot == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
        return;
    }

    ARACHNUS_SHELL_SLOT = ramSlot;
    ramSlot = SpriteSpawnSecondary(SSPRITE_ARACHNUS_HEAD, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);

    if (ramSlot == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
        return;
    }

    ramSlot = SpriteSpawnSecondary(SSPRITE_ARACHNUS_LEFT_ARM, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);

    if (ramSlot == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
        return;
    }

    ramSlot = SpriteSpawnSecondary(SSPRITE_ARACHNUS_RIGHT_ARM, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);

    if (ramSlot == UCHAR_MAX)
    {
        gCurrentSprite.status = 0;
    }
}

void ArachnusWalkingInit(void)
{
    gCurrentSprite.pose = ARACHNUS_POSE_WALKING;
    gCurrentSprite.pOam = sArachnusOam_Walking;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    ArachnusSetStandingHitbox();
    SpriteUtilSetSecondarySpriteOamPointer(sArachnusShellOam_Walking);
}

void ArachnusWalking(void)
{
    u32 turn;
    u16 movement;

    turn = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);

        if ((gPreviousCollisionCheck & 0xF0) == 0)
        {
            // On ledge
            turn = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(18),
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);

            if ((gPreviousCollisionCheck & 0xF) != 0)
            {
                // Hit wall
                turn = TRUE;
            }
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);

        if ((gPreviousCollisionCheck & 0xF0) == 0)
        {
            turn = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(18),
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);

            if ((gPreviousCollisionCheck & 0xF) != 0)
            {
                turn = TRUE;
            }
        }
    }

    if (turn)
    {
        gCurrentSprite.pose = ARACHNUS_POSE_IDLE_INIT;
    }
    else
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0:
                movement = PIXEL_TO_SUB_PIXEL(0.25f);
                if (gCurrentSprite.animationDurationCounter == 9)
                {
                    SoundPlay(SOUND_ARACHNUS_WALK);
                }
                break;

            case 1:
                movement = PIXEL_TO_SUB_PIXEL(0.5f);
                break;

            case 2:
                movement = PIXEL_TO_SUB_PIXEL(0.75f);
                break;

            case 3:
                movement = PIXEL_TO_SUB_PIXEL(0.5f);
                break;

            default:
                movement = 0;
                break;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.xPosition += movement;
            gSpriteData[ARACHNUS_SHELL_SLOT].xPosition += movement;
        }
        else
        {
            gCurrentSprite.xPosition -= movement;
            gSpriteData[ARACHNUS_SHELL_SLOT].xPosition -= movement;
        }
    }

    ArachnusDetermineAttack();
}

void ArachnusIdleInit(void)
{
    u8 shellSpriteSlot;

    shellSpriteSlot = ARACHNUS_SHELL_SLOT;

    if (ARACHNUS_ATTACK_TIMER == UCHAR_MAX)
    {
        // Bonk ended
        gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
        gSpriteData[shellSpriteSlot].status &= ~SPRITE_STATUS_ROTATION_SCALING_SINGLE;
        gSpriteData[shellSpriteSlot].hitboxTop = PIXEL_TO_SUB_PIXEL(-40);
        gSpriteData[shellSpriteSlot].hitboxBottom = 0;

        if (gSpriteData[shellSpriteSlot].status & SPRITE_STATUS_X_FLIP)
        {
            gSpriteData[shellSpriteSlot].hitboxLeft = PIXEL_TO_SUB_PIXEL(-20);
            gSpriteData[shellSpriteSlot].hitboxRight = 0;
        }
        else
        {
            gSpriteData[shellSpriteSlot].hitboxLeft = 0;
            gSpriteData[shellSpriteSlot].hitboxRight = PIXEL_TO_SUB_PIXEL(20);
        }
    }

    gCurrentSprite.pose = ARACHNUS_POSE_IDLE;
    gCurrentSprite.pOam = sArachnusOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    ArachnusSetStandingHitbox();
    SpriteUtilSetSecondarySpriteOamPointer(sArachnusShellOam_Idle);
}

void ArachnusIdle(void)
{
    u32 newPose;

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gCurrentSprite.xPosition > gSamusData.xPosition)
                newPose = ARACHNUS_POSE_TURNING_INIT;
            else
                newPose = ARACHNUS_POSE_WALKING_INIT;
        }
        else
        {
            if (gCurrentSprite.xPosition < gSamusData.xPosition)
                newPose = ARACHNUS_POSE_TURNING_INIT;
            else
                newPose = ARACHNUS_POSE_WALKING_INIT;
        }
        gCurrentSprite.pose = newPose;
    }
}

void ArachnusTurningInit(void)
{
    gCurrentSprite.pose = ARACHNUS_POSE_TURNING;
    gCurrentSprite.pOam = sArachnusOam_Turning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-8);
    gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(8);
    SpriteUtilSetSecondarySpriteOamPointer(sArachnusShellOam_Turning);
}

void ArachnusTurning(void)
{
    u32 shellSpriteSlot;

    shellSpriteSlot = ARACHNUS_SHELL_SLOT;

    if (gCurrentSprite.animationDurationCounter == 4 && gCurrentSprite.currentAnimationFrame == 2)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
        gSpriteData[shellSpriteSlot].status ^= SPRITE_STATUS_X_FLIP;

        if (gSpriteData[shellSpriteSlot].status & SPRITE_STATUS_X_FLIP)
        {
            gSpriteData[shellSpriteSlot].hitboxLeft = PIXEL_TO_SUB_PIXEL(-20);
            gSpriteData[shellSpriteSlot].hitboxRight = 0;
        }
        else
        {
            gSpriteData[shellSpriteSlot].hitboxLeft = 0;
            gSpriteData[shellSpriteSlot].hitboxRight = PIXEL_TO_SUB_PIXEL(20);
        }
    }

    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = ARACHNUS_POSE_WALKING_INIT;
}

void Arachnus(void)
{
    if (gCurrentSprite.pose != SPRITE_POSE_UNINITIALIZED)
    {
        if (gCurrentSprite.health > 0)
        {
            if (SPRITE_GET_ISFT(gCurrentSprite) >= 6)
            {
                // Hit by any weapon dealing greater damage than a normal beam
                if ((gCurrentSprite.pose == ARACHNUS_POSE_WALKING || gCurrentSprite.pose == ARACHNUS_POSE_IDLE) &&
                    gCurrentSprite.pose != ARACHNUS_POSE_SCREAMING)
                {
                    ArachnusScreamingInit();
                }
            }
            else if (SPRITE_GET_ISFT(gCurrentSprite) >= 3)
            {
                // Hit by any weapon dealing less or equal damage than a normal beam
                gCurrentSprite.status |= SPRITE_STATUS_ARACHNUS_HIT_BY_NORMAL_BEAM;

                if (ARACHNUS_ATTACK_TIMER != UCHAR_MAX)
                    ARACHNUS_ATTACK_TIMER = 0;
            }
        }
        else
        {
            ArachnusDyingInit();
        }
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            ArachnusInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            ArachnusCoreXTransformation();
            break;

        case SPRITE_POSE_UNINITIALIZED:
            ArachnusInit();
            break;

        case ARACHNUS_POSE_WALKING_INIT:
            ArachnusWalkingInit();

        case ARACHNUS_POSE_WALKING:
            ArachnusWalking();
            break;

        case ARACHNUS_POSE_IDLE_INIT:
            ArachnusIdleInit();

        case ARACHNUS_POSE_IDLE:
            ArachnusIdle();
            break;

        case ARACHNUS_POSE_TURNING_INIT:
            ArachnusTurningInit();

        case ARACHNUS_POSE_TURNING:
            ArachnusTurning();
            break;

        case ARACHNUS_POSE_SLASHING:
            ArachnusSlashing();
            break;

        case ARACHNUS_POSE_ROLLING:
            ArachnusRolling();
            break;

        case ARACHNUS_POSE_BONKING:
            ArachnusBonking();
            break;

        case ARACHNUS_POSE_SCREAMING:
            ArachnusScreaming();
            break;

        case ARACHNUS_POSE_SHOOTING_FIRE:
            ArachnusShootingFire();
            break;

        case ARACHNUS_POSE_DYING:
            ArachnusDying();
            break;
    }
}

void ArachnusShell(void)
{
    u8 arachnusRamSlot;

    arachnusRamSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status = gCurrentSprite.status & ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.drawOrder = 5;
        gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.drawDistanceTop = 48;
        gCurrentSprite.drawDistanceBottom = 0;
        gCurrentSprite.drawDistanceHorizontal = 24;
        gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-40);
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.pOam = sArachnusShellOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-20);
            gCurrentSprite.hitboxRight = 0;
        }
        else
        {
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(20);
        }
    }

    if (gSpriteData[arachnusRamSlot].pose == ARACHNUS_POSE_WALKING && SPRITE_GET_ISFT(gCurrentSprite) > 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gCurrentSprite.xPosition > gSamusData.xPosition)
            {
                // Oversight: could use arachnusRamSlot instead of gCurrentSprite.primarySpriteRamSlot
                gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose = ARACHNUS_POSE_IDLE_INIT;
            }
        }
        else
        {
            if (gCurrentSprite.xPosition < gSamusData.xPosition)
            {
                gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose = ARACHNUS_POSE_IDLE_INIT;
            }
        }
    }

    if (gSpriteData[arachnusRamSlot].status & SPRITE_STATUS_MOSAIC)
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;

    if (gSpriteData[arachnusRamSlot].pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
        gCurrentSprite.status = 0;
}

void ArachnusPart(void)
{
    u8 arachnusRamSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    arachnusRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gSpriteData[arachnusRamSlot].pose)
    {
        case ARACHNUS_POSE_WALKING:
            break;

        case ARACHNUS_POSE_WALKING_INIT:
            gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

        case ARACHNUS_POSE_IDLE_INIT:
            break;

        default:
            gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
            break;
    }

    gCurrentSprite.yPosition = gSpriteData[arachnusRamSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[arachnusRamSlot].xPosition;
    gCurrentSprite.paletteRow = gSpriteData[arachnusRamSlot].paletteRow;

    if (gSpriteData[arachnusRamSlot].status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

    if (gSpriteData[arachnusRamSlot].pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
        gCurrentSprite.status = 0;
}

void ArachnusHead(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.drawOrder = 3;
        gCurrentSprite.drawDistanceTop = 48;
        gCurrentSprite.drawDistanceBottom = 0;
        gCurrentSprite.drawDistanceHorizontal = 32;
        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;
        gCurrentSprite.pOam = sArachnusHeadOam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
    }

    ArachnusPart();
}

void ArachnusArm1(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.drawOrder = 4;
        gCurrentSprite.drawDistanceTop = 32;
        gCurrentSprite.drawDistanceBottom = 0;
        gCurrentSprite.drawDistanceHorizontal = 40;
        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;
        gCurrentSprite.pOam = sArachnusArm1Oam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
    }

    ArachnusPart();
}

void ArachnusArm2(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.drawOrder = 2;
        gCurrentSprite.drawDistanceTop = 32;
        gCurrentSprite.drawDistanceBottom = 0;
        gCurrentSprite.drawDistanceHorizontal = 40;
        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;
        gCurrentSprite.pOam = sArachnusArm2Oam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
    }

    ArachnusPart();
}

void ArachnusFire(void)
{
    u8 arachnusRamSlot;

    arachnusRamSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[arachnusRamSlot].pose == ARACHNUS_POSE_DYING &&
        gCurrentSprite.pose != ARACHNUS_PROJECTILE_POSE_ARACHNUS_DYING)
    {
        gCurrentSprite.pose = ARACHNUS_PROJECTILE_POSE_ARACHNUS_DYING;
        ARACHNUS_PROJECTILE_TIMER = 40;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawOrder = 2;
            gCurrentSprite.drawDistanceTop = 40;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 8;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-6);
            gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(6);
            ARACHNUS_PROJECTILE_TIMER = 0;

            if (gCurrentSprite.roomSlot == 0)
            {
                gCurrentSprite.pOam = sArachnusFireballOam;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
                gCurrentSprite.pose = ARACHNUS_FIRE_POSE_FIREBALL;
                gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-12);
            }
            else
            {
                gCurrentSprite.pOam = sArachnusFireTrailOam_Short;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
                gCurrentSprite.pose = ARACHNUS_FIRE_POSE_FIRE_TRAIL_1;
                gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-16);
                SoundPlay(SOUND_ARACHNUS_FIRE_BURNING);
            }
            break;

        case ARACHNUS_FIRE_POSE_FIREBALL:
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

            if (gPreviousCollisionCheck != 0)
            {
                gCurrentSprite.pose = ARACHNUS_FIRE_POSE_FIRE_TRAIL_1;
                gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
                gCurrentSprite.pOam = sArachnusFireTrailOam_Short;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-16);
                SoundPlay(SOUND_ARACHNUS_FIRE_BURNING);
            }
            else
            {
                gCurrentSprite.yPosition += PIXEL_TO_SUB_PIXEL(1.25f);
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                    gCurrentSprite.xPosition += PIXEL_TO_SUB_PIXEL(1.5f);
                else
                    gCurrentSprite.xPosition -= PIXEL_TO_SUB_PIXEL(1.5f);
            }
            break;

        case ARACHNUS_FIRE_POSE_FIRE_TRAIL_1:
            if (++ARACHNUS_PROJECTILE_TIMER == 8 && gCurrentSprite.roomSlot < 7)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    SpriteSpawnSecondary(SSPRITE_ARACHNUS_FIRE_BALL, gCurrentSprite.roomSlot + 1,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(.875f), SPRITE_STATUS_X_FLIP);
                }
                else
                {
                    SpriteSpawnSecondary(SSPRITE_ARACHNUS_FIRE_BALL, gCurrentSprite.roomSlot + 1,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(.875f), 0);
                }
            }

            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pose = ARACHNUS_FIRE_POSE_FIRE_TRAIL_2;
                gCurrentSprite.pOam = sArachnusFireTrailOam_Medium;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-24);
            }
            break;

        case ARACHNUS_FIRE_POSE_FIRE_TRAIL_2:
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pose = ARACHNUS_FIRE_POSE_FIRE_TRAIL_3;
                gCurrentSprite.pOam = sArachnusFireTrailOam_Tall;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-32);
            }
            break;

        case ARACHNUS_FIRE_POSE_FIRE_TRAIL_3:
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pose = ARACHNUS_FIRE_POSE_FIRE_TRAIL_4;
                gCurrentSprite.pOam = sArachnusFireTrailOam_Medium;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-24);
            }
            break;

        case ARACHNUS_FIRE_POSE_FIRE_TRAIL_4:
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pose = ARACHNUS_FIRE_POSE_FIRE_TRAIL_DYING;
                gCurrentSprite.pOam = sArachnusFireTrailOam_Short;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-16);
            }
            break;

        case ARACHNUS_FIRE_POSE_FIRE_TRAIL_DYING:
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.status = 0;
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x25);
            }
            break;

        case ARACHNUS_PROJECTILE_POSE_ARACHNUS_DYING:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;

            if ((gFrameCounter8Bit & 1) == 0)
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

            if (--ARACHNUS_PROJECTILE_TIMER == 0)
                gCurrentSprite.status = 0;

            break;

        case SPRITE_POSE_STOPPED: {
            gCurrentSprite.status = 0;
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x25);
            break;
        }
    }
}

void ArachnusSlash(void)
{
    u8 ramSlot;

    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose == ARACHNUS_POSE_DYING &&
        gCurrentSprite.pose != ARACHNUS_PROJECTILE_POSE_ARACHNUS_DYING)
    {
        gCurrentSprite.pose = ARACHNUS_PROJECTILE_POSE_ARACHNUS_DYING;
        ARACHNUS_PROJECTILE_TIMER = 40;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.drawDistanceTop = 48;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 56;
            gCurrentSprite.hitboxTop = PIXEL_TO_SUB_PIXEL(-48);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = PIXEL_TO_SUB_PIXEL(-8);
            gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(8);
            gCurrentSprite.pOam = sArachnusSlashOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.pose = ARACHNUS_SLASH_POSE_MOVING;

            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                ramSlot = SpriteSpawnSecondary(SSPRITE_ARACHNUS_BEAM_TRAIL, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(3),
                    gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);
            }
            else
            {
                ramSlot = SpriteSpawnSecondary(SSPRITE_ARACHNUS_BEAM_TRAIL, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(3),
                    gCurrentSprite.xPosition, 0);
            }

            if (ramSlot == UCHAR_MAX)
                gCurrentSprite.status = 0;
            else
                ARACHNUS_SLASH_TRAIL_SLOT = ramSlot;

            break;

        case ARACHNUS_SLASH_POSE_MOVING:
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(24),
                gCurrentSprite.xPosition);

            if (gPreviousCollisionCheck != 0)
            {
                gCurrentSprite.status = 0;
                gSpriteData[ARACHNUS_SLASH_TRAIL_SLOT].status = 0;
                ParticleSet(gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(24), gCurrentSprite.xPosition, PE_0x25);
                ParticleSet(gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(8), gCurrentSprite.xPosition, PE_0x25);
                ParticleSet(gCurrentSprite.yPosition - PIXEL_TO_SUB_PIXEL(40), gCurrentSprite.xPosition, PE_0x25);
                SoundPlayNotAlreadyPlaying(SOUND_ARACHNUS_SLASH_HIT_WALL);
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                    gCurrentSprite.xPosition += PIXEL_TO_SUB_PIXEL(3);
                else
                    gCurrentSprite.xPosition -= PIXEL_TO_SUB_PIXEL(3);

                gSpriteData[ARACHNUS_SLASH_TRAIL_SLOT].xPosition = gCurrentSprite.xPosition;
            }
            break;

        case ARACHNUS_PROJECTILE_POSE_ARACHNUS_DYING: {
            gCurrentSprite.ignoreSamusCollisionTimer = 1;

            if ((gFrameCounter8Bit & 1) == 0)
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

            if (--ARACHNUS_PROJECTILE_TIMER == 0)
                gCurrentSprite.status = 0;

            break;
        }
    }
}

void ArachnusSlashTrail(void)
{
    if (gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose == ARACHNUS_POSE_DYING)
    {
        gCurrentSprite.status = 0;
    }
    else
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 1;

        if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
        {
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawOrder = 2;
            gCurrentSprite.drawDistanceTop = 32;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 64;
            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;
            gCurrentSprite.pOam = sArachnusSlashTrailOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = SPRITE_POSE_IDLE;
        }
    }
}
