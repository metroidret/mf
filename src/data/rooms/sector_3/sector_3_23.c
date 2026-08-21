#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_23_Scrolls[SCROLL_DATA_SIZE(2)] = {
	23, // Room
	2, // Number of scrolls
	
	// Scroll 0
	16, 31, // X bounds
	2, 12, // Y bounds
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

const u8 sSector3_23_Clipdata[143] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_23_clipdata.rle")
};

const u8 sSector3_23_Bg2[148] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_23_bg2.rle")
};

const u8 sSector3_23_Bg1[598] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_23_bg1.rle")
};

const u8 sSector3_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	5, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	20, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	20, 26, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

