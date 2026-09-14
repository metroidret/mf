#include "bg_clip.h"

#include "globals.h"
#include "macros.h"
#include "connection.h"
#include "minimap.h"
#include "sound_event.h"

#include "data/block_data.h"
#include "data/clipdata_data.h"
#include "data/samus_data.h"

#include "constants/audio.h"
#include "constants/block.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/event.h"
#include "structs/samus.h"

/**
 * @brief 6bfc4 | 44 | Checks if touching a transition, tank, or crumble block
 * 
*/
void BgClipCheckTouchingSpecialClipdata(void)
{
    BgClipCheckGrabbingCrumbleBlock(FALSE);

    if (gSamusData.pose == SPOSE_USING_ELEVATOR)
    {
        BgClipCheckTouchingTransitionOnElevator();
    }
    else if (!gDisableDoorsAndTanks)
    {
        if (MOD_AND(gFrameCounter8Bit, 2))
            BgClipCheckTouchingTransitionOrTank();

        BgClipCheckWalkingOnCrumbleBlock();
    }
}

/**
 * @brief 6c008 | 60 | Checks if Samus is walking on a crumble block
 * 
*/
void BgClipCheckWalkingOnCrumbleBlock(void)
{
    s32 samusRight;
    s32 leftPos;
    s32 samusLeft;
    s32 samusBottom;
    s32 x;

    samusRight = SUB_PIXEL_TO_BLOCK_(gSamusData.xPosition + gSamusData.drawDistanceRight);
    if (samusRight > gBackgroundsData.clipdataWidth)
        samusRight = gBackgroundsData.clipdataWidth;

    leftPos = gSamusData.xPosition + gSamusData.drawDistanceLeft;
    if (leftPos < 0)
        leftPos = 0;
    samusLeft = SUB_PIXEL_TO_BLOCK_(leftPos);

    samusBottom = SUB_PIXEL_TO_BLOCK_(gSamusData.drawDistanceBottom +
        gSamusData.yPosition + PIXEL_TO_SUB_PIXEL(.5f));
    if (samusBottom > gBackgroundsData.clipdataHeight)
        samusBottom = gBackgroundsData.clipdataHeight;

    for (x = samusLeft; x <= samusRight; x++)
        BgClipCheckOnCrumbleBlock(samusBottom, x);
}

/**
 * @brief 6c068 | d0 | Checks if Samus is touching a transition while using an elevator
 * 
*/
void BgClipCheckTouchingTransitionOnElevator(void)
{
    s32 goingDown;
    s32 position;
    u16 xPosition;
    u16 behavior;
    u16 yPosition;

    if (gSamusData.elevatorOrClimbingDirection ^ KEY_UP)
        goingDown = TRUE;
    else
        goingDown = FALSE;

    position = gSamusData.xPosition;
    CLAMP2(position, 0, BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataWidth));

    xPosition = SUB_PIXEL_TO_BLOCK_(position);

    if (!goingDown)
        position = gSamusData.drawDistanceBottom + gSamusData.yPosition + BLOCK_TO_SUB_PIXEL(2);
    else
        position = gSamusData.drawDistanceTop + gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(2);

    behavior = position;

    if (position < 0)
        behavior = 0;
    else if (behavior > BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataHeight))
        behavior = BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataHeight);

    yPosition = SUB_PIXEL_TO_BLOCK_(behavior);

    position = GET_CLIP_BLOCK(xPosition, yPosition);
    if (position & CLIPDATA_TILEMAP_FLAG)
        behavior = sClipdataTilemapBehaviorTypes[position & CLIPDATA_TILEMAP_MASK];
    else
        behavior = gTilemapAndClipPointers.pClipBehaviors[position];

    position = FALSE;
    if (!goingDown)
    {
        if (behavior == CLIP_BEHAVIOR_VERTICAL_UP_TRANSITION)
            position = TRUE;
    }
    else
    {
        if (behavior == CLIP_BEHAVIOR_VERTICAL_DOWN_TRANSITION)
            position = TRUE;
    }
    
    if (position)
    {
        if (!ConnectionCheckAreaConnection(yPosition, xPosition))
            ConnectionCheckEnterDoor(yPosition, xPosition);
    }
}

