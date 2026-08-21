#include "sprites_AI/owtch.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/owtch.h"
#include "data/sprites/x_parasite.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/samus.h"
#include "structs/sprite.h"

enum OwtchPose {
    OWTCH_POSE_TURNING_AROUND_INIT = 3,
    OWTCH_POSE_TURNING_AROUND = 4,
    OWTCH_POSE_LANDING_INIT = 7,
    OWTCH_POSE_LANDING = 8
};

boolu8 OwtchCheckCollidingWithAir(void)
{
    boolu8 colliding;

    colliding = FALSE;

    if (gCurrentSprite.work0 != 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == 0)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition);
                if (gPreviousCollisionCheck == 0)
                    colliding = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
            if (gPreviousCollisionCheck == 0)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                    gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                if (gPreviousCollisionCheck == 0)
                    colliding = TRUE;
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousCollisionCheck == 0)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                if (gPreviousCollisionCheck == 0)
                    colliding = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
            if (gPreviousCollisionCheck == 0)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                if (gPreviousCollisionCheck == 0)
                    colliding = TRUE;
            }
        }
    }

    return colliding;
}

void OwtchUpdateHitbox(void)
{
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.6875f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.25f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.6875f);
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.6875f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.4375f);
        }
        else
        {
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.6875f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.25f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.4375f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.4375f);
        }
    }

    return;
}

void OwtchSetCrawlingOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sOwtchOam_379154;
    else
        gCurrentSprite.pOam = sOwtchOam_3790d4;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void OwtchSetFallingOam(void)
{
    if (gCurrentSprite.work0)
        gCurrentSprite.pOam = sOwtchOam_379154;
    else
        gCurrentSprite.pOam = sOwtchOam_3790d4;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

void OwtchTurningIntoX(void)
{
    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.625f);
        else
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.625f);
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.625f);
        else
            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.625f);
    }
}

void OwtchInit(void)
{
    SpriteUtilTrySetAbsorbXFlag();
    if ((gCurrentSprite.properties & SP_CAN_ABSORB_X) && (!(gCurrentSprite.status & SPRITE_STATUS_HIDDEN)))
    {
        gCurrentSprite.status = 0;
    }
    else
    {
        if (gCurrentSprite.pose == SPRITE_POSE_SPAWNING_FROM_X_INIT)
        {
            gCurrentSprite.pose = SPRITE_POSE_SPAWNING_FROM_X;
            gCurrentSprite.workY = X_PARASITE_MOSAIC_MAX_INDEX;
        }
        else
        {
            SpriteUtilChooseRandomXDirection();
            gCurrentSprite.pose = SPRITE_POSE_IDLE;

            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            {
                gCurrentSprite.work0 = FALSE;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(1.0625f),
                    gCurrentSprite.xPosition);
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    gCurrentSprite.work0 = FALSE;
                    gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(1.0f);
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5625f));
                    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                    {
                        gCurrentSprite.work0 = TRUE;
                        gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                        gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                        {
                            gCurrentSprite.work0 = TRUE;
                            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);
                        }
                        else
                        {
                            gCurrentSprite.status = 0;
                            return;
                        }
                    }
                }
            }
        }

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

        OwtchSetCrawlingOam();
        OwtchUpdateHitbox();

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.work1 = 0;
        gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
        gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(1);
        gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(1);
    }
}

void OwtchIdleInit(void)
{
    OwtchSetCrawlingOam();
    gCurrentSprite.pose = SPRITE_POSE_IDLE;
}

