#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_4_Clipdata[74] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_4_clipdata.rle")
};

const u8 sSector6_4_Bg2[178] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_4_bg2.rle")
};

const u8 sSector6_4_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	3, 16, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	3, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 16, SPRITESET_IDX(1),
	6, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_4_Bg1[248] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_4_bg1.rle")
};

const u8 sSector6_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	4, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	6, 16, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

