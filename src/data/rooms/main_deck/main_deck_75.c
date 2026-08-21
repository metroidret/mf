#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_75_Scrolls[SCROLL_DATA_SIZE(1)] = {
	75, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sMainDeck_75_Clipdata[118] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_75_clipdata.rle")
};

const u8 sMainDeck_75_Bg2[288] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_75_bg2.rle")
};

const u8 sMainDeck_75_Bg1[373] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_75_bg1.rle")
};

const u8 sMainDeck_75_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	18, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

