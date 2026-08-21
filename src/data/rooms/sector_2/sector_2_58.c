#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_58_Scrolls[SCROLL_DATA_SIZE(3)] = {
	58, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 18, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	17, 31, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_58_Clipdata[155] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_58_clipdata.rle")
};

const u8 sSector2_58_Bg2[128] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_58_bg2.rle")
};

const u8 sSector2_58_Bg1[665] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_58_bg1.rle")
};

const u8 sSector2_58_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	6, 24, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	6, 33, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	7, 27, SPRITESET_IDX(1),
	7, 30, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	7, 34, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 36, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	15, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	15, 15, SPRITESET_IDX(1),
	18, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

