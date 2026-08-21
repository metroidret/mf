#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_34_Clipdata[74] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_34_clipdata.rle")
};

const u8 sSector6_34_Bg2[14] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_34_bg2.rle")
};

const u8 sSector6_34_Bg1[204] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_34_bg1.rle")
};

const u8 sSector6_34_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

