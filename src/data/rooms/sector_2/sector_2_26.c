#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_26_Scrolls[SCROLL_DATA_SIZE(2)] = {
	26, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_26_Clipdata[144] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_26_clipdata.rle")
};

const u8 sSector2_26_Bg2[920] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_26_bg2.rle")
};

const u8 sSector2_26_Bg1[367] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_26_bg1.rle")
};

const u8 sSector2_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	20, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

