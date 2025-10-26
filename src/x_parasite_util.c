#include "x_parasite_util.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/power_bomb.h"
#include "structs/samus.h"
#include "structs/sprite.h"

u32 CheckSpritesThatCantAbsorbX(void)
{
    u8 i;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (gSpriteData[i].status & SPRITE_STATUS_EXISTS)
        {
            if (gSpriteData[i].pose >= SPRITE_POSE_TURNING_INTO_X && gSpriteData[i].pose <= X_PARASITE_POSE_FLYING)
                return TRUE;

            if (gSpriteData[i].pose <= SPRITE_POSE_SPAWNING_FROM_X && SPRITE_IS_INFECTED(gSpriteData[i]) &&
                !(gSpriteData[i].properties & SP_CAN_ABSORB_X))
                return TRUE;
        }
    }

    return FALSE;
}

u8 CountPrimarySpritesThatCantAbsorbX(void)
{
    u8 count;
    u8 i;

    count = 0;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (gSpriteData[i].status & SPRITE_STATUS_EXISTS)
        {
            if (gSpriteData[i].pose < SPRITE_POSE_TURNING_INTO_X || gSpriteData[i].pose > X_PARASITE_POSE_FLYING)
            {
                if (gSpriteData[i].pose <= SPRITE_POSE_SPAWNING_FROM_X && SPRITE_IS_INFECTED(gSpriteData[i]) &&
                    !(gSpriteData[i].properties & (SP_SECONDARY_SPRITE | SP_CAN_ABSORB_X)))
                    count++;
            }
            else
            {
                count++;
            }
        }
    }

    return count;
}

void XParasiteMove(u16 dstY, u16 dstX, u8 ySpeedCap, u8 xSpeedCap, u8 speedDivisor)
{
    u8 flip;
    u16 velocity;

    flip = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Move right
        if (gCurrentSprite.work2 == 0)
        {
            if (gCurrentSprite.xPosition > dstX - PIXEL_SIZE)
            {
                gCurrentSprite.work2 = gCurrentSprite.work3;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work3 < xSpeedCap)
                    gCurrentSprite.work3++;

                // Apply speed
                gCurrentSprite.xPosition += (gCurrentSprite.work3 >> speedDivisor);
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
                gCurrentSprite.xPosition += (gCurrentSprite.work2 >> speedDivisor);
            else
                flip = TRUE;
        }
    }
    else
    {
        // Move left
        if (gCurrentSprite.work2 == 0)
        {
            if (gCurrentSprite.xPosition < dstX + PIXEL_SIZE)
            {
                gCurrentSprite.work2 = gCurrentSprite.work3;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work3 < xSpeedCap)
                    gCurrentSprite.work3++;

                // Apply speed
                velocity = gCurrentSprite.work3 >> speedDivisor;
                if ((gCurrentSprite.xPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work2 = 0;
                }
                else
                {
                    gCurrentSprite.xPosition -= velocity;
                }
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
            {
                velocity = gCurrentSprite.work2 >> speedDivisor;
                if ((gCurrentSprite.xPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work2 = 0;
                }
                else
                {
                    gCurrentSprite.xPosition -= velocity;
                }
            }
            else
            {
                flip = TRUE;
            }
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.work3 = 1;

        if (++gCurrentSprite.workX >= 4)
            gCurrentSprite.workX = 0;

        SoundPlayNotAlreadyPlaying(SOUND_X_PARASITE_MOVING);

        if (gCurrentSprite.drawOrder == 1)
            gCurrentSprite.drawOrder = 16;
        else
            gCurrentSprite.drawOrder = 1;
    }

    flip = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        // Move down
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.yPosition > dstY - PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work4;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work4 < ySpeedCap)
                    gCurrentSprite.work4++;

                // Apply speed
                gCurrentSprite.yPosition += (gCurrentSprite.work4 >> speedDivisor);
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
                gCurrentSprite.yPosition += (gCurrentSprite.work1 >> speedDivisor);
            else
                flip = TRUE;
        }
    }
    else
    {
        // Move up
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.yPosition < dstY + PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work4;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work4 < ySpeedCap)
                    gCurrentSprite.work4++;

                // Apply speed
                velocity = gCurrentSprite.work4 >> speedDivisor;
                if ((gCurrentSprite.yPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work1 = 0;
                }
                else
                {
                    gCurrentSprite.yPosition -= velocity;
                }
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                velocity = gCurrentSprite.work1 >> speedDivisor;
                if ((gCurrentSprite.yPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work1 = 0;
                }
                else
                {
                    gCurrentSprite.yPosition -= velocity;
                }
            }
            else
            {
                flip = TRUE;
            }
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.work4 = 1;

        SoundPlayNotAlreadyPlaying(SOUND_X_PARASITE_MOVING);
    }
}

