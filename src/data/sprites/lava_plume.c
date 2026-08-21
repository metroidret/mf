#include "data/sprites/lava_plume.h"

#include "macros.h"

const u32 sLavaPlumeGfx[1 * 512] = INCBIN_U32("data/sprites/lava_plume.gfx");
static const u16 sLavaPlumePal[1 * 16] = INCBIN_U16("data/sprites/lava_plume.pal");

static const u16 sLavaPlumeWarningOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-12, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x234, 8, 0),
};

static const u16 sLavaPlumeWarningOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x214, 8, 0),
};

static const u16 sLavaPlumeWarningOam_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(5, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sLavaPlumeWarningOam_Idle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(5, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-20, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
};

static const u16 sLavaPlumeWarningOam_Idle_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(5, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, 20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, 22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, 24, OAM_DIMS_16x16, OAM_XY_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, 26, OAM_DIMS_16x16, OAM_XY_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame8[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, 34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, 26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame9[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, 26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame10[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-7, 50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x16, OAM_XY_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame11[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(2, 67, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 67, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 57, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 57, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x16, OAM_XY_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame12[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-7, 66, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 71, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 71, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 61, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 61, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, 26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame13[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-7, 74, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 75, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 75, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 65, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 65, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, 26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_GoingUp_Frame14[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-7, 78, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 75, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 75, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 65, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 65, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x16, OAM_XY_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_Idle_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-7, 82, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 75, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 75, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 65, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 65, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x16, OAM_XY_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_Stopping_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-7, 66, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 59, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 59, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 49, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 49, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_Stopping_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-7, 45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_Stopping_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-7, 35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_XY_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_Y_FLIP, 0x200, 8, 0),
};

static const u16 sLavaPlumeOam_Stopping_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-7, 21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
};

static const u16 sLavaPlumeOam_Stopping_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
};

static const u16 sLavaPlumeOam_Stopping_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(2, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
};

static const u16 sLavaPlumeOam_Stopping_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
};

const struct FrameData sLavaPlumeWarningOam_Idle1[5] = {
    [0] = {
        .pFrame = sLavaPlumeWarningOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sLavaPlumeWarningOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sLavaPlumeWarningOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sLavaPlumeWarningOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLavaPlumeWarningOam_Idle2[6] = {
    [0] = {
        .pFrame = sLavaPlumeWarningOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sLavaPlumeWarningOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sLavaPlumeWarningOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sLavaPlumeWarningOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sLavaPlumeWarningOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = FRAME_DATA_TERMINATOR
};


const struct FrameData sLavaPlumeOam_GoingUp[16] = {
    [0] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame7,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sLavaPlumeOam_GoingUp_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLavaPlumeOam_Idle[2] = {
    [0] = {
        .pFrame = sLavaPlumeOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLavaPlumeOam_Stopping[8] = {
    [0] = {
        .pFrame = sLavaPlumeOam_Stopping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sLavaPlumeOam_Stopping_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sLavaPlumeOam_Stopping_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sLavaPlumeOam_Stopping_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sLavaPlumeOam_Stopping_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sLavaPlumeOam_Stopping_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sLavaPlumeOam_Stopping_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};
