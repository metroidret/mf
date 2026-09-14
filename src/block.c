#include "block.h"

#include "globals.h"
#include "macros.h"
#include "bg_clip.h"

#include "data/block_data.h"
#include "data/clipdata_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/samus.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/power_bomb.h"
#include "structs/samus.h"

static BlockFunc_T sNonReformDestroyFunctionPointers[BLOCK_SUB_TYPE_COUNT] = {
    [BLOCK_SUB_TYPE_REFORM] = BlockDestroySingleBreakableBlock,
    [BLOCK_SUB_TYPE_SQUARE_NO_REFORM] = BlockDestroySquareBlock,
    [BLOCK_SUB_TYPE_NO_REFORM] = BlockDestroySingleBreakableBlock,
    [BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM] = BlockDestroySquareBlock,
    [BLOCK_SUB_TYPE_BOMB_CHAIN] = BlockDestroyBombChainBlock
};

static u8 sBlob_79bb64_79bbcc[] = INCBIN_U8("data/Blob_79bb64_79bbcc.bin");


/**
 * @brief 6acbc | 224 | Checks if something should happen to a block depending on the current clipdata action
 *
 * @param pClipBlock Clipdata block data pointer
 * @return s32 bool, block was affected (destroyed or revealed)
 */
bools32 BlockCheckClipdataAction(struct ClipdataBlockData* pClipBlock)
{
    u16 block;
    bools32 blockAffected;
    bools32 destroy;
    s32 bombChainType;

    blockAffected = FALSE;

    block = BEHAVIOR_TO_BLOCK(pClipBlock->behavior);
    if (block > BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BLOCK_END))
        return FALSE;

    pClipBlock->blockBehavior = BEHAVIOR_TO_BLOCK(pClipBlock->behavior);

    if (gCurrentClipdataAffectingAction == CAA_SPEED_BOOST_GROUND)
    {
        if (!sBlockBehaviors[pClipBlock->blockBehavior].isSpeedboost)
            return FALSE;

        gCurrentClipdataAffectingAction = CAA_SPEED_BOOST;
    }
    else if (gCurrentClipdataAffectingAction == CAA_BOMB_CHAIN)
    {
        if (!sBlockBehaviors[pClipBlock->blockBehavior].isBombChain)
            return FALSE;
    }

    destroy = TRUE;
    bombChainType = BOMB_CHAIN_TYPE_VERTICAL_1;

    switch (pClipBlock->blockBehavior)
    {
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NEVER_REFORM):
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NO_REFORM):
            pClipBlock->xPosition--;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NEVER_REFORM):
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NO_REFORM):
            pClipBlock->xPosition--;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NEVER_REFORM):
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NO_REFORM):
            pClipBlock->yPosition--;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_NEVER_REFORM):
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_REFORM):
            if (!(sClipdataActionDamageTypes[gCurrentClipdataAffectingAction] &
                (CAA_DAMAGE_TYPE_BOMB | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_SPEEDBOOST | CAA_DAMAGE_TYPE_SCREW_ATTACK)))
            {
                destroy = FALSE;
            }
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NEVER_REFORM):
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_POWER_BOMB_BLOCK_NEVER_REFORM):
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NO_REFORM):
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEED_BOOST_BLOCK_NO_REFORM):
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEED_BOOST_BLOCK_REFORM):
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SCREW_ATTACK_BLOCK_NO_REFORM):
            destroy = BlockCheckRevealOrDestroyNonBombBlock(pClipBlock);
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_CRUMBLE_BLOCK):
            BlockCheckRevealOrDestroyNonBombBlock(pClipBlock);
            destroy = FALSE;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_1):
            bombChainType = BOMB_CHAIN_TYPE_VERTICAL_1;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_2):
            bombChainType = BOMB_CHAIN_TYPE_VERTICAL_2;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_3):
            bombChainType = BOMB_CHAIN_TYPE_VERTICAL_3;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN_4):
            bombChainType = BOMB_CHAIN_TYPE_VERTICAL_4;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_1):
            bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL_1;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_2):
            bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL_2;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_3):
            bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL_3;
            break;
        
        case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN_4):
            bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL_4;
            break;
    }

    if (!destroy)
        return FALSE;

    switch (sBlockBehaviors[pClipBlock->blockBehavior].lifeType)
    {
        case BLOCK_LIFE_TYPE_NO_NEVER_REFORM:
            if (BlockDestroyNonReformBlock(pClipBlock))
                blockAffected = TRUE;
            break;

        case BLOCK_LIFE_TYPE_REFORM:
            if (BlockStoreBrokenReformBlock(sBlockBehaviors[pClipBlock->blockBehavior].type,
                pClipBlock->xPosition, pClipBlock->yPosition, FALSE))
            {
                blockAffected = TRUE;
            }
            break;

        case BLOCK_LIFE_TYPE_BOMB_CHAIN:
            if ((sClipdataActionDamageTypes[gCurrentClipdataAffectingAction] & (CAA_DAMAGE_TYPE_BOMB | CAA_DAMAGE_TYPE_POWER_BOMB | CAA_DAMAGE_TYPE_BOMB_CHAIN)) &&
                !(gActiveBombChainTypes & sBombChainReverseData[bombChainType].typeFlag) &&
                BlockStartBombChain(bombChainType, pClipBlock->xPosition, pClipBlock->yPosition))
            {
                if (BlockDestroyNonReformBlock(pClipBlock))
                    blockAffected = TRUE;
            }
            break;

        case BLOCK_LIFE_TYPE_TANK:
            if (sClipdataActionDamageTypes[gCurrentClipdataAffectingAction] & TANK_WEAKNESS)
            {
                if (BgClipRevealHiddenTank(pClipBlock))
                    blockAffected = TRUE;
            }
            break;
    }

    return blockAffected;
}

