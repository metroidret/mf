#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_24_Scrolls[SCROLL_DATA_SIZE(2)] = {
	24, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension

	// Scroll 1
	2, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_24_Clipdata[136] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_24_clipdata.rle")
};

const u8 sMainDeck_24_Bg2[388] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_24_bg2.rle")
};

const u8 sMainDeck_24_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	15, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	15, 29, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	16, 6, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	16, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	16, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	16, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	16, 29, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	16, 37, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	16, 39, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	16, 41, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	17, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	17, 29, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	18, 24, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(12),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_24_Bg1[561] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_24_bg1.rle")
};

const u8 sMainDeck_24_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	15, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	15, 29, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	16, 6, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	16, 8, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	16, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(0),
	16, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(2),
	16, 29, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	16, 37, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	16, 39, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(3),
	16, 41, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	17, 18, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(4),
	17, 29, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_24_Bg0[32] = {
    49, // Room width
    24, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_24_bg0.rle")
};

