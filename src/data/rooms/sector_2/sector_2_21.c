#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_21_Scrolls[SCROLL_DATA_SIZE(2)] = {
	21, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	16, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_21_Clipdata[143] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_21_clipdata.rle")
};

const u8 sSector2_21_Bg2[212] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_21_bg2.rle")
};

const u8 sSector2_21_Bg1[361] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_21_bg1.rle")
};

const u8 sSector2_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 11, SPRITESET_IDX(1),
	9, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	9, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

