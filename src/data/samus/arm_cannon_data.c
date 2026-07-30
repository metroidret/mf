#include "data/samus/arm_cannon_data.h"
#include "oam.h"
#include "macros.h"
#include "constants/samus.h"
#include "structs/samus.h"
#include "data/samus/samus_empty_data.h"

static const u16 sArmCannonOam_Running_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-32, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Left_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_2899e4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Left_Frame5[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Left_Frame6[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Left_Frame7[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-36, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-20, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289a34[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289a48[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-17, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-1, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Left_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Left_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-18, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-2, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289ac0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-18, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-2, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Left_Frame6[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Left_Frame7[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-21, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-5, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Left_Frame8[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-21, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-5, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289b10[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-31, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-15, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289b4c[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289b74[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-31, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-15, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Left_Frame5[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-32, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289b9c[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Left_Frame7[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Left_Frame8[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289bd8[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-32, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Standing_Up_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289c00[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289c14[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Shooting_Up_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Standing_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-36, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-20, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Standing_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-36, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-20, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Standing_DiagonalUp_Left_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-36, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-20, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Shooting_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Standing_None_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289ca0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289cb4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Shooting_None_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-18, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-2, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Standing_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289cf0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289d04[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Shooting_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_Up_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_Up_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_None_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_None_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-17, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-1, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(0, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(16, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(0, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Standing_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(3, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(19, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Right_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(3, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(19, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289e1c[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Right_Frame5[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Right_Frame6[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalUp_Right_Frame7[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(4, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289e6c[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(3, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(19, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289e80[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-15, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(1, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Right_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Right_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Right_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-14, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(2, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289ef8[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-14, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(2, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Right_Frame6[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Right_Frame7[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(5, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(5, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_Forward_Right_Frame8[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289f48[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-1, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(15, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-1, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289f84[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Right_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Right_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(0, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(16, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289fc0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(0, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(16, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_289fd4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Right_Frame7[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Right_Frame8[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Running_DiagonalDown_Right_Frame9[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Standing_Up_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28a032[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28a040[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Shooting_Up_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -47, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28a05c[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(4, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28a070[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(4, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28a084[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(4, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Shooting_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
#ifdef BUGFIX
    OAM_ENTRY(2, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
#else // !BUGFIX
    OAM_ENTRY(3, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(19, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
#endif // BUGFIX
};

static const u16 sArmCannonOam_Standing_None_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28a0c0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28a0d4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Shooting_None_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Standing_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(3, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(19, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28a110[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(3, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(19, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28a124[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(3, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(19, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Shooting_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_Up_Right_Frame1[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -39, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-4, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_Up_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -38, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-4, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_DiagonalUp_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_None_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_None_Right_Frame0[OAM_DATA_SIZE(3)] = {
#ifdef BUGFIX
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
#endif // BUGFIX
    OAM_ENTRY(1, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5f, 1, 0),
#ifndef BUGFIX
    0
#endif // !BUGFIX
};

static const u16 sArmCannonOam_ShootingAndCrouching_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(3, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(19, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingAndCrouching_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const s16 sArmCannonOffset_Running_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-7)
};

static const s16 sArmCannonOffset_Running_None_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(-9)
};

static const s16 sArmCannonOffset_Running_None_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-28),
    [ACO_X] = C_S9_2_S16(-12)
};

static const s16 sArmCannonOffset_Running_None_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-25),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_Running_None_Left_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(-9)
};

#ifdef BUGFIX
static const s16 sArmCannonOffset_Running_None_Left_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(-3)
};
#endif // BUGFIX

static const s16 sArmCannonOffset_Running_None_Left_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(3)
};

static const s16 sArmCannonOffset_Running_None_Left_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(0)
};

static const s16 sArmCannonOffset_Running_None_Left_Frame8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(-2)
};

static const s16 sArmCannonOffset_Running_None_Left_Frame9[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-34),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Standing_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Left_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-34),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Left_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Left_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-19)
};

static const s16 sArmCannonOffset_Running_Forward_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_Running_Forward_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_Running_Forward_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_Running_Forward_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_Running_Forward_Left_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Running_Forward_Left_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_Running_Forward_Left_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(-19)
};

static const s16 sArmCannonOffset_Running_Forward_Left_Frame8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(-19)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(-13)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Left_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(-14)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Left_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Left_Frame8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Standing_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-46),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_Shooting_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-45),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_Shooting_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_Standing_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_Shooting_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Standing_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_Shooting_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-14),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_Up_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(-4)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_DiagonalUp_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-29),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-29),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_None_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_DiagonalDown_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-3),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-4),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(11)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(-2)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(9)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(10)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-26),
    [ACO_X] = C_S9_2_S16(12)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-30),
    [ACO_X] = C_S9_2_S16(14)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-30),
    [ACO_X] = C_S9_2_S16(13)
};

static const s16 sArmCannonOffset_Running_None_Right_Frame9[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-25),
    [ACO_X] = C_S9_2_S16(13)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-34),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Standing_DiagonalUp_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Right_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-34),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Right_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Running_DiagonalUp_Right_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(19)
};

static const s16 sArmCannonOffset_Running_Forward_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_Running_Forward_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Running_Forward_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_Running_Forward_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_Running_Forward_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Running_Forward_Right_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Running_Forward_Right_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(19)
};

static const s16 sArmCannonOffset_Running_Forward_Right_Frame8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(19)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(13)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(14)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Right_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Right_Frame8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Running_DiagonalDown_Right_Frame9[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_Standing_Up_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-46),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_Shooting_Up_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-45),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_Shooting_DiagonalUp_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Standing_None_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_Shooting_None_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Standing_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Shooting_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_Up_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(4)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_Up_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-36),
    [ACO_X] = C_S9_2_S16(4)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_DiagonalUp_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-29),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_DiagonalUp_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-29),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_None_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_None_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_DiagonalDown_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-3),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_ShootingAndCrouching_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-4),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Skidding_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-28),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_28a7bc_Frame23[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(-10)
};

static const s16 sArmCannonOffset_28a7bc_Frame28[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(-1)
};

static const s16 sArmCannonOffset_Unused_28a35c[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-14),
    [ACO_X] = C_S9_2_S16(6)
};

static const s16 sArmCannonOffset_Skidding_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-26),
    [ACO_X] = C_S9_2_S16(13)
};

static const s16 sArmCannonOffset_HitByOmegaMetroid_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-3),
    [ACO_X] = C_S9_2_S16(-12)
};

static const s16 sArmCannonOffset_HitByOmegaMetroid_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-3),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_HitByOmegaMetroid_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-3),
    [ACO_X] = C_S9_2_S16(-10)
};

static const s16 sArmCannonOffset_HitByOmegaMetroid_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-6),
    [ACO_X] = C_S9_2_S16(3)
};

static const s16 sArmCannonOffset_HitByOmegaMetroid_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-4),
    [ACO_X] = C_S9_2_S16(0)
};

static const s16 sArmCannonOffset_HitByOmegaMetroid_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-4),
    [ACO_X] = C_S9_2_S16(-2)
};

const struct ArmCannonAnimData sArmCannonAnim_Running_None_Left[10] = {
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
#ifdef BUGFIX
        .pOffset = sArmCannonOffset_Running_None_Left_Frame5,
#else // !BUGFIX
        .pOffset = sArmCannonOffset_Empty,
#endif // BUGFIX
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame7,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame8,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame9,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Running_DiagonalUp_Left[10] = {
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Left_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame2
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Left_Frame3,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Left_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Left_Frame5,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame5
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Left_Frame6,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame6
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Left_Frame7,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame7
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Left_Frame3,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Left_Frame6,
        .pOam = sArmCannonOam_Running_DiagonalUp_Left_Frame6
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Running_Forward_Left[10] = {
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame0,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame1,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame2,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame2
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame3,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame4,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame4,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame6,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame6
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame7,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame7
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame8,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame8
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Left_Frame6,
        .pOam = sArmCannonOam_Running_Forward_Left_Frame6
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Running_DiagonalDown_Left[10] = {
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame3,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame5,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame5
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame7,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame7
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame8,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame8
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Left_Frame5,
        .pOam = sArmCannonOam_Running_DiagonalDown_Left_Frame5
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Standing_Up_Left[3] = {
    {
        .pOffset = sArmCannonOffset_Standing_Up_Left_Frame0,
        .pOam = sArmCannonOam_Standing_Up_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_Up_Left_Frame0,
        .pOam = sArmCannonOam_Standing_Up_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_Up_Left_Frame0,
        .pOam = sArmCannonOam_Standing_Up_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shooting_Up_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Shooting_Up_Left_Frame0,
        .pOam = sArmCannonOam_Shooting_Up_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_Up_Left_Frame0,
        .pOam = sArmCannonOam_Standing_Up_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Standing_DiagonalUp_Left[3] = {
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalUp_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalUp_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalUp_Left_Frame2
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shooting_DiagonalUp_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Shooting_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_Shooting_DiagonalUp_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalUp_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Standing_None_Left[3] = {
    {
        .pOffset = sArmCannonOffset_Standing_None_Left_Frame0,
        .pOam = sArmCannonOam_Standing_None_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_None_Left_Frame0,
        .pOam = sArmCannonOam_Standing_None_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_None_Left_Frame0,
        .pOam = sArmCannonOam_Standing_None_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shooting_None_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Shooting_None_Left_Frame0,
        .pOam = sArmCannonOam_Shooting_None_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_None_Left_Frame0,
        .pOam = sArmCannonOam_Standing_None_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Standing_DiagonalDown_Left[3] = {
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalDown_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shooting_DiagonalDown_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Shooting_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_Shooting_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalDown_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingAndCrouching_Up_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_Up_Left_Frame0,
        .pOam = sArmCannonOam_ShootingAndCrouching_Up_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_Up_Left_Frame1,
        .pOam = sArmCannonOam_ShootingAndCrouching_Up_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingAndCrouching_DiagonalUp_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_ShootingAndCrouching_DiagonalUp_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_DiagonalUp_Left_Frame1,
        .pOam = sArmCannonOam_ShootingAndCrouching_DiagonalUp_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingAndCrouching_None_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_None_Left_Frame0,
        .pOam = sArmCannonOam_ShootingAndCrouching_None_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_None_Left_Frame1,
        .pOam = sArmCannonOam_ShootingAndCrouching_None_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingAndCrouching_DiagonalDown_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_ShootingAndCrouching_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_DiagonalDown_Left_Frame1,
        .pOam = sArmCannonOam_ShootingAndCrouching_DiagonalDown_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Running_None_Right[10] = {
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame7,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame8,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame9,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Running_DiagonalUp_Right[10] = {
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_Running_DiagonalUp_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Right_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalUp_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalUp_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Right_Frame3,
        .pOam = sArmCannonOam_Running_DiagonalUp_Right_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Right_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalUp_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Right_Frame5,
        .pOam = sArmCannonOam_Running_DiagonalUp_Right_Frame5
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Right_Frame6,
        .pOam = sArmCannonOam_Running_DiagonalUp_Right_Frame6
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Right_Frame7,
        .pOam = sArmCannonOam_Running_DiagonalUp_Right_Frame7
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Right_Frame3,
        .pOam = sArmCannonOam_Running_DiagonalUp_Right_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalUp_Right_Frame6,
        .pOam = sArmCannonOam_Running_DiagonalUp_Right_Frame6
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Running_Forward_Right[10] = {
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame0,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame1,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame2,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame2
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame3,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame4,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame4,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame6,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame6
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame7,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame7
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame8,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame8
    },
    {
        .pOffset = sArmCannonOffset_Running_Forward_Right_Frame6,
        .pOam = sArmCannonOam_Running_Forward_Right_Frame6
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Running_DiagonalDown_Right[10] = {
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame3,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame4,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame4,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame1,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame7,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame7
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame8,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame8
    },
    {
        .pOffset = sArmCannonOffset_Running_DiagonalDown_Right_Frame9,
        .pOam = sArmCannonOam_Running_DiagonalDown_Right_Frame9
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Standing_Up_Right[3] = {
    {
        .pOffset = sArmCannonOffset_Standing_Up_Right_Frame0,
        .pOam = sArmCannonOam_Standing_Up_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_Up_Right_Frame0,
        .pOam = sArmCannonOam_Standing_Up_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_Up_Right_Frame0,
        .pOam = sArmCannonOam_Standing_Up_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shooting_Up_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Shooting_Up_Right_Frame0,
        .pOam = sArmCannonOam_Shooting_Up_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_Up_Right_Frame0,
        .pOam = sArmCannonOam_Standing_Up_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Standing_DiagonalUp_Right[3] = {
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalUp_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalUp_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalUp_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shooting_DiagonalUp_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Shooting_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_Shooting_DiagonalUp_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalUp_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Standing_None_Right[3] = {
    {
        .pOffset = sArmCannonOffset_Standing_None_Right_Frame0,
        .pOam = sArmCannonOam_Standing_None_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_None_Right_Frame0,
        .pOam = sArmCannonOam_Standing_None_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_None_Right_Frame0,
        .pOam = sArmCannonOam_Standing_None_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shooting_None_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Shooting_None_Right_Frame0,
        .pOam = sArmCannonOam_Shooting_None_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_None_Right_Frame0,
        .pOam = sArmCannonOam_Standing_None_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Standing_DiagonalDown_Right[3] = {
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalDown_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shooting_DiagonalDown_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Shooting_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_Shooting_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Standing_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_Standing_DiagonalDown_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingAndCrouching_Up_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_Up_Right_Frame0,
        .pOam = sArmCannonOam_ShootingAndCrouching_Up_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_Up_Right_Frame1,
        .pOam = sArmCannonOam_ShootingAndCrouching_Up_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingAndCrouching_DiagonalUp_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_ShootingAndCrouching_DiagonalUp_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_DiagonalUp_Right_Frame1,
        .pOam = sArmCannonOam_ShootingAndCrouching_DiagonalUp_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingAndCrouching_None_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_None_Right_Frame0,
        .pOam = sArmCannonOam_ShootingAndCrouching_None_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_None_Right_Frame1,
        .pOam = sArmCannonOam_ShootingAndCrouching_None_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingAndCrouching_DiagonalDown_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_ShootingAndCrouching_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingAndCrouching_DiagonalDown_Right_Frame1,
        .pOam = sArmCannonOam_ShootingAndCrouching_DiagonalDown_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Unused_28a7bc[40] = {
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame7,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame8,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame9,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame7,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame8,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame9,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_28a7bc_Frame23,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame7,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_28a7bc_Frame28,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Left_Frame9,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame7,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame8,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Running_None_Right_Frame9,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Skidding_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Skidding_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Skidding_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Skidding_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Skidding_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Skidding_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_HitByOmegaMetroid_Left[8] = {
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_HitByOmegaMetroid_Right[8] = {
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HitByOmegaMetroid_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
};

static const u16 sArmCannonOam_Frame_Unused_28a99c[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Up_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Up_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Up_Left_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Up_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Up_Left_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_Up_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28aa50[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Left_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Left_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28aac8[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Left_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-18, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-2, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Left_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Left_Frame5[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_Forward_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-18, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_Forward_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28ab7c[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Left_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Left_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Left_Frame5[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-33, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28ac30[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalDown_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-36, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-20, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalDown_Left_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-17, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-1, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28ac6c[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-34, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-18, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Down_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28ac94[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28aca8[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -49, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Up_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -50, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Up_Right_Frame1[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -46, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Up_Right_Frame2[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -41, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_Up_Right_Frame1[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -45, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Up_Right_Frame4[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28acfc[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_Up_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-10, -41, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-2, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28ad18[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -45, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-14, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(3, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-13, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28ad4e[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-14, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Right_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Right_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-14, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Right_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-14, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalUp_Right_Frame5[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-14, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalUp_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-14, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28adda[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Right_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-14, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(2, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Right_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Right_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Forward_Right_Frame5[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_Forward_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-14, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(2, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_Forward_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28ae8e[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28aeb6[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Right_Frame2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Right_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Right_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_DiagonalDown_Right_Frame5[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(1, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(17, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28af42[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -45, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalDown_Right_Frame3[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(4, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Landing_DiagonalDown_Right_Frame4[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-15, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(1, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28af78[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_MidAir_Down_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28af9a[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-11, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const s16 sArmCannonOffset_DelayBeforeShinesparking_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-25),
    [ACO_X] = C_S9_2_S16(-10)
};

static const s16 sArmCannonOffset_MidAir_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(-14)
};

static const s16 sArmCannonOffset_MidAir_None_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-13)
};

static const s16 sArmCannonOffset_MidAir_None_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(-12)
};

static const s16 sArmCannonOffset_MidAir_None_Left_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(-12)
};

static const s16 sArmCannonOffset_MidAir_None_Left_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-12)
};

static const s16 sArmCannonOffset_Landing_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_Spinning_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_Unused_28afc8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-47),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_MidAir_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-42),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_Unused_28afd0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-44),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_MidAir_Up_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-40),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_Landing_Up_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-43),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_Unused_28afdc[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-46),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_Landing_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-39),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-36),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-30),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-34),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Left_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Landing_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-28),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_Landing_DiagonalUp_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-32),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Unused_28b000[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_MidAir_Forward_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_MidAir_Forward_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_MidAir_Forward_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-18),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_MidAir_Forward_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_MidAir_Forward_Left_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_MidAir_Forward_Left_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_Landing_Forward_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Landing_Forward_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-19),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_Unused_28b024[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_MidAir_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_MidAir_DiagonalDown_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_MidAir_DiagonalDown_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Landing_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_Landing_DiagonalDown_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(-16)
};

static const s16 sArmCannonOffset_Landing_DiagonalDown_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-36),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_Landing_DiagonalDown_Left_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-20),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_MidAir_Down_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-2),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_DelayBeforeShinesparking_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(10)
};

static const s16 sArmCannonOffset_MidAir_None_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(13)
};

static const s16 sArmCannonOffset_MidAir_None_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-20),
    [ACO_X] = C_S9_2_S16(11)
};

static const s16 sArmCannonOffset_MidAir_None_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(11)
};

static const s16 sArmCannonOffset_MidAir_None_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(11)
};

static const s16 sArmCannonOffset_MidAir_None_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-18),
    [ACO_X] = C_S9_2_S16(12)
};

static const s16 sArmCannonOffset_MidAir_None_Right_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(12)
};

static const s16 sArmCannonOffset_Landing_None_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(11)
};

static const s16 sArmCannonOffset_Unused_28b068[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-47),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_MidAir_Up_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-42),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_Unused_28b070[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-44),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_MidAir_Up_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-39),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_Landing_Up_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-43),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_Unused_28b07c[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-46),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_Landing_Up_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-39),
    [ACO_X] = C_S9_2_S16(6)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-36),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-30),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-34),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_MidAir_DiagonalUp_Right_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-39),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Landing_DiagonalUp_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-28),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_Landing_DiagonalUp_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-32),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Unused_28b0a4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-22),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_MidAir_Forward_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_MidAir_Forward_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_MidAir_Forward_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-18),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_MidAir_Forward_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_MidAir_Forward_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_MidAir_Forward_Right_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_Landing_Forward_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Landing_Forward_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-19),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Unused_28b0c8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_MidAir_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_MidAir_DiagonalDown_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_MidAir_DiagonalDown_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Landing_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_Landing_DiagonalDown_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_Landing_DiagonalDown_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-36),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_Landing_DiagonalDown_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-20),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_MidAir_Down_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-2),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_Spinning_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-3),
    [ACO_X] = C_S9_2_S16(0)
};

static const s16 sArmCannonOffset_Spinning_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-7),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_Spinning_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(10)
};

static const s16 sArmCannonOffset_Spinning_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-19),
    [ACO_X] = C_S9_2_S16(6)
};

static const s16 sArmCannonOffset_Spinning_Left_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(0)
};

static const s16 sArmCannonOffset_Spinning_Left_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-20),
    [ACO_X] = C_S9_2_S16(-7)
};

static const s16 sArmCannonOffset_Spinning_Left_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-14),
    [ACO_X] = C_S9_2_S16(-10)
};

static const s16 sArmCannonOffset_Spinning_Left_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(-6)
};

static const s16 sArmCannonOffset_Spinning_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-3),
    [ACO_X] = C_S9_2_S16(3)
};

static const s16 sArmCannonOffset_Spinning_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-6),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_Spinning_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_Spinning_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-23),
    [ACO_X] = C_S9_2_S16(-3)
};

static const s16 sArmCannonOffset_Spinning_Right_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(8)
};

static const s16 sArmCannonOffset_Spinning_Right_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(10)
};

static const s16 sArmCannonOffset_Spinning_Right_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-5),
    [ACO_X] = C_S9_2_S16(8)
};

static const s16 sArmCannonOffset_StartingSpinJump_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-11),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_Shinesparking_Upwards_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-18),
    [ACO_X] = C_S9_2_S16(-4)
};

static const s16 sArmCannonOffset_Shinesparking_Upwards_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-19),
    [ACO_X] = C_S9_2_S16(-2)
};

static const s16 sArmCannonOffset_Shinesparking_Upwards_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(-2)
};

static const s16 sArmCannonOffset_Shinesparking_Upwards_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-20),
    [ACO_X] = C_S9_2_S16(-6)
};

static const s16 sArmCannonOffset_Shinesparking_Sideways_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_Shinesparking_Sideways_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_Shinesparking_Sideways_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-10)
};

