#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_16_Clipdata[132] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_16_clipdata.rle")
};

const u8 sSector5_16_Bg2[497] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_16_bg2.rle")
};

const u8 sSector5_16_Bg1[415] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_16_bg1.rle")
};

const u8 sSector5_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	20, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

