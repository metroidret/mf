#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_68_Clipdata[22] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_68_clipdata.rle")
};

const u8 sMainDeck_68_Bg2[14] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_68_bg2.rle")
};

const u8 sMainDeck_68_Bg1[148] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_68_bg1.rle")
};

const u8 sMainDeck_68_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_68_Bg0[329] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_68_bg0.rle")
};

