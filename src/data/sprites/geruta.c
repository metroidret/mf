#include "data/sprites/geruta.h"
#include "macros.h"

const s16 sGerutaIdleYMovement[65] = {
    0, 0, 0, 0,
    1, 1, 1, 1,
    2, 2, 2, 2,
    3, 3, 4, 4,
    4, 4, 3, 3,
    2, 2, 2, 2,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
    -1, -1, -1, -1,
    -2, -2, -2, -2,
    -3, -3, -4, -4,
    -4, -4, -3, -3,
    -2, -2, -2, -2,
    -1, -1, -1, -1,
    0, 0, 0, 0,
    SHORT_MAX
};

const u32 sGerutaGfx[512 * 1] = INCBIN_U32("data/sprites/geruta.gfx");
const u16 sGerutaPal[16 * 1] = INCBIN_U16("data/sprites/geruta.pal");

static const u16 sGerutaOam_Idle_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-5, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-12, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-17, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-17, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-2, 11, OAM_DIMS_16x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-6, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-11, 11, OAM_DIMS_16x8, OAM_X_FLIP, 0x236, 8, 0),
};

static const u16 sGerutaOam_Idle_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-4, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-18, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-18, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(3, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(0, 13, OAM_DIMS_16x8, OAM_X_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-6, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-10, 13, OAM_DIMS_16x8, OAM_X_FLIP, 0x238, 8, 0),
};

static const u16 sGerutaOam_Idle_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-4, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-19, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-19, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(3, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-1, 15, OAM_DIMS_16x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-6, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-10, 15, OAM_DIMS_16x8, OAM_X_FLIP, 0x218, 8, 0),
};

static const u16 sGerutaOam_AttackWarning_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-5, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-12, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-21, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-21, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-6, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
};

static const u16 sGerutaOam_Lunging_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-12, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-23, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-6, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
};

static const u16 sGerutaOam_Swiping_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-9, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-12, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-6, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
};

static const u16 sGerutaOam_Swiping_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-13, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-12, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-29, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-29, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-6, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
};

static const u16 sGerutaOam_Swiping_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-10, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-10, 14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-24, 14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-6, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
};

static const u16 sGerutaOam_Swiping_Frame3[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-6, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-6, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-20, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-20, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-6, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
};

static const u16 sGerutaOam_Swiping_Frame4[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-5, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-21, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-21, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-6, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
};

static const u16 sGerutaOam_TurningAround_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(2, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, 5, OAM_DIMS_16x8, OAM_X_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-18, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-18, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(2, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(2, 15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-10, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-18, 15, OAM_DIMS_16x8, OAM_X_FLIP, 0x218, 8, 0),
};

const struct FrameData sGerutaOam_Idle[5] = {
    [0] = {
        .pFrame = sGerutaOam_Idle_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sGerutaOam_Idle_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sGerutaOam_Idle_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sGerutaOam_Idle_Frame1,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_AttackWarning[2] = {
    [0] = {
        .pFrame = sGerutaOam_AttackWarning_Frame0,
        .timer = 6
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_Lunging[2] = {
    [0] = {
        .pFrame = sGerutaOam_Lunging_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_Swiping[6] = {
    [0] = {
        .pFrame = sGerutaOam_Swiping_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sGerutaOam_Swiping_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sGerutaOam_Swiping_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sGerutaOam_Swiping_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sGerutaOam_Swiping_Frame4,
        .timer = 5
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_TurningAround[2] = {
    [0] = {
        .pFrame = sGerutaOam_TurningAround_Frame0,
        .timer = 6
    },
    [1] = FRAME_DATA_TERMINATOR
};
