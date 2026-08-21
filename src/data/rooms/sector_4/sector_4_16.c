#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_16_Clipdata[213] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_16_clipdata.rle")
};

const u8 sSector4_16_Bg2[220] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_16_bg2.rle")
};

const u8 sSector4_16_Bg1[626] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_16_bg1.rle")
};

const u8 sSector4_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	6, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	9, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	13, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	16, 5, SPRITESET_IDX(1),
	17, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	18, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	20, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	22, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	22, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	23, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	25, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

