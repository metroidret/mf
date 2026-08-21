#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_8_Scrolls[SCROLL_DATA_SIZE(3)] = {
	8, // Room
	3, // Number of scrolls
	
	// Scroll 0
	32, 46, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	12, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector4_8_Clipdata[283] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_8_clipdata.rle")
};

const u8 sSector4_8_Bg2[342] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_8_bg2.rle")
};

const u8 sSector4_8_Bg1[817] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_8_bg1.rle")
};

const u8 sSector4_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	3, 43, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	13, 42, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	15, 33, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	17, 21, SPRITESET_IDX(2),
	20, 37, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	27, 5, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	33, 5, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	33, 10, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_8_Bg0[211] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_8_bg0.rle")
};

