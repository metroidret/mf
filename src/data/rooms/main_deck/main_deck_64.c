#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_64_Clipdata[76] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_64_clipdata.rle")
};

const u8 sMainDeck_64_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_64_bg2.rle")
};

const u8 sMainDeck_64_Bg1[158] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_64_bg1.rle")
};

const u8 sMainDeck_64_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

