#include "data/sprites/security_pad.h"
#include "macros.h"

const u32 sSecurityPadGfx[3 * 512] = INCBIN_U32("data/sprites/security_pad.gfx");
const u16 sSecurityPadPal[3 * 16] = INCBIN_U16("data/sprites/security_pad.pal");

static const u16 sSecurityPadMonitorOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-19, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 597, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 599, 8, 0),
};

static const u16 sSecurityPadMonitorOam_ArmExtending_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-19, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 597, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 599, 8, 0),
    OAM_ENTRY(10, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 592, 8, 0),
};

static const u16 sSecurityPadMonitorOam_ArmExtending_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-19, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 597, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 599, 8, 0),
    OAM_ENTRY(12, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 593, 8, 0),
};

static const u16 sSecurityPadMonitorOam_ArmExtending_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-19, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 597, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 599, 8, 0),
    OAM_ENTRY(14, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 594, 8, 0),
    OAM_ENTRY(6, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 596, 8, 0),
};

static const u16 sSecurityPadMonitorOam_ArmExtending_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-19, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 597, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 599, 8, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 595, 8, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 596, 8, 0),
};

static const u16 sSecurityPadMonitorOam_ArmRetracting_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-19, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 597, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 599, 8, 0),
    OAM_ENTRY(17, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(9, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 596, 8, 0),
};

static const u16 sSecurityPadScreenOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sSecurityPadScreenOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sSecurityPadScreenOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sSecurityPadScreenOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sSecurityPadScreenOam_Unlocking_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sSecurityPadScreenOam_Unlocking_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sSecurityPadScreenOam_Unlocking_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityPadScreenOam_Unlocking_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sSecurityPadScreenOam_Inactive_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityPadScreenOam_Inactive_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(5, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 515, 8, 0),
};

static const u16 sSecurityPadScreenOam_Inactive_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 574, 8, 0),
    OAM_ENTRY(5, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 515, 8, 0),
};

static const u16 sSecurityPadScreenOam_Inactive_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(5, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(-3, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityPadOam_Idle_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 581, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 583, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 581, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 583, 9, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 640, 9, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 577, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 579, 9, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 577, 9, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 640, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 590, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 520, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 522, 9, 0),
};

static const u16 sSecurityPadOam_Pressing_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 579, 9, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 581, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 583, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 581, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 583, 9, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 640, 9, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 577, 9, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 577, 9, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 640, 9, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 9, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_X_FLIP, 590, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 520, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 522, 9, 0),
};

static const u16 sSecurityPadOam_Pressing_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 584, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 586, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 584, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 586, 9, 0),
    OAM_ENTRY(-23, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 640, 9, 0),
    OAM_ENTRY(-18, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 577, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 579, 9, 0),
    OAM_ENTRY(2, 9, OAM_DIMS_16x16, OAM_X_FLIP, 577, 9, 0),
    OAM_ENTRY(15, 9, OAM_DIMS_8x16, OAM_X_FLIP, 640, 9, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 9, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 590, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 520, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 522, 9, 0),
};

static const u16 sSecurityPadOam_Pressing_Frame2[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 587, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 589, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 589, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 587, 9, 0),
    OAM_ENTRY(-24, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 640, 9, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 577, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 579, 9, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 577, 9, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_8x16, OAM_X_FLIP, 640, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 520, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 522, 9, 0),
};

static const u16 sSecurityPadOam_Pressing_Frame3[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 587, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 589, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 589, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 579, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 587, 9, 0),
    OAM_ENTRY(-25, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 640, 9, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 577, 9, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 577, 9, 0),
    OAM_ENTRY(17, 9, OAM_DIMS_8x16, OAM_X_FLIP, 640, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 520, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 522, 9, 0),
};


const struct FrameData sSecurityPadMonitorOam_Idle[2] = {
    [0] = {
        .pFrame = sSecurityPadMonitorOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadMonitorOam_ArmExtending[6] = {
    [0] = {
        .pFrame = sSecurityPadMonitorOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSecurityPadMonitorOam_ArmExtending_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSecurityPadMonitorOam_ArmExtending_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSecurityPadMonitorOam_ArmExtending_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sSecurityPadMonitorOam_ArmExtending_Frame4,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadScreenOam_Idle[5] = {
    [0] = {
        .pFrame = sSecurityPadScreenOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSecurityPadScreenOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSecurityPadScreenOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSecurityPadScreenOam_Idle_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadScreenOam_Unlocking[5] = {
    [0] = {
        .pFrame = sSecurityPadScreenOam_Unlocking_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSecurityPadScreenOam_Unlocking_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSecurityPadScreenOam_Unlocking_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSecurityPadScreenOam_Unlocking_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadScreenOam_Inactive[5] = {
    [0] = {
        .pFrame = sSecurityPadScreenOam_Inactive_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSecurityPadScreenOam_Inactive_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSecurityPadScreenOam_Inactive_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSecurityPadScreenOam_Inactive_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadMonitorOam_ArmRetracting[6] = {
    [0] = {
        .pFrame = sSecurityPadMonitorOam_ArmRetracting_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSecurityPadMonitorOam_ArmExtending_Frame4,
        .timer = 6
    },
    [2] = {
        .pFrame = sSecurityPadMonitorOam_ArmExtending_Frame3,
        .timer = 6
    },
    [3] = {
        .pFrame = sSecurityPadMonitorOam_ArmExtending_Frame2,
        .timer = 6
    },
    [4] = {
        .pFrame = sSecurityPadMonitorOam_ArmExtending_Frame1,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadOam_Pressing[5] = {
    [0] = {
        .pFrame = sSecurityPadOam_Pressing_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSecurityPadOam_Pressing_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSecurityPadOam_Pressing_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSecurityPadOam_Pressing_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadOam_Depressing[5] = {
    [0] = {
        .pFrame = sSecurityPadOam_Pressing_Frame3,
        .timer = 6
    },
    [1] = {
        .pFrame = sSecurityPadOam_Pressing_Frame2,
        .timer = 6
    },
    [2] = {
        .pFrame = sSecurityPadOam_Pressing_Frame1,
        .timer = 6
    },
    [3] = {
        .pFrame = sSecurityPadOam_Pressing_Frame0,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadOam_Idle[2] = {
    [0] = {
        .pFrame = sSecurityPadOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadOam_Pressed[2] = {
    [0] = {
        .pFrame = sSecurityPadOam_Pressing_Frame3,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadMonitorOam_ArmExtended[2] = {
    [0] = {
        .pFrame = sSecurityPadMonitorOam_ArmRetracting_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityPadMonitorOam_2f78bc[2] = {
    [0] = {
        .pFrame = sSecurityPadMonitorOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u16 sSecurityPad_2f78cc[16 * 16] = INCBIN_U16("data/sprites/security_pad_2f78cc.pal");
