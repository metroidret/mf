#include "data/rooms/sector_2_rooms_data.h"
#include "macros.h"

const u8 sSector2_13_Clipdata[496] = {
    19, // Room width
    84, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_13_clipdata.rle")
};

const u8 sSector2_13_Bg2[953] = {
    19, // Room width
    84, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_13_bg2.rle")
};

const u8 sSector2_13_Bg1[1249] = {
    19, // Room width
    84, // Room height
    _INCBIN_U8("data/rooms/sector_2/sector_2_13_bg1.rle")
};

const u8 sSector2_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	18, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	29, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	40, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	44, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	58, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	64, 11, SPRITESET_IDX(1),
	67, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	80, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

