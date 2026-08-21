#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_22_Clipdata[63] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_22_clipdata.rle")
};

const u8 sSector4_22_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_22_bg2.rle")
};

const u8 sSector4_22_Bg1[158] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_22_bg1.rle")
};

const u8 sSector4_22_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

