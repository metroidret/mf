#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_15_Clipdata[165] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_15_clipdata.rle")
};

const u8 sSector1_15_Bg2[337] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_15_bg2.rle")
};

const u8 sSector1_15_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	5, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	10, 17, SPRITESET_IDX(2),
	20, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_15_Bg1[588] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_15_bg1.rle")
};

const u8 sSector1_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	5, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	10, 17, SPRITESET_IDX(2),
	14, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	14, 22, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	14, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	20, 22, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	ROOM_SPRITE_DATA_TERMINATOR
};

