#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_25_Clipdata[253] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_25_clipdata.rle")
};

const u8 sSector4_25_Bg2[342] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_25_bg2.rle")
};

const u8 sSector4_25_Bg1[809] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_25_bg1.rle")
};

const u8 sSector4_25_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	21, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	22, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	22, 9, SPRITESET_IDX(2),
	23, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	25, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	25, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	26, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	35, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

