#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_18_Clipdata[215] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_18_clipdata.rle")
};

const u8 sSector1_18_Bg2[1245] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_18_bg2.rle")
};

const u8 sSector1_18_Bg1[649] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_18_bg1.rle")
};

const u8 sSector1_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	24, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	32, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

