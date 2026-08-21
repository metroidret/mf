#include "data/sprites/mega_x.h"
#include "macros.h"

const s16 sVariaSuitAbilitySpawningYMovement[65] = {
    0, 0, 0, 0,
    1, 1, 1, 1,
    2, 2, 2, 2,
    3, 3, 3, 3,
    4, 4, 4, 4,
    4, 3, 2, 1,
    0, 0, 0, 0,
    -1, -2, -3, -4,
    -6, -8, -10, -12,
    -14, -16, -18, -20,
    -24, -28, -32, -32,
    -32, -32, -28, -24,
    -20, -18, -16, -14,
    -12, -10, -8, -7,
    -6, -5, -4, -3,
    -2, -1, -1, 0,
    SHORT_MAX
};

const s16 sVariaSuitAbilitySpawningXMovement[57] = {
    0, -1, -2, -3,
    -4, -5, -6, -7,
    -8, -9, -10, -11,
    -12, -14, -16, -18,
    -20, -24, -28, -32,
    -32, -32, -32, -32,
    -32, -32, -32, -32,
    -32, -32, -32, -32,
    -32, -32, -32, -32,
    -32, -32, -32, -32,
    -32, -28, -24, -20,
    -18, -16, -14, -12,
    -10, -8, -6, -4,
    -2, -1, -1, 0,
    SHORT_MAX
};

const u32 sMegaXGfx[8 * 512] = INCBIN_U32("data/sprites/mega_x.gfx");
const u16 sMegaXPal[8 * 16] = INCBIN_U16("data/sprites/mega_x.pal");

static const u16 sMegaXOam_3a5e40_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x28c, 9, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x290, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x310, 9, 0),
};

static const u16 sMegaXOam_3a5e50_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x28c, 10, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x290, 10, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30c, 10, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x310, 10, 0),
};

static const u16 sMegaXOam_3a5b68_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x28c, 11, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x290, 11, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x310, 11, 0),
};

static const u16 sMegaXOam_3a5a58_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d2, 9, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2b2, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 9, 0),
};

static const u16 sMegaXOam_3a5a58_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d3, 9, 0),
    OAM_ENTRY(7, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f4, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x293, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x295, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x296, 9, 0),
};

static const u16 sMegaXOam_3a5a58_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(5, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f3, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x297, 9, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x299, 9, 0),
};

static const u16 sMegaXOam_3a5a80_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d5, 9, 0),
    OAM_ENTRY(7, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d6, 9, 0),
};

static const u16 sMegaXOam_3a5a80_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b7, 9, 0),
};

static const u16 sMegaXOam_3a5a80_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f6, 9, 0),
};

static const u16 sMegaXOam_3a5aa8_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d7, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_XY_FLIP, 0x2b2, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x292, 9, 0),
};

static const u16 sMegaXOam_3a5aa8_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f7, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x293, 9, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x295, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x296, 9, 0),
};

static const u16 sMegaXOam_3a5aa8_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d8, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x297, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 0x299, 9, 0),
};

