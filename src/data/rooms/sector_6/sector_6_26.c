#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_26_Scrolls[SCROLL_DATA_SIZE(2)] = {
	26, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	4, 7, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	12, 22, // Y bounds
	14, 12, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sSector6_26_Clipdata[124] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_26_clipdata.rle")
};

const u8 sSector6_26_Bg2[14] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_26_bg2.rle")
};

const u8 sSector6_26_Bg1[294] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_26_bg1.rle")
};

const u8 sSector6_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	20, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

