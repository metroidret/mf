#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_1_Clipdata[142] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_1_clipdata.rle")
};

const u8 sMainDeck_1_Bg2[86] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_1_bg2.rle")
};

const u8 sMainDeck_1_Bg1[349] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_1_bg1.rle")
};

const u8 sMainDeck_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	20, 16, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