/**
 * @brief 6aee0 | 6c | Handles the destruction of a non-reform block
 *
 * @param pClipBlock Clipdata block data pointer
 * @return s32 bool, block was destroyed
 */
bools32 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock)
{
    bools32 handled;
    BlockSubType subType;

    handled = FALSE;
    subType =sBlockBehaviors[pClipBlock->blockBehavior].subType;

    switch (subType)
    {
        case BLOCK_SUB_TYPE_REFORM:
        case BLOCK_SUB_TYPE_SQUARE_NO_REFORM:
        case BLOCK_SUB_TYPE_BOMB_CHAIN:
            // Nothing special to do
            break;

        case BLOCK_SUB_TYPE_NO_REFORM:
        case BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM:
            // Store a never reform bock
            handled = BlockStoreSingleNeverReformBlock(pClipBlock->xPosition, pClipBlock->yPosition);
            break;

        default:
            handled = TRUE;
    }

    if (handled)
        return FALSE;

    // Run special handler depending on the type
    sNonReformDestroyFunctionPointers[subType](pClipBlock);
    return TRUE;
}

/**
 * @brief 6af4c | 6c | Destroys a single bomb chain block
 *
 * @param pClipBlock Clipdata block data pointer
 */
void BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock)
{
    u16 yPosition;
    u16 xPosition;
    u16 block;
    s32 index;

    block = GET_BG_BLOCK(1, pClipBlock->xPosition, pClipBlock->yPosition);
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    
    index = BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition,
        sBlockBehaviors[pClipBlock->blockBehavior].type);

    gBrokenBlockBg1Values[index] = block;
    gBrokenNonReformBlocks[index].type = BLOCK_TYPE_BROKEN;
}

/**
 * @brief 6afb8 | 38 | Destroys a single block
 *
 * @param pClipBlock Clipdata block data pointer
 */
void BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock)
{
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, sBlockBehaviors[pClipBlock->blockBehavior].type);
}

/**
 * @brief 6aff0 | bc | Destroys a square (4x4) block
 *
 * @param pClipBlock Clipdata block data pointer
 */
void BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock)
{
    BlockType type;

    type = sBlockBehaviors[pClipBlock->blockBehavior].type;

    // Destroy top left
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, type);

    // Destroy bottom right
    pClipBlock->xPosition++;
    pClipBlock->yPosition++;
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, type);

    // Destroy top right
    pClipBlock->yPosition--;
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, type);

    // Destroy bottom left
    pClipBlock->xPosition--;
    pClipBlock->yPosition++;
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, type);
}

/**
 * @brief 6b0ac | 84 | Stores a single never reform block in the save array
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @return s32 bool, couldn't store
 */
bools32 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition)
{
    s32 i;
    s32 maxCount;
    bools32 overLimit;
    u8* pBlock;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        return FALSE;

    i = gCurrentArea;
    maxCount = MAX_AMOUNT_OF_NEVER_REFORM_BLOCK_PER_AREA;
    // Main Deck has twice as much space
    if (i != AREA_MAIN_DECK)
        i++;
    else
        maxCount *= 2;

    overLimit = TRUE;
    pBlock = gNeverReformBlocks[i];

    for (i = 0; i < maxCount; i++, pBlock += NEVER_REFORM_BLOCK_INFO_SIZE)
    {
        if (*pBlock == UCHAR_MAX)
        {
            overLimit = FALSE;
            break;
        }
    }

    if (!overLimit)
    {
        *pBlock++ = gCurrentRoom;
        *pBlock++ = xPosition;
        *pBlock = yPosition;
        gNumberOfNeverReformBlocks[gCurrentArea]++;
    }

    return overLimit;
}

/**
 * @brief 6b130 | dc | Removes the broken never reform blocks in a room
 *
 */
