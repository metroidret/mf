#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_27_Clipdata[88] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_27_clipdata.rle")
};

const u8 sSector1_27_Bg2[191] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_27_bg2.rle")
};

const u8 sSector1_27_Bg1[113] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_27_bg1.rle")
};

const u8 sSector1_27_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	12, 10, SPRITESET_IDX(1),
	14, 9, SPRITESET_IDX(14),
	20, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_27_Bg0[42] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_27_bg0.rle")
};

