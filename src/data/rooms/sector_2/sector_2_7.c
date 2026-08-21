#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_7_Clipdata[124] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_7_clipdata.rle")
};

const u8 sSector2_7_Bg2[381] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_7_bg2.rle")
};

const u8 sSector2_7_Bg1[510] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_7_bg1.rle")
};

const u8 sSector2_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	8, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	15, 13, SPRITESET_IDX(0),
	18, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

