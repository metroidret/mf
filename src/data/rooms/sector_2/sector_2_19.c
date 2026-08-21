#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_19_Scrolls[SCROLL_DATA_SIZE(2)] = {
	19, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	20, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_19_Clipdata[233] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_19_clipdata.rle")
};

const u8 sSector2_19_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	9, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	11, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	15, 8, SPRITESET_IDX(1),
	15, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	15, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_19_Bg2[257] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_19_bg2.rle")
};

const u8 sSector2_19_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	9, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	15, 8, SPRITESET_IDX(1),
	15, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_19_Bg1[607] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_19_bg1.rle")
};

const u8 sSector2_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	9, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	14, 8, SPRITESET_IDX(1),
	15, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

