#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_18_Clipdata[257] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_18_clipdata.rle")
};

const u8 sSector5_18_Bg2[227] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_18_bg2.rle")
};

const u8 sSector5_18_Bg1[878] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_18_bg1.rle")
};

const u8 sSector5_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	5, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	5, 25, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	13, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	13, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	13, 15, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	14, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	15, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	15, 26, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	17, 14, SPRITESET_IDX(1),
	24, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	24, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	24, 20, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

