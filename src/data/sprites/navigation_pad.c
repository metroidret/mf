#include "data/sprites/navigation_pad.h"

const u32 sNavigationPadGfx[512 * 3] = INCBIN_U32("data/sprites/navigation_pad.gfx");
const u16 sNavigationPadPal[16 * 3] = INCBIN_U16("data/sprites/navigation_pad.pal");

static const u16 sNavigationPadOam_31e268_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-40, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_32x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x26a, 8, 0),
};

static const u16 sNavigationPadOam_31e318_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x259, 9, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 9, 0),
    OAM_ENTRY(8, 24, OAM_DIMS_16x8, OAM_X_FLIP, 0x259, 9, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0x25b, 9, 0),
};

static const u16 sNavigationPadOam_31e278_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(8, 24, OAM_DIMS_16x8, OAM_X_FLIP, 0x25c, 9, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25c, 9, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
};

static const u16 sNavigationPadOam_31e278_Frame1[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27c, 9, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(8, 24, OAM_DIMS_16x8, OAM_X_FLIP, 0x27c, 9, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23a, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x23a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x23c, 9, 0),
    OAM_ENTRY(-23, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-18, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(2, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(15, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
};

static const u16 sNavigationPadOam_31e278_Frame2[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x21f, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(-24, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27c, 9, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(8, 24, OAM_DIMS_16x8, OAM_X_FLIP, 0x27c, 9, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0x27e, 9, 0),
};

static const u16 sNavigationPadOam_31e278_Frame3[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x21f, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(-25, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(17, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27c, 9, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(8, 24, OAM_DIMS_16x8, OAM_X_FLIP, 0x27c, 9, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0x27e, 9, 0),
};

static const u16 sNavigationPadOam_31e2a0_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
};

static const u16 sNavigationPadOam_31e2a0_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x20d, 8, 0),
};

static const u16 sNavigationPadOam_31e2a0_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x210, 8, 0),
};

static const u16 sNavigationPadOam_31e2c8_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 8, 0),
};

static const u16 sNavigationPadOam_31e2c8_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x216, 8, 0),
};

static const u16 sNavigationPadOam_31e2c8_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 8, 0),
};

static const u16 sNavigationPadOam_31e328_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
};

static const u16 sNavigationPadOam_31e328_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-32, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sNavigationPadOam_31e340_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sNavigationPadOam_31e340_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-4, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sNavigationPadOam_31e340_Frame2[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sNavigationPadOam_31e340_Frame3[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sNavigationPadOam_31e340_Frame4[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sNavigationPadOam_31e340_Frame5[OAM_DATA_SIZE(28)] = {
    28,
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sNavigationPadOam_31e340_Frame6[OAM_DATA_SIZE(36)] = {
    36,
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, 11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, 11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, 11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, 11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

const struct FrameData sNavigationPadOam_31e268[2] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e268_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNavigationPadOam_31e278[5] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e278_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sNavigationPadOam_31e278_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sNavigationPadOam_31e278_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sNavigationPadOam_31e278_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNavigationPadOam_31e2a0[5] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e2a0_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sNavigationPadOam_31e2a0_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sNavigationPadOam_31e2a0_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sNavigationPadOam_31e2a0_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNavigationPadOam_31e2c8[5] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e2c8_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sNavigationPadOam_31e2c8_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sNavigationPadOam_31e2c8_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sNavigationPadOam_31e2c8_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNavigationPadOam_31e2f0[5] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e278_Frame3,
        .timer = 6
    },
    [1] = {
        .pFrame = sNavigationPadOam_31e278_Frame2,
        .timer = 6
    },
    [2] = {
        .pFrame = sNavigationPadOam_31e278_Frame1,
        .timer = 6
    },
    [3] = {
        .pFrame = sNavigationPadOam_31e278_Frame0,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNavigationPadOam_31e318[2] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e318_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNavigationPadOam_31e328[3] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e328_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sNavigationPadOam_31e328_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNavigationPadOam_31e340[8] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e340_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sNavigationPadOam_31e340_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sNavigationPadOam_31e340_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sNavigationPadOam_31e340_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sNavigationPadOam_31e340_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sNavigationPadOam_31e340_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sNavigationPadOam_31e340_Frame6,
        .timer = 1
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNavigationPadOam_31e380[2] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e278_Frame3,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNavigationPadOam_31e390[8] = {
    [0] = {
        .pFrame = sNavigationPadOam_31e340_Frame6,
        .timer = 1
    },
    [1] = {
        .pFrame = sNavigationPadOam_31e340_Frame5,
        .timer = 1
    },
    [2] = {
        .pFrame = sNavigationPadOam_31e340_Frame4,
        .timer = 1
    },
    [3] = {
        .pFrame = sNavigationPadOam_31e340_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sNavigationPadOam_31e340_Frame2,
        .timer = 2
    },
    [5] = {
        .pFrame = sNavigationPadOam_31e340_Frame1,
        .timer = 3
    },
    [6] = {
        .pFrame = sNavigationPadOam_31e340_Frame0,
        .timer = 3
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_31e3d0_35dd74[] = INCBIN_U8("data/Blob_31e3d0_35dd74.bin");
