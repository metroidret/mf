#include "data/sprites/geega.h"
#include "macros.h"

const s16 sGeega_3791d4[65] = {
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

const u32 sGeegaGfx[512 * 1] = INCBIN_U32("data/sprites/geega.gfx");
const u16 sGeegaPal[16 * 1] = INCBIN_U16("data/sprites/geega.pal");

static const u16 sGeegaOam_GoingUp_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeegaOam_GoingUp_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sGeegaOam_GoingUp_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sGeegaOam_GoingForward_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sGeegaOam_GoingForward_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sGeegaOam_GoingForward_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

const struct FrameData sGeegaOam_GoingUp[5] = {
    [0] = {
        .pFrame = sGeegaOam_GoingUp_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sGeegaOam_GoingUp_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sGeegaOam_GoingUp_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sGeegaOam_GoingUp_Frame1,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeegaOam_GoingForward[5] = {
    [0] = {
        .pFrame = sGeegaOam_GoingForward_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sGeegaOam_GoingForward_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sGeegaOam_GoingForward_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sGeegaOam_GoingForward_Frame1,
        .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};
