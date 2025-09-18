#include "data/sprites/destroyed_data_pad.h"
#include "macros.h"

const u32 sDestroyedDataPadGfx[512] = INCBIN_U32("data/sprites/destroyed_data_pad.gfx");
const u16 sDestroyedDataPadPal[16 * 1] = INCBIN_U16("data/sprites/destroyed_data_pad.pal");

static const u16 sDestroyedDataPadOam_Destroyed_Frame0[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-32, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-40, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 525, 8, 0),
    OAM_ENTRY(24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 570, 8, 0),
    OAM_ENTRY(-32, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 568, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 570, 8, 0),
    OAM_ENTRY(24, 8, OAM_DIMS_8x8, OAM_X_FLIP, 571, 8, 0),
    OAM_ENTRY(24, 16, OAM_DIMS_8x8, OAM_X_FLIP, 572, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 541, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 543, 8, 0),
    OAM_ENTRY(-40, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(-40, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 564, 8, 0),
};

const struct FrameData sDestroyedDataPadOam_Destroyed[2] = {
    [0] = {
        .pFrame = sDestroyedDataPadOam_Destroyed_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
