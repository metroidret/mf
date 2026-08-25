#include "data/sprites/lab_debris.h"
#include "macros.h"

const u32 sLabDebrisGfx[512 * 1] = INCBIN_U32("data/sprites/lab_debris.gfx");
const u16 sLabDebrisPal[PAL_ROW * 1] = INCBIN_U16("data/sprites/lab_debris.pal");

static const u16 sLabDebrisOam_Left_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLabDebrisOam_Middle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sLabDebrisOam_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(8, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sLabDebrisOam_Unused_385c4c_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sLabDebrisOam_Unused_385c5c_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
};

static const u16 sLabDebrisOam_Unused_385c6c_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-17, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-17, -21, OAM_DIMS_32x8, OAM_NO_FLIP, 0x217, 8, 0),
};

static const u16 sLabDebrisOam_Unused_385c7c_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
};

static const u16 sLabDebrisOam_Unused_385c8c_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-3, -23, OAM_DIMS_8x8, OAM_X_FLIP, 0x230, 8, 0),
};

static const u16 sLabDebrisOam_Unused_385c9c_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-17, -13, OAM_DIMS_32x16, OAM_X_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-17, -21, OAM_DIMS_32x8, OAM_X_FLIP, 0x217, 8, 0),
};

const struct FrameData sLabDebrisOam_Left[2] = {
    [0] = {
        .pFrame = sLabDebrisOam_Left_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLabDebrisOam_Middle[2] = {
    [0] = {
        .pFrame = sLabDebrisOam_Middle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLabDebrisOam_Right[2] = {
    [0] = {
        .pFrame = sLabDebrisOam_Right_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLabDebrisOam_Unused_385c4c[2] = {
    [0] = {
        .pFrame = sLabDebrisOam_Unused_385c4c_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLabDebrisOam_Unused_385c5c[2] = {
    [0] = {
        .pFrame = sLabDebrisOam_Unused_385c5c_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLabDebrisOam_Unused_385c6c[2] = {
    [0] = {
        .pFrame = sLabDebrisOam_Unused_385c6c_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLabDebrisOam_Unused_385c7c[2] = {
    [0] = {
        .pFrame = sLabDebrisOam_Unused_385c7c_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLabDebrisOam_Unused_385c8c[2] = {
    [0] = {
        .pFrame = sLabDebrisOam_Unused_385c8c_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLabDebrisOam_Unused_385c9c[2] = {
    [0] = {
        .pFrame = sLabDebrisOam_Unused_385c9c_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
