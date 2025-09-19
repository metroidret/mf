#include "data/sprites/sa_x.h"
#include "macros.h"

const s16 sSaXBeamForwardYMovement[4] = {
    64, -128, 64, SHORT_MAX
};

const s16 sSaXBeamDiagonalYMovement[4] = {
    52, -104, 52, SHORT_MAX
};

const s16 sSaXBeamDiagonalXMovement[4] = {
    -52, 104, -52, SHORT_MAX
};

const s16 sSaXWalkingSpeed[8] = {
    1, 2, 2, 2, 2, 2, 2, 2
};

const s16 sSaXRunningSpeed[8] = {
    4, 6, 8, 8, 8, 10, 10, 12
};

const s16 sSaXJumpYVelocity_0[10] = {
    -8, -4, 4, 8,
    12, 16, 16, 16,
    16, 16
};

const s16 sSaXJumpYVelocity_1[10] = {
    -8, -6, -4, 0,
    4, 8, 12, 16,
    16, 16
};

const s16 sSaXJumpYVelocity_2[10] = {
    -8, -12, -12, -8,
    -4, 0, 4, 8,
    12, 16
};

const s16 sSaXJumpYVelocity_3[18] = {
    -8, -12, -16, -16,
    -16, -12, -8, -6,
    -4, -2, 0, 0,
    0, 0, 4, 8,
    12, 16
};

const s16 sSaXJumpYVelocity_4[10] = {
    -2, -1, 2, 4,
    6, 8, 10, 12,
    16, 16
};

const s16 sSaXBossSpinJumpYVelocity_2[11] = {
    -8, -12, -16, -12,
    -8, -4, 0, 4,
    8, 12, 16
};

const s16 sSaXBossSpinJumpYVelocity_5[18] = {
    -8, -12, -16, -20,
    -16, -12, -8, -6,
    -4, -2, 0, 0,
    0, 0, 4, 8,
    12, 16
};

const s16 sSaXBossJumpYVelocity_1[10] = {
    -8, -12, -12, -8,
    -4, 0, 4, 8,
    12, 16
};

const s16 sSaXBossJumpYVelocity_2[10] = {
    -8, -12, -16, -12,
    -8, -4, 4, 8,
    12, 16
};

const s16 sSaXBossJumpYVelocity_3[10] = {
    0, 2, 0, -2,
    0, 2, 4, 8,
    12, 16
};

const s16 sSaX_2e6cc6[6] = {
    4, 6, 8, 10, 12, 16
};

const s16 sSaXBossKnockbackYMovement[12] = {
    -12, -10, -8, -6,
    -4, -2, 0, 0,
    0, 0, 0, SHORT_MAX
};

const s16 sSaX_2e6cea[28] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    -12, -10, -8, -6,
    -4, -2, 0, 0,
    0, 0, 0, SHORT_MAX,
    0, 0, 0, 0,
    0, 0, 0, 0
};

const u16 sSaXMosaicValues[30] = {
    0x11, 0x22, 0x33, 0x44,
    0x55, 0x66, 0x77, 0x88,
    0x77, 0x66, 0x55, 0x44,
    0x33, 0x22, 0x11, 0x22,
    0x33, 0x44, 0x55, 0x66,
    0x77, 0x88, 0x77, 0x66,
    0x55, 0x44, 0x33, 0x22,
    0x11, 0x00
};

const u32 sSaXWeaponsGfx[2 * 512] = INCBIN_U32("data/sa_x/weapons.gfx");
const u16 sSaXPalette_Default[2 * 16] = INCBIN_U16("data/sa_x/default.pal");

static const u16 sSaXBeamOam_Forward_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 576, 9, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 608, 9, 0),
};

static const u16 sSaXBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 578, 9, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 609, 9, 0),
};

static const u16 sSaXBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 580, 9, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 581, 9, 0),
};

static const u16 sSaXOam_Placeholder_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(6, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(6, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sSaXPowerBombOam_SpinningSlow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 584, 3, 0),
};

static const u16 sSaXPowerBombOam_SpinningSlow_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 585, 3, 0),
};

