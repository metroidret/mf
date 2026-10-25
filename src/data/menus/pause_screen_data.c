#include "data/menus/pause_screen_data.h"

#include "macros.h"
#include "constants/menus/pause_screen.h"

const u8 sMinimapTilesGfx[32 * 14 * TILE_SIZE] = INCBIN_U8("data/menus/pause_screen/minimap_tiles.gfx");
const u16 sMinimapTilesPal[3 * PAL_ROW] = INCBIN_U16("data/menus/pause_screen/minimap_tiles.pal");

const u16 sPauseScreenBgPal_565808[13 * PAL_ROW] = INCBIN_U16("data/menus/pause_screen/bg_565808.pal");
const u16 sPauseScreenBgPal_5659a8[13 * PAL_ROW] = INCBIN_U16("data/menus/pause_screen/bg_5659a8.pal");
const u16 sPauseScreenObjPal_565b48[16 * PAL_ROW] = INCBIN_U16("data/menus/pause_screen/obj_565b48.pal");
const u16 sNavConversationSamusPal[3 * PAL_ROW] = INCBIN_U16("data/menus/pause_screen/nav_conversation_samus.pal");

static const u16 sPauseScreenOam_BlinkingSquare_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3f4, 3, 0),
};

static const u16 sPauseScreenOam_Frame_565db0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x220, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0x220, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x220, 3, 0),
};

static const u16 sPauseScreenOam_Frame_565dca[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 3, 0),
    OAM_ENTRY(1, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x220, 3, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_XY_FLIP, 0x220, 3, 0),
    OAM_ENTRY(-9, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x220, 3, 0),
};

static const u16 sPauseScreenOam_MapPreviewPoint_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 3, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_8x8, OAM_XY_FLIP, 0x221, 3, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 3, 0),
    OAM_ENTRY(-13, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 3, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x322, 3, 0),
};

static const u16 sPauseScreenOam_MapPreviewPoint_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 3, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x221, 3, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 3, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 3, 0),
};

static const u16 sPauseScreenOam_MapPreviewPoint_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 3, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_XY_FLIP, 0x221, 3, 0),
    OAM_ENTRY(3, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 3, 0),
    OAM_ENTRY(-11, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 3, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x322, 3, 0),
};

static const u16 sPauseScreenOam_MapPreviewPoint_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 3, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x221, 3, 0),
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 3, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 3, 0),
};

static const u16 sPauseScreenOam_MapUpArrow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 3, 0),
};

static const u16 sPauseScreenOam_MapDownArrow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_Y_FLIP, 0x200, 3, 0),
};

static const u16 sPauseScreenOam_MapLeftArrow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 3, 0),
};

static const u16 sPauseScreenOam_MapRightArrow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 3, 0),
};

static const u16 sPauseScreenOam_PauseDebugCursorArrows_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 3, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x260, 3, 0),
};

static const u16 sPauseScreenOam_PauseDebugCursorArrows_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 3, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_Y_FLIP, 0x260, 3, 0),
};

static const u16 sPauseScreenOam_PauseDebugCursorArrows_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 3, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x8, OAM_Y_FLIP, 0x260, 3, 0),
};

static const u16 sPauseScreenOam_PauseDebugCursorDownArrow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 3, 0),
};

static const u16 sPauseScreenOam_PauseDebugCursorDownArrow_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 3, 0),
};

static const u16 sPauseScreenOam_PauseDebugCursorDownArrow_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 3, 0),
};

static const u16 sPauseScreenOam_NavTextCursor_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x223, 3, 0),
};

static const u16 sPauseScreenOam_BlinkingSquare_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 9, 0),
};

static const u16 sPauseScreenOam_Unk13_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 3, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 3, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 3, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 3, 0),
};

static const u16 sPauseScreenOam_NavTextArrow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ac, 3, 0),
};

static const u16 sPauseScreenOam_NavTextArrow_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ac, 3, 0),
};

static const u16 sPauseScreenOam_NavTextArrow_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ac, 3, 0),
};

static const u16 sPauseScreenOam_YesNoCursor_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 3, 0),
};

static const u16 sPauseScreenOam_YesNoCursor_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 3, 0),
};

static const u16 sPauseScreenOam_YesNoCursor_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetAbove_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d6, 3, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f3, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetAbove_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f3, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetAbove_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d6, 3, 0),
    OAM_ENTRY(-16, -23, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2d7, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f4, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetAbove_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f4, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetAbove_Frame16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d6, 3, 0),
    OAM_ENTRY(-16, -22, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f5, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetAbove_Frame17[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f5, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetAbove_Frame24[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d6, 3, 0),
    OAM_ENTRY(-16, -23, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2d7, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f6, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetAbove_Frame25[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f6, 3, 0),
};

const u16 sPauseScreenOam_Frame_565f90[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2d6, 3, 0),
    OAM_ENTRY(-16, -22, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f6, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorUpArrows_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorUpArrows_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorUpArrows_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorUpArrows_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorUpArrows_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorUpArrows_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorDownArrows_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorDownArrows_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_Y_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorDownArrows_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_Y_FLIP, 0x242, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorDownArrows_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorDownArrows_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x242, 3, 0),
};

static const u16 sPauseScreenOam_MapElevatorDownArrows_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0),
};

static const u16 sPauseScreenOam_DownloadScanLineTrailing_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-128, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(-96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
};

static const u16 sPauseScreenOam_DownloadScanLineTrailing_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-128, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(-96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
};

static const u16 sPauseScreenOam_DownloadScanLineTrailing_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-128, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(-96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
};

static const u16 sPauseScreenOam_DownloadScanLineTrailing_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-128, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
};

static const u16 sPauseScreenOam_MapTargetBelow_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2d6, 3, 0),
    OAM_ENTRY(-16, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f3, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetBelow_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2d6, 3, 0),
    OAM_ENTRY(-16, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2d7, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f4, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetBelow_Frame16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2d6, 3, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f5, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetBelow_Frame24[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2d6, 3, 0),
    OAM_ENTRY(-16, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2d7, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f6, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetLeft_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e4, 3, 0),
    OAM_ENTRY(-39, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f3, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetLeft_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e4, 3, 0),
    OAM_ENTRY(-39, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2d7, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f4, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetLeft_Frame16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e4, 3, 0),
    OAM_ENTRY(-39, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f5, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetLeft_Frame24[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e4, 3, 0),
    OAM_ENTRY(-39, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2d7, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f6, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetRight_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e4, 3, 0),
    OAM_ENTRY(7, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f3, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetRight_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e4, 3, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2d7, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f4, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetRight_Frame16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e4, 3, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2db, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f5, 3, 0),
};

static const u16 sPauseScreenOam_MapTargetRight_Frame24[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e4, 3, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2d7, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f6, 3, 0),
};

static const u16 sPauseScreenOam_MapUpArrow_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 3, 0),
};

static const u16 sPauseScreenOam_MapUpArrow_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 3, 0),
};

static const u16 sPauseScreenOam_MapDownArrow_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -3, OAM_DIMS_16x8, OAM_Y_FLIP, 0x200, 3, 0),
};

static const u16 sPauseScreenOam_MapDownArrow_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -2, OAM_DIMS_16x8, OAM_Y_FLIP, 0x200, 3, 0),
};

static const u16 sPauseScreenOam_MapLeftArrow_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 3, 0),
};

static const u16 sPauseScreenOam_MapLeftArrow_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 3, 0),
};

static const u16 sPauseScreenOam_MapRightArrow_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 3, 0),
};

static const u16 sPauseScreenOam_MapRightArrow_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-2, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 3, 0),
};

