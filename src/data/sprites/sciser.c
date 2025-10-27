#include "data/sprites/sciser.h"
#include "macros.h"

const s16 sSciserDancingSidewaysMovementLeft[12] = {
    -1, 0, 0, 1,
    0, 0, 1, 0,
    0, -1, 0, 0
};

const s16 sSciserDancingSidewaysMovementRight[12] = {
    1, 0, 0, -1,
    0, 0, -1, 0,
    0, 1, 0, 0
};

const s16 sSciserProjectileThrownDownVelocity[25] = {
    -4, -4, -3, -3,
    -2, -2, -1, -1,
    0, 0, 0, 0,
    1, 1, 2, 2,
    4, 4, 6, 6,
    8, 8, 12, 12,
    SHORT_MAX
};

const s16 sSciserProjectileThrownUpVelocity[25] = {
    0, 1, 0, 1,
    0, 1, 0, 1,
    1, 1, 1, 1,
    1, 1, 2, 2,
    4, 4, 6, 6,
    7, 7, 8, 8,
    SHORT_MAX
};

const u32 sSciserGfx[512 * 2] = INCBIN_U32("data/sprites/sciser.gfx");
const u16 sSciserPal[16 * 2] = INCBIN_U16("data/sprites/sciser.pal");

static const u16 sSciserOam_CrawlingHorizontal_Uninfected_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-13, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sSciserOam_CrawlingHorizontal_Uninfected_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-14, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sSciserOam_CrawlingHorizontal_Uninfected_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-15, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 8, 0),
};

static const u16 sOam_318746[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-18, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x216, 8, 0),
};

static const u16 sOam_31876c[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-18, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(2, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x217, 8, 0),
};

static const u16 sOam_318792[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-18, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_8x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_X_FLIP, 0x217, 8, 0),
};

static const u16 sSciserOam_CrawlingVertical_Uninfected_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(9, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sSciserOam_CrawlingVertical_Uninfected_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sSciserOam_CrawlingVertical_Uninfected_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(8, -3, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20a, 8, 0),
};

static const u16 sOam_3187fa[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(9, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x256, 8, 0),
};

static const u16 sOam_318820[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(9, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-2, 8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x276, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x276, 8, 0),
};

static const u16 sOam_318846[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(6, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(6, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-3, 8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x276, 8, 0),
    OAM_ENTRY(-5, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x276, 8, 0),
};

static const u16 sSciserProjectileOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 9, 0),
};

static const u16 sSciserProjectileOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x233, 9, 0),
};

static const u16 sSciserOam_CrawlingHorizontal_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x242, 9, 0),
    OAM_ENTRY(-16, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sSciserOam_CrawlingHorizontal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-17, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(1, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sSciserOam_CrawlingHorizontal_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-18, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 9, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 9, 0),
};

static const u16 sSciserOam_IdleHorizontal_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(3, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 9, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sSciserOam_IdleHorizontal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(4, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-20, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sSciserOam_ShootingHorizontal_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-20, -13, OAM_DIMS_16x16, OAM_Y_FLIP, 0x240, 9, 0),
    OAM_ENTRY(4, -13, OAM_DIMS_16x16, OAM_XY_FLIP, 0x240, 9, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sSciserOam_PreparingToShootHorizontal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-21, -13, OAM_DIMS_16x16, OAM_Y_FLIP, 0x240, 9, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_16x16, OAM_XY_FLIP, 0x240, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sSciserOam_ShootingHorizontal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-21, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sOam_3189a0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-22, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sSciserOam_ShootingHorizontal_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(6, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-22, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sSciserOam_ShootingHorizontal_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-12, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sSciserOam_ShootingHorizontal_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sSciserOam_PullingClawsDownHorizontal_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-21, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 9, 0),
    OAM_ENTRY(5, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
};

static const u16 sSciserOam_PullingClawsDownHorizontal_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(7, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-23, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
};

static const u16 sSciserOam_PullingClawsDownHorizontal_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(4, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(5, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-21, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sSciserOam_CrawlingVertical_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(9, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20a, 9, 0),
};

static const u16 sSciserOam_CrawlingVertical_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(8, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
};

static const u16 sSciserOam_CrawlingVertical_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(7, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20a, 9, 0),
};

static const u16 sSciserOam_IdleVertical_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(8, 3, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
};

static const u16 sSciserOam_IdleVertical_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(6, 4, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
};

static const u16 sSciserOam_ShootingVertical_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-3, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-3, 4, OAM_DIMS_16x16, OAM_XY_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
};

static const u16 sSciserOam_PreparingToShootVertical_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(-1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-3, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-3, 5, OAM_DIMS_16x16, OAM_XY_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
};

static const u16 sSciserOam_ShootingVertical_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-2, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-2, 5, OAM_DIMS_16x16, OAM_Y_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
};

