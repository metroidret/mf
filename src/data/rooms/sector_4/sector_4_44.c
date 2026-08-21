#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_44_Clipdata[53] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_44_clipdata.rle")
};

const u8 sSector4_44_Bg2[36] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_44_bg2.rle")
};

const u8 sSector4_44_Bg1[167] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_44_bg1.rle")
};

const u8 sSector4_44_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

