#include "data/sprites/nettori.h"
#include "macros.h"

const s16 sNettoriEaterSporeFloatingYVelocity[64] = {
     0,  0,  0,  0,
    -1,  0, -1,  0,
    -1,  0, -1,  0,
    -1, -1, -1, -2,
    -2, -1, -1, -1,
     0, -1,  0, -1,
     0, -1,  0, -1,
     0,  0,  0,  0,
     0,  0,  0,  0,
     1,  0,  1,  0,
     1,  0,  1,  0,
     1,  1,  1,  2,
     2,  1,  1,  1,
     0,  1,  0,  1,
     0,  1,  0,  1,
     0,  0,  0,
    SHORT_MAX
};

const s16 sNettoriEaterSporeFloatingSmallXVelocity[64] = {
     0,  0,  0,  1,
     0,  1,  1,  2,
     2,  3,  3,  4,
     4,  5,  5,  6,
     6,  5,  5,  4,
     4,  3,  3,  2,
     2,  1,  1,  0,
     1,  0,  0,  0,
     0,  0,  0, -1,
     0, -1, -1, -2,
    -2, -3, -3, -4,
    -4, -5, -5, -6,
    -6, -5, -5, -4,
    -4, -3, -3, -2,
    -2, -1, -1,  0,
    -1,  0,  0,
    SHORT_MAX
};

const s16 sNettoriEaterSporeFloatingLargeXVelocity[64] = {
     0,  0,  0, -1,
     0, -1, -1, -2,
    -2, -3, -3, -4,
    -4, -5, -5, -6,
    -6, -5, -5, -4,
    -4, -3, -3, -2,
    -2, -1, -1,  0,
    -1,  0,  0,  0,
     0,  0,  0,  1,
     0,  1,  1,  2,
     2,  3,  3,  4,
     4,  5,  5,  6,
     6,  5,  5,  4,
     4,  3,  3,  2,
     2,  1,  1,  0,
     1,  0,  0,
     SHORT_MAX
};

const s16 sNettoriEaterSporeMovingYVelocity[32] = {
    -10, -9, -8, -7,
     -6, -6, -5, -5,
     -4, -4, -3, -3,
     -2, -2, -1, -1,
      0,  0,  0,  0,
      0,  0,  0,  0,
      1,  2,  3,  4,
      5,  6,  8,
      SHORT_MAX
};


const u32 sNettoriGfx[4096] = INCBIN_U32("data/sprites/nettori.gfx");
const u16 sNettoriPal[8 * 16] = INCBIN_U16("data/sprites/nettori.pal");

static const u16 sNettoriOam_Idle_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-32, -96, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -88, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-32, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 772, 8, 0),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 836, 8, 0),
    OAM_ENTRY(0, -56, OAM_DIMS_8x32, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 616, 8, 0),
};

static const u16 sNettoriOam_Idle_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-32, -96, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -88, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-32, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 768, 8, 0),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 832, 8, 0),
    OAM_ENTRY(0, -56, OAM_DIMS_8x32, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 616, 8, 0),
};

static const u16 sNettoriOam_Idle_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-32, -96, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -88, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-32, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 584, 8, 0),
    OAM_ENTRY(0, -56, OAM_DIMS_8x32, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 616, 8, 0),
};

static const u16 sNettoriPartOam_PlasmaShootingHigh_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 640, 9, 0),
};

static const u16 sNettoriPartOam_PlasmaShootingHigh_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-27, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 776, 11, 0),
};

static const u16 sNettoriPartOam_PlasmaShootingLow_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 825, 11, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 888, 11, 0),
};

static const u16 sNettoriPartOam_HeadVinesIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-30, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 778, 8, 0),
};

static const u16 sNettoriPartOam_HeadVinesIdle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, -96, OAM_DIMS_8x32, OAM_NO_FLIP, 782, 8, 0),
};

static const u16 sNettoriPartOam_HeadVinesIdle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-33, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 783, 8, 0),
    OAM_ENTRY(-17, -96, OAM_DIMS_8x32, OAM_NO_FLIP, 785, 8, 0),
};

static const u16 sNettoriPartOam_BodyVinesIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-18, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 886, 8, 0),
    OAM_ENTRY(-10, -54, OAM_DIMS_8x16, OAM_NO_FLIP, 823, 8, 0),
};

