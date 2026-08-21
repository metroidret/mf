#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_38_Scrolls[SCROLL_DATA_SIZE(4)] = {
	38, // Room
	4, // Number of scrolls
	
	// Scroll 0
	32, 61, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	46, 61, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	18, 46, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 3
	2, 18, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_38_Clipdata[342] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_38_clipdata.rle")
};

const u8 sMainDeck_38_Bg2[175] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_38_bg2.rle")
};

const u8 sMainDeck_38_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	25, 53, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_38_Bg1[1254] = {
    64, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_38_bg1.rle")
};

const u8 sMainDeck_38_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	24, 53, SPRITESET_IDX(14),
	25, 53, SPRITESET_IDX(2),
	30, 50, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

