#include "data/sprites/gadora.h"
#include "macros.h"

const u32 sGadoraGfx[1024] = INCBIN_U32("data/sprites/gadora.gfx");
const u16 sGadoraPal[2 * 16] = INCBIN_U16("data/sprites/gadora.pal");

static const u16 sGadoraOam_EyeClosed_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 515, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 517, 8, 0),
    OAM_ENTRY(3, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 527, 8, 0),
};

static const u16 sGadoraOam_EyeClosed_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(3, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 514, 8, 0),
};

static const u16 sGadoraOam_OpeningEye_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 518, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 520, 8, 0),
};

static const u16 sGadoraOam_Vulnerable_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 526, 8, 0),
};

static const u16 sGadoraOam_Vulnerable_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 521, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 523, 8, 0),
    OAM_ENTRY(0, 32, OAM_DIMS_16x8, OAM_Y_FLIP, 527, 8, 0),
};

static const u16 sGadoraOam_Shooting_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 559, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 623, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 561, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 625, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 526, 8, 0),
};

static const u16 sGadoraOam_Shooting_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 561, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 625, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 559, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 623, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 522, 8, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_Y_FLIP, 521, 8, 0),
    OAM_ENTRY(0, 32, OAM_DIMS_16x8, OAM_Y_FLIP, 527, 8, 0),
};

static const u16 sGadoraOam_Shooting_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 531, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 526, 8, 0),
};

static const u16 sGadoraOam_Shooting_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 595, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 595, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 521, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 523, 8, 0),
    OAM_ENTRY(0, 32, OAM_DIMS_16x8, OAM_Y_FLIP, 527, 8, 0),
};

static const u16 sGadoraBeamOam_Idle_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 565, 9, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 567, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 629, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 631, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 565, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x16, OAM_Y_FLIP, 567, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 629, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 631, 9, 0),
};

static const u16 sGadoraBeamOam_Idle_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 568, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 632, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 568, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 632, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 634, 9, 0),
};

static const u16 sGadoraBeamOam_Idle_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 571, 9, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 635, 9, 0),
    OAM_ENTRY(-7, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 571, 9, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 635, 9, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 530, 0, 0),
    OAM_ENTRY(-15, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 530, 0, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 532, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 532, 9, 0),
};

static const u16 sGadoraBeamOam_Idle_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 573, 9, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 575, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 637, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 639, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 573, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x16, OAM_Y_FLIP, 575, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 637, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 639, 9, 0),
};

static const u16 sGadoraRootsOam_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(12, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(12, 27, OAM_DIMS_8x8, OAM_Y_FLIP, 536, 8, 0),
    OAM_ENTRY(15, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sGadoraRootsOam_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(14, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(12, 27, OAM_DIMS_8x8, OAM_Y_FLIP, 537, 8, 0),
    OAM_ENTRY(15, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 541, 8, 0),
};

static const u16 sGadoraRootsOam_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(13, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(12, 27, OAM_DIMS_8x8, OAM_Y_FLIP, 533, 8, 0),
    OAM_ENTRY(15, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sGadoraRootsOam_Idle_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(12, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(14, 27, OAM_DIMS_8x8, OAM_Y_FLIP, 534, 8, 0),
    OAM_ENTRY(15, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sGadoraRootsOam_Idle_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(12, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(13, 27, OAM_DIMS_8x8, OAM_Y_FLIP, 535, 8, 0),
    OAM_ENTRY(15, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 539, 8, 0),
};


const struct FrameData sGadoraRootsOam_Idle[6] = {
    [0] = {
        .pFrame = sGadoraRootsOam_Idle_Frame0,
        .timer = 9
    },
    [1] = {
        .pFrame = sGadoraRootsOam_Idle_Frame1,
        .timer = 9
    },
    [2] = {
        .pFrame = sGadoraRootsOam_Idle_Frame2,
        .timer = 9
    },
    [3] = {
        .pFrame = sGadoraRootsOam_Idle_Frame3,
        .timer = 9
    },
    [4] = {
        .pFrame = sGadoraRootsOam_Idle_Frame4,
        .timer = 9
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_EyeClosed[3] = {
    [0] = {
        .pFrame = sGadoraOam_EyeClosed_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sGadoraOam_EyeClosed_Frame1,
        .timer = 12
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_OpeningEye[2] = {
    [0] = {
        .pFrame = sGadoraOam_OpeningEye_Frame0,
        .timer = 6,
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_ClosingEye[2] = {
    [0] = {
        .pFrame = sGadoraOam_OpeningEye_Frame0,
        .timer = 6
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_Shooting[5] = {
    [0] = {
        .pFrame = sGadoraOam_Shooting_Frame0,
        .timer = 7
    },
    [1] = {
        .pFrame = sGadoraOam_Shooting_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sGadoraOam_Shooting_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sGadoraOam_Shooting_Frame3,
        .timer = 7
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_Vulnerable[3] = {
    [0] = {
        .pFrame = sGadoraOam_Vulnerable_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sGadoraOam_Vulnerable_Frame1,
        .timer = 10
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraBeamOam_Idle[5] = {
    [0] = {
        .pFrame = sGadoraBeamOam_Idle_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sGadoraBeamOam_Idle_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sGadoraBeamOam_Idle_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sGadoraBeamOam_Idle_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraRootsOam_OpeningEye[6] = {
    [0] = {
        .pFrame = sGadoraRootsOam_Idle_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sGadoraRootsOam_Idle_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sGadoraRootsOam_Idle_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sGadoraRootsOam_Idle_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sGadoraRootsOam_Idle_Frame4,
        .timer = 5
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_365110[3] = {
    [0] = {
        .pFrame = sGadoraOam_Shooting_Frame1,
        .timer = 12
    },
    [1] = {
        .pFrame = sGadoraOam_Shooting_Frame3,
        .timer = 12
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_365128[6] = {
    [0] = {
        .pFrame = sGadoraOam_Vulnerable_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sGadoraOam_Vulnerable_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sGadoraOam_OpeningEye_Frame0,
        .timer = 8
    },
    [3] = {
        .pFrame = sGadoraOam_EyeClosed_Frame0,
        .timer = 8
    },
    [4] = {
        .pFrame = sGadoraOam_EyeClosed_Frame1,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};
