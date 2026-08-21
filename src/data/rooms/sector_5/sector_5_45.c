#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_45_Clipdata[203] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_45_clipdata.rle")
};

const u8 sSector5_45_Bg2[156] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_45_bg2.rle")
};

const u8 sSector5_45_Bg1[580] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_45_bg1.rle")
};

const u8 sSector5_45_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	3, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	3, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	3, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	29, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	32, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	32, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	34, 8, SPRITESET_IDX(0),
	35, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

