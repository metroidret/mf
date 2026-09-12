#include "data/scroll_data.h"

#include "macros.h"

const u8 sScroll_Empty[11] = {
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX,
    UCHAR_MAX
};

const s8 sBg3LeftToRightMovement[128] = {
    0, 0, 0, 1, 0, 0, 0, 1,
    0, 0, 0, 1, 0, 0, 0, 1,
    0, 0, 0, 1, 0, 0, 0, 1,
    0, 0, 0, 1, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, -1,
    0, 0, 0, -1, 0, 0, 0, -1,
    0, 0, 0, -1, 0, 0, 0, -1,
    0, 0, 0, -1, 0, 0, 0, -1,
    0, 0, 0, -1, 0, 0, 0, -1,
};

const u16 sNightmareShadowPositions[5][2] = {
    {
        BLOCK_TO_SUB_PIXEL(32), BLOCK_TO_SUB_PIXEL(16)
    },
    {
        BLOCK_TO_SUB_PIXEL(40), BLOCK_TO_SUB_PIXEL(10)
    },
    {
        BLOCK_TO_SUB_PIXEL(16), BLOCK_TO_SUB_PIXEL(10)
    },
    {
        BLOCK_TO_SUB_PIXEL(40), BLOCK_TO_SUB_PIXEL(24)
    },
    {
        BLOCK_TO_SUB_PIXEL(16), BLOCK_TO_SUB_PIXEL(24)
    }
};