static const u16 sMegaXOam_3a59b0_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sMegaXOam_3a59b0_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sMegaXOam_3a59b0_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sMegaXOam_3a59b0_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sMegaXOam_3a59b0_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sMegaXOam_3a59b0_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sMegaXOam_3a59b0_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sMegaXOam_3a59b0_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sMegaXOam_3a5b68_Frame1[OAM_DATA_SIZE(13)] = {
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

static const u16 sMegaXOam_3a5b68_Frame2[OAM_DATA_SIZE(10)] = {
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

static const u16 sMegaXOam_3a5b68_Frame3[OAM_DATA_SIZE(14)] = {
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

static const u16 sMegaXOam_3a5b68_Frame4[OAM_DATA_SIZE(16)] = {
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

static const u16 sMegaXOam_3a5b68_Frame5[OAM_DATA_SIZE(16)] = {
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

static const u16 sMegaXOam_3a5b68_Frame6[OAM_DATA_SIZE(9)] = {
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

static const u16 sMegaXOam_3a5b68_Frame7[OAM_DATA_SIZE(8)] = {
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

static const u16 sMegaXOam_3a5a58_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ef, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29a, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x29a, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x29a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x29a, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29c, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x29c, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x29c, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x29c, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x29e, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame12[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x2da, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame16[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2dc, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2dc, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2dc, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x2dc, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame20[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2de, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2de, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x2de, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2de, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame24[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x314, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x314, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x314, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x314, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame28[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x316, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x316, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x316, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x316, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame32[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x318, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x318, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x318, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x318, 9, 0),
};

static const u16 sMegaXOam_3a5bb0_Frame36[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x31a, 9, 0),
};

static const u16 sMegaXOam_3a5a40_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x286, 8, 0),
};

static const u16 sMegaXOam_3a5a40_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -18, OAM_DIMS_32x32, OAM_NO_FLIP, 0x286, 8, 0),
};

static const u16 sMegaXOam_3a5e70_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-20, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 0x340, 12, 0),
    OAM_ENTRY(12, -20, OAM_DIMS_8x32, OAM_NO_FLIP, 0x344, 12, 0),
    OAM_ENTRY(-20, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c0, 12, 0),
};

static const u16 sMegaXOam_3a5e70_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-20, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 0x345, 12, 0),
    OAM_ENTRY(12, -20, OAM_DIMS_8x32, OAM_NO_FLIP, 0x349, 12, 0),
    OAM_ENTRY(-20, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c5, 12, 0),
};

static const u16 sMegaXOam_3a5e70_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-20, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 0x34a, 12, 0),
    OAM_ENTRY(12, -20, OAM_DIMS_8x32, OAM_NO_FLIP, 0x34e, 12, 0),
    OAM_ENTRY(-20, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 12, 0),
};

static const u16 sMegaXOam_3a5ef8_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x34f, 12, 0),
};

static const u16 sMegaXOam_3a5ef8_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x353, 12, 0),
};

static const u16 sMegaXOam_3a5ef8_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x357, 12, 0),
};

