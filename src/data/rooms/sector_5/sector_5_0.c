#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_0_Scrolls[SCROLL_DATA_SIZE(2)] = {
	0, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	16, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_0_Clipdata[220] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_0_clipdata.rle")
};

const u8 sSector5_0_Bg2[14] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_0_bg2.rle")
};

const u8 sSector5_0_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	6, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	13, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	13, 10, SPRITESET_IDX(1),
	16, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	17, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	18, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	24, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	26, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector5_0_Bg1[730] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_0_bg1.rle")
};

const u8 sSector5_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	13, 10, SPRITESET_IDX(1),
	16, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	18, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	26, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

