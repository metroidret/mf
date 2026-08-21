#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_29_Clipdata[83] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_29_clipdata.rle")
};

const u8 sSector1_29_Bg2[14] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_29_bg2.rle")
};

const u8 sSector1_29_Bg1[292] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_29_bg1.rle")
};

const u8 sSector1_29_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	0, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	0, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	0, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	0, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	4, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	4, 14, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	4, 21, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	4, 26, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	5, 17, SPRITESET_IDX(2),
	7, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	7, 24, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_29_Bg0[161] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_29_bg0.rle")
};

