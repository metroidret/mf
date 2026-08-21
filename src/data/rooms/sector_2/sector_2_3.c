#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_3_Clipdata[72] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_3_clipdata.rle")
};

const u8 sSector2_3_Bg2[196] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_3_bg2.rle")
};

const u8 sSector2_3_Bg1[281] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_3_bg1.rle")
};

const u8 sSector2_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	3, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	5, 16, SPRITESET_IDX(1),
	7, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

