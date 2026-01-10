#include "sprites_AI/dachora.h"

boolu32 DachoraCheckDoHeadMovement(void)
{
    boolu32 do_head_movement;

    do_head_movement = 1;
    switch (gSpriteRandomNumber)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            gCurrentSprite.pose = 7;
            gCurrentSprite.work2 = 0;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            gCurrentSprite.pose = 7;
            gCurrentSprite.work2 = 1;
            break;
        case 8:
        case 9:
            gCurrentSprite.pose = 7;
            gCurrentSprite.work2 = 2;
            break;
        case 10:
        case 11:
        case 12:
            gCurrentSprite.pose = 7;
            gCurrentSprite.work2 = 3;
            break;
        default:
            do_head_movement = FALSE;
            break;
    }
    return do_head_movement;
}

void DachoraInit(void)
{
    boolu32 animals_released;

    animals_released = EventCheckAfter_AnimalsReleased();

    if (animals_released)
    {
        gCurrentSprite.status = 0x0;
    }
    else
    {
        gCurrentSprite.properties = gCurrentSprite.properties | SP_ALWAYS_ACTIVE;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 0xe;
        gCurrentSprite.bgPriority = 3;
        gCurrentSprite.drawDistanceTop = 0x30;
        gCurrentSprite.drawDistanceBottom = 8;
        gCurrentSprite.drawDistanceHorizontal = 0x20;
        gCurrentSprite.hitboxTop = -4;
        gCurrentSprite.hitboxBottom = 4;
        gCurrentSprite.hitboxLeft = -4;
        gCurrentSprite.hitboxRight = 4;
        gCurrentSprite.yPosition = gCurrentSprite.yPosition - 0x20;
        gCurrentSprite.workX = gCurrentSprite.xPosition;
        MakeSpriteFaceSamusXFlip();
        gCurrentSprite.pose = 2;
        gCurrentSprite.pOam = (struct FrameData*)0x0838451c;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = animals_released;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.work1 = 0xb4;
    }
    return;
}

void DachoraIdleInit(void)
{
    gCurrentSprite.pose = 2;
    gCurrentSprite.pOam = (struct FrameData*)0x0838451c;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work1 = gSpriteRandomNumber * 4 + 0x3c;
    return;
}

void DachoraIdle(void)
{
    u16 var1;
    u16 var2;

    if (EventCheckAfter_AnimalsReleased())
    {
        if (gSpriteData[gBossWork2].pose == 0x1A)
        {
            var1 = (gAbilityRestingXPosition - 0x100) & 0xFFFF;
            if (gCurrentSprite.xPosition > var1 - 0x20 && gCurrentSprite.xPosition < var1 + 0x20)
            {
                gCurrentSprite.pose = 0x17;
                return;
            }
        }
    }
    else if (gCurrentSprite.xPosition > gAbilityRestingXPosition + 0x1C0 ||
        gCurrentSprite.xPosition < gAbilityRestingXPosition - 0x1C0)
    {
        if (gCurrentSprite.work1 != 0)
        {
            gCurrentSprite.work1--;
        }
        else if ((gFrameCounter8Bit & 0x1F) == 0 && (boolu8)DachoraCheckDoHeadMovement())
        {
            return;
        }
    }

    var2 = gCurrentSprite.work3 >> 2;

    if (gCurrentSprite.work3 <= 0x0F)
        gCurrentSprite.work3++;

    if (gCurrentSprite.status & 0x40)
    {
        if (gCurrentSprite.workX + 0x380 >= gCurrentSprite.xPosition)
        {
            var1 = gCurrentSprite.xPosition;
            var1 = var1 + var2;
            gCurrentSprite.xPosition = var1;
            return;
        }
        gCurrentSprite.pose = 3;
    }
    else
    {
        if (gCurrentSprite.workX - 0x380 > gCurrentSprite.xPosition)
        {
            gCurrentSprite.pose = 3;
        }
        else
        {
            gCurrentSprite.xPosition -= var2;
        }
    }

    return;
}

void DachoraStandingIdle(void)
{
    gCurrentSprite.pose = 8;
    gCurrentSprite.pOam = (struct FrameData*)0x0838450c;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 0xb;
}

void DachoraStanding(void)
{
    gCurrentSprite.work1 = gCurrentSprite.work1 - 1;
    if (gCurrentSprite.work1)
        return;

    gCurrentSprite.pose = 9;
}

