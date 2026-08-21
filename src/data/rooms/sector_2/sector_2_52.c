#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_52_Clipdata[53] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_52_clipdata.rle")
};

const u8 sSector2_52_Bg2[36] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_52_bg2.rle")
};

const u8 sSector2_52_Bg1[161] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_52_bg1.rle")
};

const u8 sSector2_52_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

