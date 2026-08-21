#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_25_Clipdata[88] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_25_clipdata.rle")
};

const u8 sSector2_25_Bg2[155] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_25_bg2.rle")
};

const u8 sSector2_25_Bg1[250] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_25_bg1.rle")
};

const u8 sSector2_25_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	11, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

