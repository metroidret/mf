#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_12_Clipdata[65] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_12_clipdata.rle")
};

const u8 sSector1_12_Bg2[89] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_12_bg2.rle")
};

const u8 sSector1_12_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_12_Bg1[192] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_12_bg1.rle")
};

const u8 sSector1_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	4, 8, SPRITESET_IDX(1),
	8, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

