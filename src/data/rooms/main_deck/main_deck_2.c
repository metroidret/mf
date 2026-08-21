#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_2_Clipdata[142] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_2_clipdata.rle")
};

const u8 sMainDeck_2_Bg2[86] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_2_bg2.rle")
};

const u8 sMainDeck_2_Bg1[349] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_2_bg1.rle")
};

const u8 sMainDeck_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

