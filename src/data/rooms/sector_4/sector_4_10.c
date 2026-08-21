#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_10_Clipdata[272] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_10_clipdata.rle")
};

const u8 sSector4_10_Bg2[14] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_10_bg2.rle")
};

const u8 sSector4_10_Bg1[525] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_10_bg1.rle")
};

const u8 sSector4_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	14, 12, SPRITESET_IDX(2),
	17, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_10_Bg0[158] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_10_bg0.rle")
};