static const u16 sOam_318bc2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-2, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-2, 6, OAM_DIMS_16x16, OAM_Y_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
};

static const u16 sSciserOam_ShootingVertical_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(2, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(1, 6, OAM_DIMS_16x16, OAM_Y_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
};

static const u16 sSciserOam_ShootingVertical_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(9, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(9, 3, OAM_DIMS_16x16, OAM_Y_FLIP, 0x252, 9, 0),
    OAM_ENTRY(2, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(2, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20a, 9, 0),
};

static const u16 sSciserOam_ShootingVertical_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(7, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(7, 3, OAM_DIMS_16x16, OAM_Y_FLIP, 0x252, 9, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20a, 9, 0),
};

static const u16 sSciserOam_PullingClawsDownVertical_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(5, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(5, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(11, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(11, -21, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x248, 9, 0),
};

static const u16 sSciserOam_PullingClawsDownVertical_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(3, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(3, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(3, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(3, 7, OAM_DIMS_16x16, OAM_Y_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x248, 9, 0),
};

static const u16 sSciserOam_PullingClawsDownVertical_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(3, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(3, 5, OAM_DIMS_16x16, OAM_Y_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0),
};

static const u16 sSciserOam_IdleHorizontal_Uninfected_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-1, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sSciserOam_IdleHorizontal_Uninfected_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sSciserOam_IdleVertical_Uninfected_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(8, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20a, 8, 0),
};

static const u16 sSciserOam_IdleVertical_Uninfected_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(7, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24a, 8, 0),
};

static const u16 sSciserOam_DancingInBackgroundHorizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
};

static const u16 sSciserOam_DancingInBackgroundHorizontal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
};

static const u16 sSciserOam_DancingInBackgroundHorizontal_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
};

static const u16 sSciserOam_DancingInBackgroundVertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25c, 8, 0),
};

static const u16 sSciserOam_DancingInBackgroundVertical_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25e, 8, 0),
};

static const u16 sSciserOam_DancingInBackgroundVertical_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25e, 8, 0),
};

static const u16 sSciserProjectileOam_Exploding1_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(-1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(-7, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
};

static const u16 sSciserProjectileOam_Exploding1_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(-9, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
};

static const u16 sSciserProjectileOam_Exploding1_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(2, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(-10, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
};

static const u16 sSciserProjectileOam_Exploding1_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(-12, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
};

static const u16 sOam_318de4[OAM_DATA_SIZE(0)] = {
    0,
};

static const u16 sSciserProjectileOam_Exploding2_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(-5, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x274, 9, 0),
    OAM_ENTRY(-2, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x274, 9, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x274, 9, 0),
};

static const u16 sSciserProjectileOam_Exploding2_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(-6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
};

static const u16 sSciserProjectileOam_Exploding2_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(-7, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 9, 0),
};

static const u16 sSciserProjectileOam_Exploding2_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(-9, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
    OAM_ENTRY(3, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x275, 9, 0),
};

