#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_51_Clipdata[101] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_51_clipdata.rle")
};

const u8 sSector1_51_Bg2[306] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_51_bg2.rle")
};

const u8 sSector1_51_Bg1[252] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_51_bg1.rle")
};

const u8 sSector1_51_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 17, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	4, 18, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	5, 17, SPRITESET_IDX(0),
	6, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	10, 27, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

