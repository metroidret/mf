#include "data/rooms/main_deck_rooms_data.h"
#include "macros.h"

const u8 sMainDeck_78_Scrolls[SCROLL_DATA_SIZE(2)] = {
	78, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	32, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sMainDeck_78_Clipdata[176] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_78_clipdata.rle")
};

const u8 sMainDeck_78_Bg2[346] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_78_bg2.rle")
};

const u8 sMainDeck_78_Bg1[461] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_78_bg1.rle")
};

const u8 sMainDeck_78_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(24)] = {
	23, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	24, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	25, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	25, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	25, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	26, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	26, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	26, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	27, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	27, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	27, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	30, 10, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(7),
	33, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	34, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	35, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	35, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	35, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	36, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	36, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	36, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	37, 5, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	37, 9, SSP_X_ABSORBABLE_BY_SAMUS | SPRITESET_IDX(1),
	37, 13, SSP_UNINFECTED_OR_BOSS | SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sMainDeck_78_Bg0[578] = {
    19, // Room width
    44, // Room height
    _INCBIN_U8("data/rooms/main_deck/main_deck_78_bg0.rle")
};

