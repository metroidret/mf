#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_19_Scrolls[SCROLL_DATA_SIZE(4)] = {
	19, // Room
	4, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 46, // X bounds
	12, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	17, 46, // X bounds
	7, 27, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 3
	46, 61, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector3_19_Clipdata[306] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_19_clipdata.rle")
};

const u8 sSector3_19_Bg2[14] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_19_bg2.rle")
};

const u8 sSector3_19_Bg1[1187] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_19_bg1.rle")
};

const u8 sSector3_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	16, 37, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	17, 34, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 26, SPRITESET_IDX(1),
	18, 29, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	20, 6, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	20, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_19_Bg0[23] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_19_bg0.rle")
};

