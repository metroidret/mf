#include "sprites_AI/lab_debris.h"
#include "data/sprites/lab_debris.h"

#include "globals.h"
#include "macros.h"

#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite_debris.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"

enum LabDebrisPose {
    LAB_DEBRIS_POSE_IDLE = 1,
    LAB_DEBRIS_POSE_FALLING = 2,
    LAB_DEBRIS_POSE_CRUMBLING = 0x18,
};

#define LAB_DEBRIS_FALL_DELAY work1
#define LAB_DEBRIS_PARTICLE_TIMER work2
#define LAB_DEBRIS_FALL_SPEED_IDX work4

/**
 * @brief 4f518 | 60 | Sets collision for lab debris based on which piece it is
 * 
 * @param clipAction Clipdata affecting action
 */
void LabDebrisSetCollision(u8 clipAction)
{
    u16 yPosition;
    u16 xPosition;
    u8 prop;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    prop = gCurrentSprite.spritesetSlotAndProperties;

    gCurrentClipdataAffectingAction = clipAction;
    ClipdataProcess(yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition);
    
    gCurrentClipdataAffectingAction = clipAction;
    ClipdataProcess(yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition + BLOCK_TO_SUB_PIXEL(1));
    
    if (prop == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3)) ||
        prop == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4)))
    {
        gCurrentClipdataAffectingAction = clipAction;
        ClipdataProcess(yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition + BLOCK_TO_SUB_PIXEL(2));
    }
}

/**
 * @brief 4f578 | 9c | Initializes lab debris
 * 
 */
void LabDebrisInit(void)
{
    if (!EventCheckOn_RestrictedLabExplosion())
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(1);
    gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(3);

    gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.0625f);
    gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.0625f);

    gCurrentSprite.pose = LAB_DEBRIS_POSE_IDLE;
    gCurrentSprite.LAB_DEBRIS_PARTICLE_TIMER = 0;
    gCurrentSprite.pOam = sLabDebrisOam_Left;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    if (gCurrentSprite.spritesetSlotAndProperties == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3)))
        gCurrentSprite.pOam = sLabDebrisOam_Middle;
    else if (gCurrentSprite.spritesetSlotAndProperties == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4)))
        gCurrentSprite.pOam = sLabDebrisOam_Right;
    else
        gCurrentSprite.pOam = sLabDebrisOam_Left;

    LabDebrisSetCollision(CAA_MAKE_SOLID);
}

/**
 * @brief 4f614 | 5c | Handles lab debris being idle
 * 
 */
void LabDebrisIdle(void)
{
    if ((u8)EventCheckOn_Escape() == ESCAPE_RESTRICTED_LAB)
    {
        gCurrentSprite.LAB_DEBRIS_FALL_SPEED_IDX = 0;
        gCurrentSprite.pose = LAB_DEBRIS_POSE_FALLING;

        if (gCurrentSprite.spritesetSlotAndProperties == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2)))
            gCurrentSprite.LAB_DEBRIS_FALL_DELAY = CONVERT_SECONDS(.8f);
        else if (gCurrentSprite.spritesetSlotAndProperties == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4)))
            gCurrentSprite.LAB_DEBRIS_FALL_DELAY = CONVERT_SECONDS(17/30.f);
        else if (gXParasiteTargetXPosition > gCurrentSprite.xPosition)
            gCurrentSprite.LAB_DEBRIS_FALL_DELAY = CONVERT_SECONDS(1/6.f);
        else
            gCurrentSprite.LAB_DEBRIS_FALL_DELAY = CONVERT_SECONDS(.4f);
    }
}

/**
 * @brief 4f670 | 1d4 | Handles lab debris falling
 * 
 */
