#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_3_Clipdata[70] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_3_clipdata.rle")
};

const u8 sSector1_3_Bg2[205] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_3_bg2.rle")
};

const u8 sSector1_3_Bg1[307] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_3_bg1.rle")
};

const u8 sSector1_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	0, 13, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 16, SPRITESET_IDX(2),
	5, 33, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	6, 27, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	6, 41, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	8, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	8, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	10, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 27, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