void XParasiteMoveWithSound(u16 dstY, u16 dstX, u8 ySpeedCap, u8 xSpeedCap, u8 speedDivisor, u16 sound)
{
    u8 flip;
    u16 velocity;

    flip = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Move right
        if (gCurrentSprite.work2 == 0)
        {
            if (gCurrentSprite.xPosition > dstX - PIXEL_SIZE)
            {
                gCurrentSprite.work2 = gCurrentSprite.work3;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work3 < xSpeedCap)
                    gCurrentSprite.work3++;

                // Apply speed
                gCurrentSprite.xPosition += (gCurrentSprite.work3 >> speedDivisor);
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
                gCurrentSprite.xPosition += (gCurrentSprite.work2 >> speedDivisor);
            else
                flip = TRUE;
        }
    }
    else
    {
        // Move left
        if (gCurrentSprite.work2 == 0)
        {
            if (gCurrentSprite.xPosition < dstX + PIXEL_SIZE)
            {
                gCurrentSprite.work2 = gCurrentSprite.work3;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work3 < xSpeedCap)
                    gCurrentSprite.work3++;

                // Apply speed
                velocity = gCurrentSprite.work3 >> speedDivisor;
                if ((gCurrentSprite.xPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work2 = 0;
                }
                else
                {
                    gCurrentSprite.xPosition -= velocity;
                }
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
            {
                velocity = gCurrentSprite.work2 >> speedDivisor;
                if ((gCurrentSprite.xPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work2 = 0;
                }
                else
                {
                    gCurrentSprite.xPosition -= velocity;
                }
            }
            else
            {
                flip = TRUE;
            }
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.work3 = 1;

        SoundPlayNotAlreadyPlaying(sound);
    }

    flip = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        // Move down
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.yPosition > dstY - PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work4;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work4 < ySpeedCap)
                    gCurrentSprite.work4++;

                // Apply speed
                gCurrentSprite.yPosition += (gCurrentSprite.work4 >> speedDivisor);
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
                gCurrentSprite.yPosition += (gCurrentSprite.work1 >> speedDivisor);
            else
                flip = TRUE;
        }
    }
    else
    {
        // Move up
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.yPosition < dstY + PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work4;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work4 < ySpeedCap)
                    gCurrentSprite.work4++;

                // Apply speed
                velocity = gCurrentSprite.work4 >> speedDivisor;
                if ((gCurrentSprite.yPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work1 = 0;
                }
                else
                {
                    gCurrentSprite.yPosition -= velocity;
                }
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                velocity = gCurrentSprite.work1 >> speedDivisor;
                if ((gCurrentSprite.yPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work1 = 0;
                }
                else
                {
                    gCurrentSprite.yPosition -= velocity;
                }
            }
            else
            {
                flip = TRUE;
            }
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.work4 = 1;

        SoundPlayNotAlreadyPlaying(sound);
    }
}

void SamusAbsorbX(void)
{
    u8 properties;
    u16 energy;
    u16 missiles;
    u16 powerBombs;

    properties = gCurrentSprite.spritesetSlotAndProperties;

    switch (properties & SSP_PROPERTY_MASK)
    {
        case SSP_X_ABSORBABLE_BY_SAMUS:
            if (gCurrentSprite.samusCollision == SSC_RED_X_PARASITE)
            {
                energy = 500;
                missiles = 100;
                powerBombs = 10;
                ParticleSet(gSamusData.yPosition + gSamusData.drawDistanceTop / 2, gSamusData.xPosition,
                    PE_ABSORB_RED_X);
            }
            else if (gCurrentSprite.samusCollision == SSC_GREEN_X_PARASITE)
            {
                energy = 0;
                missiles = 2;
                powerBombs = 0;
                ParticleSet(gSamusData.yPosition + gSamusData.drawDistanceTop / 2, gSamusData.xPosition,
                    PE_ABSORB_MISSILE_X);
            }
            else
            {
                energy = 10;
                missiles = 0;
                powerBombs = 0;
                ParticleSet(gSamusData.yPosition + gSamusData.drawDistanceTop / 2, gSamusData.xPosition,
                    PE_ABSORB_HEALTH_X);
            }

            SpriteUtilRefillSamus(energy, missiles, powerBombs);
            gSamusEnvironmentalEffects[0].externalTimer = 48;
            SoundPlay(SOUND_X_PARASITE_GETTING_ABSORBED);
            break;

        case SSP_X_UNABSORBABLE_BY_SAMUS:
        case SSP_UNKNOWN_40:
        default:
            break;
    }
}

