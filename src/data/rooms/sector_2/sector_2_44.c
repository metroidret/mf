#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_44_Scrolls[SCROLL_DATA_SIZE(1)] = {
	44, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector2_44_Clipdata[120] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_44_clipdata.rle")
};

const u8 sSector2_44_Bg2[226] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_44_bg2.rle")
};

const u8 sSector2_44_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	3, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	3, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	3, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	4, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	5, 16, SPRITESET_IDX(2),
	6, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	7, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	9, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_44_Bg1[334] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_44_bg1.rle")
};

const u8 sSector2_44_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	3, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	3, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	3, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	6, 16, SPRITESET_IDX(2),
	9, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

