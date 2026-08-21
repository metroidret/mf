#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_31_Clipdata[76] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_31_clipdata.rle")
};

const u8 sMainDeck_31_Bg2[315] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_31_bg2.rle")
};

const u8 sMainDeck_31_Bg1[281] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_31_bg1.rle")
};

const u8 sMainDeck_31_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	3, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	3, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	4, 16, SPRITESET_IDX(2),
	5, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