void BlockRemoveNeverReformBlocks(void)
{
    s32 i;
    s32 maxCount;
    s32 index;
    u8* pBlock;
    u16 behavior;

    if (gPauseScreenFlag != 0 || gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        return;

    i = gCurrentArea;
    maxCount = MAX_AMOUNT_OF_NEVER_REFORM_BLOCK_PER_AREA;
    // Main Deck has twice as much space
    if (i != AREA_MAIN_DECK)
        i++;
    else
        maxCount *= 2;
    
    pBlock = gNeverReformBlocks[i];

    for (i = 0; i < maxCount; i++, pBlock += 3)
    {
        if (pBlock[0] == UCHAR_MAX)
            return;

        if (pBlock[0] != gCurrentRoom)
            continue;
        
        index = (pBlock[2] * gBackgroundsData.clipdataWidth) + pBlock[1];
        behavior = gTilemapAndClipPointers.pClipBehaviors[gBackgroundsData.pClipDecomp[index]];
        gBackgroundsData.pClipDecomp[index] = CLIPDATA_AIR;
        gBackgroundsData.backgrounds[1].pDecomp[index] = 0;

        if (behavior == CLIP_BEHAVIOR_TOP_LEFT_SHOT_BLOCK_NEVER_REFORM)
        {
            gBackgroundsData.pClipDecomp[index + 1] = CLIPDATA_AIR;
            gBackgroundsData.backgrounds[1].pDecomp[index + 1] = 0;
            
            index += gBackgroundsData.clipdataWidth;
            gBackgroundsData.pClipDecomp[index] = CLIPDATA_AIR;
            gBackgroundsData.backgrounds[1].pDecomp[index] = 0;

            index++;
            gBackgroundsData.pClipDecomp[index] = CLIPDATA_AIR;
            gBackgroundsData.backgrounds[1].pDecomp[index] = 0;
        }
    }
}

/**
 * @brief 6b20c | 190 | Stores a broken non-reform block in the first available position
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @param type Block type
 * @return s32 bool, couldn't store
 */
bools32 BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, BlockType type)
{
    bools32 notStored;
    s32 i;
    s32 stage;

    notStored = TRUE;

    // Try finding an empty slot
    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++)
    {
        if (gBrokenNonReformBlocks[i].stage == 0)
        {
            gBrokenBlockBg1Values[i] = 0;
    
            gBrokenNonReformBlocks[i].xPosition = xPosition;
            gBrokenNonReformBlocks[i].yPosition = yPosition;
            gBrokenNonReformBlocks[i].stage = 2;
            gBrokenNonReformBlocks[i].timer = 0;
            gBrokenNonReformBlocks[i].type = type;
    
            BlockUpdateBrokenBlockAnimation(&gBrokenNonReformBlocks[i], i);
            notStored = FALSE;
            break;
        }
    }

    // If not found, try finding an existing block at a later stage
    for (stage = 4; notStored && stage != 0; stage >>= 1)
    {
        for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++)
        {
            if (gBrokenNonReformBlocks[i].stage >= stage && gBrokenNonReformBlocks[i].type != BLOCK_TYPE_BROKEN)
            {
                BgClipSetBg1BlockValue(0, gBrokenNonReformBlocks[i].yPosition, gBrokenNonReformBlocks[i].xPosition);
                
                gBrokenNonReformBlocks[i].xPosition = xPosition;
                gBrokenNonReformBlocks[i].yPosition = yPosition;
                gBrokenNonReformBlocks[i].stage = 2;
                gBrokenNonReformBlocks[i].timer = 0;
                gBrokenNonReformBlocks[i].type = type;
                
                BlockUpdateBrokenBlockAnimation(&gBrokenNonReformBlocks[i], i);
                notStored = FALSE;
                break;
            }
        }
    }

    // BUG: The loop conditions here seem wrong, since the stage check will always be true by the 4th loop
    for (stage = 4; notStored; )
    {
        for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; stage >>= 1, i++)
        {
            if (gBrokenNonReformBlocks[i].stage >= stage)
            {
                BgClipSetBg1BlockValue(gBrokenBlockBg1Values[i] + 1, gBrokenNonReformBlocks[i].yPosition, gBrokenNonReformBlocks[i].xPosition);

                gBrokenNonReformBlocks[i].xPosition = xPosition;
                gBrokenNonReformBlocks[i].yPosition = yPosition;
                gBrokenNonReformBlocks[i].stage = 2;
                gBrokenNonReformBlocks[i].timer = 0;
                gBrokenNonReformBlocks[i].type = type;

                BlockUpdateBrokenBlockAnimation(&gBrokenNonReformBlocks[i], i);
                return i;
            }
        }
    }

    return i;
}

/**
 * @brief 6b39c | 88 | Check if a non bomb block should be revealed or destroyed
 *
 * @param pClipBlock Clipdata block data pointer
 * @return s32 bool, should be destroyed
 */