void OwtchIdle(void)
{
    boolu8 turnAround;

    turnAround = FALSE;

    if (OwtchCheckCollidingWithAir())
    {
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
    }
    else if (!(gCurrentSprite.properties & SP_CAN_ABSORB_X))
    {
        if (gCurrentSprite.work0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turnAround = TRUE;
                        gCurrentSprite.work2 = 7;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turnAround = TRUE;
                            gCurrentSprite.work2 = 5;
                        }
                        else
                        {
                            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
                        }
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                        gCurrentSprite.xPosition);
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turnAround = TRUE;
                        gCurrentSprite.work2 = 5;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turnAround = TRUE;
                            gCurrentSprite.work2 = 7;
                        }
                        else
                        {
                            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
                        }
                    }
                }
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turnAround = TRUE;
                        gCurrentSprite.work2 = 6;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(0.5f),
                            gCurrentSprite.xPosition);
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                            turnAround = TRUE;
                            gCurrentSprite.work2 = 4;
                        }
                        else
                        {
                            gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
                        }
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turnAround = TRUE;
                        gCurrentSprite.work2 = 4;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.5f),
                            gCurrentSprite.xPosition);
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                            turnAround = TRUE;
                            gCurrentSprite.work2 = 6;
                        }
                        else
                        {
                            gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
                        }
                    }
                }
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                        gCurrentSprite.xPosition);
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turnAround = TRUE;
                        gCurrentSprite.work2 = 2;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                            turnAround = TRUE;
                            gCurrentSprite.work2 = 3;
                        }
                        else
                        {
                            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
                        }
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turnAround = TRUE;
                        gCurrentSprite.work2 = 3;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                            turnAround = TRUE;
                            gCurrentSprite.work2 = 2;
                        }
                        else
                        {
                            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
                        }
                    }
                }
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turnAround = TRUE;
                        gCurrentSprite.work2 = 0;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                            gCurrentSprite.xPosition + BLOCK_TO_SUB_PIXEL(0.5f));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turnAround = TRUE;
                            gCurrentSprite.work2 = 1;
                        }
                        else
                        {
                            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.015625f);
                        }
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition,
                        gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.0625f));
                    if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turnAround = TRUE;
                        gCurrentSprite.work2 = 1;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
                            gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turnAround = TRUE;
                            gCurrentSprite.work2 = 0;
                        }
                        else
                        {
                            gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.015625f);
                        }
                    }
                }
            }
        }

        if (turnAround)
            gCurrentSprite.pose = OWTCH_POSE_TURNING_AROUND_INIT;
    }
}

void OwtchTurningAroundInit(void)
{
    gCurrentSprite.pose = OWTCH_POSE_TURNING_AROUND;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    switch (gCurrentSprite.work2)
    {
        case 0:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sOwtchOam_379114;
            else
                gCurrentSprite.pOam = sOwtchOam_379194;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case 1:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sOwtchOam_379114;
            else
                gCurrentSprite.pOam = sOwtchOam_379194;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case 2:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sOwtchOam_379194;
            else
                gCurrentSprite.pOam = sOwtchOam_379114;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        case 3:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sOwtchOam_379194;
            else
                gCurrentSprite.pOam = sOwtchOam_379114;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        case 4:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sOwtchOam_3791b4;
            else
                gCurrentSprite.pOam = sOwtchOam_379134;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case 5:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sOwtchOam_379134;
            else
                gCurrentSprite.pOam = sOwtchOam_3791b4;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case 6:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sOwtchOam_3791b4;
            else
                gCurrentSprite.pOam = sOwtchOam_379134;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        case 7:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sOwtchOam_379134;
            else
                gCurrentSprite.pOam = sOwtchOam_3791b4;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        default:
            gCurrentSprite.status = 0;
            break;
    }
}

void OwtchTurningAround(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SPRITE_POSE_IDLE;

        switch (gCurrentSprite.work2)
        {
            case 0:
                if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                {
                    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.4375f);
                    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.4375f);
                }

                gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
                gCurrentSprite.work0 = TRUE;
                break;

            case 1:
                if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                {
                    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                    gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);
                }

                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.work0 = TRUE;
                break;

            case 2:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.4375f);
                    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.4375f);
                }

                gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
                gCurrentSprite.work0 = TRUE;
                break;

            case 3:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.5f);
                    gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);
                }

                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.work0 = TRUE;
                break;

            case 4:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.5f);
                    gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.5f);
                }

                gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
                gCurrentSprite.work0 = FALSE;
                break;

            case 5:
                if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                {
                    gCurrentSprite.yPosition += BLOCK_TO_SUB_PIXEL(0.5f);
                    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.5f);
                }

                gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
                gCurrentSprite.work0 = FALSE;
                break;

            case 6:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.4375f);
                    gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.4375f);
                }

                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                gCurrentSprite.work0 = FALSE;
                break;

            case 7:
                if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                {
                    gCurrentSprite.yPosition -= BLOCK_TO_SUB_PIXEL(0.4375f);
                    gCurrentSprite.xPosition -= BLOCK_TO_SUB_PIXEL(0.4375f);
                }

                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                gCurrentSprite.work0 = FALSE;
                break;

            default:
                gCurrentSprite.status = 0;
                break;
        }

        OwtchSetCrawlingOam();
        OwtchUpdateHitbox();
    }
}

