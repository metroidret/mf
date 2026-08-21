#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_21_Scrolls[SCROLL_DATA_SIZE(2)] = {
	21, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_21_Clipdata[190] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_21_clipdata.rle")
};

const u8 sMainDeck_21_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	7, 5, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_21_Bg2[253] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_21_bg2.rle")
};

const u8 sMainDeck_21_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	7, 5, SPRITESET_IDX(1),
	15, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	29, 27, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	33, 16, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(7),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_21_Bg1[619] = {
    34, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_21_bg1.rle")
};

const u8 sMainDeck_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	7, 5, SPRITESET_IDX(1),
	15, 5, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	16, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	29, 27, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	33, 16, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(7),
	ROOM_SPRITE_DATA_TERMINATOR
};

