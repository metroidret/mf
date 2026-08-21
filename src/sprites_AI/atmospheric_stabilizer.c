#include "data/sprites/atmospheric_stabilizer.h"

#include "globals.h"

#include "data/generic_data.h"
#include "data/samus_data.h"
#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

u8 AtmosphericStabilizerCheckIsInfected(void)
{
    u8 i;
    u8 spriteId;
    u16 stabilizerBit;

    // Find a stabilizer
    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;
        if (gSpriteData[i].properties & SP_SECONDARY_SPRITE)
            continue;

        spriteId = gSpriteData[i].spriteId;
        switch (spriteId)
        {
            case PSPRITE_ATMOSPHERIC_STABILIZER_1:
            case PSPRITE_ATMOSPHERIC_STABILIZER_2:
            case PSPRITE_ATMOSPHERIC_STABILIZER_3:
            case PSPRITE_ATMOSPHERIC_STABILIZER_4:
            case PSPRITE_ATMOSPHERIC_STABILIZER_5:
                // All stabilizer sprite IDs are next to each other numerically, so doing spriteId - firstStabilizerId
                // offsets the ID to start at 0
                spriteId -= PSPRITE_ATMOSPHERIC_STABILIZER_1;

                // Get bit affected by the current stabilizer
                stabilizerBit = gAtmosphericStabilizersOnline >> spriteId;

                if (stabilizerBit & 1)
                    // Online
                    return FALSE;
                else
                    // Offline
                    return TRUE;
        }
    }

    // No stabilizer is found
    return FALSE;
}

