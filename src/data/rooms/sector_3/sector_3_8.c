#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_8_Scrolls[SCROLL_DATA_SIZE(4)] = {
	8, // Room
	4, // Number of scrolls
	
	// Scroll 0
	32, 46, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	19, 36, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 3
	2, 21, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector3_8_Clipdata[256] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_8_clipdata.rle")
};

const u8 sSector3_8_Bg2[495] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_8_bg2.rle")
};

const u8 sSector3_8_Bg1[647] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_8_bg1.rle")
};

const u8 sSector3_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	15, 26, SPRITESET_IDX(1),
	20, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	20, 20, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	20, 24, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	20, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	20, 44, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	21, 22, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

