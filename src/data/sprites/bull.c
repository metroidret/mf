#include "data/sprites/bull.h"
#include "macros.h"

const u32 sBullGfx[512 * 1] = INCBIN_U32("data/sprites/bull.gfx");
const u16 sBullPal[16 * 1] = INCBIN_U16("data/sprites/bull.pal");

static const u16 sBullOam_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-12, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-12, -3, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
};

static const u16 sBullOam_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-4, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-12, -2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sBullOam_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20f, 8, 0),
};

static const u16 sBullSmokeOam_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-18, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(10, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-15, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(5, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
};

static const u16 sBullSmokeOam_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-25, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -17, OAM_DIMS_8x8, OAM_XY_FLIP, 0x210, 8, 0),
    OAM_ENTRY(11, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(10, -15, OAM_DIMS_8x8, OAM_Y_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-22, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-15, 9, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(5, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sBullSmokeOam_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-30, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-18, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(14, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(10, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-27, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-15, 9, OAM_DIMS_8x8, OAM_Y_FLIP, 0x230, 8, 0),
    OAM_ENTRY(9, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(5, 9, OAM_DIMS_8x8, OAM_XY_FLIP, 0x230, 8, 0),
};

static const u16 sBullSmokeOam_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-37, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(21, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-34, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sBullSmokeOam_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-37, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(21, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-34, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(16, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sBullSmokeOam_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-33, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(25, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-30, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(20, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
};

static const u16 sBullSmokeOam_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-33, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(25, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-30, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(20, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
};

static const u16 sBullSmokeOam_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-33, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(25, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-30, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(20, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
};

const struct FrameData sBullOam[5] = {
    [0] = {
        .pFrame = sBullOam_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sBullOam_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sBullOam_Frame0,
        .timer = 8
    },
    [3] = {
        .pFrame = sBullOam_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBullSmokeOam[9] = {
    [0] = {
        .pFrame = sBullSmokeOam_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sBullSmokeOam_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sBullSmokeOam_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sBullSmokeOam_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sBullSmokeOam_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sBullSmokeOam_Frame5,
        .timer = 7
    },
    [6] = {
        .pFrame = sBullSmokeOam_Frame6,
        .timer = 5
    },
    [7] = {
        .pFrame = sBullSmokeOam_Frame7,
        .timer = 5
    },
    [8] = FRAME_DATA_TERMINATOR
};
