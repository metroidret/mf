#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_26_Clipdata[164] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_26_clipdata.rle")
};

const u8 sSector5_26_Bg2[14] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_26_bg2.rle")
};

const u8 sSector5_26_Bg1[435] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_26_bg1.rle")
};

const u8 sSector5_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	4, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	4, 32, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	9, 22, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

