#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_20_Clipdata[154] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_20_clipdata.rle")
};

const u8 sSector6_20_Bg2[14] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_20_bg2.rle")
};

const u8 sSector6_20_Bg1[495] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_20_bg1.rle")
};

const u8 sSector6_20_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	4, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	11, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	13, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	17, 12, SPRITESET_IDX(1),
	22, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	23, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

