#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_5_Clipdata[170] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_5_clipdata.rle")
};

const u8 sSector3_5_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	12, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	15, 6, SPRITESET_IDX(0),
	18, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	28, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_5_Bg2[251] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_5_bg2.rle")
};

const u8 sSector3_5_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	12, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	15, 6, SPRITESET_IDX(0),
	18, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	28, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_5_Bg1[393] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_5_bg1.rle")
};

const u8 sSector3_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	28, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

