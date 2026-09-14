#ifndef BG_CLIP_STRUCT_H
#define BG_CLIP_STRUCT_H

#include "types.h"

#include "constants/connection.h"

// Macros

/**
 * Gets a background block value using `gBackgroundsData` (order is y * width + x)
 */
#define GET_BG_BLOCK(bg, x, y) gBackgroundsData.backgrounds[bg].pDecomp[(y) * gBackgroundsData.backgrounds[bg].width + (x)]
/**
 * Gets a background block value using `gBackgroundsData` (order is width * y + x)
 */
#define GET_BG_BLOCK_(bg, x, y) gBackgroundsData.backgrounds[bg].pDecomp[gBackgroundsData.backgrounds[bg].width * (y) + (x)]
/**
 * Gets a clipdata block value using `gBackgroundsData` (order is y * width + x)
 */
#define GET_CLIP_BLOCK(x, y) gBackgroundsData.pClipDecomp[(y) * gBackgroundsData.clipdataWidth + (x)]
/**
 * Gets a clipdata block value using `gBackgroundsData` (order is width * y + x)
 */
#define GET_CLIP_BLOCK_(x, y) gBackgroundsData.pClipDecomp[gBackgroundsData.clipdataWidth * (y) + (x)]
/**
 * Sets a background block value using `gBackgroundsData` (order is y * width + x)
 */
#define SET_BG_BLOCK(bg, value, x, y) GET_BG_BLOCK(bg, x, y) = value
/**
 * Sets a background block value using `gBackgroundsData` (order is width * y + x)
 */
#define SET_BG_BLOCK_(bg, value, x, y) GET_BG_BLOCK_(bg, x, y) = value
/**
 * Sets a clipdata block value using `gBackgroundsData` (order is y * width + x)
 */
#define SET_CLIP_BLOCK(value, x, y) GET_CLIP_BLOCK(x, y) = value
/**
 * Sets a clipdata block value using `gBackgroundsData` (order is width * y + x)
 */
#define SET_CLIP_BLOCK_(value, x, y) GET_CLIP_BLOCK_(x, y) = value

// Structs

struct BackgroundsData {
    struct {
        u16* pDecomp;
        u16 width;
        u16 height;
    } backgrounds[3];
    u16* pClipDecomp;
    u16 clipdataWidth;
    u16 clipdataHeight;
};

struct LastTankCollected {
    u16 behavior;
    u8 xPosition;
    u8 yPosition;
};

// Globals

#define COLLECTED_TANKS_SIZE 256
#define COLLECTED_TANKS_INFO_SIZE 4
#define MAX_AMOUNT_OF_COLLECTED_TANKS_PER_AREA (COLLECTED_TANKS_SIZE / COLLECTED_TANKS_INFO_SIZE)

#ifdef USE_EWRAM_SYMBOLS
extern u8 gCollectedTanks[MAX_AMOUNT_OF_AREAS][COLLECTED_TANKS_SIZE];
#else
#define gCollectedTanks CAST_TO_ARRAY(u8, [MAX_AMOUNT_OF_AREAS][COLLECTED_TANKS_SIZE], EWRAM_BASE + 0x37200)
#endif // USE_EWRAM_SYMBOLS

extern bools8 gCollectingTank;
extern u8 gNumberOfCollectedTanks[MAX_AMOUNT_OF_AREAS];

extern struct BackgroundsData gBackgroundsData;

extern struct LastTankCollected gLastTankCollected;

#endif /* BG_CLIP_STRUCT_H */
