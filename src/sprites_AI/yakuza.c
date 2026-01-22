#include "data/sprites/yakuza.h"

#include "gba.h"
#include "globals.h"
#include "macros.h"

#include "data/frame_data_pointers.h"
#include "data/sprite_data.h"
#include "data/sprites/core_x.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/samus.h"

#include "structs/samus.h"

void YakuzaSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    u16 oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];

    if (gCurrentSprite.pOam != sYakuzaFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sYakuzaFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition =
        gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition =
        gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

void YakuzaUpdatePalette(void)
{
    u32 update;
    u16 health;
    u16 maxHealth;
    const u16* pPal;

    update = FALSE;
    health = gCurrentSprite.health;
    maxHealth = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    switch (gBossWork1)
    {
        case 0:
            if (health <= maxHealth * 2 / 3)
            {
                pPal = sYakuzaPal + 2 * PAL_ROW;
                gBossWork1 = 1;
                update = TRUE;
            }
            break;

        case 1:
            if (health <= maxHealth / 4)
            {
                pPal = sYakuzaPal + 3 * PAL_ROW;
                gBossWork1 = 2;
                update = TRUE;
            }
            break;
    }

    if (update)
        DMA_SET(3, pPal, PALRAM_OBJ + 8 * PAL_ROW_SIZE, C_32_2_16(DMA_ENABLE, 1 * PAL_ROW))
}

boolu8 YakuzaUpdateGrabbedSamus(void)
{
    if (gSamusData.pose == SPOSE_GRABBED_BY_YAKUZA)
    {
        gSamusData.yPosition = gSubSpriteData1.yPosition + BLOCK_TO_SUB_PIXEL(3.0f);
        gSamusData.xPosition = gSubSpriteData1.xPosition;
        SpriteUtilTakeConstantDamageFromYakuza();
        return TRUE;
    }

    return FALSE;
}

boolu8 YakuzaCheckCollidingWithRightWall(void)
{
    // Checks for X position relative to BG1
    if ((u16)(SUB_PIXEL_TO_PIXEL_(gSubSpriteData1.xPosition) - SUB_PIXEL_TO_PIXEL_(gBg1XPosition)) >=
        SCREEN_SIZE_X - 24)
        return TRUE;
    return FALSE;
}

boolu8 YakuzaCheckCollidingWithLeftWall(void)
{
    if ((u16)(SUB_PIXEL_TO_PIXEL_(gSubSpriteData1.xPosition) - SUB_PIXEL_TO_PIXEL_(gBg1XPosition)) <= 24)
        return TRUE;

    return FALSE;
}

boolu8 YakuzaCheckCollidingWithFloor(void)
{
    if (gSubSpriteData1.yPosition > BLOCK_TO_SUB_PIXEL(28.96875f))
        return TRUE;

    return FALSE;
}

boolu8 YakuzaCheckCollidingWithCeiling(void)
{
    if (gSamusData.pose == SPOSE_GRABBED_BY_YAKUZA)
    {
        if (gSubSpriteData1.yPosition >= BLOCK_TO_SUB_PIXEL(16.f))
            return FALSE;
        else
            return TRUE;
    }
    else
    {
        if (gSubSpriteData1.yPosition >= BLOCK_TO_SUB_PIXEL(24.f))
            return FALSE;
        else
            return TRUE;
    }
}

boolu8 YakuzaXMovement(u16 movement)
{
    boolu8 collided;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        collided = YakuzaCheckCollidingWithRightWall();
        if (!collided)
            gSubSpriteData1.xPosition += movement;
    }
    else
    {
        collided = YakuzaCheckCollidingWithLeftWall();
        if (!collided)
            gSubSpriteData1.xPosition -= movement;
    }

    return collided;
}

boolu8 YakuzaYMovement(u16 movement)
{
    boolu8 collided;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        collided = YakuzaCheckCollidingWithFloor();
        if (!collided)
        {
            gSubSpriteData1.yPosition += movement;
        }
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            collided = FALSE;
        }
    }
    else
    {
        collided = YakuzaCheckCollidingWithCeiling();
        if (!collided)
            gSubSpriteData1.yPosition -= movement;
    }

    return collided;
}

void YakuzaGrabbedSamusInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b0f98;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x28;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;

    SoundPlay(SOUND_13F);
}

void YakuzaGrabbedSamus(void)
{
    if (!YakuzaUpdateGrabbedSamus())
    {
        gCurrentSprite.pose = 0x2f;
        return;
    }

    if (gCurrentSprite.work2 == 0)
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
        {
            gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1178;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            gCurrentSprite.work2 += 1;
        }
    }
    else
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
        {
            gCurrentSprite.pose = 0x2a;
            gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1188;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            gCurrentSprite.work2 = 0;
        }
    }
}

void YakuzaPullingSamus(void)
{
    if (!YakuzaUpdateGrabbedSamus())
    {
        gCurrentSprite.pose = 0x2f;
        return;
    }

    if (gCurrentSprite.work2 == 0)
    {
        if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
            SoundPlay(SOUND_136);

        if (YakuzaYMovement(4))
        {
            gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b11b0;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            gCurrentSprite.work2 += 1;
        }
    }
    else
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
        {
            gCurrentSprite.pose = 0x2c;
            gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b11c0;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            gCurrentSprite.work1 = 60;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        }
    }
}

