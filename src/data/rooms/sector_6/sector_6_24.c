#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_24_Scrolls[SCROLL_DATA_SIZE(1)] = {
	24, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	16, 10, // Breakable block position
	1, // Breakable block direction
	31, // Breakable block Y bound extension
};

const u8 sSector6_24_Clipdata[105] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_24_clipdata.rle")
};

const u8 sSector6_24_Bg2[243] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_24_bg2.rle")
};

const u8 sSector6_24_Bg1[217] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_24_bg1.rle")
};

const u8 sSector6_24_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	6, 10, SPRITESET_IDX(1),
	10, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

