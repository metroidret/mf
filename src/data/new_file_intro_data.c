#include "macros.h"
#include "oam.h"

#include "gba/memory.h"

#include "constants/text.h"

#include "data/new_file_intro_data.h"

static const u16 sOamFrame_597708[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 128, 4, 0),
};

static const u16 sOamFrame_597710[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 129, 4, 0),
};

static const u16 sOamFrame_597718[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 130, 4, 0),
};

static const u16 sOamFrame_597720[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 131, 4, 0),
};

static const u16 sOamFrame_597728[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0, 8, 0),
};

static const u16 sOamFrame_597730[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 4, 8, 0),
};

static const u16 sOamFrame_597738[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 8, 8, 0),
};

static const u16 sOamFrame_597740[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 12, 8, 0),
};

static const u16 sOamFrame_597748[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 24, 8, 0),
};

static const u16 sOamFrame_597750[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 140, 3, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 132, 1, 0),
};

static const u16 sOamFrame_59775e[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 132, 1, 0),
};

static const u16 sOamFrame_597766[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 3, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 132, 1, 0),
};

static const u16 sOamFrame_597774[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-20, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 140, 3, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 140, 3, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 16, 1, 0),
};

static const u16 sOamFrame_597788[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 16, 1, 0),
};

static const u16 sOamFrame_597790[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-20, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 3, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 3, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 16, 1, 0),
};

static const u16 sOamFrame_5977a4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_5977b2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-32, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-32, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
};

static const u16 sOamFrame_5977d8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(16, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
};

static const u16 sOamFrame_5977f2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-64, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
};

static const u16 sOamFrame_597800[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_597856[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_5978ac[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_597902[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_597958[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_5979ae[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_597a04[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_597a5a[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_597ab0[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_597b06[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_597b5c[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u16 sOamFrame_597bb2[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 746, 0, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 910, 0, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 974, 0, 0),
    OAM_ENTRY(-62, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 738, 0, 0),
    OAM_ENTRY(-30, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 0, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 872, 0, 0),
    OAM_ENTRY(-62, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 936, 0, 0),
    OAM_ENTRY(-46, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 0, 0),
    OAM_ENTRY(2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-67, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 832, 0, 0),
    OAM_ENTRY(-67, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 0, 0),
};

static const u8 sPadding_597c08[2] = {0, 0};

static const u16 sOamFrame_597c0a[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 332, 3, 0),
};

static const u16 sOamFrame_597c12[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 333, 3, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 333, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 333, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 333, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 332, 3, 0),
};

static const u16 sOamFrame_597c32[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 333, 3, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 333, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_X_FLIP, 333, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 333, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 256, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 256, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 256, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 256, 3, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 332, 3, 0),
};

static const u16 sOamFrame_597c6a[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(0, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 333, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 333, 3, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_8x8, OAM_X_FLIP, 333, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_XY_FLIP, 333, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 256, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 256, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 256, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 256, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 258, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 258, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 258, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 258, 3, 0),
};

static const u16 sOamFrame_597cb4[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-4, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 272, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 256, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 256, 3, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x16, OAM_X_FLIP, 256, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 256, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 258, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 258, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 258, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 258, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 260, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 260, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 260, 3, 0),
};

static const u16 sOamFrame_597d04[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-4, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 274, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 258, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 258, 3, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x16, OAM_X_FLIP, 258, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 258, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 260, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 260, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 260, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
};

static const u16 sOamFrame_597d5a[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 272, 3, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 276, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 260, 3, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x16, OAM_X_FLIP, 260, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 260, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
};

static const u16 sOamFrame_597da4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 3, 0),
    OAM_ENTRY(-16, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(0, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 274, 3, 0),
    OAM_ENTRY(-4, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 278, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 3, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x16, OAM_X_FLIP, 262, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 262, 3, 0),
};

static const u16 sOamFrame_597ddc[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 3, 0),
    OAM_ENTRY(-16, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 270, 3, 0),
    OAM_ENTRY(0, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 276, 3, 0),
};

static const u16 sOamFrame_597df6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 3, 0),
    OAM_ENTRY(0, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 270, 3, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 278, 3, 0),
};

static const u16 sOamFrame_597e0a[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 270, 3, 0),
};

static const u16 sOamFrame_597e12[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 140, 3, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 384, 1, 0),
};

static const u16 sOamFrame_597e20[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 384, 1, 0),
};

static const u16 sOamFrame_597e28[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 3, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 384, 1, 0),
};

static const u16 sOamFrame_597e36[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 140, 3, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 1, 0),
};

static const u16 sOamFrame_597e44[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 1, 0),
};

static const u16 sOamFrame_597e4c[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 142, 3, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 1, 0),
};

static const u16 sOamFrame_597e5a[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(14, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 2, 0),
    OAM_ENTRY(46, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 580, 2, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 132, 1, 0),
};

static const u16 sOamFrame_597e6e[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(14, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 517, 2, 0),
    OAM_ENTRY(46, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 585, 2, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 132, 1, 0),
};

static const u16 sOamFrame_597e82[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(13, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 2, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 132, 1, 0),
};

static const u16 sOamFrame_597e90[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-30, -27, OAM_DIMS_32x32, OAM_NO_FLIP, 526, 2, 0),
    OAM_ENTRY(-2, -27, OAM_DIMS_32x32, OAM_X_FLIP, 526, 2, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 16, 1, 0),
};

static const u16 sOamFrame_597ea4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 16, 1, 0),
};

static const u16 sOamFrame_597eac[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-30, -25, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 2, 0),
    OAM_ENTRY(-2, -25, OAM_DIMS_32x32, OAM_X_FLIP, 530, 2, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 16, 1, 0),
};

