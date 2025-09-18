#include "data/sprites/movable_platform.h"
#include "macros.h"

const u32 sMovablePlatformGfx[512] = INCBIN_U32("data/sprites/movable_platform.gfx");
const u16 sMovablePlatformPal[16 * 1] = INCBIN_U16("data/sprites/movable_platform.pal");

static const u16 sMovablePlatformOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
};

const struct FrameData sMovablePlatformOam_Idle[2] = {
    [0] = {
        .pFrame = sMovablePlatformOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
