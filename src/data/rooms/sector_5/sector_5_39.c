#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_39_Clipdata[72] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_39_clipdata.rle")
};

const u8 sSector5_39_Bg2[202] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_39_bg2.rle")
};

const u8 sSector5_39_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	3, 35, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 18, SPRITESET_IDX(1),
	8, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	10, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	13, 18, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector5_39_Bg1[291] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_39_bg1.rle")
};

const u8 sSector5_39_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	6, 18, SPRITESET_IDX(1),
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	10, 21, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

