#include "data/sprites/animals.h"
#include "macros.h"

const s16 sAnimalsLeavingEnclosureYSpeeds[13] = {
    -6, -4, -2, 0,
    0, 2, 4, 6,
    8, 8, 8, 8,
    SHORT_MAX
};

const u32 sAnimalsGfx[512 * 4] = INCBIN_U32("data/sprites/animals.gfx");
const u16 sAnimalsPal[PAL_ROW * 4] = INCBIN_U16("data/sprites/animals.pal");

const u16 sEtecoonOam_Standing_Foreground_Still_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-11, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x288, 9, 0),
    OAM_ENTRY(3, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x287, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x287, 9, 0),
};

const u16 sEtecoonOam_Standing_Foreground_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-11, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-11, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x289, 9, 0),
    OAM_ENTRY(3, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x288, 9, 0),
    OAM_ENTRY(3, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x289, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x287, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x287, 9, 0),
};

const u16 sEtecoonOam_Standing_Foreground_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-11, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-11, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a9, 9, 0),
    OAM_ENTRY(3, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x288, 9, 0),
    OAM_ENTRY(3, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a9, 9, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x287, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a7, 9, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x287, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a7, 9, 0),
};

const u16 sEtecoonOam_Standing_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x283, 9, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 9, 0),
};

const u16 sEtecoonOam_Waiting_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x283, 9, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 9, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 9, 0),
};

const u16 sEtecoonOam_Waiting_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x283, 9, 0),
    OAM_ENTRY(-7, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 9, 0),
};

const u16 sEtecoonOam_Running_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x285, 9, 0),
    OAM_ENTRY(-13, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28c, 9, 0),
    OAM_ENTRY(3, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x28e, 9, 0),
};

const u16 sEtecoonOam_Running_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x285, 9, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28f, 9, 0),
};

const u16 sEtecoonOam_Running_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x285, 9, 0),
    OAM_ENTRY(-5, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x291, 9, 0),
};

const u16 sEtecoonOam_Running_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x285, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x293, 9, 0),
};

const u16 sEtecoonOam_Turning_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x283, 9, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x295, 9, 0),
};

const u16 sEtecoonOam_TurningHead_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x285, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x287, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x287, 9, 0),
};

const u16 sEtecoonOam_TurningHead_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x283, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x287, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x287, 9, 0),
};

const u16 sEtecoonOam_TurningHead_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x287, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x287, 9, 0),
};

const u16 sEtecoonOam_TurningHead_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x283, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x287, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x287, 9, 0),
};

const u16 sEtecoonOam_TurningHead_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x285, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x287, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x287, 9, 0),
};

const u16 sTireSwingOam_Idle_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -72, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c9, 9, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2cb, 9, 0),
    OAM_ENTRY(0, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -104, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
};

const u16 sTireSwingOam_Bobbing_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -71, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c9, 9, 0),
    OAM_ENTRY(-8, -55, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2cb, 9, 0),
    OAM_ENTRY(0, -79, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -87, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -95, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -103, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
};

const u16 sTireSwingOam_EtecoonLeaving_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2cd, 9, 0),
    OAM_ENTRY(-6, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2eb, 9, 0),
    OAM_ENTRY(0, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e2, 9, 0),
    OAM_ENTRY(-5, -104, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e2, 9, 0),
    OAM_ENTRY(-4, -88, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e2, 9, 0),
};

const u16 sTireSwingOam_EtecoonLeaving_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -76, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c9, 9, 0),
    OAM_ENTRY(-8, -60, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2cb, 9, 0),
    OAM_ENTRY(1, -84, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e2, 9, 0),
    OAM_ENTRY(-4, -92, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e2, 9, 0),
    OAM_ENTRY(1, -100, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e2, 9, 0),
    OAM_ENTRY(-4, -108, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e2, 9, 0),
};

