#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_77_Scrolls[SCROLL_DATA_SIZE(3)] = {
	77, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	32, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	9, 35, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_77_Clipdata[426] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_77_clipdata.rle")
};

const u8 sMainDeck_77_Bg2[66] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_77_bg2.rle")
};

const u8 sMainDeck_77_Bg1[448] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_77_bg1.rle")
};

const u8 sMainDeck_77_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_77_Bg0[158] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_77_bg0.rle")
};

