#include "data/sprites/hornoad.h"
#include "macros.h"

const s16 sHornoadSpitYMovement[21] = {
    -4, -4, -3, -3,
    -2, -2, -1, -1,
     0,  0,  0,  0,
     1,  1,  2,  2,
     4,  4,  6,  8,
     SHORT_MAX
};

const s16 sHornoadJumpVelocityHigh[10] = {
    -6, -12, -6, -3,
     0,   4,  8,  12,
    16,  16
};

const s16 sHornoadJumpVelocityLow[10] = {
    -4,  -8, -4, -2,
     0,   4,  8, 16,
    16,  16
};

const u32 sHornoadGfx[512 * 3] = INCBIN_U32("data/sprites/hornoad.gfx");
const u16 sHornoadPal[16 * 3] = INCBIN_U16("data/sprites/hornoad.pal");

static const u16 sHornoadOam_TiltingHeadHidden_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20f, 8, 0),
};

static const u16 sHornoadOam_TiltingHeadHidden_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_TiltingHeadHidden_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sHornoadOam_MunchingHidden_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_MunchingHidden_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-17, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-17, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-1, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_MunchingHidden_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x263, 8, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_MouthHangingOpenHidden_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_MouthHangingOpenHidden_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_TurningAroundHidden_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x249, 8, 0),
};

static const u16 sOam_2eabe0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x249, 8, 0),
};

static const u16 sOam_2eabfa[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_X_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x8, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
};

static const u16 sOam_2eac1a[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_16x8, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
};

static const u16 sOam_2eac3a[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x8, OAM_X_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_16x8, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_IdleHidden_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_IdleHidden_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_IdleHidden_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_JumpingHidden_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -9, OAM_DIMS_16x16, OAM_XY_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_JumpingHidden_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_JumpingHidden_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_JumpingHidden_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_LandingHidden_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_LandingHidden_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_FallingHidden_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-1, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-15, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
};

static const u16 sHornoadOam_FallingHidden_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-9, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
};

static const u16 sHornoadOam_TouchedSamusHidden_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
};

static const u16 sHornoadOam_TouchedSamusHidden_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-9, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
};

static const u16 sHornoadSpawnerOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
};

static const u16 sHornoadSpawnerOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24e, 8, 0),
};

static const u16 sHornoadSpawnerOam_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x250, 8, 0),
};

static const u16 sHornoadOam_TiltingHead_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x265, 9, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
};

static const u16 sHornoadOam_TiltingHead_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x263, 9, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_TiltingHead_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 9, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20f, 9, 0),
};

static const u16 sHornoadOam_MouthHangingOpen_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_MouthHangingOpen_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_MouthHangingOpen_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 9, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_TurningAround_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x249, 9, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 9, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 9, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x249, 9, 0),
};

static const u16 sOam_2eaf16[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x249, 9, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x259, 9, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 9, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x249, 9, 0),
};

static const u16 sOam_2eaf30[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 9, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x203, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_8x16, OAM_X_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Idle_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 9, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Idle_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x267, 9, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x263, 9, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Idle_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x263, 9, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Jumping_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -9, OAM_DIMS_16x16, OAM_XY_FLIP, 0x216, 9, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
};

static const u16 sHornoadOam_Jumping_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
};

static const u16 sHornoadOam_Jumping_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
};

static const u16 sHornoadOam_Jumping_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
};

static const u16 sHornoadOam_Landing_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x263, 9, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Landing_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x263, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Spitting_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-3, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(1, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Spitting_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-15, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(1, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Spitting_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Spitting_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-17, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-1, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Spitting_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 9, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
};

static const u16 sHornoadSpitOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 10, 0),
};

static const u16 sHornoadSpitOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 10, 0),
};

static const u16 sHornoadSpitOam_ExplodingOnGroundOrCeiling_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x274, 10, 0),
};

static const u16 sHornoadSpitOam_ExplodingOnGroundOrCeiling_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 10, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x256, 10, 0),
};

static const u16 sHornoadSpitOam_ExplodingOnGroundOrCeiling_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x276, 10, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x278, 10, 0),
};

static const u16 sHornoadSpitOam_ExplodingOnWall_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 10, 0),
};

static const u16 sHornoadSpitOam_ExplodingOnWall_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 10, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25f, 10, 0),
};

static const u16 sHornoadSpitOam_ExplodingOnWall_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 10, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x283, 10, 0),
};

static const u16 sHornoadSpitOam_ExplodingMidair_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x284, 10, 0),
};

static const u16 sHornoadSpitOam_ExplodingMidair_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x286, 10, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x288, 10, 0),
    OAM_ENTRY(-9, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x289, 10, 0),
};

