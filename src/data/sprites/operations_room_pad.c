#include "data/sprites/operations_room_pad.h"

const u32 sOperationsRoomPadGfx[2 * 512] = INCBIN_U32("data/sprites/operations_room_pad.gfx");
const u16 sOperationsRoomPadPal[2 * 16] = INCBIN_U16("data/sprites/operations_room_pad.pal");

static const u16 sOperationsRoomPadOam_34c244_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-40, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_32x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_16x8, OAM_X_FLIP, 0x26a, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c2f4_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
};

static const u16 sOperationsRoomPadOam_34c254_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 9, 0),
    OAM_ENTRY(-23, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-18, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(2, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
};

static const u16 sOperationsRoomPadOam_34c254_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23a, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x23a, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x23c, 9, 0),
    OAM_ENTRY(-23, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-18, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(2, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(15, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
};

static const u16 sOperationsRoomPadOam_34c254_Frame2[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x21f, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(-24, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
};

static const u16 sOperationsRoomPadOam_34c254_Frame3[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x21f, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x21d, 9, 0),
    OAM_ENTRY(-25, 9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-19, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(17, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 9, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_X_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 9, 0),
};

static const u16 sOperationsRoomPadOam_34c27c_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23d, 8, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x23d, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c27c_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x23e, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c27c_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x23f, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c2a4_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x259, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c2a4_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x25a, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c2a4_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x25b, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c304_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c304_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-32, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c31c_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c31c_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-4, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c31c_Frame2[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

static const u16 sOperationsRoomPadOam_34c31c_Frame3[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-32, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x277, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-32, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
};

const struct FrameData sOperationsRoomPadOam_34c244[2] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c244_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOperationsRoomPadOam_34c254[5] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c254_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sOperationsRoomPadOam_34c254_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sOperationsRoomPadOam_34c254_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sOperationsRoomPadOam_34c254_Frame3,
        .timer = 4
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOperationsRoomPadOam_34c27c[5] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c27c_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sOperationsRoomPadOam_34c27c_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sOperationsRoomPadOam_34c27c_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sOperationsRoomPadOam_34c27c_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOperationsRoomPadOam_34c2a4[5] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c2a4_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sOperationsRoomPadOam_34c2a4_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sOperationsRoomPadOam_34c2a4_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sOperationsRoomPadOam_34c2a4_Frame1,
        .timer = 16
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOperationsRoomPadOam_34c2cc[5] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c254_Frame3,
        .timer = 6
    },
    [1] = {
        .pFrame = sOperationsRoomPadOam_34c254_Frame2,
        .timer = 6
    },
    [2] = {
        .pFrame = sOperationsRoomPadOam_34c254_Frame1,
        .timer = 6
    },
    [3] = {
        .pFrame = sOperationsRoomPadOam_34c254_Frame0,
        .timer = 6
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOperationsRoomPadOam_34c2f4[2] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c2f4_Frame0,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOperationsRoomPadOam_34c304[3] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c304_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sOperationsRoomPadOam_34c304_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOperationsRoomPadOam_34c31c[5] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c31c_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sOperationsRoomPadOam_34c31c_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sOperationsRoomPadOam_34c31c_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sOperationsRoomPadOam_34c31c_Frame3,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOperationsRoomPadOam_34c344[2] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c254_Frame3,
        .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOperationsRoomPadOam_34c354[5] = {
    [0] = {
        .pFrame = sOperationsRoomPadOam_34c31c_Frame3,
        .timer = 3
    },
    [1] = {
        .pFrame = sOperationsRoomPadOam_34c31c_Frame2,
        .timer = 3
    },
    [2] = {
        .pFrame = sOperationsRoomPadOam_34c31c_Frame1,
        .timer = 3
    },
    [3] = {
        .pFrame = sOperationsRoomPadOam_34c31c_Frame0,
        .timer = 3
    },
    [4] = FRAME_DATA_TERMINATOR
};
