#include "data/sprites/serris.h"
#include "macros.h"

const s16 sSerris_373548[49] = {
    0, 0, 0, 0,
    1, 0, 1, 0,
    1, 2, 3, 4,
    3, 2, 1, 0,
    1, 0, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    -1, 0, -1, 0,
    -1, -2, -3, -4,
    -3, -2, -1, 0,
    -1, 0, -1, 0,
    0, 0, 0, 0,
    SHORT_MAX
};

const s16 sSerris_3735aa[65] = {
    0, 0, 0, 0,
    1, 1, 1, 1,
    2, 2, 2, 2,
    3, 3, 3, 3,
    3, 3, 3, 3,
    2, 2, 2, 2,
    1, 1, 1, 1,
    0, 0, 0, 0,
    0, 0, 0, 0,
    -1, -1, -1, -1,
    -2, -2, -2, -2,
    -3, -3, -3, -3,
    -3, -3, -3, -3,
    -2, -2, -2, -2,
    -1, -1, -1, -1,
    0, 0, 0, 0,
    SHORT_MAX
};

const s16 sSerris_37362c[81] = {
    0, 0, 1, 1,
    2, 2, 3, 3,
    4, 4, 5, 5,
    6, 6, 7, 7,
    7, 7, 8, 8,
    8, 8, 7, 7,
    7, 7, 6, 6,
    5, 5, 4, 4,
    3, 3, 2, 2,
    1, 1, 0, 0,
    0, 0, -1, -1,
    -2, -2, -3, -3,
    -4, -4, -5, -5,
    -6, -6, -7, -7,
    -7, -7, -8, -8,
    -8, -8, -7, -7,
    -7, -7, -6, -6,
    -5, -5, -4, -4,
    -3, -3, -2, -2,
    -1, -1, 0, 0,
    SHORT_MAX
};

const s16 sSerrisPartDyingVelocity[8] = {
    -16, -12, -10, -8,
    -6, -4, -2,

    SHORT_MAX
};

const s16 sSerrisPartFallingVelocity[12] = {
    1, 2, 4, 6,
    8, 10, 12, 14,
    16, 18, 20,
    
    SHORT_MAX
};

const u32 sSerrisGfx[4096] = INCBIN_U32("data/sprites/serris.gfx");
const u16 sSerrisPal[16 * 8] = INCBIN_U16("data/sprites/serris.pal");

static const u16 sSerrisOam_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 848, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_HeadDiagonalIdle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-20, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 906, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 875, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 876, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 877, 8, 0),
};

static const u16 sSerrisOam_HeadFrontIdle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 878, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 1007, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 1008, 8, 0),
};

static const u16 sSerrisOam_Left_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-9, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(-1, 14, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 8, 0),
    OAM_ENTRY(-9, 14, OAM_DIMS_8x8, OAM_NO_FLIP, 848, 8, 0),
    OAM_ENTRY(-17, 14, OAM_DIMS_8x8, OAM_NO_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 796, 8, 0),
    OAM_ENTRY(-7, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(1, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 8, 0),
    OAM_ENTRY(-7, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 848, 8, 0),
    OAM_ENTRY(-15, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(-6, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(2, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 8, 0),
    OAM_ENTRY(-6, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 848, 8, 0),
    OAM_ENTRY(-14, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_3778a6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(4, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 8, 0),
    OAM_ENTRY(-4, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 848, 8, 0),
    OAM_ENTRY(-12, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_3778c6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(-2, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 8, 0),
    OAM_ENTRY(-10, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 848, 8, 0),
    OAM_ENTRY(-18, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_3778e6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 796, 8, 0),
    OAM_ENTRY(-6, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(2, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 8, 0),
    OAM_ENTRY(-6, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 848, 8, 0),
    OAM_ENTRY(-14, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 847, 8, 0),
};

static const u16 sSerrisPartOam_Left_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 914, 9, 0),
    OAM_ENTRY(7, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 916, 9, 0),
    OAM_ENTRY(-3, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 917, 9, 0),
    OAM_ENTRY(13, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 919, 9, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 857, 9, 0),
    OAM_ENTRY(14, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 858, 9, 0),
    OAM_ENTRY(22, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 859, 9, 0),
};

static const u16 sSerrisPartOam_Left_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(-10, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 850, 9, 0),
    OAM_ENTRY(6, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 852, 9, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 853, 9, 0),
    OAM_ENTRY(13, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 855, 9, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 825, 9, 0),
    OAM_ENTRY(14, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 826, 9, 0),
    OAM_ENTRY(22, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 827, 9, 0),
};

static const u16 sSerrisPartOam_Left_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(-10, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(6, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 788, 9, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 789, 9, 0),
    OAM_ENTRY(13, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 791, 9, 0),
    OAM_ENTRY(5, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 793, 9, 0),
    OAM_ENTRY(13, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 794, 9, 0),
    OAM_ENTRY(21, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 795, 9, 0),
};

static const u16 sSerrisPartOam_HeadJointDiagonalIdle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 979, 9, 0),
    OAM_ENTRY(3, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 981, 9, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 981, 9, 0),
};