static const u16 sHornoadSpitOam_ExplodingMidair_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 10, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x28d, 10, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2a9, 10, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a3, 10, 0),
};

static const u16 sHornoadSpawnerOam_Spawning_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadSpawnerOam_Spawning_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-14, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(2, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadSpawnerOam_Spawning_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-14, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(-14, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(2, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_Falling_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-1, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25d, 9, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-15, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Falling_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-9, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25d, 9, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sOam_2eb244[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25d, 9, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(1, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sOam_2eb26a[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-9, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25d, 9, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
};

static const u16 sHornoadOam_Munching_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 9, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sOam_2eb2b0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 9, 0),
};

static const u16 sHornoadOam_Munching_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 9, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sHornoadOam_Munching_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-17, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-17, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-1, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sHornoadOam_Munching_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x263, 9, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sHornoadOam_Spitting_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 9, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 9, 0),
};

static const u16 sHornoadOam_HalfAsleepHidden_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_HalfAsleepHidden_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_HalfAsleepHidden_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_HalfAsleepHidden_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_HalfAsleepHidden_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ae, 8, 0),
};

static const u16 sHornoadOam_HalfAsleepHidden_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ae, 8, 0),
};

static const u16 sHornoadOam_HalfAsleepHidden_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ae, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sHornoadOam_HalfAsleepHidden_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-5, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ae, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
};

