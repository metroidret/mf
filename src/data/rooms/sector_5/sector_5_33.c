#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_33_Clipdata[71] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_33_clipdata.rle")
};

const u8 sSector5_33_Bg2[98] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_33_bg2.rle")
};

const u8 sSector5_33_Bg1[173] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_33_bg1.rle")
};

const u8 sSector5_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	7, 9, SPRITESET_IDX(1),
	10, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

