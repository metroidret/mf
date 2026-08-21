#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_23_Clipdata[59] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_23_clipdata.rle")
};

const u8 sSector5_23_Bg2[48] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_23_bg2.rle")
};

const u8 sSector5_23_Bg1[156] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_23_bg1.rle")
};

const u8 sSector5_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

