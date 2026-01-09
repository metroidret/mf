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
