#include "data/sprites/sova.h"
#include "macros.h"

const s16 sSova_3516fc[16] = {
    0, 0, 0, 1,
    2, 3, 4, 5,
    6, 7, 8, 9,
    10, 11, 12, SHORT_MAX
};

const u32 sSovaGfx[3 * 512] = INCBIN_U32("data/sprites/sova.gfx");
const u16 sSovaPal[3 * 16] = INCBIN_U16("data/sprites/sova.pal");

static const u16 sSovaOam_CrawlingOnFlatGround_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x241, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x245, 8, 0),
    OAM_ENTRY(-12, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
};

static const u16 sSovaOam_CrawlingOnFlatGround_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x261, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x265, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
};

static const u16 sSovaOam_CrawlingOnFlatGround_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x245, 8, 0),
    OAM_ENTRY(-12, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-6, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
};

static const u16 sSovaOam_CrawlingOnFlatGround_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(1, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x265, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
};

static const u16 sSovaOam_CrawlingOnWall_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x267, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x232, 8, 0),
};

static const u16 sSovaOam_CrawlingOnWall_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-1, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x268, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sSovaOam_CrawlingOnWall_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x269, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(13, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x235, 8, 0),
};

static const u16 sSovaOam_CrawlingOnWall_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x269, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
};

static const u16 sSovaOam_CrawlingOnCeiling_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x240, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x241, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x245, 8, 0),
    OAM_ENTRY(-12, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(4, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24c, 8, 0),
};

static const u16 sSovaOam_CrawlingOnCeiling_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x260, 8, 0),
    OAM_ENTRY(1, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x261, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x265, 8, 0),
    OAM_ENTRY(-12, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(4, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
};

static const u16 sSovaOam_CrawlingOnCeiling_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x242, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x245, 8, 0),
    OAM_ENTRY(-12, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(4, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 8, 0),
};

static const u16 sSovaOam_CrawlingOnCeiling_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(1, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-9, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x265, 8, 0),
    OAM_ENTRY(-12, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(4, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x255, 8, 0),
};

static const u16 sSovaOam_CrawlingOnSlope_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28d, 8, 0),
    OAM_ENTRY(-6, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x241, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27b, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 8, 0),
};

static const u16 sSovaOam_CrawlingOnSlope_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-6, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x261, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x283, 8, 0),
    OAM_ENTRY(12, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x285, 8, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a5, 8, 0),
};

static const u16 sSovaOam_CrawlingOnSlope_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28d, 8, 0),
    OAM_ENTRY(-6, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(3, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x286, 8, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x289, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x288, 8, 0),
};

static const u16 sSovaOam_CrawlingOnSlope_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-6, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x262, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a9, 8, 0),
};

static const u16 sSovaGroundFlameOam_Big_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x297, 8, 0),
};

static const u16 sSovaGroundFlameOam_Big_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x299, 8, 0),
};

static const u16 sSovaGroundFlameOam_Big_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29b, 8, 0),
};

static const u16 sSovaGroundFlameOam_Big_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29d, 8, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27d, 8, 0),
};

static const u16 sSovaGroundFlameOam_Small_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-3, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x291, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b2, 8, 0),
};

static const u16 sSovaGroundFlameOam_Small_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x293, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
};

static const u16 sSovaGroundFlameOam_Small_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b3, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x295, 8, 0),
};

static const u16 sSovaGroundFlameOam_Small_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b5, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x296, 8, 0),
};

static const u16 sSovaGroundFlameOam_Disappearing_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
};

static const u16 sSovaGroundFlameOam_Disappearing_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x257, 8, 0),
};

static const u16 sSovaGroundFlameOam_Disappearing_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
};

static const u16 sSovaGroundFlameOam_Disappearing_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sSovaFallingFlameOam_Falling_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x297, 8, 0),
    OAM_ENTRY(-5, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 8, 0),
};

static const u16 sSovaFallingFlameOam_Falling_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x299, 8, 0),
    OAM_ENTRY(-5, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
};

static const u16 sSovaFallingFlameOam_Falling_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29b, 8, 0),
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29f, 8, 0),
};

static const u16 sSovaFallingFlameOam_Falling_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29d, 8, 0),
    OAM_ENTRY(-5, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27d, 8, 0),
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bf, 8, 0),
};

