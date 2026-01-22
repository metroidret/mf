#include "data/sprites/genesis.h"
#include "macros.h"

const u32 sGenesisGfx[512 * 2] = INCBIN_U32("data/sprites/genesis.gfx");
const u16 sGenesisPal[16 * 2] = INCBIN_U16("data/sprites/genesis.pal");

static const u16 sGenesisOam_Walking_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(15, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-30, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
};

static const u16 sGenesisOam_Walking_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-2, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-19, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
};

static const u16 sGenesisOam_Walking_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(6, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x243, 8, 0),
};

static const u16 sGenesisOam_Walking_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x243, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 8, 0),
};

static const u16 sGenesisOam_Walking_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(9, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sGenesisOam_Walking_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-2, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-23, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x216, 8, 0),
};

static const u16 sGenesisOam_37c3d0_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-2, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(14, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-29, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-17, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
};

static const u16 sGenesisOam_37c3d0_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-31, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-19, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
};

static const u16 sGenesisOam_37c3d0_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(15, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-30, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
};

static const u16 sGenesisOam_37c3f0_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-28, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x245, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(20, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26d, 8, 0),
};

static const u16 sGenesisOam_37c3f0_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(21, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-11, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-19, 10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
};

static const u16 sGenesisOam_37c3f0_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-28, 2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-20, 0, OAM_DIMS_32x16, OAM_Y_FLIP, 0x245, 8, 0),
    OAM_ENTRY(12, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x249, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(20, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x26d, 8, 0),
};

static const u16 sOam_37be20[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x231, 8, 0),
    OAM_ENTRY(14, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-31, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-19, 8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x240, 8, 0),
};

static const u16 sGenesisOam_TurningAround_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-22, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
};

