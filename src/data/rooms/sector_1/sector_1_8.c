#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_8_Clipdata[352] = {
    19, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_8_clipdata.rle")
};

const u8 sSector1_8_Bg2[205] = {
    19, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_8_bg2.rle")
};

const u8 sSector1_8_Bg1[742] = {
    19, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_8_bg1.rle")
};

const u8 sSector1_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	0, 10, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	0, 12, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	14, 14, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	19, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	24, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	29, 4, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	31, 9, SPRITESET_IDX(1),
	34, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	39, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	44, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	49, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

