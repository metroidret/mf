#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_56_Clipdata[102] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_56_clipdata.rle")
};

const u8 sSector2_56_Bg2[42] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_56_bg2.rle")
};

const u8 sSector2_56_Bg1[379] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_56_bg1.rle")
};

const u8 sSector2_56_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_56_Bg0[273] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_56_bg0.rle")
};

