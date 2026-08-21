#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_27_Scrolls[SCROLL_DATA_SIZE(1)] = {
	27, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sMainDeck_27_Clipdata[130] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_27_clipdata.rle")
};

const u8 sMainDeck_27_Bg2[186] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_27_bg2.rle")
};

const u8 sMainDeck_27_Bg1[382] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_27_bg1.rle")
};

const u8 sMainDeck_27_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	4, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	5, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	6, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	7, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	7, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(11),
	8, 4, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	9, 9, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(12),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_27_Bg0[53] = {
    19, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_27_bg0.rle")
};

