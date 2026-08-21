#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_0_Clipdata[472] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_0_clipdata.rle")
};

const u8 sSector3_0_Bg2[225] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_0_bg2.rle")
};

const u8 sSector3_0_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	12, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	13, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	18, 17, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	22, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	28, 14, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	28, 19, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	32, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	32, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_0_Bg1[953] = {
    34, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_0_bg1.rle")
};

const u8 sSector3_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	25, 15, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

