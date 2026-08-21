#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_6_Clipdata[175] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_6_clipdata.rle")
};

const u8 sSector1_6_Bg2[227] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_6_bg2.rle")
};

const u8 sSector1_6_Bg1[471] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_6_bg1.rle")
};

const u8 sSector1_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

