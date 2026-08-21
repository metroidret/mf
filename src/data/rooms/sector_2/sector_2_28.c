#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_28_Clipdata[72] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_28_clipdata.rle")
};

const u8 sSector2_28_Bg2[163] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_28_bg2.rle")
};

const u8 sSector2_28_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	5, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 9, SPRITESET_IDX(1),
	6, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_28_Bg1[162] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_28_bg1.rle")
};

const u8 sSector2_28_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	4, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	5, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	5, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	7, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

