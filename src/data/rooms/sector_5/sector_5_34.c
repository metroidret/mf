#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_34_Clipdata[98] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_34_clipdata.rle")
};

const u8 sSector5_34_Bg2[55] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_34_bg2.rle")
};

const u8 sSector5_34_Bg1[185] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_34_bg1.rle")
};

const u8 sSector5_34_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

