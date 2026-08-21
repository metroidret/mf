#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_35_Clipdata[635] = {
    19, // Room width
    114, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_35_clipdata.rle")
};

const u8 sSector3_35_Bg2[175] = {
    19, // Room width
    114, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_35_bg2.rle")
};

const u8 sSector3_35_Bg1[2238] = {
    19, // Room width
    114, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_35_bg1.rle")
};

const u8 sSector3_35_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_35_Bg0[23] = {
    19, // Room width
    114, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_35_bg0.rle")
};

