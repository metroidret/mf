#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_23_Scrolls[SCROLL_DATA_SIZE(2)] = {
	23, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_23_Clipdata[140] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_23_clipdata.rle")
};

const u8 sMainDeck_23_Bg2[91] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_23_bg2.rle")
};

const u8 sMainDeck_23_Bg1[418] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_23_bg1.rle")
};

const u8 sMainDeck_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

