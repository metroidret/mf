#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_50_Scrolls[SCROLL_DATA_SIZE(3)] = {
	50, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	16, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	5, 24, // X bounds
	2, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_50_Clipdata[164] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_50_clipdata.rle")
};

const u8 sSector5_50_Bg2[605] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_50_bg2.rle")
};

const u8 sSector5_50_Bg1[818] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_50_bg1.rle")
};

const u8 sSector5_50_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

