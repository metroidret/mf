#include "data/sprites/shake_trigger.h"

#include "globals.h"

#include "data/generic_data.h"
#include "data/samus_data.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_debris.h"

#include "structs/clipdata.h"
#include "structs/samus.h"
#include "structs/sprite.h"
#include "structs/sprite_debris.h"

enum ShakeTrigger {
    SHAKE_TRIGGER_SUPER_MISSILE_DOWNLOADED,
    SHAKE_TRIGGER_SA_X_QUAKE,
    SHAKE_TRIGGER_RESTRICTED_LAB_EXPLOSION_FIRST,
    SHAKE_TRIGGER_RESTRICTED_LAB_EXPLOSION_SECOND,
    SHAKE_TRIGGER_BOX_2_RUMBLE
};

void ShakeTriggerStartScreenShake(void)
{
    u8 shake;

    shake = FALSE;

    if (gCurrentSprite.animationDurationCounter == 2)
    {
        shake = TRUE;
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 2:
            case 5:
            case 8:
            case 11:
            case 14:
            case 17:
            case 20:
            case 23:
            case 26:
            case 29:
            case 32:
            case 35:
            case 38:
            case 41:
            case 44:
            case 47:
                break;

            default:
                shake = FALSE;
                break;
        }
    }

    if (shake)
    {
        ScreenShakeStartHorizontal(20, 0x81);
        ScreenShakeStartVertical(20, 0x81);
    }
}

#ifndef BUGFIX
u32 PreBoxCeilingDebrisCheckSamusInRange(u16 yBlockOffset, u16 xBlockOffset)
{
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;
    u16 yOffset;
    u16 xOffset;

    samusY = gSamusData.yPosition - PIXEL_SIZE;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    yOffset = BLOCK_TO_SUB_PIXEL(yBlockOffset);
    xOffset = BLOCK_TO_SUB_PIXEL(xBlockOffset);

    if (spriteX < samusX && samusX < spriteX + xOffset && spriteY < samusY && samusY < spriteY + yOffset)
        return TRUE;

    return FALSE;
}
#endif // !BUGFIX

