#include "data/sprites/yard.h"
#include "macros.h"

const u32 sYardGfx[512 * 3] = INCBIN_U32("data/sprites/yard.gfx");
const u16 sYardPal[16 * 3] = INCBIN_U16("data/sprites/yard.pal");

static const u16 sYardOam_CrawlingHorizontal_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-20, -21, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-9, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-3, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-10, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 8, 0),
};

static const u16 sYardOam_CrawlingHorizontal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-5, -29, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-12, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 8, 0),
    OAM_ENTRY(-4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-10, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
};

static const u16 sYardOam_CrawlingHorizontal_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -23, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-10, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 8, 0),
};

static const u16 sYardOam_ChargingHorizontal_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-20, -23, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-10, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-10, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 8, 0),
};

static const u16 sYardOam_ChargingHorizontal_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sYardOam_ChargingHorizontal_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sYardOam_ChargingHorizontal_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sYardOam_ChargingHorizontal_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sYardOam_ShootingHorizontal_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-15, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sYardOam_ShootingHorizontal_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(4, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-15, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sYardOam_ShootingHorizontal_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-2, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-15, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sYardOam_ShootingHorizontal_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(4, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(4, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-15, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sYardOam_CrawlingVertical_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(6, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(20, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x271, 8, 0),
};

static const u16 sYardOam_CrawlingVertical_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x249, 8, 0),
};

static const u16 sYardOam_CrawlingVertical_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(6, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(7, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(7, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(21, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24a, 8, 0),
};

static const u16 sYardOam_ChargingVertical_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(9, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-4, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(7, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(7, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(21, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24a, 8, 0),
};

static const u16 sYardOam_ChargingVertical_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26e, 8, 0),
    OAM_ENTRY(-6, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(3, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
};

static const u16 sYardOam_ChargingVertical_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-6, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
};

static const u16 sYardOam_ChargingVertical_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26e, 8, 0),
    OAM_ENTRY(-6, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
};

static const u16 sYardOam_ChargingVertical_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-6, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(6, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
};

static const u16 sYardOam_ShootingVertical_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
};

static const u16 sYardOam_ShootingVertical_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(1, 3, OAM_DIMS_32x16, OAM_Y_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(9, 19, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26e, 8, 0),
    OAM_ENTRY(-6, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
};

static const u16 sYardOam_ShootingVertical_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(12, 5, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(4, -3, OAM_DIMS_16x16, OAM_Y_FLIP, 0x233, 8, 0),
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26e, 8, 0),
    OAM_ENTRY(-6, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
};

static const u16 sYardOam_ShootingVertical_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(9, 3, OAM_DIMS_32x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(9, 19, OAM_DIMS_16x8, OAM_Y_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26e, 8, 0),
    OAM_ENTRY(-6, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
};

static const u16 sYardOam_StartledHorizontal_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 8, 0),
    OAM_ENTRY(-4, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_XY_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_16x8, OAM_Y_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-6, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x266, 8, 0),
};

static const u16 sYardOam_StartledHorizontal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-20, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-3, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-10, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 8, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-12, -5, OAM_DIMS_16x8, OAM_Y_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x266, 8, 0),
};

static const u16 sYardOam_StartledVertical_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(1, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(1, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-1, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-1, -14, OAM_DIMS_8x16, OAM_Y_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-1, -7, OAM_DIMS_8x16, OAM_XY_FLIP, 0x205, 8, 0),
};

static const u16 sYardOam_StartledVertical_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(2, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(2, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(2, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-3, -13, OAM_DIMS_8x16, OAM_Y_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-1, -6, OAM_DIMS_8x16, OAM_XY_FLIP, 0x205, 8, 0),
};

static const u16 sYardOam_TurningAroundHorizontal1_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-11, -10, OAM_DIMS_8x8, OAM_XY_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(1, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-20, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-3, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-10, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 8, 0),
};

static const u16 sYardOam_TurningAroundHorizontal1_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-1, -9, OAM_DIMS_8x8, OAM_Y_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-11, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x22f, 8, 0),
};

static const u16 sYardOam_TurningAroundVertical1_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x260, 8, 0),
    OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(2, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(18, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(4, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x271, 8, 0),
};

static const u16 sYardOam_TurningAroundVertical1_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(1, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x260, 8, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(4, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(18, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
};

static const u16 sYardOam_UninfectedHorizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
};

static const u16 sYardOam_UninfectedVertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x284, 8, 0),
};

static const u16 sYardProjectileOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sYardProjectileOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
};

static const u16 sYardProjectileOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x25c, 8, 0),
};

static const u16 sYardProjectileOam_Moving_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -2, OAM_DIMS_16x8, OAM_XY_FLIP, 0x25e, 8, 0),
};

static const u16 sYardProjectileOam_Exploding_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x16, OAM_XY_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x288, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x288, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x288, 8, 0),
};

static const u16 sYardProjectileOam_Exploding_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(-10, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(1, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(-13, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x288, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x288, 8, 0),
};

static const u16 sYardProjectileOam_Exploding_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x288, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_8x8, OAM_XY_FLIP, 0x288, 8, 0),
    OAM_ENTRY(9, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x288, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x288, 8, 0),
};

static const u16 sYardOam_TurningAroundHorizontal1_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-9, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-5, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-12, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 8, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-12, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
};

static const u16 sYardOam_TurningAroundVertical1_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x249, 8, 0),
};

