#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_53_Clipdata[102] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_53_clipdata.rle")
};

const u8 sSector1_53_Bg2[14] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_53_bg2.rle")
};

const u8 sSector1_53_Bg1[110] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_53_bg1.rle")
};

const u8 sSector1_53_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	12, 10, SPRITESET_IDX(1),
	13, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	14, 9, SPRITESET_IDX(14),
	ROOM_SPRITE_DATA_TERMINATOR
};

