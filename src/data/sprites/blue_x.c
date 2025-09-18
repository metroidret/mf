#include "data/sprites/blue_x.h"
#include "macros.h"

const s16 sBlueXIdleYMovement[65] = {
     0,  0,  0,  0,
     1,  1,  1,  1,
     2,  2,  2,  2,
     3,  3,  3,  3,
     3,  3,  3,  3,
     2,  2,  2,  2,
     1,  1,  1,  1,
     0,  0,  0,  0,
     0,  0,  0,  0,
    -1, -1, -1, -1,
    -2, -2, -2, -2,
    -3, -3, -3, -3,
    -3, -3, -3, -3,
    -2, -2, -2, -2,
    -1, -1, -1, -1,
     0, 0, 0, 0,
     SHORT_MAX
};

const s16 sBlueXIdleXMovement[81] = {
     0,  0,  1,  1,
     2,  2,  3,  3,
     4,  4,  5,  5,
     6,  6,  7,  7,
     7,  7,  8,  8,
     8,  8,  7,  7,
     7,  7,  6,  6,
     5,  5,  4,  4,
     3,  3,  2,  2,
     1,  1,  0,  0,
     0,  0, -1, -1,
    -2, -2, -3, -3,
    -4, -4, -5, -5,
    -6, -6, -7, -7,
    -7, -7, -8, -8,
    -8, -8, -7, -7,
    -7, -7, -6, -6,
    -5, -5, -4, -4,
    -3, -3, -2, -2,
    -1, -1,  0,  0,
     SHORT_MAX
};

const u32 sBlueXGfx[1024] = INCBIN_U32("data/sprites/blue_x.gfx");
const u16 sBlueXPal[2 * 16] = INCBIN_U16("data/sprites/blue_x.pal");

static const u16 sBlueXOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sBlueXOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sBlueXOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sBlueXOam_Moving_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sBlueXOam_Moving_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sBlueXOam_Moving_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sBlueXOam_Frame_35ef08[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 601, 8, 0),
};

static const u16 sBlueXOam_Frame_35ef10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 602, 8, 0),
};

static const u16 sBlueXOam_Frame_35ef18[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 603, 8, 0),
};

static const u16 sBlueXOam_Frame_35ef20[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sBlueXOam_Frame_35ef28[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
};

static const u16 sBlueXOam_Frame_35ef30[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
};

static const u16 sBlueXOam_Frame_35ef38[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_Absorbing_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 601, 8, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 536, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 536, 8, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_Absorbing_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(14, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 602, 8, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 601, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 538, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 538, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_Absorbing_Frame8[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 603, 8, 0),
    OAM_ENTRY(-21, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 602, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 540, 8, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(14, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_Absorbing_Frame12[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(6, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 603, 8, 0),
    OAM_ENTRY(-20, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 601, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 542, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 542, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 542, 8, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(14, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(-21, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_Absorbing_Frame16[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(3, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(-15, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 602, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 536, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 536, 8, 0),
    OAM_ENTRY(-20, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(14, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-21, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_Absorbing_Frame20[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(-11, 11, OAM_DIMS_8x8, OAM_NO_FLIP, 603, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 538, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 538, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 538, 8, 0),
    OAM_ENTRY(-20, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(14, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(-21, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_Absorbing_Frame24[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-8, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 540, 8, 0),
    OAM_ENTRY(-20, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-21, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_Absorbing_Frame28[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-5, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 542, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 542, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 542, 8, 0),
    OAM_ENTRY(-20, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_FadingAway_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 536, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 536, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 536, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_FadingAway_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 538, 8, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_XY_FLIP, 538, 8, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 538, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_FadingAway_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 540, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 540, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_FadingAway_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_X_FLIP, 635, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 635, 8, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 635, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_FadingAway_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x8, OAM_X_FLIP, 636, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_FadingAway_Frame10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 636, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_FadingAway_Frame12[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_X_FLIP, 636, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_FadingAway_Frame14[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(-1, -5, OAM_DIMS_8x8, OAM_X_FLIP, 636, 8, 0),
};

static const u16 sBlueXAbsorbtionOam_Absorbing_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 600, 8, 0),
};


const struct FrameData sBlueXOam_Moving[7] = {
    [0] = {
        .pFrame = sBlueXOam_Moving_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sBlueXOam_Moving_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sBlueXOam_Moving_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sBlueXOam_Moving_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sBlueXOam_Moving_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sBlueXOam_Moving_Frame5,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBlueXOam_Idle[7] = {
    [0] = {
        .pFrame = sBlueXOam_Moving_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sBlueXOam_Moving_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sBlueXOam_Moving_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sBlueXOam_Moving_Frame3,
        .timer = 10
    },
    [4] = {
        .pFrame = sBlueXOam_Moving_Frame4,
        .timer = 10
    },
    [5] = {
        .pFrame = sBlueXOam_Moving_Frame5,
        .timer = 10
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBlueXAbsorbtionOam_Absorbing[33] = {
    [0] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame4,
        .timer = 1
    },
    [7] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame12,
        .timer = 1
    },
    [15] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [16] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [18] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [20] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame20,
        .timer = 1
    },
    [21] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [22] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame20,
        .timer = 1
    },
    [23] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [24] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [26] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [28] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame28,
        .timer = 1
    },
    [29] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [30] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame28,
        .timer = 1
    },
    [31] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [32] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBlueXAbsorbtionOam_FadingAway[16] = {
    [0] = {
        .pFrame = sBlueXAbsorbtionOam_FadingAway_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sBlueXAbsorbtionOam_FadingAway_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sBlueXAbsorbtionOam_FadingAway_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sBlueXAbsorbtionOam_FadingAway_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sBlueXAbsorbtionOam_FadingAway_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sBlueXAbsorbtionOam_FadingAway_Frame10,
        .timer = 1
    },
    [11] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sBlueXAbsorbtionOam_FadingAway_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sBlueXAbsorbtionOam_Absorbing_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sBlueXAbsorbtionOam_FadingAway_Frame14,
        .timer = 1
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBlueXOam_Stunned[5] = {
    [0] = {
        .pFrame = sBlueXOam_Moving_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sBlueXOam_Moving_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sBlueXOam_Moving_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sBlueXOam_Moving_Frame1,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};
