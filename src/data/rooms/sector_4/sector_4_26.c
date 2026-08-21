#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_26_Clipdata[64] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_26_clipdata.rle")
};

const u8 sSector4_26_Bg2[248] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_26_bg2.rle")
};

const u8 sSector4_26_Bg1[132] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_26_bg1.rle")
};

const u8 sSector4_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

