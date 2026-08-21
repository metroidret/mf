#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_8_Clipdata[56] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_8_clipdata.rle")
};

const u8 sSector5_8_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	5, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	5, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	6, 15, SPRITESET_IDX(0),
	6, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	8, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector5_8_Bg2[101] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_8_bg2.rle")
};

const u8 sSector5_8_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	5, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	6, 15, SPRITESET_IDX(0),
	8, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	8, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector5_8_Bg1[260] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_8_bg1.rle")
};

const u8 sSector5_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	5, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	7, 14, SPRITESET_IDX(0),
	8, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	8, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

