#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_20_Scrolls[SCROLL_DATA_SIZE(1)] = {
	20, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_20_Clipdata[118] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_20_clipdata.rle")
};

const u8 sSector5_20_Bg2[68] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_20_bg2.rle")
};

const u8 sSector5_20_Bg1[391] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_20_bg1.rle")
};

const u8 sSector5_20_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	15, 8, SPRITESET_IDX(1),
	15, 10, SPRITESET_IDX(14),
	15, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

