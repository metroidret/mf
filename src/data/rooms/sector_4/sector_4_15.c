#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_15_Clipdata[254] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_15_clipdata.rle")
};

const u8 sSector4_15_Bg2[418] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_15_bg2.rle")
};

const u8 sSector4_15_Bg1[609] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_15_bg1.rle")
};

const u8 sSector4_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	2, 37, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	3, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	3, 21, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	3, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	4, 41, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	4, 45, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	5, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	6, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	6, 29, SPRITESET_IDX(2),
	8, 37, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	10, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 36, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