void ShakeTrigger(void)
{
    u8 type;

    type = gCurrentSprite.roomSlot;
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            if (EventCheckOn_EnteredSuperMissileDataRoom())
            {
                type = SHAKE_TRIGGER_SUPER_MISSILE_DOWNLOADED;
            }
            else if (EventCheckOn_BombsDownloaded())
            {
                type = SHAKE_TRIGGER_SA_X_QUAKE;
            }
            else if (EventCheckOn_WaveBeamRecovered())
            {
                type = SHAKE_TRIGGER_RESTRICTED_LAB_EXPLOSION_FIRST;
            }
            else if (EventCheckOn_RestrictedLabExplosion())
            {
                type = SHAKE_TRIGGER_RESTRICTED_LAB_EXPLOSION_SECOND;
            }
            else if (EventCheckOn_RestrictedZoneWarning())
            {
                type = SHAKE_TRIGGER_BOX_2_RUMBLE;
            }
            else
            {
                gCurrentSprite.status = 0;
                break;
            }

            gCurrentSprite.roomSlot = type;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = SPRITE_POSE_IDLE;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.0625f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.0625f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(.0625f);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.pOam = sShakeTriggerOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (!gDebugFlag)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            break;

        case SPRITE_POSE_IDLE:
            if (type == SHAKE_TRIGGER_SUPER_MISSILE_DOWNLOADED)
            {
                if (EventCheckOn_SuperMissileDownloaded())
                {
                    gCurrentSprite.pose = 0x18;
                    gCurrentSprite.work1 = 20;
                    SoundPlay_3b1c(SOUND_22C);
                    gCurrentSprite.pOam = sShakeTriggerOam_TriggeredNotRestrictedLab;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }
            else if (type == SHAKE_TRIGGER_SA_X_QUAKE)
            {
                if (EventCheckOn_BombsQuake())
                {
                    gCurrentSprite.pose = 0x18;
                    gCurrentSprite.work1 = 8;
                    gCurrentSprite.pOam = sShakeTriggerOam_TriggeredNotRestrictedLab;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }
            else if (type == SHAKE_TRIGGER_BOX_2_RUMBLE)
            {
                if (EventCheckOn_TriggeredBox2Rumble())
                {
                    gCurrentSprite.pose = 0x18;
                    gCurrentSprite.work1 = 8;
                    gCurrentSprite.pOam = sShakeTriggerOam_TriggeredNotRestrictedLab;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }
            else if (type == SHAKE_TRIGGER_RESTRICTED_LAB_EXPLOSION_FIRST)
            {
                if (EventCheckOn_RestrictedLabExplosion())
                {
                    gCurrentSprite.pose = 0x1a;
                    gCurrentSprite.work1 = 30;
                    gCurrentSprite.work2 = 20;
                    gCurrentSprite.pOam = sShakeTriggerOam_TriggeredRestrictedLab;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }
            else if (type == SHAKE_TRIGGER_RESTRICTED_LAB_EXPLOSION_SECOND)
            {
                if (EventCheckOn_RestrictedLabExplosion())
                {
                    gCurrentSprite.pose = 0x1c;
                    gCurrentSprite.pOam = sShakeTriggerOam_TriggeredRestrictedLab;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    SoundPlay(SOUND_239);
                }
            }
            break;

        case 0x18:
            if (--gCurrentSprite.work1 == 0)
            {
                gCurrentSprite.pose = 0x4e;
                ScreenShakeStartHorizontal(60, 0x81);
                ScreenShakeStartVertical(60, 0x81);

                if (type == SHAKE_TRIGGER_SUPER_MISSILE_DOWNLOADED)
                    SoundPlay(SOUND_22D);
                else if (type == SHAKE_TRIGGER_SA_X_QUAKE)
                    SoundPlay_3b1c(SOUND_22B);
                else if (type == SHAKE_TRIGGER_BOX_2_RUMBLE)
                    SoundPlay_3b1c(SOUND_237);
            }
            break;

        case 0x1a:
            if (gCurrentSprite.work1 > 0)
            {
                gCurrentSprite.work1--;
                break;
            }

            if (gCurrentSprite.work2 > 0)
            {
                if (--gCurrentSprite.work2 == 0)
                {
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    PlayMusic(MUSIC_27, 10);
                    SoundPlay(SOUND_238);
                }
                break;
            }

        case 0x1c:
            ShakeTriggerStartScreenShake();
            break;
    }
}

void PreBoxCeilingDebris(void)
{
    u8 var_1;
    u8 var_2;
    u8 var_3;
    u16 y;
    u16 x;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            if (!EventCheckOn_SuperMissileDownloaded())
            {
                gCurrentSprite.status = 0;
                break;
            }
            gCurrentSprite.yPosition -= BLOCK_SIZE;
            gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
            gCurrentSprite.bgPriority = 1;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = SPRITE_POSE_IDLE;
            gCurrentSprite.drawDistanceTop = BLOCK_TO_PIXEL(.0625f);
            gCurrentSprite.drawDistanceBottom = BLOCK_TO_PIXEL(.0625f);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_TO_PIXEL(7);
            gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.0625f);
            gCurrentSprite.pOam = sShakeTriggerOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (!gDebugFlag)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            break;

        case SPRITE_POSE_IDLE:
#ifdef BUGFIX
            if (EventCheckOn_BoxRumble())
#else // !BUGFIX
            if (PreBoxCeilingDebrisCheckSamusInRange(6, 6) && EventCheckOn_BoxRumble())
#endif // BUGFIX
            {
                gCurrentSprite.pose = 0x18;
                gCurrentSprite.pOam = sShakeTriggerOam_TriggeredNotRestrictedLab;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work1 = CONVERT_SECONDS(1.0f);
            }
            break;

        case 0x18:
            if (--gCurrentSprite.work1 == 0)
            {
                gCurrentSprite.pose = 0x1a;
                gCurrentSprite.work1 = UCHAR_MAX; // For the screen to shake next frame
                gCurrentSprite.workY = 420; // Unused
            }
            break;

        case 0x1a:
            gCurrentSprite.work1++;
            var_1 = MOD_AND(gXParasiteTargetXPosition, QUARTER_BLOCK_SIZE);
            var_2 = MOD_AND(gXParasiteTargetYPosition, HALF_BLOCK_SIZE);
            var_3 = gSpriteRandomNumber;
            if (var_3 < 8)
                var_3 += 8;

            y = gCurrentSprite.yPosition;
            // Needed to produce matching ASM
            y++; y--;
            x = gCurrentSprite.xPosition;
            gCurrentSprite.xPosition += BLOCK_TO_SUB_PIXEL(0.0625f);
            SpriteUtilCheckCollisionAtPosition(y + BLOCK_SIZE * 2, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck != COLLISION_AIR)
            {
                gCurrentSprite.status = 0;
                break;
            }

            if (MOD_AND(gCurrentSprite.work1, 32) == 0)
            {
                ScreenShakeStartVertical(40, 0x81);
                SoundPlay_3b1c(SOUND_22E);

                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                {
                    if (MOD_AND(var_3, 2) != 0)
                        SpriteDebrisInit(0, DEBRIS_TYPE_LIGHT_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(1.6875f) + var_3,
                            x + BLOCK_TO_SUB_PIXEL(0.3125f) + var_3 * BLOCK_TO_SUB_PIXEL(0.5f));
                    else
                        SpriteDebrisInit(0, DEBRIS_TYPE_LIGHT_SLOW_RIGHT, y - BLOCK_TO_SUB_PIXEL(1.5625f) + var_3,
                            x + BLOCK_TO_SUB_PIXEL(0.40625f) + var_3 * BLOCK_TO_SUB_PIXEL(0.25f));

                    if (gSpriteRandomNumber >= 8)
                    {
                        SpriteDebrisInit(0, DEBRIS_TYPE_HEAVY_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(1.25f) + var_3,
                            x - BLOCK_TO_SUB_PIXEL(0.28125f) - var_3 * BLOCK_TO_SUB_PIXEL(0.03125f));
                    }
                    else
                    {
                        SpriteDebrisInit(0, DEBRIS_TYPE_HEAVY_SLOW_RIGHT, y - BLOCK_TO_SUB_PIXEL(1.40625f) + var_3,
                            x - BLOCK_TO_SUB_PIXEL(0.28125f) - var_3 * BLOCK_TO_SUB_PIXEL(0.0625f));
                        SpriteDebrisInit(0, DEBRIS_TYPE_LIGHT_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(1.875f) + var_2,
                            x - var_1 * BLOCK_TO_SUB_PIXEL(0.125f));
                    }

                    if (MOD_AND(gCurrentSprite.work1, 16) == 0)
                    {
                        if (MOD_AND(var_3, 2) != 0)
                            SpriteDebrisInit(0, DEBRIS_TYPE_HEAVY_SLOW_RIGHT, y - BLOCK_TO_SUB_PIXEL(1.875f) + var_2,
                                x - var_1 * BLOCK_TO_SUB_PIXEL(1.0f));
                        else
                            SpriteDebrisInit(0, DEBRIS_TYPE_HEAVY_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(1.25f) + var_2,
                                x - var_1 * BLOCK_TO_SUB_PIXEL(0.25f));

                        if (gSpriteRandomNumber >= 12)
                        {
                            SpriteDebrisInit(0, DEBRIS_TYPE_LIGHT_SLOW_LEFT, y - BLOCK_TO_SUB_PIXEL(1.375f) + var_2,
                                x + var_1 * BLOCK_TO_SUB_PIXEL(0.0625f));
                            SpriteDebrisInit(0, DEBRIS_TYPE_HEAVY_SLOW_RIGHT, y - BLOCK_TO_SUB_PIXEL(1.5625f) + var_3,
                                x - var_3 * BLOCK_TO_SUB_PIXEL(0.125f));
                        }
                        else
                        {
                            SpriteDebrisInit(0, DEBRIS_TYPE_LIGHT_SLOW_RIGHT, y - BLOCK_TO_SUB_PIXEL(1.71875f) + var_2,
                                x + var_1 * BLOCK_TO_SUB_PIXEL(0.03125f));
                        }
                    }
                }
            }
            break;
    }
}
