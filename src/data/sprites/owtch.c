#include "data/sprites/owtch.h"
#include "macros.h"

const u32 sOwtchGfx[512] = INCBIN_U32("data/sprites/owtch.gfx");
const u16 sOwtchPal[16] = INCBIN_U16("data/sprites/owtch.pal");

static const u16 sOwtchOam_3790d4_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sOwtchOam_3790d4_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sOwtchOam_3790d4_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sOwtchOam_379114_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(11, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
};

static const u16 sOwtchOam_379114_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(11, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sOwtchOam_379114_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(5, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(13, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
};

static const u16 sOwtchOam_379154_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sOwtchOam_379154_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sOwtchOam_379154_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sOwtchOam_379194_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
};

static const u16 sOwtchOam_379194_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(6, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-10, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sOwtchOam_379194_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-1, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(7, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
};

static const u16 sOwtchOam_3791b4_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
};

static const u16 sOwtchOam_3791b4_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(16, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sOwtchOam_3791b4_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(5, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(16, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
};

const struct FrameData sOwtchOam_3790d4[4] = {
    [0] = {
        .pFrame = sOwtchOam_3790d4_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sOwtchOam_3790d4_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sOwtchOam_3790d4_Frame2,
        .timer = 8
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOwtchOam_3790f4[4] = {
    [0] = {
        .pFrame = sOwtchOam_3790d4_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sOwtchOam_3790d4_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sOwtchOam_3790d4_Frame2,
        .timer = 6
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOwtchOam_379114[4] = {
    [0] = {
        .pFrame = sOwtchOam_379114_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sOwtchOam_379114_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sOwtchOam_379114_Frame2,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOwtchOam_379134[4] = {
    [0] = {
        .pFrame = sOwtchOam_379114_Frame2,
        .timer = 2
    },
    [1] = {
        .pFrame = sOwtchOam_379114_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sOwtchOam_379114_Frame0,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOwtchOam_379154[4] = {
    [0] = {
        .pFrame = sOwtchOam_379154_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sOwtchOam_379154_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sOwtchOam_379154_Frame2,
        .timer = 8
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOwtchOam_379174[4] = {
    [0] = {
        .pFrame = sOwtchOam_379154_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sOwtchOam_379154_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sOwtchOam_379154_Frame2,
        .timer = 6
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOwtchOam_379194[4] = {
    [0] = {
        .pFrame = sOwtchOam_379194_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sOwtchOam_379194_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sOwtchOam_379194_Frame2,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOwtchOam_3791b4[4] = {
    [0] = {
        .pFrame = sOwtchOam_3791b4_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sOwtchOam_3791b4_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sOwtchOam_3791b4_Frame2,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};
