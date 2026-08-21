#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_14_Clipdata[171] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_14_clipdata.rle")
};

const u8 sMainDeck_14_Bg2[486] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_14_bg2.rle")
};

const u8 sMainDeck_14_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	4, 15, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_14_Bg1[461] = {
    49, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_14_bg1.rle")
};

const u8 sMainDeck_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	4, 15, SPRITESET_IDX(2),
	10, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	10, 15, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

