#include "data/sprites/nightmare.h"

#include "globals.h"
#include "macros.h"

#include "data/audio.h"
#include "data/frame_data_pointers.h"
#include "data/sprite_data.h"
#include "data/sprites/core_x.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/particle.h"
#include "constants/projectile.h"
#include "constants/samus.h"

#include "structs/projectile.h"
#include "structs/samus.h"

void NightmareMoveToPosition(u16 dstY, u16 dstX, u8 ySpeedCap, u8 xSpeedCap, u8 speedDivisor)
{
    boolu8 flip;
    u16 velocity;

    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Move right
        if (gCurrentSprite.work2 == 0)
        {
            if (gSubSpriteData1.xPosition > dstX + BLOCK_TO_SUB_PIXEL(1.f / 16))
            {
                gCurrentSprite.work2 = gCurrentSprite.work3;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work3 < xSpeedCap)
                    gCurrentSprite.work3++;

                // Apply speed
                gSubSpriteData1.xPosition += (gCurrentSprite.work3 >> speedDivisor);
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
                gSubSpriteData1.xPosition += (gCurrentSprite.work2 >> speedDivisor);
            else
                flip = TRUE;
        }
    }
    else
    {
        // Move left
        if (gCurrentSprite.work2 == 0)
        {
            if (gSubSpriteData1.xPosition < dstX - BLOCK_TO_SUB_PIXEL(1.f / 16))
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
                if ((gSubSpriteData1.xPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work2 = 0;
                }
                else
                {
                    gSubSpriteData1.xPosition -= velocity;
                }
            }
        }
        else
        {
            if (--gCurrentSprite.work2 != 0)
            {
                velocity = gCurrentSprite.work2 >> speedDivisor;
                if ((gSubSpriteData1.xPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work2 = 0;
                }
                else
                {
                    gSubSpriteData1.xPosition -= velocity;
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
        SoundPlayNotAlreadyPlaying(SOUND_NIGHTMARE_CHANGING_DIRECTION);
    }

    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        // Move down
        if (gCurrentSprite.work1 == 0)
        {
            if (gSubSpriteData1.yPosition > dstY - BLOCK_TO_SUB_PIXEL(1.f / 16))
            {
                gCurrentSprite.work1 = gCurrentSprite.work4;
            }
            else
            {
                // Increase speed if below cap
                if (gCurrentSprite.work4 < ySpeedCap)
                    gCurrentSprite.work4++;

                // Apply speed
                gSubSpriteData1.yPosition += (gCurrentSprite.work4 >> speedDivisor);
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
                gSubSpriteData1.yPosition += (gCurrentSprite.work1 >> speedDivisor);
            else
                flip = TRUE;
        }
    }
    else
    {
        // Move up
        if (gCurrentSprite.work1 == 0)
        {
            if (gSubSpriteData1.yPosition < dstY + BLOCK_TO_SUB_PIXEL(1.f / 16))
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
                if ((gSubSpriteData1.yPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work1 = 0;
                }
                else
                {
                    gSubSpriteData1.yPosition -= velocity;
                }
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                velocity = gCurrentSprite.work1 >> speedDivisor;
                if ((gSubSpriteData1.yPosition - velocity) & 0x8000)
                {
                    flip = TRUE;
                    gCurrentSprite.work1 = 0;
                }
                else
                {
                    gSubSpriteData1.yPosition -= velocity;
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
        SoundPlayNotAlreadyPlaying(SOUND_NIGHTMARE_CHANGING_DIRECTION);
    }
}

void NightmareSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;

    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];

    if (gCurrentSprite.pOam != sNightmareFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sNightmareFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition =
        gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition =
        gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

void NightmarePlaySound(void)
{
    if (gCurrentSprite.samusCollision != SSC_NONE && gSubSpriteData1.currentAnimationFrame == 0 &&
        gSubSpriteData1.animationDurationCounter == 12)
        SoundPlay(SOUND_NIGHTMARE_IDLE);
}

void NightmareMakeMissilesFall(void)
{
    u8 i;
    u8 typeToCheck;
    u16 fallingSpeed;

    typeToCheck = PROJ_TYPE_ICE_MISSILE;

    for (i = 0; i < MAX_AMOUNT_OF_PROJECTILES; i++)
    {
        if (!(gProjectileData[i].status & PROJ_STATUS_EXISTS))
            continue;

        if (!(gProjectileData[i].status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT))
            continue;

        if (gProjectileData[i].type != typeToCheck)
            continue;

        if ((gProjectileData[i].part & 3) == 0)
            gProjectileData[i].part++;

        if (gProjectileData[i].part < 0x2a)
            fallingSpeed = gProjectileData[i].part;
        else
            fallingSpeed = 0x2a;

        gProjectileData[i].yPosition += fallingSpeed;
    }
}

void NightmareReduceSamusXVelocity(void)
{
    if (gEquipment.currentEnergy != 0)
    {
        if (gSamusData.xVelocity > 4)
            gSamusData.xVelocity -= 2;
        else if (gSamusData.xVelocity < -4)
            gSamusData.xVelocity += 2;
    }
}

void NightmareInit(void)
{
    u32 y;
    u32 x;
    u8 primaryRamSlot;
    u8 eyeRamSlot;
    u8 mouthRamSlot;

    if (gEquipment.suitMiscStatus & SMF_GRAVITY_SUIT)
    {
        gCurrentSprite.status = 0;
    }
    else
    {
        gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(11.f);
        gCurrentSprite.xPosition += BLOCK_SIZE;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        gCurrentSprite.roomSlot = NIGHTMARE_PART_BODY;
        gCurrentSprite.drawOrder = 12;
        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(5);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
        gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(4);
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(4.0f);
        gCurrentSprite.hitboxBottom = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.5f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(3.0f);
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gSubSpriteData1.pMultiOam = sNightmareMultiSpriteData;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.work0 = 0;
        gCurrentSprite.pose = 0x37;
        gCurrentSprite.work1 = 3 * 60;

        gBossWork3 = 3 * 60;

        y = gSubSpriteData1.yPosition;
        x = gSubSpriteData1.xPosition;
        primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_CHIN_SLUDGE, 0, primaryRamSlot, y, x, 0);
        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_EYE_SLUDGE, 0, primaryRamSlot, y, x, 0);
        eyeRamSlot = SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_EYE, 0, primaryRamSlot, y, x, 0);
        mouthRamSlot = SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_MOUTH, 0, primaryRamSlot, y, x, 0);
        gSpriteData[eyeRamSlot].numberOfXToForm = mouthRamSlot;

        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_RIGHT_ARM_TOP, 0, primaryRamSlot, y, x, 0);
        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_RIGHT_TURRET_1, 0, primaryRamSlot, y, x, 0);
        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_RIGHT_TURRET_2, 0, primaryRamSlot, y, x, 0);
        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_RIGHT_TURRET_3, 0, primaryRamSlot, y, x, 0);
        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_RIGHT_ARM_BOTTOM, 0, primaryRamSlot, y, x, 0);

        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_GENERATOR, 0, primaryRamSlot, y, x, 0);
        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_LEFT_TURRET_1, 0, primaryRamSlot, y, x, 0);
        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_LEFT_TURRET_2, 0, primaryRamSlot, y, x, 0);
        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_PART, NIGHTMARE_PART_LEFT_TURRET_3, 0, primaryRamSlot, y, x, 0);
    }
}

