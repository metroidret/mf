#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_19_Clipdata[60] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_19_clipdata.rle")
};

const u8 sSector1_19_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_19_bg2.rle")
};

const u8 sSector1_19_Bg1[151] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_19_bg1.rle")
};

const u8 sSector1_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