static const s16 sArmCannonOffset_Shinesparking_Sideways_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-26),
    [ACO_X] = C_S9_2_S16(-13)
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_None_Left[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Left_Frame5,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_None_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Landing_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_Up_Left[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Up_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Up_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Left_Frame2,
        .pOam = sArmCannonOam_MidAir_Up_Left_Frame2
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Up_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Up_Left_Frame4
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Up_Left_Frame4
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_Up_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Landing_Up_Left_Frame0,
        .pOam = sArmCannonOam_Landing_Up_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Landing_Up_Left_Frame1,
        .pOam = sArmCannonOam_MidAir_Up_Left_Frame3
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_DiagonalUp_Left[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Left_Frame1,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Left_Frame2,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Left_Frame2
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Left_Frame3,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Left_Frame4,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Left_Frame4
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Left_Frame4,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Left_Frame4
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_DiagonalUp_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_Landing_DiagonalUp_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalUp_Left_Frame1,
        .pOam = sArmCannonOam_Landing_DiagonalUp_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_Forward_Left[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Forward_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Left_Frame1,
        .pOam = sArmCannonOam_MidAir_Forward_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Left_Frame2,
        .pOam = sArmCannonOam_MidAir_Forward_Left_Frame2
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Left_Frame3,
        .pOam = sArmCannonOam_MidAir_Forward_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Left_Frame4,
        .pOam = sArmCannonOam_MidAir_Forward_Left_Frame4
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Left_Frame5,
        .pOam = sArmCannonOam_MidAir_Forward_Left_Frame5
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_Forward_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Landing_Forward_Left_Frame0,
        .pOam = sArmCannonOam_Landing_Forward_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Landing_Forward_Left_Frame1,
        .pOam = sArmCannonOam_Landing_Forward_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_DiagonalDown_Left[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalDown_Left_Frame2,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Left_Frame2
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalDown_Left_Frame3,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Left_Frame2,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Left_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Landing_Forward_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Left_Frame5
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_DiagonalDown_Left[7] = {
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Left_Frame1,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Landing_Up_Left_Frame1,
        .pOam = sArmCannonOam_MidAir_Up_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Left_Frame3,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Left_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Left_Frame4,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Left_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Left_Frame1,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Left_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_None_Right[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_None_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_None_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Landing_None_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Landing_None_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_Up_Right[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Up_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Up_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Right_Frame2,
        .pOam = sArmCannonOam_MidAir_Up_Right_Frame2
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Right_Frame0,
        .pOam = sArmCannonOam_Landing_Up_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Up_Right_Frame4
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Up_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Up_Right_Frame4
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_Up_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Landing_Up_Right_Frame0,
        .pOam = sArmCannonOam_Landing_Up_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Landing_Up_Right_Frame1,
        .pOam = sArmCannonOam_Landing_Up_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_DiagonalUp_Right[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Right_Frame1,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Right_Frame2,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Right_Frame2
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Right_Frame3,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Right_Frame3
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Right_Frame4,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Right_Frame4
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalUp_Right_Frame5,
        .pOam = sArmCannonOam_MidAir_DiagonalUp_Right_Frame5
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_DiagonalUp_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_Landing_DiagonalUp_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalUp_Right_Frame1,
        .pOam = sArmCannonOam_Landing_DiagonalUp_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_Forward_Right[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Forward_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Right_Frame1,
        .pOam = sArmCannonOam_MidAir_Forward_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Right_Frame2,
        .pOam = sArmCannonOam_MidAir_Forward_Right_Frame2
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Right_Frame3,
        .pOam = sArmCannonOam_MidAir_Forward_Right_Frame3
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Right_Frame4,
        .pOam = sArmCannonOam_MidAir_Forward_Right_Frame4
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Right_Frame5,
        .pOam = sArmCannonOam_MidAir_Forward_Right_Frame5
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_Forward_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Landing_Forward_Right_Frame0,
        .pOam = sArmCannonOam_Landing_Forward_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Landing_Forward_Right_Frame1,
        .pOam = sArmCannonOam_Landing_Forward_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_DiagonalDown_Right[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalDown_Right_Frame2,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Right_Frame2
    },
    {
        .pOffset = sArmCannonOffset_MidAir_DiagonalDown_Right_Frame3,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Right_Frame3
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Forward_Right_Frame2,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Right_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Landing_Forward_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_DiagonalDown_Right_Frame5
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Landing_DiagonalDown_Right[7] = {
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Right_Frame1,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Landing_Up_Right_Frame1,
        .pOam = sArmCannonOam_Landing_Up_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Right_Frame3,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Right_Frame3
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Right_Frame4,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Right_Frame4
    },
    {
        .pOffset = sArmCannonOffset_Landing_DiagonalDown_Right_Frame1,
        .pOam = sArmCannonOam_Landing_DiagonalDown_Right_Frame1
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_Down_Left[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Left_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MidAir_Down_Right[6] = {
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_MidAir_Down_Right_Frame0,
        .pOam = sArmCannonOam_MidAir_Down_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Spinning_Left[8] = {
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame7,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Spinning_Right[8] = {
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame7,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_StartingSpinJump_Left[1] = {
    {
        .pOffset = sArmCannonOffset_StartingSpinJump_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_StartingSpinJump_Right[1] = {
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame7,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_DelayBeforeShinesparking_Left[4] = {
    {
        .pOffset = sArmCannonOffset_DelayBeforeShinesparking_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shinesparking_Upwards_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Shinesparking_Upwards_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Shinesparking_Upwards_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_DelayBeforeShinesparking_Right[4] = {
    {
        .pOffset = sArmCannonOffset_DelayBeforeShinesparking_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MidAir_None_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shinesparking_Upwards_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Shinesparking_Upwards_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Shinesparking_Upwards_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shinesparking_Sideways_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Shinesparking_Sideways_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Shinesparking_Sideways_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Shinesparking_Sideways_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Shinesparking_Sideways_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Shinesparking_Sideways_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_DelayAfterShinesparking_Upwards_Left[9] = {
    {
        .pOffset = sArmCannonOffset_Shinesparking_Upwards_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame7,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_DelayAfterShinesparking_Upwards_Right[9] = {
    {
        .pOffset = sArmCannonOffset_Shinesparking_Upwards_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame7,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_DelayAfterShinesparking_Sideways_Left[9] = {
    {
        .pOffset = sArmCannonOffset_Shinesparking_Sideways_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Left_Frame7,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_DelayAfterShinesparking_Sideways_Right[9] = {
    {
        .pOffset = sArmCannonOffset_Shinesparking_Sideways_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Spinning_Right_Frame7,
        .pOam = sSamusOam_Empty
    },
};

static const u16 sArmCannonOam_Crouching_Up_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Crouching_Up_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -39, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-4, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Crouching_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Crouching_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(2, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(18, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Crouching_Forward_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Crouching_Forward_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Crouching_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-35, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-19, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Crouching_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(3, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(19, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_BeingRecharged_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28b75a[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28b76e[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28b782[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28b796[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_BeingRecharged_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28b7be[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28b7d2[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28b7e6[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Frame_Unused_28b7fa[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(4, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const s16 sArmCannonOffset_Unused_28b80e[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-46),
    [ACO_X] = C_S9_2_S16(-5)
};

static const s16 sArmCannonOffset_Turning_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-46),
    [ACO_X] = C_S9_2_S16(-3)
};

static const s16 sArmCannonOffset_Turning_Up_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-46),
    [ACO_X] = C_S9_2_S16(3)
};

static const s16 sArmCannonOffset_Unused_28b81a[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-46),
    [ACO_X] = C_S9_2_S16(5)
};

static const s16 sArmCannonOffset_Unused_28b81e[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_Turning_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_Turning_DiagonalUp_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(8)
};

static const s16 sArmCannonOffset_Unused_28b82a[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_Unused_28b82e[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_Turning_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-10)
};

static const s16 sArmCannonOffset_Turning_None_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(6)
};

static const s16 sArmCannonOffset_Unused_28b83a[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Crouching_Forward_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_Turning_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-14),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_Turning_DiagonalDown_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-14),
    [ACO_X] = C_S9_2_S16(2)
};

static const s16 sArmCannonOffset_Unused_28b84a[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Crouching_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(-4)
};

static const s16 sArmCannonOffset_TurningAndCrouching_Up_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(-3)
};

static const s16 sArmCannonOffset_Crouching_Up_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(4)
};

static const s16 sArmCannonOffset_Crouching_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-29),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_TurningAndCrouching_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-27),
    [ACO_X] = C_S9_2_S16(-10)
};

static const s16 sArmCannonOffset_TurningAndCrouching_DiagonalUp_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-27),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_Crouching_DiagonalUp_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-29),
    [ACO_X] = C_S9_2_S16(16)
};

static const s16 sArmCannonOffset_TurningAndCrouching_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_TurningAndCrouching_None_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(6)
};

static const s16 sArmCannonOffset_Crouching_Forward_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_Crouching_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-3),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_TurningAndCrouching_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-4),
    [ACO_X] = C_S9_2_S16(-12)
};

static const s16 sArmCannonOffset_TurningAndCrouching_DiagonalDown_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-4),
    [ACO_X] = C_S9_2_S16(2)
};

static const s16 sArmCannonOffset_Crouching_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-3),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_TurningMidAir_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-42),
    [ACO_X] = C_S9_2_S16(-3)
};

static const s16 sArmCannonOffset_TurningMidAir_Up_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-42),
    [ACO_X] = C_S9_2_S16(3)
};

static const s16 sArmCannonOffset_TurningMidAir_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-31),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_TurningMidAir_DiagonalUp_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-31),
    [ACO_X] = C_S9_2_S16(8)
};

static const s16 sArmCannonOffset_TurningMidAir_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(-10)
};

static const s16 sArmCannonOffset_TurningMidAir_None_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(6)
};

static const s16 sArmCannonOffset_TurningMidAir_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_TurningMidAir_DiagonalDown_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(2)
};

static const s16 sArmCannonOffset_Unused_28b8a6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(-13)
};

static const s16 sArmCannonOffset_Unused_28b8aa[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(13)
};

static const s16 sArmCannonOffset_Unmorphing_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-6),
    [ACO_X] = C_S9_2_S16(2)
};

static const s16 sArmCannonOffset_Morphing_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-7),
    [ACO_X] = C_S9_2_S16(2)
};

static const s16 sArmCannonOffset_Morphing_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-9),
    [ACO_X] = C_S9_2_S16(-1)
};

static const s16 sArmCannonOffset_MorphBall_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(0)
};