static const u16 sSerrisPartOam_HeadJointFrontIdle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 524, 9, 0),
    OAM_ENTRY(-4, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 978, 9, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 1010, 9, 0),
};

static const u16 sSerrisOam_3779ca[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 644, 11, 0),
    OAM_ENTRY(-10, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 11, 0),
    OAM_ENTRY(6, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 788, 11, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 789, 11, 0),
    OAM_ENTRY(13, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 791, 11, 0),
    OAM_ENTRY(5, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 793, 11, 0),
    OAM_ENTRY(13, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 794, 11, 0),
    OAM_ENTRY(21, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 795, 11, 0),
};

static const u16 sSerrisOam_3779fc[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 925, 11, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 987, 11, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 890, 11, 0),
    OAM_ENTRY(13, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 891, 11, 0),
};

static const u16 sSerrisOam_377a1c[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -11, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
    OAM_ENTRY(-13, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 925, 11, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 987, 11, 0),
    OAM_ENTRY(5, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 890, 11, 0),
    OAM_ENTRY(13, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 891, 11, 0),
};

static const u16 sSerrisOam_377a3c[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -12, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
    OAM_ENTRY(-13, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 925, 11, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 987, 11, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 890, 11, 0),
    OAM_ENTRY(13, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 891, 11, 0),
};

static const u16 sSerrisOam_377a5c[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 925, 11, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 987, 11, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 890, 11, 0),
    OAM_ENTRY(13, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 891, 11, 0),
};

static const u16 sSerrisOam_377a7c[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -15, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
    OAM_ENTRY(-13, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 925, 11, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 987, 11, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 890, 11, 0),
    OAM_ENTRY(13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 891, 11, 0),
};

static const u16 sSerrisOam_377a9c[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
    OAM_ENTRY(-13, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 925, 11, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 987, 11, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 890, 11, 0),
    OAM_ENTRY(13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 891, 11, 0),
};

static const u16 sSerrisOam_377abc[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 923, 11, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 985, 11, 0),
    OAM_ENTRY(5, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 762, 11, 0),
    OAM_ENTRY(13, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 763, 11, 0),
};

static const u16 sSerrisOam_377adc[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 921, 11, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 983, 11, 0),
    OAM_ENTRY(5, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 730, 11, 0),
    OAM_ENTRY(13, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 731, 11, 0),
};

static const u16 sSerrisOam_377afc[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 652, 11, 0),
    OAM_ENTRY(-6, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 1022, 11, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 990, 11, 0),
    OAM_ENTRY(3, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 1023, 11, 0),
    OAM_ENTRY(3, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 991, 11, 0),
    OAM_ENTRY(4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 1023, 11, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 991, 11, 0),
};

static const u16 sSerrisOam_377b28[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 656, 11, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 1021, 11, 0),
    OAM_ENTRY(-4, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 989, 11, 0),
};

static const u16 sSerrisPartOam_Middle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 9, 0),
};

static const u16 sSerrisPartOam_SectionDiagonalIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 520, 9, 0),
};

static const u16 sSerrisPartOam_SectionFrontIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 524, 9, 0),
};

static const u16 sSerrisOam_377b54[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 640, 11, 0),
};

static const u16 sSerrisOam_377b5c[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
};

static const u16 sSerrisOam_377b64[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -11, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
};

static const u16 sSerrisOam_377b6c[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -12, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
};

static const u16 sSerrisOam_377b74[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
};

static const u16 sSerrisOam_377b7c[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -15, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
};

static const u16 sSerrisOam_377b84[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 11, 0),
};

static const u16 sSerrisOam_377b8c[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 652, 11, 0),
};

static const u16 sSerrisOam_377b94[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 656, 11, 0),
};

