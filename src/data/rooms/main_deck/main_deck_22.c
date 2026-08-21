#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_22_Clipdata[148] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_22_clipdata.rle")
};

const u8 sMainDeck_22_Bg2[432] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_22_bg2.rle")
};

const u8 sMainDeck_22_Bg1[330] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_22_bg1.rle")
};

const u8 sMainDeck_22_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 9, SPRITESET_IDX(2),
	9, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	14, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	20, 12, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	32, 12, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

