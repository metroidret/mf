#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_35_Clipdata[60] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_35_clipdata.rle")
};

const u8 sSector6_35_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_35_bg2.rle")
};

const u8 sSector6_35_Bg1[147] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_35_bg1.rle")
};

const u8 sSector6_35_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

