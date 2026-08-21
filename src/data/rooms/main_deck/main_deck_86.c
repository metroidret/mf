#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_86_Clipdata[154] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_86_clipdata.rle")
};

const u8 sMainDeck_86_Bg2[235] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_86_bg2.rle")
};

const u8 sMainDeck_86_Bg1[351] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_86_bg1.rle")
};

const u8 sMainDeck_86_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	23, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	24, 9, SPRITESET_IDX(14),
	25, 9, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_86_Bg0[63] = {
    19, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_86_bg0.rle")
};

