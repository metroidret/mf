#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_22_Scrolls[SCROLL_DATA_SIZE(2)] = {
	22, // Room
	2, // Number of scrolls
	
	// Scroll 0
	3, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	11, 20, // Y bounds
	17, 19, // Breakable block position
	1, // Breakable block direction
	31, // Breakable block Y bound extension
};

const u8 sSector2_22_Clipdata[191] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_22_clipdata.rle")
};

const u8 sSector2_22_Bg2[359] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_22_bg2.rle")
};

const u8 sSector2_22_Bg1[543] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_22_bg1.rle")
};

const u8 sSector2_22_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	13, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	13, 25, SPRITESET_IDX(14),
	14, 3, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	16, 23, SPRITESET_IDX(0),
	19, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	20, 3, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	20, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	20, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_22_Bg0[62] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_22_bg0.rle")
};

