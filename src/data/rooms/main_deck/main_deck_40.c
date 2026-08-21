#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_40_Scrolls[SCROLL_DATA_SIZE(1)] = {
	40, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sMainDeck_40_Clipdata[124] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_40_clipdata.rle")
};

const u8 sMainDeck_40_Bg2[298] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_40_bg2.rle")
};

const u8 sMainDeck_40_Bg1[468] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_40_bg1.rle")
};

const u8 sMainDeck_40_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_40_Bg0[42] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_40_bg0.rle")
};

