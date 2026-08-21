#include "data/sprites/ridley_pre_spawn.h"
#include "macros.h"

const u32 sRidleyPreSpawnGfx[512 * 2] = INCBIN_U32("data/sprites/ridley_pre_spawn.gfx");
const u16 sRidleyPreSpawnPal[16 * 2] = INCBIN_U16("data/sprites/ridley_pre_spawn.pal");

static const u16 sRidleyPreSpawnOam_Idle_Frame0[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-32, -71, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-32, -39, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -63, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(32, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(48, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-40, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(32, -55, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-40, -55, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-40, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(0, -71, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-24, -87, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sRidleyPreSpawnOam_OpeningEye_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, -68, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 8, 0),
    OAM_ENTRY(-32, -71, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-32, -39, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -63, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(32, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(48, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-40, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(32, -55, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-40, -55, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-40, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(0, -71, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-24, -87, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sRidleyPreSpawnOam_OpeningEye_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, -68, OAM_DIMS_8x8, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-32, -71, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-32, -39, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -63, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(32, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(48, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-40, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(32, -55, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-40, -55, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-40, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(0, -71, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-24, -87, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sRidleyPreSpawnOam_OpeningEye_Frame2[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, -68, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-32, -71, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-32, -39, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -63, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(32, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(48, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-40, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(32, -55, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-40, -55, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-40, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(0, -71, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-24, -87, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sRidleyPreSpawnOam_OpeningEye_Frame3[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, -68, OAM_DIMS_8x8, OAM_NO_FLIP, 0x276, 8, 0),
    OAM_ENTRY(-32, -71, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-32, -39, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -63, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(32, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(48, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-40, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(32, -55, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-40, -55, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-40, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(0, -71, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-24, -87, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sRidleyPreSpawnOam_OpeningEye_Frame4[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, -68, OAM_DIMS_8x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -71, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-32, -39, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -63, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(32, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(48, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-40, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(32, -55, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-40, -55, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-40, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(0, -71, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-24, -87, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
};

const struct FrameData sRidleyPreSpawnOam_Idle[2] = {
    [0] = {
        .pFrame = sRidleyPreSpawnOam_Idle_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyPreSpawnOam_OpeningEye[7] = {
    [0] = {
        .pFrame = sRidleyPreSpawnOam_OpeningEye_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sRidleyPreSpawnOam_OpeningEye_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sRidleyPreSpawnOam_OpeningEye_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sRidleyPreSpawnOam_OpeningEye_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sRidleyPreSpawnOam_OpeningEye_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sRidleyPreSpawnOam_OpeningEye_Frame3,
        .timer = 255
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyPreSpawnOam_ClosingEye[4] = {
    [0] = {
        .pFrame = sRidleyPreSpawnOam_OpeningEye_Frame2,
        .timer = 4
    },
    [1] = {
        .pFrame = sRidleyPreSpawnOam_OpeningEye_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sRidleyPreSpawnOam_OpeningEye_Frame0,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};
