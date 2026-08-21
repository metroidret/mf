#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_7_Clipdata[106] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_7_clipdata.rle")
};

const u8 sSector3_7_Bg2[287] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_7_bg2.rle")
};

const u8 sSector3_7_Bg1[452] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_7_bg1.rle")
};

const u8 sSector3_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 32, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 17, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 21, SPRITESET_IDX(1),
	4, 26, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	9, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 15, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 21, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 26, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 29, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_7_Bg0[205] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_7_bg0.rle")
};