void XParasiteGettingAbsorbedInit(void)
{
    gCurrentSprite.pose = X_PARASITE_POSE_GETTING_ABSORBED;
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 1;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 1;

    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
    gCurrentSprite.rotation = 0;
    gCurrentSprite.scaling = Q_8_8(1);
    gCurrentSprite.workY = 20;

    SamusAbsorbX();
}

void SpriteDyingInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.pose = SPRITE_POSE_DYING;
    gCurrentSprite.work1 = X_PARASITE_MOSAIC_MAX_INDEX;

    SoundPlayNotAlreadyPlaying(SOUND_SPRITE_TRANSFORMING_INTO_X);
}

void SpriteDying(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.paletteRow != 0)
        gCurrentSprite.paletteRow = 0;

    if ((gCurrentSprite.work1 & 1) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    if (--gCurrentSprite.work1 == 0)
    {
        if (gCurrentSprite.properties & SP_SECONDARY_SPRITE)
        {
            gCurrentSprite.status = 0;
        }
        else
        {
            gCurrentSprite.pose = 0x5b;
            gCurrentSprite.spritesetGfxSlot = 0;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        }
    }

    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.work1];
}

void XParasiteSpawningInit(void)
{
    u8 offset;

    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX / 2;
    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = X_PARASITE_POSE_IDLE;

    offset = gSpriteRandomNumber * 4;
    gCurrentSprite.work3 = offset;
    gCurrentSprite.work4 = offset;
}

void XParasiteDetermineColor(u8 type, u8 spriteId)
{
    u16 randomNumber;
    u16 yellowXThreshold;
    u16 greenXThreshold;
    u16 redXThreshold;

    switch (gCurrentSprite.spritesetSlotAndProperties & SSP_PROPERTY_MASK)
    {
        case SSP_X_ABSORBABLE_BY_SAMUS:
            if (type == X_PARASITE_TYPE_FROM_CORE_X)
            {
                if (gSpriteRandomNumber < 5 || SpriteUtilCheckEnergyFullAndMissilesNotFull())
                {
                    gCurrentSprite.pOam = sXParasiteOam_Green;
                    gCurrentSprite.samusCollision = SSC_GREEN_X_PARASITE;
                }
                else
                {
                    gCurrentSprite.pOam = sXParasiteOam_Yellow;
                    gCurrentSprite.samusCollision = SSC_YELLOW_X_PARASITE_SPAWN_ON_ROOM_LOAD;
                }
            }
            else if (type == X_PARASITE_TYPE_FROM_SPRITE)
            {
                // Calculate random number between 1 and 1024 inclusive
                randomNumber = gSpriteRandomNumber & 3;
                randomNumber <<= 8;
                randomNumber |= gFrameCounter8Bit;
                randomNumber++;

                yellowXThreshold = sPrimarySpriteStats[spriteId][4];
                greenXThreshold = sPrimarySpriteStats[spriteId][5];
                redXThreshold = sPrimarySpriteStats[spriteId][6];

                if (redXThreshold > 0)
                {
                    redXThreshold = 1024 - redXThreshold;
                    if (randomNumber <= 1024 && randomNumber > redXThreshold)
                    {
                        // Eligible for red, spawn red
                        gCurrentSprite.pOam = sXParasiteOam_Red;
                        gCurrentSprite.samusCollision = SSC_RED_X_PARASITE;
                        break;
                    }
                }
                else
                {
                    redXThreshold = 1024;
                }

                if (greenXThreshold > 0)
                {
                    greenXThreshold = redXThreshold - greenXThreshold;
                    if (redXThreshold >= randomNumber && randomNumber > greenXThreshold)
                    {
                        // Eligible for green, spawn yellow if missiles full and energy not full, green otherwise
                        if (SpriteUtilCheckMissilesFullAndEnergyNotFull())
                        {
                            gCurrentSprite.pOam = sXParasiteOam_Yellow;
                            gCurrentSprite.samusCollision = SSC_YELLOW_X_PARASITE_SPAWN_ON_ROOM_LOAD;
                        }
                        else
                        {
                            gCurrentSprite.pOam = sXParasiteOam_Green;
                            gCurrentSprite.samusCollision = SSC_GREEN_X_PARASITE;
                        }

                        break;
                    }
                }
                else
                {
                    greenXThreshold = redXThreshold;
                }

                if (yellowXThreshold > 0 && greenXThreshold >= randomNumber && randomNumber > 0)
                {
                    // Eligible for yellow, spawn green if energy full and missiles not full, yellow otherwise
                    if (SpriteUtilCheckEnergyFullAndMissilesNotFull())
                    {
                        gCurrentSprite.pOam = sXParasiteOam_Green;
                        gCurrentSprite.samusCollision = SSC_GREEN_X_PARASITE;
                    }
                    else
                    {
                        gCurrentSprite.pOam = sXParasiteOam_Yellow;
                        gCurrentSprite.samusCollision = SSC_YELLOW_X_PARASITE_SPAWN_ON_ROOM_LOAD;
                    }

                    break;
                }
                else
                {
                    // This point shouldn't be reached if drop chances sum to 1024
                    gCurrentSprite.status = 0;
                }
            }
            else
            {
                gCurrentSprite.pOam = sXParasiteOam_Yellow;
                gCurrentSprite.samusCollision = SSC_YELLOW_X_PARASITE_SPAWN_ON_ROOM_LOAD;
            }
            break;

        case SSP_X_UNABSORBABLE_BY_SAMUS:
            gCurrentSprite.invincibilityStunFlashTimer &= 0x7f;
            gCurrentSprite.pOam = sXParasiteOam_Yellow;
            gCurrentSprite.samusCollision = SSC_YELLOW_X_PARASITE_SPAWN_ON_ROOM_LOAD;
            break;

        case SSP_UNKNOWN_40:
            gCurrentSprite.pOam = sXParasiteOam_Yellow;
            gCurrentSprite.samusCollision = SSC_YELLOW_X_PARASITE;
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }
}