bools32 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock)
{
    s32 blockType;

    blockType = sBlockBehaviors[pClipBlock->blockBehavior].type;

    if (sBlockWeaknesses[blockType] == CAA_NONE)
        return FALSE;

    if (gCurrentClipdataAffectingAction == sBlockWeaknesses[blockType])
        return TRUE;

    if (gCurrentClipdataAffectingAction != CAA_BOMB &&
        (gCurrentClipdataAffectingAction != CAA_POWER_BOMB || gCurrentPowerBomb.ownedBySaX))
        return FALSE;

    if (pClipBlock->tilemapValue != sReformingBlocksTilemapValue[blockType] &&
        BlockStoreRevealedBlock(blockType, pClipBlock->xPosition, pClipBlock->yPosition))
    {
        BgClipSetBg1BlockValueCommon(sReformingBlocksTilemapValue[blockType], pClipBlock->yPosition, pClipBlock->xPosition);
        BgClipSetClipdataBlockValue(sReformingBlocksTilemapValue[blockType], pClipBlock->yPosition, pClipBlock->xPosition);
    }

    return FALSE;
}

/**
 * @brief 6b424 | 164 | Applies the current clipdata action
 *
 * @param yPosition Y position
 * @param xPosition X position
 * @param trueClip True clipdata block value
 * @return s32 bool, block was affected (destroyed or revealed)
 */
bools32 BlockApplyClipdataAction(u16 yPosition, u16 xPosition, u16 trueClip)
{
    struct ClipdataBlockData block;
    bools32 blockAffected;

    block.xPosition = xPosition;
    block.yPosition = yPosition;

    if (trueClip & CLIPDATA_TILEMAP_FLAG)
    {
        block.tilemapValue = trueClip;
        block.behavior = sClipdataTilemapBehaviorTypes[trueClip & CLIPDATA_TILEMAP_MASK];

    }
    else
    {
        block.tilemapValue = 0;
        block.behavior = gTilemapAndClipPointers.pClipBehaviors[trueClip];
    }

    blockAffected = FALSE;

    switch (gCurrentClipdataAffectingAction)
    {
        case CAA_4:
            if (BlockCheckClipdataAction(&block))
                blockAffected = TRUE;
            break;

        case CAA_BEAM:
        case CAA_BOMB:
        case CAA_MISSILE:
        case CAA_POWER_BOMB:
            if (BgClipCheckProjectileHitHatch(block.xPosition, block.yPosition) || BlockCheckClipdataAction(&block))
                blockAffected = TRUE;
            break;
        
        case CAA_SPEED_BOOST:
        case CAA_SPEED_BOOST_GROUND:
            if (BlockCheckClipdataAction(&block))
            {
                SoundPlayNotAlreadyPlaying(SOUND_129);
                blockAffected = TRUE;
            }
            break;
        
        case CAA_SCREW_ATTACK:
            if (BlockCheckClipdataAction(&block))
            {
                SoundPlayNotAlreadyPlaying(SOUND_12A);
                blockAffected = TRUE;
            }
            break;
        
        case CAA_BOMB_CHAIN:
            if (BlockCheckClipdataAction(&block))
            {
                SoundPlayNotAlreadyPlaying(SOUND_128);
                blockAffected = TRUE;
            }
            break;
        
        case CAA_REMOVE_SOLID:
            if (!BlockUpdateMakeSolidBlock(FALSE, xPosition, yPosition))
                BgClipSetBg1BlockValue(0, yPosition, xPosition);
            BgClipSetClipdataBlockValue(CLIPDATA_AIR, yPosition, xPosition);
            break;
        
        case CAA_MAKE_SOLID:
            blockAffected = BlockUpdateMakeSolidBlock(TRUE, xPosition, yPosition);
            if (blockAffected)
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_SOLID_SPRITE | CLIPDATA_TILEMAP_FLAG, yPosition, xPosition);
            break;
        
        case CAA_MAKE_SOLID_STOP_ENEMY:
            blockAffected = BlockUpdateMakeSolidBlock(TRUE, xPosition, yPosition);
            if (blockAffected)
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_STOP_ENEMY | CLIPDATA_TILEMAP_FLAG, yPosition, xPosition);
            break;
    }

    return blockAffected;
}

/**
 * @brief 6b588 | bc | Adds or removes a make solid block
 *
 * @param makeSolid Make solid flag
 * @param xPosition X position
 * @param yPosition Y position
 * @return s32 bool, a block was added or removed
 */
bools32 BlockUpdateMakeSolidBlock(boolu8 makeSolid, u16 xPosition, u16 yPosition)
{
    bools32 found;
    u16* pBlocks;
    s32 i;

    found = FALSE;

    if (!makeSolid)
    {
        // Remove solid
        pBlocks = gMakeSolidBlocks;
#ifdef BUGFIX
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0;)
#else // !BUGFIX
        // BUG: i is decremented twice each loop
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0; i--)
#endif // BUGFIX
        {
            if (pBlocks[--i] == C_16_2_8(xPosition, yPosition))
            {
                // Found in the array, remove
                pBlocks[i] = 0;
                found = TRUE;
                break;
            }
        }
    }
    else
    {
        // Make solid
        pBlocks = gMakeSolidBlocks;
#ifdef BUGFIX
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0;)
#else // !BUGFIX
        // BUG: i is decremented twice each loop
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0; i--)
#endif // BUGFIX
        {
            if (pBlocks[--i] == C_16_2_8(xPosition, yPosition))
            {
                // Already in the array
                i = UCHAR_MAX;
                break;
            }
            else if (pBlocks[i] == 0)
            {
                // Found empty space
                break;
            }
        }

        found = FALSE;
        if (i != UCHAR_MAX)
        {
            if (GET_CLIP_BLOCK_(xPosition, yPosition) == CLIPDATA_AIR)
            {
                // Store if no block
                pBlocks[i] = C_16_2_8(xPosition, yPosition);
                found = TRUE;
            }
        }
    }

    return found;
}