static const u16 sSerrisOam_377b9c[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 774, 11, 0),
    OAM_ENTRY(-16, 18, OAM_DIMS_32x8, OAM_NO_FLIP, 838, 11, 0),
    OAM_ENTRY(-9, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 11, 0),
    OAM_ENTRY(-9, 22, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 11, 0),
};

static const u16 sSerrisOam_377bb6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, 5, OAM_DIMS_32x32, OAM_NO_FLIP, 768, 11, 0),
    OAM_ENTRY(-8, 37, OAM_DIMS_16x16, OAM_NO_FLIP, 772, 11, 0),
    OAM_ENTRY(-9, 21, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 11, 0),
    OAM_ENTRY(-9, 37, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 11, 0),
};

static const u16 sSerrisOam_377bd0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 774, 11, 0),
    OAM_ENTRY(-16, 20, OAM_DIMS_32x8, OAM_NO_FLIP, 838, 11, 0),
};

static const u16 sSerrisOam_377bde[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 836, 11, 0),
    OAM_ENTRY(-8, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 870, 11, 0),
};

static const u16 sSerrisOam_377bec[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 11, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 11, 0),
};

static const u16 sSerrisOam_377bfa[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 870, 11, 0),
};

static const u16 sSerrisOam_377c02[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 896, 11, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 898, 11, 0),
};

static const u16 sSerrisOam_377c10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 960, 11, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 962, 11, 0),
};

static const u16 sSerrisOam_377c1e[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 899, 11, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 901, 11, 0),
};

static const u16 sSerrisOam_377c2c[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 899, 11, 0),
    OAM_ENTRY(-14, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 931, 11, 0),
    OAM_ENTRY(6, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 901, 11, 0),
    OAM_ENTRY(6, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 933, 11, 0),
};

static const u16 sSerrisPartOam_MiddleEnd_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 528, 9, 0),
};

static const u16 sSerrisPartOam_MiddleEndDiagonalIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 532, 9, 0),
};

static const u16 sSerrisPartOam_MiddleEndFrontIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 536, 9, 0),
};

static const u16 sSerrisPartOam_TailJoint_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 660, 9, 0),
};

static const u16 sSerrisPartOam_TailJointDiagonalIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 662, 9, 0),
};

static const u16 sSerrisPartOam_TailJointFrontIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 664, 9, 0),
};

static const u16 sSerrisPartOam_Tail_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 963, 9, 0),
};

static const u16 sSerrisPartOam_TailIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 966, 9, 0),
};

static const u16 sSerrisPartOam_TailFrontIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 968, 9, 0),
};

static const u16 sMiniSerrisOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 842, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 9, 0),
};

static const u16 sMiniSerrisOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 842, 8, 0),
    OAM_ENTRY(-7, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(4, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 726, 9, 0),
};

static const u16 sMiniSerrisOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 842, 8, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(14, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 724, 9, 0),
};

static const u16 sMiniSerrisOam_TurningLeft_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-6, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 844, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 724, 9, 0),
};

static const u16 sMiniSerrisOam_TurningLeft_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 844, 8, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(2, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 724, 9, 0),
};

static const u16 sMiniSerrisOam_TurningLeft_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 782, 8, 0),
    OAM_ENTRY(-10, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 845, 8, 0),
    OAM_ENTRY(-10, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(-7, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 724, 9, 0),
};

static const u16 sMiniSerrisOam_TurningLeft_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 782, 8, 0),
    OAM_ENTRY(-12, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 845, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 664, 9, 0),
};

static const u16 sMiniSerrisOam_TurningLeft_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -9, OAM_DIMS_16x16, OAM_X_FLIP, 780, 8, 0),
    OAM_ENTRY(-10, 7, OAM_DIMS_8x8, OAM_X_FLIP, 844, 8, 0),
    OAM_ENTRY(-18, -12, OAM_DIMS_16x16, OAM_X_FLIP, 666, 9, 0),
};

static const u16 sMiniSerrisOam_TurningLeft_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -9, OAM_DIMS_16x16, OAM_X_FLIP, 780, 8, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_X_FLIP, 844, 8, 0),
    OAM_ENTRY(-19, -12, OAM_DIMS_16x16, OAM_X_FLIP, 666, 9, 0),
    OAM_ENTRY(-23, -14, OAM_DIMS_16x16, OAM_X_FLIP, 728, 9, 0),
};

