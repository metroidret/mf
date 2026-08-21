#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_21_Clipdata[60] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_21_clipdata.rle")
};

const u8 sSector3_21_Bg2[277] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_21_bg2.rle")
};

const u8 sSector3_21_Bg1[135] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_21_bg1.rle")
};

const u8 sSector3_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	6, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	10, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