const struct FrameData sSciserOam_CrawlingHorizontal_Uninfected[5] = {
    [0] = {
        .pFrame = sSciserOam_CrawlingHorizontal_Uninfected_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSciserOam_CrawlingHorizontal_Uninfected_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSciserOam_CrawlingHorizontal_Uninfected_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSciserOam_CrawlingHorizontal_Uninfected_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_IdleHorizontal_Uninfected[5] = {
    [0] = {
        .pFrame = sSciserOam_CrawlingHorizontal_Uninfected_Frame1,
        .timer = 7
    },
    [1] = {
        .pFrame = sSciserOam_IdleHorizontal_Uninfected_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSciserOam_IdleHorizontal_Uninfected_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSciserOam_IdleHorizontal_Uninfected_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_CrawlingVertical_Uninfected[5] = {
    [0] = {
        .pFrame = sSciserOam_CrawlingVertical_Uninfected_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSciserOam_CrawlingVertical_Uninfected_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSciserOam_CrawlingVertical_Uninfected_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSciserOam_CrawlingVertical_Uninfected_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_IdleVertical_Uninfected[5] = {
    [0] = {
        .pFrame = sSciserOam_CrawlingVertical_Uninfected_Frame1,
        .timer = 7
    },
    [1] = {
        .pFrame = sSciserOam_IdleVertical_Uninfected_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSciserOam_IdleVertical_Uninfected_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSciserOam_IdleVertical_Uninfected_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserProjectileOam_Moving[3] = {
    [0] = {
        .pFrame = sSciserProjectileOam_Moving_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSciserProjectileOam_Moving_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_CrawlingHorizontal[5] = {
    [0] = {
        .pFrame = sSciserOam_CrawlingHorizontal_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSciserOam_CrawlingHorizontal_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSciserOam_CrawlingHorizontal_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSciserOam_CrawlingHorizontal_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_IdleHorizontal[3] = {
    [0] = {
        .pFrame = sSciserOam_IdleHorizontal_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSciserOam_IdleHorizontal_Frame1,
        .timer = 8
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_ShootingHorizontal[6] = {
    [0] = {
        .pFrame = sSciserOam_ShootingHorizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSciserOam_ShootingHorizontal_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sSciserOam_ShootingHorizontal_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sSciserOam_ShootingHorizontal_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sSciserOam_ShootingHorizontal_Frame4,
        .timer = 255
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_PreparingToShootHorizontal[3] = {
    [0] = {
        .pFrame = sSciserOam_ShootingHorizontal_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSciserOam_PreparingToShootHorizontal_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_PullingClawsDownHorizontal[6] = {
    [0] = {
        .pFrame = sSciserOam_IdleHorizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSciserOam_ShootingHorizontal_Frame3,
        .timer = 4
    },
    [2] = {
        .pFrame = sSciserOam_PullingClawsDownHorizontal_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSciserOam_PullingClawsDownHorizontal_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sSciserOam_PullingClawsDownHorizontal_Frame4,
        .timer = 255
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_CrawlingVertical[5] = {
    [0] = {
        .pFrame = sSciserOam_CrawlingVertical_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sSciserOam_CrawlingVertical_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSciserOam_CrawlingVertical_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sSciserOam_CrawlingVertical_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_IdleVertical[3] = {
    [0] = {
        .pFrame = sSciserOam_IdleVertical_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSciserOam_IdleVertical_Frame1,
        .timer = 8
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_ShootingVertical[6] = {
    [0] = {
        .pFrame = sSciserOam_ShootingVertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSciserOam_ShootingVertical_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sSciserOam_ShootingVertical_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sSciserOam_ShootingVertical_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sSciserOam_ShootingVertical_Frame4,
        .timer = 255
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_PreparingToShootVertical[3] = {
    [0] = {
        .pFrame = sSciserOam_ShootingVertical_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSciserOam_PreparingToShootVertical_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_PullingClawsDownVertical[6] = {
    [0] = {
        .pFrame = sSciserOam_IdleVertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSciserOam_ShootingVertical_Frame3,
        .timer = 4
    },
    [2] = {
        .pFrame = sSciserOam_PullingClawsDownVertical_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSciserOam_PullingClawsDownVertical_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sSciserOam_PullingClawsDownVertical_Frame4,
        .timer = 255
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_DancingInBackgroundHorizontal[5] = {
    [0] = {
        .pFrame = sSciserOam_DancingInBackgroundHorizontal_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSciserOam_DancingInBackgroundHorizontal_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSciserOam_DancingInBackgroundHorizontal_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSciserOam_DancingInBackgroundHorizontal_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserOam_DancingInBackgroundVertical[5] = {
    [0] = {
        .pFrame = sSciserOam_DancingInBackgroundVertical_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSciserOam_DancingInBackgroundVertical_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sSciserOam_DancingInBackgroundVertical_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSciserOam_DancingInBackgroundVertical_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserProjectileOam_Exploding1[5] = {
    [0] = {
        .pFrame = sSciserProjectileOam_Exploding1_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sSciserProjectileOam_Exploding1_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sSciserProjectileOam_Exploding1_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sSciserProjectileOam_Exploding1_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSciserProjectileOam_Exploding2[5] = {
    [0] = {
        .pFrame = sSciserProjectileOam_Exploding2_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sSciserProjectileOam_Exploding2_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sSciserProjectileOam_Exploding2_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sSciserProjectileOam_Exploding2_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u32 sGoldSciserGfx[512 * 2] = INCBIN_U32("data/sprites/gold_sciser.gfx");
const u16 sGoldSciserPal[16 * 2] = INCBIN_U16("data/sprites/gold_sciser.pal");