static const u16 sMiniSerrisOam_TurningLeft_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, 1, OAM_DIMS_16x8, OAM_X_FLIP, 842, 8, 0),
    OAM_ENTRY(-10, -9, OAM_DIMS_16x16, OAM_X_FLIP, 778, 8, 0),
    OAM_ENTRY(-22, -12, OAM_DIMS_16x16, OAM_X_FLIP, 666, 9, 0),
    OAM_ENTRY(-27, -12, OAM_DIMS_16x16, OAM_X_FLIP, 726, 9, 0),
};

static const u16 sMiniSerrisOam_TurningRight_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -9, OAM_DIMS_16x16, OAM_X_FLIP, 780, 8, 0),
    OAM_ENTRY(-2, 7, OAM_DIMS_8x8, OAM_X_FLIP, 844, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_X_FLIP, 666, 9, 0),
    OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_X_FLIP, 724, 9, 0),
};

static const u16 sMiniSerrisOam_TurningRight_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -9, OAM_DIMS_16x16, OAM_X_FLIP, 780, 8, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_8x8, OAM_X_FLIP, 844, 8, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_X_FLIP, 666, 9, 0),
    OAM_ENTRY(-18, -12, OAM_DIMS_16x16, OAM_X_FLIP, 724, 9, 0),
};

static const u16 sMiniSerrisOam_TurningRight_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -9, OAM_DIMS_16x16, OAM_X_FLIP, 782, 8, 0),
    OAM_ENTRY(2, 7, OAM_DIMS_8x8, OAM_X_FLIP, 845, 8, 0),
    OAM_ENTRY(-6, -12, OAM_DIMS_16x16, OAM_X_FLIP, 666, 9, 0),
    OAM_ENTRY(-9, -12, OAM_DIMS_16x16, OAM_X_FLIP, 724, 9, 0),
};

static const u16 sMiniSerrisOam_TurningRight_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_X_FLIP, 782, 8, 0),
    OAM_ENTRY(4, 7, OAM_DIMS_8x8, OAM_X_FLIP, 845, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_X_FLIP, 664, 9, 0),
};

static const u16 sMiniSerrisOam_TurningRight_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-2, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(2, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 844, 8, 0),
    OAM_ENTRY(2, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
};

static const u16 sMiniSerrisOam_TurningRight_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 844, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(7, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 9, 0),
};

static const u16 sMiniSerrisOam_TurningRight_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 842, 8, 0),
    OAM_ENTRY(-6, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(6, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(11, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 726, 9, 0),
};

static const u16 sMiniSerrisOam_Fast_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 842, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 9, 0),
};

static const u16 sMiniSerrisOam_Fast_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 842, 8, 0),
    OAM_ENTRY(-7, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(4, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 726, 9, 0),
};

static const u16 sMiniSerrisOam_Fast_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 842, 8, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(14, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 724, 9, 0),
};

