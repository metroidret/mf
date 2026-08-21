#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_63_Clipdata[56] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_63_clipdata.rle")
};

const u8 sMainDeck_63_Bg2[397] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_63_bg2.rle")
};

const u8 sMainDeck_63_Bg1[93] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_63_bg1.rle")
};

const u8 sMainDeck_63_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 30, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

