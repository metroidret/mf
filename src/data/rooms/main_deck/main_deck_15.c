#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_15_Clipdata[168] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_15_clipdata.rle")
};

const u8 sMainDeck_15_Bg2[14] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_15_bg2.rle")
};

const u8 sMainDeck_15_Bg1[366] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_15_bg1.rle")
};

const u8 sMainDeck_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	16, 14, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	17, 8, SPRITESET_IDX(0),
	23, 14, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	33, 8, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	33, 12, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

