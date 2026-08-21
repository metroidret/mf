#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_22_Scrolls[SCROLL_DATA_SIZE(2)] = {
	22, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector3_22_Clipdata[165] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_22_clipdata.rle")
};

const u8 sSector3_22_Bg2[468] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_22_bg2.rle")
};

const u8 sSector3_22_Bg1[768] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_22_bg1.rle")
};

const u8 sSector3_22_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	4, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_22_Bg0[310] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_22_bg0.rle")
};