/**
 * @brief 6c138 | 360 | Checks if Samus is touching a transition or a tank
 * 
*/
void BgClipCheckTouchingTransitionOrTank(void)
{
    s32 behaviors[4];  // (right, center), (left, center), (center, bottom), (center, top)
    s32 yPositions[3]; // center, bottom, top
    s32 xPositions[3]; // right, left, center
    s32 i;
    s32 j;

    // Get X positions
    // On the right
    j = DIV_SHIFT(gSamusData.drawDistanceRight, 2) + gSamusData.xPosition;
    CLAMP2(j, 0, BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataWidth));
    xPositions[0] = SUB_PIXEL_TO_BLOCK_(j);

    // On the left
    j = DIV_SHIFT(gSamusData.drawDistanceLeft, 2) + gSamusData.xPosition;
    CLAMP2(j, 0, BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataWidth));
    xPositions[1] = SUB_PIXEL_TO_BLOCK_(j);

    // Center
    j = gSamusData.xPosition;
    CLAMP2(j, 0, BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataWidth));
    xPositions[2] = SUB_PIXEL_TO_BLOCK_(j);

    // Get Y positions
    // Center
    j = DIV_SHIFT(gSamusData.drawDistanceTop, 2) + gSamusData.yPosition;
    CLAMP2(j, 0, BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataHeight));
    yPositions[0] = SUB_PIXEL_TO_BLOCK_(j);

    // Bottom
    j = DIV_SHIFT(gSamusData.drawDistanceTop, 4) + gSamusData.yPosition;
    CLAMP2(j, 0, BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataHeight));
    yPositions[1] = SUB_PIXEL_TO_BLOCK_(j);

    // Top
    j = DIV_SHIFT(gSamusData.drawDistanceTop, 4) + DIV_SHIFT(gSamusData.drawDistanceTop, 2) + gSamusData.yPosition;
    CLAMP2(j, 0, BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataHeight));
    yPositions[2] = SUB_PIXEL_TO_BLOCK_(j);

    // Get clipdata behaviors on the X axis
    for (i = 0; i < ARRAY_SIZE(xPositions) - 1; i++)
    {
        j = GET_CLIP_BLOCK_(xPositions[i], yPositions[0]);
        if (j & CLIPDATA_TILEMAP_FLAG)
            behaviors[i] = sClipdataTilemapBehaviorTypes[j & CLIPDATA_TILEMAP_MASK];
        else
            behaviors[i] = gTilemapAndClipPointers.pClipBehaviors[j];
    }

    // Get clipdata behaviors on the y axis
    for (i = 0; i < ARRAY_SIZE(yPositions) - 1; i++)
    {
        j = GET_CLIP_BLOCK_(xPositions[2], yPositions[i + 1]);
        if (j & CLIPDATA_TILEMAP_FLAG)
            behaviors[i + 2] = sClipdataTilemapBehaviorTypes[j & CLIPDATA_TILEMAP_MASK];
        else
            behaviors[i + 2] = gTilemapAndClipPointers.pClipBehaviors[j];
    }

    // Check for transition clipdata
    j = -1;
    // If touching a horizontal door from the right
    if (behaviors[0] == CLIP_BEHAVIOR_DOOR_TRANSITION)
        j = 0;
    // If touching a horizontal door from the left
    else if (behaviors[1] == CLIP_BEHAVIOR_DOOR_TRANSITION)
        j = 1;
    // If touching a vertical door from the bottom
    else if (behaviors[2] == CLIP_BEHAVIOR_VERTICAL_UP_TRANSITION)
        j = 2;
    // If touching a vertical door from the top
    else if (behaviors[3] == CLIP_BEHAVIOR_VERTICAL_DOWN_TRANSITION)
        j = 3;

    // If room transition
    if (j + 1 != 0)
    {
        // Check for door
        if (!ConnectionCheckEnterDoor(yPositions[sBlockTouchOffsets[j][0]], xPositions[sBlockTouchOffsets[j][1]]))
        {
            ConnectionCheckAreaConnection(yPositions[sBlockTouchOffsets[j][0]], xPositions[sBlockTouchOffsets[j][1]]);
        }
        return;
    }

    // Abort if already collecting a tank
    if (gDisableDoorsAndTanks || gCollectingTank)
        return;

    for (j = ARRAY_SIZE(behaviors) - 1; j >= 0; j--)
    {
        // No behavior, continue
        if (behaviors[j] == 0)
            continue;

        // Not a tank behavior, continue
        if (BEHAVIOR_TO_TANK(behaviors[j]) > (u32)BEHAVIOR_TO_TANK(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK))
            continue;

        // Get tank type
        i = sTankBehaviors[BEHAVIOR_TO_TANK(behaviors[j])].tankType;

        // Check is a tank (hidden tanks not broken aren't tanks yet)
        if (i != TANK_TYPE_NONE)
        {
            // Check the tile is explored
            if (MinimapCheckIsTileExplored(xPositions[sBlockTouchOffsets[j][1]], yPositions[sBlockTouchOffsets[j][0]]))
            {
                gCollectingTank = TRUE;

                // Set last tank collected data
                gLastTankCollected.behavior = behaviors[j];
                gLastTankCollected.xPosition = xPositions[sBlockTouchOffsets[j][1]];
                gLastTankCollected.yPosition = yPositions[sBlockTouchOffsets[j][0]];

                // Apply tank
                if (i == TANK_TYPE_MISSILE)
                {
                    if (gEquipment.maxMissiles + MISSILE_INCREASE_AMOUNT <= MAX_MISSILE_AMOUNT)
                    {
                        gEquipment.maxMissiles += MISSILE_INCREASE_AMOUNT;
                        gEquipment.currentMissiles += MISSILE_INCREASE_AMOUNT;
                    }
                }
                else if (i == TANK_TYPE_ENERGY)
                {
                    if (gEquipment.maxEnergy + ENERGY_INCREASE_AMOUNT <= MAX_ENERGY_AMOUNT)
                    {
                        gEquipment.maxEnergy += ENERGY_INCREASE_AMOUNT;
                        gEquipment.currentEnergy = gEquipment.maxEnergy;
                    }
                }
                else if (i == TANK_TYPE_POWER_BOMB)
                {
                    if (gEquipment.maxPowerBombs + POWER_BOMB_INCREASE_AMOUNT <= MAX_POWER_BOMB_AMOUNT)
                    {
                        gEquipment.maxPowerBombs += POWER_BOMB_INCREASE_AMOUNT;
                        gEquipment.currentPowerBombs += POWER_BOMB_INCREASE_AMOUNT;
                    }
                }

                // Spawn the message banner
                i = sTankBehaviors[BEHAVIOR_TO_TANK(behaviors[j])].messageId;
                if (i != 0) // TODO: Message enum
                {
                    SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, i, SPRITE_GFX_SLOT_SPECIAL,
                        SSP_UNINFECTED_OR_BOSS, gSamusData.yPosition, gSamusData.xPosition, 0);
                }
            }
        }

        // Collecting a tank, abort
        if (gCollectingTank)
            break;
    }
}

