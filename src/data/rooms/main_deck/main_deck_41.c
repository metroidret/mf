#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_41_Clipdata[56] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_41_clipdata.rle")
};

const u8 sMainDeck_41_Bg2[295] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_41_bg2.rle")
};

const u8 sMainDeck_41_Bg1[298] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_41_bg1.rle")
};

const u8 sMainDeck_41_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

