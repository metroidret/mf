#include "data/sprites/yakuza.h"
#include "macros.h"

const s16 sYakuzaFireBurningSpeed[5] = {
    4, -4, -4, 4, SHORT_MAX
};

const s16 sYakuza_3b0b0e[24] = {
    -28, -24, -20, -16,
    -14, -12, -10, -8,
    -8, -8, -8, -8,
    -6, -4, -2, 0,
    0, 0, 0, 0,
    0, 0, 0, SHORT_MAX
};

const s16 sYakuzaSlammingSpeed[24] = {
    0, 1, 2, 3,
    4, 5, 6, 7,
    8, 9, 10, 11,
    12, 13, 14, 15,
    16, 17, 18, 19,
    20, 21, 22, SHORT_MAX
};

const u8 sYakuzaMouthStartGlowingPalOffset[18] = {
    8, 9, 8, 9,
    8, 9, 10, 11,
    10, 11, 10, 11,
    12, 13, 12, 13,
    14, 13
};

const u8 sYakuzaMouthGlowingPalOffset[12] = {
    14, 15, 14, 15,
    14, 15, 14, 15,
    14, 15, 14, 15
};

const u8 sYakuzaMouthEndGlowingPalOffset[8] = {
    14, 13, 12, 11,
    10, 9, 8, 0
};

const s16 sYakuzaPhase2Speed[16] = {
    -8, -12, -16, -20,
    -16, -12, -8, 0,
    1, 2, 3, 4,
    6, 8, 12, 16
};