/**
 * @brief 6c498 | 60 | Clears the BG1 and clipdata for a tank, updates the collected tank list, and updates the minimap
 * 
*/
void BgClipFinishCollectingTank(void)
{
    s32 tank;
    s32 clip;

    gCollectingTank = FALSE;

    tank = BEHAVIOR_TO_TANK(gLastTankCollected.behavior);
    if (sTankBehaviors[tank].tankType == TANK_TYPE_NONE)
        return;

    if (sTankBehaviors[tank].underwater)
        clip = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_WATER;
    else
        clip = CLIPDATA_AIR;

    BgClipSetBg1BlockValue(0, gLastTankCollected.yPosition, gLastTankCollected.xPosition);
    BgClipSetClipdataBlockValue(clip, gLastTankCollected.yPosition, gLastTankCollected.xPosition);
    
    BgClipSetTankAsCollected(gLastTankCollected.xPosition, gLastTankCollected.yPosition, sTankBehaviors[tank].tankType);
    MinimapUpdateForCollectedItem(gLastTankCollected.xPosition, gLastTankCollected.yPosition);
}

/**
 * @brief 6c4f8 | 78 | Checks if Samus is on a crumble block
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
*/
void BgClipCheckOnCrumbleBlock(u16 yPosition, u16 xPosition)
{
    u16 clip;
    u16 behavior;
    boolu8 speedBoosting;

    clip = GET_CLIP_BLOCK(xPosition, yPosition);

    if (clip & CLIPDATA_TILEMAP_FLAG)
        behavior = sClipdataTilemapBehaviorTypes[clip & CLIPDATA_TILEMAP_MASK];
    else
        behavior = gTilemapAndClipPointers.pClipBehaviors[clip];

    if (behavior == CLIP_BEHAVIOR_CRUMBLE_BLOCK && gSamusData.yVelocity >= 0)
    {
        speedBoosting = FALSE;
        if (gSamusData.pose == SPOSE_RUNNING)
            speedBoosting = gSamusData.speedboostingCounter != 0;

        BlockStoreBrokenReformBlock(BLOCK_TYPE_CRUMBLE, xPosition, yPosition, speedBoosting);
    }
}

