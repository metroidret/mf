#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_17_Scrolls[SCROLL_DATA_SIZE(3)] = {
	17, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	31, 46, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_17_Clipdata[177] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_17_clipdata.rle")
};

const u8 sSector2_17_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	3, 40, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	4, 42, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	5, 43, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	5, 45, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	14, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	14, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	15, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	17, 20, SPRITESET_IDX(1),
	17, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	17, 29, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	20, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_17_Bg2[404] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_17_bg2.rle")
};

const u8 sSector2_17_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	3, 39, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	5, 45, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	14, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	14, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	17, 20, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_17_Bg1[618] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_17_bg1.rle")
};

const u8 sSector2_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	3, 39, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	5, 45, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	14, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	14, 26, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	15, 24, SPRITESET_IDX(1),
	16, 45, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	20, 13, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	20, 16, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	20, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	20, 20, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