void YakuzaHoldingSamusHigh(void)
{
    if (!YakuzaUpdateGrabbedSamus())
    {
        gCurrentSprite.pose = 0x2f;
        return;
    }

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x2e;
        gCurrentSprite.work4 = 0;
    }
}

void YakuzaSlammingSamus(void)
{
    boolu8 grabbing;
    u8 offset;
    s16 movement;
    u32 blockTop;

    grabbing = YakuzaUpdateGrabbedSamus();
    offset = gCurrentSprite.work4;
    movement = sYakuzaSlammingSpeed[offset];

    if (movement == SHORT_MAX)
    {
        movement = sYakuzaSlammingSpeed[offset - 1];
        gSubSpriteData1.yPosition += movement;
    }
    else
    {
        offset++;
        gCurrentSprite.work4 = offset;
        gSubSpriteData1.yPosition += movement;
    }

    if (grabbing)
    {
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition + BLOCK_TO_SUB_PIXEL(3.0f),
            gSubSpriteData1.xPosition);
        if (gPreviousCollisionCheck != 0)
        {
            SpriteUtilTakeDamageFromYakuzaSlamming();
        }
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition + BLOCK_TO_SUB_PIXEL(1.125f),
        gSubSpriteData1.xPosition);
    if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) != 0)
    {
        gSubSpriteData1.yPosition = blockTop - BLOCK_TO_SUB_PIXEL(1.125f);
        gCurrentSprite.pose = 0x2f;

        ScreenShakeStartVertical(60, 0x81);
        ParticleSet(blockTop, gSubSpriteData1.xPosition, PE_OUTWARD_SMOKE);
        ParticleSet(blockTop + BLOCK_TO_SUB_PIXEL(0.9375f), gSubSpriteData1.xPosition, PE_OUTWARD_SMOKE);
        SoundPlay(SOUND_13A);
    }
}

void YakuzaReleasingSamusInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b0fc0;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x30;
}

void YakuzaReleasingSamus(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = 9;
}

void YakuzaAfterReleasingSamusInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b0f28;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0xa;
}

void YakuzaAfterReleasingSamus(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        gCurrentSprite.samusCollision = SSC_YAKUZA_CAN_GRAB;
        gCurrentSprite.pose = 1;
        SpriteUtilMakeSpriteFaceSamusDirection();
    }
}

void YakuzaInit(void)
{
    if (gEquipment.suitMiscStatus & SMF_SPACE_JUMP)
    {
        gCurrentSprite.status = 0;
    }
    else
    {
        gBossWork1 = 0;

        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(8.0f);

        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        gCurrentSprite.drawDistanceTop = 36;
        gCurrentSprite.drawDistanceBottom = 36;
        gCurrentSprite.drawDistanceHorizontal = 36;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.125f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.125f);
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.drawOrder = 12;
        gCurrentSprite.roomSlot = YAKUZA_PART_BODY;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gSubSpriteData1.health = 1;
        gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b0f28;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.samusCollision = SSC_YAKUZA_CAN_GRAB;
        gCurrentSprite.status |= (SPRITE_STATUS_HIDDEN | SPRITE_STATUS_FACING_DOWN);
        gCurrentSprite.work0 = 0;
        gCurrentSprite.pose = 0x37;

        SpriteSpawnSecondary(SSPRITE_YAKUZA_PART, YAKUZA_PART_EYE, 0, gCurrentSprite.primarySpriteRamSlot,
            gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_YAKUZA_PART, YAKUZA_PART_LEGS, 0, gCurrentSprite.primarySpriteRamSlot,
            gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
    }
}

void YakuzaWaitingToAppear(void)
{
    if (gSamusData.yPosition >= BLOCK_TO_SUB_PIXEL(28.f))
    {
        gCurrentSprite.pose = 0x38;
        gCurrentSprite.work1 = 60;
    }
}

void YakuzaAboutToAppear(void)
{
    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 7;
        gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
        ScreenShakeStartHorizontal(60, 0x81);
        ScreenShakeStartVertical(60, 0x81);
        gBossWork2 = 1;
        SoundPlay_3b1c(SOUND_12F);
    }
}

void YakuzaIdleBeforeNewRoundInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b0f28;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 8;
    gCurrentSprite.samusCollision = SSC_YAKUZA_CAN_GRAB;
}

void YakuzaIdleBeforeNewRound(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gCurrentSprite.work0 > 0)
        {
            gCurrentSprite.work0--;
            gCurrentSprite.pose = 1;
            SpriteUtilMakeSpriteFaceSamusDirection();
        }
        else
        {
            gCurrentSprite.pose = 0x31;
        }
    }
}

void YakuzaBeginSweepInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b0f50;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 2;
}

void YakuzaBeginSweep(void)
{
    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b0f60;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x18;
    }
}

void YakuzaSweeping(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlay(SOUND_136);

    if (YakuzaYMovement(3))
    {
        if (SpriteUtilHasSubSprite1AnimationEnded())
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b0f88;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
            gCurrentSprite.pose = 0x1a;
        }
    }
    else
    {
        if (YakuzaXMovement(8))
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
}

