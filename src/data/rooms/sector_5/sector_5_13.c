#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_13_Clipdata[346] = {
    19, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_13_clipdata.rle")
};

const u8 sSector5_13_Bg2[361] = {
    19, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_13_bg2.rle")
};

const u8 sSector5_13_Bg1[743] = {
    19, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_13_bg1.rle")
};

const u8 sSector5_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	5, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	26, 11, SPRITESET_IDX(1),
	34, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	41, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	48, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	52, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	56, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

