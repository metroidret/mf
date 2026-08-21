#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_12_Clipdata[63] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_12_clipdata.rle")
};

const u8 sSector5_12_Bg2[144] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_12_bg2.rle")
};

const u8 sSector5_12_Bg1[186] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_12_bg1.rle")
};

const u8 sSector5_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 9, SPRITESET_IDX(1),
	9, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

