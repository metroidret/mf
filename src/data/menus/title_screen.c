#include "data/menus/title_screen.h"
#include "macros.h"

const u8 sTitleScreenDebugTextCharactersGfx[768] = INCBIN_U8("data/menus/title_screen/characters.gfx");
const u8 sTitleScreenDebugText[2] = " ";

const u32 sTitleScreenObjectsGfx[1974] = INCBIN_U32("data/menus/title_screen/objects.gfx.lz");
const u16 sTitleScreenObjectsPal[16 * 16] = INCBIN_U16("data/menus/title_screen/objects.pal");

const u16 sTitleScreen_592d74[16 * 16] = INCBIN_U16("data/menus/title_screen/592d74.pal");
const u16 sTitleScreen_592f74[16 * 16] = INCBIN_U16("data/menus/title_screen/592f74.pal");
const u16 sTitleScreenPressStartPal[16 * 8] = INCBIN_U16("data/menus/title_screen/press_start.pal");

const u32 sTitleScreenLogoGfx[3153] = INCBIN_U32("data/menus/title_screen/logo.gfx.lz");
const u32 sTitleScreenLogoTileTable[597] = INCBIN_U32("data/menus/title_screen/logo.tt");
const u16 sTitleScreenLogoPal[16 * 8] = INCBIN_U16("data/menus/title_screen/logo.pal");
const u16 sTitleScreen_596e0c[16 * 8] = INCBIN_U16("data/menus/title_screen/596e0c.pal");

static const u16 sTitleScreenOam_Copyright_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-59, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0, 0, 0),
    OAM_ENTRY(-44, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 2, 0, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 6, 0, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 10, 0, 0),
};

static const u16 sTitleScreenOam_596f26[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 64, 0, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 68, 0, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 72, 0, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 116, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 120, 0, 0),
};

static const u16 sTitleScreenOam_596f46[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 128, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 132, 0, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 136, 0, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 116, 0, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 120, 0, 0),
};

static const u16 sTitleScreenOam_596f66[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 140, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-40, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 84, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 88, 0, 0),
    OAM_ENTRY(24, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 92, 0, 0),
};

static const u16 sTitleScreenOam_Language_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 76, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 80, 0, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 84, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 88, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 92, 0, 0),
};

static const u16 sTitleScreenOam_596fa6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 64, 1, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 68, 1, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 72, 1, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 116, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 120, 0, 0),
};

static const u16 sTitleScreenOam_596fc6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 76, 1, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 80, 1, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 84, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 88, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 92, 0, 0),
};

static const u16 sTitleScreenOam_PressStart_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 192, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 196, 0, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 200, 0, 0),
};

static const u16 sTitleScreenOam_596ffa[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 192, 1, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 196, 1, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 200, 1, 0),
};

static const u16 sTitleScreenOam_59700e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 320, 0, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 324, 0, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 328, 0, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 372, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 376, 0, 0),
};

static const u16 sTitleScreenOam_59702e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 384, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 388, 0, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 392, 0, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 372, 0, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 376, 0, 0),
};

static const u16 sTitleScreenOam_59704e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 396, 0, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 400, 0, 0),
    OAM_ENTRY(-40, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 340, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 344, 0, 0),
    OAM_ENTRY(24, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 348, 0, 0),
};

static const u16 sTitleScreenOam_59706e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -3, OAM_DIMS_32x16, OAM_NO_FLIP, 332, 0, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_32x16, OAM_NO_FLIP, 336, 0, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 340, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 344, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 348, 0, 0),
};

static const u16 sTitleScreenOam_59708e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 320, 1, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 324, 1, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 328, 1, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 372, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 376, 0, 0),
};

static const u16 sTitleScreenOam_5970ae[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -3, OAM_DIMS_32x16, OAM_NO_FLIP, 332, 1, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_32x16, OAM_NO_FLIP, 336, 1, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 340, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 344, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 348, 0, 0),
};

static const u16 sTitleScreenOam_5970ce[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 448, 0, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 452, 0, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 456, 0, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 500, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 504, 0, 0),
};

static const u16 sTitleScreenOam_5970ee[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 0, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 0, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 500, 0, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 504, 0, 0),
};

static const u16 sTitleScreenOam_59710e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 0, 0),
    OAM_ENTRY(-40, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 468, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 472, 0, 0),
    OAM_ENTRY(24, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 476, 0, 0),
};

static const u16 sTitleScreenOam_59712e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 460, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 464, 0, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 468, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 472, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 476, 0, 0),
};

static const u16 sTitleScreenOam_59714e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 448, 1, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 452, 1, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 456, 1, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 500, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 504, 0, 0),
};

