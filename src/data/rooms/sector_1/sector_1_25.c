#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_25_Clipdata[96] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_25_clipdata.rle")
};

const u8 sSector1_25_Bg2[306] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_25_bg2.rle")
};

const u8 sSector1_25_Bg1[253] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_25_bg1.rle")
};

const u8 sSector1_25_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	2, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	2, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	2, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	2, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	2, 29, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 14, SPRITESET_IDX(0),
	10, 27, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

