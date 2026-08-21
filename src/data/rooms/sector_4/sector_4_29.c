#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_29_Clipdata[76] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_29_clipdata.rle")
};

const u8 sSector4_29_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_29_bg2.rle")
};

const u8 sSector4_29_Bg1[151] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_29_bg1.rle")
};

const u8 sSector4_29_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

