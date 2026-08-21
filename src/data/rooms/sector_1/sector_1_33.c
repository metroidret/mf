#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_33_Clipdata[184] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_33_clipdata.rle")
};

const u8 sSector1_33_Bg2[243] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_33_bg2.rle")
};

const u8 sSector1_33_Bg1[450] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_33_bg1.rle")
};

const u8 sSector1_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	28, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

