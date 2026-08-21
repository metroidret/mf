#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_38_Clipdata[123] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_38_clipdata.rle")
};

const u8 sSector6_38_Bg2[14] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_38_bg2.rle")
};

const u8 sSector6_38_Bg1[220] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_38_bg1.rle")
};

const u8 sSector6_38_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	8, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	8, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	8, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	8, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	8, 20, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	8, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	8, 27, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	8, 28, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	8, 32, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	8, 34, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	8, 36, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

