#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_6_Scrolls[SCROLL_DATA_SIZE(3)] = {
	6, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 17, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	17, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector3_6_Clipdata[201] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_6_clipdata.rle")
};

const u8 sSector3_6_Bg2[358] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_6_bg2.rle")
};

const u8 sSector3_6_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	5, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	7, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	9, 17, SPRITESET_IDX(1),
	9, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	11, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	11, 14, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	11, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_6_Bg1[489] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_6_bg1.rle")
};

const u8 sSector3_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

