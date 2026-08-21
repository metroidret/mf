#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_46_Scrolls[SCROLL_DATA_SIZE(2)] = {
	46, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_46_Clipdata[108] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_46_clipdata.rle")
};

const u8 sMainDeck_46_Bg2[36] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_46_bg2.rle")
};

const u8 sMainDeck_46_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_46_Bg1[337] = {
    34, // Room width
    14, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_46_bg1.rle")
};

const u8 sMainDeck_46_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 11, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

