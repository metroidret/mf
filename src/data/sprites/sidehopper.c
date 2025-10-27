#include "data/sprites/sidehopper.h"
#include "macros.h"

const s16 sSidehopperBigHopVelocity[10] = {
    -8, -16, -16, -8,
    -4, 0, 4, 8,
    16, 16
};

const s16 sSidehopperLittleHopVelocity[10] = {
    -4, -8, -4, -2,
    0, 4, 8, 16,
    16, 16
};

const u32 sSidehopperGfx[512 * 1] = INCBIN_U32("data/sprites/sidehopper.gfx");
const u16 sSidehopperPal[16 * 1] = INCBIN_U16("data/sprites/sidehopper.pal");

static const u16 sSidehopperOam_Idle_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-22, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(6, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_X_FLIP, 0x20a, 8, 0),
};

static const u16 sSidehopperOam_Idle_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-22, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(6, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_X_FLIP, 0x20d, 8, 0),
};

static const u16 sSidehopperOam_Idle_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-22, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(6, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_XY_FLIP, 0x20a, 8, 0),
};

static const u16 sSidehopperOam_JumpWarning_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_X_FLIP, 0x20d, 8, 0),
};

static const u16 sSidehopperOam_JumpWarning_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_8x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-22, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-13, -18, OAM_DIMS_8x8, OAM_Y_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(6, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(5, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x20a, 8, 0),
};

static const u16 sSidehopperOam_Jumping_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-20, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-13, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(4, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-11, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(3, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-1, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x213, 8, 0),
};

static const u16 sSidehopperOam_Jumping_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-20, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-13, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(4, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-11, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(3, 4, OAM_DIMS_8x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-1, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x231, 8, 0),
};

static const u16 sSidehopperOam_Jumping_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-20, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-13, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(4, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-11, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(3, 4, OAM_DIMS_8x16, OAM_X_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-1, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x211, 8, 0),
};

static const u16 sSidehopperOam_ShakingHead_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-22, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(6, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_X_FLIP, 0x20d, 8, 0),
};

static const u16 sSidehopperOam_ShakingHead_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-22, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(6, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_XY_FLIP, 0x20a, 8, 0),
};

static const u16 sSidehopperOam_ShakingHead_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-22, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(6, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_X_FLIP, 0x20d, 8, 0),
};

static const u16 sSidehopperOam_ShakingHead_Frame6[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-22, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(6, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_8x8, OAM_XY_FLIP, 0x20a, 8, 0),
};

const struct FrameData sSidehopperOam_Idle[5] = {
    [0] = {
        .pFrame = sSidehopperOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSidehopperOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSidehopperOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSidehopperOam_Idle_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSidehopperOam_ShakingHead[9] = {
    [0] = {
        .pFrame = sSidehopperOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame1,
        .timer = 3
    },
    [4] = {
        .pFrame = sSidehopperOam_Idle_Frame0,
        .timer = 3
    },
    [5] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame5,
        .timer = 8
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSidehopperOam_JumpWarning[4] = {
    [0] = {
        .pFrame = sSidehopperOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame2,
        .timer = 12
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSidehopperOam_Jumping[4] = {
    [0] = {
        .pFrame = sSidehopperOam_Jumping_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSidehopperOam_Jumping_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sSidehopperOam_Jumping_Frame2,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSidehopperOam_Landing[4] = {
    [0] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame2,
        .timer = 12
    },
    [1] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSidehopperOam_Idle_Frame0,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_31ad70_35dd74[] = INCBIN_U8("data/Blob_31ad70_35dd74.bin");