static const u16 sPauseScreenOam_BslDiagramTargetAbove_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a8, 3, 0),
    OAM_ENTRY(15, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(15, -23, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ec, 8, 0),
    OAM_ENTRY(37, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x305, 3, 0),
    OAM_ENTRY(31, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e8, 3, 0),
};

static const u16 sPauseScreenOam_BslDiagramTargetAbove_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(15, -23, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ec, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramTargetAbove_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a8, 3, 0),
    OAM_ENTRY(15, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(37, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x305, 3, 0),
    OAM_ENTRY(31, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(15, -23, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3f0, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramTargetAbove_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(15, -23, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3f0, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramTargetBelow_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2a8, 3, 0),
    OAM_ENTRY(15, 7, OAM_DIMS_16x8, OAM_Y_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(15, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ec, 8, 0),
    OAM_ENTRY(37, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x305, 3, 0),
    OAM_ENTRY(31, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2e8, 3, 0),
};

static const u16 sPauseScreenOam_BslDiagramTargetBelow_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(15, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ec, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramTargetBelow_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2a8, 3, 0),
    OAM_ENTRY(15, 7, OAM_DIMS_16x8, OAM_Y_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(37, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x305, 3, 0),
    OAM_ENTRY(31, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(15, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3f0, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramTargetBelow_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(15, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3f0, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramStartAbove_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a8, 3, 0),
    OAM_ENTRY(15, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(31, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x305, 3, 0),
    OAM_ENTRY(15, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3d8, 8, 0),
    OAM_ENTRY(31, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3da, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramStartAbove_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(15, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3d8, 8, 0),
    OAM_ENTRY(31, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3da, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramStartAbove_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a8, 3, 0),
    OAM_ENTRY(15, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(31, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x305, 3, 0),
    OAM_ENTRY(15, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3db, 8, 0),
    OAM_ENTRY(31, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3dd, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramStartAbove_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(15, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3db, 8, 0),
    OAM_ENTRY(31, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3dd, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramStartBelow_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2a8, 3, 0),
    OAM_ENTRY(15, 7, OAM_DIMS_16x8, OAM_Y_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(31, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x305, 3, 0),
    OAM_ENTRY(15, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3d8, 8, 0),
    OAM_ENTRY(31, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3da, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramStartBelow_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(15, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3d8, 8, 0),
    OAM_ENTRY(31, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3da, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramStartBelow_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2a8, 3, 0),
    OAM_ENTRY(15, 7, OAM_DIMS_16x8, OAM_Y_FLIP, 0x2e8, 3, 0),
    OAM_ENTRY(31, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x305, 3, 0),
    OAM_ENTRY(15, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3db, 8, 0),
    OAM_ENTRY(31, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3dd, 8, 0),
};

static const u16 sPauseScreenOam_BslDiagramStartBelow_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(15, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3db, 8, 0),
    OAM_ENTRY(31, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3dd, 8, 0),
};

static const u16 sPauseScreenOam_ObjectiveButton_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-37, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3ae, 3, 0),
    OAM_ENTRY(-23, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3d0, 3, 0),
    OAM_ENTRY(9, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3d4, 3, 0),
};

static const u16 sPauseScreenOam_Sector1Text_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x390, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3b0, 8, 0),
};

static const u16 sPauseScreenOam_Sector2Text_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x390, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3b1, 8, 0),
};

static const u16 sPauseScreenOam_Sector3Text_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x390, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3b2, 8, 0),
};

static const u16 sPauseScreenOam_Sector4Text_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x390, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3b3, 8, 0),
};

static const u16 sPauseScreenOam_Sector5Text_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x390, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3b4, 8, 0),
};

static const u16 sPauseScreenOam_Sector6Text_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x390, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3b5, 8, 0),
};

static const u16 sPauseScreenOam_AreaTextAppearing_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x314, 8, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x316, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x314, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x316, 8, 0),
};

static const u16 sPauseScreenOam_AreaTextAppearing_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x334, 8, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x336, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x334, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x336, 8, 0),
};

static const u16 sPauseScreenOam_AreaTextAppearing_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x354, 8, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x356, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x354, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x356, 8, 0),
};

static const u16 sPauseScreenOam_AreaTextAppearing_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x374, 8, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x376, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x374, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x376, 8, 0),
};

static const u16 sPauseScreenOam_AreaTextAppearing_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x374, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x374, 8, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x375, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x375, 8, 0),
};

static const u16 sPauseScreenOam_SleepButton_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x37b, 11, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x37f, 11, 0),
};

static const u16 sPauseScreenOam_SleepButton_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x37b, 12, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x37f, 12, 0),
};

static const u16 sPauseScreenOam_SleepButton_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x37b, 13, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x37f, 13, 0),
};

static const u16 sPauseScreenOam_SleepButton_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x37b, 7, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x37f, 7, 0),
};

static const u16 sPauseScreenOam_StatusButton_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x39b, 11, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x39f, 11, 0),
};

static const u16 sPauseScreenOam_StatusButton_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x39b, 12, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x39f, 12, 0),
};

static const u16 sPauseScreenOam_StatusButton_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x39b, 13, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x39f, 13, 0),
};

static const u16 sPauseScreenOam_StatusButton_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x39b, 7, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x39f, 7, 0),
};

static const u16 sPauseScreenOam_L1Lock_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c0, 7, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1c2, 7, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1cc, 3, 0),
};

static const u16 sPauseScreenOam_L2Lock_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c3, 7, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1c5, 7, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1cc, 3, 0),
};

static const u16 sPauseScreenOam_L3Lock_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c6, 7, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1c8, 7, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1cc, 3, 0),
};

static const u16 sPauseScreenOam_L4Lock_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1c9, 7, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1cb, 7, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1cc, 3, 0),
};

static const u16 sPauseScreenOam_L1Open_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e0, 7, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1e2, 7, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1ec, 3, 0),
};

static const u16 sPauseScreenOam_L2Open_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e3, 7, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1e5, 7, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1ec, 3, 0),
};

static const u16 sPauseScreenOam_L3Open_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e6, 7, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1e8, 7, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1ec, 3, 0),
};

static const u16 sPauseScreenOam_L4Open_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e9, 7, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1eb, 7, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1ec, 3, 0),
};

static const u16 sPauseScreenOam_SleepButtonSelected_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x37b, 3, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x37f, 3, 0),
};

static const u16 sPauseScreenOam_SleepButtonSelected_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x37b, 5, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x37f, 5, 0),
};

static const u16 sPauseScreenOam_StatusButtonSelected_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x39b, 3, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x39f, 3, 0),
};

static const u16 sPauseScreenOam_StatusButtonSelected_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x39b, 5, 0),
    OAM_ENTRY(12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x39f, 5, 0),
};

static const u16 sPauseScreenOam_MainDeckText_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x395, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x399, 8, 0),
};

static const u16 sPauseScreenOam_CollectedEnergyTanks_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1b8, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1bc, 8, 0),
};

static const u16 sPauseScreenOam_CollectedMissileTanks_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1d8, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1dc, 8, 0),
};

static const u16 sPauseScreenOam_CollectedPowerBombTanks_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1f8, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1fc, 8, 0),
};

static const u16 sPauseScreenOam_InGameTimer_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x198, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x19c, 8, 0),
};

static const u16 sPauseScreenOam_EnergyTankCheckMark_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1b6, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x194, 3, 0),
};

static const u16 sPauseScreenOam_MissileTankCheckMark_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1b6, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1b4, 3, 0),
};

static const u16 sPauseScreenOam_PowerBombTankCheckMark_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1b6, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x196, 3, 0),
};

