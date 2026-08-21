#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_12_Clipdata[171] = {
    64, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_12_clipdata.rle")
};

const u8 sSector4_12_Bg2[469] = {
    64, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_12_bg2.rle")
};

const u8 sSector4_12_Bg1[761] = {
    64, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_12_bg1.rle")
};

const u8 sSector4_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	2, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	2, 39, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	3, 33, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	4, 51, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	6, 42, SPRITESET_IDX(2),
	9, 52, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 45, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	11, 27, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	11, 38, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	11, 52, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

