#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	10, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 21, // Y bounds
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

const u8 sMainDeck_10_Clipdata[139] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_10_clipdata.rle")
};

const u8 sMainDeck_10_Bg2[94] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_10_bg2.rle")
};

const u8 sMainDeck_10_Bg1[450] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_10_bg1.rle")
};

const u8 sMainDeck_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	10, 11, SPRITESET_IDX(2),
	14, 15, SSP_X_UNABSORBABLE_BY_SAMUS | SPRITESET_IDX(6),
	16, 30, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(0),
	17, 14, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	18, 22, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_10_Bg0[14] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_10_bg0.rle")
};

