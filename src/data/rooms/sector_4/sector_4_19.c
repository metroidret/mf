#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_19_Clipdata[422] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_19_clipdata.rle")
};

const u8 sSector4_19_Bg2[639] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_19_bg2.rle")
};

const u8 sSector4_19_Bg1[1275] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_19_bg1.rle")
};

const u8 sSector4_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	4, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	13, 20, SPRITESET_IDX(2),
	18, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	18, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	21, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	22, 29, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	24, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

