#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_28_Scrolls[SCROLL_DATA_SIZE(1)] = {
	28, // Room
	1, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	2, 11, // Y bounds
	17, 10, // Breakable block position
	0, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sSector6_28_Clipdata[118] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_28_clipdata.rle")
};

const u8 sSector6_28_Bg2[14] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_28_bg2.rle")
};

const u8 sSector6_28_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	3, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	3, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	4, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 24, SPRITESET_IDX(1),
	6, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	7, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	8, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_28_Bg1[254] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_28_bg1.rle")
};

const u8 sSector6_28_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 22, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

