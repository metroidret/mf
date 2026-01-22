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
        gCurrentSprite.drawDistanceTop = 32;
        gCurrentSprite.drawDistanceBottom = 16;
        gCurrentSprite.drawDistanceHorizontal = 24;
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
