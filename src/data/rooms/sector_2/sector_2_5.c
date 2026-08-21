#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_5_Scrolls[SCROLL_DATA_SIZE(2)] = {
	5, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	16, 31, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_5_Clipdata[232] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_5_clipdata.rle")
};

const u8 sSector2_5_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	4, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	17, 8, SPRITESET_IDX(1),
	17, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	19, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	27, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	29, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_5_Bg2[400] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_5_bg2.rle")
};

const u8 sSector2_5_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	17, 9, SPRITESET_IDX(1),
	19, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	29, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_5_Bg1[895] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_5_bg1.rle")
};

const u8 sSector2_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	8, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	17, 9, SPRITESET_IDX(1),
	19, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	29, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

