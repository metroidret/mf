#include "globals.h"
#include "event_checks.h"
#include "structs/sprite.h"
#include "constants/sprite.h"

boolu32 DachoraCheckDoHeadMovement(void) {
    boolu32 do_head_movement;

    do_head_movement = 1;
    switch (gSpriteRandomNumber) {
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

  if (animals_released) {
    gCurrentSprite.status = 0x0;
  } else {
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
    gCurrentSprite.pOam = (struct FrameData*)0x0838451c; // ?
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = animals_released;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work1 = 0xb4;
  }
  return;
}

void DachoraIdleInit(void) {
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

    if (CheckOnAfterAnimalsReleasedEvent()) {
        if (gSpriteData[gBossWork2].pose == 0x1A) {
            var1 = (gAbilityRestingXPosition - 0x100) & 0xFFFF;
            if (gCurrentSprite.xPosition > var1 - 0x20 &&
                gCurrentSprite.xPosition < var1 + 0x20) {
                gCurrentSprite.pose = 0x17;
                return;
            }
        }
    } else if (gCurrentSprite.xPosition > gAbilityRestingXPosition + 0x1C0 ||
               gCurrentSprite.xPosition < gAbilityRestingXPosition - 0x1C0) {

        if (gCurrentSprite.work1 != 0) {
            gCurrentSprite.work1--;
        } else if ((gFrameCounter8Bit & 0x1F) == 0 &&
                   (boolu8)DachoraCheckDoHeadMovement()) {
            return;
        }
    }

    var2 = gCurrentSprite.work3 >> 2;

    if (gCurrentSprite.work3 <= 0x0F)
        gCurrentSprite.work3++;

    if (gCurrentSprite.status & 0x40) {
        if (gCurrentSprite.workX + 0x380 >= gCurrentSprite.xPosition) {
            var1 = gCurrentSprite.xPosition;
            var1 = var1 + var2;
            gCurrentSprite.xPosition = var1;
            return;
        }
        gCurrentSprite.pose = 3;
    } else {
      if (gCurrentSprite.workX - 0x380 > gCurrentSprite.xPosition) {
        gCurrentSprite.pose = 3;
      } else {
        gCurrentSprite.xPosition -= var2;
      }
    }

    return;
}

asm (".short 0x0000");

void DachoraStandingIdle(void) {
    gCurrentSprite.pose = 8;
    gCurrentSprite.pOam = (struct FrameData*)0x0838450c;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work1 = 0xb;
}

void DachoraStanding(void) {
    gCurrentSprite.work1 = gCurrentSprite.work1 - 1;
    if (gCurrentSprite.work1)
        return;

    gCurrentSprite.pose = 9;
}
