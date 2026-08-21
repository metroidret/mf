#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_74_Scrolls[SCROLL_DATA_SIZE(2)] = {
	74, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	28, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_74_Clipdata[183] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_74_clipdata.rle")
};

const u8 sMainDeck_74_Bg2[1047] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_74_bg2.rle")
};

const u8 sMainDeck_74_Bg1[731] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_74_bg1.rle")
};

const u8 sMainDeck_74_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	16, 26, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_74_Bg0[53] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_74_bg0.rle")
};

