#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_23_Clipdata[176] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_23_clipdata.rle")
};

const u8 sSector1_23_Bg2[14] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_23_bg2.rle")
};

const u8 sSector1_23_Bg1[477] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_23_bg1.rle")
};

const u8 sSector1_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