void NightmareWaitingToAppear(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x38;

        ScreenShakeStartHorizontal(60, 0x81);
        ScreenShakeStartVertical(60, 0x81);

        gCurrentSprite.work1 = 60;

        SoundPlay_3b1c(SOUND_NIGHTMARE_APPEARING);
    }
}

void NightmareAppearing(void)
{
    gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    if (--gCurrentSprite.work1 == 0)
    {
        ScreenShakeStartHorizontal(60, 0x81);
        ScreenShakeStartVertical(60, 0x81);

        gCurrentSprite.work1 = 60;

        SoundPlay_3b1c(SOUND_NIGHTMARE_APPEARING);
    }

    if (gSubSpriteData1.yPosition > BLOCK_TO_SUB_PIXEL(16.f))
        gSubSpriteData1.yPosition -= BLOCK_TO_SUB_PIXEL(1.f / 64);
    else
        gCurrentSprite.pose = 0x39;
}

void NightmarePhase1Init(void)
{
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = BLOCK_TO_SUB_PIXEL(1.f / 64);
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = BLOCK_TO_SUB_PIXEL(1.f / 64);
    gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
    gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
    gCurrentSprite.pose = 0x3a;

    PlayMusic(MUSIC_NIGHTMARE_BATTLE, 7);
}

void NightmarePhase1(void)
{
    NightmareMoveToPosition(gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(4.f),
        gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(3.f), BLOCK_TO_SUB_PIXEL(0.15625f) * 4,
        BLOCK_TO_SUB_PIXEL(0.03125f) * 4, LOG2(4));
}

void NightmarePhase2ResettingPosition(void)
{
    u8 reachedDst;
    u16 dstY;
    u16 dstX;

    reachedDst = 0;
    dstY = gAbilityRestingYPosition - BLOCK_TO_SUB_PIXEL(2.f);
    dstX = gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(4.f);

    if (gSubSpriteData1.xPosition < dstX)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;

    if (gSubSpriteData1.yPosition < dstY)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;

    if (gSubSpriteData1.yPosition < dstY + BLOCK_TO_SUB_PIXEL(0.09375f) &&
        gSubSpriteData1.yPosition > dstY - BLOCK_TO_SUB_PIXEL(0.09375f))
        reachedDst++;
    else if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gSubSpriteData1.yPosition += BLOCK_TO_SUB_PIXEL(1.f / 64);
    else
        gSubSpriteData1.yPosition -= BLOCK_TO_SUB_PIXEL(1.f / 64);

    if (gSubSpriteData1.xPosition < dstX + BLOCK_TO_SUB_PIXEL(0.09375f) &&
        gSubSpriteData1.xPosition > dstX - BLOCK_TO_SUB_PIXEL(0.09375f))
        reachedDst++;
    else if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.xPosition += BLOCK_TO_SUB_PIXEL(1.f / 64);
    else
        gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(1.f / 64);

    if (reachedDst == 2)
    {
        gCurrentSprite.pose = 1;
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    }
}

void NightmarePhase2MovementInit(void)
{
    gCurrentSprite.pose = 2;
    gCurrentSprite.workY = 0;
    gCurrentSprite.work4 = 0;
}

void NightmarePhase2Movement(void)
{
    u16 movement;

    movement = sNightmarePhase2XSpeed[DIV_SHIFT(gCurrentSprite.workY, 32)];

    if (gCurrentSprite.workY < ARRAY_SIZE(sNightmarePhase2XSpeed) * 32 - 1)
    {
        gCurrentSprite.workY++;
    }
    else
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.workY = 0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.xPosition += movement;
    else
        gSubSpriteData1.xPosition -= movement;

    movement = sNightmarePhase2YSpeed[DIV_SHIFT(gCurrentSprite.work4, 8)];
    if (gCurrentSprite.work4 < ARRAY_SIZE(sNightmarePhase2YSpeed) * 8 - 1)
        gCurrentSprite.work4++;
    else
        gCurrentSprite.work4 = 0;

    gSubSpriteData1.yPosition += movement;
}

void NightmareMovingToPhase3Init(void)
{
    gCurrentSprite.pose = 0x18;
}

void NightmareMovingToPhase3(void)
{
    u8 reachedDst;
    u16 dstY;
    u16 dstX;

    reachedDst = 0;
    dstY = gAbilityRestingYPosition;
    dstX = gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(3.f);

    if (gSubSpriteData1.xPosition < dstX)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;

    if (gSubSpriteData1.yPosition < dstY)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;

    if (gSubSpriteData1.yPosition < dstY + BLOCK_TO_SUB_PIXEL(0.09375f) &&
        gSubSpriteData1.yPosition > dstY - BLOCK_TO_SUB_PIXEL(0.09375f))
        reachedDst++;
    else if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gSubSpriteData1.yPosition += BLOCK_TO_SUB_PIXEL(1.f / 64);
    else
        gSubSpriteData1.yPosition -= BLOCK_TO_SUB_PIXEL(1.f / 64);

    if (gSubSpriteData1.xPosition < dstX + BLOCK_TO_SUB_PIXEL(0.09375f) &&
        gSubSpriteData1.xPosition > dstX - BLOCK_TO_SUB_PIXEL(0.09375f))
        reachedDst++;
    else if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.xPosition += BLOCK_TO_SUB_PIXEL(1.f / 64);
    else
        gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(1.f / 64);

    if (reachedDst == 2)
        gCurrentSprite.pose = 0x19;
}

void NightmareReachedPhase3Position(void)
{
    // Empty
}

void NightmarePhase3SlowMovementInit(void)
{
    // Empty
}

void NightmarePhase3SlowMovement(void)
{
    u8 switchToFastMovement;

    switchToFastMovement = 0;

    if (gSubSpriteData1.yPosition < gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(2.0f))
        gSubSpriteData1.yPosition += BLOCK_TO_SUB_PIXEL(1.f / 64);
    else
        switchToFastMovement++;

    // Check if Nightmare is near the wall
    SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(3.0f));

    if (gPreviousCollisionCheck != 0)
        switchToFastMovement++;
    else
        gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(1.f / 64);

    if (switchToFastMovement == 2)
        gCurrentSprite.pose = 0x1b;
}