static const u16 sGenesisOam_Waiting_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-13, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x276, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x278, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-11, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame7[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame8[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-11, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-13, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame9[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-13, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x279, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-13, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame10[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-14, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x279, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-15, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-13, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame11[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-15, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame12[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-15, 1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-11, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame13[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-15, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame14[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-15, 9, OAM_DIMS_8x8, OAM_X_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-14, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame15[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-13, 10, OAM_DIMS_8x8, OAM_X_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-12, 12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame16[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-13, 10, OAM_DIMS_8x8, OAM_X_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-11, 12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame17[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-11, 11, OAM_DIMS_8x8, OAM_X_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-10, 14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame18[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-11, 12, OAM_DIMS_8x8, OAM_X_FLIP, 0x278, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame19[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-10, 12, OAM_DIMS_8x8, OAM_X_FLIP, 0x277, 8, 0),
};

static const u16 sGenesisOam_Spitting_Frame20[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-9, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x276, 8, 0),
};

static const u16 sGenesisSpitOam_Hanging_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
};

static const u16 sGenesisSpitOam_Splashing_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25e, 8, 0),
};

static const u16 sGenesisSpitOam_Splashing_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25f, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 8, 0),
};

static const u16 sGenesisSpitOam_Splashing_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 8, 0),
};

static const u16 sGenesisOam_Waiting_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sGenesisOam_Waiting_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
};

static const u16 sGenesisOam_Skidding_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
};

const struct FrameData sGenesisOam_Walking[7] = {
    [0] = {
        .pFrame = sGenesisOam_Walking_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sGenesisOam_Walking_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sGenesisOam_Walking_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sGenesisOam_Walking_Frame3,
        .timer = 7
    },
    [4] = {
        .pFrame = sGenesisOam_Walking_Frame4,
        .timer = 7
    },
    [5] = {
        .pFrame = sGenesisOam_Walking_Frame5,
        .timer = 7
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisOam_Running[7] = {
    [0] = {
        .pFrame = sGenesisOam_Walking_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sGenesisOam_Walking_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sGenesisOam_Walking_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sGenesisOam_Walking_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sGenesisOam_Walking_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sGenesisOam_Walking_Frame5,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisOam_37c3d0[4] = {
    [0] = {
        .pFrame = sGenesisOam_37c3d0_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sGenesisOam_37c3d0_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sGenesisOam_37c3d0_Frame2,
        .timer = 6
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisOam_37c3f0[4] = {
    [0] = {
        .pFrame = sGenesisOam_37c3f0_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sGenesisOam_37c3f0_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sGenesisOam_37c3f0_Frame2,
        .timer = 6
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisOam_37c410[4] = {
    [0] = {
        .pFrame = sGenesisOam_37c3f0_Frame2,
        .timer = 6
    },
    [1] = {
        .pFrame = sGenesisOam_37c3f0_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sGenesisOam_37c3f0_Frame0,
        .timer = 6
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisOam_37c430[4] = {
    [0] = {
        .pFrame = sGenesisOam_37c3d0_Frame2,
        .timer = 6
    },
    [1] = {
        .pFrame = sGenesisOam_37c3d0_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sGenesisOam_37c3d0_Frame0,
        .timer = 6
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisOam_Waiting[5] = {
    [0] = {
        .pFrame = sGenesisOam_Waiting_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sGenesisOam_Waiting_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sGenesisOam_Waiting_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sGenesisOam_Waiting_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisOam_Skidding[2] = {
    [0] = {
        .pFrame = sGenesisOam_Skidding_Frame0,
        .timer = 10
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisOam_TurningAround[2] = {
    [0] = {
        .pFrame = sGenesisOam_TurningAround_Frame0,
        .timer = 8
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisOam_Spitting[22] = {
    [0] = {
        .pFrame = sGenesisOam_Waiting_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sGenesisOam_Spitting_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sGenesisOam_Spitting_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sGenesisOam_Spitting_Frame1,
        .timer = 4
    },
    [4] = {
        .pFrame = sGenesisOam_Spitting_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sGenesisOam_Spitting_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sGenesisOam_Spitting_Frame6,
        .timer = 6
    },
    [7] = {
        .pFrame = sGenesisOam_Spitting_Frame7,
        .timer = 4
    },
    [8] = {
        .pFrame = sGenesisOam_Spitting_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sGenesisOam_Spitting_Frame9,
        .timer = 8
    },
    [10] = {
        .pFrame = sGenesisOam_Spitting_Frame10,
        .timer = 8
    },
    [11] = {
        .pFrame = sGenesisOam_Spitting_Frame11,
        .timer = 6
    },
    [12] = {
        .pFrame = sGenesisOam_Spitting_Frame12,
        .timer = 6
    },
    [13] = {
        .pFrame = sGenesisOam_Spitting_Frame13,
        .timer = 6
    },
    [14] = {
        .pFrame = sGenesisOam_Spitting_Frame14,
        .timer = 6
    },
    [15] = {
        .pFrame = sGenesisOam_Spitting_Frame15,
        .timer = 6
    },
    [16] = {
        .pFrame = sGenesisOam_Spitting_Frame16,
        .timer = 6
    },
    [17] = {
        .pFrame = sGenesisOam_Spitting_Frame17,
        .timer = 6
    },
    [18] = {
        .pFrame = sGenesisOam_Spitting_Frame18,
        .timer = 6
    },
    [19] = {
        .pFrame = sGenesisOam_Spitting_Frame19,
        .timer = 6
    },
    [20] = {
        .pFrame = sGenesisOam_Spitting_Frame20,
        .timer = 6
    },
    [21] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisSpitOam_Hanging[2] = {
    [0] = {
        .pFrame = sGenesisSpitOam_Hanging_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGenesisSpitOam_Splashing[4] = {
    [0] = {
        .pFrame = sGenesisSpitOam_Splashing_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sGenesisSpitOam_Splashing_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sGenesisSpitOam_Splashing_Frame2,
        .timer = 6
    },
    [3] = FRAME_DATA_TERMINATOR
};
