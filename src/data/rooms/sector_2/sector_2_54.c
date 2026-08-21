#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_54_Clipdata[289] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_54_clipdata.rle")
};

const u8 sSector2_54_Bg2[310] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_54_bg2.rle")
};

const u8 sSector2_54_Bg1[780] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_54_bg1.rle")
};

const u8 sSector2_54_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

