#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_26_Clipdata[76] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_26_clipdata.rle")
};

const u8 sSector3_26_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_26_bg2.rle")
};

const u8 sSector3_26_Bg1[154] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_26_bg1.rle")
};

const u8 sSector3_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