const u16 sTireSwingOam_EtecoonLeaving_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -72, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2cf, 9, 0),
    OAM_ENTRY(-10, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d1, 9, 0),
    OAM_ENTRY(-4, -96, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e2, 9, 0),
    OAM_ENTRY(1, -104, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e2, 9, 0),
    OAM_ENTRY(1, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e2, 9, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e2, 9, 0),
};

const u16 sTireSwingOam_EtecoonLeaving_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -65, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2cd, 9, 0),
    OAM_ENTRY(-8, -49, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2eb, 9, 0),
    OAM_ENTRY(0, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -104, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
};

const u16 sTireSwingOam_EtecoonLeaving_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -69, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2cf, 9, 0),
    OAM_ENTRY(-8, -53, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d1, 9, 0),
    OAM_ENTRY(0, -76, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -84, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -92, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -100, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
    OAM_ENTRY(0, -108, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e3, 9, 0),
};

const u16 sEtecoonOam_JumpingToTire_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(3, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(-8, -39, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -31, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d3, 9, 0),
};

const u16 sEtecoonOam_JumpingToTire_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -52, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(3, -51, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(-8, -47, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-8, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d3, 9, 0),
};

const u16 sEtecoonOam_Hanging_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-7, -49, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-3, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-7, -31, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f5, 9, 0),
    OAM_ENTRY(-7, -45, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-7, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d5, 9, 0),
    OAM_ENTRY(2, -43, OAM_DIMS_8x16, OAM_X_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-8, -58, OAM_DIMS_8x16, OAM_Y_FLIP, 0x288, 9, 0),
};

const u16 sEtecoonOam_Hanging_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-7, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-3, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-7, -29, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f5, 9, 0),
    OAM_ENTRY(-7, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-7, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d5, 9, 0),
    OAM_ENTRY(2, -41, OAM_DIMS_8x16, OAM_X_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-8, -58, OAM_DIMS_8x16, OAM_Y_FLIP, 0x288, 9, 0),
};

const u16 sEtecoonOam_Hanging_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-7, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-3, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a1, 9, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f5, 9, 0),
    OAM_ENTRY(-7, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-7, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d5, 9, 0),
    OAM_ENTRY(2, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-8, -57, OAM_DIMS_8x16, OAM_Y_FLIP, 0x288, 9, 0),
};

const u16 sEtecoonOam_HangingAndTurning_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, -53, OAM_DIMS_16x16, OAM_NO_FLIP, 0x283, 9, 0),
    OAM_ENTRY(-7, -31, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f5, 9, 0),
    OAM_ENTRY(-7, -45, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-7, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d5, 9, 0),
    OAM_ENTRY(2, -43, OAM_DIMS_8x16, OAM_X_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-8, -58, OAM_DIMS_8x16, OAM_Y_FLIP, 0x288, 9, 0),
};

const u16 sEtecoonOam_HangingAndTurning_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -52, OAM_DIMS_16x16, OAM_NO_FLIP, 0x285, 9, 0),
    OAM_ENTRY(-7, -29, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f5, 9, 0),
    OAM_ENTRY(-7, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-7, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d5, 9, 0),
    OAM_ENTRY(2, -41, OAM_DIMS_8x16, OAM_X_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-8, -58, OAM_DIMS_8x16, OAM_Y_FLIP, 0x288, 9, 0),
};

const u16 sEtecoonOam_HangingAndTurning_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x285, 9, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f5, 9, 0),
    OAM_ENTRY(-7, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-7, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d5, 9, 0),
    OAM_ENTRY(2, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-8, -57, OAM_DIMS_8x16, OAM_Y_FLIP, 0x288, 9, 0),
};

const u16 sEtecoonOam_JumpingOnGlass_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c2, 9, 0),
    OAM_ENTRY(4, -36, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c2, 9, 0),
    OAM_ENTRY(-8, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a1, 9, 0),
    OAM_ENTRY(-16, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c5, 9, 0),
    OAM_ENTRY(0, -30, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c5, 9, 0),
};

