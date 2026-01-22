#include "data/sprites/zozoro.h"
#include "macros.h"

const u32 sZozoroGfx[2 * 512] = INCBIN_U32("data/sprites/zozoro.gfx");
const u16 sZozoroPal[1 * 16] = INCBIN_U16("data/sprites/zozoro.pal");

static const u16 sZozoroOam_CrawlingGround_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0)
};

static const u16 sZozoroOam_CrawlingGround_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-15, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0)
};

static const u16 sZozoroOam_CrawlingGround_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0)
};

static const u16 sZozoroOam_CrawlingGround_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0)
};

static const u16 sZozoroOam_CrawlingGround_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZozoroOam_TurningAroundGround_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0)
};

static const u16 sZozoroOam_TurningAroundGround_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-11, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZozoroOam_TurningAroundGround_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-11, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZozoroOam_TurningAroundGround_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0)
};

static const u16 sZozoroOam_CrawlingGroundFast_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-11, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0)
};

static const u16 sZozoroOam_CrawlingGroundFast_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0)
};

static const u16 sZozoroOam_CrawlingGroundFast_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0)
};

static const u16 sZozoroOam_38787c[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0)
};

static const u16 sZozoroOam_Landing_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-15, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0)
};

static const u16 sZozoroOam_CrawlingWall_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(10, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x268, 8, 0)
};

static const u16 sZozoroOam_CrawlingWall_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(10, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(11, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x269, 8, 0)
};

static const u16 sZozoroOam_CrawlingWall_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(10, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26a, 8, 0)
};

static const u16 sZozoroOam_CrawlingWall_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(10, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0)
};

static const u16 sZozoroOam_CrawlingWall_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(10, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26c, 8, 0)
};

static const u16 sZozoroOam_TurningAroundWall_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(10, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26d, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0)
};

static const u16 sZozoroOam_TurningAroundWall_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(10, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26c, 8, 0)
};

static const u16 sZozoroOam_TurningAroundWall_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(10, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26c, 8, 0)
};

static const u16 sZozoroOam_TurningAroundWall_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(10, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26d, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0)
};

static const u16 sZozoroOam_CrawlingWallFast_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(12, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(2, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(3, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(13, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x269, 8, 0)
};

static const u16 sZozoroOam_CrawlingWallFast_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(11, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(2, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(2, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(12, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26a, 8, 0)
};

static const u16 sZozoroOam_CrawlingWallFast_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(11, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(12, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26a, 8, 0)
};

static const u16 sZozoroOam_3879fa[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(10, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(9, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0)
};

static const u16 sZozoroOam_387a14[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(12, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(7, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightUpwardsSlope_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-9, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightUpwardsSlope_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-14, -19, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(3, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-11, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightUpwardsSlope_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -19, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-5, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightUpwardsSlope_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(3, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightUpwardsSlope_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-13, -18, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(2, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightDownwardsSlope_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-11, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x268, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightDownwardsSlope_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-12, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-13, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-17, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x269, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightDownwardsSlope_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -9, OAM_DIMS_8x8, OAM_XY_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-11, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-13, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_8x8, OAM_XY_FLIP, 0x26a, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightDownwardsSlope_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-12, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-13, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-17, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x26b, 8, 0)
};

static const u16 sZozoroOam_CrawlingSlightDownwardsSlope_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-11, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-13, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(2, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x26c, 8, 0)
};

static const u16 sZozoroOam_IdleGround_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-13, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0)
};

static const u16 sZozoroOam_IdleGround_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0)
};

static const u16 sZozoroOam_IdleGround_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0)
};

static const u16 sZozoroOam_IdleGround_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-14, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0)
};

static const u16 sZozoroOam_IdleGround_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZozoroOam_IdleWall_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(12, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x268, 8, 0)
};

static const u16 sZozoroOam_IdleWall_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(10, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x269, 8, 0)
};

static const u16 sZozoroOam_IdleWall_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(11, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(12, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26a, 8, 0)
};

static const u16 sZozoroOam_IdleWall_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(10, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(11, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0)
};

static const u16 sZozoroOam_IdleWall_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(12, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26c, 8, 0)
};

static const u16 sZozoroOam_StartFalling_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -3, OAM_DIMS_8x8, OAM_Y_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-12, -13, OAM_DIMS_16x16, OAM_Y_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -13, OAM_DIMS_8x16, OAM_Y_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-13, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x229, 8, 0)
};

static const u16 sZozoroOam_StartFalling_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -3, OAM_DIMS_8x8, OAM_Y_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-12, -13, OAM_DIMS_16x16, OAM_Y_FLIP, 0x206, 8, 0),
    OAM_ENTRY(4, -13, OAM_DIMS_8x16, OAM_Y_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-13, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x22c, 8, 0)
};

static const u16 sZozoroOam_StartFalling_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -3, OAM_DIMS_8x8, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_8x16, OAM_Y_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_16x16, OAM_Y_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-15, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x22a, 8, 0)
};

