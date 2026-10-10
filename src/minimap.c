#include "minimap.h"

#include "macros.h"
#include "gba/memory.h"
#include "globals.h"

#include "data/menus/pause_debug.h"
#include "data/menus/pause_screen_map_data.h"

#include "constants/connection.h"
#include "constants/minimap.h"

#include "structs/bg_clip.h"
#include "structs/connection.h"
#include "structs/minimap.h"
#include "structs/room.h"
#include "structs/samus.h"

static u32 sExploredMinimapBitFlags[32] = {
    1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7,
    1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15,
    1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22, 1 << 23,
    1 << 24, 1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29, 1 << 30, 1 << 31,
};

static u8 sBlob_79be5c_79c27c[] = INCBIN_U8("data/Blob_79be5c_79c27c.bin");

/**
 * @brief 74ffc | 88 | Loads the initial minimap data
 * 
 */
void MinimapLoadInitial(void)
{
    s32 x;
    s32 y;

    GetMinimapData(gPreviousArea, gMinimapData_Visited);
    DMA3_COPY_16(gMinimapData_Visited, gMinimapData,
        sizeof(gMinimapData_Visited) / sizeof(u16));

    MinimapSetVisitedTilesAndCollectedItems(gPreviousArea);

    // Assumes Samus starts in Main Deck room 0
    x = SUB_PIXEL_TO_BLOCK_(gSamusData.xPosition - SCREEN_X_BLOCK_PADDING);
    y = SUB_PIXEL_TO_BLOCK_(gSamusData.yPosition - SCREEN_Y_BLOCK_PADDING);
    x /= SCREEN_SIZE_X_BLOCKS;
    y /= SCREEN_SIZE_Y_BLOCKS;
    gMinimapX = sAreaRoomEntryPointers[AREA_MAIN_DECK][0].mapX + x;
    gMinimapY = sAreaRoomEntryPointers[AREA_MAIN_DECK][0].mapY + y;

    MinimapSetTileAsExplored();
}

/**
 * @brief 75084 | 24 | Updates the minimap
 * 
 */
void MinimapUpdate(void)
{
    MinimapCheckPositionChanged();

    if (gMinimapUpdateFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
    {
        MinimapSetTileAsExplored();
        MinimapUpdateForExploredTiles();
    }

    MinimapHudDraw();
}

/**
 * @brief 750a8 | 44 | Sets the current minimap tile as explored
 * 
 */
void MinimapSetTileAsExplored(void)
{
    s32 offset;

    if (gCurrentArea < AREA_NORMAL_COUNT)
    {
        offset = (gCurrentArea * (MINIMAP_SIZE / 32)) + gMinimapY;
        gVisitedMinimapTiles[offset] |= sExploredMinimapBitFlags[gMinimapX];
    }
}

/**
 * @brief 750ec | d8 | Checks if the minimap tile position has changed
 * 
 */
void MinimapCheckPositionChanged(void)
{
    u16 x;
    u16 y;
    u16 edge;

    if (gMinimapUpdateFlag != MINIMAP_UPDATE_FLAG_NONE)
        return;

    x = gSamusData.xPosition - SCREEN_X_BLOCK_PADDING;
    y = gSamusData.yPosition - SCREEN_Y_BLOCK_PADDING;

    if (x & 0x8000)
    {
        x = 0;
    }
    else
    {
        edge = BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataWidth) - (2 * SCREEN_X_BLOCK_PADDING);
        if (gSamusData.xPosition >= edge)
            x = edge - 1;
    }

    if (y & 0x8000)
    {
        y = 0;
    }
    else
    {
        edge = BLOCK_TO_SUB_PIXEL(gBackgroundsData.clipdataHeight) - (2 * SCREEN_Y_BLOCK_PADDING);
        if (gSamusData.yPosition >= edge)
            y = edge - 1;
    }

    x = SUB_PIXEL_TO_BLOCK(x);
    y = SUB_PIXEL_TO_BLOCK(y);
    x /= SCREEN_SIZE_X_BLOCKS;
    y /= SCREEN_SIZE_Y_BLOCKS;

    if (gMinimapX != x + gCurrentRoomEntry.mapX)
    {
        gMinimapX = x + gCurrentRoomEntry.mapX;
        gMinimapUpdateFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    }

    if (gMinimapY != y + gCurrentRoomEntry.mapY)
    {
        gMinimapY = y + gCurrentRoomEntry.mapY;
        gMinimapUpdateFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    }
}