static const u16 sPauseScreenOam_NavigationPad_Frame0[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14d, 1, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x14d, 1, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x111, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x32, OAM_X_FLIP, 0x111, 2, 0),
    OAM_ENTRY(-48, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_32x32, OAM_X_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0xbd, 2, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0xbf, 2, 0),
    OAM_ENTRY(8, 24, OAM_DIMS_16x8, OAM_X_FLIP, 0xbd, 2, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0xbf, 2, 0),
};

static const u16 sPauseScreenOam_NavigationPad_Frame1[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x149, 1, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x149, 1, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x111, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x32, OAM_X_FLIP, 0x111, 2, 0),
    OAM_ENTRY(-48, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_32x32, OAM_X_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0xbd, 2, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0xbf, 2, 0),
    OAM_ENTRY(8, 24, OAM_DIMS_16x8, OAM_X_FLIP, 0xbd, 2, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0xbf, 2, 0),
};

static const u16 sPauseScreenOam_NavigationPad_Frame2[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x145, 1, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x145, 1, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x111, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x32, OAM_X_FLIP, 0x111, 2, 0),
    OAM_ENTRY(-48, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_32x32, OAM_X_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0xbd, 2, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0xbf, 2, 0),
    OAM_ENTRY(8, 24, OAM_DIMS_16x8, OAM_X_FLIP, 0xbd, 2, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0xbf, 2, 0),
};

static const u16 sPauseScreenOam_NavigationPadWithSamus_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 0x115, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_X_FLIP, 0x115, 2, 0),
    OAM_ENTRY(-15, -40, OAM_DIMS_32x32, OAM_NO_FLIP, 0xe0, 0, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x160, 0, 0),
    OAM_ENTRY(-48, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_32x32, OAM_X_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14d, 1, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x14d, 1, 0),
};

static const u16 sPauseScreenOam_NavigationPadWithSamus_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-15, -40, OAM_DIMS_32x32, OAM_NO_FLIP, 0xe0, 0, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x160, 0, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 0x115, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_X_FLIP, 0x115, 2, 0),
    OAM_ENTRY(-48, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_32x32, OAM_X_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x149, 1, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x149, 1, 0),
};

static const u16 sPauseScreenOam_NavigationPadWithSamus_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-15, -40, OAM_DIMS_32x32, OAM_NO_FLIP, 0xe0, 0, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x160, 0, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 0x115, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_X_FLIP, 0x115, 2, 0),
    OAM_ENTRY(-48, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_32x32, OAM_X_FLIP, 0x11a, 1, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x15e, 1, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0xfe, 1, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x145, 1, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x145, 1, 0),
};

static const u16 sPauseScreenOam_LockedHatchLeft_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x104, 4, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x32, OAM_XY_FLIP, 0x104, 4, 0),
};

static const u16 sPauseScreenOam_LockedHatchRight_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x104, 4, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x104, 4, 0),
};

