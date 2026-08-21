#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_37_Clipdata[197] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_37_clipdata.rle")
};

const u8 sSector1_37_Bg2[26] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_37_bg2.rle")
};

const u8 sSector1_37_Bg1[356] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_37_bg1.rle")
};

const u8 sSector1_37_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 7, SPRITESET_IDX(2),
	6, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

