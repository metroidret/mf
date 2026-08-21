#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_7_Clipdata[134] = {
    79, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_7_clipdata.rle")
};

const u8 sSector1_7_Bg2[221] = {
    79, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_7_bg2.rle")
};

const u8 sSector1_7_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	3, 36, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 58, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 46, SPRITESET_IDX(1),
	10, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 43, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 56, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_7_Bg1[692] = {
    79, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_7_bg1.rle")
};

const u8 sSector1_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	6, 46, SPRITESET_IDX(1),
	10, 12, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 37, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 46, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 51, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 58, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

