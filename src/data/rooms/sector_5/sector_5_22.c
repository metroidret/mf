#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_22_Scrolls[SCROLL_DATA_SIZE(3)] = {
	22, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	32, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	2, 34, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	39, 49, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_22_Clipdata[272] = {
    19, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_22_clipdata.rle")
};

const u8 sSector5_22_Bg2[252] = {
    19, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_22_bg2.rle")
};

const u8 sSector5_22_Bg1[747] = {
    19, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_22_bg1.rle")
};

const u8 sSector5_22_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	14, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	19, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	24, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	41, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	42, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	44, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	45, 10, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

