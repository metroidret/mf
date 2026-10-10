#ifndef MINIMAP_STRUCTS_H
#define MINIMAP_STRUCTS_H

#include "types.h"
#include "macros.h"
#include "gba/memory.h"

/**
 * @brief Number of tiles on one side of a minimap
 */
#define MINIMAP_DIM 32
/**
 * @brief Total number of tiles in a minimap
 */
#define MINIMAP_SIZE (MINIMAP_DIM * MINIMAP_DIM)

#ifdef USE_EWRAM_SYMBOLS
extern u16 gMinimapData_Visited[MINIMAP_SIZE];
extern u16 gMinimapData[MINIMAP_SIZE];
extern u8 gMinimapHudGfx[3 * 3 * TILE_SIZE];
extern u32 gVisitedMinimapTiles[MAX_AMOUNT_OF_AREAS * (MINIMAP_SIZE / 32)];
#else
#define gMinimapData_Visited CAST_TO_ARRAY(u16, [MINIMAP_SIZE], EWRAM_BASE + 0x34000)
#define gMinimapData CAST_TO_ARRAY(u16, [MINIMAP_SIZE], EWRAM_BASE + 0x34800)
#define gMinimapHudGfx CAST_TO_ARRAY(u8, [3 * 3 * TILE_SIZE], EWRAM_BASE + 0x35C00)
#define gVisitedMinimapTiles CAST_TO_ARRAY(u32, [MAX_AMOUNT_OF_AREAS * (MINIMAP_SIZE / 32)], EWRAM_BASE + 0x37C00)
#endif // USE_EWRAM_SYMBOLS

extern u8 gMinimapX; // 3000031
extern u8 gMinimapY; // 3000032

extern u8 gMinimapUpdateFlag;

#endif /* MINIMAP_STRUCTS_H */