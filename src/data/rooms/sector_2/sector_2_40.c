#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_40_Clipdata[76] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_40_clipdata.rle")
};

const u8 sSector2_40_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_40_bg2.rle")
};

const u8 sSector2_40_Bg1[158] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_40_bg1.rle")
};

const u8 sSector2_40_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

