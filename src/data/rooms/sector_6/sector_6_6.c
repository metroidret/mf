#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_6_Clipdata[165] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_6_clipdata.rle")
};

const u8 sSector6_6_Bg2[167] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_6_bg2.rle")
};

const u8 sSector6_6_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	4, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	4, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	5, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	5, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	5, 24, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	6, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	6, 25, SPRITESET_IDX(1),
	10, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector6_6_Bg1[360] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_6_bg1.rle")
};

const u8 sSector6_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	4, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	4, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	5, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	5, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	5, 24, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	6, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	6, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	6, 25, SPRITESET_IDX(1),
	10, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

