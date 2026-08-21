#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_31_Scrolls[SCROLL_DATA_SIZE(1)] = {
	31, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sSector1_31_Clipdata[104] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_31_clipdata.rle")
};

const u8 sSector1_31_Bg2[262] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_31_bg2.rle")
};

const u8 sSector1_31_Bg1[351] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_31_bg1.rle")
};

const u8 sSector1_31_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

