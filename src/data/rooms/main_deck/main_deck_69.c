#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_69_Scrolls[SCROLL_DATA_SIZE(3)] = {
	69, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 46, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 46, // X bounds
	21, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_69_Clipdata[318] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_69_clipdata.rle")
};

const u8 sMainDeck_69_Bg2[1114] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_69_bg2.rle")
};

const u8 sMainDeck_69_Bg1[853] = {
    49, // Room width
    34, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_69_bg1.rle")
};

const u8 sMainDeck_69_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	9, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(9),
	9, 19, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	9, 20, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(8),
	9, 22, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(7),
	9, 23, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	9, 24, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(8),
	9, 26, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(8),
	9, 31, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(9),
	9, 39, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(9),
	19, 33, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	28, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	28, 33, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

