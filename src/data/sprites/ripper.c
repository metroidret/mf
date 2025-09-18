#include "data/sprites/ripper.h"
#include "macros.h"

const u32 sRipperGfx[512] = INCBIN_U32("data/sprites/ripper.gfx");
const u16 sRipperPal[1 * 16] = INCBIN_U16("data/sprites/ripper.pal");

static const u16 sRipperOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sRipperOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 547, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sRipperOam_Idle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sRipperOam_TurningAround_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

const struct FrameData sRipperOam_Idle[5] = {
    [0] = {
        .pFrame = sRipperOam_Idle_Frame0,
        .timer = 8,
    },
    [1] = {
        .pFrame = sRipperOam_Idle_Frame1,
        .timer = 7,
    },
    [2] = {
        .pFrame = sRipperOam_Idle_Frame0,
        .timer = 8,
    },
    [3] = {
        .pFrame = sRipperOam_Idle_Frame3,
        .timer = 7,
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRipperOam_TurningAround[2] = {
    [0] = {
        .pFrame = sRipperOam_TurningAround_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};
