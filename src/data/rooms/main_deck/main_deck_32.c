#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_32_Clipdata[72] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_32_clipdata.rle")
};

const u8 sMainDeck_32_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_32_bg2.rle")
};

const u8 sMainDeck_32_Bg1[229] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_32_bg1.rle")
};

const u8 sMainDeck_32_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_32_Bg0[36] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_32_bg0.rle")
};