/**
 * @brief 6c570 | a4 | Clears the clipdata and BG1 value of a block
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
*/
void BgClipClearClipAndBg1BlockValue(u16 yPosition, u16 xPosition)
{
    u16 offset;
    u16* dst;

    offset = yPosition * gBackgroundsData.clipdataWidth + xPosition;
    gBackgroundsData.pClipDecomp[offset] = CLIPDATA_AIR;
    gBackgroundsData.backgrounds[1].pDecomp[offset] = 0;

    // Check is on screen, no need to update the tilemap if off screen,
    // that can be delegated to the room tilemap update functions
    offset = SUB_PIXEL_TO_BLOCK(gBg1YPosition);
    if (offset - 4 > yPosition)
        return;

    if (yPosition > offset + SCREEN_SIZE_Y_BLOCKS + 3)
        return;

    offset = SUB_PIXEL_TO_BLOCK(gBg1XPosition);
    if (offset - 4 > xPosition)
        return;

    if (xPosition > offset + SCREEN_SIZE_X_BLOCKS + 3)
        return;

    // Update tilemap
    dst = (u16*)(VRAM_BASE + 0x1000);
    if (xPosition & 0x10)
        dst = (u16*)(VRAM_BASE + 0x1800);

    offset = MOD_AND(xPosition, 16) * 2;
    dst += MOD_AND(yPosition, 16) * 64 + offset;
        
    dst[0] = gTilemapAndClipPointers.pTilemap[0];
    dst[1] = gTilemapAndClipPointers.pTilemap[1];
    dst[32] = gTilemapAndClipPointers.pTilemap[2];
    dst[33] = gTilemapAndClipPointers.pTilemap[3];
}

/**
 * @brief 6c614 | d0 | Sets the BG1 value of a block
 * 
 * @param value Block value
 * @param yPosition Y Position
 * @param xPosition X Position
*/
void BgClipSetBg1BlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    u16 offset;
    u16* dst;

    offset = yPosition * gBackgroundsData.backgrounds[1].width + xPosition;
    gBackgroundsData.backgrounds[1].pDecomp[offset] = value;

    // Check is on screen, no need to update the tilemap if off screen,
    // that can be delegated to the room tilemap update functions
    offset = SUB_PIXEL_TO_BLOCK(gBg1YPosition);
    if (offset - 4 > yPosition)
        return;

    if (yPosition > offset + SCREEN_SIZE_Y_BLOCKS + 3)
        return;

    offset = SUB_PIXEL_TO_BLOCK(gBg1XPosition);
    if (offset - 4 > xPosition)
        return;

    if (xPosition > offset + SCREEN_SIZE_X_BLOCKS + 3)
        return;

    // Update tilemap
    dst = (u16*)(VRAM_BASE + 0x1000);
    if (xPosition & 0x10)
        dst = (u16*)(VRAM_BASE + 0x1800);

    offset = MOD_AND(xPosition, 16) * 2;
    dst += MOD_AND(yPosition, 16) * 64 + offset;
    
    offset = value * 4;
        
    dst[0] = gTilemapAndClipPointers.pTilemap[offset++];
    dst[1] = gTilemapAndClipPointers.pTilemap[offset++];
    dst[32] = gTilemapAndClipPointers.pTilemap[offset++];
    dst[33] = gTilemapAndClipPointers.pTilemap[offset];
}

/**
 * @brief 6c6e4 | d0 | Sets the BG1 value of a block using the common tilemap
 * 
 * @param value Block value
 * @param yPosition Y Position
 * @param xPosition X Position
*/
void BgClipSetBg1BlockValueCommon(u16 value, u16 yPosition, u16 xPosition)
{
    u16 offset;
    u16* dst;

    offset = yPosition * gBackgroundsData.backgrounds[1].width + xPosition;
    gBackgroundsData.backgrounds[1].pDecomp[offset] = value;

    // Check is on screen, no need to update the tilemap if off screen,
    // that can be delegated to the room tilemap update functions
    offset = SUB_PIXEL_TO_BLOCK(gBg1YPosition);
    if (offset - 4 > yPosition)
        return;

    if (yPosition > offset + SCREEN_SIZE_Y_BLOCKS + 3)
        return;

    offset = SUB_PIXEL_TO_BLOCK(gBg1XPosition);
    if (offset - 4 > xPosition)
        return;

    if (xPosition > offset + SCREEN_SIZE_X_BLOCKS + 3)
        return;

    // Update tilemap
    dst = (u16*)(VRAM_BASE + 0x1000);
    if (xPosition & 0x10)
        dst = (u16*)(VRAM_BASE + 0x1800);

    offset = MOD_AND(xPosition, 16) * 2;
    dst += MOD_AND(yPosition, 16) * 64 + offset;
    
    offset = value * 4;
        
    dst[0] = sCommonTilemap[offset++];
    dst[1] = sCommonTilemap[offset++];
    dst[32] = sCommonTilemap[offset++];
    dst[33] = sCommonTilemap[offset];
}

