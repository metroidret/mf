#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_12_Scrolls[SCROLL_DATA_SIZE(2)] = {
	12, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 19, // X bounds
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

const u8 sSector6_12_Clipdata[88] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_12_clipdata.rle")
};

const u8 sSector6_12_Bg2[14] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_12_bg2.rle")
};

const u8 sSector6_12_Bg1[366] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_12_bg1.rle")
};

const u8 sSector6_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	4, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	5, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	7, 24, SPRITESET_IDX(0),
	8, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	8, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	9, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

