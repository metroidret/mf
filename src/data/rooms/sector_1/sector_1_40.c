#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_40_Scrolls[SCROLL_DATA_SIZE(2)] = {
	40, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	12, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector1_40_Clipdata[181] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_40_clipdata.rle")
};

const u8 sSector1_40_Bg2[261] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_40_bg2.rle")
};

const u8 sSector1_40_Bg1[538] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_40_bg1.rle")
};

const u8 sSector1_40_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	21, 18, SPRITESET_IDX(2),
	22, 18, SPRITESET_IDX(14),
	29, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

