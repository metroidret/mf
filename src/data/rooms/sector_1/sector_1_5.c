#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_5_Clipdata[89] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_5_clipdata.rle")
};

const u8 sSector1_5_Bg2[130] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_5_bg2.rle")
};

const u8 sSector1_5_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	4, 9, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 17, SPRITESET_IDX(2),
	4, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	8, 19, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 22, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 13, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector1_5_Bg1[372] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_5_bg1.rle")
};

const u8 sSector1_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	4, 15, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 17, SPRITESET_IDX(2),
	4, 22, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	8, 19, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 23, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 13, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 15, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 18, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

