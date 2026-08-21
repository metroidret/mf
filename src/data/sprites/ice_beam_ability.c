#include "data/sprites/ice_beam_ability.h"
#include "macros.h"

const s16 sIceBeamAbilityOmegaFloatingBeforeSaXYMovement[65] = {
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

const s16 sIceBeamAbilityOmegaFloatingBeforeSaXXMovement[81] = {
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

const u32 sIceBeamAbilityOmegaGfx[512 * 2] = INCBIN_U32("data/sprites/ice_beam_ability.gfx");
const u16 sIceBeamAbilityOmegaPal[16 * 1] = INCBIN_U16("data/sprites/ice_beam_ability.pal");

static const u16 sIceBeamAbilityOmegaOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-11, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(5, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 8, 0),
};

static const u16 sIceBeamAbilityOmegaOam_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-11, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sIceBeamAbilityOmegaOam_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sIceBeamAbilityOmegaOam_Idle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
};

static const u16 sIceBeamAbilityOmegaOam_Idle_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-13, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-13, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20d, 8, 0),
};

static const u16 sIceBeamAbilityOmegaOam_Idle_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-15, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-7, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x270, 8, 0),
};

static const u16 sIceBeamAbilityOmegaOam_Idle_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-7, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
};

static const u16 sIceBeamAbilityOmegaOam_Idle_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x279, 8, 0),
    OAM_ENTRY(8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 8, 0),
};

static const u16 sIceBeamAbilityOmegaOam_GettingAbsorbed_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sIceBeamAbilityOmegaOam_GettingAbsorbed_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -18, OAM_DIMS_32x32, OAM_NO_FLIP, 0x21c, 8, 0),
};

const struct FrameData sIceBeamAbilityOmegaOam_Idle[9] = {
    [0] = {
        .pFrame = sIceBeamAbilityOmegaOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sIceBeamAbilityOmegaOam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sIceBeamAbilityOmegaOam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sIceBeamAbilityOmegaOam_Idle_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sIceBeamAbilityOmegaOam_Idle_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sIceBeamAbilityOmegaOam_Idle_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sIceBeamAbilityOmegaOam_Idle_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sIceBeamAbilityOmegaOam_Idle_Frame7,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamAbilityOmegaOam_GettingAbsorbed[3] = {
    [0] = {
        .pFrame = sIceBeamAbilityOmegaOam_GettingAbsorbed_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sIceBeamAbilityOmegaOam_GettingAbsorbed_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};
