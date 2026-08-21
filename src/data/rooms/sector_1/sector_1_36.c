#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_36_Scrolls[SCROLL_DATA_SIZE(2)] = {
	36, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 18, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	16, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector1_36_Clipdata[229] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_36_clipdata.rle")
};

const u8 sSector1_36_Bg2[14] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_36_bg2.rle")
};

const u8 sSector1_36_Bg1[442] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_36_bg1.rle")
};

const u8 sSector1_36_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	5, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 28, SPRITESET_IDX(1),
	7, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	7, 37, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	8, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	9, 32, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_36_Bg0[221] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_36_bg0.rle")
};

