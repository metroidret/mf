#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_4_Clipdata[202] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_4_clipdata.rle")
};

const u8 sSector1_4_Bg2[337] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_4_bg2.rle")
};

const u8 sSector1_4_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	16, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	16, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_4_Bg1[644] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_4_bg1.rle")
};

const u8 sSector1_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	11, 24, SPRITESET_IDX(2),
	16, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

