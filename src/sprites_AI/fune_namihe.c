#include "data/sprites/fune_namihe.h"

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

void FuneInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(6);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.pOam = sFuneOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.workX = gCurrentSprite.xPosition;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.625f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.625f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0f);
    }
}

void FuneDying(void)
{
    // Freeze animation
    gCurrentSprite.animationDurationCounter--;
}

void FuneTurningIntoX(void)
{
    u16 x;

    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.3125f);

    if (gCurrentSprite.workX > gCurrentSprite.xPosition)
        x = DIV_SHIFT(gCurrentSprite.workX - gCurrentSprite.xPosition, 2) + gCurrentSprite.xPosition;
    else
        x = DIV_SHIFT(gCurrentSprite.xPosition - gCurrentSprite.workX, 2) + gCurrentSprite.workX;

    SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.3125f), x,
        SPRITE_STATUS_X_FLIP);
}

u8 FuneCheckSamusInFront(void)
{
    u16 nsfb;

    nsfb = SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(1.125f), BLOCK_TO_SUB_PIXEL(8.0f), 0);
    if (nsfb == NSFB_IN_FRONT)
    {
        gCurrentSprite.pose = 0x2b;
        return TRUE;
    }

    return FALSE;
}

void FuneIdleInit(void)
{
    gCurrentSprite.pOam = sFuneOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
}

void FuneIdle(void)
{
    u16 offset;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    if (FuneCheckSamusInFront())
        return;

    offset = 0;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            if ((u8)SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(4.0f), BLOCK_TO_SUB_PIXEL(8.0f), 0) ==
                NSFB_IN_FRONT)
            {
                gCurrentSprite.animationDurationCounter--;
                gCurrentSprite.pose = 0x29;
                return;
            }
            break;

        case 1:
        case 5:
            if (gCurrentSprite.animationDurationCounter == 8)
                offset = BLOCK_TO_SUB_PIXEL(0.03125f);
            else if (gCurrentSprite.animationDurationCounter == 15)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            break;

        case 2:
        case 6:
            if (gCurrentSprite.animationDurationCounter == 8)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            else if (gCurrentSprite.animationDurationCounter == 15)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            break;

        case 3:
        case 7:
            if (gCurrentSprite.animationDurationCounter == 8)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            else if (gCurrentSprite.animationDurationCounter == 15)
                offset = BLOCK_TO_SUB_PIXEL(0.03125f);
            break;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.currentAnimationFrame >= 4)
            gCurrentSprite.xPosition -= offset;
        else
            gCurrentSprite.xPosition += offset;
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame >= 4)
            gCurrentSprite.xPosition += offset;
        else
            gCurrentSprite.xPosition -= offset;
    }
}

void FuneSpittingInit(void)
{
    gCurrentSprite.pOam = sFuneOam_Spitting;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x2a;
}

void FuneSpitting(void)
{
    u16 offset;

    if (FuneCheckSamusInFront())
        return;

    offset = 0;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
            if (gCurrentSprite.animationDurationCounter == 1)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            else if (gCurrentSprite.animationDurationCounter == 2)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            break;

        case 7:
            if (gCurrentSprite.animationDurationCounter == 40)
            {
                gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
                return;
            }
            else if (gCurrentSprite.animationDurationCounter == 1)
            {
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            }
            else if (gCurrentSprite.animationDurationCounter == 2)
            {
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            }
            break;

        case 3:
            if (gCurrentSprite.animationDurationCounter == 1)
            {
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            }
            else if (gCurrentSprite.animationDurationCounter == 2)
            {
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            }
            else if (gCurrentSprite.animationDurationCounter == 4)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    SpriteSpawnSecondary(SSPRITE_FUNE_SPIT, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
                        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.25f),
                        gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);
                }
                else
                {
                    SpriteSpawnSecondary(SSPRITE_FUNE_SPIT, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
                        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.25f),
                        gCurrentSprite.xPosition, 0);
                }
            }
            break;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.currentAnimationFrame >= 4)
            gCurrentSprite.xPosition -= offset;
        else
            gCurrentSprite.xPosition += offset;
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame >= 4)
            gCurrentSprite.xPosition += offset;
        else
            gCurrentSprite.xPosition -= offset;
    }
}

void FuneLungingInit(void)
{
    gCurrentSprite.pOam = sFuneOam_Lunging;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x2c;

    SoundPlayNotAlreadyPlaying(SOUND_FUNE_LUNGING);
}

