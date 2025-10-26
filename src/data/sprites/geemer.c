#include "data/sprites/geemer.h"
#include "macros.h"

const u32 sGeemerGfx[512 * 2] = INCBIN_U32("data/sprites/geemer.gfx");
const u16 sGeemerPal[16 * 2] = INCBIN_U16("data/sprites/geemer.pal");

static const u16 sGeemerOam_2fcc80_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_2fcc80_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_IdleHorizontal_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_IdleHorizontal_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sGeemerOam_2fcde0_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-8, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_2fcde0_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sGeemerOam_2fcde0_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 8, 0),
};

static const u16 sGeemerOam_CrawlingHorizontal_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_CrawlingHorizontal_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_CrawlingHorizontal_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_CrawlingHorizontal_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_CrawlingHorizontal_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_CrawlingHorizontal_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(1, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_2fce38_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-2, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_2fce38_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_2fce38_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-18, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_2fce38_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-18, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(1, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_2fce38_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-19, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(2, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_2fceb0_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-19, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(2, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
};

static const u16 sGeemerFlashingLightOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
};

static const u16 sGeemerFlashingLightOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0),
};

static const u16 sGeemerFlashingLightOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
};

static const u16 sGeemerOam_2fcc58_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x246, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x246, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
};

static const u16 sGeemerOam_2fcc58_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
};

static const u16 sGeemerOam_2fcc58_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
};

static const u16 sGeemerOam_2fcc80_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
};

static const u16 sGeemerOam_2fcc80_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 8, 0),
};

static const u16 sGeemerOam_2fccb0_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x246, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x246, 8, 0),
    OAM_ENTRY(-9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
};

static const u16 sGeemerOam_2fcce8_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sGeemerOam_2fcce8_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sGeemerOam_IdleVertical_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sGeemerOam_IdleVertical_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sGeemerOam_2fcf70_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sGeemerOam_2fcf70_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sGeemerOam_2fcf70_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
};

static const u16 sGeemerOam_CrawlingVertical_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_CrawlingVertical_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-2, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_CrawlingVertical_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-2, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_CrawlingVertical_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_CrawlingVertical_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-2, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_CrawlingVertical_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-2, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_2fcfc8_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
};

static const u16 sGeemerOam_2fcfc8_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_2fcfc8_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_2fcfc8_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_2fcfc8_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(1, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(1, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_2fd040_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(1, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(1, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
};

static const u16 sGeemerOam_2fcce8_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
};

static const u16 sGeemerOam_2fcd18_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
};

static const u16 sGeemerOam_2fcd18_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
};

static const u16 sGeemerOam_2fcce8_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sGeemerOam_2fcce8_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(0, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x258, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
};

static const u16 sGeemerOam_2fcd40_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-1, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
};

static const u16 sGeemerOam_UncoveringHorizontal_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-18, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_HidingHorizontal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-18, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(1, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_HidingHorizontal_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-18, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 8, 0),
};

static const u16 sGeemerOam_HidingHorizontal_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-17, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 8, 0),
};

static const u16 sGeemerOam_HidingHorizontal_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-15, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-2, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
};

static const u16 sGeemerOam_HidingHorizontal_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
};

static const u16 sGeemerOam_UncoveringVertical_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_HidingVertical_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

static const u16 sGeemerOam_HidingVertical_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-1, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
};

static const u16 sGeemerOam_HidingVertical_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(1, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sGeemerOam_HidingVertical_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-1, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
};

static const u16 sGeemerOam_HidingVertical_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
};

static const u16 sGeemerOam_HidingHorizontal_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-19, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
};

static const u16 sGeemerOam_HidingVertical_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
};

