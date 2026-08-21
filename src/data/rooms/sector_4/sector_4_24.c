#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_24_Scrolls[SCROLL_DATA_SIZE(3)] = {
	24, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	18, 32, // X bounds
	2, 12, // Y bounds
	18, 4, // Breakable block position
	0, // Breakable block direction
	2, // Breakable block Y bound extension

	// Scroll 2
	32, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector4_24_Clipdata[339] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_24_clipdata.rle")
};

const u8 sSector4_24_Bg2[455] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_24_bg2.rle")
};

const u8 sSector4_24_Bg1[988] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_24_bg1.rle")
};

const u8 sSector4_24_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	5, 25, SPRITESET_IDX(2),
	6, 21, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	6, 29, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	13, 21, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 27, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 36, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	18, 34, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	19, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

