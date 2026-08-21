#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_60_Scrolls[SCROLL_DATA_SIZE(1)] = {
	60, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sMainDeck_60_Clipdata[116] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_60_clipdata.rle")
};

const u8 sMainDeck_60_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_60_Bg2[249] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_60_bg2.rle")
};

const u8 sMainDeck_60_Bg1[326] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_60_bg1.rle")
};

const u8 sMainDeck_60_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_60_Bg0[14] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_60_bg0.rle")
};

