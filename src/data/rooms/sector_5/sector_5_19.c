#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_19_Scrolls[SCROLL_DATA_SIZE(2)] = {
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
	2, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_19_Clipdata[128] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_19_clipdata.rle")
};

const u8 sSector5_19_Bg2[192] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_19_bg2.rle")
};

const u8 sSector5_19_Bg1[546] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_19_bg1.rle")
};

const u8 sSector5_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(18)] = {
	6, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	13, 22, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 23, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 6, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	15, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	15, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 17, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	18, 16, SPRITESET_IDX(1),
	18, 18, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	20, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	20, 11, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	20, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	20, 23, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	20, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

