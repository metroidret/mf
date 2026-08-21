#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_11_Clipdata[128] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_11_clipdata.rle")
};

const u8 sSector2_11_Bg2[304] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_11_bg2.rle")
};

const u8 sSector2_11_Bg1[262] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_11_bg1.rle")
};

const u8 sSector2_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	6, 23, SPRITESET_IDX(1),
	10, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	10, 26, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	10, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	10, 37, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	11, 28, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

