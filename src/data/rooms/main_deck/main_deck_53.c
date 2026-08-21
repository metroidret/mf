#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_53_Clipdata[156] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_53_clipdata.rle")
};

const u8 sMainDeck_53_Bg2[470] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_53_bg2.rle")
};

const u8 sMainDeck_53_Bg1[305] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_53_bg1.rle")
};

const u8 sMainDeck_53_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	14, 9, SPRITESET_IDX(14),
	20, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

