#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_57_Scrolls[SCROLL_DATA_SIZE(3)] = {
	57, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 18, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	17, 31, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_57_Clipdata[168] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_57_clipdata.rle")
};

const u8 sSector2_57_Bg2[128] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_57_bg2.rle")
};

const u8 sSector2_57_Bg1[665] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_57_bg1.rle")
};

const u8 sSector2_57_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	6, 24, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	7, 30, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	8, 36, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	8, 41, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_57_Bg0[501] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_57_bg0.rle")
};

