#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_70_Clipdata[59] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_70_clipdata.rle")
};

const u8 sMainDeck_70_Bg2[14] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_70_bg2.rle")
};

const u8 sMainDeck_70_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	6, 9, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_70_Bg1[170] = {
    19, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_70_bg1.rle")
};

const u8 sMainDeck_70_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	6, 9, SPRITESET_IDX(2),
	6, 10, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(7),
	8, 10, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

