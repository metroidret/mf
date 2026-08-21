#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_14_Clipdata[72] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_14_clipdata.rle")
};

const u8 sSector5_14_Bg2[54] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_14_bg2.rle")
};

const u8 sSector5_14_Bg1[137] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_14_bg1.rle")
};

const u8 sSector5_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	4, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

