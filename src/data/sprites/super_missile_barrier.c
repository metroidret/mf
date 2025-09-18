#include "data/sprites/super_missile_barrier.h"
#include "macros.h"

const u32 sSuperMissileBarrierGfx[512] = INCBIN_U32("data/sprites/super_missile_barrier.gfx");
const u16 sSuperMissileBarrierPal[1 * 16] = INCBIN_U16("data/sprites/super_missile_barrier.pal");

static const u16 sSuperMissileBarrierStemOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
};

static const u16 sSuperMissileBarrierStemOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sSuperMissileBarrierStemOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 526, 8, 0),
};

static const u16 sSuperMissileBarrierStemOam_Destroyed_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSuperMissileBarrierStemOam_Destroyed_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSuperMissileBarrierStemOam_Destroyed_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x8, OAM_Y_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSuperMissileBarrierStemOam_Destroyed_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x8, OAM_Y_FLIP, 550, 8, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 550, 8, 0),
};

static const u16 sSuperMissileBarrierOam_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-19, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sSuperMissileBarrierOam_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-19, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSuperMissileBarrierOam_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-19, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sSuperMissileBarrierOam_Idle_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-19, 3, OAM_DIMS_32x8, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
};


const struct FrameData sSuperMissileBarrierStemOam_Idle[5] = {
    [0] = {
        .pFrame = sSuperMissileBarrierStemOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSuperMissileBarrierStemOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSuperMissileBarrierStemOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSuperMissileBarrierStemOam_Idle_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileBarrierStemOam_Destroyed[5] = {
    [0] = {
        .pFrame = sSuperMissileBarrierStemOam_Destroyed_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSuperMissileBarrierStemOam_Destroyed_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sSuperMissileBarrierStemOam_Destroyed_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sSuperMissileBarrierStemOam_Destroyed_Frame3,
        .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileBarrierOam_Idle[5] = {
    [0] = {
        .pFrame = sSuperMissileBarrierOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSuperMissileBarrierOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSuperMissileBarrierOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSuperMissileBarrierOam_Idle_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};