/**
 * @brief 751c4 | b0 | Updates the minimap when taking a transition
 * 
 */
void MinimapCheckOnTransition(void)
{
    if (gCurrentArea == AREA_MAIN_DECK &&
        gCurrentCutscene != CUTSCENE_NONE && gCurrentCutscene == CUTSCENE_RESTRICTED_LAB_DETACHING)
    {
        // Reload minimap since Restricted Lab is gone
        gPreviousArea = 0x80;
    }

    if (gPreviousArea != gCurrentArea)
    {
        gPreviousArea = gCurrentArea;
        GetMinimapData(gPreviousArea, gMinimapData_Visited);
        DMA3_COPY_16(gMinimapData_Visited, gMinimapData, sizeof(gMinimapData_Visited) / sizeof(u16));

        MinimapSetVisitedTilesAndCollectedItems(gPreviousArea);

        gMinimapX = UCHAR_MAX;
        gMinimapY = UCHAR_MAX;
    }

    gMinimapUpdateFlag = MINIMAP_UPDATE_FLAG_NONE;
    MinimapCheckPositionChanged();

    if (gMinimapUpdateFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
    {
        MinimapSetTileAsExplored();
        MinimapUpdateForExploredTiles();
    }

    gMinimapUpdateFlag = MINIMAP_UPDATE_FLAG_UPPER_LINE;
    MinimapHudDraw();

    gMinimapUpdateFlag = MINIMAP_UPDATE_FLAG_MIDDLE_LINE;
    MinimapHudDraw();
    
    gMinimapUpdateFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    MinimapHudDraw();
}

/**
 * @brief 75274 | f4 | Draws the minimap on the HUD
 * 
 */
void MinimapHudDraw(void)
{
    u16* src;
    u8* dst;
    s32 yOffset;
    s32 xOffset;
    u32 x;
    u32 y;
    u16 mapTile;
    u16* pMapTile;
    u32 flip;
    u32 palette;
    u32 tileOffset;

    if (gMinimapUpdateFlag == MINIMAP_UPDATE_FLAG_NONE)
        return;
    
    src = gMinimapData_Visited;
    dst = gMinimapHudGfx;

    if (gMinimapUpdateFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
        yOffset = 1;
    else if (gMinimapUpdateFlag == MINIMAP_UPDATE_FLAG_MIDDLE_LINE)
        yOffset = 0;
    else if (gMinimapUpdateFlag == MINIMAP_UPDATE_FLAG_UPPER_LINE)
        yOffset = -1;

    dst += (gMinimapUpdateFlag - 1) * (3 * TILE_SIZE);

    for (xOffset = -1; xOffset <= 1; xOffset++)
    {
        x = gMinimapX + xOffset;
        if (x > MINIMAP_DIM - 1)
            x = UCHAR_MAX;

        y = gMinimapY + yOffset;
        if (y > MINIMAP_DIM - 1)
            y = UCHAR_MAX;
        
        if (y == UCHAR_MAX || x == UCHAR_MAX)
        {
            x = MINIMAP_DIM - 1;
            y = MINIMAP_DIM - 1;
        }
        
        pMapTile = &src[(y * MINIMAP_DIM) + x];
        flip = *pMapTile & ((1 << 10) | (1 << 11));
        palette = *pMapTile >> 12;
        tileOffset = (*pMapTile & 0x3FF) * TILE_SIZE;

        if (flip == 0)
            MinimapCopyTileGfx(&dst, &tileOffset, palette);
        else if (flip == (1 << 10))
            MinimapCopyTileXFlippedGfx(&dst, &tileOffset, palette);
        else if (flip == (1 << 11))
            MinimapCopyTileYFlippedGfx(&dst, &tileOffset, palette);
        else // (1 << 10) | (1 << 11)
            MinimapCopyTileXYFlippedGfx(&dst, &tileOffset, palette);
    }
}

/**
 * @brief 75368 | 64 | Copies the graphics of a map tile
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
void MinimapCopyTileGfx(u8** dst, u32* pTile, u8 palette)
{
    u8 value;
    s32 i;
    u8 tile;
    u8 low;

    value = 0;

    for (i = 0; i < TILE_SIZE; i++, (*pTile)++, (*dst)++)
    {
        value = sMinimapTilesGfx[*pTile];
        tile = value;
        value = sMinimapHudColorMapping_High[palette][HIGH_NIBBLE(tile)];
        low = sMinimapHudColorMapping_Low[palette][LOW_NIBBLE(tile)];
        **dst = value | low;
    }
}

/**
 * @brief 753cc | 7c | Copies the graphics of a map tile (X flipped)
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
void MinimapCopyTileXFlippedGfx(u8** dst, u32* pTile, u8 palette)
{
    u8 value;
    s32 i;
    s32 j;
    u8 tile;
    u8 low;

    value = 0;

    for (i = 0; i < TILE_DIM; i++)
    {
        // Start at end of row
        *pTile += TILE_PIXEL_ROW_SIZE - 1;

        for (j = 0; j < TILE_PIXEL_ROW_SIZE; j++, (*dst)++, (*pTile)--)
        {
            value = sMinimapTilesGfx[*pTile];
            tile = value;
            value = sMinimapHudColorMapping_High[palette][LOW_NIBBLE(tile)];
            low = sMinimapHudColorMapping_Low[palette][HIGH_NIBBLE(tile)];
            **dst = value | low;
        }

        // Go to start of next row
        *pTile += TILE_PIXEL_ROW_SIZE + 1;
    }
}

/**
 * @brief 75448 | 7c | Copies the graphics of a map tile (Y flipped)
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
void MinimapCopyTileYFlippedGfx(u8** dst, u32* pTile, u8 palette)
{
    u8 value;
    s32 i;
    s32 j;
    u8 tile;
    u8 low;

    value = 0;
    // Start on last row of tile
    *pTile += TILE_SIZE - TILE_PIXEL_ROW_SIZE;

    for (i = 0; i < TILE_DIM; i++)
    {
        for (j = 0; j < TILE_PIXEL_ROW_SIZE; j++, (*dst)++, (*pTile)++)
        {
            value = sMinimapTilesGfx[*pTile];
            tile = value;
            value = sMinimapHudColorMapping_High[palette][HIGH_NIBBLE(tile)];
            low = sMinimapHudColorMapping_Low[palette][LOW_NIBBLE(tile)];
            **dst = value | low;
        }

        // Go to start of previous row
        *pTile -= 2 * TILE_PIXEL_ROW_SIZE;
    }
}

/**
 * @brief 754c4 | 68 | Copies the graphics of a map tile (X and Y flipped)
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
void MinimapCopyTileXYFlippedGfx(u8** dst, u32* pTile, u8 palette)
{
    u8 value;
    s32 i;
    s32 j;
    u8 tile;
    u8 low;

    value = 0;
    // Start at end of tile
    *pTile += TILE_SIZE - 1;

    for (i = 0; i < TILE_SIZE; i++, (*dst)++, (*pTile)--)
    {
        value = sMinimapTilesGfx[*pTile];
        tile = value;
        value = sMinimapHudColorMapping_High[palette][LOW_NIBBLE(tile)];
        low = sMinimapHudColorMapping_Low[palette][HIGH_NIBBLE(tile)];
        **dst = value | low;
    }
}
