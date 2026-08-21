#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_4_Clipdata[71] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_4_clipdata.rle")
};

const u8 sSector3_4_Bg2[279] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_4_bg2.rle")
};

const u8 sSector3_4_Bg1[140] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_4_bg1.rle")
};

const u8 sSector3_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