void XParasiteInit(void)
{
    if (gCurrentSprite.properties & SP_SECONDARY_SPRITE)
    {
        gCurrentSprite.status = 0;
        return;
    }

    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_X_PARASITE_CORE_X_FORMATION:
            gCurrentSprite.pose = X_PARASITE_POSE_IDLE;
            gCurrentSprite.work3 = 1;
            gCurrentSprite.work4 = 1;

            XParasiteDetermineColor(X_PARASITE_TYPE_IN_ROOM, 0);

            if (gSpriteRandomNumber & 1)
                gCurrentSprite.drawOrder = 1;
            else
                gCurrentSprite.drawOrder = 16;
            break;

        case PSPRITE_X_PARASITE_IN_ROOM:
        case PSPRITE_X_PARASITE_IN_ROOM_PROXIMITY:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pose = X_PARASITE_POSE_IDLE;
            gCurrentSprite.work3 = 1;
            gCurrentSprite.work4 = 1;

            XParasiteDetermineColor(X_PARASITE_TYPE_IN_ROOM, 0);
            break;

        case PSPRITE_X_PARASITE_CORE_X_OR_PARASITE:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
            gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
            gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];

            gCurrentSprite.pose = X_PARASITE_POSE_IDLE;
            gCurrentSprite.workX = 0;
            gCurrentSprite.work2 = 0;
            gCurrentSprite.work3 = 1;
            gCurrentSprite.work1 = 0;
            gCurrentSprite.work4 = 1;

            XParasiteDetermineColor(X_PARASITE_TYPE_FROM_CORE_X, 0);

            if (gSpriteRandomNumber & 1)
                gCurrentSprite.drawOrder = 1;
            else
                gCurrentSprite.drawOrder = 16;
            break;

        case PSPRITE_X_PARASITE:
        case PSPRITE_X_PARASITE_AQUA_ZEBESIAN:
            XParasiteSpawningInit();
            XParasiteDetermineColor(X_PARASITE_TYPE_FROM_SPRITE, gCurrentSprite.roomSlot);
            break;

        default:
            XParasiteSpawningInit();
            XParasiteDetermineColor(X_PARASITE_TYPE_FROM_SPRITE, gCurrentSprite.spriteId);
            gCurrentSprite.spriteId = PSPRITE_X_PARASITE;
            break;
    }

    gCurrentSprite.invincibilityStunFlashTimer = 0;
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.properties &= ~SP_CAN_ABSORB_X;
    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.drawDistanceTop = 16;
    gCurrentSprite.drawDistanceBottom = 16;
    gCurrentSprite.drawDistanceHorizontal = 16;

    gCurrentSprite.hitboxTop = -PIXEL_TO_SUB_PIXEL(9);
    gCurrentSprite.hitboxBottom = PIXEL_TO_SUB_PIXEL(9);
    gCurrentSprite.hitboxLeft = -PIXEL_TO_SUB_PIXEL(9);
    gCurrentSprite.hitboxRight = PIXEL_TO_SUB_PIXEL(9);

    gCurrentSprite.health = 1;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.frozenPaletteRowOffset = 0;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work2 = 0;

    if (gCurrentSprite.yPosition > gSamusData.yPosition + gSamusData.drawDistanceTop)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

    SpriteUtilMakeSpriteFaceSamusDirection();
}

