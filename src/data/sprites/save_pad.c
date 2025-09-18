#include "data/sprites/save_pad.h"
#include "macros.h"

const s16 sSavePlatformFloatingYMovement[49] = {
     0,  0,  0,  0,
     1,  0,  1,  0,
     1,  1,  2,  2,
     2,  1,  1,  0,
     1,  0,  1,  0,
     0,  0,  0,  0,
     0,  0,  0,  0,
    -1,  0, -1,  0,
    -1, -1, -2, -2,
    -2, -1, -1,  0,
    -1,  0, -1,  0,
     0,  0,  0,  0,
     SHORT_MAX
};

const u32 sSavePadGfx[3 * 512] = INCBIN_U32("data/sprites/save_pad.gfx");
const u16 sSavePadPal[3 * 16] = INCBIN_U16("data/sprites/save_pad.pal");

static const u16 sSavePlatformOam_Floating_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sSavePlatformOam_Floating_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
};

static const u16 sSavePlatformOam_Floating_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 553, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_X_FLIP, 553, 8, 0),
};

static const u16 sSavePlatformOam_Floating_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
};

static const u16 sSavePadOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 515, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 517, 8, 0),
};

static const u16 sSavePadOam_LockedIn_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 547, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 549, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 547, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 549, 8, 0),
};

static const u16 sSavePadOam_LockedIn_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 518, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
};

static const u16 sSavePadOam_LockedIn_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 550, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 552, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 550, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 552, 8, 0),
};

static const u16 sSavePadOam_Frame_2f13cc[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 555, 8, 0),
};

static const u16 sSavePadHologramOam_Opening_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sSavePadHologramOam_Opening_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(16, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-32, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSavePadHologramOam_Opening_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-32, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(16, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 568, 8, 0),
};

static const u16 sSavePadHologramOam_Opening_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-32, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(16, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSavePadHologramOam_Opening_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(16, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-5, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(3, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-13, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
};

static const u16 sSavePadHologramOam_Flashing_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(16, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-13, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-5, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(3, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 529, 8, 0),
};

static const u16 sSavePadHologramOam_Flashing_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sSavePadOam_Disabled_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 515, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 517, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};


const struct FrameData sSavePlatformOam_Floating[7] = {
    [0] = {
        .pFrame = sSavePlatformOam_Floating_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSavePlatformOam_Floating_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSavePlatformOam_Floating_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSavePlatformOam_Floating_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sSavePlatformOam_Floating_Frame2,
        .timer = 8
    },
    [5] = {
        .pFrame = sSavePlatformOam_Floating_Frame1,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePadOam_Idle[2] = {
    [0] = {
        .pFrame = sSavePadOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePadOam_2f14d4[2] = {
    [0] = {
        .pFrame = sSavePadOam_Frame_2f13cc,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePadOam_LockedIn[6] = {
    [0] = {
        .pFrame = sSavePadOam_LockedIn_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSavePadOam_LockedIn_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSavePadOam_LockedIn_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSavePadOam_LockedIn_Frame1,
        .timer = 8
    },
    [4] = {
        .pFrame = sSavePadOam_LockedIn_Frame0,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePadHologramOam_Opening[6] = {
    [0] = {
        .pFrame = sSavePadHologramOam_Opening_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sSavePadHologramOam_Opening_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sSavePadHologramOam_Opening_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sSavePadHologramOam_Opening_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sSavePadHologramOam_Opening_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePadHologramOam_Closing[6] = {
    [0] = {
        .pFrame = sSavePadHologramOam_Opening_Frame4,
        .timer = 3
    },
    [1] = {
        .pFrame = sSavePadHologramOam_Opening_Frame3,
        .timer = 3
    },
    [2] = {
        .pFrame = sSavePadHologramOam_Opening_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sSavePadHologramOam_Opening_Frame1,
        .timer = 3
    },
    [4] = {
        .pFrame = sSavePadHologramOam_Opening_Frame0,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePadHologramOam_Flashing[3] = {
    [0] = {
        .pFrame = sSavePadHologramOam_Flashing_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSavePadHologramOam_Flashing_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePadOam_Disabled[2] = {
    [0] = {
        .pFrame = sSavePadOam_Disabled_Frame0,
        .timer = UCHAR_MAX
    }
};
