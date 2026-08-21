#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_31_Scrolls[SCROLL_DATA_SIZE(1)] = {
	31, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_31_Clipdata[272] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_31_clipdata.rle")
};

const u8 sSector6_31_Bg2[14] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_31_bg2.rle")
};

const u8 sSector6_31_Bg1[748] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_31_bg1.rle")
};

const u8 sSector6_31_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	3, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	3, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	5, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	15, 6, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	18, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	21, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	23, 8, SPRITESET_IDX(1),
	25, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	27, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	30, 6, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	33, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

