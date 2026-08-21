#include "data/sprites/metroid_husk.h"
#include "macros.h"

const u32 sMetroidHuskGfx[512 * 1] = INCBIN_U32("data/sprites/metroid_husk.gfx");
const u16 sMetroidHuskPal[16 * 1] = INCBIN_U16("data/sprites/metroid_husk.pal");

static const u16 sMetroidHuskOam_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-16, -36, OAM_DIMS_32x8, OAM_NO_FLIP, 0x20c, 8, 0),
};

const struct FrameData sMetroidHuskOam[2] = {
    [0] = {
        .pFrame = sMetroidHuskOam_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};
