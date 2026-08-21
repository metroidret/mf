#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_44_Clipdata[81] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_44_clipdata.rle")
};

const u8 sSector1_44_Bg2[72] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_44_bg2.rle")
};

const u8 sSector1_44_Bg1[227] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_44_bg1.rle")
};

const u8 sSector1_44_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	5, 10, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

