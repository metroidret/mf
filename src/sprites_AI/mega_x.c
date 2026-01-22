#include "data/sprites/mega_x.h"

#include "gba.h"
#include "globals.h"

#include "data/generic_data.h"
#include "data/sprite_data.h"
#include "data/sprites/message_banner.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/samus.h"

#include "structs/samus.h"
#include "structs/sprite.h"

void MegaXUpdatePalette(void)
{
    boolu32 update;
    u16 health;
    u16 maxHealth;
    const u16* pPal;

    update = FALSE;
    health = gCurrentSprite.health;
    maxHealth = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    switch (gBossWork1)
    {
        case 0:
            if (health <= maxHealth * 2 / 3)
            {
                pPal = sMegaXPal + 5 * PAL_ROW;
                gBossWork1 = 1;
                update = TRUE;
            }
            break;

        case 1:
            if (health <= maxHealth / 3)
            {
                pPal = sMegaXPal + 6 * 16;
                gBossWork1 = 2;
                update = TRUE;
            }
            break;
    }

    if (update)
        DMA_SET(3, pPal, PALRAM_OBJ + 12 * PAL_ROW_SIZE, C_32_2_16(DMA_ENABLE, 1 * PAL_ROW));
}

void MegaXDestroyShields(void)
{
    u8 i;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (gSpriteData[i].status & SPRITE_STATUS_EXISTS && gSpriteData[i].properties & SP_SECONDARY_SPRITE &&
            gSpriteData[i].spriteId == SSPRITE_MEGA_X_SHIELD)
        {
            // Checking health here is unnecessary
            if (gSpriteData[i].health > 0)
                gSpriteData[i].health = 0;
        }
    }
}

void MegaXTurningIntoX_Unused(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (--gCurrentSprite.workY != 0)
    {
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.workY];
    }
    else
    {
        gCurrentSprite.pose = 0x1b;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
        gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    }

    if (gCurrentSprite.workY < sizeof(sMessageBannerGfx) / 512)
        SpriteLoadGfx(PSPRITE_MESSAGE_BANNER, 6, gCurrentSprite.workY);
    else if (gCurrentSprite.workY == sizeof(sMessageBannerGfx) / 512)
        SpriteLoadPal(PSPRITE_MESSAGE_BANNER, 6, ARRAY_SIZE(sMessageBannerPal) / 16);
}

void VariaSuitAbilityInit(void)
{
    if (gEquipment.suitMiscStatus & SMF_VARIA_SUIT)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gBossWork1 = 0;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(4.0f);
    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(2.0f);
    gCurrentSprite.workY = gCurrentSprite.yPosition;
    gCurrentSprite.workX = gCurrentSprite.xPosition;
    gCurrentSprite.pose = 0x37;
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawOrder = 6;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.drawDistanceTop = 16;
    gCurrentSprite.drawDistanceBottom = 16;
    gCurrentSprite.drawDistanceHorizontal = 16;
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.pOam = sMegaXOam_3a59b0;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.rotation = 0;
    gCurrentSprite.scaling = Q_8_8(1.f / 16);
    gCurrentSprite.work0 = 0;

    SpriteSpawnSecondary(SSPRITE_MEGA_X, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_CORE_X_SHELL_VARIA, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ABILITY_AURA, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ABILITY_AURA, 1, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ABILITY_AURA, 2, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
}

void VariaSuitAbilityWaitingToSpawn(void)
{
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_TO_SUB_PIXEL(4.f), BLOCK_TO_SUB_PIXEL(4.f)) != NSLR_OUT_OF_RANGE)
    {
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.work4 = 0;
        gCurrentSprite.pose = 0x38;

        PlayMusic(MUSIC_VARIA_CORE_X_BATTLE, 7);
    }
}

