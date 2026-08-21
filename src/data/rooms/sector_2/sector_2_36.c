#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_36_Scrolls[SCROLL_DATA_SIZE(2)] = {
	36, // Room
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

const u8 sSector2_36_Clipdata[104] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_36_clipdata.rle")
};

const u8 sSector2_36_Bg2[110] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_36_bg2.rle")
};

const u8 sSector2_36_Bg1[452] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_36_bg1.rle")
};

const u8 sSector2_36_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	12, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	14, 10, SPRITESET_IDX(1),
	18, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

