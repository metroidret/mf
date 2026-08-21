#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_41_Clipdata[144] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_41_clipdata.rle")
};

const u8 sSector4_41_Bg2[146] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_41_bg2.rle")
};

const u8 sSector4_41_Bg1[367] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_41_bg1.rle")
};

const u8 sSector4_41_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	4, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	4, 11, SPRITESET_IDX(1),
	6, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	7, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