const u16 sEtecoonOam_JumpingOnGlass_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(4, -36, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c3, 9, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a2, 9, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c7, 9, 0),
    OAM_ENTRY(0, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c7, 9, 0),
};

const u16 sEtecoonOam_JumpingOnGlass_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(3, -37, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d3, 9, 0),
};

const u16 sEtecoonOam_JumpingOnGlass_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(3, -38, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f1, 9, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d3, 9, 0),
};

const u16 sEtecoonOam_JumpingOnGlass_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-13, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x282, 9, 0),
    OAM_ENTRY(5, -11, OAM_DIMS_8x8, OAM_X_FLIP, 0x282, 9, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c0, 9, 0),
};

const u16 sEtecoonOam_JumpingOnGlass_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-13, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x282, 9, 0),
    OAM_ENTRY(5, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x282, 9, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c0, 9, 0),
};

const u16 sDachoraOam_Standing_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
};

const u16 sDachoraOam_Waiting_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
};

const u16 sDachoraOam_Waiting_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-6, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x267, 8, 0),
};

const u16 sDachoraOam_TiltingHead_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
};

const u16 sDachoraOam_TiltingHead_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
};

const u16 sDachoraOam_Blinking_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-12, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-16, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
};

const u16 sDachoraOam_Blinking_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-12, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-16, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
};

const u16 sDachoraOam_Bowing_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-32, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
};

const u16 sDachoraOam_Bowing_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-32, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
};

const u16 sDachoraOam_Bowing_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-32, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
};

const u16 sDachoraOam_Bowing_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-8, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
};

const u16 sDachoraOam_Running_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x245, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x269, 8, 0),
};

const u16 sDachoraOam_Running_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-17, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-14, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-6, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-6, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-2, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0),
};

const u16 sDachoraOam_Running_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-14, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(10, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-6, -29, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-6, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-14, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26d, 8, 0),
};

const u16 sDachoraOam_Running_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x265, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26f, 8, 0),
};

const u16 sDachoraOam_Running_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-14, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-6, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-6, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-2, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x271, 8, 0),
};

const u16 sDachoraOam_Running_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-14, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(10, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x246, 8, 0),
    OAM_ENTRY(-6, -29, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-6, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-14, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 8, 0),
};

const u16 sDachoraOam_Turning_Start_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
};

const u16 sDachoraOam_Turning_Start_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21c, 8, 0),
};

const u16 sDachoraOam_TurningHead_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
};

const u16 sDachoraOam_TurningHead_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
};

const u16 sBabyDachoraOam_Standing_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
};

const u16 sBabyDachoraOam_Walking_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
};

const u16 sBabyDachoraOam_Walking_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0),
};

const u16 sBabyDachoraOam_Walking_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
};

const u16 sBabyDachoraOam_Blinking_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
};

const u16 sBabyDachoraOam_Blinking_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
};

const u16 sBabyDachoraOam_Waiting_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
};

const u16 sBabyDachoraOam_Waiting_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
};

const u16 sHabitationGateLightOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(8, -60, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29b, 10, 0),
    OAM_ENTRY(16, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29c, 10, 0),
};

const u16 sHabitationGateLightOam_Flashing_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e4, 10, 0),
};

const u16 sHabitationGateOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x29f, 10, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x29e, 10, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x32, OAM_NO_FLIP, 0x297, 10, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 10, 0),
};

const u16 sHabitationGateOam_Opening_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x29d, 10, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x29d, 10, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x29d, 10, 0),
    OAM_ENTRY(-18, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x29f, 10, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bb, 10, 0),
    OAM_ENTRY(-18, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2be, 10, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_32x32, OAM_NO_FLIP, 0x297, 10, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 10, 0),
};

const u16 sHabitationGateOam_Opening_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bd, 10, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29d, 10, 0),
    OAM_ENTRY(-20, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x29f, 10, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bb, 10, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2be, 10, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_32x32, OAM_NO_FLIP, 0x297, 10, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 10, 0),
};

