#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_8_Clipdata[60] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_8_clipdata.rle")
};

const u8 sMainDeck_8_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_8_bg2.rle")
};

const u8 sMainDeck_8_Bg1[137] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_8_bg1.rle")
};

const u8 sMainDeck_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

