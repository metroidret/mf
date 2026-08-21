#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_14_Scrolls[SCROLL_DATA_SIZE(2)] = {
	14, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_14_Clipdata[138] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_14_clipdata.rle")
};

const u8 sSector6_14_Bg2[149] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_14_bg2.rle")
};

const u8 sSector6_14_Bg1[494] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_14_bg1.rle")
};

const u8 sSector6_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	3, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	3, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	11, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	12, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	13, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	17, 27, SPRITESET_IDX(1),
	18, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

