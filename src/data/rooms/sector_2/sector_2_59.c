#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_59_Clipdata[95] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_59_clipdata.rle")
};

const u8 sSector2_59_Bg2[14] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_59_bg2.rle")
};

const u8 sSector2_59_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	0, 1, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	0, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	2, 0, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	6, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	7, 10, SPRITESET_IDX(0),
	8, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	11, 0, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	13, 1, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	13, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_59_Bg1[167] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_59_bg1.rle")
};

const u8 sSector2_59_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

