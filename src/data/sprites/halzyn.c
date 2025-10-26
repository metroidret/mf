#include "data/sprites/halzyn.h"
#include "macros.h"

const s16 sHalzynSwingingXVelocity[16] = {
    0, 0, 1, 2,
    3, 4, 5, 6,
    7, 6, 5, 4,
    3, 2, 1, 0
};

const s16 sHalzynSwingingYVelocity[16] = {
     0,  1,  2,  3,
     4,  3,  2,  1,
    -1, -2, -3, -4,
    -3, -2, -1,  0
};

const s16 sHalzynLungingVelocity[28] = {
    2, 4, 6, 8, 12, 14, 16, 18, 20, 22, 24, SHORT_MAX,
    22, 20, 18, 16, 14, 12, 8, 7, 6, 5, 4, 3, 2, 1, 0, SHORT_MAX
};

const u32 sHalzynGfx[1024] = INCBIN_U32("data/sprites/halzyn.gfx");
const u16 sHalzynPal[16 * 2] = INCBIN_U16("data/sprites/halzyn.pal");

static const u16 sOam_2ec964[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2ec978[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sOam_2ec980[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-19, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sOam_2ec988[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-20, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sOam_2ec990[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2ec9a4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2ec9b8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2ec9cc[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2ec9e0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-20, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sOam_2ec9e8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-25, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sOam_2ec9f6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-28, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-12, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x244, 8, 0),
};

static const u16 sOam_2eca04[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-28, -30, OAM_DIMS_16x32, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
};

static const u16 sOam_2eca12[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2eca26[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2eca3a[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26c, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x26c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-13, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2eca5a[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2eca6e[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-15, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sOam_2eca76[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sOam_2eca7e[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2eca92[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-23, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sOam_2ecaa0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-24, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sOam_2ecaae[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(5, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2ecac2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-13, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2ecad6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x270, 8, 0),
};

static const u16 sOam_2ecaea[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x251, 8, 0),
};

static const u16 sOam_2ecb0a[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
};

static const u16 sOam_2ecb24[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x270, 8, 0),
};

static const u16 sOam_2ecb3e[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x251, 8, 0),
};

static const u16 sOam_2ecb58[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
};

static const u16 sOam_2ecb72[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-18, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
};

static const u16 sOam_2ecb86[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-18, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x252, 8, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 8, 0),
};

static const u16 sOam_2ecba6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-18, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
};

static const u16 sOam_2ecbc0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-18, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
};

static const u16 sOam_2ecbd4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-18, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x252, 8, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x216, 8, 0),
};

static const u16 sOam_2ecbf4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26d, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x26d, 8, 0),
    OAM_ENTRY(-18, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
};

static const u16 sOam_2ecc14[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-20, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(4, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0),
};

static const u16 sOam_2ecc28[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x258, 8, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 8, 0),
};

static const u16 sOam_2ecc48[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-20, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(4, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 8, 0),
};

static const u16 sOam_2ecc68[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-20, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(4, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0),
};

static const u16 sOam_2ecc82[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(5, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x258, 8, 0),
};

static const u16 sOam_2ecc9c[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-20, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(4, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
};

static const u16 sOam_2eccb0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-20, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
};

static const u16 sOam_2eccd0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
};

static const u16 sOam_2eccf0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-20, -15, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25c, 8, 0),
};

static const u16 sOam_2ecd10[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-19, -11, OAM_DIMS_16x16, OAM_Y_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
};

static const u16 sOam_2ecd30[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-20, -10, OAM_DIMS_16x16, OAM_Y_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x252, 8, 0),
};

static const u16 sOam_2ecd50[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-19, -10, OAM_DIMS_16x16, OAM_Y_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
};

static const u16 sOam_2ecd70[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(7, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x237, 8, 0),
};

