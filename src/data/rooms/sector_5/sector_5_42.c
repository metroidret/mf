#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_42_Scrolls[SCROLL_DATA_SIZE(2)] = {
	42, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_42_Clipdata[123] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_42_clipdata.rle")
};

const u8 sSector5_42_Bg2[148] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_42_bg2.rle")
};

const u8 sSector5_42_Bg1[488] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_42_bg1.rle")
};

const u8 sSector5_42_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	4, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	5, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	8, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	15, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	16, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	16, 12, SPRITESET_IDX(1),
	16, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	17, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