void XParasiteFlyingInit(void)
{
    gCurrentSprite.pose = 0x5d;
    gCurrentSprite.workY = 5 * 60;
    gCurrentSprite.workX = 0;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 1;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 1;

    if (gCurrentSprite.spriteId != PSPRITE_X_PARASITE)
        gCurrentSprite.spriteId = PSPRITE_X_PARASITE;
}

void XParasiteIdleFloating(void)
{
    u8 offset;
    s16 movement;

    if ((gCurrentSprite.invincibilityStunFlashTimer & 0x80) == 0)
    {
        offset = gCurrentSprite.work4;
        movement = sXParasiteIdleFloatingYMovement[offset];

        if (movement == SHORT_MAX)
        {
            movement = sXParasiteIdleFloatingYMovement[0];
            offset = 0;
        }

        offset++;
        gCurrentSprite.work4 = offset;
        gCurrentSprite.yPosition += movement;

        offset = gCurrentSprite.work3;
        movement = sXParasiteIdleFloatingXMovement[offset];

        if (movement == SHORT_MAX)
        {
            movement = sXParasiteIdleFloatingXMovement[0];
            offset = 0;
        }

        offset++;
        gCurrentSprite.work3 = offset;
        gCurrentSprite.xPosition += movement;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
    {
        if (--gCurrentSprite.workY > 0)
        {
            gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];

            if ((gCurrentSprite.spritesetSlotAndProperties & SSP_PROPERTY_MASK) == SSP_X_UNABSORBABLE_BY_SAMUS ||
                gCurrentSprite.workY > X_PARASITE_MOSAIC_MAX_INDEX / 2)
            {
                gCurrentSprite.ignoreSamusCollisionTimer = 1;
            }
            else if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                if (gCurrentSprite.spriteId != PSPRITE_X_PARASITE)
                    gCurrentSprite.spriteId = PSPRITE_X_PARASITE;

                XParasiteGettingAbsorbedInit();
            }
        }
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
            if ((gCurrentSprite.spritesetSlotAndProperties & SSP_PROPERTY_MASK) == SSP_X_UNABSORBABLE_BY_SAMUS)
            {
                gCurrentSprite.ignoreSamusCollisionTimer = 1;
                XParasiteFlyingInit();
            }
            else
            {
                gCurrentSprite.workY = 60;
            }
        }
    }
    else
    {
        if (--gCurrentSprite.workY == 0)
            XParasiteFlyingInit();

        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            XParasiteGettingAbsorbedInit();
    }
}

