#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_5_Clipdata[56] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_5_clipdata.rle")
};

const u8 sSector4_5_Bg2[71] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_5_bg2.rle")
};

const u8 sSector4_5_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	2, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(7),
	4, 8, SPRITESET_IDX(2),
	4, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	8, 10, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector4_5_Bg1[171] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_5_bg1.rle")
};

const u8 sSector4_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	4, 8, SPRITESET_IDX(2),
	4, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	8, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