/**
 * @brief 6c7b4 | 78 | Sets the BG1 tilemap value of a block
 * 
 * @param value Block value
 * @param yPosition Y Position
 * @param xPosition X Position
*/
void BgClipSetBg1TilemapValue(u16 value, u16 yPosition, u16 xPosition)
{
    u16* dst;
    u16 offset;

    // Update tilemap
    dst = (u16*)(VRAM_BASE + 0x1000);
    if (xPosition & 0x10)
        dst = (u16*)(VRAM_BASE + 0x1800);

    offset = MOD_AND(xPosition, 16) * 2;
    dst += MOD_AND(yPosition, 16) * 64 + offset;
    
    offset = value * 4;

    dst[0] = sCommonTilemap[offset++];
    dst[1] = sCommonTilemap[offset++];
    dst[32] = sCommonTilemap[offset++];
    dst[33] = sCommonTilemap[offset];
}

/**
 * @brief 6c82c | 28 | Sets the clipdata value of a block
 * 
 * @param value Block value
 * @param yPosition Y Position
 * @param xPosition X Position
*/
void BgClipSetClipdataBlockValue(u16 value, u16 yPosition, u16 xPosition)
{
    u16 offset;

    offset = yPosition * gBackgroundsData.clipdataWidth + xPosition;
    gBackgroundsData.pClipDecomp[offset] = value;
}

/**
 * @brief 6c854 | dc | Updates hatches that are opening or closing
 * 
*/
void BgClipUpdateHatches(void)
{
    s32 i;
    u8 exists;
    u8 state;

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        do {
        exists = gHatchData[i].exists;
        } while (0);
        if (!exists)
            continue;

        state = gHatchData[i].state;
        if (state != HATCH_STATE_OPENING && state != HATCH_STATE_CLOSING)
            continue;
        
        if (gHatchData[i].currentAnimation == 0)
        {
            if (gHatchData[i].state == HATCH_STATE_OPENING)
                SoundPlay(SOUND_FA);
            else
                SoundPlay(SOUND_FB);

            do {
            gHatchData[i].unk_1_3 = 0;
            } while (0);
            gHatchData[i].currentAnimation++;
        }
        else
        {
            if (gHatchData[i].unk_1_3 < 2)
            {
                gHatchData[i].unk_1_3++;
            }
            else
            {
                gHatchData[i].unk_1_3 = 0;
                BgClipUpdateHatchAnimation(i);

                gHatchData[i].currentAnimation++;

                if (gHatchData[i].currentAnimation == 5)
                {
                    if (gHatchData[i].state == HATCH_STATE_OPENING)
                        gHatchData[i].state = HATCH_STATE_OPENED;
                    else if (gHatchData[i].state == HATCH_STATE_CLOSING)
                        gHatchData[i].state = HATCH_STATE_CLOSED;

                    gHatchData[i].currentAnimation = 0;
                }
            }
        }
    }
}

