#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_32_Clipdata[543] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_32_clipdata.rle")
};

const u8 sSector2_32_Bg2[1011] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_32_bg2.rle")
};

const u8 sSector2_32_Bg1[1130] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_32_bg1.rle")
};

const u8 sSector2_32_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	4, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	19, 7, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	32, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	32, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	35, 7, SPRITESET_IDX(1),
	41, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	42, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	46, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	48, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	49, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	57, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sSector2_32_Bg0[922] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_32_bg0.rle")
};

