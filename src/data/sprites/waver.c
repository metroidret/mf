#include "data/sprites/waver.h"
#include "macros.h"

const s16 sWaverDebrisFallingSpeed[30] = {
    -4, -4, -3, -3,
    -2, -2, -1, -1,
    0, 0, 1, 1,
    2, 2, 3, 3,
    4, 4, 5, 5,
    6, 6, 7, 7,
    8, 8, 9, 9,
    10, SHORT_MAX
};

const s16 sWaverFlyingYMovement[12] = {
    0, 1, 2, 3,
    4, 4, 4, 4,
    3, 2, 1, 0
};

const u32 sWaverGfc[2 * 512] = INCBIN_U32("data/sprites/waver.gfx");
const u16 sWaverPal[2 * 16] = INCBIN_U16("data/sprites/waver.pal");

static const u16 sWaverDebrisOam_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-1, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x241, 8, 0),
};

static const u16 sWaverDebrisOam_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-5, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 8, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x241, 8, 0),
};

static const u16 sWaverDebrisOam_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-13, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x241, 8, 0),
};

static const u16 sWaverDebrisOam_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x223, 8, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-10, -13, OAM_DIMS_8x8, OAM_X_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-2, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
};

static const u16 sOam_31752e[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x263, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20E, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20C, 8, 0),
};

static const u16 sWaverOam_BackingOut_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x210, 9, 0),
};

static const u16 sWaverOam_FlyingDown_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x214, 9, 0),
};

static const u16 sWaverOam_FlyingDown_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(-16, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x244, 9, 0),
};

static const u16 sWaverOam_FlyingDown_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24C, 9, 0),
};

static const u16 sWaverOam_FlyingDown_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x218, 9, 0),
};

static const u16 sWaverOam_FlyingDown_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x21C, 9, 0),
};

const struct FrameData sWaverOam_FlyingUp[2] = {
    [0] = {
        .pFrame = sWaverOam_FlyingDown_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaverOam_FlyingDown[6] = {
    [0] = {
        .pFrame = sWaverOam_FlyingDown_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sWaverOam_FlyingDown_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sWaverOam_FlyingDown_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sWaverOam_FlyingDown_Frame3,
        .timer = 10
    },
    [4] = {
        .pFrame = sWaverOam_FlyingDown_Frame4,
        .timer = 10
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaverOam_BackingOut[3] = {
    [0] = {
        .pFrame = sWaverOam_FlyingDown_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sWaverOam_BackingOut_Frame1,
        .timer = 10
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaverOam_Charging[6] = {
    [0] = {
        .pFrame = sWaverOam_FlyingDown_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sWaverOam_FlyingDown_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sWaverOam_FlyingDown_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sWaverOam_FlyingDown_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sWaverOam_FlyingDown_Frame4,
        .timer = 4
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaverDebrisOam[5] = {
    [0] = {
        .pFrame = sWaverDebrisOam_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sWaverDebrisOam_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sWaverDebrisOam_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sWaverDebrisOam_Frame3,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};