/**
 * @brief 6c930 | 14c | Updates an opening or closing hatch's animation and clipdata
 * 
 * @param slot Hatch data index
*/
void BgClipUpdateHatchAnimation(s32 slot)
{
    s32 block;
    s32 xPosition;
    s32 animation;

    block = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_DOOR_RIGHT_TOP_SLIGHTLY_OPEN;
    xPosition = gHatchData[slot].xPosition;
    
    if (gHatchData[slot].facingRight)
        block = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_DOOR_LEFT_TOP_SLIGHTLY_OPEN;

    animation = gHatchData[slot].currentAnimation - 1;

    if (gHatchData[slot].state == HATCH_STATE_CLOSING)
    {
        animation = 2 - animation;
        if (animation < 0)
        {
            animation = 0;

            if (gHatchData[slot].locked || gHatchData[slot].lockType == HATCH_LOCK_CAN_LOCK)
            {
                block = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_26;
                block += gHatchData[slot].facingRight;
            }
            else
            {
                if (gHatchData[slot].lockType == HATCH_LOCK_GRAY)
                    block = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_WHITE_DOOR_RIGHT_TOP_SLOT_0;
                else if (gHatchData[slot].lockType == HATCH_LOCK_LEVEL_1)
                    block = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_BLUE_DOOR_RIGHT_TOP_SLOT_0;
                else if (gHatchData[slot].lockType == HATCH_LOCK_LEVEL_2)
                    block = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_GREEN_DOOR_RIGHT_TOP_SLOT_0;
                else if (gHatchData[slot].lockType == HATCH_LOCK_LEVEL_3)
                    block = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_YELLOW_DOOR_RIGHT_TOP_SLOT_0;
                else // HATCH_LOCK_LEVEL_4
                    block = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_RED_DOOR_RIGHT_TOP_SLOT_0;   

                if (gHatchData[slot].facingRight)
                    block += MAX_AMOUNT_OF_HATCHES;

                block += slot;
            }
        }
    }

    if (gHatchData[slot].lockType == HATCH_LOCK_CAN_LOCK)
    {
        animation += CLIPDATA_TILEMAP_LOCKED_DOOR_RIGHT_TOP_SLIGHTLY_OPEN -
            CLIPDATA_TILEMAP_DOOR_RIGHT_TOP_SLIGHTLY_OPEN;
    }

    block += animation;

    BgClipSetBg1BlockValueCommon(block + 16 * 0, gHatchData[slot].yPosition, xPosition);
    BgClipSetBg1BlockValueCommon(block + 16 * 1, gHatchData[slot].yPosition + 1, xPosition);
    BgClipSetBg1BlockValueCommon(block + 16 * 2, gHatchData[slot].yPosition + 2, xPosition);
    BgClipSetBg1BlockValueCommon(block + 16 * 3, gHatchData[slot].yPosition + 3, xPosition);

    BgClipSetClipdataBlockValue(block + 16 * 0, gHatchData[slot].yPosition, xPosition);
    BgClipSetClipdataBlockValue(block + 16 * 1, gHatchData[slot].yPosition + 1, xPosition);
    BgClipSetClipdataBlockValue(block + 16 * 2, gHatchData[slot].yPosition + 2, xPosition);
    BgClipSetClipdataBlockValue(block + 16 * 3, gHatchData[slot].yPosition + 3, xPosition);
}

/**
 * @brief 6ca7c | c8 | Checks if Samus is grabbing a crumble block
 * 
 * @param dontDestroy Don't destroy block flag
*/
void BgClipCheckGrabbingCrumbleBlock(boolu8 dontDestroy)
{
    s32 setPose;
    s32 xOffset;
    u16 xPosition;
    u16 yPosition;
    u16 clip;

    setPose = FALSE;

    if (gSamusData.pose != SPOSE_HANGING_ON_LEDGE)
        return;

    if (gSamusData.direction & KEY_RIGHT)
        xOffset = BLOCK_TO_SUB_PIXEL(.5f);
    else
        xOffset = -BLOCK_TO_SUB_PIXEL(.5f);

    xPosition = gSamusData.xPosition + xOffset;
    yPosition = gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.9375);

    if (!dontDestroy)
    {
        xPosition = SUB_PIXEL_TO_BLOCK(xPosition);
        yPosition = SUB_PIXEL_TO_BLOCK(yPosition);
        clip = GET_CLIP_BLOCK(xPosition, yPosition);
        
        if (clip & CLIPDATA_TILEMAP_FLAG)
            clip = sClipdataTilemapBehaviorTypes[clip & CLIPDATA_TILEMAP_MASK];
        else
            clip = gTilemapAndClipPointers.pClipBehaviors[clip];

        if (clip == CLIP_BEHAVIOR_CRUMBLE_BLOCK)
        {
            BlockStoreBrokenReformBlock(BLOCK_TYPE_CRUMBLE, xPosition, yPosition, FALSE);
            setPose = TRUE;
        }
    }

    if (!setPose)
    {
        if (!(ClipdataProcessForSamus(gSamusData.yPosition - BLOCK_TO_SUB_PIXEL(1.9375),
            gSamusData.xPosition + xOffset) & CLIPDATA_TYPE_SOLID_FLAG))
        {
            setPose = TRUE;
        }
    }

    if (setPose)
    {
        SAMUS_SET_POSE(SPOSE_MID_AIR_REQUEST);
    }
}

