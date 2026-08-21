#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_35_Scrolls[SCROLL_DATA_SIZE(2)] = {
	35, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	41, 71, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sSector4_35_Clipdata[360] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_35_clipdata.rle")
};

const u8 sSector4_35_Bg2[14] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_35_bg2.rle")
};

const u8 sSector4_35_Bg1[1374] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_35_bg1.rle")
};

const u8 sSector4_35_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	17, 12, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	20, 18, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	22, 5, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	23, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	27, 0, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	29, 12, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	31, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	33, 0, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	36, 5, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	38, 9, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	38, 18, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	40, 18, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	43, 0, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	44, 0, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

