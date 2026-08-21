#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_16_Scrolls[SCROLL_DATA_SIZE(2)] = {
	16, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_16_Clipdata[179] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_16_clipdata.rle")
};

const u8 sSector6_16_Bg2[156] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_16_bg2.rle")
};

const u8 sSector6_16_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	14, 16, SPRITESET_IDX(2),
	15, 18, SPRITESET_IDX(14),
	20, 24, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_16_Bg1[431] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_16_bg1.rle")
};

const u8 sSector6_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	15, 18, SPRITESET_IDX(14),
	ROOM_SPRITE_DATA_TERMINATOR
};

