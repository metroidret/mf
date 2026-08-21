#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_7_Scrolls[SCROLL_DATA_SIZE(2)] = {
	7, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	31, 46, // X bounds
	22, 38, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector5_7_Clipdata[426] = {
    49, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_7_clipdata.rle")
};

const u8 sSector5_7_Bg2[613] = {
    49, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_7_bg2.rle")
};

const u8 sSector5_7_Bg1[1618] = {
    49, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_7_bg1.rle")
};

const u8 sSector5_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(17)] = {
	5, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	6, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	7, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	16, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	17, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	18, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	28, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	28, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	33, 36, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	34, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	36, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	36, 16, SPRITESET_IDX(1),
	38, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	43, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	45, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	45, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