void YakuzaSweepingEnd(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
        gCurrentSprite.pose = 7;
}

void YakuzaOpeningMouthInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b0fe8;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.work1 = 0;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.pose = 0x32;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.0f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5625f);
    gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;

    SoundPlay(SOUND_137);
}

void YakuzaOpeningMouth(void)
{
    u8 offset;
    u16 maxHealth;

    switch (gCurrentSprite.work2)
    {
        case 0:
            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1040;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.work2++;
                SoundPlay(SOUND_138);
            }
            break;

        case 1:
            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1050;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.work2++;
                offset = sYakuzaMouthStartGlowingPalOffset[0] - 8;
                DMA_SET(3, sYakuzaMouthGlowingPal[offset], PALRAM_OBJ + 9 * PAL_ROW_SIZE,
                    C_32_2_16(DMA_ENABLE, 1 * PAL_ROW));
                gCurrentSprite.work3 = 0;
                gCurrentSprite.work1 = 3;
            }
            break;

        case 2:
            if (--gCurrentSprite.work1 == 0)
            {
                if (gCurrentSprite.work3 <= 16)
                {
                    gCurrentSprite.work3++;
                    gCurrentSprite.work1 = 3;
                    offset = sYakuzaMouthStartGlowingPalOffset[gCurrentSprite.work3] - 8;
                    DMA_SET(3, sYakuzaMouthGlowingPal[offset], PALRAM_OBJ + 9 * PAL_ROW_SIZE,
                        C_32_2_16(DMA_ENABLE, 1 * PAL_ROW));
                }
                else
                {
                    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1060;
                    gSubSpriteData1.animationDurationCounter = 0;
                    gSubSpriteData1.currentAnimationFrame = 0;
                    gCurrentSprite.work2++;
                    offset = sYakuzaMouthGlowingPalOffset[0] - 8;
                    DMA_SET(3, sYakuzaMouthGlowingPal[offset], PALRAM_OBJ + 9 * PAL_ROW_SIZE,
                        C_32_2_16(DMA_ENABLE, 1 * PAL_ROW));
                    gCurrentSprite.work3 = 0;
                    gCurrentSprite.work1 = 4;
                }
            }
            break;

        case 3:
            if (--gCurrentSprite.work1 == 0)
            {
                if (gCurrentSprite.work3 <= 10)
                {
                    gCurrentSprite.work3++;
                    gCurrentSprite.work1 = 4;
                    offset = sYakuzaMouthGlowingPalOffset[gCurrentSprite.work3] - 8;
                    DMA_SET(3, sYakuzaMouthGlowingPal[offset], PALRAM_OBJ + 9 * PAL_ROW_SIZE,
                        C_32_2_16(DMA_ENABLE, 1 * PAL_ROW));
                }
                else
                {
                    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1078;
                    gSubSpriteData1.animationDurationCounter = 0;
                    gSubSpriteData1.currentAnimationFrame = 0;
                    gCurrentSprite.work2++;

                    SpriteSpawnSecondary(SSPRITE_YAKUZA_PROJECTILE, 0, 0, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(2.3125f), gCurrentSprite.xPosition, 0);
                    SpriteSpawnSecondary(SSPRITE_YAKUZA_PROJECTILE, 1, 0, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(2.4375f), gCurrentSprite.xPosition, 0);
                    SpriteSpawnSecondary(SSPRITE_YAKUZA_PROJECTILE, 1, 0, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(2.4375f), gCurrentSprite.xPosition,
                        SPRITE_STATUS_X_FLIP);

                    if (gBossWork2)
                    {
                        gBossWork2 = FALSE;
                        PlayMusic(MUSIC_SERRIS_YAKUZA_BATTLE, 7);
                        SoundPlay_3b1c(SOUND_130);
                    }
                    else
                    {
                        SoundPlay(SOUND_139);
                    }
                }
            }
            break;

        case 4:
            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1050;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.work2++;
                offset = sYakuzaMouthEndGlowingPalOffset[0] - 8;
                DMA_SET(3, sYakuzaMouthGlowingPal[offset], PALRAM_OBJ + 9 * PAL_ROW_SIZE,
                    C_32_2_16(DMA_ENABLE, 1 * PAL_ROW));
                gCurrentSprite.work3 = 0;
                gCurrentSprite.work1 = 2;
            }
            break;

        case 5:
            if (--gCurrentSprite.work1 == 0)
            {
                if (gCurrentSprite.work3 <= 5)
                {
                    gCurrentSprite.work3++;
                    gCurrentSprite.work1 = 2;
                    offset = sYakuzaMouthEndGlowingPalOffset[gCurrentSprite.work3] - 8;
                    DMA_SET(3, sYakuzaMouthGlowingPal[offset], PALRAM_OBJ + 9 * PAL_ROW_SIZE,
                        C_32_2_16(DMA_ENABLE, 1 * PAL_ROW));
                }
                else
                {
                    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b10a0;
                    gSubSpriteData1.animationDurationCounter = 0;
                    gSubSpriteData1.currentAnimationFrame = 0;
                    gCurrentSprite.work2++;
                }
            }
            break;

        case 6:
            if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
            {
                maxHealth = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
                if (gCurrentSprite.health < maxHealth / 2)
                {
                    gCurrentSprite.health = maxHealth / 2;
                    gCurrentSprite.pose = 0x1f;
                    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
                }
                else
                {
                    gCurrentSprite.pose = 0x1b;
                }
            }
            break;
    }
}

void YakuzaMouthOpenedInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1000;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x1c;
    gCurrentSprite.work1 = 20;
}

void YakuzaMouthOpened(void)
{
    if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.pose = 0x1d;
}

void YakuzaClosingMouthInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1028;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x1e;
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.125f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.125f);
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
}

void YakuzaClosingMouth(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        gCurrentSprite.pose = 7;
        // Do between 1-4 sweeping rounds
        gCurrentSprite.work0 = gSpriteRandomNumber / 4 + 1;
    }
}

void YakuzaPhase1DyingInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b10b0;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x20;
    gCurrentSprite.work1 = 120;

    ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, PE_0x2F);
    SoundPlay_3b1c(SOUND_132);
}

void YakuzaPhase1Dying(void)
{
    u8 work1;

    if (gSubSpriteData1.yPosition <= BLOCK_TO_SUB_PIXEL(24.96875f))
        gSubSpriteData1.yPosition += BLOCK_TO_SUB_PIXEL(0.0625f);

    work1 = gCurrentSprite.work1;
    if ((work1 & 3) == 0)
    {
        if (work1 & 4)
            SPRITE_SET_ABSOLUTE_PALETTE_ROW(gCurrentSprite, SPRITE_FLASHING_PALETTE_ROW);
        else
            gCurrentSprite.paletteRow = 0;
    }

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x21;
        gCurrentSprite.paletteRow = 0;
    }
}

void YakuzaUpdateHitboxAndImmunity(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ROTATION_SCALING_WHOLE)
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    }
    else
    {
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.0f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
    }
}

