#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_0_Clipdata[175] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_0_clipdata.rle")
};

const u8 sSector4_0_Bg2[80] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_0_bg2.rle")
};

const u8 sSector4_0_Bg1[490] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_0_bg1.rle")
};

const u8 sSector4_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

