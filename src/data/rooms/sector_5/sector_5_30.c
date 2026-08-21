#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_30_Scrolls[SCROLL_DATA_SIZE(2)] = {
	30, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	2, 11, // Y bounds
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

const u8 sSector5_30_Clipdata[135] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_30_clipdata.rle")
};

const u8 sSector5_30_Bg2[138] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_30_bg2.rle")
};

const u8 sSector5_30_Bg1[341] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_30_bg1.rle")
};

const u8 sSector5_30_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	3, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	4, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	4, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	6, 26, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	7, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	7, 27, SPRITESET_IDX(1),
	10, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