/**
 * @brief 6cb44 | b0 | Checks if a projectile is hitting a hatch that can open
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @return s32 bool, a hatch is opening
*/
bools32 BgClipCheckProjectileHitHatch(u16 xPosition, u16 yPosition)
{
    bools32 opening;
    s16 xOffset;
    s32 i;

    if (gEquipment.securityHatchLevel > 4)
        return FALSE;

    opening = FALSE;
    xOffset = 0;

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (!gHatchData[i].exists || gHatchData[i].state != HATCH_STATE_CLOSED || gHatchData[i].locked)
            continue;

        if (gHatchData[i].xPosition + xOffset == xPosition &&
            gHatchData[i].yPosition <= yPosition && gHatchData[i].yPosition + 3 >= yPosition)
        {
            i |= 0x80;
        }

        if (i & 0x80)
        {
            i &= 0x7F;
            if (gHatchData[i].lockType <= gEquipment.securityHatchLevel)
            {
                gHatchData[i].state = HATCH_STATE_OPENING;
                opening = TRUE;
            }
            break;
        }
    }

    return opening;
}

/**
 * @brief 6cbf4 | 58 | Reveals a hidden tank
 * 
 * @param pClipBlock Clipdata block data pointer
 * @return s32 bool, tank was revealed
*/
bools32 BgClipRevealHiddenTank(struct ClipdataBlockData* pBlock)
{
    if (pBlock->behavior == CLIP_BEHAVIOR_HIDDEN_MISSILE_TANK)
    {
        BgClipSetBg1BlockValueCommon(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_MISSILE_TANK, pBlock->yPosition, pBlock->xPosition);
        BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_MISSILE_TANK, pBlock->yPosition, pBlock->xPosition);
        return TRUE;
    }
    else if (pBlock->behavior == CLIP_BEHAVIOR_HIDDEN_ENERGY_TANK)
    {
#ifndef BUGFIX
        // OVERSIGHT: Energy tank clipdata is set twice
        BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_ENERGY_TANK, pBlock->yPosition, pBlock->xPosition);
#endif // !BUGFIX
        BgClipSetBg1BlockValueCommon(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_ENERGY_TANK, pBlock->yPosition, pBlock->xPosition);
        BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_ENERGY_TANK, pBlock->yPosition, pBlock->xPosition);
        return TRUE;
    }
    else if (pBlock->behavior == CLIP_BEHAVIOR_HIDDEN_POWER_BOMB_TANK)
    {
        BgClipSetBg1BlockValueCommon(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_POWER_BOMB_TANK, pBlock->yPosition, pBlock->xPosition);
        BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_POWER_BOMB_TANK, pBlock->yPosition, pBlock->xPosition);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * @brief 6cc4c | ac | Updates BG1 and sound event during the SA-X elevator cutscene
 * 
 * @param doorShot Door was shot
*/
void BgClipUpdateSaXElevatorCutscene(boolu8 doorShot)
{
    s32 yPos;
    s32 xPos;
    s32 xStart;
    s32 value;

    if (gEventCounter != EVENT_ENTERED_ELEVATOR_ROOM)
        return;

    yPos = 14;
    
    if (doorShot)
        xPos = 14;
    else
        xPos = 3;
    xStart = xPos;

    // Copy destroyed blocks below screen over blocks on screen
    for (; yPos < 18; yPos++)
    {
        xPos = xStart;
        value = GET_BG_BLOCK(1, xPos, yPos);
        BgClipSetBg1BlockValue(value, yPos - 9, xPos);

        xPos++;
        value = GET_BG_BLOCK(1, xPos, yPos);
        BgClipSetBg1BlockValue(value, yPos - 9, xPos);

        xPos++;
        value = GET_BG_BLOCK(1, xPos, yPos);
        BgClipSetBg1BlockValue(value, yPos - 9, xPos);
    }

    if (!doorShot)
        value = SOUND_EVENT_SA_X_ELEVATOR_CUTSCENE_EXPLOSION;
    else
        value = SOUND_EVENT_SA_X_ELEVATOR_CUTSCENE_DOOR_SHOT;

    SoundEventUpdate(value, SEVENT_TTYPE_SA_X_ENCOUNTER);
}

