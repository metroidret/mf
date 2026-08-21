#include "data/samus/samus_graphics.h"
#include "data/samus/samus_empty_data.h"

#include "oam.h"

#define SAMUS_ANIM_TERMINATOR \
{                             \
    .pTopGfx = NULL,          \
    .pBottomGfx = NULL,       \
    .pOam = NULL,             \
    .timer = 0,               \
}

static const u8 sSamusGfx_Running_None_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Running_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Running_Frame1_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Left_Frame2_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_Running_Frame2_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/running_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Left_Frame3_Top[SAMUS_GFX_SIZE(4, 3)] = {
    4, 3,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_3_top.gfx")
};

static const u8 sSamusGfx_Running_Frame3_Bottom[SAMUS_GFX_SIZE(6, 4)] = {
    6, 4,
    _INCBIN_U8("data/samus/graphics/body/running_frame_3_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Left_Frame4_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_4_top.gfx")
};

static const u8 sSamusGfx_Running_Frame4_Bottom[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/running_frame_4_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Left_Frame5_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_5_top.gfx")
};

static const u8 sSamusGfx_Running_Frame5_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_frame_5_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Left_Frame6_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_6_top.gfx")
};

static const u8 sSamusGfx_Running_Frame6_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_frame_6_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Left_Frame7_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_7_top.gfx")
};

static const u8 sSamusGfx_Running_Frame7_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/running_frame_7_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Left_Frame8_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_8_top.gfx")
};

static const u8 sSamusGfx_Running_Frame8_Bottom[SAMUS_GFX_SIZE(6, 4)] = {
    6, 4,
    _INCBIN_U8("data/samus/graphics/body/running_frame_8_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Left_Frame9_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_left_frame_9_top.gfx")
};

static const u8 sSamusGfx_Running_Frame9_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/running_frame_9_bottom.gfx")
};

static const u8 sSamusGfx_Running_DiagonalUp_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalUp_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_up_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalUp_Left_Frame2_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_up_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_Running_Forward_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_forward_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Running_Forward_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_forward_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Running_Forward_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_forward_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalDown_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalDown_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_down_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalDown_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_down_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Up_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_up_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Standing_Up_Right_Frame0_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_up_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Standing_Up_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_Up_Right_Frame1_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_up_right_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_Standing_Up_Left_Frame2_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_up_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_Standing_Up_Frame2_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_up_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Up_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Shooting_Up_Left_Frame0_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_up_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalUp_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalUp_Frame0_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_up_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalUp_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_up_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalUp_Frame1_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_up_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalUp_Left_Frame2_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_up_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalUp_Frame2_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_up_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalUp_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_Forward_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_forward_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_Forward_Frame0_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_forward_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Standing_Forward_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_forward_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Standing_Forward_Frame1_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_forward_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_Standing_Forward_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_forward_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_Standing_Forward_Frame2_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_forward_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Forward_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_forward_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalDown_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalDown_Frame0_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_down_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalDown_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_down_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalDown_Frame1_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_down_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalDown_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_down_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalDown_Frame2_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_down_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalDown_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Up_Left_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_up_left_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Up_Left_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_up_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalUp_Left_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_up_left_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalUp_Left_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_up_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Forward_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_forward_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Forward_Left_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_forward_left_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Forward_Left_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_forward_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalDown_Left_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_down_left_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalDown_Left_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_down_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame0_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame2_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame3_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_3_top.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame4_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_4_top.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame5_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_5_top.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame6_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_6_top.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame7_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_7_top.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame8_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_8_top.gfx")
};

