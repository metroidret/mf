#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_39_Scrolls[SCROLL_DATA_SIZE(3)] = {
	39, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	16, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector1_39_Clipdata[159] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_39_clipdata.rle")
};

const u8 sSector1_39_Bg2[176] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_39_bg2.rle")
};

const u8 sSector1_39_Bg1[572] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_39_bg1.rle")
};

const u8 sSector1_39_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	14, 8, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

