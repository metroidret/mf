#include "data/sprites/misc_pad.h"

const u32 sControlPadGfx[2 * 512] = INCBIN_U32("data/sprites/control_pad.gfx");
const u16 sControlPadPal[2 * 16] = INCBIN_U16("data/sprites/control_pad.pal");

static const u16 sControlPadConsoleOam_Inactive_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_8x16, OAM_X_FLIP, 0x24b, 8, 0),
};

static const u16 sControlPadConsoleOam_Inactive_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_8x16, OAM_X_FLIP, 0x248, 8, 0),
};

static const u16 sControlPadConsoleOam_Inactive_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x243, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 8, 0),
};

static const u16 sControlPadConsoleOam_Active_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x251, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_8x16, OAM_X_FLIP, 0x253, 8, 0),
};

static const u16 sControlPadConsoleOam_Active_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-24, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x216, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_8x16, OAM_X_FLIP, 0x256, 8, 0),
};

static const u16 sControlPadConsoleOam_Active_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-24, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x257, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_8x16, OAM_X_FLIP, 0x259, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0),
};

static const u16 sControlPadOam_SwitchUnpressed_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x20e, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 9, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 9, 0),
};

static const u16 sControlPadOam_PressingSwitch_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x20e, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 9, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 9, 0),
};

static const u16 sControlPadOam_PressingSwitch_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22e, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x22e, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x230, 9, 0),
    OAM_ENTRY(-23, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-18, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(2, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(15, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 9, 0),
};

static const u16 sControlPadOam_PressingSwitch_Frame2[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(-24, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 9, 0),
};

static const u16 sControlPadOam_PressingSwitch_Frame3[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(-25, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(17, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 9, 0),
};

static const u16 sControlPadOam_34a03c[] = {
    0
};

static const u16 sControlPadOam_34a03e[] = {
    0
};

static const u16 sControlPadOam_34a040[] = {
    0
};

const struct FrameData sControlPadConsoleOam_Inactive[5] = {
    [0] = {
        .pFrame = sControlPadConsoleOam_Inactive_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sControlPadConsoleOam_Inactive_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sControlPadConsoleOam_Inactive_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sControlPadConsoleOam_Inactive_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sControlPadConsoleOam_Active[5] = {
    [0] = {
        .pFrame = sControlPadConsoleOam_Active_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sControlPadConsoleOam_Active_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sControlPadConsoleOam_Active_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sControlPadConsoleOam_Active_Frame1,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sControlPadOam_PressingSwitch[5] = {
    [0] = {
        .pFrame = sControlPadOam_PressingSwitch_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sControlPadOam_PressingSwitch_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sControlPadOam_PressingSwitch_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sControlPadOam_PressingSwitch_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sControlPadOam_ReleasingSwitch[5] = {
    [0] = {
        .pFrame = sControlPadOam_PressingSwitch_Frame3,
        .timer = 6
    },
    [1] = {
        .pFrame = sControlPadOam_PressingSwitch_Frame2,
        .timer = 6
    },
    [2] = {
        .pFrame = sControlPadOam_PressingSwitch_Frame1,
        .timer = 6
    },
    [3] = {
        .pFrame = sControlPadOam_PressingSwitch_Frame0,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sControlPadOam_SwitchUnpressed[2] = {
    [0] = {
        .pFrame = sControlPadOam_SwitchUnpressed_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sControlPadOam_SwitchPressed[2] = {
    [0] = {
        .pFrame = sControlPadOam_PressingSwitch_Frame3,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u32 sHabitationPadGfx[1 * 512] = INCBIN_U32("data/sprites/habitation_pad.gfx");
const u16 sHabitationPadPal[1 * 16] = INCBIN_U16("data/sprites/habitation_pad.pal");

static const u16 sHabitationPadConsoleOam_Inactive_Frame0[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x236, 8, 0),
};

static const u16 sHabitationPadConsoleOam_Inactive_Frame1[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x218, 8, 0),
};

static const u16 sHabitationPadConsoleOam_Inactive_Frame2[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x238, 8, 0),
};

static const u16 sHabitationPadConsoleOam_Active_Frame0[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x214, 8, 0),
};

static const u16 sHabitationPadConsoleOam_Active_Frame1[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x234, 8, 0),
};

static const u16 sHabitationPadConsoleOam_Active_Frame2[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x8, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x216, 8, 0),
};

static const u16 sHabitationPadOam_SwitchUnpressed_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 8, 0),
};

static const u16 sHabitationPadOam_PressingSwitch_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 8, 0),
};

static const u16 sHabitationPadOam_PressingSwitch_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-23, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-18, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(2, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(15, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 8, 0),
};

static const u16 sHabitationPadOam_PressingSwitch_Frame2[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-24, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 8, 0),
};

static const u16 sHabitationPadOam_PressingSwitch_Frame3[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-25, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(17, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 8, 0),
};

const struct FrameData sHabitationPadConsoleOam_Inactive[5] = {
    [0] = {
        .pFrame = sHabitationPadConsoleOam_Inactive_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sHabitationPadConsoleOam_Inactive_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sHabitationPadConsoleOam_Inactive_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sHabitationPadConsoleOam_Inactive_Frame1,
        .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHabitationPadConsoleOam_Active[5] = {
    [0] = {
        .pFrame = sHabitationPadConsoleOam_Active_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sHabitationPadConsoleOam_Active_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sHabitationPadConsoleOam_Active_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sHabitationPadConsoleOam_Active_Frame1,
        .timer = 10
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHabitationPadOam_PressingSwitch[5] = {
    [0] = {
        .pFrame = sHabitationPadOam_PressingSwitch_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sHabitationPadOam_PressingSwitch_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sHabitationPadOam_PressingSwitch_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sHabitationPadOam_PressingSwitch_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHabitationPadOam_ReleasingSwitch[5] = {
    [0] = {
        .pFrame = sHabitationPadOam_PressingSwitch_Frame3,
        .timer = 6
    },
    [1] = {
        .pFrame = sHabitationPadOam_PressingSwitch_Frame2,
        .timer = 6
    },
    [2] = {
        .pFrame = sHabitationPadOam_PressingSwitch_Frame1,
        .timer = 6
    },
    [3] = {
        .pFrame = sHabitationPadOam_PressingSwitch_Frame0,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHabitationPadOam_SwitchUnpressed[2] = {
    [0] = {
        .pFrame = sHabitationPadOam_SwitchUnpressed_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHabitationPadOam_SwitchPressed[2] = {
    [0] = {
        .pFrame = sHabitationPadOam_PressingSwitch_Frame3,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};
