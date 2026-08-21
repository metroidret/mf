#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_39_Clipdata[80] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_39_clipdata.rle")
};

const u8 sSector2_39_Bg2[138] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_39_bg2.rle")
};

const u8 sSector2_39_Bg1[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_39_bg1.rle")
};

const u8 sSector2_39_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	4, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	8, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	9, 8, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

