#include "data/sprites/mimic.h"
#include "macros.h"

const s16 sMimicFlyingYMovement[65] = {
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

const u32 sMimicEnergyTankGfx[1 * 512] = INCBIN_U32("data/sprites/mimic_energy_tank.gfx");
const u16 sMimicEnergyTankPal[1 * 16] = INCBIN_U16("data/sprites/mimic_energy_tank.pal");

static const u16 sMimicEnergyTankOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sMimicEnergyTankOam_WakingUp_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-15, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(7, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x219, 8, 0),
};

static const u16 sMimicEnergyTankOam_WakingUp_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-15, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(7, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 8, 0),
};

static const u16 sMimicEnergyTankOam_WakingUp_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-13, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(5, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
};

static const u16 sMimicEnergyTankOam_WakingUp_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
};

static const u16 sMimicEnergyTankOam_WakingUp_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
};

static const u16 sMimicEnergyTankOam_WakingUp_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
};

static const u16 sMimicEnergyTankOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sMimicEnergyTankOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

const struct FrameData sMimicEnergyTankOam_Idle[5] = {
    [0] = {
        .pFrame = sMimicEnergyTankOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sMimicEnergyTankOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sMimicEnergyTankOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sMimicEnergyTankOam_Idle_Frame0,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMimicEnergyTankOam_WakingUp[7] = {
    [0] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame3,
        .timer = 11
    },
    [4] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame5,
        .timer = 15
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMimicEnergyTankOam_Flying[5] = {
    [0] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame3,
        .timer = 4
    },
    [1] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame4,
        .timer = 4
    },
    [2] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame5,
        .timer = 4
    },
    [3] = {
        .pFrame = sMimicEnergyTankOam_WakingUp_Frame4,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u32 sMimicMissileTankGfx[1 * 512] = INCBIN_U32("data/sprites/mimic_missile_tank.gfx");
const u16 sMimicMissileTankPal[1 * 16] = INCBIN_U16("data/sprites/mimic_missile_tank.pal");

static const u16 sMimicMissileTankOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sMimicMissileTankOam_WakingUp_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(2, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(8, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x219, 8, 0),
};

static const u16 sMimicMissileTankOam_WakingUp_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-15, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(7, -20, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-10, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(2, -3, OAM_DIMS_8x8, OAM_X_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sMimicMissileTankOam_WakingUp_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 8, 0),
};

static const u16 sMimicMissileTankOam_WakingUp_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 8, 0),
};

static const u16 sMimicMissileTankOam_WakingUp_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
};

static const u16 sMimicMissileTankOam_WakingUp_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
};

static const u16 sMimicMissileTankOam_WakingUp_Frame6[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-22, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(6, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
};

static const u16 sMimicMissileTankOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sMimicMissileTankOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

const struct FrameData sMimicMissileTankOam_Idle[5] = {
    [0] = {
        .pFrame = sMimicMissileTankOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sMimicMissileTankOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sMimicMissileTankOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sMimicMissileTankOam_Idle_Frame0,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMimicMissileTankOam_WakingUp[8] = {
    [0] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame3,
        .timer = 15
    },
    [4] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame4,
        .timer = 9
    },
    [5] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame5,
        .timer = 9
    },
    [6] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame6,
        .timer = 10
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMimicMissileTankOam_Flying[5] = {
    [0] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame4,
        .timer = 4
    },
    [1] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame5,
        .timer = 4
    },
    [2] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame6,
        .timer = 4
    },
    [3] = {
        .pFrame = sMimicMissileTankOam_WakingUp_Frame5,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_37e2a4_386718[] = INCBIN_U8("data/Blob_37e2a4_386718.bin");
