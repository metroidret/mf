#include "data/sprites/dessgeega.h"

const s16 sDessgeegaBigHopVelocity[10] = {
    -8, -16, -16, -8,
    -4, 0, 4, 8,
    16, 16
};

const s16 sDessgeegaLittleHopVelocity[10] = {
    -4, -8, -4, -2,
    0, 4, 8, 16,
    16, 16
};

const u32 sDessgeegaGfx[512 * 1] = INCBIN_U32("data/sprites/dessgeega.gfx");
const u16 sDessgeegaPal[16 * 1] = INCBIN_U16("data/sprites/dessgeega.pal");

static const u16 sDessgeegaOam_Idle_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-16, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_16x8, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(6, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -12, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x227, 8, 0),
};

static const u16 sDessgeegaOam_Idle_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-22, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x209, 8, 0),
};

static const u16 sDessgeegaOam_Idle_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x221, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x229, 8, 0),
};

static const u16 sDessgeegaOam_JumpWarning_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_8x16, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x8, OAM_X_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
};

static const u16 sDessgeegaOam_JumpWarning_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x8, OAM_X_FLIP, 0x221, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-22, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x229, 8, 0),
    OAM_ENTRY(6, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
};

static const u16 sDessgeegaOam_Jumping_Frame0[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x221, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-20, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(6, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -15, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(4, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-17, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(9, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x211, 8, 0),
};

static const u16 sDessgeegaOam_Jumping_Frame1[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x221, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-20, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(6, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -15, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(4, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-17, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(9, 4, OAM_DIMS_8x16, OAM_X_FLIP, 0x20e, 8, 0),
};

static const u16 sDessgeegaOam_Jumping_Frame2[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x221, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-20, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(6, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -15, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(4, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-17, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(9, 4, OAM_DIMS_8x16, OAM_X_FLIP, 0x20d, 8, 0),
};

static const u16 sDessgeegaOam_ShakingHead_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-14, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-6, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-22, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x209, 8, 0),
};

static const u16 sDessgeegaOam_ShakingHead_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-5, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x235, 8, 0),
    OAM_ENTRY(-13, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-5, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x229, 8, 0),
};

static const u16 sDessgeegaOam_ShakingHead_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-2, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-10, -23, OAM_DIMS_8x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-22, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x209, 8, 0),
};

static const u16 sDessgeegaOam_ShakingHead_Frame6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-11, -23, OAM_DIMS_16x8, OAM_X_FLIP, 0x235, 8, 0),
    OAM_ENTRY(5, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-11, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x229, 8, 0),
};

static const u16 sDessgeegaSpikeOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sDessgeegaSpikeOam_Exploding_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
};

static const u16 sDessgeegaSpikeOam_Exploding_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0),
};

static const u16 sDessgeegaSpikeOam_Exploding_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 8, 0),
};

const struct FrameData sDessgeegaOam_Idle[5] = {
    [0] = {
        .pFrame = sDessgeegaOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sDessgeegaOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sDessgeegaOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sDessgeegaOam_Idle_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessgeegaOam_ShakingHead[9] = {
    [0] = {
        .pFrame = sDessgeegaOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sDessgeegaOam_ShakingHead_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sDessgeegaOam_ShakingHead_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sDessgeegaOam_ShakingHead_Frame1,
        .timer = 3
    },
    [4] = {
        .pFrame = sDessgeegaOam_Idle_Frame0,
        .timer = 3
    },
    [5] = {
        .pFrame = sDessgeegaOam_ShakingHead_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sDessgeegaOam_ShakingHead_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sDessgeegaOam_ShakingHead_Frame5,
        .timer = 8
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessgeegaOam_JumpWarning[4] = {
    [0] = {
        .pFrame = sDessgeegaOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sDessgeegaOam_JumpWarning_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sDessgeegaOam_JumpWarning_Frame2,
        .timer = 12
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessgeegaOam_Jumping[4] = {
    [0] = {
        .pFrame = sDessgeegaOam_Jumping_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sDessgeegaOam_Jumping_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sDessgeegaOam_Jumping_Frame2,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessgeegaOam_Landing[4] = {
    [0] = {
        .pFrame = sDessgeegaOam_JumpWarning_Frame2,
        .timer = 12
    },
    [1] = {
        .pFrame = sDessgeegaOam_JumpWarning_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sDessgeegaOam_Idle_Frame0,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessgeegaSpikeOam_Moving[2] = {
    [0] = {
        .pFrame = sDessgeegaSpikeOam_Moving_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessgeegaSpikeOam_Exploding[4] = {
    [0] = {
        .pFrame = sDessgeegaSpikeOam_Exploding_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sDessgeegaSpikeOam_Exploding_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sDessgeegaSpikeOam_Exploding_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_31b9f0_35dd74[] = INCBIN_U8("data/Blob_31b9f0_35dd74.bin");
