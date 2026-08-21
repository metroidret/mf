#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_50_Clipdata[193] = {
    64, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_50_clipdata.rle")
};

const u8 sMainDeck_50_Bg2[827] = {
    64, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_50_bg2.rle")
};

const u8 sMainDeck_50_Bg1[480] = {
    64, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_50_bg1.rle")
};

const u8 sMainDeck_50_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	0, 31, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	0, 43, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	4, 21, SPRITESET_IDX(2),
	10, 23, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	10, 47, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	13, 27, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	13, 41, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

