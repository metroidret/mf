#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_55_Clipdata[357] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_55_clipdata.rle")
};

const u8 sSector2_55_Bg2[574] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_55_bg2.rle")
};

const u8 sSector2_55_Bg1[978] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_55_bg1.rle")
};

const u8 sSector2_55_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

