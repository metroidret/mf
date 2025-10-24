#include "data/sprites/core_x_downloading_varia.h"
#include "macros.h"

const u32 sCoreXDownloadingVariaGfx[512 * 4] = INCBIN_U32("data/sprites/core_x_downloading_varia.gfx");
const u16 sCoreXDownloadingVariaPal[16 * 4] = INCBIN_U16("data/sprites/core_x_downloading_varia.pal");

static const u16 sCoreXShellBeforeVariaCoreOam_Downloading_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x290, 9, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d5, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d4, 9, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x292, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x294, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d7, 9, 0),
};

static const u16 sCoreXShellBeforeVariaCoreOam_Downloading_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x290, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d5, 10, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d4, 10, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x292, 10, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x294, 10, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d7, 10, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_3_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d9, 9, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2b8, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x298, 9, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_3_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(7, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2fb, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x299, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29b, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x29c, 9, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_3_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(5, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2fa, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x29d, 9, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x29f, 9, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_3_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2dc, 9, 0),
    OAM_ENTRY(7, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2dd, 9, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_3_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2bd, 9, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_3_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2fd, 9, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_3_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2de, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_XY_FLIP, 0x2b8, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x298, 9, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_3_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2fe, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x299, 9, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x29b, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x29c, 9, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_3_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2df, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x29d, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 0x29f, 9, 0),
};

static const u16 sCoreXStaticBeforeVariaCoreOam_0_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f8, 9, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_ExplodingDataPad_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x28c, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_ExplodingDataPad_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x288, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_ExplodingDataPad_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x284, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x280, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -17, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -15, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_FloatingAway_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sCoreXAbilityBeforeVariaCoreOam_FloatingAway_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
};

const struct FrameData sCoreXShellBeforeVariaCoreOam_Idle[2] = {
    [0] = {
        .pFrame = sCoreXShellBeforeVariaCoreOam_Downloading_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXShellBeforeVariaCoreOam_Downloading[3] = {
    [0] = {
        .pFrame = sCoreXShellBeforeVariaCoreOam_Downloading_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sCoreXShellBeforeVariaCoreOam_Downloading_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria[17] = {
    [0] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame7,
        .timer = 1
    },
    [8] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame0,
        .timer = 1
    },
    [9] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame9,
        .timer = 1
    },
    [10] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame2,
        .timer = 1
    },
    [11] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame7,
        .timer = 1
    },
    [12] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame4,
        .timer = 1
    },
    [13] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame5,
        .timer = 1
    },
    [14] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame6,
        .timer = 1
    },
    [15] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame3,
        .timer = 1
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXAbilityBeforeVariaCoreOam_ExplodingDataPad[7] = {
    [0] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_ExplodingDataPad_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_ExplodingDataPad_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_ExplodingDataPad_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame1,
        .timer = 10
    },
    [4] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_ExplodingDataPad_Frame2,
        .timer = 6
    },
    [5] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_ExplodingDataPad_Frame1,
        .timer = 6
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXAbilityBeforeVariaCoreOam_FloatingAway[9] = {
    [0] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_FloatingAway_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame2,
        .timer = 6
    },
    [2] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_FloatingAway_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame6,
        .timer = 6
    },
    [4] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame3,
        .timer = 6
    },
    [5] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame7,
        .timer = 6
    },
    [7] = {
        .pFrame = sCoreXAbilityBeforeVariaCoreOam_DownloadingVaria_Frame9,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXStaticBeforeVariaCoreOam_3[19] = {
    [0] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame7,
        .timer = 1
    },
    [8] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame0,
        .timer = 1
    },
    [10] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame1,
        .timer = 1
    },
    [11] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame2,
        .timer = 1
    },
    [12] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame6,
        .timer = 1
    },
    [13] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame7,
        .timer = 1
    },
    [14] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame8,
        .timer = 1
    },
    [15] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame3,
        .timer = 1
    },
    [16] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame4,
        .timer = 1
    },
    [17] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame5,
        .timer = 1
    },
    [18] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXStaticBeforeVariaCoreOam_0[5] = {
    [0] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_0_Frame3,
        .timer = 20
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXStaticBeforeVariaCoreOam_1[5] = {
    [0] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame6,
        .timer = 2
    },
    [1] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame7,
        .timer = 2
    },
    [2] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame8,
        .timer = 2
    },
    [3] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_0_Frame3,
        .timer = 40
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXStaticBeforeVariaCoreOam_2[5] = {
    [0] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame3,
        .timer = 2
    },
    [1] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame4,
        .timer = 2
    },
    [2] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_3_Frame5,
        .timer = 2
    },
    [3] = {
        .pFrame = sCoreXStaticBeforeVariaCoreOam_0_Frame3,
        .timer = 60
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u32 sVariaXAfterDownloadingGfx[512 * 2] = INCBIN_U32("data/sprites/varia_x_after_downloading.gfx");

static const u8 sBlob_316414_35dd74[] = INCBIN_U8("data/Blob_316414_35dd74.bin");
