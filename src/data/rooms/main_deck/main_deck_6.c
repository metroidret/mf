#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_6_Clipdata[233] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_6_clipdata.rle")
};

const u8 sMainDeck_6_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	24, 10, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_6_Bg2[148] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_6_bg2.rle")
};

const u8 sMainDeck_6_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	30, 11, SPRITESET_IDX(2),
	35, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_6_Bg1[554] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_6_bg1.rle")
};

const u8 sMainDeck_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_6_Bg0[14] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_6_bg0.rle")
};

