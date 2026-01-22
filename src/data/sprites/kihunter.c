#include "data/sprites/kihunter.h"

const s16 sKihunterBugIdleYMovement[65] = {
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

const s16 sKihunterBugIdleXMovement[81] = {
    0, 0, 1, 1,
    2, 2, 3, 3,
    4, 4, 4, 5,
    5, 5, 6, 6,
    6, 7, 7, 7,
    7, 7, 7, 6,
    6, 6, 5, 5,
    5, 4, 4, 4,
    3, 3, 2, 2,
    1, 1, 0, 0,
    0, 0, -1, -1,
    -2, -2, -3, -3,
    -4, -4, -4, -5,
    -5, -5, -6, -6,
    -6, -7, -7, -7,
    -7, -7, -7, -6,
    -6, -6, -5, -5,
    -5, -4, -4, -4,
    -3, -3, -2, -2,
    -1, -1, 0, 0,
    SHORT_MAX
};

const s16 sKihunterSpitFallingSpeed[21] = {
    -4, -4, -3, -3,
    -2, -2, -1, -1,
    0, 0, 0, 0,
    1, 1, 2, 2,
    4, 4, 6, 8,
    SHORT_MAX
};

const s16 sKihunterGroundHighJumpSpeed[10] = {
    -16, -12, -8, -4, 0,
    4, 8, 12, 16, 16
};

const s16 sKihunterGroundLowJumpSpeed[10] = {
    -12, -8, -4, -2, 0,
    4, 8, 16, 16, 16
};

const s16 sKihunterFlyingIdleYMovement[49] = {
    0, 0, 0, 0,
    1, 0, 1, 0,
    1, 1, 2, 2,
    2, 1, 1, 0,
    1, 0, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    -1, 0, -1, 0,
    -1, -1, -2, -2,
    -2, -1, -1, 0,
    -1, 0, -1, 0,
    0, 0, 0, 0,
    SHORT_MAX
};

const s16 sKihunterFlyingSwoopingDownYSpeed[16] = {
    1, 2, 3, 4,
    5, 6, 7, 8,
    10, 12, 14, 12,
    10, 8, 6, SHORT_MAX
};

const s16 sKihunterFlyingSwoopingAcrossYSpeed[8] = {
    5, 5, 4, 4,
    3, 3, 2, SHORT_MAX
};

const s16 sKihunterFlyingAfterSwoopingAcceleratingYSpeed[12] = {
    -1, -1, -2, -2,
    -3, -3, -4, -5,
    -6, -7, -8, SHORT_MAX
};

const s16 sKihunterFlyingAfterSwoopingDeceleratingYSpeed[12] = {
    -7, -7, -6, -6,
    -5, -5, -4, -4,
    -4, -3, -2, SHORT_MAX
};

const u32 sKihunterGfx[3 * 512] = INCBIN_U32("data/sprites/kihunter.gfx");
const u16 sKihunterPal[3 * 16] = INCBIN_U16("data/sprites/kihunter.pal");

static const u16 sKihunterFlyingOam_Idle_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-17, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sKihunterFlyingOam_Idle_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-17, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sKihunterFlyingOam_Idle_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-17, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sKihunterFlyingOam_LungingWithStinger_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-17, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-11, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sKihunterFlyingOam_LungingWithStinger_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-6, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-15, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-22, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
};

static const u16 sKihunterWingsOam_Flapping_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
};

static const u16 sKihunterWingsOam_Flapping_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
};

static const u16 sKihunterWingsOam_Flapping_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(15, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 8, 0),
};

static const u16 sKihunterWingsOam_Falling_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 8, 0),
    OAM_ENTRY(6, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24a, 8, 0),
};

static const u16 sKihunterWingsOam_Falling_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
};

static const u16 sKihunterWingsOam_Landed_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
};

static const u16 sKihunterWingsOam_Falling_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-13, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(3, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
};

static const u16 sKihunterWingsOam_Falling_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(-6, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x266, 8, 0),
};

static const u16 sKihunterFlyingOam_Swiping_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-15, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sKihunterFlyingOam_Swiping_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-14, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-13, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-6, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
};

