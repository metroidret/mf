#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_31_Scrolls[SCROLL_DATA_SIZE(3)] = {
	31, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	31, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 31, // X bounds
	21, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_31_Clipdata[206] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_31_clipdata.rle")
};

const u8 sSector2_31_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	5, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	14, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	15, 15, SPRITESET_IDX(1),
	16, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	16, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	26, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	26, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	28, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	29, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_31_Bg2[411] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_31_bg2.rle")
};

const u8 sSector2_31_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	6, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	13, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	15, 14, SPRITESET_IDX(0),
	18, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	26, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	26, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	29, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_31_Bg1[1035] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_31_bg1.rle")
};

const u8 sSector2_31_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	4, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	5, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	15, 13, SPRITESET_IDX(0),
	18, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	26, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	26, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	29, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

