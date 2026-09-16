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

static const u8 sBlob_5a9620_60093c[] = INCBIN_U8("data/Blob_5a9620_60093c.bin");

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