/**
 * @brief 6ccf8 | 84 | Stores a collected tank in the save array
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @param tankType Tank type
*/
void BgClipSetTankAsCollected(u16 xPosition, u16 yPosition, u8 tankType)
{
    s32 i;
    s32 maxCount;
    bools32 overLimit;
    u8* pTank;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        return;

    i = gCurrentArea;
    maxCount = MAX_AMOUNT_OF_COLLECTED_TANKS_PER_AREA;
    if (i != AREA_MAIN_DECK)
        i++;
    else
        maxCount *= 2;

    overLimit = TRUE;
    pTank = gCollectedTanks[i];

    for (i = 0; i < maxCount; i++, pTank += COLLECTED_TANKS_INFO_SIZE)
    {
        if (*pTank == UCHAR_MAX)
        {
            overLimit = FALSE;
            break;
        }
    }

    if (!overLimit)
    {
        *pTank++ = gCurrentRoom;
        *pTank++ = tankType;
        *pTank++ = xPosition;
        *pTank = yPosition;
        gNumberOfCollectedTanks[gCurrentArea]++;
    }
}

/**
 * @brief 6cd7c | c4 | Counts the number of tanks within a screen (likely a debug function)
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @return s32 Tank count
*/
s32 BgClipCountTanksWithinScreen(u16 xPosition, u16 yPosition)
{
    s32 xStart;
    s32 yStart;
    s32 tanks;
    s32 yPos;
    s32 xPos;
    s32 clip;

    xStart = (xPosition - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS;
    yStart = (yPosition - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS;
    xStart = xStart * SCREEN_SIZE_X_BLOCKS + SCREEN_X_PADDING;
    yStart = yStart * SCREEN_SIZE_Y_BLOCKS + SCREEN_Y_PADDING;
    
    tanks = 0;

    for (yPos = yStart; yPos < yStart + SCREEN_SIZE_Y_BLOCKS; yPos++)
    {
        for (xPos = xStart; xPos < xStart + SCREEN_SIZE_X_BLOCKS; xPos++)
        {
            clip = GET_CLIP_BLOCK(xPos, yPos);
            
            if (!(clip & CLIPDATA_TILEMAP_FLAG))
                clip = gTilemapAndClipPointers.pClipBehaviors[clip];

            if (clip == 0)
                continue;
            
            if (clip >= CLIP_BEHAVIOR_TANK_START && clip <= CLIP_BEHAVIOR_TANK_END)
            {
                tanks++;
            }
#ifdef BUGFIX
            else if (clip >= (CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_MISSILE_TANK) &&
                clip <= (CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_POWER_BOMB_TANK))
#else // !BUGFIX
            // BUG: Missile tank isn't checked
            else if (clip >= (CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_ENERGY_TANK) &&
                clip <= (CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_POWER_BOMB_TANK))
#endif // BUGFIX
            {
                tanks++;
            }
        }
    }

    return tanks;
}

/**
 * @brief 6ce40 | cc | Removes the collected tanks in a room
 * 
*/
void BgClipRemoveCollectedTanks(void)
{
    s32 i;
    s32 maxCount;
    u8 yPosition;
    u8 xPosition;
    s32 index;
    u8* pTank;
    s32 behavior;

    if (gPauseScreenFlag != 0 || gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        return;

    i = gCurrentArea;
    maxCount = MAX_AMOUNT_OF_COLLECTED_TANKS_PER_AREA;
    // Main Deck has twice as much space
    if (i != AREA_MAIN_DECK)
        i++;
    else
        maxCount *= 2;

    pTank = gCollectedTanks[i];

    for (i = 0; i < maxCount; i++, pTank += COLLECTED_TANKS_INFO_SIZE)
    {
        if (pTank[0] == UCHAR_MAX)
            return;

        if (pTank[0] != gCurrentRoom)
            continue;

        yPosition = pTank[3];
        xPosition = pTank[2];
        index = (yPosition * gBackgroundsData.clipdataWidth) + xPosition;
        behavior = gTilemapAndClipPointers.pClipBehaviors[gBackgroundsData.pClipDecomp[index]];

        if (behavior >= CLIP_BEHAVIOR_UNDERWATER_ENERGY_TANK &&
            behavior <= CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK)
        {
            gBackgroundsData.pClipDecomp[index] = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_WATER;
            gBackgroundsData.backgrounds[1].pDecomp[index] = 0;
        }
        else
        {
            gBackgroundsData.pClipDecomp[index] = CLIPDATA_AIR;
            gBackgroundsData.backgrounds[1].pDecomp[index] = 0;
        }
    }
}
