#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_49_Clipdata[60] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_49_clipdata.rle")
};

const u8 sSector5_49_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_49_bg2.rle")
};

const u8 sSector5_49_Bg1[148] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_49_bg1.rle")
};

const u8 sSector5_49_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

