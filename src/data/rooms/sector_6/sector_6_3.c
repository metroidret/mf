#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_3_Clipdata[166] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_3_clipdata.rle")
};

const u8 sSector6_3_Bg2[279] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_3_bg2.rle")
};

const u8 sSector6_3_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	4, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	4, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	13, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	13, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	15, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	16, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	16, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	18, 17, SPRITESET_IDX(1),
	20, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_3_Bg1[552] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_3_bg1.rle")
};

const u8 sSector6_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	18, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	18, 19, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

