#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_52_Clipdata[60] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_52_clipdata.rle")
};

const u8 sMainDeck_52_Bg2[178] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_52_bg2.rle")
};

const u8 sMainDeck_52_Bg1[189] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_52_bg1.rle")
};

const u8 sMainDeck_52_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

