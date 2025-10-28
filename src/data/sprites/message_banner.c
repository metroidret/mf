#include "data/sprites/message_banner.h"

const u32 sMessageBannerGfx[512 * 2] = INCBIN_U32("data/sprites/message_banner.gfx");
const u16 sMessageBannerPal[16 * 2] = INCBIN_U16("data/sprites/message_banner.pal");

static const u16 sMessageBannerYesNoCursorOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sMessageBannerYesNoCursorOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sMessageBannerYesNoCursorOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-56, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-88, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-120, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(112, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame5[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-120, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(112, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-120, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(112, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-112, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-112, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-112, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame7[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-120, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(112, -10, OAM_DIMS_8x16, OAM_X_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(-120, -6, OAM_DIMS_8x16, OAM_Y_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(112, -6, OAM_DIMS_8x16, OAM_XY_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(-112, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-112, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame8[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-120, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(112, -12, OAM_DIMS_8x16, OAM_X_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(-120, -4, OAM_DIMS_8x16, OAM_Y_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(112, -4, OAM_DIMS_8x16, OAM_XY_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-112, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sMessageBannerOam_PopUp_Frame9[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-120, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(112, -14, OAM_DIMS_8x16, OAM_X_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(-120, -2, OAM_DIMS_8x16, OAM_Y_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(112, -2, OAM_DIMS_8x16, OAM_XY_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(-112, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-112, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-80, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(80, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sMessageBannerOam_Static_Frame0[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-112, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(112, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(-120, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(112, 0, OAM_DIMS_8x16, OAM_XY_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(-112, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
};

static const u16 sMessageBannerOam_31f72c[] = {
    0
};

const struct FrameData sMessageBannerYesNoCursorOam[5] = {
    [0] = {
        .pFrame = sMessageBannerYesNoCursorOam_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sMessageBannerYesNoCursorOam_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sMessageBannerYesNoCursorOam_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sMessageBannerYesNoCursorOam_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMessageBannerOam_PopUp[11] = {
    [0] = {
        .pFrame = sMessageBannerOam_PopUp_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sMessageBannerOam_PopUp_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sMessageBannerOam_PopUp_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sMessageBannerOam_PopUp_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sMessageBannerOam_PopUp_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sMessageBannerOam_PopUp_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sMessageBannerOam_PopUp_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sMessageBannerOam_PopUp_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sMessageBannerOam_PopUp_Frame8,
        .timer = 3
    },
    [9] = {
        .pFrame = sMessageBannerOam_PopUp_Frame9,
        .timer = 3
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMessageBannerOam_Removal[11] = {
    [0] = {
        .pFrame = sMessageBannerOam_PopUp_Frame9,
        .timer = 3
    },
    [1] = {
        .pFrame = sMessageBannerOam_PopUp_Frame8,
        .timer = 3
    },
    [2] = {
        .pFrame = sMessageBannerOam_PopUp_Frame7,
        .timer = 2
    },
    [3] = {
        .pFrame = sMessageBannerOam_PopUp_Frame6,
        .timer = 2
    },
    [4] = {
        .pFrame = sMessageBannerOam_PopUp_Frame5,
        .timer = 2
    },
    [5] = {
        .pFrame = sMessageBannerOam_PopUp_Frame4,
        .timer = 1
    },
    [6] = {
        .pFrame = sMessageBannerOam_PopUp_Frame3,
        .timer = 1
    },
    [7] = {
        .pFrame = sMessageBannerOam_PopUp_Frame2,
        .timer = 1
    },
    [8] = {
        .pFrame = sMessageBannerOam_PopUp_Frame1,
        .timer = 1
    },
    [9] = {
        .pFrame = sMessageBannerOam_PopUp_Frame0,
        .timer = 1
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMessageBannerOam_Static[2] = {
    [0] = {
        .pFrame = sMessageBannerOam_Static_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_31f818_35dd74[] = INCBIN_U8("data/Blob_31f818_35dd74.bin");
