#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_1_Clipdata[76] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_1_clipdata.rle")
};

const u8 sSector6_1_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_1_bg2.rle")
};

const u8 sSector6_1_Bg1[158] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_1_bg1.rle")
};

const u8 sSector6_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

