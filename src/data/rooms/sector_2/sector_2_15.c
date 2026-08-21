#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_15_Clipdata[109] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_15_clipdata.rle")
};

const u8 sSector2_15_Bg2[292] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_15_bg2.rle")
};

const u8 sSector2_15_Bg1[368] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_15_bg1.rle")
};

const u8 sSector2_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	7, 26, SPRITESET_IDX(0),
	8, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

