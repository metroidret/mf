#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_35_Clipdata[459] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_35_clipdata.rle")
};

const u8 sMainDeck_35_Bg2[1264] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_35_bg2.rle")
};

const u8 sMainDeck_35_Bg1[1170] = {
    19, // Room width
    74, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_35_bg1.rle")
};

const u8 sMainDeck_35_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	21, 11, SPRITESET_IDX(2),
	25, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	32, 7, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(7),
	70, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

