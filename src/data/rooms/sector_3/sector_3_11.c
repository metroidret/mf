#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_11_Scrolls[SCROLL_DATA_SIZE(1)] = {
	11, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	3, 15, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector3_11_Clipdata[153] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_11_clipdata.rle")
};

const u8 sSector3_11_Bg2[512] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_11_bg2.rle")
};

const u8 sSector3_11_Bg1[692] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_11_bg1.rle")
};

const u8 sSector3_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	4, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	4, 39, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	5, 33, SPRITESET_IDX(1),
	9, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	9, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	9, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	9, 33, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	9, 38, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	9, 51, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_11_Bg0[178] = {
    64, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_11_bg0.rle")
};