static const u16 sNettoriPartOam_BodyVinesIdle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-18, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 852, 8, 0),
    OAM_ENTRY(-10, -47, OAM_DIMS_8x8, OAM_NO_FLIP, 821, 8, 0),
};

static const u16 sNettoriPartOam_BodyVinesIdle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-14, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 850, 8, 0),
};

static const u16 sNettoriPartOam_RightArmIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-33, -52, OAM_DIMS_16x32, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-41, -52, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
};

static const u16 sNettoriPartOam_HeadIdle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-41, -92, OAM_DIMS_32x32, OAM_NO_FLIP, 525, 8, 0),
    OAM_ENTRY(-49, -90, OAM_DIMS_8x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(-34, -60, OAM_DIMS_8x8, OAM_NO_FLIP, 595, 8, 0),
};

static const u16 sNettoriPartOam_LegIdle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-17, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(-25, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-17, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sNettoriPartOam_LeftArmIdle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-17, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-23, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-22, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 627, 8, 0),
};

static const u16 sSamusEaterOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x32, OAM_NO_FLIP, 640, 9, 0),
};

static const u16 sSamusEaterOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x32, OAM_NO_FLIP, 648, 9, 0),
};

static const u16 sSamusEaterOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x32, OAM_NO_FLIP, 656, 9, 0),
};

static const u16 sSamusEaterOam_EatingSamus_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 896, 9, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 900, 9, 0),
};

static const u16 sSamusEaterOam_EatingSamus_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 902, 9, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 906, 9, 0),
};

static const u16 sSamusEaterOam_EatingSamus_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -31, OAM_DIMS_32x32, OAM_NO_FLIP, 908, 9, 0),
    OAM_ENTRY(8, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 912, 9, 0),
};

static const u16 sSamusEaterOam_EatingSamus_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 914, 9, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 918, 9, 0),
};

static const u16 sSamusEaterSporeOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 600, 9, 0),
};

static const u16 sSamusEaterSporeOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 601, 9, 0),
};

static const u16 sSamusEaterSporeOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 632, 9, 0),
};

static const u16 sSamusEaterSporeOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 633, 9, 0),
};

static const u16 sSamusEaterSporeOam_Exploding_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 864, 9, 0),
};

static const u16 sSamusEaterSporeOam_Exploding_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 865, 9, 0),
};

static const u16 sSamusEaterSporeOam_Exploding_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 9, 0),
};

static const u16 sSamusEaterBudOam_TurningAround_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 9, 0),
    OAM_ENTRY(-9, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 866, 9, 0),
};

static const u16 sSamusEaterBudOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 602, 9, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 9, 0),
};

static const u16 sSamusEaterBudOam_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 604, 9, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 569, 9, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 9, 0),
};

static const u16 sSamusEaterBudOam_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 606, 9, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 569, 9, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 9, 0),
};

static const u16 sSamusEatingBudOam_Shooting_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-20, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 539, 9, 0),
    OAM_ENTRY(-4, -3, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 9, 0),
    OAM_ENTRY(-12, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 834, 9, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 9, 0),
};

static const u16 sSamusEatingBudOam_Shooting_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-29, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 728, 9, 0),
    OAM_ENTRY(-5, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 835, 9, 0),
    OAM_ENTRY(-11, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 9, 0),
};

static const u16 sNettoriPlasmaBeamOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 664, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 668, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 794, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 796, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 664, 10, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 798, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 920, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 668, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 922, 10, 0),
    OAM_ENTRY(-12, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 664, 10, 0),
    OAM_ENTRY(-6, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 665, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 668, 10, 0),
    OAM_ENTRY(-6, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 669, 10, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 924, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 920, 10, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 664, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 922, 10, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 668, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-20, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 664, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 665, 10, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 924, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 920, 10, 0),
    OAM_ENTRY(-20, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 668, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 669, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame10[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 664, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 665, 10, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 922, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Emerging_Frame11[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 668, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 669, 10, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 924, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Charging_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 664, 10, 0),
};

static const u16 sNettoriPlasmaBeamOam_Charging_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 668, 10, 0),
};