void FuneLunging(void)
{
    u16 offset;

    offset = 0;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            if (gCurrentSprite.animationDurationCounter == 1)
                offset = BLOCK_TO_SUB_PIXEL(0.375f);
            else if (gCurrentSprite.animationDurationCounter == 3)
                offset = BLOCK_TO_SUB_PIXEL(0.375f);
            break;

        case 10:
            if (gCurrentSprite.animationDurationCounter == 1)
                offset = BLOCK_TO_SUB_PIXEL(0.25f);
            else if (gCurrentSprite.animationDurationCounter == 3)
                offset = BLOCK_TO_SUB_PIXEL(0.25f);
            break;

        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            if (gCurrentSprite.animationDurationCounter == 1)
                offset = BLOCK_TO_SUB_PIXEL(0.25f);
            else if (gCurrentSprite.animationDurationCounter == 2)
                offset = BLOCK_TO_SUB_PIXEL(0.25f);
            break;

        case 25:
            if (gCurrentSprite.animationDurationCounter == 40)
                gCurrentSprite.pose = 0x2e;
            break;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.currentAnimationFrame >= 11)
        {
            gCurrentSprite.xPosition -= offset;
            gCurrentSprite.hitboxLeft += offset;
        }
        else
        {
            gCurrentSprite.xPosition += offset;
            gCurrentSprite.hitboxLeft -= offset;
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame >= 11)
        {
            gCurrentSprite.xPosition += offset;
            gCurrentSprite.hitboxRight -= offset;
        }
        else
        {
            gCurrentSprite.xPosition -= offset;
            gCurrentSprite.hitboxRight += offset;
        }
    }
}

void FuneLungingEnd(void)
{
    // Freeze animation
    gCurrentSprite.animationDurationCounter--;

    if (gCurrentSprite.xPosition < gCurrentSprite.workX)
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
    else if (gCurrentSprite.xPosition > gCurrentSprite.workX)
        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
    else
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void FuneSpitInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.pOam = sFuneSpitOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.frozenPaletteRowOffset = 1;

    SoundPlayNotAlreadyPlaying(SOUND_FUNE_SPIT);
}

void FuneSpitMoving(void)
{
    SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.15625f);
        else
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.15625f);
    }
}

void FuneSpitExplodingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_EXPLODING;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pOam = sFuneSpitOam_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void FuneSpitExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

void NamiheInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if (gCurrentSprite.properties & SP_CAN_ABSORB_X && !(gCurrentSprite.status & SPRITE_STATUS_HIDDEN))
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
    {
        gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
        gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(2);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(6);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.625f);
    gCurrentSprite.pOam = sNamiheOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.workX = gCurrentSprite.xPosition;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(1.0f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.625f);
    }
    else
    {
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.625f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(1.0f);
    }
}

void NamiheDying(void)
{
    // Freeze animation
    gCurrentSprite.animationDurationCounter--;
}

void NamiheTurningIntoX(void)
{
    u16 x;

    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.3125f);
    if (gCurrentSprite.workX > gCurrentSprite.xPosition)
        x = (DIV_SHIFT(gCurrentSprite.workX - gCurrentSprite.xPosition, 2)) + gCurrentSprite.xPosition;
    else
        x = (DIV_SHIFT(gCurrentSprite.xPosition - gCurrentSprite.workX, 2)) + gCurrentSprite.workX;

    SpriteSpawnNewXParasite(PSPRITE_X_PARASITE, gCurrentSprite.spriteId, 0, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.spritesetSlotAndProperties, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.3125f), x,
        SPRITE_STATUS_X_FLIP);
}

u8 NamiheCheckSamusInFront(void)
{
    u16 nsfb;

    nsfb = SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(1.125f), BLOCK_TO_SUB_PIXEL(8.0f), 0);
    if (nsfb == NSFB_IN_FRONT)
    {
        gCurrentSprite.pose = 0x2b;
        return TRUE;
    }

    return FALSE;
}

void NamiheIdleInit(void)
{
    gCurrentSprite.pOam = sNamiheOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
}

