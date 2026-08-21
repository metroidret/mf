#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_57_Clipdata[103] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_57_clipdata.rle")
};

const u8 sMainDeck_57_Bg2[76] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_57_bg2.rle")
};

const u8 sMainDeck_57_Bg1[158] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_57_bg1.rle")
};

const u8 sMainDeck_57_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_57_Bg0[151] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_57_bg0.rle")
};

