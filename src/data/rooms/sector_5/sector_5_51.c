#include "data/rooms/sector_5_rooms_data.h"
#include "macros.h"

const u8 sSector5_51_Clipdata[124] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_51_clipdata.rle")
};

const u8 sSector5_51_Bg2[174] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_51_bg2.rle")
};

const u8 sSector5_51_Bg1[402] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/sector_5/sector_5_51_bg1.rle")
};

const u8 sSector5_51_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	9, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	13, 10, SPRITESET_IDX(0),
	23, 8, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	23, 10, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