const struct FrameData sNettoriOam_Idle[5] = {
    [0] = {
        .pFrame = sNettoriOam_Idle_Frame0,
        .timer = 24
    },
    [1] = {
        .pFrame = sNettoriOam_Idle_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sNettoriOam_Idle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sNettoriOam_Idle_Frame1,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriOam_ChargingBeam[5] = {
    [0] = {
        .pFrame = sNettoriOam_Idle_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sNettoriOam_Idle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sNettoriOam_Idle_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sNettoriOam_Idle_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_RightArmIdle[2] = {
    [0] = {
        .pFrame = sNettoriPartOam_RightArmIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_HeadIdle[2] = {
    [0] = {
        .pFrame = sNettoriPartOam_HeadIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_HeadVinesIdle[5] = {
    [0] = {
        .pFrame = sNettoriPartOam_HeadVinesIdle_Frame0,
        .timer = 24
    },
    [1] = {
        .pFrame = sNettoriPartOam_HeadVinesIdle_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sNettoriPartOam_HeadVinesIdle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sNettoriPartOam_HeadVinesIdle_Frame1,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_HeadVinesShooting[5] = {
    [0] = {
        .pFrame = sNettoriPartOam_HeadVinesIdle_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sNettoriPartOam_HeadVinesIdle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sNettoriPartOam_HeadVinesIdle_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sNettoriPartOam_HeadVinesIdle_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_PlasmaShootingHigh[16] = {
    [0] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame0,
        .timer = 6
    },
    [3] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame0,
        .timer = 6
    },
    [5] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame0,
        .timer = 6
    },
    [7] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame0,
        .timer = 6
    },
    [9] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame0,
        .timer = 6
    },
    [11] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame0,
        .timer = 6
    },
    [13] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame0,
        .timer = UCHAR_MAX
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_LegIdle[2] = {
    [0] = {
        .pFrame = sNettoriPartOam_LegIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_BodyVinesIdle[5] = {
    [0] = {
        .pFrame = sNettoriPartOam_BodyVinesIdle_Frame0,
        .timer = 24
    },
    [1] = {
        .pFrame = sNettoriPartOam_BodyVinesIdle_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sNettoriPartOam_BodyVinesIdle_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sNettoriPartOam_BodyVinesIdle_Frame1,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_BodyVinesShooting[5] = {
    [0] = {
        .pFrame = sNettoriPartOam_BodyVinesIdle_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sNettoriPartOam_BodyVinesIdle_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sNettoriPartOam_BodyVinesIdle_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sNettoriPartOam_BodyVinesIdle_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_PlasmaShootingLow[16] = {
    [0] = {
        .pFrame = sNettoriPartOam_PlasmaShootingLow_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sNettoriPartOam_PlasmaShootingLow_Frame0,
        .timer = 6
    },
    [3] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sNettoriPartOam_PlasmaShootingLow_Frame0,
        .timer = 6
    },
    [5] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sNettoriPartOam_PlasmaShootingLow_Frame0,
        .timer = 6
    },
    [7] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sNettoriPartOam_PlasmaShootingLow_Frame0,
        .timer = 6
    },
    [9] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [10] = {
        .pFrame = sNettoriPartOam_PlasmaShootingLow_Frame0,
        .timer = 6
    },
    [11] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [12] = {
        .pFrame = sNettoriPartOam_PlasmaShootingLow_Frame0,
        .timer = 6
    },
    [13] = {
        .pFrame = sNettoriPartOam_PlasmaShootingHigh_Frame1,
        .timer = 1
    },
    [14] = {
        .pFrame = sNettoriPartOam_PlasmaShootingLow_Frame0,
        .timer = UCHAR_MAX
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPartOam_LeftArmIdle[2] = {
    [0] = {
        .pFrame = sNettoriPartOam_LeftArmIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEaterOam_Idle[5] = {
    [0] = {
        .pFrame = sSamusEaterOam_Idle_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sSamusEaterOam_Idle_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sSamusEaterOam_Idle_Frame2,
        .timer = 20
    },
    [3] = {
        .pFrame = sSamusEaterOam_Idle_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEaterOam_EatingSamus[14] = {
    [0] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame3,
        .timer = 10
    },
    [4] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame2,
        .timer = 10
    },
    [5] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame3,
        .timer = 10
    },
    [6] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame2,
        .timer = 10
    },
    [7] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame3,
        .timer = 10
    },
    [8] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame2,
        .timer = 10
    },
    [9] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame3,
        .timer = 10
    },
    [10] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame2,
        .timer = 10
    },
    [11] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame1,
        .timer = 6
    },
    [12] = {
        .pFrame = sSamusEaterOam_EatingSamus_Frame0,
        .timer = 6
    },
    [13] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEaterBudOam_Idle[5] = {
    [0] = {
        .pFrame = sSamusEaterBudOam_Idle_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sSamusEaterBudOam_Idle_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sSamusEaterBudOam_Idle_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sSamusEaterBudOam_Idle_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEaterBudOam_Shooting[9] = {
    [0] = {
        .pFrame = sSamusEaterBudOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sSamusEaterBudOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sSamusEaterBudOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sSamusEatingBudOam_Shooting_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sSamusEatingBudOam_Shooting_Frame4,
        .timer = 30
    },
    [5] = {
        .pFrame = sSamusEatingBudOam_Shooting_Frame3,
        .timer = 8
    },
    [6] = {
        .pFrame = sSamusEaterBudOam_Idle_Frame2,
        .timer = 8
    },
    [7] = {
        .pFrame = sSamusEaterBudOam_Idle_Frame1,
        .timer = 16
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEaterBudOam_TurningAround[2] = {
    [0] = {
        .pFrame = sSamusEaterBudOam_TurningAround_Frame0,
        .timer = 8
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEaterSporeOam_Idle[5] = {
    [0] = {
        .pFrame = sSamusEaterSporeOam_Idle_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sSamusEaterSporeOam_Idle_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sSamusEaterSporeOam_Idle_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sSamusEaterSporeOam_Idle_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSamusEaterSporeOam_Exploding[4] = {
    [0] = {
        .pFrame = sSamusEaterSporeOam_Exploding_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sSamusEaterSporeOam_Exploding_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sSamusEaterSporeOam_Exploding_Frame2,
        .timer = 5
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPlasmaBeamOam_Moving[3] = {
    [0] = {
        .pFrame = sNettoriPlasmaBeamOam_Moving_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sNettoriPlasmaBeamOam_Moving_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPlasmaBeamOam_Emerging[23] = {
    [0] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame6,
        .timer = 3
    },
    [7] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame7,
        .timer = 3
    },
    [8] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame8,
        .timer = 3
    },
    [9] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame9,
        .timer = 3
    },
    [10] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame10,
        .timer = 3
    },
    [11] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame11,
        .timer = 3
    },
    [12] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame10,
        .timer = 3
    },
    [13] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame11,
        .timer = 3
    },
    [14] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame10,
        .timer = 3
    },
    [15] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame11,
        .timer = 3
    },
    [16] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame10,
        .timer = 3
    },
    [17] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame11,
        .timer = 3
    },
    [18] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame10,
        .timer = 3
    },
    [19] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame11,
        .timer = 3
    },
    [20] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame8,
        .timer = 2
    },
    [21] = {
        .pFrame = sNettoriPlasmaBeamOam_Emerging_Frame9,
        .timer = 2
    },
    [22] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNettoriPlasmaBeamOam_Charging[3] = {
    [0] = {
        .pFrame = sNettoriPlasmaBeamOam_Charging_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sNettoriPlasmaBeamOam_Charging_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};


const u16 sNettoriPal_Purple[1 * 16] = INCBIN_U16("data/sprites/nettori_purple.pal");
const u16 sNettoriPal_Red[1 * 16] = INCBIN_U16("data/sprites/nettori_red.pal");
const u16 sNettoriGlowingPal_1[1 * 16] = INCBIN_U16("data/sprites/nettori_glowing_1.pal");
const u16 sNettoriGlowingPal_2[1 * 16] = INCBIN_U16("data/sprites/nettori_glowing_2.pal");
const u16 sNettoriGlowingPal_3[1 * 16] = INCBIN_U16("data/sprites/nettori_glowing_3.pal");
