#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_36_Clipdata[53] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_36_clipdata.rle")
};

const u8 sSector6_36_Bg2[36] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_36_bg2.rle")
};

const u8 sSector6_36_Bg1[171] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_36_bg1.rle")
};

const u8 sSector6_36_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