const u16 sHabitationGateOam_Opening_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bd, 10, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29d, 10, 0),
    OAM_ENTRY(-22, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x29f, 10, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bb, 10, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2be, 10, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_32x32, OAM_NO_FLIP, 0x297, 10, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 10, 0),
};

const u16 sHabitationGateOam_Opening_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bd, 10, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29d, 10, 0),
    OAM_ENTRY(-20, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x29f, 10, 0),
    OAM_ENTRY(-20, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bb, 10, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2be, 10, 0),
    OAM_ENTRY(7, -48, OAM_DIMS_32x32, OAM_NO_FLIP, 0x297, 10, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 10, 0),
};

const u16 sHabitationGateOam_Opening_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bd, 10, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29d, 10, 0),
    OAM_ENTRY(-21, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x29f, 10, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bb, 10, 0),
    OAM_ENTRY(-21, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2be, 10, 0),
    OAM_ENTRY(9, -48, OAM_DIMS_32x32, OAM_NO_FLIP, 0x297, 10, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 10, 0),
};

const u16 sHabitationGateOam_Opening_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bd, 10, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29d, 10, 0),
    OAM_ENTRY(-22, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x29f, 10, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2bb, 10, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2be, 10, 0),
    OAM_ENTRY(11, -48, OAM_DIMS_32x32, OAM_NO_FLIP, 0x297, 10, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 10, 0),
};