void NightmarePhase3FastMovementInit(void)
{
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = BLOCK_TO_SUB_PIXEL(1.f / 64);
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = BLOCK_TO_SUB_PIXEL(1.f / 64);
    gCurrentSprite.pose = 0x1c;
    gCurrentSprite.workY = 5 * 60;
}

void NightmarePhase3FastMovement(void)
{
    u16 dstX;
    u16 dstY;
    u16 posOnScreen;

    if (gCurrentSprite.workY > 4 * 60)
    {
        dstY = gXParasiteTargetYPosition;
        dstX = gXParasiteTargetXPosition;
    }
    else
    {
        dstY = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(2.0f);
        dstX = gSamusData.xPosition;
    }

    NightmareMoveToPosition(dstY, dstX, BLOCK_TO_SUB_PIXEL(0.1875f) * 4, BLOCK_TO_SUB_PIXEL(0.1875f) * 4, LOG2(4));

    if (gCurrentSprite.workY > 0)
    {
        gCurrentSprite.workY--;
    }
    else
    {
        posOnScreen = SUB_PIXEL_TO_PIXEL_(gSubSpriteData1.xPosition) - SUB_PIXEL_TO_PIXEL_(gBg1XPosition);
        if (posOnScreen > 140 && posOnScreen < SCREEN_SIZE_X - 24)
        {
            posOnScreen = SUB_PIXEL_TO_PIXEL_(gSubSpriteData1.yPosition) - SUB_PIXEL_TO_PIXEL_(gBg1YPosition);
            if (posOnScreen > 20 && posOnScreen < SCREEN_SIZE_Y - 60)
            {
                if (gSamusData.xPosition < gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.0f))
                    gCurrentSprite.pose = 0x1e;
            }
        }
    }
}

void NightmareDeathFlash(void)
{
    u8 work2;

    work2 = gCurrentSprite.work2++;

    if ((work2 & 3) == 0)
    {
        if ((work2 & 4) != 0)
            SPRITE_SET_ABSOLUTE_PALETTE_ROW(gCurrentSprite, SPRITE_FLASHING_PALETTE_ROW);
        else
            gCurrentSprite.paletteRow = 0;
    }
}

void NightmareMovingToDeathPosition(void)
{
    u8 reachedDst;
    u16 dstY;
    u16 dstX;

    NightmareDeathFlash();

    reachedDst = 0;
    dstY = gAbilityRestingYPosition;
    dstX = gAbilityRestingXPosition + BLOCK_TO_SUB_PIXEL(3);

    if (gSubSpriteData1.xPosition < dstX)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;

    if (gSubSpriteData1.yPosition < dstY)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;

    if (gSubSpriteData1.yPosition < dstY + BLOCK_TO_SUB_PIXEL(0.09375f) &&
        gSubSpriteData1.yPosition > dstY - BLOCK_TO_SUB_PIXEL(0.09375f))
        reachedDst++;
    else if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gSubSpriteData1.yPosition += BLOCK_TO_SUB_PIXEL(1.f / 64);
    else
        gSubSpriteData1.yPosition -= BLOCK_TO_SUB_PIXEL(1.f / 64);

    if (gSubSpriteData1.xPosition < dstX + BLOCK_TO_SUB_PIXEL(0.09375f) &&
        gSubSpriteData1.xPosition > dstX - BLOCK_TO_SUB_PIXEL(0.09375f))
        reachedDst++;
    else if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.xPosition += BLOCK_TO_SUB_PIXEL(1.f / 64);
    else
        gSubSpriteData1.xPosition -= BLOCK_TO_SUB_PIXEL(1.f / 64);

    if (reachedDst == 2)
    {
        if (--gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.pose = 0x22;
            gCurrentSprite.work1 = 60;
            SoundPlay_3b1c(SOUND_NIGHTMARE_DYING);
        }
    }
}

void NightmareTurningIntoCoreX(void)
{
    if (gCurrentSprite.work1 > 0)
    {
        NightmareDeathFlash();

        if (--gCurrentSprite.work1 == 0)
        {
            gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
            gCurrentSprite.invincibilityStunFlashTimer = 0;
            gCurrentSprite.paletteRow = 0;
            gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
        }
    }
    else
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];

        if (--gCurrentSprite.workY == 0)
        {
            gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
            gCurrentSprite.spriteId = PSPRITE_GRAVITY_SUIT_ABILITY;
        }

        if (gCurrentSprite.workY < sizeof(sGravityCoreXGfx) / 512)
            SpriteLoadGfx(PSPRITE_GRAVITY_SUIT_ABILITY, 0, gCurrentSprite.workY);
        else if (gCurrentSprite.workY == sizeof(sGravityCoreXGfx) / 512)
            SpriteLoadPal(PSPRITE_GRAVITY_SUIT_ABILITY, 0, ARRAY_SIZE(sGravityCoreXPal) / 16);
    }
}

void NightmarePartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = 2;
    gCurrentSprite.work0 = 0;

    switch (gCurrentSprite.roomSlot)
    {
        case NIGHTMARE_PART_CHIN_SLUDGE:
            gCurrentSprite.drawOrder = 9;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case NIGHTMARE_PART_EYE_SLUDGE:
            gCurrentSprite.drawOrder = 9;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(3);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case NIGHTMARE_PART_EYE:
            gCurrentSprite.drawOrder = 10;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.5f);
            gCurrentSprite.hitboxBottom = -BLOCK_TO_SUB_PIXEL(1.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0f);
            gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case NIGHTMARE_PART_MOUTH:
            gCurrentSprite.drawOrder = 11;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(3.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(3);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case NIGHTMARE_PART_RIGHT_ARM_TOP:
            gCurrentSprite.drawOrder = 4;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 1;
            break;

        case NIGHTMARE_PART_RIGHT_TURRET_1:
            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.625f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.625f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.125f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 1;
            break;

        case NIGHTMARE_PART_RIGHT_TURRET_2:
            gCurrentSprite.drawOrder = 6;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.625f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.125f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 1;
            break;

        case NIGHTMARE_PART_RIGHT_TURRET_3:
            gCurrentSprite.drawOrder = 7;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.625f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.625f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 1;
            break;

        case NIGHTMARE_PART_RIGHT_ARM_BOTTOM:
            gCurrentSprite.drawOrder = 8;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.125f);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 1;
            break;

        case NIGHTMARE_PART_GENERATOR:
            gCurrentSprite.drawOrder = 11;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.25f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.0f);
            gCurrentSprite.frozenPaletteRowOffset = 3;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gSubSpriteData1.health = gCurrentSprite.health;
            gCurrentSprite.work1 = 0;
            gCurrentSprite.work2 = 0;
            gCurrentSprite.pose = 1;
            break;

        case NIGHTMARE_PART_LEFT_TURRET_1:
            gCurrentSprite.drawOrder = 13;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 1;
            break;

        case NIGHTMARE_PART_LEFT_TURRET_2:
            gCurrentSprite.drawOrder = 14;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 1;
            break;

        case NIGHTMARE_PART_LEFT_TURRET_3:
            gCurrentSprite.drawOrder = 15;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.375f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 1;
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }

    NightmareSyncSubSprites();
}