static const u16 sSerrisOam_Jumbled_Frame0[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-120, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(-104, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(-96, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 8, 0),
    OAM_ENTRY(-104, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 848, 8, 0),
    OAM_ENTRY(-112, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 847, 8, 0),
    OAM_ENTRY(-96, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(-90, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-74, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 788, 9, 0),
    OAM_ENTRY(-83, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 789, 9, 0),
    OAM_ENTRY(-75, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 793, 9, 0),
    OAM_ENTRY(-59, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 795, 9, 0),
    OAM_ENTRY(-80, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 28, 9, 0),
    OAM_ENTRY(-65, -12, OAM_DIMS_32x32, OAM_NO_FLIP, 156, 9, 0),
    OAM_ENTRY(-53, 3, OAM_DIMS_32x32, OAM_NO_FLIP, 284, 9, 0),
    OAM_ENTRY(-41, 13, OAM_DIMS_32x32, OAM_NO_FLIP, 156, 9, 0),
    OAM_ENTRY(-31, 17, OAM_DIMS_32x32, OAM_NO_FLIP, 28, 9, 0),
    OAM_ENTRY(-16, 15, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-3, 10, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(6, 3, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(18, -3, OAM_DIMS_32x32, OAM_NO_FLIP, 28, 9, 0),
    OAM_ENTRY(29, -7, OAM_DIMS_32x32, OAM_NO_FLIP, 28, 9, 0),
    OAM_ENTRY(42, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 28, 9, 0),
    OAM_ENTRY(60, -11, OAM_DIMS_32x32, OAM_NO_FLIP, 528, 9, 0),
    OAM_ENTRY(79, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 660, 9, 0),
    OAM_ENTRY(88, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 963, 9, 0),
};

static const u16 sSerrisOam_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 784, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_8x8, OAM_X_FLIP, 849, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_8x8, OAM_X_FLIP, 848, 8, 0),
    OAM_ENTRY(8, 16, OAM_DIMS_8x8, OAM_X_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_Right_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_32x32, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_X_FLIP, 784, 8, 0),
    OAM_ENTRY(-7, 14, OAM_DIMS_8x8, OAM_X_FLIP, 849, 8, 0),
    OAM_ENTRY(1, 14, OAM_DIMS_8x8, OAM_X_FLIP, 848, 8, 0),
    OAM_ENTRY(9, 14, OAM_DIMS_8x8, OAM_X_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_Right_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_32x32, OAM_X_FLIP, 796, 8, 0),
    OAM_ENTRY(-9, 2, OAM_DIMS_16x16, OAM_X_FLIP, 784, 8, 0),
    OAM_ENTRY(-9, 18, OAM_DIMS_8x8, OAM_X_FLIP, 849, 8, 0),
    OAM_ENTRY(-1, 18, OAM_DIMS_8x8, OAM_X_FLIP, 848, 8, 0),
    OAM_ENTRY(7, 18, OAM_DIMS_8x8, OAM_X_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_Right_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-10, 4, OAM_DIMS_16x16, OAM_X_FLIP, 784, 8, 0),
    OAM_ENTRY(-10, 20, OAM_DIMS_8x8, OAM_X_FLIP, 849, 8, 0),
    OAM_ENTRY(-2, 20, OAM_DIMS_8x8, OAM_X_FLIP, 848, 8, 0),
    OAM_ENTRY(6, 20, OAM_DIMS_8x8, OAM_X_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_SpeedboostingLeft_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(-2, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 8, 0),
    OAM_ENTRY(-10, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 848, 8, 0),
    OAM_ENTRY(-18, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 847, 8, 0),
};

static const u16 sSerrisOam_SpeedboostingRight_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-6, -4, OAM_DIMS_16x16, OAM_X_FLIP, 784, 8, 0),
    OAM_ENTRY(-6, 12, OAM_DIMS_8x8, OAM_X_FLIP, 849, 8, 0),
    OAM_ENTRY(2, 12, OAM_DIMS_8x8, OAM_X_FLIP, 848, 8, 0),
    OAM_ENTRY(10, 12, OAM_DIMS_8x8, OAM_X_FLIP, 847, 8, 0),
};

static const u16 sSerrisPartOam_Right_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_X_FLIP, 516, 9, 0),
    OAM_ENTRY(-7, -21, OAM_DIMS_16x16, OAM_X_FLIP, 914, 9, 0),
    OAM_ENTRY(-15, -21, OAM_DIMS_8x8, OAM_X_FLIP, 916, 9, 0),
    OAM_ENTRY(-13, -18, OAM_DIMS_16x16, OAM_X_FLIP, 917, 9, 0),
    OAM_ENTRY(-29, -18, OAM_DIMS_16x16, OAM_X_FLIP, 919, 9, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_8x8, OAM_X_FLIP, 857, 9, 0),
    OAM_ENTRY(-22, -9, OAM_DIMS_8x8, OAM_X_FLIP, 858, 9, 0),
    OAM_ENTRY(-30, -9, OAM_DIMS_8x8, OAM_X_FLIP, 859, 9, 0),
};

static const u16 sSerrisPartOam_Right_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_X_FLIP, 516, 9, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_16x16, OAM_X_FLIP, 850, 9, 0),
    OAM_ENTRY(-14, -22, OAM_DIMS_8x8, OAM_X_FLIP, 852, 9, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_16x16, OAM_X_FLIP, 853, 9, 0),
    OAM_ENTRY(-29, -19, OAM_DIMS_16x16, OAM_X_FLIP, 855, 9, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_8x8, OAM_X_FLIP, 825, 9, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_8x8, OAM_X_FLIP, 826, 9, 0),
    OAM_ENTRY(-30, -10, OAM_DIMS_8x8, OAM_X_FLIP, 827, 9, 0),
};

