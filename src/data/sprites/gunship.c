#include "data/sprites/gunship.h"
#include "macros.h"

const u32 sGunshipGfx[6 * 512] = INCBIN_U32("data/sprites/gunship.gfx");
const u16 sGunshipPal[6 * 16] = INCBIN_U16("data/sprites/gunship.pal");

static const u16 sGunshipPartOam_Idle_Frame0[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -56, OAM_DIMS_32x32, OAM_NO_FLIP, 720, 9, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 849, 9, 0),
    OAM_ENTRY(-80, -104, OAM_DIMS_64x64, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-48, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 9, 0),
    OAM_ENTRY(-80, -40, OAM_DIMS_32x32, OAM_NO_FLIP, 776, 9, 0),
    OAM_ENTRY(-96, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 646, 9, 0),
    OAM_ENTRY(-96, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 774, 9, 0),
    OAM_ENTRY(-84, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 736, 9, 0),
    OAM_ENTRY(16, -104, OAM_DIMS_64x64, OAM_X_FLIP, 520, 9, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_32x16, OAM_X_FLIP, 780, 9, 0),
    OAM_ENTRY(48, -40, OAM_DIMS_32x32, OAM_X_FLIP, 776, 9, 0),
    OAM_ENTRY(80, -72, OAM_DIMS_16x32, OAM_X_FLIP, 646, 9, 0),
    OAM_ENTRY(80, -40, OAM_DIMS_16x32, OAM_X_FLIP, 774, 9, 0),
    OAM_ENTRY(52, -8, OAM_DIMS_32x8, OAM_X_FLIP, 736, 9, 0),
};

static const u16 sGunshipOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -104, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 9, 0),
    OAM_ENTRY(-24, -88, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(8, -88, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sGunshipBeamOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 704, 8, 0),
};

static const u16 sGunshipBeamOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-15, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 704, 8, 0),
    OAM_ENTRY(-1, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 706, 8, 0),
};

static const u16 sGunshipBeamOam_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 704, 8, 0),
    OAM_ENTRY(-2, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 706, 8, 0),
};


const struct FrameData sGunshipOam_Idle[2] = {
    [0] = {
        .pFrame = sGunshipOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipBeamOam_Idle[5] = {
    [0] = {
        .pFrame = sGunshipBeamOam_Idle_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sGunshipBeamOam_Idle_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sGunshipBeamOam_Idle_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sGunshipBeamOam_Idle_Frame1,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_Idle[2] = {
    [0] = {
        .pFrame = sGunshipPartOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u16 sGunshipFlashingPal[7 * 16] = INCBIN_U16("data/sprites/gunship_flashing.pal");
