#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_71_Clipdata[66] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_71_clipdata.rle")
};

const u8 sMainDeck_71_Bg2[43] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_71_bg2.rle")
};

const u8 sMainDeck_71_Bg1[234] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_71_bg1.rle")
};

const u8 sMainDeck_71_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	4, 8, SPRITESET_IDX(0),
	9, 7, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

