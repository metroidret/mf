#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_62_Clipdata[82] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_62_clipdata.rle")
};

const u8 sMainDeck_62_Bg2[184] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_62_bg2.rle")
};

const u8 sMainDeck_62_Bg1[190] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_62_bg1.rle")
};

const u8 sMainDeck_62_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

