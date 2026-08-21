#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_32_Clipdata[188] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_32_clipdata.rle")
};

const u8 sSector1_32_Bg2[430] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_32_bg2.rle")
};

const u8 sSector1_32_Bg1[650] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_32_bg1.rle")
};

const u8 sSector1_32_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	4, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	7, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	9, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	12, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	13, 23, SPRITESET_IDX(2),
	20, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	20, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

