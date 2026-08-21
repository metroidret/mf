#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_6_Clipdata[475] = {
    49, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_6_clipdata.rle")
};

const u8 sSector5_6_Bg2[2275] = {
    49, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_6_bg2.rle")
};

const u8 sSector5_6_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	21, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector5_6_Bg1[1521] = {
    49, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_6_bg1.rle")
};

const u8 sSector5_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	10, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	10, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	18, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	30, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	37, 25, SPRITESET_IDX(1),
	40, 18, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	40, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	40, 36, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

