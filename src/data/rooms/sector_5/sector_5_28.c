#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_28_Clipdata[108] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_28_clipdata.rle")
};

const u8 sSector5_28_Bg2[143] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_28_bg2.rle")
};

const u8 sSector5_28_Bg1[267] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_28_bg1.rle")
};

const u8 sSector5_28_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	17, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	17, 10, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

