#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_5_Clipdata[80] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_5_clipdata.rle")
};

const u8 sMainDeck_5_Bg1[169] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_5_bg1.rle")
};

const u8 sMainDeck_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