void AtmosphericStabilizerInit(void)
{
    u8 tmp;
    u8 secondarySpriteId;
    u16 stabilizerBit;

    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 32;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    SpriteUtilChooseRandomXDirection();

    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_ATMOSPHERIC_STABILIZER_1:
        case PSPRITE_ATMOSPHERIC_STABILIZER_3:
            secondarySpriteId = SSPRITE_ATMOSPHERIC_STABILIZER_COVER_RIGHT;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.work2 = FALSE;
            gCurrentSprite.pOam = sAtmosphericStabilizerFanOam_CloggedVertical;
            break;

        case PSPRITE_ATMOSPHERIC_STABILIZER_4:
        case PSPRITE_ATMOSPHERIC_STABILIZER_5:
            secondarySpriteId = SSPRITE_ATMOSPHERIC_STABILIZER_COVER_LEFT;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.work2 = FALSE;
            gCurrentSprite.pOam = sAtmosphericStabilizerFanOam_CloggedVertical;
            break;

        case PSPRITE_ATMOSPHERIC_STABILIZER_2:
            secondarySpriteId = SSPRITE_ATMOSPHERIC_STABILIZER_COVER_DOWN;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.work2 = TRUE;
            gCurrentSprite.pOam = sAtmosphericStabilizerFanOam_CloggedHorizontal;
            break;

        default:
            gCurrentSprite.status = 0;
            return;
    }

    // All stabilizer sprite IDs are next to each other numerically, so doing spriteId - firstStabilizerId
    // offsets the ID to start at 0
    tmp = gCurrentSprite.spriteId;
    tmp -= PSPRITE_ATMOSPHERIC_STABILIZER_1;

    // Get bit affected by the current stabilizer
    stabilizerBit = gAtmosphericStabilizersOnline >> tmp;

    if (stabilizerBit & 1)
    {
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.health = 0;
        if (gCurrentSprite.work2)
            gCurrentSprite.pOam = sAtmosphericStabilizerFanOam_OnlineHorizontal;
        else
            gCurrentSprite.pOam = sAtmosphericStabilizerFanOam_OnlineVertical;

        SoundPlay(SOUND_FE);
    }
    else
    {
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

        if (secondarySpriteId == SSPRITE_ATMOSPHERIC_STABILIZER_COVER_RIGHT)
        {
            tmp = SpriteSpawnSecondary(SSPRITE_ATMOSPHERIC_STABILIZER_COVER_RIGHT, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            if (tmp == UCHAR_MAX)
            {
                gCurrentSprite.status = 0;
                return;
            }

            tmp = SpriteSpawnSecondary(SSPRITE_ATMOSPHERIC_STABILIZER_COVER_RIGHT, 1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            if (tmp == UCHAR_MAX)
            {
                gCurrentSprite.status = 0;
                return;
            }

            tmp = SpriteSpawnNewXParasite(PSPRITE_ATMOSPHERIC_STABILIZER_PARASITE, 1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.spritesetSlotAndProperties,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            if (tmp == UCHAR_MAX)
            {
                gCurrentSprite.status = 0;
                return;
            }
        }
        else if (secondarySpriteId == SSPRITE_ATMOSPHERIC_STABILIZER_COVER_LEFT)
        {
            tmp = SpriteSpawnSecondary(SSPRITE_ATMOSPHERIC_STABILIZER_COVER_LEFT, 2, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            if (tmp == UCHAR_MAX)
            {
                gCurrentSprite.status = 0;
                return;
            }

            tmp = SpriteSpawnSecondary(SSPRITE_ATMOSPHERIC_STABILIZER_COVER_LEFT, 3, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            if (tmp == UCHAR_MAX)
            {
                gCurrentSprite.status = 0;
                return;
            }

            tmp = SpriteSpawnNewXParasite(PSPRITE_ATMOSPHERIC_STABILIZER_PARASITE, 2, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.spritesetSlotAndProperties,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            if (tmp == UCHAR_MAX)
            {
                gCurrentSprite.status = 0;
                return;
            }
        }
        else if (secondarySpriteId == SSPRITE_ATMOSPHERIC_STABILIZER_COVER_DOWN)
        {
            tmp = SpriteSpawnSecondary(SSPRITE_ATMOSPHERIC_STABILIZER_COVER_DOWN, 4, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            if (tmp == UCHAR_MAX)
            {
                gCurrentSprite.status = 0;
                return;
            }

            tmp = SpriteSpawnSecondary(SSPRITE_ATMOSPHERIC_STABILIZER_COVER_DOWN, 5, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            if (tmp == UCHAR_MAX)
            {
                gCurrentSprite.status = 0;
                return;
            }

            tmp = SpriteSpawnNewXParasite(PSPRITE_ATMOSPHERIC_STABILIZER_PARASITE, 3, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.spritesetSlotAndProperties,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            if (tmp == UCHAR_MAX)
            {
                gCurrentSprite.status = 0;
                return;
            }
        }
        else
        {
            gCurrentSprite.status = 0;
            return;
        }

        SoundPlay(SOUND_FF);
    }

    gCurrentSprite.spritesetSlotAndProperties = SSP_UNINFECTED_OR_BOSS;
}

void AtmosphericStabilizerBackOnlineInit(void)
{
    gCurrentSprite.pose = 0x18;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 0;

    if (gCurrentSprite.work2)
        gCurrentSprite.pOam = sAtmosphericStabilizerFanOam_RestartingHorizontal;
    else
        gCurrentSprite.pOam = sAtmosphericStabilizerFanOam_RestartingVertical;

    SoundPlay(SOUND_100);
}

void AtmosphericStabilizerBackOnline(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        if (gCurrentSprite.work2)
            gCurrentSprite.pOam = sAtmosphericStabilizerFanOam_OnlineHorizontal;
        else
            gCurrentSprite.pOam = sAtmosphericStabilizerFanOam_OnlineVertical;

        RoomEffectStartStopEventBased(EVENT_EFFECT_ATMOSPHERIC_STABILIZER);
    }
}

void AtmosphericStabilizerCoverInit(void)
{
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 4;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(2);
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;

    switch (gCurrentSprite.roomSlot)
    {
        case 0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pOam = sAtmosphericStabilizerCoverOam_Right;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
            break;

        case 1:
            gCurrentSprite.pOam = sAtmosphericStabilizerCoverOam_Right;
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
            break;

        case 2:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pOam = sAtmosphericStabilizerCoverOam_Left;
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.5f);
            break;

        case 3:
            gCurrentSprite.pOam = sAtmosphericStabilizerCoverOam_Left;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.5f);
            break;

        case 4:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pOam = sAtmosphericStabilizerCoverOam_Down;
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.5f);
            break;

        case 5:
            gCurrentSprite.pOam = sAtmosphericStabilizerCoverOam_Down;
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxLeft = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
            break;

        case 6:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pOam = sAtmosphericStabilizerCoverOam_UpRight;
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxRight = -BLOCK_TO_SUB_PIXEL(0.5f);
            break;

        case 7:
            gCurrentSprite.pOam = sAtmosphericStabilizerCoverOam_UpRight;
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.5f);
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.5f);
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }
}

void AtmosphericStabilizerCoverIdle(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.yPosition = gSpriteData[primary].yPosition;
    gCurrentSprite.xPosition = gSpriteData[primary].xPosition;

    if (gSpriteData[primary].pose == 0x18)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
        {
            gCurrentSprite.status = 0;
        }
        else
        {
            gCurrentSprite.pose = 0x18;
            gCurrentSprite.work1 = 0;
        }
    }
}

void AtmosphericStabilizerCoverExploding(void)
{
    u16 y;
    u16 x;
    u8 messageType;
    u16 stabilizersOnline;
    u8 count;
    u8 check;

    y = gCurrentSprite.yPosition;
    x = gCurrentSprite.xPosition;

    gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    if (MOD_AND(gCurrentSprite.work1, 4) == 0)
        SoundPlay(SOUND_RANDOM_SPRITE_DEBRIS);

    if (gCurrentSprite.roomSlot == 0)
    {
        switch (gCurrentSprite.work1)
        {
            case 0:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.75f), x + BLOCK_TO_SUB_PIXEL(0.0625f), PE_0x25);
                break;

            case 2:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(0.0625f), PE_0x25);
                break;

            case 4:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.125f), x - BLOCK_TO_SUB_PIXEL(1.0f), PE_0x25);
                break;

            case 6:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.59375f), x - BLOCK_TO_SUB_PIXEL(0.75f), PE_0x26);
                break;

            case 7:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.59375f), x - BLOCK_TO_SUB_PIXEL(0.75f), PE_0x26);
                break;

            case 8:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.9375f), x + BLOCK_TO_SUB_PIXEL(0.9375f), PE_0x25);
                break;

            case 9:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.78125f), x + BLOCK_TO_SUB_PIXEL(0.78125f), PE_0x25);
                break;

            case 10:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.0f), x, PE_0x26);
                break;

            case 12:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.25f), x - BLOCK_TO_SUB_PIXEL(0.8125f), PE_0x25);
                break;

            case 14:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.25f), x - BLOCK_TO_SUB_PIXEL(1.0625), PE_0x25);
                break;

            case 16:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(0.8125f), PE_0x25);
                break;

            case 17:
                ParticleSet(y + 0x58, x + BLOCK_TO_SUB_PIXEL(0.25f), PE_0x25);
                break;

            case 18:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.125f), x + BLOCK_TO_SUB_PIXEL(1.25f), PE_0x25);
                break;

            case 19:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.21875f), x + BLOCK_TO_SUB_PIXEL(1.125f), PE_0x25);
                break;

            case 24:
                gCurrentSprite.status = 0;
                break;
        }

        gCurrentSprite.work1++;
    }
    else if (gCurrentSprite.roomSlot == 2)
    {
        switch (gCurrentSprite.work1)
        {
            case 0:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.75f), x + BLOCK_TO_SUB_PIXEL(0.0625f), PE_0x25);
                break;

            case 2:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(0.0625f), PE_0x25);
                break;

            case 4:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.125f), x + BLOCK_TO_SUB_PIXEL(1.0f), PE_0x25);
                break;

            case 6:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.59375f), x - BLOCK_TO_SUB_PIXEL(0.75f), PE_0x26);
                break;

            case 7:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.59375f), x - BLOCK_TO_SUB_PIXEL(0.75f), PE_0x26);
                break;

            case 8:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.9375f), x + BLOCK_TO_SUB_PIXEL(0.9375f), PE_0x25);
                break;

            case 9:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.78125f), x + BLOCK_TO_SUB_PIXEL(0.78125f), PE_0x25);
                break;

            case 10:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.0f), x, PE_0x26);
                break;

            case 12:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.25f), x - BLOCK_TO_SUB_PIXEL(0.8125f), PE_0x25);
                break;

            case 14:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.25f), x + BLOCK_TO_SUB_PIXEL(1.0625f), PE_0x25);
                break;

            case 16:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(0.8125f), PE_0x25);
                break;

            case 17:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.125f), x - BLOCK_TO_SUB_PIXEL(0.125f), PE_0x25);
                break;

            case 18:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.125f), x + BLOCK_TO_SUB_PIXEL(1.25f), PE_0x25);
                break;

            case 19:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.21875f), x + BLOCK_TO_SUB_PIXEL(1.125f), PE_0x25);
                break;

            case 24:
                gCurrentSprite.status = 0;
                break;
        }

        gCurrentSprite.work1++;
    }
    else if (gCurrentSprite.roomSlot == 4)
    {
        switch (gCurrentSprite.work1)
        {
            case 0:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.75f), x + BLOCK_TO_SUB_PIXEL(0.0625f), PE_0x25);
                break;

            case 2:
                ParticleSet(y, x - BLOCK_TO_SUB_PIXEL(1.125f), PE_0x25);
                break;

            case 4:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.125f), x + BLOCK_TO_SUB_PIXEL(1.0f), PE_0x25);
                break;

            case 6:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.59375f), x - BLOCK_TO_SUB_PIXEL(0.75f), PE_0x26);
                break;

            case 7:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.59375f), x - BLOCK_TO_SUB_PIXEL(0.75f), PE_0x26);
                break;

            case 8:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.9375f), x + BLOCK_TO_SUB_PIXEL(0.9375f), PE_0x25);
                break;

            case 9:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.78125f), x + BLOCK_TO_SUB_PIXEL(0.78125f), PE_0x25);
                break;

            case 10:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.125f), x, PE_0x25);
                break;

            case 12:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.25f), x - BLOCK_TO_SUB_PIXEL(0.8125f), PE_0x25);
                break;

            case 14:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.25f), x + BLOCK_TO_SUB_PIXEL(1.0625f), PE_0x25);
                break;

            case 16:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(0.8125f), PE_0x25);
                break;

            case 17:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.125f), x - BLOCK_TO_SUB_PIXEL(1.0f), PE_0x25);
                break;

            case 18:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.125f), x + BLOCK_TO_SUB_PIXEL(1.25f), PE_0x25);
                break;

            case 19:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.21875f), x + BLOCK_TO_SUB_PIXEL(1.125f), PE_0x25);
                break;

            case 24:
                gCurrentSprite.status = 0;
                break;
        }

        gCurrentSprite.work1++;
    }
    else if (gCurrentSprite.roomSlot == 6)
    {
        switch (gCurrentSprite.work1)
        {
            case 0:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.75f), x + BLOCK_TO_SUB_PIXEL(0.0625f), PE_0x25);
                break;

            case 2:
                ParticleSet(y, x - BLOCK_TO_SUB_PIXEL(1.125f), PE_0x25);
                break;

            case 4:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.125f), x + BLOCK_TO_SUB_PIXEL(1.0f), PE_0x25);
                break;

            case 6:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.59375f), x - BLOCK_TO_SUB_PIXEL(0.75f), PE_0x26);
                break;

            case 7:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.59375f), x - BLOCK_TO_SUB_PIXEL(0.75f), PE_0x26);
                break;

            case 8:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(0.9375f), x + BLOCK_TO_SUB_PIXEL(0.9375f), PE_0x25);
                break;

            case 9:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.78125f), x + BLOCK_TO_SUB_PIXEL(0.78125f), PE_0x25);
                break;

            case 10:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.125f), x, PE_0x25);
                break;

            case 12:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.25f), x, PE_0x25);
                break;

            case 14:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.25f), x + BLOCK_TO_SUB_PIXEL(1.0625f), PE_0x25);
                break;

            case 16:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.0f), x - BLOCK_TO_SUB_PIXEL(0.8125f), PE_0x25);
                break;

            case 17:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(0.125f), x - BLOCK_TO_SUB_PIXEL(1.0f), PE_0x25);
                break;

            case 18:
                ParticleSet(y - BLOCK_TO_SUB_PIXEL(1.125f), x + BLOCK_TO_SUB_PIXEL(1.25f), PE_0x25);
                break;

            case 19:
                ParticleSet(y + BLOCK_TO_SUB_PIXEL(1.21875f), x + BLOCK_TO_SUB_PIXEL(1.125f), PE_0x25);
                break;

            case 24:
                gCurrentSprite.status = 0;
                break;
        }

        gCurrentSprite.work1++;
    }
    else
    {
        gCurrentSprite.status = 0;
    }

    if (gCurrentSprite.work1 == 25)
    {
        stabilizersOnline = gAtmosphericStabilizersOnline;
        count = 0;

        check = 1 << 0;
        if (stabilizersOnline & check)
            count++;

        check = 1 << 1;
        if (stabilizersOnline & check)
            count++;

        check = 1 << 2;
        if (stabilizersOnline & check)
            count++;

        check = 1 << 3;
        if (stabilizersOnline & check)
            count++;

        check = 1 << 4;
        if (stabilizersOnline & check)
            count++;

        if (count == 1)
            messageType = 1;
        else if (count == 2)
            messageType = 2;
        else if (count == 3)
            messageType = 3;
        else if (count == 4)
            messageType = 4;
        else if (count == 5)
            messageType = 5;
        else
            return;

        if (count > 0)
        {
            TrySpawnMessageBanner(messageType);
            gPreventMovementTimer = SAMUS_ITEM_PMT;
        }
    }
}

void AtmosphericStabilizerParasiteInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);

    switch (gCurrentSprite.roomSlot)
    {
        case 1:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f);
            break;

        case 2:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.375f);
            break;

        case 3:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.375f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.5f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.5f);
            break;

        case 4:
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.375f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.375f);
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }
}

void AtmosphericStabilizerParasiteIdleInit(void)
{
    gCurrentSprite.pOam = sAtmosphericStabilizerParasiteOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 120;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
}

void AtmosphericStabilizerParasiteIdle(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.yPosition = gSpriteData[primary].yPosition;
    gCurrentSprite.xPosition = gSpriteData[primary].xPosition;

    if (CountPrimarySpritesThatCantAbsorbX() >= 5)
    {
        gCurrentSprite.work1 = 120;
    }
    else if (--gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.pOam = sAtmosphericStabilizerParasiteOam_SpawningX;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        gCurrentSprite.work1 = X_PARASITE_MOSAIC_MAX_INDEX;
        gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.work1];
    }
}

void AtmosphericStabilizerParasiteSpawnX(void)
{
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.yPosition = gSpriteData[primary].yPosition;
    gCurrentSprite.xPosition = gSpriteData[primary].xPosition;
    gCurrentSprite.work1--;
    gWrittenToMosaic_H = sXParasiteMosaicValues[gCurrentSprite.work1];

    if (gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
        SpriteSpawnNewXParasite(PSPRITE_X_PARASITE_CORE_X_OR_PARASITE, 0, 0, gCurrentSprite.primarySpriteRamSlot,
            SSP_X_ABSORBABLE_BY_SAMUS, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        AtmosphericStabilizerParasiteIdleInit();
    }
}

void AtmosphericStabilizerParasiteDeath(void)
{
    u8 spriteId;
    u16 stabilizerBit;
    u8 primary;

    primary = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.pOam = sAtmosphericStabilizerParasiteOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gSpriteData[primary].pose = 0x17;

    // All stabilizer sprite IDs are next to each other numerically, so doing spriteId - firstStabilizerId
    // offsets the ID to start at 0
    spriteId = gSpriteData[primary].spriteId;
    spriteId -= PSPRITE_ATMOSPHERIC_STABILIZER_1;

    // Get bit affected by the current stabilizer
    stabilizerBit = 1 << spriteId;

    gAtmosphericStabilizersOnline |= stabilizerBit;

    if (gAtmosphericStabilizersOnline == 31) // 11111 in binary
        EventCheckAdvance(EVENT_ALL_STABILIZERS_ONLINE);
}

void AtmosphericStabilizer(void)
{
    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case 0:
            AtmosphericStabilizerInit();
            break;

        case 0x17:
            AtmosphericStabilizerBackOnlineInit();

        case 0x18:
            gCurrentSprite.ignoreSamusCollisionTimer = 1;
            AtmosphericStabilizerBackOnline();
            break;

        default:
            if (MOD_AND(gFrameCounter8Bit, 2) != 0)
            {
                if (gCurrentSprite.work2)
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        gCurrentSprite.xPosition += 1;
                    else
                        gCurrentSprite.xPosition -= 1;
                }
                else
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        gCurrentSprite.yPosition += 1;
                    else
                        gCurrentSprite.yPosition -= 1;
                }

                if (--gCurrentSprite.work1 == 0)
                {
                    gCurrentSprite.work1 = 64;
                    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
                }
            }
            break;
    }
}

void AtmosphericStabilizerCover(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            AtmosphericStabilizerCoverInit();

        case SPRITE_POSE_IDLE:
            AtmosphericStabilizerCoverIdle();
            break;

        case 0x18:
            AtmosphericStabilizerCoverExploding();
            break;
    }
}

void AtmosphericStabilizerParasite(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_GERON_HURT);

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            AtmosphericStabilizerParasiteInit();

        case SPRITE_POSE_IDLE_INIT:
            AtmosphericStabilizerParasiteIdleInit();

        case SPRITE_POSE_IDLE:
            AtmosphericStabilizerParasiteIdle();
            break;

        case 0x18:
            AtmosphericStabilizerParasiteSpawnX();
            break;

        case SPRITE_POSE_DYING_INIT:
            AtmosphericStabilizerParasiteDeath();
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            SpriteDying();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            XParasiteInit();
    }
}
