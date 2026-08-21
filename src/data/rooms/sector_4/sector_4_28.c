#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_28_Clipdata[94] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_28_clipdata.rle")
};

const u8 sSector4_28_Bg2[94] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_28_bg2.rle")
};

const u8 sSector4_28_Bg1[246] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_28_bg1.rle")
};

const u8 sSector4_28_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	3, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	3, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	3, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	3, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	8, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	8, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	8, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	8, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	8, 27, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_28_Bg0[141] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_28_bg0.rle")
};

