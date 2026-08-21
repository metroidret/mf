#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_37_Clipdata[77] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_37_clipdata.rle")
};

const u8 sSector3_37_Bg2[40] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_37_bg2.rle")
};

const u8 sSector3_37_Bg1[174] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_37_bg1.rle")
};

const u8 sSector3_37_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

