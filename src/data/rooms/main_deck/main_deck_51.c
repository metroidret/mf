#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_51_Clipdata[610] = {
    34, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_51_clipdata.rle")
};

const u8 sMainDeck_51_Bg2[2182] = {
    34, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_51_bg2.rle")
};

const u8 sMainDeck_51_Bg1[1078] = {
    34, // Room width
    54, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_51_bg1.rle")
};

const u8 sMainDeck_51_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	15, 9, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	22, 27, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	29, 21, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	34, 3, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	34, 11, SPRITESET_IDX(2),
	36, 27, SSP_HIDDEN_ON_ROOM_LOAD | SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

