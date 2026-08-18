#include "data/sprites/metroid.h"
#include "macros.h"

const s16 sMetroidBackgroundFloatingYSpeeds[32] = {
    0, 0, 0, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 1, 1, 2,
    2, 1, 1, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 0, 0, SHORT_MAX
};

const s16 sMetroidBackgroundFloatingXSpeeds[40] = {
    0, 0, 0, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 1, 1, 1,
    1, 1, 2, 2, 2, 2, 1, 1,
    1, 1, 1, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 0, 0, SHORT_MAX
};

const s16 sMetroidFloatingYSpeeds[32] = {
    0, 0, 0, 0, 1, 1, 1, 1,
    2, 2, 2, 2, 3, 3, 3, 3,
    3, 3, 3, 3, 2, 2, 2, 2,
    1, 1, 1, 1, 0, 0, 0, SHORT_MAX
};

const s16 sMetroidFloatingXSpeeds[40] = {
    0, 0, 1, 1, 2, 2, 3, 3,
    4, 4, 4, 4, 5, 5, 5, 5,
    6, 6, 6, 6, 6, 6, 6, 6,
    5, 5, 5, 5, 4, 4, 4, 4,
    3, 3, 2, 2, 1, 1, 0, SHORT_MAX
};

const s16 sMetroidSwayingYSpeeds[64] = {
    0, 0, 0, 0, 1, 1, 1, 1,
    2, 2, 2, 3, 3, 3, 4, 4,
    4, 4, 3, 3, 3, 2, 2, 2,
    1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, -1, -1, -1, -1,
    -2, -2, -2, -3, -3, -3, -4, -4,
    -4, -4, -3, -3, -3, -2, -2, -2,
    -1, -1, -1, -1, 0, 0, 0, SHORT_MAX
};

const s16 sMetroidSwayingXSpeeds[80] = {
    0, 0, 1, 1, 2, 2, 3, 3,
    4, 4, 5, 5, 6, 6, 7, 7,
    7, 7, 8, 8, 8, 8, 7, 7,
    7, 7, 6, 6, 5, 5, 4, 4,
    3, 3, 2, 2, 1, 1, 0, 0,
    0, 0, -1, -1, -2, -2, -3, -3,
    -4, -4, -5, -5, -6, -6, -7, -7,
    -7, -7, -8, -8, -8, -8, -7, -7,
    -7, -7, -6, -6, -5, -5, -4, -4,
    -3, -3, -2, -2, -1, -1, 0, SHORT_MAX
};

const u32 sMetroidGfx[512 * 1] = INCBIN_U32("data/sprites/metroid.gfx");
const u16 sMetroidPal[PAL_ROW * 1] = INCBIN_U16("data/sprites/metroid.pal");

const u16 sMetroidOam_Unused_385294_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

const u16 sMetroidOam_Unused_385294_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
};

const u16 sMetroidOam_Unused_385294_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
};

const u16 sMetroidOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
};

const u16 sMetroidOam_Idle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
};

const u16 sMetroidOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

const u16 sMetroidOam_Background_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
};

const u16 sMetroidOam_Background_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

const u16 sMetroidOam_Background_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
};

const u16 sMetroidOam_Unused_38530c_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

const u16 sMetroidOam_Unused_38531c_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

const u16 sMetroidOam_Unused_38531c_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

const u16 sMetroidOam_Unused_38531c_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

const u16 sMetroidOam_Unused_385344_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
};

const u16 sMetroidOam_Unused_385344_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
};

const u16 sMetroidOam_Unused_385344_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
};

const u16 sMetroidOam_Unused_38536c_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
};

const struct FrameData sMetroidOam_Unused_385294[5] = {
    [0] = {
        .pFrame = sMetroidOam_Unused_385294_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sMetroidOam_Unused_385294_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sMetroidOam_Unused_385294_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sMetroidOam_Unused_385294_Frame1,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOam_Idle[5] = {
    [0] = {
        .pFrame = sMetroidOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sMetroidOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sMetroidOam_Idle_Frame0,
        .timer = 8
    },
    [3] = {
        .pFrame = sMetroidOam_Idle_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOam_Background[5] = {
    [0] = {
        .pFrame = sMetroidOam_Background_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sMetroidOam_Background_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sMetroidOam_Background_Frame0,
        .timer = 12
    },
    [3] = {
        .pFrame = sMetroidOam_Background_Frame3,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOam_Unused_38530c[2] = {
    [0] = {
        .pFrame = sMetroidOam_Unused_38530c_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOam_Unused_38531c[5] = {
    [0] = {
        .pFrame = sMetroidOam_Unused_38531c_Frame0,
        .timer = 9
    },
    [1] = {
        .pFrame = sMetroidOam_Unused_38531c_Frame1,
        .timer = 9
    },
    [2] = {
        .pFrame = sMetroidOam_Unused_38531c_Frame0,
        .timer = 9
    },
    [3] = {
        .pFrame = sMetroidOam_Unused_38531c_Frame3,
        .timer = 9
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOam_Unused_385344[5] = {
    [0] = {
        .pFrame = sMetroidOam_Unused_385344_Frame0,
        .timer = 9
    },
    [1] = {
        .pFrame = sMetroidOam_Unused_385344_Frame1,
        .timer = 9
    },
    [2] = {
        .pFrame = sMetroidOam_Unused_385344_Frame0,
        .timer = 9
    },
    [3] = {
        .pFrame = sMetroidOam_Unused_385344_Frame3,
        .timer = 9
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOam_Unused_38536c[2] = {
    [0] = {
        .pFrame = sMetroidOam_Unused_38536c_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_38537c_386718[] = INCBIN_U8("data/Blob_38537c_386718.bin");
