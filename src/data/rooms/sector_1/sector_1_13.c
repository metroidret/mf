#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_13_Clipdata[222] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_13_clipdata.rle")
};

const u8 sSector1_13_Bg2[259] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_13_bg2.rle")
};

const u8 sSector1_13_Bg1[617] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_13_bg1.rle")
};

const u8 sSector1_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	5, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 26, SPRITESET_IDX(2),
	18, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	18, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_13_Bg0[23] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_13_bg0.rle")
};