static const u16 sSovaFallingFlameOam_Exploding_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
};

static const u16 sSovaFallingFlameOam_Exploding_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-10, -5, OAM_DIMS_8x8, OAM_XY_FLIP, 0x284, 8, 0),
    OAM_ENTRY(-4, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x295, 8, 0),
    OAM_ENTRY(-11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 8, 0),
};

static const u16 sSovaFallingFlameOam_Exploding_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-11, -11, OAM_DIMS_16x8, OAM_Y_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-1, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(4, -7, OAM_DIMS_8x8, OAM_XY_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x284, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a9, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x279, 8, 0),
    OAM_ENTRY(-7, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
};

static const u16 sSovaFallingFlameOam_Exploding_Frame3[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-14, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a9, 8, 0),
    OAM_ENTRY(-15, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x295, 8, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x270, 8, 0),
    OAM_ENTRY(3, -13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x259, 8, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a9, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_XY_FLIP, 0x279, 8, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 8, 0),
    OAM_ENTRY(-5, -33, OAM_DIMS_8x8, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sSovaFallingFlameOam_Exploding_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(1, -33, OAM_DIMS_8x8, OAM_X_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x295, 8, 0),
    OAM_ENTRY(4, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(-14, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-7, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sSovaGroundFlameOam_Disappearing_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20a, 8, 0),
};

const struct FrameData sSovaOam_CrawlingOnFlatGround[5] = {
    [0] = {
        .pFrame = sSovaOam_CrawlingOnFlatGround_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSovaOam_CrawlingOnFlatGround_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSovaOam_CrawlingOnFlatGround_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSovaOam_CrawlingOnFlatGround_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_CrawlingOnWall[5] = {
    [0] = {
        .pFrame = sSovaOam_CrawlingOnWall_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSovaOam_CrawlingOnWall_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSovaOam_CrawlingOnWall_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSovaOam_CrawlingOnWall_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_CrawlingOnCeiling[5] = {
    [0] = {
        .pFrame = sSovaOam_CrawlingOnCeiling_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSovaOam_CrawlingOnCeiling_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSovaOam_CrawlingOnCeiling_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSovaOam_CrawlingOnCeiling_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_CrawlingOnSlope[5] = {
    [0] = {
        .pFrame = sSovaOam_CrawlingOnSlope_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSovaOam_CrawlingOnSlope_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSovaOam_CrawlingOnSlope_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSovaOam_CrawlingOnSlope_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaGroundFlameOam_Big[5] = {
    [0] = {
        .pFrame = sSovaGroundFlameOam_Big_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSovaGroundFlameOam_Big_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSovaGroundFlameOam_Big_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSovaGroundFlameOam_Big_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaGroundFlameOam_Small[5] = {
    [0] = {
        .pFrame = sSovaGroundFlameOam_Small_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSovaGroundFlameOam_Small_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSovaGroundFlameOam_Small_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSovaGroundFlameOam_Small_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaGroundFlameOam_Disappearing[9] = {
    [0] = {
        .pFrame = sSovaGroundFlameOam_Disappearing_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSovaGroundFlameOam_Disappearing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sSovaGroundFlameOam_Disappearing_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSovaGroundFlameOam_Disappearing_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sSovaGroundFlameOam_Disappearing_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sSovaGroundFlameOam_Disappearing_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sSovaGroundFlameOam_Disappearing_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sSovaGroundFlameOam_Disappearing_Frame1,
        .timer = 1
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaFallingFlameOam_Falling[5] = {
    [0] = {
        .pFrame = sSovaFallingFlameOam_Falling_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSovaFallingFlameOam_Falling_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sSovaFallingFlameOam_Falling_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sSovaFallingFlameOam_Falling_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaFallingFlameOam_Exploding[6] = {
    [0] = {
        .pFrame = sSovaFallingFlameOam_Exploding_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSovaFallingFlameOam_Exploding_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sSovaFallingFlameOam_Exploding_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sSovaFallingFlameOam_Exploding_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sSovaFallingFlameOam_Exploding_Frame4,
        .timer = 4
    },
    [5] = FRAME_DATA_TERMINATOR
};
