#include "menus/pause_screen_map.h"

#include "globals.h"
#include "gba/dma.h"
#include "gba/keys.h"

#include "data/event_data.h"
#include "data/menus/pause_debug.h"
#include "data/menus/pause_screen_map_data.h"

#include "constants/audio.h"
#include "constants/block.h"
#include "constants/connection.h"
#include "constants/event.h"
#include "constants/minimap.h"

#include "structs/bg_clip.h"
#include "structs/connection.h"
#include "structs/minimap.h"
#include "structs/room.h"
#include "structs/samus.h"

extern u32 sExploredMinimapBitFlags[32];

// Minimap data?
static u8* sUnk_79be5c[11] = {
    (u8*)0x8572D48,
    (u8*)0x8572F9C,
    (u8*)0x8573748,
    (u8*)0x857317C,
    (u8*)0x8573538,
    (u8*)0x857395C,
    (u8*)0x8573364,
    (u8*)0x8572D48,
    (u8*)0x8572D48,
    (u8*)0x8573B54,
    (u8*)0x8572C4C,
};

// 4 byte struct?
static u8 sUnk_79be88[32] = {
    0x00, 0x00, 0x00, 0x00,
    0x13, 0x36, 0x24, 0x8E,
    0x14, 0x37, 0x24, 0x18,
    0x15, 0x38, 0x24, 0x20,
    0x16, 0x39, 0x24, 0x28,
    0x17, 0x3A, 0x32, 0x0D,
    0x18, 0x3B, 0x48, 0x0D,
    0x19, 0x3C, 0x5E, 0x0D,
};

static u8* sUnk_79bea8[5] = {
    (u8*)0x8576168,
    (u8*)0x857616D,
    (u8*)0x8576171,
    (u8*)0x8576173,
    (u8*)0x8576175,
};

static u8 sUnk_79bebc[4] = {
    4, 5, 6, 7
};

static u8 sBlob_79bec0_79c128[] = INCBIN_U8("data/Blob_79bec0_79c128.bin");

/**
 * @brief 7552c | 214 | Pause screen map main loop
 * 
 */
void PauseScreenMapHandler(void)
{
    s32 action;
#ifndef BUGFIX
    u32 unused[4];
#endif // !BUGFIX

    action = 0;
    
    if (!(gButtonInput & KEY_A))
    {
        PAUSE_SCREEN_DATA.canScrollUp = PAUSE_SCREEN_DATA.mapViewY != PAUSE_SCREEN_DATA.mapTopBorder;
        PAUSE_SCREEN_DATA.canScrollDown = PAUSE_SCREEN_DATA.mapBottomBorder > PAUSE_SCREEN_DATA.mapViewY;
        PAUSE_SCREEN_DATA.canScrollRight = PAUSE_SCREEN_DATA.mapRightBorder > PAUSE_SCREEN_DATA.mapViewX;
        PAUSE_SCREEN_DATA.canScrollLeft = PAUSE_SCREEN_DATA.mapViewX != PAUSE_SCREEN_DATA.mapLeftBorder;
        
        if (gChangedInput & KEY_UP)
        {
            if (PAUSE_SCREEN_DATA.canScrollUp)
            {
                PAUSE_SCREEN_DATA.mapViewY--;
                action = 1;
            }
        }
        else if (gChangedInput & KEY_DOWN)
        {
            if (PAUSE_SCREEN_DATA.canScrollDown)
            {
                PAUSE_SCREEN_DATA.mapViewY++;
                action = 1;
            }
        }
        else if (gChangedInput & KEY_RIGHT)
        {
            if (PAUSE_SCREEN_DATA.canScrollRight)
            {
                PAUSE_SCREEN_DATA.mapViewX++;
                action = 1;
            }
        }
        else if (gChangedInput & KEY_LEFT)
        {
            if (PAUSE_SCREEN_DATA.canScrollLeft)
            {
                PAUSE_SCREEN_DATA.mapViewX--;
                action = 1;
            }
        }

        gBackgroundPositions.bg[3].x = 0x200 -
            ((SCREEN_SIZE_X_BLOCKS - PAUSE_SCREEN_DATA.mapViewX) * 8);
        gBackgroundPositions.bg[3].y = 0x200 -
            ((SCREEN_SIZE_Y_BLOCKS - PAUSE_SCREEN_DATA.mapViewY) * 8);
        
        if (gChangedInput & KEY_R)
        {
            PAUSE_SCREEN_DATA.unk_28 = 6;
            PAUSE_SCREEN_DATA.timer = 0;
            PAUSE_SCREEN_DATA.pauseDebugEditingValue = 0;
            action = 3;
        }
        else if (gChangedInput & KEY_L) {
            PAUSE_SCREEN_DATA.unk_28 = 0xB;
            PAUSE_SCREEN_DATA.timer = 0;
            PAUSE_SCREEN_DATA.pauseDebugEditingValue = 0;
            action = 3;
        }
    }

    if (gChangedInput & KEY_A)
        action = 2;

    if (action != 0)
    {
        if (action == 1)
        {
            unk_77840(1);
        }
        else if (action == 2)
        {
            if (PAUSE_SCREEN_DATA.unk_1 == 4)
                action = 1;
            else if (PAUSE_SCREEN_DATA.unk_1 == 5)
                action = 2;
            else if (PAUSE_SCREEN_DATA.unk_1 == 9)
                action = 1;
            
            unk_77840(action);
        }
    }
    else
    {
        if ((gChangedInput & KEY_SELECT) && PAUSE_SCREEN_DATA.unk_274 != 0)
            PauseScreenMapDrawIgtAndTanks(TRUE);
    }
}

