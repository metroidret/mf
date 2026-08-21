#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_53_Clipdata[58] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_53_clipdata.rle")
};

const u8 sSector2_53_Bg2[36] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_53_bg2.rle")
};

const u8 sSector2_53_Bg1[175] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_53_bg1.rle")
};

const u8 sSector2_53_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

