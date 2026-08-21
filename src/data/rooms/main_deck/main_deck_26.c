#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_26_Scrolls[SCROLL_DATA_SIZE(1)] = {
	26, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sMainDeck_26_Clipdata[142] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_26_clipdata.rle")
};

const u8 sMainDeck_26_Bg2[188] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_26_bg2.rle")
};

const u8 sMainDeck_26_Bg1[382] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_26_bg1.rle")
};

const u8 sMainDeck_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	4, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	5, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	6, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	6, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	7, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	7, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(9),
	9, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(12),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_26_Bg0[53] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_26_bg0.rle")
};

