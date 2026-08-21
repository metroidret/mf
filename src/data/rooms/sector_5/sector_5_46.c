#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_46_Scrolls[SCROLL_DATA_SIZE(2)] = {
	46, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 46, // X bounds
	2, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_46_Clipdata[120] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_46_clipdata.rle")
};

const u8 sSector5_46_Bg2[1011] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_46_bg2.rle")
};

const u8 sSector5_46_Bg1[630] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_46_bg1.rle")
};

const u8 sSector5_46_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	13, 37, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 33, SPRITESET_IDX(1),
	16, 20, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	16, 30, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	16, 38, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	18, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	18, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

