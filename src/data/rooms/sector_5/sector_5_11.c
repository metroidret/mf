#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_11_Clipdata[112] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_11_clipdata.rle")
};

const u8 sSector5_11_Bg2[33] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_11_bg2.rle")
};

const u8 sSector5_11_Bg1[259] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_11_bg1.rle")
};

const u8 sSector5_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	3, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	4, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	8, 9, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

