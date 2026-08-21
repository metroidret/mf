#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_26_Clipdata[167] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_26_clipdata.rle")
};

const u8 sSector1_26_Bg2[14] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_26_bg2.rle")
};

const u8 sSector1_26_Bg1[251] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_26_bg1.rle")
};

const u8 sSector1_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	4, 8, SPRITESET_IDX(0),
	4, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	4, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	6, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	7, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_26_Bg0[189] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_26_bg0.rle")
};

