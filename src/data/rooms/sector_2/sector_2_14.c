#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_14_Clipdata[78] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_14_clipdata.rle")
};

const u8 sSector2_14_Bg2[230] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_14_bg2.rle")
};

const u8 sSector2_14_Bg1[259] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_14_bg1.rle")
};

const u8 sSector2_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	3, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	3, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	3, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	6, 16, SPRITESET_IDX(1),
	9, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	9, 11, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	9, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	9, 18, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	9, 22, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

