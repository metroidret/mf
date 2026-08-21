#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_23_Scrolls[SCROLL_DATA_SIZE(2)] = {
	23, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 61, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 21, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector4_23_Clipdata[280] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_23_clipdata.rle")
};

const u8 sSector4_23_Bg2[184] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_23_bg2.rle")
};

const u8 sSector4_23_Bg1[1176] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_23_bg1.rle")
};

const u8 sSector4_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	3, 26, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	4, 24, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 32, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 37, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	5, 44, SPRITESET_IDX(1),
	5, 49, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 54, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 26, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 41, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 56, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	7, 34, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 34, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