static const u8 sSamusGfx_Running_None_Right_Frame9_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_none_right_frame_9_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalUp_Right_Frame0_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalUp_Right_Frame1_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_up_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalUp_Right_Frame2_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_up_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_Running_Forward_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_forward_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Running_Forward_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_forward_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Running_Forward_Right_Frame2_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_forward_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalDown_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalDown_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_down_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Running_DiagonalDown_Right_Frame2_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/running_diagonal_down_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_Standing_Up_Right_Frame0_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_Up_Right_Frame1_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_up_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Standing_Up_Right_Frame2_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_up_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Up_Right_Frame0_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Shooting_Up_Right_Frame0_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_up_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalUp_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalUp_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_up_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalUp_Right_Frame2_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_up_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalUp_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_Forward_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_forward_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_Forward_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_forward_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Standing_Forward_Right_Frame2_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_forward_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Forward_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_forward_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalDown_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalDown_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_down_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Standing_DiagonalDown_Right_Frame2_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/standing_diagonal_down_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalDown_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Up_Right_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_up_right_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Up_Right_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_up_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalUp_Right_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_up_right_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalUp_Right_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_up_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Forward_Right_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_forward_right_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_Forward_Right_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_forward_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalDown_Right_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_down_right_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingAndCrouching_DiagonalDown_Right_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_and_crouching_diagonal_down_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Skidding_Default_Left_Frame0_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/skidding_default_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Skidding_Frame0_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/skidding_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Skidding_Armed_Left_Frame0_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/skidding_armed_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Skidding_Default_Right_Frame0_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/skidding_default_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Skidding_Armed_Right_Frame0_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/skidding_armed_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_Default_Left_Frame0_Top[SAMUS_GFX_SIZE(7, 6)] = {
    7, 6,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_default_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_Default_Left_Frame1_Top[SAMUS_GFX_SIZE(7, 6)] = {
    7, 6,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_default_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_Default_Left_Frame2_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_default_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_Frame2_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_LookingUp_Left_Frame0_Top[SAMUS_GFX_SIZE(7, 6)] = {
    7, 6,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_looking_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_LookingUp_Left_Frame1_Top[SAMUS_GFX_SIZE(7, 6)] = {
    7, 6,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_looking_up_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_LookingUp_Left_Frame2_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_looking_up_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_Default_Right_Frame0_Top[SAMUS_GFX_SIZE(8, 6)] = {
    8, 6,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_default_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_Default_Right_Frame1_Top[SAMUS_GFX_SIZE(7, 5)] = {
    7, 5,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_default_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_Default_Right_Frame2_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_default_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_LookingUp_Right_Frame0_Top[SAMUS_GFX_SIZE(8, 6)] = {
    8, 6,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_looking_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_LookingUp_Right_Frame1_Top[SAMUS_GFX_SIZE(7, 5)] = {
    7, 5,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_looking_up_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_HitByOmegaMetroid_LookingUp_Right_Frame2_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/hit_by_omega_metroid_looking_up_right_frame_2_top.gfx")
};

static const u16 sSamusOam_Running_None_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-14, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(2, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_None_Left_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_Running_None_Left_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-11, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Running_None_Left_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Running_None_Left_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Left_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Left_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_None_Left_Frame9[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-1, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-18, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-2, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Left_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-18, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-2, -39, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Left_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Left_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-18, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-2, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Left_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Left_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-19, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-3, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Left_Frame9[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Left_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Left_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Left_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Left_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Left_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-19, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Left_Frame8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-19, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Left_Frame9[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-14, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Left_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Left_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-14, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Left_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-15, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Left_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Left_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-15, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Left_Frame9[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-15, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Standing_Up_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Standing_Up_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Standing_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-3, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-19, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Standing_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-19, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Shooting_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Standing_Forward_Left_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-20, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Standing_Forward_Left_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-20, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Standing_Forward_Left_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-20, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-8, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_Shooting_Forward_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-12, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Standing_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Standing_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Standing_DiagonalDown_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-18, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Shooting_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_Up_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_Up_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_Forward_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_Forward_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(10, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(6, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(8, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_16x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-14, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(9, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_16x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_None_Right_Frame9[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Right_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -39, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_16x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Right_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-14, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Right_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Right_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Right_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalUp_Right_Frame9[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -42, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -43, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Right_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -43, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_16x8, OAM_X_FLIP, 0x18, 0, 0),
    OAM_ENTRY(1, -44, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Right_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-14, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -42, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Right_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -42, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Right_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(2, -43, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Right_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_16x8, OAM_X_FLIP, 0x18, 0, 0),
    OAM_ENTRY(2, -44, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Running_Forward_Right_Frame9[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(1, -42, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-2, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Right_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_16x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Right_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-1, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-14, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Right_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-1, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Right_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Right_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_16x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Running_DiagonalDown_Right_Frame9[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Standing_Up_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Standing_Up_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Shooting_Up_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-7, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Standing_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Shooting_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Standing_Forward_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -41, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Standing_Forward_Right_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(0, -41, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Shooting_Forward_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-1, -41, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Standing_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(2, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Standing_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(2, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Shooting_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_Up_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_Up_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_DiagonalUp_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(9, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(8, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_Forward_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-1, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_Forward_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-2, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingAndCrouching_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2bce2a[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-15, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-14, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-7, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_2bce4a[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-14, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_2bce64[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(7, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-18, -17, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_2bce84[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(9, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -17, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Skidding_Left_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-9, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-16, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_2bcec4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-9, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-17, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_Skidding_Default_Right_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(1, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_Skidding_Armed_Right_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(1, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_Default_Left_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-11, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_Default_Left_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_Default_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_LookingUp_Left_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-11, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_LookingUp_Left_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-11, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_LookingUp_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_Default_Right_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-3, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_Default_Right_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-4, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_Default_Right_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_LookingUp_Right_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-3, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_LookingUp_Right_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-4, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
};

static const u16 sSamusOam_HitByOmegaMetroid_LookingUp_Right_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

const struct SamusAnimData sSamusAnim_Running_None_Left[11] = {
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame4_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame5_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame6_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame6,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame7_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame7,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame8_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame8,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame9_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame9,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Running_DiagonalUp_Left[11] = {
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame6,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame7,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Left_Frame9,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Running_Forward_Left[11] = {
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame7,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame8,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_Forward_Left_Frame9,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Running_DiagonalDown_Left[11] = {
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame7,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame8,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Left_Frame9,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Standing_Up_Left[4] = {
    {
        .pTopGfx = sSamusGfx_Standing_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Up_Right_Frame1_Bottom,
        .pOam = sSamusOam_Standing_Up_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Up_Right_Frame1_Bottom,
        .pOam = sSamusOam_Standing_Up_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_Up_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Standing_Up_Frame2_Bottom,
        .pOam = sSamusOam_Standing_Up_Left_Frame2,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shooting_Up_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Shooting_Up_Left_Frame0_Bottom,
        .pOam = sSamusOam_Standing_Up_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Up_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Standing_Up_Right_Frame0_Bottom,
        .pOam = sSamusOam_Standing_Up_Left_Frame2,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Standing_DiagonalUp_Left[4] = {
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame0_Bottom,
        .pOam = sSamusOam_Standing_DiagonalUp_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame1_Bottom,
        .pOam = sSamusOam_Standing_DiagonalUp_Left_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame2_Bottom,
        .pOam = sSamusOam_Standing_DiagonalUp_Left_Frame1,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shooting_DiagonalUp_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame2_Bottom,
        .pOam = sSamusOam_Shooting_DiagonalUp_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame0_Bottom,
        .pOam = sSamusOam_Standing_DiagonalUp_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Standing_Forward_Left[4] = {
    {
        .pTopGfx = sSamusGfx_Standing_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Standing_Forward_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame1_Bottom,
        .pOam = sSamusOam_Standing_Forward_Left_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_Forward_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame2_Bottom,
        .pOam = sSamusOam_Standing_Forward_Left_Frame2,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shooting_Forward_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame2_Bottom,
        .pOam = sSamusOam_Shooting_Forward_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Standing_Forward_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Standing_DiagonalDown_Left[4] = {
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_Standing_DiagonalDown_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalDown_Frame1_Bottom,
        .pOam = sSamusOam_Standing_DiagonalDown_Left_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalDown_Frame2_Bottom,
        .pOam = sSamusOam_Standing_DiagonalDown_Left_Frame2,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shooting_DiagonalDown_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame2_Bottom,
        .pOam = sSamusOam_Shooting_DiagonalDown_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_Standing_DiagonalDown_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingAndCrouching_Up_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_Up_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_Up_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Up_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_Up_Left_Frame1_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_Up_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingAndCrouching_DiagonalUp_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_DiagonalUp_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_DiagonalUp_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_DiagonalUp_Left_Frame1_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_DiagonalUp_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingAndCrouching_Forward_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_Forward_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_Forward_Left_Frame1_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_Forward_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingAndCrouching_DiagonalDown_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_DiagonalDown_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_DiagonalDown_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_DiagonalDown_Left_Frame1_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_DiagonalDown_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Running_None_Right[11] = {
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame4_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame5_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame6_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame6,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame7_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame7,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame8_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame8,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame9_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame9,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Running_DiagonalUp_Right[11] = {
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame6,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame7,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_DiagonalUp_Right_Frame9,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Running_Forward_Right[11] = {
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame7,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame8,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_Forward_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_Forward_Right_Frame9,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Running_DiagonalDown_Right[11] = {
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame7,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame8,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Running_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_DiagonalDown_Right_Frame9,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Standing_Up_Right[4] = {
    {
        .pTopGfx = sSamusGfx_Standing_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Up_Right_Frame0_Bottom,
        .pOam = sSamusOam_Standing_Up_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_Up_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Standing_Up_Right_Frame1_Bottom,
        .pOam = sSamusOam_Standing_Up_Right_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_Up_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Standing_Up_Frame2_Bottom,
        .pOam = sSamusOam_Standing_Up_Right_Frame0,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shooting_Up_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Shooting_Up_Right_Frame0_Bottom,
        .pOam = sSamusOam_Shooting_Up_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Up_Right_Frame0_Bottom,
        .pOam = sSamusOam_Standing_Up_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Standing_DiagonalUp_Right[4] = {
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame0_Bottom,
        .pOam = sSamusOam_Standing_DiagonalUp_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame1_Bottom,
        .pOam = sSamusOam_Standing_DiagonalUp_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame2_Bottom,
        .pOam = sSamusOam_Standing_DiagonalUp_Right_Frame0,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shooting_DiagonalUp_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame2_Bottom,
        .pOam = sSamusOam_Shooting_DiagonalUp_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalUp_Frame0_Bottom,
        .pOam = sSamusOam_Standing_DiagonalUp_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Standing_Forward_Right[4] = {
    {
        .pTopGfx = sSamusGfx_Standing_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Standing_Forward_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_Forward_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame1_Bottom,
        .pOam = sSamusOam_Standing_Forward_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_Forward_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame2_Bottom,
        .pOam = sSamusOam_Standing_Forward_Right_Frame2,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shooting_Forward_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame2_Bottom,
        .pOam = sSamusOam_Shooting_Forward_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Standing_Forward_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Standing_DiagonalDown_Right[4] = {
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_Standing_DiagonalDown_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalDown_Frame1_Bottom,
        .pOam = sSamusOam_Standing_DiagonalDown_Right_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalDown_Frame2_Bottom,
        .pOam = sSamusOam_Standing_DiagonalDown_Right_Frame0,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shooting_DiagonalDown_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_Forward_Frame2_Bottom,
        .pOam = sSamusOam_Shooting_DiagonalDown_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Standing_DiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_Standing_DiagonalDown_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingAndCrouching_Up_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_Up_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_Up_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_Up_Right_Frame1_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_Up_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingAndCrouching_DiagonalUp_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_DiagonalUp_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_DiagonalUp_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_DiagonalUp_Right_Frame1_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_DiagonalUp_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingAndCrouching_Forward_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_Forward_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_Forward_Right_Frame1_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_Forward_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingAndCrouching_DiagonalDown_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingAndCrouching_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_DiagonalDown_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_DiagonalDown_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Standing_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingAndCrouching_DiagonalDown_Right_Frame1_Bottom,
        .pOam = sSamusOam_ShootingAndCrouching_DiagonalDown_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2bdb68[11] = {
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame2,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame4_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame5_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame5,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame6_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame6,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame7_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame7,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame8_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame8,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame9_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame9,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2bdc18[11] = {
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame2,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame4_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame5_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame5,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame6_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame6,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame7_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame7,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame8_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame8,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame9_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame9,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2bdcc8[11] = {
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame2,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_2bce2a,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame4_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame5_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame5,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame6_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame6,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame7_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame7,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame8_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_2bce4a,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Left_Frame9_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_None_Left_Frame9,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2bdd78[11] = {
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Running_Frame0_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Running_Frame1_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Running_Frame2_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame2,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_Running_Frame3_Bottom,
        .pOam = sSamusOam_2bce64,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame4_Top,
        .pBottomGfx = sSamusGfx_Running_Frame4_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame5_Top,
        .pBottomGfx = sSamusGfx_Running_Frame5_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame5,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame6_Top,
        .pBottomGfx = sSamusGfx_Running_Frame6_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame6,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame7_Top,
        .pBottomGfx = sSamusGfx_Running_Frame7_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame7,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame8_Top,
        .pBottomGfx = sSamusGfx_Running_Frame8_Bottom,
        .pOam = sSamusOam_2bce84,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Running_None_Right_Frame9_Top,
        .pBottomGfx = sSamusGfx_Running_Frame9_Bottom,
        .pOam = sSamusOam_Running_None_Right_Frame9,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Skidding_Default_Left[2] = {
    {
        .pTopGfx = sSamusGfx_Skidding_Default_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Skidding_Frame0_Bottom,
        .pOam = sSamusOam_Skidding_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Skidding_Armed_Left[2] = {
    {
        .pTopGfx = sSamusGfx_Skidding_Armed_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Skidding_Frame0_Bottom,
        .pOam = sSamusOam_Skidding_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Skidding_Default_Right[2] = {
    {
        .pTopGfx = sSamusGfx_Skidding_Default_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Skidding_Frame0_Bottom,
        .pOam = sSamusOam_Skidding_Default_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Skidding_Armed_Right[2] = {
    {
        .pTopGfx = sSamusGfx_Skidding_Armed_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Skidding_Frame0_Bottom,
        .pOam = sSamusOam_Skidding_Armed_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_HitByOmegaMetroid_Default_Left[5] = {
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_Default_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame0_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_Default_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_Default_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame1_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_Default_Left_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_Default_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame2_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_Default_Left_Frame2,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_Default_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame1_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_Default_Left_Frame1,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_HitByOmegaMetroid_LookingUp_Left[5] = {
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_LookingUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame0_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_LookingUp_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_LookingUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame1_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_LookingUp_Left_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_LookingUp_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame2_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_LookingUp_Left_Frame2,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_LookingUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame1_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_LookingUp_Left_Frame1,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_HitByOmegaMetroid_Default_Right[5] = {
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_Default_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame0_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_Default_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_Default_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame1_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_Default_Right_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_Default_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame2_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_Default_Right_Frame2,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_Default_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame1_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_Default_Right_Frame1,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_HitByOmegaMetroid_LookingUp_Right[5] = {
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_LookingUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame0_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_LookingUp_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_LookingUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame1_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_LookingUp_Right_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_LookingUp_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame2_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_LookingUp_Right_Frame2,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HitByOmegaMetroid_LookingUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_HitByOmegaMetroid_Frame1_Bottom,
        .pOam = sSamusOam_HitByOmegaMetroid_LookingUp_Right_Frame1,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

static const u8 sSamusGfx_DelayBeforeShinesparking_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/delay_before_shinesparking_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_DelayBeforeShinesparking_Left_Frame0_Bottom[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/delay_before_shinesparking_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_None_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_NotDown_Frame0_Bottom[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_not_down_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_None_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_NotDown_Frame1_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_not_down_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_None_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_MidAir_NotDown_Frame2_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_not_down_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_None_Left_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_left_frame_3_top.gfx")
};

static const u8 sSamusGfx_MidAir_NotDown_Frame3_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_not_down_frame_3_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_None_Left_Frame4_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_left_frame_4_top.gfx")
};

static const u8 sSamusGfx_MidAir_NotDown_Frame4_Bottom[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_not_down_frame_4_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_None_Left_Frame5_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_left_frame_5_top.gfx")
};

static const u8 sSamusGfx_MidAir_NotDown_Frame5_Bottom[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_not_down_frame_5_bottom.gfx")
};

static const u8 sSamusGfx_Landing_None_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/landing_none_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Landing_NotNone_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/landing_not_none_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Landing_None_Left_Frame1_Top[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/landing_none_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Landing_NotNone_Left_Frame1_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/landing_not_none_left_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_Up_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_Up_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_up_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_Up_Left_Frame2_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_up_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalUp_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalUp_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_up_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalUp_Left_Frame2_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_up_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_MidAir_Forward_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_forward_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_Forward_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_forward_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_Forward_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_forward_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalDown_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalDown_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_down_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalDown_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_down_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_2bf8e4[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/2bf8e6.gfx")
};

static const u8 sSamusGfx_2bf986[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/2bf988.gfx")
};

static const u8 sSamusGfx_2bfa48[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/2bfa4a.gfx")
};

static const u8 sSamusGfx_2bfb0a[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/2bfb0c.gfx")
};

static const u8 sSamusGfx_MidAir_Down_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_Down_Frame0_Bottom[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_down_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_Down_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_down_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_Down_Frame1_Bottom[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_down_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_DelayBeforeShinesparking_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/delay_before_shinesparking_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_DelayBeforeShinesparking_Right_Frame0_Bottom[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/delay_before_shinesparking_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_None_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_None_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_None_Right_Frame2_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_MidAir_None_Right_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_right_frame_3_top.gfx")
};

static const u8 sSamusGfx_MidAir_None_Right_Frame4_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_right_frame_4_top.gfx")
};

static const u8 sSamusGfx_MidAir_None_Right_Frame5_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_none_right_frame_5_top.gfx")
};

static const u8 sSamusGfx_Landing_None_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/landing_none_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Landing_None_Right_Frame1_Top[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/landing_none_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Landing_NotNone_Right_Frame1_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/landing_not_none_right_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_MidAir_Up_Right_Frame0_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_Up_Right_Frame1_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_up_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_Up_Right_Frame2_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_up_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalUp_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalUp_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_up_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalUp_Right_Frame2_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_up_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_MidAir_Forward_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_forward_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_Forward_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_forward_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_Forward_Right_Frame2_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_forward_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_2c101c[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/2c101e.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalDown_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalDown_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_down_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_MidAir_DiagonalDown_Right_Frame2_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/mid_air_diagonal_down_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_2c12a4[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/2c12a6.gfx")
};

static const u8 sSamusGfx_2c1326[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/2c1328.gfx")
};

static const u8 sSamusGfx_2c13e8[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/2c13ea.gfx")
};

static const u8 sSamusGfx_2c14aa[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/2c14ac.gfx")
};

static const u8 sSamusGfx_MidAir_Down_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_MidAir_Down_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/mid_air_down_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Spinning_Left_Frame0_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/spinning_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Spinning_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/spinning_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Spinning_Left_Frame2_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/spinning_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_Spinning_Left_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/spinning_left_frame_3_top.gfx")
};

static const u8 sSamusGfx_Spinning_Right_Frame0_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/spinning_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Spinning_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/spinning_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Spinning_Right_Frame2_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/spinning_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_Spinning_Right_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/spinning_right_frame_3_top.gfx")
};

static const u8 sSamusGfx_StartingSpinJump_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/starting_spin_jump_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_StartingSpinJump_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/starting_spin_jump_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_StartingSpinJump_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/starting_spin_jump_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Shinesparking_Upwards_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Shinesparking_Upwards_Frame0_Bottom[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_up_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Shinesparking_Upwards_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_up_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Shinesparking_Upwards_Frame1_Bottom[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_up_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_Shinesparking_Upwards_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Shinesparking_Upwards_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_up_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_Shinesparking_Sideways_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_sideways_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_Shinesparking_Sideways_Frame0_Bottom[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_sideways_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Shinesparking_Sideways_Left_Frame1_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_sideways_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_Shinesparking_Sideways_Frame1_Bottom[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_sideways_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_Shinesparking_Sideways_Right_Frame0_Top[SAMUS_GFX_SIZE(7, 7)] = {
    7, 7,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_sideways_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Shinesparking_Sideways_Right_Frame1_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/shinesparking_sideways_right_frame_1_top.gfx")
};

static const u16 sSamusOam_DelayBeforeShinesparking_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-14, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-14, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Left_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-13, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Left_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-14, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Left_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-14, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Left_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-14, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Landing_None_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-13, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Landing_None_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-13, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_2c347a[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -47, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -45, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Left_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Left_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Left_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -47, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Left_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_Up_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_Up_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3570[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -39, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Left_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -31, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Left_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Left_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Left_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_DiagonalUp_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3666[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-9, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-17, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Left_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Left_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Left_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Left_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_Forward_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_Forward_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3792[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-17, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-9, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Left_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Left_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Left_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Left_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3888[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c38a2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-19, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c38bc[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c38d6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Down_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-12, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-2, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Down_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-12, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-4, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_DelayBeforeShinesparking_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-3, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-3, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Right_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Right_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_None_Right_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_None_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_None_Right_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-3, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -39, OAM_DIMS_8x8, OAM_X_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_2c3a20[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Right_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Right_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Right_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Right_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Up_Right_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_Up_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3acc[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(9, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -39, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Right_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -31, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Right_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalUp_Right_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(9, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_DiagonalUp_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3bc2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -42, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(1, -44, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -43, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Right_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -38, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -41, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Right_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -44, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Forward_Right_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -43, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_Forward_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -36, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_Forward_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -39, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3cb8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Right_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Right_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_DiagonalDown_Right_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Landing_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3dae[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3dc2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(11, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2c3ddc[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Down_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-14, -30, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MidAir_Down_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-12, -30, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-12, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Spinning_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_Spinning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -21, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_Spinning_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Spinning_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -13, OAM_DIMS_32x16, OAM_XY_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_32x16, OAM_XY_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_Spinning_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -21, OAM_DIMS_32x16, OAM_XY_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_Spinning_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_XY_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_XY_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_StartingSpinJump_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-12, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_StartingSpinJump_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Shinesparking_Upwards_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Shinesparking_Upwards_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Shinesparking_Upwards_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Shinesparking_Upwards_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -40, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Shinesparking_Sideways_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(5, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_Shinesparking_Sideways_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(22, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18, 0, 0),
};

static const u16 sSamusOam_Shinesparking_Sideways_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(3, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_Shinesparking_Sideways_Right_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-14, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(2, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-30, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x18, 0, 0),
};

const struct SamusAnimData sSamusAnim_MidAir_None_Left[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_None_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_None_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_None_Left_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_None_Left_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_None_Left_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Left_Frame4_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_None_Left_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Left_Frame5_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_None_Left_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_None_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Landing_None_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_None_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Landing_None_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Left_Frame1_Bottom,
        .pOam = sSamusOam_Landing_None_Left_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_Up_Left[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_Up_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Up_Left_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_Up_Left_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_Up_Left_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_Up_Left_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_Up_Left_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_Up_Left[3] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_Up_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Left_Frame1_Bottom,
        .pOam = sSamusOam_Landing_Up_Left_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_DiagonalUp_Left[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Left_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Left_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Left_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Left_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Left_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_DiagonalUp_Left[3] = {
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_DiagonalUp_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Left_Frame1_Bottom,
        .pOam = sSamusOam_Landing_DiagonalUp_Left_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_Forward_Left[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Left_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Left_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Left_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Left_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Left_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_Forward_Left[3] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_Forward_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Left_Frame1_Bottom,
        .pOam = sSamusOam_Landing_Forward_Left_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_DiagonalDown_Left[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Left_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Left_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Left_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Left_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Left_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_DiagonalDown_Left[3] = {
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_DiagonalDown_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Left_Frame1_Bottom,
        .pOam = sSamusOam_Landing_DiagonalDown_Left_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c42a8[2] = {
    {
        .pTopGfx = sSamusGfx_2bf8e4,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_2c3888,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c42c8[2] = {
    {
        .pTopGfx = sSamusGfx_2bf986,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_2c38a2,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c42e8[2] = {
    {
        .pTopGfx = sSamusGfx_2bfa48,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_2c38bc,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c4308[2] = {
    {
        .pTopGfx = sSamusGfx_2bfb0a,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_2c38d6,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c4328[2] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_None_Right[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_None_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_None_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_None_Right_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_None_Right_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_None_Right_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Right_Frame4_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_None_Right_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Right_Frame5_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_None_Right_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_None_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Landing_None_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_None_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Landing_None_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Right_Frame1_Bottom,
        .pOam = sSamusOam_Landing_None_Right_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_Up_Right[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_Up_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Up_Right_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_Up_Right_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_Up_Right_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_Up_Right_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_Up_Right_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_Up_Right[3] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_Up_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Up_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Right_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Up_Right_Frame3,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_DiagonalUp_Right[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Right_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Right_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Right_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Right_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalUp_Right_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_DiagonalUp_Right[3] = {
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_DiagonalUp_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalUp_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Right_Frame1_Bottom,
        .pOam = sSamusOam_Landing_DiagonalUp_Right_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_Forward_Right[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Right_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Right_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Right_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Right_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_Forward_Right_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_Forward_Right[3] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_Forward_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Forward_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Right_Frame1_Bottom,
        .pOam = sSamusOam_Landing_Forward_Right_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_DiagonalDown_Right[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Right_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Right_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Right_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame4_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Right_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame5_Bottom,
        .pOam = sSamusOam_MidAir_DiagonalDown_Right_Frame5,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Landing_DiagonalDown_Right[3] = {
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Frame0_Bottom,
        .pOam = sSamusOam_Landing_DiagonalDown_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Landing_NotNone_Right_Frame1_Bottom,
        .pOam = sSamusOam_Landing_DiagonalDown_Right_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c4668[2] = {
    {
        .pTopGfx = sSamusGfx_2c12a4,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_2c3dae,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c4688[2] = {
    {
        .pTopGfx = sSamusGfx_2c1326,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_2c3dc2,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c46a8[2] = {
    {
        .pTopGfx = sSamusGfx_2c13e8,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_2c3ddc,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c46c8[2] = {
    {
        .pTopGfx = sSamusGfx_2c14aa,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame3_Bottom,
        .pOam = sSamusOam_Landing_DiagonalDown_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2c46e8[2] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_Down_Left[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_Down_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Left_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Left_Frame1,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Left_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Left_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Left_Frame1,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MidAir_Down_Right[7] = {
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_Down_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Right_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Right_Frame1,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Right_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Right_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_MidAir_Down_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_Down_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_Down_Right_Frame1,
        .timer = 6
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Spinning_Left[9] = {
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame5,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame7,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Spinning_Right[9] = {
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame5,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame7,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_StartingSpinJump_Left[2] = {
    {
        .pTopGfx = sSamusGfx_StartingSpinJump_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_StartingSpinJump_Frame0_Bottom,
        .pOam = sSamusOam_StartingSpinJump_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_StartingSpinJump_Right[2] = {
    {
        .pTopGfx = sSamusGfx_StartingSpinJump_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_StartingSpinJump_Frame0_Bottom,
        .pOam = sSamusOam_StartingSpinJump_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_DelayBeforeShinesparking_Left[5] = {
    {
        .pTopGfx = sSamusGfx_DelayBeforeShinesparking_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_DelayBeforeShinesparking_Left_Frame0_Bottom,
        .pOam = sSamusOam_DelayBeforeShinesparking_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_None_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_None_Left_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_None_Left_Frame2,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shinesparking_Upwards_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Shinesparking_Upwards_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Upwards_Frame0_Bottom,
        .pOam = sSamusOam_Shinesparking_Upwards_Left_Frame0,
        .timer = 8
    },
    {
        .pTopGfx = sSamusGfx_Shinesparking_Upwards_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Upwards_Frame1_Bottom,
        .pOam = sSamusOam_Shinesparking_Upwards_Left_Frame1,
        .timer = 255
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_DelayBeforeShinesparking_Right[5] = {
    {
        .pTopGfx = sSamusGfx_DelayBeforeShinesparking_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_DelayBeforeShinesparking_Right_Frame0_Bottom,
        .pOam = sSamusOam_DelayBeforeShinesparking_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame0_Bottom,
        .pOam = sSamusOam_MidAir_None_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame1_Bottom,
        .pOam = sSamusOam_MidAir_None_Right_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_MidAir_None_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_MidAir_NotDown_Frame2_Bottom,
        .pOam = sSamusOam_MidAir_None_Right_Frame2,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shinesparking_Upwards_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Shinesparking_Upwards_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Upwards_Frame0_Bottom,
        .pOam = sSamusOam_Shinesparking_Upwards_Right_Frame0,
        .timer = 8
    },
    {
        .pTopGfx = sSamusGfx_Shinesparking_Upwards_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Upwards_Frame1_Bottom,
        .pOam = sSamusOam_Shinesparking_Upwards_Right_Frame1,
        .timer = 255
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shinesparking_Sideways_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Shinesparking_Sideways_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Sideways_Frame0_Bottom,
        .pOam = sSamusOam_Shinesparking_Sideways_Left_Frame0,
        .timer = 8
    },
    {
        .pTopGfx = sSamusGfx_Shinesparking_Sideways_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Sideways_Frame1_Bottom,
        .pOam = sSamusOam_Shinesparking_Sideways_Left_Frame1,
        .timer = 255
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Shinesparking_Sideways_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Shinesparking_Sideways_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Sideways_Frame0_Bottom,
        .pOam = sSamusOam_Shinesparking_Sideways_Right_Frame0,
        .timer = 8
    },
    {
        .pTopGfx = sSamusGfx_Shinesparking_Sideways_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Sideways_Frame1_Bottom,
        .pOam = sSamusOam_Shinesparking_Sideways_Right_Frame1,
        .timer = 255
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_DelayAfterShinesparking_Upwards_Left[10] = {
    {
        .pTopGfx = sSamusGfx_Shinesparking_Upwards_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Upwards_Frame1_Bottom,
        .pOam = sSamusOam_Shinesparking_Upwards_Left_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame5,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame7,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_DelayAfterShinesparking_Upwards_Right[10] = {
    {
        .pTopGfx = sSamusGfx_Shinesparking_Upwards_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Upwards_Frame1_Bottom,
        .pOam = sSamusOam_Shinesparking_Upwards_Right_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame5,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame7,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_DelayAfterShinesparking_Sideways_Left[10] = {
    {
        .pTopGfx = sSamusGfx_Shinesparking_Sideways_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Sideways_Frame1_Bottom,
        .pOam = sSamusOam_Shinesparking_Sideways_Left_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame5,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame7,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_DelayAfterShinesparking_Sideways_Right[10] = {
    {
        .pTopGfx = sSamusGfx_Shinesparking_Sideways_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Shinesparking_Sideways_Frame1_Bottom,
        .pOam = sSamusOam_Shinesparking_Sideways_Right_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame3,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame5,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame4,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Spinning_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Spinning_Frame7,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

static const u8 sSamusGfx_Crouching_Up_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/crouching_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_2c4dca[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/2c4dcc.gfx")
};

static const u8 sSamusGfx_Turning_Up_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/turning_up_frame_0_top.gfx")
};

static const u8 sSamusGfx_Turning_Up_Frame0_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/turning_up_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Turning_Up_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/turning_up_frame_1_top.gfx")
};

static const u8 sSamusGfx_Crouching_Up_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/crouching_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Crouching_DiagonalUp_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/crouching_diagonal_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_2c5276[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/2c5278.gfx")
};

static const u8 sSamusGfx_Turning_DiagonalUp_Frame1_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/turning_diagonal_up_frame_1_top.gfx")
};

static const u8 sSamusGfx_Turning_Forward_Frame0_Bottom[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/turning_forward_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Turning_DiagonalUp_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/turning_diagonal_up_frame_0_top.gfx")
};

static const u8 sSamusGfx_Crouching_DiagonalUp_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/crouching_diagonal_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Crouching_Forward_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/crouching_forward_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_2c5782[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/2c5784.gfx")
};

static const u8 sSamusGfx_Turning_Forward_Frame1_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/turning_forward_frame_1_top.gfx")
};

static const u8 sSamusGfx_Turning_Forward_Frame0_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/turning_forward_frame_0_top.gfx")
};

static const u8 sSamusGfx_2c5a68[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/2c5a6a.gfx")
};

static const u8 sSamusGfx_Crouching_DiagonalDown_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/crouching_diagonal_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_2c5c4c[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/2c5c4e.gfx")
};

static const u8 sSamusGfx_Turning_DiagonalDown_Frame1_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/turning_diagonal_down_frame_1_top.gfx")
};

static const u8 sSamusGfx_Turning_DiagonalDown_Frame0_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/turning_diagonal_down_frame_0_top.gfx")
};

static const u8 sSamusGfx_2c5f52[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/2c5f54.gfx")
};

static const u8 sSamusGfx_Crouching_Up_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/crouching_up_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_TurningAndCrouching_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/turning_and_crouching_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Crouching_DiagonalUp_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/crouching_diagonal_up_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Crouching_Forward_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/crouching_forward_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Crouching_Forward_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/crouching_forward_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_Crouching_DiagonalDown_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/crouching_diagonal_down_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Crouching_DiagonalDown_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/crouching_diagonal_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/turning_mid_air_not_diagonal_down_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_TurningMidAir_Down_Left_Frame0_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/turning_mid_air_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_2c6746[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/2c6748.gfx")
};

static const u8 sSamusGfx_Unmorphing_Frame2_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/unmorphing_frame_2_top.gfx")
};

static const u8 sSamusGfx_Morphing_Frame0_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/morphing_frame_0_top.gfx")
};

static const u8 sSamusGfx_Morphing_Frame1_Top[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/morphing_frame_1_top.gfx")
};

static const u8 sSamusGfx_MorphBall_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/morph_ball_frame_0_top.gfx")
};

static const u8 sSamusGfx_MorphBall_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/morph_ball_frame_1_top.gfx")
};

static const u8 sSamusGfx_MorphBall_Frame2_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/morph_ball_frame_2_top.gfx")
};

static const u8 sSamusGfx_FacingForeground_Frame0_Top[SAMUS_GFX_SIZE(9, 6)] = {
    9, 6,
    _INCBIN_U8("data/samus/graphics/body/facing_foreground_frame_0_top.gfx")
};

static const u8 sSamusGfx_FacingForeground_Frame1_Top[SAMUS_GFX_SIZE(9, 6)] = {
    9, 6,
    _INCBIN_U8("data/samus/graphics/body/facing_foreground_frame_1_top.gfx")
};

static const u8 sSamusGfx_FacingForeground_Frame2_Top[SAMUS_GFX_SIZE(9, 6)] = {
    9, 6,
    _INCBIN_U8("data/samus/graphics/body/facing_foreground_frame_2_top.gfx")
};

static const u8 sSamusGfx_FacingBackground_Left_Frame3_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/facing_background_left_frame_3_top.gfx")
};

static const u8 sSamusGfx_FacingBackground_Frame3_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/facing_background_frame_3_bottom.gfx")
};

static const u8 sSamusGfx_FacingBackground_Frame0_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/facing_background_frame_0_top.gfx")
};

static const u8 sSamusGfx_FacingBackground_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/facing_background_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_FacingBackground_Right_Frame3_Top[SAMUS_GFX_SIZE(6, 4)] = {
    6, 4,
    _INCBIN_U8("data/samus/graphics/body/facing_background_right_frame_3_top.gfx")
};

static const u8 sSamusGfx_OnNavigationPad_Frame10_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/on_navigation_pad_frame_10_top.gfx")
};

static const u8 sSamusGfx_OnNavigationPad_Frame3_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/on_navigation_pad_frame_3_top.gfx")
};

static const u8 sSamusGfx_OnNavigationPad_Frame11_Top[SAMUS_GFX_SIZE(7, 4)] = {
    7, 4,
    _INCBIN_U8("data/samus/graphics/body/on_navigation_pad_frame_11_top.gfx")
};

static const u8 sSamusGfx_OnNavigationPad_Frame7_Top[SAMUS_GFX_SIZE(8, 4)] = {
    8, 4,
    _INCBIN_U8("data/samus/graphics/body/on_navigation_pad_frame_7_top.gfx")
};

static const u8 sSamusGfx_OnNavigationPad_Frame14_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/on_navigation_pad_frame_14_top.gfx")
};

static const u8 sSamusGfx_OnNavigationPad_Frame12_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/on_navigation_pad_frame_12_top.gfx")
};

static const u8 sSamusGfx_UsingElevator_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/using_elevator_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_UsingElevator_Frame0_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/using_elevator_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_UsingElevator_Frame2_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/using_elevator_frame_2_top.gfx")
};

static const u8 sSamusGfx_UsingElevator_Frame2_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/using_elevator_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_2c8178[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/2c817a.gfx")
};

static const u8 sSamusGfx_2c829a[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/2c829c.gfx")
};

static const u8 sSamusGfx_UsingElevator_Right_Frame0_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/using_elevator_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame0_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_0_top.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame10_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_10_top.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame10_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_10_bottom.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame12_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_12_top.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame12_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_12_bottom.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame14_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_14_top.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame14_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_14_bottom.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame15_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_15_top.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame15_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_15_bottom.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame13_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_13_top.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame13_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_13_bottom.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame11_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_11_top.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame11_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_11_bottom.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame9_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_9_top.gfx")
};

static const u8 sSamusGfx_DownloadingAbility_Frame9_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/downloading_ability_frame_9_bottom.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Left_Frame2_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Frame2_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Left_Frame4_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_left_frame_4_top.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Frame4_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_frame_4_bottom.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Left_Frame6_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_left_frame_6_top.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Frame6_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_frame_6_bottom.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Left_Frame1_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Frame1_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Right_Frame2_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Right_Frame4_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_right_frame_4_top.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Right_Frame6_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_right_frame_6_top.gfx")
};

static const u8 sSamusGfx_BeingRecharged_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/being_recharged_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_UnlockingSecurity_Left_Frame0_Top[SAMUS_GFX_SIZE(7, 2)] = {
    7, 2,
    _INCBIN_U8("data/samus/graphics/body/unlocking_security_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_UnlockingSecurity_Right_Frame0_Top[SAMUS_GFX_SIZE(6, 2)] = {
    6, 2,
    _INCBIN_U8("data/samus/graphics/body/unlocking_security_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_UnlockingHabitationsDeck_Frame0_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/unlocking_habitations_deck_frame_0_top.gfx")
};

static const u8 sSamusGfx_UnlockingHabitationsDeck_Frame0_Bottom[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/unlocking_habitations_deck_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_UnlockingHabitationsDeck_Frame1_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/unlocking_habitations_deck_frame_1_top.gfx")
};

static const u8 sSamusGfx_UnlockingHabitationsDeck_Frame4_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/unlocking_habitations_deck_frame_4_top.gfx")
};

static const u8 sSamusGfx_UnlockingHabitationsDeck_Frame4_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/unlocking_habitations_deck_frame_4_bottom.gfx")
};

static const u16 sSamusOam_2ca66a[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Turning_Up_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Turning_Up_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_2ca6ca[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_2ca6ea[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-19, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Turning_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Turning_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2ca74a[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2ca76a[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-9, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-17, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Turning_Forward_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Turning_Forward_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2ca7dc[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(9, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_2ca802[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_Turning_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(3, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-13, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Turning_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(8, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2ca86e[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(11, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
};

static const u16 sSamusOam_TurningAndCrouching_Up_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningAndCrouching_Up_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Crouching_Up_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Crouching_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningAndCrouching_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-15, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningAndCrouching_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(9, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Crouching_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(9, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Crouching_Forward_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-17, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningAndCrouching_Forward_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-17, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningAndCrouching_Forward_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Crouching_Forward_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Crouching_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-18, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningAndCrouching_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-14, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(2, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningAndCrouching_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(8, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_Crouching_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(3, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningMidAir_Up_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningMidAir_Up_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningMidAir_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningMidAir_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningMidAir_Forward_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningMidAir_Forward_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningMidAir_Down_Left_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(3, -31, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-13, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-15, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 1, 0),
};

static const u16 sSamusOam_TurningMidAir_Down_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(8, -31, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2cab26[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-15, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_2cab4c[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-2, -41, OAM_DIMS_8x8, OAM_X_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x17, 0, 0),
    OAM_ENTRY(-1, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Unmorphing_Left_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_Morphing_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Morphing_Left_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MorphBall_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MorphBall_Left_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MorphBall_Left_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MorphBall_Left_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_Y_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MorphBall_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MorphBall_Left_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_XY_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MorphBall_Left_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MorphBall_Left_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_Unmorphing_Right_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_Morphing_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_Morphing_Right_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_FacingForeground_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5, 0, 0),
};

static const u16 sSamusOam_FacingBackground_Left_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_FacingBackground_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(5, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_FacingBackground_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_OnNavigationPad_Frame10[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-3, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_OnNavigationPad_Frame11[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-19, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-3, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_OnNavigationPad_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-19, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-3, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_OnNavigationPad_Frame12[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-3, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-11, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_UsingElevator_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-11, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(5, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
};

static const u16 sSamusOam_2cad7a[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-9, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(7, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(6, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
};

static const u16 sSamusOam_UsingElevator_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_DownloadingAbility_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_BeingRecharged_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_BeingRecharged_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_BeingRecharged_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_UnlockingSecurity_Left_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_UnlockingSecurity_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(3, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_UnlockingHabitationsDeck_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(3, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-13, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(3, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_UnlockingHabitationsDeck_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-9, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(7, -39, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(7, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

const struct SamusAnimData sSamusAnim_Turning_Up_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Up_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Up_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Up_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Up_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Turning_Up_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Up_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Up_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Up_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Up_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Turning_DiagonalUp_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_DiagonalUp_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_DiagonalUp_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Turning_DiagonalUp_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_DiagonalUp_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_DiagonalUp_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Turning_Forward_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Forward_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Forward_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Turning_Forward_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Forward_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Forward_Frame1,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Turning_DiagonalDown_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_DiagonalDown_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_DiagonalDown_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Turning_DiagonalDown_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_DiagonalDown_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_DiagonalDown_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningAndCrouching_Up_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_Up_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_Up_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningAndCrouching_Up_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_Up_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_Up_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningAndCrouching_DiagonalUp_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_DiagonalUp_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_DiagonalUp_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningAndCrouching_DiagonalUp_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_DiagonalUp_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_DiagonalUp_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningAndCrouching_Forward_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_Forward_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_Forward_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningAndCrouching_Forward_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_Forward_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_Forward_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningAndCrouching_DiagonalDown_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_DiagonalDown_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_DiagonalDown_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningAndCrouching_DiagonalDown_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_DiagonalDown_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningAndCrouching_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_DiagonalDown_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningMidAir_Up_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Up_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Up_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningMidAir_Up_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Up_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Up_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Up_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningMidAir_DiagonalUp_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_DiagonalUp_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_DiagonalUp_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningMidAir_DiagonalUp_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_DiagonalUp_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalUp_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_DiagonalUp_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningMidAir_Forward_Left[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Forward_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Forward_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningMidAir_Forward_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Forward_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Forward_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningMidAir_Down_Left[3] = {
    {
        .pTopGfx = sSamusGfx_TurningMidAir_Down_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Down_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Down_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningMidAir_Down_Right[3] = {
    {
        .pTopGfx = sSamusGfx_Turning_DiagonalDown_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Down_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_TurningMidAir_Down_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningMidAir_NotDiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_TurningMidAir_Down_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Crouching_Up_Left[2] = {
    {
        .pTopGfx = sSamusGfx_Crouching_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Crouching_Up_Frame0_Bottom,
        .pOam = sSamusOam_TurningAndCrouching_Up_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Crouching_Up_Right[2] = {
    {
        .pTopGfx = sSamusGfx_Crouching_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Crouching_Up_Frame0_Bottom,
        .pOam = sSamusOam_Crouching_Up_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Crouching_DiagonalUp_Left[2] = {
    {
        .pTopGfx = sSamusGfx_Crouching_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Crouching_DiagonalUp_Frame0_Bottom,
        .pOam = sSamusOam_Crouching_DiagonalUp_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Crouching_DiagonalUp_Right[2] = {
    {
        .pTopGfx = sSamusGfx_Crouching_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Crouching_DiagonalUp_Frame0_Bottom,
        .pOam = sSamusOam_Crouching_DiagonalUp_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Crouching_Forward_Left[2] = {
    {
        .pTopGfx = sSamusGfx_Crouching_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Crouching_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Crouching_Forward_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Crouching_Forward_Right[2] = {
    {
        .pTopGfx = sSamusGfx_Crouching_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Crouching_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Crouching_Forward_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Crouching_DiagonalDown_Left[2] = {
    {
        .pTopGfx = sSamusGfx_Crouching_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Crouching_DiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_Crouching_DiagonalDown_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Crouching_DiagonalDown_Right[2] = {
    {
        .pTopGfx = sSamusGfx_Crouching_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Crouching_DiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_Crouching_DiagonalDown_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Morphing_Left[4] = {
    {
        .pTopGfx = sSamusGfx_Morphing_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Morphing_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Morphing_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Morphing_Left_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame7,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MorphBall_Left[9] = {
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame6,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame7,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unmorphing_Left[4] = {
    {
        .pTopGfx = sSamusGfx_Morphing_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Morphing_Left_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Morphing_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Morphing_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Unmorphing_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Unmorphing_Left_Frame2,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Morphing_Right[4] = {
    {
        .pTopGfx = sSamusGfx_Morphing_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Morphing_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Morphing_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Morphing_Right_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame1,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MorphBall_Right[9] = {
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame7,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame6,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame5,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Frame4,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame3,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame2,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_MorphBall_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_MorphBall_Left_Frame1,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unmorphing_Right[4] = {
    {
        .pTopGfx = sSamusGfx_Morphing_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Morphing_Right_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Morphing_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Morphing_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Unmorphing_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Unmorphing_Right_Frame2,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_OnSavePad_Left[5] = {
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Forward_Frame1,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_OnSavePad_Right[5] = {
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Forward_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_FacingForeground_Left[5] = {
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame1_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Forward_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_FacingForeground_Right[5] = {
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_Turning_Forward_Frame0_Top,
        .pBottomGfx = sSamusGfx_Turning_Forward_Frame0_Bottom,
        .pOam = sSamusOam_Turning_Forward_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_OnNavigationPad_Left[17] = {
    {
        .pTopGfx = sSamusGfx_FacingBackground_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame3_Bottom,
        .pOam = sSamusOam_FacingBackground_Left_Frame3,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame10_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame3_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame10_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame3_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame11_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame11,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame7_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame7,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame11_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame11,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame7_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame7,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame10_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame11_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame11,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame12_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame12,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 12
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame14_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 30
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 8
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_FacingBackground_Left[5] = {
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame3_Bottom,
        .pOam = sSamusOam_FacingBackground_Left_Frame3,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_OnNavigationPad_Right[17] = {
    {
        .pTopGfx = sSamusGfx_FacingBackground_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame3_Bottom,
        .pOam = sSamusOam_FacingBackground_Right_Frame3,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame10_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame3_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame10_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame3_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame11_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame11,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame7_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame7,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame11_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame11,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame7_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame7,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame10_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame11_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame11,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame12_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame12,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 12
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame14_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 30
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 8
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_FacingBackground_Right[5] = {
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Frame0_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame3_Bottom,
        .pOam = sSamusOam_FacingBackground_Right_Frame3,
        .timer = 8
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_UsingElevator_Left[6] = {
    {
        .pTopGfx = sSamusGfx_UsingElevator_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_UsingElevator_Frame0_Bottom,
        .pOam = sSamusOam_FacingBackground_Left_Frame3,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_UsingElevator_Frame2_Top,
        .pBottomGfx = sSamusGfx_UsingElevator_Frame2_Bottom,
        .pOam = sSamusOam_UsingElevator_Frame2,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_UsingElevator_Frame2_Top,
        .pBottomGfx = sSamusGfx_UsingElevator_Frame2_Bottom,
        .pOam = sSamusOam_UsingElevator_Frame2,
        .timer = 255
    },
    {
        .pTopGfx = sSamusGfx_UsingElevator_Frame2_Top,
        .pBottomGfx = sSamusGfx_UsingElevator_Frame2_Bottom,
        .pOam = sSamusOam_UsingElevator_Frame2,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_UsingElevator_Right[6] = {
    {
        .pTopGfx = sSamusGfx_UsingElevator_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_UsingElevator_Frame0_Bottom,
        .pOam = sSamusOam_UsingElevator_Right_Frame0,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_UsingElevator_Frame2_Top,
        .pBottomGfx = sSamusGfx_UsingElevator_Frame2_Bottom,
        .pOam = sSamusOam_UsingElevator_Frame2,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_UsingElevator_Frame2_Top,
        .pBottomGfx = sSamusGfx_UsingElevator_Frame2_Bottom,
        .pOam = sSamusOam_UsingElevator_Frame2,
        .timer = 255
    },
    {
        .pTopGfx = sSamusGfx_UsingElevator_Frame2_Top,
        .pBottomGfx = sSamusGfx_UsingElevator_Frame2_Bottom,
        .pOam = sSamusOam_UsingElevator_Frame2,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_DownloadingAbility_Left[17] = {
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame0_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame0_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame10_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame10_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame15_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame15_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame12_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame12_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame13_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame13_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame14_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame14_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame11_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame11_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame0_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame0_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame9_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame9_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame10_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame10_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame11_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame11_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame12_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame12_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame13_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame13_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame14_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame14_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame15_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame15_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_DownloadingAbility_Right[17] = {
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame0_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame0_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_FacingForeground_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_FacingForeground_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame10_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame10_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame15_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame15_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame12_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame12_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame13_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame13_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame14_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame14_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame11_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame11_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame0_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame0_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame9_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame9_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame10_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame10_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame11_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame11_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame12_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame12_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame13_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame13_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame14_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame14_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_DownloadingAbility_Frame15_Top,
        .pBottomGfx = sSamusGfx_DownloadingAbility_Frame15_Bottom,
        .pOam = sSamusOam_DownloadingAbility_Frame0,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_BeingRecharged_Left[9] = {
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame0_Bottom,
        .pOam = sSamusOam_BeingRecharged_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_BeingRecharged_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame2_Bottom,
        .pOam = sSamusOam_BeingRecharged_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_BeingRecharged_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Left_Frame4_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame4_Bottom,
        .pOam = sSamusOam_BeingRecharged_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_BeingRecharged_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Left_Frame6_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame6_Bottom,
        .pOam = sSamusOam_BeingRecharged_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_BeingRecharged_Left_Frame0,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_BeingRecharged_Right[9] = {
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame0_Bottom,
        .pOam = sSamusOam_BeingRecharged_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_BeingRecharged_Right_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame2_Bottom,
        .pOam = sSamusOam_BeingRecharged_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_BeingRecharged_Right_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Right_Frame4_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame4_Bottom,
        .pOam = sSamusOam_BeingRecharged_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_BeingRecharged_Right_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Right_Frame6_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame6_Bottom,
        .pOam = sSamusOam_BeingRecharged_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_BeingRecharged_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_BeingRecharged_Right_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_UnlockingSecurity_Left[2] = {
    {
        .pTopGfx = sSamusGfx_UnlockingSecurity_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_UnlockingSecurity_Left_Frame0,
        .timer = 60
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_UnlockingSecurity_Right[2] = {
    {
        .pTopGfx = sSamusGfx_UnlockingSecurity_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_BeingRecharged_Frame1_Bottom,
        .pOam = sSamusOam_UnlockingSecurity_Right_Frame0,
        .timer = 60
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_UnlockingHabitationsDeck[7] = {
    {
        .pTopGfx = sSamusGfx_UnlockingHabitationsDeck_Frame0_Top,
        .pBottomGfx = sSamusGfx_UnlockingHabitationsDeck_Frame0_Bottom,
        .pOam = sSamusOam_UnlockingHabitationsDeck_Frame0,
        .timer = 8
    },
    {
        .pTopGfx = sSamusGfx_UnlockingHabitationsDeck_Frame1_Top,
        .pBottomGfx = sSamusGfx_UnlockingHabitationsDeck_Frame0_Bottom,
        .pOam = sSamusOam_UnlockingHabitationsDeck_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_UnlockingHabitationsDeck_Frame0_Top,
        .pBottomGfx = sSamusGfx_UnlockingHabitationsDeck_Frame0_Bottom,
        .pOam = sSamusOam_UnlockingHabitationsDeck_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_OnNavigationPad_Frame7_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame0_Bottom,
        .pOam = sSamusOam_OnNavigationPad_Frame7,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_UnlockingHabitationsDeck_Frame4_Top,
        .pBottomGfx = sSamusGfx_UnlockingHabitationsDeck_Frame4_Bottom,
        .pOam = sSamusOam_UnlockingHabitationsDeck_Frame4,
        .timer = 32
    },
    {
        .pTopGfx = sSamusGfx_FacingBackground_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_FacingBackground_Frame3_Bottom,
        .pOam = sSamusOam_FacingBackground_Right_Frame3,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame3_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_3_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame3_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_3_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame4_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_4_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame4_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_4_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame5_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_5_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame5_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_5_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame1_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame1_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame2_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Left_Frame2_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_left_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Right_Frame0_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Right_Frame1_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Right_Frame2_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Right_Frame3_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_right_frame_3_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Right_Frame4_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_right_frame_4_top.gfx")
};

static const u8 sSamusGfx_HangingOnVerticalLadder_Right_Frame5_Top[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_from_vertical_ladder_right_frame_5_top.gfx")
};

static const u8 sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame0_Top[SAMUS_GFX_SIZE(6, 6)] = {
    6, 6,
    _INCBIN_U8("data/samus/graphics/body/starting_to_hold_arm_out_on_vertical_ladder_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/starting_to_hold_arm_out_on_vertical_ladder_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame1_Top[SAMUS_GFX_SIZE(6, 4)] = {
    6, 4,
    _INCBIN_U8("data/samus/graphics/body/starting_to_hold_arm_out_on_vertical_ladder_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame1_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/starting_to_hold_arm_out_on_vertical_ladder_left_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_DiagonalUp_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_diagonal_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_forward_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_DiagonalUp_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_diagonal_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Forward_Left_Frame0_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_forward_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_forward_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Forward_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_forward_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_DiagonalDown_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_diagonal_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_DiagonalDown_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_diagonal_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame0_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/starting_to_hold_arm_out_on_vertical_ladder_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame0_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/starting_to_hold_arm_out_on_vertical_ladder_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/starting_to_hold_arm_out_on_vertical_ladder_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame1_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/starting_to_hold_arm_out_on_vertical_ladder_right_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_DiagonalUp_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_diagonal_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_forward_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_DiagonalUp_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_diagonal_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Forward_Right_Frame0_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_forward_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_forward_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Forward_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_forward_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_DiagonalDown_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 3)] = {
    4, 3,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_diagonal_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_DiagonalDown_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 3)] = {
    4, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_diagonal_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_StartingWallJump_Left_Frame0_Top[SAMUS_GFX_SIZE(7, 7)] = {
    7, 7,
    _INCBIN_U8("data/samus/graphics/body/starting_wall_jump_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_StartingWallJump_Left_Frame1_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/starting_wall_jump_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_StartingWallJump_Right_Frame0_Top[SAMUS_GFX_SIZE(7, 7)] = {
    7, 7,
    _INCBIN_U8("data/samus/graphics/body/starting_wall_jump_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_StartingWallJump_Right_Frame1_Top[SAMUS_GFX_SIZE(6, 3)] = {
    6, 3,
    _INCBIN_U8("data/samus/graphics/body/starting_wall_jump_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Frame2_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Left_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_left_frame_3_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Frame3_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_frame_3_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Frame1_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Left_Frame5_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_left_frame_5_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Frame5_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_frame_5_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Frame0_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_PullingUpFromHanging_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/pulling_up_from_hanging_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_PullingUpFromHanging_Frame1_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/pulling_up_from_hanging_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_PullingUpFromHanging_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/pulling_up_from_hanging_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_PullingUpFromHanging_Frame2_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/pulling_up_from_hanging_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Frame1_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Left_Frame2_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_left_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Left_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_left_frame_3_top.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Frame3_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_frame_3_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Right_Frame2_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Right_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_right_frame_3_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Right_Frame5_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_right_frame_5_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_Default_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_default_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_PullingUpFromHanging_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/pulling_up_from_hanging_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_PullingUpFromHanging_Right_Frame2_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/pulling_up_from_hanging_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Right_Frame2_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Right_Frame2_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_right_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_PullingForwardFromHanging_Right_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/pulling_forward_from_hanging_right_frame_3_top.gfx")
};

static const u8 sSamusGfx_PullingIntoMorphFromHanging_Left_Frame0_Top[SAMUS_GFX_SIZE(7, 3)] = {
    7, 3,
    _INCBIN_U8("data/samus/graphics/body/pulling_into_morph_from_hanging_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_PullingIntoMorphFromHanging_Right_Frame0_Top[SAMUS_GFX_SIZE(7, 4)] = {
    7, 4,
    _INCBIN_U8("data/samus/graphics/body/pulling_into_morph_from_hanging_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_2d0ebc[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/2d0ebe.gfx")
};

static const u8 sSamusGfx_2d0fbe[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/2d0fc0.gfx")
};

static const u8 sSamusGfx_2d1060[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/2d1062.gfx")
};

static const u8 sSamusGfx_2d1162[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/2d1164.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame9_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_9_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Frame9_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_frame_9_bottom.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame0_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame1_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame1_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame2_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_2_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame2_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_2_bottom.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame3_Top[SAMUS_GFX_SIZE(5, 2)] = {
    5, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_3_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame3_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_3_bottom.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame4_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_4_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame4_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_4_bottom.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame5_Top[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_5_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame5_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_5_bottom.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame6_Top[SAMUS_GFX_SIZE(4, 3)] = {
    4, 3,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_6_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame6_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_6_bottom.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame7_Top[SAMUS_GFX_SIZE(4, 3)] = {
    4, 3,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_7_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame7_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_7_bottom.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame8_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_8_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Left_Frame8_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_left_frame_8_bottom.gfx")
};

static const u8 sSamusGfx_TurningOnHorizontalLadder_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/turning_on_horizontal_ladder_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_TurningOnHorizontalLadder_Frame0_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/turning_on_horizontal_ladder_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_TurningOnHorizontalLadder_Left_Frame1_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/turning_on_horizontal_ladder_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_2d2572[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/2d2574.gfx")
};

static const u8 sSamusGfx_2d2674[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/2d2676.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame9_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_9_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame0_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame1_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame2_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_2_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_3_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame4_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_4_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame5_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_5_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame6_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_6_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame7_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_7_top.gfx")
};

static const u8 sSamusGfx_MovingOnHorizontalLadder_Right_Frame8_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/moving_on_horizontal_ladder_right_frame_8_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Default_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_default_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Default_Frame1_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_default_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Default_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_default_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Default_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_default_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_diagonal_down_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Frame1_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_diagonal_down_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_diagonal_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_diagonal_down_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Down_Left_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_down_left_frame_1_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Down_Frame1_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_down_frame_1_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Down_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Down_Frame0_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_down_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Default_Right_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_default_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Default_Right_Frame0_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_default_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_diagonal_down_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame0_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_diagonal_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Down_Right_Frame1_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_down_right_frame_1_top.gfx")
};

static const u8 sSamusGfx_ShootingOnHorizontalLadder_Down_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_horizontal_ladder_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_2d40ee[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/2d40f0.gfx")
};

static const u8 sSamusGfx_2d4210[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/2d4212.gfx")
};

static const u8 sSamusGfx_2d4332[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/2d4334.gfx")
};

static const u8 sSamusGfx_2d4454[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/2d4456.gfx")
};

static const u8 sSamusGfx_2d4576[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/2d4578.gfx")
};

static const u8 sSamusGfx_2d4698[SAMUS_GFX_SIZE(5, 4)] = {
    5, 4,
    _INCBIN_U8("data/samus/graphics/body/2d469a.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Up_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Up_Right_Frame0_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_up_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Up_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_up_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Up_Right_Frame0_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_up_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Down_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Down_Right_Frame0_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_down_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Down_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_down_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Down_Right_Frame0_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_down_right_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Up_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Up_Left_Frame0_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_up_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Up_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_up_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Up_Left_Frame0_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_up_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Down_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ArmOutOnVerticalLadder_Down_Left_Frame0_Bottom[SAMUS_GFX_SIZE(3, 2)] = {
    3, 2,
    _INCBIN_U8("data/samus/graphics/body/arm_out_on_vertical_ladder_down_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Down_Left_Frame0_Top[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_down_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_ShootingOnVerticalLadder_Down_Left_Frame0_Bottom[SAMUS_GFX_SIZE(2, 2)] = {
    2, 2,
    _INCBIN_U8("data/samus/graphics/body/shooting_on_vertical_ladder_down_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_pushing_away_left_frame_0_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_pushing_away_left_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Top[SAMUS_GFX_SIZE(3, 3)] = {
    3, 3,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_pushing_away_right_frame_0_top.gfx")
};

static const u8 sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Bottom[SAMUS_GFX_SIZE(4, 2)] = {
    4, 2,
    _INCBIN_U8("data/samus/graphics/body/hanging_on_ledge_pushing_away_right_frame_0_bottom.gfx")
};

static const u16 sSamusOam_HangingOnVerticalLadder_Left_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-12, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Left_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -36, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-12, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Left_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-11, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-11, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Right_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Right_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Right_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Right_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-7, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_HangingOnVerticalLadder_Right_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(7, -31, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-9, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_StartingToHoldArmOutOnVerticalLadder_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_StartingToHoldArmOutOnVerticalLadder_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_ArmOutOnVerticalLadder_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_DiagonalUp_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_ArmOutOnVerticalLadder_Forward_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -31, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_Forward_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -31, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_ArmOutOnVerticalLadder_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_StartingToHoldArmOutOnVerticalLadder_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(7, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_StartingToHoldArmOutOnVerticalLadder_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(9, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_ArmOutOnVerticalLadder_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(6, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(5, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_ArmOutOnVerticalLadder_Forward_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_Forward_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(7, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_ArmOutOnVerticalLadder_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(7, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(5, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_StartingWallJump_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-22, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
#ifdef BUGFIX
    OAM_ENTRY(-6, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x6, 0, 0),
#else // !BUGFIX
    OAM_ENTRY(250, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x6, 0, 0),
#endif // BUGFIX
    OAM_ENTRY(-24, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_StartingWallJump_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-18, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-2, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_StartingWallJump_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-2, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(14, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_StartingWallJump_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(10, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(16, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Left_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Left_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Left_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingUpFromHanging_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingUpFromHanging_Left_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingForwardFromHanging_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_8x16, OAM_X_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_PullingForwardFromHanging_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_8x16, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_PullingForwardFromHanging_Left_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-19, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_PullingForwardFromHanging_Left_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-17, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Right_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -17, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Right_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_Default_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-3, -3, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingUpFromHanging_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingUpFromHanging_Right_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingForwardFromHanging_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-1, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingForwardFromHanging_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingForwardFromHanging_Right_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingForwardFromHanging_Right_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_PullingIntoMorphFromHanging_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-12, -29, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-12, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(4, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x6, 0, 0),
};

static const u16 sSamusOam_PullingIntoMorphFromHanging_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_16x8, OAM_X_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-4, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-12, -22, OAM_DIMS_8x16, OAM_X_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-12, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x6, 0, 0),
};

static const u16 sSamusOam_2d5aa6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame9[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-17, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-13, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-5, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-6, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-12, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-1, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-15, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-1, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-15, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-10, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-10, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(5, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Left_Frame8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(1, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_TurningOnHorizontalLadder_Left_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-12, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-12, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-12, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_TurningOnHorizontalLadder_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-2, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2d5c46[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_8x16, OAM_X_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame9[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_8x16, OAM_X_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-5, -37, OAM_DIMS_8x16, OAM_X_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, 2, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(0, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, 1, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(4, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-6, 1, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-11, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-6, -30, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(1, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, 2, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-2, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-13, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(2, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_MovingOnHorizontalLadder_Right_Frame8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-12, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(1, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, 3, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_Default_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-3, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-3, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_Default_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-11, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-11, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-9, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_Down_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-2, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-1, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_Down_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_Default_Right_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-3, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_8x16, OAM_X_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_Default_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_8x16, OAM_X_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-5, 2, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-6, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, 2, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_8x16, OAM_X_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_8x16, OAM_X_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_Down_Right_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_ShootingOnHorizontalLadder_Down_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_8x16, OAM_X_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_2d5ef6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-3, -33, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_2d5f16[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-3, -33, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};
static const u16 sSamusOam_2d5f36[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-3, -33, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-7, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2d5f56[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -33, OAM_DIMS_8x8, OAM_X_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-9, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -18, OAM_DIMS_16x8, OAM_X_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-6, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_2d5f76[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -33, OAM_DIMS_8x8, OAM_X_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-9, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_2d5f96[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -33, OAM_DIMS_8x8, OAM_X_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-9, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-9, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-1, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_Up_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_Down_Right_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-6, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_Up_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(1, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_Up_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_Down_Left_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16, 0, 0),
};

static const u16 sSamusOam_ShootingOnVerticalLadder_Down_Left_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-10, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_PushingAway_Left_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-10, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
    OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(6, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_HangingOnLedge_PushingAway_Right_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(2, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-7, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-7, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x16, 0, 0),
};

const struct SamusAnimData sSamusAnim_HangingOnVerticalLadder_Left[8] = {
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame1,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame2_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame3_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame3,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame4_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame4_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame4,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame5_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame5_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame5,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_HangingOnVerticalLadder_Right[8] = {
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame3_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame4_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame1,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame5_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame3,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame4_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame4,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame5_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame2_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame5,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame3_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2d617c[7] = {
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame5_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame5_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame5,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame4_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame4_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame4,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame3_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame3,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame2_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame1,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2d61ec[7] = {
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame5_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame2_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame5,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame4_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame4,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame3,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame5_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame4_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame1,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_HangingOnVerticalLadder_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnVerticalLadder_Left_Frame3_Bottom,
        .pOam = sSamusOam_HangingOnVerticalLadder_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_StartingToHoldArmOutOnVerticalLadder_Left[3] = {
    {
        .pTopGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame0_Bottom,
        .pOam = sSamusOam_StartingToHoldArmOutOnVerticalLadder_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame1_Bottom,
        .pOam = sSamusOam_StartingToHoldArmOutOnVerticalLadder_Left_Frame1,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_StartingToPutArmAwayOnVerticalLadder_Left[3] = {
    {
        .pTopGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame1_Bottom,
        .pOam = sSamusOam_StartingToHoldArmOutOnVerticalLadder_Left_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Left_Frame0_Bottom,
        .pOam = sSamusOam_StartingToHoldArmOutOnVerticalLadder_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_DiagonalUp_Left[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_DiagonalUp_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_DiagonalUp_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_DiagonalUp_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_DiagonalUp_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_DiagonalUp_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_Forward_Left[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_Forward_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_Forward_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Forward_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_Forward_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_DiagonalDown_Left[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_DiagonalDown_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_DiagonalDown_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_DiagonalDown_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Left_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_DiagonalDown_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_StartingToHoldArmOutOnVerticalLadder_Right[3] = {
    {
        .pTopGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame0_Bottom,
        .pOam = sSamusOam_StartingToHoldArmOutOnVerticalLadder_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame1_Bottom,
        .pOam = sSamusOam_StartingToHoldArmOutOnVerticalLadder_Right_Frame1,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_StartingToPutArmAwayOnVerticalLadder_Right[3] = {
    {
        .pTopGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame1_Bottom,
        .pOam = sSamusOam_StartingToHoldArmOutOnVerticalLadder_Right_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_StartingToHoldArmOutOnVerticalLadder_Right_Frame0_Bottom,
        .pOam = sSamusOam_StartingToHoldArmOutOnVerticalLadder_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_DiagonalUp_Right[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_DiagonalUp_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_DiagonalUp_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_DiagonalUp_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_DiagonalUp_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_DiagonalUp_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_Forward_Right[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_Forward_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_Forward_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Forward_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_Forward_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_DiagonalDown_Right[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_DiagonalDown_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_DiagonalDown_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_DiagonalDown_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Forward_Right_Frame0_Bottom,
        .pOam = sSamusOam_ArmOutOnVerticalLadder_DiagonalDown_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_StartingWallJump_Left[3] = {
    {
        .pTopGfx = sSamusGfx_StartingWallJump_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_StartingWallJump_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_StartingWallJump_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_StartingWallJump_Left_Frame1,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_StartingWallJump_Right[3] = {
    {
        .pTopGfx = sSamusGfx_StartingWallJump_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_StartingWallJump_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_StartingWallJump_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_StartingWallJump_Right_Frame1,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_HangingOnLedge_Default_Left[8] = {
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Left_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame2_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Left_Frame2,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Left_Frame3,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Left_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Left_Frame5_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame5_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Left_Frame5,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Left_Frame1,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_PullingUpFromHanging_Left[4] = {
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Left_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_PullingUpFromHanging_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_PullingUpFromHanging_Frame1_Bottom,
        .pOam = sSamusOam_PullingUpFromHanging_Left_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_PullingUpFromHanging_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_PullingUpFromHanging_Frame2_Bottom,
        .pOam = sSamusOam_PullingUpFromHanging_Left_Frame2,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_PullingForwardFromHanging_Left[5] = {
    {
        .pTopGfx = sSamusGfx_PullingForwardFromHanging_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_PullingForwardFromHanging_Frame0_Bottom,
        .pOam = sSamusOam_PullingForwardFromHanging_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_PullingForwardFromHanging_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_PullingForwardFromHanging_Frame1_Bottom,
        .pOam = sSamusOam_PullingForwardFromHanging_Left_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_PullingForwardFromHanging_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_PullingForwardFromHanging_Left_Frame2_Bottom,
        .pOam = sSamusOam_PullingForwardFromHanging_Left_Frame2,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_PullingForwardFromHanging_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_PullingForwardFromHanging_Frame3_Bottom,
        .pOam = sSamusOam_PullingForwardFromHanging_Left_Frame3,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_PullingIntoMorphFromHanging_Left[2] = {
    {
        .pTopGfx = sSamusGfx_PullingIntoMorphFromHanging_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_PullingIntoMorphFromHanging_Left_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_HangingOnLedge_Default_Right[8] = {
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Right_Frame1,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame2_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Right_Frame2,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Right_Frame3,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Right_Frame1,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Right_Frame5_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame5_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Right_Frame5,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Right_Frame1,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_PullingUpFromHanging_Right[4] = {
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Right_Frame0,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_PullingUpFromHanging_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_PullingUpFromHanging_Frame1_Bottom,
        .pOam = sSamusOam_PullingUpFromHanging_Right_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_PullingUpFromHanging_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_PullingUpFromHanging_Frame2_Bottom,
        .pOam = sSamusOam_PullingUpFromHanging_Right_Frame2,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_PullingForwardFromHanging_Right[5] = {
    {
        .pTopGfx = sSamusGfx_PullingForwardFromHanging_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_PullingForwardFromHanging_Frame0_Bottom,
        .pOam = sSamusOam_PullingForwardFromHanging_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_PullingForwardFromHanging_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_PullingForwardFromHanging_Frame1_Bottom,
        .pOam = sSamusOam_PullingForwardFromHanging_Right_Frame1,
        .timer = 6
    },
    {
        .pTopGfx = sSamusGfx_PullingForwardFromHanging_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_PullingForwardFromHanging_Right_Frame2_Bottom,
        .pOam = sSamusOam_PullingForwardFromHanging_Right_Frame2,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_PullingForwardFromHanging_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_PullingForwardFromHanging_Frame3_Bottom,
        .pOam = sSamusOam_PullingForwardFromHanging_Right_Frame3,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_PullingIntoMorphFromHanging_Right[2] = {
    {
        .pTopGfx = sSamusGfx_PullingIntoMorphFromHanging_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_PullingIntoMorphFromHanging_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2d67bc[5] = {
    {
        .pTopGfx = sSamusGfx_2d0ebc,
        .pBottomGfx = sSamusGfx_2d0fbe,
        .pOam = sSamusOam_2d5aa6,
        .timer = 14
    },
    {
        .pTopGfx = sSamusGfx_2d1060,
        .pBottomGfx = sSamusGfx_2d1162,
        .pOam = sSamusOam_2d5aa6,
        .timer = 14
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame9_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Frame9_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame9,
        .timer = 14
    },
    {
        .pTopGfx = sSamusGfx_2d1060,
        .pBottomGfx = sSamusGfx_2d1162,
        .pOam = sSamusOam_2d5aa6,
        .timer = 14
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MovingOnHorizontalLadder_Left[11] = {
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame0_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame1_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame1,
        .timer = 5
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame2_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame2_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame2,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame3_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame3_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame3,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame4_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame4_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame4,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame5_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame5_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame5,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame6_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame6_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame6,
        .timer = 5
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame7_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame7_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame7,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame8_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame8_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame8,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame9_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Frame9_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Left_Frame9,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningOnHorizontalLadder_Left[3] = {
    {
        .pTopGfx = sSamusGfx_TurningOnHorizontalLadder_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningOnHorizontalLadder_Frame0_Bottom,
        .pOam = sSamusOam_TurningOnHorizontalLadder_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_TurningOnHorizontalLadder_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningOnHorizontalLadder_Frame0_Bottom,
        .pOam = sSamusOam_TurningOnHorizontalLadder_Right_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_TurningOnHorizontalLadder_Right[3] = {
    {
        .pTopGfx = sSamusGfx_TurningOnHorizontalLadder_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_TurningOnHorizontalLadder_Frame0_Bottom,
        .pOam = sSamusOam_TurningOnHorizontalLadder_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_TurningOnHorizontalLadder_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_TurningOnHorizontalLadder_Frame0_Bottom,
        .pOam = sSamusOam_TurningOnHorizontalLadder_Left_Frame0,
        .timer = 2
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2d691c[5] = {
    {
        .pTopGfx = sSamusGfx_2d2572,
        .pBottomGfx = sSamusGfx_2d0fbe,
        .pOam = sSamusOam_2d5c46,
        .timer = 14
    },
    {
        .pTopGfx = sSamusGfx_2d2674,
        .pBottomGfx = sSamusGfx_2d1162,
        .pOam = sSamusOam_2d5c46,
        .timer = 14
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame9_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Frame9_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame9,
        .timer = 14
    },
    {
        .pTopGfx = sSamusGfx_2d2674,
        .pBottomGfx = sSamusGfx_2d1162,
        .pOam = sSamusOam_2d5c46,
        .timer = 14
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_MovingOnHorizontalLadder_Right[11] = {
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame4_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame5_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame1,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame2_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame6_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame2,
        .timer = 5
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame3_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame7_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame3,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame4_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame8_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame4,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame5_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame0_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame5,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame6_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame1_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame6,
        .timer = 5
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame7_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame2_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame7,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame8_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Left_Frame3_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame8,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_MovingOnHorizontalLadder_Right_Frame9_Top,
        .pBottomGfx = sSamusGfx_MovingOnHorizontalLadder_Frame9_Bottom,
        .pOam = sSamusOam_MovingOnHorizontalLadder_Right_Frame9,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_AfterShootingOnHorizontalLadder_Default_Left[2] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Default_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnHorizontalLadder_Default_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Default_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Default_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_AfterShootingOnHorizontalLadder_DiagonalDown_Left[2] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnHorizontalLadder_DiagonalDown_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_AfterShootingOnHorizontalLadder_Down_Left[2] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Down_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnHorizontalLadder_Down_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Down_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Down_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_AfterShootingOnHorizontalLadder_Default_Right[2] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Default_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnHorizontalLadder_Default_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Default_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Default_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Default_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_AfterShootingOnHorizontalLadder_DiagonalDown_Right[2] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnHorizontalLadder_DiagonalDown_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_DiagonalDown_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_DiagonalDown_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_AfterShootingOnHorizontalLadder_Down_Right[2] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Down_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnHorizontalLadder_Down_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Down_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_ShootingOnHorizontalLadder_Down_Frame1_Bottom,
        .pOam = sSamusOam_ShootingOnHorizontalLadder_Down_Right_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_LoweringDownToStartHanging_Left[3] = {
    {
        .pTopGfx = sSamusGfx_PullingUpFromHanging_Left_Frame1_Top,
        .pBottomGfx = sSamusGfx_PullingUpFromHanging_Frame1_Bottom,
        .pOam = sSamusOam_PullingUpFromHanging_Left_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Left_Frame0,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_LoweringDownToStartHanging_Right[3] = {
    {
        .pTopGfx = sSamusGfx_PullingUpFromHanging_Right_Frame1_Top,
        .pBottomGfx = sSamusGfx_PullingUpFromHanging_Frame1_Bottom,
        .pOam = sSamusOam_PullingUpFromHanging_Right_Frame1,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_Default_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_Default_Right_Frame0,
        .timer = 3
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2d6c5c[8] = {
    {
        .pTopGfx = sSamusGfx_2d40ee,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_2d5ef6,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d40ee,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_2d5ef6,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d40ee,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_2d5ef6,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d40ee,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_2d5ef6,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d4210,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_2d5f16,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d4332,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame5_Bottom,
        .pOam = sSamusOam_2d5f36,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d4210,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_2d5f16,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Unused_2d6cdc[8] = {
    {
        .pTopGfx = sSamusGfx_2d4454,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_2d5f56,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d4454,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_2d5f56,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d4454,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_2d5f56,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d4454,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame3_Bottom,
        .pOam = sSamusOam_2d5f56,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d4576,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_2d5f56,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d4698,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame5_Bottom,
        .pOam = sSamusOam_2d5f96,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_2d4576,
        .pBottomGfx = sSamusGfx_HangingOnLedge_Default_Frame1_Bottom,
        .pOam = sSamusOam_2d5f56,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_Up_Right[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Up_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Up_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_Up_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Up_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Up_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Up_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Up_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Up_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_Down_Right[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Down_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Down_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Down_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_Down_Right[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_Down_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Down_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Down_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Down_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Down_Right_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Down_Right_Frame0,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_Up_Left[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Up_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Up_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_Up_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Up_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Up_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Up_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Up_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Up_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ArmOutOnVerticalLadder_Down_Left[2] = {
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Down_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Down_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Down_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ShootingOnVerticalLadder_Down_Left[3] = {
    {
        .pTopGfx = sSamusGfx_ShootingOnVerticalLadder_Down_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ShootingOnVerticalLadder_Down_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Down_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_ArmOutOnVerticalLadder_Down_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_ArmOutOnVerticalLadder_Down_Left_Frame0_Bottom,
        .pOam = sSamusOam_ShootingOnVerticalLadder_Down_Left_Frame1,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_HangingOnLedge_PushingAway_Left[8] = {
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Left_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Left_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Left_Frame0,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_HangingOnLedge_PushingAway_Right[8] = {
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Right_Frame0,
        .timer = 16
    },
    {
        .pTopGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Top,
        .pBottomGfx = sSamusGfx_HangingOnLedge_PushingAway_Right_Frame0_Bottom,
        .pOam = sSamusOam_HangingOnLedge_PushingAway_Right_Frame0,
        .timer = 16
    },
    SAMUS_ANIM_TERMINATOR
};

static const u8 sSamusGfx_SpaceJumping_Frame0_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/space_jumping_frame_0_top.gfx")
};

static const u8 sSamusGfx_SpaceJumping_Frame1_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/space_jumping_frame_1_top.gfx")
};

static const u8 sSamusGfx_SpaceJumping_Frame2_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/space_jumping_frame_2_top.gfx")
};

static const u8 sSamusGfx_SpaceJumping_Frame3_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/space_jumping_frame_3_top.gfx")
};

static const u8 sSamusGfx_ScrewAttacking_Frame12_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/screw_attacking_frame_12_top.gfx")
};

static const u8 sSamusGfx_ScrewAttacking_Frame13_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/screw_attacking_frame_13_top.gfx")
};

static const u8 sSamusGfx_ScrewAttacking_Frame10_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/screw_attacking_frame_10_top.gfx")
};

static const u8 sSamusGfx_ScrewAttacking_Frame11_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/screw_attacking_frame_11_top.gfx")
};

static const u16 sSamusOam_SpaceJumping_Left_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -27, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_SpaceJumping_Left_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -11, OAM_DIMS_32x16, OAM_XY_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_32x16, OAM_XY_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_SpaceJumping_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -27, OAM_DIMS_32x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x16, OAM_X_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_SpaceJumping_Right_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -11, OAM_DIMS_32x16, OAM_Y_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_32x16, OAM_Y_FLIP, 0x4, 0, 0),
};

const struct SamusAnimData sSamusAnim_SpaceJumping_Left[9] = {
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_SpaceJumping_Right[9] = {
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ScrewAttacking_Left[17] = {
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame13_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame11_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame12_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame13_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame11_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame12_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame13_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame11_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Left_Frame4,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_ScrewAttacking_Right[17] = {
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_SpaceJumping_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame13_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame11_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame12_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame13_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame11_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame12_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame13_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_ScrewAttacking_Frame11_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_SpaceJumping_Right_Frame4,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};

static const u8 sSamusGfx_Dying_Frame0_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/dying_frame_0_top.gfx")
};

static const u8 sSamusGfx_Dying_Frame1_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/dying_frame_1_top.gfx")
};

static const u8 sSamusGfx_Dying_Frame2_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/dying_frame_2_top.gfx")
};

static const u8 sSamusGfx_Dying_Frame4_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/dying_frame_4_top.gfx")
};

static const u8 sSamusGfx_Dying_Frame5_Top[SAMUS_GFX_SIZE(8, 8)] = {
    8, 8,
    _INCBIN_U8("data/samus/graphics/body/dying_frame_5_top.gfx")
};

static const u8 sSamusGfx_Dying_Frame6_Top[SAMUS_GFX_SIZE(9, 8)] = {
    9, 8,
    _INCBIN_U8("data/samus/graphics/body/dying_frame_6_top.gfx")
};

static const u8 sSamusGfx_Dying_Frame7_Top[SAMUS_GFX_SIZE(4, 0)] = {
    4, 0,
    _INCBIN_U8("data/samus/graphics/body/dying_frame_7_top.gfx")
};

static const u8 sSamusGfx_Dying_Frame8_Top[SAMUS_GFX_SIZE(2, 0)] = {
    2, 0,
    _INCBIN_U8("data/samus/graphics/body/dying_frame_8_top.gfx")
};

static const u16 sSamusOam_Dying_Left_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_Dying_Left_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
};

static const u16 sSamusOam_Dying_Left_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-21, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(2, -34, OAM_DIMS_8x8, OAM_Y_FLIP, 0x1, 0, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(10, -49, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_Dying_Left_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(4, -34, OAM_DIMS_8x8, OAM_XY_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-26, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 0, 0),
};

static const u16 sSamusOam_Dying_Right_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x4, 0, 0),
};

static const u16 sSamusOam_Dying_Right_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x4, 0, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x8, 0, 0),
};

static const u16 sSamusOam_Dying_Right_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(13, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-10, -34, OAM_DIMS_8x8, OAM_XY_FLIP, 0x1, 0, 0),
    OAM_ENTRY(10, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-18, -49, OAM_DIMS_8x8, OAM_X_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_Dying_Right_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -34, OAM_DIMS_8x8, OAM_Y_FLIP, 0x0, 0, 0),
    OAM_ENTRY(18, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x1, 0, 0),
};

const struct SamusAnimData sSamusAnim_Dying_Left[11] = {
    {
        .pTopGfx = sSamusGfx_Dying_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Left_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Left_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame4_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame5_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Left_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame6_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Left_Frame6,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame7_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Left_Frame7,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame8_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Left_Frame8,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame8_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Empty,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

const struct SamusAnimData sSamusAnim_Dying_Right[11] = {
    {
        .pTopGfx = sSamusGfx_Dying_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Right_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame0_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Right_Frame0,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame4_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame5_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Right_Frame0,
        .timer = 2
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame6_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Right_Frame6,
        .timer = 3
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame7_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Right_Frame7,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame8_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Dying_Right_Frame8,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_Dying_Frame8_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Empty,
        .timer = 4
    },
    SAMUS_ANIM_TERMINATOR
};

static const u8 sSamusGfx_LoadingSave_Frame1_Top[SAMUS_GFX_SIZE(5, 3)] = {
    5, 3,
    _INCBIN_U8("data/samus/graphics/body/loading_save_frame_1_top.gfx")
};

static const u8 sSamusGfx_LoadingSave_Frame3_Top[SAMUS_GFX_SIZE(5, 5)] = {
    5, 5,
    _INCBIN_U8("data/samus/graphics/body/loading_save_frame_3_top.gfx")
};

static const u8 sSamusGfx_LoadingSave_Frame5_Top[SAMUS_GFX_SIZE(8, 5)] = {
    8, 5,
    _INCBIN_U8("data/samus/graphics/body/loading_save_frame_5_top.gfx")
};

static const u8 sSamusGfx_LoadingSave_Frame2_Top[SAMUS_GFX_SIZE(8, 6)] = {
    8, 6,
    _INCBIN_U8("data/samus/graphics/body/loading_save_frame_2_top.gfx")
};

static const u8 sSamusGfx_LoadingSave_Frame4_Top[SAMUS_GFX_SIZE(8, 6)] = {
    8, 6,
    _INCBIN_U8("data/samus/graphics/body/loading_save_frame_4_top.gfx")
};

static const u8 sSamusGfx_LoadingSave_Frame10_Top[SAMUS_GFX_SIZE(9, 6)] = {
    9, 6,
    _INCBIN_U8("data/samus/graphics/body/loading_save_frame_10_top.gfx")
};

static const u16 sSamusOam_LoadingSave_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-12, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_LoadingSave_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(5, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
};

static const u16 sSamusOam_LoadingSave_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-13, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(3, -39, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-13, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
};

static const u16 sSamusOam_LoadingSave_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-12, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
};

static const u16 sSamusOam_LoadingSave_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-12, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
};

static const u16 sSamusOam_LoadingSave_Frame10[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5, 0, 0),
};

const struct SamusAnimData sSamusAnim_LoadingSave[29] = {
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_Empty,
        .timer = 10
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame1_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame1,
        .timer = 7
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame2,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame3_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame3,
        .timer = 7
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame4_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame4,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame5_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame5,
        .timer = 7
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame2_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame2,
        .timer = 7
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame4_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame4,
        .timer = 7
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 4
    },
    {
        .pTopGfx = sSamusGfx_LoadingSave_Frame10_Top,
        .pBottomGfx = sSamusGfx_Empty,
        .pOam = sSamusOam_LoadingSave_Frame10,
        .timer = 180
    },
    SAMUS_ANIM_TERMINATOR
};

static const u8 sSamusGfx_Saving_Frame32_Top[SAMUS_GFX_SIZE(19, 1)] = {
    19, 1,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_32_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame0_Bottom[SAMUS_GFX_SIZE(10, 8)] = {
    10, 8,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_0_bottom.gfx")
};

static const u8 sSamusGfx_Saving_Frame34_Top[SAMUS_GFX_SIZE(17, 2)] = {
    17, 2,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_34_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame36_Top[SAMUS_GFX_SIZE(16, 3)] = {
    16, 3,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_36_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame38_Top[SAMUS_GFX_SIZE(16, 3)] = {
    16, 3,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_38_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame33_Top[SAMUS_GFX_SIZE(20, 16)] = {
    20, 16,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_33_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame11_Bottom[SAMUS_GFX_SIZE(12, 8)] = {
    12, 8,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_11_bottom.gfx")
};

static const u8 sSamusGfx_Saving_Frame35_Top[SAMUS_GFX_SIZE(20, 15)] = {
    20, 15,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_35_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame37_Top[SAMUS_GFX_SIZE(20, 15)] = {
    20, 15,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_37_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame39_Top[SAMUS_GFX_SIZE(20, 15)] = {
    20, 15,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_39_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame1_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_1_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame3_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_3_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame5_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_5_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame7_Top[SAMUS_GFX_SIZE(4, 4)] = {
    4, 4,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_7_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame57_Top[SAMUS_GFX_SIZE(13, 5)] = {
    13, 5,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_57_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame11_Top[SAMUS_GFX_SIZE(11, 5)] = {
    11, 5,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_11_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame13_Top[SAMUS_GFX_SIZE(11, 5)] = {
    11, 5,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_13_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame15_Top[SAMUS_GFX_SIZE(12, 6)] = {
    12, 6,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_15_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame17_Top[SAMUS_GFX_SIZE(17, 9)] = {
    17, 9,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_17_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame19_Top[SAMUS_GFX_SIZE(15, 9)] = {
    15, 9,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_19_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame21_Top[SAMUS_GFX_SIZE(15, 9)] = {
    15, 9,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_21_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame23_Top[SAMUS_GFX_SIZE(16, 10)] = {
    16, 10,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_23_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame16_Top[SAMUS_GFX_SIZE(10, 0)] = {
    10, 0,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_16_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame18_Top[SAMUS_GFX_SIZE(10, 1)] = {
    10, 1,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_18_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame20_Top[SAMUS_GFX_SIZE(9, 2)] = {
    9, 2,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_20_top.gfx")
};

static const u8 sSamusGfx_Saving_Frame22_Top[SAMUS_GFX_SIZE(8, 1)] = {
    8, 1,
    _INCBIN_U8("data/samus/graphics/body/saving_frame_22_top.gfx")
};

static const u16 sSamusOam_Saving_Frame32[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(16, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(-27, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(-19, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1, 0, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-21, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(7, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-24, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x11, 0, 0),
    OAM_ENTRY(-26, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x12, 0, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x12, 0, 0),
    OAM_ENTRY(-10, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x12, 0, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(18, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x12, 0, 0),
};

static const u16 sSamusOam_Saving_Frame34[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-21, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(8, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-20, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-26, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-21, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(-13, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(17, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10, 0, 0),
};

static const u16 sSamusOam_Saving_Frame36[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-26, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(16, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-8, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(-24, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-22, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-11, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(-29, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-26, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-18, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x9, 0, 0),
};

static const u16 sSamusOam_Saving_Frame38[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(16, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-19, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(-9, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(7, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-23, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-25, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-17, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(14, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
};

static const u16 sSamusOam_Saving_Frame33[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(16, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x13, 0, 0),
    OAM_ENTRY(-27, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x29, 0, 0),
    OAM_ENTRY(-19, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a, 0, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(-21, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(7, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-24, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(-26, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f, 0, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f, 0, 0),
    OAM_ENTRY(-10, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f, 0, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x11, 0, 0),
    OAM_ENTRY(18, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame35[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-24, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a, 0, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b, 0, 0),
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c, 0, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c, 0, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-21, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(8, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-20, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d, 0, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(-26, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x12, 0, 0),
    OAM_ENTRY(-21, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(-13, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(17, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame37[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-26, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x13, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b, 0, 0),
    OAM_ENTRY(1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b, 0, 0),
    OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c, 0, 0),
    OAM_ENTRY(16, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-8, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(-24, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-22, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-11, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d, 0, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d, 0, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-29, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(-26, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(-18, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x11, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame39[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x11, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x12, 0, 0),
    OAM_ENTRY(4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x12, 0, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x13, 0, 0),
    OAM_ENTRY(16, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-19, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b, 0, 0),
    OAM_ENTRY(-9, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b, 0, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(7, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-23, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d, 0, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d, 0, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(-25, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-17, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(14, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
};

static const u16 sSamusOam_Saving_Frame57[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(16, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-27, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-19, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-26, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(-10, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(18, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame11[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-24, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-26, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-21, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-13, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(17, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame13[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-26, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(16, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-29, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-26, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-18, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame15[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(16, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-25, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-17, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(14, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame17[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(16, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(-27, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-19, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-26, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(-10, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(18, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame19[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-26, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-21, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-13, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(17, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame21[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-26, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(16, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-29, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-26, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-18, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame23[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe, 0, 0),
    OAM_ENTRY(16, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-25, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-17, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(14, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x1e, 0, 0),
};

static const u16 sSamusOam_Saving_Frame16[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-5, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-21, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(7, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-24, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 0, 0),
};

static const u16 sSamusOam_Saving_Frame18[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-5, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1, 0, 0),
    OAM_ENTRY(-21, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
    OAM_ENTRY(8, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-20, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(-20, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7, 0, 0),
};

static const u16 sSamusOam_Saving_Frame20[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-24, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-22, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1, 0, 0),
    OAM_ENTRY(-11, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6, 0, 0),
};

static const u16 sSamusOam_Saving_Frame22[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-19, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-9, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5, 0, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1, 0, 0),
    OAM_ENTRY(7, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(-23, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x7, 0, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3, 0, 0),
};

static const u16 sSamusOam_Saving_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 0, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c, 0, 0),
};

const struct SamusAnimData sSamusAnim_Saving[73] = {
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame1_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame3_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame5_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame7_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame57_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame57,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame11_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame11,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame13_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame13,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame15_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame15,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame16_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame16,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame17_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame17,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame18_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame18,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame19_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame19,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame20_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame20,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame21_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame21,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame22_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame22,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame23_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame23,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame16_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame16,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame17_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame17,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame18_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame18,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame19_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame19,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame20_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame20,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame21_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame21,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame22_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame22,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame23_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame23,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame32_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame32,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame33_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame33,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame34_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame34,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame35_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame35,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame36_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame36,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame37_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame37,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame38_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame38,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame39_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame39,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame16_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame16,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame17_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame17,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame18_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame18,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame19_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame19,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame20_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame20,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame21_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame21,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame22_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame22,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame23_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame23,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame16_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame16,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame17_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame17,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame18_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame18,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame19_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame19,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame20_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame20,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame21_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame21,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame22_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame22,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame23_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame23,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame57_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame57,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame11_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame11,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame13_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame13,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame15_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame11_Bottom,
        .pOam = sSamusOam_Saving_Frame15,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame1_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame3_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame5_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame1,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Empty,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame0,
        .timer = 1
    },
    {
        .pTopGfx = sSamusGfx_Saving_Frame7_Top,
        .pBottomGfx = sSamusGfx_Saving_Frame0_Bottom,
        .pOam = sSamusOam_Saving_Frame1,
        .timer = 1
    },
    SAMUS_ANIM_TERMINATOR
};
