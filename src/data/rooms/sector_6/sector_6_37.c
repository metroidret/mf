#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_37_Clipdata[58] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_37_clipdata.rle")
};

const u8 sSector6_37_Bg2[36] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_37_bg2.rle")
};

const u8 sSector6_37_Bg1[179] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_37_bg1.rle")
};

const u8 sSector6_37_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