void VariaSuitAbilitySpawning(void)
{
    u8 yOffset;
    u8 xOffset;
    s16 yMovement;
    s16 xMovement;

    yOffset = gCurrentSprite.work4;
    yMovement = sVariaSuitAbilitySpawningYMovement[yOffset];
    if (yMovement == SHORT_MAX)
    {
        yMovement = sVariaSuitAbilitySpawningYMovement[gCurrentSprite.work4 - 1];
        gCurrentSprite.yPosition += yMovement;
    }
    else
    {
        yOffset++;
        gCurrentSprite.work4 = yOffset;
        gCurrentSprite.yPosition += yMovement;
    }

    xOffset = gCurrentSprite.work3;
    xMovement = sVariaSuitAbilitySpawningXMovement[xOffset];
    if (xMovement == SHORT_MAX)
    {
        xMovement = sVariaSuitAbilitySpawningXMovement[gCurrentSprite.work3 - 1];
        gCurrentSprite.xPosition += xMovement;
    }
    else
    {
        xOffset++;
        gCurrentSprite.work3 = xOffset;
        gCurrentSprite.xPosition += xMovement;
    }

    if (gCurrentSprite.work1 == 0)
    {
        if (gCurrentSprite.scaling < Q_8_8(2))
        {
            gCurrentSprite.scaling = gCurrentSprite.scaling + Q_8_8(1.f / 16);
        }
        else
        {
            gCurrentSprite.work1 = 1;
            gCurrentSprite.work2 = 60;
        }
    }
    else
    {
        if (--gCurrentSprite.work2 == 0)
        {
            gCurrentSprite.pose = 0x39;

            SpriteSpawnSecondary(SSPRITE_MEGA_X_SHIELD, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_MEGA_X_SHIELD, 1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_MEGA_X_SHIELD, 2, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_MEGA_X_SHIELD, 3, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_MEGA_X_SHIELD, 4, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_MEGA_X_SHIELD, 5, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_MEGA_X_SHIELD, 6, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_MEGA_X_SHIELD, 7, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }
    }
}

void VariaSuitAbilityMovingInit(void)
{
    gCurrentSprite.pose = 0x3a;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 1;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 1;
}

void VariaSuitAbilityMoving(void)
{
    u16 targetY;

    if ((gFrameCounter8Bit & 128) != 0)
        targetY = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(5.0f);
    else
        targetY = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.125f);

    XParasiteMoveWithSound(targetY, gSamusData.xPosition, BLOCK_TO_SUB_PIXEL(0.21875f) * 4,
        BLOCK_TO_SUB_PIXEL(0.3125f) * 4, LOG2(4), SOUND_CORE_X_MOVING);
}

void VariaSuitAbilityShrinking(void)
{
    if (gCurrentSprite.scaling > Q_8_8(1))
    {
        gCurrentSprite.scaling -= Q_8_8(1.f / 16);
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pose = 0x3c;
        gCurrentSprite.work1 = 9;
    }
}

void VariaSuitAbilityShrunk(void)
{
    // Empty
}

void VariaSuitAbilityTurningIntoCoreX(void)
{
    if (--gCurrentSprite.work1 == 0)
        gCurrentSprite.pose = 0x3f;

    if (gCurrentSprite.work1 < sizeof(sMessageBannerGfx) / 512)
        SpriteLoadGfx(PSPRITE_MESSAGE_BANNER, 6, gCurrentSprite.work1);
    else if (gCurrentSprite.work1 == sizeof(sMessageBannerGfx) / 512)
        SpriteLoadPal(PSPRITE_MESSAGE_BANNER, 6, ARRAY_SIZE(sMessageBannerPal) / 16);
}

void VariaSuitAbilityCoreXMovingInit(void)
{
    gCurrentSprite.pose = 0x40;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 1;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 1;
}

void VariaSuitAbilityCoreXMoving(void)
{
    XParasiteMoveWithSound((u16)(gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.125f)), gSamusData.xPosition,
        BLOCK_TO_SUB_PIXEL(0.109375f) * 4, BLOCK_TO_SUB_PIXEL(0.15625f) * 4, LOG2(4), SOUND_CORE_X_MOVING);
}

void VariaSuitAbilityCoreXMovingInit_Unused(void)
{
    gCurrentSprite.pose = 0x42;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 1;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work4 = 1;
}

void VariaSuitAbilityCoreXMoving_Unused(void)
{
    XParasiteMoveWithSound((u16)(gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.125f)), gSamusData.xPosition,
        BLOCK_TO_SUB_PIXEL(0.109375f) * 4, BLOCK_TO_SUB_PIXEL(0.15625f) * 4, LOG2(4), SOUND_CORE_X_MOVING);
}

void MegaXShieldInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    gCurrentSprite.drawDistanceTop = 12;
    gCurrentSprite.drawDistanceBottom = 12;
    gCurrentSprite.drawDistanceHorizontal = 12;
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.pOam = sMegaXOam_3a5ef8;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.pose = 2;
    gCurrentSprite.scaling = 0x100;
    gCurrentSprite.work3 = FALSE;
    gCurrentSprite.work2 = gCurrentSprite.roomSlot * Q_8_8(1.f / 8);
}