/**
 * @brief 75740 | 2c | Sets the Samus head icon on the map screen
 * 
 */
void PauseScreenMapSetSamusHeadPosition(void)
{
    PAUSE_SCREEN_DATA.oam[0x20].xPosition = gMinimapX * TILE_DIM;
    PAUSE_SCREEN_DATA.oam[0x20].yPosition = gMinimapY * TILE_DIM;
}

/**
 * @brief 7576c | 20 | Sets visited tiles and collected items on the minimap
 * 
 * @param area Area ID
 */
void MinimapSetVisitedTilesAndCollectedItems(u8 area)
{
    u8 index;

    index = area > AREA_NORMAL_COUNT ? AREA_NORMAL_COUNT : area;

    MinimapSetVisitedTiles(index);
    MinimapSetCollectedItems(index);
}

/**
 * @brief 7578c | f8 | Sets visited tiles on the minimap
 * 
 * @param area Area ID
 */
void MinimapSetVisitedTiles(u8 area)
{
    u8 index;
    u32* pVisited;
    u16* pMap;
    s32 i;
    s32 j;
    u32 tmp1;
    u32 tmp2;

    if (area < AREA_NORMAL_COUNT)
        index = area;
    else
        index = AREA_NORMAL_COUNT;

    pVisited = &gVisitedMinimapTiles[index * (MINIMAP_SIZE / 32)];
    pMap = gMinimapData_Visited;

    if ((gEquipment.downloadedMaps >> index) & 1)
    {
        for (i = 0; i < MINIMAP_DIM; i++, pVisited++)
        {
            for (j = 0; j < MINIMAP_DIM; j++, pMap++)
            {
                tmp1 = *pVisited;
                if (sExploredMinimapBitFlags[j] & tmp1)
                {
                    if (!(*pMap & MINIMAP_TILE_HIDDEN_FLAG))
                        *pMap |= MINIMAP_TILE_NORMAL_FLAG;
                }
                else
                {
                    if (*pMap & MINIMAP_TILE_HIDDEN_FLAG)
                        *pMap = MINIMAP_TILE_BACKGROUND;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < MINIMAP_DIM; i++, pVisited++)
        {
            for (j = 0; j < MINIMAP_DIM; j++, pMap++)
            {
                tmp2 = *pVisited;
                if (sExploredMinimapBitFlags[j] & tmp2)
                {
                    if (!(*pMap & MINIMAP_TILE_HIDDEN_FLAG))
                        *pMap |= MINIMAP_TILE_NORMAL_FLAG;
                }
                else
                {
                    *pMap = MINIMAP_TILE_BACKGROUND;
                }
            }
        }
    }
}

/**
 * @brief 75884 | a4 | Sets collected items on the minimap
 * 
 * @param area Area ID
 */
void MinimapSetCollectedItems(u8 area)
{
    s32 i;
    u16* pMap;
    s32 maxCount;
    u8* pTank;
    s32 x;
    s32 y;
    const struct RoomEntryRom* pRoom;

    if (area < AREA_NORMAL_COUNT)
        i = area;
    else
        i = AREA_NORMAL_COUNT;

    pMap = gMinimapData_Visited;
    
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
            break;

        x = (pTank[2] - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS;
        y = (pTank[3] - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS;
        pRoom = &sAreaRoomEntryPointers[area][pTank[0]];
        x += pRoom->mapX;
        y += pRoom->mapY;
        pMap[y * MINIMAP_DIM + x]++;        
    }
}

/**
 * @brief 75928 | 60 | Checks to update the current tile in the visited minimap data
 * 
 */
void MinimapCheckUpdateVisitedTile(void)
{
    s32 offset;

    if (gCurrentArea >= AREA_NORMAL_COUNT)
        return;

    offset = gMinimapX + (gMinimapY * MINIMAP_DIM);

    // Check if not visited
    if (!(gMinimapData_Visited[offset] & (MINIMAP_TILE_NORMAL_FLAG | MINIMAP_TILE_HIDDEN_FLAG)))
    {
        if (!(gMinimapData[offset] & MINIMAP_TILE_HIDDEN_FLAG))
            gMinimapData_Visited[offset] = gMinimapData[offset] | MINIMAP_TILE_NORMAL_FLAG;
        else
            gMinimapData_Visited[offset] = gMinimapData[offset];
    }
}

/**
 * @brief 75988 | 2dc | To document
 * 
 * @param arg0
 */
void unk_75988(boolu8 arg0)
{
    u16* pMap;
    s32 found;
    s32 i;
    s32 j;
    s32 mapX;
    s32 mapY;
    
    PAUSE_SCREEN_DATA.canScrollRight = FALSE;
    PAUSE_SCREEN_DATA.canScrollLeft = FALSE;
    PAUSE_SCREEN_DATA.canScrollUp = FALSE;
    PAUSE_SCREEN_DATA.canScrollDown = FALSE;
    
    PAUSE_SCREEN_DATA.mapLeftBorder = MINIMAP_DIM - 1;
    PAUSE_SCREEN_DATA.mapTopBorder = MINIMAP_DIM - 1;
    PAUSE_SCREEN_DATA.mapRightBorder = 0;
    PAUSE_SCREEN_DATA.mapBottomBorder = 0;

    pMap = gMinimapData_Visited;

    // Find first non-blank row from top
    found = FALSE;
    for (i = 0; i < MINIMAP_DIM; i++)
    {
        for (j = 0; j < MINIMAP_DIM; j++)
        {
            if (pMap[i * MINIMAP_DIM + j] != MINIMAP_TILE_BACKGROUND)
            {
                PAUSE_SCREEN_DATA.mapTopBorder = i;
                found = TRUE;
                break;
            }
        }

        if (found)
            break;
    }

    // Find first non-blank row from bottom
    found = FALSE;
    for (i = MINIMAP_DIM; i > 0;)
    {
        i--;

        for (j = 0; j < MINIMAP_DIM; j++)
        {
            if (pMap[i * MINIMAP_DIM + j] != MINIMAP_TILE_BACKGROUND)
            {
                PAUSE_SCREEN_DATA.mapBottomBorder = i;
                found = TRUE;
                break;
            }
        }

        if (found)
            break;
    }

    // Find first non-blank column from left
    found = FALSE;
    for (i = 0; i < MINIMAP_DIM; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (pMap[i + j * MINIMAP_DIM] != MINIMAP_TILE_BACKGROUND)
            {
                PAUSE_SCREEN_DATA.mapLeftBorder = i;
                found = TRUE;
                break;
            }
        }

        if (found)
            break;
    }

    // Find first non-blank column from right
    found = FALSE;
    for (i = MINIMAP_DIM; i > 0;)
    {
        i--;

        for (j = 0; j < 20; j++)
        {
            if (pMap[i + j * MINIMAP_DIM] != MINIMAP_TILE_BACKGROUND)
            {
                PAUSE_SCREEN_DATA.mapRightBorder = i;
                found = TRUE;
                break;
            }
        }

        if (found)
            break;
    }

    if (PAUSE_SCREEN_DATA.mapLeftBorder > PAUSE_SCREEN_DATA.mapRightBorder)
        PAUSE_SCREEN_DATA.mapRightBorder = PAUSE_SCREEN_DATA.mapLeftBorder;
    if (PAUSE_SCREEN_DATA.mapTopBorder > PAUSE_SCREEN_DATA.mapBottomBorder)
        PAUSE_SCREEN_DATA.mapBottomBorder = PAUSE_SCREEN_DATA.mapTopBorder;

    PAUSE_SCREEN_DATA.unk_25A = PAUSE_SCREEN_DATA.mapRightBorder;
    PAUSE_SCREEN_DATA.unk_25B = PAUSE_SCREEN_DATA.mapLeftBorder;
    PAUSE_SCREEN_DATA.unk_25C = PAUSE_SCREEN_DATA.mapTopBorder;
    PAUSE_SCREEN_DATA.unk_25D = PAUSE_SCREEN_DATA.mapBottomBorder;
    
    if (arg0)
    {
        mapX = PAUSE_SCREEN_DATA.mapX;
        mapY = PAUSE_SCREEN_DATA.mapY;
    }
    else
    {
        mapX = DIV_SHIFT(PAUSE_SCREEN_DATA.mapLeftBorder + PAUSE_SCREEN_DATA.mapRightBorder, 2);
        mapY = DIV_SHIFT(PAUSE_SCREEN_DATA.mapTopBorder + PAUSE_SCREEN_DATA.mapBottomBorder, 2);
        
        i = mapY + 4;
        j = mapY - 7;
        if (i < PAUSE_SCREEN_DATA.mapY)
            mapY += PAUSE_SCREEN_DATA.mapY - i;
        else if (j > PAUSE_SCREEN_DATA.mapY)
            mapY -= j - PAUSE_SCREEN_DATA.mapY;
        
        i = mapX + 12;
        j = mapX - 12;
        if (i < PAUSE_SCREEN_DATA.mapX)
            mapX += PAUSE_SCREEN_DATA.mapX - i;
        else if (j > PAUSE_SCREEN_DATA.mapX)
            mapX -= j - PAUSE_SCREEN_DATA.mapX;
    }
    
    PAUSE_SCREEN_DATA.mapViewX = mapX;
    PAUSE_SCREEN_DATA.mapViewY = mapY;
    gBackgroundPositions.bg[3].x = 0x200 - ((SCREEN_SIZE_X_BLOCKS - PAUSE_SCREEN_DATA.mapViewX) * 8);
    gBackgroundPositions.bg[3].y = 0x200 - ((SCREEN_SIZE_Y_BLOCKS - PAUSE_SCREEN_DATA.mapViewY) * 8);
    
    i = DIV_SHIFT(PAUSE_SCREEN_DATA.mapBottomBorder - PAUSE_SCREEN_DATA.mapTopBorder, 2);
    if (i > 3)
        i = 3;
    PAUSE_SCREEN_DATA.mapTopBorder += i;
    PAUSE_SCREEN_DATA.mapBottomBorder -= i;

    i = DIV_SHIFT(PAUSE_SCREEN_DATA.mapRightBorder - PAUSE_SCREEN_DATA.mapLeftBorder, 2);
    if (i > 3)
        i = 3;
    PAUSE_SCREEN_DATA.mapLeftBorder += i;
    PAUSE_SCREEN_DATA.mapRightBorder -= i;
}

/**
 * @brief 75c64 | 64 | Changes the minimap tile when an item is collected
 * 
 * @param xPosition Minimap tile X position
 * @param yPosition Minimap tile Y position
 */
void MinimapUpdateForCollectedItem(u8 xPosition, u8 yPosition)
{
    s32 offset;

    offset = ((xPosition - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS) + gCurrentRoomEntry.mapX +
       ((((yPosition - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS) + gCurrentRoomEntry.mapY) * MINIMAP_DIM);
    gMinimapData_Visited[offset]++;
    gMinimapData[offset]++;

    gMinimapUpdateFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    MinimapHudDraw();
}

/**
 * @brief 75cc8 | 60 | Checks if a minimap tile has been visited
 * 
 * @param xPosition Minimap tile X position
 * @param yPosition Minimap tile Y position
 * @return s32 Visited bit flag (non-zero if visited)
 */
s32 MinimapCheckIsTileVisited(u8 xPosition, u8 yPosition)
{
    s32 areaOffset;
    s32 column;
    s32 row;

    if (gCurrentArea >= AREA_NORMAL_COUNT)
        return TRUE;

    areaOffset = gCurrentArea * MINIMAP_DIM;
    
    column = (xPosition - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS;
    column += gCurrentRoomEntry.mapX;

    row = (yPosition - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS;
    row += gCurrentRoomEntry.mapY;
    
    return gVisitedMinimapTiles[row + areaOffset] & sExploredMinimapBitFlags[column];
}

/**
 * @brief 75d28 | 13c | Counts the number of collected tanks for the map screen
 * 
 */
void PauseScreenMapCountTanks(void)
{
    s32 i;
    s32 maxCount;    
    u8* pTank;

    PAUSE_SCREEN_DATA.totalEnergyTanks = sNumberOfTanksPerArea[AREA_NORMAL_COUNT][TANK_NUM_ENERGY];
    PAUSE_SCREEN_DATA.totalMissileTanks = sNumberOfTanksPerArea[AREA_NORMAL_COUNT][TANK_NUM_MISSILE];
    PAUSE_SCREEN_DATA.totalPowerBombTanks = sNumberOfTanksPerArea[AREA_NORMAL_COUNT][TANK_NUM_POWER_BOMB];
    
    PAUSE_SCREEN_DATA.currentTotalEnergyTanks =
        (gEquipment.maxEnergy - STARTING_ENERGY) / ENERGY_INCREASE_AMOUNT;
    PAUSE_SCREEN_DATA.currentTotalMissileTanks =
        (gEquipment.maxMissiles - STARTING_MISSILES) / MISSILE_INCREASE_AMOUNT;
    PAUSE_SCREEN_DATA.currentTotalPowerBombTanks =
        (gEquipment.maxPowerBombs - STARTING_POWER_BOMBS) / POWER_BOMB_INCREASE_AMOUNT;
    
    PAUSE_SCREEN_DATA.maxEnergyTanks = 0;
    PAUSE_SCREEN_DATA.maxMissileTanks = 0;
    PAUSE_SCREEN_DATA.maxPowerBombTanks = 0;
    
    PAUSE_SCREEN_DATA.currentEnergyTanks = 0;
    PAUSE_SCREEN_DATA.currentMissileTanks = 0;
    PAUSE_SCREEN_DATA.currentPowerBombTanks = 0;

    if (gCurrentArea < AREA_NORMAL_COUNT)
    {
        PAUSE_SCREEN_DATA.maxEnergyTanks = sNumberOfTanksPerArea[gCurrentArea][TANK_NUM_ENERGY];
        PAUSE_SCREEN_DATA.maxMissileTanks = sNumberOfTanksPerArea[gCurrentArea][TANK_NUM_MISSILE];
        PAUSE_SCREEN_DATA.maxPowerBombTanks = sNumberOfTanksPerArea[gCurrentArea][TANK_NUM_POWER_BOMB];
        
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
                break;

            if (pTank[1] == TANK_TYPE_MISSILE)
                PAUSE_SCREEN_DATA.currentMissileTanks++;
            else if (pTank[1] == TANK_TYPE_ENERGY)
                PAUSE_SCREEN_DATA.currentEnergyTanks++;
            else if (pTank[1] == TANK_TYPE_POWER_BOMB)
                PAUSE_SCREEN_DATA.currentPowerBombTanks++;
        }
    }
}

/**
 * @brief 75e64 | 374 | Draws the in-game timer and number of collected tanks on the map screen
 * 
 * @param arg0
 */
void PauseScreenMapDrawIgtAndTanks(boolu8 arg0)
{
    bools32 flag;
    s32 value;
    s32 count;

    if (arg0)
    {
        if (PAUSE_SCREEN_DATA.unk_274 == 1)
        {
            PAUSE_SCREEN_DATA.unk_274 = 2;
            flag = TRUE;
        }
        else if (PAUSE_SCREEN_DATA.unk_274 == 2)
        {
            PAUSE_SCREEN_DATA.unk_274 = 1;
            flag = FALSE;
        }
        else
        {
            return;
        }
    }
    else
    {
        PAUSE_SCREEN_DATA.unk_274 = 1;
        flag = FALSE;
    }

    // Hours tens
    value = gInGameTimer.hours / 10 % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_IGT_HOURS_IDX], TILE_SIZE / sizeof(u32));

    // Hours ones
    value = gInGameTimer.hours % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_IGT_HOURS_IDX] + TILE_SIZE, TILE_SIZE / sizeof(u32));

    // Minutes tens
    value = gInGameTimer.minutes / 10 % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_IGT_MINUTES_IDX], TILE_SIZE / sizeof(u32));

    // Minutes ones
    value = gInGameTimer.minutes % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_IGT_MINUTES_IDX] + TILE_SIZE, TILE_SIZE / sizeof(u32));

    // Current energy tanks
    if (!flag)
        count = PAUSE_SCREEN_DATA.currentTotalEnergyTanks;
    else
        count = PAUSE_SCREEN_DATA.currentEnergyTanks;

    value = count / 10 % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_CURR_ENERGY_IDX], TILE_SIZE / sizeof(u32));

    value = count % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_CURR_ENERGY_IDX] + TILE_SIZE, TILE_SIZE / sizeof(u32));

    // Total energy tanks
    if (!flag)
        count = PAUSE_SCREEN_DATA.totalEnergyTanks;
    else
        count = PAUSE_SCREEN_DATA.maxEnergyTanks;

    value = count / 10 % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_TOTAL_ENERGY_IDX], TILE_SIZE / sizeof(u32));

    value = count % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_TOTAL_ENERGY_IDX] + TILE_SIZE, TILE_SIZE / sizeof(u32));

    // Current missile tanks
    if (!flag)
        count = PAUSE_SCREEN_DATA.currentTotalMissileTanks;
    else
        count = PAUSE_SCREEN_DATA.currentMissileTanks;

    value = count / 10 % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_CURR_MISSILE_IDX], TILE_SIZE / sizeof(u32));

    value = count % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_CURR_MISSILE_IDX] + TILE_SIZE, TILE_SIZE / sizeof(u32));

    // Total missile tanks
    if (!flag)
        count = PAUSE_SCREEN_DATA.totalMissileTanks;
    else
        count = PAUSE_SCREEN_DATA.maxMissileTanks;

    value = count / 10 % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_TOTAL_MISSILE_IDX], TILE_SIZE / sizeof(u32));

    value = count % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_TOTAL_MISSILE_IDX] + TILE_SIZE, TILE_SIZE / sizeof(u32));
    
    // Current power bomb tanks
    if (!flag)
        count = PAUSE_SCREEN_DATA.currentTotalPowerBombTanks;
    else
        count = PAUSE_SCREEN_DATA.currentPowerBombTanks;

    value = count / 10 % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_CURR_POWER_BOMB_IDX], TILE_SIZE / sizeof(u32));

    value = count % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_CURR_POWER_BOMB_IDX] + TILE_SIZE, TILE_SIZE / sizeof(u32));

    // Total power bomb tanks
    if (!flag)
        count = PAUSE_SCREEN_DATA.totalPowerBombTanks;
    else
        count = PAUSE_SCREEN_DATA.maxPowerBombTanks;

    value = count / 10 % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_TOTAL_POWER_BOMB_IDX], TILE_SIZE / sizeof(u32));

    value = count % 10;
    DMA3_COPY_32(VRAM_BASE + 0x17EC0 + value * TILE_SIZE,
        sMapScreenTimeTankVramAddresses[MAP_SCREEN_TOTAL_POWER_BOMB_IDX] + TILE_SIZE, TILE_SIZE / sizeof(u32));
}

