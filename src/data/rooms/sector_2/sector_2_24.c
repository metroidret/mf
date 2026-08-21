#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_24_Scrolls[SCROLL_DATA_SIZE(2)] = {
	24, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	15, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_24_Clipdata[103] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_24_clipdata.rle")
};

const u8 sSector2_24_Bg2[110] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_24_bg2.rle")
};

const u8 sSector2_24_Bg1[452] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_24_bg1.rle")
};

const u8 sSector2_24_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	18, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_24_Bg0[382] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_24_bg0.rle")
};

