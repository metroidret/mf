#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_28_Scrolls[SCROLL_DATA_SIZE(4)] = {
	28, // Room
	4, // Number of scrolls
	
	// Scroll 0
	2, 32, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 25, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 3
	2, 16, // X bounds
	31, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector3_28_Clipdata[411] = {
    49, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_28_clipdata.rle")
};

const u8 sSector3_28_Bg2[384] = {
    49, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_28_bg2.rle")
};

const u8 sSector3_28_Bg1[1288] = {
    49, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_28_bg1.rle")
};

const u8 sSector3_28_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	21, 22, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

