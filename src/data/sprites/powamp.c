#include "data/sprites/powamp.h"
#include "macros.h"

const u32 sPowampGfx[512 * 1] = INCBIN_U32("data/sprites/powamp.gfx");
const u16 sPowampPal[PAL_ROW * 1] = INCBIN_U16("data/sprites/powamp.pal");

static const u16 sPowampOam_Extending_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPowampOam_Extending_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sPowampOam_Extending_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sPowampOam_Extending_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-3, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(9, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(-16, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPowampOam_Extended_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-20, -38, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-12, -22, OAM_DIMS_32x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-4, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(1, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-17, -30, OAM_DIMS_16x8, OAM_X_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sPowampOam_Extended_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-20, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(1, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-17, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sPowampOam_Extended_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-20, -39, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-12, -23, OAM_DIMS_32x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-4, -47, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(1, -31, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-17, -31, OAM_DIMS_16x8, OAM_X_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPowampOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
};

static const u16 sPowampOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sPowampOam_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sPowampOam_Unused_386708_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x230, 8, 0),
};

static const u16 sPowampOam_Retracting_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sPowampOam_Retracting_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sPowampOam_Unused_3866e8_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-20, -39, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-12, -23, OAM_DIMS_32x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-4, -47, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPowampOam_Unused_3866e8_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-20, -38, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-12, -22, OAM_DIMS_32x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-4, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sPowampOam_Unused_3866e8_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-20, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

const struct FrameData sPowampOam_Idle[4] = {
    [0] = {
        .pFrame = sPowampOam_Idle_Frame0,
        .timer = 9
    },
    [1] = {
        .pFrame = sPowampOam_Idle_Frame1,
        .timer = 9
    },
    [2] = {
        .pFrame = sPowampOam_Idle_Frame2,
        .timer = 9
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowampOam_Extended[4] = {
    [0] = {
        .pFrame = sPowampOam_Extended_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sPowampOam_Extended_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sPowampOam_Extended_Frame2,
        .timer = 5
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowampOam_Extending[7] = {
    [0] = {
        .pFrame = sPowampOam_Extending_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sPowampOam_Extending_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sPowampOam_Extending_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sPowampOam_Extending_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sPowampOam_Extended_Frame1,
        .timer = 4
    },
    [5] = {
        .pFrame = sPowampOam_Extended_Frame2,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowampOam_Retracting[7] = {
    [0] = {
        .pFrame = sPowampOam_Extending_Frame3,
        .timer = 4
    },
    [1] = {
        .pFrame = sPowampOam_Retracting_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sPowampOam_Retracting_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sPowampOam_Extending_Frame0,
        .timer = 4
    },
    [4] = {
        .pFrame = sPowampOam_Idle_Frame1,
        .timer = 4
    },
    [5] = {
        .pFrame = sPowampOam_Idle_Frame2,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowampOam_Unused_3866e8[4] = {
    [0] = {
        .pFrame = sPowampOam_Unused_3866e8_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sPowampOam_Unused_3866e8_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sPowampOam_Unused_3866e8_Frame2,
        .timer = 5
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowampOam_Unused_386708[2] = {
    [0] = {
        .pFrame = sPowampOam_Unused_386708_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