static const s16 sArmCannonOffset_MorphBall_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-9),
    [ACO_X] = C_S9_2_S16(0)
};

static const s16 sArmCannonOffset_MorphBall_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(0)
};

static const s16 sArmCannonOffset_Unmorphing_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-6),
    [ACO_X] = C_S9_2_S16(-2)
};

static const s16 sArmCannonOffset_Morphing_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-7),
    [ACO_X] = C_S9_2_S16(-2)
};

static const s16 sArmCannonOffset_Morphing_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-9),
    [ACO_X] = C_S9_2_S16(1)
};

static const s16 sArmCannonOffset_FacingForeground_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_FacingBackground_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(-1)
};

static const s16 sArmCannonOffset_FacingBackground_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(10)
};

static const s16 sArmCannonOffset_FacingBackground_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-18),
    [ACO_X] = C_S9_2_S16(9)
};

static const s16 sArmCannonOffset_UsingElevator_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-6)
};

static const s16 sArmCannonOffset_UsingElevator_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_UsingElevator_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(-7)
};

static const s16 sArmCannonOffset_UsingElevator_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(-3)
};

static const s16 sArmCannonOffset_BeingRecharged_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(-18)
};

static const s16 sArmCannonOffset_BeingRecharged_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-21),
    [ACO_X] = C_S9_2_S16(18)
};

