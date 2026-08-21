#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_47_Clipdata[68] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_47_clipdata.rle")
};

const u8 sSector5_47_Bg2[67] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_47_bg2.rle")
};

const u8 sSector5_47_Bg1[224] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_47_bg1.rle")
};

const u8 sSector5_47_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	3, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	3, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	3, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	3, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	3, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	6, 3, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	6, 10, SPRITESET_IDX(0),
	10, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	10, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

