#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_50_Clipdata[115] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_50_clipdata.rle")
};

const u8 sSector1_50_Bg2[143] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_50_bg2.rle")
};

const u8 sSector1_50_Bg1[408] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_50_bg1.rle")
};

const u8 sSector1_50_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

