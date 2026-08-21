#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_12_Clipdata[162] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_12_clipdata.rle")
};

const u8 sSector2_12_Bg2[222] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_12_bg2.rle")
};

const u8 sSector2_12_Bg1[335] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_12_bg1.rle")
};

const u8 sSector2_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	4, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	4, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	11, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	12, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	12, 11, SPRITESET_IDX(0),
	18, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	19, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

