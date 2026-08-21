#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_2_Clipdata[72] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_2_clipdata.rle")
};

const u8 sSector5_2_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_2_bg2.rle")
};

const u8 sSector5_2_Bg1[229] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_2_bg1.rle")
};

const u8 sSector5_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

