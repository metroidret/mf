#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_48_Clipdata[401] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_48_clipdata.rle")
};

const u8 sMainDeck_48_Bg2[917] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_48_bg2.rle")
};

const u8 sMainDeck_48_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	18, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_48_Bg1[581] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_48_bg1.rle")
};

const u8 sMainDeck_48_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	18, 7, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

