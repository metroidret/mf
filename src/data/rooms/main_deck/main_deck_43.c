#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_43_Clipdata[56] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_43_clipdata.rle")
};

const u8 sMainDeck_43_Bg2[154] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_43_bg2.rle")
};

const u8 sMainDeck_43_Bg1[218] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_43_bg1.rle")
};

const u8 sMainDeck_43_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

