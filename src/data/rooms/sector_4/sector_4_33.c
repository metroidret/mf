#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_33_Scrolls[SCROLL_DATA_SIZE(2)] = {
	33, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 61, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 17, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector4_33_Clipdata[292] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_33_clipdata.rle")
};

const u8 sSector4_33_Bg2[386] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_33_bg2.rle")
};

const u8 sSector4_33_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	8, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	12, 43, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	17, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	17, 43, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_33_Bg1[942] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_33_bg1.rle")
};

const u8 sSector4_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	8, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	10, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	10, 41, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	12, 43, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	17, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	17, 43, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	23, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

