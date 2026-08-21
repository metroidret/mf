#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_4_Scrolls[SCROLL_DATA_SIZE(2)] = {
	4, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 18, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_4_Clipdata[86] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_4_clipdata.rle")
};

const u8 sSector5_4_Bg2[75] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_4_bg2.rle")
};

const u8 sSector5_4_Bg1[257] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_4_bg1.rle")
};

const u8 sSector5_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	7, 25, SPRITESET_IDX(1),
	10, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

