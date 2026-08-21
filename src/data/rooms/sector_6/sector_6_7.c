#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_7_Scrolls[SCROLL_DATA_SIZE(1)] = {
	7, // Room
	1, // Number of scrolls
	
	// Scroll 0
	17, 46, // X bounds
	2, 11, // Y bounds
	17, 8, // Breakable block position
	0, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sSector6_7_Clipdata[110] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_7_clipdata.rle")
};

const u8 sSector6_7_Bg2[192] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_7_bg2.rle")
};

const u8 sSector6_7_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	5, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 34, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	6, 36, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	7, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	7, 25, SPRITESET_IDX(1),
	7, 33, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	7, 37, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	9, 34, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	9, 36, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	10, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_7_Bg1[307] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_7_bg1.rle")
};

const u8 sSector6_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	5, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 34, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	6, 36, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	7, 25, SPRITESET_IDX(0),
	7, 33, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	7, 37, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	9, 34, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	9, 36, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	10, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	10, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

