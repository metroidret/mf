#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_36_Scrolls[SCROLL_DATA_SIZE(3)] = {
	36, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	22, 34, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	32, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_36_Clipdata[240] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_36_clipdata.rle")
};

const u8 sSector5_36_Bg2[241] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_36_bg2.rle")
};

const u8 sSector5_36_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	30, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	36, 18, SPRITESET_IDX(1),
	38, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector5_36_Bg1[611] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_36_bg1.rle")
};

const u8 sSector5_36_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	6, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	6, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	12, 9, SPRITESET_IDX(1),
	15, 13, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	20, 4, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	20, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	20, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