void XParasiteFlying(void)
{
    if ((gCurrentSprite.spritesetSlotAndProperties & SSP_PROPERTY_MASK) == SSP_X_UNABSORBABLE_BY_SAMUS)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
        // Set flashing
        if ((gFrameCounter8Bit & 7) == 0)
        {
            if (gCurrentSprite.paletteRow == 0)
            {
                if (gCurrentSprite.samusCollision == SSC_RED_X_PARASITE)
                    gCurrentSprite.paletteRow = 3;
                else if (gCurrentSprite.samusCollision == SSC_GREEN_X_PARASITE)
                    gCurrentSprite.paletteRow = 2;
                else
                    gCurrentSprite.paletteRow = 1;
            }
            else
            {
                gCurrentSprite.paletteRow = 0;
            }
        }

        if (gCurrentSprite.workY == 0)
        {
            gCurrentSprite.paletteRow = 0;
            gCurrentSprite.pose = X_PARASITE_POSE_FLYING_AWAY;
        }
        else
        {
            gCurrentSprite.workY--;
            if (XParasiteFlyingMovement() == X_PARASITE_FLYING_STAGE_FREE_FLOATING)
            {
                gCurrentSprite.spritesetSlotAndProperties = SSP_X_ABSORBABLE_BY_SAMUS;
                gCurrentSprite.paletteRow = 0;
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
        {
            XParasiteGettingAbsorbedInit();
        }
        else if ((gCurrentSprite.invincibilityStunFlashTimer & 0x80) != 0)
        {
            if (gCurrentPowerBomb.animationState == 0)
                gCurrentSprite.invincibilityStunFlashTimer &= 0x7f;
        }
        else if (gCurrentSprite.workY == 0)
        {
            gCurrentSprite.pose = X_PARASITE_POSE_FLYING_AWAY;
        }
        else
        {
            gCurrentSprite.workY--;
            XParasiteFlyingMovement();
        }
    }
}

void XParasiteGettingAbsorbed(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    XParasiteStickToSamus();

    if (gCurrentSprite.scaling > Q_8_8(5.f / 16))
        gCurrentSprite.scaling -= Q_8_8(1.f / 32);
    else
        gCurrentSprite.status = 0;
}

u8 XParasiteFlyingMovement(void)
{
    u8 stage;
    u16 y;
    u16 x;
    u8 i;
    u16 targetY;
    u16 targetX;
    u16 distY;
    u16 distX;
    u8 ySpeedCap;
    u8 xSpeedCap;
    u8 targetRamSlot;

    stage = X_PARASITE_FLYING_STAGE_FREE_FLOATING;
    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (gSpriteData[i].status & SPRITE_STATUS_EXISTS && gSpriteData[i].properties & SP_CAN_ABSORB_X &&
            gSpriteData[i].health > 0 && gSpriteData[i].freezeTimer == 0)
        {
            // Sprite is eligible to form
            targetY = gSpriteData[i].yPosition;
            targetX = gSpriteData[i].xPosition;

            // Calculate and store taxicab distance from X parasite to other sprite
            SET_ABS_SUB(distY, y, targetY);
            SET_ABS_SUB(distX, x, targetX);
            gUnk_030007c0[i] = distY + distX;

            stage = X_PARASITE_FLYING_STAGE_FLYING_TO_SPRITE;
            if (gCurrentSprite.pose == X_PARASITE_POSE_FLYING)
                gCurrentSprite.workY = 300;

            if (y + EIGHTH_BLOCK_SIZE > targetY + gSpriteData[i].hitboxTop &&
                y - EIGHTH_BLOCK_SIZE < targetY + gSpriteData[i].hitboxBottom &&
                x + EIGHTH_BLOCK_SIZE > targetX + gSpriteData[i].hitboxLeft &&
                x - EIGHTH_BLOCK_SIZE < targetX + gSpriteData[i].hitboxRight)
            {
                // Touched sprite
                if (--gSpriteData[i].numberOfXToForm == 0)
                {
                    // Enough X to form the sprite
                    if (gSpriteData[i].spritesetSlotAndProperties >= SSP_UNINFECTED_OR_BOSS &&
                        gSpriteData[i].spritesetSlotAndProperties < SSP_UNINFECTED_OR_BOSS + 0x10)
                        gSpriteData[i].spritesetSlotAndProperties = SSP_X_ABSORBABLE_BY_SAMUS;

                    gSpriteData[i].pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
                    gSpriteData[i].status |= (SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_MOSAIC);
                    gSpriteData[i].status &= ~SPRITE_STATUS_HIDDEN;
                    gSpriteData[i].properties &= ~SP_CAN_ABSORB_X;

                    gCurrentSprite.xPosition = gSpriteData[i].xPosition;
                    gCurrentSprite.pose = X_PARASITE_POSE_FORMING_INIT;
                }
                else
                {
                    // Not enough X
                    gCurrentSprite.pose = X_PARASITE_POSE_WAITING_FOR_ENOUGH_X_TO_FORM_INIT;
                    gCurrentSprite.work2 = i;
                    gCurrentSprite.workY = gSpriteData[i].yPosition;
                    gCurrentSprite.workX = gSpriteData[i].xPosition;
                }

                stage = X_PARASITE_FLYING_STAGE_TOUCHED_SPRITE;
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                break;
            }
        }
        else
        {
            // Sprite isn't eligible to absorb/spawn, set dummy value that's greater than any sprite eligible
            gUnk_030007c0[i] = 0x8000;
        }
    }

    if (stage == X_PARASITE_FLYING_STAGE_TOUCHED_SPRITE)
    {
        return stage;
    }
    else if (stage == X_PARASITE_FLYING_STAGE_FREE_FLOATING)
    {
        targetY = gXParasiteTargetYPosition;
        targetX = gXParasiteTargetXPosition;

        if (gCurrentSprite.pose == X_PARASITE_POSE_FLYING)
        {
            // workX is incremented mod 4 when changing X direction in XParasiteMove
            switch (gCurrentSprite.workX)
            {
                case 1:
                    targetY -= BLOCK_SIZE;
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        targetX += BLOCK_SIZE;
                    else
                        targetX -= BLOCK_SIZE;
                    break;

                case 3:
                    targetY += BLOCK_SIZE;
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        targetX -= BLOCK_SIZE;
                    else
                        targetX += BLOCK_SIZE;
                    break;
            }
        }

        ySpeedCap = PIXEL_TO_SUB_PIXEL(5);
        xSpeedCap = PIXEL_TO_SUB_PIXEL(7);
        i = 1;
    }
    else
    {
        targetRamSlot = 1;

        // Get nearest sprite by taxicab distance
        for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
        {
            if (gUnk_030007c0[targetRamSlot] > gUnk_030007c0[i])
                targetRamSlot = i;
        }

        targetY = gSpriteData[targetRamSlot].yPosition + gSpriteData[targetRamSlot].hitboxTop +
            (gSpriteData[targetRamSlot].hitboxBottom - gSpriteData[targetRamSlot].hitboxTop) / 2;
        targetX = gSpriteData[targetRamSlot].xPosition;
        ySpeedCap = PIXEL_TO_SUB_PIXEL(5);
        xSpeedCap = PIXEL_TO_SUB_PIXEL(5);
        i = 1;
    }

    XParasiteMove(targetY, targetX, ySpeedCap, xSpeedCap, i);

    return stage;
}

