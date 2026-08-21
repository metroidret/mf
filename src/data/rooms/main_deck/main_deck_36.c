#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_36_Clipdata[97] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_36_clipdata.rle")
};

const u8 sMainDeck_36_Bg2[210] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_36_bg2.rle")
};

const u8 sMainDeck_36_Bg1[256] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_36_bg1.rle")
};

const u8 sMainDeck_36_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

