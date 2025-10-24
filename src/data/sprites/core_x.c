#include "data/sprites/core_x.h"
#include "macros.h"

const s16 sCoreXIdleYSpeed[65] = {
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

const s16 sCoreXIdleXSpeed[81] = {
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

const u32 sMorphBallCoreXGfx[512 * 5] = INCBIN_U32("data/sprites/morph_ball_core_x.gfx");
const u16 sMorphBallCoreXPal[16 * 5] = INCBIN_U16("data/sprites/morph_ball_core_x.pal");

static const u16 sCoreXShellOam_White_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x28c, 9, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x290, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x310, 9, 0),
};

static const u16 sCoreXShellOam_Yellow_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x28c, 10, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x290, 10, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30c, 10, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x310, 10, 0),
};

static const u16 sCoreXShellOam_Red_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x28c, 11, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x290, 11, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x310, 11, 0),
};

static const u16 sCoreXStaticOam_0_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d2, 9, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2b2, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 9, 0),
};

static const u16 sCoreXStaticOam_0_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d3, 9, 0),
    OAM_ENTRY(7, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f4, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x293, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x295, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x296, 9, 0),
};

static const u16 sCoreXStaticOam_0_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(5, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f3, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x297, 9, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x299, 9, 0),
};

static const u16 sCoreXStaticOam_1_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d5, 9, 0),
    OAM_ENTRY(7, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d6, 9, 0),
};

static const u16 sCoreXStaticOam_1_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b7, 9, 0),
};

static const u16 sCoreXStaticOam_1_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f6, 9, 0),
};

static const u16 sCoreXStaticOam_2_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d7, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_XY_FLIP, 0x2b2, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x292, 9, 0),
};

static const u16 sCoreXStaticOam_2_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f7, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x293, 9, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x295, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x296, 9, 0),
};

static const u16 sCoreXStaticOam_2_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d8, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x297, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 0x299, 9, 0),
};

static const u16 sCoreXAbilityOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sCoreXAbilityOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sCoreXAbilityOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sCoreXAbilityOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sCoreXAbilityOam_Idle_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sCoreXAbilityOam_Idle_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sCoreXAbilityOam_Idle_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sCoreXAbilityOam_Idle_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sCoreXShellOam_Breaking_Frame1[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-20, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2ad, 11, 0),
    OAM_ENTRY(-20, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28d, 11, 0),
    OAM_ENTRY(-28, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2ac, 11, 0),
    OAM_ENTRY(1, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 11, 0),
    OAM_ENTRY(9, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x290, 11, 0),
    OAM_ENTRY(17, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d1, 11, 0),
    OAM_ENTRY(-27, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ec, 11, 0),
    OAM_ENTRY(-27, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(-11, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0),
    OAM_ENTRY(1, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x30f, 11, 0),
    OAM_ENTRY(9, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(17, 10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x311, 11, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_XY_FLIP, 0x312, 9, 0),
};

static const u16 sCoreXShellOam_Breaking_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-6, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-11, -7, OAM_DIMS_16x16, OAM_Y_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-34, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a0, 11, 0),
    OAM_ENTRY(-29, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x281, 11, 0),
    OAM_ENTRY(-22, 25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x301, 11, 0),
    OAM_ENTRY(-30, 17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e0, 11, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a0, 11, 0),
    OAM_ENTRY(6, -17, OAM_DIMS_16x8, OAM_X_FLIP, 0x281, 11, 0),
    OAM_ENTRY(3, 18, OAM_DIMS_16x16, OAM_X_FLIP, 0x301, 11, 0),
    OAM_ENTRY(19, 10, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e0, 11, 0),
};

static const u16 sCoreXShellOam_Breaking_Frame3[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_XY_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-3, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-14, -3, OAM_DIMS_16x16, OAM_Y_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-39, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x283, 11, 0),
    OAM_ENTRY(-39, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c3, 11, 0),
    OAM_ENTRY(-34, 37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x303, 11, 0),
    OAM_ENTRY(-18, 34, OAM_DIMS_8x16, OAM_NO_FLIP, 0x305, 11, 0),
    OAM_ENTRY(9, -5, OAM_DIMS_16x16, OAM_X_FLIP, 0x283, 11, 0),
    OAM_ENTRY(9, 11, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c3, 11, 0),
    OAM_ENTRY(12, 28, OAM_DIMS_16x16, OAM_X_FLIP, 0x303, 11, 0),
    OAM_ENTRY(4, 25, OAM_DIMS_8x16, OAM_X_FLIP, 0x305, 11, 0),
};

