#include "macros.h"
#include "oam.h"

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

const u16 sIntroSamusShipPal[16 * 5] = INCBIN_U16("data/new_file_intro/samus_ship.pal");
const u16 sPal_598150[16 * 2] = INCBIN_U16("data/new_file_intro/598150.pal"); // Loaded to PALRAM but not used?

const u32 sIntroSamusHelmetCloseupTilemap[172] = INCBIN_U32("data/new_file_intro/samus_helmet_closeup.tm.lz");

static const u8 sBlob_598440_598818[] = INCBIN_U8("data/Blob_598440_598818.bin");

const u16 sIntroSamusHelmetCloseupPal[16 * 4] = INCBIN_U16("data/new_file_intro/samus_helmet_closeup.pal");

const u32 sIntroSamusShipFlyingTextTilemap[125] = INCBIN_U32("data/new_file_intro/samus_ship_flying_text.tm.lz");

const u16 sPal_598a8c[16 * 1] = INCBIN_U16("data/new_file_intro/598a8c.pal");
const u16 sIntroSamusCloseupGrayscalePal[16 * 4] = INCBIN_U16("data/new_file_intro/samus_helmet_closeup_grayscale.pal");

const u16 sSr388SpaceAndSurfacePal[256] = INCBIN_U16("data/new_file_intro/sr388_space_and_surface.pal");

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
const u16 sIntroSr388SpaceAndSurfaceObjPal[16 * 16] = INCBIN_U16("data/new_file_intro/sr388_space_and_surface_objects.pal");

const u8 sArray_59db00[8] = {20, 30, 40, 50, 40, 30, 0, 0};

const u32 sIntroHornoadEncounterObjGfx[4252] = INCBIN_U32("data/new_file_intro/hornoad_encounter_obj.gfx.lz");
const u16 sIntroHornoadEncounterObjPal[16 * 16] = INCBIN_U16("data/new_file_intro/hornoad_encounter_obj.pal");

static const u8 sBlob_5a1f78_5a44cc[] = INCBIN_U8("data/Blob_5a1f78_5a44cc.bin");

const u32 sIntroHornoadEncounterBgGfx[4027] = INCBIN_U32("data/new_file_intro/hornoad_encounter_bg.gfx.lz");

const u32 sTilemap_5a83b8[196] = INCBIN_U32("data/new_file_intro/5a83b8.tm.lz");
const u32 sTilemap_5a86c8[479] = INCBIN_U32("data/new_file_intro/5a86c8.tm.lz");

const u16 sPal_5a8e44[16 * 16] = INCBIN_U16("data/new_file_intro/5a8e44.pal");

const u32 sTilemap_5a9044[135] = INCBIN_U32("data/new_file_intro/5a9044.tm.lz");

static const u8 sBlob_5a9260_60093c[] = INCBIN_U8("data/Blob_5a9260_60093c.bin");

const u32 sIntroSamusSittingGfx[4818] = INCBIN_U32("data/new_file_intro/samus_sitting.gfx.lz");
const u16 sIntroSamusSittingPal[16 * 16] = INCBIN_U16("data/new_file_intro/samus_sitting.pal");
const u32 sIntroSamusSittingTilemap[171] = INCBIN_U32("data/new_file_intro/samus_sitting.tm.lz");

static const u8 sBlob_605930_605d08[] = INCBIN_U8("data/Blob_605930_605d08.bin");

const u32 sTitleScreenSpaceBackgroundGfx[830] = INCBIN_U32("data/menus/title_screen/space_background.gfx.lz");

static const u8 sBlob_606a00_609020[] = INCBIN_U8("data/Blob_606a00_609020.bin");

const u16 sPal_609020[16 * 8] = INCBIN_U16("data/new_file_intro/609020.pal");
const u16 sTitleScreenSpaceBackgroundPal[16 * 8] = INCBIN_U16("data/menus/title_screen/space_background.pal");

const u32 sTitleScreenSpaceBackgroundTilemap[172] = INCBIN_U32("data/menus/title_screen/space_background.tm.lz");

static const u8 sBlob_6094d0_60b148[] = INCBIN_U8("data/Blob_6094d0_60b148.bin");

const u8 sIntroSpaceTilemap[1320] = INCBIN_U8("data/new_file_intro/space_bg.tm.lz");
const u8 sIntroBslTilemap[1586] = INCBIN_U8("data/new_file_intro/bsl_bg.tm.lz");

static const u8 padding[2] = {0, 0};

const u32 sIntroBslSpaceBgGfx[4421] = INCBIN_U32("data/new_file_intro/bsl_space_bg.gfx.lz");

static const u8 sBlob_6101b8_612e48[] = INCBIN_U8("data/Blob_6101b8_612e48.bin");

const u16 sIntroBslSpaceBgPal[16 * 8] = INCBIN_U16("data/new_file_intro/bsl_space_bg.pal");
const u16 sPal_612f48[16 * 16] = INCBIN_U16("data/new_file_intro/612f48.pal");

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

const struct FrameData sOam_613180[5] = {
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

const u16 sNextPageArrowPal[16 * 1] = INCBIN_U16("data/new_file_intro/next_page_arrow.pal");

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

