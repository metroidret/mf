#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_45_Clipdata[44] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_45_clipdata.rle")
};

const u8 sMainDeck_45_Bg2[163] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_45_bg2.rle")
};

const u8 sMainDeck_45_Bg1[140] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_45_bg1.rle")
};

const u8 sMainDeck_45_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

