#include "data/sprites/moto.h"
#include "macros.h"

const u32 sMotoGfx[1536] = INCBIN_U32("data/sprites/moto.gfx");
const u16 sMotoPal[48] = INCBIN_U16("data/sprites/moto.pal");

static const u16 sMotoOam_Charging_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-29, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-24, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(-24, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_Charging_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-29, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-20, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(-10, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-24, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(-24, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_Charging_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-29, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-20, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-24, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(-24, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_Charging_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-30, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-21, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 594, 8, 0),
    OAM_ENTRY(-25, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(-25, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sMotoOam_Charging_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-31, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-22, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 590, 8, 0),
    OAM_ENTRY(-26, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(-26, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sMotoOam_Idle_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-22, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-10, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_Idle_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-22, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-10, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-14, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-6, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 584, 8, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_Idle_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-22, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-10, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-14, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_Charging_Frame8[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-31, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 590, 8, 0),
    OAM_ENTRY(-26, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(-26, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sMotoOam_Charging_Frame9[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-31, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 590, 8, 0),
    OAM_ENTRY(-26, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(-26, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sMotoOam_Charging_Frame10[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-31, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(-3, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 590, 8, 0),
    OAM_ENTRY(-26, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(-26, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sMotoOam_Walking_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-23, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 594, 8, 0),
    OAM_ENTRY(-15, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sMotoOam_Walking_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-22, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_Walking_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-22, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-14, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sMotoOam_Walking_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-23, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-15, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-3, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sMotoOam_Walking_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-22, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-6, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_Walking_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-22, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_TurningAroundFIrstPart_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-16, -26, OAM_DIMS_32x8, OAM_NO_FLIP, 615, 8, 0),
    OAM_ENTRY(-22, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-22, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_TurningAroundFIrstPart_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 600, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_32x8, OAM_NO_FLIP, 615, 8, 0),
    OAM_ENTRY(-22, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-22, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_2ef66a[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, -25, OAM_DIMS_32x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_16x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(-6, -7, OAM_DIMS_16x8, OAM_X_FLIP, 630, 8, 0),
    OAM_ENTRY(-6, -14, OAM_DIMS_16x8, OAM_X_FLIP, 598, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_32x16, OAM_X_FLIP, 576, 8, 0),
    OAM_ENTRY(-18, -10, OAM_DIMS_32x8, OAM_X_FLIP, 583, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_X_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_WalkingSlowing_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-17, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 570, 8, 0),
    OAM_ENTRY(-24, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-20, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-14, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sMotoOam_WalkingSlowing_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-17, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 570, 8, 0),
    OAM_ENTRY(-22, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sMotoOam_2ef6ee[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-22, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-10, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-14, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-14, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-6, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 584, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_2ef720[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-22, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-10, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-14, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-14, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_Falling_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-21, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-18, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 651, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-13, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-13, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 585, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sMotoOam_Falling_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-22, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-19, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 651, 8, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-14, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(2, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 585, 8, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_WalkingCharged_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-20, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 594, 8, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sMotoOam_WalkingCharged_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-22, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_WalkingCharged_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-23, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-14, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sMotoOam_WalkingCharged_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-20, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-15, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sMotoOam_WalkingCharged_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-22, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-6, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoOam_WalkingCharged_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-23, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-19, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 583, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sMotoFrontOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 653, 8, 0),
};


const struct FrameData sMotoOam_Idle[5] = {
    [0] = {
        .pFrame = sMotoOam_Idle_Frame0,
        .timer = 7
    },
    [1] = {
        .pFrame = sMotoOam_Idle_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sMotoOam_Idle_Frame0,
        .timer = 7
    },
    [3] = {
        .pFrame = sMotoOam_Idle_Frame3,
        .timer = 7
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotoOam_Walking[7] = {
    [0] = {
        .pFrame = sMotoOam_Walking_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sMotoOam_Walking_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sMotoOam_Walking_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sMotoOam_Walking_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sMotoOam_Walking_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sMotoOam_Walking_Frame5,
        .timer = 6
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotoOam_TurningAroundFirstPart[3] = {
    [0] = {
        .pFrame = sMotoOam_TurningAroundFIrstPart_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sMotoOam_TurningAroundFIrstPart_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotoOam_TurningAroundSecondPart[3] = {
    [0] = {
        .pFrame = sMotoOam_TurningAroundFIrstPart_Frame1,
        .timer = 3
    },
    [1] = {
        .pFrame = sMotoOam_TurningAroundFIrstPart_Frame0,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotoOam_WalkingSlowing[3] = {
    [0] = {
        .pFrame = sMotoOam_WalkingSlowing_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMotoOam_WalkingSlowing_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotoOam_Falling[3] = {
    [0] = {
        .pFrame = sMotoOam_Falling_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMotoOam_Falling_Frame1,
        .timer = UCHAR_MAX
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotoOam_Charging[14] = {
    [0] = {
        .pFrame = sMotoOam_Charging_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sMotoOam_Charging_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sMotoOam_Charging_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sMotoOam_Charging_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sMotoOam_Charging_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sMotoOam_Charging_Frame0,
        .timer = 3
    },
    [6] = {
        .pFrame = sMotoOam_Charging_Frame1,
        .timer = 3
    },
    [7] = {
        .pFrame = sMotoOam_Charging_Frame2,
        .timer = 4
    },
    [8] = {
        .pFrame = sMotoOam_Charging_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sMotoOam_Charging_Frame9,
        .timer = 1
    },
    [10] = {
        .pFrame = sMotoOam_Charging_Frame10,
        .timer = 1
    },
    [11] = {
        .pFrame = sMotoOam_Charging_Frame9,
        .timer = 5
    },
    [12] = {
        .pFrame = sMotoOam_Charging_Frame4,
        .timer = 2
    },
    [13] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotoOam_WalkingCharged[7] = {
    [0] = {
        .pFrame = sMotoOam_WalkingCharged_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sMotoOam_WalkingCharged_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sMotoOam_WalkingCharged_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sMotoOam_WalkingCharged_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sMotoOam_WalkingCharged_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sMotoOam_WalkingCharged_Frame5,
        .timer = 3
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotoFrontOam_Idle[2] = {
    [0] = {
        .pFrame = sMotoFrontOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