void OwtchLandingInit(void)
{
    gCurrentSprite.pose = OWTCH_POSE_LANDING;
    OwtchSetFallingOam();
}

void OwtchLanding(void)
{
    if (OwtchCheckCollidingWithAir())
        gCurrentSprite.pose = SPRITE_POSE_FALLING_INIT;
    else if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
}

void OwtchFallingInit(void)
{
    gCurrentSprite.pose = SPRITE_POSE_FALLING;
    gCurrentSprite.work4 = 0;
    gCurrentSprite.work0 = 0;
    gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;

    OwtchUpdateHitbox();
    OwtchSetFallingOam();
}

void OwtchFalling(void)
{
    u16 yCollisionPoint;
    u16 xCollisionPoint;
    u32 blockTop;
    u8 onWall;
    u8 offset;
    s16 movement;

    onWall = FALSE;
    yCollisionPoint = gCurrentSprite.yPosition;
    xCollisionPoint = gCurrentSprite.xPosition;

    if (gCurrentSprite.work0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            xCollisionPoint -= 4;

        yCollisionPoint += gCurrentSprite.hitboxBottom;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            yCollisionPoint += gCurrentSprite.hitboxBottom;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yCollisionPoint, xCollisionPoint);

    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        if (gCurrentSprite.work0)
            onWall++;

        gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.work0 = 0;
        OwtchUpdateHitbox();

        if (onWall)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxRight;
            else
                gCurrentSprite.xPosition -= gCurrentSprite.hitboxLeft;
        }

        if (gCurrentSprite.properties & SP_CAN_ABSORB_X)
        {
            gCurrentSprite.pose = SPRITE_POSE_IDLE;
            OwtchSetCrawlingOam();
        }
        else
        {
            gCurrentSprite.pose = OWTCH_POSE_LANDING;
            OwtchSetFallingOam();
        }
    }
    else
    {
        offset = gCurrentSprite.work4;
        movement = sSpritesFallingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            offset++;
            gCurrentSprite.work4 = offset;
            gCurrentSprite.yPosition += movement;
        }
    }
}

void Owtch(void)
{
    if (SPRITE_GET_ISFT(gCurrentSprite) == 4)
        SoundPlayNotAlreadyPlaying(SOUND_OWTCH_HURT);

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
    }
    else
    {
        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                OwtchInit();
                break;

            case SPRITE_POSE_IDLE_INIT:
                OwtchIdleInit();
            case SPRITE_POSE_IDLE:
                OwtchIdle();
                break;

            case OWTCH_POSE_TURNING_AROUND_INIT:
                OwtchTurningAroundInit();
            case OWTCH_POSE_TURNING_AROUND:
                OwtchTurningAround();
                break;

            case OWTCH_POSE_LANDING_INIT:
                OwtchLandingInit();
            case OWTCH_POSE_LANDING:
                OwtchLanding();
                break;

            case SPRITE_POSE_FALLING_INIT:
                OwtchFallingInit();
            case SPRITE_POSE_FALLING:
                OwtchFalling();
                break;

            case SPRITE_POSE_DYING_INIT:
                SpriteDyingInit();
            case SPRITE_POSE_DYING:
                SpriteDying();
                break;

            case SPRITE_POSE_SPAWNING_FROM_X_INIT:
                OwtchInit();
            case SPRITE_POSE_SPAWNING_FROM_X:
                SpriteSpawningFromX();
                break;

            case SPRITE_POSE_TURNING_INTO_X:
                OwtchTurningIntoX();
                XParasiteInit();
                break;
        }
    }
}
