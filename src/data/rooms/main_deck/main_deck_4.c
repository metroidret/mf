#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_4_Clipdata[70] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_4_clipdata.rle")
};

const u8 sMainDeck_4_Bg2[178] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_4_bg2.rle")
};

const u8 sMainDeck_4_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	10, 30, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(8),
	10, 33, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(8),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_4_Bg1[289] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_4_bg1.rle")
};

const u8 sMainDeck_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