void YakuzaLosingLegsInit(void)
{
    u16 y;
    u16 x;
    u8 primaryRamSlot;

    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1128;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = 0x22;
    gCurrentSprite.work1 = 0x1e;
    gCurrentSprite.scaling = Q_8_8(1);
    gCurrentSprite.rotation = 0;
    gCurrentSprite.work3 = gSpriteRandomNumber + 1;
    gCurrentSprite.work4 = 0x20;

    gSubSpriteData1.health = 0;

    if (gSamusData.xPosition < gSubSpriteData1.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;
    y = gCurrentSprite.yPosition, x = gCurrentSprite.xPosition;
    SpriteSpawnSecondary(SSPRITE_YAKUZA_FALLING_LEG, 0, 0, primaryRamSlot, y - BLOCK_TO_SUB_PIXEL(0.25f),
        x - BLOCK_TO_SUB_PIXEL(1.f), 0);
    SpriteSpawnSecondary(SSPRITE_YAKUZA_FALLING_LEG, 1, 0, primaryRamSlot, y - BLOCK_TO_SUB_PIXEL(0.5f),
        x - BLOCK_TO_SUB_PIXEL(1.f), 0);
    SpriteSpawnSecondary(SSPRITE_YAKUZA_FALLING_LEG, 2, 0, primaryRamSlot, y - BLOCK_TO_SUB_PIXEL(1.f),
        x - BLOCK_TO_SUB_PIXEL(1.f), 0);
    SpriteSpawnSecondary(SSPRITE_YAKUZA_FALLING_LEG, 3, 0, primaryRamSlot, y - BLOCK_TO_SUB_PIXEL(0.25f),
        x + BLOCK_TO_SUB_PIXEL(1.f), 0);
    SpriteSpawnSecondary(SSPRITE_YAKUZA_FALLING_LEG, 4, 0, primaryRamSlot, y - BLOCK_TO_SUB_PIXEL(0.5f),
        x + BLOCK_TO_SUB_PIXEL(1.f), 0);
    SpriteSpawnSecondary(SSPRITE_YAKUZA_FALLING_LEG, 5, 0, primaryRamSlot, y - BLOCK_TO_SUB_PIXEL(1.f),
        x + BLOCK_TO_SUB_PIXEL(1.f), 0);
}

void YakuzaLosingLegs(void)
{
    if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.pose = 0x24;

    YakuzaUpdateHitboxAndImmunity();
}

void YakuzaPhase2Init(void)
{
    gCurrentSprite.pose = 0x24;
    gCurrentSprite.work4 = 0;

    if (gSamusData.xPosition < gSubSpriteData1.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

void YakuzaPhase2(void)
{
    u8 jump;
    s16 movement;
    u32 blockTop;

    jump = FALSE;
    movement = gCurrentSprite.work3;

    if (SPRITE_GET_ISFT(gCurrentSprite) < 5 && gCurrentSprite.status & SPRITE_STATUS_DOUBLE_SIZE)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition,
                gSubSpriteData1.xPosition + BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            else
                gSubSpriteData1.xPosition += movement;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition,
                gSubSpriteData1.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            else
                gSubSpriteData1.xPosition -= movement;
        }
    }

    movement = sYakuzaPhase2Speed[DIV_SHIFT(gCurrentSprite.work4, 4)];

    if (gCurrentSprite.work4 < ARRAY_SIZE(sYakuzaPhase2Speed) * 4 - 1)
        gCurrentSprite.work4 += 1;

    gSubSpriteData1.yPosition += movement;

    if (movement > 0)
    {
        if (gCurrentSprite.rotation != 0)
        {
            gCurrentSprite.rotation += Q_8_8(1.f / 8);
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ROTATION_SCALING_WHOLE)
            {
                gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1128;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;
                gCurrentSprite.status &= ~SPRITE_STATUS_ROTATION_SCALING_WHOLE;

                SpriteSpawnSecondary(SSPRITE_YAKUZA_PROJECTILE, 0, 0, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(2.3125f), gCurrentSprite.xPosition, 0);
                SoundPlay(SOUND_140);
            }
        }

        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(
            gSubSpriteData1.yPosition + BLOCK_TO_SUB_PIXEL(2.0f), gSubSpriteData1.xPosition);
        if (gPreviousVerticalCollisionCheck != 0)
        {
            gSubSpriteData1.yPosition = blockTop - BLOCK_TO_SUB_PIXEL(2.f);
            gCurrentSprite.work4 = 0;
            jump++;
        }
        else
        {
            if (gSamusData.yPosition < gSubSpriteData1.yPosition)
            {
                gCurrentSprite.work4 = 0;
                jump++;
            }

            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition + BLOCK_TO_SUB_PIXEL(5.0f),
                gSubSpriteData1.xPosition);
            if (gPreviousCollisionCheck != 0 &&
                (gSpriteRandomNumber == 8 || !(gCurrentSprite.status & SPRITE_STATUS_DOUBLE_SIZE)))
            {
                if ((gCurrentSprite.work4 & 1) != 0)
                    jump++;
                gCurrentSprite.work4 = 0;
            }

            SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition + BLOCK_TO_SUB_PIXEL(3.5f),
                gSubSpriteData1.xPosition);
            if (gPreviousCollisionCheck != 0 && gSpriteRandomNumber == 14)
            {
                if ((gCurrentSprite.work4 & 1) != 0)
                    jump++;
                gCurrentSprite.work4 = 0;
            }

            if (SPRITE_GET_ISFT(gCurrentSprite) == 16 && gSubSpriteData1.yPosition > BLOCK_TO_SUB_PIXEL(21.96875f))
            {
                jump++;
                gCurrentSprite.work4 = 0;
            }
        }

        if (jump)
        {
            if (gSamusData.xPosition < gSubSpriteData1.xPosition)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            else
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

            gCurrentSprite.work3 = gSpriteRandomNumber + 1;
        }

        if (gCurrentSprite.work4 == 0)
            SoundPlay(SOUND_13B);
    }
    else
    {
        gCurrentSprite.status |= (SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING_WHOLE);
        gCurrentSprite.rotation += Q_8_8(1.f / 8);

        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition - BLOCK_TO_SUB_PIXEL(2.0f),
            gSubSpriteData1.xPosition);
        if (gPreviousCollisionCheck != 0 || gSubSpriteData1.yPosition <= BLOCK_TO_SUB_PIXEL(21.96875f))
            gSubSpriteData1.yPosition -= movement;

        if ((gCurrentSprite.work4 & 0xf) == 0)
            SoundPlay(SOUND_13B);
    }

    YakuzaUpdateHitboxAndImmunity();
}

void YakuzaPhase2DyingInit(void)
{
    gSubSpriteData1.pMultiOam = sYakuzaMultiSpriteData_3b1160;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = 0x48;
    gCurrentSprite.work1 = 60;
    gCurrentSprite.status &= ~SPRITE_STATUS_DOUBLE_SIZE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.health = 1;
}

void YakuzaPhase2Dying(void)
{
    u16 y;
    u16 x;

    if (gSubSpriteData1.yPosition <= BLOCK_TO_SUB_PIXEL(24.96875f))
        gSubSpriteData1.yPosition += BLOCK_TO_SUB_PIXEL(0.0625f);

    y = gSubSpriteData1.yPosition, x = gSubSpriteData1.xPosition;
    gCurrentSprite.work1--;

    switch (gCurrentSprite.work1)
    {
        case 40:
            ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(0.25f), PE_0x2F);
            SoundPlay_3b1c(SOUND_134);
            break;

        case 35:
            ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.5f), x - BLOCK_TO_SUB_PIXEL(0.25f), PE_0x25);
            break;

        case 30:
            ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.5f), x + BLOCK_TO_SUB_PIXEL(0.4375f), PE_0x2F);
            break;

        case 25:
            ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.0f), x + BLOCK_TO_SUB_PIXEL(0.5f), PE_0x25);
            break;

        case 20:
            ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.5f), x - BLOCK_TO_SUB_PIXEL(0.25f), PE_0x26);
            break;

        case 15:
            ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(0.25f), PE_0x2F);
            break;

        case 10:
            ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.0f), x + BLOCK_TO_SUB_PIXEL(0.4375f), PE_0x25);
            break;

        case 5:
            ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.25f), x, PE_0x3A);
            break;

        case 0:
            gCurrentSprite.pose = 0x49;
            break;
    }
}

