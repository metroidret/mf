#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_5_Scrolls[SCROLL_DATA_SIZE(3)] = {
	5, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	15, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	16, 31, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector6_5_Clipdata[309] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_5_clipdata.rle")
};

const u8 sSector6_5_Bg2[297] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_5_bg2.rle")
};

const u8 sSector6_5_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	3, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	7, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	11, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	20, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	20, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	27, 12, SPRITESET_IDX(1),
	28, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	31, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	37, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_5_Bg1[736] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_5_bg1.rle")
};

const u8 sSector6_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	3, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	27, 12, SPRITESET_IDX(1),
	37, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