static const u16 sSaXPowerBombOam_SpinningSlow_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 586, 3, 0),
};

static const u16 sSaXMissileOam_Forward_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_X_FLIP, 591, 3, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 591, 3, 0),
    OAM_ENTRY(11, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 591, 3, 0),
    OAM_ENTRY(5, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 591, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 616, 3, 0),
};

static const u16 sSaXMissileOam_Forward_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 624, 3, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 592, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 616, 3, 0),
};

static const u16 sSaXMissileOam_Diagonal_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, 0, OAM_DIMS_8x8, OAM_X_FLIP, 591, 3, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 591, 3, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 591, 3, 0),
    OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_XY_FLIP, 591, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 582, 3, 0),
};

static const u16 sSaXMissileOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 623, 3, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 592, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 582, 3, 0),
};

static const u16 sSaXElevatorOam_2e8038_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-19, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 591, 3, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_X_FLIP, 591, 3, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 591, 3, 0),
    OAM_ENTRY(-13, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 591, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 616, 3, 0),
};

static const u16 sSaXElevatorOam_2e8038_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-20, -4, OAM_DIMS_8x8, OAM_X_FLIP, 624, 3, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_X_FLIP, 592, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 616, 3, 0),
};

static const u16 sSaXMissileOam_Diagonal_XFlipped_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 591, 3, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_8x8, OAM_X_FLIP, 591, 3, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_XY_FLIP, 591, 3, 0),
    OAM_ENTRY(-15, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 591, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 582, 3, 0),
};

static const u16 sSaXMissileOam_Diagonal_XFlipped_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-15, 7, OAM_DIMS_8x8, OAM_X_FLIP, 623, 3, 0),
    OAM_ENTRY(-10, 2, OAM_DIMS_8x8, OAM_X_FLIP, 592, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 582, 3, 0),
};

