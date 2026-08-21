#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_12_Scrolls[SCROLL_DATA_SIZE(2)] = {
	12, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	21, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector3_12_Clipdata[456] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_12_clipdata.rle")
};

const u8 sSector3_12_Bg2[245] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_12_bg2.rle")
};

const u8 sSector3_12_Bg1[1432] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_12_bg1.rle")
};

const u8 sSector3_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	8, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	11, 22, SPRITESET_IDX(1),
	13, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	27, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	32, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	37, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	39, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_12_Bg0[23] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_12_bg0.rle")
};