const struct FrameData sGeemerOam_2fcc58[5] = {
    [0] = {
        .pFrame = sGeemerOam_2fcc58_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sGeemerOam_2fcc58_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sGeemerOam_2fcc58_Frame0,
        .timer = 12
    },
    [3] = {
        .pFrame = sGeemerOam_2fcc58_Frame3,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fcc80[6] = {
    [0] = {
        .pFrame = sGeemerOam_2fcc58_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sGeemerOam_2fcc80_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sGeemerOam_2fcc80_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sGeemerOam_2fcc80_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sGeemerOam_2fcc80_Frame4,
        .timer = 20
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fccb0[7] = {
    [0] = {
        .pFrame = sGeemerOam_2fccb0_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sGeemerOam_2fcc58_Frame0,
        .timer = 2
    },
    [2] = {
        .pFrame = sGeemerOam_2fccb0_Frame0,
        .timer = 2
    },
    [3] = {
        .pFrame = sGeemerOam_2fcc58_Frame0,
        .timer = 2
    },
    [4] = {
        .pFrame = sGeemerOam_2fccb0_Frame0,
        .timer = 2
    },
    [5] = {
        .pFrame = sGeemerOam_2fcc58_Frame0,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fcce8[6] = {
    [0] = {
        .pFrame = sGeemerOam_2fcce8_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sGeemerOam_2fcce8_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sGeemerOam_2fcce8_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sGeemerOam_2fcce8_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sGeemerOam_2fcce8_Frame4,
        .timer = 20
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fcd18[5] = {
    [0] = {
        .pFrame = sGeemerOam_2fcce8_Frame0,
        .timer = 12
    },
    [1] = {
        .pFrame = sGeemerOam_2fcd18_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sGeemerOam_2fcce8_Frame0,
        .timer = 12
    },
    [3] = {
        .pFrame = sGeemerOam_2fcd18_Frame3,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fcd40[7] = {
    [0] = {
        .pFrame = sGeemerOam_2fcd40_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sGeemerOam_2fcce8_Frame0,
        .timer = 2
    },
    [2] = {
        .pFrame = sGeemerOam_2fcd40_Frame0,
        .timer = 2
    },
    [3] = {
        .pFrame = sGeemerOam_2fcce8_Frame0,
        .timer = 2
    },
    [4] = {
        .pFrame = sGeemerOam_2fcd40_Frame0,
        .timer = 2
    },
    [5] = {
        .pFrame = sGeemerOam_2fcce8_Frame0,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerFlashingLightOam_Idle[4] = {
    [0] = {
        .pFrame = sGeemerFlashingLightOam_Idle_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sGeemerFlashingLightOam_Idle_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sGeemerFlashingLightOam_Idle_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_IdleHorizontal[9] = {
    [0] = {
        .pFrame = sGeemerOam_2fcc80_Frame4,
        .timer = 12
    },
    [1] = {
        .pFrame = sGeemerOam_2fcc80_Frame3,
        .timer = 12
    },
    [2] = {
        .pFrame = sGeemerOam_IdleHorizontal_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sGeemerOam_IdleHorizontal_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sGeemerOam_2fcc80_Frame4,
        .timer = 12
    },
    [5] = {
        .pFrame = sGeemerOam_2fcc80_Frame3,
        .timer = 12
    },
    [6] = {
        .pFrame = sGeemerOam_IdleHorizontal_Frame2,
        .timer = 6
    },
    [7] = {
        .pFrame = sGeemerOam_IdleHorizontal_Frame3,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fcde0[4] = {
    [0] = {
        .pFrame = sGeemerOam_2fcde0_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sGeemerOam_2fcde0_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sGeemerOam_2fcde0_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_CrawlingHorizontal[7] = {
    [0] = {
        .pFrame = sGeemerOam_CrawlingHorizontal_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sGeemerOam_CrawlingHorizontal_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sGeemerOam_CrawlingHorizontal_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sGeemerOam_CrawlingHorizontal_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sGeemerOam_CrawlingHorizontal_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sGeemerOam_CrawlingHorizontal_Frame5,
        .timer = 5
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fce38[15] = {
    [0] = {
        .pFrame = sGeemerOam_2fce38_Frame0,
        .timer = 20
    },
    [1] = {
        .pFrame = sGeemerOam_2fce38_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sGeemerOam_2fce38_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sGeemerOam_2fce38_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sGeemerOam_2fce38_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sGeemerOam_2fce38_Frame3,
        .timer = 2
    },
    [6] = {
        .pFrame = sGeemerOam_2fce38_Frame4,
        .timer = 2
    },
    [7] = {
        .pFrame = sGeemerOam_2fce38_Frame3,
        .timer = 2
    },
    [8] = {
        .pFrame = sGeemerOam_2fce38_Frame4,
        .timer = 2
    },
    [9] = {
        .pFrame = sGeemerOam_2fce38_Frame3,
        .timer = 2
    },
    [10] = {
        .pFrame = sGeemerOam_2fce38_Frame4,
        .timer = 2
    },
    [11] = {
        .pFrame = sGeemerOam_2fce38_Frame3,
        .timer = 2
    },
    [12] = {
        .pFrame = sGeemerOam_2fce38_Frame4,
        .timer = 8
    },
    [13] = {
        .pFrame = sGeemerOam_2fce38_Frame1,
        .timer = 10
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fceb0[3] = {
    [0] = {
        .pFrame = sGeemerOam_2fce38_Frame4,
        .timer = 4
    },
    [1] = {
        .pFrame = sGeemerOam_2fceb0_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_HidingHorizontal[8] = {
    [0] = {
        .pFrame = sGeemerOam_HidingHorizontal_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sGeemerOam_HidingHorizontal_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sGeemerOam_HidingHorizontal_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sGeemerOam_HidingHorizontal_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sGeemerOam_HidingHorizontal_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sGeemerOam_HidingHorizontal_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sGeemerOam_HidingHorizontal_Frame4,
        .timer = 255
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_UncoveringHorizontal[4] = {
    [0] = {
        .pFrame = sGeemerOam_HidingHorizontal_Frame3,
        .timer = 7
    },
    [1] = {
        .pFrame = sGeemerOam_HidingHorizontal_Frame2,
        .timer = 7
    },
    [2] = {
        .pFrame = sGeemerOam_UncoveringHorizontal_Frame2,
        .timer = 7
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_IdleVertical[9] = {
    [0] = {
        .pFrame = sGeemerOam_2fcce8_Frame4,
        .timer = 12
    },
    [1] = {
        .pFrame = sGeemerOam_2fcce8_Frame3,
        .timer = 12
    },
    [2] = {
        .pFrame = sGeemerOam_IdleVertical_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sGeemerOam_IdleVertical_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sGeemerOam_2fcce8_Frame4,
        .timer = 12
    },
    [5] = {
        .pFrame = sGeemerOam_2fcce8_Frame3,
        .timer = 12
    },
    [6] = {
        .pFrame = sGeemerOam_IdleVertical_Frame2,
        .timer = 6
    },
    [7] = {
        .pFrame = sGeemerOam_IdleVertical_Frame3,
        .timer = 6
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fcf70[4] = {
    [0] = {
        .pFrame = sGeemerOam_2fcf70_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sGeemerOam_2fcf70_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sGeemerOam_2fcf70_Frame2,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_CrawlingVertical[7] = {
    [0] = {
        .pFrame = sGeemerOam_CrawlingVertical_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sGeemerOam_CrawlingVertical_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sGeemerOam_CrawlingVertical_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sGeemerOam_CrawlingVertical_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sGeemerOam_CrawlingVertical_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sGeemerOam_CrawlingVertical_Frame5,
        .timer = 5
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fcfc8[15] = {
    [0] = {
        .pFrame = sGeemerOam_2fcfc8_Frame0,
        .timer = 20
    },
    [1] = {
        .pFrame = sGeemerOam_2fcfc8_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sGeemerOam_2fcfc8_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sGeemerOam_2fcfc8_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sGeemerOam_2fcfc8_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sGeemerOam_2fcfc8_Frame3,
        .timer = 2
    },
    [6] = {
        .pFrame = sGeemerOam_2fcfc8_Frame4,
        .timer = 2
    },
    [7] = {
        .pFrame = sGeemerOam_2fcfc8_Frame3,
        .timer = 2
    },
    [8] = {
        .pFrame = sGeemerOam_2fcfc8_Frame4,
        .timer = 2
    },
    [9] = {
        .pFrame = sGeemerOam_2fcfc8_Frame3,
        .timer = 2
    },
    [10] = {
        .pFrame = sGeemerOam_2fcfc8_Frame4,
        .timer = 2
    },
    [11] = {
        .pFrame = sGeemerOam_2fcfc8_Frame3,
        .timer = 2
    },
    [12] = {
        .pFrame = sGeemerOam_2fcfc8_Frame4,
        .timer = 8
    },
    [13] = {
        .pFrame = sGeemerOam_2fcfc8_Frame1,
        .timer = 10
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_2fd040[3] = {
    [0] = {
        .pFrame = sGeemerOam_2fcfc8_Frame4,
        .timer = 4
    },
    [1] = {
        .pFrame = sGeemerOam_2fd040_Frame1,
        .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_HidingVertical[8] = {
    [0] = {
        .pFrame = sGeemerOam_HidingVertical_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sGeemerOam_HidingVertical_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sGeemerOam_HidingVertical_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sGeemerOam_HidingVertical_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sGeemerOam_HidingVertical_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sGeemerOam_HidingVertical_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sGeemerOam_HidingVertical_Frame4,
        .timer = 255
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeemerOam_UncoveringVertical[4] = {
    [0] = {
        .pFrame = sGeemerOam_HidingVertical_Frame3,
        .timer = 7
    },
    [1] = {
        .pFrame = sGeemerOam_HidingVertical_Frame2,
        .timer = 7
    },
    [2] = {
        .pFrame = sGeemerOam_UncoveringVertical_Frame2,
        .timer = 7
    },
    [3] = FRAME_DATA_TERMINATOR
};
