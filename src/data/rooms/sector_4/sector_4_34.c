#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_34_Scrolls[SCROLL_DATA_SIZE(3)] = {
	34, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	21, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector4_34_Clipdata[433] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_34_clipdata.rle")
};

const u8 sSector4_34_Bg2[440] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_34_bg2.rle")
};

const u8 sSector4_34_Bg1[1402] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_34_bg1.rle")
};

const u8 sSector4_34_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(18)] = {
	0, 13, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	0, 25, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 0, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 20, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	5, 26, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	6, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 10, SPRITESET_IDX(1),
	9, 29, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	11, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	18, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	19, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	21, 6, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	21, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	29, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	29, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	31, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	35, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

