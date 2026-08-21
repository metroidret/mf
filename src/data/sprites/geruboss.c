#include "data/sprites/geruboss.h"
#include "macros.h"

const u32 sGerubossGfx[512 * 1] = INCBIN_U32("data/sprites/geruboss.gfx");
const u16 sGerubossPal[16 * 1] = INCBIN_U16("data/sprites/geruboss.pal");

static const u16 sGerubossOam_Idle_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 9, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 0x20f, 8, 0),
};

static const u16 sGerubossOam_Idle_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 0x20f, 8, 0),
};

static const u16 sGerubossOam_Idle_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 0x20f, 8, 0),
};

static const u16 sGerubossOam_Charging_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-23, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-23, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(7, -1, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_16x8, OAM_Y_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-11, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0),
    OAM_ENTRY(3, -14, OAM_DIMS_16x8, OAM_XY_FLIP, 0x225, 8, 0),
    OAM_ENTRY(3, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x224, 8, 0),
};

static const u16 sGerubossOam_Charging_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-24, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(8, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-21, -14, OAM_DIMS_16x8, OAM_Y_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-13, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_16x8, OAM_XY_FLIP, 0x225, 8, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x224, 8, 0),
};

static const u16 sGerubossOam_Charging_Frame3[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-20, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-20, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(4, -1, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-16, -22, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(0, -22, OAM_DIMS_16x16, OAM_XY_FLIP, 0x20d, 8, 0),
};

static const u16 sGerubossOam_Charging_Frame4[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-21, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(5, 4, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(1, -17, OAM_DIMS_16x16, OAM_XY_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-22, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(14, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -22, OAM_DIMS_8x8, OAM_Y_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x8, OAM_Y_FLIP, 0x215, 8, 0),
    OAM_ENTRY(4, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x238, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x8, OAM_XY_FLIP, 0x215, 8, 0),
};

static const u16 sGerubossOam_GoingDown_Frame0[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-22, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, 2, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-17, -12, OAM_DIMS_16x8, OAM_Y_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, -4, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_16x8, OAM_XY_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-24, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(16, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_8x8, OAM_Y_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_Y_FLIP, 0x215, 8, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x8, OAM_XY_FLIP, 0x238, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_XY_FLIP, 0x215, 8, 0),
};

static const u16 sGerubossOam_GoingDown_Frame1[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-22, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, 2, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-17, -12, OAM_DIMS_16x8, OAM_Y_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, -4, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_16x8, OAM_XY_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-24, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(16, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_Y_FLIP, 0x233, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_XY_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_XY_FLIP, 0x233, 8, 0),
};

static const u16 sGerubossOam_GoingDown_Frame2[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-22, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, 2, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-17, -12, OAM_DIMS_16x8, OAM_Y_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, -4, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_16x8, OAM_XY_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-24, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(16, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_Y_FLIP, 0x213, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_XY_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_XY_FLIP, 0x213, 8, 0),
};

static const u16 sGerubossOam_GrabbingCeiling_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-22, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-17, -10, OAM_DIMS_16x8, OAM_Y_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, -10, OAM_DIMS_16x8, OAM_XY_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, -2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x224, 8, 0),
};

static const u16 sGerubossOam_TiltingUp_Frame0[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-22, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -1, OAM_DIMS_16x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-17, -10, OAM_DIMS_16x8, OAM_Y_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, -10, OAM_DIMS_16x8, OAM_XY_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, -2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-23, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(15, -11, OAM_DIMS_8x8, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -18, OAM_DIMS_8x8, OAM_Y_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x8, OAM_Y_FLIP, 0x215, 8, 0),
    OAM_ENTRY(4, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x238, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x8, OAM_XY_FLIP, 0x215, 8, 0),
};

static const u16 sGerubossOam_TiltingUp_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-22, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -12, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x201, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x223, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x201, 8, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x223, 8, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sGerubossOam_TiltingUp_Frame2[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-22, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-17, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x224, 8, 0),
};

static const u16 sGerubossOam_TiltingUp_Frame3[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-22, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -5, OAM_DIMS_16x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-17, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, 6, OAM_DIMS_16x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-12, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-16, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(4, 15, OAM_DIMS_8x8, OAM_X_FLIP, 0x238, 8, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_16x8, OAM_X_FLIP, 0x215, 8, 0),
};