static const u16 sKihunterFlyingOam_Swiping_Frame3[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-25, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-13, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-3, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-10, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sKihunterFlyingOam_Swiping_Frame4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-9, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-23, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26b, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-17, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-10, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sKihunterFlyingOam_Swiping_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-9, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-17, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-17, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-11, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sKihunterFlyingOam_Swiping_Frame6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-9, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-17, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-17, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-11, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
};

static const u16 sKihunterFlyingOam_Swiping_Frame7[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-9, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-17, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-17, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-11, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
};

static const u16 sKihunterGroundOam_StartLowJump_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-20, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-5, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-19, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(2, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-10, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-19, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
};

static const u16 sKihunterGroundOam_StartLowJump_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-18, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
};

static const u16 sKihunterGroundOam_StartLowJump_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-17, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
};

static const u16 sKihunterGroundOam_StartLowJump_Frame3[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-19, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-6, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-18, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-11, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sKihunterGroundOam_JumpingLow_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-7, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-17, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-13, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23a, 8, 0),
};

static const u16 sKihunterGroundOam_JumpingHighOrFalling_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-1, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
};

static const u16 sKihunterGroundOam_Idle_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-17, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-10, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-19, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
};

static const u16 sKihunterGroundOam_Idle_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-5, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-18, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-10, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-19, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
};

static const u16 sKihunterGroundOam_Idle_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-18, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-19, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
};

static const u16 sKihunterFlyingOam_TurningAround1_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-13, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-18, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-10, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
};

static const u16 sKihunterFlyingOam_TurningAround1_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-4, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-1, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-3, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-11, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-3, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-17, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-11, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
};

static const u16 sKihunterHiveOam_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x284, 9, 0),
};

static const u16 sKihunterBugOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2aa, 8, 0),
};

static const u16 sKihunterBugOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ab, 8, 0),
};

static const u16 sKihunterBugOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2ab, 8, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame7[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-18, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-15, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-17, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a8, 8, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame8[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-18, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-15, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-25, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x288, 8, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame9[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-18, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-15, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-24, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28a, 8, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame10[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-18, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-15, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-29, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28c, 8, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame11[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-18, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-15, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-32, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a9, 8, 0),
};

static const u16 sKihunterSpitOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28e, 8, 0),
};

static const u16 sKihunterSpitOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28c, 8, 0),
};

static const u16 sKihunterSpitOam_Exploding_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x290, 9, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x292, 9, 0),
    OAM_ENTRY(-9, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x293, 9, 0),
};

static const u16 sKihunterSpitOam_Exploding_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x295, 9, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x297, 9, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b3, 9, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x2b8, 9, 0),
};

