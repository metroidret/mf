#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_34_Scrolls[SCROLL_DATA_SIZE(2)] = {
	34, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	16, 31, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector3_34_Clipdata[182] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_34_clipdata.rle")
};

const u8 sSector3_34_Bg2[260] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_34_bg2.rle")
};

const u8 sSector3_34_Bg1[541] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_34_bg1.rle")
};

const u8 sSector3_34_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	13, 22, SPRITESET_IDX(1),
	14, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	16, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	16, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	17, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	19, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	19, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

