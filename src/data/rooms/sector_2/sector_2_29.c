#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_29_Scrolls[SCROLL_DATA_SIZE(1)] = {
	29, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sSector2_29_Clipdata[122] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_29_clipdata.rle")
};

const u8 sSector2_29_Bg2[136] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_29_bg2.rle")
};

const u8 sSector2_29_Bg1[400] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_29_bg1.rle")
};

const u8 sSector2_29_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	15, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