void XParasiteFlyingAway(void)
{
    u32 movement;

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        XParasiteGettingAbsorbedInit();
    }
    else if ((gCurrentSprite.invincibilityStunFlashTimer & 0x80) != 0)
    {
        if (gCurrentPowerBomb.animationState == 0)
            gCurrentSprite.invincibilityStunFlashTimer &= 0x7f;
    }
    else
    {
        if (gCurrentSprite.work3 < PIXEL_TO_SUB_PIXEL(6.25f) * 8)
            gCurrentSprite.work3 += 1;

        movement = DIV_SHIFT(gCurrentSprite.work3, 8);

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.xPosition += movement;
        else
            gCurrentSprite.xPosition -= movement;

        if (gCurrentSprite.work4 < PIXEL_TO_SUB_PIXEL(6.25f) * 8)
            gCurrentSprite.work4 += 1;

        movement = DIV_SHIFT(gCurrentSprite.work4, 8);

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            gCurrentSprite.yPosition += movement;
        else
            gCurrentSprite.yPosition -= movement;

        if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
            gCurrentSprite.status = 0;
    }
}

void XParasiteWaitingForEnoughXToFormInit(void)
{
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = X_PARASITE_POSE_WAITING_FOR_ENOUGH_X_TO_FORM;
    gCurrentSprite.work1 = X_PARASITE_MOSAIC_MAX_INDEX;
    gCurrentSprite.scaling = 300;

    SoundPlayNotAlreadyPlaying(SOUND_X_PARASITE_FORMING);
}

void XParasiteWaitingForEnoughXToForm(void)
{
    u8 targetRamSlot;
    u16 tmp;

    gCurrentSprite.scaling--;
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    targetRamSlot = gCurrentSprite.work2;

    if (gSpriteData[targetRamSlot].numberOfXToForm == 0)
    {
        // Target sprite successfully formed
        gCurrentSprite.status = 0;
    }
    else if (!CheckSpritesThatCantAbsorbX() || gCurrentSprite.scaling == 0)
    {
        // Give up waiting after enough time or if there's no floating X parasite in the room
        gSpriteData[targetRamSlot].numberOfXToForm++;
        gCurrentSprite.pose = X_PARASITE_POSE_FLYING_AWAY;
        gCurrentSprite.status &= ~(SPRITE_STATUS_MOSAIC | SPRITE_STATUS_NOT_DRAWN);
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    else
    {
        // Make it flicker
        if ((gCurrentSprite.work1 & 1) == 0)
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

        if (--gCurrentSprite.work1 == 0)
            gCurrentSprite.work1 = X_PARASITE_MOSAIC_MAX_INDEX;

        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.work1];

        // Stick to the sprite it's trying to form
        if (gSpriteData[targetRamSlot].yPosition > gCurrentSprite.workY)
        {
            tmp = gSpriteData[targetRamSlot].yPosition - gCurrentSprite.workY;
            gCurrentSprite.yPosition += tmp;
        }
        else
        {
            tmp = gCurrentSprite.workY - gSpriteData[targetRamSlot].yPosition;
            gCurrentSprite.yPosition -= tmp;
        }

        if (gSpriteData[targetRamSlot].xPosition > gCurrentSprite.workX)
        {
            tmp = gSpriteData[targetRamSlot].xPosition - gCurrentSprite.workX;
            gCurrentSprite.xPosition += tmp;
        }
        else
        {
            tmp = gCurrentSprite.workX - gSpriteData[targetRamSlot].xPosition;
            gCurrentSprite.xPosition -= tmp;
        }

        gCurrentSprite.workY = gSpriteData[targetRamSlot].yPosition;
        gCurrentSprite.workX = gSpriteData[targetRamSlot].xPosition;
    }
}