void NightmarePartDying(u8 primaryRamSlot)
{
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.paletteRow = gSpriteData[primaryRamSlot].paletteRow;
}

void NightmarePartSpawnBeam(void)
{
    if (gCurrentSprite.currentAnimationFrame == 11 && gCurrentSprite.animationDurationCounter == 3)
    {
        SpriteSpawnSecondary(SSPRITE_NIGHTMARE_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f), 0);
    }
}

void NightmarePartRightArmTop(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;

        case 2:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gSpriteData[primaryRamSlot].pose == 0x3a)
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
                gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
                gCurrentSprite.pose = 0x18;
            }
            break;

        case 0x18:
            if (gSpriteData[primaryRamSlot].pose == 0x22)
            {
                SpriteSpawnSecondary(SSPRITE_NIGHTMARE_FALLING_ARM, NIGHTMARE_FALLING_PART_RIGHT_ARM_TOP, 0,
                    primaryRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x1e;
            }
            else if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                NightmarePartDying(gCurrentSprite.primarySpriteRamSlot);
            }
            break;
    }
}

void NightmarePartRightArmBottom(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;

        case 2:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gSpriteData[primaryRamSlot].pose == 0x3a)
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
                gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
                gCurrentSprite.pose = 0x18;
            }
            break;

        case 0x18:
            if (gSpriteData[primaryRamSlot].pose == 0x22)
            {
                SpriteSpawnSecondary(SSPRITE_NIGHTMARE_FALLING_ARM, NIGHTMARE_FALLING_PART_RIGHT_ARM_BOTTOM, 0,
                    primaryRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x1e;
            }
            else if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                NightmarePartDying(gCurrentSprite.primarySpriteRamSlot);
            }
            break;
    }
}

void NightmarePartRightTurret1(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case 2:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gSpriteData[primaryRamSlot].pose == 0x3a)
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
                gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
                gCurrentSprite.work1 = 108;
                gCurrentSprite.pose = 0x18;
            }
            break;

        case 0x18:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_RightTurret1Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (--gCurrentSprite.work1 == 0)
                {
                    if (gSpriteData[primaryRamSlot].pose == 2)
                        gCurrentSprite.pOam = sNightmarePartOam_RightTurret1NotFiring;
                    else if (gSpriteData[primaryRamSlot].pose == 0x1c)
                        gCurrentSprite.pOam = sNightmarePartOam_RightTurret1NotFiring;
                    else
                        gCurrentSprite.pOam = sNightmarePartOam_RightTurret1Firing;

                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.pose = 0x1a;
                }
            }
            break;

        case 0x1a:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_RightTurret1Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (gCurrentSprite.pOam == sNightmarePartOam_RightTurret1Firing)
                    NightmarePartSpawnBeam();

                if (SpriteUtilHasCurrentAnimationEnded())
                {
                    gCurrentSprite.pOam = sNightmarePartOam_RightTurret1Idle;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.work1 = gBossWork2;
                    gCurrentSprite.pose = 0x18;
                }
            }
            break;

        case 0x1c:
            NightmarePartDying(gCurrentSprite.primarySpriteRamSlot);

            if (gSpriteData[primaryRamSlot].pose == 0x22)
            {
                SpriteSpawnSecondary(SSPRITE_NIGHTMARE_FALLING_ARM, NIGHTMARE_FALLING_PART_RIGHT_TURRET_1, 0,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x1e;
            }
            break;

        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;
    }
}

void NightmarePartRightTurret2(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case 2:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gSpriteData[primaryRamSlot].pose == 0x3a)
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
                gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
                gCurrentSprite.work1 = 104;
                gCurrentSprite.pose = 0x18;
            }
            break;

        case 0x18:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_RightTurret2Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (--gCurrentSprite.work1 == 0)
                {
                    if (gSpriteData[primaryRamSlot].pose == 2)
                        gCurrentSprite.pOam = sNightmarePartOam_RightTurret2NotFiring;
                    else if (gSpriteData[primaryRamSlot].pose == 0x1c)
                        gCurrentSprite.pOam = sNightmarePartOam_RightTurret2NotFiring;
                    else
                        gCurrentSprite.pOam = sNightmarePartOam_RightTurret2Firing;

                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.pose = 0x1a;
                }
            }
            break;

        case 0x1a:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_RightTurret2Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (gCurrentSprite.pOam == sNightmarePartOam_RightTurret2Firing)
                    NightmarePartSpawnBeam();

                if (SpriteUtilHasCurrentAnimationEnded())
                {
                    gCurrentSprite.pOam = sNightmarePartOam_RightTurret2Idle;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.work1 = gBossWork2;
                    gCurrentSprite.pose = 0x18;
                }
            }
            break;

        case 0x1c:
            NightmarePartDying(gCurrentSprite.primarySpriteRamSlot);

            if (gSpriteData[primaryRamSlot].pose == 0x22)
            {
                SpriteSpawnSecondary(SSPRITE_NIGHTMARE_FALLING_ARM, NIGHTMARE_FALLING_PART_RIGHT_TURRET_2, 0,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x1e;
            }
            break;

        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;
    }
}

void NightmarePartRightTurret3(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case 2:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gSpriteData[primaryRamSlot].pose == 0x3a)
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
                gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
                gCurrentSprite.work1 = 100;
                gCurrentSprite.pose = 0x18;
            }
            break;

        case 0x18:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_RightTurret3Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (--gCurrentSprite.work1 == 0)
                {
                    if (gSpriteData[primaryRamSlot].pose == 0x1c)
                        gCurrentSprite.pOam = sNightmarePartOam_RightTurret3NotFiring;
                    else
                        gCurrentSprite.pOam = sNightmarePartOam_RightTurret3Firing;

                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.pose = 0x1a;
                }
            }
            break;

        case 0x1a:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_RightTurret3Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (gCurrentSprite.pOam == sNightmarePartOam_RightTurret3Firing)
                    NightmarePartSpawnBeam();

                if (SpriteUtilHasCurrentAnimationEnded())
                {
                    gCurrentSprite.pOam = sNightmarePartOam_RightTurret3Idle;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gBossWork2 = gBossWork3;
                    gCurrentSprite.work1 = gBossWork3;
                    gCurrentSprite.pose = 0x18;
                }
            }
            break;

        case 0x1c:
            NightmarePartDying(gCurrentSprite.primarySpriteRamSlot);

            if (gSpriteData[primaryRamSlot].pose == 0x22)
            {
                SpriteSpawnSecondary(SSPRITE_NIGHTMARE_FALLING_ARM, NIGHTMARE_FALLING_PART_RIGHT_TURRET_3, 0,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x1e;
            }
            break;

        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;
    }
}

