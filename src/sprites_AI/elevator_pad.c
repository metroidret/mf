#include "sprites_AI/elevator_pad.h"
#include "macros.h"
#include "globals.h"

#include "data/sprites/elevator_pad.h"

#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/samus.h"
#include "structs/sprite.h"

/**
 * @brief 473bc | a8 | Elevator pad AI
 * 
 */
void ElevatorPad(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(0.0625);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0.0625);
        gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(0.0625);

        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.pOam = sElevatorPadOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;
    }

    if (gSamusData.pose == SPOSE_USING_ELEVATOR)
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
}
