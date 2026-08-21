#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	10, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	29, 39, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_10_Clipdata[282] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_10_clipdata.rle")
};

const u8 sSector2_10_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	3, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	4, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	11, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	11, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	14, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	14, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	19, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	20, 15, SPRITESET_IDX(1),
	20, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	26, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	27, 3, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	27, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	30, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_10_Bg2[776] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_10_bg2.rle")
};

const u8 sSector2_10_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	3, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	4, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	11, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	16, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	19, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	20, 15, SPRITESET_IDX(1),
	26, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	27, 3, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_10_Bg1[1295] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_10_bg1.rle")
};

const u8 sSector2_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	4, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	11, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	16, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	19, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	22, 23, SPRITESET_IDX(1),
	28, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	30, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	30, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	35, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

