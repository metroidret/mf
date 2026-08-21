#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_13_Clipdata[68] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_13_clipdata.rle")
};

const u8 sSector3_13_Bg2[96] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_13_bg2.rle")
};

const u8 sSector3_13_Bg1[170] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_13_bg1.rle")
};

const u8 sSector3_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	3, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	3, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	3, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	3, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 9, SPRITESET_IDX(1),
	10, 7, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	10, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_13_Bg0[14] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_13_bg0.rle")
};

