#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_24_Scrolls[SCROLL_DATA_SIZE(3)] = {
	24, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	19, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	31, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_24_Clipdata[228] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_24_clipdata.rle")
};

const u8 sSector5_24_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	40, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector5_24_Bg2[923] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_24_bg2.rle")
};

const u8 sSector5_24_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	21, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	28, 9, SPRITESET_IDX(0),
	30, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector5_24_Bg1[463] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_24_bg1.rle")
};

const u8 sSector5_24_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	17, 9, SPRITESET_IDX(1),
	30, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

