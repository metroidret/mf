#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_30_Clipdata[60] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_30_clipdata.rle")
};

const u8 sSector2_30_Bg2[196] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_30_bg2.rle")
};

const u8 sSector2_30_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	4, 15, SPRITESET_IDX(1),
	5, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	7, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	7, 20, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_30_Bg1[312] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_30_bg1.rle")
};

const u8 sSector2_30_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	4, 16, SPRITESET_IDX(1),
	7, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	7, 20, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

