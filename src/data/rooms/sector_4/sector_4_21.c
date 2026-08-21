#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_21_Scrolls[SCROLL_DATA_SIZE(2)] = {
	21, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	32, 41, // Y bounds
	13, 34, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	39, 61, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector4_21_Clipdata[457] = {
    19, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_21_clipdata.rle")
};

const u8 sSector4_21_Bg2[194] = {
    19, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_21_bg2.rle")
};

const u8 sSector4_21_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	10, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	14, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	21, 9, SPRITESET_IDX(2),
	22, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	31, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	42, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	44, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	46, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	47, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	48, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	54, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_21_Bg1[1097] = {
    19, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_21_bg1.rle")
};

const u8 sSector4_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	10, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	14, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	21, 9, SPRITESET_IDX(2),
	22, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	31, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	40, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	42, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	46, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	47, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	54, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	61, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

