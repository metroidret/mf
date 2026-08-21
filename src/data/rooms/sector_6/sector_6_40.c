#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_40_Clipdata[70] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_40_clipdata.rle")
};

const u8 sSector6_40_Bg2[172] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_40_bg2.rle")
};

const u8 sSector6_40_Bg1[225] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_40_bg1.rle")
};

const u8 sSector6_40_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	5, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	7, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	7, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	7, 17, SPRITESET_IDX(1),
	7, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	8, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	8, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	9, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

