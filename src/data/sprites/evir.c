#include "data/sprites/evir.h"
#include "macros.h"

const u32 sEvirGfx[512 * 2] = INCBIN_U32("data/sprites/evir.gfx");
const u16 sEvirPal[16 * 2] = INCBIN_U16("data/sprites/evir.pal");

static const u16 sEvirOam_Idle_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-1, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-10, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-17, -34, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Idle_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-1, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-9, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-10, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-17, -33, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Idle_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(0, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-1, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-9, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Idle_Frame3[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-1, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-6, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-10, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-17, -34, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Idle_Frame4[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-1, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-10, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-17, -35, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Idle_Frame5[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-1, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-10, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-17, -34, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Idle_Frame6[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(0, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-1, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-10, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-17, -33, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(1, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Idle_Frame7[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(0, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-6, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-10, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-17, -34, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(1, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Shooting_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(1, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-9, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-16, -34, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(1, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Shooting_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(1, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-9, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-16, -35, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(1, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-10, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_Shooting_Frame2[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(1, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-6, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-10, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-17, -34, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(2, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(9, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-10, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sEvirOam_Shooting_Frame3[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(2, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-5, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-9, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(3, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(10, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(9, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sEvirOam_Shooting_Frame4[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(1, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-9, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(2, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(11, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(12, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
};

static const u16 sEvirOam_Shooting_Frame5[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(0, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-6, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-9, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(1, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
};

static const u16 sEvirOam_Shooting_Frame6[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(0, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-9, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-16, -34, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(6, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(5, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-2, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sEvirOam_TurningAround1_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-3, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-18, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-18, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-2, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-10, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x276, 8, 0),
    OAM_ENTRY(-3, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
};

static const u16 sEvirOam_TurningAround1_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(-16, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(0, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(0, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23d, 8, 0),
};

static const u16 sEvirProjectileOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
};

static const u16 sEvirProjectileOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
};

static const u16 sEvirProjectileOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 8, 0),
};

static const u16 sEvirProjectileOam_Moving_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 8, 0),
};

static const u16 sEvirProjectileOam_Exploding_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(3, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x25f, 8, 0),
    OAM_ENTRY(-10, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-2, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
};

static const u16 sEvirProjectileOam_Exploding_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-6, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-11, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(2, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-11, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(2, 5, OAM_DIMS_8x8, OAM_XY_FLIP, 0x273, 8, 0),
    OAM_ENTRY(5, 2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(7, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x273, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(-15, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21c, 8, 0),
};

static const u16 sEvirProjectileOam_Exploding_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-11, 11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(4, 9, OAM_DIMS_8x8, OAM_XY_FLIP, 0x273, 8, 0),
    OAM_ENTRY(11, 3, OAM_DIMS_8x8, OAM_X_FLIP, 0x273, 8, 0),
    OAM_ENTRY(-19, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(-21, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0),
    OAM_ENTRY(7, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x273, 8, 0),
    OAM_ENTRY(-13, -21, OAM_DIMS_8x8, OAM_Y_FLIP, 0x273, 8, 0),
};

const struct FrameData sEvirOam_Idle[9] = {
    [0] = {
        .pFrame = sEvirOam_Idle_Frame0,
        .timer = 10
    },
    [1] = {
        .pFrame = sEvirOam_Idle_Frame1,
        .timer = 10
    },
    [2] = {
        .pFrame = sEvirOam_Idle_Frame2,
        .timer = 10
    },
    [3] = {
        .pFrame = sEvirOam_Idle_Frame3,
        .timer = 10
    },
    [4] = {
        .pFrame = sEvirOam_Idle_Frame4,
        .timer = 10
    },
    [5] = {
        .pFrame = sEvirOam_Idle_Frame5,
        .timer = 10
    },
    [6] = {
        .pFrame = sEvirOam_Idle_Frame6,
        .timer = 10
    },
    [7] = {
        .pFrame = sEvirOam_Idle_Frame7,
        .timer = 10
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEvirOam_Shooting[8] = {
    [0] = {
        .pFrame = sEvirOam_Shooting_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sEvirOam_Shooting_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sEvirOam_Shooting_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sEvirOam_Shooting_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sEvirOam_Shooting_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sEvirOam_Shooting_Frame5,
        .timer = 6
    },
    [6] = {
        .pFrame = sEvirOam_Shooting_Frame6,
        .timer = 10
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEvirOam_TurningAround1[4] = {
    [0] = {
        .pFrame = sEvirOam_Idle_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sEvirOam_TurningAround1_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sEvirOam_TurningAround1_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEvirOam_TurningAround2[4] = {
    [0] = {
        .pFrame = sEvirOam_TurningAround1_Frame2,
        .timer = 4
    },
    [1] = {
        .pFrame = sEvirOam_TurningAround1_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sEvirOam_Idle_Frame0,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEvirProjectileOam_Moving[5] = {
    [0] = {
        .pFrame = sEvirProjectileOam_Moving_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sEvirProjectileOam_Moving_Frame1,
        .timer = 12
    },
    [2] = {
        .pFrame = sEvirProjectileOam_Moving_Frame2,
        .timer = 12
    },
    [3] = {
        .pFrame = sEvirProjectileOam_Moving_Frame3,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEvirProjectileOam_Exploding[4] = {
    [0] = {
        .pFrame = sEvirProjectileOam_Exploding_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sEvirProjectileOam_Exploding_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sEvirProjectileOam_Exploding_Frame2,
        .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};
