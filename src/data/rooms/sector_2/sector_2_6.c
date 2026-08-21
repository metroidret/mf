#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_6_Scrolls[SCROLL_DATA_SIZE(1)] = {
	6, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	16, 6, // Breakable block position
	1, // Breakable block direction
	31, // Breakable block Y bound extension
};

const u8 sSector2_6_Clipdata[95] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_6_clipdata.rle")
};

const u8 sSector2_6_Bg2[181] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_6_bg2.rle")
};

const u8 sSector2_6_Bg1[260] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_6_bg1.rle")
};

const u8 sSector2_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	3, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	5, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 10, SPRITESET_IDX(1),
	8, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	10, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

