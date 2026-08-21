#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_43_Clipdata[58] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_43_clipdata.rle")
};

const u8 sSector4_43_Bg2[36] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_43_bg2.rle")
};

const u8 sSector4_43_Bg1[179] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_43_bg1.rle")
};

const u8 sSector4_43_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