void XParasiteFormingInit(void)
{
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = 0x64;
    gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;

    SoundPlayNotAlreadyPlaying(SOUND_X_PARASITE_FORMING);
}

void XParasiteForming(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if ((gCurrentSprite.workY & 1) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    if (--gCurrentSprite.workY == 0)
        gCurrentSprite.status = 0;

    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
}

void SpriteSpawningFromX(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (--gCurrentSprite.workY > 0)
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = 1;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }
}

void unk_62328(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Move right
        if (gCurrentSprite.work2 == 0)
        {
            if (gCurrentSprite.xPosition > gSamusData.xPosition - PIXEL_SIZE)
            {
                gCurrentSprite.work2 = gCurrentSprite.work3;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work3 < PIXEL_TO_SUB_PIXEL(2.5f))
                    gCurrentSprite.work3++;

                // Apply speed
                gCurrentSprite.xPosition += gCurrentSprite.work3;
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
            {
                gCurrentSprite.xPosition += DIV_SHIFT(gCurrentSprite.work2, 2);
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work3 = 1;
            }
        }
    }
    else
    {
        // Move left
        if (gCurrentSprite.work2 == 0)
        {
            if (gCurrentSprite.xPosition < gSamusData.xPosition + PIXEL_SIZE)
            {
                gCurrentSprite.work2 = gCurrentSprite.work3;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work3 < PIXEL_TO_SUB_PIXEL(2.5f))
                    gCurrentSprite.work3++;

                // Apply speed
                gCurrentSprite.xPosition -= gCurrentSprite.work3;
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
            {
                gCurrentSprite.xPosition -= DIV_SHIFT(gCurrentSprite.work2, 2);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work3 = 1;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        // Move down
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.yPosition > gSamusData.yPosition - (BLOCK_SIZE + PIXEL_SIZE * 3))
            {
                gCurrentSprite.work1 = gCurrentSprite.work4;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work4 < PIXEL_TO_SUB_PIXEL(2.5f))
                    gCurrentSprite.work4++;

                // Apply speed
                gCurrentSprite.yPosition += gCurrentSprite.work4;
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                gCurrentSprite.yPosition += DIV_SHIFT(gCurrentSprite.work1, 2);
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.work4 = 1;
            }
        }
    }
    else
    {
        // Move up
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.yPosition < gSamusData.yPosition - (BLOCK_SIZE + PIXEL_SIZE))
            {
                gCurrentSprite.work1 = gCurrentSprite.work4;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work4 < PIXEL_TO_SUB_PIXEL(2.5f))
                    gCurrentSprite.work4++;

                // Apply speed
                gCurrentSprite.yPosition -= gCurrentSprite.work4;
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                gCurrentSprite.yPosition -= DIV_SHIFT(gCurrentSprite.work1, 2);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.work4 = 1;
            }
        }
    }
}

void XParasiteStickToSamus(void)
{
    u16 currentPosition;
    u16 targetPosition;
    u16 distance;
    u16 movement;

    currentPosition = gCurrentSprite.xPosition + 0x200;
    targetPosition = gSamusData.xPosition + 0x200;

    SET_ABS_SUB(distance, currentPosition, targetPosition);

    if (distance <= EIGHTH_BLOCK_SIZE)
        movement = 0;
    else
        movement = DIV_SHIFT(distance - EIGHTH_BLOCK_SIZE, 2);

    if (currentPosition > targetPosition)
        gCurrentSprite.xPosition -= movement;
    else if (currentPosition < targetPosition)
        gCurrentSprite.xPosition += movement;

    currentPosition = gCurrentSprite.yPosition + 0x200;

    if (SpriteUtilCheckSamusMorphed())
        targetPosition = gSamusData.yPosition + 0x200 - PIXEL_TO_SUB_PIXEL(0xc);
    else
        targetPosition = gSamusData.yPosition + 0x200 - PIXEL_TO_SUB_PIXEL(19.5f);

    SET_ABS_SUB(distance, currentPosition, targetPosition);

    if (distance <= EIGHTH_BLOCK_SIZE)
        movement = 0;
    else
        movement = DIV_SHIFT(distance - EIGHTH_BLOCK_SIZE, 2);

    if (currentPosition > targetPosition)
        gCurrentSprite.yPosition -= movement;
    else if (currentPosition < targetPosition)
        gCurrentSprite.yPosition += movement;
}