void LabDebrisFalling(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 prop;

    u32 blockTopY;
    u8 index;
    s16 ySpeed;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    prop = gCurrentSprite.spritesetSlotAndProperties;

    if (gCurrentSprite.LAB_DEBRIS_FALL_DELAY > 0)
    {
        gCurrentSprite.LAB_DEBRIS_FALL_DELAY--;
        if (gCurrentSprite.LAB_DEBRIS_FALL_DELAY > 0)
            return;

        LabDebrisSetCollision(CAA_REMOVE_SOLID);
        ParticleSet(yPosition + BLOCK_TO_SUB_PIXEL(.5f), xPosition, PE_0x2F);
        SoundPlay(SOUND_23D);

        if (prop == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2)))
        {
            SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_LEFT,
                yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition + BLOCK_TO_SUB_PIXEL(.125f));
            SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_RIGHT,
                yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition - BLOCK_TO_SUB_PIXEL(.25f));
        }
        else if (prop == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4)))
        {
            SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_FAST_RIGHT,
                yPosition - BLOCK_TO_SUB_PIXEL(1), xPosition - BLOCK_TO_SUB_PIXEL(.25f));
            SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_HOPPING_FAST_LEFT,
                yPosition - BLOCK_TO_SUB_PIXEL(1), xPosition);
        }
        else
        {
            if (gXParasiteTargetXPosition <= gCurrentSprite.xPosition)
            {
                SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_LEFT,
                    yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition + BLOCK_TO_SUB_PIXEL(.125f));
                SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_RIGHT,
                    yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition - BLOCK_TO_SUB_PIXEL(.25f));
            }
            else
            {
                SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_FAST_RIGHT,
                    yPosition, xPosition - BLOCK_TO_SUB_PIXEL(.125f));
                SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_HOPPING_FAST_LEFT,
                    yPosition, xPosition + BLOCK_TO_SUB_PIXEL(.25f));
            }
        }
    }
    else
    {
        blockTopY = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yPosition, xPosition);
        if (gPreviousVerticalCollisionCheck != 0)
        {
            gCurrentSprite.yPosition = blockTopY;
            gCurrentSprite.pose = LAB_DEBRIS_POSE_CRUMBLING;
            gCurrentSprite.LAB_DEBRIS_FALL_SPEED_IDX = 0;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
            gCurrentSprite.bgPriority = gIoRegisters.bg1Cnt & 3;

            SoundPlay(SOUND_23E);

            if (prop == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2)))
            {
                SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_LEFT,
                    yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition + BLOCK_TO_SUB_PIXEL(.125f));
                SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_RIGHT,
                    yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition - BLOCK_TO_SUB_PIXEL(.25f));
            }
            else if (prop == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4)))
            {
                SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_FAST_RIGHT,
                    yPosition - BLOCK_TO_SUB_PIXEL(1), xPosition - BLOCK_TO_SUB_PIXEL(.25f));
                SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_HOPPING_FAST_LEFT,
                    yPosition - BLOCK_TO_SUB_PIXEL(1), xPosition);
            }
            else
            {
                if (gXParasiteTargetXPosition > gCurrentSprite.xPosition)
                {
                    SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_FAST_RIGHT,
                        yPosition, xPosition - BLOCK_TO_SUB_PIXEL(.125f));
                    SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_HOPPING_FAST_LEFT,
                        yPosition, xPosition + BLOCK_TO_SUB_PIXEL(.25f));
                }
                else
                {
                    SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_LEFT,
                        yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition + BLOCK_TO_SUB_PIXEL(.125f));
                    SpriteDebrisInit(DEBRIS_CLOUD_TYPE_NONE, DEBRIS_TYPE_FALLING | DEBRIS_TYPE_HOPPING_SLOW_RIGHT,
                        yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition - BLOCK_TO_SUB_PIXEL(.25f));
                }
            }
        }
        else
        {
            gCurrentSprite.LAB_DEBRIS_PARTICLE_TIMER++;
            index = gCurrentSprite.LAB_DEBRIS_FALL_SPEED_IDX;
            ySpeed = sSpritesFallingSpeed[index];
            if (ySpeed == SHORT_MAX)
            {
                ySpeed = sSpritesFallingSpeed[index - 1];
                gCurrentSprite.yPosition = gCurrentSprite.yPosition + ySpeed;
            }
            else
            {
                gCurrentSprite.LAB_DEBRIS_FALL_SPEED_IDX++;
                gCurrentSprite.yPosition = gCurrentSprite.yPosition + ySpeed;
            }

            if (!(gCurrentSprite.LAB_DEBRIS_PARTICLE_TIMER & 3))
            {
                if (gCurrentSprite.LAB_DEBRIS_PARTICLE_TIMER & 4)
                {
                    ParticleSet(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition, PE_HEAVY_DUST_1);
                }
                else
                {
                    if (prop == (SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2)))
                        xPosition -= BLOCK_TO_SUB_PIXEL(.1875f);
                    else
                        xPosition += BLOCK_TO_SUB_PIXEL(.1875f);

                    ParticleSet(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(.5f), xPosition, PE_HEAVY_DUST_1);
                }
            }
        }
    }
}

/**
 * @brief 4f844 | 4c | Handles lab debris crumbling
 * 
 */
void LabDebrisCrumbling(void)
{
    u8 index;
    s16 ySpeed;

    index = gCurrentSprite.LAB_DEBRIS_FALL_SPEED_IDX;
    ySpeed = sSpritesFallingSpeedHovering[index];

    if (ySpeed == SHORT_MAX)
    {
        ySpeed = sSpritesFallingSpeedHovering[index - 1];
        gCurrentSprite.yPosition += ySpeed;
    }
    else
    {
        gCurrentSprite.LAB_DEBRIS_FALL_SPEED_IDX++;
        gCurrentSprite.yPosition += ySpeed;
    }
}

/**
 * @brief 4f890 | 48 | Lab debris AI
 * 
 */
void LabDebris(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            LabDebrisInit();
            break;

        case LAB_DEBRIS_POSE_IDLE:
            LabDebrisIdle();
            break;

        case LAB_DEBRIS_POSE_FALLING:
            LabDebrisFalling();
            break;
        
        case LAB_DEBRIS_POSE_CRUMBLING:
            LabDebrisCrumbling();
            break;
    }
}
