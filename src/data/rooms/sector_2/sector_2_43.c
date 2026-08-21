#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_43_Clipdata[100] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_43_clipdata.rle")
};

const u8 sSector2_43_Bg2[210] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_43_bg2.rle")
};

const u8 sSector2_43_Bg1[287] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_43_bg1.rle")
};

const u8 sSector2_43_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	11, 6, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