void YakuzaTurningIntoCoreXInit(void)
{
    gCurrentSprite.pose = 0x4a;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
}

void YakuzaTurningIntoCoreX(void)
{
    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    gCurrentSprite.workY--;

    if (gCurrentSprite.workY < sizeof(sSpaceJumpCoreXGfx) / 512)
        SpriteLoadGfx(PSPRITE_SPACE_JUMP_ABILITY, 0, gCurrentSprite.workY);
    else if (gCurrentSprite.workY == sizeof(sSpaceJumpCoreXGfx) / 512)
        SpriteLoadPal(PSPRITE_SPACE_JUMP_ABILITY, 0, ARRAY_SIZE(sSpaceJumpCoreXPal) / 16);

    if (gCurrentSprite.workY == 0)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
        gCurrentSprite.spriteId = PSPRITE_SPACE_JUMP_ABILITY;
    }
}

void YakuzaPartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = 2;

    switch (gCurrentSprite.roomSlot)
    {
        case YAKUZA_PART_EYE:
            gCurrentSprite.drawOrder = 11;
            gCurrentSprite.drawDistanceTop = 8;
            gCurrentSprite.drawDistanceBottom = 8;
            gCurrentSprite.drawDistanceHorizontal = 8;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.work1 = 0;
            gCurrentSprite.work2 = 0;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case YAKUZA_PART_LEGS:
            gCurrentSprite.drawOrder = 13;
            gCurrentSprite.drawDistanceTop = 40;
            gCurrentSprite.drawDistanceBottom = 40;
            gCurrentSprite.drawDistanceHorizontal = 56;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.0f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.5f);
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = 1;
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }

    gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
    YakuzaSyncSubSprites();
}

void YakuzaPartLegsIdle(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
    {
        if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_HIDDEN)
            return;
        gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
    }

    if (gSamusData.pose == SPOSE_GRABBED_BY_YAKUZA)
        gCurrentSprite.samusCollision = SSC_NONE;
    else
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    if (gSpriteData[primaryRamSlot].hitboxBottom == BLOCK_TO_SUB_PIXEL(1.5f))
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
    else
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.6875f);
}

void YakuzaPartLegsDead(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
    {
        gCurrentSprite.status = 0;
    }
    else
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_ROTATION_SCALING_WHOLE)
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    }
}

void YakuzaPartEyeIdle(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_ROTATION_SCALING_WHOLE)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.status |= SPRITE_STATUS_HIDDEN;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        {
            if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_HIDDEN)
                return;
            gCurrentSprite.status &= ~SPRITE_STATUS_HIDDEN;
        }

        gCurrentSprite.paletteRow = gSpriteData[primaryRamSlot].paletteRow;

        if (gCurrentSprite.work2 == 0)
        {
            if (SPRITE_GET_ISFT(gSpriteData[primaryRamSlot]) == 16)
            {
                gCurrentSprite.work1 = 2;
                gCurrentSprite.work2++;
                gCurrentSprite.pOam = sYakuzaPartOam_3b7240;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            }
            else if (gSpriteData[primaryRamSlot].pose == 7 || gSpriteData[primaryRamSlot].pose == 9)
            {
                if ((gSpriteRandomNumber & 3) < 3)
                {
                    gCurrentSprite.work1 = gSpriteRandomNumber & 1;
                    gCurrentSprite.work2 += 1;
                    gCurrentSprite.pOam = sYakuzaPartOam_3b7240;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                }
            }
        }
        else
        {
            if (SPRITE_GET_ISFT(gSpriteData[primaryRamSlot]) > 0)
                gCurrentSprite.animationDurationCounter += 2;

            if (SpriteUtilHasCurrentAnimationEnded())
            {
                if (gCurrentSprite.work1 > 0)
                {
                    gCurrentSprite.work1--;
                }
                else
                {
                    gCurrentSprite.work2 = 0;
                    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                }
            }
        }
    }
}

void YakuzaPartEyePhase2(void)
{
    u8 primaryRamSlot;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gSpriteData[primaryRamSlot].status & SPRITE_STATUS_MOSAIC)
        gCurrentSprite.status = 0;
}

void YakuzaProjectileInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 4;

    if (gSubSpriteData1.health > 0)
    {
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.drawDistanceTop = 40;
        gCurrentSprite.drawDistanceBottom = 0;
        gCurrentSprite.drawDistanceHorizontal = 16;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.375f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.375f);
        gCurrentSprite.pOam = sYakuzaProjectileFireOam_Burning1;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 2;
        gCurrentSprite.health = 0;
    }
    else
    {
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
        gCurrentSprite.drawDistanceTop = 24;
        gCurrentSprite.drawDistanceBottom = 8;
        gCurrentSprite.drawDistanceHorizontal = 16;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.4375f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.4375f);
        gCurrentSprite.pOam = sYakuzaProjectileSpitOam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = 0x28;
        gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
        gCurrentSprite.health = 1;
    }
}

void YakuzaProjectileExploding(void)
{
    ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_EXPLOSION_SMOKE);
    SoundPlay(SOUND_RANDOM_SPRITE_DEBRIS);
    gCurrentSprite.status = 0;
}