static const u16 sZozoroOam_StartFalling_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -3, OAM_DIMS_8x8, OAM_Y_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-12, -13, OAM_DIMS_16x16, OAM_Y_FLIP, 0x203, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_Y_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-13, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x22d, 8, 0)
};

static const u16 sZozoroOam_Landing_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(4, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x229, 8, 0)
};

static const u16 sZozoroOam_Landing_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-15, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(4, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25f, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepUpwardsSlope_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-12, -21, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(1, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepUpwardsSlope_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-13, -22, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-6, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-10, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepUpwardsSlope_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-12, -20, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-7, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepUpwardsSlope_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-13, -21, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepUpwardsSlope_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-12, -20, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepDownwardsSlope_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -7, OAM_DIMS_8x8, OAM_XY_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-11, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_8x8, OAM_XY_FLIP, 0x268, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepDownwardsSlope_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -7, OAM_DIMS_8x8, OAM_XY_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-15, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-17, -3, OAM_DIMS_8x8, OAM_XY_FLIP, 0x269, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepDownwardsSlope_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-11, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-11, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(1, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x26a, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepDownwardsSlope_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -7, OAM_DIMS_8x8, OAM_XY_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-10, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-17, -5, OAM_DIMS_8x8, OAM_XY_FLIP, 0x26b, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0)
};

static const u16 sZozoroOam_CrawlingSteepDownwardsSlope_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -5, OAM_DIMS_8x8, OAM_XY_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-11, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_8x8, OAM_XY_FLIP, 0x26c, 8, 0)
};

const struct FrameData sZozoroOam_CrawlingGround[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingGround_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingGround_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingGround_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingGround_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingGround_Frame4,
        .timer = 7
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingGroundFast[7] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingGround_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingGroundFast_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingGroundFast_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingGroundFast_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingGround_Frame3,
        .timer = 2
    },
    [5] = {
        .pFrame = sZozoroOam_CrawlingGround_Frame4,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_TurningAroundGround[5] = {
    [0] = {
        .pFrame = sZozoroOam_TurningAroundGround_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sZozoroOam_TurningAroundGround_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sZozoroOam_TurningAroundGround_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sZozoroOam_TurningAroundGround_Frame3,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingWall[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingWall_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingWall_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingWall_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingWall_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingWall_Frame4,
        .timer = 7
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingWallFast[7] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingWall_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingWallFast_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingWallFast_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingWallFast_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingWall_Frame3,
        .timer = 2
    },
    [5] = {
        .pFrame = sZozoroOam_CrawlingWall_Frame4,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_TurningAroundWall[5] = {
    [0] = {
        .pFrame = sZozoroOam_TurningAroundWall_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sZozoroOam_TurningAroundWall_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sZozoroOam_TurningAroundWall_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sZozoroOam_TurningAroundWall_Frame3,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingSlightUpwardsSlope[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame4,
        .timer = 7
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingSlightUpwardsSlopeFast[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingSlightUpwardsSlope_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingSlightDownwardsSlope[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame4,
        .timer = 7
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingSlightDownwardsSlopeFast[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingSlightDownwardsSlope_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingSteepUpwardsSlope[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame4,
        .timer = 7
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingSteepUpwardsSlopeFast[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingSteepUpwardsSlope_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingSteepDownwardsSlope[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame4,
        .timer = 7
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_CrawlingSteepDownwardsSlopeFast[6] = {
    [0] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sZozoroOam_CrawlingSteepDownwardsSlope_Frame4,
        .timer = 3
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_IdleGround[6] = {
    [0] = {
        .pFrame = sZozoroOam_IdleGround_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sZozoroOam_IdleGround_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sZozoroOam_IdleGround_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sZozoroOam_IdleGround_Frame3,
        .timer = 12
    },
    [4] = {
        .pFrame = sZozoroOam_IdleGround_Frame4,
        .timer = 12
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_IdleWall[6] = {
    [0] = {
        .pFrame = sZozoroOam_IdleWall_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sZozoroOam_IdleWall_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sZozoroOam_IdleWall_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sZozoroOam_IdleWall_Frame3,
        .timer = 12
    },
    [4] = {
        .pFrame = sZozoroOam_IdleWall_Frame4,
        .timer = 12
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_StartFalling[5] = {
    [0] = {
        .pFrame = sZozoroOam_StartFalling_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZozoroOam_StartFalling_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sZozoroOam_StartFalling_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sZozoroOam_StartFalling_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZozoroOam_Landing[5] = {
    [0] = {
        .pFrame = sZozoroOam_Landing_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZozoroOam_Landing_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sZozoroOam_Landing_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sZozoroOam_CrawlingGround_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_388224_39f718[] = INCBIN_U8("data/Blob_388224_39f718.bin");
