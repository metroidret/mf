#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_35_Clipdata[314] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_35_clipdata.rle")
};

const u8 sSector1_35_Bg2[123] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_35_bg2.rle")
};

const u8 sSector1_35_Bg1[603] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_35_bg1.rle")
};

const u8 sSector1_35_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	13, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	18, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	18, 10, SPRITESET_IDX(1),
	23, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	28, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	33, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

