#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_47_Scrolls[SCROLL_DATA_SIZE(2)] = {
	47, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 23, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	22, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_47_Clipdata[320] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_47_clipdata.rle")
};

const u8 sSector2_47_Bg2[1547] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_47_bg2.rle")
};

const u8 sSector2_47_Bg1[912] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_47_bg1.rle")
};

const u8 sSector2_47_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	16, 13, SPRITESET_IDX(0),
	18, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

