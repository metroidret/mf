#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_3_Clipdata[530] = {
    49, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_3_clipdata.rle")
};

const u8 sSector5_3_Bg2[1886] = {
    49, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_3_bg2.rle")
};

const u8 sSector5_3_Bg1[1158] = {
    49, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_3_bg1.rle")
};

const u8 sSector5_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	10, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	10, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	30, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	34, 28, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	34, 34, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	37, 25, SPRITESET_IDX(1),
	40, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	40, 18, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	40, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	40, 36, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

