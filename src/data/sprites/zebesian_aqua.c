#include "data/sprites/zebesian_aqua.h"
#include "macros.h"

const u32 sZebesianAquaGfx[512 * 2] = INCBIN_U32("data/sprites/zebesian_aqua.gfx");
const u16 sZebesianAquaPal[PAL_ROW * 2] = INCBIN_U16("data/sprites/zebesian_aqua.pal");

static const u16 sZebesianAquaOam_Unused_38172c_Frame0[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-28, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-20, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-32, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Unused_38172c_Frame1[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-23, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-7, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(11, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-19, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-3, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -33, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-27, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Unused_38172c_Frame2[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-20, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-18, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Unused_38172c_Frame3[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-19, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-3, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-9, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(17, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-19, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-22, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Unused_38172c_Frame4[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-26, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-10, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-21, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-3, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-31, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-15, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Unused_38172c_Frame5[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-35, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-19, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-18, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-21, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-3, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-36, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-20, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Idle_Frame0[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-28, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-20, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-32, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Idle_Frame1[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-28, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-20, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(11, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-32, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Idle_Frame2[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-28, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-20, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-32, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Idle_Frame3[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-28, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-20, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-10, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(17, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Idle_Frame4[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-10, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-21, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-3, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-16, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-33, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-17, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Idle_Frame5[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-28, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-21, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-10, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-3, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Frame_Unused_380efe[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-22, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(5, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-33, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_TurningAround_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-18, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-11, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-3, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-17, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-27, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
};

static const u16 sZebesianAquaOam_TurningAround_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-13, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-5, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-3, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-12, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-16, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
};

static const u16 sZebesianAquaOam_TurningAround_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-13, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-5, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-3, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-12, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-16, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
};

static const u16 sZebesianAquaOam_Frame_Unused_381014[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-12, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-29, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(2, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x244, 8, 0),
    OAM_ENTRY(3, -41, OAM_DIMS_8x8, OAM_X_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-5, -25, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-15, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-7, -34, OAM_DIMS_16x32, OAM_X_FLIP, 0x215, 8, 0),
    OAM_ENTRY(9, -26, OAM_DIMS_8x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-12, -30, OAM_DIMS_16x16, OAM_X_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-12, -14, OAM_DIMS_16x8, OAM_X_FLIP, 0x252, 8, 0),
    OAM_ENTRY(11, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 8, 0),
};

static const u16 sZebesianAquaOam_Frame_Unused_38105e[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(6, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-2, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-13, -3, OAM_DIMS_8x8, OAM_X_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-29, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-1, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(3, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-13, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-13, -15, OAM_DIMS_16x8, OAM_X_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-6, -34, OAM_DIMS_16x32, OAM_X_FLIP, 0x215, 8, 0),
    OAM_ENTRY(10, -26, OAM_DIMS_8x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(17, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame0[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-22, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-33, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame1[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-20, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-35, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-19, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame2[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-21, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-20, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-38, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-22, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame3[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-21, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-5, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-19, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-38, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-22, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame4[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-12, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-20, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-15, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-20, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-32, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-35, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame5[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-12, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-20, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-15, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-14, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-32, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-35, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-34, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-20, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(-11, -33, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-19, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame6[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-12, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-20, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-15, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-32, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-35, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-37, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(-11, -33, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-19, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame7[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-17, -27, OAM_DIMS_8x16, OAM_Y_FLIP, 0x25f, 9, 0),
    OAM_ENTRY(-17, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25f, 9, 0),
    OAM_ENTRY(-12, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-20, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-15, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-37, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x25f, 9, 0),
    OAM_ENTRY(-37, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25f, 9, 0),
    OAM_ENTRY(-32, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-35, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-3, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame8[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-11, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-19, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-17, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-31, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-39, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-34, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-20, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame9[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-12, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-15, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-20, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-32, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-35, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-20, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame10[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-21, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-20, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-38, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-22, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
};

static const u16 sZebesianAquaOam_Shooting_Frame11[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-20, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-19, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-36, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-20, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
};

static const u16 sZebesianAquaProjectileOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 9, 0),
    OAM_ENTRY(-2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 9, 0),
};

static const u16 sZebesianAquaProjectileOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 9, 0),
    OAM_ENTRY(-1, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 9, 0),
};

static const u16 sZebesianAquaProjectileOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 9, 0),
};

static const u16 sZebesianAquaOam_Unused_38184c_Frame2[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-21, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 9, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-38, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-22, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-20, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sZebesianAquaOam_Unused_38184c_Frame3[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-21, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-5, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 9, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-38, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-22, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-19, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sZebesianAquaOam_Unused_38184c_Frame4[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-21, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 9, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-38, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-22, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-20, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sZebesianAquaOam_Unused_38184c_Frame5[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-20, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-35, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-19, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
};

static const u16 sZebesianAquaOam_Unused_38184c_Frame6[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-24, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-33, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

static const u16 sZebesianAquaOam_Frame_Unused_3816dc[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-28, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-12, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-20, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-32, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
};

const struct FrameData sZebesianAquaOam_Unused_38172c[7] = {
    [0] = {
        .pFrame = sZebesianAquaOam_Unused_38172c_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sZebesianAquaOam_Unused_38172c_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sZebesianAquaOam_Unused_38172c_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sZebesianAquaOam_Unused_38172c_Frame3,
        .timer = 10
    },
    [4] = {
        .pFrame = sZebesianAquaOam_Unused_38172c_Frame4,
        .timer = 10
    },
    [5] = {
        .pFrame = sZebesianAquaOam_Unused_38172c_Frame5,
        .timer = 10
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebesianAquaOam_Idle[7] = {
    [0] = {
        .pFrame = sZebesianAquaOam_Idle_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sZebesianAquaOam_Idle_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sZebesianAquaOam_Idle_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sZebesianAquaOam_Idle_Frame3,
        .timer = 10
    },
    [4] = {
        .pFrame = sZebesianAquaOam_Idle_Frame4,
        .timer = 10
    },
    [5] = {
        .pFrame = sZebesianAquaOam_Idle_Frame5,
        .timer = 10
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebesianAquaOam_TurningAround[5] = {
    [0] = {
        .pFrame = sZebesianAquaOam_TurningAround_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sZebesianAquaOam_TurningAround_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sZebesianAquaOam_TurningAround_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sZebesianAquaOam_TurningAround_Frame0,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebesianAquaOam_Shooting[13] = {
    [0] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame7,
        .timer = 1
    },
    [8] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame9,
        .timer = 10
    },
    [10] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame10,
        .timer = 8
    },
    [11] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame11,
        .timer = 8
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebesianAquaProjectileOam_Idle[4] = {
    [0] = {
        .pFrame = sZebesianAquaProjectileOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sZebesianAquaProjectileOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sZebesianAquaProjectileOam_Idle_Frame2,
        .timer = 8
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebesianAquaOam_Unused_38184c[8] = {
    [0] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sZebesianAquaOam_Shooting_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sZebesianAquaOam_Unused_38184c_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sZebesianAquaOam_Unused_38184c_Frame3,
        .timer = 9
    },
    [4] = {
        .pFrame = sZebesianAquaOam_Unused_38184c_Frame4,
        .timer = 10
    },
    [5] = {
        .pFrame = sZebesianAquaOam_Unused_38184c_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sZebesianAquaOam_Unused_38184c_Frame6,
        .timer = 6
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_38188c_38475c[] = INCBIN_U8("data/Blob_38188c_38475c.bin");
