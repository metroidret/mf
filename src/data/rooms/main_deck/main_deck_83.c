#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_83_Clipdata[405] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_83_clipdata.rle")
};

const u8 sMainDeck_83_Bg2[917] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_83_bg2.rle")
};

const u8 sMainDeck_83_Bg1[776] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_83_bg1.rle")
};

const u8 sMainDeck_83_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