static const u16 sSerrisPartOam_Right_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_X_FLIP, 516, 9, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(-14, -22, OAM_DIMS_8x8, OAM_X_FLIP, 788, 9, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_16x16, OAM_X_FLIP, 789, 9, 0),
    OAM_ENTRY(-29, -19, OAM_DIMS_16x16, OAM_X_FLIP, 791, 9, 0),
    OAM_ENTRY(-13, -10, OAM_DIMS_8x8, OAM_X_FLIP, 793, 9, 0),
    OAM_ENTRY(-21, -10, OAM_DIMS_8x8, OAM_X_FLIP, 794, 9, 0),
    OAM_ENTRY(-29, -10, OAM_DIMS_8x8, OAM_X_FLIP, 795, 9, 0),
};

static const u16 sSerrisBlockOam_Idle1_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 640, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling1_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 642, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling1_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 644, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling1_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 646, 10, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 652, 10, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 648, 10, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 651, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling1_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 646, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 652, 10, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 648, 10, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 651, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling1_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 646, 10, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 652, 10, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 648, 10, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_8x16, OAM_NO_FLIP, 651, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling1_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 646, 10, 0),
    OAM_ENTRY(-8, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 652, 10, 0),
    OAM_ENTRY(-8, 17, OAM_DIMS_16x16, OAM_NO_FLIP, 648, 10, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 651, 10, 0),
    OAM_ENTRY(-3, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 650, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling1_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 646, 10, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 652, 10, 0),
    OAM_ENTRY(-8, 35, OAM_DIMS_16x16, OAM_NO_FLIP, 648, 10, 0),
    OAM_ENTRY(0, 20, OAM_DIMS_8x16, OAM_NO_FLIP, 651, 10, 0),
    OAM_ENTRY(-3, 35, OAM_DIMS_8x8, OAM_NO_FLIP, 650, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling1_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, 28, OAM_DIMS_16x16, OAM_NO_FLIP, 646, 10, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 652, 10, 0),
    OAM_ENTRY(-8, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 648, 10, 0),
    OAM_ENTRY(0, 36, OAM_DIMS_8x16, OAM_NO_FLIP, 651, 10, 0),
    OAM_ENTRY(-3, 55, OAM_DIMS_8x8, OAM_NO_FLIP, 650, 10, 0),
};

static const u16 sSerrisBlockOam_Idle0_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 704, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling0_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 706, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling0_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 708, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling0_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 710, 10, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 716, 10, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 712, 10, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 714, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling0_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 710, 10, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 716, 10, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 712, 10, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 714, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling0_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 710, 10, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 716, 10, 0),
    OAM_ENTRY(-8, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 712, 10, 0),
    OAM_ENTRY(-8, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 714, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling0_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 710, 10, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 716, 10, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 712, 10, 0),
    OAM_ENTRY(-8, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 714, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling0_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 710, 10, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 716, 10, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 712, 10, 0),
    OAM_ENTRY(-8, 23, OAM_DIMS_16x16, OAM_NO_FLIP, 714, 10, 0),
};

static const u16 sSerrisBlockOam_Crumbling0_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 710, 10, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 716, 10, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 712, 10, 0),
    OAM_ENTRY(-8, 35, OAM_DIMS_16x16, OAM_NO_FLIP, 714, 10, 0),
};


