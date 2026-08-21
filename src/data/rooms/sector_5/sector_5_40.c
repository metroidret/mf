#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_40_Clipdata[60] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_40_clipdata.rle")
};

const u8 sSector5_40_Bg2[202] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_40_bg2.rle")
};

const u8 sSector5_40_Bg1[315] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_40_bg1.rle")
};

const u8 sSector5_40_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	3, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	3, 38, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 18, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

