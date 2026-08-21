#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_27_Scrolls[SCROLL_DATA_SIZE(2)] = {
	27, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	9, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_27_Clipdata[181] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_27_clipdata.rle")
};

const u8 sSector6_27_Bg2[104] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_27_bg2.rle")
};

const u8 sSector6_27_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	6, 23, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_27_Bg1[495] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_27_bg1.rle")
};

const u8 sSector6_27_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	7, 17, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

