#include "data/sprites/reo.h"
#include "macros.h"

const s16 sReoIdleYMovement[49] = {
    0, 0, 0, 0,
    1, 0, 1, 0,
    1, 2, 3, 4,
    3, 2, 1, 0,
    1, 0, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    -1, 0, -1, 0,
    -1, -2, -3, -4,
    -3, -2, -1, 0,
    -1, 0, -1, 0,
    0, 0, 0, 0,
    SHORT_MAX
};

const s16 sReoGoingDownYSpeed[12] = {
    1, 1, 2, 2,
    3, 3, 4, 4,
    5, 5, 6, SHORT_MAX
};

const s16 sReoSlidingYSpeed[16] = {
    5, 5, 5, 5,
    4, 4, 4, 4,
    3, 3, 3, 2,
    2, 2, 1, SHORT_MAX
};

const s16 sReoGoingUpAcceleratingYSpeed[12] = {
    -1, -1, -2, -2,
    -3, -3, -4, -4,
    -5, -5, -6, SHORT_MAX
};

const s16 sReoGoingUpDeceleratingYSpeed[16] = {
    -5, -5, -5, -5,
    -4, -4, -4, -4,
    -3, -3, -3, -2,
    -2, -2, -1, SHORT_MAX
};

const u32 sReoGfx[1 * 512] = INCBIN_U32("data/sprites/reo.gfx");
const u16 sReoPal[1 * 16] = INCBIN_U16("data/sprites/reo.pal");

static const u16 sReoOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-18, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
};

static const u16 sReoOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x201, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x201, 8, 0),
};

static const u16 sReoOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
};

static const u16 sReoWingsOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-1, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x203, 8, 0),
};

static const u16 sReoWingsOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-1, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
};

static const u16 sReoWingsOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-1, -19, OAM_DIMS_16x8, OAM_X_FLIP, 0x227, 8, 0),
};

static const u16 sReoOam_Falling_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-17, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-1, -19, OAM_DIMS_16x8, OAM_X_FLIP, 0x227, 8, 0),
};

static const u16 sReoOam_Falling_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-1, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-1, -19, OAM_DIMS_16x8, OAM_X_FLIP, 0x227, 8, 0),
};

static const u16 sReoOam_Falling_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-2, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-15, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-2, -19, OAM_DIMS_16x8, OAM_X_FLIP, 0x227, 8, 0),
};

const struct FrameData sReoOam_Idle[5] = {
    [0] = {
        .pFrame = sReoOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sReoOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sReoOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sReoOam_Idle_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoWingsOam_Idle[5] = {
    [0] = {
        .pFrame = sReoWingsOam_Idle_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sReoWingsOam_Idle_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sReoWingsOam_Idle_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sReoWingsOam_Idle_Frame1,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOam_Falling[4] = {
    [0] = {
        .pFrame = sReoOam_Falling_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sReoOam_Falling_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sReoOam_Falling_Frame2,
        .timer = 255
    },
    [3] = FRAME_DATA_TERMINATOR
};