/**
 * @brief 6b644 | b8 | Applies the speed booster or screw attack destructing action
 *
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param action Destructing action
 * @return s32 bool, block destroyed
 */
bools32 BlockApplySpeedBoosterScrewAttackDamage(u16 xPosition, u16 yPosition, u16 action)
{
    u16 blockY;
    u16 blockX;
    u16 clipdata;
    u16 destroyed;
    u16 position;

    blockX = SUB_PIXEL_TO_BLOCK(xPosition);
    blockY = SUB_PIXEL_TO_BLOCK(yPosition);

    if (blockX < gBackgroundsData.clipdataWidth && blockY < gBackgroundsData.clipdataHeight)
    {
        // Set Ccaa
        if (action == SDA_SPEED_BOOSTER)
            gCurrentClipdataAffectingAction = CAA_SPEED_BOOST;
        else if (action == SDA_SCREW_ATTACK)
            gCurrentClipdataAffectingAction = CAA_SCREW_ATTACK;
        else if (action == SDA_SCREW_ATTACK_SPEED_BOOSTER)
            gCurrentClipdataAffectingAction = CAA_SCREW_ATTACK;
        else if (action == SDA_SPEED_BOOSTER_ON_GROUND)
            gCurrentClipdataAffectingAction = CAA_SPEED_BOOST_GROUND;
        else
            return FALSE;

        // Get clipdata block
        position = gBackgroundsData.clipdataWidth * blockY + blockX;
        clipdata = gBackgroundsData.pClipDecomp[position];

        if (clipdata != CLIPDATA_AIR)
        {
            // Apply first
            destroyed = BlockApplyClipdataAction(blockY, blockX, clipdata);

            if (!destroyed && action == SDA_SCREW_ATTACK_SPEED_BOOSTER)
            {
                // Apply second
                gCurrentClipdataAffectingAction = CAA_SPEED_BOOST;
                BlockApplyClipdataAction(blockY, blockX, clipdata);
            }
        }
#ifdef BUGFIX
        else
        {
            destroyed = FALSE;
        }
#endif // BUGFIX
    }
    else
    {
        return FALSE;
    }

    // Clear Ccaa
    gCurrentClipdataAffectingAction = CAA_NONE;

    // BUG: destroyed is never set if Samus isn't colliding with any non air tile
    return destroyed;
}

/**
 * @brief 6b6fc | 118 | Updates the broken reform blocks
 *
 */
