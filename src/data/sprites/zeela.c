#include "data/sprites/zeela.h"
#include "macros.h"

const s16 sZeelaProjectileMovement[32] = {
    -4, -12, -11, -10,
    -9, -8, -7, -6,
    -5, -4, -3, -2,
    -1, 0, 0, 0,
    0, 0, 0, 1,
    2, 3, 4, 5,
    6, 7, 8, 9,
    10, 11, 12, SHORT_MAX
};

const u32 sZeelaGfx[2 * 512] = INCBIN_U32("data/sprites/zeela.gfx");
const u16 sZeelaPal[2 * 16] = INCBIN_U16("data/sprites/zeela.pal");

static const u16 sZeelaOam_CrawlingHorizontal_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sZeelaOam_CrawlingHorizontal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-14, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(1, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sZeelaOam_CrawlingHorizontal_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x213, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sZeelaOam_CrawlingHorizontal_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-2, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sZeelaOam_CrawlingHorizontal_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sZeelaOam_FallingHorizontal_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-12, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(4, -14, OAM_DIMS_8x16, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sZeelaOam_FallingHorizontal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-12, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(4, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sZeelaOam_FallingHorizontal_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sZeelaOam_FallingHorizontal_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-12, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(4, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sZeelaOam_3502e2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-15, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sZeelaOam_350308[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sZeelaOam_CrawlingVertical_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
};

static const u16 sZeelaOam_CrawlingVertical_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x278, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-1, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
};

static const u16 sZeelaOam_CrawlingVertical_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(2, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(3, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x253, 8, 0),
    OAM_ENTRY(-1, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
};

static const u16 sZeelaOam_CrawlingVertical_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-2, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x278, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(1, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
};

static const u16 sZeelaOam_CrawlingVertical_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_Y_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
};

static const u16 sZeelaOam_FallingVertical_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-2, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-2, 4, OAM_DIMS_16x8, OAM_Y_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-1, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
};

static const u16 sZeelaOam_FallingVertical_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
    OAM_ENTRY(-1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-1, 4, OAM_DIMS_16x8, OAM_Y_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-1, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
};

static const u16 sZeelaOam_FallingVertical_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-1, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24f, 8, 0),
};

static const u16 sZeelaOam_FallingVertical_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-1, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-1, 4, OAM_DIMS_16x8, OAM_Y_FLIP, 0x257, 8, 0),
};

static const u16 sZeelaProjectileOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZeelaProjectileOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sZeelaProjectileOam_35064c_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
};

static const u16 sZeelaProjectileOam_35064c_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
};

static const u16 sZeelaProjectileOam_35064c_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sZeelaProjectileOam_Exploding1_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-5, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-1, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
};

static const u16 sZeelaProjectileOam_Exploding1_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
};

static const u16 sZeelaProjectileOam_Exploding1_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-7, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
};

static const u16 sZeelaProjectileOam_Exploding1_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-9, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(3, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
};

static const u16 sZeelaProjectileOam_Exploding2_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-7, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
};

static const u16 sZeelaProjectileOam_Exploding2_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-9, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
};

static const u16 sZeelaProjectileOam_Exploding2_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-10, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(2, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0),
};

static const u16 sZeelaProjectileOam_Exploding2_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-12, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
};

const struct FrameData sZeelaOam_CrawlingHorizontal[6] = {
    [0] = {
        .pFrame = sZeelaOam_CrawlingHorizontal_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZeelaOam_CrawlingHorizontal_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sZeelaOam_CrawlingHorizontal_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sZeelaOam_CrawlingHorizontal_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZeelaOam_CrawlingHorizontal_Frame4,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_FallingHorizontal[5] = {
    [0] = {
        .pFrame = sZeelaOam_FallingHorizontal_Frame0,
        .timer = 11
    },
    [1] = {
        .pFrame = sZeelaOam_FallingHorizontal_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sZeelaOam_FallingHorizontal_Frame2,
        .timer = 14
    },
    [3] = {
        .pFrame = sZeelaOam_FallingHorizontal_Frame3,
        .timer = 13
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_CrawlingVertical[6] = {
    [0] = {
        .pFrame = sZeelaOam_CrawlingVertical_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZeelaOam_CrawlingVertical_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sZeelaOam_CrawlingVertical_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sZeelaOam_CrawlingVertical_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sZeelaOam_CrawlingVertical_Frame4,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_FallingVertical[5] = {
    [0] = {
        .pFrame = sZeelaOam_FallingVertical_Frame0,
        .timer = 11
    },
    [1] = {
        .pFrame = sZeelaOam_FallingVertical_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sZeelaOam_FallingVertical_Frame2,
        .timer = 14
    },
    [3] = {
        .pFrame = sZeelaOam_FallingVertical_Frame3,
        .timer = 13
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaProjectileOam_Moving[3] = {
    [0] = {
        .pFrame = sZeelaProjectileOam_Moving_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sZeelaProjectileOam_Moving_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaProjectileOam_35064c[4] = {
    [0] = {
        .pFrame = sZeelaProjectileOam_35064c_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sZeelaProjectileOam_35064c_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sZeelaProjectileOam_35064c_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaProjectileOam_Exploding1[5] = {
    [0] = {
        .pFrame = sZeelaProjectileOam_Exploding1_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sZeelaProjectileOam_Exploding1_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sZeelaProjectileOam_Exploding1_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sZeelaProjectileOam_Exploding1_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaProjectileOam_Exploding2[5] = {
    [0] = {
        .pFrame = sZeelaProjectileOam_Exploding2_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sZeelaProjectileOam_Exploding2_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sZeelaProjectileOam_Exploding2_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sZeelaProjectileOam_Exploding2_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u32 sRedZeelaGfx[2 * 512] = INCBIN_U32("data/sprites/red_zeela.gfx");
const u16 sRedZeelaPal[2 * 16] = INCBIN_U16("data/sprites/red_zeela.pal");
