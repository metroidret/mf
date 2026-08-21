#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_12_Scrolls[SCROLL_DATA_SIZE(2)] = {
	12, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 15, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_12_Clipdata[118] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_12_clipdata.rle")
};

const u8 sMainDeck_12_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	13, 6, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_12_Bg2[160] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_12_bg2.rle")
};

const u8 sMainDeck_12_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	6, 13, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	13, 6, SPRITESET_IDX(2),
	19, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	19, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_12_Bg1[417] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_12_bg1.rle")
};

const u8 sMainDeck_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	17, 9, SPRITESET_IDX(2),
	19, 19, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	19, 24, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