void DachoraHeadMovementInit(void)
{
    gCurrentSprite.pose = 0xA;

    if (gCurrentSprite.work2 == 1)
    {
        gCurrentSprite.pOam = (struct FrameData*)0x083845c4;
    }
    else if (gCurrentSprite.work2 == 2)
    {
        gCurrentSprite.pOam = (struct FrameData*)0x083845e4;
    }
    else if (gCurrentSprite.work2 == 3)
    {
        gCurrentSprite.pOam = (struct FrameData*)0x083845fc;
    }
    else
    {
        gCurrentSprite.pOam = (struct FrameData*)0x08384584;
    }

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DachoraHeadMovement(void)
{
    if (!SpriteUtilHasCurrentAnimationEnded())
    {
        return;
    }

    if (gCurrentSprite.work2 == 1 && gSpriteRandomNumber > 0xc)
    {
        return;
    }

    if (gSpriteRandomNumber <= 2)
    {
        gCurrentSprite.pose = 3;
    }
    else
    {
        gCurrentSprite.pose = 1;
    }
}

void DachoraTurningAroundInit(void)
{
    gCurrentSprite.pose = 4;
    gCurrentSprite.pOam = (struct FrameData*)0x08384554;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DachoraTurningAround(void)
{
    if (!SpriteUtilHasCurrentAnimationEnded())
    {
        return;
    }

    gCurrentSprite.pose = 5;
    gCurrentSprite.pOam = (struct FrameData*)0x0838456C;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.status ^= 0x40;

    if (gCurrentSprite.drawOrder == 0xE)
    {
        gCurrentSprite.drawOrder = 0xf;
    }
    else
    {
        gCurrentSprite.drawOrder = 0xe;
    }
}

void DachoraTurningAroundSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded() != 0)
    {
        gCurrentSprite.pose = 1;
    }
}

void DachoraTurningAroundWhileLeavingInit(void)
{
    gCurrentSprite.pose = 0x38;
    gCurrentSprite.pOam = (struct FrameData*)0x08384554;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void DachoraTurningAroundWhileLeaving(void)
{
    if (SpriteUtilHasCurrentAnimationEnded() != 0)
    {
        gCurrentSprite.pose = 0x3A;
        gCurrentSprite.pOam = (struct FrameData*)0x0838456C;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.status ^= 0x40;
    }
}

void DachoraTurningAroundWhileLeavingSecondPart(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded() != 0)
    {
        gCurrentSprite.pose = 0x19;
    }
}

void DachoraLeavingEnclosureInit(void)
{
    gCurrentSprite.pose = 0x18;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.bgPriority = 2;
    gCurrentSprite.drawOrder = 4;
}

void DachoraLeavingEnclosure(void)
{
    s16 offset;
    u8 index;

    index = gCurrentSprite.work4;
    offset = sAnimalsEnclosure_38188c[index];

    if (offset == SHORT_MAX)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.pose = 0x1a;
        else
            gCurrentSprite.pose = 0x37;
    }
    else
    {
        gCurrentSprite.work4++;
        gCurrentSprite.yPosition += offset;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += PIXEL_SIZE;
        else
            gCurrentSprite.xPosition -= PIXEL_SIZE;
    }
}

void DachoraWalkingToWaitingSpotInit(void)
{
    gCurrentSprite.pOam = (struct FrameData*)0x0838451C;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x1A;
}

void DachoraWalkingToWaitingSpot(void)
{
    if ((s32)gCurrentSprite.xPosition < (s32)(gAbilityRestingXPosition - 0xC0))
    {
        gCurrentSprite.xPosition += 4;
        return;
    }
    gCurrentSprite.pOam = (struct FrameData*)0x083846CC;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 0x1B;
}

void DachoraWaitingForOthers(void)
{
    u8 count;
    u8 i;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
    {
        SoundPlay(0x122);
    }

    for (count = 0, i = 0; i < 0x18; i++)
    {
        if (gSpriteData[i].status & 1 && !(gSpriteData[i].properties & 0x80) && gSpriteData[i].spriteId == 0xB6 &&
            gSpriteData[i].pose == 0x1C)
            count++;
    }

    if (count == 3)
    {
        gCurrentSprite.pose = 0x1C;
        gCurrentSprite.work1 = 0x3C;
    }
}

void DachoraWaitingToSpawnBaby(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
    {
        SoundPlay(0x122);
    }

    gCurrentSprite.work1--;
    if (gCurrentSprite.work1 == 0)
    {
        gCurrentSprite.pose = 0x1D;
        SpriteSpawnSecondary(0x69, 0, gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition - 0x20, gCurrentSprite.xPosition - 0xC0, 0x40);
        gCurrentSprite.work1 = 0x78;
    }
}

void DachoraWaitingForBaby(void)
{
    u32 var;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
    {
        SoundPlay(0x122);
    }

    var = (--gCurrentSprite.work1) & 0xff;
    if (var == 0)
    {
        gCurrentSprite.pose = 0x1E;
        gPreventMovementTimer = var;
        sSamusSetPoseFunctionPointer[gSamusData.unk_0](0x3B);
        gCurrentSprite.work1 = 0x3C;
        gCurrentSprite.work2 = 1;
    }
}

