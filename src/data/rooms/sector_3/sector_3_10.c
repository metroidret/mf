#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_10_Clipdata[434] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_10_clipdata.rle")
};

const u8 sSector3_10_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	14, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	26, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	33, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	43, 10, SPRITESET_IDX(0),
	45, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	53, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	60, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_10_Bg2[649] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_10_bg2.rle")
};

const u8 sSector3_10_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	14, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	26, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	33, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	43, 10, SPRITESET_IDX(0),
	45, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	53, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	60, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_10_Bg1[1267] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_10_bg1.rle")
};

const u8 sSector3_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

