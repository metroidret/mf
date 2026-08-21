#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_19_Scrolls[SCROLL_DATA_SIZE(1)] = {
	19, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_19_Clipdata[116] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_19_clipdata.rle")
};

const u8 sMainDeck_19_Bg2[304] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_19_bg2.rle")
};

const u8 sMainDeck_19_Bg1[461] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_19_bg1.rle")
};

const u8 sMainDeck_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_19_Bg0[42] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_19_bg0.rle")
};