const struct FrameData sEtecoonOam_Standing_Foreground_Still[2] = {
    [0] = {
        .pFrame = sEtecoonOam_Standing_Foreground_Still_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_Standing_Foreground[5] = {
    [0] = {
        .pFrame = sEtecoonOam_Standing_Foreground_Still_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sEtecoonOam_Standing_Foreground_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sEtecoonOam_Standing_Foreground_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sEtecoonOam_Standing_Foreground_Frame1,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_Standing[2] = {
    [0] = {
        .pFrame = sEtecoonOam_Standing_Frame0,
        .timer = 8
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_Running[5] = {
    [0] = {
        .pFrame = sEtecoonOam_Running_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sEtecoonOam_Running_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sEtecoonOam_Running_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sEtecoonOam_Running_Frame3,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_Turning[2] = {
    [0] = {
        .pFrame = sEtecoonOam_Turning_Frame0,
        .timer = 6
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_TurningHead[9] = {
    [0] = {
        .pFrame = sEtecoonOam_TurningHead_Frame0,
        .timer = 40
    },
    [1] = {
        .pFrame = sEtecoonOam_TurningHead_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sEtecoonOam_TurningHead_Frame2,
        .timer = 40
    },
    [3] = {
        .pFrame = sEtecoonOam_TurningHead_Frame1,
        .timer = 8
    },
    [4] = {
        .pFrame = sEtecoonOam_TurningHead_Frame0,
        .timer = 4
    },
    [5] = {
        .pFrame = sEtecoonOam_TurningHead_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sEtecoonOam_TurningHead_Frame6,
        .timer = 40
    },
    [7] = {
        .pFrame = sEtecoonOam_TurningHead_Frame5,
        .timer = 8
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_JumpingOnGlass[11] = {
    [0] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame1,
        .timer = 20
    },
    [2] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame5,
        .timer = 8
    },
    [6] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame4,
        .timer = 8
    },
    [7] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame2,
        .timer = 6
    },
    [8] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame1,
        .timer = 6
    },
    [9] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame0,
        .timer = 6
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_JumpingToTire[11] = {
    [0] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame1,
        .timer = 20
    },
    [2] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sEtecoonOam_JumpingToTire_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sEtecoonOam_JumpingToTire_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sEtecoonOam_JumpingToTire_Frame3,
        .timer = 4
    },
    [6] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame4,
        .timer = 6
    },
    [7] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame2,
        .timer = 3
    },
    [8] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame1,
        .timer = 6
    },
    [9] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame0,
        .timer = 40
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_Hanging_Start[5] = {
    [0] = {
        .pFrame = sEtecoonOam_Hanging_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sEtecoonOam_Hanging_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sEtecoonOam_Hanging_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sEtecoonOam_Hanging_Frame1,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_Hanging[5] = {
    [0] = {
        .pFrame = sEtecoonOam_Hanging_Frame0,
        .timer = 14
    },
    [1] = {
        .pFrame = sEtecoonOam_Hanging_Frame1,
        .timer = 14
    },
    [2] = {
        .pFrame = sEtecoonOam_Hanging_Frame2,
        .timer = 14
    },
    [3] = {
        .pFrame = sEtecoonOam_Hanging_Frame1,
        .timer = 14
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_HangingAndTurning[5] = {
    [0] = {
        .pFrame = sEtecoonOam_HangingAndTurning_Frame0,
        .timer = 14
    },
    [1] = {
        .pFrame = sEtecoonOam_HangingAndTurning_Frame1,
        .timer = 14
    },
    [2] = {
        .pFrame = sEtecoonOam_HangingAndTurning_Frame2,
        .timer = 14
    },
    [3] = {
        .pFrame = sEtecoonOam_HangingAndTurning_Frame1,
        .timer = 14
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_FallingFromTire[5] = {
    [0] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame4,
        .timer = 9
    },
    [1] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame2,
        .timer = 6
    },
    [2] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame1,
        .timer = 6
    },
    [3] = {
        .pFrame = sEtecoonOam_JumpingOnGlass_Frame0,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTireSwingOam_Idle[2] = {
    [0] = {
        .pFrame = sTireSwingOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTireSwingOam_Bobbing_Fast[4] = {
    [0] = {
        .pFrame = sTireSwingOam_Idle_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sTireSwingOam_Bobbing_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sTireSwingOam_Idle_Frame0,
        .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTireSwingOam_Bobbing_Slow[4] = {
    [0] = {
        .pFrame = sTireSwingOam_Idle_Frame0,
        .timer = 28
    },
    [1] = {
        .pFrame = sTireSwingOam_Bobbing_Frame1,
        .timer = 14
    },
    [2] = {
        .pFrame = sTireSwingOam_Idle_Frame0,
        .timer = 14
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTireSwingOam_EtecoonLeaving[10] = {
    [0] = {
        .pFrame = sTireSwingOam_EtecoonLeaving_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sTireSwingOam_EtecoonLeaving_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sTireSwingOam_EtecoonLeaving_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sTireSwingOam_EtecoonLeaving_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sTireSwingOam_EtecoonLeaving_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sTireSwingOam_Idle_Frame0,
        .timer = 8
    },
    [6] = {
        .pFrame = sTireSwingOam_Bobbing_Frame1,
        .timer = 10
    },
    [7] = {
        .pFrame = sTireSwingOam_Idle_Frame0,
        .timer = 12
    },
    [8] = {
        .pFrame = sTireSwingOam_Bobbing_Frame1,
        .timer = 16
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDachoraOam_Standing[2] = {
    [0] = {
        .pFrame = sDachoraOam_Standing_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDachoraOam_Running[7] = {
    [0] = {
        .pFrame = sDachoraOam_Running_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sDachoraOam_Running_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sDachoraOam_Running_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sDachoraOam_Running_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sDachoraOam_Running_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sDachoraOam_Running_Frame5,
        .timer = 5
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDachoraOam_Turning_Start[3] = {
    [0] = {
        .pFrame = sDachoraOam_Turning_Start_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sDachoraOam_Turning_Start_Frame1,
        .timer = 5
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDachoraOam_Turning_End[3] = {
    [0] = {
        .pFrame = sDachoraOam_Turning_Start_Frame1,
        .timer = 5
    },
    [1] = {
        .pFrame = sDachoraOam_Turning_Start_Frame0,
        .timer = 5
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDachoraOam_Bowing[8] = {
    [0] = {
        .pFrame = sDachoraOam_Bowing_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sDachoraOam_Bowing_Frame1,
        .timer = 7
    },
    [2] = {
        .pFrame = sDachoraOam_Bowing_Frame2,
        .timer = 7
    },
    [3] = {
        .pFrame = sDachoraOam_Bowing_Frame3,
        .timer = 7
    },
    [4] = {
        .pFrame = sDachoraOam_Bowing_Frame2,
        .timer = 7
    },
    [5] = {
        .pFrame = sDachoraOam_Bowing_Frame1,
        .timer = 7
    },
    [6] = {
        .pFrame = sDachoraOam_Bowing_Frame0,
        .timer = 10
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDachoraOam_Blinking[4] = {
    [0] = {
        .pFrame = sDachoraOam_Blinking_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sDachoraOam_Blinking_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sDachoraOam_Blinking_Frame0,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDachoraOam_TiltingHead[3] = {
    [0] = {
        .pFrame = sDachoraOam_TiltingHead_Frame0,
        .timer = 14
    },
    [1] = {
        .pFrame = sDachoraOam_TiltingHead_Frame1,
        .timer = 8
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDachoraOam_TurningHead[4] = {
    [0] = {
        .pFrame = sDachoraOam_TurningHead_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sDachoraOam_TurningHead_Frame1,
        .timer = 30
    },
    [2] = {
        .pFrame = sDachoraOam_TurningHead_Frame0,
        .timer = 8
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBabyDachoraOam_Standing[2] = {
    [0] = {
        .pFrame = sBabyDachoraOam_Standing_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBabyDachoraOam_Walking[5] = {
    [0] = {
        .pFrame = sBabyDachoraOam_Standing_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sBabyDachoraOam_Walking_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sBabyDachoraOam_Walking_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sBabyDachoraOam_Walking_Frame3,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBabyDachoraOam_Blinking[4] = {
    [0] = {
        .pFrame = sBabyDachoraOam_Blinking_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sBabyDachoraOam_Blinking_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sBabyDachoraOam_Blinking_Frame0,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHabitationGateLightOam_Idle[2] = {
    [0] = {
        .pFrame = sHabitationGateLightOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHabitationGateOam_Idle[2] = {
    [0] = {
        .pFrame = sHabitationGateOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHabitationGateOam_Opening[7] = {
    [0] = {
        .pFrame = sHabitationGateOam_Opening_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sHabitationGateOam_Opening_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sHabitationGateOam_Opening_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sHabitationGateOam_Opening_Frame3,
        .timer = 10
    },
    [4] = {
        .pFrame = sHabitationGateOam_Opening_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sHabitationGateOam_Opening_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDachoraOam_Waiting[5] = {
    [0] = {
        .pFrame = sDachoraOam_Standing_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sDachoraOam_Waiting_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sDachoraOam_Waiting_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sDachoraOam_Waiting_Frame1,
        .timer = 20
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBabyDachoraOam_Waiting[5] = {
    [0] = {
        .pFrame = sBabyDachoraOam_Standing_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sBabyDachoraOam_Waiting_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sBabyDachoraOam_Waiting_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sBabyDachoraOam_Waiting_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEtecoonOam_Waiting[5] = {
    [0] = {
        .pFrame = sEtecoonOam_Standing_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sEtecoonOam_Waiting_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sEtecoonOam_Waiting_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sEtecoonOam_Waiting_Frame1,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHabitationGateLightOam_Flashing[3] = {
    [0] = {
        .pFrame = sHabitationGateLightOam_Idle_Frame0,
        .timer = 32
    },
    [1] = {
        .pFrame = sHabitationGateLightOam_Flashing_Frame1,
        .timer = 32
    },
    [2] = FRAME_DATA_TERMINATOR
};