const struct FrameData sHornoadOam_TiltingHeadHidden[5] = {
    [0] = {
        .pFrame = sHornoadOam_TiltingHeadHidden_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sHornoadOam_TiltingHeadHidden_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sHornoadOam_TiltingHeadHidden_Frame0,
        .timer = 6
    },
    [3] = {
        .pFrame = sHornoadOam_TiltingHeadHidden_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_MunchingHidden[9] = {
    [0] = {
        .pFrame = sHornoadOam_TiltingHeadHidden_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sHornoadOam_MunchingHidden_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sHornoadOam_TiltingHeadHidden_Frame0,
        .timer = 10
    },
    [3] = {
        .pFrame = sHornoadOam_MunchingHidden_Frame1,
        .timer = 10
    },
    [4] = {
        .pFrame = sHornoadOam_MunchingHidden_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sHornoadOam_MunchingHidden_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sHornoadOam_MunchingHidden_Frame4,
        .timer = 4
    },
    [7] = {
        .pFrame = sHornoadOam_MunchingHidden_Frame5,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_MouthHangingOpenHidden[5] = {
    [0] = {
        .pFrame = sHornoadOam_TiltingHeadHidden_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sHornoadOam_MouthHangingOpenHidden_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sHornoadOam_MouthHangingOpenHidden_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sHornoadOam_MouthHangingOpenHidden_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_TurningAroundHidden[3] = {
    [0] = {
        .pFrame = sHornoadOam_MouthHangingOpenHidden_Frame1,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_TurningAroundHidden_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_TurninSecondPartHidden[3] = {
    [0] = {
        .pFrame = sHornoadOam_TurningAroundHidden_Frame1,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_MouthHangingOpenHidden_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_IdleHidden[5] = {
    [0] = {
        .pFrame = sHornoadOam_IdleHidden_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sHornoadOam_IdleHidden_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sHornoadOam_IdleHidden_Frame0,
        .timer = 10
    },
    [3] = {
        .pFrame = sHornoadOam_IdleHidden_Frame3,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_JumpingHidden[5] = {
    [0] = {
        .pFrame = sHornoadOam_JumpingHidden_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_JumpingHidden_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sHornoadOam_JumpingHidden_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sHornoadOam_JumpingHidden_Frame3,
        .timer = 255
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_LandingHidden[3] = {
    [0] = {
        .pFrame = sHornoadOam_LandingHidden_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sHornoadOam_LandingHidden_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_FallingHidden[3] = {
    [0] = {
        .pFrame = sHornoadOam_FallingHidden_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_FallingHidden_Frame1,
        .timer = 255
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_TouchedSamusHidden[3] = {
    [0] = {
        .pFrame = sHornoadOam_TouchedSamusHidden_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_TouchedSamusHidden_Frame1,
        .timer = 16
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadSpawnerOam_Idle[4] = {
    [0] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame2,
        .timer = 12
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadSpawnerOam_BeforeSpawning[7] = {
    [0] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame0,
        .timer = 4
    },
    [4] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame1,
        .timer = 4
    },
    [5] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame2,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_TiltingHead[5] = {
    [0] = {
        .pFrame = sHornoadOam_TiltingHead_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sHornoadOam_TiltingHead_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sHornoadOam_TiltingHead_Frame0,
        .timer = 6
    },
    [3] = {
        .pFrame = sHornoadOam_TiltingHead_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_Munching[9] = {
    [0] = {
        .pFrame = sHornoadOam_Munching_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sHornoadOam_Munching_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sHornoadOam_Munching_Frame0,
        .timer = 10
    },
    [3] = {
        .pFrame = sHornoadOam_Munching_Frame1,
        .timer = 10
    },
    [4] = {
        .pFrame = sHornoadOam_Munching_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sHornoadOam_Munching_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sHornoadOam_Munching_Frame4,
        .timer = 4
    },
    [7] = {
        .pFrame = sHornoadOam_Munching_Frame5,
        .timer = 4
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_MouthHangingOpen[5] = {
    [0] = {
        .pFrame = sHornoadOam_MouthHangingOpen_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sHornoadOam_MouthHangingOpen_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sHornoadOam_MouthHangingOpen_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sHornoadOam_MouthHangingOpen_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_TurningAround[3] = {
    [0] = {
        .pFrame = sHornoadOam_MouthHangingOpen_Frame1,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_TurningAround_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_TurninSecondPart[3] = {
    [0] = {
        .pFrame = sHornoadOam_TurningAround_Frame1,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_MouthHangingOpen_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_Idle[5] = {
    [0] = {
        .pFrame = sHornoadOam_Idle_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sHornoadOam_Idle_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sHornoadOam_Idle_Frame0,
        .timer = 10
    },
    [3] = {
        .pFrame = sHornoadOam_Idle_Frame3,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_Jumping[5] = {
    [0] = {
        .pFrame = sHornoadOam_Jumping_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_Jumping_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sHornoadOam_Jumping_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sHornoadOam_Jumping_Frame3,
        .timer = 255
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_Landing[3] = {
    [0] = {
        .pFrame = sHornoadOam_Landing_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sHornoadOam_Landing_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_Spitting[7] = {
    [0] = {
        .pFrame = sHornoadOam_Spitting_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_Spitting_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sHornoadOam_Spitting_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sHornoadOam_Spitting_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sHornoadOam_Spitting_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sHornoadOam_Spitting_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadSpitOam_Idle[3] = {
    [0] = {
        .pFrame = sHornoadSpitOam_Idle_Frame0,
        .timer = 9
    },
    [1] = {
        .pFrame = sHornoadSpitOam_Idle_Frame1,
        .timer = 9
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadSpitOam_ExplodingOnGroundOrCeiling[4] = {
    [0] = {
        .pFrame = sHornoadSpitOam_ExplodingOnGroundOrCeiling_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadSpitOam_ExplodingOnGroundOrCeiling_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sHornoadSpitOam_ExplodingOnGroundOrCeiling_Frame2,
        .timer = 7
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadSpitOam_ExplodingOnWall[4] = {
    [0] = {
        .pFrame = sHornoadSpitOam_ExplodingOnWall_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sHornoadSpitOam_ExplodingOnWall_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sHornoadSpitOam_ExplodingOnWall_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadSpitOam_ExplodingMidair[4] = {
    [0] = {
        .pFrame = sHornoadSpitOam_ExplodingMidair_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sHornoadSpitOam_ExplodingMidair_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sHornoadSpitOam_ExplodingMidair_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadSpawnerOam_2eb7e4[2] = {
    [0] = {
        .pFrame = sHornoadSpawnerOam_Idle_Frame2,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadSpawnerOam_Spawning[4] = {
    [0] = {
        .pFrame = sHornoadSpawnerOam_Spawning_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadSpawnerOam_Spawning_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sHornoadSpawnerOam_Spawning_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_Falling[3] = {
    [0] = {
        .pFrame = sHornoadOam_Falling_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_Falling_Frame1,
        .timer = 255
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_TouchedSamus[3] = {
    [0] = {
        .pFrame = sHornoadOam_Spitting_Frame4,
        .timer = 4
    },
    [1] = {
        .pFrame = sHornoadOam_Spitting_Frame1,
        .timer = 16
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHornoadOam_HalfAsleepHidden[13] = {
    [0] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame0,
        .timer = 34
    },
    [1] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame1,
        .timer = 22
    },
    [2] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame2,
        .timer = 18
    },
    [3] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame3,
        .timer = 16
    },
    [4] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame4,
        .timer = 34
    },
    [5] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame5,
        .timer = 22
    },
    [6] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame6,
        .timer = 18
    },
    [7] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame7,
        .timer = 16
    },
    [8] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame4,
        .timer = 34
    },
    [9] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame5,
        .timer = 22
    },
    [10] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame6,
        .timer = 18
    },
    [11] = {
        .pFrame = sHornoadOam_HalfAsleepHidden_Frame7,
        .timer = 16
    },
    [12] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_2eb8ac_2ed2e8[] = INCBIN_U8("data/Blob_2eb8ac_2ed2e8.bin");
