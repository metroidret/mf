#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_50_Clipdata[266] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_50_clipdata.rle")
};

const u8 sSector2_50_Bg2[108] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_50_bg2.rle")
};

const u8 sSector2_50_Bg1[504] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_50_bg1.rle")
};

const u8 sSector2_50_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	10, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	12, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	14, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	16, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	18, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	21, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	23, 8, SPRITESET_IDX(1),
	27, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

