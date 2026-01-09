#include "event_checks.h"
#include "structs/sprite.h"
#include "constants/sprite.h"

void DachoraInit(void)
{
  u32 animals_released;
    
  animals_released = EventCheckAfter_AnimalsReleased();

  if (animals_released) {
    gCurrentSprite.status = 0x0;
  }
  else {
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
    // gCurrentSprite.samusCollision = animals_released;
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
