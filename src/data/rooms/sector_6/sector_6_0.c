#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_0_Scrolls[SCROLL_DATA_SIZE(2)] = {
	0, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 46, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 19, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_0_Clipdata[182] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_0_clipdata.rle")
};

const u8 sSector6_0_Bg2[239] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_0_bg2.rle")
};

const u8 sSector6_0_Bg1[721] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_0_bg1.rle")
};

const u8 sSector6_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	3, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	3, 43, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 31, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 31, SPRITESET_IDX(1),
	8, 33, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 29, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	10, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	10, 38, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	15, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

