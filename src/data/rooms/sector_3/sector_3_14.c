#include "data/rooms/sector_3_rooms_data.h"
#include "macros.h"

const u8 sSector3_14_Clipdata[108] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_14_clipdata.rle")
};

const u8 sSector3_14_Bg2[85] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_14_bg2.rle")
};

const u8 sSector3_14_Bg1[341] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_3/sector_3_14_bg1.rle")
};

const u8 sSector3_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	10, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	12, 11, SPRITESET_IDX(0),
	15, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

