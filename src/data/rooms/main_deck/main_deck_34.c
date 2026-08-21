#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_34_Clipdata[68] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_34_clipdata.rle")
};

const u8 sMainDeck_34_Bg2[150] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_34_bg2.rle")
};

const u8 sMainDeck_34_Bg1[215] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_34_bg1.rle")
};

const u8 sMainDeck_34_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

