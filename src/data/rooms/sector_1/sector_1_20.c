#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_20_Scrolls[SCROLL_DATA_SIZE(2)] = {
	20, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	2, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector1_20_Clipdata[193] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_20_clipdata.rle")
};

const u8 sSector1_20_Bg2[50] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_20_bg2.rle")
};

const u8 sSector1_20_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	18, 26, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_20_Bg1[725] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_20_bg1.rle")
};

const u8 sSector1_20_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_20_Bg0[23] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_20_bg0.rle")
};

