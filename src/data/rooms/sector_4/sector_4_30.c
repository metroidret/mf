#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_30_Clipdata[249] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_30_clipdata.rle")
};

const u8 sSector4_30_Bg2[127] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_30_bg2.rle")
};

const u8 sSector4_30_Bg1[589] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_30_bg1.rle")
};

const u8 sSector4_30_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	14, 11, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_30_Bg0[90] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_30_bg0.rle")
};