void BlockUpdateBrokenBlocks(void)
{
    struct BrokenBlock* pBlock;
    s32 i;
    bools32 updateStage;

    for (pBlock = gBrokenReformBlocks, i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
    {
        if (pBlock->stage == 0 || pBlock->stage == BROKEN_BLOCK_STAGE_INTACT)
            continue;

        pBlock->timer++;

        if (pBlock->timer < sBrokenBlockTimers[pBlock->type][pBlock->stage])
            continue;

        updateStage = FALSE;
        pBlock->timer = 0;

        if (pBlock->stage >= ARRAY_SIZE(sBrokenBlockTimers[0]))
        {
            if (BlockCheckSamusInReformingBlock(pBlock->yPosition, pBlock->xPosition))
            {
                pBlock->stage = 2;
            }
            else
            {
                pBlock->stage = BROKEN_BLOCK_STAGE_INTACT;
                BgClipSetClipdataBlockValue(sReformingBlocksTilemapValue[pBlock->type], pBlock->yPosition, pBlock->xPosition);
            }
        }
        else if (pBlock->stage == 7)
        {
            if (BlockCheckSamusInReformingBlock(pBlock->yPosition, pBlock->xPosition))
                pBlock->timer = sBrokenBlockTimers[pBlock->type][pBlock->stage] / 2;
            else
                updateStage = TRUE;
        }
        else
        {
            if (pBlock->stage == 1)
                BgClipClearClipAndBg1BlockValue(pBlock->yPosition, pBlock->xPosition);

            updateStage = TRUE;
        }
            
        if (updateStage)
        {
            pBlock->stage++;
            BlockUpdateBrokenBlockAnimation(&gBrokenReformBlocks[i], i);
        }
    }
}

/**
 * @brief 6b814 | 7c | Updates the animation of the broken non-reform blocks
 *
 */
void BlockUpdateNonReformBlocksAnimation(void)
{
    struct BrokenBlock* pBlock;
    s32 i;

    for (pBlock = gBrokenNonReformBlocks, i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
    {
        if (pBlock->stage == 0 || pBlock->stage == BROKEN_BLOCK_STAGE_INTACT)
            continue;

        pBlock->timer++;
        if (pBlock->timer > 3)
        {
            pBlock->timer = 0;
            pBlock->stage++;
            BlockUpdateBrokenBlockAnimation(pBlock, i);

            if (pBlock->stage > 6)
            {
                pBlock->stage = 0;
                pBlock->xPosition = 0;
                pBlock->yPosition = 0;
            }
        }
    }
}

/**
 * @brief 6b890 | 30 | Redraws all broken reform blocks
 *
 */
void BlockRedrawBrokenBlocks(void)
{
    s32 i;

    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++)
    {
        if (gBrokenReformBlocks[i].stage != 0 && gBrokenReformBlocks[i].stage != BROKEN_BLOCK_STAGE_INTACT)
            BlockUpdateBrokenBlockAnimation(&gBrokenReformBlocks[i], i);
    }
}

/**
 * @brief 6b8c0 | 180 | Updates the animation of a broken block
 *
 * @param pBlock Broken block pointer
 * @param index Broken block array index
 */
void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock, u8 index)
{
    u16 value;
    s32 offset;
    u16* dst;

    value = CLIPDATA_TILEMAP_AIR;

    // Get clipdata tilemap value
    switch (pBlock->stage)
    {
        case 2:
        case 12:
            value = sReformingBlocksTilemapValue[pBlock->type];
            break;

        case 3:
        case 11:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID;
            break;

        case 4:
        case 10:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID_BREAKING_1;
            break;

        case 5:
        case 9:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID_BREAKING_2;
            break;

        case 6:
        case 8:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID_BREAKING_3;
            break;

        case 7:
            if (pBlock->type == BLOCK_TYPE_BROKEN)
                value = gBrokenBlockBg1Values[index] + 1;
            else
                value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_AIR;
            break;

        case 0:
        case 1:
        case 13:
            break;
    }

    // No tile, abort
    if (value == CLIPDATA_TILEMAP_AIR)
        return;

    // Write value to BG1 map
    SET_BG_BLOCK(1, value, pBlock->xPosition, pBlock->yPosition);

    // Check is on screen, no need to update the tilemap if off screen, that can be delegated to the room tilemap update functions
    offset = SUB_PIXEL_TO_BLOCK(gBg1YPosition);
    if (offset - 4 > pBlock->yPosition || pBlock->yPosition > offset + SCREEN_SIZE_Y_BLOCKS + 3)
        return;

    offset = SUB_PIXEL_TO_BLOCK(gBg1XPosition);
    if (offset - 4 > pBlock->xPosition || pBlock->xPosition > offset + SCREEN_SIZE_X_BLOCKS + 3)
        return;

    // Apply to tilemap
    dst = VRAM_BASE + 0x1000;
    if (pBlock->xPosition & 0x10)
        dst = VRAM_BASE + 0x1800;

    offset = (pBlock->xPosition & 0xF) * 2;
    dst += (pBlock->yPosition & 0xF) * 64 + offset;

    if (value & CLIPDATA_TILEMAP_FLAG)
    {
        offset = (value & CLIPDATA_TILEMAP_MASK) * 4;
        dst[0] = sCommonTilemap[offset++];
        dst[1] = sCommonTilemap[offset++];
        dst[32] = sCommonTilemap[offset++];
        dst[33] = sCommonTilemap[offset];
    }
    else
    {
        offset = value * 4;
        dst[0] = gTilemapAndClipPointers.pTilemap[offset++];
        dst[1] = gTilemapAndClipPointers.pTilemap[offset++];
        dst[32] = gTilemapAndClipPointers.pTilemap[offset++];
        dst[33] = gTilemapAndClipPointers.pTilemap[offset];
    }
}

/**
 * @brief 6ba40 | c0 | Stores a new broken reform block
 *
 * @param type Block type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param skipStageAdvance Skips advancing the stage to 2 and drawing the block
 * @return s32 bool, could store
 */