void NamiheIdle(void)
{
    u16 offset;

    if (gCurrentSprite.status & SPRITE_STATUS_HIDDEN)
        return;

    if (NamiheCheckSamusInFront())
        return;

    offset = 0;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            if ((u8)SpriteUtilCheckSamusNearSpriteFrontBehind(BLOCK_TO_SUB_PIXEL(5.0f), BLOCK_TO_SUB_PIXEL(8.0f), 0) ==
                NSFB_IN_FRONT)
            {
                gCurrentSprite.animationDurationCounter--;
                gCurrentSprite.pose = 0x29;
                return;
            }
            break;

        case 1:
        case 5:
            if (gCurrentSprite.animationDurationCounter == 8)
                offset = BLOCK_TO_SUB_PIXEL(0.03125f);
            else if (gCurrentSprite.animationDurationCounter == 15)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            break;

        case 2:
        case 6:
            if (gCurrentSprite.animationDurationCounter == 8)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            else if (gCurrentSprite.animationDurationCounter == 15)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            break;

        case 3:
        case 7:
            if (gCurrentSprite.animationDurationCounter == 8)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            else if (gCurrentSprite.animationDurationCounter == 15)
                offset = BLOCK_TO_SUB_PIXEL(0.03125f);
            break;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.currentAnimationFrame >= 4)
            gCurrentSprite.xPosition -= offset;
        else
            gCurrentSprite.xPosition += offset;
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame >= 4)
            gCurrentSprite.xPosition += offset;
        else
            gCurrentSprite.xPosition -= offset;
    }
}

void NamiheSpittingInit(void)
{
    gCurrentSprite.pOam = sNamiheOam_Spitting;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x2a;
}

void NamiheSpitting(void)
{
    u16 offset;

    if (NamiheCheckSamusInFront())
        return;

    offset = 0;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
            if (gCurrentSprite.animationDurationCounter == 1)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            else if (gCurrentSprite.animationDurationCounter == 2)
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            break;

        case 7:
            if (gCurrentSprite.animationDurationCounter == 1)
            {
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            }
            else if (gCurrentSprite.animationDurationCounter == 2)
            {
                offset = BLOCK_TO_SUB_PIXEL(0.0625f);
            }
            else if (gCurrentSprite.animationDurationCounter == 4)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    SpriteSpawnSecondary(SSPRITE_NAMIHE_SPIT, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
                        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                        gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.25f), SPRITE_STATUS_X_FLIP);
                }
                else
                {
                    SpriteSpawnSecondary(SSPRITE_NAMIHE_SPIT, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
                        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.25f), 0);
                }
            }
            break;

        case 15:
            if (gCurrentSprite.animationDurationCounter == 40)
            {
                gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
                return;
            }
            break;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.currentAnimationFrame >= 8)
            gCurrentSprite.xPosition -= offset;
        else
            gCurrentSprite.xPosition += offset;
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame >= 8)
            gCurrentSprite.xPosition += offset;
        else
            gCurrentSprite.xPosition -= offset;
    }
}

void NamiheLungingInit(void)
{
    gCurrentSprite.pOam = sNamiheOam_Lunging;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x2c;

    SoundPlayNotAlreadyPlaying(SOUND_NAMIHE_LUNGING);
}

void NamiheLunging(void)
{
    u16 offset;

    offset = 0;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            if (gCurrentSprite.animationDurationCounter == 1)
                offset = BLOCK_TO_SUB_PIXEL(0.375f);
            else if (gCurrentSprite.animationDurationCounter == 3)
                offset = BLOCK_TO_SUB_PIXEL(0.375f);
            break;

        case 18:
            if (gCurrentSprite.animationDurationCounter == 1)
                offset = BLOCK_TO_SUB_PIXEL(0.25f);
            else if (gCurrentSprite.animationDurationCounter == 3)
                offset = BLOCK_TO_SUB_PIXEL(0.25f);
            break;

        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
            if (gCurrentSprite.animationDurationCounter == 1)
                offset = BLOCK_TO_SUB_PIXEL(0.25f);
            else if (gCurrentSprite.animationDurationCounter == 2)
                offset = BLOCK_TO_SUB_PIXEL(0.25f);
            break;

        case 37:
            if (gCurrentSprite.animationDurationCounter == 40)
                gCurrentSprite.pose = 0x2e;
            break;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (gCurrentSprite.currentAnimationFrame >= 19)
        {
            gCurrentSprite.xPosition -= offset;
            gCurrentSprite.hitboxLeft += offset;
        }
        else
        {
            gCurrentSprite.xPosition += offset;
            gCurrentSprite.hitboxLeft -= offset;
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame >= 19)
        {
            gCurrentSprite.xPosition += offset;
            gCurrentSprite.hitboxRight -= offset;
        }
        else
        {
            gCurrentSprite.xPosition -= offset;
            gCurrentSprite.hitboxRight += offset;
        }
    }
}

