#include "data/sprites/skree.h"
#include "macros.h"

#define SKREE_FALLING_ACCELERATION (PIXEL_SIZE / 2)

const s16 sSkreeGoingDownYVelocity[] = {
    SKREE_FALLING_ACCELERATION * 1,
    SKREE_FALLING_ACCELERATION * 2,
    SKREE_FALLING_ACCELERATION * 3,
    SKREE_FALLING_ACCELERATION * 4,
    SKREE_FALLING_ACCELERATION * 6,
    SKREE_FALLING_ACCELERATION * 7,
    SKREE_FALLING_ACCELERATION * 8,
    SKREE_FALLING_ACCELERATION * 9,
    SKREE_FALLING_ACCELERATION * 10,
    SKREE_FALLING_ACCELERATION * 11,
    SKREE_FALLING_ACCELERATION * 12,
    SHORT_MAX
};

const u32 sSkreeGfx[512] = INCBIN_U32("data/sprites/skree.gfx");
const u16 sSkreePal[16 * 1] = INCBIN_U16("data/sprites/skree.pal");

static const u16 sSkreeOam_WaitingForX_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sSkreeOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 515, 8, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_X_FLIP, 517, 8, 0),
};

static const u16 sSkreeOam_WaitingForX_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sSkreeOam_WaitingForX_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 523, 8, 0),
};

static const u16 sSkreeOam_WaitingForX_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sSkreeOam_Crashing_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 514, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_XY_FLIP, 514, 8, 0),
};

static const u16 sSkreeOam_Frame_2f912c[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_Y_FLIP, 622, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 515, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 515, 8, 0),
    OAM_ENTRY(-13, -24, OAM_DIMS_8x8, OAM_Y_FLIP, 517, 8, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_8x8, OAM_XY_FLIP, 517, 8, 0),
};

static const u16 sSkreeOam_Crashing_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 520, 8, 0),
};

static const u16 sSkreeOam_Crashing_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 523, 8, 0),
};

static const u16 sSkreeOam_Crashing_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 526, 8, 0),
};

static const u16 sSkreeOam_Frame_2f9176[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 578, 9, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 576, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_X_FLIP, 578, 9, 0),
};

static const u16 sSkreeOam_Frame_2f9190[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 580, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 582, 9, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 580, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_X_FLIP, 582, 9, 0),
};

static const u16 sSkreeOam_Frame_2f91aa[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 584, 9, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 586, 9, 0),
};

static const u16 sSkreeOam_Frame_2f91b8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 588, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 590, 9, 0),
};

static const u16 sSkreeOam_Frame_2f91c6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 576, 9, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 578, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 576, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_XY_FLIP, 578, 9, 0),
};

static const u16 sSkreeOam_Frame_2f91e0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 580, 9, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 582, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 580, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_XY_FLIP, 582, 9, 0),
};

static const u16 sSkreeOam_Frame_2f91fa[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 584, 9, 0),
    OAM_ENTRY(-9, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 586, 9, 0),
};

static const u16 sSkreeOam_Frame_2f9208[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 588, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 590, 9, 0),
};

static const u16 sSkreeOam_Frame_2f9216[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 549, 8, 0),
};


const struct FrameData sSkreeOam_WaitingForX[5] = {
    [0] = {
        .pFrame = sSkreeOam_WaitingForX_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sSkreeOam_WaitingForX_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sSkreeOam_WaitingForX_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sSkreeOam_WaitingForX_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_Idle[3] = {
    [0] = {
        .pFrame = sSkreeOam_WaitingForX_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sSkreeOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_GoingDown[5] = {
    [0] = {
        .pFrame = sSkreeOam_WaitingForX_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSkreeOam_WaitingForX_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSkreeOam_WaitingForX_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSkreeOam_WaitingForX_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSkreeOam_2f9288[5] = {
    [0] = {
        .pFrame = sSkreeOam_Crashing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sSkreeOam_Crashing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sSkreeOam_Crashing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sSkreeOam_Crashing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSkreeOam_2f92b0[3] = {
    [0] = {
        .pFrame = sSkreeOam_Crashing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sSkreeOam_Frame_2f912c,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_Crashing[5] = {
    [0] = {
        .pFrame = sSkreeOam_Crashing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSkreeOam_Crashing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSkreeOam_Crashing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSkreeOam_Crashing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSkreeOam_2f92f0[5] = {
    [0] = {
        .pFrame = sSkreeOam_Frame_2f9176,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sSkreeOam_Frame_2f91aa,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sSkreeOam_WaitingForX_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sSkreeOam_Frame_2f91b8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSkreeOam_2f9318[3] = {
    [0] = {
        .pFrame = sSkreeOam_Frame_2f9176,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sSkreeOam_Frame_2f9190,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSkreeOam_2f9330[5] = {
    [0] = {
        .pFrame = sSkreeOam_Frame_2f9176,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSkreeOam_Frame_2f91aa,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSkreeOam_WaitingForX_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSkreeOam_Frame_2f91b8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSkreeOam_2f9358[5] = {
    [0] = {
        .pFrame = sSkreeOam_Frame_2f91c6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sSkreeOam_Frame_2f91fa,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sSkreeOam_Crashing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sSkreeOam_Frame_2f9208,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSkreeOam_2f9380[3] = {
    [0] = {
        .pFrame = sSkreeOam_Frame_2f91c6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sSkreeOam_Frame_2f91e0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSkreeOam_2f9398[5] = {
    [0] = {
        .pFrame = sSkreeOam_Frame_2f91c6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSkreeOam_Frame_2f91fa,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSkreeOam_Crashing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSkreeOam_Frame_2f9208,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSkreeOam_2f93c0[2] = {
    [0] = {
        .pFrame = sSkreeOam_Frame_2f9216,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
