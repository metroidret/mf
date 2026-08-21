#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_46_Clipdata[69] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_46_clipdata.rle")
};

const u8 sSector4_46_Bg2[75] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_46_bg2.rle")
};

const u8 sSector4_46_Bg1[175] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_46_bg1.rle")
};

const u8 sSector4_46_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	4, 11, SPRITESET_IDX(2),
	5, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	6, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	7, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	9, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	9, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_46_Bg0[50] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_46_bg0.rle")
};

