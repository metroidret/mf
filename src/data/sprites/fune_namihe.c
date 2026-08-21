#include "data/sprites/fune_namihe.h"
#include "macros.h"

const u32 sFuneNamiheGfx[2 * 512] = INCBIN_U32("data/sprites/fune_namihe.gfx");
const u16 sFuneNamihePal[2 * 16] = INCBIN_U16("data/sprites/fune_namihe.pal");

static const u16 sFuneOam_Idle_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sFuneOam_Idle_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sFuneOam_Idle_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sFuneOam_Spitting_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sFuneOam_Spitting_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sFuneOam_Spitting_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 3, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sFuneOam_Spitting_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(12, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, -3, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(12, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame6[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-17, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(36, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame7[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, -3, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(12, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(36, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(48, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame8[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(36, -18, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(48, -18, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(60, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame9[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-17, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(12, -10, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(36, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(48, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(60, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame10[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(31, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(43, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(55, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(67, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(79, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame11[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(20, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(32, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(44, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(56, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(68, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(80, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame12[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-19, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-3, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(7, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(18, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(29, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(40, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(51, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(62, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(72, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame13[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-20, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(18, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(28, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(37, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(46, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(55, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(64, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame14[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-20, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(8, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -9, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(32, -10, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(48, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(56, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame15[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-17, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-20, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(16, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(32, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(40, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(48, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame16[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-17, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-20, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(32, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(40, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame17[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-20, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame18[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-20, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(24, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame19[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-20, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneOam_Lunging_Frame20[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-20, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sFuneSpitOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 9, 0),
};

static const u16 sFuneSpitOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 9, 0),
};

static const u16 sFuneSpitOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 9, 0),
};

static const u16 sFuneSpitOam_Exploding_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x253, 9, 0),
};

static const u16 sFuneSpitOam_Exploding_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x255, 9, 0),
};

static const u16 sFuneSpitOam_Exploding_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x257, 9, 0),
};

const struct FrameData sFuneOam_Idle[9] = {
    [0] = {
        .pFrame = sFuneOam_Idle_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sFuneOam_Idle_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sFuneOam_Idle_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sFuneOam_Idle_Frame1,
        .timer = 16
    },
    [4] = {
        .pFrame = sFuneOam_Idle_Frame0,
        .timer = 16
    },
    [5] = {
        .pFrame = sFuneOam_Idle_Frame1,
        .timer = 16
    },
    [6] = {
        .pFrame = sFuneOam_Idle_Frame2,
        .timer = 16
    },
    [7] = {
        .pFrame = sFuneOam_Idle_Frame1,
        .timer = 16
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFuneOam_Spitting[9] = {
    [0] = {
        .pFrame = sFuneOam_Spitting_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sFuneOam_Spitting_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sFuneOam_Spitting_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sFuneOam_Spitting_Frame3,
        .timer = 40
    },
    [4] = {
        .pFrame = sFuneOam_Spitting_Frame2,
        .timer = 8
    },
    [5] = {
        .pFrame = sFuneOam_Spitting_Frame1,
        .timer = 8
    },
    [6] = {
        .pFrame = sFuneOam_Spitting_Frame0,
        .timer = 8
    },
    [7] = {
        .pFrame = sFuneOam_Idle_Frame0,
        .timer = 50
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFuneOam_Lunging[27] = {
    [0] = {
        .pFrame = sFuneOam_Spitting_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sFuneOam_Spitting_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sFuneOam_Spitting_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sFuneOam_Spitting_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sFuneOam_Lunging_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sFuneOam_Lunging_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sFuneOam_Lunging_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sFuneOam_Lunging_Frame7,
        .timer = 4
    },
    [8] = {
        .pFrame = sFuneOam_Lunging_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sFuneOam_Lunging_Frame9,
        .timer = 3
    },
    [10] = {
        .pFrame = sFuneOam_Lunging_Frame10,
        .timer = 20
    },
    [11] = {
        .pFrame = sFuneOam_Lunging_Frame11,
        .timer = 3
    },
    [12] = {
        .pFrame = sFuneOam_Lunging_Frame12,
        .timer = 3
    },
    [13] = {
        .pFrame = sFuneOam_Lunging_Frame13,
        .timer = 3
    },
    [14] = {
        .pFrame = sFuneOam_Lunging_Frame14,
        .timer = 3
    },
    [15] = {
        .pFrame = sFuneOam_Lunging_Frame15,
        .timer = 3
    },
    [16] = {
        .pFrame = sFuneOam_Lunging_Frame16,
        .timer = 2
    },
    [17] = {
        .pFrame = sFuneOam_Lunging_Frame17,
        .timer = 2
    },
    [18] = {
        .pFrame = sFuneOam_Lunging_Frame18,
        .timer = 2
    },
    [19] = {
        .pFrame = sFuneOam_Lunging_Frame19,
        .timer = 2
    },
    [20] = {
        .pFrame = sFuneOam_Lunging_Frame20,
        .timer = 2
    },
    [21] = {
        .pFrame = sFuneOam_Spitting_Frame3,
        .timer = 2
    },
    [22] = {
        .pFrame = sFuneOam_Spitting_Frame2,
        .timer = 2
    },
    [23] = {
        .pFrame = sFuneOam_Spitting_Frame1,
        .timer = 2
    },
    [24] = {
        .pFrame = sFuneOam_Spitting_Frame0,
        .timer = 2
    },
    [25] = {
        .pFrame = sFuneOam_Idle_Frame0,
        .timer = 50
    },
    [26] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFuneSpitOam_Moving[4] = {
    [0] = {
        .pFrame = sFuneSpitOam_Moving_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sFuneSpitOam_Moving_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sFuneSpitOam_Moving_Frame2,
        .timer = 5
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFuneSpitOam_Exploding[4] = {
    [0] = {
        .pFrame = sFuneSpitOam_Exploding_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sFuneSpitOam_Exploding_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sFuneSpitOam_Exploding_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

static const u16 sNamiheOam_Idle_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Idle_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Idle_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Spitting_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Spitting_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Spitting_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26f, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Spitting_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Spitting_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Spitting_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Spitting_Frame6[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Spitting_Frame7[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame12[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame13[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, -2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame14[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-17, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 7, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(36, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame15[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, -2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(36, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(48, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame16[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(36, -18, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(48, -18, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(60, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame17[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-17, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 1, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -10, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(36, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(48, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(60, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame18[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(31, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(43, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(55, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(67, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(79, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame19[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(20, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(32, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(44, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(56, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(68, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(80, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame20[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(7, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(18, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(29, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(40, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(51, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(62, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(72, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame21[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(18, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(28, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(37, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(46, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(55, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(64, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame22[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -9, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(32, -10, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(48, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(56, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame23[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-17, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(32, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(40, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(48, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame24[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-17, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(32, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(40, -17, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame25[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame26[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(24, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame27[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheOam_Lunging_Frame28[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-19, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-3, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sNamiheSpitOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sNamiheSpitOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sNamiheSpitOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
};

static const u16 sNamiheSpitOam_Exploding_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x253, 8, 0),
};

static const u16 sNamiheSpitOam_Exploding_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x255, 8, 0),
};

static const u16 sNamiheSpitOam_Exploding_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x257, 8, 0),
};

const struct FrameData sNamiheOam_Idle[9] = {
    [0] = {
        .pFrame = sNamiheOam_Idle_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sNamiheOam_Idle_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sNamiheOam_Idle_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sNamiheOam_Idle_Frame1,
        .timer = 16
    },
    [4] = {
        .pFrame = sNamiheOam_Idle_Frame0,
        .timer = 16
    },
    [5] = {
        .pFrame = sNamiheOam_Idle_Frame1,
        .timer = 16
    },
    [6] = {
        .pFrame = sNamiheOam_Idle_Frame2,
        .timer = 16
    },
    [7] = {
        .pFrame = sNamiheOam_Idle_Frame1,
        .timer = 16
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNamiheOam_Spitting[17] = {
    [0] = {
        .pFrame = sNamiheOam_Spitting_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sNamiheOam_Spitting_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sNamiheOam_Spitting_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sNamiheOam_Spitting_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sNamiheOam_Spitting_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sNamiheOam_Spitting_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sNamiheOam_Spitting_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sNamiheOam_Spitting_Frame7,
        .timer = 50
    },
    [8] = {
        .pFrame = sNamiheOam_Spitting_Frame6,
        .timer = 8
    },
    [9] = {
        .pFrame = sNamiheOam_Spitting_Frame5,
        .timer = 8
    },
    [10] = {
        .pFrame = sNamiheOam_Spitting_Frame4,
        .timer = 8
    },
    [11] = {
        .pFrame = sNamiheOam_Spitting_Frame3,
        .timer = 10
    },
    [12] = {
        .pFrame = sNamiheOam_Spitting_Frame2,
        .timer = 4
    },
    [13] = {
        .pFrame = sNamiheOam_Spitting_Frame1,
        .timer = 4
    },
    [14] = {
        .pFrame = sNamiheOam_Spitting_Frame0,
        .timer = 4
    },
    [15] = {
        .pFrame = sNamiheOam_Idle_Frame0,
        .timer = 50
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNamiheOam_Lunging[39] = {
    [0] = {
        .pFrame = sNamiheOam_Spitting_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sNamiheOam_Spitting_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sNamiheOam_Spitting_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sNamiheOam_Spitting_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sNamiheOam_Lunging_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sNamiheOam_Lunging_Frame5,
        .timer = 5
    },
    [6] = {
        .pFrame = sNamiheOam_Lunging_Frame4,
        .timer = 6
    },
    [7] = {
        .pFrame = sNamiheOam_Spitting_Frame3,
        .timer = 2
    },
    [8] = {
        .pFrame = sNamiheOam_Spitting_Frame4,
        .timer = 3
    },
    [9] = {
        .pFrame = sNamiheOam_Spitting_Frame5,
        .timer = 3
    },
    [10] = {
        .pFrame = sNamiheOam_Spitting_Frame6,
        .timer = 3
    },
    [11] = {
        .pFrame = sNamiheOam_Spitting_Frame7,
        .timer = 3
    },
    [12] = {
        .pFrame = sNamiheOam_Lunging_Frame12,
        .timer = 6
    },
    [13] = {
        .pFrame = sNamiheOam_Lunging_Frame13,
        .timer = 6
    },
    [14] = {
        .pFrame = sNamiheOam_Lunging_Frame14,
        .timer = 4
    },
    [15] = {
        .pFrame = sNamiheOam_Lunging_Frame15,
        .timer = 4
    },
    [16] = {
        .pFrame = sNamiheOam_Lunging_Frame16,
        .timer = 4
    },
    [17] = {
        .pFrame = sNamiheOam_Lunging_Frame17,
        .timer = 3
    },
    [18] = {
        .pFrame = sNamiheOam_Lunging_Frame18,
        .timer = 20
    },
    [19] = {
        .pFrame = sNamiheOam_Lunging_Frame19,
        .timer = 3
    },
    [20] = {
        .pFrame = sNamiheOam_Lunging_Frame20,
        .timer = 3
    },
    [21] = {
        .pFrame = sNamiheOam_Lunging_Frame21,
        .timer = 3
    },
    [22] = {
        .pFrame = sNamiheOam_Lunging_Frame22,
        .timer = 3
    },
    [23] = {
        .pFrame = sNamiheOam_Lunging_Frame23,
        .timer = 3
    },
    [24] = {
        .pFrame = sNamiheOam_Lunging_Frame24,
        .timer = 2
    },
    [25] = {
        .pFrame = sNamiheOam_Lunging_Frame25,
        .timer = 2
    },
    [26] = {
        .pFrame = sNamiheOam_Lunging_Frame26,
        .timer = 2
    },
    [27] = {
        .pFrame = sNamiheOam_Lunging_Frame27,
        .timer = 2
    },
    [28] = {
        .pFrame = sNamiheOam_Lunging_Frame28,
        .timer = 2
    },
    [29] = {
        .pFrame = sNamiheOam_Spitting_Frame7,
        .timer = 2
    },
    [30] = {
        .pFrame = sNamiheOam_Spitting_Frame6,
        .timer = 2
    },
    [31] = {
        .pFrame = sNamiheOam_Spitting_Frame5,
        .timer = 2
    },
    [32] = {
        .pFrame = sNamiheOam_Spitting_Frame4,
        .timer = 2
    },
    [33] = {
        .pFrame = sNamiheOam_Spitting_Frame3,
        .timer = 4
    },
    [34] = {
        .pFrame = sNamiheOam_Spitting_Frame2,
        .timer = 4
    },
    [35] = {
        .pFrame = sNamiheOam_Spitting_Frame1,
        .timer = 4
    },
    [36] = {
        .pFrame = sNamiheOam_Spitting_Frame0,
        .timer = 4
    },
    [37] = {
        .pFrame = sNamiheOam_Idle_Frame0,
        .timer = 50
    },
    [38] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNamiheSpitOam_Moving[4] = {
    [0] = {
        .pFrame = sNamiheSpitOam_Moving_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sNamiheSpitOam_Moving_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sNamiheSpitOam_Moving_Frame2,
        .timer = 5
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNamiheSpitOam_Exploding[4] = {
    [0] = {
        .pFrame = sNamiheSpitOam_Exploding_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sNamiheSpitOam_Exploding_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sNamiheSpitOam_Exploding_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};
