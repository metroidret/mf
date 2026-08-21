#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_13_Scrolls[SCROLL_DATA_SIZE(2)] = {
	13, // Room
	2, // Number of scrolls
	
	// Scroll 0
	32, 46, // X bounds
	2, 31, // Y bounds
	30, 9, // Breakable block position
	0, // Breakable block direction
	17, // Breakable block Y bound extension

	// Scroll 1
	2, 46, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector4_13_Clipdata[386] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_13_clipdata.rle")
};

const u8 sSector4_13_Bg2[499] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_13_bg2.rle")
};

const u8 sSector4_13_Bg1[1145] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_13_bg1.rle")
};

const u8 sSector4_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	5, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	5, 28, SPRITESET_IDX(0),
	8, 41, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	12, 43, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	17, 20, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	17, 28, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	18, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	19, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	22, 41, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	24, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	26, 26, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	26, 40, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	28, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

