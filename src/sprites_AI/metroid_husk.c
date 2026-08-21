#include "data/sprites/metroid_husk.h"

#include "globals.h"

#include "data/sprite_data.h"
#include "data/sprites/x_parasite.h"

#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/samus.h"
#include "structs/sprite.h"

void MetroidHusk(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.drawOrder = 4;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(2);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
        gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1.5f);
        gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
        gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
        gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
        gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
        gCurrentSprite.pose = 2;
        gCurrentSprite.pOam = sMetroidHuskOam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}
