#include "data/sprites/skultera.h"
#include "macros.h"

const u32 sSkulteraGfx[2 * 512] = INCBIN_U32("data/sprites/skultera.gfx");
const u16 sSkulteraPal[2 * 16] = INCBIN_U16("data/sprites/skultera.pal");

static const u16 sSkulteraOam_IdleSmall_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-14, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-14, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-2, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
};

static const u16 sSkulteraOam_IdleSmall_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-14, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-14, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 8, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sSkulteraOam_IdleSmall_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-14, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-14, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(3, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x205, 8, 0),
};

static const u16 sSkulteraOam_TurningAroundSmall_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-14, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-14, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 8, 0),
    OAM_ENTRY(-2, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sSkulteraOam_TurningAroundSmall_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-13, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-13, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 8, 0),
    OAM_ENTRY(1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sSkulteraOam_TurningAroundSmall_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-14, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x266, 8, 0),
    OAM_ENTRY(-2, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x205, 8, 0),
};

static const u16 sSkulteraOam_TurningAroundSmall_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_16x8, OAM_X_FLIP, 0x264, 8, 0),
    OAM_ENTRY(-18, -13, OAM_DIMS_8x8, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
};

static const u16 sSkulteraOam_TurningAroundSmall_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-12, -6, OAM_DIMS_16x8, OAM_X_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_8x8, OAM_X_FLIP, 0x201, 8, 0),
};

static const u16 sSkulteraOam_TurningAroundSmall_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-9, -6, OAM_DIMS_16x8, OAM_X_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-13, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-15, -13, OAM_DIMS_8x8, OAM_X_FLIP, 0x200, 8, 0),
};

static const u16 sSkulteraOam_TurningAroundSmall_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-5, -6, OAM_DIMS_16x8, OAM_X_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-9, -13, OAM_DIMS_8x8, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x204, 8, 0),
};

static const u16 sSkulteraOam_TurningAroundSmall_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-1, -6, OAM_DIMS_16x8, OAM_X_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-5, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-10, -13, OAM_DIMS_8x8, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x205, 8, 0),
};

static const u16 sSkulteraOam_IdleLarge_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-18, -30, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-5, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 9, 0),
    OAM_ENTRY(10, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 9, 0),
};

static const u16 sSkulteraOam_IdleLarge_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-26, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20b, 9, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 9, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 9, 0),
};

static const u16 sSkulteraOam_IdleLarge_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-26, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20b, 9, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sSkulteraOam_IdleLarge_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-26, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20b, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 9, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 9, 0),
};

static const u16 sSkulteraOam_TurningAroundLarge_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-26, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20b, 9, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 9, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 9, 0),
};

static const u16 sSkulteraOam_TurningAroundLarge_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-14, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20f, 9, 0),
    OAM_ENTRY(-7, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 9, 0),
    OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 9, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 9, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sSkulteraOam_TurningAroundLarge_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x211, 9, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(-9, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x253, 9, 0),
    OAM_ENTRY(-2, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(3, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sSkulteraOam_TurningAroundLarge_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -31, OAM_DIMS_16x32, OAM_X_FLIP, 0x20f, 9, 0),
    OAM_ENTRY(-15, -39, OAM_DIMS_8x8, OAM_X_FLIP, 0x213, 9, 0),
    OAM_ENTRY(-24, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x233, 9, 0),
    OAM_ENTRY(-19, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-3, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 9, 0),
};

static const u16 sSkulteraOam_TurningAroundLarge_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -39, OAM_DIMS_8x8, OAM_X_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-16, -31, OAM_DIMS_32x32, OAM_X_FLIP, 0x20b, 9, 0),
    OAM_ENTRY(-18, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x201, 9, 0),
};

static const u16 sSkulteraOam_TurningAroundLarge_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-21, -30, OAM_DIMS_32x32, OAM_X_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-10, -38, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x202, 9, 0),
    OAM_ENTRY(-18, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x200, 9, 0),
};

static const u16 sSkulteraOam_TurningAroundLarge_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -39, OAM_DIMS_8x8, OAM_X_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-10, -31, OAM_DIMS_32x32, OAM_X_FLIP, 0x20b, 9, 0),
    OAM_ENTRY(-12, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-17, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x202, 9, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x204, 9, 0),
};

static const u16 sSkulteraOam_TurningAroundLarge_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -39, OAM_DIMS_8x8, OAM_X_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-6, -31, OAM_DIMS_32x32, OAM_X_FLIP, 0x20b, 9, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x202, 9, 0),
    OAM_ENTRY(-13, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-18, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x205, 9, 0),
};

const struct FrameData sSkulteraOam_IdleSmall[4] = {
    [0] = {
        .pFrame = sSkulteraOam_IdleSmall_Frame0,
        .timer = 14
    },
    [1] = {
        .pFrame = sSkulteraOam_IdleSmall_Frame1,
        .timer = 14
    },
    [2] = {
        .pFrame = sSkulteraOam_IdleSmall_Frame2,
        .timer = 14
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkulteraOam_TurningAroundSmall[9] = {
    [0] = {
        .pFrame = sSkulteraOam_TurningAroundSmall_Frame0,
        .timer = 13
    },
    [1] = {
        .pFrame = sSkulteraOam_TurningAroundSmall_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sSkulteraOam_TurningAroundSmall_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSkulteraOam_TurningAroundSmall_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sSkulteraOam_TurningAroundSmall_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sSkulteraOam_TurningAroundSmall_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sSkulteraOam_TurningAroundSmall_Frame6,
        .timer = 10
    },
    [7] = {
        .pFrame = sSkulteraOam_TurningAroundSmall_Frame7,
        .timer = 13
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkulteraOam_ChasingSmall[4] = {
    [0] = {
        .pFrame = sSkulteraOam_IdleSmall_Frame0,
        .timer = 9
    },
    [1] = {
        .pFrame = sSkulteraOam_IdleSmall_Frame1,
        .timer = 9
    },
    [2] = {
        .pFrame = sSkulteraOam_IdleSmall_Frame2,
        .timer = 9
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkulteraOam_IdleLarge[5] = {
    [0] = {
        .pFrame = sSkulteraOam_IdleLarge_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sSkulteraOam_IdleLarge_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sSkulteraOam_IdleLarge_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sSkulteraOam_IdleLarge_Frame3,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkulteraOam_TurningAroundLarge[9] = {
    [0] = {
        .pFrame = sSkulteraOam_TurningAroundLarge_Frame0,
        .timer = 13
    },
    [1] = {
        .pFrame = sSkulteraOam_TurningAroundLarge_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sSkulteraOam_TurningAroundLarge_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSkulteraOam_TurningAroundLarge_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sSkulteraOam_TurningAroundLarge_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sSkulteraOam_TurningAroundLarge_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sSkulteraOam_TurningAroundLarge_Frame6,
        .timer = 10
    },
    [7] = {
        .pFrame = sSkulteraOam_TurningAroundLarge_Frame7,
        .timer = 13
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkulteraOam_ChasingLarge[5] = {
    [0] = {
        .pFrame = sSkulteraOam_IdleLarge_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSkulteraOam_IdleLarge_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSkulteraOam_IdleLarge_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSkulteraOam_IdleLarge_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};
