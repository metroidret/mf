#include "data/sprites/missile_hatch.h"
#include "macros.h"

const s16 sMissileHatchDebrisFallingXMovement[16] = {
    -10, -9, -8, -8,
     -7, -7, -6, -6,
     -5, -5, -4, -4,
     -3, -3, -2,
    SHORT_MAX
};

const u32 sMissileHatchGfx[512] = INCBIN_U32("data/sprites/missile_hatch.gfx");
const u16 sMissileHatchPal[1 * 16] = INCBIN_U16("data/sprites/missile_hatch.pal");

static const u16 sMissileHatchOam_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Falling0_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Falling0_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Falling0_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Falling0_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 523, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Frame_35fc54[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Frame_35fc5c[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 574, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Frame_35fc64[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 543, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Falling1_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Falling3_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sMissileHatchDebrisOam_Falling2_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};


const struct FrameData sMissileHatchOam_Idle[2] = {
    [0] = {
        .pFrame = sMissileHatchOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileHatchDebrisOam_Falling0[5] = {
    [0] = {
        .pFrame = sMissileHatchDebrisOam_Falling0_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sMissileHatchDebrisOam_Falling0_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sMissileHatchDebrisOam_Falling0_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sMissileHatchDebrisOam_Falling0_Frame3,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileHatchOam_35fcbc[2] = {
    [0] = {
        .pFrame = sMissileHatchDebrisOam_Frame_35fc54,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileHatchOam_35fccc[2] = {
    [0] = {
        .pFrame = sMissileHatchDebrisOam_Frame_35fc5c,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileHatchDebrisOam_Falling1[2] = {
    [0] = {
        .pFrame = sMissileHatchDebrisOam_Falling1_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileHatchDebrisOam_Falling2[2] = {
    [0] = {
        .pFrame = sMissileHatchDebrisOam_Falling2_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileHatchDebrisOam_Falling3[2] = {
    [0] = {
        .pFrame = sMissileHatchDebrisOam_Falling3_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
