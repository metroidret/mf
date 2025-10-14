#include "data/sprites/zombie_researcher.h"
#include "macros.h"

const s16 sZombieLungingVelocity[4] = {
    2,  4,  2,  1
};

const u32 sZombieGfx[512 * 3] = INCBIN_U32("data/sprites/zombie_researcher.gfx");
const u16 sZombiePal[16 * 3] = INCBIN_U16("data/sprites/zombie_researcher.pal");

static const u16 sZombieOam_Moving_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(0, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2af, 8, 0),
    OAM_ENTRY(-10, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-11, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-11, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-1, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-4, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-1, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-11, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-1, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-4, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame8[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(2, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(2, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-2, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2af, 8, 0),
    OAM_ENTRY(-10, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame9[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(3, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-5, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-2, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame10[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(2, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame11[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-9, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-1, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-10, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame24[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-12, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-1, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2af, 8, 0),
    OAM_ENTRY(-10, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame25[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-2, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-2, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-5, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame26[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-2, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-2, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-9, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Moving_Frame27[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-9, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-11, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Idle_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(0, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-10, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Idle_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-10, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-1, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Idle_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-1, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Idle_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-10, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-4, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25f, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23a, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame9[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-3, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b1, 8, 0),
    OAM_ENTRY(-15, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-7, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x255, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame10[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-3, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b1, 8, 0),
    OAM_ENTRY(-15, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-7, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x255, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame11[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-3, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-17, -7, OAM_DIMS_32x8, OAM_X_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-9, -13, OAM_DIMS_16x8, OAM_X_FLIP, 0x255, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame12[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-3, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-9, -14, OAM_DIMS_16x8, OAM_X_FLIP, 0x255, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame13[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b1, 8, 0),
    OAM_ENTRY(-15, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-7, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 0x275, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame14[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b1, 8, 0),
    OAM_ENTRY(-15, -15, OAM_DIMS_32x16, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-7, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x275, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame15[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-6, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-17, -15, OAM_DIMS_32x16, OAM_X_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-9, -22, OAM_DIMS_16x8, OAM_X_FLIP, 0x275, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame16[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-6, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ab, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x8, OAM_X_FLIP, 0x275, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame17[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-15, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x293, 8, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2b7, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame18[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-2, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29b, 8, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x29d, 8, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27b, 8, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27d, 8, 0),
    OAM_ENTRY(-5, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25b, 8, 0)
};

static const u16 sZombieOam_FormingFromBlob_Frame19[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(2, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2af, 8, 0),
    OAM_ENTRY(-10, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24e, 8, 0)
};

static const u16 sZombieOam_Dying_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(5, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x242, 8, 0)
};

static const u16 sZombieOam_Dying_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-11, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x245, 8, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a4, 8, 0),
    OAM_ENTRY(14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x283, 8, 0),
    OAM_ENTRY(-14, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x283, 8, 0),
    OAM_ENTRY(2, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0),
    OAM_ENTRY(-17, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0)
};

static const u16 sZombieOam_Dying_Frame3[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-11, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-4, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x263, 8, 0),
    OAM_ENTRY(5, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x288, 8, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(12, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(6, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0),
    OAM_ENTRY(-8, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0),
    OAM_ENTRY(-18, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x283, 8, 0)
};

static const u16 sZombieOam_Dying_Frame4[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-12, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x267, 8, 0),
    OAM_ENTRY(12, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24b, 8, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(14, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x263, 8, 0),
    OAM_ENTRY(-6, -17, OAM_DIMS_8x8, OAM_XY_FLIP, 0x2a8, 8, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a8, 8, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0),
    OAM_ENTRY(-2, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0),
    OAM_ENTRY(-18, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x283, 8, 0)
};

static const u16 sZombieOam_Dying_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(12, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24d, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x267, 8, 0),
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0)
};

static const u16 sZombieOam_Dying_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-12, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x267, 8, 0)
};

static const u16 sZombieOam_FormingFromPieces_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-11, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x247, 8, 0)
};

static const u16 sZombieOam_TurningIntoBlob_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x287, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x243, 8, 0)
};

static const u16 sZombieOam_Turning_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ab, 8, 0),
    OAM_ENTRY(3, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29e, 8, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-10, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_2fb17e[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x2ab, 8, 0),
    OAM_ENTRY(-11, -23, OAM_DIMS_8x16, OAM_X_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x29e, 8, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(2, -27, OAM_DIMS_8x16, OAM_X_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_EndLunging_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-7, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28b, 8, 0),
    OAM_ENTRY(-1, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-1, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(-5, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-9, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sZombieOam_Lunging_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-10, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0)
};

static const u16 sZombieOam_Lunging_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28d, 8, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0)
};

static const u16 sZombieOam_Lunging_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28d, 8, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x235, 8, 0)
};

static const u16 sZombieOam_Lunging_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28d, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b2, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x236, 8, 0)
};

const struct FrameData sZombieOam_FormingFromBlob[21] = {
    [0] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame8,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame9,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame10,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [11] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame11,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [12] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame12,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [13] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame13,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [14] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame14,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [15] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame15,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame16,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [17] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame17,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [18] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame18,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [19] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame19,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [20] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_Idle[5] = {
    [0] = {
        .pFrame = sZombieOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZombieOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sZombieOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZombieOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_Moving[29] = {
    [0] = {
        .pFrame = sZombieOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZombieOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sZombieOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZombieOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sZombieOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sZombieOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = {
        .pFrame = sZombieOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [7] = {
        .pFrame = sZombieOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(3.f / 10)
    },
    [8] = {
        .pFrame = sZombieOam_Moving_Frame8,
        .timer = CONVERT_SECONDS(7.f / 30)
    },
    [9] = {
        .pFrame = sZombieOam_Moving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = {
        .pFrame = sZombieOam_Moving_Frame10,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [11] = {
        .pFrame = sZombieOam_Moving_Frame11,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [12] = {
        .pFrame = sZombieOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [13] = {
        .pFrame = sZombieOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [14] = {
        .pFrame = sZombieOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [15] = {
        .pFrame = sZombieOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [16] = {
        .pFrame = sZombieOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [17] = {
        .pFrame = sZombieOam_Moving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [18] = {
        .pFrame = sZombieOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [19] = {
        .pFrame = sZombieOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(3.f / 10)
    },
    [20] = {
        .pFrame = sZombieOam_Moving_Frame8,
        .timer = CONVERT_SECONDS(7.f / 30)
    },
    [21] = {
        .pFrame = sZombieOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [22] = {
        .pFrame = sZombieOam_Moving_Frame10,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [23] = {
        .pFrame = sZombieOam_Moving_Frame11,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [24] = {
        .pFrame = sZombieOam_Moving_Frame24,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [25] = {
        .pFrame = sZombieOam_Moving_Frame25,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [26] = {
        .pFrame = sZombieOam_Moving_Frame26,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [27] = {
        .pFrame = sZombieOam_Moving_Frame27,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [28] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_Turning[2] = {
    [0] = {
        .pFrame = sZombieOam_Turning_Frame0,
        .timer = CONVERT_SECONDS(7.f / 30)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_Dying[8] = {
    [0] = {
        .pFrame = sZombieOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sZombieOam_Dying_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sZombieOam_Dying_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sZombieOam_Dying_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sZombieOam_Dying_Frame4,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [5] = {
        .pFrame = sZombieOam_Dying_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sZombieOam_Dying_Frame6,
        .timer = UCHAR_MAX
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_Lunging[5] = {
    [0] = {
        .pFrame = sZombieOam_Lunging_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sZombieOam_Lunging_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sZombieOam_Lunging_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sZombieOam_Lunging_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_EndLunging[7] = {
    [0] = {
        .pFrame = sZombieOam_Lunging_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sZombieOam_Lunging_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sZombieOam_Lunging_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sZombieOam_Lunging_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sZombieOam_EndLunging_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sZombieOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_StartLunging[2] = {
    [0] = {
        .pFrame = sZombieOam_EndLunging_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_FormingFromPieces[11] = {
    [0] = {
        .pFrame = sZombieOam_FormingFromPieces_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sZombieOam_Dying_Frame6,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sZombieOam_FormingFromPieces_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sZombieOam_Dying_Frame6,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sZombieOam_FormingFromPieces_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame7,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame10,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame14,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame17,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [9] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame18,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_Blob[21] = {
    [0] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [9] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [10] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [11] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame3,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [12] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [15] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [16] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame0,
        .timer = CONVERT_SECONDS(11.f / 60)
    },
    [17] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [18] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [19] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame3,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [20] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZombieOam_TurningIntoBlob[8] = {
    [0] = {
        .pFrame = sZombieOam_TurningIntoBlob_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sZombieOam_FormingFromBlob_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_2fb610_35dd74[] = INCBIN_U8("data/Blob_2fb610_35dd74.bin");
