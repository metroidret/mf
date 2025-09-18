#include "data/sprites/zoro_cocoon.h"
#include "macros.h"

const u32 sZoroCocoonGfx[1024] = INCBIN_U32("data/sprites/zoro_cocoon.gfx");
const u16 sZoroCocoonPal[2 * 16] = INCBIN_U16("data/sprites/zoro_cocoon.pal");


static const u16 sZoroCocoonOam_TransformedVertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sZoroCocoonOam_TransformedVertical_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 515, 8, 0),
};

static const u16 sZoroCocoonOam_TransformedVertical_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 515, 8, 0),
};

static const u16 sZoroCocoonOam_TransformedVertical_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-1, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 615, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 515, 8, 0),
};

static const u16 sZoroCocoonOam_UntransformedVertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(16, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 587, 8, 0),
};

static const u16 sZoroCocoonOam_TransformedHorizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 525, 8, 0),
};

static const u16 sZoroCocoonOam_TransformedHorizontal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 529, 8, 0),
};

static const u16 sZoroCocoonOam_TransformedHorizontal_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 597, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 599, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 601, 8, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 529, 8, 0),
};

static const u16 sZoroCocoonOam_TransformedHorizontal_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 597, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 600, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 601, 8, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 529, 8, 0),
};

static const u16 sZoroCocoonOam_UntransformedHorizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 537, 8, 0),
};


const struct FrameData sZoroCocoonOam_TransformedVertical[10] = {
    [0] = {
        .pFrame = sZoroCocoonOam_TransformedVertical_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZoroCocoonOam_TransformedVertical_Frame1,
        .timer = 30
    },
    [2] = {
        .pFrame = sZoroCocoonOam_TransformedVertical_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sZoroCocoonOam_TransformedVertical_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZoroCocoonOam_TransformedVertical_Frame0,
        .timer = 4
    },
    [5] = {
        .pFrame = sZoroCocoonOam_TransformedVertical_Frame1,
        .timer = 4
    },
    [6] = {
        .pFrame = sZoroCocoonOam_TransformedVertical_Frame2,
        .timer = 4
    },
    [7] = {
        .pFrame = sZoroCocoonOam_TransformedVertical_Frame3,
        .timer = 4
    },
    [8] = {
        .pFrame = sZoroCocoonOam_TransformedVertical_Frame2,
        .timer = 60
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoroCocoonOam_UntransformedVertical[2] = {
    [0] = {
        .pFrame = sZoroCocoonOam_UntransformedVertical_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoroCocoonOam_TransformedHorizontal[10] = {
    [0] = {
        .pFrame = sZoroCocoonOam_TransformedHorizontal_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZoroCocoonOam_TransformedHorizontal_Frame1,
        .timer = 30
    },
    [2] = {
        .pFrame = sZoroCocoonOam_TransformedHorizontal_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sZoroCocoonOam_TransformedHorizontal_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZoroCocoonOam_TransformedHorizontal_Frame0,
        .timer = 4
    },
    [5] = {
        .pFrame = sZoroCocoonOam_TransformedHorizontal_Frame1,
        .timer = 4
    },
    [6] = {
        .pFrame = sZoroCocoonOam_TransformedHorizontal_Frame2,
        .timer = 4
    },
    [7] = {
        .pFrame = sZoroCocoonOam_TransformedHorizontal_Frame3,
        .timer = 4
    },
    [8] = {
        .pFrame = sZoroCocoonOam_TransformedHorizontal_Frame2,
        .timer = 60
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoroCocoonOam_UntransformedHorizontal[2] = {
    [0] = {
        .pFrame = sZoroCocoonOam_UntransformedHorizontal_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};


const u32 sZoroHuskGfx[512] = INCBIN_U32("data/sprites/zoro_husk.gfx");
const u16 sZoroHuskPal[1 * 16] = INCBIN_U16("data/sprites/zoro_husk.pal");


static const u16 sZoroHuskOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 8, 0),
};

static const u16 sZoroHuskOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
};

const struct FrameData sZoroHuskOam_Vertical[2] = {
    [0] = {
        .pFrame = sZoroHuskOam_Vertical_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoroHuskOam_Horizontal[2] = {
    [0] = {
        .pFrame = sZoroHuskOam_Horizontal_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
