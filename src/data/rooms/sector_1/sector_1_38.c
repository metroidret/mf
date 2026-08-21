#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_38_Scrolls[SCROLL_DATA_SIZE(1)] = {
	38, // Room
	1, // Number of scrolls
	
	// Scroll 0
	9, 46, // X bounds
	2, 11, // Y bounds
	9, 4, // Breakable block position
	0, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sSector1_38_Clipdata[170] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_38_clipdata.rle")
};

const u8 sSector1_38_Bg2[152] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_38_bg2.rle")
};

const u8 sSector1_38_Bg1[499] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_38_bg1.rle")
};

const u8 sSector1_38_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 25, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	3, 30, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	6, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	7, 24, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	9, 20, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	10, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