static const u16 sGerubossOam_GoingUp_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-22, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -5, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-17, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-12, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(4, 20, OAM_DIMS_8x8, OAM_X_FLIP, 0x238, 8, 0),
    OAM_ENTRY(0, 12, OAM_DIMS_16x8, OAM_X_FLIP, 0x215, 8, 0),
};

static const u16 sGerubossOam_GoingUp_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-22, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -5, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-17, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-12, 20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(4, 20, OAM_DIMS_8x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, 12, OAM_DIMS_16x8, OAM_X_FLIP, 0x233, 8, 0),
};

static const u16 sGerubossOam_GoingUp_Frame2[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-22, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-22, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(6, -5, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-17, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(1, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-12, 20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(4, 20, OAM_DIMS_8x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, 12, OAM_DIMS_16x8, OAM_X_FLIP, 0x213, 8, 0),
};

static const u16 sGerubossOam_Stalling_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-21, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-21, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(5, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_16x8, OAM_Y_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-11, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0),
    OAM_ENTRY(3, -14, OAM_DIMS_16x8, OAM_XY_FLIP, 0x225, 8, 0),
    OAM_ENTRY(3, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x224, 8, 0),
};

static const u16 sGerubossOam_Stalling_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-19, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-19, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(3, -9, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(3, -1, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-21, -14, OAM_DIMS_16x8, OAM_Y_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-13, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_16x8, OAM_XY_FLIP, 0x225, 8, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x224, 8, 0),
};

const struct FrameData sGerubossOam_Stalling[4] = {
    [0] = {
        .pFrame = sGerubossOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sGerubossOam_Stalling_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sGerubossOam_Stalling_Frame2,
        .timer = 255
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerubossOam_Idle[5] = {
    [0] = {
        .pFrame = sGerubossOam_Idle_Frame0,
        .timer = 14
    },
    [1] = {
        .pFrame = sGerubossOam_Idle_Frame1,
        .timer = 14
    },
    [2] = {
        .pFrame = sGerubossOam_Idle_Frame2,
        .timer = 14
    },
    [3] = {
        .pFrame = sGerubossOam_Idle_Frame1,
        .timer = 14
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerubossOam_Charging[6] = {
    [0] = {
        .pFrame = sGerubossOam_Idle_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sGerubossOam_Charging_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sGerubossOam_Charging_Frame2,
        .timer = 40
    },
    [3] = {
        .pFrame = sGerubossOam_Charging_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sGerubossOam_Charging_Frame4,
        .timer = 6
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerubossOam_StartGoingDown[4] = {
    [0] = {
        .pFrame = sGerubossOam_GoingDown_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sGerubossOam_GoingDown_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sGerubossOam_GoingDown_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerubossOam_GoingDown[4] = {
    [0] = {
        .pFrame = sGerubossOam_GoingDown_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sGerubossOam_GoingDown_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sGerubossOam_GoingDown_Frame2,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerubossOam_StartGoingUp[4] = {
    [0] = {
        .pFrame = sGerubossOam_GoingUp_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sGerubossOam_GoingUp_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sGerubossOam_GoingUp_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerubossOam_GoingUp[4] = {
    [0] = {
        .pFrame = sGerubossOam_GoingUp_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sGerubossOam_GoingUp_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sGerubossOam_GoingUp_Frame2,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerubossOam_TiltingUp[5] = {
    [0] = {
        .pFrame = sGerubossOam_TiltingUp_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sGerubossOam_TiltingUp_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sGerubossOam_TiltingUp_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sGerubossOam_TiltingUp_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerubossOam_TiltingDown[5] = {
    [0] = {
        .pFrame = sGerubossOam_TiltingUp_Frame3,
        .timer = 4
    },
    [1] = {
        .pFrame = sGerubossOam_TiltingUp_Frame2,
        .timer = 5
    },
    [2] = {
        .pFrame = sGerubossOam_TiltingUp_Frame1,
        .timer = 5
    },
    [3] = {
        .pFrame = sGerubossOam_TiltingUp_Frame0,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerubossOam_GrabbingCeiling[5] = {
    [0] = {
        .pFrame = sGerubossOam_TiltingUp_Frame3,
        .timer = 4
    },
    [1] = {
        .pFrame = sGerubossOam_TiltingUp_Frame2,
        .timer = 5
    },
    [2] = {
        .pFrame = sGerubossOam_TiltingUp_Frame1,
        .timer = 5
    },
    [3] = {
        .pFrame = sGerubossOam_GrabbingCeiling_Frame3,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};