void NightmarePartLeftTurret1(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case 2:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gSpriteData[primaryRamSlot].pose == 0x3a)
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
                gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
                gCurrentSprite.work1 = 120;
                gCurrentSprite.pose = 0x18;
            }
            break;

        case 0x18:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_LeftTurret1Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (--gCurrentSprite.work1 == 0)
                {
                    if (gSpriteData[primaryRamSlot].pose == 2)
                        gCurrentSprite.pOam = sNightmarePartOam_LeftTurret1NotFiring;
                    else if (gSpriteData[primaryRamSlot].pose == 0x1c)
                        gCurrentSprite.pOam = sNightmarePartOam_LeftTurret1NotFiring;
                    else
                        gCurrentSprite.pOam = sNightmarePartOam_LeftTurret1Firing;

                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.pose = 0x1a;
                }
            }
            break;

        case 0x1a:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_LeftTurret1Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (gCurrentSprite.pOam == sNightmarePartOam_LeftTurret1Firing)
                    NightmarePartSpawnBeam();

                if (SpriteUtilHasCurrentAnimationEnded())
                {
                    gCurrentSprite.pOam = sNightmarePartOam_LeftTurret1Idle;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.work1 = gBossWork2;
                    gCurrentSprite.pose = 0x18;
                }
            }
            break;

        case 0x1c:
            NightmarePartDying(gCurrentSprite.primarySpriteRamSlot);

            if (gSpriteData[primaryRamSlot].pose == 0x22)
            {
                SpriteSpawnSecondary(SSPRITE_NIGHTMARE_FALLING_ARM, NIGHTMARE_FALLING_PART_LEFT_TURRET_1, 0,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x1e;
            }
            break;

        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;
    }
}

void NightmarePartLeftTurret2(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case 2:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gSpriteData[primaryRamSlot].pose == 0x3a)
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
                gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
                gCurrentSprite.work1 = 116;
                gCurrentSprite.pose = 0x18;
            }
            break;

        case 0x18:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_LeftTurret2Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (--gCurrentSprite.work1 == 0)
                {
                    if (gSpriteData[primaryRamSlot].pose == 2)
                        gCurrentSprite.pOam = sNightmarePartOam_LeftTurret2NotFiring;
                    else if (gSpriteData[primaryRamSlot].pose == 0x1c)
                        gCurrentSprite.pOam = sNightmarePartOam_LeftTurret2NotFiring;
                    else
                        gCurrentSprite.pOam = sNightmarePartOam_LeftTurret2Firing;

                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.pose = 0x1a;
                }
            }
            break;

        case 0x1a:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_LeftTurret2Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (gCurrentSprite.pOam == sNightmarePartOam_LeftTurret2Firing)
                    NightmarePartSpawnBeam();

                if (SpriteUtilHasCurrentAnimationEnded())
                {
                    gCurrentSprite.pOam = sNightmarePartOam_LeftTurret2Idle;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.work1 = gBossWork2;
                    gCurrentSprite.pose = 0x18;
                }
            }
            break;

        case 0x1c:
            NightmarePartDying(gCurrentSprite.primarySpriteRamSlot);

            if (gSpriteData[primaryRamSlot].pose == 0x22)
            {
                SpriteSpawnSecondary(SSPRITE_NIGHTMARE_FALLING_ARM, NIGHTMARE_FALLING_PART_LEFT_TURRET_2, 0,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x1e;
            }
            break;

        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;
    }
}

void NightmarePartLeftTurret3(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case 2:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gSpriteData[primaryRamSlot].pose == 0x3a)
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
                gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
                gCurrentSprite.work1 = 112;
                gCurrentSprite.pose = 0x18;
            }
            break;

        case 0x18:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_LeftTurret3Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (--gCurrentSprite.work1 == 0)
                {
                    if (gSpriteData[primaryRamSlot].pose == 0x1c)
                        gCurrentSprite.pOam = sNightmarePartOam_LeftTurret3NotFiring;
                    else
                        gCurrentSprite.pOam = sNightmarePartOam_LeftTurret3Firing;

                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.pose = 0x1a;
                }
            }
            break;

        case 0x1a:
            if (gSpriteData[primaryRamSlot].pose == 0x20)
            {
                gCurrentSprite.pOam = sNightmarePartOam_LeftTurret3Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1c;
                NightmarePartDying(primaryRamSlot);
            }
            else
            {
                if (gCurrentSprite.pOam == sNightmarePartOam_LeftTurret3Firing)
                    NightmarePartSpawnBeam();

                if (SpriteUtilHasCurrentAnimationEnded())
                {
                    gCurrentSprite.pOam = sNightmarePartOam_LeftTurret3Idle;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.work1 = gBossWork2;
                    gCurrentSprite.pose = 0x18;
                }
            }
            break;

        case 0x1c:
            NightmarePartDying(gCurrentSprite.primarySpriteRamSlot);

            if (gSpriteData[primaryRamSlot].pose == 0x22)
            {
                SpriteSpawnSecondary(SSPRITE_NIGHTMARE_FALLING_ARM, NIGHTMARE_FALLING_PART_LEFT_TURRET_3, 0,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x1e;
            }
            break;

        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;
    }
}

