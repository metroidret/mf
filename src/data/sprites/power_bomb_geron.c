#include "data/sprites/power_bomb_geron.h"
#include "macros.h"

const u32 sPowerBombGeronGfx[1024] = INCBIN_U32("data/sprites/power_bomb_geron.gfx");
const u16 sPowerBombGeronPal[2 * 16] = INCBIN_U16("data/sprites/power_bomb_geron.pal");

static const u16 sPowerBombGeronStemOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombGeronStemOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombGeronStemOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 532, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombGeronStemOam_Idle_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombGeronStemOam_Destroyed_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_Y_FLIP, 588, 8, 0),
};

static const u16 sPowerBombGeronStemOam_Destroyed_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_32x8, OAM_Y_FLIP, 592, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 528, 8, 0),
};

static const u16 sPowerBombGeronStemOam_Destroyed_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -25, OAM_DIMS_32x8, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-16, 17, OAM_DIMS_32x8, OAM_Y_FLIP, 596, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 532, 8, 0),
};

static const u16 sPowerBombGeronStemOam_Destroyed_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 604, 8, 0),
};

static const u16 sPowerBombGeronStemOam_Destroyed_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 636, 8, 0),
};

static const u16 sPowerBombGeronOam_36179e[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 504, 8, 0),
};

static const u16 sPowerBombGeronOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 9, 0),
};

static const u16 sPowerBombGeronOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 9, 0),
};

static const u16 sPowerBombGeronOam_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 9, 0),
};

static const u16 sPowerBombGeronOam_Idle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 9, 0),
};

const struct FrameData sPowerBombGeronStemOam_Idle[41] = {
    [0] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 5
    },
    [5] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 5
    },
    [6] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 5
    },
    [7] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 5
    },
    [8] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 8
    },
    [9] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 8
    },
    [10] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 8
    },
    [11] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 8
    },
    [12] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 8
    },
    [13] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 8
    },
    [14] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 8
    },
    [15] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 8
    },
    [16] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 10
    },
    [17] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 10
    },
    [18] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 10
    },
    [19] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 10
    },
    [20] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 10
    },
    [21] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 10
    },
    [22] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 10
    },
    [23] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 10
    },
    [24] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 12
    },
    [25] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 12
    },
    [26] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 12
    },
    [27] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 12
    },
    [28] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 14
    },
    [29] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 14
    },
    [30] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 14
    },
    [31] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 14
    },
    [32] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 12
    },
    [33] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 12
    },
    [34] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 12
    },
    [35] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 12
    },
    [36] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame0,
        .timer = 8
    },
    [37] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame1,
        .timer = 8
    },
    [38] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame2,
        .timer = 8
    },
    [39] = {
        .pFrame = sPowerBombGeronStemOam_Idle_Frame3,
        .timer = 8
    },
    [40] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombGeronStemOam_Destroyed[6] = {
    [0] = {
        .pFrame = sPowerBombGeronStemOam_Destroyed_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sPowerBombGeronStemOam_Destroyed_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sPowerBombGeronStemOam_Destroyed_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sPowerBombGeronStemOam_Destroyed_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPowerBombGeronStemOam_Destroyed_Frame4,
        .timer = 1
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombGeronOam_Idle[41] = {
    [0] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 5
    },
    [5] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 5
    },
    [6] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 5
    },
    [7] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 5
    },
    [8] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 8
    },
    [9] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 8
    },
    [10] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 8
    },
    [11] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 8
    },
    [12] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 8
    },
    [13] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 8
    },
    [14] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 8
    },
    [15] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 8
    },
    [16] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 10
    },
    [17] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 10
    },
    [18] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 10
    },
    [19] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 10
    },
    [20] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 10
    },
    [21] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 10
    },
    [22] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 10
    },
    [23] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 10
    },
    [24] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 12
    },
    [25] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 12
    },
    [26] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 12
    },
    [27] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 12
    },
    [28] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 14
    },
    [29] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 14
    },
    [30] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 14
    },
    [31] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 14
    },
    [32] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 12
    },
    [33] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 12
    },
    [34] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 12
    },
    [35] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 12
    },
    [36] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame0,
        .timer = 8
    },
    [37] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame1,
        .timer = 8
    },
    [38] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame2,
        .timer = 8
    },
    [39] = {
        .pFrame = sPowerBombGeronOam_Idle_Frame3,
        .timer = 8
    },
    [40] = FRAME_DATA_TERMINATOR
};
