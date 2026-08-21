#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_19_Scrolls[SCROLL_DATA_SIZE(2)] = {
	19, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_19_Clipdata[176] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_19_clipdata.rle")
};

const u8 sSector6_19_Bg2[14] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_19_bg2.rle")
};

const u8 sSector6_19_Bg1[594] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_19_bg1.rle")
};

const u8 sSector6_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	4, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	6, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	14, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	16, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	16, 12, SPRITESET_IDX(1),
	17, 29, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	19, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