void YakuzaProjectileSpitFalling(void)
{
    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.1875f);

    if (gCurrentSprite.health == 0)
        YakuzaProjectileExploding();
}

void YakuzaProjectileFireFalling(void)
{
    u32 blockTop;

    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.1875f);

    if (gCurrentSprite.roomSlot != 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.1875f);
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5625f));
        }
        else
        {
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.1875f);
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5625f));
        }

        if (gPreviousCollisionCheck != 0)
            gCurrentSprite.roomSlot = 0;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != 0)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.work1 = 120;
        gCurrentSprite.work3 = 0;

        SoundPlay(SOUND_13C);
    }
}

void YakuzaProjectileFireBurning1(void)
{
    u8 offset;
    s16 movement;

    offset = gCurrentSprite.work3;
    movement = sYakuzaFireBurningSpeed[offset];

    if (sYakuzaFireBurningSpeed[offset] == SHORT_MAX)
    {
        movement = sYakuzaFireBurningSpeed[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work3 = offset;
    gCurrentSprite.xPosition += movement;

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.work1 = 80;
        gCurrentSprite.pose = 0x1a;
        gCurrentSprite.pOam = sYakuzaProjectileFireOam_Burning2;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);

        SoundPlay(SOUND_13D);
    }
    else if ((gCurrentSprite.work1 & 0xf) == 0)
    {
        SoundPlay(SOUND_13C);
    }
}

void YakuzaProjectileFireBurning2(void)
{
    u8 offset;
    s16 movement;

    offset = gCurrentSprite.work3;
    movement = sYakuzaFireBurningSpeed[offset];

    if (sYakuzaFireBurningSpeed[offset] == SHORT_MAX)
    {
        movement = sYakuzaFireBurningSpeed[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work3 = offset;
    gCurrentSprite.xPosition += movement;

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.work1 = 60;
        gCurrentSprite.pose = 0x1c;
        gCurrentSprite.pOam = sYakuzaProjectileFireOam_Burning3;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.1875f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.1875f);

        SoundPlay(SOUND_13E);
    }
    else if ((gCurrentSprite.work1 & 0xf) == 0)
    {
        SoundPlay(SOUND_13D);
    }
}

void YakuzaProjectileFireBurning3(void)
{
    u8 offset;
    s16 movement;

    offset = gCurrentSprite.work3;
    movement = sYakuzaFireBurningSpeed[offset];

    if (sYakuzaFireBurningSpeed[offset] == SHORT_MAX)
    {
        movement = sYakuzaFireBurningSpeed[0];
        offset = 0;
    }

    offset++;
    gCurrentSprite.work3 = offset;
    gCurrentSprite.xPosition += movement;

    if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.work1 = 60;
        gCurrentSprite.pose = 0x1e;
    }

    if ((gCurrentSprite.work1 & 0xf) == 0)
        SoundPlay(SOUND_13E);
}

void YakuzaProjectileFireBurning4(void)
{
    if (gCurrentSprite.work1 < 30)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
        if ((gCurrentSprite.work1 & 1) == 0)
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    }

    if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.status = 0;
}

void YakuzaFallingLegInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawOrder = 2;
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
        case 0:
            gCurrentSprite.pOam = sYakuzaPartOam_3b7320;
            gCurrentSprite.drawDistanceTop = 8;
            gCurrentSprite.drawDistanceBottom = 32;
            gCurrentSprite.drawDistanceHorizontal = 24;
            gCurrentSprite.work3 = 2;
            gCurrentSprite.work1 = 0;

            ScreenShakeStartVertical(60, 0x81);
            SoundPlay_3b1c(0x133);
            break;

        case 1:
            gCurrentSprite.pOam = sYakuzaPartOam_3b7330;
            gCurrentSprite.drawDistanceTop = 8;
            gCurrentSprite.drawDistanceBottom = 32;
            gCurrentSprite.drawDistanceHorizontal = 32;
            gCurrentSprite.work3 = 6;
            gCurrentSprite.work1 = 8;
            break;

        case 2:
            gCurrentSprite.pOam = sYakuzaPartOam_3b7340;
            gCurrentSprite.drawDistanceTop = 16;
            gCurrentSprite.drawDistanceBottom = 8;
            gCurrentSprite.drawDistanceHorizontal = 40;
            gCurrentSprite.work3 = 10;
            gCurrentSprite.work1 = 6;
            break;

        case 3:
            gCurrentSprite.pOam = sYakuzaPartOam_3b7350;
            gCurrentSprite.drawDistanceTop = 8;
            gCurrentSprite.drawDistanceBottom = 32;
            gCurrentSprite.drawDistanceHorizontal = 24;
            gCurrentSprite.work3 = 4;
            gCurrentSprite.work1 = 10;
            break;

        case 4:
            gCurrentSprite.pOam = sYakuzaPartOam_3b7360;
            gCurrentSprite.drawDistanceTop = 8;
            gCurrentSprite.drawDistanceBottom = 32;
            gCurrentSprite.drawDistanceHorizontal = 32;
            gCurrentSprite.work3 = 6;
            gCurrentSprite.work1 = 2;
            break;

        case 5:
            gCurrentSprite.pOam = sYakuzaPartOam_3b7370;
            gCurrentSprite.drawDistanceTop = 16;
            gCurrentSprite.drawDistanceBottom = 8;
            gCurrentSprite.drawDistanceHorizontal = 40;
            gCurrentSprite.work3 = 10;
            gCurrentSprite.work1 = 4;
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }
}

