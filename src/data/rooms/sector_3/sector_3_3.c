#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_3_Scrolls[SCROLL_DATA_SIZE(3)] = {
	3, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 48, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	47, 61, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	32, 46, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector3_3_Clipdata[185] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_3_clipdata.rle")
};

const u8 sSector3_3_Bg2[492] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_3_bg2.rle")
};

const u8 sSector3_3_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	0, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	0, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	0, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	4, 36, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	5, 31, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	5, 41, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	6, 29, SPRITESET_IDX(1),
	10, 25, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	10, 30, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	10, 44, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	20, 43, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	20, 45, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_3_Bg1[514] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_3_bg1.rle")
};

const u8 sSector3_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 30, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