void DachoraBowing(void)
{
    u32 var1, var2;

    if (gCurrentSprite.work1 != 0)
    {
        var1 = --gCurrentSprite.work1;
        if (var1 == 0)
        {
            gCurrentSprite.pOam = (struct FrameData*)0x08384584;
            gCurrentSprite.animationDurationCounter = var1;
            gCurrentSprite.currentAnimationFrame = var1;
            SoundPlay(0x123);
        }
        else if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        {
            SoundPlay(0x122);
        }
    }
    else if (SpriteUtilHasCurrentAnimationEnded() != 0)
    {
        var2 = --gCurrentSprite.work2;
        if (var2 == 0)
        {
            gCurrentSprite.pose = 0x1F;
            gCurrentSprite.work1 = 0x3C;
            gCurrentSprite.pOam = (struct FrameData*)0x083846CC;
            gCurrentSprite.animationDurationCounter = var2;
            gCurrentSprite.currentAnimationFrame = var2;
        }
    }
}

void DachoraWaitingToRun(void)
{
    u32 var;

    var = --gCurrentSprite.work1;
    if (var == 0)
    {
        *(&gCurrentSprite.work1 - 0xA) = 0x20;
        gCurrentSprite.pOam = (struct FrameData*)0x0838451C;
        gCurrentSprite.animationDurationCounter = var;
        gCurrentSprite.currentAnimationFrame = var;
        SoundPlay_3b1c(0x124);
    }
}

void DachoraRunning(void)
{
    u16 temp_r0;

    gCurrentSprite.xPosition += 0xE;
    gCurrentSprite.animationDurationCounter += 2;
    temp_r0 = 2 & gCurrentSprite.status;
    if (temp_r0 == 0)
    {
        gCurrentSprite.status = temp_r0;
    }
}

void BabyDachoraInit(void)
{
    gCurrentSprite.status &= 0xFFFB;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.drawOrder = 0xC;
    gCurrentSprite.bgPriority = 3;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTop = 0x10;
    gCurrentSprite.drawDistanceBottom = 0;
    gCurrentSprite.drawDistanceHorizontal = 8;
    gCurrentSprite.hitboxTop = -4;
    gCurrentSprite.hitboxBottom = 4;
    gCurrentSprite.hitboxLeft = -4;
    gCurrentSprite.hitboxRight = 4;
    gCurrentSprite.pOam = (struct FrameData*)0x0838462C;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = 1;
    gCurrentSprite.work1 = 0x20;
}

void BabyDachoraWalkingToGate(void)
{
    u8 var;

    var = --gCurrentSprite.work1;
    if (var != 0)
    {
        gCurrentSprite.xPosition += 4;
    }
    else
    {
        gCurrentSprite.pose = 2;
        gCurrentSprite.work4 = var;
    }
}

void BabyDachoraLeavingEnclosure(void)
{
    u8 var;

    var = gCurrentSprite.work4;

    if (sAnimalsEnclosure_38188c[var] == 0x7FFF)
    {
        gCurrentSprite.pose = 0x17;
        gCurrentSprite.work1 = 0x28;
        gCurrentSprite.bgPriority = 2;
    }
    else
    {
        gCurrentSprite.work4 = var + 1;
        gCurrentSprite.yPosition += sAnimalsEnclosure_38188c[var];
        gCurrentSprite.xPosition += 4;
    }
}

void BabyDachoraWalkingToWaitingSpot(void)
{
    u8 var;

    var = --gCurrentSprite.work1;
    if (var)
    {
        gCurrentSprite.xPosition += 2;
    }
    else
    {
        gCurrentSprite.pose = 0x18;
        gCurrentSprite.drawOrder = 5;
        gCurrentSprite.pOam = (struct FrameData*)0x083846F4;
        gCurrentSprite.animationDurationCounter = var;
        gCurrentSprite.currentAnimationFrame = var;
    }
}

void BabyDachoraWaitingToRun(void)
{
    u8 i;
    u8* e0;
    u8* ea;
    struct SpriteData* sprites;

    i = 0;
    sprites = gSpriteData;
    ea = &gCurrentSprite.work1;
    e0 = ea - 0xA;

    while (i < 0x18)
    {
        if (sprites[i].status & 1 && !(sprites[i].properties & 0x80) && sprites[i].spriteId == 0xB8 &&
            sprites[i].pose == 0x20)
        {
            *e0 = 0x19;
            *ea = 0x5A;
        }
        i++;
    }
}

void BabyDachoraRunning(void)
{
    u16 var1, var2;

    if (gCurrentSprite.work1 != 0)
    {
        var1 = --gCurrentSprite.work1;
        if (var1 == 0)
        {
            gCurrentSprite.pOam = (struct FrameData*)0x0838462C;
            gCurrentSprite.animationDurationCounter = var1;
            gCurrentSprite.currentAnimationFrame = var1;
        }
    }
    else
    {
        gCurrentSprite.xPosition += 8;
        gCurrentSprite.animationDurationCounter += 4;

        var2 = gCurrentSprite.status & 2;
        if (var2 == 0)
        {
            gSamusData.currentAnimationFrame++;
            gCurrentSprite.status = var2;
        }
    }
}
