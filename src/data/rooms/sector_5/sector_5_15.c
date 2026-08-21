#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_15_Scrolls[SCROLL_DATA_SIZE(2)] = {
	15, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	31, 46, // X bounds
	22, 36, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_15_Clipdata[439] = {
    49, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_15_clipdata.rle")
};

const u8 sSector5_15_Bg2[396] = {
    49, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_15_bg2.rle")
};

const u8 sSector5_15_Bg1[1790] = {
    49, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_15_bg1.rle")
};

const u8 sSector5_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	3, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	3, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	4, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	5, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	15, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	15, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	16, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	28, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	34, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	36, 16, SPRITESET_IDX(1),
	37, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	44, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	44, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	46, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