static const u16 sCoreXShellOam_Breaking_Frame4[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-8, -3, OAM_DIMS_16x16, OAM_XY_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x312, 9, 0),
    OAM_ENTRY(7, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-24, 9, OAM_DIMS_16x16, OAM_Y_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-23, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x312, 9, 0),
    OAM_ENTRY(8, 9, OAM_DIMS_16x16, OAM_XY_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-43, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2a0, 11, 0),
    OAM_ENTRY(-38, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 0x281, 11, 0),
    OAM_ENTRY(12, 16, OAM_DIMS_16x16, OAM_XY_FLIP, 0x2a0, 11, 0),
    OAM_ENTRY(7, 32, OAM_DIMS_16x8, OAM_XY_FLIP, 0x281, 11, 0),
    OAM_ENTRY(-38, 58, OAM_DIMS_16x16, OAM_X_FLIP, 0x301, 11, 0),
    OAM_ENTRY(-22, 50, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e0, 11, 0),
    OAM_ENTRY(14, 44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x301, 11, 0),
    OAM_ENTRY(6, 36, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e0, 11, 0),
};

static const u16 sCoreXShellOam_Breaking_Frame5[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-6, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-10, 1, OAM_DIMS_16x16, OAM_XY_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-17, -10, OAM_DIMS_16x16, OAM_Y_FLIP, 0x312, 9, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x312, 9, 0),
    OAM_ENTRY(20, -17, OAM_DIMS_8x8, OAM_XY_FLIP, 0x332, 9, 0),
    OAM_ENTRY(-25, 25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x333, 9, 0),
    OAM_ENTRY(-28, -17, OAM_DIMS_8x8, OAM_Y_FLIP, 0x332, 9, 0),
    OAM_ENTRY(17, 25, OAM_DIMS_8x8, OAM_X_FLIP, 0x333, 9, 0),
    OAM_ENTRY(-47, 35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x303, 11, 0),
    OAM_ENTRY(-31, 32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x305, 11, 0),
    OAM_ENTRY(-39, 80, OAM_DIMS_16x16, OAM_X_FLIP, 0x301, 11, 0),
    OAM_ENTRY(-23, 72, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e0, 11, 0),
    OAM_ENTRY(2, 46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x303, 11, 0),
    OAM_ENTRY(18, 43, OAM_DIMS_8x16, OAM_NO_FLIP, 0x305, 11, 0),
    OAM_ENTRY(15, 54, OAM_DIMS_16x16, OAM_NO_FLIP, 0x301, 11, 0),
    OAM_ENTRY(7, 46, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e0, 11, 0),
};

static const u16 sCoreXShellOam_Breaking_Frame6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-40, 48, OAM_DIMS_16x16, OAM_X_FLIP, 0x312, 11, 0),
    OAM_ENTRY(8, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 11, 0),
    OAM_ENTRY(-40, 96, OAM_DIMS_16x16, OAM_XY_FLIP, 0x312, 11, 0),
    OAM_ENTRY(9, 72, OAM_DIMS_16x16, OAM_Y_FLIP, 0x312, 11, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-10, 6, OAM_DIMS_16x16, OAM_XY_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x16, OAM_Y_FLIP, 0x312, 9, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x332, 9, 0),
};

static const u16 sCoreXShellOam_Breaking_Frame7[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-40, 62, OAM_DIMS_8x8, OAM_Y_FLIP, 0x332, 11, 0),
    OAM_ENTRY(16, 80, OAM_DIMS_8x8, OAM_XY_FLIP, 0x332, 11, 0),
    OAM_ENTRY(-40, 120, OAM_DIMS_8x8, OAM_NO_FLIP, 0x332, 11, 0),
    OAM_ENTRY(16, 104, OAM_DIMS_8x8, OAM_X_FLIP, 0x332, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x333, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x333, 9, 0),
    OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_XY_FLIP, 0x333, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x333, 9, 0),
};

static const u16 sCoreXOam_Empty[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ef, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29a, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x29a, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x29a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x29a, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29c, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x29c, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x29c, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x29c, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x29e, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame12[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x2da, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame16[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2dc, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2dc, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2dc, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x2dc, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame20[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2de, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2de, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x2de, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2de, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame24[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x314, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x314, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x314, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x314, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame28[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x316, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x316, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x316, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x316, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame32[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x318, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x318, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x318, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x318, 9, 0),
};

static const u16 sCoreXAbilityAuraOam_Frame36[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x31a, 9, 0),
};

static const u16 sCoreXAbilityOam_GettingAbsorbed_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x286, 8, 0),
};

static const u16 sCoreXAbilityOam_GettingAbsorbed_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -18, OAM_DIMS_32x32, OAM_NO_FLIP, 0x286, 8, 0),
};

