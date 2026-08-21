#include "data/sprites/choot.h"
#include "macros.h"

const s16 sChootJumpVelocity[53] = {
    -12, -12, -12, -12,
    -12, -12, -12, -12,
    -11, -11, -11, -11,
    -10, -10, -10, -10,
    -9, -9, -9, -9,
    -8, -8, -8, -8,
    -8, -8, -8, -8,
    -7, -7, -7, -7,
    -6, -6, -6, -6,
    -5, -5, -5, -5,
    -4, -4, -4, -4,
    -3, -3, -3, -3,
    -2, -2, -2, -2,
    SHORT_MAX
};

const u32 sChootGfx[512 * 1] = INCBIN_U32("data/sprites/choot.gfx");
const u16 sChootPal[16 * 1] = INCBIN_U16("data/sprites/choot.pal");

static const u16 sChootOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x220, 8, 0),
};

static const u16 sChootOam_Launching_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x220, 8, 0),
};

static const u16 sChootOam_Launching_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
};

static const u16 sChootOam_Jumping_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sChootOam_Opening_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
};

static const u16 sChootOam_FloatingDown_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
};

static const u16 sChootOam_FloatingDown_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
};

static const u16 sChootOam_FloatingDown_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x20c, 8, 0),
};

static const u16 sChootSpitOam_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20e, 8, 0),
};

static const u16 sChootSpitOam_Falling_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20f, 8, 0),
};

static const u16 sChootSpitOam_ExplodingMidair_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
};

static const u16 sChootSpitOam_ExplodingMidair_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-10, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
};

static const u16 sChootSpitOam_ExplodingMidair_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0),
};

static const u16 sChootSpitOam_ExplodingMidair_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(6, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-14, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sChootSpitOam_ExplodingOnGround_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sChootSpitOam_ExplodingOnGround_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sChootSpitOam_ExplodingOnGround_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
};

static const u16 sChootSpitOam_ExplodingOnGround_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sChootSpitOam_ExplodingOnGround_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x235, 8, 0),
};

const struct FrameData sChootOam_Idle[2] = {
    [0] = {
        .pFrame = sChootOam_Idle_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChootOam_Launching[3] = {
    [0] = {
        .pFrame = sChootOam_Launching_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChootOam_Launching_Frame1,
        .timer = 8
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChootOam_Jumping[2] = {
    [0] = {
        .pFrame = sChootOam_Jumping_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChootOam_Opening[5] = {
    [0] = {
        .pFrame = sChootOam_Launching_Frame1,
        .timer = 6
    },
    [1] = {
        .pFrame = sChootOam_Launching_Frame0,
        .timer = 4
    },
    [2] = {
        .pFrame = sChootOam_Idle_Frame0,
        .timer = 4
    },
    [3] = {
        .pFrame = sChootOam_Opening_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChootOam_FloatingDown[5] = {
    [0] = {
        .pFrame = sChootOam_FloatingDown_Frame0,
        .timer = 9
    },
    [1] = {
        .pFrame = sChootOam_FloatingDown_Frame1,
        .timer = 9
    },
    [2] = {
        .pFrame = sChootOam_FloatingDown_Frame2,
        .timer = 9
    },
    [3] = {
        .pFrame = sChootOam_FloatingDown_Frame1,
        .timer = 9
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChootSpitOam_Spawning[2] = {
    [0] = {
        .pFrame = sChootSpitOam_Spawning_Frame0,
        .timer = 8
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChootSpitOam_Falling[2] = {
    [0] = {
        .pFrame = sChootSpitOam_Falling_Frame0,
        .timer = 2
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChootSpitOam_ExplodingMidair[5] = {
    [0] = {
        .pFrame = sChootSpitOam_ExplodingMidair_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sChootSpitOam_ExplodingMidair_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sChootSpitOam_ExplodingMidair_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sChootSpitOam_ExplodingMidair_Frame3,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChootSpitOam_ExplodingOnGround[6] = {
    [0] = {
        .pFrame = sChootSpitOam_ExplodingOnGround_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sChootSpitOam_ExplodingOnGround_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sChootSpitOam_ExplodingOnGround_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sChootSpitOam_ExplodingOnGround_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sChootSpitOam_ExplodingOnGround_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};
