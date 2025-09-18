#include "data/sprites/yameba.h"
#include "macros.h"

const s16 sYamebaIdleYMovement[65] = {
     0,  0,  0,  0,
     1,  0,  1,  0,
     1,  0,  1,  0,
     1,  1,  1,  2,
     2,  1,  1,  1,
     0,  1,  0,  1,
     0,  1,  0,  1,
     0,  0,  0,  0,
     0,  0,  0,  0,
    -1,  0, -1,  0,
    -1,  0, -1,  0,
    -1, -1, -1, -2,
    -2, -1, -1, -1,
     0, -1,  0, -1,
     0, -1,  0, -1,
     0,  0,  0,  0,
    SHORT_MAX
};

const s16 sYamebaIdleXMovement[81] = {
     0,  0,  0,  0,
     1,  0,  1,  0,
     1,  0,  1,  0,
     1,  1,  1,  1,
     1,  1,  2,  2,
     2,  2,  1,  1,
     1,  1,  1,  1,
     0,  1,  0,  1,
     0,  1,  0,  1,
     0,  0,  0,  0,
     0,  0,  0,  0,
    -1,  0, -1,  0,
    -1,  0, -1,  0,
    -1, -1, -1, -1,
    -1, -1, -2, -2,
    -2, -2, -1, -1,
    -1, -1, -1, -1,
     0, -1,  0, -1,
     0, -1,  0, -1,
     0,  0,  0,  0,
    SHORT_MAX
};

static const s16 sYameba_2f493c[65] = {
     0,  0,  0,  0,
     1,  1,  1,  1,
     2,  2,  2,  2,
     3,  3,  3,  3,
     3,  3,  3,  3,
     2,  2,  2,  2,
     1,  1,  1,  1,
     0,  0,  0,  0,
     0,  0,  0,  0,
    -1, -1, -1, -1,
    -2, -2, -2, -2,
    -3, -3, -3, -3,
    -3, -3, -3, -3,
    -2, -2, -2, -2,
    -1, -1, -1, -1,
     0,  0,  0,  0,
    SHORT_MAX
};

static const s16 sYameba_2f49be[81] = {
     0,  0,  1,  1,
     2,  2,  3,  3,
     4,  4,  5,  5,
     6,  6,  7,  7,
     7,  7,  8,  8,
     8,  8,  7,  7,
     7,  7,  6,  6,
     5,  5,  4,  4,
     3,  3,  2,  2,
     1,  1,  0,  0,
     0,  0, -1, -1,
    -2, -2, -3, -3,
    -4, -4, -5, -5,
    -6, -6, -7, -7,
    -7, -7, -8, -8,
    -8, -8, -7, -7,
    -7, -7, -6, -6,
    -5, -5, -4, -4,
    -3, -3, -2, -2,
    -1, -1,  0,  0,
    SHORT_MAX
};

const u32 sYamebaGfx[2 * 512] = INCBIN_U32("data/sprites/yameba.gfx");
const u16 sYamebaPal[2 * 16] = INCBIN_U16("data/sprites/yameba.pal");


static const u16 sYamebaOam_Small_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sYamebaOam_Small_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sYamebaOam_Small_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sYamebaOam_Small_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sYamebaOam_Small_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sYamebaOam_Big_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sYamebaOam_Big_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sYamebaOam_Big_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sYamebaOam_Big_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sYamebaOam_Big_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sYamebaOam_Small_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 8, 0),
};

static const u16 sYamebaOam_Small_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 578, 8, 0),
};

static const u16 sYamebaOam_Small_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 580, 8, 0),
};

static const u16 sYamebaOam_Small_Unused_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 582, 8, 0),
};

static const u16 sYamebaOam_Small_Unused_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 584, 8, 0),
};


const struct FrameData sYamebaOam_Small[9] = {
    [0] = {
        .pFrame = sYamebaOam_Small_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sYamebaOam_Small_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sYamebaOam_Small_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sYamebaOam_Small_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sYamebaOam_Small_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sYamebaOam_Small_Frame3,
        .timer = 8
    },
    [6] = {
        .pFrame = sYamebaOam_Small_Frame2,
        .timer = 8
    },
    [7] = {
        .pFrame = sYamebaOam_Small_Frame1,
        .timer = 8
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYamebaOam_Big[9] = {
    [0] = {
        .pFrame = sYamebaOam_Big_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sYamebaOam_Big_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sYamebaOam_Big_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sYamebaOam_Big_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sYamebaOam_Big_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sYamebaOam_Big_Frame3,
        .timer = 8
    },
    [6] = {
        .pFrame = sYamebaOam_Big_Frame2,
        .timer = 8
    },
    [7] = {
        .pFrame = sYamebaOam_Big_Frame1,
        .timer = 8
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYamebaOam_Small_Unused[9] = {
    [0] = {
        .pFrame = sYamebaOam_Small_Unused_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sYamebaOam_Small_Unused_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sYamebaOam_Small_Unused_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sYamebaOam_Small_Unused_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sYamebaOam_Small_Unused_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sYamebaOam_Small_Unused_Frame3,
        .timer = 8
    },
    [6] = {
        .pFrame = sYamebaOam_Small_Unused_Frame2,
        .timer = 8
    },
    [7] = {
        .pFrame = sYamebaOam_Small_Unused_Frame1,
        .timer = 8
    },
    [8] = FRAME_DATA_TERMINATOR
};
