#include "data/sprites/flashing_number.h"

#include "macros.h"

const u32 sBigFlashingNumberGfx[512] = INCBIN_U32("data/sprites/big_flashing_number.gfx");
const u16 sBigFlashingNumberPal[1 * 16] = INCBIN_U16("data/sprites/big_flashing_number.pal");

static const u16 sBigFlashingNumberOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 0, 0),
};

static const u16 sBigFlashingNumberOam_Sector1_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector1_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector1_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector1_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector2_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(8, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector2_Fram2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(8, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector2_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(8, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector2_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(8, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector3_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector3_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector3_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector3_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector4_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector4_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector4_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector4_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector5_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector5_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector5_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector5_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector6_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-9, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-9, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector6_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-9, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-9, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector6_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-9, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-9, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sBigFlashingNumberOam_Sector6_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-9, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-9, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
};

const struct FrameData sBigFlashingNumberOam_Sector1[] = {
    [0] = {
        .pFrame = sBigFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBigFlashingNumberOam_Sector1_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBigFlashingNumberOam_Sector1_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sBigFlashingNumberOam_Sector1_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sBigFlashingNumberOam_Sector1_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sBigFlashingNumberOam_Sector1_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sBigFlashingNumberOam_Sector1_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sBigFlashingNumberOam_Sector1_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBigFlashingNumberOam_Sector2[] = {
    [0] = {
        .pFrame = sBigFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBigFlashingNumberOam_Sector2_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBigFlashingNumberOam_Sector2_Fram2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sBigFlashingNumberOam_Sector2_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sBigFlashingNumberOam_Sector2_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sBigFlashingNumberOam_Sector2_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sBigFlashingNumberOam_Sector2_Fram2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sBigFlashingNumberOam_Sector2_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBigFlashingNumberOam_Sector3[] = {
    [0] = {
        .pFrame = sBigFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBigFlashingNumberOam_Sector3_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBigFlashingNumberOam_Sector3_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sBigFlashingNumberOam_Sector3_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sBigFlashingNumberOam_Sector3_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sBigFlashingNumberOam_Sector3_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sBigFlashingNumberOam_Sector3_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sBigFlashingNumberOam_Sector3_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBigFlashingNumberOam_Sector4[] = {
    [0] = {
        .pFrame = sBigFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBigFlashingNumberOam_Sector4_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBigFlashingNumberOam_Sector4_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sBigFlashingNumberOam_Sector4_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sBigFlashingNumberOam_Sector4_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sBigFlashingNumberOam_Sector4_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sBigFlashingNumberOam_Sector4_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sBigFlashingNumberOam_Sector4_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBigFlashingNumberOam_Sector5[] = {
    [0] = {
        .pFrame = sBigFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBigFlashingNumberOam_Sector5_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBigFlashingNumberOam_Sector5_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sBigFlashingNumberOam_Sector5_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sBigFlashingNumberOam_Sector5_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sBigFlashingNumberOam_Sector5_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sBigFlashingNumberOam_Sector5_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sBigFlashingNumberOam_Sector5_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBigFlashingNumberOam_Sector6[] = {
    [0] = {
        .pFrame = sBigFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBigFlashingNumberOam_Sector6_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBigFlashingNumberOam_Sector6_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sBigFlashingNumberOam_Sector6_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sBigFlashingNumberOam_Sector6_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sBigFlashingNumberOam_Sector6_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sBigFlashingNumberOam_Sector6_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sBigFlashingNumberOam_Sector6_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const u32 sFlashingNumberGfx[512] = INCBIN_U32("data/sprites/flashing_number.gfx");
const u16 sFlashingNumberPal[1 * 16] = INCBIN_U16("data/sprites/flashing_number.pal");

static const u16 sFlashingNumberOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
};

static const u16 sFlashingNumberOam_Sector1_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sFlashingNumberOam_Sector1_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sFlashingNumberOam_Sector1_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sFlashingNumberOam_Sector1_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21e, 8, 0),
};

static const u16 sFlashingNumberOam_Sector2_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sFlashingNumberOam_Sector2_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sFlashingNumberOam_Sector2_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sFlashingNumberOam_Sector2_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21e, 8, 0),
};

static const u16 sFlashingNumberOam_Sector3_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sFlashingNumberOam_Sector3_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sFlashingNumberOam_Sector3_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sFlashingNumberOam_Sector3_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21e, 8, 0),
};

static const u16 sFlashingNumberOam_Sector4_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sFlashingNumberOam_Sector4_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sFlashingNumberOam_Sector4_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sFlashingNumberOam_Sector4_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21e, 8, 0),
};

static const u16 sFlashingNumberOam_Sector5_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sFlashingNumberOam_Sector5_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sFlashingNumberOam_Sector5_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sFlashingNumberOam_Sector5_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21e, 8, 0),
};

static const u16 sFlashingNumberOam_Sector6_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sFlashingNumberOam_Sector6_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sFlashingNumberOam_Sector6_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sFlashingNumberOam_Sector6_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21e, 8, 0),
};

const struct FrameData sFlashingNumberOam_Sector1[] = {
    [0] = {
        .pFrame = sFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sFlashingNumberOam_Sector1_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sFlashingNumberOam_Sector1_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sFlashingNumberOam_Sector1_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sFlashingNumberOam_Sector1_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sFlashingNumberOam_Sector1_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sFlashingNumberOam_Sector1_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sFlashingNumberOam_Sector1_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFlashingNumberOam_Sector2[] = {

    [0] = {
        .pFrame = sFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sFlashingNumberOam_Sector2_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sFlashingNumberOam_Sector2_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sFlashingNumberOam_Sector2_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sFlashingNumberOam_Sector2_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sFlashingNumberOam_Sector2_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sFlashingNumberOam_Sector2_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sFlashingNumberOam_Sector2_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFlashingNumberOam_Sector3[] = {
    [0] = {
        .pFrame = sFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sFlashingNumberOam_Sector3_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sFlashingNumberOam_Sector3_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sFlashingNumberOam_Sector3_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sFlashingNumberOam_Sector3_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sFlashingNumberOam_Sector3_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sFlashingNumberOam_Sector3_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sFlashingNumberOam_Sector3_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFlashingNumberOam_Sector4[] = {
    [0] = {
        .pFrame = sFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sFlashingNumberOam_Sector4_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sFlashingNumberOam_Sector4_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sFlashingNumberOam_Sector4_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sFlashingNumberOam_Sector4_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sFlashingNumberOam_Sector4_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sFlashingNumberOam_Sector4_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sFlashingNumberOam_Sector4_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFlashingNumberOam_Sector5[] = {
    [0] = {
        .pFrame = sFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sFlashingNumberOam_Sector5_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sFlashingNumberOam_Sector5_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sFlashingNumberOam_Sector5_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sFlashingNumberOam_Sector5_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sFlashingNumberOam_Sector5_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sFlashingNumberOam_Sector5_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sFlashingNumberOam_Sector5_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFlashingNumberOam_Sector6[] = {
    [0] = {
        .pFrame = sFlashingNumberOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sFlashingNumberOam_Sector6_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sFlashingNumberOam_Sector6_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sFlashingNumberOam_Sector6_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sFlashingNumberOam_Sector6_Frame4,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = {
        .pFrame = sFlashingNumberOam_Sector6_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [6] = {
        .pFrame = sFlashingNumberOam_Sector6_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [7] = {
        .pFrame = sFlashingNumberOam_Sector6_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};
