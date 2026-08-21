#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_17_Scrolls[SCROLL_DATA_SIZE(2)] = {
	17, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector4_17_Clipdata[328] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_17_clipdata.rle")
};

const u8 sSector4_17_Bg2[283] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_17_bg2.rle")
};

const u8 sSector4_17_Bg1[554] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_17_bg1.rle")
};

const u8 sSector4_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(16)] = {
	6, 12, SPRITESET_IDX(2),
	9, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	9, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	13, 20, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 25, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	14, 23, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	14, 27, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 21, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	17, 33, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	19, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	22, 32, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	23, 17, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	23, 20, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	23, 25, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	23, 30, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

