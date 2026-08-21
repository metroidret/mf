#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_10_Clipdata[197] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_10_clipdata.rle")
};

const u8 sSector6_10_Bg2[138] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_10_bg2.rle")
};

const u8 sSector6_10_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	6, 12, SPRITESET_IDX(1),
	7, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	11, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	13, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	14, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	15, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	18, 3, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	19, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	19, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_10_Bg1[312] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_10_bg1.rle")
};

const u8 sSector6_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	6, 11, SPRITESET_IDX(1),
	11, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	13, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	15, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	18, 3, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	19, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	19, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

