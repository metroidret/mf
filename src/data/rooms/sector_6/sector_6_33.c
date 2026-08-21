#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_33_Scrolls[SCROLL_DATA_SIZE(3)] = {
	33, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	9, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	17, 61, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_33_Clipdata[238] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_33_clipdata.rle")
};

const u8 sSector6_33_Bg2[14] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_33_bg2.rle")
};

const u8 sSector6_33_Bg1[748] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_33_bg1.rle")
};

const u8 sSector6_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	3, 45, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	4, 42, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	4, 48, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	6, 34, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 40, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	6, 45, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	8, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 29, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 33, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	10, 47, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	13, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	14, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	16, 24, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

