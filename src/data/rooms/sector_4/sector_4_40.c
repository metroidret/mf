#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_40_Clipdata[163] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_40_clipdata.rle")
};

const u8 sSector4_40_Bg2[283] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_40_bg2.rle")
};

const u8 sSector4_40_Bg1[507] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_40_bg1.rle")
};

const u8 sSector4_40_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	11, 6, SPRITESET_IDX(2),
	11, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	17, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	17, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	18, 2, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	19, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	20, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	20, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	21, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(7),
	ROOM_SPRITE_DATA_TERMINATOR
};

