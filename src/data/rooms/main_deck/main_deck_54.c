#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_54_Clipdata[74] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_54_clipdata.rle")
};

const u8 sMainDeck_54_Bg2[149] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_54_bg2.rle")
};

const u8 sMainDeck_54_Bg1[191] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_54_bg1.rle")
};

const u8 sMainDeck_54_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

