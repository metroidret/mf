#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_45_Clipdata[44] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_45_clipdata.rle")
};

const u8 sSector4_45_Bg2[14] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_45_bg2.rle")
};

const u8 sSector4_45_Bg1[174] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_45_bg1.rle")
};

const u8 sSector4_45_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

