#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_18_Clipdata[236] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_18_clipdata.rle")
};

const u8 sMainDeck_18_Bg2[267] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_18_bg2.rle")
};

const u8 sMainDeck_18_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 9, SPRITESET_IDX(2),
	6, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_18_Bg1[620] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_18_bg1.rle")
};

const u8 sMainDeck_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_18_Bg0[14] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_18_bg0.rle")
};