void NightmarePartEye(void)
{
    u8 primaryRamSlot;
    u8 mouthRamSlot;
    u16 maxHealth;
    u8 work1;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;
    mouthRamSlot = gCurrentSprite.numberOfXToForm;
    maxHealth = gSpriteData[primaryRamSlot].health;

    if (SPRITE_GET_ISFT(gCurrentSprite) == 16)
        SoundPlayNotAlreadyPlaying(SOUND_NIGHTMARE_HIT_EXPLOSION);
    else if (SPRITE_GET_ISFT(gCurrentSprite) == 5)
        SoundPlayNotAlreadyPlaying(SOUND_NIGHTMARE_HURT);

    switch (gCurrentSprite.pose)
    {
        case 2:
            if (gSpriteData[primaryRamSlot].pose == 0x1a)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pOam = sNightmarePartEyeOam_NotDrooping;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x18;
                gCurrentSprite.health = maxHealth;
                gSubSpriteData1.health = maxHealth;

                ParticleSet(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(2.0f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.25f), PE_0x3A);
                SoundPlay_3b1c(SOUND_NIGHTMARE_MASK_DESTROYED);
            }
            break;

        case 0x18:
            gSpriteData[mouthRamSlot].paletteRow = gCurrentSprite.paletteRow;
            gSubSpriteData1.health = gCurrentSprite.health;
            if (gSubSpriteData1.health < maxHealth * 2 / 3)
            {
                gCurrentSprite.pose = 0x1a;
                gCurrentSprite.pOam = sNightmarePartEyeAndMouthOam_DroopingSlightly;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gSpriteData[mouthRamSlot].status |= SPRITE_STATUS_NOT_DRAWN;
                SoundPlay(SOUND_NIGHTMARE_FACE_SAGGING);
            }
            break;

        case 0x1a:
            gSpriteData[mouthRamSlot].paletteRow = gCurrentSprite.paletteRow;
            gSubSpriteData1.health = gCurrentSprite.health;
            if (gCurrentSprite.currentAnimationFrame != 0)
                gCurrentSprite.frozenPaletteRowOffset = 1;

            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pose = 0x1c;
                gCurrentSprite.pOam = sNightmarePartEyeOam_DroopingSlightly;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gSpriteData[mouthRamSlot].pOam = sNightmarePartMouthOam_DroopingSlightly;
                gSpriteData[mouthRamSlot].animationDurationCounter = 0;
                gSpriteData[mouthRamSlot].currentAnimationFrame = 0;
                gSpriteData[mouthRamSlot].status &= ~SPRITE_STATUS_NOT_DRAWN;
                gSpriteData[mouthRamSlot].frozenPaletteRowOffset = 1;
            }
            break;

        case 0x1c:
            gSpriteData[mouthRamSlot].paletteRow = gCurrentSprite.paletteRow;
            gSubSpriteData1.health = gCurrentSprite.health;
            if (gSubSpriteData1.health < maxHealth / 3)
            {
                gCurrentSprite.pose = 0x1e;
                gCurrentSprite.pOam = sNightmarePartEyeAndMouthOam_DroopingMore;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gSpriteData[mouthRamSlot].status |= SPRITE_STATUS_NOT_DRAWN;
                SoundPlay(SOUND_NIGHTMARE_FACE_SAGGING);
            }
            break;

        case 0x1e:
            gSpriteData[mouthRamSlot].paletteRow = gCurrentSprite.paletteRow;
            gSubSpriteData1.health = gCurrentSprite.health;
            if (gCurrentSprite.currentAnimationFrame != 0)
                gCurrentSprite.frozenPaletteRowOffset = 2;

            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pose = 0x20;
                gCurrentSprite.pOam = sNightmarePartEyeOam_DroopingMore;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gSpriteData[mouthRamSlot].pOam = sNightmarePartMouthOam_DroopingMore;
                gSpriteData[mouthRamSlot].animationDurationCounter = 0;
                gSpriteData[mouthRamSlot].currentAnimationFrame = 0;
                gSpriteData[mouthRamSlot].status &= ~SPRITE_STATUS_NOT_DRAWN;
                gSpriteData[mouthRamSlot].frozenPaletteRowOffset = 2;
            }
            break;

        case 0x20:
            gSpriteData[mouthRamSlot].paletteRow = gCurrentSprite.paletteRow;
            gSubSpriteData1.health = gCurrentSprite.health;
            if (gCurrentSprite.health == 0)
            {
                gCurrentSprite.pose = 0x22;
                gCurrentSprite.work1 = 0;
                gCurrentSprite.invincibilityStunFlashTimer = 0;
                gSpriteData[primaryRamSlot].pose = 0x20;
                gSpriteData[primaryRamSlot].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                gSpriteData[primaryRamSlot].samusCollision = SSC_NONE;
                gSpriteData[primaryRamSlot].work1 = 80;
                gSpriteData[primaryRamSlot].work2 = 0;
            }
            break;

        case 0x22:
            work1 = gCurrentSprite.work1++;
            if ((work1 & 3) == 0)
            {
                if ((work1 & 4) != 0)
                    SPRITE_SET_ABSOLUTE_PALETTE_ROW(gCurrentSprite, SPRITE_FLASHING_PALETTE_ROW);
                else
                    gCurrentSprite.paletteRow = 0;
            }

            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
            {
                gCurrentSprite.paletteRow = 0;
                gCurrentSprite.pose = 0x24;
                gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
            }

            gSpriteData[mouthRamSlot].paletteRow = gCurrentSprite.paletteRow;
            break;

        default:
            if (gSpriteData[primaryRamSlot].spriteId == PSPRITE_GRAVITY_SUIT_ABILITY)
                gCurrentSprite.status = 0;
            break;
    }
}

void NightmarePartMouth(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        default:
            if (gSpriteData[primaryRamSlot].spriteId == PSPRITE_GRAVITY_SUIT_ABILITY)
                gCurrentSprite.status = 0;
            break;

        case 2:
            if (gSpriteData[primaryRamSlot].pose == 0x1a)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pOam = sNightmarePartMouthOam_NotDrooping;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x18;
                gSpriteData[primaryRamSlot].pose = 0x1e;
            }
            break;

        case 0x18:
            if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
                SoundPlay(SOUND_NIGHTMARE_GROAN);

            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
            {
                gCurrentSprite.paletteRow = 0;
                gCurrentSprite.pose = 0x24;
                gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
            }
            break;
    }
}

void NightmarePartEyeSludge(void)
{
    u8 primaryRamSlot;
    u16 maxHealth;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;
    maxHealth = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    switch (gCurrentSprite.pose)
    {
        case 2:
            if (gSubSpriteData1.health < maxHealth * 2 / 3)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pOam = sNightmarePartOam_EyeSludge;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x18;
                SoundPlay(SOUND_NIGHTMARE_EYE_SLUDGE);
            }
            break;

        case 0x18:
            if (gSubSpriteData1.health < maxHealth / 3)
            {
                gCurrentSprite.pOam = sNightmarePartOam_EyeSludgeDroppingToChin;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work1 = 120;
                gCurrentSprite.pose = 0x1a;
                SoundPlay(SOUND_NIGHTMARE_EYE_SLUDGE);
            }
            break;

        case 0x1a:
            if (gSubSpriteData1.health == 0)
            {
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work1 = 80;
                gCurrentSprite.pose = 0x1c;
                SoundPlay(SOUND_NIGHTMARE_EYE_SLUDGE);
            }
            else
            {
                if (--gCurrentSprite.work1 == 0)
                {
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.work1 = 120;
                    SoundPlay(SOUND_NIGHTMARE_EYE_SLUDGE);
                }
            }
            break;

        case 0x1c:
            if (--gCurrentSprite.work1 == 0)
            {
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work1 = 80;
                SoundPlay(SOUND_NIGHTMARE_EYE_SLUDGE);
            }

            if (gSpriteData[primaryRamSlot].pose == 0x19)
            {
                gCurrentSprite.pose = 0x1e;
                gCurrentSprite.work1 = 80;
            }
            break;

        case 0x1e:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (--gCurrentSprite.work1 == 0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x20;
            }
            break;

        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;
    }
}