static const u16 sLabExplosionOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-19, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-19, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(4, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(4, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame18[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-10, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame19[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-10, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame24[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-22, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame25[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-22, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame30[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame31[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame33[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-21, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame34[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-21, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame42[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame43[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame45[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(5, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame46[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(5, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 9, 0),
};

static const u16 sLabExplosionOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 613, 9, 0),
};

const struct FrameData sSaXOam_Placeholder[2] = {
    [0] = {
        .pFrame = sSaXOam_Placeholder_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSaXBeamOam_Forward[2] = {
    [0] = {
        .pFrame = sSaXBeamOam_Forward_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSaXBeamOam_Diagonal[2] = {
    [0] = {
        .pFrame = sSaXBeamOam_Diagonal_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSaXBeamOam_Vertical[2] = {
    [0] = {
        .pFrame = sSaXBeamOam_Vertical_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSaXMissileOam_Diagonal[3] = {
    [0] = {
        .pFrame = sSaXMissileOam_Diagonal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSaXMissileOam_Diagonal_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSaXMissileOam_Forward[3] = {
    [0] = {
        .pFrame = sSaXMissileOam_Forward_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSaXMissileOam_Forward_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSaXPowerBombOam_SpinningSlow[4] = {
    [0] = {
        .pFrame = sSaXPowerBombOam_SpinningSlow_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSaXPowerBombOam_SpinningSlow_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSaXPowerBombOam_SpinningSlow_Frame2,
        .timer = 8
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSaXPowerBombOam_SpinningFast[4] = {
    [0] = {
        .pFrame = sSaXPowerBombOam_SpinningSlow_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sSaXPowerBombOam_SpinningSlow_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sSaXPowerBombOam_SpinningSlow_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSaXMissileOam_Diagonal_XFlipped[3] = {
    [0] = {
        .pFrame = sSaXMissileOam_Diagonal_XFlipped_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSaXMissileOam_Diagonal_XFlipped_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSaXElevatorOam_2e8038[3] = {
    [0] = {
        .pFrame = sSaXElevatorOam_2e8038_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSaXElevatorOam_2e8038_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLabExplosionOam_Idle[49] = {
    [0] = {
        .pFrame = sLabExplosionOam_Idle_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sLabExplosionOam_Idle_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sLabExplosionOam_Idle_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sLabExplosionOam_Idle_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 4
    },
    [6] = {
        .pFrame = sLabExplosionOam_Idle_Frame3,
        .timer = 2
    },
    [7] = {
        .pFrame = sLabExplosionOam_Idle_Frame4,
        .timer = 2
    },
    [8] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 16
    },
    [9] = {
        .pFrame = sLabExplosionOam_Idle_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sLabExplosionOam_Idle_Frame10,
        .timer = 2
    },
    [11] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 4
    },
    [12] = {
        .pFrame = sLabExplosionOam_Idle_Frame9,
        .timer = 2
    },
    [13] = {
        .pFrame = sLabExplosionOam_Idle_Frame10,
        .timer = 2
    },
    [14] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 8
    },
    [15] = {
        .pFrame = sLabExplosionOam_Idle_Frame0,
        .timer = 2
    },
    [16] = {
        .pFrame = sLabExplosionOam_Idle_Frame1,
        .timer = 2
    },
    [17] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 4
    },
    [18] = {
        .pFrame = sLabExplosionOam_Idle_Frame18,
        .timer = 2
    },
    [19] = {
        .pFrame = sLabExplosionOam_Idle_Frame19,
        .timer = 2
    },
    [20] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 4
    },
    [21] = {
        .pFrame = sLabExplosionOam_Idle_Frame3,
        .timer = 2
    },
    [22] = {
        .pFrame = sLabExplosionOam_Idle_Frame4,
        .timer = 2
    },
    [23] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 4
    },
    [24] = {
        .pFrame = sLabExplosionOam_Idle_Frame24,
        .timer = 2
    },
    [25] = {
        .pFrame = sLabExplosionOam_Idle_Frame25,
        .timer = 2
    },
    [26] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 4
    },
    [27] = {
        .pFrame = sLabExplosionOam_Idle_Frame24,
        .timer = 2
    },
    [28] = {
        .pFrame = sLabExplosionOam_Idle_Frame25,
        .timer = 2
    },
    [29] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 24
    },
    [30] = {
        .pFrame = sLabExplosionOam_Idle_Frame30,
        .timer = 2
    },
    [31] = {
        .pFrame = sLabExplosionOam_Idle_Frame31,
        .timer = 2
    },
    [32] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 16
    },
    [33] = {
        .pFrame = sLabExplosionOam_Idle_Frame33,
        .timer = 2
    },
    [34] = {
        .pFrame = sLabExplosionOam_Idle_Frame34,
        .timer = 2
    },
    [35] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 4
    },
    [36] = {
        .pFrame = sLabExplosionOam_Idle_Frame33,
        .timer = 2
    },
    [37] = {
        .pFrame = sLabExplosionOam_Idle_Frame34,
        .timer = 2
    },
    [38] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 24
    },
    [39] = {
        .pFrame = sLabExplosionOam_Idle_Frame30,
        .timer = 2
    },
    [40] = {
        .pFrame = sLabExplosionOam_Idle_Frame31,
        .timer = 2
    },
    [41] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 8
    },
    [42] = {
        .pFrame = sLabExplosionOam_Idle_Frame42,
        .timer = 2
    },
    [43] = {
        .pFrame = sLabExplosionOam_Idle_Frame43,
        .timer = 2
    },
    [44] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 20
    },
    [45] = {
        .pFrame = sLabExplosionOam_Idle_Frame45,
        .timer = 2
    },
    [46] = {
        .pFrame = sLabExplosionOam_Idle_Frame46,
        .timer = 2
    },
    [47] = {
        .pFrame = sLabExplosionOam_Idle_Frame2,
        .timer = 8
    },
    [48] = FRAME_DATA_TERMINATOR
};

const u32 sSaXLabExplosionsGfx[2 * 512] = INCBIN_U32("data/sa_x/lab_explosions.gfx");
const u16 sSaXLabExplosionsPal[2 * 16] = INCBIN_U16("data/sa_x/lab_explosions.pal");

static const u8 sBlob_2e9218_2ed2e8[] = INCBIN_U8("data/Blob_2e9218_2ed2e8.bin");
