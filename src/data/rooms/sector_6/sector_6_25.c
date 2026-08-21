#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_25_Clipdata[68] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_25_clipdata.rle")
};

const u8 sSector6_25_Bg2[262] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_25_bg2.rle")
};

const u8 sSector6_25_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_25_Bg1[133] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_25_bg1.rle")
};

const u8 sSector6_25_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

