#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_23_Clipdata[53] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_23_clipdata.rle")
};

const u8 sSector2_23_Bg2[155] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_23_bg2.rle")
};

const u8 sSector2_23_Bg1[273] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_23_bg1.rle")
};

const u8 sSector2_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	3, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	3, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	6, 19, SPRITESET_IDX(1),
	8, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	8, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	8, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	8, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	8, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	8, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

