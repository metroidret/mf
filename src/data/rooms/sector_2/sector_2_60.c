#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_60_Clipdata[88] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_60_clipdata.rle")
};

const u8 sSector2_60_Bg2[42] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_60_bg2.rle")
};

const u8 sSector2_60_Bg1[384] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_60_bg1.rle")
};

const u8 sSector2_60_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	5, 13, SPRITESET_IDX(1),
	5, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	5, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

