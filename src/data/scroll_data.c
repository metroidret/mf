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

// TODO: Move these

static const u8 sBlob_3c92d0_3c94d0[] = INCBIN_U8("data/Blob_3c92d0_3c94d0.bin");

const s8 sEndingSamusPosingSineTable[128] = {
    0, 6, 12, 19, 25, 31, 37, 43,
    49, 54, 60, 65, 71, 76, 81, 85,
    90, 94, 98, 102, 106, 109, 112, 115,
    117, 120, 122, 123, 125, 126, 126, 127,
    127, 127, 126, 126, 125, 123, 122, 120,
    117, 115, 112, 109, 106, 102, 98, 94,
    90, 85, 81, 76, 71, 65, 60, 54,
    49, 43, 37, 31, 25, 19, 12, 6,
    0, -6, -12, -19, -25, -31, -37, -43,
    -49, -54, -60, -65, -71, -76, -81, -85,
    -90, -94, -98, -102, -106, -109, -112, -115,
    -117, -120, -122, -123, -125, -126, -126, -127,
    -127, -127, -126, -126, -125, -123, -122, -120,
    -117, -115, -112, -109, -106, -102, -98, -94,
    -90, -85, -81, -76, -71, -65, -60, -54,
    -49, -43, -37, -31, -25, -19, -12, -6,
};

static const u8 sBlob_3c9550_3e392c[] = INCBIN_U8("data/Blob_3c9550_3e392c.bin");
