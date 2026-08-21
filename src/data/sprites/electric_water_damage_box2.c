#include "data/sprites/electric_water_damage_box2.h"
#include "macros.h"

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-10, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-5, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(1, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(2, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-3, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Stopping_Frame6[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(1, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(1, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x235, 8, 0),
    OAM_ENTRY(1, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-9, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-13, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-9, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(2, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(4, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-9, -31, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(1, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(2, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-3, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Stopping_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x235, 8, 0),
    OAM_ENTRY(3, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(5, -23, OAM_DIMS_8x8, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(1, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Stopping_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x203, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-10, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame10[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-5, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(1, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame11[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-10, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-10, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x235, 8, 0),
    OAM_ENTRY(-10, -13, OAM_DIMS_8x8, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x230, 8, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_8x8, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x8, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-11, -36, OAM_DIMS_8x8, OAM_X_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-13, -30, OAM_DIMS_8x8, OAM_X_FLIP, 0x231, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_8x8, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-10, -19, OAM_DIMS_8x8, OAM_X_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-11, -30, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-6, -11, OAM_DIMS_8x8, OAM_X_FLIP, 0x233, 8, 0),
};

static const u16 sElectricWaterDamageBox2Oam_Idle_Frame12[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x235, 8, 0),
    OAM_ENTRY(-10, -21, OAM_DIMS_8x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-12, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x214, 8, 0),
};


const struct FrameData sElectricWaterDamageBox2Oam_Idle[14] = {
    [0] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame7,
        .timer = 6
    },
    [8] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame8,
        .timer = 6
    },
    [9] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame9,
        .timer = 6
    },
    [10] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame10,
        .timer = 6
    },
    [11] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame11,
        .timer = 6
    },
    [12] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame12,
        .timer = 6
    },
    [13] = FRAME_DATA_TERMINATOR
};

const struct FrameData sElectricWaterDamageBox2Oam_Stopping[10] = {
    [0] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sElectricWaterDamageBox2Oam_Idle_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sElectricWaterDamageBox2Oam_Stopping_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sElectricWaterDamageBox2Oam_Stopping_Frame7,
        .timer = 6
    },
    [8] = {
        .pFrame = sElectricWaterDamageBox2Oam_Stopping_Frame8,
        .timer = 10
    },
    [9] = FRAME_DATA_TERMINATOR
};
