#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_73_Clipdata[75] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_73_clipdata.rle")
};

const u8 sMainDeck_73_Bg2[184] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_73_bg2.rle")
};

const u8 sMainDeck_73_Bg1[171] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_73_bg1.rle")
};

const u8 sMainDeck_73_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

