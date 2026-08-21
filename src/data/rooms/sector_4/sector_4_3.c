#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_3_Clipdata[207] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_3_clipdata.rle")
};

const u8 sSector4_3_Bg2[151] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_3_bg2.rle")
};

const u8 sSector4_3_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	5, 11, SPRITESET_IDX(1),
	8, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(10),
	12, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(10),
	16, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(10),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_3_Bg1[538] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_3_bg1.rle")
};

const u8 sSector4_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	5, 11, SPRITESET_IDX(1),
	8, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(10),
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	10, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	12, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(10),
	16, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(10),
	18, 17, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(10),
	20, 17, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

