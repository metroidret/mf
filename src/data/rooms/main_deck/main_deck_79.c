#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_79_Scrolls[SCROLL_DATA_SIZE(1)] = {
	79, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	32, 41, // Y bounds
	10, 32, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sMainDeck_79_Clipdata[188] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_79_clipdata.rle")
};

const u8 sMainDeck_79_Bg2[274] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_79_bg2.rle")
};

const u8 sMainDeck_79_Bg1[425] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_79_bg1.rle")
};

const u8 sMainDeck_79_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	8, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	15, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	20, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	24, 6, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	26, 12, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	32, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	32, 6, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	32, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	32, 12, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	33, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	34, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	35, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	40, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_79_Bg0[14] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_79_bg0.rle")
};

