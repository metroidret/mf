#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_27_Clipdata[99] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_27_clipdata.rle")
};

const u8 sSector5_27_Bg2[81] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_27_bg2.rle")
};

const u8 sSector5_27_Bg1[222] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_27_bg1.rle")
};

const u8 sSector5_27_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	3, 23, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	5, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	7, 17, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

