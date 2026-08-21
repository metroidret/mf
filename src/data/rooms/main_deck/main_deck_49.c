#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_49_Clipdata[482] = {
    34, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_49_clipdata.rle")
};

const u8 sMainDeck_49_Bg2[1103] = {
    34, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_49_bg2.rle")
};

const u8 sMainDeck_49_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	22, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	24, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	31, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	37, 17, SPRITESET_IDX(2),
	37, 28, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	38, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	39, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	41, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	43, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(4),
	54, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	58, 11, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	58, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	58, 17, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	58, 20, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_49_Bg1[1219] = {
    34, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_49_bg1.rle")
};

const u8 sMainDeck_49_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	24, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	37, 17, SPRITESET_IDX(2),
	37, 28, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	38, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	41, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	54, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	58, 14, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_49_Bg0[1698] = {
    34, // Room width
    64, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_49_bg0.rle")
};

