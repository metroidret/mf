#include "data/escape_data.h"

const u16 sEscapeDigitsPal[16 * 3] = INCBIN_U16("data/escape/palette.pal");
const u8 sEscapeDigitsGfx[2048] = INCBIN_U8("data/escape/graphics.gfx");

const u16 sEscapeDigitsOam[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(0, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 15, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 15, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 970, 15, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 15, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 15, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 1002, 15, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 15, 0),
    OAM_ENTRY(56, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 15, 0),
};

const struct FrameData sEscapeTimerFrameData[2] = {
    [0] = {
        .pFrame = sEscapeDigitsOam,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_3e9940_3ec038[9976] = INCBIN_U8("data/Blob_3e9940_3ec038.bin");