bools32 BlockStoreBrokenReformBlock(BlockType type, u16 xPosition, u16 yPosition, boolu8 skipStageAdvance)
{
    s32 found;
    s32 i;

    found = FALSE;

    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++)
    {
        if (gBrokenReformBlocks[i].xPosition == xPosition && gBrokenReformBlocks[i].yPosition == yPosition)
        {
            if (gBrokenReformBlocks[i].stage == BROKEN_BLOCK_STAGE_INTACT)
                found = TRUE;
            else if (gBrokenReformBlocks[i].stage != 0)
                found = FALSE;
            else
                continue;

            break;
        }
        else
        {
            if (gBrokenReformBlocks[i].stage == 0 || gBrokenReformBlocks[i].stage == BROKEN_BLOCK_STAGE_INTACT)
                found = i | 0x80;
        }
    }
    
    if (found & 0x80)
    {
        i = found & 0x7F;
        gBrokenReformBlocks[i].xPosition = xPosition;
        gBrokenReformBlocks[i].yPosition = yPosition;
        found = TRUE;
    }

    if (found)
    {
        gBrokenReformBlocks[i].timer = 0;
        gBrokenReformBlocks[i].stage = 1;
        gBrokenReformBlocks[i].type = type;

        if (!skipStageAdvance)
        {
            gBrokenReformBlocks[i].stage = 2;
            BgClipClearClipAndBg1BlockValue(yPosition, xPosition);
            BlockUpdateBrokenBlockAnimation(&gBrokenReformBlocks[i], i);
        }
    }

    return found;
}

/**
 * @brief 6bb00 | 90 | Stores a block that has been revealed
 * 
 * @param type Block type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return s32 bool, could store
 */
bools32 BlockStoreRevealedBlock(BlockType type, u16 xPosition, u16 yPosition)
{
    s32 found;
    s32 i;

    found = 0;

    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++)
    {
        if (gBrokenReformBlocks[i].xPosition == xPosition && gBrokenReformBlocks[i].yPosition == yPosition)
        {
            if (gBrokenReformBlocks[i].stage == BROKEN_BLOCK_STAGE_INTACT)
                found = TRUE;
            else if (gBrokenReformBlocks[i].stage != 0)
                found = FALSE;
            else
                continue;

            break;
        }
        else
        {
            if (gBrokenReformBlocks[i].stage == 0 || gBrokenReformBlocks[i].stage == BROKEN_BLOCK_STAGE_INTACT)
                found = i | 0x80;
        }
    }
    
    if (found & 0x80)
    {
        i = found & 0x7F;
        gBrokenReformBlocks[i].xPosition = xPosition;
        gBrokenReformBlocks[i].yPosition = yPosition;
        found = TRUE;
    }

    if (found)
    {
        gBrokenReformBlocks[i].timer = 0;
        gBrokenReformBlocks[i].stage = BROKEN_BLOCK_STAGE_INTACT;
        gBrokenReformBlocks[i].type = type;
    }

    return found;
}

/**
 * @brief 6bb90 | 5c | Checks if Samus is in a reforming block
 *
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return s32 bool, in block
 */
bools32 BlockCheckSamusInReformingBlock(u16 yPosition, u16 xPosition)
{
    u16 samusX;
    u16 samusY[2];
    bools32 inX;
    bools32 inY;
    bools32 inBlock;

    samusX = SUB_PIXEL_TO_BLOCK_(gSamusData.xPosition);
    samusY[0] = SUB_PIXEL_TO_BLOCK_(gSamusData.drawDistanceTop + gSamusData.yPosition);
    samusY[1] = SUB_PIXEL_TO_BLOCK_(gSamusData.drawDistanceBottom + gSamusData.yPosition);

    inX = FALSE;
    if (samusX == xPosition)
        inX = TRUE;

    inY = FALSE;
    if (yPosition >= samusY[0] && yPosition <= samusY[1])
        inY = TRUE;

    inBlock = FALSE;
    if (inX)
        inBlock = inY;

    return inBlock;
}

/**
 * @brief 6bbec | 88 | Starts a new bomb chain
 *
 * @param type Bomb chain type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return s32 bool, could start
 */
bools32 BlockStartBombChain(BombChainType type, u16 xPosition, u16 yPosition)
{
    s32 i;
    bools32 couldStart;

    couldStart = FALSE;

    for (i = ARRAY_SIZE(gBombChains); i > 0;)
    {
        i--;

        if (gBombChains[i].currentOffset == 0)
        {
            gBombChains[i].currentOffset = 1;
            gBombChains[i].srcXPosition = xPosition;
            gBombChains[i].srcYPosition = yPosition;
            gBombChains[i].negativeActive = TRUE;
            gBombChains[i].positiveActive = TRUE;
            gBombChains[i].type = type;

            gActiveBombChainTypes |= sBombChainReverseData[type].typeFlag;
            couldStart = TRUE;
            break;
        }
    }

    return couldStart;
}

/**
 * @brief 6bc74 | 2a0 | Updates the bomb chains
 *
 */