void MegaXShieldIdle(void)
{
    s16 distance;
    u32 angle;
    s16 sin;
    s16 cos;
    u16 yOffset;
    u16 xOffset;
    u8 primarySlot;

    if (gCurrentSprite.health == 0)
    {
        ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_0x22);
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.work2 += Q_8_8(3.f / 256);

    if (gCurrentSprite.work3)
    {
        if (gCurrentSprite.scaling < 0x140)
            gCurrentSprite.scaling += 2;
        else
            gCurrentSprite.work3 = FALSE;
    }
    else
    {
        if (gCurrentSprite.scaling > 0xc0)
            gCurrentSprite.scaling -= 2;
        else
            gCurrentSprite.work3 = TRUE;
    }

    primarySlot = gCurrentSprite.primarySpriteRamSlot;
    distance = gCurrentSprite.scaling;
    angle = gCurrentSprite.work2;

    sin = SIN(angle);
    if (sin < 0)
    {
        yOffset = Q_8_8_TO_INT(-sin * distance);
        gCurrentSprite.yPosition = gSpriteData[primarySlot].yPosition - yOffset;
    }
    else
    {
        yOffset = Q_8_8_TO_INT(sin * distance);
        gCurrentSprite.yPosition = gSpriteData[primarySlot].yPosition + yOffset;
    }

    cos = COS(angle);
    if (cos < 0)
    {
        xOffset = Q_8_8_TO_INT(-cos * distance);
        gCurrentSprite.xPosition = gSpriteData[primarySlot].xPosition - xOffset;
    }
    else
    {
        xOffset = Q_8_8_TO_INT(cos * distance);
        gCurrentSprite.xPosition = gSpriteData[primarySlot].xPosition + xOffset;
    }
}

void VariaSuitAbility(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            VariaSuitAbilityInit();
            break;

        case 0x37:
            VariaSuitAbilityWaitingToSpawn();
            break;

        case 0x38:
            VariaSuitAbilitySpawning();
            break;

        case 0x39:
            VariaSuitAbilityMovingInit();
            break;

        case 0x3a:
            VariaSuitAbilityMoving();
            break;

        case 0x3b:
            VariaSuitAbilityShrinking();
            break;

        case 0x3c:
            VariaSuitAbilityShrunk();
            break;

        case 0x3d:
            VariaSuitAbilityTurningIntoCoreX();
            break;

        case 0x3f:
            VariaSuitAbilityCoreXMovingInit();
            break;

        case 0x40:
            VariaSuitAbilityCoreXMoving();
            break;

        case 0x5c:
            CoreXAbilityMovingToTargetInit();
            break;

        case 0x5d:
            CoreXAbilityMovingToTarget();
            break;

        case 0x5e:
            CoreXAbilityWaitingAtTarget();
            break;

        case 0x5f:
            CoreXAbilityGettingAbsorbed();
            break;
    }
}

