#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_7_Clipdata[212] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_7_clipdata.rle")
};

const u8 sSector4_7_Bg2[504] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_7_bg2.rle")
};

const u8 sSector4_7_Bg1[539] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_7_bg1.rle")
};

const u8 sSector4_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	3, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	4, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	4, 13, SPRITESET_IDX(1),
	5, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	8, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	12, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	14, 26, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	15, 24, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	16, 30, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	17, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	19, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_7_Bg0[325] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_7_bg0.rle")
};