void BlockUpdateBombChains(void)
{
    s32 index;
    s32 horizontal;
    struct ClipdataBlockData clipBlock;
    bools32 destroyed;
    u16 clipdata;

    // Only update one bomb chain per frame
    index = MOD_AND(gFrameCounter8Bit, ARRAY_SIZE(gBombChains));

    if (gBombChains[index].currentOffset == 0)
        return;

    horizontal = FALSE;
    if (gBombChains[index].type >= BOMB_CHAIN_TYPE_HORIZONTAL_1)
        horizontal = TRUE;

    clipBlock.behavior = sBombChainReverseData[gBombChains[index].type].behavior;
    clipBlock.tilemapValue = 0;
    clipBlock.blockBehavior = BEHAVIOR_TO_BLOCK(clipBlock.behavior);

    destroyed = FALSE;
    
    if (!horizontal)
    {
        // Update vertical
        clipBlock.xPosition = gBombChains[index].srcXPosition;
        if (gBombChains[index].negativeActive)
        {
            clipBlock.yPosition = gBombChains[index].srcYPosition - gBombChains[index].currentOffset;
            if (clipBlock.yPosition <= 1)
            {
                gBombChains[index].negativeActive = FALSE;
            }
            else
            {
                clipdata = GET_CLIP_BLOCK(clipBlock.xPosition, clipBlock.yPosition);
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    BlockDestroyNonReformBlock(&clipBlock);
                    destroyed = TRUE;
                }
                else
                {
                    gBombChains[index].negativeActive = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_GOING_UP,
                        clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }

        if (gBombChains[index].positiveActive)
        {
            clipBlock.yPosition = gBombChains[index].srcYPosition + gBombChains[index].currentOffset;
            if (clipBlock.yPosition >= gBackgroundsData.clipdataHeight - 2)
            {
                gBombChains[index].positiveActive = FALSE;
            }
            else
            {
                clipdata = GET_CLIP_BLOCK(clipBlock.xPosition, clipBlock.yPosition);
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    BlockDestroyNonReformBlock(&clipBlock);
                    destroyed = TRUE;
                }
                else
                {
                    gBombChains[index].positiveActive = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_GOING_DOWN,
                        clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }
    }
    else
    {
        // Update horizontal
        clipBlock.yPosition = gBombChains[index].srcYPosition;
        if (gBombChains[index].negativeActive)
        {
            clipBlock.xPosition = gBombChains[index].srcXPosition - gBombChains[index].currentOffset;
            if (clipBlock.xPosition <= 1)
            {
                gBombChains[index].negativeActive = FALSE;
            }
            else
            {
                clipdata = GET_CLIP_BLOCK(clipBlock.xPosition, clipBlock.yPosition);
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    BlockDestroyNonReformBlock(&clipBlock);
                    destroyed = TRUE;
                }
                else
                {
                    gBombChains[index].negativeActive = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_VERTICAL_GOING_LEFT,
                        clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }

        if (gBombChains[index].positiveActive)
        {
            clipBlock.xPosition = gBombChains[index].srcXPosition + gBombChains[index].currentOffset;
            if (clipBlock.xPosition >= gBackgroundsData.clipdataWidth - 2)
            {
                gBombChains[index].positiveActive = FALSE;
            }
            else
            {
                clipdata = GET_CLIP_BLOCK(clipBlock.xPosition, clipBlock.yPosition);
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    BlockDestroyNonReformBlock(&clipBlock);
                    destroyed = TRUE;
                }
                else
                {
                    gBombChains[index].positiveActive = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_VERTICAL_GOING_RIGHT,
                        clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }
    }

    if (gBombChains[index].negativeActive || gBombChains[index].positiveActive)
    {
        gBombChains[index].currentOffset++;
    }
    else
    {
        gBombChains[index].currentOffset = 0;
        gActiveBombChainTypes &= ~sBombChainReverseData[gBombChains[index].type].typeFlag;
    }

    if (destroyed)
        SoundPlayNotAlreadyPlaying(SOUND_128);
}

/**
 * @brief 6bf14 | b0 | Checks if a new sub bomb chain should start
 * 
 * @param type Sub bomb chain type
 * @param xPosition X position
 * @param yPosition Y position
 */
void BlockCheckStartNewSubBombChain(SubBombChainRequest type, u8 xPosition, u8 yPosition)
{
    u16 clipdata;
    s32 i;
    struct BackgroundsData* pBg;
    s32 blockY;
    s32 blockX;
    s32 offset;

    gCurrentClipdataAffectingAction = CAA_BOMB_CHAIN;

    // Check the current position
    clipdata = GET_CLIP_BLOCK(xPosition, yPosition);
    if (clipdata != CLIPDATA_AIR)
        BlockApplyClipdataAction(yPosition, xPosition, clipdata);

    for (i = 0; i < ARRAY_SIZE(sSubBombChainPositionOffset[0]) / 2; i++)
    {
        pBg = &gBackgroundsData;

        blockY = yPosition + sSubBombChainPositionOffset[type][i * 2 + 1];
        offset = blockY * pBg->clipdataWidth;

        blockX = xPosition + sSubBombChainPositionOffset[type][i * 2 + 0];
        offset += blockX;

        clipdata = pBg->pClipDecomp[offset];
        if (clipdata != CLIPDATA_AIR)
            BlockApplyClipdataAction(blockY, blockX, clipdata);
    }

    gCurrentClipdataAffectingAction = CAA_NONE;
}
