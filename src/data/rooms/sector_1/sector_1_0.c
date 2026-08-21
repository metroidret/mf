#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_0_Scrolls[SCROLL_DATA_SIZE(1)] = {
	0, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector1_0_Clipdata[219] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_0_clipdata.rle")
};

const u8 sSector1_0_Bg2[178] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_0_bg2.rle")
};

const u8 sSector1_0_Bg1[465] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_0_bg1.rle")
};

const u8 sSector1_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	0, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	0, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	10, 14, SPRITESET_IDX(1),
	13, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	16, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	20, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	23, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

