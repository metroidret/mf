#include "data/rooms/sector_6_rooms_data.h"
#include "macros.h"

const u8 sSector6_32_Clipdata[126] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_32_clipdata.rle")
};

const u8 sSector6_32_Bg2[196] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_32_bg2.rle")
};

const u8 sSector6_32_Bg1[325] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_6/sector_6_32_bg1.rle")
};

const u8 sSector6_32_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	3, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	10, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	10, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	11, 10, SPRITESET_IDX(1),
	12, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

