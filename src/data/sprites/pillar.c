#include "data/sprites/pillar.h"
#include "macros.h"

const u32 sPillarGfx[512 * 1] = INCBIN_U32("data/sprites/pillar.gfx");
const u16 sPillarPal[16 * 1] = INCBIN_U16("data/sprites/pillar.pal");

static const u16 sPillarOam_37a984_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sPillarOam_37a984_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sPillarOam_37a984_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame10[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame11[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame12[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame13[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame14[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame15[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame17[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame18[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -52, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame19[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -54, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame20[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame21[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -58, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame22[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame23[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -62, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a7b4_Frame24[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sPillarOam_37a94c_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sPillarOam_37a94c_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sPillarOam_37a94c_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
};

static const u16 sPillarOam_37ab8c_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sPillarOam_37ab8c_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sPillarOam_37ab8c_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(12, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x217, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(14, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x217, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(14, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(26, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame10[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(28, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame11[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(30, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame12[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame13[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame14[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(28, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame15[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(30, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame17[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(42, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame18[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(44, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame19[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(46, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame20[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame21[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(42, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame22[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(44, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame23[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(46, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sPillarOam_37a9bc_Frame24[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
};

static const u16 sPillarOam_37ab54_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sPillarOam_37ab54_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sPillarOam_37ab54_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
};

const struct FrameData sPillarOam_37a7b4[26] = {
    [0] = {
        .pFrame = sPillarOam_37a7b4_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPillarOam_37a7b4_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sPillarOam_37a7b4_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sPillarOam_37a7b4_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPillarOam_37a7b4_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sPillarOam_37a7b4_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sPillarOam_37a7b4_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sPillarOam_37a7b4_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sPillarOam_37a7b4_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sPillarOam_37a7b4_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sPillarOam_37a7b4_Frame10,
        .timer = 2
    },
    [11] = {
        .pFrame = sPillarOam_37a7b4_Frame11,
        .timer = 2
    },
    [12] = {
        .pFrame = sPillarOam_37a7b4_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sPillarOam_37a7b4_Frame13,
        .timer = 2
    },
    [14] = {
        .pFrame = sPillarOam_37a7b4_Frame14,
        .timer = 2
    },
    [15] = {
        .pFrame = sPillarOam_37a7b4_Frame15,
        .timer = 2
    },
    [16] = {
        .pFrame = sPillarOam_37a7b4_Frame16,
        .timer = 2
    },
    [17] = {
        .pFrame = sPillarOam_37a7b4_Frame17,
        .timer = 2
    },
    [18] = {
        .pFrame = sPillarOam_37a7b4_Frame18,
        .timer = 2
    },
    [19] = {
        .pFrame = sPillarOam_37a7b4_Frame19,
        .timer = 2
    },
    [20] = {
        .pFrame = sPillarOam_37a7b4_Frame20,
        .timer = 2
    },
    [21] = {
        .pFrame = sPillarOam_37a7b4_Frame21,
        .timer = 2
    },
    [22] = {
        .pFrame = sPillarOam_37a7b4_Frame22,
        .timer = 2
    },
    [23] = {
        .pFrame = sPillarOam_37a7b4_Frame23,
        .timer = 2
    },
    [24] = {
        .pFrame = sPillarOam_37a7b4_Frame24,
        .timer = 2
    },
    [25] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPillarOam_37a884[25] = {
    [0] = {
        .pFrame = sPillarOam_37a7b4_Frame24,
        .timer = 2
    },
    [1] = {
        .pFrame = sPillarOam_37a7b4_Frame23,
        .timer = 2
    },
    [2] = {
        .pFrame = sPillarOam_37a7b4_Frame22,
        .timer = 2
    },
    [3] = {
        .pFrame = sPillarOam_37a7b4_Frame21,
        .timer = 2
    },
    [4] = {
        .pFrame = sPillarOam_37a7b4_Frame20,
        .timer = 2
    },
    [5] = {
        .pFrame = sPillarOam_37a7b4_Frame19,
        .timer = 2
    },
    [6] = {
        .pFrame = sPillarOam_37a7b4_Frame18,
        .timer = 2
    },
    [7] = {
        .pFrame = sPillarOam_37a7b4_Frame17,
        .timer = 2
    },
    [8] = {
        .pFrame = sPillarOam_37a7b4_Frame16,
        .timer = 2
    },
    [9] = {
        .pFrame = sPillarOam_37a7b4_Frame15,
        .timer = 2
    },
    [10] = {
        .pFrame = sPillarOam_37a7b4_Frame14,
        .timer = 2
    },
    [11] = {
        .pFrame = sPillarOam_37a7b4_Frame13,
        .timer = 2
    },
    [12] = {
        .pFrame = sPillarOam_37a7b4_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sPillarOam_37a7b4_Frame11,
        .timer = 2
    },
    [14] = {
        .pFrame = sPillarOam_37a7b4_Frame10,
        .timer = 2
    },
    [15] = {
        .pFrame = sPillarOam_37a7b4_Frame9,
        .timer = 2
    },
    [16] = {
        .pFrame = sPillarOam_37a7b4_Frame8,
        .timer = 2
    },
    [17] = {
        .pFrame = sPillarOam_37a7b4_Frame7,
        .timer = 2
    },
    [18] = {
        .pFrame = sPillarOam_37a7b4_Frame6,
        .timer = 2
    },
    [19] = {
        .pFrame = sPillarOam_37a7b4_Frame5,
        .timer = 2
    },
    [20] = {
        .pFrame = sPillarOam_37a7b4_Frame4,
        .timer = 2
    },
    [21] = {
        .pFrame = sPillarOam_37a7b4_Frame3,
        .timer = 2
    },
    [22] = {
        .pFrame = sPillarOam_37a7b4_Frame2,
        .timer = 2
    },
    [23] = {
        .pFrame = sPillarOam_37a7b4_Frame1,
        .timer = 2
    },
    [24] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPillarOam_37a94c[7] = {
    [0] = {
        .pFrame = sPillarOam_37a94c_Frame0,
        .timer = 14
    },
    [1] = {
        .pFrame = sPillarOam_37a94c_Frame1,
        .timer = 20
    },
    [2] = {
        .pFrame = sPillarOam_37a94c_Frame0,
        .timer = 14
    },
    [3] = {
        .pFrame = sPillarOam_37a7b4_Frame24,
        .timer = 14
    },
    [4] = {
        .pFrame = sPillarOam_37a94c_Frame4,
        .timer = 50
    },
    [5] = {
        .pFrame = sPillarOam_37a7b4_Frame24,
        .timer = 14
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPillarOam_37a984[7] = {
    [0] = {
        .pFrame = sPillarOam_37a984_Frame0,
        .timer = 14
    },
    [1] = {
        .pFrame = sPillarOam_37a984_Frame1,
        .timer = 20
    },
    [2] = {
        .pFrame = sPillarOam_37a984_Frame0,
        .timer = 14
    },
    [3] = {
        .pFrame = sPillarOam_37a7b4_Frame0,
        .timer = 14
    },
    [4] = {
        .pFrame = sPillarOam_37a984_Frame4,
        .timer = 50
    },
    [5] = {
        .pFrame = sPillarOam_37a7b4_Frame0,
        .timer = 14
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPillarOam_37a9bc[26] = {
    [0] = {
        .pFrame = sPillarOam_37a9bc_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sPillarOam_37a9bc_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sPillarOam_37a9bc_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sPillarOam_37a9bc_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sPillarOam_37a9bc_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sPillarOam_37a9bc_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sPillarOam_37a9bc_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sPillarOam_37a9bc_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sPillarOam_37a9bc_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sPillarOam_37a9bc_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sPillarOam_37a9bc_Frame10,
        .timer = 2
    },
    [11] = {
        .pFrame = sPillarOam_37a9bc_Frame11,
        .timer = 2
    },
    [12] = {
        .pFrame = sPillarOam_37a9bc_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sPillarOam_37a9bc_Frame13,
        .timer = 2
    },
    [14] = {
        .pFrame = sPillarOam_37a9bc_Frame14,
        .timer = 2
    },
    [15] = {
        .pFrame = sPillarOam_37a9bc_Frame15,
        .timer = 2
    },
    [16] = {
        .pFrame = sPillarOam_37a9bc_Frame16,
        .timer = 2
    },
    [17] = {
        .pFrame = sPillarOam_37a9bc_Frame17,
        .timer = 2
    },
    [18] = {
        .pFrame = sPillarOam_37a9bc_Frame18,
        .timer = 2
    },
    [19] = {
        .pFrame = sPillarOam_37a9bc_Frame19,
        .timer = 2
    },
    [20] = {
        .pFrame = sPillarOam_37a9bc_Frame20,
        .timer = 2
    },
    [21] = {
        .pFrame = sPillarOam_37a9bc_Frame21,
        .timer = 2
    },
    [22] = {
        .pFrame = sPillarOam_37a9bc_Frame22,
        .timer = 2
    },
    [23] = {
        .pFrame = sPillarOam_37a9bc_Frame23,
        .timer = 2
    },
    [24] = {
        .pFrame = sPillarOam_37a9bc_Frame24,
        .timer = 2
    },
    [25] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPillarOam_37aa8c[25] = {
    [0] = {
        .pFrame = sPillarOam_37a9bc_Frame24,
        .timer = 2
    },
    [1] = {
        .pFrame = sPillarOam_37a9bc_Frame23,
        .timer = 2
    },
    [2] = {
        .pFrame = sPillarOam_37a9bc_Frame22,
        .timer = 2
    },
    [3] = {
        .pFrame = sPillarOam_37a9bc_Frame21,
        .timer = 2
    },
    [4] = {
        .pFrame = sPillarOam_37a9bc_Frame20,
        .timer = 2
    },
    [5] = {
        .pFrame = sPillarOam_37a9bc_Frame19,
        .timer = 2
    },
    [6] = {
        .pFrame = sPillarOam_37a9bc_Frame18,
        .timer = 2
    },
    [7] = {
        .pFrame = sPillarOam_37a9bc_Frame17,
        .timer = 2
    },
    [8] = {
        .pFrame = sPillarOam_37a9bc_Frame16,
        .timer = 2
    },
    [9] = {
        .pFrame = sPillarOam_37a9bc_Frame15,
        .timer = 2
    },
    [10] = {
        .pFrame = sPillarOam_37a9bc_Frame14,
        .timer = 2
    },
    [11] = {
        .pFrame = sPillarOam_37a9bc_Frame13,
        .timer = 2
    },
    [12] = {
        .pFrame = sPillarOam_37a9bc_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sPillarOam_37a9bc_Frame11,
        .timer = 2
    },
    [14] = {
        .pFrame = sPillarOam_37a9bc_Frame10,
        .timer = 2
    },
    [15] = {
        .pFrame = sPillarOam_37a9bc_Frame9,
        .timer = 2
    },
    [16] = {
        .pFrame = sPillarOam_37a9bc_Frame8,
        .timer = 2
    },
    [17] = {
        .pFrame = sPillarOam_37a9bc_Frame7,
        .timer = 2
    },
    [18] = {
        .pFrame = sPillarOam_37a9bc_Frame6,
        .timer = 2
    },
    [19] = {
        .pFrame = sPillarOam_37a9bc_Frame5,
        .timer = 2
    },
    [20] = {
        .pFrame = sPillarOam_37a9bc_Frame4,
        .timer = 2
    },
    [21] = {
        .pFrame = sPillarOam_37a9bc_Frame3,
        .timer = 2
    },
    [22] = {
        .pFrame = sPillarOam_37a9bc_Frame2,
        .timer = 2
    },
    [23] = {
        .pFrame = sPillarOam_37a9bc_Frame1,
        .timer = 2
    },
    [24] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPillarOam_37ab54[7] = {
    [0] = {
        .pFrame = sPillarOam_37ab54_Frame0,
        .timer = 14
    },
    [1] = {
        .pFrame = sPillarOam_37ab54_Frame1,
        .timer = 20
    },
    [2] = {
        .pFrame = sPillarOam_37ab54_Frame0,
        .timer = 14
    },
    [3] = {
        .pFrame = sPillarOam_37a9bc_Frame24,
        .timer = 14
    },
    [4] = {
        .pFrame = sPillarOam_37ab54_Frame4,
        .timer = 50
    },
    [5] = {
        .pFrame = sPillarOam_37a9bc_Frame24,
        .timer = 14
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPillarOam_37ab8c[7] = {
    [0] = {
        .pFrame = sPillarOam_37ab8c_Frame0,
        .timer = 14
    },
    [1] = {
        .pFrame = sPillarOam_37ab8c_Frame1,
        .timer = 20
    },
    [2] = {
        .pFrame = sPillarOam_37ab8c_Frame0,
        .timer = 14
    },
    [3] = {
        .pFrame = sPillarOam_37a9bc_Frame0,
        .timer = 14
    },
    [4] = {
        .pFrame = sPillarOam_37ab8c_Frame4,
        .timer = 50
    },
    [5] = {
        .pFrame = sPillarOam_37a9bc_Frame0,
        .timer = 14
    },
    [6] = FRAME_DATA_TERMINATOR
};