static const s16 sYakuzaMultiSpriteData_3b0f28_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f28_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f28_Frame2[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f50_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F30, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7088, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f60_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B70B0, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f60_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B70B0, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f60_Frame2[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B70B0, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f88_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F30, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B70F8, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f98_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7120, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f98_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7120, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0f98_Frame2[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7120, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0fc0_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7140, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0fc0_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7140, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0fc0_Frame2[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7140, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0fe8_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F40, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b0fe8_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F40, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1000_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F68, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1000_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F68, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1000_Frame2[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -1, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F68, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1028_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -1, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F90, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1028_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F90, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1040_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6FA8, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1050_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6FC0, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1060_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6FD0, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1060_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6FD0, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1078_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6FE8, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1078_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -1, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6FE8, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1078_Frame3[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6FE8, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b10a0_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7010, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b10b0_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7028, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b10b0_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7028, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b10b0_Frame2[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7028, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7060, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b10e8_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b10e8_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b10e8_Frame2[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1150_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F58, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1110_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F40, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1110_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F40, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1160_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -1, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F90, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1160_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F90, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1128_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F68, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1128_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F68, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1128_Frame2[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -1, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F68, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7150, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1178_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F30, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7198, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1188_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B71C0, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1188_Frame1[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -3, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B71C0, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b1188_Frame2[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -2, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F08, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B71C0, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b11b0_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F30, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7208, 0, 0)
};

static const s16 sYakuzaMultiSpriteData_3b11c0_Frame0[YAKUZA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [YAKUZA_PART_EYE] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7230, -4, -16),
    [YAKUZA_PART_BODY] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B6F30, 0, 0),
    [YAKUZA_PART_LEGS] = MULTI_SPRITE_DATA_INFO(YAKUZA_OAM_3B7188, 0, 0)
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b0f28[5] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b0f28_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b0f28_Frame1,
        .timer = 6
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b0f28_Frame2,
        .timer = 6
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b0f28_Frame1,
        .timer = 6
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b0f50[2] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b0f50_Frame0,
        .timer = 6
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b0f60[5] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b0f60_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b0f60_Frame1,
        .timer = 6
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b0f60_Frame2,
        .timer = 6
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b0f60_Frame1,
        .timer = 6
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b0f88[2] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b0f88_Frame0,
        .timer = 6
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b0f98[5] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b0f98_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b0f98_Frame1,
        .timer = 6
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b0f98_Frame2,
        .timer = 6
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b0f98_Frame1,
        .timer = 6
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b0fc0[5] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b0fc0_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b0fc0_Frame1,
        .timer = 6
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b0fc0_Frame2,
        .timer = 6
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b0fc0_Frame1,
        .timer = 6
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b0fe8[3] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b0fe8_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b0fe8_Frame1,
        .timer = 6
    },
    [2] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1000[5] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1000_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b1000_Frame1,
        .timer = 6
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b1000_Frame2,
        .timer = 6
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b1000_Frame1,
        .timer = 6
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1028[3] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1028_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b1028_Frame1,
        .timer = 6
    },
    [2] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1040[2] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1040_Frame0,
        .timer = 4
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1050[2] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1050_Frame0,
        .timer = 4
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1060[3] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1060_Frame0,
        .timer = 4
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b1060_Frame1,
        .timer = 4
    },
    [2] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1078[5] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1078_Frame0,
        .timer = 3
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b1078_Frame1,
        .timer = 3
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b1078_Frame0,
        .timer = 3
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b1078_Frame3,
        .timer = 12
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b10a0[2] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b10a0_Frame0,
        .timer = 4
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b10b0[7] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b10b0_Frame0,
        .timer = 2
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b10b0_Frame1,
        .timer = 2
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b10b0_Frame2,
        .timer = 2
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b10b0_Frame1,
        .timer = 2
    },
    [4] = {
        .pData = sYakuzaMultiSpriteData_3b10b0_Frame2,
        .timer = 2
    },
    [5] = {
        .pData = sYakuzaMultiSpriteData_3b10b0_Frame1,
        .timer = 2
    },
    [6] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b10e8[5] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b10e8_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b10e8_Frame1,
        .timer = 6
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b10e8_Frame2,
        .timer = 6
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b10e8_Frame1,
        .timer = 6
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1110[3] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1110_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b1110_Frame1,
        .timer = 6
    },
    [2] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1128[5] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1128_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b1128_Frame1,
        .timer = 6
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b1128_Frame2,
        .timer = 6
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b1128_Frame1,
        .timer = 6
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1150[2] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1150_Frame0,
        .timer = 4
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1160[3] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1160_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b1160_Frame1,
        .timer = 6
    },
    [2] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1178[2] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1178_Frame0,
        .timer = 6
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b1188[5] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b1188_Frame0,
        .timer = 6
    },
    [1] = {
        .pData = sYakuzaMultiSpriteData_3b1188_Frame1,
        .timer = 6
    },
    [2] = {
        .pData = sYakuzaMultiSpriteData_3b1188_Frame2,
        .timer = 6
    },
    [3] = {
        .pData = sYakuzaMultiSpriteData_3b1188_Frame1,
        .timer = 6
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b11b0[2] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b11b0_Frame0,
        .timer = 6
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sYakuzaMultiSpriteData_3b11c0[2] = {
    [0] = {
        .pData = sYakuzaMultiSpriteData_3b11c0_Frame0,
        .timer = 255
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const u32 sYakuzaGfx[512 * 8] = INCBIN_U32("data/sprites/yakuza.gfx");
const u16 sYakuzaPal[16 * 8] = INCBIN_U16("data/sprites/yakuza.pal");

const u16 sYakuzaMouthGlowingPal[8][16] = INCBIN_U16("data/sprites/yakuza_mouth_glowing.pal");

static const u16 sYakuzaPartOam_3b6f08_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d4, 8, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3de, 8, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x367, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x367, 8, 0),
    OAM_ENTRY(-15, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x38e, 8, 0),
    OAM_ENTRY(-1, 2, OAM_DIMS_16x16, OAM_X_FLIP, 0x38e, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x32, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-24, -35, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6f08_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d4, 8, 0),
    OAM_ENTRY(-24, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3de, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x387, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_8x8, OAM_X_FLIP, 0x387, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x38e, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_X_FLIP, 0x38e, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x32, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-24, -35, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6f08_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d4, 8, 0),
    OAM_ENTRY(-24, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3de, 8, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(-17, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x38e, 8, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x16, OAM_X_FLIP, 0x38e, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_32x32, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-24, -36, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -36, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6f40_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x387, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_8x8, OAM_X_FLIP, 0x387, 8, 0),
    OAM_ENTRY(-22, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x390, 8, 0),
    OAM_ENTRY(6, 1, OAM_DIMS_16x16, OAM_X_FLIP, 0x390, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x32, OAM_NO_FLIP, 0x298, 8, 0),
    OAM_ENTRY(-24, -35, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6f40_Frame1[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(-27, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(11, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x318, 8, 0),
    OAM_ENTRY(-24, -34, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6f58_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_8x8, OAM_X_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(-28, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(12, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-24, -33, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6fa8_Frame1[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_8x8, OAM_X_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(-28, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(12, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x29c, 9, 0),
    OAM_ENTRY(-24, -33, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6fc0_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_8x8, OAM_X_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(-28, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(12, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x31c, 9, 0),
    OAM_ENTRY(-24, -33, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6fd0_Frame1[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(-29, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(13, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 0x31c, 9, 0),
    OAM_ENTRY(-24, -33, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6fe8_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_8x8, OAM_X_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(-30, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(14, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x31c, 9, 0),
    OAM_ENTRY(-24, -34, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6fe8_Frame1[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_8x8, OAM_X_FLIP, 0x3a7, 8, 0),
    OAM_ENTRY(-31, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(15, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_32x32, OAM_NO_FLIP, 0x31c, 9, 0),
    OAM_ENTRY(-24, -35, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6f68_Frame1[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(-28, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(12, -1, OAM_DIMS_16x16, OAM_X_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x32, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-24, -33, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b6f68_Frame2[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 0x396, 8, 0),
    OAM_ENTRY(-24, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x394, 8, 0),
    OAM_ENTRY(-24, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d2, 8, 0),
    OAM_ENTRY(-8, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_8x8, OAM_X_FLIP, 0x3c7, 8, 0),
    OAM_ENTRY(-28, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(12, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x3d0, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_32x32, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-24, -34, OAM_DIMS_32x32, OAM_NO_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -34, OAM_DIMS_16x16, OAM_X_FLIP, 0x39a, 8, 0),
    OAM_ENTRY(8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x3da, 8, 0),
};

static const u16 sYakuzaPartOam_3b70b0_Frame0[OAM_DATA_SIZE(21)] = {
    21,
    OAM_ENTRY(-40, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-37, -1, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-21, 23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(9, -9, OAM_DIMS_16x32, OAM_X_FLIP, 0x383, 8, 0),
    OAM_ENTRY(29, -24, OAM_DIMS_8x32, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(29, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(17, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x344, 8, 0),
    OAM_ENTRY(25, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x324, 8, 0),
    OAM_ENTRY(25, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x3cb, 8, 0),
    OAM_ENTRY(13, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(21, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
};

static const u16 sYakuzaPartOam_3b70b0_Frame1[OAM_DATA_SIZE(22)] = {
    22,
    OAM_ENTRY(-40, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-40, -5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-24, 19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -13, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x263, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x265, 8, 0),
    OAM_ENTRY(-54, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-38, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(-34, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x266, 8, 0),
    OAM_ENTRY(7, 1, OAM_DIMS_16x32, OAM_X_FLIP, 0x383, 8, 0),
    OAM_ENTRY(13, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(13, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(30, -16, OAM_DIMS_8x32, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(30, 16, OAM_DIMS_8x8, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(23, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(25, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x3cd, 8, 0),
    OAM_ENTRY(19, -30, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(13, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
};

static const u16 sYakuzaPartOam_3b70b0_Frame2[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-40, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-41, -11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-25, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-37, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-37, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x223, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-31, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-31, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-49, -18, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-41, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-41, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-50, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-34, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(14, 2, OAM_DIMS_16x32, OAM_X_FLIP, 0x385, 8, 0),
    OAM_ENTRY(6, 26, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(15, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(30, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(24, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(26, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x326, 8, 0),
    OAM_ENTRY(34, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x366, 8, 0),
    OAM_ENTRY(14, -25, OAM_DIMS_8x8, OAM_X_FLIP, 0x227, 8, 0),
    OAM_ENTRY(14, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(22, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x226, 8, 0),
};

static const u16 sYakuzaPartOam_3b70b0_Frame3[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-36, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x385, 8, 0),
    OAM_ENTRY(-20, 11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(-33, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x320, 8, 0),
    OAM_ENTRY(-40, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-48, -19, OAM_DIMS_16x32, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-33, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 8, 0),
    OAM_ENTRY(-33, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x324, 8, 0),
    OAM_ENTRY(-47, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x38b, 8, 0),
    OAM_ENTRY(-31, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38d, 8, 0),
    OAM_ENTRY(-30, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-30, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(17, 3, OAM_DIMS_16x32, OAM_X_FLIP, 0x385, 8, 0),
    OAM_ENTRY(9, 27, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e1, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c1, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e0, 8, 0),
    OAM_ENTRY(42, -1, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(34, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(34, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(33, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x326, 8, 0),
    OAM_ENTRY(41, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x366, 8, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e7, 8, 0),
    OAM_ENTRY(34, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e6, 8, 0),
};

static const u16 sYakuzaPartOam_3b70b0_Frame4[OAM_DATA_SIZE(21)] = {
    21,
    OAM_ENTRY(-25, -9, OAM_DIMS_16x32, OAM_NO_FLIP, 0x383, 8, 0),
    OAM_ENTRY(-37, -24, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-37, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-33, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 8, 0),
    OAM_ENTRY(-33, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x324, 8, 0),
    OAM_ENTRY(-41, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3cb, 8, 0),
    OAM_ENTRY(-29, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-29, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(21, -1, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(13, 23, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(24, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_8x16, OAM_X_FLIP, 0x282, 8, 0),
    OAM_ENTRY(43, -7, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, 1, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(40, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(32, -28, OAM_DIMS_8x16, OAM_X_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(18, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(34, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaPartOam_3b70b0_Frame5[OAM_DATA_SIZE(22)] = {
    22,
    OAM_ENTRY(-23, 1, OAM_DIMS_16x32, OAM_NO_FLIP, 0x383, 8, 0),
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-29, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-38, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-38, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-39, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-41, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3cd, 8, 0),
    OAM_ENTRY(-27, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-29, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(24, -5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(16, 19, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(43, -13, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -21, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x263, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x265, 8, 0),
    OAM_ENTRY(38, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x388, 8, 0),
    OAM_ENTRY(30, -35, OAM_DIMS_8x16, OAM_X_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(18, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x266, 8, 0),
};

static const u16 sYakuzaPartOam_3b70b0_Frame6[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-30, 2, OAM_DIMS_16x32, OAM_NO_FLIP, 0x385, 8, 0),
    OAM_ENTRY(-14, 26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(-31, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-31, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-38, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-46, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-40, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-42, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x326, 8, 0),
    OAM_ENTRY(-42, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x366, 8, 0),
    OAM_ENTRY(-22, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-22, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-30, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(25, -11, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(17, 13, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(29, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(21, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x223, 8, 0),
    OAM_ENTRY(13, -20, OAM_DIMS_8x16, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(15, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(23, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(41, -18, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(33, -26, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(33, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(34, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x388, 8, 0),
    OAM_ENTRY(26, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x38a, 8, 0),
};

static const u16 sYakuzaPartOam_3b70b0_Frame7[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-33, 3, OAM_DIMS_16x32, OAM_NO_FLIP, 0x385, 8, 0),
    OAM_ENTRY(-17, 27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e1, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c1, 8, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e0, 8, 0),
    OAM_ENTRY(-50, -1, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-42, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-42, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-49, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x326, 8, 0),
    OAM_ENTRY(-49, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x366, 8, 0),
    OAM_ENTRY(-34, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e7, 8, 0),
    OAM_ENTRY(-42, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e6, 8, 0),
    OAM_ENTRY(20, -13, OAM_DIMS_16x32, OAM_X_FLIP, 0x385, 8, 0),
    OAM_ENTRY(12, 11, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(17, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x320, 8, 0),
    OAM_ENTRY(32, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(32, -19, OAM_DIMS_16x32, OAM_X_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(17, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x344, 8, 0),
    OAM_ENTRY(25, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x324, 8, 0),
    OAM_ENTRY(31, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x38b, 8, 0),
    OAM_ENTRY(23, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x38d, 8, 0),
    OAM_ENTRY(14, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(22, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
};

static const u16 sYakuzaPartOam_3b7150_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-27, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x360, 8, 0),
    OAM_ENTRY(-26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x361, 8, 0),
    OAM_ENTRY(19, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x382, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x3a2, 8, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x3c2, 8, 0),
};

static const u16 sYakuzaPartOam_3b7150_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(18, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-27, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x360, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x361, 8, 0),
    OAM_ENTRY(-26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x382, 8, 0),
    OAM_ENTRY(19, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x3a2, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x3c2, 8, 0),
};

static const u16 sYakuzaPartOam_3b7150_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(16, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x360, 8, 0),
    OAM_ENTRY(-27, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x361, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x382, 8, 0),
    OAM_ENTRY(-26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a2, 8, 0),
    OAM_ENTRY(19, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x3c2, 8, 0),
};

static const u16 sYakuzaPartOam_3b7150_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(19, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x360, 8, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x361, 8, 0),
    OAM_ENTRY(-27, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x382, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a2, 8, 0),
    OAM_ENTRY(-26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3c2, 8, 0),
};

static const u16 sYakuzaPartOam_3b7150_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(19, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x360, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x361, 8, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x382, 8, 0),
    OAM_ENTRY(-27, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a2, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3c2, 8, 0),
};

static const u16 sYakuzaPartOam_3b7150_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x360, 8, 0),
    OAM_ENTRY(19, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x361, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x382, 8, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x3a2, 8, 0),
    OAM_ENTRY(-27, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3c2, 8, 0),
};

static const u16 sYakuzaPartOam_3b70f8_Frame0[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(9, -9, OAM_DIMS_16x32, OAM_X_FLIP, 0x383, 8, 0),
    OAM_ENTRY(29, -24, OAM_DIMS_8x32, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(29, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(17, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x344, 8, 0),
    OAM_ENTRY(25, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x324, 8, 0),
    OAM_ENTRY(25, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x3cb, 8, 0),
    OAM_ENTRY(13, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(21, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-40, -5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-24, 19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0),
    OAM_ENTRY(-51, -13, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x263, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x265, 8, 0),
    OAM_ENTRY(-54, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-38, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(-34, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x266, 8, 0),
};

static const u16 sYakuzaPartOam_3b70f8_Frame1[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(7, 1, OAM_DIMS_16x32, OAM_X_FLIP, 0x383, 8, 0),
    OAM_ENTRY(13, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(13, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(30, -16, OAM_DIMS_8x32, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(30, 16, OAM_DIMS_8x8, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(23, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(25, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x3cd, 8, 0),
    OAM_ENTRY(19, -30, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(13, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-36, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x385, 8, 0),
    OAM_ENTRY(-20, 11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(-33, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x320, 8, 0),
    OAM_ENTRY(-37, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-37, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x223, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-49, -18, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-41, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-41, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-31, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-31, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-49, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-33, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
};

static const u16 sYakuzaPartOam_3b70f8_Frame2[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(14, 2, OAM_DIMS_16x32, OAM_X_FLIP, 0x385, 8, 0),
    OAM_ENTRY(6, 26, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(15, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(30, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(24, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(26, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x326, 8, 0),
    OAM_ENTRY(34, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x366, 8, 0),
    OAM_ENTRY(14, -25, OAM_DIMS_8x8, OAM_X_FLIP, 0x227, 8, 0),
    OAM_ENTRY(14, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(22, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-34, -6, OAM_DIMS_16x32, OAM_NO_FLIP, 0x385, 8, 0),
    OAM_ENTRY(-18, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(-33, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x281, 8, 0),
    OAM_ENTRY(-41, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-25, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-49, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-41, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-41, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-31, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-31, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-50, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-34, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
};

static const u16 sYakuzaPartOam_3b70f8_Frame3[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(17, 3, OAM_DIMS_16x32, OAM_X_FLIP, 0x385, 8, 0),
    OAM_ENTRY(9, 27, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e1, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c1, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e0, 8, 0),
    OAM_ENTRY(42, -1, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(34, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(34, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(33, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x326, 8, 0),
    OAM_ENTRY(41, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x366, 8, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e7, 8, 0),
    OAM_ENTRY(34, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e6, 8, 0),
    OAM_ENTRY(-33, 3, OAM_DIMS_16x32, OAM_NO_FLIP, 0x385, 8, 0),
    OAM_ENTRY(-17, 27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e1, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c1, 8, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e0, 8, 0),
    OAM_ENTRY(-50, -1, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-42, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-42, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-54, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-38, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(-34, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x266, 8, 0),
};

static const u16 sYakuzaPartOam_3b7060_Frame0[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-40, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-37, -1, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-21, 23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(24, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_8x16, OAM_X_FLIP, 0x282, 8, 0),
    OAM_ENTRY(21, -1, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(13, 23, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(43, -7, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, 1, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(40, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(32, -28, OAM_DIMS_8x16, OAM_X_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(18, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(34, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaPartOam_3b7120_Frame0[OAM_DATA_SIZE(28)] = {
    28,
    OAM_ENTRY(-32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c1, 8, 0),
    OAM_ENTRY(-32, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x301, 8, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e0, 8, 0),
    OAM_ENTRY(-33, 2, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-17, 26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c1, 8, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x301, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e0, 8, 0),
    OAM_ENTRY(17, 2, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(9, 26, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(43, -7, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, 1, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(40, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(32, -28, OAM_DIMS_8x16, OAM_X_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(18, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(34, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaPartOam_3b7120_Frame1[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-32, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-27, 7, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-11, 31, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 10, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(11, 7, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(3, 31, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(43, -7, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, 1, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(40, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(32, -28, OAM_DIMS_8x16, OAM_X_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(18, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(34, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaPartOam_3b7120_Frame2[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(43, -7, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, 1, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(40, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(32, -28, OAM_DIMS_8x16, OAM_X_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(18, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(34, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaPartOam_3b7060_Frame1[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-40, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-37, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-21, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -6, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(24, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_8x16, OAM_X_FLIP, 0x282, 8, 0),
    OAM_ENTRY(21, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(13, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(43, -6, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -14, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(40, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(32, -27, OAM_DIMS_8x16, OAM_X_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(18, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(34, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaPartOam_3b7060_Frame2[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-39, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-23, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-36, 2, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-20, 26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-50, -6, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-42, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-42, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-39, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-23, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-55, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-39, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-33, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-41, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(23, -5, OAM_DIMS_16x16, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(15, -5, OAM_DIMS_8x16, OAM_X_FLIP, 0x282, 8, 0),
    OAM_ENTRY(20, 2, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(12, 26, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(42, -6, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(34, -14, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(34, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(23, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(15, -17, OAM_DIMS_8x16, OAM_X_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(39, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(31, -27, OAM_DIMS_8x16, OAM_X_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(17, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(33, -25, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaPartOam_3b7088_Frame1[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-40, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-37, -1, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-21, 23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 8, 0),
    OAM_ENTRY(24, -5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(16, 19, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(43, -13, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -21, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x263, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x265, 8, 0),
    OAM_ENTRY(38, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x388, 8, 0),
    OAM_ENTRY(30, -35, OAM_DIMS_8x16, OAM_X_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(18, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x266, 8, 0),
};

static const u16 sYakuzaPartOam_3b7088_Frame2[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-40, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-37, -1, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-21, 23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(25, -11, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(17, 13, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(29, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(21, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x223, 8, 0),
    OAM_ENTRY(13, -20, OAM_DIMS_8x16, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(15, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(23, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(41, -18, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(33, -26, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(33, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(34, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x388, 8, 0),
    OAM_ENTRY(26, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x38a, 8, 0),
};

static const u16 sYakuzaPartOam_3b7088_Frame3[OAM_DATA_SIZE(24)] = {
    24,
    OAM_ENTRY(-40, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-37, -1, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-21, 23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(20, -13, OAM_DIMS_16x32, OAM_X_FLIP, 0x385, 8, 0),
    OAM_ENTRY(12, 11, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e7, 8, 0),
    OAM_ENTRY(17, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x320, 8, 0),
    OAM_ENTRY(32, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(32, -19, OAM_DIMS_16x32, OAM_X_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(17, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x344, 8, 0),
    OAM_ENTRY(25, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x324, 8, 0),
    OAM_ENTRY(31, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x38b, 8, 0),
    OAM_ENTRY(23, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x38d, 8, 0),
    OAM_ENTRY(14, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(22, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
};

static const u16 sYakuzaPartOam_3b7230_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2c6, 8, 0),
};

static const u16 sYakuzaPartOam_3b7240_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x392, 8, 0),
};

static const u16 sYakuzaPartOam_3b7240_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x39e, 8, 0),
};

static const u16 sYakuzaPartOam_3b7198_Frame1[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(43, -13, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -21, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x263, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x265, 8, 0),
    OAM_ENTRY(38, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x388, 8, 0),
    OAM_ENTRY(30, -35, OAM_DIMS_8x16, OAM_X_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(18, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x266, 8, 0),
};

static const u16 sYakuzaPartOam_3b7198_Frame2[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(29, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(21, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x223, 8, 0),
    OAM_ENTRY(13, -20, OAM_DIMS_8x16, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(15, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(23, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(41, -18, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(33, -26, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(33, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(34, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x388, 8, 0),
    OAM_ENTRY(26, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x38a, 8, 0),
};

static const u16 sYakuzaPartOam_3b7198_Frame3[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(32, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(32, -19, OAM_DIMS_16x32, OAM_X_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(17, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x344, 8, 0),
    OAM_ENTRY(25, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x324, 8, 0),
    OAM_ENTRY(31, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x38b, 8, 0),
    OAM_ENTRY(23, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x38d, 8, 0),
    OAM_ENTRY(14, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(22, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
};

static const u16 sYakuzaPartOam_3b71c0_Frame0[OAM_DATA_SIZE(24)] = {
    24,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-56, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-40, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-34, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-42, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
    OAM_ENTRY(29, -24, OAM_DIMS_8x32, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(29, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(17, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x344, 8, 0),
    OAM_ENTRY(25, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x324, 8, 0),
    OAM_ENTRY(25, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x3cb, 8, 0),
    OAM_ENTRY(13, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(21, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
};

static const u16 sYakuzaPartOam_3b71c0_Frame1[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -13, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x263, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x265, 8, 0),
    OAM_ENTRY(-54, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-38, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(-34, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x266, 8, 0),
    OAM_ENTRY(30, -16, OAM_DIMS_8x32, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(30, 16, OAM_DIMS_8x8, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(23, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(25, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x3cd, 8, 0),
    OAM_ENTRY(19, -30, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(13, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
};

static const u16 sYakuzaPartOam_3b71c0_Frame2[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-37, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-37, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x223, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-31, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-31, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-49, -18, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-41, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-41, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-50, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-34, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(30, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(24, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(26, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x326, 8, 0),
    OAM_ENTRY(34, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x366, 8, 0),
    OAM_ENTRY(14, -25, OAM_DIMS_8x8, OAM_X_FLIP, 0x227, 8, 0),
    OAM_ENTRY(14, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(22, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x226, 8, 0),
};

static const u16 sYakuzaPartOam_3b71c0_Frame3[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-40, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-48, -19, OAM_DIMS_16x32, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-33, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 8, 0),
    OAM_ENTRY(-33, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x324, 8, 0),
    OAM_ENTRY(-47, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x38b, 8, 0),
    OAM_ENTRY(-31, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38d, 8, 0),
    OAM_ENTRY(-30, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-30, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(42, -1, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(34, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(34, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(33, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x326, 8, 0),
    OAM_ENTRY(41, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x366, 8, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e7, 8, 0),
    OAM_ENTRY(34, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e6, 8, 0),
};

static const u16 sYakuzaPartOam_3b71c0_Frame4[OAM_DATA_SIZE(24)] = {
    24,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-37, -24, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-37, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-33, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x344, 8, 0),
    OAM_ENTRY(-33, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x324, 8, 0),
    OAM_ENTRY(-41, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3cb, 8, 0),
    OAM_ENTRY(-29, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-29, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(43, -7, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, 1, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(40, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(32, -28, OAM_DIMS_8x16, OAM_X_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(18, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(34, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaPartOam_3b71c0_Frame5[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-38, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-38, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-39, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-41, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3cd, 8, 0),
    OAM_ENTRY(-27, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-29, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(43, -13, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(35, -21, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(35, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x263, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x265, 8, 0),
    OAM_ENTRY(38, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x388, 8, 0),
    OAM_ENTRY(30, -35, OAM_DIMS_8x16, OAM_X_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(18, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x266, 8, 0),
};

static const u16 sYakuzaPartOam_3b71c0_Frame6[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-38, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-46, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-40, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-42, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x326, 8, 0),
    OAM_ENTRY(-42, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x366, 8, 0),
    OAM_ENTRY(-22, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0),
    OAM_ENTRY(-22, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-30, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(29, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0),
    OAM_ENTRY(21, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x223, 8, 0),
    OAM_ENTRY(13, -20, OAM_DIMS_8x16, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(15, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(23, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(41, -18, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(33, -26, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(33, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(34, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x388, 8, 0),
    OAM_ENTRY(26, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x38a, 8, 0),
};

static const u16 sYakuzaPartOam_3b71c0_Frame7[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-50, -1, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-42, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-42, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-49, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x326, 8, 0),
    OAM_ENTRY(-49, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x366, 8, 0),
    OAM_ENTRY(-34, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e7, 8, 0),
    OAM_ENTRY(-42, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2e6, 8, 0),
    OAM_ENTRY(32, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(32, -19, OAM_DIMS_16x32, OAM_X_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(17, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x344, 8, 0),
    OAM_ENTRY(25, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x324, 8, 0),
    OAM_ENTRY(31, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x38b, 8, 0),
    OAM_ENTRY(23, -38, OAM_DIMS_8x16, OAM_X_FLIP, 0x38d, 8, 0),
    OAM_ENTRY(14, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(22, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
};

static const u16 sYakuzaPartOam_3b7208_Frame0[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-51, -13, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-43, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-43, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x263, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x265, 8, 0),
    OAM_ENTRY(-54, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-38, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(-34, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x266, 8, 0),
    OAM_ENTRY(29, -24, OAM_DIMS_8x32, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(29, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(17, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x344, 8, 0),
    OAM_ENTRY(25, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x324, 8, 0),
    OAM_ENTRY(25, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x3cb, 8, 0),
    OAM_ENTRY(13, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(21, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
};

static const u16 sYakuzaPartOam_3b7208_Frame1[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-37, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(-37, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x223, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-49, -18, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-41, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-41, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-31, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-31, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-49, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-33, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(30, -16, OAM_DIMS_8x32, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(30, 16, OAM_DIMS_8x8, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(23, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(25, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x3cd, 8, 0),
    OAM_ENTRY(19, -30, OAM_DIMS_8x8, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(13, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x226, 8, 0),
};

static const u16 sYakuzaPartOam_3b7208_Frame2[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-41, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-25, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
    OAM_ENTRY(-49, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-41, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-41, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-31, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-31, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-50, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-34, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(30, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(24, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(26, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x326, 8, 0),
    OAM_ENTRY(34, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x366, 8, 0),
    OAM_ENTRY(14, -25, OAM_DIMS_8x8, OAM_X_FLIP, 0x227, 8, 0),
    OAM_ENTRY(14, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(22, -24, OAM_DIMS_8x16, OAM_X_FLIP, 0x226, 8, 0),
};

static const u16 sYakuzaPartOam_3b7208_Frame3[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-32, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x322, 8, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x362, 8, 0),
    OAM_ENTRY(-28, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x322, 8, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_X_FLIP, 0x362, 8, 0),
    OAM_ENTRY(12, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(4, 29, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
    OAM_ENTRY(-50, -1, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-42, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-42, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-40, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(-54, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x388, 8, 0),
    OAM_ENTRY(-38, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 0x38a, 8, 0),
    OAM_ENTRY(-34, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x266, 8, 0),
    OAM_ENTRY(42, -1, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(34, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(34, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(24, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e3, 8, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x2e5, 8, 0),
    OAM_ENTRY(33, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x326, 8, 0),
    OAM_ENTRY(41, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x366, 8, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x2e7, 8, 0),
    OAM_ENTRY(34, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x2e6, 8, 0),
};

static const u16 sYakuzaPartOam_3b7320_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-22, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-6, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-19, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-3, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3e2, 8, 0),
};

static const u16 sYakuzaPartOam_3b7330_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-33, 2, OAM_DIMS_8x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-25, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-25, 10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x249, 8, 0),
    OAM_ENTRY(-22, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-6, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2a5, 8, 0),
};

static const u16 sYakuzaPartOam_3b7340_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-37, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(-21, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-15, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(-23, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaPartOam_3b7350_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(6, -5, OAM_DIMS_16x16, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-2, -5, OAM_DIMS_8x16, OAM_X_FLIP, 0x282, 8, 0),
    OAM_ENTRY(3, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x380, 8, 0),
    OAM_ENTRY(-5, 24, OAM_DIMS_8x8, OAM_X_FLIP, 0x3e2, 8, 0),
};

static const u16 sYakuzaPartOam_3b7360_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(25, 2, OAM_DIMS_8x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(17, -6, OAM_DIMS_8x16, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(17, 10, OAM_DIMS_8x8, OAM_X_FLIP, 0x249, 8, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a3, 8, 0),
    OAM_ENTRY(-2, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x2a5, 8, 0),
};

static const u16 sYakuzaPartOam_3b7370_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(21, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x3c8, 8, 0),
    OAM_ENTRY(13, -11, OAM_DIMS_8x16, OAM_X_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-1, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x2a7, 8, 0),
    OAM_ENTRY(15, -9, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a6, 8, 0),
};

static const u16 sYakuzaProjectileFireOam_Burning1_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20d, 12, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20f, 12, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28d, 12, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 12, 0),
};

static const u16 sYakuzaProjectileFireOam_Burning1_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x210, 12, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x212, 12, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x290, 12, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x292, 12, 0),
};

static const u16 sYakuzaProjectileFireOam_Burning1_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x213, 12, 0),
    OAM_ENTRY(4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x215, 12, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x293, 12, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x295, 12, 0),
};

static const u16 sYakuzaProjectileFireOam_Burning2_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x216, 12, 0),
};

static const u16 sYakuzaProjectileFireOam_Burning2_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x296, 12, 0),
};

static const u16 sYakuzaProjectileFireOam_Burning2_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x316, 12, 0),
};

static const u16 sYakuzaProjectileFireOam_Burning3_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x328, 12, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x368, 12, 0),
};

static const u16 sYakuzaProjectileFireOam_Burning3_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x32a, 12, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x36a, 12, 0),
};

static const u16 sYakuzaProjectileFireOam_Burning3_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x32c, 12, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x36c, 12, 0),
};

static const u16 sYakuzaProjectileSpitOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2a9, 8, 0),
};

static const u16 sYakuzaProjectileSpitOam_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ac, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2cb, 8, 0),
};

static const u16 sYakuzaProjectileSpitOam_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ae, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
};

static const u16 sYakuzaProjectileSpitOam_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2b1, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d3, 8, 0),
};

static const u16 sYakuzaProjectileSpitOam_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2b4, 8, 0),
};

static const u16 sYakuzaProjectileSpitOam_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x30f, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x34e, 8, 0),
};

const struct FrameData sYakuzaPartOam_3b6f08[5] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b6f30[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b6f40[3] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6f40_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b6f40_Frame1,
        .timer = 6
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b6f58[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6f58_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b6f68[5] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6f58_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b6f68_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b6f68_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b6f68_Frame1,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b6f90[3] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6f40_Frame1,
        .timer = 6
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b6f40_Frame0,
        .timer = 6
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b6fa8[3] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6f58_Frame0,
        .timer = 20
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b6fa8_Frame1,
        .timer = 14
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b6fc0[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6fc0_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b6fd0[3] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6fc0_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b6fd0_Frame1,
        .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b6fe8[5] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6fe8_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b6fe8_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b6fe8_Frame0,
        .timer = 3
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b6fd0_Frame1,
        .timer = 12
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7010[3] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6fa8_Frame1,
        .timer = 4
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b6f58_Frame0,
        .timer = 6
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7028[7] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b6f40_Frame0,
        .timer = 2
    },
    [4] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame2,
        .timer = 2
    },
    [5] = {
        .pFrame = sYakuzaPartOam_3b6f08_Frame1,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7060[5] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7060_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b7060_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b7060_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b7060_Frame1,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7088[5] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7060_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b7088_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b7088_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b7088_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b70b0[9] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b70b0_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b70b0_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b70b0_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b70b0_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sYakuzaPartOam_3b70b0_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sYakuzaPartOam_3b70b0_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sYakuzaPartOam_3b70b0_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sYakuzaPartOam_3b70b0_Frame7,
        .timer = 2
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b70f8[5] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b70f8_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b70f8_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b70f8_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b70f8_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7120[4] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7120_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b7120_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b7120_Frame2,
        .timer = 255
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7140[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7120_Frame0,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7150[7] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7150_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b7150_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b7150_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b7150_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sYakuzaPartOam_3b7150_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sYakuzaPartOam_3b7150_Frame5,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7188[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7120_Frame2,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7198[5] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7120_Frame2,
        .timer = 2
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b7198_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b7198_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b7198_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b71c0[9] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b71c0_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b71c0_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b71c0_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b71c0_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sYakuzaPartOam_3b71c0_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sYakuzaPartOam_3b71c0_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sYakuzaPartOam_3b71c0_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sYakuzaPartOam_3b71c0_Frame7,
        .timer = 2
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7208[5] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7208_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b7208_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b7208_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b7208_Frame3,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7230[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7230_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7240[4] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7240_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b7240_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b7240_Frame0,
        .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7260[5] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7240_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sYakuzaPartOam_3b7240_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sYakuzaPartOam_3b7240_Frame0,
        .timer = 2
    },
    [3] = {
        .pFrame = sYakuzaPartOam_3b7230_Frame0,
        .timer = 2
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaProjectileSpitOam[7] = {
    [0] = {
        .pFrame = sYakuzaProjectileSpitOam_Frame0,
        .timer = 6
    },
    [1] = {
        .pFrame = sYakuzaProjectileSpitOam_Frame1,
        .timer = 6
    },
    [2] = {
        .pFrame = sYakuzaProjectileSpitOam_Frame2,
        .timer = 6
    },
    [3] = {
        .pFrame = sYakuzaProjectileSpitOam_Frame3,
        .timer = 6
    },
    [4] = {
        .pFrame = sYakuzaProjectileSpitOam_Frame4,
        .timer = 6
    },
    [5] = {
        .pFrame = sYakuzaProjectileSpitOam_Frame5,
        .timer = 6
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaProjectileFireOam_Burning1[4] = {
    [0] = {
        .pFrame = sYakuzaProjectileFireOam_Burning1_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sYakuzaProjectileFireOam_Burning1_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sYakuzaProjectileFireOam_Burning1_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaProjectileFireOam_Burning2[4] = {
    [0] = {
        .pFrame = sYakuzaProjectileFireOam_Burning2_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sYakuzaProjectileFireOam_Burning2_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sYakuzaProjectileFireOam_Burning2_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaProjectileFireOam_Burning3[4] = {
    [0] = {
        .pFrame = sYakuzaProjectileFireOam_Burning3_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sYakuzaProjectileFireOam_Burning3_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sYakuzaProjectileFireOam_Burning3_Frame2,
        .timer = 3
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7320[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7320_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7330[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7330_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7340[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7340_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7350[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7350_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7360[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7360_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sYakuzaPartOam_3b7370[2] = {
    [0] = {
        .pFrame = sYakuzaPartOam_3b7370_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};