const struct FrameData sSerrisOam_HeadIdle[2] = {
    [0] = {
        .pFrame = sSerrisOam_Left_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisOam_HeadDiagonalIdle[2] = {
    [0] = {
        .pFrame = sSerrisOam_HeadDiagonalIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisOam_HeadFrontIdle[2] = {
    [0] = {
        .pFrame = sSerrisOam_HeadFrontIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};


const struct FrameData sSerrisOam_Left[6] = {
    [0] = {
        .pFrame = sSerrisOam_Left_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSerrisOam_Left_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSerrisOam_Left_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSerrisOam_Left_Frame1,
        .timer = 8
    },
    [4] = {
        .pFrame = sSerrisOam_Left_Frame4,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisOam_Right[6] = {
    [0] = {
        .pFrame = sSerrisOam_Right_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSerrisOam_Right_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSerrisOam_Right_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSerrisOam_Right_Frame1,
        .timer = 8
    },
    [4] = {
        .pFrame = sSerrisOam_Right_Frame4,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisOam_SpeedboostingLeft[2] = {
    [0] = {
        .pFrame = sSerrisOam_SpeedboostingLeft_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisOam_SpeedboostingRight[2] = {
    [0] = {
        .pFrame = sSerrisOam_SpeedboostingRight_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};


const struct FrameData sSerrisPartOam_HeadJointIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_Left_Frame0,
        .timer = 8
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_HeadJointDiagonalIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_HeadJointDiagonalIdle_Frame0,
        .timer = 8
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_HeadJointFrontIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_HeadJointFrontIdle_Frame0,
        .timer = 8
    },
    [1] = FRAME_DATA_TERMINATOR
};


const struct FrameData sSerrisPartOam_Left[5] = {
    [0] = {
        .pFrame = sSerrisPartOam_Left_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sSerrisPartOam_Left_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sSerrisPartOam_Left_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sSerrisPartOam_Left_Frame1,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_HadJointFlapping[5] = {
    [0] = {
        .pFrame = sSerrisPartOam_Left_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSerrisPartOam_Left_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sSerrisPartOam_Left_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sSerrisPartOam_Left_Frame1,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_378318[7] = {
    [0] = {
        .pFrame = sSerrisOam_3779ca,
        .timer = 8
    },
    [1] = {
        .pFrame = sSerrisOam_3779fc,
        .timer = 8
    },
    [2] = {
        .pFrame = sSerrisOam_377a1c,
        .timer = 4
    },
    [3] = {
        .pFrame = sSerrisOam_377a3c,
        .timer = 6
    },
    [4] = {
        .pFrame = sSerrisOam_377a5c,
        .timer = 6
    },
    [5] = {
        .pFrame = sSerrisOam_377a7c,
        .timer = 6
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_378350[5] = {
    [0] = {
        .pFrame = sSerrisOam_377adc,
        .timer = 12
    },
    [1] = {
        .pFrame = sSerrisOam_377abc,
        .timer = 12
    },
    [2] = {
        .pFrame = sSerrisOam_377a9c,
        .timer = 12
    },
    [3] = {
        .pFrame = sSerrisOam_377abc,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_378378[5] = {
    [0] = {
        .pFrame = sSerrisOam_377adc,
        .timer = 2
    },
    [1] = {
        .pFrame = sSerrisOam_377abc,
        .timer = 2
    },
    [2] = {
        .pFrame = sSerrisOam_377a9c,
        .timer = 2
    },
    [3] = {
        .pFrame = sSerrisOam_377abc,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_3783a0[2] = {
    [0] = {
        .pFrame = sSerrisOam_377adc,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_3783b0[2] = {
    [0] = {
        .pFrame = sSerrisOam_377afc,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_3783c0[2] = {
    [0] = {
        .pFrame = sSerrisOam_377b28,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_Middle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_Middle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_SectionDiagonalIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_SectionDiagonalIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_SectionFrontIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_SectionFrontIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_378400[7] = {
    [0] = {
        .pFrame = sSerrisOam_377b54,
        .timer = 8
    },
    [1] = {
        .pFrame = sSerrisOam_377b5c,
        .timer = 8
    },
    [2] = {
        .pFrame = sSerrisOam_377b64,
        .timer = 4
    },
    [3] = {
        .pFrame = sSerrisOam_377b6c,
        .timer = 6
    },
    [4] = {
        .pFrame = sSerrisOam_377b74,
        .timer = 6
    },
    [5] = {
        .pFrame = sSerrisOam_377b7c,
        .timer = 6
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_378438[2] = {
    [0] = {
        .pFrame = sSerrisOam_377b84,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_378448[2] = {
    [0] = {
        .pFrame = sSerrisOam_377b8c,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_378458[2] = {
    [0] = {
        .pFrame = sSerrisOam_377b94,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_378468[5] = {
    [0] = {
        .pFrame = sSerrisOam_377b9c,
        .timer = 8
    },
    [1] = {
        .pFrame = sSerrisOam_377bb6,
        .timer = 4
    },
    [2] = {
        .pFrame = sSerrisOam_377bd0,
        .timer = 6
    },
    [3] = {
        .pFrame = sSerrisOam_377bde,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_378490[2] = {
    [0] = {
        .pFrame = sSerrisOam_377bec,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_3784a0[2] = {
    [0] = {
        .pFrame = sSerrisOam_377bfa,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_3784b0[5] = {
    [0] = {
        .pFrame = sSerrisOam_377c02,
        .timer = 4
    },
    [1] = {
        .pFrame = sSerrisOam_377c10,
        .timer = 4
    },
    [2] = {
        .pFrame = sSerrisOam_377c1e,
        .timer = 4
    },
    [3] = {
        .pFrame = sSerrisOam_377c2c,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};


const struct FrameData sSerrisPartOam_MiddleEnd[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_MiddleEnd_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_MiddleEndDiagonalIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_MiddleEndDiagonalIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_MiddleEndFrontIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_MiddleEndFrontIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};


const struct FrameData sSerrisPartOam_TailJoint[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_TailJoint_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_TailJointDiagonalIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_TailJointDiagonalIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_TailJointFrontIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_TailJointFrontIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_Tail[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_Tail_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_TailIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_TailIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisPartOam_TailFrontIdle[2] = {
    [0] = {
        .pFrame = sSerrisPartOam_TailFrontIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};


const struct FrameData sMiniSerrisOam_Idle[5] = {
    [0] = {
        .pFrame = sMiniSerrisOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sMiniSerrisOam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sMiniSerrisOam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sMiniSerrisOam_Idle_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMiniSerrisOam_Fast[5] = {
    [0] = {
        .pFrame = sMiniSerrisOam_Fast_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sMiniSerrisOam_Fast_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sMiniSerrisOam_Fast_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sMiniSerrisOam_Fast_Frame1,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMiniSerrisOam_TurningLeft[8] = {
    [0] = {
        .pFrame = sMiniSerrisOam_TurningLeft_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sMiniSerrisOam_TurningLeft_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sMiniSerrisOam_TurningLeft_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sMiniSerrisOam_TurningLeft_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sMiniSerrisOam_TurningLeft_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sMiniSerrisOam_TurningLeft_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sMiniSerrisOam_TurningLeft_Frame6,
        .timer = 4
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMiniSerrisOam_TurningRight[8] = {
    [0] = {
        .pFrame = sMiniSerrisOam_TurningRight_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sMiniSerrisOam_TurningRight_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sMiniSerrisOam_TurningRight_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sMiniSerrisOam_TurningRight_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sMiniSerrisOam_TurningRight_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sMiniSerrisOam_TurningRight_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sMiniSerrisOam_TurningRight_Frame6,
        .timer = 4
    },
    [7] = FRAME_DATA_TERMINATOR
};


const struct FrameData sSerrisOam_Jumbled[2] = {
    [0] = {
        .pFrame = sSerrisOam_Jumbled_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisOam_378648[2] = {
    [0] = {
        .pFrame = sSerrisOam_Right_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};


const struct FrameData sSerrisPartOam_Right[5] = {
    [0] = {
        .pFrame = sSerrisPartOam_Right_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sSerrisPartOam_Right_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sSerrisPartOam_Right_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sSerrisPartOam_Right_Frame1,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};


const struct FrameData sSerrisBlockOam_Idle1[2] = {
    [0] = {
        .pFrame = sSerrisBlockOam_Idle1_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisBlockOam_Crumbling1[9] = {
    [0] = {
        .pFrame = sSerrisBlockOam_Crumbling1_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSerrisBlockOam_Crumbling1_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSerrisBlockOam_Crumbling1_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSerrisBlockOam_Crumbling1_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sSerrisBlockOam_Crumbling1_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sSerrisBlockOam_Crumbling1_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sSerrisBlockOam_Crumbling1_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sSerrisBlockOam_Crumbling1_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisBlockOam_Falling1[2] = {
    [0] = {
        .pFrame = sSerrisBlockOam_Crumbling1_Frame7,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};


const struct FrameData sSerrisBlockOam_Idle0[2] = {
    [0] = {
        .pFrame = sSerrisBlockOam_Idle0_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisBlockOam_Crumbling0[9] = {
    [0] = {
        .pFrame = sSerrisBlockOam_Crumbling0_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSerrisBlockOam_Crumbling0_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSerrisBlockOam_Crumbling0_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSerrisBlockOam_Crumbling0_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sSerrisBlockOam_Crumbling0_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sSerrisBlockOam_Crumbling0_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sSerrisBlockOam_Crumbling0_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sSerrisBlockOam_Crumbling0_Frame7,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSerrisBlockOam_Falling0[2] = {
    [0] = {
        .pFrame = sSerrisBlockOam_Crumbling0_Frame7,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};


const u16 sSerrisSecondPhasePal[16 * 2] = INCBIN_U16("data/sprites/serris_phase_two.pal");
const u16 sSerrisThirdPhasePal[16 * 2] = INCBIN_U16("data/sprites/serris_phase_three.pal");

static const u8 sBlob_3787d0_3bdebc[] = INCBIN_U8("data/Blob_3787d0_3bdebc.bin");
