#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_18_Scrolls[SCROLL_DATA_SIZE(2)] = {
	18, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_18_Clipdata[177] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_18_clipdata.rle")
};

const u8 sSector6_18_Bg2[14] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_18_bg2.rle")
};

const u8 sSector6_18_Bg1[562] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_18_bg1.rle")
};

const u8 sSector6_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	3, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	4, 5, SPRITESET_IDX(0),
	8, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	9, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	20, 27, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