static const s16 sArmCannonOffset_UnlockingHabitationsDeck_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(8)
};

static const s16 sArmCannonOffset_UnlockingHabitationsDeck_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(6)
};

static const s16 sArmCannonOffset_UnlockingHabitationsDeck_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-17),
    [ACO_X] = C_S9_2_S16(12)
};

const struct ArmCannonAnimData sArmCannonAnim_Turning_Up_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Turning_Up_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_Up_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Turning_Up_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Turning_Up_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_Up_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Turning_DiagonalUp_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Turning_DiagonalUp_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_DiagonalUp_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Turning_DiagonalUp_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Turning_DiagonalUp_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_DiagonalUp_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Turning_None_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Turning_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Turning_None_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Turning_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Turning_DiagonalDown_Left[2] = {
    {
        .pOffset = sArmCannonOffset_Turning_DiagonalDown_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_DiagonalDown_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Turning_DiagonalDown_Right[2] = {
    {
        .pOffset = sArmCannonOffset_Turning_DiagonalDown_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_DiagonalDown_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningAndCrouching_Up_Left[2] = {
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_Up_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_Up_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningAndCrouching_Up_Right[2] = {
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_Up_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_Up_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningAndCrouching_DiagonalUp_Left[2] = {
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_DiagonalUp_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_DiagonalUp_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningAndCrouching_DiagonalUp_Right[2] = {
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_DiagonalUp_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_DiagonalUp_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningAndCrouching_None_Left[2] = {
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningAndCrouching_None_Right[2] = {
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningAndCrouching_DiagonalDown_Left[2] = {
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_DiagonalDown_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_DiagonalDown_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningAndCrouching_DiagonalDown_Right[2] = {
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_DiagonalDown_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningAndCrouching_DiagonalDown_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningMidAir_Up_Left[2] = {
    {
        .pOffset = sArmCannonOffset_TurningMidAir_Up_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningMidAir_Up_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningMidAir_Up_Right[2] = {
    {
        .pOffset = sArmCannonOffset_TurningMidAir_Up_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningMidAir_Up_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningMidAir_DiagonalUp_Left[2] = {
    {
        .pOffset = sArmCannonOffset_TurningMidAir_DiagonalUp_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningMidAir_DiagonalUp_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningMidAir_DiagonalUp_Right[2] = {
    {
        .pOffset = sArmCannonOffset_TurningMidAir_DiagonalUp_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningMidAir_DiagonalUp_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningMidAir_None_Left[2] = {
    {
        .pOffset = sArmCannonOffset_TurningMidAir_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningMidAir_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningMidAir_None_Right[2] = {
    {
        .pOffset = sArmCannonOffset_TurningMidAir_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningMidAir_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningMidAir_DiagonalDown_Left[2] = {
    {
        .pOffset = sArmCannonOffset_TurningMidAir_DiagonalDown_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningMidAir_DiagonalDown_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningMidAir_DiagonalDown_Right[2] = {
    {
        .pOffset = sArmCannonOffset_TurningMidAir_DiagonalDown_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningMidAir_DiagonalDown_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Crouching_Up_Left[1] = {
    {
        .pOffset = sArmCannonOffset_Crouching_Up_Left_Frame0,
        .pOam = sArmCannonOam_Crouching_Up_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Crouching_Up_Right[1] = {
    {
        .pOffset = sArmCannonOffset_Crouching_Up_Right_Frame0,
        .pOam = sArmCannonOam_Crouching_Up_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Crouching_DiagonalUp_Left[1] = {
    {
        .pOffset = sArmCannonOffset_Crouching_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_Crouching_DiagonalUp_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Crouching_DiagonalUp_Right[1] = {
    {
        .pOffset = sArmCannonOffset_Crouching_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_Crouching_DiagonalUp_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Crouching_Forward_Left[1] = {
    {
        .pOffset = sArmCannonOffset_Crouching_Forward_Left_Frame0,
        .pOam = sArmCannonOam_Crouching_Forward_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Crouching_Forward_Right[1] = {
    {
        .pOffset = sArmCannonOffset_Crouching_Forward_Right_Frame0,
        .pOam = sArmCannonOam_Crouching_Forward_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Crouching_DiagonalDown_Left[1] = {
    {
        .pOffset = sArmCannonOffset_Crouching_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_Crouching_DiagonalDown_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Crouching_DiagonalDown_Right[1] = {
    {
        .pOffset = sArmCannonOffset_Crouching_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_Crouching_DiagonalDown_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Morphing_Left[3] = {
    {
        .pOffset = sArmCannonOffset_Morphing_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Morphing_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MorphBall_Left[8] = {
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Unmorphing_Left[3] = {
    {
        .pOffset = sArmCannonOffset_Morphing_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Morphing_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unmorphing_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Morphing_Right[3] = {
    {
        .pOffset = sArmCannonOffset_Morphing_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Morphing_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MorphBall_Right[8] = {
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MorphBall_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Unmorphing_Right[3] = {
    {
        .pOffset = sArmCannonOffset_Morphing_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Morphing_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unmorphing_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnSavePad_Left[4] = {
    {
        .pOffset = sArmCannonOffset_Turning_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnSavePad_Right[4] = {
    {
        .pOffset = sArmCannonOffset_Turning_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_FacingForeground_Left[4] = {
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_None_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_FacingForeground_Right[4] = {
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Turning_None_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnNavigationPad_Left[16] = {
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_FacingBackground_Left[4] = {
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnNavigationPad_Right[16] = {
    {
        .pOffset = sArmCannonOffset_FacingBackground_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_FacingBackground_Right[4] = {
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_UsingElevator_Left[5] = {
    {
        .pOffset = sArmCannonOffset_UsingElevator_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_UsingElevator_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_UsingElevator_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_UsingElevator_Frame2,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_UsingElevator_Right[5] = {
    {
        .pOffset = sArmCannonOffset_UsingElevator_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_UsingElevator_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_UsingElevator_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_UsingElevator_Frame2,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_DownloadingAbility_Left[16] = {
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_DownloadingAbility_Right[16] = {
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingForeground_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_BeingRecharged_Left[8] = {
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Left_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Left_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Left_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Left_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Left_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Left_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Left_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Left_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_BeingRecharged_Right[8] = {
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Right_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Right_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Right_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Right_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Right_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Right_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Right_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Right_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_UnlockingSecurity_Left[1] = {
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Left_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_UnlockingSecurity_Right[1] = {
    {
        .pOffset = sArmCannonOffset_BeingRecharged_Right_Frame0,
        .pOam = sArmCannonOam_BeingRecharged_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_UnlockingHabitationsDeck[6] = {
    {
        .pOffset = sArmCannonOffset_UnlockingHabitationsDeck_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_UnlockingHabitationsDeck_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_UnlockingHabitationsDeck_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_UnlockingHabitationsDeck_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_FacingBackground_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
};

static const u16 sArmCannonOam_UsingElevator_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x40, 3, 0),
};

static const u16 sArmCannonOam_UsingElevator_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x60, 3, 0),
};

static const u16 sArmCannonOam_UsingElevator_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x44, 3, 0),
};

static const u16 sArmCannonOam_UsingElevator_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x64, 3, 0),
};

const struct FrameData sArmCannonOam_UsingElevator[5] = {
    {
        .pFrame = sArmCannonOam_UsingElevator_Frame0,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_UsingElevator_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_UsingElevator_Frame2,
        .timer = 2
    },
    {
        .pFrame = sArmCannonOam_UsingElevator_Frame3,
        .timer = 2
    },
    {
        .pFrame = NULL,
        .timer = 0
    },
};

static const u16 sArmCannonOam_OnVerticalLadder_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-38, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-22, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-37, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-21, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-21, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_OnVerticalLadder_None_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-27, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-27, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-11, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_None_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-26, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-26, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-10, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_OnVerticalLadder_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-38, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-22, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-22, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-37, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-21, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-21, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_OnVerticalLadder_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(6, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(22, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(5, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(21, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(5, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_OnVerticalLadder_None_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-6, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(10, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(10, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_None_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-7, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(9, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(9, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_OnVerticalLadder_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(6, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(22, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(6, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(4, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(20, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(4, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_AfterShootingOnHorizontalLadder_None_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-3, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_None_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-17, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-1, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-31, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-15, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-29, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-13, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-13, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_Down_Left_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-12, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_Down_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-20, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-4, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_None_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-13, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_None_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-15, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(1, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(0, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-2, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(14, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_Down_Right_Frame1[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -15, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-4, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnHorizontalLadder_Down_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-12, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-4, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_OnVerticalLadder_Up_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-9, -43, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-1, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_Up_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-9, -41, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-1, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_OnVerticalLadder_Down_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-9, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-1, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_Down_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    OAM_ENTRY(-9, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-1, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_OnVerticalLadder_Up_Left_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-23, -43, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_Up_Left_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-23, -41, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_OnVerticalLadder_Down_Left_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-23, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ShootingOnVerticalLadder_Down_Left_Frame0[OAM_DATA_SIZE(2)] = {
    2 | ARM_CANNON_OAM_ORDER_BEHIND,
    OAM_ENTRY(-23, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-9)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Left_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(-9)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Left_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-31),
    [ACO_X] = C_S9_2_S16(-9)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-29),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-33),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-36),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(9)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(9)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-31),
    [ACO_X] = C_S9_2_S16(9)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-29),
    [ACO_X] = C_S9_2_S16(8)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-33),
    [ACO_X] = C_S9_2_S16(8)
};

static const s16 sArmCannonOffset_HangingOnVerticalLadder_Right_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-30),
    [ACO_X] = C_S9_2_S16(9)
};

static const s16 sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-25),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-20),
    [ACO_X] = C_S9_2_S16(-2)
};

static const s16 sArmCannonOffset_OnVerticalLadder_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-33),
    [ACO_X] = C_S9_2_S16(-21)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_DiagonalUp_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-32),
    [ACO_X] = C_S9_2_S16(-20)
};

static const s16 sArmCannonOffset_OnVerticalLadder_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-19),
    [ACO_X] = C_S9_2_S16(-25)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-19),
    [ACO_X] = C_S9_2_S16(-24)
};

static const s16 sArmCannonOffset_OnVerticalLadder_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(-21)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(-20)
};

static const s16 sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-26),
    [ACO_X] = C_S9_2_S16(-6)
};

static const s16 sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-20),
    [ACO_X] = C_S9_2_S16(2)
};

static const s16 sArmCannonOffset_OnVerticalLadder_DiagonalUp_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-33),
    [ACO_X] = C_S9_2_S16(21)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_DiagonalUp_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-32),
    [ACO_X] = C_S9_2_S16(20)
};

static const s16 sArmCannonOffset_OnVerticalLadder_None_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-19),
    [ACO_X] = C_S9_2_S16(24)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_None_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-19),
    [ACO_X] = C_S9_2_S16(23)
};

static const s16 sArmCannonOffset_OnVerticalLadder_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(21)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-11),
    [ACO_X] = C_S9_2_S16(19)
};

static const s16 sArmCannonOffset_StartingWallJump_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(-19)
};

static const s16 sArmCannonOffset_StartingWallJump_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-7),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_StartingWallJump_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(19)
};

static const s16 sArmCannonOffset_StartingWallJump_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-7),
    [ACO_X] = C_S9_2_S16(11)
};

static const s16 sArmCannonOffset_HangingOnLedge_Default_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_HangingOnLedge_Default_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-32),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_PullingUpFromHanging_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-24),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_PullingUpFromHanging_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-6)
};

static const s16 sArmCannonOffset_PullingForwardFromHanging_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-12),
    [ACO_X] = C_S9_2_S16(-7)
};

static const s16 sArmCannonOffset_PullingForwardFromHanging_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(-6)
};

static const s16 sArmCannonOffset_PullingForwardFromHanging_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-9),
    [ACO_X] = C_S9_2_S16(-10)
};

static const s16 sArmCannonOffset_PullingForwardFromHanging_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(-22)
};

static const s16 sArmCannonOffset_HangingOnLedge_Default_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(8)
};

static const s16 sArmCannonOffset_HangingOnLedge_Default_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(9)
};

static const s16 sArmCannonOffset_HangingOnLedge_Default_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-35),
    [ACO_X] = C_S9_2_S16(10)
};

static const s16 sArmCannonOffset_PullingUpFromHanging_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-28),
    [ACO_X] = C_S9_2_S16(9)
};

static const s16 sArmCannonOffset_PullingUpFromHanging_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-15),
    [ACO_X] = C_S9_2_S16(9)
};

static const s16 sArmCannonOffset_PullingForwardFromHanging_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-13),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_PullingForwardFromHanging_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-9),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_PullingForwardFromHanging_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(10)
};

static const s16 sArmCannonOffset_PullingForwardFromHanging_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-10),
    [ACO_X] = C_S9_2_S16(22)
};

static const s16 sArmCannonOffset_PullingIntoMorphFromHanging_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-7),
    [ACO_X] = C_S9_2_S16(-4)
};

static const s16 sArmCannonOffset_PullingIntoMorphFromHanging_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-7),
    [ACO_X] = C_S9_2_S16(4)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame9[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-11),
    [ACO_X] = C_S9_2_S16(2)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-9),
    [ACO_X] = C_S9_2_S16(-6)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-19),
    [ACO_X] = C_S9_2_S16(-14)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-8)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-4)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-2)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame5[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(4)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-11),
    [ACO_X] = C_S9_2_S16(3)
};

static const s16 sArmCannonOffset_TurningOnHorizontalLadder_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-9),
    [ACO_X] = C_S9_2_S16(-2)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame9[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-9),
    [ACO_X] = C_S9_2_S16(-1)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(6)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-30),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame2[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(12)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame3[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(8)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame4[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-38),
    [ACO_X] = C_S9_2_S16(6)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame6[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-3)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame7[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-37),
    [ACO_X] = C_S9_2_S16(-7)
};

static const s16 sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame8[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-18),
    [ACO_X] = C_S9_2_S16(3)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_None_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-17)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_None_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-15)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-7),
    [ACO_X] = C_S9_2_S16(-14)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(-12)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_Down_Left_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(1),
    [ACO_X] = C_S9_2_S16(-4)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_Down_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-1),
    [ACO_X] = C_S9_2_S16(-4)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_None_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(17)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_None_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(15)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-7),
    [ACO_X] = C_S9_2_S16(14)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-8),
    [ACO_X] = C_S9_2_S16(12)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_Down_Right_Frame1[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(1),
    [ACO_X] = C_S9_2_S16(4)
};

static const s16 sArmCannonOffset_ShootingOnHorizontalLadder_Down_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-1),
    [ACO_X] = C_S9_2_S16(4)
};

static const s16 sArmCannonOffset_OnVerticalLadder_Up_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-41),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_Up_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-39),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_OnVerticalLadder_Down_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-4),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_Down_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-6),
    [ACO_X] = C_S9_2_S16(7)
};

static const s16 sArmCannonOffset_OnVerticalLadder_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-41),
    [ACO_X] = C_S9_2_S16(-7)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_Up_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-39),
    [ACO_X] = C_S9_2_S16(-7)
};

static const s16 sArmCannonOffset_OnVerticalLadder_Down_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-2),
    [ACO_X] = C_S9_2_S16(-7)
};

static const s16 sArmCannonOffset_ShootingOnVerticalLadder_Down_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-4),
    [ACO_X] = C_S9_2_S16(-7)
};