void NamiheLungingEnd(void)
{
    // Freeze animation
    gCurrentSprite.animationDurationCounter--;

    if (gCurrentSprite.xPosition < gCurrentSprite.workX)
        gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
    else if (gCurrentSprite.xPosition > gCurrentSprite.workX)
        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
    else
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void NamiheSpitInit(void)
{
    u16 samusCenterY;
    u16 spriteY;
    u16 ySpeed;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
    gCurrentSprite.pOam = sNamiheSpitOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_DIES_WHEN_HIT;
    gCurrentSprite.work1 = 6;

    samusCenterY = gSamusData.yPosition + gSamusData.drawDistanceTop / 2;
    spriteY = gCurrentSprite.yPosition;
    if (spriteY > samusCenterY)
    {
        gCurrentSprite.work2 = FALSE;
        ySpeed = (spriteY - samusCenterY) / 32;
    }
    else
    {
        gCurrentSprite.work2 = TRUE;
        ySpeed = (samusCenterY - spriteY) / 32;
    }

    gCurrentSprite.work4 = ySpeed;

    SoundPlayNotAlreadyPlaying(SOUND_NAMIHE_SPIT);
}

void NamiheSpitMoving(void)
{
    SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.15625f);
        else
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.15625f);

        if (gCurrentSprite.work1 > 0)
        {
            gCurrentSprite.work1--;
        }
        else
        {
            if (gCurrentSprite.work2)
                gCurrentSprite.yPosition += gCurrentSprite.work4;
            else
                gCurrentSprite.yPosition -= gCurrentSprite.work4;
        }
    }
}

void NamiheSpitExplodingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_EXPLODING;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pOam = sNamiheSpitOam_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void NamiheSpitExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

void Fune(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_FUNE_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            FuneInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            FuneIdleInit();

        case SPRITE_POSE_IDLE:
            FuneIdle();
            break;

        case 0x29:
            FuneSpittingInit();

        case 0x2a:
            FuneSpitting();
            break;

        case 0x2b:
            FuneLungingInit();

        case 0x2c:
            FuneLunging();
            break;

        case 0x2e:
            FuneLungingEnd();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            FuneDying();
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            FuneInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            FuneTurningIntoX();
            XParasiteInit();
            break;
    }
}

void FuneSpit(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            FuneSpitInit();

        case SPRITE_POSE_IDLE:
            FuneSpitMoving();
            break;

        case SPRITE_POSE_EXPLODING:
            FuneSpitExploding();
            break;

        default:
            FuneSpitExplodingInit();
            break;
    }
}

void Namihe(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_NAMIHE_HURT);

    if (gCurrentSprite.freezeTimer > 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            NamiheInit();
            break;

        case SPRITE_POSE_IDLE_INIT:
            NamiheIdleInit();

        case SPRITE_POSE_IDLE:
            NamiheIdle();
            break;

        case 0x29:
            NamiheSpittingInit();

        case 0x2a:
            NamiheSpitting();
            break;

        case 0x2b:
            NamiheLungingInit();

        case 0x2c:
            NamiheLunging();
            break;

        case 0x2e:
            NamiheLungingEnd();
            break;

        case SPRITE_POSE_DYING_INIT:
            SpriteDyingInit();

        case SPRITE_POSE_DYING:
            NamiheDying();
            SpriteDying();
            break;

        case SPRITE_POSE_SPAWNING_FROM_X_INIT:
            NamiheInit();

        case SPRITE_POSE_SPAWNING_FROM_X:
            SpriteSpawningFromX();
            break;

        case SPRITE_POSE_TURNING_INTO_X:
            NamiheTurningIntoX();
            XParasiteInit();
            break;
    }
}

void NamiheSpit(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            NamiheSpitInit();

        case SPRITE_POSE_IDLE:
            NamiheSpitMoving();
            break;

        case SPRITE_POSE_EXPLODING:
            NamiheSpitExploding();
            break;

        default:
            NamiheSpitExplodingInit();
            break;
    }
}
