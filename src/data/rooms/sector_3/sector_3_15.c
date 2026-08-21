#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_15_Clipdata[291] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_15_clipdata.rle")
};

const u8 sSector3_15_Bg2[274] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_15_bg2.rle")
};

const u8 sSector3_15_Bg1[1119] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_15_bg1.rle")
};

const u8 sSector3_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	5, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 4, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	6, 18, SPRITESET_IDX(2),
	6, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	7, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	12, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	16, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	16, 25, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	19, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	20, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	29, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	29, 20, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector3_15_Bg0[23] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_15_bg0.rle")
};

