#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_8_Scrolls[SCROLL_DATA_SIZE(2)] = {
	8, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	30, 46, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_8_Clipdata[436] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_8_clipdata.rle")
};

const u8 sSector6_8_Bg2[366] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_8_bg2.rle")
};

const u8 sSector6_8_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	3, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	7, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	8, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	12, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	12, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	13, 16, SPRITESET_IDX(1),
	18, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	20, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	22, 17, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	23, 41, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	24, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_8_Bg1[892] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_8_bg1.rle")
};

const u8 sSector6_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	7, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	13, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	13, 15, SPRITESET_IDX(1),
	23, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	23, 41, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	24, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