/**
 * @brief 761d8 | 420 | Main loop for downloading a map
 * 
 * @return s32 bool, ended
 */
bools32 PauseScreenMapDownload(void)
{
    bools32 ended;
    s32 i;
    s32 flag;

    ended = FALSE;
    APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.downloadMapTimer);

    switch (PAUSE_SCREEN_DATA.downloadMapStage)
    {
        case 0:
            if (PAUSE_SCREEN_DATA.downloadMapTimer > CONVERT_SECONDS(2/15.f))
            {
                PAUSE_SCREEN_DATA.oam[0x20].oamId = 0;
                PAUSE_SCREEN_DATA.oam[0x20].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.oam[0x20].currentAnimationFrame = 0;

                PAUSE_SCREEN_DATA.oam[3].oamId = 0x11;
                PAUSE_SCREEN_DATA.oam[3].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.oam[3].currentAnimationFrame = 0;
                PAUSE_SCREEN_DATA.oam[3].xPosition = 0x74;
                PAUSE_SCREEN_DATA.oam[3].yPosition = -8;
                PAUSE_SCREEN_DATA.oam[3].priority = 0;

                for (i = ARRAY_SIZE(sUnk_79bebc); i > 0;)
                {
                    i -= 1;
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].oamId = 0;
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].animationDurationCounter = 0;
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].currentAnimationFrame = 0;
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].xPosition = 0x74;
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].yPosition = -8;
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].priority = 0;
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].objMode = 1;
                }

                PAUSE_SCREEN_DATA.downloadMapStage++;
                PAUSE_SCREEN_DATA.downloadMapTimer = 0;
                PAUSE_SCREEN_DATA.unk_232 = 0;
                PAUSE_SCREEN_DATA.unk_234 = 0x80;
            }
            break;

        case 1:
            PAUSE_SCREEN_DATA.downloadMapCurrentLine = 0;

            if (gBackgroundPositions.bg[3].y < 0x200)
            {
                PAUSE_SCREEN_DATA.downloadMapCurrentLine = 0x20 - DIV_SHIFT(0x200 - gBackgroundPositions.bg[3].y, 8);
            }
            else if (gBackgroundPositions.bg[3].y > 0x200)
            {
                PAUSE_SCREEN_DATA.downloadMapCurrentLine = DIV_SHIFT(gBackgroundPositions.bg[3].y - 0x200, 8);
            }

            PAUSE_SCREEN_DATA.unk_232 = 0;
            SoundPlay(SOUND_11B);
            PAUSE_SCREEN_DATA.downloadMapStage++;
            PAUSE_SCREEN_DATA.downloadMapTimer = 0;
            break;

        case 2:
            i = TRUE;

            if (PAUSE_SCREEN_DATA.downloadMapTimer > CONVERT_SECONDS(7/60.f))
            {
                if (PAUSE_SCREEN_DATA.unk_232 <= 0x13)
                {
                    DMA3_COPY_16(&gMinimapData_Visited[PAUSE_SCREEN_DATA.downloadMapCurrentLine * MINIMAP_DIM],
                        VRAM_BASE + 0xE000 + (PAUSE_SCREEN_DATA.downloadMapCurrentLine * MINIMAP_DIM * sizeof(u16)), MINIMAP_DIM);

                    PAUSE_SCREEN_DATA.unk_232++;
                    PAUSE_SCREEN_DATA.downloadMapCurrentLine++;
                    if (PAUSE_SCREEN_DATA.downloadMapCurrentLine >= MINIMAP_DIM)
                        PAUSE_SCREEN_DATA.downloadMapCurrentLine = 0;
                }
                else
                {
                    PAUSE_SCREEN_DATA.downloadMapStage++;
                    i = FALSE;
                }
                PAUSE_SCREEN_DATA.downloadMapTimer = 0;
            }

            if (i)
            {
                PAUSE_SCREEN_DATA.oam[3].yPosition = (PAUSE_SCREEN_DATA.unk_232 * 8) + PAUSE_SCREEN_DATA.downloadMapTimer - 5;
                PAUSE_SCREEN_DATA.unk_234++;
                if (PAUSE_SCREEN_DATA.unk_234 > 3)
                    PAUSE_SCREEN_DATA.unk_234 = 0;

                i = PAUSE_SCREEN_DATA.unk_234;
                PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].yPosition = PAUSE_SCREEN_DATA.oam[3].yPosition - 1;
                if (i <= 2)
                {
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].oamId = 0x10;
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].animationDurationCounter = 0;
                    PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].currentAnimationFrame = 0;
                }
            }
            break;

        case 3:
            DMA3_COPY_16(gMinimapData_Visited, VRAM_BASE + 0xE000, MINIMAP_SIZE);
            PAUSE_SCREEN_DATA.downloadMapStage++;
            PAUSE_SCREEN_DATA.downloadMapTimer = 0;
            break;

        case 4:
            for (i = MINIMAP_UPDATE_FLAG_LOWER_LINE; i > MINIMAP_UPDATE_FLAG_NONE; i--)
            {
                gMinimapUpdateFlag = i;
                MinimapHudDraw();
            }

            PAUSE_SCREEN_DATA.downloadMapStage++;
            PAUSE_SCREEN_DATA.downloadMapTimer = 0;
            break;

        case 5:
            PAUSE_SCREEN_DATA.oam[0x20].oamId = 1;
            PAUSE_SCREEN_DATA.oam[0x20].animationDurationCounter = 0;
            PAUSE_SCREEN_DATA.oam[0x20].currentAnimationFrame = 0;
            PAUSE_SCREEN_DATA.oam[3].oamId = 0;
            PAUSE_SCREEN_DATA.oam[3].animationDurationCounter = 0;
            PAUSE_SCREEN_DATA.oam[3].currentAnimationFrame = 0;

            for (i = ARRAY_SIZE(sUnk_79bebc); i > 0;)
            {
                i--;
                PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].oamId = 0;
                PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].animationDurationCounter = 0;
                PAUSE_SCREEN_DATA.oam[sUnk_79bebc[i]].currentAnimationFrame = 0;
            }

            PAUSE_SCREEN_DATA.downloadMapTimer = 0;
            PAUSE_SCREEN_DATA.downloadMapStage++;
            break;

        case 6:
            if (PAUSE_SCREEN_DATA.downloadMapTimer > CONVERT_SECONDS(29/60.f))
            {
                PAUSE_SCREEN_DATA.downloadMapTimer = 0;
                PAUSE_SCREEN_DATA.downloadMapStage = 0;
                ended = TRUE;
            }
            break;
    }

    return ended;
}
