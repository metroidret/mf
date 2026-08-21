#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_30_Scrolls[SCROLL_DATA_SIZE(2)] = {
	30, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 18, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_30_Clipdata[283] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_30_clipdata.rle")
};

const u8 sSector6_30_Bg2[14] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_30_bg2.rle")
};

const u8 sSector6_30_Bg1[869] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_30_bg1.rle")
};

const u8 sSector6_30_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	3, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	12, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	14, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	14, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	14, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	23, 29, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	27, 24, SPRITESET_IDX(0),
	33, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

