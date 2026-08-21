#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_33_Scrolls[SCROLL_DATA_SIZE(2)] = {
	33, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 18, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_33_Clipdata[102] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_33_clipdata.rle")
};

const u8 sSector2_33_Bg2[161] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_33_bg2.rle")
};

const u8 sSector2_33_Bg1[318] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_33_bg1.rle")
};

const u8 sSector2_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 30, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	4, 37, SPRITESET_IDX(1),
	5, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	10, 26, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	10, 38, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

