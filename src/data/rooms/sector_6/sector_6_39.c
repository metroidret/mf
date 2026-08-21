#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_39_Clipdata[487] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_39_clipdata.rle")
};

const u8 sSector6_39_Bg2[896] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_39_bg2.rle")
};

const u8 sSector6_39_Bg1[1142] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_39_bg1.rle")
};

const u8 sSector6_39_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

