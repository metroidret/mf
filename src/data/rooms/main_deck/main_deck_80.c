#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_80_Clipdata[122] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_80_clipdata.rle")
};

const u8 sMainDeck_80_Bg2[26] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_80_bg2.rle")
};

const u8 sMainDeck_80_Bg1[247] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_80_bg1.rle")
};

const u8 sMainDeck_80_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	3, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(7),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_80_Bg0[14] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_80_bg0.rle")
};

