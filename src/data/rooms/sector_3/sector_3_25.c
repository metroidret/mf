#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_25_Clipdata[100] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_25_clipdata.rle")
};

const u8 sSector3_25_Bg2[675] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_25_bg2.rle")
};

const u8 sSector3_25_Bg1[316] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_25_bg1.rle")
};

const u8 sSector3_25_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	14, 8, SPRITESET_IDX(14),
	15, 8, SPRITESET_IDX(1),
	20, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

