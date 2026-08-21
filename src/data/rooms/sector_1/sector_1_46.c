#include "data/rooms/sector_1_rooms_data.h"
#include "macros.h"

const u8 sSector1_46_Clipdata[68] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_46_clipdata.rle")
};

const u8 sSector1_46_Bg2[89] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_46_bg2.rle")
};

const u8 sSector1_46_Bg1[191] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/sector_1/sector_1_46_bg1.rle")
};

const u8 sSector1_46_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	1, 7, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(9),
	3, 7, SPRITESET_IDX(0),
	7, 8, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	7, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(6),
	7, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