void NightmarePartChinSludge(void)
{
    u8 primaryRamSlot;
    u16 maxHealth;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;
    maxHealth = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    switch (gCurrentSprite.pose)
    {
        case 2:
            if (gSubSpriteData1.health < maxHealth / 3)
            {
                gCurrentSprite.work1 = 120;
                gCurrentSprite.pose = 0x18;
            }
            break;

        case 0x18:
            if (--gCurrentSprite.work1 == 0)
            {
                gCurrentSprite.status = gCurrentSprite.status & ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pOam = sNightmarePartOam_ChinSludge;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x1a;
                gCurrentSprite.work1 = 100;
            }
            break;

        case 0x1a:
            if (--gCurrentSprite.work1 == 0)
            {
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work1 = 100;
            }

            if (gSpriteData[primaryRamSlot].pose == 0x19)
            {
                gCurrentSprite.pose = 0x1c;
                gCurrentSprite.work1 = 80;
            }
            break;

        case 0x1c:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (--gCurrentSprite.work1 == 0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                gCurrentSprite.pose = 0x1e;
                gSpriteData[primaryRamSlot].pose = 0x1a;
            }
            break;

        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;
    }
}

void NightmarePartGeneratorUpdateGlowingPalette(void)
{
    if ((gCurrentSprite.work1 & 7) == 0)
    {
        gCurrentSprite.paletteRow = sNightmareGeneratorGlowingPaletteRow[gCurrentSprite.work2 & 7];
        gCurrentSprite.work2 += 1;
    }

    gCurrentSprite.work1++;
}

void NightmarePartGeneratorUpdateDyingPalette(void)
{
    u8 work1;

    work1 = gCurrentSprite.work1++;

    if ((work1 & 3) == 0)
    {
        if ((work1 & 4) != 0)
            SPRITE_SET_ABSOLUTE_PALETTE_ROW(gCurrentSprite, SPRITE_FLASHING_PALETTE_ROW);
        else
            gCurrentSprite.paletteRow = 0;
    }
}

void NightmarePartGenerator(void)
{
    u8 primaryRamSlot;
    u16 maxHealth;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    if (SPRITE_GET_ISFT(gCurrentSprite) == 16)
        SoundPlayNotAlreadyPlaying(SOUND_NIGHTMARE_HIT_EXPLOSION);
    else if (SPRITE_GET_ISFT(gCurrentSprite) == 5)
        SoundPlayNotAlreadyPlaying(SOUND_NIGHTMARE_HURT);

    switch (gCurrentSprite.pose)
    {
        case 1:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (gSpriteData[primaryRamSlot].pose == 0x3a)
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_IGNORE_PROJECTILES | SPRITE_STATUS_NOT_DRAWN);
                gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
                gCurrentSprite.pose = 2;
            }
            break;

        case 2:
            NightmarePartGeneratorUpdateGlowingPalette();

            gSubSpriteData1.health = gCurrentSprite.health;
            maxHealth = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            if (gSubSpriteData1.health < maxHealth * 4 / 5)
            {
                gCurrentSprite.pose = 0x18;
                gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningVerySlow;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work0 = 0;
                gSamusPhysics.slowed = 0x80;
                gSpriteData[primaryRamSlot].pose = 0x3b;
                gBossWork3 = 60;
                SoundPlay(SOUND_NIGHTMARE_GENERATOR_ON);
            }
            break;

        case 0x18:
            NightmareMakeMissilesFall();
            NightmarePartGeneratorUpdateGlowingPalette();

            gSubSpriteData1.health = gCurrentSprite.health;
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                if (gCurrentSprite.work0 == 0)
                {
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningSlow;
                }
                else if (gCurrentSprite.work0 == 1)
                {
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningSlightlySlow;
                }
                else if (gCurrentSprite.work0 == 2)
                {
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningSlightlyFast;
                }
                else if (gCurrentSprite.work0 != 3)
                {
                    gCurrentSprite.pose = 0x1a;
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningVeryFast;
                    break;
                }
                else
                {
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningFast;
                }

                gCurrentSprite.work0++;
            }
            break;

        case 0x1a:
            NightmareMakeMissilesFall();
            NightmarePartGeneratorUpdateGlowingPalette();

            gSubSpriteData1.health = gCurrentSprite.health;
            if (gSubSpriteData1.health == 0)
            {
                gCurrentSprite.pose = 0x1c;
                gCurrentSprite.work1 = 0;
                gCurrentSprite.work0 = 0;
                gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningFast;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                
                ApplyMusicSoundFading(
                    sMusicTrackDataRom[sSoundDataEntries[SOUND_NIGHTMARE_GENERATOR_ON].trackGroupNumber].pTrack, 120);
            }
            break;

        case 0x1c:
            NightmareMakeMissilesFall();
            NightmarePartGeneratorUpdateDyingPalette();

            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                if (gCurrentSprite.work0 == 0)
                {
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningSlightlyFast;
                }
                else if (gCurrentSprite.work0 == 1)
                {
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningSlightlySlow;
                }
                else if (gCurrentSprite.work0 == 2)
                {
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningSlow;
                }
                else if (gCurrentSprite.work0 != 3)
                {
                    gCurrentSprite.pose = 0x1e;
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_Stationary;
                    gCurrentSprite.work0 = 60;
                    gCurrentSprite.samusCollision = SSC_NONE;
                    gSpriteData[primaryRamSlot].pose = 0x17;
                    gSamusPhysics.slowed = 0;
                    gBossWork3 = 100;
                    break;
                }
                else
                {
                    gCurrentSprite.pOam = sNightmarePartGeneratorOam_SpinningVerySlow;
                }

                gCurrentSprite.work0++;
            }
            break;

        case 0x1e:
            NightmarePartGeneratorUpdateDyingPalette();
            if (gSpriteData[primaryRamSlot].pose == 0x19)
                gCurrentSprite.pose = 0x20;
            break;

        case 0x20:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 < 30)
            {
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
                if (gCurrentSprite.work0 == 0)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
                    gCurrentSprite.pose = 0x22;
                    ParticleSet(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.25f), PE_0x30);
                }
            }
            else if (gCurrentSprite.work0 == 30)
            {
                ParticleSet(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(1.0f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(1.0f), PE_0x3A);
                gCurrentSprite.paletteRow = 0;
                SoundPlay_3b1c(SOUND_NIGHTMARE_GENERATOR_DESTROYED);
            }
            else
            {
                NightmarePartGeneratorUpdateDyingPalette();
            }
            break;

        default:
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
                gCurrentSprite.status = 0;
            break;
    }

    if (gSamusPhysics.slowed == 0x80)
        NightmareReduceSamusXVelocity();
}

void NightmareBeamInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.125f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.pOam = sNightmareBeamOam;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 2;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
    gCurrentSprite.frozenPaletteRowOffset = 2;

    SoundPlay(SOUND_NIGHTMARE_BEAM);
}

void NightmareBeamMoving(void)
{
    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.3125f);
}

void NightmareFallingArmInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawOrder = 1;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 2;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.health = 0;

    switch (gCurrentSprite.roomSlot)
    {
        case NIGHTMARE_FALLING_PART_RIGHT_ARM_TOP:
            gCurrentSprite.pOam = sNightmarePartOam_RightArmTop;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
            gCurrentSprite.work3 = 2;
            gCurrentSprite.work1 = 10;
            break;

        case NIGHTMARE_FALLING_PART_RIGHT_TURRET_1:
            gCurrentSprite.pOam = sNightmarePartOam_RightTurret1Idle;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.work3 = 3;
            gCurrentSprite.work1 = 8;
            break;

        case NIGHTMARE_FALLING_PART_RIGHT_TURRET_2:
            gCurrentSprite.pOam = sNightmarePartOam_RightTurret2Idle;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.work3 = 4;
            gCurrentSprite.work1 = 6;
            break;

        case NIGHTMARE_FALLING_PART_RIGHT_TURRET_3:
            gCurrentSprite.pOam = sNightmarePartOam_RightTurret3Idle;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.75f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);
            gCurrentSprite.work3 = 5;
            gCurrentSprite.work1 = 4;
            break;

        case NIGHTMARE_FALLING_PART_RIGHT_ARM_BOTTOM:
            gCurrentSprite.pOam = sNightmarePartOam_RightArmBottom;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.work3 = 6;
            gCurrentSprite.work1 = 2;
            break;

        case NIGHTMARE_FALLING_PART_LEFT_TURRET_1:
            gCurrentSprite.pOam = sNightmarePartOam_LeftTurret1Idle;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.work3 = 3;
            gCurrentSprite.work1 = 8;
            break;

        case NIGHTMARE_FALLING_PART_LEFT_TURRET_2:
            gCurrentSprite.pOam = sNightmarePartOam_LeftTurret2Idle;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.5f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.work3 = 4;
            gCurrentSprite.work1 = 6;
            break;

        case NIGHTMARE_FALLING_PART_LEFT_TURRET_3:
            gCurrentSprite.pOam = sNightmarePartOam_LeftTurret3Idle;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.625f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
            gCurrentSprite.work3 = 5;
            gCurrentSprite.work1 = 4;
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }
}

void NightmareFallingArmMoving(void)
{
    u8 offset;
    s16 movement;

    if (gCurrentSprite.work1 > 0)
    {
        if (--gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.roomSlot == 0 || gCurrentSprite.roomSlot == 5)
                ParticleSet(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.25f), gCurrentSprite.xPosition, PE_0x3A);
            else
                ParticleSet(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.25f), gCurrentSprite.xPosition, PE_0x22);
        }
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

        if (gCurrentSprite.roomSlot < 5)
            gCurrentSprite.xPosition += gCurrentSprite.work3;
        else
            gCurrentSprite.xPosition -= gCurrentSprite.work3;
    }
}

void Nightmare(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            NightmareInit();
            break;

        case 0x37:
            NightmareWaitingToAppear();
            break;

        case 0x38:
            NightmareAppearing();
            break;

        case 0x39:
            NightmarePhase1Init();
        case 0x3a:
            NightmarePhase1();
            break;

        case 0x3b:
            NightmarePhase2ResettingPosition();
            break;

        case 1:
            NightmarePhase2MovementInit();
            break;

        case 2:
            NightmarePhase2Movement();
            break;

        case 0x17:
            NightmareMovingToPhase3Init();
        case 0x18:
            NightmareMovingToPhase3();
            break;

        case 0x19:
            NightmareReachedPhase3Position();
            break;

        case 0x1a:
            NightmarePhase3SlowMovementInit();
            break;

        case 0x1b:
            NightmarePhase3FastMovementInit();
        case 0x1c:
            NightmarePhase3FastMovement();
            break;

        case 0x1e:
            NightmarePhase3SlowMovement();
            break;

        case 0x20:
            NightmareMovingToDeathPosition();
            break;

        case 0x22:
            NightmareTurningIntoCoreX();
            break;
    }

    NightmarePlaySound();
    SpriteUtilUpdateSubSpriteData1Animation();
    NightmareSyncSubSprites();
}

void NightmarePart(void)
{
    if (gCurrentSprite.pose == 0)
    {
        NightmarePartInit();
        return;
    }

    switch (gCurrentSprite.roomSlot)
    {
        case NIGHTMARE_PART_GENERATOR:
            NightmarePartGenerator();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_EYE_SLUDGE:
            NightmarePartEyeSludge();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_CHIN_SLUDGE:
            NightmarePartChinSludge();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_EYE:
            NightmarePartEye();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_MOUTH:
            NightmarePartMouth();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_RIGHT_TURRET_1:
            NightmarePartRightTurret1();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_RIGHT_TURRET_2:
            NightmarePartRightTurret2();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_RIGHT_TURRET_3:
            NightmarePartRightTurret3();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_LEFT_TURRET_1:
            NightmarePartLeftTurret1();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_LEFT_TURRET_2:
            NightmarePartLeftTurret2();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_LEFT_TURRET_3:
            NightmarePartLeftTurret3();
            SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
            break;

        case NIGHTMARE_PART_RIGHT_ARM_TOP:
            NightmarePartRightArmTop();
            NightmareSyncSubSprites();
            break;

        case NIGHTMARE_PART_RIGHT_ARM_BOTTOM:
            NightmarePartRightArmBottom();
            NightmareSyncSubSprites();
            break;
    }
}

void NightmareBeam(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            NightmareBeamInit();
            break;

        case 2:
            NightmareBeamMoving();
            break;
    }
}

void NightmareFallingArm(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            NightmareFallingArmInit();
            break;

        case 2:
            NightmareFallingArmMoving();
            break;
    }
}
