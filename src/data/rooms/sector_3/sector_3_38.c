#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_38_Clipdata[58] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_38_clipdata.rle")
};

const u8 sSector3_38_Bg2[36] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_38_bg2.rle")
};

const u8 sSector3_38_Bg1[175] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_38_bg1.rle")
};

const u8 sSector3_38_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

