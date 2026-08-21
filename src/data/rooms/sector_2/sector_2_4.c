#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_4_Clipdata[80] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_4_clipdata.rle")
};

const u8 sSector2_4_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 16, SPRITESET_IDX(1),
	10, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	10, 22, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_4_Bg2[226] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_4_bg2.rle")
};

const u8 sSector2_4_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	7, 16, SPRITESET_IDX(0),
	10, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	10, 22, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_4_Bg1[237] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_4_bg1.rle")
};

const u8 sSector2_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	6, 16, SPRITESET_IDX(0),
	10, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	10, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

