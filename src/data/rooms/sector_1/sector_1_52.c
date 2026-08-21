#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_52_Clipdata[55] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_52_clipdata.rle")
};

const u8 sSector1_52_Bg2[298] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_52_bg2.rle")
};

const u8 sSector1_52_Bg1[185] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_52_bg1.rle")
};

const u8 sSector1_52_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