static const u16 sKihunterSpitOam_Exploding_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x298, 9, 0),
    OAM_ENTRY(-12, 5, OAM_DIMS_16x8, OAM_X_FLIP, 0x298, 9, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x298, 9, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b8, 9, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame4[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-18, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-19, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame5[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-18, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-16, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-9, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame6[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-17, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-13, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-3, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-20, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame12[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-18, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-15, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

static const u16 sKihunterGroundOam_Spitting_Frame13[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-18, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-18, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
};

const struct FrameData sKihunterFlyingOam_Idle[4] = {
    [0] = {
        .pFrame = sKihunterFlyingOam_Idle_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sKihunterFlyingOam_Idle_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sKihunterFlyingOam_Idle_Frame2,
        .timer = 1
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterWingsOam_Flapping[4] = {
    [0] = {
        .pFrame = sKihunterWingsOam_Flapping_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sKihunterWingsOam_Flapping_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sKihunterWingsOam_Flapping_Frame2,
        .timer = 1
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterWingsOam_Landed[2] = {
    [0] = {
        .pFrame = sKihunterWingsOam_Landed_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterFlyingOam_LungingWithStinger[4] = {
    [0] = {
        .pFrame = sKihunterFlyingOam_Idle_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sKihunterFlyingOam_LungingWithStinger_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sKihunterFlyingOam_LungingWithStinger_Frame2,
        .timer = 255
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterWingsOam_Falling[9] = {
    [0] = {
        .pFrame = sKihunterWingsOam_Falling_Frame0,
        .timer = 9
    },
    [1] = {
        .pFrame = sKihunterWingsOam_Falling_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sKihunterWingsOam_Landed_Frame0,
        .timer = 3
    },
    [3] = {
        .pFrame = sKihunterWingsOam_Falling_Frame3,
        .timer = 9
    },
    [4] = {
        .pFrame = sKihunterWingsOam_Falling_Frame4,
        .timer = 9
    },
    [5] = {
        .pFrame = sKihunterWingsOam_Falling_Frame3,
        .timer = 4
    },
    [6] = {
        .pFrame = sKihunterWingsOam_Landed_Frame0,
        .timer = 3
    },
    [7] = {
        .pFrame = sKihunterWingsOam_Falling_Frame1,
        .timer = 9
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterFlyingOam_Swiping[9] = {
    [0] = {
        .pFrame = sKihunterFlyingOam_Idle_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sKihunterFlyingOam_Swiping_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sKihunterFlyingOam_Swiping_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sKihunterFlyingOam_Swiping_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sKihunterFlyingOam_Swiping_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sKihunterFlyingOam_Swiping_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sKihunterFlyingOam_Swiping_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sKihunterFlyingOam_Swiping_Frame7,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterGroundOam_StartLowJump[5] = {
    [0] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame3,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterGroundOam_StartHighJump[5] = {
    [0] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterGroundOam_Landing[2] = {
    [0] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame1,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterGroundOam_Idle[7] = {
    [0] = {
        .pFrame = sKihunterGroundOam_Idle_Frame0,
        .timer = 7
    },
    [1] = {
        .pFrame = sKihunterGroundOam_Idle_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sKihunterGroundOam_Idle_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sKihunterGroundOam_Idle_Frame1,
        .timer = 7
    },
    [4] = {
        .pFrame = sKihunterGroundOam_Idle_Frame0,
        .timer = 7
    },
    [5] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame2,
        .timer = 7
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterFlyingOam_TurningAround1[3] = {
    [0] = {
        .pFrame = sKihunterFlyingOam_TurningAround1_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sKihunterFlyingOam_TurningAround1_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterFlyingOam_TurningAround2[3] = {
    [0] = {
        .pFrame = sKihunterFlyingOam_TurningAround1_Frame1,
        .timer = 2
    },
    [1] = {
        .pFrame = sKihunterFlyingOam_TurningAround1_Frame0,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterHiveOam[2] = {
    [0] = {
        .pFrame = sKihunterHiveOam_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterBugOam[4] = {
    [0] = {
        .pFrame = sKihunterBugOam_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sKihunterBugOam_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sKihunterBugOam_Frame2,
        .timer = 1
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterSpitOam_Moving[3] = {
    [0] = {
        .pFrame = sKihunterSpitOam_Moving_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sKihunterSpitOam_Moving_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterSpitOam_Exploding[4] = {
    [0] = {
        .pFrame = sKihunterSpitOam_Exploding_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sKihunterSpitOam_Exploding_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sKihunterSpitOam_Exploding_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterGroundOam_Spitting[15] = {
    [0] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame0,
        .timer = 4
    },
    [3] = {
        .pFrame = sKihunterGroundOam_StartLowJump_Frame1,
        .timer = 6
    },
    [4] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame7,
        .timer = 3
    },
    [8] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame8,
        .timer = 3
    },
    [9] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame9,
        .timer = 3
    },
    [10] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame10,
        .timer = 3
    },
    [11] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame11,
        .timer = 3
    },
    [12] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame12,
        .timer = 4
    },
    [13] = {
        .pFrame = sKihunterGroundOam_Spitting_Frame13,
        .timer = 6
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterGroundOam_JumpingLow[2] = {
    [0] = {
        .pFrame = sKihunterGroundOam_JumpingLow_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKihunterGroundOam_JumpingHighOrFalling[3] = {
    [0] = {
        .pFrame = sKihunterGroundOam_JumpingLow_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sKihunterGroundOam_JumpingHighOrFalling_Frame1,
        .timer = 255
    },
    [2] = FRAME_DATA_TERMINATOR
};
