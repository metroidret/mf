#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_49_Clipdata[53] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_49_clipdata.rle")
};

const u8 sSector1_49_Bg2[36] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_49_bg2.rle")
};

const u8 sSector1_49_Bg1[167] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_49_bg1.rle")
};

const u8 sSector1_49_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

