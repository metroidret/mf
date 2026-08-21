#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_9_Clipdata[192] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_9_clipdata.rle")
};

const u8 sSector1_9_Bg2[397] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_9_bg2.rle")
};

const u8 sSector1_9_Bg1[712] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_9_bg1.rle")
};

const u8 sSector1_9_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	5, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	12, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	14, 20, SPRITESET_IDX(2),
	20, 17, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	ROOM_SPRITE_DATA_TERMINATOR
};

