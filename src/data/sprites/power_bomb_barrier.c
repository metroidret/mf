#include "data/sprites/power_bomb_barrier.h"
#include "macros.h"

const u32 sPowerBombBarrierGfx[1024] = INCBIN_U32("data/sprites/power_bomb_barrier.gfx");
const u16 sPowerBombBarrierPal[2 * 16] = INCBIN_U16("data/sprites/power_bomb_barrier.pal");

static const u16 sPowerBombBarrierStemOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombBarrierStemOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombBarrierStemOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 532, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombBarrierStemOam_Idle_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombBarrierStemOam_Destroyed_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombBarrierStemOam_Destroyed_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_32x8, OAM_Y_FLIP, 592, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 528, 8, 0),
};

static const u16 sPowerBombBarrierStemOam_Destroyed_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -25, OAM_DIMS_32x8, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-16, 17, OAM_DIMS_32x8, OAM_Y_FLIP, 596, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 532, 8, 0),
};

static const u16 sPowerBombBarrierStemOam_Destroyed_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 604, 8, 0),
};

static const u16 sPowerBombBarrierStemOam_Destroyed_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 636, 8, 0),
};

static const u16 sPowerBombBarrierOam_36179e[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 504, 8, 0),
};

static const u16 sPowerBombBarrierOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 9, 0),
};

static const u16 sPowerBombBarrierOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 9, 0),
};

static const u16 sPowerBombBarrierOam_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 9, 0),
};

static const u16 sPowerBombBarrierOam_Idle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 9, 0),
};

const struct FrameData sPowerBombBarrierStemOam_Idle[41] = {
    [0] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 5
    },
    [5] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 5
    },
    [6] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 5
    },
    [7] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 5
    },
    [8] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 8
    },
    [9] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 8
    },
    [10] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 8
    },
    [11] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 8
    },
    [12] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 8
    },
    [13] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 8
    },
    [14] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 8
    },
    [15] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 8
    },
    [16] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 10
    },
    [17] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 10
    },
    [18] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 10
    },
    [19] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 10
    },
    [20] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 10
    },
    [21] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 10
    },
    [22] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 10
    },
    [23] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 10
    },
    [24] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 12
    },
    [25] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 12
    },
    [26] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 12
    },
    [27] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 12
    },
    [28] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 14
    },
    [29] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 14
    },
    [30] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 14
    },
    [31] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 14
    },
    [32] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 12
    },
    [33] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 12
    },
    [34] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 12
    },
    [35] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 12
    },
    [36] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame0,
        .timer = 8
    },
    [37] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame1,
        .timer = 8
    },
    [38] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame2,
        .timer = 8
    },
    [39] = {
        .pFrame = sPowerBombBarrierStemOam_Idle_Frame3,
        .timer = 8
    },
    [40] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombBarrierStemOam_Destroyed[6] = {
    [0] = {
        .pFrame = sPowerBombBarrierStemOam_Destroyed_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sPowerBombBarrierStemOam_Destroyed_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sPowerBombBarrierStemOam_Destroyed_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sPowerBombBarrierStemOam_Destroyed_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPowerBombBarrierStemOam_Destroyed_Frame4,
        .timer = 1
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombBarrierOam_Idle[41] = {
    [0] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 5
    },
    [5] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 5
    },
    [6] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 5
    },
    [7] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 5
    },
    [8] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 8
    },
    [9] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 8
    },
    [10] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 8
    },
    [11] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 8
    },
    [12] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 8
    },
    [13] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 8
    },
    [14] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 8
    },
    [15] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 8
    },
    [16] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 10
    },
    [17] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 10
    },
    [18] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 10
    },
    [19] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 10
    },
    [20] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 10
    },
    [21] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 10
    },
    [22] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 10
    },
    [23] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 10
    },
    [24] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 12
    },
    [25] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 12
    },
    [26] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 12
    },
    [27] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 12
    },
    [28] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 14
    },
    [29] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 14
    },
    [30] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 14
    },
    [31] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 14
    },
    [32] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 12
    },
    [33] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 12
    },
    [34] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 12
    },
    [35] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 12
    },
    [36] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame0,
        .timer = 8
    },
    [37] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame1,
        .timer = 8
    },
    [38] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame2,
        .timer = 8
    },
    [39] = {
        .pFrame = sPowerBombBarrierOam_Idle_Frame3,
        .timer = 8
    },
    [40] = FRAME_DATA_TERMINATOR
};
