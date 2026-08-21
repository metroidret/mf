#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_8_Clipdata[60] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_8_clipdata.rle")
};

const u8 sSector2_8_Bg2[255] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_8_bg2.rle")
};

const u8 sSector2_8_Bg1[133] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_8_bg1.rle")
};

const u8 sSector2_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

