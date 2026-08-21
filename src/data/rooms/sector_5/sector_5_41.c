#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_41_Clipdata[95] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_41_clipdata.rle")
};

const u8 sSector5_41_Bg2[83] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_41_bg2.rle")
};

const u8 sSector5_41_Bg1[214] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_41_bg1.rle")
};

const u8 sSector5_41_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 7, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	3, 14, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	8, 19, SPRITESET_IDX(0),
	10, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

