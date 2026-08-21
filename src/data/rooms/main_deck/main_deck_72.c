#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_72_Clipdata[53] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_72_clipdata.rle")
};

const u8 sMainDeck_72_Bg2[14] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_72_bg2.rle")
};

const u8 sMainDeck_72_Bg1[188] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_72_bg1.rle")
};

const u8 sMainDeck_72_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 11, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