const struct FrameData sYardOam_CrawlingHorizontal[4] = {
    [0] = {
        .pFrame = sYardOam_CrawlingHorizontal_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sYardOam_CrawlingHorizontal_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sYardOam_CrawlingHorizontal_Frame2,
        .timer = 12
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_ChargingHorizontal[6] = {
    [0] = {
        .pFrame = sYardOam_ChargingHorizontal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYardOam_ChargingHorizontal_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sYardOam_ChargingHorizontal_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sYardOam_ChargingHorizontal_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sYardOam_ChargingHorizontal_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_ShootingHorizontal[7] = {
    [0] = {
        .pFrame = sYardOam_ShootingHorizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sYardOam_ShootingHorizontal_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYardOam_ShootingHorizontal_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sYardOam_ShootingHorizontal_Frame1,
        .timer = 2
    },
    [4] = {
        .pFrame = sYardOam_ShootingHorizontal_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sYardOam_ShootingHorizontal_Frame1,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_RecoilHorizontal[4] = {
    [0] = {
        .pFrame = sYardOam_ChargingHorizontal_Frame4,
        .timer = 2
    },
    [1] = {
        .pFrame = sYardOam_ChargingHorizontal_Frame2,
        .timer = 2
    },
    [2] = {
        .pFrame = sYardOam_ChargingHorizontal_Frame0,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_StartledHorizontal[7] = {
    [0] = {
        .pFrame = sYardOam_StartledHorizontal_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sYardOam_StartledHorizontal_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sYardOam_StartledHorizontal_Frame0,
        .timer = 3
    },
    [3] = {
        .pFrame = sYardOam_StartledHorizontal_Frame1,
        .timer = 3
    },
    [4] = {
        .pFrame = sYardOam_StartledHorizontal_Frame0,
        .timer = 3
    },
    [5] = {
        .pFrame = sYardOam_StartledHorizontal_Frame1,
        .timer = 3
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_TurningAroundHorizontal1[4] = {
    [0] = {
        .pFrame = sYardOam_TurningAroundHorizontal1_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYardOam_TurningAroundHorizontal1_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sYardOam_TurningAroundHorizontal1_Frame2,
        .timer = 6
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_TurningAroundHorizontal2[4] = {
    [0] = {
        .pFrame = sYardOam_TurningAroundHorizontal1_Frame2,
        .timer = 6
    },
    [1] = {
        .pFrame = sYardOam_TurningAroundHorizontal1_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sYardOam_TurningAroundHorizontal1_Frame0,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_CrawlingVertical[4] = {
    [0] = {
        .pFrame = sYardOam_CrawlingVertical_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sYardOam_CrawlingVertical_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sYardOam_CrawlingVertical_Frame2,
        .timer = 12
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_ChargingVertical[6] = {
    [0] = {
        .pFrame = sYardOam_ChargingVertical_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYardOam_ChargingVertical_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sYardOam_ChargingVertical_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sYardOam_ChargingVertical_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sYardOam_ChargingVertical_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_ShootingVertical[7] = {
    [0] = {
        .pFrame = sYardOam_ShootingVertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sYardOam_ShootingVertical_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYardOam_ShootingVertical_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sYardOam_ShootingVertical_Frame1,
        .timer = 2
    },
    [4] = {
        .pFrame = sYardOam_ShootingVertical_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sYardOam_ShootingVertical_Frame1,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_RecoilVertical[4] = {
    [0] = {
        .pFrame = sYardOam_ChargingVertical_Frame4,
        .timer = 2
    },
    [1] = {
        .pFrame = sYardOam_ChargingVertical_Frame2,
        .timer = 2
    },
    [2] = {
        .pFrame = sYardOam_ChargingVertical_Frame0,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_StartledVertical[7] = {
    [0] = {
        .pFrame = sYardOam_StartledVertical_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sYardOam_StartledVertical_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sYardOam_StartledVertical_Frame0,
        .timer = 3
    },
    [3] = {
        .pFrame = sYardOam_StartledVertical_Frame1,
        .timer = 3
    },
    [4] = {
        .pFrame = sYardOam_StartledVertical_Frame0,
        .timer = 3
    },
    [5] = {
        .pFrame = sYardOam_StartledVertical_Frame1,
        .timer = 3
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_TurningAroundVertical1[4] = {
    [0] = {
        .pFrame = sYardOam_TurningAroundVertical1_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYardOam_TurningAroundVertical1_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sYardOam_TurningAroundVertical1_Frame2,
        .timer = 6
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_TurningAroundVertical2[4] = {
    [0] = {
        .pFrame = sYardOam_TurningAroundVertical1_Frame2,
        .timer = 6
    },
    [1] = {
        .pFrame = sYardOam_TurningAroundVertical1_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sYardOam_TurningAroundVertical1_Frame0,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardProjectileOam_Moving[5] = {
    [0] = {
        .pFrame = sYardProjectileOam_Moving_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sYardProjectileOam_Moving_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sYardProjectileOam_Moving_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sYardProjectileOam_Moving_Frame3,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_UninfectedHorizontal[2] = {
    [0] = {
        .pFrame = sYardOam_UninfectedHorizontal_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardOam_UninfectedVertical[2] = {
    [0] = {
        .pFrame = sYardOam_UninfectedVertical_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYardProjectileOam_Exploding[4] = {
    [0] = {
        .pFrame = sYardProjectileOam_Exploding_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYardProjectileOam_Exploding_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYardProjectileOam_Exploding_Frame2,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};