void YakuzaFallingLegMoving(void)
{
    u8 offset;
    s16 movement;

    if (gCurrentSprite.work1 > 0)
    {
        // BUG: Lower-left leg doesn't spawn explosion
        if (--gCurrentSprite.work1 == 0)
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x25);
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sSpritesFallingSpeed_2e499c[offset];
        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed_2e499c[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
            gCurrentSprite.yPosition += movement;
        }

        if (gCurrentSprite.roomSlot <= 2)
            gCurrentSprite.xPosition -= gCurrentSprite.work3;
        else
            gCurrentSprite.xPosition += gCurrentSprite.work3;
    }
}

void Yakuza(void)
{
    if (gCurrentSprite.health == 0 && gCurrentSprite.pose != 0)
        gCurrentSprite.pose = 0x47;

    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(0x131);

    switch (gCurrentSprite.pose)
    {
        case 0:
            YakuzaInit();
            break;

        case 0x37:
            YakuzaWaitingToAppear();
            break;

        case 0x38:
            YakuzaAboutToAppear();
            break;

        case 1:
            YakuzaBeginSweepInit();
        case 2:
            YakuzaBeginSweep();
            break;

        case 0x18:
            YakuzaSweeping();
            break;

        case 0x1a:
            YakuzaSweepingEnd();
            break;

        case 7:
            YakuzaIdleBeforeNewRoundInit();
        case 8:
            YakuzaIdleBeforeNewRound();
            break;

        case 0x27:
            YakuzaGrabbedSamusInit();
        case 0x28:
            YakuzaGrabbedSamus();
            break;

        case 0x2a:
            YakuzaPullingSamus();
            break;

        case 0x2c:
            YakuzaHoldingSamusHigh();
            break;

        case 0x2e:
            YakuzaSlammingSamus();
            break;

        case 0x2f:
            YakuzaReleasingSamusInit();
        case 0x30:
            YakuzaReleasingSamus();
            break;

        case 9:
            YakuzaAfterReleasingSamusInit();
        case 10:
            YakuzaAfterReleasingSamus();
            break;

        case 0x31:
            YakuzaOpeningMouthInit();
        case 0x32:
            YakuzaOpeningMouth();
            break;

        case 0x1b:
            YakuzaMouthOpenedInit();
        case 0x1c:
            YakuzaMouthOpened();
            break;

        case 0x1d:
            YakuzaClosingMouthInit();
        case 0x1e:
            YakuzaClosingMouth();
            break;

        case 0x1f:
            YakuzaPhase1DyingInit();
        case 0x20:
            YakuzaPhase1Dying();
            break;

        case 0x21:
            YakuzaLosingLegsInit();
        case 0x22:
            YakuzaLosingLegs();
            break;

        case 0x23:
            YakuzaPhase2Init();
        case 0x24:
            YakuzaPhase2();
            break;

        case 0x47:
            YakuzaPhase2DyingInit();
        case 0x48:
            YakuzaPhase2Dying();
            break;

        case 0x49:
            YakuzaTurningIntoCoreXInit();
        case 0x4a:
            YakuzaTurningIntoCoreX();
            break;
    }

    SpriteUtilUpdateSubSpriteData1Animation();
    YakuzaSyncSubSprites();
    YakuzaUpdatePalette();
}

void YakuzaPart(void)
{
    if (gCurrentSprite.pose == 0)
    {
        YakuzaPartInit();
        return;
    }

    if (gCurrentSprite.roomSlot == YAKUZA_PART_LEGS)
    {
        if (gSubSpriteData1.health > 0)
            YakuzaPartLegsIdle();
        else
            YakuzaPartLegsDead();

        YakuzaSyncSubSprites();
    }
    else if (gCurrentSprite.roomSlot == YAKUZA_PART_EYE)
    {
        if (gCurrentSprite.pose == 2)
            YakuzaPartEyeIdle();
        else
            YakuzaPartEyePhase2();

        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }
}

void YakuzaProjectile(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            YakuzaProjectileInit();
            break;

        case 0x28:
            YakuzaProjectileSpitFalling();
            break;

        case SPRITE_POSE_STOPPED:
            YakuzaProjectileExploding();
            break;

        case 2:
            YakuzaProjectileFireFalling();
            break;

        case 0x18:
            YakuzaProjectileFireBurning1();
            break;

        case 0x1a:
            YakuzaProjectileFireBurning2();
            break;

        case 0x1c:
            YakuzaProjectileFireBurning3();
            break;

        case 0x1e:
            YakuzaProjectileFireBurning4();
            break;
    }
}

void YakuzaFallingLeg(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case 0:
            YakuzaFallingLegInit();
            break;

        case 2:
            YakuzaFallingLegMoving();
            break;
    }
}