static const s16 sArmCannonOffset_HangingOnLedge_PushingAway_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-30),
    [ACO_X] = C_S9_2_S16(8)
};

const struct ArmCannonAnimData sArmCannonAnim_HangingOnVerticalLadder_Left[7] = {
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_HangingOnVerticalLadder_Right[7] = {
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_28c3e0[12] = {
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_StartingToHoldArmOutOnVerticalLadder_Left[2] = {
    {
        .pOffset = sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_StartingToPutArmAwayOnVerticalLadder_Left[2] = {
    {
        .pOffset = sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_DiagonalUp_Left[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_DiagonalUp_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_DiagonalUp_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_DiagonalUp_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_DiagonalUp_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_DiagonalUp_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_None_Left[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_None_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_None_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_None_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_None_Left_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_None_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_None_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_None_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_DiagonalDown_Left[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_DiagonalDown_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_DiagonalDown_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_DiagonalDown_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_StartingToHoldArmOutOnVerticalLadder_Right[2] = {
    {
        .pOffset = sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_StartingToPutArmAwayOnVerticalLadder_Right[2] = {
    {
        .pOffset = sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_StartingToHoldArmOutOnVerticalLadder_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_DiagonalUp_Right[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_DiagonalUp_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_DiagonalUp_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_DiagonalUp_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_DiagonalUp_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_DiagonalUp_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_None_Right[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_None_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_None_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_None_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_None_Right_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_None_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_None_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_None_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_DiagonalDown_Right[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_DiagonalDown_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_DiagonalDown_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_DiagonalDown_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_StartingWallJump_Left[2] = {
    {
        .pOffset = sArmCannonOffset_StartingWallJump_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_StartingWallJump_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_StartingWallJump_Right[2] = {
    {
        .pOffset = sArmCannonOffset_StartingWallJump_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_StartingWallJump_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_HangingOnLedge_Default_Left[7] = {
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_PullingUpFromHanging_Left[3] = {
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingUpFromHanging_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingUpFromHanging_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_PullingForwardFromHanging_Left[4] = {
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_PullingIntoMorphFromHanging_Left[1] = {
    {
        .pOffset = sArmCannonOffset_PullingIntoMorphFromHanging_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_HangingOnLedge_Default_Right[7] = {
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_PullingUpFromHanging_Right[3] = {
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingUpFromHanging_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingUpFromHanging_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_PullingForwardFromHanging_Right[4] = {
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_PullingIntoMorphFromHanging_Right[5] = {
    {
        .pOffset = sArmCannonOffset_PullingIntoMorphFromHanging_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame9,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame9,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame9,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame9,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MovingOnHorizontalLadder_Left[10] = {
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnVerticalLadder_Right_Frame5,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame8,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame9,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningOnHorizontalLadder_Left[2] = {
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_TurningOnHorizontalLadder_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_TurningOnHorizontalLadder_Right[6] = {
    {
        .pOffset = sArmCannonOffset_TurningOnHorizontalLadder_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_PullingForwardFromHanging_Left_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame9,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame9,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame9,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame9,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_MovingOnHorizontalLadder_Right[10] = {
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame2,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame3,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Left_Frame4,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame6,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame7,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame8,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_MovingOnHorizontalLadder_Right_Frame9,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_AfterShootingOnHorizontalLadder_None_Left[1] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_None_Left_Frame1,
        .pOam = sArmCannonOam_AfterShootingOnHorizontalLadder_None_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnHorizontalLadder_None_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_None_Left_Frame0,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_None_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_None_Left_Frame1,
        .pOam = sArmCannonOam_AfterShootingOnHorizontalLadder_None_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_AfterShootingOnHorizontalLadder_DiagonalDown_Left[1] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnHorizontalLadder_DiagonalDown_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame0,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_AfterShootingOnHorizontalLadder_Down_Left[1] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_Down_Left_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_Down_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnHorizontalLadder_Down_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_Down_Left_Frame0,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_Down_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_Down_Left_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_Down_Left_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_AfterShootingOnHorizontalLadder_None_Right[1] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_None_Right_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_None_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnHorizontalLadder_None_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_None_Right_Frame0,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_None_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_None_Right_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_None_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_AfterShootingOnHorizontalLadder_DiagonalDown_Right[1] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnHorizontalLadder_DiagonalDown_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame0,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_AfterShootingOnHorizontalLadder_Down_Right[1] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_Down_Right_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_Down_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnHorizontalLadder_Down_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_Down_Right_Frame0,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_Down_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_ShootingOnHorizontalLadder_Down_Right_Frame1,
        .pOam = sArmCannonOam_ShootingOnHorizontalLadder_Down_Right_Frame1
    },
};

const struct ArmCannonAnimData sArmCannonAnim_LoweringDownToStartHanging_Left[2] = {
    {
        .pOffset = sArmCannonOffset_PullingUpFromHanging_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_LoweringDownToStartHanging_Right[10] = {
    {
        .pOffset = sArmCannonOffset_PullingUpFromHanging_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Right_Frame1,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_Up_Right[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_Up_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_Up_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_Up_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_Up_Right_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_Up_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_Up_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_Up_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_Down_Right[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_Down_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_Down_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_Down_Right[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_Down_Right_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_Down_Right_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_Down_Right_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_Down_Right_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_Up_Left[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_Up_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_Up_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_Up_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_Up_Left_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_Up_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_Up_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_Up_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_OnVerticalLadder_Down_Left[1] = {
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_Down_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_Down_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ShootingOnVerticalLadder_Down_Left[2] = {
    {
        .pOffset = sArmCannonOffset_ShootingOnVerticalLadder_Down_Left_Frame0,
        .pOam = sArmCannonOam_ShootingOnVerticalLadder_Down_Left_Frame0
    },
    {
        .pOffset = sArmCannonOffset_OnVerticalLadder_Down_Left_Frame0,
        .pOam = sArmCannonOam_OnVerticalLadder_Down_Left_Frame0
    },
};

const struct ArmCannonAnimData sArmCannonAnim_HangingOnLedge_PushingAway_Left[7] = {
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_Default_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_HangingOnLedge_PushingAway_Right[7] = {
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_PushingAway_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_PushingAway_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_PushingAway_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_PushingAway_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_PushingAway_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_PushingAway_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_HangingOnLedge_PushingAway_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
};

static const s16 sArmCannonOffset_SpaceJumping_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-11),
    [ACO_X] = C_S9_2_S16(0)
};

const struct ArmCannonAnimData sArmCannonAnim_SpaceJumping_Left[8] = {
    {
        .pOffset = sArmCannonOffset_SpaceJumping_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_SpaceJumping_Right[8] = {
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ScrewAttacking_Left[16] = {
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_ScrewAttacking_Right[16] = {
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Empty,
        .pOam = sSamusOam_Empty
    },
};

static const u16 sArmCannonOam_ScrewAttacking_Left_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ScrewAttacking_Left_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ScrewAttacking_Left_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-13, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-13, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ScrewAttacking_Left_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -31, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-13, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x44, 1, 0),
    OAM_ENTRY(3, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 1, 0),
    OAM_ENTRY(-6, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x64, 1, 0),
};

static const u16 sArmCannonOam_ScrewAttacking_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-18, -27, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -11, OAM_DIMS_32x16, OAM_X_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ScrewAttacking_Right_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-18, -27, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-18, -11, OAM_DIMS_32x16, OAM_X_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ScrewAttacking_Right_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-19, -25, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-19, -9, OAM_DIMS_32x16, OAM_X_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_ScrewAttacking_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -31, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(5, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x44, 1, 0),
    OAM_ENTRY(-19, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x46, 1, 0),
    OAM_ENTRY(-10, 1, OAM_DIMS_16x8, OAM_X_FLIP, 0x64, 1, 0),
};

const struct FrameData sArmCannonOam_ScrewAttacking_Left[5] = {
    {
        .pFrame = sArmCannonOam_ScrewAttacking_Left_Frame0,
        .timer = 2
    },
    {
        .pFrame = sArmCannonOam_ScrewAttacking_Left_Frame1,
        .timer = 2
    },
    {
        .pFrame = sArmCannonOam_ScrewAttacking_Left_Frame2,
        .timer = 2
    },
    {
        .pFrame = sArmCannonOam_ScrewAttacking_Left_Frame3,
        .timer = 2
    },
    FRAME_DATA_TERMINATOR
};

const struct FrameData sArmCannonOam_ScrewAttacking_Right[5] = {
    {
        .pFrame = sArmCannonOam_ScrewAttacking_Right_Frame0,
        .timer = 2
    },
    {
        .pFrame = sArmCannonOam_ScrewAttacking_Right_Frame1,
        .timer = 2
    },
    {
        .pFrame = sArmCannonOam_ScrewAttacking_Right_Frame2,
        .timer = 2
    },
    {
        .pFrame = sArmCannonOam_ScrewAttacking_Right_Frame3,
        .timer = 2
    },
    FRAME_DATA_TERMINATOR
};

static const s16 sArmCannonOffset_Dying_Left_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-11),
    [ACO_X] = C_S9_2_S16(-11)
};

static const s16 sArmCannonOffset_Dying_Right_Frame0[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-11),
    [ACO_X] = C_S9_2_S16(11)
};

const struct ArmCannonAnimData sArmCannonAnim_Dying_Left[9] = {
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_Dying_Right[9] = {
    {
        .pOffset = sArmCannonOffset_Dying_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Right_Frame0,
        .pOam = sSamusOam_Empty
    },
};

const struct ArmCannonAnimData sArmCannonAnim_LoadingSave[28] = {
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Dying_Left_Frame0,
        .pOam = sSamusOam_Empty
    },
};

static const u16 sArmCannonOam_Dying_Left_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Dying_Left_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Dying_Left_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
    OAM_ENTRY(-10, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x48, 1, 0),
};

static const u16 sArmCannonOam_Dying_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -33, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
    OAM_ENTRY(-1, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 0x68, 1, 0),
};

static const u16 sArmCannonOam_Dying_Left_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -33, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
    OAM_ENTRY(0, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4a, 1, 0),
};

static const u16 sArmCannonOam_Dying_Left_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-15, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Dying_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Dying_Right_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_Dying_Right_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x44, 1, 0),
    OAM_ENTRY(-6, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x48, 1, 0),
};

static const u16 sArmCannonOam_Dying_Right_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -33, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_X_FLIP, 0x44, 1, 0),
    OAM_ENTRY(-15, -41, OAM_DIMS_16x8, OAM_X_FLIP, 0x68, 1, 0),
};

static const u16 sArmCannonOam_Dying_Right_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -33, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_X_FLIP, 0x44, 1, 0),
    OAM_ENTRY(-8, -41, OAM_DIMS_8x8, OAM_X_FLIP, 0x4a, 1, 0),
};

static const u16 sArmCannonOam_Dying_Right_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-17, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x44, 1, 0),
};

const struct FrameData sArmCannonOam_Dying_Left[7] = {
    {
        .pFrame = sArmCannonOam_Dying_Left_Frame0,
        .timer = 4
    },
    {
        .pFrame = sArmCannonOam_Dying_Left_Frame1,
        .timer = 2
    },
    {
        .pFrame = sArmCannonOam_Dying_Left_Frame2,
        .timer = 4
    },
    {
        .pFrame = sArmCannonOam_Dying_Left_Frame3,
        .timer = 4
    },
    {
        .pFrame = sArmCannonOam_Dying_Left_Frame4,
        .timer = 6
    },
    {
        .pFrame = sArmCannonOam_Dying_Left_Frame5,
        .timer = 12
    },
    FRAME_DATA_TERMINATOR
};

const struct FrameData sArmCannonOam_Dying_Right[7] = {
    {
        .pFrame = sArmCannonOam_Dying_Right_Frame0,
        .timer = 4
    },
    {
        .pFrame = sArmCannonOam_Dying_Right_Frame1,
        .timer = 2
    },
    {
        .pFrame = sArmCannonOam_Dying_Right_Frame2,
        .timer = 4
    },
    {
        .pFrame = sArmCannonOam_Dying_Right_Frame3,
        .timer = 4
    },
    {
        .pFrame = sArmCannonOam_Dying_Right_Frame4,
        .timer = 6
    },
    {
        .pFrame = sArmCannonOam_Dying_Right_Frame5,
        .timer = 12
    },
    FRAME_DATA_TERMINATOR
};

static const u16 sArmCannonOam_LoadingSave_Frame16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x48, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame18[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x48, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame20[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x48, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame22[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame13[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x44, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame24[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame12[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame14[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x40, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x40, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x40, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x40, 1, 0),
};

static const u16 sArmCannonOam_LoadingSave_Frame46[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x40, 1, 0),
};

const struct FrameData sArmCannonOam_LoadingSave[49] = {
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame0,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame2,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame4,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame46,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame24,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame13,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame12,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame13,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame14,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame16,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame13,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame18,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame20,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame13,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame22,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame24,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame13,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame12,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame13,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame14,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame24,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame13,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame12,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame13,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame14,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame0,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame2,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame4,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame46,
        .timer = 1
    },
    {
        .pFrame = sArmCannonOam_LoadingSave_Frame1,
        .timer = 1
    },
    {
        .pFrame = NULL,
        .timer = 0
    },
};


static const s16 sArmCannonOffset_Unused_28d014[ACO_COUNT] = {
    [ACO_Y] = C_S8_2_S16(-16),
    [ACO_X] = C_S9_2_S16(-8)
};

const struct ArmCannonAnimData sArmCannonAnim_Unused_28d018[72] = {
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
    {
        .pOffset = sArmCannonOffset_Unused_28d014,
        .pOam = sSamusOam_Empty
    },
};
