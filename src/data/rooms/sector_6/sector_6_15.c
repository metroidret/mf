#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_15_Clipdata[51] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_15_clipdata.rle")
};

const u8 sSector6_15_Bg2[14] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_15_bg2.rle")
};

const u8 sSector6_15_Bg1[205] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_15_bg1.rle")
};

const u8 sSector6_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	3, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	3, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	3, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	7, 9, SPRITESET_IDX(1),
	8, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	10, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

