#include "data/sprites/missile_geron.h"

const u32 sMissileGeronGfx[512 * 1] = INCBIN_U32("data/sprites/missile_geron.gfx");
const u16 sMissileGeronPal[16 * 1] = INCBIN_U16("data/sprites/missile_geron.pal");

static const u16 sMissileGeronStemOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x200, 8, 0),
};

static const u16 sMissileGeronStemOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20a, 8, 0),
};

static const u16 sMissileGeronStemOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
};

static const u16 sMissileGeronStemOam_Destroyed_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sMissileGeronStemOam_Destroyed_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sMissileGeronStemOam_Destroyed_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x8, OAM_Y_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sMissileGeronStemOam_Destroyed_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x8, OAM_Y_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
};

static const u16 sMissileGeronOam_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-19, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sMissileGeronOam_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-19, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sMissileGeronOam_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-19, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sMissileGeronOam_Idle_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-19, 3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

const struct FrameData sMissileGeronStemOam_Idle[5] = {
    [0] = {
        .pFrame = sMissileGeronStemOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sMissileGeronStemOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sMissileGeronStemOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sMissileGeronStemOam_Idle_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileGeronStemOam_Destroyed[5] = {
    [0] = {
        .pFrame = sMissileGeronStemOam_Destroyed_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sMissileGeronStemOam_Destroyed_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sMissileGeronStemOam_Destroyed_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sMissileGeronStemOam_Destroyed_Frame3,
        .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileGeronOam_Idle[5] = {
    [0] = {
        .pFrame = sMissileGeronOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sMissileGeronOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sMissileGeronOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sMissileGeronOam_Idle_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};
