#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_17_Clipdata[151] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_17_clipdata.rle")
};

const u8 sSector5_17_Bg2[135] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_17_bg2.rle")
};

const u8 sSector5_17_Bg1[755] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_17_bg1.rle")
};

const u8 sSector5_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	3, 6, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	3, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	3, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	7, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	7, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	10, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	12, 23, SPRITESET_IDX(1),
	14, 35, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	14, 36, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	14, 39, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	14, 42, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	18, 28, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	18, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