const struct FrameData sOam_597ec0[2] = {
    [0] = {
        .pFrame = sOamFrame_597708,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597ed0[2] = {
    [0] = {
        .pFrame = sOamFrame_597710,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597ee0[2] = {
    [0] = {
        .pFrame = sOamFrame_597718,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597ef0[2] = {
    [0] = {
        .pFrame = sOamFrame_597720,
        .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597f00[2] = {
    [0] = {
            .pFrame = sOamFrame_597728,
            .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597f10[2] = {
    [0] = {
            .pFrame = sOamFrame_597730,
            .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597f20[2] = {
    [0] = {
            .pFrame = sOamFrame_597738,
            .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597f30[2] = {
    [0] = {
            .pFrame = sOamFrame_597740,
            .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597f40[2] = {
    [0] = {
            .pFrame = sOamFrame_597748,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597f50[7] = {
    [0] = {
            .pFrame = sOamFrame_597e5a,
            .timer = 1
    },
    [1] = {
            .pFrame = sOamFrame_59775e,
            .timer = 1
    },
    [2] = {
            .pFrame = sOamFrame_597e6e,
            .timer = 1
    },
    [3] = {
            .pFrame = sOamFrame_597e5a,
            .timer = 1
    },
    [4] = {
            .pFrame = sOamFrame_59775e,
            .timer = 1
    },
    [5] = {
            .pFrame = sOamFrame_597e82,
            .timer = 1
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597f88[5] = {
    [0] = {
            .pFrame = sOamFrame_597e90,
            .timer = 1
    },
    [1] = {
            .pFrame = sOamFrame_597788,
            .timer = 1
    },
    [2] = {
            .pFrame = sOamFrame_597eac,
            .timer = 1
    },
    [3] = {
            .pFrame = sOamFrame_597788,
            .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597fb0[2] = {
    [0] = {
            .pFrame = sOamFrame_5977a4,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597fc0[2] = {
    [0] = {
            .pFrame = sOamFrame_5977b2,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597fd0[2] = {
    [0] = {
            .pFrame = sOamFrame_5977d8,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597fe0[2] = {
    [0] = {
            .pFrame = sOamFrame_5977f2,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_597ff0[2] = {
    [0] = {
            .pFrame = sOamFrame_597800,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_598000[12] = {
    [0] = {
            .pFrame = sOamFrame_597c0a,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_597c12,
            .timer = 4
    },
    [2] = {
            .pFrame = sOamFrame_597c32,
            .timer = 4
    },
    [3] = {
            .pFrame = sOamFrame_597c6a,
            .timer = 4
    },
    [4] = {
            .pFrame = sOamFrame_597cb4,
            .timer = 4
    },
    [5] = {
            .pFrame = sOamFrame_597d04,
            .timer = 4
    },
    [6] = {
            .pFrame = sOamFrame_597d5a,
            .timer = 6
    },
    [7] = {
            .pFrame = sOamFrame_597da4,
            .timer = 7
    },
    [8] = {
            .pFrame = sOamFrame_597ddc,
            .timer = 8
    },
    [9] = {
            .pFrame = sOamFrame_597df6,
            .timer = 9
    },
    [10] = {
            .pFrame = sOamFrame_597e0a,
            .timer = 10
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_598060[5] = {
    [0] = {
            .pFrame = sOamFrame_597e12,
            .timer = 1
    },
    [1] = {
            .pFrame = sOamFrame_597e20,
            .timer = 1
    },
    [2] = {
            .pFrame = sOamFrame_597e28,
            .timer = 1
    },
    [3] = {
            .pFrame = sOamFrame_597e20,
            .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_598088[5] = {
    [0] = {
            .pFrame = sOamFrame_597e36,
            .timer = 1
    },
    [1] = {
            .pFrame = sOamFrame_597e44,
            .timer = 1
    },
    [2] = {
            .pFrame = sOamFrame_597e4c,
            .timer = 1
    },
    [3] = {
            .pFrame = sOamFrame_597e44,
            .timer = 1
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u16 sIntroSamusShipPal[5 * PAL_ROW] = INCBIN_U16("data/new_file_intro/samus_ship.pal");
const u16 sPal_598150[2 * PAL_ROW] = INCBIN_U16("data/new_file_intro/598150.pal"); // Loaded to PALRAM but not used?

const u32 sIntroSamusHelmetCloseupTilemap[172] = INCBIN_U32("data/new_file_intro/samus_helmet_closeup.tm.lz");

static const u8 sBlob_598440_598818[] = INCBIN_U8("data/Blob_598440_598818.bin");

const u16 sIntroSamusHelmetCloseupPal[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/samus_helmet_closeup.pal");

const u32 sIntroSamusShipFlyingTextTilemap[125] = INCBIN_U32("data/new_file_intro/samus_ship_flying_text.tm.lz");

const u16 sPal_598a8c[1 * PAL_ROW] = INCBIN_U16("data/new_file_intro/598a8c.pal");
const u16 sIntroSamusCloseupGrayscalePal[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/samus_helmet_closeup_grayscale.pal");

const u16 sSr388SpaceAndSurfacePal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/sr388_space_and_surface.pal");

const u32 sIntroSr388SurfaceTilemap[551] = INCBIN_U32("data/new_file_intro/sr388_surface.tm.lz");
const u32 sIntroSr388SpaceBgTilemap[265] = INCBIN_U32("data/new_file_intro/sr388_space_bg.tm.lz");
const u32 sIntroSr388PlanetTilemap[199] = INCBIN_U32("data/new_file_intro/sr388_planet.tm.lz");

static const u16 sOamFrame_599d08[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0, 8, 0),
};

static const u16 sOamFrame_599d10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 8, 8, 0),
};

static const u16 sOamFrame_599d18[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 12, 8, 0),
};

static const u16 sOamFrame_599d20[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 136, 8, 0),
};

static const u16 sOamFrame_599d28[OAM_DATA_SIZE(52)] = {
    52,
    OAM_ENTRY_MODE(0, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 152, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, -48, OAM_DIMS_32x8, OAM_NO_FLIP, 216, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(64, -64, OAM_DIMS_32x32, OAM_NO_FLIP, 256, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(96, -64, OAM_DIMS_8x32, OAM_NO_FLIP, 287, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-64, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 260, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-32, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 264, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-64, -64, OAM_DIMS_64x32, OAM_NO_FLIP, 144, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(32, -64, OAM_DIMS_32x32, OAM_NO_FLIP, 156, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 248, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-16, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 266, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 268, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 332, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 334, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 335, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(32, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 272, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(40, -32, OAM_DIMS_64x32, OAM_NO_FLIP, 273, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(40, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 384, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-80, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 402, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-48, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 512, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-40, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 513, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-40, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 545, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-24, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 579, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-40, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 609, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-32, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 547, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(8, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 519, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(8, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 583, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, 16, OAM_DIMS_8x16, OAM_NO_FLIP, 582, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-8, 16, OAM_DIMS_8x16, OAM_NO_FLIP, 581, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 549, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 517, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(16, 32, OAM_DIMS_64x32, OAM_NO_FLIP, 394, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(80, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 620, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-88, 32, OAM_DIMS_16x32, OAM_NO_FLIP, 281, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-64, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 283, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, 32, OAM_DIMS_16x32, OAM_NO_FLIP, 392, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 502, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-16, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 440, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-32, 48, OAM_DIMS_16x8, OAM_NO_FLIP, 470, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-24, 32, OAM_DIMS_16x8, OAM_NO_FLIP, 407, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-8, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 409, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-32, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 406, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 439, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-32, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 438, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-80, 64, OAM_DIMS_16x16, OAM_NO_FLIP, 523, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-56, 88, OAM_DIMS_32x8, OAM_NO_FLIP, 442, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-72, 80, OAM_DIMS_32x8, OAM_NO_FLIP, 410, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-24, 80, OAM_DIMS_16x16, OAM_NO_FLIP, 414, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, 64, OAM_DIMS_16x16, OAM_NO_FLIP, 478, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-8, 72, OAM_DIMS_8x16, OAM_NO_FLIP, 587, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-64, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 588, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
};

static const u16 sOamFrame_599e62[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-128, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 736, 0, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 744, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 752, 0, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x64, OAM_NO_FLIP, 760, 0, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 764, 0, 0),
    OAM_ENTRY(96, 32, OAM_DIMS_16x32, OAM_NO_FLIP, 892, 0, 0),
    OAM_ENTRY(-128, 64, OAM_DIMS_32x8, OAM_NO_FLIP, 992, 0, 0),
    OAM_ENTRY(-96, 64, OAM_DIMS_32x8, OAM_NO_FLIP, 996, 0, 0),
    OAM_ENTRY(-64, 64, OAM_DIMS_32x8, OAM_NO_FLIP, 1000, 0, 0),
    OAM_ENTRY(-32, 64, OAM_DIMS_32x8, OAM_NO_FLIP, 1004, 0, 0),
    OAM_ENTRY(0, 64, OAM_DIMS_32x8, OAM_NO_FLIP, 1008, 0, 0),
    OAM_ENTRY(32, 64, OAM_DIMS_32x8, OAM_NO_FLIP, 1012, 0, 0),
    OAM_ENTRY(64, 64, OAM_DIMS_32x8, OAM_NO_FLIP, 1016, 0, 0),
    OAM_ENTRY(96, 64, OAM_DIMS_16x8, OAM_NO_FLIP, 1020, 0, 0),
    OAM_ENTRY(80, -64, OAM_DIMS_32x64, OAM_NO_FLIP, 506, 0, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 697, 0, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 704, 0, 0),
};

static const u16 sOamFrame_599eca[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(80, -64, OAM_DIMS_32x64, OAM_NO_FLIP, 506, 0, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 697, 0, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 704, 0, 0),
};

static const u16 sOamFrame_599ede[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(2, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 16, 1, 0),
};

static const u16 sOamFrame_599ee6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(3, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 18, 1, 0),
};

static const u16 sOamFrame_599eee[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(4, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 20, 1, 0),
};

static const u16 sOamFrame_599ef6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(2, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 124, 1, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 30, 1, 0),
};

static const u16 sOamFrame_599f04[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(10, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 30, 1, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 1, 0),
};

static const u16 sOamFrame_599f12[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(10, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 94, 1, 0),
    OAM_ENTRY(-6, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 60, 1, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 30, 1, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 1, 0),
};

static const u16 sOamFrame_599f2c[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 28, 0, 0),
    OAM_ENTRY(10, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 94, 1, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 30, 1, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 1, 0),
};

static const u16 sOamFrame_599f46[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-14, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 26, 0, 0),
    OAM_ENTRY(-6, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 28, 0, 0),
    OAM_ENTRY(10, 24, OAM_DIMS_8x16, OAM_NO_FLIP, 31, 0, 0),
    OAM_ENTRY(10, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 94, 1, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 30, 1, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 1, 0),
};

static const u16 sOamFrame_599f6c[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-22, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 24, 0, 0),
    OAM_ENTRY(-14, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 26, 0, 0),
    OAM_ENTRY(-6, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 28, 0, 0),
    OAM_ENTRY(10, 24, OAM_DIMS_8x32, OAM_NO_FLIP, 31, 0, 0),
    OAM_ENTRY(10, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 94, 1, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 30, 1, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 1, 0),
};

static const u16 sOamFrame_599f98[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-30, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 22, 0, 0),
    OAM_ENTRY(-22, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 24, 0, 0),
    OAM_ENTRY(-14, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 26, 0, 0),
    OAM_ENTRY(-6, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 28, 0, 0),
    OAM_ENTRY(10, 24, OAM_DIMS_8x32, OAM_NO_FLIP, 31, 0, 0),
    OAM_ENTRY(2, 48, OAM_DIMS_8x16, OAM_NO_FLIP, 87, 0, 0),
    OAM_ENTRY(10, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 94, 1, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 30, 1, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 1, 0),
};

static const u16 sOamFrame_599fd0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-30, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 22, 0, 0),
    OAM_ENTRY(-22, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 24, 0, 0),
    OAM_ENTRY(-14, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 26, 0, 0),
    OAM_ENTRY(-6, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 28, 0, 0),
    OAM_ENTRY(10, 24, OAM_DIMS_8x32, OAM_NO_FLIP, 31, 0, 0),
    OAM_ENTRY(2, 48, OAM_DIMS_8x16, OAM_NO_FLIP, 87, 0, 0),
    OAM_ENTRY(-14, 64, OAM_DIMS_16x16, OAM_NO_FLIP, 88, 0, 0),
    OAM_ENTRY(10, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 94, 1, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 30, 1, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 1, 0),
};

static const u16 sOamFrame_59a00e[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-30, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 22, 0, 0),
    OAM_ENTRY(-22, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 24, 0, 0),
    OAM_ENTRY(-14, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 26, 0, 0),
    OAM_ENTRY(-6, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 28, 0, 0),
    OAM_ENTRY(10, 24, OAM_DIMS_8x32, OAM_NO_FLIP, 31, 0, 0),
    OAM_ENTRY(2, 48, OAM_DIMS_8x16, OAM_NO_FLIP, 87, 0, 0),
    OAM_ENTRY(-14, 64, OAM_DIMS_16x16, OAM_NO_FLIP, 88, 0, 0),
    OAM_ENTRY(-30, 80, OAM_DIMS_16x16, OAM_NO_FLIP, 90, 0, 0),
    OAM_ENTRY(-14, 80, OAM_DIMS_8x8, OAM_NO_FLIP, 54, 0, 0),
    OAM_ENTRY(10, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 94, 1, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 30, 1, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 1, 0),
};

static const u16 sOamFrame_59a058[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-30, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 22, 0, 0),
    OAM_ENTRY(-22, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 24, 0, 0),
    OAM_ENTRY(-14, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 26, 0, 0),
    OAM_ENTRY(-6, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 28, 0, 0),
    OAM_ENTRY(10, 24, OAM_DIMS_8x32, OAM_NO_FLIP, 31, 0, 0),
    OAM_ENTRY(2, 48, OAM_DIMS_8x16, OAM_NO_FLIP, 87, 0, 0),
    OAM_ENTRY(-14, 64, OAM_DIMS_16x16, OAM_NO_FLIP, 88, 0, 0),
    OAM_ENTRY(-30, 80, OAM_DIMS_16x16, OAM_NO_FLIP, 90, 0, 0),
    OAM_ENTRY(-14, 80, OAM_DIMS_8x8, OAM_NO_FLIP, 54, 0, 0),
    OAM_ENTRY(10, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 94, 1, 0),
};

static const u16 sOamFrame_59a096[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 798, 6, 0),
};

const struct FrameData sOam_59a0a0[2] = {
    [0] = {
            .pFrame = sOamFrame_599d08,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_59a0b0[2] = {
    [0] = {
            .pFrame = sOamFrame_599d10,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_59a0c0[2] = {
    [0] = {
            .pFrame = sOamFrame_599d18,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_59a0d0[2] = {
    [0] = {
            .pFrame = sOamFrame_599d20,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_59a0e0[2] = {
    [0] = {
            .pFrame = sOamFrame_599d28,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_59a0f0[2] = {
    [0] = {
            .pFrame = sOamFrame_599e62,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_59a100[13] = {
    [0] = {
            .pFrame = sOamFrame_59a096,
            .timer = 80
    },
    [1] = {
            .pFrame = sOamFrame_599ef6,
            .timer = 1
    },
    [2] = {
            .pFrame = sOamFrame_599f04,
            .timer = 1
    },
    [3] = {
            .pFrame = sOamFrame_599f12,
            .timer = 1
    },
    [4] = {
            .pFrame = sOamFrame_599f2c,
            .timer = 1
    },
    [5] = {
            .pFrame = sOamFrame_599f46,
            .timer = 1
    },
    [6] = {
            .pFrame = sOamFrame_599f6c,
            .timer = 1
    },
    [7] = {
            .pFrame = sOamFrame_599f98,
            .timer = 1
    },
    [8] = {
            .pFrame = sOamFrame_599fd0,
            .timer = 1
    },
    [9] = {
            .pFrame = sOamFrame_59a00e,
            .timer = 212
    },
    [10] = {
            .pFrame = sOamFrame_59a00e,
            .timer = 220
    },
    [11] = {
            .pFrame = sOamFrame_59a00e,
            .timer = 200
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_59a168[2] = {
    [0] = {
            .pFrame = sOamFrame_599eca,
            .timer = 4
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_59a178[8] = {
    [0] = {
            .pFrame = sOamFrame_59a096,
            .timer = 116
    },
    [1] = {
            .pFrame = sOamFrame_599ede,
            .timer = 12
    },
    [2] = {
            .pFrame = sOamFrame_599ee6,
            .timer = 8
    },
    [3] = {
            .pFrame = sOamFrame_599eee,
            .timer = 4
    },
    [4] = {
            .pFrame = sOamFrame_599d28,
            .timer = 140
    },
    [5] = {
            .pFrame = sOamFrame_59a096,
            .timer = 240
    },
    [6] = {
            .pFrame = sOamFrame_59a096,
            .timer = 200
    },
    [7] = FRAME_DATA_TERMINATOR
};

const u32 sIntroSr388SpaceAndSurfaceObjGfx[3538] = INCBIN_U32("data/new_file_intro/sr388_space_and_surface_objects.gfx.lz");
const u16 sIntroSr388SpaceAndSurfaceObjPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/sr388_space_and_surface_objects.pal");

const u8 sArray_59db00[8] = {20, 30, 40, 50, 40, 30, 0, 0};

const u32 sIntroHornoadEncounterObjGfx[4252] = INCBIN_U32("data/new_file_intro/hornoad_encounter_obj.gfx.lz");
const u16 sIntroHornoadEncounterObjPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/hornoad_encounter_obj.pal");

static const u16 sOamFrame_5a1f78[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-11, -13, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -9, OAM_DIMS_16x8, OAM_X_FLIP, 579, 8, 0),
	OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
	OAM_ENTRY(-16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a1f98[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_Y_FLIP, 534, 8, 0),
	OAM_ENTRY(-12, -10, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-5, -19, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
	OAM_ENTRY(-5, -11, OAM_DIMS_16x8, OAM_X_FLIP, 618, 8, 0),
	OAM_ENTRY(-13, -19, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a1fb8[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 538, 8, 0),
	OAM_ENTRY(-5, -10, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(2, -19, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
	OAM_ENTRY(2, -11, OAM_DIMS_16x8, OAM_X_FLIP, 618, 8, 0),
	OAM_ENTRY(-6, -19, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a1fd8[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_X_FLIP, 540, 8, 0),
	OAM_ENTRY(-5, -10, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(2, -19, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
	OAM_ENTRY(2, -11, OAM_DIMS_16x8, OAM_X_FLIP, 618, 8, 0),
	OAM_ENTRY(-6, -19, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a1ff8[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_X_FLIP, 542, 8, 0),
	OAM_ENTRY(-16, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -19, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
	OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_X_FLIP, 618, 8, 0),
	OAM_ENTRY(-16, -19, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a2018[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-16, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -18, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
	OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 618, 8, 0),
	OAM_ENTRY(-16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a2038[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-16, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_X_FLIP, 512, 8, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 618, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a2058[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -15, OAM_DIMS_16x8, OAM_X_FLIP, 613, 9, 0),
	OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 528, 9, 0),
	OAM_ENTRY(-16, -20, OAM_DIMS_8x16, OAM_X_FLIP, 530, 9, 0),
};

static const u16 sOamFrame_5a2078[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -15, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_X_FLIP, 611, 9, 0),
	OAM_ENTRY(-16, -20, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a2098[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_X_FLIP, 525, 9, 0),
	OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_X_FLIP, 581, 9, 0),
	OAM_ENTRY(-16, -20, OAM_DIMS_8x16, OAM_X_FLIP, 527, 9, 0),
};

static const u16 sOamFrame_5a20b8[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -15, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 520, 9, 0),
	OAM_ENTRY(-16, -20, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a20d8[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 520, 9, 0),
	OAM_ENTRY(-16, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a20f8[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -13, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 552, 9, 0),
	OAM_ENTRY(-16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a2118[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-10, -16, OAM_DIMS_8x16, OAM_X_FLIP, 585, 9, 0),
	OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_X_FLIP, 590, 9, 0),
	OAM_ENTRY(-12, -24, OAM_DIMS_8x16, OAM_X_FLIP, 578, 9, 0),
	OAM_ENTRY(3, -16, OAM_DIMS_8x16, OAM_X_FLIP, 585, 9, 0),
};

static const u16 sOamFrame_5a2132[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 585, 9, 0),
	OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 590, 9, 0),
	OAM_ENTRY(4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 9, 0),
	OAM_ENTRY(-11, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 585, 9, 0),
};

static const u16 sOamFrame_5a214c[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(0, -19, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 520, 9, 0),
	OAM_ENTRY(-8, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a216c[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-11, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -9, OAM_DIMS_16x8, OAM_X_FLIP, 552, 9, 0),
	OAM_ENTRY(-16, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a218c[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-11, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 615, 9, 0),
	OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 611, 9, 0),
	OAM_ENTRY(-16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a21b2[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-11, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -9, OAM_DIMS_16x8, OAM_X_FLIP, 611, 9, 0),
	OAM_ENTRY(-16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a21d2[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_Y_FLIP, 534, 9, 0),
	OAM_ENTRY(-12, -10, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-5, -21, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-13, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
	OAM_ENTRY(-5, -14, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
};

static const u16 sOamFrame_5a21f2[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -7, OAM_DIMS_16x16, OAM_X_FLIP, 538, 9, 0),
	OAM_ENTRY(-5, -10, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(2, -21, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-6, -20, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
	OAM_ENTRY(2, -12, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
};

static const u16 sOamFrame_5a2212[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_X_FLIP, 540, 9, 0),
	OAM_ENTRY(-5, -10, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(2, -21, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-6, -20, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
	OAM_ENTRY(2, -12, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
};

static const u16 sOamFrame_5a2232[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_X_FLIP, 542, 9, 0),
	OAM_ENTRY(-16, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-16, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
	OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
};

static const u16 sOamFrame_5a2252[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-16, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_X_FLIP, 611, 9, 0),
	OAM_ENTRY(-16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a2272[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-16, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 611, 9, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a2292[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-11, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-7, -20, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-7, -15, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
	OAM_ENTRY(-15, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a22b2[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-11, -15, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-7, -22, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
	OAM_ENTRY(-15, -21, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a22d2[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-9, -13, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
	OAM_ENTRY(-16, -23, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a22f2[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-13, -16, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-10, -13, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
	OAM_ENTRY(-17, -23, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a2312[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-11, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 592, 9, 0),
	OAM_ENTRY(-16, -18, OAM_DIMS_8x16, OAM_X_FLIP, 514, 9, 0),
	OAM_ENTRY(-8, -18, OAM_DIMS_16x8, OAM_X_FLIP, 583, 9, 0),
};

static const u16 sOamFrame_5a2332[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-6, -23, OAM_DIMS_16x8, OAM_X_FLIP, 568, 9, 0),
	OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 9, 0),
	OAM_ENTRY(-6, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 9, 0),
	OAM_ENTRY(1, -20, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(0, -11, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
	OAM_ENTRY(-7, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a2358[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, -22, OAM_DIMS_16x8, OAM_X_FLIP, 568, 9, 0),
	OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_X_FLIP, 538, 9, 0),
	OAM_ENTRY(-7, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 9, 0),
	OAM_ENTRY(-1, -19, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-2, -12, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
	OAM_ENTRY(-9, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a237e[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-14, -23, OAM_DIMS_16x8, OAM_X_FLIP, 568, 9, 0),
	OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-10, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-7, -20, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
	OAM_ENTRY(-15, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a23a4[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-15, -22, OAM_DIMS_16x8, OAM_X_FLIP, 568, 9, 0),
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 515, 9, 0),
	OAM_ENTRY(-9, -12, OAM_DIMS_16x16, OAM_X_FLIP, 518, 9, 0),
	OAM_ENTRY(-16, -19, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sOamFrame_5a23ca[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -15, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_X_FLIP, 618, 9, 0),
	OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_X_FLIP, 512, 9, 0),
	OAM_ENTRY(-16, -20, OAM_DIMS_8x16, OAM_X_FLIP, 514, 9, 0),
};

static const u16 sOamFrame_5a23ea[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 528, 9, 0),
	OAM_ENTRY(-16, -20, OAM_DIMS_8x16, OAM_X_FLIP, 530, 9, 0),
};

static const u16 sOamFrame_5a2404[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -13, OAM_DIMS_16x8, OAM_X_FLIP, 618, 9, 0),
	OAM_ENTRY(-8, -21, OAM_DIMS_16x8, OAM_X_FLIP, 512, 9, 0),
	OAM_ENTRY(-16, -21, OAM_DIMS_8x16, OAM_X_FLIP, 514, 9, 0),
};

static const u16 sOamFrame_5a2424[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-14, -16, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-9, -11, OAM_DIMS_16x8, OAM_X_FLIP, 520, 9, 0),
	OAM_ENTRY(-9, -21, OAM_DIMS_16x16, OAM_X_FLIP, 512, 9, 0),
	OAM_ENTRY(-17, -21, OAM_DIMS_8x16, OAM_X_FLIP, 514, 9, 0),
};

static const u16 sOamFrame_5a2444[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-12, -16, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_X_FLIP, 611, 9, 0),
	OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 512, 9, 0),
	OAM_ENTRY(-16, -21, OAM_DIMS_8x16, OAM_X_FLIP, 514, 9, 0),
};

static const u16 sOamFrame_5a2464[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 9, 0),
	OAM_ENTRY(-11, -14, OAM_DIMS_8x8, OAM_X_FLIP, 536, 9, 0),
	OAM_ENTRY(-8, -19, OAM_DIMS_16x8, OAM_X_FLIP, 512, 9, 0),
	OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_X_FLIP, 579, 9, 0),
	OAM_ENTRY(-16, -19, OAM_DIMS_8x16, OAM_X_FLIP, 514, 9, 0),
};

static const u16 sOamFrame_5a2484[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-11, -11, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_X_FLIP, 588, 8, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 579, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a24a4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-11, -12, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_X_FLIP, 588, 8, 0),
	OAM_ENTRY(-8, -9, OAM_DIMS_16x8, OAM_X_FLIP, 579, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a24c4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-11, -13, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -18, OAM_DIMS_16x8, OAM_X_FLIP, 588, 8, 0),
	OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 592, 8, 0),
	OAM_ENTRY(-16, -17, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a24e4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-11, -12, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_X_FLIP, 588, 8, 0),
	OAM_ENTRY(-8, -9, OAM_DIMS_16x8, OAM_X_FLIP, 579, 8, 0),
	OAM_ENTRY(-16, -17, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a2504[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-11, -11, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 579, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
	OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_X_FLIP, 620, 8, 0),
};

static const u16 sOamFrame_5a2524[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-11, -12, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -9, OAM_DIMS_16x8, OAM_X_FLIP, 579, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
	OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_X_FLIP, 620, 8, 0),
};

static const u16 sOamFrame_5a2544[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-11, -13, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -18, OAM_DIMS_16x8, OAM_X_FLIP, 620, 8, 0),
	OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 592, 8, 0),
	OAM_ENTRY(-16, -17, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a2564[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_X_FLIP, 594, 8, 0),
	OAM_ENTRY(-11, -12, OAM_DIMS_8x8, OAM_X_FLIP, 536, 8, 0),
	OAM_ENTRY(-8, -17, OAM_DIMS_16x8, OAM_X_FLIP, 620, 8, 0),
	OAM_ENTRY(-8, -9, OAM_DIMS_16x8, OAM_X_FLIP, 579, 8, 0),
	OAM_ENTRY(-16, -17, OAM_DIMS_8x16, OAM_X_FLIP, 514, 8, 0),
};

static const u16 sOamFrame_5a2584[OAM_DATA_SIZE(9)] = {
	9,
	OAM_ENTRY(-19, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 3, 0),
	OAM_ENTRY(-3, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 962, 3, 0),
	OAM_ENTRY(-18, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 896, 3, 0),
	OAM_ENTRY(-10, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 865, 3, 0),
	OAM_ENTRY(6, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 867, 3, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 647, 3, 0),
	OAM_ENTRY(8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 649, 3, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 711, 3, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 713, 3, 0),
};

static const u16 sOamFrame_5a25bc[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-18, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 3, 0),
	OAM_ENTRY(-2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 962, 3, 0),
	OAM_ENTRY(-18, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 896, 3, 0),
	OAM_ENTRY(-10, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 865, 3, 0),
	OAM_ENTRY(6, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 867, 3, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 652, 3, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 716, 3, 0),
};

static const u16 sOamFrame_5a25e8[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-18, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 3, 0),
	OAM_ENTRY(-2, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 962, 3, 0),
	OAM_ENTRY(-18, -33, OAM_DIMS_32x16, OAM_NO_FLIP, 896, 3, 0),
	OAM_ENTRY(-10, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 865, 3, 0),
	OAM_ENTRY(6, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 867, 3, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 643, 3, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 3, 0),
};

static const u16 sOamFrame_5a2614[OAM_DATA_SIZE(9)] = {
	9,
	OAM_ENTRY(-19, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 3, 0),
	OAM_ENTRY(-3, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 962, 3, 0),
	OAM_ENTRY(-18, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 896, 3, 0),
	OAM_ENTRY(-10, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 865, 3, 0),
	OAM_ENTRY(6, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 867, 3, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 640, 3, 0),
	OAM_ENTRY(8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 642, 3, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 704, 3, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 706, 3, 0),
};

static const u16 sOamFrame_5a264c[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-18, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 3, 0),
	OAM_ENTRY(-2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 962, 3, 0),
	OAM_ENTRY(-18, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 896, 3, 0),
	OAM_ENTRY(-10, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 865, 3, 0),
	OAM_ENTRY(6, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 867, 3, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 645, 3, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 709, 3, 0),
};

static const u16 sOamFrame_5a2678[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-18, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 3, 0),
	OAM_ENTRY(-2, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 962, 3, 0),
	OAM_ENTRY(-18, -33, OAM_DIMS_32x16, OAM_NO_FLIP, 896, 3, 0),
	OAM_ENTRY(-10, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 865, 3, 0),
	OAM_ENTRY(6, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 867, 3, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 3, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 714, 3, 0),
};

static const u16 sOamFrame_5a26a4[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-12, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 868, 3, 0),
	OAM_ENTRY(4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 870, 3, 0),
	OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 996, 3, 0),
	OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 998, 3, 0),
};

static const u16 sOamFrame_5a26be[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-4, -40, OAM_DIMS_16x32, OAM_X_FLIP, 868, 3, 0),
	OAM_ENTRY(-12, -40, OAM_DIMS_8x32, OAM_X_FLIP, 870, 3, 0),
	OAM_ENTRY(-4, -8, OAM_DIMS_16x8, OAM_X_FLIP, 996, 3, 0),
	OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_X_FLIP, 998, 3, 0),
};

static const u16 sOamFrame_5a26d8[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-18, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 960, 3, 0),
	OAM_ENTRY(-2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 962, 3, 0),
	OAM_ENTRY(-18, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 896, 3, 0),
	OAM_ENTRY(-10, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 865, 3, 0),
	OAM_ENTRY(6, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 867, 3, 0),
	OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 686, 3, 0),
	OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 688, 3, 0),
};

static const u16 sOamFrame_5a2704[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(2, -24, OAM_DIMS_16x8, OAM_X_FLIP, 960, 3, 0),
	OAM_ENTRY(-6, -24, OAM_DIMS_8x8, OAM_X_FLIP, 962, 3, 0),
	OAM_ENTRY(-14, -32, OAM_DIMS_32x16, OAM_X_FLIP, 896, 3, 0),
	OAM_ENTRY(-6, -40, OAM_DIMS_16x8, OAM_X_FLIP, 865, 3, 0),
	OAM_ENTRY(-14, -40, OAM_DIMS_8x8, OAM_X_FLIP, 867, 3, 0),
	OAM_ENTRY(-4, -16, OAM_DIMS_16x16, OAM_X_FLIP, 686, 3, 0),
	OAM_ENTRY(-12, -16, OAM_DIMS_8x16, OAM_X_FLIP, 688, 3, 0),
};

static const u16 sOamFrame_5a2730[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 662, 3, 0),
	OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 3, 0),
};

static const u16 sOamFrame_5a273e[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 662, 3, 0),
	OAM_ENTRY(7, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 3, 0),
};

static const u16 sOamFrame_5a274c[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 694, 3, 0),
	OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 3, 0),
};

static const u16 sOamFrame_5a275a[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 694, 3, 0),
	OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 3, 0),
};

static const u16 sOamFrame_5a2768[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 728, 3, 0),
};

static const u16 sOamFrame_5a2770[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 729, 3, 0),
};

static const u16 sOamFrame_5a2778[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 730, 3, 0),
};

static const u16 sOamFrame_5a2780[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 731, 3, 0),
};

static const u16 sOamFrame_5a2788[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 732, 3, 0),
};

static const u16 sOamFrame_5a2790[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 696, 3, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 696, 3, 0),
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 696, 3, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 696, 3, 0),
};

static const u16 sOamFrame_5a27aa[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 665, 3, 0),
	OAM_ENTRY(0, -1, OAM_DIMS_16x16, OAM_XY_FLIP, 665, 3, 0),
	OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_X_FLIP, 665, 3, 0),
	OAM_ENTRY(-16, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 665, 3, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 696, 3, 0),
	OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_X_FLIP, 696, 3, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_XY_FLIP, 696, 3, 0),
	OAM_ENTRY(-24, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 696, 3, 0),
};

static const u16 sOamFrame_5a27dc[OAM_DATA_SIZE(12)] = {
	12,
	OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 667, 3, 0),
	OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_X_FLIP, 667, 3, 0),
	OAM_ENTRY(0, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 667, 3, 0),
	OAM_ENTRY(-16, -2, OAM_DIMS_16x16, OAM_Y_FLIP, 667, 3, 0),
	OAM_ENTRY(-32, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 665, 3, 0),
	OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_XY_FLIP, 665, 3, 0),
	OAM_ENTRY(-16, -33, OAM_DIMS_16x16, OAM_X_FLIP, 665, 3, 0),
	OAM_ENTRY(-32, -17, OAM_DIMS_16x16, OAM_Y_FLIP, 665, 3, 0),
	OAM_ENTRY(4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 696, 3, 0),
	OAM_ENTRY(12, -16, OAM_DIMS_8x8, OAM_X_FLIP, 696, 3, 0),
	OAM_ENTRY(12, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 696, 3, 0),
	OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 696, 3, 0),
};

static const u16 sOamFrame_5a2826[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 669, 3, 0),
	OAM_ENTRY(0, -19, OAM_DIMS_16x16, OAM_X_FLIP, 669, 3, 0),
	OAM_ENTRY(0, -3, OAM_DIMS_16x16, OAM_XY_FLIP, 669, 3, 0),
	OAM_ENTRY(-16, -3, OAM_DIMS_16x16, OAM_Y_FLIP, 669, 3, 0),
	OAM_ENTRY(-32, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 667, 3, 0),
	OAM_ENTRY(-16, -34, OAM_DIMS_16x16, OAM_X_FLIP, 667, 3, 0),
	OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_XY_FLIP, 667, 3, 0),
	OAM_ENTRY(-32, -18, OAM_DIMS_16x16, OAM_Y_FLIP, 667, 3, 0),
	OAM_ENTRY(-4, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 665, 3, 0),
	OAM_ENTRY(12, -9, OAM_DIMS_16x16, OAM_XY_FLIP, 665, 3, 0),
	OAM_ENTRY(12, -25, OAM_DIMS_16x16, OAM_X_FLIP, 665, 3, 0),
	OAM_ENTRY(-4, -9, OAM_DIMS_16x16, OAM_Y_FLIP, 665, 3, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 757, 3, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 757, 3, 0),
};

static const u16 sOamFrame_5a287c[OAM_DATA_SIZE(16)] = {
	16,
	OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 733, 3, 0),
	OAM_ENTRY(-16, -5, OAM_DIMS_16x16, OAM_Y_FLIP, 733, 3, 0),
	OAM_ENTRY(0, -5, OAM_DIMS_16x16, OAM_XY_FLIP, 733, 3, 0),
	OAM_ENTRY(0, -21, OAM_DIMS_16x16, OAM_X_FLIP, 733, 3, 0),
	OAM_ENTRY(-32, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 669, 3, 0),
	OAM_ENTRY(-16, -35, OAM_DIMS_16x16, OAM_X_FLIP, 669, 3, 0),
	OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_XY_FLIP, 669, 3, 0),
	OAM_ENTRY(-32, -19, OAM_DIMS_16x16, OAM_Y_FLIP, 669, 3, 0),
	OAM_ENTRY(-4, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 667, 3, 0),
	OAM_ENTRY(12, -26, OAM_DIMS_16x16, OAM_X_FLIP, 667, 3, 0),
	OAM_ENTRY(12, -10, OAM_DIMS_16x16, OAM_XY_FLIP, 667, 3, 0),
	OAM_ENTRY(-4, -10, OAM_DIMS_16x16, OAM_Y_FLIP, 667, 3, 0),
	OAM_ENTRY(-33, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 759, 3, 0),
	OAM_ENTRY(16, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 757, 3, 0),
	OAM_ENTRY(-26, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 759, 3, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 757, 3, 0),
};

static const u16 sOamFrame_5a28de[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(-32, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 733, 3, 0),
	OAM_ENTRY(-32, -20, OAM_DIMS_16x16, OAM_Y_FLIP, 733, 3, 0),
	OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_XY_FLIP, 733, 3, 0),
	OAM_ENTRY(-16, -36, OAM_DIMS_16x16, OAM_X_FLIP, 733, 3, 0),
	OAM_ENTRY(-4, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 669, 3, 0),
	OAM_ENTRY(12, -27, OAM_DIMS_16x16, OAM_X_FLIP, 669, 3, 0),
	OAM_ENTRY(12, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 669, 3, 0),
	OAM_ENTRY(-4, -11, OAM_DIMS_16x16, OAM_Y_FLIP, 669, 3, 0),
	OAM_ENTRY(-34, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 761, 3, 0),
	OAM_ENTRY(17, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 759, 3, 0),
	OAM_ENTRY(-40, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 3, 0),
	OAM_ENTRY(-28, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 761, 3, 0),
	OAM_ENTRY(-32, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 3, 0),
	OAM_ENTRY(10, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 759, 3, 0),
};

static const u16 sOamFrame_5a2934[OAM_DATA_SIZE(12)] = {
	12,
	OAM_ENTRY(-4, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 733, 3, 0),
	OAM_ENTRY(-4, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 733, 3, 0),
	OAM_ENTRY(12, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 733, 3, 0),
	OAM_ENTRY(12, -28, OAM_DIMS_16x16, OAM_X_FLIP, 733, 3, 0),
	OAM_ENTRY(-35, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 763, 3, 0),
	OAM_ENTRY(18, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 761, 3, 0),
	OAM_ENTRY(-41, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 3, 0),
	OAM_ENTRY(24, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 3, 0),
	OAM_ENTRY(-30, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 763, 3, 0),
	OAM_ENTRY(-34, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 3, 0),
	OAM_ENTRY(12, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 761, 3, 0),
	OAM_ENTRY(17, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 596, 3, 0),
};

static const u16 sOamFrame_5a297e[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(19, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 763, 3, 0),
	OAM_ENTRY(-42, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 600, 3, 0),
	OAM_ENTRY(25, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 3, 0),
	OAM_ENTRY(-36, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 600, 3, 0),
	OAM_ENTRY(14, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 763, 3, 0),
	OAM_ENTRY(20, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 3, 0),
};

static const u16 sOamFrame_5a29a4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(8, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 602, 3, 0),
	OAM_ENTRY(-43, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 602, 3, 0),
	OAM_ENTRY(26, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 600, 3, 0),
	OAM_ENTRY(-38, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 602, 3, 0),
	OAM_ENTRY(23, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 600, 3, 0),
};

static const u16 sOamFrame_5a29c4[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(27, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 602, 3, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 602, 3, 0),
};

static const u16 sOamFrame_5a29d2[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 800, 4, 0),
};

static const u16 sOamFrame_5a29da[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 802, 4, 0),
};

static const u16 sOamFrame_5a29e2[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 804, 4, 0),
};

static const u16 sOamFrame_5a29ea[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 806, 4, 0),
};

static const u16 sOamFrame_5a29f2[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 808, 4, 0),
};

static const u16 sOamFrame_5a29fa[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 810, 4, 0),
};

static const u16 sOamFrame_5a2a02[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 696, 3, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 696, 3, 0),
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 696, 3, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 696, 3, 0),
};

static const u16 sOamFrame_5a2a1c[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 665, 3, 0),
	OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 665, 3, 0),
	OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 665, 3, 0),
	OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 665, 3, 0),
};

static const u16 sOamFrame_5a2a36[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 667, 3, 0),
	OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 667, 3, 0),
	OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 667, 3, 0),
	OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 667, 3, 0),
};

static const u16 sOamFrame_5a2a50[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 669, 3, 0),
	OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 669, 3, 0),
	OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 669, 3, 0),
	OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 669, 3, 0),
};

static const u16 sOamFrame_5a2a6a[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 733, 3, 0),
	OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 733, 3, 0),
	OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 733, 3, 0),
	OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 733, 3, 0),
};

static const u16 sOamFrame_5a2a84[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-64, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 816, 14, 0),
	OAM_ENTRY(-64, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 944, 14, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 948, 14, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 952, 14, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(32, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(32, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(64, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(64, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(96, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(96, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 825, 14, 0),
};

static const u16 sOamFrame_5a2ac8[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(64, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(64, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(96, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(96, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(32, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 825, 14, 0),
	OAM_ENTRY(32, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 825, 14, 0),
};

const struct FrameData sOam_5a2af0[13] = {
	[0] = {
		.pFrame = sOamFrame_5a2484,
		.timer = 34
	},
	[1] = {
		.pFrame = sOamFrame_5a24a4,
		.timer = 22
	},
	[2] = {
		.pFrame = sOamFrame_5a24c4,
		.timer = 18
	},
	[3] = {
		.pFrame = sOamFrame_5a24e4,
		.timer = 16
	},
	[4] = {
		.pFrame = sOamFrame_5a2504,
		.timer = 34
	},
	[5] = {
		.pFrame = sOamFrame_5a2524,
		.timer = 22
	},
	[6] = {
		.pFrame = sOamFrame_5a2544,
		.timer = 18
	},
	[7] = {
		.pFrame = sOamFrame_5a2564,
		.timer = 16
	},
	[8] = {
		.pFrame = sOamFrame_5a2504,
		.timer = 34
	},
	[9] = {
		.pFrame = sOamFrame_5a2524,
		.timer = 22
	},
	[10] = {
		.pFrame = sOamFrame_5a2544,
		.timer = 18
	},
	[11] = {
		.pFrame = sOamFrame_5a2564,
		.timer = 16
	},
	[12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_IdleUnused[2] = {
	[0] = {
		.pFrame = sOamFrame_5a1f78,
		.timer = 10
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_JumpingUnused[5] = {
	[0] = {
		.pFrame = sOamFrame_5a1f98,
		.timer = 4
	},
	[1] = {
		.pFrame = sOamFrame_5a1fb8,
		.timer = 4
	},
	[2] = {
		.pFrame = sOamFrame_5a1fd8,
		.timer = 4
	},
	[3] = {
		.pFrame = sOamFrame_5a1ff8,
		.timer = 255
	},
	[4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_BouncingUnused[3] = {
	[0] = {
		.pFrame = sOamFrame_5a2018,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5a2038,
		.timer = 3
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_Shaking[5] = {
	[0] = {
		.pFrame = sOamFrame_5a2078,
		.timer = 6
	},
	[1] = {
		.pFrame = sOamFrame_5a2058,
		.timer = 8
	},
	[2] = {
		.pFrame = sOamFrame_5a2078,
		.timer = 6
	},
	[3] = {
		.pFrame = sOamFrame_5a2098,
		.timer = 8
	},
	[4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_Panting[5] = {
	[0] = {
		.pFrame = sOamFrame_5a20b8,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5a20d8,
		.timer = 8
	},
	[2] = {
		.pFrame = sOamFrame_5a20f8,
		.timer = 8
	},
	[3] = {
		.pFrame = sOamFrame_5a20d8,
		.timer = 8
	},
	[4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_Chomping[12] = {
	[0] = {
		.pFrame = sOamFrame_5a2272,
		.timer = 4
	},
	[1] = {
		.pFrame = sOamFrame_5a2292,
		.timer = 4
	},
	[2] = {
		.pFrame = sOamFrame_5a22b2,
		.timer = 4
	},
	[3] = {
		.pFrame = sOamFrame_5a22d2,
		.timer = 4
	},
	[4] = {
		.pFrame = sOamFrame_5a22f2,
		.timer = 4
	},
	[5] = {
		.pFrame = sOamFrame_5a2312,
		.timer = 4
	},
	[6] = {
		.pFrame = sOamFrame_5a2272,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5a2292,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5a22b2,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5a22d2,
		.timer = 2
	},
	[10] = {
		.pFrame = sOamFrame_5a22f2,
		.timer = 2
	},
	[11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a2c58[3] = {
	[0] = {
		.pFrame = sOamFrame_5a2118,
		.timer = 4
	},
	[1] = {
		.pFrame = sOamFrame_5a20d8,
		.timer = 4
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_Biting[5] = {
	[0] = {
		.pFrame = sOamFrame_5a216c,
		.timer = 10
	},
	[1] = {
		.pFrame = sOamFrame_5a218c,
		.timer = 10
	},
	[2] = {
		.pFrame = sOamFrame_5a216c,
		.timer = 10
	},
	[3] = {
		.pFrame = sOamFrame_5a21b2,
		.timer = 10
	},
	[4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_Jumping[5] = {
	[0] = {
		.pFrame = sOamFrame_5a21d2,
		.timer = 4
	},
	[1] = {
		.pFrame = sOamFrame_5a21f2,
		.timer = 4
	},
	[2] = {
		.pFrame = sOamFrame_5a2212,
		.timer = 4
	},
	[3] = {
		.pFrame = sOamFrame_5a2232,
		.timer = 255
	},
	[4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_Bouncing[3] = {
	[0] = {
		.pFrame = sOamFrame_5a2252,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5a2272,
		.timer = 3
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388HornoadOam_MidAir[3] = {
	[0] = {
		.pFrame = sOamFrame_5a2332,
		.timer = 4
	},
	[1] = {
		.pFrame = sOamFrame_5a2358,
		.timer = 255
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388BslResearcherOam_Walking[7] = {
	[0] = {
		.pFrame = sOamFrame_5a2584,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5a25bc,
		.timer = 8
	},
	[2] = {
		.pFrame = sOamFrame_5a25e8,
		.timer = 8
	},
	[3] = {
		.pFrame = sOamFrame_5a2614,
		.timer = 8
	},
	[4] = {
		.pFrame = sOamFrame_5a264c,
		.timer = 8
	},
	[5] = {
		.pFrame = sOamFrame_5a2678,
		.timer = 8
	},
	[6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a2d28[2] = {
	[0] = {
		.pFrame = sOamFrame_5a2704,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a2d38[3] = {
	[0] = {
		.pFrame = sOamFrame_5a26a4,
		.timer = 4
	},
	[1] = {
		.pFrame = sOamFrame_5a26be,
		.timer = 4
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388BslResearcherOam_Turning[3] = {
	[0] = {
		.pFrame = sOamFrame_5a26be,
		.timer = 4
	},
	[1] = {
		.pFrame = sOamFrame_5a26a4,
		.timer = 4
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388BslResearcherOam_Idle[2] = {
	[0] = {
		.pFrame = sOamFrame_5a26d8,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a2d78[2] = {
	[0] = {
		.pFrame = sOamFrame_5a2704,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a2d88[2] = {
	[0] = {
		.pFrame = sOamFrame_5a26d8,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a2d98[2] = {
	[0] = {
		.pFrame = sOamFrame_5a2704,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388MissileOam_Horizontal[3] = {
	[0] = {
		.pFrame = sOamFrame_5a2730,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5a273e,
		.timer = 2
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388MissileOam_Diagonal[3] = {
	[0] = {
		.pFrame = sOamFrame_5a274c,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5a275a,
		.timer = 2
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388MissileTrailOam[6] = {
	[0] = {
		.pFrame = sOamFrame_5a2768,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5a2770,
		.timer = 8
	},
	[2] = {
		.pFrame = sOamFrame_5a2778,
		.timer = 8
	},
	[3] = {
		.pFrame = sOamFrame_5a2780,
		.timer = 8
	},
	[4] = {
		.pFrame = sOamFrame_5a2788,
		.timer = 8
	},
	[5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388MissileExplosionOam_Small[6] = {
	[0] = {
		.pFrame = sOamFrame_5a2a02,
		.timer = 6
	},
	[1] = {
		.pFrame = sOamFrame_5a2a1c,
		.timer = 6
	},
	[2] = {
		.pFrame = sOamFrame_5a2a36,
		.timer = 6
	},
	[3] = {
		.pFrame = sOamFrame_5a2a50,
		.timer = 6
	},
	[4] = {
		.pFrame = sOamFrame_5a2a6a,
		.timer = 6
	},
	[5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388MissileExplosionOam_Big[11] = {
	[0] = {
		.pFrame = sOamFrame_5a2790,
		.timer = 4
	},
	[1] = {
		.pFrame = sOamFrame_5a27aa,
		.timer = 4
	},
	[2] = {
		.pFrame = sOamFrame_5a27dc,
		.timer = 4
	},
	[3] = {
		.pFrame = sOamFrame_5a2826,
		.timer = 6
	},
	[4] = {
		.pFrame = sOamFrame_5a287c,
		.timer = 6
	},
	[5] = {
		.pFrame = sOamFrame_5a28de,
		.timer = 6
	},
	[6] = {
		.pFrame = sOamFrame_5a2934,
		.timer = 6
	},
	[7] = {
		.pFrame = sOamFrame_5a297e,
		.timer = 6
	},
	[8] = {
		.pFrame = sOamFrame_5a29a4,
		.timer = 6
	},
	[9] = {
		.pFrame = sOamFrame_5a29c4,
		.timer = 6
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388XParasiteOam_Floating[7] = {
	[0] = {
		.pFrame = sOamFrame_5a29d2,
		.timer = 5
	},
	[1] = {
		.pFrame = sOamFrame_5a29da,
		.timer = 5
	},
	[2] = {
		.pFrame = sOamFrame_5a29e2,
		.timer = 5
	},
	[3] = {
		.pFrame = sOamFrame_5a29ea,
		.timer = 5
	},
	[4] = {
		.pFrame = sOamFrame_5a29f2,
		.timer = 5
	},
	[5] = {
		.pFrame = sOamFrame_5a29fa,
		.timer = 5
	},
	[6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388CaveEntranceBgOam[2] = {
	[0] = {
		.pFrame = sOamFrame_5a2a84,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388BlackRectangeOam[2] = {
	[0] = {
		.pFrame = sOamFrame_5a2ac8,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

static const u16 sOamFrame_5a2ee8[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-5, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5a2ef6[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-8, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 2, 0, 0),
	OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 68, 0, 0),
};

static const u16 sOamFrame_5a2f04[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-8, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 6, 0, 0),
	OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 8, 0, 0),
	OAM_ENTRY(-16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 37, 0, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 5, 0, 0),
};

static const u16 sOamFrame_5a2f1e[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-8, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 9, 0, 0),
	OAM_ENTRY(-12, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 72, 0, 0),
	OAM_ENTRY(8, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 11, 0, 0),
	OAM_ENTRY(-16, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 36, 0, 0),
};

static const u16 sOamFrame_5a2f38[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-7, -39, OAM_DIMS_16x32, OAM_NO_FLIP, 12, 0, 0),
	OAM_ENTRY(-10, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 75, 0, 0),
	OAM_ENTRY(9, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 107, 0, 0),
};

static const u16 sOamFrame_5a2f4c[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-4, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 14, 0, 0),
	OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 18, 0, 0),
	OAM_ENTRY(-5, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 64, 0, 0),
};

static const u16 sOamFrame_5a2f60[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-7, -37, OAM_DIMS_16x32, OAM_NO_FLIP, 16, 0, 0),
	OAM_ENTRY(6, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 82, 0, 0),
	OAM_ENTRY(9, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 50, 0, 0),
};

static const u16 sOamFrame_5a2f74[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-8, -39, OAM_DIMS_16x32, OAM_NO_FLIP, 20, 0, 0),
	OAM_ENTRY(8, -33, OAM_DIMS_8x32, OAM_NO_FLIP, 22, 0, 0),
	OAM_ENTRY(-16, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 19, 0, 0),
	OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 51, 0, 0),
};

static const u16 sOamFrame_5a2f8e[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-7, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 23, 0, 0),
	OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 121, 0, 0),
	OAM_ENTRY(9, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 57, 0, 0),
	OAM_ENTRY(-15, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 25, 0, 0),
};

static const u16 sOamFrame_5a2fa8[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-6, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 26, 0, 0),
	OAM_ENTRY(10, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 83, 0, 0),
	OAM_ENTRY(-14, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 28, 0, 0),
};

static const u16 sOamFrame_5a2fbc[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-4, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 61, 0, 0),
	OAM_ENTRY(-11, -40, OAM_DIMS_16x32, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5a2fd0[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(2, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 31, 0, 0),
	OAM_ENTRY(-8, -40, OAM_DIMS_16x32, OAM_X_FLIP, 2, 0, 0),
	OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_X_FLIP, 68, 0, 0),
};

static const u16 sOamFrame_5a2fe4[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 137, 0, 0),
	OAM_ENTRY(-8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 168, 0, 0),
	OAM_ENTRY(-8, -40, OAM_DIMS_16x32, OAM_X_FLIP, 6, 0, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_X_FLIP, 8, 0, 0),
	OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_X_FLIP, 37, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 5, 0, 0),
};

static const u16 sOamFrame_5a300a[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 30, 0, 0),
	OAM_ENTRY(6, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 31, 0, 0),
	OAM_ENTRY(-8, -40, OAM_DIMS_16x32, OAM_X_FLIP, 9, 0, 0),
	OAM_ENTRY(4, -18, OAM_DIMS_8x16, OAM_X_FLIP, 72, 0, 0),
	OAM_ENTRY(-16, -21, OAM_DIMS_8x16, OAM_X_FLIP, 11, 0, 0),
};

static const u16 sOamFrame_5a302a[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(1, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 60, 0, 0),
	OAM_ENTRY(-9, -39, OAM_DIMS_16x32, OAM_X_FLIP, 12, 0, 0),
	OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_X_FLIP, 75, 0, 0),
	OAM_ENTRY(-17, -21, OAM_DIMS_8x8, OAM_X_FLIP, 107, 0, 0),
};

static const u16 sOamFrame_5a3044[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-3, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 61, 0, 0),
	OAM_ENTRY(-12, -40, OAM_DIMS_16x32, OAM_X_FLIP, 14, 0, 0),
	OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 18, 0, 0),
};

static const u16 sOamFrame_5a3058[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-10, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 92, 0, 0),
	OAM_ENTRY(-9, -21, OAM_DIMS_16x16, OAM_X_FLIP, 80, 0, 0),
	OAM_ENTRY(-9, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 94, 0, 0),
	OAM_ENTRY(-14, -15, OAM_DIMS_8x16, OAM_X_FLIP, 82, 0, 0),
	OAM_ENTRY(-17, -29, OAM_DIMS_8x8, OAM_X_FLIP, 50, 0, 0),
};

static const u16 sOamFrame_5a3078[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-12, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 130, 0, 0),
	OAM_ENTRY(2, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-8, -39, OAM_DIMS_16x32, OAM_X_FLIP, 20, 0, 0),
	OAM_ENTRY(-16, -33, OAM_DIMS_8x32, OAM_X_FLIP, 22, 0, 0),
	OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_X_FLIP, 51, 0, 0),
};

static const u16 sOamFrame_5a3098[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(1, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-9, -40, OAM_DIMS_16x32, OAM_X_FLIP, 23, 0, 0),
	OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_X_FLIP, 121, 0, 0),
	OAM_ENTRY(-17, -16, OAM_DIMS_8x16, OAM_X_FLIP, 57, 0, 0),
	OAM_ENTRY(7, -32, OAM_DIMS_8x8, OAM_X_FLIP, 25, 0, 0),
};

static const u16 sOamFrame_5a30be[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-6, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 134, 0, 0),
	OAM_ENTRY(2, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 136, 0, 0),
	OAM_ENTRY(-10, -40, OAM_DIMS_16x32, OAM_X_FLIP, 26, 0, 0),
	OAM_ENTRY(-18, -24, OAM_DIMS_8x16, OAM_X_FLIP, 83, 0, 0),
	OAM_ENTRY(-2, -8, OAM_DIMS_16x8, OAM_X_FLIP, 28, 0, 0),
};

static const u16 sOamFrame_5a30de[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-11, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 146, 0, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_8x8, OAM_XY_FLIP, 170, 0, 0),
    OAM_ENTRY(-12, -26, OAM_DIMS_16x8, OAM_XY_FLIP, 138, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 192, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3110[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-11, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 148, 0, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 0, 0),
    OAM_ENTRY(-12, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 171, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 194, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3142[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-11, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
    OAM_ENTRY(-12, -26, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 196, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 232, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 233, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3174[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(-10, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 180, 0, 0),
	OAM_ENTRY(-11, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 174, 0, 0),
	OAM_ENTRY(-3, -33, OAM_DIMS_8x8, OAM_NO_FLIP, 143, 0, 0),
	OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 198, 0, 0),
	OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 234, 0, 0),
	OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 235, 0, 0),
	OAM_ENTRY(-18, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a31a6[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 200, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 201, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 192, 0, 0),
};

static const u16 sOamFrame_5a31d2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 154, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 157, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 194, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 202, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 203, 0, 0),
};

static const u16 sOamFrame_5a31fe[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 184, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 158, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 196, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 232, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 233, 0, 0),
};

static const u16 sOamFrame_5a322a[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(2, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-6, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 186, 0, 0),
	OAM_ENTRY(-4, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 159, 0, 0),
	OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 198, 0, 0),
	OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 234, 0, 0),
	OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 235, 0, 0),
};

static const u16 sOamFrame_5a3256[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-11, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 146, 0, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_8x8, OAM_XY_FLIP, 170, 0, 0),
    OAM_ENTRY(-12, -26, OAM_DIMS_16x8, OAM_XY_FLIP, 138, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 200, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 201, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 192, 0, 0),
    OAM_ENTRY(-23, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 63, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a328e[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-11, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 148, 0, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 0, 0),
    OAM_ENTRY(-12, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 171, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 194, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 202, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 203, 0, 0),
    OAM_ENTRY(-23, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 63, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a32c6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-11, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
    OAM_ENTRY(-12, -26, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 196, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 232, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 233, 0, 0),
    OAM_ENTRY(-23, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 63, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a32fe[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-10, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 180, 0, 0),
    OAM_ENTRY(-11, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 174, 0, 0),
    OAM_ENTRY(-3, -33, OAM_DIMS_8x8, OAM_NO_FLIP, 143, 0, 0),
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 198, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 234, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 235, 0, 0),
    OAM_ENTRY(-21, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 63, 0, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3336[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(15, -25, OAM_DIMS_8x8, OAM_X_FLIP, 63, 0, 0),
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 200, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 201, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 192, 0, 0),
};

static const u16 sOamFrame_5a3368[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(15, -25, OAM_DIMS_8x8, OAM_X_FLIP, 63, 0, 0),
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 154, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 157, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 194, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 202, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 203, 0, 0),
};

static const u16 sOamFrame_5a339a[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(15, -25, OAM_DIMS_8x8, OAM_X_FLIP, 63, 0, 0),
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_16x8, OAM_NO_FLIP, 184, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 158, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 196, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 232, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 233, 0, 0),
};

static const u16 sOamFrame_5a33cc[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(13, -25, OAM_DIMS_8x8, OAM_X_FLIP, 63, 0, 0),
    OAM_ENTRY(2, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-6, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 186, 0, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 159, 0, 0),
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 198, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 234, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 235, 0, 0),
};

static const u16 sOamFrame_5a33fe[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-3, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 256, 0, 0),
    OAM_ENTRY(-13, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 206, 0, 0),
    OAM_ENTRY(-11, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 204, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 260, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 268, 0, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 270, 0, 0),
    OAM_ENTRY(-20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 214, 0, 0),
};

static const u16 sOamFrame_5a342a[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-3, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 257, 0, 0),
    OAM_ENTRY(-13, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 0, 0),
    OAM_ENTRY(-11, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 204, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 271, 0, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 273, 0, 0),
    OAM_ENTRY(-20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 214, 0, 0),
};

static const u16 sOamFrame_5a3456[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-3, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 258, 0, 0),
    OAM_ENTRY(-13, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 210, 0, 0),
    OAM_ENTRY(-11, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 204, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 300, 0, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 302, 0, 0),
    OAM_ENTRY(-20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 214, 0, 0),
};

static const u16 sOamFrame_5a3482[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-2, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 259, 0, 0),
    OAM_ENTRY(-12, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 212, 0, 0),
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 274, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 303, 0, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 305, 0, 0),
    OAM_ENTRY(-19, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 214, 0, 0),
};

static const u16 sOamFrame_5a34ae[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-3, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 288, 0, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 218, 0, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 216, 0, 0),
    OAM_ENTRY(-5, -37, OAM_DIMS_16x16, OAM_X_FLIP, 204, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 260, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 268, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_X_FLIP, 270, 0, 0),
    OAM_ENTRY(-3, -36, OAM_DIMS_16x16, OAM_X_FLIP, 206, 0, 0),
};

static const u16 sOamFrame_5a34e0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-3, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 289, 0, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 250, 0, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 248, 0, 0),
    OAM_ENTRY(-5, -37, OAM_DIMS_16x16, OAM_X_FLIP, 204, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 262, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 271, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_X_FLIP, 273, 0, 0),
    OAM_ENTRY(-3, -36, OAM_DIMS_16x16, OAM_X_FLIP, 208, 0, 0),
};

static const u16 sOamFrame_5a3512[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-3, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 290, 0, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 251, 0, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 219, 0, 0),
    OAM_ENTRY(-5, -37, OAM_DIMS_16x16, OAM_X_FLIP, 204, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 264, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 300, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_X_FLIP, 302, 0, 0),
    OAM_ENTRY(-3, -36, OAM_DIMS_16x16, OAM_X_FLIP, 210, 0, 0),
};

static const u16 sOamFrame_5a3544[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 291, 0, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 221, 0, 0),
    OAM_ENTRY(14, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 252, 0, 0),
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_X_FLIP, 274, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 266, 0, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 303, 0, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_X_FLIP, 305, 0, 0),
    OAM_ENTRY(-4, -35, OAM_DIMS_16x16, OAM_X_FLIP, 212, 0, 0),
};

static const u16 sOamFrame_5a3576[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-3, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 256, 0, 0),
    OAM_ENTRY(-13, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 206, 0, 0),
    OAM_ENTRY(-11, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 204, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 260, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 268, 0, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 270, 0, 0),
    OAM_ENTRY(-21, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 223, 0, 0),
    OAM_ENTRY(-20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 214, 0, 0),
};

static const u16 sOamFrame_5a35a8[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-3, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 257, 0, 0),
    OAM_ENTRY(-13, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 0, 0),
    OAM_ENTRY(-11, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 204, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 271, 0, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 273, 0, 0),
    OAM_ENTRY(-21, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 223, 0, 0),
    OAM_ENTRY(-20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 214, 0, 0),
};

static const u16 sOamFrame_5a35da[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-3, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 258, 0, 0),
    OAM_ENTRY(-13, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 210, 0, 0),
    OAM_ENTRY(-11, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 204, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 264, 0, 0),
    OAM_ENTRY(-11, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 300, 0, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 302, 0, 0),
    OAM_ENTRY(-21, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 223, 0, 0),
    OAM_ENTRY(-20, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 214, 0, 0),
};

static const u16 sOamFrame_5a360c[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-2, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 259, 0, 0),
    OAM_ENTRY(-12, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 212, 0, 0),
    OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 274, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 303, 0, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 305, 0, 0),
    OAM_ENTRY(-20, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 223, 0, 0),
    OAM_ENTRY(-19, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 214, 0, 0),
};

static const u16 sOamFrame_5a363e[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-3, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 288, 0, 0),
    OAM_ENTRY(13, -40, OAM_DIMS_8x8, OAM_X_FLIP, 223, 0, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 218, 0, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 216, 0, 0),
    OAM_ENTRY(-5, -37, OAM_DIMS_16x16, OAM_X_FLIP, 204, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 260, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 268, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_X_FLIP, 270, 0, 0),
    OAM_ENTRY(-3, -36, OAM_DIMS_16x16, OAM_X_FLIP, 206, 0, 0),
};

static const u16 sOamFrame_5a3676[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-3, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 289, 0, 0),
    OAM_ENTRY(13, -40, OAM_DIMS_8x8, OAM_X_FLIP, 223, 0, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 250, 0, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 248, 0, 0),
    OAM_ENTRY(-5, -37, OAM_DIMS_16x16, OAM_X_FLIP, 204, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 262, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 271, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_X_FLIP, 273, 0, 0),
    OAM_ENTRY(-3, -36, OAM_DIMS_16x16, OAM_X_FLIP, 208, 0, 0),
};

static const u16 sOamFrame_5a36ae[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-3, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 290, 0, 0),
    OAM_ENTRY(13, -40, OAM_DIMS_8x8, OAM_X_FLIP, 223, 0, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 251, 0, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 219, 0, 0),
    OAM_ENTRY(-5, -37, OAM_DIMS_16x16, OAM_X_FLIP, 204, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 264, 0, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 300, 0, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_X_FLIP, 302, 0, 0),
    OAM_ENTRY(-3, -36, OAM_DIMS_16x16, OAM_X_FLIP, 210, 0, 0),
};

static const u16 sOamFrame_5a36e6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-4, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 291, 0, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 221, 0, 0),
    OAM_ENTRY(12, -39, OAM_DIMS_8x8, OAM_X_FLIP, 223, 0, 0),
    OAM_ENTRY(14, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 252, 0, 0),
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_X_FLIP, 274, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 266, 0, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 303, 0, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_X_FLIP, 305, 0, 0),
    OAM_ENTRY(-4, -35, OAM_DIMS_16x16, OAM_X_FLIP, 212, 0, 0),
};

static const u16 sOamFrame_5a371e[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 276, 0, 0),
    OAM_ENTRY(1, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 278, 0, 0),
    OAM_ENTRY(-7, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 285, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 320, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 322, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 354, 0, 0),
};

static const u16 sOamFrame_5a3744[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 279, 0, 0),
    OAM_ENTRY(4, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 281, 0, 0),
    OAM_ENTRY(-4, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 317, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 323, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 325, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 357, 0, 0),
};

static const u16 sOamFrame_5a376a[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 0, 0),
    OAM_ENTRY(6, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 0, 0),
    OAM_ENTRY(-10, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 124, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 320, 0, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 322, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 354, 0, 0),
};

static const u16 sOamFrame_5a3790[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-8, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 146, 0, 0),
	OAM_ENTRY(-1, -33, OAM_DIMS_8x8, OAM_XY_FLIP, 170, 0, 0),
	OAM_ENTRY(-8, -26, OAM_DIMS_16x8, OAM_XY_FLIP, 138, 0, 0),
	OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-17, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-5, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5a37bc[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-9, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 148, 0, 0),
	OAM_ENTRY(-3, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 0, 0),
	OAM_ENTRY(-10, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 171, 0, 0),
	OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-18, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 66, 0, 0),
	OAM_ENTRY(-1, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 68, 0, 0),
};

static const u16 sOamFrame_5a37e8[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(-10, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-4, -35, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-11, -28, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-19, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 70, 0, 0),
	OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 8, 0, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 5, 0, 0),
};

static const u16 sOamFrame_5a381a[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(-11, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-11, -28, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-10, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-19, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 73, 0, 0),
	OAM_ENTRY(-12, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 72, 0, 0),
	OAM_ENTRY(8, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 11, 0, 0),
};

static const u16 sOamFrame_5a384c[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(-10, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 148, 0, 0),
	OAM_ENTRY(-3, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 0, 0),
	OAM_ENTRY(-10, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 171, 0, 0),
	OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-19, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-7, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 76, 0, 0),
	OAM_ENTRY(-10, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 75, 0, 0),
	OAM_ENTRY(9, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 107, 0, 0),
};

static const u16 sOamFrame_5a387e[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-8, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 146, 0, 0),
	OAM_ENTRY(-1, -35, OAM_DIMS_8x8, OAM_XY_FLIP, 170, 0, 0),
	OAM_ENTRY(-9, -27, OAM_DIMS_16x8, OAM_XY_FLIP, 138, 0, 0),
	OAM_ENTRY(-7, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-17, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 326, 0, 0),
	OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 18, 0, 0),
};

static const u16 sOamFrame_5a38aa[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(-7, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 148, 0, 0),
	OAM_ENTRY(1, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 0, 0),
	OAM_ENTRY(-7, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 171, 0, 0),
	OAM_ENTRY(-6, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-16, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-7, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 328, 0, 0),
	OAM_ENTRY(6, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 82, 0, 0),
	OAM_ENTRY(2, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 0, 0),
};

static const u16 sOamFrame_5a38dc[OAM_DATA_SIZE(9)] = {
	9,
	OAM_ENTRY(-8, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-1, -36, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-8, -28, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-17, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 330, 0, 0),
	OAM_ENTRY(8, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 86, 0, 0),
	OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 51, 0, 0),
	OAM_ENTRY(2, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 51, 0, 0),
};

static const u16 sOamFrame_5a3914[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(-9, -38, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-2, -36, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-9, -28, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-18, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 332, 0, 0),
	OAM_ENTRY(9, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 57, 0, 0),
	OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 121, 0, 0),
};

static const u16 sOamFrame_5a3946[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(-9, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 148, 0, 0),
	OAM_ENTRY(-2, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 140, 0, 0),
	OAM_ENTRY(-9, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 171, 0, 0),
	OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-6, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 334, 0, 0),
	OAM_ENTRY(10, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 83, 0, 0),
	OAM_ENTRY(-14, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 28, 0, 0),
	OAM_ENTRY(-18, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3978[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(1, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-8, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
	OAM_ENTRY(-5, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
	OAM_ENTRY(-9, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-11, -24, OAM_DIMS_16x16, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5a399e[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(2, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-7, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 154, 0, 0),
	OAM_ENTRY(-4, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 157, 0, 0),
	OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 66, 0, 0),
	OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_X_FLIP, 68, 0, 0),
};

static const u16 sOamFrame_5a39c4[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(3, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-5, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 184, 0, 0),
	OAM_ENTRY(-3, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 158, 0, 0),
	OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 70, 0, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_X_FLIP, 8, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 5, 0, 0),
};

static const u16 sOamFrame_5a39f0[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(3, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-5, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 184, 0, 0),
	OAM_ENTRY(-3, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 158, 0, 0),
	OAM_ENTRY(-6, -39, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 73, 0, 0),
	OAM_ENTRY(4, -18, OAM_DIMS_8x16, OAM_X_FLIP, 72, 0, 0),
	OAM_ENTRY(-16, -21, OAM_DIMS_8x16, OAM_X_FLIP, 11, 0, 0),
};

static const u16 sOamFrame_5a3a1c[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(3, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-6, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 154, 0, 0),
	OAM_ENTRY(-4, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 157, 0, 0),
	OAM_ENTRY(-7, -38, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_X_FLIP, 76, 0, 0),
	OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_X_FLIP, 75, 0, 0),
	OAM_ENTRY(-17, -21, OAM_DIMS_8x8, OAM_X_FLIP, 107, 0, 0),
};

static const u16 sOamFrame_5a3a48[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(1, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-7, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
	OAM_ENTRY(-6, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
	OAM_ENTRY(-9, -37, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-12, -24, OAM_DIMS_16x16, OAM_X_FLIP, 326, 0, 0),
	OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_X_FLIP, 18, 0, 0),
};

static const u16 sOamFrame_5a3a6e[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(0, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-9, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 154, 0, 0),
	OAM_ENTRY(-7, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 157, 0, 0),
	OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-9, -21, OAM_DIMS_16x16, OAM_X_FLIP, 328, 0, 0),
	OAM_ENTRY(-14, -15, OAM_DIMS_8x16, OAM_X_FLIP, 82, 0, 0),
	OAM_ENTRY(-10, -24, OAM_DIMS_8x8, OAM_X_FLIP, 199, 0, 0),
};

static const u16 sOamFrame_5a3a9a[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(1, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-8, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 184, 0, 0),
	OAM_ENTRY(-5, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 158, 0, 0),
	OAM_ENTRY(-9, -38, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 330, 0, 0),
	OAM_ENTRY(-16, -17, OAM_DIMS_8x16, OAM_X_FLIP, 86, 0, 0),
	OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_X_FLIP, 51, 0, 0),
	OAM_ENTRY(-10, -18, OAM_DIMS_8x8, OAM_X_FLIP, 51, 0, 0),
};

static const u16 sOamFrame_5a3acc[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(2, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-6, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 184, 0, 0),
	OAM_ENTRY(-4, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 158, 0, 0),
	OAM_ENTRY(-8, -38, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_X_FLIP, 332, 0, 0),
	OAM_ENTRY(-17, -16, OAM_DIMS_8x16, OAM_X_FLIP, 57, 0, 0),
	OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_X_FLIP, 121, 0, 0),
};

static const u16 sOamFrame_5a3af8[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(2, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-6, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 154, 0, 0),
	OAM_ENTRY(-4, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 157, 0, 0),
	OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-10, -24, OAM_DIMS_16x16, OAM_X_FLIP, 334, 0, 0),
	OAM_ENTRY(-18, -24, OAM_DIMS_8x16, OAM_X_FLIP, 83, 0, 0),
	OAM_ENTRY(-2, -8, OAM_DIMS_16x8, OAM_X_FLIP, 28, 0, 0),
};

static const u16 sOamFrame_5a3b24[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-10, -37, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-3, -35, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-10, -27, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 336, 0, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 338, 0, 0),
	OAM_ENTRY(-19, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3b50[OAM_DATA_SIZE(8)] = {
	8,
	OAM_ENTRY(-10, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-3, -38, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-10, -30, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-9, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-19, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 340, 0, 0),
	OAM_ENTRY(-1, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(-2, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 199, 0, 0),
};

static const u16 sOamFrame_5a3b82[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-11, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-4, -34, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-11, -26, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 342, 0, 0),
	OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 370, 0, 0),
};

static const u16 sOamFrame_5a3bae[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-11, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-4, -28, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-11, -20, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-10, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-20, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-9, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 344, 0, 0),
	OAM_ENTRY(-9, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 346, 0, 0),
};

static const u16 sOamFrame_5a3bda[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-12, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-5, -26, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-12, -19, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-10, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-20, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 348, 0, 0),
};

static const u16 sOamFrame_5a3c00[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-11, -33, OAM_DIMS_16x8, OAM_NO_FLIP, 178, 0, 0),
	OAM_ENTRY(-4, -31, OAM_DIMS_8x8, OAM_XY_FLIP, 173, 0, 0),
	OAM_ENTRY(-11, -24, OAM_DIMS_16x8, OAM_XY_FLIP, 141, 0, 0),
	OAM_ENTRY(-10, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
	OAM_ENTRY(-20, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
	OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 350, 0, 0),
	OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 378, 0, 0),
};

static const u16 sOamFrame_5a3c2c[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(3, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-5, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
	OAM_ENTRY(-3, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
	OAM_ENTRY(-6, -37, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 336, 0, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 338, 0, 0),
};

static const u16 sOamFrame_5a3c52[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(3, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-6, -39, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
	OAM_ENTRY(-4, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
	OAM_ENTRY(-7, -40, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 340, 0, 0),
	OAM_ENTRY(-7, -8, OAM_DIMS_8x16, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-6, -29, OAM_DIMS_8x8, OAM_X_FLIP, 199, 0, 0),
};

static const u16 sOamFrame_5a3c7e[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-5, -35, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
	OAM_ENTRY(-2, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
	OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_X_FLIP, 342, 0, 0),
	OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 370, 0, 0),
};

static const u16 sOamFrame_5a3ca4[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(4, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-4, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
	OAM_ENTRY(-2, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
	OAM_ENTRY(-6, -30, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-7, -18, OAM_DIMS_16x16, OAM_X_FLIP, 344, 0, 0),
	OAM_ENTRY(-7, -2, OAM_DIMS_16x8, OAM_X_FLIP, 346, 0, 0),
};

static const u16 sOamFrame_5a3cca[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(4, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-4, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
	OAM_ENTRY(-2, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
	OAM_ENTRY(-6, -29, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 348, 0, 0),
};

static const u16 sOamFrame_5a3cea[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(4, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
	OAM_ENTRY(-4, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 152, 0, 0),
	OAM_ENTRY(-2, -31, OAM_DIMS_8x16, OAM_NO_FLIP, 156, 0, 0),
	OAM_ENTRY(-6, -34, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
	OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_X_FLIP, 350, 0, 0),
	OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_X_FLIP, 378, 0, 0),
};

static const u16 sOamFrame_5a3d10[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 395, 0, 0),
    OAM_ENTRY(-12, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 413, 0, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 417, 0, 0),
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 0, 0),
    OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3d36[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-3, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 395, 0, 0),
    OAM_ENTRY(-12, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 413, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 418, 0, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 0, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 419, 0, 0),
    OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3d62[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-3, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 396, 0, 0),
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 420, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 484, 0, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 486, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3d8e[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-3, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 394, 0, 0),
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 411, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 422, 0, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 487, 0, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 489, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3dba[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 394, 0, 0),
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 411, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 426, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 490, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3de0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 395, 0, 0),
    OAM_ENTRY(-12, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 413, 0, 0),
    OAM_ENTRY(-7, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 428, 0, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 492, 0, 0),
    OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3e06[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 395, 0, 0),
    OAM_ENTRY(-12, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 413, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 430, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 462, 0, 0),
    OAM_ENTRY(-10, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3e2c[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 396, 0, 0),
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 0, 0),
    OAM_ENTRY(-19, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 465, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 434, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3e52[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 394, 0, 0),
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 411, 0, 0),
    OAM_ENTRY(-11, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 437, 0, 0),
    OAM_ENTRY(-11, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 469, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3e78[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 394, 0, 0),
    OAM_ENTRY(-12, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 411, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 441, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 505, 0, 0),
    OAM_ENTRY(-10, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 144, 0, 0),
    OAM_ENTRY(-20, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 150, 0, 0),
};

static const u16 sOamFrame_5a3e9e[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 399, 0, 0),
    OAM_ENTRY(-2, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 408, 0, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_X_FLIP, 417, 0, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 448, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
};

static const u16 sOamFrame_5a3ec4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(4, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 399, 0, 0),
    OAM_ENTRY(-2, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 408, 0, 0),
    OAM_ENTRY(-3, -24, OAM_DIMS_8x8, OAM_X_FLIP, 418, 0, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 450, 0, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_8x8, OAM_X_FLIP, 419, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
};

static const u16 sOamFrame_5a3ef0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 400, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 415, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 420, 0, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 484, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_X_FLIP, 486, 0, 0),
};

static const u16 sOamFrame_5a3f1c[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 398, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 407, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_X_FLIP, 422, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 487, 0, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_X_FLIP, 489, 0, 0),
};

static const u16 sOamFrame_5a3f48[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 398, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 407, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 426, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 490, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
};

static const u16 sOamFrame_5a3f6e[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 399, 0, 0),
    OAM_ENTRY(-2, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 408, 0, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_16x16, OAM_X_FLIP, 428, 0, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_X_FLIP, 492, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
};

static const u16 sOamFrame_5a3f94[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 399, 0, 0),
    OAM_ENTRY(-2, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 408, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_X_FLIP, 430, 0, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_32x16, OAM_X_FLIP, 462, 0, 0),
    OAM_ENTRY(-6, -37, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
};

static const u16 sOamFrame_5a3fba[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 400, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 415, 0, 0),
    OAM_ENTRY(-13, -16, OAM_DIMS_32x16, OAM_X_FLIP, 465, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x8, OAM_X_FLIP, 434, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
};

static const u16 sOamFrame_5a3fe0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 398, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 407, 0, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_16x8, OAM_X_FLIP, 437, 0, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_32x16, OAM_X_FLIP, 469, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
};

static const u16 sOamFrame_5a4006[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 0, 0),
    OAM_ENTRY(-5, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 398, 0, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 407, 0, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 441, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 505, 0, 0),
    OAM_ENTRY(-6, -36, OAM_DIMS_16x16, OAM_X_FLIP, 144, 0, 0),
};

const struct FrameData sOam_5a402c[11] = {
    [0] = {
            .pFrame = sOamFrame_5a2ee8,
            .timer = 3
    },
    [1] = {
            .pFrame = sOamFrame_5a2ef6,
            .timer = 3
    },
    [2] = {
            .pFrame = sOamFrame_5a2f04,
            .timer = 3
    },
    [3] = {
            .pFrame = sOamFrame_5a2f1e,
            .timer = 3
    },
    [4] = {
            .pFrame = sOamFrame_5a2f38,
            .timer = 3
    },
    [5] = {
            .pFrame = sOamFrame_5a2f4c,
            .timer = 3
    },
    [6] = {
            .pFrame = sOamFrame_5a2f60,
            .timer = 3
    },
    [7] = {
            .pFrame = sOamFrame_5a2f74,
            .timer = 3
    },
    [8] = {
            .pFrame = sOamFrame_5a2f8e,
            .timer = 3
    },
    [9] = {
            .pFrame = sOamFrame_5a2fa8,
            .timer = 3
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a4084[11] = {
    [0] = {
            .pFrame = sOamFrame_5a2fbc,
            .timer = 3
    },
    [1] = {
            .pFrame = sOamFrame_5a2fd0,
            .timer = 3
    },
    [2] = {
            .pFrame = sOamFrame_5a2fe4,
            .timer = 3
    },
    [3] = {
            .pFrame = sOamFrame_5a300a,
            .timer = 3
    },
    [4] = {
            .pFrame = sOamFrame_5a302a,
            .timer = 3
    },
    [5] = {
            .pFrame = sOamFrame_5a3044,
            .timer = 3
    },
    [6] = {
            .pFrame = sOamFrame_5a3058,
            .timer = 3
    },
    [7] = {
            .pFrame = sOamFrame_5a3078,
            .timer = 3
    },
    [8] = {
            .pFrame = sOamFrame_5a3098,
            .timer = 3
    },
    [9] = {
            .pFrame = sOamFrame_5a30be,
            .timer = 3
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_IdleLeft[4] = {
    [0] = {
            .pFrame = sOamFrame_5a30de,
            .timer = 16
    },
    [1] = {
            .pFrame = sOamFrame_5a3110,
            .timer = 16
    },
    [2] = {
            .pFrame = sOamFrame_5a3142,
            .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a40fc[3] = {
    [0] = {
            .pFrame = sOamFrame_5a3174,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a3110,
            .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_IdleRight[4] = {
    [0] = {
            .pFrame = sOamFrame_5a31a6,
            .timer = 16
    },
    [1] = {
            .pFrame = sOamFrame_5a31d2,
            .timer = 16
    },
    [2] = {
            .pFrame = sOamFrame_5a31fe,
            .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a4134[3] = {
    [0] = {
            .pFrame = sOamFrame_5a322a,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a31d2,
            .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_MissileArmedLeft[4] = {
    [0] = {
            .pFrame = sOamFrame_5a3256,
            .timer = 16
    },
    [1] = {
            .pFrame = sOamFrame_5a328e,
            .timer = 16
    },
    [2] = {
            .pFrame = sOamFrame_5a32c6,
            .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_FiringMissileLeft[3] = {
    [0] = {
            .pFrame = sOamFrame_5a32fe,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a328e,
            .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a4184[4] = {
    [0] = {
            .pFrame = sOamFrame_5a3336,
            .timer = 16
    },
    [1] = {
            .pFrame = sOamFrame_5a3368,
            .timer = 16
    },
    [2] = {
            .pFrame = sOamFrame_5a339a,
            .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a41a4[3] = {
    [0] = {
            .pFrame = sOamFrame_5a33cc,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a3368,
            .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a41bc[4] = {
    [0] = {
            .pFrame = sOamFrame_5a33fe,
            .timer = 16
    },
    [1] = {
            .pFrame = sOamFrame_5a342a,
            .timer = 16
    },
    [2] = {
            .pFrame = sOamFrame_5a3456,
            .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a41dc[3] = {
    [0] = {
            .pFrame = sOamFrame_5a3482,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a342a,
            .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a41f4[4] = {
    [0] = {
            .pFrame = sOamFrame_5a34ae,
            .timer = 16
    },
    [1] = {
            .pFrame = sOamFrame_5a34e0,
            .timer = 16
    },
    [2] = {
            .pFrame = sOamFrame_5a3512,
            .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a4214[3] = {
    [0] = {
            .pFrame = sOamFrame_5a3544,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a34e0,
            .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_MissileArmedUpLeft[4] = {
    [0] = {
            .pFrame = sOamFrame_5a3576,
            .timer = 16
    },
    [1] = {
            .pFrame = sOamFrame_5a35a8,
            .timer = 16
    },
    [2] = {
            .pFrame = sOamFrame_5a35da,
            .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_FiringMissileUpLeft[3] = {
    [0] = {
            .pFrame = sOamFrame_5a360c,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a35a8,
            .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a4264[4] = {
    [0] = {
            .pFrame = sOamFrame_5a363e,
            .timer = 16
    },
    [1] = {
            .pFrame = sOamFrame_5a3676,
            .timer = 16
    },
    [2] = {
            .pFrame = sOamFrame_5a36ae,
            .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a4284[3] = {
    [0] = {
            .pFrame = sOamFrame_5a36e6,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a3676,
            .timer = 4
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_TurningRight[4] = {
    [0] = {
            .pFrame = sOamFrame_5a371e,
            .timer = 2
    },
    [1] = {
            .pFrame = sOamFrame_5a3744,
            .timer = 2
    },
    [2] = {
            .pFrame = sOamFrame_5a376a,
            .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_TurningLeft[4] = {
    [0] = {
            .pFrame = sOamFrame_5a376a,
            .timer = 2
    },
    [1] = {
            .pFrame = sOamFrame_5a3744,
            .timer = 2
    },
    [2] = {
            .pFrame = sOamFrame_5a371e,
            .timer = 2
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a42dc[11] = {
    [0] = {
            .pFrame = sOamFrame_5a3790,
            .timer = 3
    },
    [1] = {
            .pFrame = sOamFrame_5a37bc,
            .timer = 3
    },
    [2] = {
            .pFrame = sOamFrame_5a37e8,
            .timer = 3
    },
    [3] = {
            .pFrame = sOamFrame_5a381a,
            .timer = 3
    },
    [4] = {
            .pFrame = sOamFrame_5a384c,
            .timer = 3
    },
    [5] = {
            .pFrame = sOamFrame_5a387e,
            .timer = 3
    },
    [6] = {
            .pFrame = sOamFrame_5a38aa,
            .timer = 3
    },
    [7] = {
            .pFrame = sOamFrame_5a38dc,
            .timer = 3
    },
    [8] = {
            .pFrame = sOamFrame_5a3914,
            .timer = 3
    },
    [9] = {
            .pFrame = sOamFrame_5a3946,
            .timer = 3
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a4334[11] = {
    [0] = {
            .pFrame = sOamFrame_5a3978,
            .timer = 3
    },
    [1] = {
            .pFrame = sOamFrame_5a399e,
            .timer = 3
    },
    [2] = {
            .pFrame = sOamFrame_5a39c4,
            .timer = 3
    },
    [3] = {
            .pFrame = sOamFrame_5a39f0,
            .timer = 3
    },
    [4] = {
            .pFrame = sOamFrame_5a3a1c,
            .timer = 3
    },
    [5] = {
            .pFrame = sOamFrame_5a3a48,
            .timer = 3
    },
    [6] = {
            .pFrame = sOamFrame_5a3a6e,
            .timer = 3
    },
    [7] = {
            .pFrame = sOamFrame_5a3a9a,
            .timer = 3
    },
    [8] = {
            .pFrame = sOamFrame_5a3acc,
            .timer = 3
    },
    [9] = {
            .pFrame = sOamFrame_5a3af8,
            .timer = 3
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a438c[4] = {
    [0] = {
            .pFrame = sOamFrame_5a3b24,
            .timer = 6
    },
    [1] = {
            .pFrame = sOamFrame_5a3b50,
            .timer = 6
    },
    [2] = {
            .pFrame = sOamFrame_5a3b82,
            .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a43ac[2] = {
    [0] = {
            .pFrame = sOamFrame_5a3bae,
            .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a43bc[3] = {
    [0] = {
            .pFrame = sOamFrame_5a3bda,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a3c00,
            .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a43d4[4] = {
    [0] = {
            .pFrame = sOamFrame_5a3c2c,
            .timer = 6
    },
    [1] = {
            .pFrame = sOamFrame_5a3c52,
            .timer = 6
    },
    [2] = {
            .pFrame = sOamFrame_5a3c7e,
            .timer = 4
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a43f4[2] = {
    [0] = {
            .pFrame = sOamFrame_5a3ca4,
            .timer = 255
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5a4404[3] = {
    [0] = {
            .pFrame = sOamFrame_5a3cca,
            .timer = 4
    },
    [1] = {
            .pFrame = sOamFrame_5a3cea,
            .timer = 3
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_WalkingLeft[11] = {
    [0] = {
            .pFrame = sOamFrame_5a3d10,
            .timer = 5
    },
    [1] = {
            .pFrame = sOamFrame_5a3d36,
            .timer = 5
    },
    [2] = {
            .pFrame = sOamFrame_5a3d62,
            .timer = 5
    },
    [3] = {
            .pFrame = sOamFrame_5a3d8e,
            .timer = 5
    },
    [4] = {
            .pFrame = sOamFrame_5a3dba,
            .timer = 5
    },
    [5] = {
            .pFrame = sOamFrame_5a3de0,
            .timer = 5
    },
    [6] = {
            .pFrame = sOamFrame_5a3e06,
            .timer = 5
    },
    [7] = {
            .pFrame = sOamFrame_5a3e2c,
            .timer = 5
    },
    [8] = {
            .pFrame = sOamFrame_5a3e52,
            .timer = 5
    },
    [9] = {
            .pFrame = sOamFrame_5a3e78,
            .timer = 5
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroInSr388SamusOam_WalkingRight[11] = {
    [0] = {
            .pFrame = sOamFrame_5a3e9e,
            .timer = 5
    },
    [1] = {
            .pFrame = sOamFrame_5a3ec4,
            .timer = 5
    },
    [2] = {
            .pFrame = sOamFrame_5a3ef0,
            .timer = 5
    },
    [3] = {
            .pFrame = sOamFrame_5a3f1c,
            .timer = 5
    },
    [4] = {
            .pFrame = sOamFrame_5a3f48,
            .timer = 5
    },
    [5] = {
            .pFrame = sOamFrame_5a3f6e,
            .timer = 5
    },
    [6] = {
            .pFrame = sOamFrame_5a3f94,
            .timer = 5
    },
    [7] = {
            .pFrame = sOamFrame_5a3fba,
            .timer = 5
    },
    [8] = {
            .pFrame = sOamFrame_5a3fe0,
            .timer = 5
    },
    [9] = {
            .pFrame = sOamFrame_5a4006,
            .timer = 5
    },
    [10] = FRAME_DATA_TERMINATOR
};

const u32 sIntroHornoadEncounterBgGfx[4027] = INCBIN_U32("data/new_file_intro/hornoad_encounter_bg.gfx.lz");

const u32 sTilemap_5a83b8[196] = INCBIN_U32("data/new_file_intro/5a83b8.tm.lz");
const u32 sTilemap_5a86c8[479] = INCBIN_U32("data/new_file_intro/5a86c8.tm.lz");

const u16 sPal_5a8e44[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5a8e44.pal");

const u32 sTilemap_5a9044[135] = INCBIN_U32("data/new_file_intro/5a9044.tm.lz");

const u16 sPal_5a9260[15 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5a9260.pal");
const u16 sPal_5a9440[15 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5a9440.pal");

const u16 sArray_5a9620[30] = {
	C_16_2_8(0, 36),
	C_16_2_8(1, 12),
	C_16_2_8(2, 12),
	C_16_2_8(3, 36),
	C_16_2_8(2, 12),
	C_16_2_8(1, 12),
	C_16_2_8(0, 36),
	C_16_2_8(1, 12),
	C_16_2_8(2, 12),
	C_16_2_8(3, 36),
	C_16_2_8(4, 12),
	C_16_2_8(5, 12),
	C_16_2_8(6, 12),
	C_16_2_8(7, 12),
	C_16_2_8(11, 36),
	C_16_2_8(10, 12),
	C_16_2_8(9, 12),
	C_16_2_8(8, 36),
	C_16_2_8(9, 12),
	C_16_2_8(10, 12),
	C_16_2_8(11, 36),
	C_16_2_8(10, 12),
	C_16_2_8(9, 12),
	C_16_2_8(8, 36),
	C_16_2_8(9, 12),
	C_16_2_8(10, 12),
	C_16_2_8(11, 36),
	C_16_2_8(10, 12),
	C_16_2_8(9, 12),
	C_16_2_8(8, 36)
};

const u32 sIntroMetroidVaccineObjGfx[1485] = INCBIN_U32("data/new_file_intro/metroid_vaccine_obj.gfx.lz");

static const u16 sOamFrame_5aad90[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-39, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
};

static const u16 sOamFrame_5aaefa[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-38, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
};

static const u16 sOamFrame_5ab064[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-37, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
};

static const u16 sOamFrame_5ab1ce[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-36, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
};

static const u16 sOamFrame_5ab338[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-34, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
};

static const u16 sOamFrame_5ab4a2[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-32, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
};

static const u16 sOamFrame_5ab60c[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-30, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
};

static const u16 sOamFrame_5ab776[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-27, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
};

static const u16 sOamFrame_5ab8e0[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-24, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
};

static const u16 sOamFrame_5aba4a[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-21, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
};

static const u16 sOamFrame_5abbb4[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-18, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
};

static const u16 sOamFrame_5abd1e[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-14, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5abe88[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-11, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5abff2[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-1, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5ac15c[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-4, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
};

static const u16 sOamFrame_5ac2c6[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-7, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
};

static const u16 sOamFrame_5ac430[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(3, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
};

static const u16 sOamFrame_5ac59a[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(6, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
};

static const u16 sOamFrame_5ac704[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(10, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
};

static const u16 sOamFrame_5ac86e[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(13, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
};

static const u16 sOamFrame_5ac9d8[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(16, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
};

static const u16 sOamFrame_5acb42[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(19, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
};

static const u16 sOamFrame_5accac[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(22, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
};

static const u16 sOamFrame_5ace16[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(24, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
};

static const u16 sOamFrame_5acf80[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(26, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
};

static const u16 sOamFrame_5ad0ea[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(28, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
};

static const u16 sOamFrame_5ad254[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(29, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
};

static const u16 sOamFrame_5ad3be[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(30, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
};

static const u16 sOamFrame_5ad528[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(31, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
};

static const u16 sOamFrame_5ad692[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(31, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
};

static const u16 sOamFrame_5ad7fc[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(30, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
};

static const u16 sOamFrame_5ad966[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(29, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
};

static const u16 sOamFrame_5adad0[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(28, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
};

static const u16 sOamFrame_5adc3a[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(26, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
};

static const u16 sOamFrame_5adda4[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(24, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
};

static const u16 sOamFrame_5adf0e[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(22, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
};

static const u16 sOamFrame_5ae078[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(19, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
};

static const u16 sOamFrame_5ae1e2[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(16, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
};

static const u16 sOamFrame_5ae34c[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(13, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
};

static const u16 sOamFrame_5ae4b6[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(10, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
};

static const u16 sOamFrame_5ae620[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(6, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
};

static const u16 sOamFrame_5ae78a[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(3, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5ae8f4[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-1, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5aea5e[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-4, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
};

static const u16 sOamFrame_5aebc8[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-7, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
};

static const u16 sOamFrame_5aed32[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-11, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
};

static const u16 sOamFrame_5aee9c[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-14, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
};

static const u16 sOamFrame_5af006[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-18, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
};

static const u16 sOamFrame_5af170[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-21, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
};

static const u16 sOamFrame_5af2da[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-24, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
};

static const u16 sOamFrame_5af444[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-27, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
};

static const u16 sOamFrame_5af5ae[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-30, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
};

static const u16 sOamFrame_5af718[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-32, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 224, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 228, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
};

static const u16 sOamFrame_5af882[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-34, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 192, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 196, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 4, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 256, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 260, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
};

static const u16 sOamFrame_5af9ec[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-36, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
};

static const u16 sOamFrame_5afb56[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-37, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(16, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-24, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(26, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-34, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(28, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-36, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(19, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-27, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(6, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-7, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-21, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(13, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-32, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-1, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 128, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 132, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
};

static const u16 sOamFrame_5afcc0[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-38, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-38, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(30, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-32, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(24, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-21, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(13, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-14, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(19, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-27, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(28, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-36, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(31, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-39, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(26, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-34, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-24, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-11, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(3, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(16, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-34, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-4, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 96, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 100, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 352, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 356, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 288, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 292, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 32, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 36, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 160, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 164, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_X_FLIP, 384, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_X_FLIP, 388, 0, 0),
};

static const u16 sOamFrame_5afe2a[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-39, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-37, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-30, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(22, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-18, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(10, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-4, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-4, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(10, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-18, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(22, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-30, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(29, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(30, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(24, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(13, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-21, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-14, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-27, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(19, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-36, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-1, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-7, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 64, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 64, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 68, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 320, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 320, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 324, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 128, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 132, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 256, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 260, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 192, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 196, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 416, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 0, 0),
};

static const u16 sOamFrame_5aff94[OAM_DATA_SIZE(60)] = {
	60,
	OAM_ENTRY(-39, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-36, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(28, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-27, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(19, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-14, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(6, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-7, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-1, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(13, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-21, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(24, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(-32, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(30, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-38, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(29, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(-37, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(22, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(-30, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-18, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 0, 0),
	OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 4, 0),
	OAM_ENTRY(-18, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-30, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 1, 0),
	OAM_ENTRY(22, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 3, 0),
	OAM_ENTRY(-37, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(29, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-39, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(31, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-34, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 2, 0),
	OAM_ENTRY(26, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 2, 0),
	OAM_ENTRY(-24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(16, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(-11, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 3, 0),
	OAM_ENTRY(3, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 1, 0),
	OAM_ENTRY(3, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 414, 4, 0),
	OAM_ENTRY(-11, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 415, 0, 0),
	OAM_ENTRY(-32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 32, 0, 0),
	OAM_ENTRY(0, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 36, 0, 0),
	OAM_ENTRY(0, -88, OAM_DIMS_32x8, OAM_X_FLIP, 96, 0, 0),
	OAM_ENTRY(-32, -88, OAM_DIMS_32x8, OAM_X_FLIP, 100, 0, 0),
	OAM_ENTRY(0, -72, OAM_DIMS_32x8, OAM_X_FLIP, 352, 0, 0),
	OAM_ENTRY(-32, -72, OAM_DIMS_32x8, OAM_X_FLIP, 356, 0, 0),
	OAM_ENTRY(-32, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 288, 0, 0),
	OAM_ENTRY(0, -56, OAM_DIMS_32x8, OAM_NO_FLIP, 292, 0, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 160, 0, 0),
	OAM_ENTRY(0, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 0, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_X_FLIP, 0, 0, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_X_FLIP, 4, 0, 0),
	OAM_ENTRY(0, 40, OAM_DIMS_32x8, OAM_X_FLIP, 224, 0, 0),
	OAM_ENTRY(-32, 40, OAM_DIMS_32x8, OAM_X_FLIP, 228, 0, 0),
	OAM_ENTRY(-32, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 0, 0),
	OAM_ENTRY(0, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 0, 0),
};

static const u16 sOamFrame_5b00fe[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-112, -59, OAM_DIMS_8x16, OAM_NO_FLIP, 8, 6, 0),
};

static const u16 sOamFrame_5b0106[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-103, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_16x16, OAM_NO_FLIP, 8, 6, 0),
};

static const u16 sOamFrame_5b0114[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-103, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_16x16, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-96, -59, OAM_DIMS_8x16, OAM_NO_FLIP, 10, 6, 0),
};

static const u16 sOamFrame_5b0128[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-103, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-87, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 148, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 8, 6, 0),
};

static const u16 sOamFrame_5b013c[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-80, -59, OAM_DIMS_8x16, OAM_NO_FLIP, 12, 6, 0),
};

static const u16 sOamFrame_5b0150[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 150, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-80, -59, OAM_DIMS_16x16, OAM_NO_FLIP, 12, 6, 0),
};

static const u16 sOamFrame_5b016a[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 150, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-88, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 11, 6, 0),
};

static const u16 sOamFrame_5b0184[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-80, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 12, 6, 0),
};

static const u16 sOamFrame_5b019e[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-44, 31, OAM_DIMS_8x8, OAM_NO_FLIP, 136, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-48, -59, OAM_DIMS_8x16, OAM_NO_FLIP, 16, 6, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 8, 6, 0),
};

static const u16 sOamFrame_5b01c4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-44, 31, OAM_DIMS_16x16, OAM_NO_FLIP, 136, 5, 0),
	OAM_ENTRY(-48, -59, OAM_DIMS_16x16, OAM_NO_FLIP, 16, 6, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 8, 6, 0),
};

static const u16 sOamFrame_5b01e4[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-44, 31, OAM_DIMS_16x16, OAM_NO_FLIP, 136, 5, 0),
	OAM_ENTRY(-29, 39, OAM_DIMS_8x8, OAM_NO_FLIP, 170, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-56, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 15, 6, 0),
};

static const u16 sOamFrame_5b020a[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-44, 31, OAM_DIMS_16x16, OAM_NO_FLIP, 136, 5, 0),
	OAM_ENTRY(-29, 39, OAM_DIMS_16x8, OAM_NO_FLIP, 170, 5, 0),
	OAM_ENTRY(-48, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 16, 6, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 8, 6, 0),
};

static const u16 sOamFrame_5b0230[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-44, 31, OAM_DIMS_16x16, OAM_NO_FLIP, 136, 5, 0),
	OAM_ENTRY(-13, 31, OAM_DIMS_8x32, OAM_NO_FLIP, 140, 5, 0),
	OAM_ENTRY(-29, 39, OAM_DIMS_16x8, OAM_NO_FLIP, 170, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-72, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 13, 6, 0),
};

static const u16 sOamFrame_5b025c[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-44, 31, OAM_DIMS_16x16, OAM_NO_FLIP, 136, 5, 0),
	OAM_ENTRY(-29, 31, OAM_DIMS_32x32, OAM_NO_FLIP, 138, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-64, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 14, 6, 0),
};

static const u16 sOamFrame_5b0282[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-44, 31, OAM_DIMS_16x16, OAM_NO_FLIP, 136, 5, 0),
	OAM_ENTRY(-29, 31, OAM_DIMS_32x32, OAM_NO_FLIP, 138, 5, 0),
	OAM_ENTRY(3, 31, OAM_DIMS_8x32, OAM_NO_FLIP, 142, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-56, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 15, 6, 0),
};

static const u16 sOamFrame_5b02ae[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-44, 31, OAM_DIMS_16x16, OAM_NO_FLIP, 136, 5, 0),
	OAM_ENTRY(-29, 31, OAM_DIMS_32x32, OAM_NO_FLIP, 138, 5, 0),
	OAM_ENTRY(3, 31, OAM_DIMS_16x32, OAM_NO_FLIP, 142, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-48, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 16, 6, 0),
};

static const u16 sOamFrame_5b02da[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-103, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 5, 0),
	OAM_ENTRY(-71, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 182, 5, 0),
	OAM_ENTRY(-44, 31, OAM_DIMS_16x16, OAM_NO_FLIP, 136, 5, 0),
	OAM_ENTRY(-29, 31, OAM_DIMS_64x32, OAM_NO_FLIP, 138, 5, 0),
	OAM_ENTRY(-112, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 8, 6, 0),
	OAM_ENTRY(-48, -59, OAM_DIMS_64x32, OAM_NO_FLIP, 16, 6, 0),
	OAM_ENTRY(16, -59, OAM_DIMS_16x32, OAM_NO_FLIP, 24, 6, 0),
};

static const u16 sOamFrame_5b0306[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-128, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b030e[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-126, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b0316[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-124, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b031e[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-122, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b0326[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-128, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b032e[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-126, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b0336[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-124, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b033e[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-122, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b0346[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-120, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b034e[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-118, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(-126, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 5, 0),
};

static const u16 sOamFrame_5b035c[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-116, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(-124, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 5, 0),
};

static const u16 sOamFrame_5b036a[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-114, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(-122, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 5, 0),
};

static const u16 sOamFrame_5b0378[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-128, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0380[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-126, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0388[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-124, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0390[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-122, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0398[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-120, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03a0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-118, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03a8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-116, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03b0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-114, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03b8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-112, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03c0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-110, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03c8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-108, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03d0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-106, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03d8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-104, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03e0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-102, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03e8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-100, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03f0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-98, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b03f8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-96, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0400[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 26, 5, 0),
	OAM_ENTRY(-94, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b040e[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 28, 5, 0),
	OAM_ENTRY(-92, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 332, 5, 0),
};

static const u16 sOamFrame_5b041c[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 30, 5, 0),
	OAM_ENTRY(-90, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 336, 5, 0),
};

static const u16 sOamFrame_5b042a[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 90, 5, 0),
	OAM_ENTRY(-88, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 340, 5, 0),
};

static const u16 sOamFrame_5b0438[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 92, 5, 0),
	OAM_ENTRY(-86, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 344, 5, 0),
};

static const u16 sOamFrame_5b0446[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 94, 5, 0),
	OAM_ENTRY(-84, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 5, 0),
};

static const u16 sOamFrame_5b0454[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 154, 5, 0),
	OAM_ENTRY(-82, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 360, 5, 0),
};

static const u16 sOamFrame_5b0462[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 156, 5, 0),
	OAM_ENTRY(-80, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 364, 5, 0),
};

static const u16 sOamFrame_5b0470[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 158, 5, 0),
	OAM_ENTRY(-78, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 368, 5, 0),
};

static const u16 sOamFrame_5b047e[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 274, 5, 0),
	OAM_ENTRY(-76, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 372, 5, 0),
};

static const u16 sOamFrame_5b048c[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 276, 5, 0),
	OAM_ENTRY(-74, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 376, 5, 0),
};

static const u16 sOamFrame_5b049a[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 278, 5, 0),
};

static const u16 sOamFrame_5b04a2[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 216, 5, 0),
};

static const u16 sOamFrame_5b04aa[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 218, 5, 0),
};

static const u16 sOamFrame_5b04b2[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 220, 5, 0),
};

static const u16 sOamFrame_5b04ba[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 222, 5, 0),
};

static const u16 sOamFrame_5b04c2[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-48, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 380, 5, 0),
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 266, 5, 0),
};

static const u16 sOamFrame_5b04d0[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-48, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 381, 5, 0),
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 210, 5, 0),
};

static const u16 sOamFrame_5b04de[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-48, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 382, 5, 0),
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 212, 5, 0),
};

static const u16 sOamFrame_5b04ec[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 214, 5, 0),
	OAM_ENTRY(-48, 72, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b04fa[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-48, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 392, 5, 0),
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 268, 5, 0),
};

static const u16 sOamFrame_5b0508[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-48, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 394, 5, 0),
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 270, 5, 0),
};

static const u16 sOamFrame_5b0516[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-48, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 396, 5, 0),
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 272, 5, 0),
};

static const u16 sOamFrame_5b0524[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 280, 5, 0),
	OAM_ENTRY(-48, 72, OAM_DIMS_16x8, OAM_NO_FLIP, 398, 5, 0),
};

static const u16 sOamFrame_5b0532[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 5, 0),
	OAM_ENTRY(-56, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 400, 5, 0),
};

static const u16 sOamFrame_5b0540[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 284, 5, 0),
	OAM_ENTRY(-56, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 404, 0, 0),
};

static const u16 sOamFrame_5b054e[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-64, 72, OAM_DIMS_16x16, OAM_NO_FLIP, 286, 5, 0),
	OAM_ENTRY(-56, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 408, 5, 0),
};

static const u16 sOamFrame_5b055c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-56, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0564[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-54, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b056c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-52, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0574[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-50, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b057c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-48, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0584[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-46, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b058c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-44, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0594[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-42, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b059c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-40, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05a4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-38, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05ac[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-36, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05b4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-34, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05bc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-32, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05c4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-30, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05cc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-28, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05d4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-26, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05dc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-24, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05e4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-22, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05ec[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-20, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05f4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-18, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b05fc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0604[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-14, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b060c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-12, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0614[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-10, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b061c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0624[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-6, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b062c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0634[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-2, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b063c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(0, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0644[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b064c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(4, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0654[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(6, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b065c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(8, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0664[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(10, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b066c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(12, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0674[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(14, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b067c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(16, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0684[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(18, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b068c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(20, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0694[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(22, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b069c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(24, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06a4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(26, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06ac[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(28, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06b4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(30, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06bc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(32, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06c4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(34, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06cc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(36, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06d4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(38, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06dc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(40, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06e4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(42, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06ec[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(44, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06f4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(46, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b06fc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(48, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0704[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(50, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b070c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(52, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0714[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(54, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b071c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(56, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0724[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(58, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b072c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(60, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0734[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(62, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b073c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(64, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0744[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(66, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b074c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(68, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0754[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(70, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b075c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(72, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0764[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(74, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b076c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(76, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0774[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(78, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b077c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(80, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0784[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(82, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b078c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(84, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0794[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(86, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b079c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(88, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07a4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(90, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07ac[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(92, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07b4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(94, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07bc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(96, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07c4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(98, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07cc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(100, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07d4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(102, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07dc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(104, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07e4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(106, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07ec[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(108, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07f4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(110, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b07fc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(112, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0804[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(114, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b080c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(116, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b0814[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(118, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

static const u16 sOamFrame_5b081c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(120, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 328, 5, 0),
};

const struct FrameData sIntroMetroidVaccineDoubleHelixOam[60] = {
	[0] = {
		.pFrame = sOamFrame_5aad90,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5aaefa,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5ab064,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5ab1ce,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5ab338,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5ab4a2,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5ab60c,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5ab776,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5ab8e0,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5aba4a,
		.timer = 2
	},
	[10] = {
		.pFrame = sOamFrame_5abbb4,
		.timer = 2
	},
	[11] = {
		.pFrame = sOamFrame_5abd1e,
		.timer = 2
	},
	[12] = {
		.pFrame = sOamFrame_5abe88,
		.timer = 2
	},
	[13] = {
		.pFrame = sOamFrame_5abff2,
		.timer = 2
	},
	[14] = {
		.pFrame = sOamFrame_5ac15c,
		.timer = 2
	},
	[15] = {
		.pFrame = sOamFrame_5ac2c6,
		.timer = 2
	},
	[16] = {
		.pFrame = sOamFrame_5ac430,
		.timer = 2
	},
	[17] = {
		.pFrame = sOamFrame_5ac59a,
		.timer = 2
	},
	[18] = {
		.pFrame = sOamFrame_5ac704,
		.timer = 2
	},
	[19] = {
		.pFrame = sOamFrame_5ac86e,
		.timer = 2
	},
	[20] = {
		.pFrame = sOamFrame_5ac9d8,
		.timer = 2
	},
	[21] = {
		.pFrame = sOamFrame_5acb42,
		.timer = 2
	},
	[22] = {
		.pFrame = sOamFrame_5accac,
		.timer = 2
	},
	[23] = {
		.pFrame = sOamFrame_5ace16,
		.timer = 2
	},
	[24] = {
		.pFrame = sOamFrame_5acf80,
		.timer = 2
	},
	[25] = {
		.pFrame = sOamFrame_5ad0ea,
		.timer = 2
	},
	[26] = {
		.pFrame = sOamFrame_5ad254,
		.timer = 2
	},
	[27] = {
		.pFrame = sOamFrame_5ad3be,
		.timer = 2
	},
	[28] = {
		.pFrame = sOamFrame_5ad528,
		.timer = 2
	},
	[29] = {
		.pFrame = sOamFrame_5ad692,
		.timer = 2
	},
	[30] = {
		.pFrame = sOamFrame_5ad7fc,
		.timer = 2
	},
	[31] = {
		.pFrame = sOamFrame_5ad966,
		.timer = 2
	},
	[32] = {
		.pFrame = sOamFrame_5adad0,
		.timer = 2
	},
	[33] = {
		.pFrame = sOamFrame_5adc3a,
		.timer = 2
	},
	[34] = {
		.pFrame = sOamFrame_5adda4,
		.timer = 2
	},
	[35] = {
		.pFrame = sOamFrame_5adf0e,
		.timer = 2
	},
	[36] = {
		.pFrame = sOamFrame_5ae078,
		.timer = 2
	},
	[37] = {
		.pFrame = sOamFrame_5ae1e2,
		.timer = 2
	},
	[38] = {
		.pFrame = sOamFrame_5ae34c,
		.timer = 2
	},
	[39] = {
		.pFrame = sOamFrame_5ae4b6,
		.timer = 2
	},
	[40] = {
		.pFrame = sOamFrame_5ae620,
		.timer = 2
	},
	[41] = {
		.pFrame = sOamFrame_5ae78a,
		.timer = 2
	},
	[42] = {
		.pFrame = sOamFrame_5ae8f4,
		.timer = 2
	},
	[43] = {
		.pFrame = sOamFrame_5aea5e,
		.timer = 2
	},
	[44] = {
		.pFrame = sOamFrame_5aebc8,
		.timer = 2
	},
	[45] = {
		.pFrame = sOamFrame_5aed32,
		.timer = 2
	},
	[46] = {
		.pFrame = sOamFrame_5aee9c,
		.timer = 2
	},
	[47] = {
		.pFrame = sOamFrame_5af006,
		.timer = 2
	},
	[48] = {
		.pFrame = sOamFrame_5af170,
		.timer = 2
	},
	[49] = {
		.pFrame = sOamFrame_5af2da,
		.timer = 2
	},
	[50] = {
		.pFrame = sOamFrame_5af444,
		.timer = 2
	},
	[51] = {
		.pFrame = sOamFrame_5af5ae,
		.timer = 2
	},
	[52] = {
		.pFrame = sOamFrame_5af718,
		.timer = 2
	},
	[53] = {
		.pFrame = sOamFrame_5af882,
		.timer = 2
	},
	[54] = {
		.pFrame = sOamFrame_5af9ec,
		.timer = 2
	},
	[55] = {
		.pFrame = sOamFrame_5afb56,
		.timer = 2
	},
	[56] = {
		.pFrame = sOamFrame_5afcc0,
		.timer = 2
	},
	[57] = {
		.pFrame = sOamFrame_5afe2a,
		.timer = 2
	},
	[58] = {
		.pFrame = sOamFrame_5aff94,
		.timer = 2
	},
	[59] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroMetroidVaccineTextboxesOam[21] = {
	[0] = {
		.pFrame = sOamFrame_5b00fe,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5b0106,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5b0114,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5b0128,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5b013c,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5b0150,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5b016a,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5b0184,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5b019e,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5b01c4,
		.timer = 2
	},
	[10] = {
		.pFrame = sOamFrame_5b01e4,
		.timer = 2
	},
	[11] = {
		.pFrame = sOamFrame_5b020a,
		.timer = 2
	},
	[12] = {
		.pFrame = sOamFrame_5b0230,
		.timer = 2
	},
	[13] = {
		.pFrame = sOamFrame_5b025c,
		.timer = 2
	},
	[14] = {
		.pFrame = sOamFrame_5b0282,
		.timer = 2
	},
	[15] = {
		.pFrame = sOamFrame_5b02ae,
		.timer = 2
	},
	[16] = {
		.pFrame = sOamFrame_5b02da,
		.timer = 240
	},
	[17] = {
		.pFrame = sOamFrame_5b02da,
		.timer = 240
	},
	[18] = {
		.pFrame = sOamFrame_5b02da,
		.timer = 240
	},
	[19] = {
		.pFrame = sOamFrame_5b02da,
		.timer = 240
	},
	[20] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroMetroidVaccineElectrocardiogramOam[146] = {
	[0] = {
		.pFrame = sOamFrame_5b0306,
		.timer = 1
	},
	[1] = {
		.pFrame = sOamFrame_5b030e,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5b0316,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5b031e,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5b0326,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5b032e,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5b0336,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5b033e,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5b0346,
		.timer = 1
	},
	[9] = {
		.pFrame = sOamFrame_5b034e,
		.timer = 1
	},
	[10] = {
		.pFrame = sOamFrame_5b035c,
		.timer = 1
	},
	[11] = {
		.pFrame = sOamFrame_5b036a,
		.timer = 1
	},
	[12] = {
		.pFrame = sOamFrame_5b0378,
		.timer = 1
	},
	[13] = {
		.pFrame = sOamFrame_5b0380,
		.timer = 1
	},
	[14] = {
		.pFrame = sOamFrame_5b0388,
		.timer = 1
	},
	[15] = {
		.pFrame = sOamFrame_5b0390,
		.timer = 1
	},
	[16] = {
		.pFrame = sOamFrame_5b0398,
		.timer = 1
	},
	[17] = {
		.pFrame = sOamFrame_5b03a0,
		.timer = 1
	},
	[18] = {
		.pFrame = sOamFrame_5b03a8,
		.timer = 1
	},
	[19] = {
		.pFrame = sOamFrame_5b03b0,
		.timer = 1
	},
	[20] = {
		.pFrame = sOamFrame_5b03b8,
		.timer = 1
	},
	[21] = {
		.pFrame = sOamFrame_5b03c0,
		.timer = 1
	},
	[22] = {
		.pFrame = sOamFrame_5b03c8,
		.timer = 1
	},
	[23] = {
		.pFrame = sOamFrame_5b03d0,
		.timer = 1
	},
	[24] = {
		.pFrame = sOamFrame_5b03d8,
		.timer = 1
	},
	[25] = {
		.pFrame = sOamFrame_5b03e0,
		.timer = 1
	},
	[26] = {
		.pFrame = sOamFrame_5b03e8,
		.timer = 1
	},
	[27] = {
		.pFrame = sOamFrame_5b03f0,
		.timer = 1
	},
	[28] = {
		.pFrame = sOamFrame_5b03f8,
		.timer = 1
	},
	[29] = {
		.pFrame = sOamFrame_5b0400,
		.timer = 1
	},
	[30] = {
		.pFrame = sOamFrame_5b040e,
		.timer = 1
	},
	[31] = {
		.pFrame = sOamFrame_5b041c,
		.timer = 1
	},
	[32] = {
		.pFrame = sOamFrame_5b042a,
		.timer = 1
	},
	[33] = {
		.pFrame = sOamFrame_5b0438,
		.timer = 1
	},
	[34] = {
		.pFrame = sOamFrame_5b0446,
		.timer = 1
	},
	[35] = {
		.pFrame = sOamFrame_5b0454,
		.timer = 1
	},
	[36] = {
		.pFrame = sOamFrame_5b0462,
		.timer = 1
	},
	[37] = {
		.pFrame = sOamFrame_5b0470,
		.timer = 1
	},
	[38] = {
		.pFrame = sOamFrame_5b047e,
		.timer = 1
	},
	[39] = {
		.pFrame = sOamFrame_5b048c,
		.timer = 1
	},
	[40] = {
		.pFrame = sOamFrame_5b049a,
		.timer = 1
	},
	[41] = {
		.pFrame = sOamFrame_5b04a2,
		.timer = 1
	},
	[42] = {
		.pFrame = sOamFrame_5b04aa,
		.timer = 1
	},
	[43] = {
		.pFrame = sOamFrame_5b04b2,
		.timer = 1
	},
	[44] = {
		.pFrame = sOamFrame_5b04ba,
		.timer = 1
	},
	[45] = {
		.pFrame = sOamFrame_5b04c2,
		.timer = 1
	},
	[46] = {
		.pFrame = sOamFrame_5b04d0,
		.timer = 1
	},
	[47] = {
		.pFrame = sOamFrame_5b04de,
		.timer = 1
	},
	[48] = {
		.pFrame = sOamFrame_5b04ec,
		.timer = 1
	},
	[49] = {
		.pFrame = sOamFrame_5b04fa,
		.timer = 1
	},
	[50] = {
		.pFrame = sOamFrame_5b0508,
		.timer = 1
	},
	[51] = {
		.pFrame = sOamFrame_5b0516,
		.timer = 1
	},
	[52] = {
		.pFrame = sOamFrame_5b0524,
		.timer = 1
	},
	[53] = {
		.pFrame = sOamFrame_5b0532,
		.timer = 1
	},
	[54] = {
		.pFrame = sOamFrame_5b0540,
		.timer = 1
	},
	[55] = {
		.pFrame = sOamFrame_5b054e,
		.timer = 1
	},
	[56] = {
		.pFrame = sOamFrame_5b055c,
		.timer = 1
	},
	[57] = {
		.pFrame = sOamFrame_5b0564,
		.timer = 1
	},
	[58] = {
		.pFrame = sOamFrame_5b056c,
		.timer = 1
	},
	[59] = {
		.pFrame = sOamFrame_5b0574,
		.timer = 1
	},
	[60] = {
		.pFrame = sOamFrame_5b057c,
		.timer = 1
	},
	[61] = {
		.pFrame = sOamFrame_5b0584,
		.timer = 1
	},
	[62] = {
		.pFrame = sOamFrame_5b058c,
		.timer = 1
	},
	[63] = {
		.pFrame = sOamFrame_5b0594,
		.timer = 1
	},
	[64] = {
		.pFrame = sOamFrame_5b059c,
		.timer = 1
	},
	[65] = {
		.pFrame = sOamFrame_5b05a4,
		.timer = 1
	},
	[66] = {
		.pFrame = sOamFrame_5b05ac,
		.timer = 1
	},
	[67] = {
		.pFrame = sOamFrame_5b05b4,
		.timer = 1
	},
	[68] = {
		.pFrame = sOamFrame_5b05bc,
		.timer = 1
	},
	[69] = {
		.pFrame = sOamFrame_5b05c4,
		.timer = 1
	},
	[70] = {
		.pFrame = sOamFrame_5b05cc,
		.timer = 1
	},
	[71] = {
		.pFrame = sOamFrame_5b05d4,
		.timer = 1
	},
	[72] = {
		.pFrame = sOamFrame_5b05dc,
		.timer = 1
	},
	[73] = {
		.pFrame = sOamFrame_5b05e4,
		.timer = 1
	},
	[74] = {
		.pFrame = sOamFrame_5b05ec,
		.timer = 1
	},
	[75] = {
		.pFrame = sOamFrame_5b05f4,
		.timer = 1
	},
	[76] = {
		.pFrame = sOamFrame_5b05fc,
		.timer = 1
	},
	[77] = {
		.pFrame = sOamFrame_5b0604,
		.timer = 1
	},
	[78] = {
		.pFrame = sOamFrame_5b060c,
		.timer = 1
	},
	[79] = {
		.pFrame = sOamFrame_5b0614,
		.timer = 1
	},
	[80] = {
		.pFrame = sOamFrame_5b061c,
		.timer = 1
	},
	[81] = {
		.pFrame = sOamFrame_5b0624,
		.timer = 1
	},
	[82] = {
		.pFrame = sOamFrame_5b062c,
		.timer = 1
	},
	[83] = {
		.pFrame = sOamFrame_5b0634,
		.timer = 1
	},
	[84] = {
		.pFrame = sOamFrame_5b063c,
		.timer = 1
	},
	[85] = {
		.pFrame = sOamFrame_5b0644,
		.timer = 1
	},
	[86] = {
		.pFrame = sOamFrame_5b064c,
		.timer = 1
	},
	[87] = {
		.pFrame = sOamFrame_5b0654,
		.timer = 1
	},
	[88] = {
		.pFrame = sOamFrame_5b065c,
		.timer = 1
	},
	[89] = {
		.pFrame = sOamFrame_5b0664,
		.timer = 1
	},
	[90] = {
		.pFrame = sOamFrame_5b066c,
		.timer = 1
	},
	[91] = {
		.pFrame = sOamFrame_5b0674,
		.timer = 1
	},
	[92] = {
		.pFrame = sOamFrame_5b067c,
		.timer = 1
	},
	[93] = {
		.pFrame = sOamFrame_5b0684,
		.timer = 1
	},
	[94] = {
		.pFrame = sOamFrame_5b068c,
		.timer = 1
	},
	[95] = {
		.pFrame = sOamFrame_5b0694,
		.timer = 1
	},
	[96] = {
		.pFrame = sOamFrame_5b069c,
		.timer = 1
	},
	[97] = {
		.pFrame = sOamFrame_5b06a4,
		.timer = 1
	},
	[98] = {
		.pFrame = sOamFrame_5b06ac,
		.timer = 1
	},
	[99] = {
		.pFrame = sOamFrame_5b06b4,
		.timer = 1
	},
	[100] = {
		.pFrame = sOamFrame_5b06bc,
		.timer = 1
	},
	[101] = {
		.pFrame = sOamFrame_5b06c4,
		.timer = 1
	},
	[102] = {
		.pFrame = sOamFrame_5b06cc,
		.timer = 1
	},
	[103] = {
		.pFrame = sOamFrame_5b06d4,
		.timer = 1
	},
	[104] = {
		.pFrame = sOamFrame_5b06dc,
		.timer = 1
	},
	[105] = {
		.pFrame = sOamFrame_5b06e4,
		.timer = 1
	},
	[106] = {
		.pFrame = sOamFrame_5b06ec,
		.timer = 1
	},
	[107] = {
		.pFrame = sOamFrame_5b06f4,
		.timer = 1
	},
	[108] = {
		.pFrame = sOamFrame_5b06fc,
		.timer = 1
	},
	[109] = {
		.pFrame = sOamFrame_5b0704,
		.timer = 1
	},
	[110] = {
		.pFrame = sOamFrame_5b070c,
		.timer = 1
	},
	[111] = {
		.pFrame = sOamFrame_5b0714,
		.timer = 1
	},
	[112] = {
		.pFrame = sOamFrame_5b071c,
		.timer = 1
	},
	[113] = {
		.pFrame = sOamFrame_5b0724,
		.timer = 1
	},
	[114] = {
		.pFrame = sOamFrame_5b072c,
		.timer = 1
	},
	[115] = {
		.pFrame = sOamFrame_5b0734,
		.timer = 1
	},
	[116] = {
		.pFrame = sOamFrame_5b073c,
		.timer = 1
	},
	[117] = {
		.pFrame = sOamFrame_5b0744,
		.timer = 1
	},
	[118] = {
		.pFrame = sOamFrame_5b074c,
		.timer = 1
	},
	[119] = {
		.pFrame = sOamFrame_5b0754,
		.timer = 1
	},
	[120] = {
		.pFrame = sOamFrame_5b075c,
		.timer = 1
	},
	[121] = {
		.pFrame = sOamFrame_5b0764,
		.timer = 1
	},
	[122] = {
		.pFrame = sOamFrame_5b076c,
		.timer = 1
	},
	[123] = {
		.pFrame = sOamFrame_5b0774,
		.timer = 1
	},
	[124] = {
		.pFrame = sOamFrame_5b077c,
		.timer = 1
	},
	[125] = {
		.pFrame = sOamFrame_5b0784,
		.timer = 1
	},
	[126] = {
		.pFrame = sOamFrame_5b078c,
		.timer = 1
	},
	[127] = {
		.pFrame = sOamFrame_5b0794,
		.timer = 1
	},
	[128] = {
		.pFrame = sOamFrame_5b079c,
		.timer = 1
	},
	[129] = {
		.pFrame = sOamFrame_5b07a4,
		.timer = 1
	},
	[130] = {
		.pFrame = sOamFrame_5b07ac,
		.timer = 1
	},
	[131] = {
		.pFrame = sOamFrame_5b07b4,
		.timer = 1
	},
	[132] = {
		.pFrame = sOamFrame_5b07bc,
		.timer = 1
	},
	[133] = {
		.pFrame = sOamFrame_5b07c4,
		.timer = 1
	},
	[134] = {
		.pFrame = sOamFrame_5b07cc,
		.timer = 1
	},
	[135] = {
		.pFrame = sOamFrame_5b07d4,
		.timer = 1
	},
	[136] = {
		.pFrame = sOamFrame_5b07dc,
		.timer = 1
	},
	[137] = {
		.pFrame = sOamFrame_5b07e4,
		.timer = 1
	},
	[138] = {
		.pFrame = sOamFrame_5b07ec,
		.timer = 1
	},
	[139] = {
		.pFrame = sOamFrame_5b07f4,
		.timer = 1
	},
	[140] = {
		.pFrame = sOamFrame_5b07fc,
		.timer = 1
	},
	[141] = {
		.pFrame = sOamFrame_5b0804,
		.timer = 1
	},
	[142] = {
		.pFrame = sOamFrame_5b080c,
		.timer = 1
	},
	[143] = {
		.pFrame = sOamFrame_5b0814,
		.timer = 1
	},
	[144] = {
		.pFrame = sOamFrame_5b081c,
		.timer = 1
	},
	[145] = FRAME_DATA_TERMINATOR
};

const u16 sIntroMetroidVaccineObjPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/metroid_vaccine_obj.pal");

const u32 sIntroMetroidVaccineBgGfx[2794] = INCBIN_U32("data/new_file_intro/metroid_vaccine_bg.gfx.lz");

const u16 sIntroMetroidVaccineBgPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/metroid_vaccine_bg.pal");

const u32 sIntroMetroidVaccineBg1Tilemap[106] = INCBIN_U32("data/new_file_intro/metroid_vaccine_bg1.tm.lz");
const u32 sIntroMetroidVaccineBg2Tilemap[109] = INCBIN_U32("data/new_file_intro/metroid_vaccine_bg2.tm.lz");
const u32 sIntroMetroidVaccineBg3Tilemap[208] = INCBIN_U32("data/new_file_intro/metroid_vaccine_bg3.tm.lz");

const u32 sIntroSamusNervousSystemObjGfx[2495] = INCBIN_U32("data/new_file_intro/samus_nervous_system_obj.gfx.lz");

static const u16 sOamFrame_5b6c7c[OAM_DATA_SIZE(31)] = {
	31,
	OAM_ENTRY(8, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 263, 3, 0),
	OAM_ENTRY(8, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 295, 1, 0),
	OAM_ENTRY(8, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 327, 2, 0),
	OAM_ENTRY(-96, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 256, 2, 0),
	OAM_ENTRY(-96, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 288, 3, 0),
	OAM_ENTRY(-88, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 289, 2, 0),
	OAM_ENTRY(-80, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 322, 3, 0),
	OAM_ENTRY(-88, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 321, 3, 0),
	OAM_ENTRY(-72, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 323, 2, 0),
	OAM_ENTRY(-96, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 320, 3, 0),
	OAM_ENTRY(-80, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 292, 3, 0),
	OAM_ENTRY(-72, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 293, 3, 0),
	OAM_ENTRY(-72, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 261, 3, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 262, 3, 0),
	OAM_ENTRY(-80, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 260, 3, 0),
	OAM_ENTRY(88, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 291, 2, 0),
	OAM_ENTRY(80, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 290, 2, 0),
	OAM_ENTRY(80, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 266, 3, 0),
	OAM_ENTRY(72, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 265, 3, 0),
	OAM_ENTRY(64, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 264, 3, 0),
	OAM_ENTRY(88, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 267, 3, 0),
	OAM_ENTRY(-72, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 325, 2, 0),
	OAM_ENTRY(-96, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 352, 3, 0),
	OAM_ENTRY(-88, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 353, 3, 0),
	OAM_ENTRY(-80, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 354, 3, 0),
	OAM_ENTRY(-72, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 355, 3, 0),
	OAM_ENTRY(-64, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 324, 1, 0),
	OAM_ENTRY(-64, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 356, 1, 0),
	OAM_ENTRY(-72, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 257, 3, 0),
	OAM_ENTRY(-72, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 258, 2, 0),
	OAM_ENTRY(-64, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 259, 3, 0),
};

static const u16 sOamFrame_5b6d38[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0, 4, 0),
};

static const u16 sOamFrame_5b6d40[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 4, 4, 0),
};

static const u16 sOamFrame_5b6d48[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 8, 4, 0),
};

static const u16 sOamFrame_5b6d50[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 12, 4, 0),
};

static const u16 sOamFrame_5b6d58[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 16, 4, 0),
};

static const u16 sOamFrame_5b6d60[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 20, 4, 0),
};

static const u16 sOamFrame_5b6d68[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 24, 4, 0),
};

static const u16 sOamFrame_5b6d70[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 28, 4, 0),
};

static const u16 sOamFrame_5b6d78[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 128, 4, 0),
};

static const u16 sOamFrame_5b6d80[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 132, 4, 0),
};

static const u16 sOamFrame_5b6d88[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 136, 4, 0),
};

static const u16 sOamFrame_5b6d90[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 140, 4, 0),
};

static const u16 sOamFrame_5b6d98[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 144, 4, 0),
};

static const u16 sOamFrame_5b6da0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 148, 4, 0),
};

static const u16 sOamFrame_5b6da8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 152, 4, 0),
};

static const u16 sOamFrame_5b6db0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 156, 4, 0),
};

static const u16 sOamFrame_5b6db8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0, 6, 0),
};

static const u16 sOamFrame_5b6dc0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 4, 6, 0),
};

static const u16 sOamFrame_5b6dc8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 8, 6, 0),
};

static const u16 sOamFrame_5b6dd0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 12, 6, 0),
};

static const u16 sOamFrame_5b6dd8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 16, 6, 0),
};

static const u16 sOamFrame_5b6de0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 20, 6, 0),
};

static const u16 sOamFrame_5b6de8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 24, 6, 0),
};

static const u16 sOamFrame_5b6df0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 28, 6, 0),
};

static const u16 sOamFrame_5b6df8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 128, 6, 0),
};

static const u16 sOamFrame_5b6e00[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 132, 6, 0),
};

static const u16 sOamFrame_5b6e08[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 136, 6, 0),
};

static const u16 sOamFrame_5b6e10[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 140, 6, 0),
};

static const u16 sOamFrame_5b6e18[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 144, 6, 0),
};

static const u16 sOamFrame_5b6e20[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 148, 6, 0),
};

static const u16 sOamFrame_5b6e28[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 152, 6, 0),
};

static const u16 sOamFrame_5b6e30[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 156, 6, 0),
};

static const u16 sOamFrame_5b6e38[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0, 7, 0),
};

static const u16 sOamFrame_5b6e40[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 4, 7, 0),
};

static const u16 sOamFrame_5b6e48[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 8, 7, 0),
};

static const u16 sOamFrame_5b6e50[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 12, 7, 0),
};

static const u16 sOamFrame_5b6e58[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 16, 7, 0),
};

static const u16 sOamFrame_5b6e60[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 20, 7, 0),
};

static const u16 sOamFrame_5b6e68[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 24, 7, 0),
};

static const u16 sOamFrame_5b6e70[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 28, 7, 0),
};

static const u16 sOamFrame_5b6e78[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 128, 7, 0),
};

static const u16 sOamFrame_5b6e80[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 132, 7, 0),
};

static const u16 sOamFrame_5b6e88[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 136, 7, 0),
};

static const u16 sOamFrame_5b6e90[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 140, 7, 0),
};

static const u16 sOamFrame_5b6e98[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 144, 7, 0),
};

static const u16 sOamFrame_5b6ea0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 148, 7, 0),
};

static const u16 sOamFrame_5b6ea8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 152, 7, 0),
};

static const u16 sOamFrame_5b6eb0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 156, 7, 0),
};

static const u16 sOamFrame_5b6eb8[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-32, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 393, 5, 0),
	OAM_ENTRY(16, -32, OAM_DIMS_16x16, OAM_X_FLIP, 393, 5, 0),
	OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_Y_FLIP, 393, 5, 0),
	OAM_ENTRY(16, 16, OAM_DIMS_16x16, OAM_XY_FLIP, 393, 5, 0),
};

static const u16 sOamFrame_5b6ed2[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-30, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 393, 5, 0),
	OAM_ENTRY(14, -30, OAM_DIMS_16x16, OAM_X_FLIP, 393, 5, 0),
	OAM_ENTRY(-30, 14, OAM_DIMS_16x16, OAM_Y_FLIP, 393, 5, 0),
	OAM_ENTRY(14, 14, OAM_DIMS_16x16, OAM_XY_FLIP, 393, 5, 0),
};

static const u16 sOamFrame_5b6eec[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-28, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 393, 5, 0),
	OAM_ENTRY(12, -28, OAM_DIMS_16x16, OAM_X_FLIP, 393, 5, 0),
	OAM_ENTRY(-28, 12, OAM_DIMS_16x16, OAM_Y_FLIP, 393, 5, 0),
	OAM_ENTRY(12, 12, OAM_DIMS_16x16, OAM_XY_FLIP, 393, 5, 0),
};

static const u16 sOamFrame_5b6f06[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-26, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 393, 5, 0),
	OAM_ENTRY(10, -26, OAM_DIMS_16x16, OAM_X_FLIP, 393, 5, 0),
	OAM_ENTRY(-26, 10, OAM_DIMS_16x16, OAM_Y_FLIP, 393, 5, 0),
	OAM_ENTRY(10, 10, OAM_DIMS_16x16, OAM_XY_FLIP, 393, 5, 0),
};

static const u16 sOamFrame_5b6f20[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 393, 5, 0),
	OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 393, 5, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 393, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 393, 5, 0),
};

static const u16 sOamFrame_5b6f3a[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-22, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 393, 5, 0),
	OAM_ENTRY(6, -22, OAM_DIMS_16x16, OAM_X_FLIP, 393, 5, 0),
	OAM_ENTRY(-22, 6, OAM_DIMS_16x16, OAM_Y_FLIP, 393, 5, 0),
	OAM_ENTRY(6, 6, OAM_DIMS_16x16, OAM_XY_FLIP, 393, 5, 0),
};

static const u16 sOamFrame_5b6f54[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-20, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 393, 5, 0),
	OAM_ENTRY(4, -20, OAM_DIMS_16x16, OAM_X_FLIP, 393, 5, 0),
	OAM_ENTRY(-20, 4, OAM_DIMS_16x16, OAM_Y_FLIP, 393, 5, 0),
	OAM_ENTRY(4, 4, OAM_DIMS_16x16, OAM_XY_FLIP, 393, 5, 0),
};

static const u16 sOamFrame_5b6f6e[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-18, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 393, 5, 0),
	OAM_ENTRY(2, -18, OAM_DIMS_16x16, OAM_X_FLIP, 393, 5, 0),
	OAM_ENTRY(-18, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 393, 5, 0),
	OAM_ENTRY(2, 2, OAM_DIMS_16x16, OAM_XY_FLIP, 393, 5, 0),
};

static const u16 sOamFrame_5b6f88[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
};

static const u16 sOamFrame_5b6f90[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b6f98[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
};

static const u16 sOamFrame_5b6fa6[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
};

static const u16 sOamFrame_5b6fba[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
};

static const u16 sOamFrame_5b6fd4[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
};

static const u16 sOamFrame_5b6ffa[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-57, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 278, 5, 0),
	OAM_ENTRY(-25, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 282, 5, 0),
};

static const u16 sOamFrame_5b701a[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 300, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 304, 5, 0),
};

static const u16 sOamFrame_5b703a[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 332, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 336, 5, 0),
};

static const u16 sOamFrame_5b705a[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 364, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 368, 5, 0),
};

static const u16 sOamFrame_5b707a[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 273, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 277, 5, 0),
};

static const u16 sOamFrame_5b709a[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 305, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 309, 5, 0),
};

static const u16 sOamFrame_5b70ba[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 337, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 341, 5, 0),
};

static const u16 sOamFrame_5b70da[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-60, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-28, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
};

static const u16 sOamFrame_5b70fa[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b711a[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b7134[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b7148[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
};

static const u16 sOamFrame_5b7156[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
};

static const u16 sOamFrame_5b715e[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-60, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-44, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 371, 5, 0),
};

static const u16 sOamFrame_5b716c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-60, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 369, 5, 0),
};

static const u16 sOamFrame_5b7174[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-60, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 369, 5, 0),
};

static const u16 sOamFrame_5b717c[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
};

static const u16 sOamFrame_5b718a[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-15, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b71a4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b71c4[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-2, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(30, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
};

static const u16 sOamFrame_5b71f0[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 278, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 282, 5, 0),
};

static const u16 sOamFrame_5b7216[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 310, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 314, 5, 0),
};

static const u16 sOamFrame_5b723c[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 342, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 5, 0),
};

static const u16 sOamFrame_5b7262[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 374, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 5, 0),
};

static const u16 sOamFrame_5b7288[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 283, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 287, 5, 0),
};

static const u16 sOamFrame_5b72ae[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 315, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 319, 5, 0),
};

static const u16 sOamFrame_5b72d4[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 347, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 5, 0),
};

static const u16 sOamFrame_5b72fa[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(1, 13, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(33, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7320[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 329, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 329, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7346[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 329, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7366[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b737a[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(1, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7388[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(9, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 5, 0),
};

static const u16 sOamFrame_5b7390[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(17, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 381, 5, 0),
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b739e[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(25, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 382, 5, 0),
};

static const u16 sOamFrame_5b73a6[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(33, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b73ae[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
};

static const u16 sOamFrame_5b73bc[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b73d0[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b73ea[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(21, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(53, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
};

static const u16 sOamFrame_5b7410[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 278, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 282, 5, 0),
};

static const u16 sOamFrame_5b7430[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 310, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 314, 5, 0),
};

static const u16 sOamFrame_5b7450[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 342, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 5, 0),
};

static const u16 sOamFrame_5b7470[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 374, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 5, 0),
};

static const u16 sOamFrame_5b7490[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 283, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 287, 5, 0),
};

static const u16 sOamFrame_5b74b0[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 315, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 319, 5, 0),
};

static const u16 sOamFrame_5b74d0[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 347, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 5, 0),
};

static const u16 sOamFrame_5b74f0[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(24, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(56, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7510[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b7530[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b754a[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b755e[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b756c[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(32, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 5, 0),
};

static const u16 sOamFrame_5b7574[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(40, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 381, 5, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7582[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(48, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 382, 5, 0),
};

static const u16 sOamFrame_5b758a[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(56, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7592[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
};

static const u16 sOamFrame_5b75a0[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b75b4[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
};

static const u16 sOamFrame_5b75ce[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(18, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(50, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
};

static const u16 sOamFrame_5b75f4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 278, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 282, 5, 0),
};

static const u16 sOamFrame_5b7614[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 310, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 314, 5, 0),
};

static const u16 sOamFrame_5b7634[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 342, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 346, 5, 0),
};

static const u16 sOamFrame_5b7654[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 374, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 378, 5, 0),
};

static const u16 sOamFrame_5b7674[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 283, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 287, 5, 0),
};

static const u16 sOamFrame_5b7694[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 315, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 319, 5, 0),
};

static const u16 sOamFrame_5b76b4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 347, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 5, 0),
};

static const u16 sOamFrame_5b76d4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(21, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(53, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b76f4[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 329, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b7714[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b772e[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 331, 5, 0),
};

static const u16 sOamFrame_5b7742[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(21, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 379, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7750[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(29, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 5, 0),
};

static const u16 sOamFrame_5b7758[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(37, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 381, 5, 0),
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7766[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(45, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 382, 5, 0),
};

static const u16 sOamFrame_5b776e[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(53, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 383, 5, 0),
};

static const u16 sOamFrame_5b7776[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
};

static const u16 sOamFrame_5b7784[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
};

static const u16 sOamFrame_5b779e[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b77be[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 384, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
};

static const u16 sOamFrame_5b77ea[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-37, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 278, 5, 0),
	OAM_ENTRY(-5, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 282, 5, 0),
};

static const u16 sOamFrame_5b7810[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 300, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 304, 5, 0),
};

static const u16 sOamFrame_5b7836[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 332, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 336, 5, 0),
};

static const u16 sOamFrame_5b785c[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 364, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 368, 5, 0),
};

static const u16 sOamFrame_5b7882[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 273, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 277, 5, 0),
};

static const u16 sOamFrame_5b78a8[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 305, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 309, 5, 0),
};

static const u16 sOamFrame_5b78ce[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 337, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 341, 5, 0),
};

static const u16 sOamFrame_5b78f4[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-40, 13, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-8, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
};

static const u16 sOamFrame_5b791a[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b7940[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 329, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b7960[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 330, 5, 0),
};

static const u16 sOamFrame_5b7974[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 373, 5, 0),
};

static const u16 sOamFrame_5b7982[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 369, 5, 0),
};

static const u16 sOamFrame_5b798a[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-40, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 369, 5, 0),
	OAM_ENTRY(-24, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 371, 5, 0),
};

static const u16 sOamFrame_5b7998[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-40, 12, OAM_DIMS_16x8, OAM_NO_FLIP, 369, 5, 0),
};

static const u16 sOamFrame_5b79a0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-40, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 369, 5, 0),
};

static const u16 sOamFrame_5b79a8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 388, 5, 0),
};

static const u16 sOamFrame_5b79b0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 389, 5, 0),
};

static const u16 sOamFrame_5b79b8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 390, 5, 0),
};

static const u16 sOamFrame_5b79c0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 391, 5, 0),
};

static const u16 sOamFrame_5b79c8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 392, 5, 0),
};

static const u16 sOamFrame_5b79d0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 452, 5, 0),
};

static const u16 sOamFrame_5b79d8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 453, 5, 0),
};

static const u16 sOamFrame_5b79e0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 454, 5, 0),
};

static const u16 sOamFrame_5b79e8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 455, 5, 0),
};

static const u16 sOamFrame_5b79f0[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 456, 5, 0),
};

static const u16 sOamFrame_5b79f8[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(2, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 395, 5, 0),
};

static const u16 sOamFrame_5b7a00[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 399, 5, 0),
	OAM_ENTRY(32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 403, 5, 0),
};

static const u16 sOamFrame_5b7a0e[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 357, 3, 0),
};

static const u16 sOamFrame_5b7a16[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b7a1e[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b7a2c[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b7a40[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b7a5a[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 299, 5, 0),
	OAM_ENTRY(-60, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(-28, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b7a80[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b7a8e[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-15, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b7aa8[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b7ac8[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-2, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(30, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
};

static const u16 sOamFrame_5b7af4[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b7b02[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b7b16[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b7b30[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(15, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(21, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(53, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
};

static const u16 sOamFrame_5b7b56[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b7b64[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b7b78[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
};

static const u16 sOamFrame_5b7b92[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 299, 5, 0),
	OAM_ENTRY(18, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(50, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
};

static const u16 sOamFrame_5b7bb8[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
};

static const u16 sOamFrame_5b7bc6[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
};

static const u16 sOamFrame_5b7be0[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
};

static const u16 sOamFrame_5b7c00[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 296, 5, 0),
	OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 297, 5, 0),
	OAM_ENTRY(0, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 298, 5, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 268, 5, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 272, 5, 0),
};

const struct FrameData sIntroSamusNervousSystemXLockOnOam_1[171] = {
	[0] = {
		.pFrame = sOamFrame_5b6eb8,
		.timer = 1
	},
	[1] = {
		.pFrame = sOamFrame_5b6ed2,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5b6eec,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5b6f06,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5b6f20,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5b6f3a,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5b6f54,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5b6f6e,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[9] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[10] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[11] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[12] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[13] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[14] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[15] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[16] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[17] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[18] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[19] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[20] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[21] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[22] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[23] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[24] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[25] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[26] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[27] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[28] = {
		.pFrame = sOamFrame_5b7a80,
		.timer = 1
	},
	[29] = {
		.pFrame = sOamFrame_5b717c,
		.timer = 1
	},
	[30] = {
		.pFrame = sOamFrame_5b7a8e,
		.timer = 1
	},
	[31] = {
		.pFrame = sOamFrame_5b718a,
		.timer = 1
	},
	[32] = {
		.pFrame = sOamFrame_5b7aa8,
		.timer = 1
	},
	[33] = {
		.pFrame = sOamFrame_5b71a4,
		.timer = 1
	},
	[34] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[35] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[36] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[37] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[38] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[39] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[40] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[41] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[42] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[43] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[44] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[45] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[46] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[47] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[48] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[49] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[50] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[51] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[52] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[53] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[54] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[55] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[56] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[57] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[58] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[59] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[60] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[61] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[62] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[63] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[64] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[65] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[66] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[67] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[68] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[69] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[70] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[71] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[72] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[73] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[74] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[75] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[76] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[77] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[78] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[79] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[80] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[81] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[82] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[83] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[84] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[85] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[86] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[87] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[88] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[89] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[90] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[91] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[92] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[93] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[94] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[95] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[96] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[97] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[98] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[99] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[100] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[101] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[102] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[103] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[104] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[105] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[106] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[107] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[108] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[109] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[110] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[111] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[112] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[113] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[114] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[115] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[116] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[117] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[118] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[119] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[120] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[121] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[122] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[123] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[124] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[125] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[126] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[127] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[128] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[129] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[130] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[131] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[132] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[133] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[134] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[135] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[136] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[137] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[138] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[139] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[140] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[141] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[142] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[143] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[144] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[145] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[146] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[147] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[148] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[149] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[150] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[151] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[152] = {
		.pFrame = sOamFrame_5b7ac8,
		.timer = 1
	},
	[153] = {
		.pFrame = sOamFrame_5b71c4,
		.timer = 1
	},
	[154] = {
		.pFrame = sOamFrame_5b71f0,
		.timer = 4
	},
	[155] = {
		.pFrame = sOamFrame_5b7216,
		.timer = 4
	},
	[156] = {
		.pFrame = sOamFrame_5b723c,
		.timer = 4
	},
	[157] = {
		.pFrame = sOamFrame_5b7262,
		.timer = 4
	},
	[158] = {
		.pFrame = sOamFrame_5b7288,
		.timer = 4
	},
	[159] = {
		.pFrame = sOamFrame_5b72ae,
		.timer = 4
	},
	[160] = {
		.pFrame = sOamFrame_5b72d4,
		.timer = 4
	},
	[161] = {
		.pFrame = sOamFrame_5b72fa,
		.timer = 4
	},
	[162] = {
		.pFrame = sOamFrame_5b7320,
		.timer = 120
	},
	[163] = {
		.pFrame = sOamFrame_5b7346,
		.timer = 3
	},
	[164] = {
		.pFrame = sOamFrame_5b7366,
		.timer = 3
	},
	[165] = {
		.pFrame = sOamFrame_5b737a,
		.timer = 3
	},
	[166] = {
		.pFrame = sOamFrame_5b7388,
		.timer = 3
	},
	[167] = {
		.pFrame = sOamFrame_5b7390,
		.timer = 3
	},
	[168] = {
		.pFrame = sOamFrame_5b739e,
		.timer = 3
	},
	[169] = {
		.pFrame = sOamFrame_5b73a6,
		.timer = 3
	},
	[170] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXLockOnOam_2[171] = {
	[0] = {
		.pFrame = sOamFrame_5b6eb8,
		.timer = 1
	},
	[1] = {
		.pFrame = sOamFrame_5b6ed2,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5b6eec,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5b6f06,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5b6f20,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5b6f3a,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5b6f54,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5b6f6e,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[9] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[10] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[11] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[12] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[13] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[14] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[15] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[16] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[17] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[18] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[19] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[20] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[21] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[22] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[23] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[24] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[25] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[26] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[27] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[28] = {
		.pFrame = sOamFrame_5b7af4,
		.timer = 1
	},
	[29] = {
		.pFrame = sOamFrame_5b73ae,
		.timer = 1
	},
	[30] = {
		.pFrame = sOamFrame_5b7b02,
		.timer = 1
	},
	[31] = {
		.pFrame = sOamFrame_5b73bc,
		.timer = 1
	},
	[32] = {
		.pFrame = sOamFrame_5b7b16,
		.timer = 1
	},
	[33] = {
		.pFrame = sOamFrame_5b73d0,
		.timer = 1
	},
	[34] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[35] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[36] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[37] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[38] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[39] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[40] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[41] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[42] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[43] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[44] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[45] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[46] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[47] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[48] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[49] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[50] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[51] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[52] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[53] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[54] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[55] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[56] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[57] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[58] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[59] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[60] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[61] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[62] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[63] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[64] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[65] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[66] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[67] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[68] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[69] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[70] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[71] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[72] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[73] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[74] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[75] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[76] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[77] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[78] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[79] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[80] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[81] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[82] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[83] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[84] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[85] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[86] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[87] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[88] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[89] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[90] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[91] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[92] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[93] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[94] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[95] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[96] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[97] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[98] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[99] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[100] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[101] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[102] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[103] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[104] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[105] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[106] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[107] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[108] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[109] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[110] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[111] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[112] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[113] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[114] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[115] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[116] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[117] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[118] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[119] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[120] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[121] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[122] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[123] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[124] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[125] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[126] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[127] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[128] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[129] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[130] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[131] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[132] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[133] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[134] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[135] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[136] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[137] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[138] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[139] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[140] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[141] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[142] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[143] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[144] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[145] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[146] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[147] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[148] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[149] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[150] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[151] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[152] = {
		.pFrame = sOamFrame_5b7b30,
		.timer = 1
	},
	[153] = {
		.pFrame = sOamFrame_5b73ea,
		.timer = 1
	},
	[154] = {
		.pFrame = sOamFrame_5b7410,
		.timer = 4
	},
	[155] = {
		.pFrame = sOamFrame_5b7430,
		.timer = 4
	},
	[156] = {
		.pFrame = sOamFrame_5b7450,
		.timer = 4
	},
	[157] = {
		.pFrame = sOamFrame_5b7470,
		.timer = 4
	},
	[158] = {
		.pFrame = sOamFrame_5b7490,
		.timer = 4
	},
	[159] = {
		.pFrame = sOamFrame_5b74b0,
		.timer = 4
	},
	[160] = {
		.pFrame = sOamFrame_5b74d0,
		.timer = 4
	},
	[161] = {
		.pFrame = sOamFrame_5b74f0,
		.timer = 4
	},
	[162] = {
		.pFrame = sOamFrame_5b7510,
		.timer = 120
	},
	[163] = {
		.pFrame = sOamFrame_5b7530,
		.timer = 3
	},
	[164] = {
		.pFrame = sOamFrame_5b754a,
		.timer = 3
	},
	[165] = {
		.pFrame = sOamFrame_5b755e,
		.timer = 3
	},
	[166] = {
		.pFrame = sOamFrame_5b756c,
		.timer = 3
	},
	[167] = {
		.pFrame = sOamFrame_5b7574,
		.timer = 3
	},
	[168] = {
		.pFrame = sOamFrame_5b7582,
		.timer = 3
	},
	[169] = {
		.pFrame = sOamFrame_5b758a,
		.timer = 3
	},
	[170] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXLockOnOam_3[171] = {
	[0] = {
		.pFrame = sOamFrame_5b6eb8,
		.timer = 1
	},
	[1] = {
		.pFrame = sOamFrame_5b6ed2,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5b6eec,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5b6f06,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5b6f20,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5b6f3a,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5b6f54,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5b6f6e,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[9] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[10] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[11] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[12] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[13] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[14] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[15] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[16] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[17] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[18] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[19] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[20] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[21] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[22] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[23] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[24] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[25] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[26] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[27] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[28] = {
		.pFrame = sOamFrame_5b7b56,
		.timer = 1
	},
	[29] = {
		.pFrame = sOamFrame_5b7592,
		.timer = 1
	},
	[30] = {
		.pFrame = sOamFrame_5b7b64,
		.timer = 1
	},
	[31] = {
		.pFrame = sOamFrame_5b75a0,
		.timer = 1
	},
	[32] = {
		.pFrame = sOamFrame_5b7b78,
		.timer = 1
	},
	[33] = {
		.pFrame = sOamFrame_5b75b4,
		.timer = 1
	},
	[34] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[35] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[36] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[37] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[38] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[39] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[40] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[41] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[42] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[43] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[44] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[45] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[46] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[47] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[48] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[49] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[50] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[51] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[52] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[53] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[54] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[55] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[56] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[57] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[58] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[59] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[60] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[61] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[62] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[63] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[64] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[65] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[66] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[67] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[68] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[69] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[70] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[71] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[72] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[73] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[74] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[75] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[76] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[77] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[78] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[79] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[80] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[81] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[82] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[83] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[84] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[85] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[86] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[87] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[88] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[89] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[90] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[91] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[92] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[93] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[94] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[95] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[96] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[97] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[98] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[99] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[100] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[101] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[102] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[103] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[104] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[105] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[106] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[107] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[108] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[109] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[110] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[111] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[112] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[113] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[114] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[115] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[116] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[117] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[118] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[119] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[120] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[121] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[122] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[123] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[124] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[125] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[126] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[127] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[128] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[129] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[130] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[131] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[132] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[133] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[134] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[135] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[136] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[137] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[138] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[139] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[140] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[141] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[142] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[143] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[144] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[145] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[146] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[147] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[148] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[149] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[150] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[151] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[152] = {
		.pFrame = sOamFrame_5b7b92,
		.timer = 1
	},
	[153] = {
		.pFrame = sOamFrame_5b75ce,
		.timer = 1
	},
	[154] = {
		.pFrame = sOamFrame_5b75f4,
		.timer = 4
	},
	[155] = {
		.pFrame = sOamFrame_5b7614,
		.timer = 4
	},
	[156] = {
		.pFrame = sOamFrame_5b7634,
		.timer = 4
	},
	[157] = {
		.pFrame = sOamFrame_5b7654,
		.timer = 4
	},
	[158] = {
		.pFrame = sOamFrame_5b7674,
		.timer = 4
	},
	[159] = {
		.pFrame = sOamFrame_5b7694,
		.timer = 4
	},
	[160] = {
		.pFrame = sOamFrame_5b76b4,
		.timer = 4
	},
	[161] = {
		.pFrame = sOamFrame_5b76d4,
		.timer = 4
	},
	[162] = {
		.pFrame = sOamFrame_5b76f4,
		.timer = 120
	},
	[163] = {
		.pFrame = sOamFrame_5b7714,
		.timer = 3
	},
	[164] = {
		.pFrame = sOamFrame_5b772e,
		.timer = 3
	},
	[165] = {
		.pFrame = sOamFrame_5b7742,
		.timer = 3
	},
	[166] = {
		.pFrame = sOamFrame_5b7750,
		.timer = 3
	},
	[167] = {
		.pFrame = sOamFrame_5b7758,
		.timer = 3
	},
	[168] = {
		.pFrame = sOamFrame_5b7766,
		.timer = 3
	},
	[169] = {
		.pFrame = sOamFrame_5b776e,
		.timer = 3
	},
	[170] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXLockOnOam_4[171] = {
	[0] = {
		.pFrame = sOamFrame_5b6eb8,
		.timer = 1
	},
	[1] = {
		.pFrame = sOamFrame_5b6ed2,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5b6eec,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5b6f06,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5b6f20,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5b6f3a,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5b6f54,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5b6f6e,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[9] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[10] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[11] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[12] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[13] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[14] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[15] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[16] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[17] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[18] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[19] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[20] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[21] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[22] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[23] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[24] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[25] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[26] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[27] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[28] = {
		.pFrame = sOamFrame_5b7a1e,
		.timer = 1
	},
	[29] = {
		.pFrame = sOamFrame_5b6f98,
		.timer = 1
	},
	[30] = {
		.pFrame = sOamFrame_5b7a2c,
		.timer = 1
	},
	[31] = {
		.pFrame = sOamFrame_5b6fa6,
		.timer = 1
	},
	[32] = {
		.pFrame = sOamFrame_5b7a40,
		.timer = 1
	},
	[33] = {
		.pFrame = sOamFrame_5b6fba,
		.timer = 1
	},
	[34] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[35] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[36] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[37] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[38] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[39] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[40] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[41] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[42] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[43] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[44] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[45] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[46] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[47] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[48] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[49] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[50] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[51] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[52] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[53] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[54] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[55] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[56] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[57] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[58] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[59] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[60] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[61] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[62] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[63] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[64] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[65] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[66] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[67] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[68] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[69] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[70] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[71] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[72] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[73] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[74] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[75] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[76] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[77] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[78] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[79] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[80] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[81] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[82] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[83] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[84] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[85] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[86] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[87] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[88] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[89] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[90] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[91] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[92] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[93] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[94] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[95] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[96] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[97] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[98] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[99] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[100] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[101] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[102] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[103] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[104] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[105] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[106] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[107] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[108] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[109] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[110] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[111] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[112] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[113] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[114] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[115] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[116] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[117] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[118] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[119] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[120] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[121] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[122] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[123] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[124] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[125] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[126] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[127] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[128] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[129] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[130] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[131] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[132] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[133] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[134] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[135] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[136] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[137] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[138] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[139] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[140] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[141] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[142] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[143] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[144] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[145] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[146] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[147] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[148] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[149] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[150] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[151] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[152] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[153] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[154] = {
		.pFrame = sOamFrame_5b6ffa,
		.timer = 4
	},
	[155] = {
		.pFrame = sOamFrame_5b701a,
		.timer = 4
	},
	[156] = {
		.pFrame = sOamFrame_5b703a,
		.timer = 4
	},
	[157] = {
		.pFrame = sOamFrame_5b705a,
		.timer = 4
	},
	[158] = {
		.pFrame = sOamFrame_5b707a,
		.timer = 4
	},
	[159] = {
		.pFrame = sOamFrame_5b709a,
		.timer = 4
	},
	[160] = {
		.pFrame = sOamFrame_5b70ba,
		.timer = 4
	},
	[161] = {
		.pFrame = sOamFrame_5b70da,
		.timer = 4
	},
	[162] = {
		.pFrame = sOamFrame_5b70fa,
		.timer = 120
	},
	[163] = {
		.pFrame = sOamFrame_5b711a,
		.timer = 3
	},
	[164] = {
		.pFrame = sOamFrame_5b7134,
		.timer = 3
	},
	[165] = {
		.pFrame = sOamFrame_5b7148,
		.timer = 3
	},
	[166] = {
		.pFrame = sOamFrame_5b7156,
		.timer = 3
	},
	[167] = {
		.pFrame = sOamFrame_5b715e,
		.timer = 3
	},
	[168] = {
		.pFrame = sOamFrame_5b716c,
		.timer = 3
	},
	[169] = {
		.pFrame = sOamFrame_5b7174,
		.timer = 3
	},
	[170] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXLockOnOam_5[171] = {
	[0] = {
		.pFrame = sOamFrame_5b6eb8,
		.timer = 1
	},
	[1] = {
		.pFrame = sOamFrame_5b6ed2,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5b6eec,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5b6f06,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5b6f20,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5b6f3a,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5b6f54,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5b6f6e,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[9] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[10] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[11] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[12] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[13] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[14] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[15] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[16] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[17] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[18] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[19] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[20] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[21] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[22] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[23] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[24] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[25] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[26] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[27] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[28] = {
		.pFrame = sOamFrame_5b7bb8,
		.timer = 1
	},
	[29] = {
		.pFrame = sOamFrame_5b7776,
		.timer = 1
	},
	[30] = {
		.pFrame = sOamFrame_5b7bc6,
		.timer = 1
	},
	[31] = {
		.pFrame = sOamFrame_5b7784,
		.timer = 1
	},
	[32] = {
		.pFrame = sOamFrame_5b7be0,
		.timer = 1
	},
	[33] = {
		.pFrame = sOamFrame_5b779e,
		.timer = 1
	},
	[34] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[35] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[36] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[37] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[38] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[39] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[40] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[41] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[42] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[43] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[44] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[45] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[46] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[47] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[48] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[49] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[50] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[51] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[52] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[53] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[54] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[55] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[56] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[57] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[58] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[59] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[60] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[61] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[62] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[63] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[64] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[65] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[66] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[67] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[68] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[69] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[70] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[71] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[72] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[73] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[74] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[75] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[76] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[77] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[78] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[79] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[80] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[81] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[82] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[83] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[84] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[85] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[86] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[87] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[88] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[89] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[90] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[91] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[92] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[93] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[94] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[95] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[96] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[97] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[98] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[99] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[100] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[101] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[102] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[103] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[104] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[105] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[106] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[107] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[108] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[109] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[110] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[111] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[112] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[113] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[114] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[115] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[116] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[117] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[118] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[119] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[120] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[121] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[122] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[123] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[124] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[125] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[126] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[127] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[128] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[129] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[130] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[131] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[132] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[133] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[134] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[135] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[136] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[137] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[138] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[139] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[140] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[141] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[142] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[143] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[144] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[145] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[146] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[147] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[148] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[149] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[150] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[151] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[152] = {
		.pFrame = sOamFrame_5b7c00,
		.timer = 1
	},
	[153] = {
		.pFrame = sOamFrame_5b77be,
		.timer = 1
	},
	[154] = {
		.pFrame = sOamFrame_5b77ea,
		.timer = 4
	},
	[155] = {
		.pFrame = sOamFrame_5b7810,
		.timer = 4
	},
	[156] = {
		.pFrame = sOamFrame_5b7836,
		.timer = 4
	},
	[157] = {
		.pFrame = sOamFrame_5b785c,
		.timer = 4
	},
	[158] = {
		.pFrame = sOamFrame_5b7882,
		.timer = 4
	},
	[159] = {
		.pFrame = sOamFrame_5b78a8,
		.timer = 4
	},
	[160] = {
		.pFrame = sOamFrame_5b78ce,
		.timer = 4
	},
	[161] = {
		.pFrame = sOamFrame_5b78f4,
		.timer = 4
	},
	[162] = {
		.pFrame = sOamFrame_5b791a,
		.timer = 120
	},
	[163] = {
		.pFrame = sOamFrame_5b7940,
		.timer = 3
	},
	[164] = {
		.pFrame = sOamFrame_5b7960,
		.timer = 3
	},
	[165] = {
		.pFrame = sOamFrame_5b7974,
		.timer = 3
	},
	[166] = {
		.pFrame = sOamFrame_5b7982,
		.timer = 3
	},
	[167] = {
		.pFrame = sOamFrame_5b798a,
		.timer = 3
	},
	[168] = {
		.pFrame = sOamFrame_5b7998,
		.timer = 3
	},
	[169] = {
		.pFrame = sOamFrame_5b79a0,
		.timer = 3
	},
	[170] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXLockOnOam_6[171] = {
	[0] = {
		.pFrame = sOamFrame_5b6eb8,
		.timer = 1
	},
	[1] = {
		.pFrame = sOamFrame_5b6ed2,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5b6eec,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5b6f06,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5b6f20,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5b6f3a,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5b6f54,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5b6f6e,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[9] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[10] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[11] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[12] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[13] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[14] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[15] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[16] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[17] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[18] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[19] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[20] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[21] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[22] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[23] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[24] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[25] = {
		.pFrame = sOamFrame_5b7a16,
		.timer = 1
	},
	[26] = {
		.pFrame = sOamFrame_5b6f88,
		.timer = 1
	},
	[27] = {
		.pFrame = sOamFrame_5b6f90,
		.timer = 4
	},
	[28] = {
		.pFrame = sOamFrame_5b7a1e,
		.timer = 1
	},
	[29] = {
		.pFrame = sOamFrame_5b6f98,
		.timer = 1
	},
	[30] = {
		.pFrame = sOamFrame_5b7a2c,
		.timer = 1
	},
	[31] = {
		.pFrame = sOamFrame_5b6fa6,
		.timer = 1
	},
	[32] = {
		.pFrame = sOamFrame_5b7a40,
		.timer = 1
	},
	[33] = {
		.pFrame = sOamFrame_5b6fba,
		.timer = 1
	},
	[34] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[35] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[36] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[37] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[38] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[39] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[40] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[41] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[42] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[43] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[44] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[45] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[46] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[47] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[48] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[49] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[50] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[51] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[52] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[53] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[54] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[55] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[56] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[57] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[58] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[59] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[60] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[61] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[62] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[63] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[64] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[65] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[66] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[67] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[68] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[69] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[70] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[71] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[72] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[73] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[74] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[75] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[76] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[77] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[78] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[79] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[80] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[81] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[82] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[83] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[84] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[85] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[86] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[87] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[88] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[89] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[90] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[91] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[92] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[93] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[94] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[95] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[96] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[97] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[98] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[99] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[100] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[101] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[102] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[103] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[104] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[105] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[106] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[107] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[108] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[109] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[110] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[111] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[112] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[113] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[114] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[115] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[116] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[117] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[118] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[119] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[120] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[121] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[122] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[123] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[124] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[125] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[126] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[127] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[128] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[129] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[130] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[131] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[132] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[133] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[134] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[135] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[136] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[137] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[138] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[139] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[140] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[141] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[142] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[143] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[144] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[145] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[146] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[147] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[148] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[149] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[150] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[151] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[152] = {
		.pFrame = sOamFrame_5b7a5a,
		.timer = 1
	},
	[153] = {
		.pFrame = sOamFrame_5b6fd4,
		.timer = 1
	},
	[154] = {
		.pFrame = sOamFrame_5b6ffa,
		.timer = 4
	},
	[155] = {
		.pFrame = sOamFrame_5b701a,
		.timer = 4
	},
	[156] = {
		.pFrame = sOamFrame_5b703a,
		.timer = 4
	},
	[157] = {
		.pFrame = sOamFrame_5b705a,
		.timer = 4
	},
	[158] = {
		.pFrame = sOamFrame_5b707a,
		.timer = 4
	},
	[159] = {
		.pFrame = sOamFrame_5b709a,
		.timer = 4
	},
	[160] = {
		.pFrame = sOamFrame_5b70ba,
		.timer = 4
	},
	[161] = {
		.pFrame = sOamFrame_5b70da,
		.timer = 4
	},
	[162] = {
		.pFrame = sOamFrame_5b70fa,
		.timer = 120
	},
	[163] = {
		.pFrame = sOamFrame_5b711a,
		.timer = 3
	},
	[164] = {
		.pFrame = sOamFrame_5b7134,
		.timer = 3
	},
	[165] = {
		.pFrame = sOamFrame_5b7148,
		.timer = 3
	},
	[166] = {
		.pFrame = sOamFrame_5b7156,
		.timer = 3
	},
	[167] = {
		.pFrame = sOamFrame_5b715e,
		.timer = 3
	},
	[168] = {
		.pFrame = sOamFrame_5b716c,
		.timer = 3
	},
	[169] = {
		.pFrame = sOamFrame_5b7174,
		.timer = 3
	},
	[170] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemCountdownOam_Fast[11] = {
	[0] = {
		.pFrame = sOamFrame_5b79f0,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5b79e8,
		.timer = 8
	},
	[2] = {
		.pFrame = sOamFrame_5b79e0,
		.timer = 8
	},
	[3] = {
		.pFrame = sOamFrame_5b79d8,
		.timer = 8
	},
	[4] = {
		.pFrame = sOamFrame_5b79d0,
		.timer = 8
	},
	[5] = {
		.pFrame = sOamFrame_5b79c8,
		.timer = 8
	},
	[6] = {
		.pFrame = sOamFrame_5b79c0,
		.timer = 8
	},
	[7] = {
		.pFrame = sOamFrame_5b79b8,
		.timer = 8
	},
	[8] = {
		.pFrame = sOamFrame_5b79b0,
		.timer = 8
	},
	[9] = {
		.pFrame = sOamFrame_5b79a8,
		.timer = 8
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemCountdownOam_Slow[11] = {
	[0] = {
		.pFrame = sOamFrame_5b79f0,
		.timer = 80
	},
	[1] = {
		.pFrame = sOamFrame_5b79e8,
		.timer = 80
	},
	[2] = {
		.pFrame = sOamFrame_5b79e0,
		.timer = 80
	},
	[3] = {
		.pFrame = sOamFrame_5b79d8,
		.timer = 80
	},
	[4] = {
		.pFrame = sOamFrame_5b79d0,
		.timer = 80
	},
	[5] = {
		.pFrame = sOamFrame_5b79c8,
		.timer = 80
	},
	[6] = {
		.pFrame = sOamFrame_5b79c0,
		.timer = 80
	},
	[7] = {
		.pFrame = sOamFrame_5b79b8,
		.timer = 80
	},
	[8] = {
		.pFrame = sOamFrame_5b79b0,
		.timer = 80
	},
	[9] = {
		.pFrame = sOamFrame_5b79a8,
		.timer = 80
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemNumber281Oam[2] = {
	[0] = {
		.pFrame = sOamFrame_5b79f8,
		.timer = 255
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemCornerTextOam[3] = {
	[0] = {
		.pFrame = sOamFrame_5b7a00,
		.timer = 40
	},
	[1] = {
		.pFrame = sOamFrame_5b7a0e,
		.timer = 30
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemNervePartsOam[2] = {
	[0] = {
		.pFrame = sOamFrame_5b6c7c,
		.timer = 255
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXParasiteOam_1[17] = {
	[0] = {
		.pFrame = sOamFrame_5b6d38,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5b6d40,
		.timer = 3
	},
	[2] = {
		.pFrame = sOamFrame_5b6d48,
		.timer = 3
	},
	[3] = {
		.pFrame = sOamFrame_5b6d50,
		.timer = 3
	},
	[4] = {
		.pFrame = sOamFrame_5b6d58,
		.timer = 3
	},
	[5] = {
		.pFrame = sOamFrame_5b6d60,
		.timer = 3
	},
	[6] = {
		.pFrame = sOamFrame_5b6d68,
		.timer = 3
	},
	[7] = {
		.pFrame = sOamFrame_5b6d70,
		.timer = 3
	},
	[8] = {
		.pFrame = sOamFrame_5b6d78,
		.timer = 3
	},
	[9] = {
		.pFrame = sOamFrame_5b6d80,
		.timer = 3
	},
	[10] = {
		.pFrame = sOamFrame_5b6d88,
		.timer = 3
	},
	[11] = {
		.pFrame = sOamFrame_5b6d90,
		.timer = 3
	},
	[12] = {
		.pFrame = sOamFrame_5b6d98,
		.timer = 3
	},
	[13] = {
		.pFrame = sOamFrame_5b6da0,
		.timer = 3
	},
	[14] = {
		.pFrame = sOamFrame_5b6da8,
		.timer = 3
	},
	[15] = {
		.pFrame = sOamFrame_5b6db0,
		.timer = 3
	},
	[16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXParasiteOam_2[17] = {
	[0] = {
		.pFrame = sOamFrame_5b6d98,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5b6da0,
		.timer = 3
	},
	[2] = {
		.pFrame = sOamFrame_5b6da8,
		.timer = 3
	},
	[3] = {
		.pFrame = sOamFrame_5b6db0,
		.timer = 3
	},
	[4] = {
		.pFrame = sOamFrame_5b6d38,
		.timer = 3
	},
	[5] = {
		.pFrame = sOamFrame_5b6d40,
		.timer = 3
	},
	[6] = {
		.pFrame = sOamFrame_5b6d48,
		.timer = 3
	},
	[7] = {
		.pFrame = sOamFrame_5b6d50,
		.timer = 3
	},
	[8] = {
		.pFrame = sOamFrame_5b6d58,
		.timer = 3
	},
	[9] = {
		.pFrame = sOamFrame_5b6d60,
		.timer = 3
	},
	[10] = {
		.pFrame = sOamFrame_5b6d68,
		.timer = 3
	},
	[11] = {
		.pFrame = sOamFrame_5b6d70,
		.timer = 3
	},
	[12] = {
		.pFrame = sOamFrame_5b6d78,
		.timer = 3
	},
	[13] = {
		.pFrame = sOamFrame_5b6d80,
		.timer = 3
	},
	[14] = {
		.pFrame = sOamFrame_5b6d88,
		.timer = 3
	},
	[15] = {
		.pFrame = sOamFrame_5b6d90,
		.timer = 3
	},
	[16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXParasiteOam_3[17] = {
	[0] = {
		.pFrame = sOamFrame_5b6df0,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5b6df8,
		.timer = 3
	},
	[2] = {
		.pFrame = sOamFrame_5b6e00,
		.timer = 3
	},
	[3] = {
		.pFrame = sOamFrame_5b6e08,
		.timer = 3
	},
	[4] = {
		.pFrame = sOamFrame_5b6e10,
		.timer = 3
	},
	[5] = {
		.pFrame = sOamFrame_5b6e18,
		.timer = 3
	},
	[6] = {
		.pFrame = sOamFrame_5b6e20,
		.timer = 3
	},
	[7] = {
		.pFrame = sOamFrame_5b6e28,
		.timer = 3
	},
	[8] = {
		.pFrame = sOamFrame_5b6e30,
		.timer = 3
	},
	[9] = {
		.pFrame = sOamFrame_5b6db8,
		.timer = 3
	},
	[10] = {
		.pFrame = sOamFrame_5b6dc0,
		.timer = 3
	},
	[11] = {
		.pFrame = sOamFrame_5b6dc8,
		.timer = 3
	},
	[12] = {
		.pFrame = sOamFrame_5b6dd0,
		.timer = 3
	},
	[13] = {
		.pFrame = sOamFrame_5b6dd8,
		.timer = 3
	},
	[14] = {
		.pFrame = sOamFrame_5b6de0,
		.timer = 3
	},
	[15] = {
		.pFrame = sOamFrame_5b6de8,
		.timer = 3
	},
	[16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXParasiteOam_4[17] = {
	[0] = {
		.pFrame = sOamFrame_5b6d68,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5b6d70,
		.timer = 3
	},
	[2] = {
		.pFrame = sOamFrame_5b6d78,
		.timer = 3
	},
	[3] = {
		.pFrame = sOamFrame_5b6d80,
		.timer = 3
	},
	[4] = {
		.pFrame = sOamFrame_5b6d88,
		.timer = 3
	},
	[5] = {
		.pFrame = sOamFrame_5b6d90,
		.timer = 3
	},
	[6] = {
		.pFrame = sOamFrame_5b6d98,
		.timer = 3
	},
	[7] = {
		.pFrame = sOamFrame_5b6da0,
		.timer = 3
	},
	[8] = {
		.pFrame = sOamFrame_5b6da8,
		.timer = 3
	},
	[9] = {
		.pFrame = sOamFrame_5b6db0,
		.timer = 3
	},
	[10] = {
		.pFrame = sOamFrame_5b6d38,
		.timer = 3
	},
	[11] = {
		.pFrame = sOamFrame_5b6d40,
		.timer = 3
	},
	[12] = {
		.pFrame = sOamFrame_5b6d48,
		.timer = 3
	},
	[13] = {
		.pFrame = sOamFrame_5b6d50,
		.timer = 3
	},
	[14] = {
		.pFrame = sOamFrame_5b6d58,
		.timer = 3
	},
	[15] = {
		.pFrame = sOamFrame_5b6d60,
		.timer = 3
	},
	[16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXParasiteOam_5[17] = {
	[0] = {
		.pFrame = sOamFrame_5b6e50,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5b6e58,
		.timer = 3
	},
	[2] = {
		.pFrame = sOamFrame_5b6e60,
		.timer = 3
	},
	[3] = {
		.pFrame = sOamFrame_5b6e68,
		.timer = 3
	},
	[4] = {
		.pFrame = sOamFrame_5b6e70,
		.timer = 3
	},
	[5] = {
		.pFrame = sOamFrame_5b6e78,
		.timer = 3
	},
	[6] = {
		.pFrame = sOamFrame_5b6e80,
		.timer = 3
	},
	[7] = {
		.pFrame = sOamFrame_5b6e88,
		.timer = 3
	},
	[8] = {
		.pFrame = sOamFrame_5b6e90,
		.timer = 3
	},
	[9] = {
		.pFrame = sOamFrame_5b6e98,
		.timer = 3
	},
	[10] = {
		.pFrame = sOamFrame_5b6ea0,
		.timer = 3
	},
	[11] = {
		.pFrame = sOamFrame_5b6ea8,
		.timer = 3
	},
	[12] = {
		.pFrame = sOamFrame_5b6eb0,
		.timer = 3
	},
	[13] = {
		.pFrame = sOamFrame_5b6e38,
		.timer = 3
	},
	[14] = {
		.pFrame = sOamFrame_5b6e40,
		.timer = 3
	},
	[15] = {
		.pFrame = sOamFrame_5b6e48,
		.timer = 3
	},
	[16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIntroSamusNervousSystemXParasiteOam_6[17] = {
	[0] = {
		.pFrame = sOamFrame_5b6e10,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5b6e18,
		.timer = 3
	},
	[2] = {
		.pFrame = sOamFrame_5b6e20,
		.timer = 3
	},
	[3] = {
		.pFrame = sOamFrame_5b6e28,
		.timer = 3
	},
	[4] = {
		.pFrame = sOamFrame_5b6e30,
		.timer = 3
	},
	[5] = {
		.pFrame = sOamFrame_5b6db8,
		.timer = 3
	},
	[6] = {
		.pFrame = sOamFrame_5b6dc0,
		.timer = 3
	},
	[7] = {
		.pFrame = sOamFrame_5b6dc8,
		.timer = 3
	},
	[8] = {
		.pFrame = sOamFrame_5b6dd0,
		.timer = 3
	},
	[9] = {
		.pFrame = sOamFrame_5b6dd8,
		.timer = 3
	},
	[10] = {
		.pFrame = sOamFrame_5b6de0,
		.timer = 3
	},
	[11] = {
		.pFrame = sOamFrame_5b6de8,
		.timer = 3
	},
	[12] = {
		.pFrame = sOamFrame_5b6df0,
		.timer = 3
	},
	[13] = {
		.pFrame = sOamFrame_5b6df8,
		.timer = 3
	},
	[14] = {
		.pFrame = sOamFrame_5b6e00,
		.timer = 3
	},
	[15] = {
		.pFrame = sOamFrame_5b6e08,
		.timer = 3
	},
	[16] = FRAME_DATA_TERMINATOR
};

const u16 sIntroSamusNervousSystemObjPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/samus_nervous_system_obj.pal");

const u32 sIntroSamusNervousSystemBgGfx[4869] = INCBIN_U32("data/new_file_intro/samus_nervous_system_bg.gfx.lz");

const u16 sIntroSamusNervousSystemBgPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/samus_nervous_system_bg.pal");

const u32 sIntroSamusNervousSystemBg3Tilemap[369] = INCBIN_U32("data/new_file_intro/samus_nervous_system_bg3.tm.lz");
const u32 sIntroSamusNervousSystemBg2Tilemap[63] = INCBIN_U32("data/new_file_intro/samus_nervous_system_bg2.tm.lz");
const u32 sIntroSamusNervousSystemBg1Tilemap[68] = INCBIN_U32("data/new_file_intro/samus_nervous_system_bg1.tm.lz");

const u16 sPal_5bf838[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bf838.pal");
const u16 sPal_5bf8b8[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bf8b8.pal");
const u16 sPal_5bf938[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bf938.pal");
const u16 sPal_5bf9b8[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bf9b8.pal");
const u16 sPal_5bfa38[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bfa38.pal");
const u16 sPal_5bfab8[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bfab8.pal");
const u16 sPal_5bfb38[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bfb38.pal");
const u16 sPal_5bfbb8[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bfbb8.pal");
const u16 sPal_5bfc38[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bfc38.pal");
const u16 sPal_5bfcb8[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bfcb8.pal");
const u16 sPal_5bfd38[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bfd38.pal");
const u16 sPal_5bfdb8[4 * PAL_ROW] = INCBIN_U16("data/new_file_intro/5bfdb8.pal");

const u32 sIntroVariaSuitCoveredInXParasitesGfx[4230] = INCBIN_U32("data/new_file_intro/suit_covered_in_parasites.gfx.lz");
const u32 sIntroHazmatTeamGfx[4915] = INCBIN_U32("data/new_file_intro/hazmat_team.gfx.lz");

const u16 sIntroSamusFoundPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/samus_found.pal");

const u32 sIntroVariaSuitCoveredInXParasitesTilemap[385] = INCBIN_U32("data/new_file_intro/suit_covered_in_parasites.tm.lz");
const u32 sIntroHazmatTeamTilemap[395] = INCBIN_U32("data/new_file_intro/hazmat_team.tm.lz");

const u32 sIntroSuitRemovalSurgeryGfx[7003] = INCBIN_U32("data/new_file_intro/suit_removal_surgery.gfx.lz");
const u32 sIntroSuitRemovalSurgeryTilemap[551] = INCBIN_U32("data/new_file_intro/suit_removal_surgery.tm.lz");

const u32 sIntroMetroidVaccineVialGfx[3525] = INCBIN_U32("data/new_file_intro/metroid_vaccine_vial.gfx.lz");
const u32 sIntroMetroidVaccineVialTilemap[385] = INCBIN_U32("data/new_file_intro/metroid_vaccine_vial.tm.lz");

const u32 sIntroSamusRebornBgTopGfx[6616] = INCBIN_U32("data/new_file_intro/samus_reborn_bg_top.gfx.lz");
const u32 sIntroSamusRebornBgBottomGfx[3537] = INCBIN_U32("data/new_file_intro/samus_reborn_bg_bottom.gfx.lz");
const u16 sIntroSamusRebornBgPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/samus_reborn_bg.pal");
const u32 sIntroSamusRebornBgTopTilemap[551] = INCBIN_U32("data/new_file_intro/samus_reborn_bg_top.tm.lz");
const u32 sIntroSamusRebornBgBottomTilemap[368] = INCBIN_U32("data/new_file_intro/samus_reborn_bg_bottom.tm.lz");

static const u8 sBlob_5dfd6c_5e116c[] = INCBIN_U8("data/Blob_5dfd6c_5e116c.bin");

const u32 sIntroApproachingBslObjGfx[3614] = INCBIN_U32("data/new_file_intro/approaching_bsl_obj.gfx.lz");

static const u8 sBlob_5e49e4_5edf70[] = INCBIN_U8("data/Blob_5e49e4_5edf70.bin");

const u32 sIntroSamusMonologueBgGfx[3282] = INCBIN_U32("data/new_file_intro/samus_monologue_bg.gfx.lz");

static const u8 sBlob_5f12b8_5f2610[] = INCBIN_U8("data/Blob_5f12b8_5f2610.bin");

static const u16 sOamFrame_5f2610[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 705, 9, 0),
	OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 711, 9, 0),
	OAM_ENTRY(-8, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 640, 9, 0),
	OAM_ENTRY(0, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 9, 0),
};

static const u16 sOamFrame_5f262a[OAM_DATA_SIZE(4)] = {
	4,
	OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 705, 9, 0),
	OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 710, 9, 0),
	OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 640, 9, 0),
	OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 520, 9, 0),
};

static const u16 sOamFrame_5f2644[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-32, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 705, 9, 0),
	OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 736, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 710, 9, 0),
	OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 708, 9, 0),
	OAM_ENTRY(-32, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 9, 0),
	OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 646, 9, 0),
	OAM_ENTRY(16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 520, 9, 0),
};

static const u16 sOamFrame_5f2670[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-40, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 705, 9, 0),
	OAM_ENTRY(8, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 708, 9, 0),
	OAM_ENTRY(-24, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 736, 9, 0),
	OAM_ENTRY(-40, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 9, 0),
	OAM_ENTRY(-8, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 644, 9, 0),
	OAM_ENTRY(24, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 520, 9, 0),
};

static const u16 sOamFrame_5f2696[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 9, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 644, 9, 0),
	OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 520, 9, 0),
	OAM_ENTRY(-40, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 705, 9, 0),
	OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 708, 9, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 736, 9, 0),
};

static const u16 sOamFrame_5f26bc[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-40, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 9, 0),
	OAM_ENTRY(-8, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 644, 9, 0),
	OAM_ENTRY(-40, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 672, 9, 0),
	OAM_ENTRY(-40, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 673, 9, 0),
	OAM_ENTRY(8, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 676, 9, 0),
	OAM_ENTRY(-24, 10, OAM_DIMS_32x8, OAM_NO_FLIP, 736, 9, 0),
	OAM_ENTRY(24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 520, 9, 0),
	OAM_ENTRY(32, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 649, 9, 0),
	OAM_ENTRY(-40, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 675, 9, 0),
	OAM_ENTRY(-40, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 675, 9, 0),
	OAM_ENTRY(24, 10, OAM_DIMS_16x8, OAM_NO_FLIP, 648, 9, 0),
};

static const u16 sOamFrame_5f2700[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-40, -22, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 9, 0),
	OAM_ENTRY(-8, -22, OAM_DIMS_32x8, OAM_NO_FLIP, 644, 9, 0),
	OAM_ENTRY(-40, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 672, 9, 0),
	OAM_ENTRY(-40, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 673, 9, 0),
	OAM_ENTRY(8, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 676, 9, 0),
	OAM_ENTRY(-24, 14, OAM_DIMS_32x8, OAM_NO_FLIP, 736, 9, 0),
	OAM_ENTRY(24, -22, OAM_DIMS_16x32, OAM_NO_FLIP, 520, 9, 0),
	OAM_ENTRY(32, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 649, 9, 0),
	OAM_ENTRY(-40, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 675, 9, 0),
	OAM_ENTRY(-40, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 675, 9, 0),
	OAM_ENTRY(24, 10, OAM_DIMS_16x8, OAM_NO_FLIP, 648, 9, 0),
};

static const u16 sOamFrame_5f2744[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(-40, -28, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 9, 0),
	OAM_ENTRY(-8, -28, OAM_DIMS_32x8, OAM_NO_FLIP, 644, 9, 0),
	OAM_ENTRY(-40, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 672, 9, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 673, 9, 0),
	OAM_ENTRY(8, 12, OAM_DIMS_32x16, OAM_NO_FLIP, 676, 9, 0),
	OAM_ENTRY(-24, 20, OAM_DIMS_32x8, OAM_NO_FLIP, 736, 9, 0),
	OAM_ENTRY(24, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 520, 9, 0),
	OAM_ENTRY(32, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 649, 9, 0),
	OAM_ENTRY(-40, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 675, 9, 0),
	OAM_ENTRY(-40, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 675, 9, 0),
	OAM_ENTRY(24, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 648, 9, 0),
	OAM_ENTRY(-32, -20, OAM_DIMS_64x32, OAM_NO_FLIP, 536, 1, 0),
	OAM_ENTRY(-32, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 664, 1, 0),
	OAM_ENTRY(0, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 668, 1, 0),
};

static const u16 sOamFrame_5f279a[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(-40, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 9, 0),
	OAM_ENTRY(-8, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 644, 9, 0),
	OAM_ENTRY(-40, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 672, 9, 0),
	OAM_ENTRY(-40, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 673, 9, 0),
	OAM_ENTRY(8, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 676, 9, 0),
	OAM_ENTRY(-24, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 736, 9, 0),
	OAM_ENTRY(24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 520, 9, 0),
	OAM_ENTRY(32, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 649, 9, 0),
	OAM_ENTRY(-40, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 675, 9, 0),
	OAM_ENTRY(-40, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 675, 9, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 536, 1, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 664, 1, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 668, 1, 0),
	OAM_ENTRY(24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 648, 9, 0),
};

static const u16 sOamFrame_5f27f0[OAM_DATA_SIZE(9)] = {
	9,
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(-88, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(-88, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(-104, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-88, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(-88, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
};

static const u16 sOamFrame_5f2828[OAM_DATA_SIZE(12)] = {
	12,
	OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 741, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(-64, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(-64, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(-80, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f2872[OAM_DATA_SIZE(12)] = {
	12,
	OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 742, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(-48, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(-48, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(-48, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f28bc[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 743, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(-24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(-40, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f2912[OAM_DATA_SIZE(13)] = {
	13,
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(-16, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(-16, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f2962[OAM_DATA_SIZE(17)] = {
	17,
	OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 741, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(0, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(-16, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f29ca[OAM_DATA_SIZE(17)] = {
	17,
	OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 742, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(16, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(16, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f2a32[OAM_DATA_SIZE(19)] = {
	19,
	OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 743, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(32, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(32, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(32, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(16, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(16, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f2aa6[OAM_DATA_SIZE(18)] = {
	18,
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(48, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(48, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(48, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(32, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f2b14[OAM_DATA_SIZE(20)] = {
	20,
	OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 741, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(64, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(64, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(64, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(48, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f2b8e[OAM_DATA_SIZE(20)] = {
	20,
	OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 742, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(80, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(80, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(80, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(80, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(64, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f2c08[OAM_DATA_SIZE(22)] = {
	22,
	OAM_ENTRY(-126, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 743, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
	OAM_ENTRY(-128, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
	OAM_ENTRY(-128, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 714, 8, 0),
	OAM_ENTRY(96, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 592, 8, 0),
	OAM_ENTRY(96, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 656, 8, 0),
	OAM_ENTRY(96, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 688, 8, 0),
	OAM_ENTRY(96, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 752, 8, 0),
	OAM_ENTRY(80, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 750, 8, 0),
	OAM_ENTRY(-96, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 590, 8, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 652, 8, 0),
	OAM_ENTRY(-96, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(0, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
	OAM_ENTRY(64, 24, OAM_DIMS_32x8, OAM_Y_FLIP, 652, 8, 0),
};

static const u16 sOamFrame_5f2c8e[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(-106, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 462, 3, 0),
	OAM_ENTRY(-115, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 464, 3, 0),
	OAM_ENTRY(-112, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-84, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f2cb4[OAM_DATA_SIZE(10)] = {
	10,
	OAM_ENTRY(-113, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 3, 0),
	OAM_ENTRY(-93, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 420, 3, 0),
	OAM_ENTRY(-109, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 494, 3, 0),
	OAM_ENTRY(-102, 0, OAM_DIMS_16x8, OAM_X_FLIP, 494, 3, 0),
	OAM_ENTRY(-110, 12, OAM_DIMS_32x8, OAM_X_FLIP, 496, 3, 0),
	OAM_ENTRY(-118, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 496, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-88, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-60, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f2cf2[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-114, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 392, 3, 0),
	OAM_ENTRY(-90, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 396, 3, 0),
	OAM_ENTRY(-76, 4, OAM_DIMS_32x8, OAM_X_FLIP, 392, 3, 0),
	OAM_ENTRY(-120, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 500, 3, 0),
	OAM_ENTRY(-105, 12, OAM_DIMS_32x8, OAM_X_FLIP, 500, 3, 0),
	OAM_ENTRY(-111, 1, OAM_DIMS_32x8, OAM_NO_FLIP, 468, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-44, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f2d36[OAM_DATA_SIZE(9)] = {
	9,
	OAM_ENTRY(-115, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 424, 3, 0),
	OAM_ENTRY(-59, 4, OAM_DIMS_32x8, OAM_X_FLIP, 424, 3, 0),
	OAM_ENTRY(-90, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 428, 3, 0),
	OAM_ENTRY(-73, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 428, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-88, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-56, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-28, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f2d6e[OAM_DATA_SIZE(16)] = {
	16,
	OAM_ENTRY(-116, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 3, 0),
	OAM_ENTRY(-116, 6, OAM_DIMS_32x8, OAM_Y_FLIP, 384, 3, 0),
	OAM_ENTRY(-42, 2, OAM_DIMS_32x8, OAM_X_FLIP, 384, 3, 0),
	OAM_ENTRY(-42, 6, OAM_DIMS_32x8, OAM_XY_FLIP, 384, 3, 0),
	OAM_ENTRY(-96, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-64, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-96, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-64, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-96, 6, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-64, 6, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-12, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f2dd0[OAM_DATA_SIZE(16)] = {
	16,
	OAM_ENTRY(-117, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 3, 0),
	OAM_ENTRY(-117, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 384, 3, 0),
	OAM_ENTRY(-25, 0, OAM_DIMS_32x8, OAM_X_FLIP, 384, 3, 0),
	OAM_ENTRY(-25, 8, OAM_DIMS_32x8, OAM_XY_FLIP, 384, 3, 0),
	OAM_ENTRY(-52, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-52, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-90, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-90, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-72, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-72, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-88, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-56, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(4, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f2e32[OAM_DATA_SIZE(17)] = {
	17,
	OAM_ENTRY(-118, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 384, 3, 0),
	OAM_ENTRY(-118, 2, OAM_DIMS_32x16, OAM_Y_FLIP, 384, 3, 0),
	OAM_ENTRY(-8, -2, OAM_DIMS_32x16, OAM_X_FLIP, 384, 3, 0),
	OAM_ENTRY(-8, 2, OAM_DIMS_32x16, OAM_XY_FLIP, 384, 3, 0),
	OAM_ENTRY(-90, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-90, 10, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, 10, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-32, 10, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-32, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(20, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f2e9a[OAM_DATA_SIZE(19)] = {
	19,
	OAM_ENTRY(-119, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 384, 3, 0),
	OAM_ENTRY(-119, 4, OAM_DIMS_32x16, OAM_Y_FLIP, 384, 3, 0),
	OAM_ENTRY(9, -4, OAM_DIMS_32x16, OAM_X_FLIP, 384, 3, 0),
	OAM_ENTRY(9, 4, OAM_DIMS_32x16, OAM_XY_FLIP, 384, 3, 0),
	OAM_ENTRY(-90, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-26, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-90, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-26, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-88, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-56, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(36, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f2f0e[OAM_DATA_SIZE(20)] = {
	20,
	OAM_ENTRY(-120, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 384, 3, 0),
	OAM_ENTRY(-120, 6, OAM_DIMS_32x16, OAM_Y_FLIP, 384, 3, 0),
	OAM_ENTRY(26, -6, OAM_DIMS_32x16, OAM_X_FLIP, 384, 3, 0),
	OAM_ENTRY(26, 6, OAM_DIMS_32x16, OAM_XY_FLIP, 384, 3, 0),
	OAM_ENTRY(-90, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-26, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(0, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-90, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-26, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(0, 14, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(24, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(52, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f2f88[OAM_DATA_SIZE(22)] = {
	22,
	OAM_ENTRY(-121, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 384, 3, 0),
	OAM_ENTRY(-121, 7, OAM_DIMS_32x16, OAM_Y_FLIP, 384, 3, 0),
	OAM_ENTRY(43, -7, OAM_DIMS_32x16, OAM_X_FLIP, 384, 3, 0),
	OAM_ENTRY(43, 7, OAM_DIMS_32x16, OAM_XY_FLIP, 384, 3, 0),
	OAM_ENTRY(-90, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-26, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(6, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-90, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-26, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(6, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(24, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(24, 15, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-88, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-56, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(68, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f300e[OAM_DATA_SIZE(23)] = {
	23,
	OAM_ENTRY(-122, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 384, 3, 0),
	OAM_ENTRY(-122, 8, OAM_DIMS_32x16, OAM_Y_FLIP, 384, 3, 0),
	OAM_ENTRY(60, -8, OAM_DIMS_32x16, OAM_X_FLIP, 384, 3, 0),
	OAM_ENTRY(60, 8, OAM_DIMS_32x16, OAM_XY_FLIP, 384, 3, 0),
	OAM_ENTRY(-90, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-26, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(6, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(-90, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-58, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-26, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(6, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(32, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 3, 0),
	OAM_ENTRY(32, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 388, 3, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(24, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(56, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-96, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(84, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f309a[OAM_DATA_SIZE(9)] = {
	9,
	OAM_ENTRY(-120, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-88, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-56, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(40, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(72, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-122, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(100, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f30d2[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
	OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
	OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 594, 8, 0),
};

static const u16 sOamFrame_5f30e6[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 662, 8, 0),
	OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
	OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 596, 8, 0),
};

static const u16 sOamFrame_5f30fa[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 694, 8, 0),
	OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
	OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 598, 8, 0),
};

static const u16 sOamFrame_5f310e[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 622, 8, 0),
	OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 626, 8, 0),
	OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 690, 8, 0),
};

static const u16 sOamFrame_5f3122[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 628, 8, 0),
	OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 692, 8, 0),
};

static const u16 sOamFrame_5f3130[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 552, 9, 0),
};

static const u16 sOamFrame_5f3138[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 772, 8, 0),
};

static const u16 sOamFrame_5f3140[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 771, 8, 0),
};

static const u16 sOamFrame_5f3148[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
};

static const u16 sOamFrame_5f3150[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
};

static const u16 sOamFrame_5f3164[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-80, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
};

static const u16 sOamFrame_5f3184[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-80, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(80, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-112, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
};

static const u16 sOamFrame_5f31b0[OAM_DATA_SIZE(18)] = {
	18,
	OAM_ENTRY(-80, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-48, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-16, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(16, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(48, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(72, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-120, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 8, 0),
	OAM_ENTRY(-112, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(104, -12, OAM_DIMS_16x16, OAM_X_FLIP, 768, 8, 0),
	OAM_ENTRY(-80, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(-48, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(-16, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(16, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(48, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(72, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(-120, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 768, 8, 0),
	OAM_ENTRY(-112, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(104, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 768, 8, 0),
};

static const u16 sOamFrame_5f321e[OAM_DATA_SIZE(18)] = {
	18,
	OAM_ENTRY(-80, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(48, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(72, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-120, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 8, 0),
	OAM_ENTRY(-112, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(104, -16, OAM_DIMS_16x16, OAM_X_FLIP, 768, 8, 0),
	OAM_ENTRY(-80, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(-48, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(16, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(48, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(72, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(-120, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 768, 8, 0),
	OAM_ENTRY(-112, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(104, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 768, 8, 0),
};

static const u16 sOamFrame_5f328c[OAM_DATA_SIZE(20)] = {
	20,
	OAM_ENTRY(-80, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(-48, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(-16, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(16, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(48, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(72, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(-120, 4, OAM_DIMS_16x16, OAM_Y_FLIP, 768, 8, 0),
	OAM_ENTRY(-112, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 8, 0),
	OAM_ENTRY(104, 4, OAM_DIMS_16x16, OAM_XY_FLIP, 768, 8, 0),
	OAM_ENTRY(-80, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-48, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-16, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(16, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(48, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(72, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-120, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 8, 0),
	OAM_ENTRY(-112, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(104, -20, OAM_DIMS_16x16, OAM_X_FLIP, 768, 8, 0),
	OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 735, 8, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 735, 8, 0),
};

static const u16 sOamFrame_5f3306[OAM_DATA_SIZE(20)] = {
	20,
	OAM_ENTRY(-72, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 9, 0),
	OAM_ENTRY(-40, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 9, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 9, 0),
	OAM_ENTRY(24, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 9, 0),
	OAM_ENTRY(56, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 9, 0),
	OAM_ENTRY(-72, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 9, 0),
	OAM_ENTRY(-40, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 9, 0),
	OAM_ENTRY(-8, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 9, 0),
	OAM_ENTRY(24, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 9, 0),
	OAM_ENTRY(56, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 9, 0),
	OAM_ENTRY(72, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 9, 0),
	OAM_ENTRY(72, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 9, 0),
	OAM_ENTRY(-120, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 9, 0),
	OAM_ENTRY(-104, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 9, 0),
	OAM_ENTRY(-120, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 768, 9, 0),
	OAM_ENTRY(-104, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 769, 9, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 735, 9, 0),
	OAM_ENTRY(104, -24, OAM_DIMS_16x16, OAM_X_FLIP, 768, 9, 0),
	OAM_ENTRY(104, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 768, 9, 0),
	OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 735, 9, 0),
};

static const u16 sOamFrame_5f3380[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 778, 9, 0),
};

static const u16 sOamFrame_5f3388[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 777, 9, 0),
};

static const u16 sOamFrame_5f3390[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 777, 9, 0),
	OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 777, 9, 0),
};

static const u16 sOamFrame_5f339e[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
};

static const u16 sOamFrame_5f33b2[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
};

static const u16 sOamFrame_5f33d2[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
};

static const u16 sOamFrame_5f33fe[OAM_DATA_SIZE(18)] = {
	18,
	OAM_ENTRY(-120, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 774, 9, 0),
	OAM_ENTRY(-104, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-72, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(104, -12, OAM_DIMS_16x16, OAM_X_FLIP, 774, 9, 0),
	OAM_ENTRY(72, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-40, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(56, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-120, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 774, 9, 0),
	OAM_ENTRY(-104, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-72, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(104, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 774, 9, 0),
	OAM_ENTRY(72, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-40, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-8, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(24, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(56, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
};

static const u16 sOamFrame_5f346c[OAM_DATA_SIZE(18)] = {
	18,
	OAM_ENTRY(-120, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 774, 9, 0),
	OAM_ENTRY(-104, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-72, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(104, -16, OAM_DIMS_16x16, OAM_X_FLIP, 774, 9, 0),
	OAM_ENTRY(72, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-40, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-8, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(24, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(56, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-120, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 774, 9, 0),
	OAM_ENTRY(-104, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-72, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(104, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 774, 9, 0),
	OAM_ENTRY(72, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-40, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-8, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(24, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(56, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
};

static const u16 sOamFrame_5f34da[OAM_DATA_SIZE(20)] = {
	20,
	OAM_ENTRY(-120, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 774, 9, 0),
	OAM_ENTRY(-104, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-72, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(104, -20, OAM_DIMS_16x16, OAM_X_FLIP, 774, 9, 0),
	OAM_ENTRY(72, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-40, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-8, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(24, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(56, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-120, 4, OAM_DIMS_16x16, OAM_Y_FLIP, 774, 9, 0),
	OAM_ENTRY(-104, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-72, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(104, 4, OAM_DIMS_16x16, OAM_XY_FLIP, 774, 9, 0),
	OAM_ENTRY(72, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-40, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(24, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(56, 12, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-120, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(112, -4, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
};

static const u16 sOamFrame_5f3554[OAM_DATA_SIZE(22)] = {
	22,
	OAM_ENTRY(-120, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 774, 9, 0),
	OAM_ENTRY(-104, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-72, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(104, -24, OAM_DIMS_16x16, OAM_X_FLIP, 774, 9, 0),
	OAM_ENTRY(72, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-40, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(24, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(56, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-120, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 774, 9, 0),
	OAM_ENTRY(-104, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-72, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(104, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 774, 9, 0),
	OAM_ENTRY(72, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-40, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-8, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(24, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(56, 16, OAM_DIMS_32x8, OAM_Y_FLIP, 775, 9, 0),
	OAM_ENTRY(-120, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(-120, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(112, -8, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
	OAM_ENTRY(112, 0, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
};

static const u16 sOamFrame_5f35da[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f3606[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-112, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f3632[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(-112, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-112, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f3688[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(-112, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-112, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f36de[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f370a[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-112, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f3736[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(-112, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-112, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f378c[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(-112, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-112, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f37e2[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 780, 0, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 9, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 770, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 800, 9, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 800, 9, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 768, 9, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 768, 9, 0),
	OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 768, 9, 0),
	OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 770, 9, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 800, 9, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_X_FLIP, 800, 9, 0),
};

static const u16 sOamFrame_5f3826[OAM_DATA_SIZE(12)] = {
	12,
	OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 910, 0, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 780, 0, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 9, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 770, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 800, 9, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 800, 9, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 768, 9, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 768, 9, 0),
	OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 768, 9, 0),
	OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 770, 9, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 800, 9, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_X_FLIP, 800, 9, 0),
};

static const u16 sOamFrame_5f3870[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 784, 3, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 774, 9, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 777, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 774, 9, 0),
	OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 777, 9, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
	OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 774, 9, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 774, 9, 0),
};

static const u16 sOamFrame_5f38b4[OAM_DATA_SIZE(12)] = {
	12,
	OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 908, 3, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 784, 3, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 774, 9, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 777, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 774, 9, 0),
	OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 777, 9, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
	OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 774, 9, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 774, 9, 0),
};

static const u16 sOamFrame_5f38fe[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 772, 8, 0),
};

static const u16 sOamFrame_5f3906[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 771, 8, 0),
};

static const u16 sOamFrame_5f390e[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
};

static const u16 sOamFrame_5f3916[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-20, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
	OAM_ENTRY(-12, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 769, 8, 0),
};

static const u16 sOamFrame_5f3924[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 8, 0),
	OAM_ENTRY(-24, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 768, 8, 0),
	OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_X_FLIP, 768, 8, 0),
	OAM_ENTRY(8, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 768, 8, 0),
	OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 771, 9, 0),
	OAM_ENTRY(-8, 4, OAM_DIMS_16x8, OAM_Y_FLIP, 771, 9, 0),
	OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f3950[OAM_DATA_SIZE(10)] = {
	10,
	OAM_ENTRY(-24, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 8, 0),
	OAM_ENTRY(-24, 4, OAM_DIMS_16x16, OAM_Y_FLIP, 768, 8, 0),
	OAM_ENTRY(8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 768, 8, 0),
	OAM_ENTRY(8, 4, OAM_DIMS_16x16, OAM_XY_FLIP, 768, 8, 0),
	OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 771, 9, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_16x8, OAM_Y_FLIP, 771, 9, 0),
	OAM_ENTRY(-16, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-24, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 800, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_X_FLIP, 800, 9, 0),
};

static const u16 sOamFrame_5f398e[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 8, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 768, 8, 0),
	OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 768, 8, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 768, 8, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 771, 9, 0),
	OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 771, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 800, 9, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 800, 9, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_X_FLIP, 800, 9, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 800, 9, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f39d2[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 778, 9, 0),
};

static const u16 sOamFrame_5f39da[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 776, 9, 0),
};

static const u16 sOamFrame_5f39e2[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
};

static const u16 sOamFrame_5f39ea[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(-12, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 775, 9, 0),
	OAM_ENTRY(-20, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 778, 9, 0),
};

static const u16 sOamFrame_5f39f8[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 774, 9, 0),
	OAM_ENTRY(-24, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 774, 9, 0),
	OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_X_FLIP, 774, 9, 0),
	OAM_ENTRY(8, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 774, 9, 0),
	OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 777, 9, 0),
	OAM_ENTRY(-8, 4, OAM_DIMS_16x8, OAM_Y_FLIP, 777, 9, 0),
	OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f3a24[OAM_DATA_SIZE(10)] = {
	10,
	OAM_ENTRY(-24, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 774, 9, 0),
	OAM_ENTRY(-24, 4, OAM_DIMS_16x16, OAM_Y_FLIP, 774, 9, 0),
	OAM_ENTRY(8, -20, OAM_DIMS_16x16, OAM_X_FLIP, 774, 9, 0),
	OAM_ENTRY(8, 4, OAM_DIMS_16x16, OAM_XY_FLIP, 774, 9, 0),
	OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 777, 9, 0),
	OAM_ENTRY(-8, 12, OAM_DIMS_16x8, OAM_Y_FLIP, 777, 9, 0),
	OAM_ENTRY(-24, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
	OAM_ENTRY(-16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
	OAM_ENTRY(-16, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 580, 9, 0),
};

static const u16 sOamFrame_5f3a62[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 774, 9, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_16x16, OAM_Y_FLIP, 774, 9, 0),
	OAM_ENTRY(8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 774, 9, 0),
	OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 774, 9, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 777, 9, 0),
	OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 777, 9, 0),
	OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
	OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_X_FLIP, 806, 9, 0),
	OAM_ENTRY(-24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 806, 9, 0),
	OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sOamFrame_5f3aa6[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 791, 8, 0),
	OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 855, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 622, 8, 0),
};

static const u16 sOamFrame_5f3aba[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 793, 8, 0),
	OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 857, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 622, 8, 0),
};

static const u16 sOamFrame_5f3ace[OAM_DATA_SIZE(3)] = {
	3,
	OAM_ENTRY(-120, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 795, 8, 0),
	OAM_ENTRY(-120, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 859, 8, 0),
	OAM_ENTRY(-128, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 622, 8, 0),
};

static const u16 sOamFrame_5f3ae2[OAM_DATA_SIZE(12)] = {
	12,
	OAM_ENTRY(2, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 89, 5, 0),
	OAM_ENTRY(-45, -68, OAM_DIMS_32x16, OAM_NO_FLIP, 22, 5, 0),
	OAM_ENTRY(-13, -68, OAM_DIMS_8x16, OAM_NO_FLIP, 26, 5, 0),
	OAM_ENTRY(-53, -63, OAM_DIMS_8x8, OAM_X_FLIP, 16, 5, 0),
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 15, 5, 0),
	OAM_ENTRY(2, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 47, 5, 0),
	OAM_ENTRY(-74, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 0, 5, 0),
	OAM_ENTRY(-58, -60, OAM_DIMS_8x16, OAM_NO_FLIP, 2, 5, 0),
	OAM_ENTRY(-74, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 64, 5, 0),
	OAM_ENTRY(-58, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 66, 5, 0),
	OAM_ENTRY(-119, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 113, 5, 0),
	OAM_ENTRY(-119, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 117, 5, 0),
};

static const u16 sOamFrame_5f3b2c[OAM_DATA_SIZE(12)] = {
	12,
	OAM_ENTRY(2, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 89, 5, 0),
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 15, 5, 0),
	OAM_ENTRY(2, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 47, 5, 0),
	OAM_ENTRY(-45, -68, OAM_DIMS_32x16, OAM_NO_FLIP, 22, 5, 0),
	OAM_ENTRY(-13, -68, OAM_DIMS_8x16, OAM_NO_FLIP, 26, 5, 0),
	OAM_ENTRY(-53, -63, OAM_DIMS_8x8, OAM_X_FLIP, 16, 5, 0),
	OAM_ENTRY(-74, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 3, 5, 0),
	OAM_ENTRY(-58, -60, OAM_DIMS_8x16, OAM_NO_FLIP, 5, 5, 0),
	OAM_ENTRY(-74, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 67, 5, 0),
	OAM_ENTRY(-58, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 69, 5, 0),
	OAM_ENTRY(-119, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 113, 5, 0),
	OAM_ENTRY(-119, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 117, 5, 0),
};

static const u16 sOamFrame_5f3b76[OAM_DATA_SIZE(12)] = {
	12,
	OAM_ENTRY(2, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 89, 5, 0),
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 15, 5, 0),
	OAM_ENTRY(2, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 47, 5, 0),
	OAM_ENTRY(-45, -68, OAM_DIMS_32x16, OAM_NO_FLIP, 22, 5, 0),
	OAM_ENTRY(-13, -68, OAM_DIMS_8x16, OAM_NO_FLIP, 26, 5, 0),
	OAM_ENTRY(-53, -63, OAM_DIMS_8x8, OAM_X_FLIP, 16, 5, 0),
	OAM_ENTRY(-74, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 6, 5, 0),
	OAM_ENTRY(-58, -60, OAM_DIMS_8x16, OAM_NO_FLIP, 8, 5, 0),
	OAM_ENTRY(-74, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 70, 5, 0),
	OAM_ENTRY(-58, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 72, 5, 0),
	OAM_ENTRY(-119, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 113, 5, 0),
	OAM_ENTRY(-119, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 117, 5, 0),
};

static const u16 sOamFrame_5f3bc0[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 15, 5, 0),
	OAM_ENTRY(2, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 47, 5, 0),
	OAM_ENTRY(-45, -68, OAM_DIMS_32x16, OAM_NO_FLIP, 22, 5, 0),
	OAM_ENTRY(-13, -68, OAM_DIMS_8x16, OAM_NO_FLIP, 26, 5, 0),
	OAM_ENTRY(-53, -63, OAM_DIMS_8x8, OAM_X_FLIP, 16, 5, 0),
	OAM_ENTRY(-74, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 9, 5, 0),
	OAM_ENTRY(-58, -60, OAM_DIMS_8x16, OAM_NO_FLIP, 11, 5, 0),
	OAM_ENTRY(-74, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 73, 5, 0),
	OAM_ENTRY(-58, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 75, 5, 0),
	OAM_ENTRY(-119, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 113, 5, 0),
	OAM_ENTRY(-119, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 117, 5, 0),
};

static const u16 sOamFrame_5f3c04[OAM_DATA_SIZE(11)] = {
	11,
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 15, 5, 0),
	OAM_ENTRY(2, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 47, 5, 0),
	OAM_ENTRY(-45, -68, OAM_DIMS_32x16, OAM_NO_FLIP, 22, 5, 0),
	OAM_ENTRY(-13, -68, OAM_DIMS_8x16, OAM_NO_FLIP, 26, 5, 0),
	OAM_ENTRY(-53, -63, OAM_DIMS_8x8, OAM_X_FLIP, 16, 5, 0),
	OAM_ENTRY(-74, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 12, 5, 0),
	OAM_ENTRY(-58, -60, OAM_DIMS_8x16, OAM_NO_FLIP, 14, 5, 0),
	OAM_ENTRY(-74, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 76, 5, 0),
	OAM_ENTRY(-58, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 78, 5, 0),
	OAM_ENTRY(-119, -25, OAM_DIMS_32x16, OAM_NO_FLIP, 113, 5, 0),
	OAM_ENTRY(-119, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 117, 5, 0),
};

static const u16 sOamFrame_5f3c48[OAM_DATA_SIZE(23)] = {
	23,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(-49, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(-35, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0, 5, 0),
	OAM_ENTRY(-19, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 2, 5, 0),
	OAM_ENTRY(-35, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 64, 5, 0),
	OAM_ENTRY(-19, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 66, 5, 0),
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 15, 5, 0),
	OAM_ENTRY(-47, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 16, 5, 0),
	OAM_ENTRY(-81, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 17, 5, 0),
	OAM_ENTRY(-49, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 21, 5, 0),
	OAM_ENTRY(-10, -23, OAM_DIMS_8x8, OAM_X_FLIP, 16, 5, 0),
	OAM_ENTRY(-2, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 22, 5, 0),
	OAM_ENTRY(30, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 26, 5, 0),
	OAM_ENTRY(-81, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 27, 5, 0),
	OAM_ENTRY(-49, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 31, 5, 0),
	OAM_ENTRY(2, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 47, 5, 0),
	OAM_ENTRY(-58, 23, OAM_DIMS_16x16, OAM_NO_FLIP, 96, 5, 0),
	OAM_ENTRY(-42, 23, OAM_DIMS_8x16, OAM_NO_FLIP, 98, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
};

static const u16 sOamFrame_5f3cd4[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(119, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 144, 5, 0),
};

static const u16 sOamFrame_5f3cdc[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(111, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 143, 5, 0),
};

static const u16 sOamFrame_5f3ce4[OAM_DATA_SIZE(2)] = {
	2,
	OAM_ENTRY(111, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 143, 5, 0),
	OAM_ENTRY(103, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 142, 5, 0),
};

static const u16 sOamFrame_5f3cf2[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
};

static const u16 sOamFrame_5f3cfa[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(87, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 139, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
};

static const u16 sOamFrame_5f3d1a[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(87, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 139, 5, 0),
	OAM_ENTRY(79, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 138, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
};

static const u16 sOamFrame_5f3d40[OAM_DATA_SIZE(5)] = {
	5,
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
};

static const u16 sOamFrame_5f3d60[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(63, 11, OAM_DIMS_8x8, OAM_NO_FLIP, 112, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
};

static const u16 sOamFrame_5f3d86[OAM_DATA_SIZE(6)] = {
	6,
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(55, 11, OAM_DIMS_16x8, OAM_NO_FLIP, 111, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
};

static const u16 sOamFrame_5f3dac[OAM_DATA_SIZE(7)] = {
	7,
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(55, 11, OAM_DIMS_16x8, OAM_NO_FLIP, 111, 5, 0),
	OAM_ENTRY(47, 11, OAM_DIMS_8x8, OAM_NO_FLIP, 110, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
};

static const u16 sOamFrame_5f3dd8[OAM_DATA_SIZE(9)] = {
	9,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
};

static const u16 sOamFrame_5f3e10[OAM_DATA_SIZE(10)] = {
	10,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(31, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 108, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
};

static const u16 sOamFrame_5f3e4e[OAM_DATA_SIZE(10)] = {
	10,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(23, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 107, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
};

static const u16 sOamFrame_5f3e8c[OAM_DATA_SIZE(10)] = {
	10,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(7, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 105, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
};

static const u16 sOamFrame_5f3eca[OAM_DATA_SIZE(10)] = {
	10,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(7, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 105, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
};

static const u16 sOamFrame_5f3f08[OAM_DATA_SIZE(13)] = {
	13,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(-49, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(7, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 105, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
	OAM_ENTRY(-58, 23, OAM_DIMS_16x16, OAM_NO_FLIP, 96, 5, 0),
	OAM_ENTRY(-42, 23, OAM_DIMS_8x16, OAM_NO_FLIP, 98, 5, 0),
};

static const u16 sOamFrame_5f3f58[OAM_DATA_SIZE(14)] = {
	14,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(-49, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(7, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 105, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
	OAM_ENTRY(-58, 23, OAM_DIMS_16x16, OAM_NO_FLIP, 96, 5, 0),
	OAM_ENTRY(-42, 23, OAM_DIMS_8x16, OAM_NO_FLIP, 98, 5, 0),
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 88, 5, 0),
};

static const u16 sOamFrame_5f3fae[OAM_DATA_SIZE(15)] = {
	15,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(-49, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(7, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 105, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
	OAM_ENTRY(-58, 23, OAM_DIMS_16x16, OAM_NO_FLIP, 96, 5, 0),
	OAM_ENTRY(-42, 23, OAM_DIMS_8x16, OAM_NO_FLIP, 98, 5, 0),
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 88, 5, 0),
	OAM_ENTRY(-47, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 16, 5, 0),
};

static const u16 sOamFrame_5f400a[OAM_DATA_SIZE(17)] = {
	17,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(-49, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(7, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 105, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
	OAM_ENTRY(-58, 23, OAM_DIMS_16x16, OAM_NO_FLIP, 96, 5, 0),
	OAM_ENTRY(-42, 23, OAM_DIMS_8x16, OAM_NO_FLIP, 98, 5, 0),
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 88, 5, 0),
	OAM_ENTRY(-47, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 16, 5, 0),
	OAM_ENTRY(-81, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 17, 5, 0),
	OAM_ENTRY(-49, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 21, 5, 0),
};

static const u16 sOamFrame_5f4072[OAM_DATA_SIZE(17)] = {
	17,
	OAM_ENTRY(48, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(94, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(-49, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 87, 5, 0),
	OAM_ENTRY(95, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 141, 5, 0),
	OAM_ENTRY(71, 6, OAM_DIMS_32x8, OAM_NO_FLIP, 137, 5, 0),
	OAM_ENTRY(39, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 109, 5, 0),
	OAM_ENTRY(7, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 105, 5, 0),
	OAM_ENTRY(90, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 102, 5, 0),
	OAM_ENTRY(106, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 104, 5, 0),
	OAM_ENTRY(43, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 99, 5, 0),
	OAM_ENTRY(59, 19, OAM_DIMS_8x16, OAM_NO_FLIP, 101, 5, 0),
	OAM_ENTRY(-58, 23, OAM_DIMS_16x16, OAM_NO_FLIP, 96, 5, 0),
	OAM_ENTRY(-42, 23, OAM_DIMS_8x16, OAM_NO_FLIP, 98, 5, 0),
	OAM_ENTRY(-43, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 88, 5, 0),
	OAM_ENTRY(-47, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 16, 5, 0),
	OAM_ENTRY(-81, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 27, 5, 0),
	OAM_ENTRY(-49, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 31, 5, 0),
};

static const u16 sOamFrame_5f40da[OAM_DATA_SIZE(47)] = {
	47,
	OAM_ENTRY(-16, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 164, 2, 0),
	OAM_ENTRY(-24, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 195, 2, 0),
	OAM_ENTRY(-32, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 226, 2, 0),
	OAM_ENTRY(8, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 199, 2, 0),
	OAM_ENTRY(24, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 201, 2, 0),
	OAM_ENTRY(-48, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 320, 2, 0),
	OAM_ENTRY(-48, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 288, 2, 0),
	OAM_ENTRY(-32, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 354, 2, 0),
	OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 298, 2, 0),
	OAM_ENTRY(32, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 362, 2, 0),
	OAM_ENTRY(-40, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 174, 2, 0),
	OAM_ENTRY(-24, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 176, 2, 0),
	OAM_ENTRY(24, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 182, 2, 0),
	OAM_ENTRY(-16, 72, OAM_DIMS_32x8, OAM_NO_FLIP, 303, 2, 0),
	OAM_ENTRY(-8, 80, OAM_DIMS_16x8, OAM_NO_FLIP, 336, 2, 0),
	OAM_ENTRY(-32, 64, OAM_DIMS_8x8, OAM_NO_FLIP, 269, 2, 0),
	OAM_ENTRY(24, 64, OAM_DIMS_8x8, OAM_NO_FLIP, 276, 2, 0),
	OAM_ENTRY(0, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 243, 2, 0),
	OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 261, 6, 0),
	OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 325, 6, 0),
	OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 292, 6, 0),
	OAM_ENTRY(0, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 262, 4, 0),
	OAM_ENTRY(-8, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 197, 4, 0),
	OAM_ENTRY(-8, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 229, 4, 0),
	OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 227, 4, 0),
	OAM_ENTRY(-32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 290, 4, 0),
	OAM_ENTRY(-32, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 258, 4, 0),
	OAM_ENTRY(-16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 324, 4, 0),
	OAM_ENTRY(-24, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 355, 4, 0),
	OAM_ENTRY(-16, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 356, 4, 0),
	OAM_ENTRY(-16, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 177, 4, 0),
	OAM_ENTRY(-40, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 225, 7, 0),
	OAM_ENTRY(-40, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 289, 7, 0),
	OAM_ENTRY(-48, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 256, 7, 0),
	OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 194, 7, 0),
	OAM_ENTRY(32, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 234, 7, 0),
	OAM_ENTRY(40, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 267, 7, 0),
	OAM_ENTRY(48, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 300, 7, 0),
	OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 209, 7, 0),
	OAM_ENTRY(-8, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 242, 7, 0),
	OAM_ENTRY(16, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 181, 7, 0),
	OAM_ENTRY(40, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 184, 7, 0),
	OAM_ENTRY(24, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 214, 7, 0),
	OAM_ENTRY(-32, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 207, 7, 0),
	OAM_ENTRY(-24, 64, OAM_DIMS_8x16, OAM_NO_FLIP, 270, 7, 0),
	OAM_ENTRY(16, 64, OAM_DIMS_8x16, OAM_NO_FLIP, 275, 7, 0),
	OAM_ENTRY(-16, 64, OAM_DIMS_32x8, OAM_NO_FLIP, 271, 7, 0),
};

static const u16 sOamFrame_5f41f6[OAM_DATA_SIZE(1)] = {
	1,
	OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 149, 5, 0),
};

const struct FrameData sOam_5f4200[11] = {
	[0] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 84
	},
	[1] = {
		.pFrame = sOamFrame_5f2610,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5f262a,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5f2644,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5f2670,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f2696,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f26bc,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5f2700,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f2744,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f279a,
		.timer = 255
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4258[10] = {
	[0] = {
		.pFrame = sOamFrame_5f279a,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f2744,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f2700,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f26bc,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f2696,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f2670,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5f2644,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5f262a,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5f2610,
		.timer = 1
	},
	[9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f42a8[13] = {
	[0] = {
		.pFrame = sOamFrame_5f27f0,
		.timer = 1
	},
	[1] = {
		.pFrame = sOamFrame_5f2828,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5f2872,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5f28bc,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5f2912,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5f2962,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5f29ca,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5f2a32,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f2aa6,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f2b14,
		.timer = 2
	},
	[10] = {
		.pFrame = sOamFrame_5f2b8e,
		.timer = 2
	},
	[11] = {
		.pFrame = sOamFrame_5f2c08,
		.timer = 50
	},
	[12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4310[13] = {
	[0] = {
		.pFrame = sOamFrame_5f2c08,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f2b8e,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f2b14,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f2aa6,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f2a32,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5f29ca,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5f2962,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5f2912,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5f28bc,
		.timer = 1
	},
	[9] = {
		.pFrame = sOamFrame_5f2872,
		.timer = 1
	},
	[10] = {
		.pFrame = sOamFrame_5f2828,
		.timer = 1
	},
	[11] = {
		.pFrame = sOamFrame_5f27f0,
		.timer = 50
	},
	[12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4378[13] = {
	[0] = {
		.pFrame = sOamFrame_5f2c8e,
		.timer = 1
	},
	[1] = {
		.pFrame = sOamFrame_5f2cb4,
		.timer = 1
	},
	[2] = {
		.pFrame = sOamFrame_5f2cf2,
		.timer = 1
	},
	[3] = {
		.pFrame = sOamFrame_5f2d36,
		.timer = 1
	},
	[4] = {
		.pFrame = sOamFrame_5f2d6e,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5f2dd0,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5f2e32,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5f2e9a,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f2f0e,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f2f88,
		.timer = 2
	},
	[10] = {
		.pFrame = sOamFrame_5f300e,
		.timer = 2
	},
	[11] = {
		.pFrame = sOamFrame_5f309a,
		.timer = 50
	},
	[12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f43e0[13] = {
	[0] = {
		.pFrame = sOamFrame_5f309a,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f300e,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f2f88,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f2f0e,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f2e9a,
		.timer = 1
	},
	[5] = {
		.pFrame = sOamFrame_5f2e32,
		.timer = 1
	},
	[6] = {
		.pFrame = sOamFrame_5f2dd0,
		.timer = 1
	},
	[7] = {
		.pFrame = sOamFrame_5f2d6e,
		.timer = 1
	},
	[8] = {
		.pFrame = sOamFrame_5f2d36,
		.timer = 1
	},
	[9] = {
		.pFrame = sOamFrame_5f2cf2,
		.timer = 1
	},
	[10] = {
		.pFrame = sOamFrame_5f2cb4,
		.timer = 1
	},
	[11] = {
		.pFrame = sOamFrame_5f2c8e,
		.timer = 255
	},
	[12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4448[5] = {
	[0] = {
		.pFrame = sOamFrame_5f30d2,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5f30e6,
		.timer = 8
	},
	[2] = {
		.pFrame = sOamFrame_5f30fa,
		.timer = 8
	},
	[3] = {
		.pFrame = sOamFrame_5f310e,
		.timer = 255
	},
	[4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4470[5] = {
	[0] = {
		.pFrame = sOamFrame_5f310e,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5f30fa,
		.timer = 8
	},
	[2] = {
		.pFrame = sOamFrame_5f30e6,
		.timer = 8
	},
	[3] = {
		.pFrame = sOamFrame_5f30d2,
		.timer = 255
	},
	[4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4498[2] = {
	[0] = {
		.pFrame = sOamFrame_5f3122,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f44a8[11] = {
	[0] = {
		.pFrame = sOamFrame_5f3138,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f3140,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f3148,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f3150,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f3164,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f3184,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f31b0,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5f321e,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f328c,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f3306,
		.timer = 255
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4500[11] = {
	[0] = {
		.pFrame = sOamFrame_5f3306,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f328c,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f321e,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f31b0,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f3184,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f3164,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f3150,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5f3148,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f3140,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f3138,
		.timer = 2
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4558[11] = {
	[0] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f35da,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5f3606,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f3632,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f3688,
		.timer = 255
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f45b0[11] = {
	[0] = {
		.pFrame = sOamFrame_5f3688,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f3632,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f3606,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f35da,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4608[11] = {
	[0] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f36de,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5f370a,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f3736,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f378c,
		.timer = 255
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4660[11] = {
	[0] = {
		.pFrame = sOamFrame_5f378c,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f3736,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f370a,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f36de,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f3130,
		.timer = 2
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f46b8[11] = {
	[0] = {
		.pFrame = sOamFrame_5f3380,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f3388,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f3390,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f339e,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f33b2,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f33d2,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f33fe,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5f346c,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f34da,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f3554,
		.timer = 255
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4710[11] = {
	[0] = {
		.pFrame = sOamFrame_5f3554,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f34da,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f346c,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f33fe,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f33d2,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f33b2,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f339e,
		.timer = 2
	},
	[7] = {
		.pFrame = sOamFrame_5f3390,
		.timer = 2
	},
	[8] = {
		.pFrame = sOamFrame_5f3388,
		.timer = 2
	},
	[9] = {
		.pFrame = sOamFrame_5f3380,
		.timer = 2
	},
	[10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4768[2] = {
	[0] = {
		.pFrame = sOamFrame_5f37e2,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4778[3] = {
	[0] = {
		.pFrame = sOamFrame_5f37e2,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5f3826,
		.timer = 8
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4790[2] = {
	[0] = {
		.pFrame = sOamFrame_5f3870,
		.timer = 4
	},
	[1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f47a0[3] = {
	[0] = {
		.pFrame = sOamFrame_5f3870,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5f38b4,
		.timer = 8
	},
	[2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f47b8[8] = {
	[0] = {
		.pFrame = sOamFrame_5f38fe,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f3906,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f390e,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f3916,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f3924,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f3950,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f398e,
		.timer = 2
	},
	[7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f47f8[8] = {
	[0] = {
		.pFrame = sOamFrame_5f398e,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f3950,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f3924,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f3916,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f390e,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f3906,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f38fe,
		.timer = 2
	},
	[7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4838[8] = {
	[0] = {
		.pFrame = sOamFrame_5f39d2,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f39da,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f39e2,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f39ea,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f39f8,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f3a24,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f3a62,
		.timer = 2
	},
	[7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f4878[8] = {
	[0] = {
		.pFrame = sOamFrame_5f3a62,
		.timer = 2
	},
	[1] = {
		.pFrame = sOamFrame_5f3a24,
		.timer = 2
	},
	[2] = {
		.pFrame = sOamFrame_5f39f8,
		.timer = 2
	},
	[3] = {
		.pFrame = sOamFrame_5f39ea,
		.timer = 2
	},
	[4] = {
		.pFrame = sOamFrame_5f39e2,
		.timer = 2
	},
	[5] = {
		.pFrame = sOamFrame_5f39da,
		.timer = 2
	},
	[6] = {
		.pFrame = sOamFrame_5f39d2,
		.timer = 2
	},
	[7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f48b8[6] = {
	[0] = {
		.pFrame = sOamFrame_5f310e,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5f3aa6,
		.timer = 8
	},
	[2] = {
		.pFrame = sOamFrame_5f3aba,
		.timer = 8
	},
	[3] = {
		.pFrame = sOamFrame_5f3ace,
		.timer = 8
	},
	[4] = {
		.pFrame = sOamFrame_5f3aa6,
		.timer = 8
	},
	[5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f48e8[26] = {
	[0] = {
		.pFrame = sOamFrame_5f3cd4,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5f3cdc,
		.timer = 3
	},
	[2] = {
		.pFrame = sOamFrame_5f3ce4,
		.timer = 3
	},
	[3] = {
		.pFrame = sOamFrame_5f3cf2,
		.timer = 3
	},
	[4] = {
		.pFrame = sOamFrame_5f3cfa,
		.timer = 3
	},
	[5] = {
		.pFrame = sOamFrame_5f3d1a,
		.timer = 3
	},
	[6] = {
		.pFrame = sOamFrame_5f3d40,
		.timer = 3
	},
	[7] = {
		.pFrame = sOamFrame_5f3d60,
		.timer = 3
	},
	[8] = {
		.pFrame = sOamFrame_5f3d86,
		.timer = 3
	},
	[9] = {
		.pFrame = sOamFrame_5f3dac,
		.timer = 3
	},
	[10] = {
		.pFrame = sOamFrame_5f3dd8,
		.timer = 3
	},
	[11] = {
		.pFrame = sOamFrame_5f3e10,
		.timer = 3
	},
	[12] = {
		.pFrame = sOamFrame_5f3e4e,
		.timer = 3
	},
	[13] = {
		.pFrame = sOamFrame_5f3e8c,
		.timer = 3
	},
	[14] = {
		.pFrame = sOamFrame_5f3eca,
		.timer = 27
	},
	[15] = {
		.pFrame = sOamFrame_5f3f08,
		.timer = 15
	},
	[16] = {
		.pFrame = sOamFrame_5f3f58,
		.timer = 3
	},
	[17] = {
		.pFrame = sOamFrame_5f3fae,
		.timer = 3
	},
	[18] = {
		.pFrame = sOamFrame_5f400a,
		.timer = 30
	},
	[19] = {
		.pFrame = sOamFrame_5f4072,
		.timer = 20
	},
	[20] = {
		.pFrame = sOamFrame_5f400a,
		.timer = 30
	},
	[21] = {
		.pFrame = sOamFrame_5f4072,
		.timer = 20
	},
	[22] = {
		.pFrame = sOamFrame_5f400a,
		.timer = 30
	},
	[23] = {
		.pFrame = sOamFrame_5f4072,
		.timer = 20
	},
	[24] = {
		.pFrame = sOamFrame_5f400a,
		.timer = 30
	},
	[25] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f49b8[6] = {
	[0] = {
		.pFrame = sOamFrame_5f3ae2,
		.timer = 8
	},
	[1] = {
		.pFrame = sOamFrame_5f3b2c,
		.timer = 8
	},
	[2] = {
		.pFrame = sOamFrame_5f3b76,
		.timer = 8
	},
	[3] = {
		.pFrame = sOamFrame_5f3bc0,
		.timer = 8
	},
	[4] = {
		.pFrame = sOamFrame_5f3c04,
		.timer = 8
	},
	[5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sOam_5f49e8[3] = {
	[0] = {
		.pFrame = sOamFrame_5f40da,
		.timer = 3
	},
	[1] = {
		.pFrame = sOamFrame_5f41f6,
		.timer = 1
	},
	[2] = FRAME_DATA_TERMINATOR
};

static const u8 sBlob_5f4a00_5f5254[] = INCBIN_U8("data/Blob_5f4a00_5f5254.bin");

const u16 sIntroApproachingBslObjPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/approaching_bsl_obj.pal");

static const u8 sBlob_5f5454_5f6018[] = INCBIN_U8("data/Blob_5f5454_5f6018.bin");

const u32 sIntroSamusMonologueBgTilemap[367] = INCBIN_U32("data/new_file_intro/samus_monologue_bg.tm.lz");

static const u8 sBlob_5f65d4_60093c[] = INCBIN_U8("data/Blob_5f65d4_60093c.bin");

const u32 sIntroSamusSittingGfx[4818] = INCBIN_U32("data/new_file_intro/samus_sitting.gfx.lz");
const u16 sIntroSamusSittingPal[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/samus_sitting.pal");
const u32 sIntroSamusSittingTilemap[171] = INCBIN_U32("data/new_file_intro/samus_sitting.tm.lz");

static const u8 sBlob_605930_605d08[] = INCBIN_U8("data/Blob_605930_605d08.bin");

const u32 sTitleScreenSpaceBackgroundGfx[830] = INCBIN_U32("data/menus/title_screen/space_background.gfx.lz");

static const u8 sBlob_606a00_609020[] = INCBIN_U8("data/Blob_606a00_609020.bin");

const u16 sPal_609020[8 * PAL_ROW] = INCBIN_U16("data/new_file_intro/609020.pal");
const u16 sTitleScreenSpaceBackgroundPal[8 * PAL_ROW] = INCBIN_U16("data/menus/title_screen/space_background.pal");

const u32 sTitleScreenSpaceBackgroundTilemap[172] = INCBIN_U32("data/menus/title_screen/space_background.tm.lz");

static const u8 sBlob_6094d0_60b148[] = INCBIN_U8("data/Blob_6094d0_60b148.bin");

const u8 sIntroSpaceTilemap[1320] = INCBIN_U8("data/new_file_intro/space_bg.tm.lz");
const u8 sIntroBslTilemap[1586] = INCBIN_U8("data/new_file_intro/bsl_bg.tm.lz");

static const u8 padding[2] = {0, 0};

const u32 sIntroBslSpaceBgGfx[4421] = INCBIN_U32("data/new_file_intro/bsl_space_bg.gfx.lz");

static const u8 sBlob_6101b8_612e48[] = INCBIN_U8("data/Blob_6101b8_612e48.bin");

const u16 sIntroBslSpaceBgPal[8 * PAL_ROW] = INCBIN_U16("data/new_file_intro/bsl_space_bg.pal");
const u16 sPal_612f48[16 * PAL_ROW] = INCBIN_U16("data/new_file_intro/612f48.pal");

const u32 sNextPageArrowGfx[8] = INCBIN_U32("data/new_file_intro/next_page_arrow.gfx");

static const u16 sOamFrame_613168[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 1023, 15, 0),
};

static const u16 sOamFrame_613170[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 1023, 15, 0),
};

static const u16 sOamFrame_613178[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 1023, 15, 0),
};

const struct FrameData sIntroNextPageArrowOam[5] = {
    [0] = {
            .pFrame = sOamFrame_613168,
            .timer = 8
    },
    [1] = {
            .pFrame = sOamFrame_613170,
            .timer = 8
    },
    [2] = {
            .pFrame = sOamFrame_613178,
            .timer = 8
    },
    [3] = {
            .pFrame = sOamFrame_613170,
            .timer = 8
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u16 sNextPageArrowPal[1 * PAL_ROW] = INCBIN_U16("data/new_file_intro/next_page_arrow.pal");

static const u8 sBlob_6131c8_63a19c[] = INCBIN_U8("data/Blob_6131c8_63a19c.bin");

const u16 sCutsceneTextNone[2] = {
    CHAR_TERMINATOR, CHAR_TERMINATOR
};

const u32 sIntroSr388SurfaceBgGfx0[686] = INCBIN_U32("data/new_file_intro/sr388_surface_bg_0.gfx.lz");
const u32 sIntroSr388SurfaceBgGfx1[767] = INCBIN_U32("data/new_file_intro/sr388_surface_bg_1.gfx.lz");
const u32 sIntroSr388SurfaceBgGfx2[848] = INCBIN_U32("data/new_file_intro/sr388_surface_bg_2.gfx.lz");
const u32 sIntroSr388SurfaceBgGfx3[641] = INCBIN_U32("data/new_file_intro/sr388_surface_bg_3.gfx.lz");
const u32 sIntroSr388SurfaceBgGfx4[577] = INCBIN_U32("data/new_file_intro/sr388_surface_bg_4.gfx.lz");
const u32 sIntroSr388SurfaceBgGfx5[655] = INCBIN_U32("data/new_file_intro/sr388_surface_bg_5.gfx.lz");
const u32 sIntroSr388SurfaceBgGfx6[513] = INCBIN_U32("data/new_file_intro/sr388_surface_bg_6.gfx.lz");
const u32 sIntroSr388SurfaceBgGfx7[177] = INCBIN_U32("data/new_file_intro/sr388_surface_bg_7.gfx.lz");

const u32 sIntroSr388PlanetBgGfx0[719] = INCBIN_U32("data/new_file_intro/sr388_planet_bg_0.gfx.lz");
const u32 sIntroSr388PlanetBgGfx1[809] = INCBIN_U32("data/new_file_intro/sr388_planet_bg_1.gfx.lz");
const u32 sIntroSr388PlanetBgGfx2[794] = INCBIN_U32("data/new_file_intro/sr388_planet_bg_2.gfx.lz");
const u32 sIntroSr388PlanetBgGfx3[782] = INCBIN_U32("data/new_file_intro/sr388_planet_bg_3.gfx.lz");
const u32 sIntroSr388PlanetBgGfx4[772] = INCBIN_U32("data/new_file_intro/sr388_planet_bg_4.gfx.lz");

const u32 sIntroBslObjectGfx0[448] = INCBIN_U32("data/new_file_intro/bsl_object_0.gfx.lz");
const u32 sIntroBslObjectGfx1[402] = INCBIN_U32("data/new_file_intro/bsl_object_1.gfx.lz");
const u32 sIntroBslObjectGfx2[420] = INCBIN_U32("data/new_file_intro/bsl_object_2.gfx.lz");
const u32 sIntroBslObjectGfx3[124] = INCBIN_U32("data/new_file_intro/bsl_object_3.gfx.lz");
const u32 sIntroBslObjectGfx4[298] = INCBIN_U32("data/new_file_intro/bsl_object_4.gfx.lz");
const u32 sIntroBslObjectGfx5[186] = INCBIN_U32("data/new_file_intro/bsl_object_5.gfx.lz");
const u32 sIntroBslObjectGfx6[543] = INCBIN_U32("data/new_file_intro/bsl_object_6.gfx.lz");
const u32 sIntroBslObjectGfx7[482] = INCBIN_U32("data/new_file_intro/bsl_object_7.gfx.lz");

const u32 sIntroSamusSittingBgGfx0[920] = INCBIN_U32("data/new_file_intro/samus_sitting_bg_0.gfx.lz");
const u32 sIntroSamusSittingBgGfx1[978] = INCBIN_U32("data/new_file_intro/samus_sitting_bg_1.gfx.lz");
const u32 sIntroSamusSittingBgGfx2[962] = INCBIN_U32("data/new_file_intro/samus_sitting_bg_2.gfx.lz");
const u32 sIntroSamusSittingBgGfx3[944] = INCBIN_U32("data/new_file_intro/samus_sitting_bg_3.gfx.lz");
const u32 sIntroSamusSittingBgGfx4[800] = INCBIN_U32("data/new_file_intro/samus_sitting_bg_4.gfx.lz");

const u32 sIntroSamusHelmetCloseupBgGfx0[598] = INCBIN_U32("data/new_file_intro/samus_helmet_closeup_bg_0.gfx.lz");
const u32 sIntroSamusHelmetCloseupBgGfx1[848] = INCBIN_U32("data/new_file_intro/samus_helmet_closeup_bg_1.gfx.lz");
const u32 sIntroSamusHelmetCloseupBgGfx2[908] = INCBIN_U32("data/new_file_intro/samus_helmet_closeup_bg_2.gfx.lz");
const u32 sIntroSamusHelmetCloseupBgGfx3[812] = INCBIN_U32("data/new_file_intro/samus_helmet_closeup_bg_3.gfx.lz");
const u32 sIntroSamusHelmetCloseupBgGfx4[844] = INCBIN_U32("data/new_file_intro/samus_helmet_closeup_bg_4.gfx.lz");
const u32 sIntroSamusHelmetCloseupBgGfx5[403] = INCBIN_U32("data/new_file_intro/samus_helmet_closeup_bg_5.gfx.lz");

static const u8 sBlob_64e470_72eee0[] = INCBIN_U8("data/Blob_64e470_72eee0.bin");