const struct FrameData sCoreXAbilityOam_Idle[9] = {
    [0] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame7,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXAbilityOam_IdleFast[9] = {
    [0] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sCoreXAbilityOam_Idle_Frame7,
        .timer = 2
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXAbilityOam_GettingAbsorbed[3] = {
    [0] = {
        .pFrame = sCoreXAbilityOam_GettingAbsorbed_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sCoreXAbilityOam_GettingAbsorbed_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXStaticOam_0[5] = {
    [0] = {
        .pFrame = sCoreXStaticOam_0_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sCoreXStaticOam_0_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sCoreXStaticOam_0_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 20
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXStaticOam_1[5] = {
    [0] = {
        .pFrame = sCoreXStaticOam_1_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sCoreXStaticOam_1_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sCoreXStaticOam_1_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 40
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXStaticOam_2[5] = {
    [0] = {
        .pFrame = sCoreXStaticOam_2_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sCoreXStaticOam_2_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sCoreXStaticOam_2_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 60
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXStaticOam_Unused[19] = {
    [0] = {
        .pFrame = sCoreXStaticOam_0_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sCoreXStaticOam_0_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sCoreXStaticOam_0_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sCoreXStaticOam_2_Frame0,
        .timer = 1
    },
    [4] = {
        .pFrame = sCoreXStaticOam_2_Frame1,
        .timer = 1
    },
    [5] = {
        .pFrame = sCoreXStaticOam_2_Frame2,
        .timer = 1
    },
    [6] = {
        .pFrame = sCoreXStaticOam_1_Frame0,
        .timer = 1
    },
    [7] = {
        .pFrame = sCoreXStaticOam_1_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sCoreXStaticOam_1_Frame2,
        .timer = 1
    },
    [9] = {
        .pFrame = sCoreXStaticOam_0_Frame0,
        .timer = 1
    },
    [10] = {
        .pFrame = sCoreXStaticOam_0_Frame1,
        .timer = 1
    },
    [11] = {
        .pFrame = sCoreXStaticOam_0_Frame2,
        .timer = 1
    },
    [12] = {
        .pFrame = sCoreXStaticOam_1_Frame0,
        .timer = 1
    },
    [13] = {
        .pFrame = sCoreXStaticOam_1_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sCoreXStaticOam_1_Frame2,
        .timer = 1
    },
    [15] = {
        .pFrame = sCoreXStaticOam_2_Frame0,
        .timer = 1
    },
    [16] = {
        .pFrame = sCoreXStaticOam_2_Frame1,
        .timer = 1
    },
    [17] = {
        .pFrame = sCoreXStaticOam_2_Frame2,
        .timer = 1
    },
    [18] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXShellOam_Breaking[9] = {
    [0] = {
        .pFrame = sCoreXShellOam_Red_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sCoreXShellOam_Breaking_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sCoreXShellOam_Breaking_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sCoreXShellOam_Breaking_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sCoreXShellOam_Breaking_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sCoreXShellOam_Breaking_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sCoreXShellOam_Breaking_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sCoreXShellOam_Breaking_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXAbilityAuraOam_Slow[41] = {
    [0] = {
        .pFrame = sCoreXAbilityAuraOam_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [2] = {
        .pFrame = sCoreXAbilityAuraOam_Frame0,
        .timer = 2
    },
    [3] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [4] = {
        .pFrame = sCoreXAbilityAuraOam_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [6] = {
        .pFrame = sCoreXAbilityAuraOam_Frame4,
        .timer = 2
    },
    [7] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [8] = {
        .pFrame = sCoreXAbilityAuraOam_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [10] = {
        .pFrame = sCoreXAbilityAuraOam_Frame8,
        .timer = 2
    },
    [11] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [12] = {
        .pFrame = sCoreXAbilityAuraOam_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [14] = {
        .pFrame = sCoreXAbilityAuraOam_Frame12,
        .timer = 2
    },
    [15] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [16] = {
        .pFrame = sCoreXAbilityAuraOam_Frame16,
        .timer = 2
    },
    [17] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [18] = {
        .pFrame = sCoreXAbilityAuraOam_Frame16,
        .timer = 2
    },
    [19] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [20] = {
        .pFrame = sCoreXAbilityAuraOam_Frame20,
        .timer = 2
    },
    [21] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [22] = {
        .pFrame = sCoreXAbilityAuraOam_Frame20,
        .timer = 2
    },
    [23] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [24] = {
        .pFrame = sCoreXAbilityAuraOam_Frame24,
        .timer = 2
    },
    [25] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [26] = {
        .pFrame = sCoreXAbilityAuraOam_Frame24,
        .timer = 2
    },
    [27] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [28] = {
        .pFrame = sCoreXAbilityAuraOam_Frame28,
        .timer = 2
    },
    [29] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [30] = {
        .pFrame = sCoreXAbilityAuraOam_Frame28,
        .timer = 2
    },
    [31] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [32] = {
        .pFrame = sCoreXAbilityAuraOam_Frame32,
        .timer = 2
    },
    [33] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [34] = {
        .pFrame = sCoreXAbilityAuraOam_Frame32,
        .timer = 2
    },
    [35] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [36] = {
        .pFrame = sCoreXAbilityAuraOam_Frame36,
        .timer = 2
    },
    [37] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [38] = {
        .pFrame = sCoreXAbilityAuraOam_Frame36,
        .timer = 2
    },
    [39] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 2
    },
    [40] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXAbilityAuraOam_Fast[41] = {
    [0] = {
        .pFrame = sCoreXAbilityAuraOam_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [2] = {
        .pFrame = sCoreXAbilityAuraOam_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [4] = {
        .pFrame = sCoreXAbilityAuraOam_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [6] = {
        .pFrame = sCoreXAbilityAuraOam_Frame4,
        .timer = 1
    },
    [7] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [8] = {
        .pFrame = sCoreXAbilityAuraOam_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [10] = {
        .pFrame = sCoreXAbilityAuraOam_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [12] = {
        .pFrame = sCoreXAbilityAuraOam_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [14] = {
        .pFrame = sCoreXAbilityAuraOam_Frame12,
        .timer = 1
    },
    [15] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [16] = {
        .pFrame = sCoreXAbilityAuraOam_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [18] = {
        .pFrame = sCoreXAbilityAuraOam_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [20] = {
        .pFrame = sCoreXAbilityAuraOam_Frame20,
        .timer = 1
    },
    [21] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [22] = {
        .pFrame = sCoreXAbilityAuraOam_Frame20,
        .timer = 1
    },
    [23] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [24] = {
        .pFrame = sCoreXAbilityAuraOam_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [26] = {
        .pFrame = sCoreXAbilityAuraOam_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [28] = {
        .pFrame = sCoreXAbilityAuraOam_Frame28,
        .timer = 1
    },
    [29] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [30] = {
        .pFrame = sCoreXAbilityAuraOam_Frame28,
        .timer = 1
    },
    [31] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [32] = {
        .pFrame = sCoreXAbilityAuraOam_Frame32,
        .timer = 1
    },
    [33] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [34] = {
        .pFrame = sCoreXAbilityAuraOam_Frame32,
        .timer = 1
    },
    [35] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [36] = {
        .pFrame = sCoreXAbilityAuraOam_Frame36,
        .timer = 1
    },
    [37] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [38] = {
        .pFrame = sCoreXAbilityAuraOam_Frame36,
        .timer = 1
    },
    [39] = {
        .pFrame = sCoreXOam_Empty,
        .timer = 1
    },
    [40] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXShellOam_White[2] = {
    [0] = {
        .pFrame = sCoreXShellOam_White_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXShellOam_Yellow[2] = {
    [0] = {
        .pFrame = sCoreXShellOam_Yellow_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCoreXShellOam_Red[2] = {
    [0] = {
        .pFrame = sCoreXShellOam_Red_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u32 sHiJumpCoreXGfx[512 * 5] = INCBIN_U32("data/sprites/hi_jump_core_x.gfx");
const u16 sHiJumpCoreXPal[16 * 5] = INCBIN_U16("data/sprites/hi_jump_core_x.pal");
const u32 sSpeedBoosterCoreXGfx[512 * 5] = INCBIN_U32("data/sprites/speed_booster_core_x.gfx");
const u16 sSpeedBoosterCoreXPal[16 * 5] = INCBIN_U16("data/sprites/speed_booster_core_x.pal");
const u32 sSpaceJumpCoreXGfx[512 * 5] = INCBIN_U32("data/sprites/space_jump_core_x.gfx");
const u16 sSpaceJumpCoreXPal[16 * 5] = INCBIN_U16("data/sprites/space_jump_core_x.pal");
const u32 sGravityCoreXGfx[512 * 5] = INCBIN_U32("data/sprites/gravity_core_x.gfx");
const u16 sGravityCoreXPal[16 * 5] = INCBIN_U16("data/sprites/gravity_core_x.pal");
const u32 sScrewAttackCoreXGfx[512 * 5] = INCBIN_U32("data/sprites/screw_attack_core_x.gfx");
const u16 sScrewAttackCoreXPal[16 * 5] = INCBIN_U16("data/sprites/screw_attack_core_x.pal");

static const u8 sBlob_312fe8_35dd74[] = INCBIN_U8("data/Blob_312fe8_35dd74.bin");
