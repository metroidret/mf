#include "data/sprites/scientist.h"

const u32 sScientistGfx[2 * 512] = INCBIN_U32("data/sprites/scientist.gfx");
const u16 sScientistPal[2 * 16] = INCBIN_U16("data/sprites/scientist.pal");

static const u16 sScientistOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sScientistOam_Idle_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sScientistOam_Idle_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sScientistOam_TurningHead1_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sScientistOam_TurningHead1_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sScientistOam_TurningHead2_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sScientistOam_TurningHead2_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sScientistOam_TurningHead2_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x223, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sScientistOam_34da54_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sScientistOam_34da54_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sScientistOam_34da54_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sScientistOam_TurningBody_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
};

static const u16 sScientistOam_TurningBody_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(8, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(0, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 8, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(16, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(0, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(16, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-3, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(13, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(5, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 8, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(24, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(24, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(5, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(21, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(13, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 8, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(24, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(24, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(5, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(21, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(13, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 8, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame13[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-5, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(3, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(3, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(11, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(11, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(11, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(19, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x278, 8, 0),
    OAM_ENTRY(19, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x278, 8, 0),
    OAM_ENTRY(19, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x278, 8, 0),
    OAM_ENTRY(27, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x278, 8, 0),
    OAM_ENTRY(19, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(27, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(27, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(35, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25d, 8, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame25[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-3, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(9, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(9, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(3, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(17, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(16, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(32, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 9, 0),
    OAM_ENTRY(19, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(9, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(1, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame35[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-3, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(9, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(9, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(3, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(12, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(17, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(16, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(32, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 9, 0),
    OAM_ENTRY(19, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(9, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(1, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame44[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(10, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(22, -31, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(22, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(16, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(25, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(30, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(29, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(45, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 9, 0),
    OAM_ENTRY(47, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x267, 9, 0),
    OAM_ENTRY(32, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(22, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(14, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame45[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(48, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(25, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25f, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(21, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(34, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(31, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(29, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(32, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(38, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(37, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(53, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 9, 0),
    OAM_ENTRY(41, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(37, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(43, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame46[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(29, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(31, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25f, 8, 0),
    OAM_ENTRY(40, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(56, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25f, 8, 0),
    OAM_ENTRY(38, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(46, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(38, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(36, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(42, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(41, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(41, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(48, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(45, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(51, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame47[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(34, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(39, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(45, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25f, 8, 0),
    OAM_ENTRY(58, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(59, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0),
    OAM_ENTRY(40, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(48, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(40, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(38, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(44, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(43, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(43, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(50, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(48, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(54, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame48[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(42, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(50, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(42, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(40, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(46, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(45, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(45, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(52, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(51, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(57, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame49[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(42, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(50, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(43, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(40, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(46, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(45, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(45, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(52, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(50, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(56, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame50[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(41, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(49, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(42, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(41, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(47, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(46, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(45, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(51, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(49, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(55, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame51[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(41, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(49, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(42, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(47, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(46, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(45, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(51, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(49, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(55, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(40, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame52[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(42, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(50, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(43, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(47, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(46, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(45, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(52, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(50, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(56, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(42, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame53[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(42, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(50, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(43, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(47, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(46, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(45, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(52, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(52, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(58, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(42, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame54[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(42, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(50, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(43, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 9, 0),
    OAM_ENTRY(51, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(47, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(46, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(45, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(52, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(52, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(58, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(42, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame55[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(42, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(50, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 9, 0),
    OAM_ENTRY(43, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x243, 9, 0),
    OAM_ENTRY(47, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(46, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(45, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(52, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(52, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x273, 9, 0),
    OAM_ENTRY(58, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(42, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 9, 0),
};

static const u16 sScientistOam_TransformingIntoZebesian_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 9, 0),
};

const struct FrameData sScientistOam_Idle[13] = {
    [0] = {
        .pFrame = sScientistOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sScientistOam_Idle_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sScientistOam_Idle_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sScientistOam_Idle_Frame1,
        .timer = 8
    },
    [4] = {
        .pFrame = sScientistOam_Idle_Frame2,
        .timer = 8
    },
    [5] = {
        .pFrame = sScientistOam_Idle_Frame0,
        .timer = 8
    },
    [6] = {
        .pFrame = sScientistOam_Idle_Frame2,
        .timer = 8
    },
    [7] = {
        .pFrame = sScientistOam_Idle_Frame0,
        .timer = 8
    },
    [8] = {
        .pFrame = sScientistOam_Idle_Frame1,
        .timer = 8
    },
    [9] = {
        .pFrame = sScientistOam_Idle_Frame0,
        .timer = 8
    },
    [10] = {
        .pFrame = sScientistOam_Idle_Frame2,
        .timer = 8
    },
    [11] = {
        .pFrame = sScientistOam_Idle_Frame1,
        .timer = 8
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sScientistOam_34da54[4] = {
    [0] = {
        .pFrame = sScientistOam_34da54_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sScientistOam_34da54_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sScientistOam_34da54_Frame2,
        .timer = 8
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sScientistOam_TurningHead1[5] = {
    [0] = {
        .pFrame = sScientistOam_Idle_Frame0,
        .timer = 20
    },
    [1] = {
        .pFrame = sScientistOam_TurningHead1_Frame1,
        .timer = 40
    },
    [2] = {
        .pFrame = sScientistOam_Idle_Frame0,
        .timer = 8
    },
    [3] = {
        .pFrame = sScientistOam_TurningHead1_Frame3,
        .timer = 40
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sScientistOam_TurningHead2[5] = {
    [0] = {
        .pFrame = sScientistOam_Idle_Frame0,
        .timer = 20
    },
    [1] = {
        .pFrame = sScientistOam_TurningHead2_Frame1,
        .timer = 40
    },
    [2] = {
        .pFrame = sScientistOam_TurningHead2_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sScientistOam_TurningHead2_Frame3,
        .timer = 40
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sScientistOam_TurningBody[5] = {
    [0] = {
        .pFrame = sScientistOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sScientistOam_TurningHead1_Frame1,
        .timer = 30
    },
    [2] = {
        .pFrame = sScientistOam_TurningBody_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sScientistOam_TurningBody_Frame3,
        .timer = 255
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sScientistOam_TransformingIntoZebesian[65] = {
    [0] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame2,
        .timer = 3
    },
    [6] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [7] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame3,
        .timer = 3
    },
    [8] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 3
    },
    [9] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame2,
        .timer = 3
    },
    [10] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [11] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame3,
        .timer = 3
    },
    [12] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [13] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame13,
        .timer = 3
    },
    [14] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [15] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame3,
        .timer = 3
    },
    [16] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [17] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame13,
        .timer = 3
    },
    [18] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [19] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame3,
        .timer = 3
    },
    [20] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [21] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame3,
        .timer = 3
    },
    [22] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [23] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame13,
        .timer = 3
    },
    [24] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [25] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame25,
        .timer = 3
    },
    [26] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [27] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame13,
        .timer = 3
    },
    [28] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [29] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame25,
        .timer = 3
    },
    [30] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [31] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame13,
        .timer = 3
    },
    [32] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [33] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame25,
        .timer = 3
    },
    [34] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [35] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame35,
        .timer = 3
    },
    [36] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [37] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame25,
        .timer = 3
    },
    [38] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [39] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame35,
        .timer = 3
    },
    [40] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [41] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame25,
        .timer = 3
    },
    [42] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame4,
        .timer = 2
    },
    [43] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame35,
        .timer = 30
    },
    [44] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame44,
        .timer = 6
    },
    [45] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame45,
        .timer = 6
    },
    [46] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame46,
        .timer = 6
    },
    [47] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame47,
        .timer = 6
    },
    [48] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame48,
        .timer = 40
    },
    [49] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame49,
        .timer = 20
    },
    [50] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame50,
        .timer = 14
    },
    [51] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame51,
        .timer = 10
    },
    [52] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame52,
        .timer = 6
    },
    [53] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame53,
        .timer = 20
    },
    [54] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame54,
        .timer = 12
    },
    [55] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame55,
        .timer = 30
    },
    [56] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame54,
        .timer = 12
    },
    [57] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame53,
        .timer = 12
    },
    [58] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame54,
        .timer = 12
    },
    [59] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame55,
        .timer = 30
    },
    [60] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame54,
        .timer = 12
    },
    [61] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame53,
        .timer = 12
    },
    [62] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame54,
        .timer = 12
    },
    [63] = {
        .pFrame = sScientistOam_TransformingIntoZebesian_Frame55,
        .timer = 30
    },
    [64] = FRAME_DATA_TERMINATOR
};
