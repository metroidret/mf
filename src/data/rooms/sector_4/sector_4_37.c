#include "data/rooms/sector_4_rooms_data.h"
#include "macros.h"

const u8 sSector4_37_Clipdata[120] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_37_clipdata.rle")
};

const u8 sSector4_37_Bg2[14] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_37_bg2.rle")
};

const u8 sSector4_37_Bg1[284] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_4/sector_4_37_bg1.rle")
};

const u8 sSector4_37_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	3, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	3, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	3, 9, SPRITESET_IDX(1),
	3, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	3, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	5, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

