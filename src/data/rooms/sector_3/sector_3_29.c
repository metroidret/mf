#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_29_Clipdata[115] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_29_clipdata.rle")
};

const u8 sSector3_29_Bg2[431] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_29_bg2.rle")
};

const u8 sSector3_29_Bg1[432] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_29_bg1.rle")
};

const u8 sSector3_29_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	5, 11, SPRITESET_IDX(1),
	8, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	8, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	8, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	18, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	18, 13, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	18, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

