#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_20_Scrolls[SCROLL_DATA_SIZE(3)] = {
	20, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	12, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	17, 31, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_20_Clipdata[430] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_20_clipdata.rle")
};

const u8 sSector2_20_Bg2[254] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_20_bg2.rle")
};

const u8 sSector2_20_Bg1[1270] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_20_bg1.rle")
};

const u8 sSector2_20_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	4, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	5, 20, SPRITESET_IDX(0),
	14, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	17, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	23, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	24, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	25, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	28, 31, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_20_Bg0[991] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_20_bg0.rle")
};