void MegaX(void)
{
    u8 primaryRamSlot;
    u8 tmp;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case 0x18:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            if (--gCurrentSprite.work1 == 0)
            {
                gSpriteData[primaryRamSlot].pose = 0x3d;
                gCurrentSprite.status = 0;
            }
            return;

        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.frozenPaletteRowOffset = 4;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.drawDistanceTop = 48;
            gCurrentSprite.drawDistanceBottom = 48;
            gCurrentSprite.drawDistanceHorizontal = 48;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(2.25f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(2.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(2.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(2.25f);
            gCurrentSprite.pOam = sMegaXOam_3a5e70;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
            gCurrentSprite.pose = SPRITE_POSE_IDLE;
            gCurrentSprite.status |= SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING_WHOLE;
            gCurrentSprite.scaling = 0x10;
            gCurrentSprite.rotation = 0;
            break;
    }

    gCurrentSprite.yPosition = gSpriteData[primaryRamSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[primaryRamSlot].xPosition;

    switch (gSpriteData[primaryRamSlot].pose)
    {
        case 0x37:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;
            break;

        case 0x38:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.scaling = gSpriteData[primaryRamSlot].scaling;
            break;

        case 0x3b:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;
            if (MOD_AND(gFrameCounter8Bit, 4) == 0)
            {
                if ((gFrameCounter8Bit & 4) != 0)
                    SPRITE_SET_ABSOLUTE_PALETTE_ROW(gCurrentSprite, SPRITE_FLASHING_PALETTE_ROW);
                else
                    gCurrentSprite.paletteRow = 0;
            }

            gCurrentSprite.scaling = gSpriteData[primaryRamSlot].scaling;
            if (gCurrentSprite.scaling <= Q_8_8(1))
            {
                gCurrentSprite.drawDistanceTop = 24;
                gCurrentSprite.drawDistanceBottom = 24;
                gCurrentSprite.drawDistanceHorizontal = 24;
                gCurrentSprite.status &= ~(SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING_WHOLE);
                gCurrentSprite.pose = 0x18;
                gCurrentSprite.work1 = 60;
                gCurrentSprite.paletteRow = 0;
                ParticleSet(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.375f), gCurrentSprite.xPosition, PE_0x3A);
            }
            else if (gCurrentSprite.scaling < Q_8_8(1.5f))
            {
                gCurrentSprite.drawDistanceTop = 34;
                gCurrentSprite.drawDistanceBottom = 34;
                gCurrentSprite.drawDistanceHorizontal = 34;
            }
            break;

        case 0x39:
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        case 0x3a:
            if (SPRITE_GET_ISFT(gCurrentSprite) == 16)
            {
                SoundPlay(SOUND_MEGA_X_HURT);
                gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
                gCurrentSprite.pOam = sMegaXOam_3a5ed0;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                if (gCurrentSprite.health == 0)
                {
                    gCurrentSprite.samusCollision = SSC_NONE;
                    gSpriteData[primaryRamSlot].pose = 0x3b;
                    MegaXDestroyShields();
                    return;
                }

                gSpriteData[primaryRamSlot].work0 = 60;

                if (gCurrentSprite.yPosition > gSamusData.yPosition - BLOCK_SIZE)
                    gSpriteData[primaryRamSlot].status |= SPRITE_STATUS_FACING_DOWN;
                else
                    gSpriteData[primaryRamSlot].status &= ~SPRITE_STATUS_FACING_DOWN;

                if (gCurrentSprite.xPosition > gSamusData.xPosition)
                    gSpriteData[primaryRamSlot].status |= SPRITE_STATUS_FACING_RIGHT;
                else
                    gSpriteData[primaryRamSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;

                gSpriteData[primaryRamSlot].work2 = 0x50;
                gSpriteData[primaryRamSlot].work3 = 0x50;
                gSpriteData[primaryRamSlot].work1 = 0x38;
                gSpriteData[primaryRamSlot].work4 = 0x38;
            }

            tmp = gSpriteData[primaryRamSlot].work0;
            if (tmp > 0)
            {
                if (MOD_AND(tmp, 4) == 0)
                {
                    if ((tmp & 4) != 0)
                        SPRITE_SET_ABSOLUTE_PALETTE_ROW(gCurrentSprite, SPRITE_FLASHING_PALETTE_ROW);
                    else
                        gCurrentSprite.paletteRow = 0;
                }

                if (--gSpriteData[primaryRamSlot].work0 == 0)
                {
                    gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
                    gCurrentSprite.paletteRow = 0;
                }
            }
            break;
    }

    MegaXUpdatePalette();
}

void CoreXShellVaria(void)
{
    u8 primaryRamSlot;
    u16 maxHealth;
    u8 tmp;

    primaryRamSlot = gCurrentSprite.primarySpriteRamSlot;
    maxHealth = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    switch (gCurrentSprite.pose)
    {
        case 0x18:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;
            if (SpriteUtilHasCurrentAnimationEnded())
                gCurrentSprite.status = 0;
            return;

        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.frozenPaletteRowOffset = 1;
            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
            gCurrentSprite.health = maxHealth;
            gCurrentSprite.drawDistanceTop = 48;
            gCurrentSprite.drawDistanceBottom = 48;
            gCurrentSprite.drawDistanceHorizontal = 48;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.25f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.25f);
            gCurrentSprite.pOam = sMegaXOam_3a5e40;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = SPRITE_POSE_IDLE;
            gCurrentSprite.status |= SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING_WHOLE;
            gCurrentSprite.scaling = 0x10;
            gCurrentSprite.rotation = 0;
            break;
    }

    gCurrentSprite.yPosition = gSpriteData[primaryRamSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[primaryRamSlot].xPosition;

    switch (gSpriteData[primaryRamSlot].pose)
    {
        case 0x37:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;
            break;

        case 0x38:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.scaling = gSpriteData[primaryRamSlot].scaling;
            break;

        case 0x3b:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;
            gCurrentSprite.scaling = gSpriteData[primaryRamSlot].scaling;
            if (gCurrentSprite.scaling <= Q_8_8(1))
            {
                gCurrentSprite.status &= ~(SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING_WHOLE);
                gCurrentSprite.drawDistanceTop = 24;
                gCurrentSprite.drawDistanceBottom = 24;
                gCurrentSprite.drawDistanceHorizontal = 24;
            }
            else if (gCurrentSprite.scaling < Q_8_8(1.5f))
            {
                gCurrentSprite.drawDistanceTop = 34;
                gCurrentSprite.drawDistanceBottom = 34;
                gCurrentSprite.drawDistanceHorizontal = 34;
            }
            break;

        case 0x3f:
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_RIDLEY_TAIL_SERRIS_SEGMENT;
        case 0x40: {
            if (gCurrentSprite.health == 0)
            {
                gCurrentSprite.samusCollision = SSC_NONE;
                gCurrentSprite.pOam = sMegaXOam_3a5b68;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.pose = 0x18;
                gSpriteData[primaryRamSlot].pose = 0x5c;

                SoundPlay(SOUND_CORE_X_SHELL_BURST);
            }
            else
            {
                if (gCurrentSprite.health <= maxHealth / 3)
                {
                    gCurrentSprite.pOam = sMegaXOam_3a5e60;
                    gCurrentSprite.frozenPaletteRowOffset = 3;
                }
                else if (gCurrentSprite.health <= maxHealth * 2 / 3)
                {
                    gCurrentSprite.pOam = sMegaXOam_3a5e50;
                    gCurrentSprite.frozenPaletteRowOffset = 2;
                }

                if (SPRITE_GET_ISFT(gCurrentSprite) == 1)
                {
                    tmp = SpriteUtilCountPrimarySprites(PSPRITE_X_PARASITE_CORE_X_OR_PARASITE);
                    if (tmp < 6)
                    {
                        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE_CORE_X_OR_PARASITE, 0, 0,
                            gCurrentSprite.primarySpriteRamSlot, SSP_X_ABSORBABLE_BY_SAMUS, gCurrentSprite.yPosition,
                            gCurrentSprite.xPosition, 0);
                    }
                }
                else if (SPRITE_GET_ISFT(gCurrentSprite) == 16)
                {
                    SoundPlay(SOUND_CORE_X_HURT);

                    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
                    gSpriteData[primaryRamSlot].work0 = 180;

                    if (gCurrentSprite.yPosition > gSamusData.yPosition - BLOCK_SIZE)
                        gSpriteData[primaryRamSlot].status |= SPRITE_STATUS_FACING_DOWN;
                    else
                        gSpriteData[primaryRamSlot].status &= ~SPRITE_STATUS_FACING_DOWN;

                    if (gCurrentSprite.xPosition > gSamusData.xPosition)
                        gSpriteData[primaryRamSlot].status |= SPRITE_STATUS_FACING_RIGHT;
                    else
                        gSpriteData[primaryRamSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;

                    gSpriteData[primaryRamSlot].work2 = BLOCK_TO_SUB_PIXEL(0.15625f) * 4;
                    gSpriteData[primaryRamSlot].work3 = BLOCK_TO_SUB_PIXEL(0.15625f) * 4;
                    gSpriteData[primaryRamSlot].work1 = BLOCK_TO_SUB_PIXEL(0.109375f) * 4;
                    gSpriteData[primaryRamSlot].work4 = BLOCK_TO_SUB_PIXEL(0.109375f) * 4;
                }

                tmp = gSpriteData[primaryRamSlot].work0;

                if (tmp != 0)
                {
                    if (MOD_AND(tmp, 4) == 0)
                    {
                        if ((tmp & 4) != 0)
                            SPRITE_SET_ABSOLUTE_PALETTE_ROW(gCurrentSprite, SPRITE_FLASHING_PALETTE_ROW);
                        else
                            gCurrentSprite.paletteRow = 0;
                    }

                    if (--gSpriteData[primaryRamSlot].work0 == 0)
                    {
                        gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
                        gCurrentSprite.paletteRow = 0;
                    }
                }
            }
        }
    }
}

void MegaXShield(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            MegaXShieldInit();
            break;

        case 2:
            MegaXShieldIdle();
            break;
    }
}
