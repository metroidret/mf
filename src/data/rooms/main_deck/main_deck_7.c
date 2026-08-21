#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_7_Scrolls[SCROLL_DATA_SIZE(2)] = {
	7, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_7_Clipdata[151] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_7_clipdata.rle")
};

const u8 sMainDeck_7_Bg2[297] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_7_bg2.rle")
};

const u8 sMainDeck_7_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	7, 17, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_7_Bg1[557] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_7_bg1.rle")
};

const u8 sMainDeck_7_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	7, 15, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_7_Bg0[64] = {
    34, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_7_bg0.rle")
};