const struct FrameData sMegaXOam_3a59b0[9] = {
    [0] = {
        .pFrame = sMegaXOam_3a59b0_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sMegaXOam_3a59b0_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sMegaXOam_3a59b0_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sMegaXOam_3a59b0_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sMegaXOam_3a59b0_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sMegaXOam_3a59b0_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sMegaXOam_3a59b0_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sMegaXOam_3a59b0_Frame7,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a59f8[9] = {
    [0] = {
        .pFrame = sMegaXOam_3a59b0_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMegaXOam_3a59b0_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sMegaXOam_3a59b0_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sMegaXOam_3a59b0_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sMegaXOam_3a59b0_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sMegaXOam_3a59b0_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sMegaXOam_3a59b0_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sMegaXOam_3a59b0_Frame7,
        .timer = 2
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5a40[3] = {
    [0] = {
        .pFrame = sMegaXOam_3a5a40_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMegaXOam_3a5a40_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5a58[5] = {
    [0] = {
        .pFrame = sMegaXOam_3a5a58_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMegaXOam_3a5a58_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sMegaXOam_3a5a58_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 20
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5a80[5] = {
    [0] = {
        .pFrame = sMegaXOam_3a5a80_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMegaXOam_3a5a80_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sMegaXOam_3a5a80_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 40
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5aa8[5] = {
    [0] = {
        .pFrame = sMegaXOam_3a5aa8_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMegaXOam_3a5aa8_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sMegaXOam_3a5aa8_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 60
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5ad0[19] = {
    [0] = {
        .pFrame = sMegaXOam_3a5a58_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sMegaXOam_3a5a58_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sMegaXOam_3a5a58_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sMegaXOam_3a5aa8_Frame0,
        .timer = 1
    },
    [4] = {
        .pFrame = sMegaXOam_3a5aa8_Frame1,
        .timer = 1
    },
    [5] = {
        .pFrame = sMegaXOam_3a5aa8_Frame2,
        .timer = 1
    },
    [6] = {
        .pFrame = sMegaXOam_3a5a80_Frame0,
        .timer = 1
    },
    [7] = {
        .pFrame = sMegaXOam_3a5a80_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sMegaXOam_3a5a80_Frame2,
        .timer = 1
    },
    [9] = {
        .pFrame = sMegaXOam_3a5a58_Frame0,
        .timer = 1
    },
    [10] = {
        .pFrame = sMegaXOam_3a5a58_Frame1,
        .timer = 1
    },
    [11] = {
        .pFrame = sMegaXOam_3a5a58_Frame2,
        .timer = 1
    },
    [12] = {
        .pFrame = sMegaXOam_3a5a80_Frame0,
        .timer = 1
    },
    [13] = {
        .pFrame = sMegaXOam_3a5a80_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sMegaXOam_3a5a80_Frame2,
        .timer = 1
    },
    [15] = {
        .pFrame = sMegaXOam_3a5aa8_Frame0,
        .timer = 1
    },
    [16] = {
        .pFrame = sMegaXOam_3a5aa8_Frame1,
        .timer = 1
    },
    [17] = {
        .pFrame = sMegaXOam_3a5aa8_Frame2,
        .timer = 1
    },
    [18] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5b68[9] = {
    [0] = {
        .pFrame = sMegaXOam_3a5b68_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sMegaXOam_3a5b68_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sMegaXOam_3a5b68_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sMegaXOam_3a5b68_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sMegaXOam_3a5b68_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sMegaXOam_3a5b68_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sMegaXOam_3a5b68_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sMegaXOam_3a5b68_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5bb0[41] = {
    [0] = {
        .pFrame = sMegaXOam_3a5bb0_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [2] = {
        .pFrame = sMegaXOam_3a5bb0_Frame0,
        .timer = 2
    },
    [3] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sMegaXOam_3a5bb0_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [6] = {
        .pFrame = sMegaXOam_3a5bb0_Frame4,
        .timer = 2
    },
    [7] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [8] = {
        .pFrame = sMegaXOam_3a5bb0_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [10] = {
        .pFrame = sMegaXOam_3a5bb0_Frame8,
        .timer = 2
    },
    [11] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [12] = {
        .pFrame = sMegaXOam_3a5bb0_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [14] = {
        .pFrame = sMegaXOam_3a5bb0_Frame12,
        .timer = 2
    },
    [15] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [16] = {
        .pFrame = sMegaXOam_3a5bb0_Frame16,
        .timer = 2
    },
    [17] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [18] = {
        .pFrame = sMegaXOam_3a5bb0_Frame16,
        .timer = 2
    },
    [19] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [20] = {
        .pFrame = sMegaXOam_3a5bb0_Frame20,
        .timer = 2
    },
    [21] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [22] = {
        .pFrame = sMegaXOam_3a5bb0_Frame20,
        .timer = 2
    },
    [23] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [24] = {
        .pFrame = sMegaXOam_3a5bb0_Frame24,
        .timer = 2
    },
    [25] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [26] = {
        .pFrame = sMegaXOam_3a5bb0_Frame24,
        .timer = 2
    },
    [27] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [28] = {
        .pFrame = sMegaXOam_3a5bb0_Frame28,
        .timer = 2
    },
    [29] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [30] = {
        .pFrame = sMegaXOam_3a5bb0_Frame28,
        .timer = 2
    },
    [31] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [32] = {
        .pFrame = sMegaXOam_3a5bb0_Frame32,
        .timer = 2
    },
    [33] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [34] = {
        .pFrame = sMegaXOam_3a5bb0_Frame32,
        .timer = 2
    },
    [35] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [36] = {
        .pFrame = sMegaXOam_3a5bb0_Frame36,
        .timer = 2
    },
    [37] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [38] = {
        .pFrame = sMegaXOam_3a5bb0_Frame36,
        .timer = 2
    },
    [39] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 2
    },
    [40] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5cf8[41] = {
    [0] = {
        .pFrame = sMegaXOam_3a5bb0_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [2] = {
        .pFrame = sMegaXOam_3a5bb0_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sMegaXOam_3a5bb0_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [6] = {
        .pFrame = sMegaXOam_3a5bb0_Frame4,
        .timer = 1
    },
    [7] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [8] = {
        .pFrame = sMegaXOam_3a5bb0_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [10] = {
        .pFrame = sMegaXOam_3a5bb0_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [12] = {
        .pFrame = sMegaXOam_3a5bb0_Frame12,
        .timer = 1
    },
    [13] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [14] = {
        .pFrame = sMegaXOam_3a5bb0_Frame12,
        .timer = 1
    },
    [15] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [16] = {
        .pFrame = sMegaXOam_3a5bb0_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [18] = {
        .pFrame = sMegaXOam_3a5bb0_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [20] = {
        .pFrame = sMegaXOam_3a5bb0_Frame20,
        .timer = 1
    },
    [21] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [22] = {
        .pFrame = sMegaXOam_3a5bb0_Frame20,
        .timer = 1
    },
    [23] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [24] = {
        .pFrame = sMegaXOam_3a5bb0_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [26] = {
        .pFrame = sMegaXOam_3a5bb0_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [28] = {
        .pFrame = sMegaXOam_3a5bb0_Frame28,
        .timer = 1
    },
    [29] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [30] = {
        .pFrame = sMegaXOam_3a5bb0_Frame28,
        .timer = 1
    },
    [31] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [32] = {
        .pFrame = sMegaXOam_3a5bb0_Frame32,
        .timer = 1
    },
    [33] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [34] = {
        .pFrame = sMegaXOam_3a5bb0_Frame32,
        .timer = 1
    },
    [35] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [36] = {
        .pFrame = sMegaXOam_3a5bb0_Frame36,
        .timer = 1
    },
    [37] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [38] = {
        .pFrame = sMegaXOam_3a5bb0_Frame36,
        .timer = 1
    },
    [39] = {
        .pFrame = sMegaXOam_3a5a58_Frame3,
        .timer = 1
    },
    [40] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5e40[2] = {
    [0] = {
        .pFrame = sMegaXOam_3a5e40_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5e50[2] = {
    [0] = {
        .pFrame = sMegaXOam_3a5e50_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5e60[2] = {
    [0] = {
        .pFrame = sMegaXOam_3a5b68_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5e70[12] = {
    [0] = {
        .pFrame = sMegaXOam_3a5e70_Frame0,
        .timer = 50
    },
    [1] = {
        .pFrame = sMegaXOam_3a5e70_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sMegaXOam_3a5e70_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sMegaXOam_3a5e70_Frame1,
        .timer = 3
    },
    [4] = {
        .pFrame = sMegaXOam_3a5e70_Frame0,
        .timer = 3
    },
    [5] = {
        .pFrame = sMegaXOam_3a5e70_Frame2,
        .timer = 5
    },
    [6] = {
        .pFrame = sMegaXOam_3a5e70_Frame1,
        .timer = 3
    },
    [7] = {
        .pFrame = sMegaXOam_3a5e70_Frame0,
        .timer = 30
    },
    [8] = {
        .pFrame = sMegaXOam_3a5e70_Frame1,
        .timer = 2
    },
    [9] = {
        .pFrame = sMegaXOam_3a5e70_Frame2,
        .timer = 4
    },
    [10] = {
        .pFrame = sMegaXOam_3a5e70_Frame1,
        .timer = 2
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5ed0[5] = {
    [0] = {
        .pFrame = sMegaXOam_3a5e70_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMegaXOam_3a5e70_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sMegaXOam_3a5e70_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sMegaXOam_3a5e70_Frame1,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMegaXOam_3a5ef8[12] = {
    [0] = {
        .pFrame = sMegaXOam_3a5ef8_Frame0,
        .timer = 50
    },
    [1] = {
        .pFrame = sMegaXOam_3a5ef8_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sMegaXOam_3a5ef8_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sMegaXOam_3a5ef8_Frame1,
        .timer = 3
    },
    [4] = {
        .pFrame = sMegaXOam_3a5ef8_Frame0,
        .timer = 3
    },
    [5] = {
        .pFrame = sMegaXOam_3a5ef8_Frame2,
        .timer = 5
    },
    [6] = {
        .pFrame = sMegaXOam_3a5ef8_Frame1,
        .timer = 3
    },
    [7] = {
        .pFrame = sMegaXOam_3a5ef8_Frame0,
        .timer = 30
    },
    [8] = {
        .pFrame = sMegaXOam_3a5ef8_Frame1,
        .timer = 2
    },
    [9] = {
        .pFrame = sMegaXOam_3a5ef8_Frame2,
        .timer = 4
    },
    [10] = {
        .pFrame = sMegaXOam_3a5ef8_Frame1,
        .timer = 2
    },
    [11] = FRAME_DATA_TERMINATOR
};
