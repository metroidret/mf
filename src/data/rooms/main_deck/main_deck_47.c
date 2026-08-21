#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_47_Scrolls[SCROLL_DATA_SIZE(2)] = {
	47, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 19, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 91, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_47_Clipdata[157] = {
    94, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_47_clipdata.rle")
};

const u8 sMainDeck_47_Bg2[510] = {
    94, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_47_bg2.rle")
};

const u8 sMainDeck_47_Bg1[590] = {
    94, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_47_bg1.rle")
};

const u8 sMainDeck_47_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	4, 40, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 47, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 55, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 64, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 72, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 80, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	4, 88, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	6, 57, SPRITESET_IDX(2),
	8, 48, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 62, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 74, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	8, 83, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

