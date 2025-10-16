#include "data/sprites/x_parasite.h"
#include "macros.h"

const s16 sXParasite_3bdebc[13] = {
    255, 224, 208, 192, 176, 160, 144, 128, 112, 96, 80, 64, 48
};

const u16 sXParasiteMosaicValues[45] = {
    0x00, 0x11, 0x22, 0x33,
    0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xaa, 0xbb,
    0xcc, 0xdd, 0xee, 0xff,
    0xee, 0xdd, 0xcc, 0xbb,
    0xaa, 0x99, 0x88, 0x77,
    0x66, 0x55, 0x44, 0x33,
    0x22, 0x11, 0x22, 0x33,
    0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xaa, 0xbb,
    0xcc, 0xdd, 0xee, 0xff,
    0x00
};

const s16 sXParasite_3bdf30[120] = {
    0, -1, 0, -2,
    0, -1, -1, 0,
    -1, -1, 0, 0,
    -1, -1, 0, -1,
    -1, 0, -1, 0,
    -1, 0, 0, -1,
    0, -1, 0, 0,
    0, -1, 1, 0,
    0, 0, 1, 0,
    1, 0, 0, 1,
    0, 1, 0, 1,
    1, 0, 1, 1,
    0, 0, 1, 1,
    0, 1, 1, 1,
    1, 0, 1, 0,
    1, 0, 1, 1,
    1, 0, 1, 1,
    0, 1, 1, 0,
    0, 1, 1, 0,
    1, 1, 0, 1,
    0, 1, 0, 0,
    1, 0, 1, 0,
    0, 0, 0, 0,
    -1, 0, 0, -1,
    0, 0, -1, 0,
    -1, 0, -1, -1,
    0, -1, -1, 0,
    0, -1, -1, 0,
    -1, -1, 0, -2,
    0, -1, -1, SHORT_MAX
};

const s16 sXParasite_3be020[61] = {
    -1, 0, -2, -1,
    -1, -1, -1, -1,
    -1, -1, -1, 0,
    -1, 0, 0, -1,
    1, 0, 0, 1,
    0, 1, 1, 1,
    1, 1, 1, 1,
    2, 1, 0, 1,
    2, 1, 1, 1,
    1, 1, 0, 1,
    1, 1, 0, 1,
    0, 0, 0, 0,
    -1, 0, -1, -1,
    -1, 0, -1, -1,
    -1, -1, -2, -1,
    SHORT_MAX
};

const s16 sXParasiteIdleFloatingYMovement[65] = {
    0, 0, 0, 0,
    1, 0, 1, 0,
    1, 0, 1, 0,
    1, 1, 1, 2,
    2, 1, 1, 1,
    0, 1, 0, 1,
    0, 1, 0, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
    -1, 0, -1, 0,
    -1, 0, -1, 0,
    -1, -1, -1, -2,
    -2, -1, -1, -1,
    0, -1, 0, -1,
    0, -1, 0, -1,
    0, 0, 0, 0,
    SHORT_MAX
};

const s16 sXParasiteIdleFloatingXMovement[81] = {
    0, 0, 0, 0,
    1, 0, 1, 0,
    1, 0, 1, 0,
    1, 1, 1, 1,
    1, 1, 2, 2,
    2, 2, 1, 1,
    1, 1, 1, 1,
    0, 1, 0, 1,
    0, 1, 0, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
    -1, 0, -1, 0,
    -1, 0, -1, 0,
    -1, -1, -1, -1,
    -1, -1, -2, -2,
    -2, -2, -1, -1,
    -1, -1, -1, -1,
    0, -1, 0, -1,
    0, -1, 0, -1,
    0, 0, 0, 0,
    SHORT_MAX
};

ALIGN_2();

static const u16 sXParasiteOam_Red_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c0, 2, 0),
};

static const u16 sXParasiteOam_Red_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c2, 2, 0),
};

static const u16 sXParasiteOam_Red_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c4, 2, 0),
};

static const u16 sXParasiteOam_Red_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c6, 2, 0),
};

static const u16 sXParasiteOam_Red_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c8, 2, 0),
};

static const u16 sXParasiteOam_Red_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1ca, 2, 0),
};

static const u16 sXParasiteOam_Green_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c0, 3, 0),
};

static const u16 sXParasiteOam_Green_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c2, 3, 0),
};

static const u16 sXParasiteOam_Green_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c4, 3, 0),
};

static const u16 sXParasiteOam_Green_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c6, 3, 0),
};

static const u16 sXParasiteOam_Green_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c8, 3, 0),
};

static const u16 sXParasiteOam_Green_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1ca, 3, 0),
};

static const u16 sXParasiteOam_Yellow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c0, 4, 0),
};

static const u16 sXParasiteOam_Yellow_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c2, 4, 0),
};

static const u16 sXParasiteOam_Yellow_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c4, 4, 0),
};

static const u16 sXParasiteOam_Yellow_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c6, 4, 0),
};

static const u16 sXParasiteOam_Yellow_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1c8, 4, 0),
};

static const u16 sXParasiteOam_Yellow_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1ca, 4, 0),
};

const struct FrameData sXParasiteOam_Yellow[7] = {
    [0] = {
        .pFrame = sXParasiteOam_Yellow_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sXParasiteOam_Yellow_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sXParasiteOam_Yellow_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sXParasiteOam_Yellow_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sXParasiteOam_Yellow_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sXParasiteOam_Yellow_Frame5,
        .timer = 5
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sXParasiteOam_Green[7] = {
    [0] = {
        .pFrame = sXParasiteOam_Green_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sXParasiteOam_Green_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sXParasiteOam_Green_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sXParasiteOam_Green_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sXParasiteOam_Green_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sXParasiteOam_Green_Frame5,
        .timer = 5
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sXParasiteOam_Red[7] = {
    [0] = {
        .pFrame = sXParasiteOam_Red_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sXParasiteOam_Red_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sXParasiteOam_Red_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sXParasiteOam_Red_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sXParasiteOam_Red_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sXParasiteOam_Red_Frame5,
        .timer = 5
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sXParasiteOam_Yellow_Slow[7] = {
    [0] = {
        .pFrame = sXParasiteOam_Yellow_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sXParasiteOam_Yellow_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sXParasiteOam_Yellow_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sXParasiteOam_Yellow_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sXParasiteOam_Yellow_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sXParasiteOam_Yellow_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sXParasiteOam_Green_Slow[7] = {
    [0] = {
        .pFrame = sXParasiteOam_Green_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sXParasiteOam_Green_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sXParasiteOam_Green_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sXParasiteOam_Green_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sXParasiteOam_Green_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sXParasiteOam_Green_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sXParasiteOam_Red_Slow[7] = {
    [0] = {
        .pFrame = sXParasiteOam_Red_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sXParasiteOam_Red_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sXParasiteOam_Red_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sXParasiteOam_Red_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sXParasiteOam_Red_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sXParasiteOam_Red_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

// HAM:
// static const u8 sBlob_3be3a0_3c0030[] = INCBIN_U8("data/Blob_3be3a0_3c0030.bin");

// Original:
// static const u8 sBlob_3be1be_3e392c[] = INCBIN_U8("data/Blob_3be1be_3e392c.bin");

static const u8 sBlob_3be3a0_3e392c[] = INCBIN_U8("data/Blob_3be3a0_3e392c.bin");
