#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_11_Clipdata[76] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_11_clipdata.rle")
};

const u8 sSector1_11_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_11_bg2.rle")
};

const u8 sSector1_11_Bg1[151] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_11_bg1.rle")
};

const u8 sSector1_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

