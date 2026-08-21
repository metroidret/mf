#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_27_Scrolls[SCROLL_DATA_SIZE(2)] = {
	27, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 21, // Y bounds
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

const u8 sSector2_27_Clipdata[142] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_27_clipdata.rle")
};

const u8 sSector2_27_Bg2[227] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_27_bg2.rle")
};

const u8 sSector2_27_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	4, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	12, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	15, 12, SPRITESET_IDX(1),
	15, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	18, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_27_Bg1[449] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_27_bg1.rle")
};

const u8 sSector2_27_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	15, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	16, 13, SPRITESET_IDX(1),
	18, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

