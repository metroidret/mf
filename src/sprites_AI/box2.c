#include "sprites_AI/box2.h"

#include "globals.h"
#include "macros.h"
#include "sprite.h"
#include "x_parasite_util.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/box.h"
#include "data/sprites/box2.h"
#include "data/sprites/shake_trigger.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
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
    u8 v;

    v = gEquipment.beamStatus & BF_WAVE_BEAM;
    if (v != 0)
    {
        gCurrentSprite.status = 0;
    }
    else
    {
        gCurrentSprite.samusCollision = v;
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
        gCurrentSprite.roomSlot = BOX_PART_BRAIN;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        gCurrentSprite.pOam = (const struct FrameData*)sBox2Oam_395658;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = v;

        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
        gSubSpriteData1.pMultiOam = (const struct MultiSpriteData*)0x0839126C;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = v;
        gSubSpriteData1.work0 = 0;

        gCurrentSprite.work2 = 0;
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.pose = 0x17;

        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 0, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 1, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 2, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 3, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 4, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 5, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 6, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 8, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 9, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 10, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);
        SpriteSpawnSecondary(SSPRITE_BOX_2_PART, 11, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, v);

        SpriteSpawnPrimary(PSPRITE_ELECTRIC_WATER_DAMAGE_BOX_2, gCurrentSprite.roomSlot, 7, 0x10,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, v);
    }
}

void Box2WaitingToRunInit(void)
{
    gSubSpriteData1.pMultiOam = (const struct MultiSpriteData*)0x083913DC;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x18;
    gCurrentSprite.work1 = 0;

    SoundPlay(SOUND_BOX_WAIT_TO_RUN);
}

void Box2WaitingToRun(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded() && ++gCurrentSprite.work1 == 1)
        gCurrentSprite.pose = 0x19;

    if (gCurrentSprite.work2 != 0)
        gCurrentSprite.pose = 0x3b;
}

void Box2SlowRunningInit(void)
{
    SpriteUtilMakeSpriteFaceSamusDirection();

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = (const struct MultiSpriteData*)0x08391354;
    else
        gSubSpriteData1.pMultiOam = (const struct MultiSpriteData*)0x083912C4;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x1a;
    gCurrentSprite.work1 = 0;
}

void Box2SlowRunning(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_279);
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            ParticleSet(gSubSpriteData1.yPosition - 0x28, gSubSpriteData1.xPosition + 0x78, 0x38);
        else
            ParticleSet(gSubSpriteData1.yPosition - 0x28, gSubSpriteData1.xPosition - 0x78, 0x38);
    }

    if (!Box2XMovement(gCurrentSprite.work1, 0x37))
    {
        if (SpriteUtilHasSubSprite1AnimationNearlyEnded() && ++gCurrentSprite.work1 == 7)
            gCurrentSprite.pose = 0x1b;

        if (gCurrentSprite.work2 != 0)
            gCurrentSprite.pose = 0x3b;
    }
}

void Box2FastRunningInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = (const struct MultiSpriteData*)0x08391384;
    else
        gSubSpriteData1.pMultiOam = (const struct MultiSpriteData*)0x083912F4;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = 0x1c;
    gCurrentSprite.work1 = 10;
}

void Box2FastRunning(void)
{
    if (gSubSpriteData1.currentAnimationFrame == 3 && gSubSpriteData1.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_279);
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            ParticleSet(gSubSpriteData1.yPosition - 0x3c, gSubSpriteData1.xPosition + 0xa0, 0x38);
        else
            ParticleSet(gSubSpriteData1.yPosition - 0x3c, gSubSpriteData1.xPosition - 0xa0, 0x38);
    }

    if (!Box2XMovement(8, 0x37))
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
                if (gSubSpriteData1.xPosition - 0xc8 > gSamusData.xPosition)
                    gCurrentSprite.pose = 0x1d;
            }
            else
            {
                if (gSubSpriteData1.xPosition + 0xc8 < gSamusData.xPosition)
                    gCurrentSprite.pose = 0x1d;
            }
        }
    }

    if (gCurrentSprite.work2 != 0)
        gCurrentSprite.pose = 0x3b;
}
