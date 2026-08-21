#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_16_Clipdata[200] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_16_clipdata.rle")
};

const u8 sSector1_16_Bg2[223] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_16_bg2.rle")
};

const u8 sSector1_16_Bg1[498] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_16_bg1.rle")
};

const u8 sSector1_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	16, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	21, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	23, 9, SPRITESET_IDX(1),
	26, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	31, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

