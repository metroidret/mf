#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_30_Clipdata[247] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_30_clipdata.rle")
};

const u8 sSector1_30_Bg2[14] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_30_bg2.rle")
};

const u8 sSector1_30_Bg1[599] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_30_bg1.rle")
};

const u8 sSector1_30_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	8, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	12, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	12, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	15, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	18, 19, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	18, 25, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	19, 21, SPRITESET_IDX(2),
	23, 17, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	23, 23, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