const struct FrameData sPauseScreenOam_BlinkingSquare[3] = {
    [0] = {
        .pFrame = sPauseScreenOam_BlinkingSquare_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_BlinkingSquare_Frame1,
        .timer = 8
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_YesNoCursor[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_YesNoCursor_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_YesNoCursor_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sPauseScreenOam_YesNoCursor_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_YesNoCursor_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_NavTextArrow[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_NavTextArrow_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_NavTextArrow_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sPauseScreenOam_NavTextArrow_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_NavTextArrow_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapPreviewPoint[7] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapPreviewPoint_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapPreviewPoint_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapPreviewPoint_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapPreviewPoint_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sPauseScreenOam_MapPreviewPoint_Frame2,
        .timer = 3
    },
    [5] = {
        .pFrame = sPauseScreenOam_MapPreviewPoint_Frame1,
        .timer = 3
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapUpArrow[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapUpArrow_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapUpArrow_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapUpArrow_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapUpArrow_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapDownArrow[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapDownArrow_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapDownArrow_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapDownArrow_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapDownArrow_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapLeftArrow[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapLeftArrow_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapLeftArrow_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapLeftArrow_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapLeftArrow_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapRightArrow[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapRightArrow_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapRightArrow_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapRightArrow_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapRightArrow_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_PauseDebugCursorArrows[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_PauseDebugCursorArrows_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_PauseDebugCursorArrows_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sPauseScreenOam_PauseDebugCursorArrows_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_PauseDebugCursorArrows_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_PauseDebugCursorDownArrow[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_PauseDebugCursorDownArrow_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_PauseDebugCursorDownArrow_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sPauseScreenOam_PauseDebugCursorDownArrow_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_PauseDebugCursorDownArrow_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_NavTextCursor[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_NavTextCursor_Frame0,
        .timer = 30
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_NavTextCursorBlinking[3] = {
    [0] = {
        .pFrame = sPauseScreenOam_NavTextCursor_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sPauseScreenOam_BlinkingSquare_Frame1,
        .timer = 16
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_Unk13[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_Unk13_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapElevatorUpArrows[8] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapElevatorUpArrows_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapElevatorUpArrows_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapElevatorUpArrows_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapElevatorUpArrows_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sPauseScreenOam_MapElevatorUpArrows_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sPauseScreenOam_MapElevatorUpArrows_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sPauseScreenOam_BlinkingSquare_Frame1,
        .timer = 8
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapElevatorDownArrows[8] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapElevatorDownArrows_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapElevatorDownArrows_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapElevatorDownArrows_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapElevatorDownArrows_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sPauseScreenOam_MapElevatorDownArrows_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sPauseScreenOam_MapElevatorDownArrows_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sPauseScreenOam_BlinkingSquare_Frame1,
        .timer = 8
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_DownloadScanLineTrailing[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_DownloadScanLineTrailing_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_DownloadScanLineTrailing_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_DownloadScanLineTrailing_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_DownloadScanLineTrailing_Frame3,
        .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_DownloadScanLineLeading[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_DownloadScanLineTrailing_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapTargetAbove[33] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame0,
        .timer = 1
    },
    [5] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame0,
        .timer = 1
    },
    [7] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [10] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [12] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame8,
        .timer = 1
    },
    [13] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [14] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame8,
        .timer = 1
    },
    [15] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [16] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [18] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [20] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame16,
        .timer = 1
    },
    [21] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [22] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame16,
        .timer = 1
    },
    [23] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [24] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [26] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [28] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame24,
        .timer = 1
    },
    [29] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [30] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame24,
        .timer = 1
    },
    [31] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [32] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapTargetBelow[33] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame0,
        .timer = 1
    },
    [5] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame0,
        .timer = 1
    },
    [7] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [10] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [12] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame8,
        .timer = 1
    },
    [13] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [14] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame8,
        .timer = 1
    },
    [15] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [16] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [18] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [20] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame16,
        .timer = 1
    },
    [21] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [22] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame16,
        .timer = 1
    },
    [23] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [24] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [26] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [28] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame24,
        .timer = 1
    },
    [29] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [30] = {
        .pFrame = sPauseScreenOam_MapTargetBelow_Frame24,
        .timer = 1
    },
    [31] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [32] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapTargetLeft[33] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame0,
        .timer = 1
    },
    [5] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame0,
        .timer = 1
    },
    [7] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [10] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [12] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame8,
        .timer = 1
    },
    [13] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [14] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame8,
        .timer = 1
    },
    [15] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [16] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [18] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [20] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame16,
        .timer = 1
    },
    [21] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [22] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame16,
        .timer = 1
    },
    [23] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [24] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [26] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [28] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame24,
        .timer = 1
    },
    [29] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [30] = {
        .pFrame = sPauseScreenOam_MapTargetLeft_Frame24,
        .timer = 1
    },
    [31] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [32] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MapTargetRight[33] = {
    [0] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame0,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [4] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame0,
        .timer = 1
    },
    [5] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [6] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame0,
        .timer = 1
    },
    [7] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame8,
        .timer = 1
    },
    [9] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [10] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame8,
        .timer = 1
    },
    [11] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [12] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame8,
        .timer = 1
    },
    [13] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [14] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame8,
        .timer = 1
    },
    [15] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame9,
        .timer = 1
    },
    [16] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame16,
        .timer = 1
    },
    [17] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [18] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame16,
        .timer = 1
    },
    [19] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [20] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame16,
        .timer = 1
    },
    [21] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [22] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame16,
        .timer = 1
    },
    [23] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame17,
        .timer = 1
    },
    [24] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame24,
        .timer = 1
    },
    [25] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [26] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame24,
        .timer = 1
    },
    [27] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [28] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame24,
        .timer = 1
    },
    [29] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [30] = {
        .pFrame = sPauseScreenOam_MapTargetRight_Frame24,
        .timer = 1
    },
    [31] = {
        .pFrame = sPauseScreenOam_MapTargetAbove_Frame25,
        .timer = 1
    },
    [32] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagramTargetAbove[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagramTargetAbove_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_BslDiagramTargetAbove_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_BslDiagramTargetAbove_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_BslDiagramTargetAbove_Frame3,
        .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagramTargetBelow[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagramTargetBelow_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_BslDiagramTargetBelow_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_BslDiagramTargetBelow_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_BslDiagramTargetBelow_Frame3,
        .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagramStartAbove[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagramStartAbove_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_BslDiagramStartAbove_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_BslDiagramStartAbove_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_BslDiagramStartAbove_Frame3,
        .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagramStartBelow[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagramStartBelow_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_BslDiagramStartBelow_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_BslDiagramStartBelow_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_BslDiagramStartBelow_Frame3,
        .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MainDeckText[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_MainDeckText_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_Sector1Text[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_Sector1Text_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_Sector2Text[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_Sector2Text_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_Sector3Text[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_Sector3Text_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_Sector4Text[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_Sector4Text_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_Sector5Text[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_Sector5Text_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_Sector6Text[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_Sector6Text_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_AreaTextAppearing[10] = {
    [0] = {
        .pFrame = sPauseScreenOam_AreaTextAppearing_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_AreaTextAppearing_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_AreaTextAppearing_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_AreaTextAppearing_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_AreaTextAppearing_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sPauseScreenOam_AreaTextAppearing_Frame3,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_AreaTextAppearing_Frame2,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_AreaTextAppearing_Frame1,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_AreaTextAppearing_Frame0,
        .timer = 2
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SleepButton[7] = {
    [0] = {
        .pFrame = sPauseScreenOam_SleepButton_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_SleepButton_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sPauseScreenOam_SleepButton_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_SleepButton_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sPauseScreenOam_SleepButton_Frame2,
        .timer = 8
    },
    [5] = {
        .pFrame = sPauseScreenOam_SleepButton_Frame1,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_StatusButton[7] = {
    [0] = {
        .pFrame = sPauseScreenOam_StatusButton_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_StatusButton_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sPauseScreenOam_StatusButton_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_StatusButton_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sPauseScreenOam_StatusButton_Frame2,
        .timer = 8
    },
    [5] = {
        .pFrame = sPauseScreenOam_StatusButton_Frame1,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SleepButtonSelected[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_SleepButtonSelected_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sPauseScreenOam_SleepButtonSelected_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sPauseScreenOam_SleepButtonSelected_Frame0,
        .timer = 6
    },
    [3] = {
        .pFrame = sPauseScreenOam_SleepButtonSelected_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_StatusButtonSelected[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_StatusButtonSelected_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sPauseScreenOam_StatusButtonSelected_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sPauseScreenOam_StatusButtonSelected_Frame0,
        .timer = 6
    },
    [3] = {
        .pFrame = sPauseScreenOam_StatusButtonSelected_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_L1Lock[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_L1Lock_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_L2Lock[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_L2Lock_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_L3Lock[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_L3Lock_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_L4Lock[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_L4Lock_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_L1Open[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_L1Open_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_L2Open[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_L2Open_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_L3Open[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_L3Open_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_L4Open[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_L4Open_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_ObjectiveButton[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_ObjectiveButton_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_CollectedEnergyTanks[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_CollectedEnergyTanks_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_CollectedMissileTanks[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_CollectedMissileTanks_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_CollectedPowerBombTanks[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_CollectedPowerBombTanks_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_InGameTimer[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_InGameTimer_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_EnergyTankCheckMark[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_EnergyTankCheckMark_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_MissileTankCheckMark[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_MissileTankCheckMark_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_PowerBombTankCheckMark[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_PowerBombTankCheckMark_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_NavigationPad[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_NavigationPad_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sPauseScreenOam_NavigationPad_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sPauseScreenOam_NavigationPad_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sPauseScreenOam_NavigationPad_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_NavigationPadWithSamus[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_NavigationPadWithSamus_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sPauseScreenOam_NavigationPadWithSamus_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sPauseScreenOam_NavigationPadWithSamus_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sPauseScreenOam_NavigationPadWithSamus_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_LockedHatchLeft[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_LockedHatchLeft_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_LockedHatchRight[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_LockedHatchRight_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const u16 sPauseScreenOam_PopUpWindow_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c1, 9, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c7, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 9, 0),
};

static const u16 sPauseScreenOam_PopUpWindow_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c1, 9, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c6, 9, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 9, 0),
};

static const u16 sPauseScreenOam_PopUpWindow_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-32, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c1, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2e0, 9, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c6, 9, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(-32, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x286, 9, 0),
    OAM_ENTRY(16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 9, 0),
};

static const u16 sPauseScreenOam_PopUpWindow_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-40, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c1, 9, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(-24, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 9, 0),
    OAM_ENTRY(-40, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x284, 9, 0),
    OAM_ENTRY(24, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 9, 0),
};

static const u16 sPauseScreenOam_PopUpWindow_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x284, 9, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c1, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 9, 0),
};

static const u16 sPauseScreenOam_PopUpWindow_Frame5[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-40, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x284, 9, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-40, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a1, 9, 0),
    OAM_ENTRY(8, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2a4, 9, 0),
    OAM_ENTRY(-24, 10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 9, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(32, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x289, 9, 0),
    OAM_ENTRY(-40, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a3, 9, 0),
    OAM_ENTRY(-40, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a3, 9, 0),
    OAM_ENTRY(24, 10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-32, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x298, 15, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x29c, 15, 0),
    OAM_ENTRY(-32, -3, OAM_DIMS_32x16, OAM_NO_FLIP, 0x298, 15, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_32x16, OAM_NO_FLIP, 0x29c, 15, 0),
};

static const u16 sPauseScreenOam_PopUpWindow_Frame6[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-40, -22, OAM_DIMS_32x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_32x8, OAM_NO_FLIP, 0x284, 9, 0),
    OAM_ENTRY(-40, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-40, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a1, 9, 0),
    OAM_ENTRY(8, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2a4, 9, 0),
    OAM_ENTRY(-24, 14, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 9, 0),
    OAM_ENTRY(24, -22, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(32, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x289, 9, 0),
    OAM_ENTRY(-40, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a3, 9, 0),
    OAM_ENTRY(-40, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a3, 9, 0),
    OAM_ENTRY(24, 10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-32, -14, OAM_DIMS_64x32, OAM_NO_FLIP, 0x218, 15, 0),
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x298, 15, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x29c, 15, 0),
};

static const u16 sPauseScreenOam_PopUpWindow_Frame7[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-40, -28, OAM_DIMS_32x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_32x8, OAM_NO_FLIP, 0x284, 9, 0),
    OAM_ENTRY(-40, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-40, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a1, 9, 0),
    OAM_ENTRY(8, 12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2a4, 9, 0),
    OAM_ENTRY(-24, 20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 9, 0),
    OAM_ENTRY(24, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(32, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x289, 9, 0),
    OAM_ENTRY(-40, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a3, 9, 0),
    OAM_ENTRY(-40, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a3, 9, 0),
    OAM_ENTRY(24, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_64x32, OAM_NO_FLIP, 0x218, 15, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x298, 15, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x29c, 15, 0),
};

static const u16 sPauseScreenOam_PopUpWindow_Frame8[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-40, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 0x280, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 0x284, 9, 0),
    OAM_ENTRY(-40, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a0, 9, 0),
    OAM_ENTRY(-40, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a1, 9, 0),
    OAM_ENTRY(8, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2a4, 9, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 9, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(32, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x289, 9, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a3, 9, 0),
    OAM_ENTRY(-40, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a3, 9, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x218, 15, 0),
    OAM_ENTRY(-32, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x298, 15, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x29c, 15, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x288, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(-88, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(-88, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(-104, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-88, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-88, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-64, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(-80, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e6, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-48, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(-48, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame3[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e7, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(-40, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame4[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(-32, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame5[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame6[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e6, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(16, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame7[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e7, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(32, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(32, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(16, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame8[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(48, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(48, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(32, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame9[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(64, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(64, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(48, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame10[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e6, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(80, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(80, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(80, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(80, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(64, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxOutline_Frame11[OAM_DATA_SIZE(22)] = {
    22,
    OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e7, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(96, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(96, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b0, 8, 0),
    OAM_ENTRY(96, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f0, 8, 0),
    OAM_ENTRY(80, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ee, 8, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 0x28c, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-106, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1ce, 3, 0),
    OAM_ENTRY(-115, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1d0, 3, 0),
    OAM_ENTRY(-112, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-84, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-113, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1a4, 3, 0),
    OAM_ENTRY(-93, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1a4, 3, 0),
    OAM_ENTRY(-109, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1ee, 3, 0),
    OAM_ENTRY(-102, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x1ee, 3, 0),
    OAM_ENTRY(-110, 12, OAM_DIMS_32x8, OAM_X_FLIP, 0x1f0, 3, 0),
    OAM_ENTRY(-118, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1f0, 3, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-88, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-60, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame2[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-114, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x188, 3, 0),
    OAM_ENTRY(-90, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x18c, 3, 0),
    OAM_ENTRY(-76, 4, OAM_DIMS_32x8, OAM_X_FLIP, 0x188, 3, 0),
    OAM_ENTRY(-120, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1f4, 3, 0),
    OAM_ENTRY(-105, 12, OAM_DIMS_32x8, OAM_X_FLIP, 0x1f4, 3, 0),
    OAM_ENTRY(-111, 1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1d4, 3, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-44, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame3[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-115, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1a8, 3, 0),
    OAM_ENTRY(-59, 4, OAM_DIMS_32x8, OAM_X_FLIP, 0x1a8, 3, 0),
    OAM_ENTRY(-90, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1ac, 3, 0),
    OAM_ENTRY(-73, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1ac, 3, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-88, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-56, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-28, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame4[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-116, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-116, 6, OAM_DIMS_32x8, OAM_Y_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-42, 2, OAM_DIMS_32x8, OAM_X_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-42, 6, OAM_DIMS_32x8, OAM_XY_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-96, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-64, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-96, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-64, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-96, 6, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-64, 6, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame5[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-117, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-117, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-25, 0, OAM_DIMS_32x8, OAM_X_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-25, 8, OAM_DIMS_32x8, OAM_XY_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-52, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-52, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-90, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-90, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-72, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-88, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-56, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame6[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-118, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-118, 2, OAM_DIMS_32x16, OAM_Y_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_32x16, OAM_X_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_32x16, OAM_XY_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-90, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-90, 10, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, 10, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-32, 10, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-32, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(20, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame7[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-119, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-119, 4, OAM_DIMS_32x16, OAM_Y_FLIP, 0x180, 3, 0),
    OAM_ENTRY(9, -4, OAM_DIMS_32x16, OAM_X_FLIP, 0x180, 3, 0),
    OAM_ENTRY(9, 4, OAM_DIMS_32x16, OAM_XY_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-90, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-26, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-90, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-26, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-8, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-90, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-58, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(36, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame8[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-120, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-120, 6, OAM_DIMS_32x16, OAM_Y_FLIP, 0x180, 3, 0),
    OAM_ENTRY(26, -6, OAM_DIMS_32x16, OAM_X_FLIP, 0x180, 3, 0),
    OAM_ENTRY(26, 6, OAM_DIMS_32x16, OAM_XY_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-90, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-26, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-90, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-26, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(0, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(52, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame9[OAM_DATA_SIZE(21)] = {
    21,
    OAM_ENTRY(-121, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-121, 7, OAM_DIMS_32x16, OAM_Y_FLIP, 0x180, 3, 0),
    OAM_ENTRY(43, -7, OAM_DIMS_32x16, OAM_X_FLIP, 0x180, 3, 0),
    OAM_ENTRY(43, 7, OAM_DIMS_32x16, OAM_XY_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-90, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-26, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(6, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-90, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-26, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(6, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(24, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(24, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-122, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-90, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-58, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(38, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(68, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame10[OAM_DATA_SIZE(22)] = {
    22,
    OAM_ENTRY(-122, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-122, 8, OAM_DIMS_32x16, OAM_Y_FLIP, 0x180, 3, 0),
    OAM_ENTRY(60, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x180, 3, 0),
    OAM_ENTRY(60, 8, OAM_DIMS_32x16, OAM_XY_FLIP, 0x180, 3, 0),
    OAM_ENTRY(-90, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-90, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-58, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-26, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(6, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x184, 3, 0),
    OAM_ENTRY(32, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x184, 3, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(56, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(84, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxBackground_Frame11[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-122, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-90, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-58, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(38, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(70, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(100, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxLightOpening_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x276, 8, 0),
    OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxLightOpening_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x296, 8, 0),
    OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxLightOpening_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b6, 8, 0),
    OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x256, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxLightOpening_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26e, 8, 0),
    OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b2, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxLightOff_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b4, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBoxBackground_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 9, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x304, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x303, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-80, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-80, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(80, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-112, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame6[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-80, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-48, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(48, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(72, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-120, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-112, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(104, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-80, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-48, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(48, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(72, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-120, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-112, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(104, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame7[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-112, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(104, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-80, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-48, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(48, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(72, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-120, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-112, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(104, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame8[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-80, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-48, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(16, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(48, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(72, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-120, 4, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-112, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 8, 0),
    OAM_ENTRY(104, 4, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-80, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-48, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(48, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(72, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-120, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-112, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(104, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x30c, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x30c, 8, 0),
};

static const u16 sPauseScreenOam_SamusTextBox_Frame9[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-72, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-40, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(24, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(56, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-72, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-40, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(24, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(56, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(72, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(72, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-120, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-104, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-120, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-104, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(104, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 9, 0),
    OAM_ENTRY(104, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 9, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x30c, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30a, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x309, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x309, 9, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x309, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-80, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-112, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x372, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame6[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-104, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-72, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(104, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(72, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-40, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-104, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-72, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(104, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(72, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-40, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(56, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-120, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-120, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x352, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame7[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-104, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-72, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(104, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-40, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(56, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-104, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(104, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(72, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-40, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(24, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(56, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-120, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x352, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame8[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-104, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-72, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(104, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(72, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-40, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(24, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(56, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-104, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-72, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(104, 4, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(72, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(24, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(56, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(112, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x326, 9, 0),
    OAM_ENTRY(-120, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-120, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x352, 9, 0),
    OAM_ENTRY(-120, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30b, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxOutline_Frame9[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-104, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-72, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(104, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(72, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-40, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(24, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(56, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-104, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-72, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(104, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(72, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-40, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(24, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(56, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-120, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x312, 8, 0),
    OAM_ENTRY(-120, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x352, 9, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x30b, 9, 0),
};

static const u16 sPauseScreenOam_SamusTextBoxBackground_Frame6[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_SamusTextBoxBackground_Frame7[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-112, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_SamusTextBoxBackground_Frame8[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-112, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_SamusTextBoxBackground_Frame9[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-112, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxBackground_Frame6[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxBackground_Frame7[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-112, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxBackground_Frame8[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-112, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_FedTextBoxBackground_Frame9[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-112, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(80, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 9, 0),
};

static const u16 sPauseScreenOam_SamusPortraitAnimated_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-56, 30, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, 30, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-48, -18, OAM_DIMS_64x64, OAM_NO_FLIP, 0x12, 6, 0),
    OAM_ENTRY(-24, -26, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-56, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_8x32, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-56, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, 22, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-40, 38, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, 38, OAM_DIMS_16x8, OAM_Y_FLIP, 0x303, 9, 0),
    OAM_ENTRY(-56, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30e, 9, 0),
};

static const u16 sPauseScreenOam_SamusPortraitAnimated_Frame1[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-32, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5e, 6, 0),
    OAM_ENTRY(-32, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x9e, 6, 0),
    OAM_ENTRY(-56, 30, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, 30, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-48, -18, OAM_DIMS_64x64, OAM_NO_FLIP, 0x12, 6, 0),
    OAM_ENTRY(-24, -26, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-56, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_8x32, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-56, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, 22, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-40, 38, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, 38, OAM_DIMS_16x8, OAM_Y_FLIP, 0x303, 9, 0),
    OAM_ENTRY(-56, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30e, 9, 0),
};

static const u16 sPauseScreenOam_FederationPortraitStill_Frame0[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-24, -26, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, 30, OAM_DIMS_16x16, OAM_Y_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, 38, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 38, OAM_DIMS_16x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, 30, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_8x32, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-56, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(16, 22, OAM_DIMS_8x8, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-48, -18, OAM_DIMS_64x32, OAM_NO_FLIP, 0xa, 14, 0),
    OAM_ENTRY(-48, 14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 14, 0),
    OAM_ENTRY(-16, 14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8e, 14, 0),
    OAM_ENTRY(-48, 30, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 14, 0),
    OAM_ENTRY(-16, 30, OAM_DIMS_32x8, OAM_NO_FLIP, 0xce, 14, 0),
    OAM_ENTRY(-56, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 0x34e, 8, 0),
};

static const u16 sPauseScreenOam_FederationPortraitAnimating_Frame1[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-24, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1e, 14, 0),
    OAM_ENTRY(-24, -26, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, 30, OAM_DIMS_16x16, OAM_Y_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, 38, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 38, OAM_DIMS_16x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, 30, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_8x32, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-56, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(16, 22, OAM_DIMS_8x8, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-48, -18, OAM_DIMS_64x32, OAM_NO_FLIP, 0xa, 14, 0),
    OAM_ENTRY(-48, 14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 14, 0),
    OAM_ENTRY(-16, 14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8e, 14, 0),
    OAM_ENTRY(-48, 30, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 14, 0),
    OAM_ENTRY(-16, 30, OAM_DIMS_32x8, OAM_NO_FLIP, 0xce, 14, 0),
    OAM_ENTRY(-56, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 0x34e, 8, 0),
};

static const u16 sPauseScreenOam_SamusPortraitOpening_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-20, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x304, 8, 0),
};

static const u16 sPauseScreenOam_SamusPortraitOpening_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
};

static const u16 sPauseScreenOam_SamusPortraitOpening_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-53, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(5, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x303, 8, 0),
};

static const u16 sPauseScreenOam_SamusPortraitOpening_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-56, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-56, 6, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, 6, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-40, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x303, 9, 0),
    OAM_ENTRY(-56, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, 6, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-40, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, 14, OAM_DIMS_16x8, OAM_Y_FLIP, 0x303, 9, 0),
    OAM_ENTRY(-48, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x72, 6, 0),
    OAM_ENTRY(-16, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x76, 6, 0),
};

static const u16 sPauseScreenOam_SamusPortraitOpening_Frame4[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-56, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-56, 14, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, 14, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-40, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x303, 9, 0),
    OAM_ENTRY(-56, 14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, 14, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-40, 22, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, 22, OAM_DIMS_16x8, OAM_Y_FLIP, 0x303, 9, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x52, 6, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x56, 6, 0),
    OAM_ENTRY(-48, 14, OAM_DIMS_32x8, OAM_NO_FLIP, 0x92, 6, 0),
    OAM_ENTRY(-16, 14, OAM_DIMS_32x8, OAM_NO_FLIP, 0x96, 6, 0),
    OAM_ENTRY(-56, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, 6, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 9, 0),
};

static const u16 sPauseScreenOam_SamusPortraitOpening_Frame5[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-56, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-56, 22, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, 22, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x303, 9, 0),
    OAM_ENTRY(-56, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_8x32, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-56, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, 22, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-40, 30, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, 30, OAM_DIMS_16x8, OAM_Y_FLIP, 0x303, 9, 0),
    OAM_ENTRY(-48, -10, OAM_DIMS_64x32, OAM_NO_FLIP, 0x32, 6, 0),
    OAM_ENTRY(-48, 22, OAM_DIMS_32x8, OAM_NO_FLIP, 0xb2, 6, 0),
    OAM_ENTRY(-16, 22, OAM_DIMS_32x8, OAM_NO_FLIP, 0xb6, 6, 0),
};

static const u16 sPauseScreenOam_SamusPortraitOpening_Frame6[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-56, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-56, 30, OAM_DIMS_16x16, OAM_Y_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, 30, OAM_DIMS_16x16, OAM_XY_FLIP, 0x300, 9, 0),
    OAM_ENTRY(8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-48, -18, OAM_DIMS_64x64, OAM_NO_FLIP, 0x12, 6, 0),
    OAM_ENTRY(-40, -26, OAM_DIMS_32x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x303, 9, 0),
    OAM_ENTRY(-56, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_8x32, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-56, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(16, 22, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 9, 0),
    OAM_ENTRY(-40, 38, OAM_DIMS_32x8, OAM_Y_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-8, 38, OAM_DIMS_16x8, OAM_Y_FLIP, 0x303, 9, 0),
};

static const u16 sPauseScreenOam_FederationPortraitOpening_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-20, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30a, 9, 0),
};

static const u16 sPauseScreenOam_FederationPortraitOpening_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x308, 9, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x308, 9, 0),
};

static const u16 sPauseScreenOam_FederationPortraitOpening_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-53, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-21, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(5, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x307, 9, 0),
};

static const u16 sPauseScreenOam_FederationPortraitOpening_Frame3[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-56, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, 6, OAM_DIMS_16x16, OAM_Y_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 14, OAM_DIMS_16x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, 6, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-48, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x6a, 15, 0),
    OAM_ENTRY(-16, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x6e, 15, 0),
};

static const u16 sPauseScreenOam_FederationPortraitOpening_Frame4[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-56, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, 14, OAM_DIMS_16x16, OAM_Y_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, 22, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 22, OAM_DIMS_16x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, 14, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(16, 6, OAM_DIMS_8x8, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4a, 15, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4e, 15, 0),
    OAM_ENTRY(-48, 14, OAM_DIMS_32x8, OAM_NO_FLIP, 0x8a, 15, 0),
    OAM_ENTRY(-16, 14, OAM_DIMS_32x8, OAM_NO_FLIP, 0x8e, 15, 0),
};

static const u16 sPauseScreenOam_FederationPortraitOpening_Frame5[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-56, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, 22, OAM_DIMS_16x16, OAM_Y_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, 30, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 30, OAM_DIMS_16x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, 22, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, 14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(16, 14, OAM_DIMS_8x8, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-56, -2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_8x16, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-48, -10, OAM_DIMS_64x32, OAM_NO_FLIP, 0x2a, 15, 0),
    OAM_ENTRY(-48, 22, OAM_DIMS_32x8, OAM_NO_FLIP, 0xaa, 15, 0),
    OAM_ENTRY(-16, 22, OAM_DIMS_32x8, OAM_NO_FLIP, 0xae, 15, 0),
};

static const u16 sPauseScreenOam_FederationPortraitOpening_Frame6[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-56, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, -26, OAM_DIMS_32x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, 30, OAM_DIMS_16x16, OAM_Y_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-40, 38, OAM_DIMS_32x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-8, 38, OAM_DIMS_16x8, OAM_Y_FLIP, 0x307, 9, 0),
    OAM_ENTRY(8, 30, OAM_DIMS_16x16, OAM_XY_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-56, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_8x32, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-56, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(16, 22, OAM_DIMS_8x8, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-48, -18, OAM_DIMS_64x32, OAM_NO_FLIP, 0xa, 14, 0),
    OAM_ENTRY(-48, 14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 14, 0),
    OAM_ENTRY(-16, 14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8e, 14, 0),
    OAM_ENTRY(-48, 30, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 14, 0),
    OAM_ENTRY(-16, 30, OAM_DIMS_32x8, OAM_NO_FLIP, 0xce, 14, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxLightFlashing_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x317, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x357, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26e, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxLightFlashing_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x319, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x359, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26e, 8, 0),
};

static const u16 sPauseScreenOam_AdamTextBoxLightFlashing_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x31b, 8, 0),
    OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x35b, 8, 0),
    OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26e, 8, 0),
};

static const u16 sPauseScreenOam_FederationPortraitFlickering_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-48, -18, OAM_DIMS_32x32, OAM_NO_FLIP, 0x1a, 14, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_32x32, OAM_NO_FLIP, 0x1a, 14, 0),
    OAM_ENTRY(-16, 6, OAM_DIMS_32x32, OAM_NO_FLIP, 0x1a, 14, 0),
    OAM_ENTRY(-48, 6, OAM_DIMS_32x32, OAM_NO_FLIP, 0x1a, 14, 0),
};

const struct FrameData sPauseScreenOam_PopUpWindow[10] = {
    [0] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame8,
        .timer = UCHAR_MAX
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_PopUpWindowClosing[10] = {
    [0] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame8,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame7,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame6,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame5,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame3,
        .timer = 1
    },
    [6] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame2,
        .timer = 1
    },
    [7] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame1,
        .timer = 1
    },
    [8] = {
        .pFrame = sPauseScreenOam_PopUpWindow_Frame0,
        .timer = 1
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_AdamTextBoxOutline[13] = {
    [0] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame10,
        .timer = 2
    },
    [11] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame11,
        .timer = 50
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_AdamTextBoxOutlineClosing[13] = {
    [0] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame11,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame10,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame9,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame8,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame7,
        .timer = 1
    },
    [5] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame6,
        .timer = 1
    },
    [6] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame5,
        .timer = 1
    },
    [7] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame4,
        .timer = 1
    },
    [8] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame3,
        .timer = 1
    },
    [9] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame2,
        .timer = 1
    },
    [10] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame1,
        .timer = 1
    },
    [11] = {
        .pFrame = sPauseScreenOam_AdamTextBoxOutline_Frame0,
        .timer = 50
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_AdamTextBoxBackground[13] = {
    [0] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame10,
        .timer = 2
    },
    [11] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame11,
        .timer = 50
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_AdamTextBoxBackgroundClosing[13] = {
    [0] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame11,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame10,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame9,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame8,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame7,
        .timer = 1
    },
    [5] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame6,
        .timer = 1
    },
    [6] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame5,
        .timer = 1
    },
    [7] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame4,
        .timer = 1
    },
    [8] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame3,
        .timer = 1
    },
    [9] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame2,
        .timer = 1
    },
    [10] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame1,
        .timer = 1
    },
    [11] = {
        .pFrame = sPauseScreenOam_AdamTextBoxBackground_Frame0,
        .timer = UCHAR_MAX
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_AdamTextBoxLightOpening[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOpening_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOpening_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOpening_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOpening_Frame3,
        .timer = UCHAR_MAX
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_AdamTextBoxLightClosing[5] = {
    [0] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOpening_Frame3,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOpening_Frame2,
        .timer = 8
    },
    [2] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOpening_Frame1,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOpening_Frame0,
        .timer = UCHAR_MAX
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_AdamTextBoxLightOff[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOff_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SamusTextBox[11] = {
    [0] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame9,
        .timer = UCHAR_MAX
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SamusTextBoxClosing[11] = {
    [0] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame9,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame8,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame7,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame6,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame5,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame4,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame3,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame2,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame1,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_SamusTextBox_Frame0,
        .timer = 2
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SamusTextBoxBackground[11] = {
    [0] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame9,
        .timer = UCHAR_MAX
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SamusTextBoxBackgroundClosing[11] = {
    [0] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame9,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame8,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame7,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame6,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_FedTextBoxBackground[11] = {
    [0] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_FedTextBoxBackground_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_FedTextBoxBackground_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_FedTextBoxBackground_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_FedTextBoxBackground_Frame9,
        .timer = UCHAR_MAX
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_FedTextBoxBackgroundClosing[11] = {
    [0] = {
        .pFrame = sPauseScreenOam_FedTextBoxBackground_Frame9,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_FedTextBoxBackground_Frame8,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_FedTextBoxBackground_Frame7,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_FedTextBoxBackground_Frame6,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_FedTextBoxOutline[11] = {
    [0] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame9,
        .timer = UCHAR_MAX
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_FedTextBoxClosing[11] = {
    [0] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame9,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame8,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame7,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame6,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame5,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame4,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame3,
        .timer = 2
    },
    [7] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame2,
        .timer = 2
    },
    [8] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame1,
        .timer = 2
    },
    [9] = {
        .pFrame = sPauseScreenOam_FedTextBoxOutline_Frame0,
        .timer = 2
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SamusPortraitStill[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_SamusPortraitAnimated_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SamusPortraitAnimated[3] = {
    [0] = {
        .pFrame = sPauseScreenOam_SamusPortraitAnimated_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_SamusPortraitAnimated_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_FederationPortraitStill[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_FederationPortraitStill_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_FederationPortraitAnimating[3] = {
    [0] = {
        .pFrame = sPauseScreenOam_FederationPortraitStill_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_FederationPortraitAnimating_Frame1,
        .timer = 8
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SamusPortraitOpening[8] = {
    [0] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame6,
        .timer = 2
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_SamusPortraitClosing[8] = {
    [0] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame6,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame5,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame4,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame2,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame1,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_SamusPortraitOpening_Frame0,
        .timer = 2
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_FederationPortraitOpening[8] = {
    [0] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame6,
        .timer = 2
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_FederationPortraitClosing[8] = {
    [0] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame6,
        .timer = 2
    },
    [1] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame5,
        .timer = 2
    },
    [2] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame4,
        .timer = 2
    },
    [3] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame2,
        .timer = 2
    },
    [5] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame1,
        .timer = 2
    },
    [6] = {
        .pFrame = sPauseScreenOam_FederationPortraitOpening_Frame0,
        .timer = 2
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_AdamTextBoxLightFlashing[6] = {
    [0] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightOpening_Frame3,
        .timer = 8
    },
    [1] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightFlashing_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightFlashing_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightFlashing_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sPauseScreenOam_AdamTextBoxLightFlashing_Frame1,
        .timer = 8
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_FederationPortraitFlickering[3] = {
    [0] = {
        .pFrame = sPauseScreenOam_FederationPortraitFlickering_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sPauseScreenOam_SamusTextBoxBackground_Frame0,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const u16 sPauseScreenOam_BslDiagram0Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-16, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-25, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-17, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram10Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-19, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-19, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-2, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-2, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-25, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-25, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-14, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram20Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-22, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-22, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-5, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-5, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(9, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-11, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-11, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram30Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-24, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-23, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-23, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(8, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram40Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-25, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-11, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(6, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(9, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram50Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-25, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-14, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(3, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-2, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(9, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram60Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-16, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-25, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-17, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram70Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-19, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-19, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-2, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-2, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-25, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-25, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-14, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram80Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-22, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-22, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-5, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-5, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(9, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-11, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-11, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram90Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-24, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-23, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-23, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(8, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram100Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-25, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-11, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(6, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(9, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram110Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-25, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-14, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(3, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-2, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(9, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram120Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-16, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-25, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-17, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram130Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-19, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-19, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-2, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-2, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-25, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-25, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-14, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram140Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-22, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-22, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-5, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-5, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(9, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-11, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-11, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram150Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-24, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-23, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-23, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(8, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram160Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-25, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-11, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(6, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(9, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram170Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-25, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-14, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(3, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-2, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(9, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram180Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-16, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-25, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-17, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram190Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-19, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-19, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-2, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-2, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-25, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-25, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-14, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram200Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-22, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-22, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-5, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-5, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(9, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-11, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-11, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram210Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-24, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-23, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-23, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(8, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram220Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-25, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-11, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(6, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(9, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram230Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-25, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-14, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(3, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(-2, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(9, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram240Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-16, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-25, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-17, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram250Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-19, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-19, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-2, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-2, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-25, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-25, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-14, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram260Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-22, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-22, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-5, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-5, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(9, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-11, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-11, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram270Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-24, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-23, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-23, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(8, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram280Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-25, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-11, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(6, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(9, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram290Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-25, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-14, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(3, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(-2, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(9, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram300Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-16, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-25, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-17, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram310Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-19, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-19, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-2, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-2, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-25, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-25, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-14, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram320Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-22, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-22, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-5, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-5, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(9, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(9, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-11, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-11, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram330Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-24, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-23, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-23, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(8, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram340Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-25, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-11, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(6, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(9, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
};

static const u16 sPauseScreenOam_BslDiagram350Degrees_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-25, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x340, 10, 0),
    OAM_ENTRY(-25, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x380, 10, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x34a, 10, 0),
    OAM_ENTRY(-14, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x38a, 10, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x342, 10, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x382, 10, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 10, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 10, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3c0, 10, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3e4, 10, 0),
    OAM_ENTRY(-8, 26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3e0, 10, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a2, 10, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x348, 10, 0),
    OAM_ENTRY(3, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x388, 10, 0),
    OAM_ENTRY(-2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 10, 0),
    OAM_ENTRY(-2, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x384, 10, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x346, 10, 0),
    OAM_ENTRY(9, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x386, 10, 0),
};

const struct FrameData sPauseScreenOam_BslDiagram0Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram0Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram10Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram10Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram20Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram20Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram30Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram30Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram40Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram40Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram50Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram50Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram60Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram60Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram70Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram70Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram80Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram80Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram90Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram90Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram100Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram100Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram110Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram110Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram120Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram120Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram130Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram130Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram140Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram140Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram150Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram150Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram160Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram160Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram170Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram170Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram180Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram180Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram190Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram190Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram200Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram200Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram210Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram210Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram220Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram220Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram230Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram230Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram240Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram240Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram250Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram250Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram260Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram260Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram270Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram270Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram280Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram280Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram290Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram290Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram300Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram300Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram310Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram310Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram320Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram320Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram330Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram330Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram340Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram340Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPauseScreenOam_BslDiagram350Degrees[2] = {
    [0] = {
        .pFrame = sPauseScreenOam_BslDiagram350Degrees_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u32 sPauseScreenBgGfx[2437] = INCBIN_U32("data/menus/pause_screen/bg.gfx.lz");
const u32 sNavConversationRoomGfx[1414] = INCBIN_U32("data/menus/pause_screen/nav_convo_room.gfx.lz");
const u32 sNavConversationShipGfx[1575] = INCBIN_U32("data/menus/pause_screen/nav_convo_ship.gfx.lz");
const u32 sPauseScreenObjGfx[3404] = INCBIN_U32("data/menus/pause_screen/obj.gfx.lz");

const u32 sBlankMinimap[63] = INCBIN_U32("data/menus/pause_screen/blank_minimap.tm.lz");
const u32 sMainDeckMinimap[149] = INCBIN_U32("data/menus/pause_screen/main_deck_minimap.tm.lz");
const u32 sSector1Minimap[120] = INCBIN_U32("data/menus/pause_screen/sector_1_minimap.tm.lz");
const u32 sSector3Minimap[122] = INCBIN_U32("data/menus/pause_screen/sector_3_minimap.tm.lz");
const u32 sSector6Minimap[117] = INCBIN_U32("data/menus/pause_screen/sector_6_minimap.tm.lz");
const u32 sSector4Minimap[132] = INCBIN_U32("data/menus/pause_screen/sector_4_minimap.tm.lz");
const u32 sSector2Minimap[133] = INCBIN_U32("data/menus/pause_screen/sector_2_minimap.tm.lz");
const u32 sSector5Minimap[126] = INCBIN_U32("data/menus/pause_screen/sector_5_minimap.tm.lz");
const u32 sMainDeckNoLabMinimap[148] = INCBIN_U32("data/menus/pause_screen/main_deck_no_lab_minimap.tm.lz");

const u32 sUnk_573da4[63] = INCBIN_U32("data/menus/pause_screen/573da4.tm.lz");
const u32 sPauseDebugTilemap[151] = INCBIN_U32("data/menus/pause_screen/pause_debug.tm.lz");
const u32 sMapScreenOutlineTilemap[123] = INCBIN_U32("data/menus/pause_screen/map_screen_outline.tm.lz");
const u32 sNavConversationTextBoxesTilemap[176] = INCBIN_U32("data/menus/pause_screen/nav_conversation_text_boxes.tm.lz");
const u32 sPauseScreenSleepTilemap[193] = INCBIN_U32("data/menus/pause_screen/sleep.tm.lz");
const u32 sStatusScreenTilemap[295] = INCBIN_U32("data/menus/pause_screen/status_screen.tm.lz");
const u32 sNavConversationRoomTilemap[359] = INCBIN_U32("data/menus/pause_screen/nav_conversation_room.tm.lz");
const u32 sPauseScreen_5752e4[65] = INCBIN_U32("data/menus/pause_screen/5752e4.tm.lz");
const u32 sNavConversationShipTilemap[414] = INCBIN_U32("data/menus/pause_screen/nav_conversation_ship.tm.lz");