static const u16 sTitleScreenOam_59716e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 460, 1, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 464, 1, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 468, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 472, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 476, 0, 0),
};

static const u16 sTitleScreenOam_59718e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 0, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 580, 0, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 0, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 628, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 632, 0, 0),
};

static const u16 sTitleScreenOam_5971ae[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 640, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 644, 0, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 648, 0, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 628, 0, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 632, 0, 0),
};

static const u16 sTitleScreenOam_5971ce[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 652, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 656, 0, 0),
    OAM_ENTRY(-40, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 596, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 600, 0, 0),
    OAM_ENTRY(24, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 604, 0, 0),
};

static const u16 sTitleScreenOam_5971ee[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 0, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 596, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 600, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 604, 0, 0),
};

static const u16 sTitleScreenOam_59720e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 1, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 580, 1, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 1, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 628, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 632, 0, 0),
};

static const u16 sTitleScreenOam_59722e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 1, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 1, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 596, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 600, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 604, 0, 0),
};

static const u16 sTitleScreenOam_59724e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 704, 0, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 708, 0, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 712, 0, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 756, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 760, 0, 0),
};

static const u16 sTitleScreenOam_59726e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 772, 0, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 776, 0, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 756, 0, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 760, 0, 0),
};

static const u16 sTitleScreenOam_59728e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 784, 0, 0),
    OAM_ENTRY(-40, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 724, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 728, 0, 0),
    OAM_ENTRY(24, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 732, 0, 0),
};

static const u16 sTitleScreenOam_5972ae[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 716, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 720, 0, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 724, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 728, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 732, 0, 0),
};

static const u16 sTitleScreenOam_5972ce[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 704, 1, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 708, 1, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 712, 1, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 756, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 760, 0, 0),
};

static const u16 sTitleScreenOam_5972ee[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 716, 1, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 720, 1, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 724, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 728, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 732, 0, 0),
};

static const u16 sTitleScreenOam_59730e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 836, 0, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 840, 0, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 884, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 888, 0, 0),
};

static const u16 sTitleScreenOam_59732e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 896, 0, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 900, 0, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 904, 0, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 884, 0, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 888, 0, 0),
};

static const u16 sTitleScreenOam_59734e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 908, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 912, 0, 0),
    OAM_ENTRY(-40, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 852, 0, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 856, 0, 0),
    OAM_ENTRY(24, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 860, 0, 0),
};

static const u16 sTitleScreenOam_59736e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 844, 0, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 848, 0, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 852, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 856, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 860, 0, 0),
};

static const u16 sTitleScreenOam_59738e[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 832, 1, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 836, 1, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 840, 1, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 884, 0, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 888, 0, 0),
};

static const u16 sTitleScreenOam_5973ae[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 844, 1, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 848, 1, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 852, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 856, 0, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 860, 0, 0),
};


const struct FrameData sTitleScreenOam_Copyright[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_Copyright_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5973e0[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_596f26,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5973f0[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_596f46,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_596f66,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_Language[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_Language_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597418[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_596f66,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_596f46,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597430[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_596fa6,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_596f26,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597448[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_596fc6,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_Language_Frame0,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_PressStart[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_PressStart_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597470[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_596ffa,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_PressStart_Frame0,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597488[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_59700e,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597498[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59702e,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_59704e,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5974b0[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_59706e,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5974c0[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59704e,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_59702e,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5974d8[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59708e,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_59700e,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5974f0[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_5970ae,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_59706e,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597508[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_5970ce,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597518[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_5970ee,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_59710e,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597530[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_59712e,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597540[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59710e,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_5970ee,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597558[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59714e,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_5970ce,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597570[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59716e,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_59712e,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597588[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_59718e,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597598[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_5971ae,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_5971ce,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5975b0[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_5971ee,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5975c0[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_5971ce,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_5971ae,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5975d8[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59720e,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_59718e,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5975f0[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59722e,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_5971ee,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597608[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_59724e,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597618[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59726e,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_59728e,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597630[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_5972ae,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597640[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59728e,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_59726e,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597658[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_5972ce,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_59724e,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597670[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_5972ee,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_5972ae,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597688[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_59730e,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_597698[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59732e,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_59734e,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5976b0[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_59736e,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5976c0[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59734e,
        .timer = 4
    },
    [1] = {
        .pFrame = sTitleScreenOam_59732e,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5976d8[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_59738e,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_59730e,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTitleScreenOam_5976f0[3] = {
    [0] = {
        .pFrame = sTitleScreenOam_5973ae,
        .timer = 3
    },
    [1] = {
        .pFrame = sTitleScreenOam_59736e,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_597708_79a29c[] = INCBIN_U8("data/Blob_597708_79a29c.bin");
