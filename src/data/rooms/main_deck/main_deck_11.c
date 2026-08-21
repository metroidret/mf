#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_11_Clipdata[60] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_11_clipdata.rle")
};

const u8 sMainDeck_11_Bg2[164] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_11_bg2.rle")
};

const u8 sMainDeck_11_Bg1[151] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_11_bg1.rle")
};

const u8 sMainDeck_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