static const u16 sOam_2ecd9c[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-9, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(1, -23, OAM_DIMS_8x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-15, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(7, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x237, 8, 0),
};

static const u16 sOam_2ecdc8[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(7, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-10, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x271, 8, 0),
};

static const u16 sOam_2ecdf4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-9, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(1, -23, OAM_DIMS_8x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-15, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(7, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x271, 8, 0),
};

static const u16 sOam_2ece20[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-9, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(1, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(7, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x251, 8, 0),
};

static const u16 sOam_2ece4c[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -25, OAM_DIMS_8x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(7, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x251, 8, 0),
};

static const u16 sOam_2ece78[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-9, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(1, -25, OAM_DIMS_8x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-15, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(7, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x251, 8, 0),
    OAM_ENTRY(3, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x271, 8, 0),
};

static const u16 sOam_2ecea4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -25, OAM_DIMS_8x8, OAM_X_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(7, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x251, 8, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x271, 8, 0),
};

const struct FrameData sHalzynOam_Swinging[5] = {
    [0] = {
        .pFrame = sOam_2ec964,
        .timer = 15,
    },
    [1] = {
        .pFrame = sOam_2ec964,
        .timer = 11,
    },
    [2] = {
        .pFrame = sOam_2ec964,
        .timer = 13,
    },
    [3] = {
        .pFrame = sOam_2ec964,
        .timer = 11,
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynWingOam_Idle[5] = {
    [0] = {
        .pFrame = sOam_2ec978,
        .timer = 15,
    },
    [1] = {
        .pFrame = sOam_2ec980,
        .timer = 11,
    },
    [2] = {
        .pFrame = sOam_2ec988,
        .timer = 13,
    },
    [3] = {
        .pFrame = sOam_2ec980,
        .timer = 11,
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_FlyingUp[7] = {
    [0] = {
        .pFrame = sOam_2ec990,
        .timer = 4,
    },
    [1] = {
        .pFrame = sOam_2ec9a4,
        .timer = 2,
    },
    [2] = {
        .pFrame = sOam_2ec9b8,
        .timer = 2,
    },
    [3] = {
        .pFrame = sOam_2ec9cc,
        .timer = 4,
    },
    [4] = {
        .pFrame = sOam_2ec9b8,
        .timer = 2,
    },
    [5] = {
        .pFrame = sOam_2ec9a4,
        .timer = 2,
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynWingOam_Flapping[7] = {
    [0] = {
        .pFrame = sOam_2ec9e0,
        .timer = 4,
    },
    [1] = {
        .pFrame = sOam_2ec9e8,
        .timer = 2,
    },
    [2] = {
        .pFrame = sOam_2ec9f6,
        .timer = 2,
    },
    [3] = {
        .pFrame = sOam_2eca04,
        .timer = 4,
    },
    [4] = {
        .pFrame = sOam_2ec9f6,
        .timer = 2,
    },
    [5] = {
        .pFrame = sOam_2ec9e8,
        .timer = 2,
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_Lunging[8] = {
    [0] = {
        .pFrame = sOam_2eca12,
        .timer = 2,
    },
    [1] = {
        .pFrame = sOam_2eca26,
        .timer = 2,
    },
    [2] = {
        .pFrame = sOam_2eca12,
        .timer = 2,
    },
    [3] = {
        .pFrame = sOam_2eca3a,
        .timer = 2,
    },
    [4] = {
        .pFrame = sOam_2eca26,
        .timer = 2,
    },
    [5] = {
        .pFrame = sOam_2ec964,
        .timer = 20,
    },
    [6] = {
        .pFrame = sOam_2eca5a,
        .timer = 255,
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynWingOam_Lunging[8] = {
    [0] = {
        .pFrame = sOam_2eca6e,
        .timer = 2,
    },
    [1] = {
        .pFrame = sOam_2ec978,
        .timer = 2,
    },
    [2] = {
        .pFrame = sOam_2eca6e,
        .timer = 2,
    },
    [3] = {
        .pFrame = sOam_2eca76,
        .timer = 2,
    },
    [4] = {
        .pFrame = sOam_2ec978,
        .timer = 2,
    },
    [5] = {
        .pFrame = sOam_2ec978,
        .timer = 20,
    },
    [6] = {
        .pFrame = sOam_2eca76,
        .timer = 255,
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed010[7] = {
    [0] = {
        .pFrame = sOam_2ec964,
        .timer = 4,
    },
    [1] = {
        .pFrame = sOam_2ec964,
        .timer = 1,
    },
    [2] = {
        .pFrame = sOam_2eca7e,
        .timer = 2,
    },
    [3] = {
        .pFrame = sOam_2eca7e,
        .timer = 1,
    },
    [4] = {
        .pFrame = sOam_2eca7e,
        .timer = 2,
    },
    [5] = {
        .pFrame = sOam_2ec964,
        .timer = 1,
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed048[7] = {
    [0] = {
        .pFrame = sOam_2ec978,
        .timer = 4,
    },
    [1] = {
        .pFrame = sOam_2ec980,
        .timer = 1,
    },
    [2] = {
        .pFrame = sOam_2eca92,
        .timer = 2,
    },
    [3] = {
        .pFrame = sOam_2ecaa0,
        .timer = 1,
    },
    [4] = {
        .pFrame = sOam_2eca92,
        .timer = 2,
    },
    [5] = {
        .pFrame = sOam_2ec980,
        .timer = 1,
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_Landing[4] = {
    [0] = {
        .pFrame = sOam_2ec964,
        .timer = 4,
    },
    [1] = {
        .pFrame = sOam_2ecaae,
        .timer = 4,
    },
    [2] = {
        .pFrame = sOam_2ecac2,
        .timer = 255,
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynWingOam_Landing[4] = {
    [0] = {
        .pFrame = sOam_2ec978,
        .timer = 4,
    },
    [1] = {
        .pFrame = sOam_2eca76,
        .timer = 4,
    },
    [2] = {
        .pFrame = sOam_2eca76,
        .timer = 255,
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed0c0[4] = {
    [0] = {
        .pFrame = sOam_2ecad6,
        .timer = 7,
    },
    [1] = {
        .pFrame = sOam_2ecaea,
        .timer = 7,
    },
    [2] = {
        .pFrame = sOam_2ecb0a,
        .timer = 7,
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed0e0[4] = {
    [0] = {
        .pFrame = sOam_2ecad6,
        .timer = 4,
    },
    [1] = {
        .pFrame = sOam_2ecaea,
        .timer = 4,
    },
    [2] = {
        .pFrame = sOam_2ecb0a,
        .timer = 4,
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed100[4] = {
    [0] = {
        .pFrame = sOam_2ecb24,
        .timer = 7,
    },
    [1] = {
        .pFrame = sOam_2ecb3e,
        .timer = 7,
    },
    [2] = {
        .pFrame = sOam_2ecb58,
        .timer = 7,
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed120[10] = {
    [0] = {
        .pFrame = sOam_2ecb72,
        .timer = 12,
    },
    [1] = {
        .pFrame = sOam_2ecb86,
        .timer = 12,
    },
    [2] = {
        .pFrame = sOam_2ecba6,
        .timer = 12,
    },
    [3] = {
        .pFrame = sOam_2ecb72,
        .timer = 12,
    },
    [4] = {
        .pFrame = sOam_2ecb86,
        .timer = 12,
    },
    [5] = {
        .pFrame = sOam_2ecba6,
        .timer = 12,
    },
    [6] = {
        .pFrame = sOam_2ecbc0,
        .timer = 8,
    },
    [7] = {
        .pFrame = sOam_2ecbd4,
        .timer = 8,
    },
    [8] = {
        .pFrame = sOam_2ecbf4,
        .timer = 8,
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed170[4] = {
    [0] = {
        .pFrame = sOam_2ecbc0,
        .timer = 8,
    },
    [1] = {
        .pFrame = sOam_2ecbd4,
        .timer = 8,
    },
    [2] = {
        .pFrame = sOam_2ecbf4,
        .timer = 8,
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed190[7] = {
    [0] = {
        .pFrame = sOam_2ecc14,
        .timer = 9,
    },
    [1] = {
        .pFrame = sOam_2ecc28,
        .timer = 9,
    },
    [2] = {
        .pFrame = sOam_2ecc48,
        .timer = 9,
    },
    [3] = {
        .pFrame = sOam_2ecc68,
        .timer = 9,
    },
    [4] = {
        .pFrame = sOam_2ecc82,
        .timer = 9,
    },
    [5] = {
        .pFrame = sOam_2ecc9c,
        .timer = 9,
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed1c8[4] = {
    [0] = {
        .pFrame = sOam_2eccb0,
        .timer = 3,
    },
    [1] = {
        .pFrame = sOam_2eccd0,
        .timer = 3,
    },
    [2] = {
        .pFrame = sOam_2eccf0,
        .timer = 3,
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed1e8[4] = {
    [0] = {
        .pFrame = sOam_2ecd10,
        .timer = 3,
    },
    [1] = {
        .pFrame = sOam_2ecd30,
        .timer = 3,
    },
    [2] = {
        .pFrame = sOam_2ecd50,
        .timer = 3,
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed208[3] = {
    [0] = {
        .pFrame = sOam_2ecd70,
        .timer = 4,
    },
    [1] = {
        .pFrame = sOam_2ecd9c,
        .timer = 16,
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed220[3] = {
    [0] = {
        .pFrame = sOam_2ecdc8,
        .timer = 4,
    },
    [1] = {
        .pFrame = sOam_2ecdf4,
        .timer = 255,
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed238[10] = {
    [0] = {
        .pFrame = sOam_2ec964,
        .timer = 20,
    },
    [1] = {
        .pFrame = sOam_2ece20,
        .timer = 2,
    },
    [2] = {
        .pFrame = sOam_2ece4c,
        .timer = 2,
    },
    [3] = {
        .pFrame = sOam_2ece20,
        .timer = 2,
    },
    [4] = {
        .pFrame = sOam_2ece4c,
        .timer = 2,
    },
    [5] = {
        .pFrame = sOam_2ece20,
        .timer = 2,
    },
    [6] = {
        .pFrame = sOam_2ece4c,
        .timer = 2,
    },
    [7] = {
        .pFrame = sOam_2ece20,
        .timer = 2,
    },
    [8] = {
        .pFrame = sOam_2ece4c,
        .timer = 10,
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed288[6] = {
    [0] = {
        .pFrame = sOam_2ece78,
        .timer = 2,
    },
    [1] = {
        .pFrame = sOam_2ecea4,
        .timer = 2,
    },
    [2] = {
        .pFrame = sOam_2ece78,
        .timer = 2,
    },
    [3] = {
        .pFrame = sOam_2ecea4,
        .timer = 2,
    },
    [4] = {
        .pFrame = sOam_2ece78,
        .timer = 255,
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed2b8[2] = {
    [0] = {
        .pFrame = sOam_2ec964,
        .timer = 255,
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynWingOam_Falling[2] = {
    [0] = {
        .pFrame = sOam_2ec988,
        .timer = 255,
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHalzynOam_2ed2d8[2] = {
    [0] = {
        .pFrame = sOam_2eca04,
        .timer = 255,
    },
    [1] = FRAME_DATA_TERMINATOR
};
