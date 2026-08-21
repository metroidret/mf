#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_45_Clipdata[78] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_45_clipdata.rle")
};

const u8 sSector1_45_Bg2[97] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_45_bg2.rle")
};

const u8 sSector1_45_Bg1[222] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_45_bg1.rle")
};

const u8 sSector1_45_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	4, 8, SPRITESET_IDX(1),
	10, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

