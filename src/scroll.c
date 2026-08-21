#include "types.h"
#include "macros.h"

#include "data/rooms/main_deck_rooms_data.h"
#include "data/rooms/sector_1_rooms_data.h"
#include "data/rooms/sector_2_rooms_data.h"
#include "data/rooms/sector_3_rooms_data.h"
#include "data/rooms/sector_4_rooms_data.h"
#include "data/rooms/sector_5_rooms_data.h"
#include "data/rooms/sector_6_rooms_data.h"

#include "data/animated_graphics_data.h" // sScroll_Empty currently sits in animated_graphics_data.c

static const u8* sScrollPointer_Empty[] = {
    sScroll_Empty
};

static const u8* sMainDeckScrolls[] = {
	sMainDeck_7_Scrolls,
	sMainDeck_10_Scrolls,
	sMainDeck_12_Scrolls,
	sMainDeck_13_Scrolls,
	sMainDeck_17_Scrolls,
	sMainDeck_19_Scrolls,
	sMainDeck_20_Scrolls,
	sMainDeck_21_Scrolls,
	sMainDeck_23_Scrolls,
	sMainDeck_24_Scrolls,
	sMainDeck_25_Scrolls,
	sMainDeck_26_Scrolls,
	sMainDeck_27_Scrolls,
	sMainDeck_28_Scrolls,
	sMainDeck_29_Scrolls,
	sMainDeck_30_Scrolls,
	sMainDeck_38_Scrolls,
	sMainDeck_40_Scrolls,
	sMainDeck_46_Scrolls,
	sMainDeck_47_Scrolls,
	sMainDeck_60_Scrolls,
	sMainDeck_61_Scrolls,
	sMainDeck_67_Scrolls,
	sMainDeck_69_Scrolls,
	sMainDeck_74_Scrolls,
	sMainDeck_75_Scrolls,
	sMainDeck_76_Scrolls,
	sMainDeck_77_Scrolls,
	sMainDeck_78_Scrolls,
	sMainDeck_79_Scrolls,
	sMainDeck_82_Scrolls,
	sMainDeck_85_Scrolls,
    sScroll_Empty
};

static const u8* sSector1Scrolls[] = {
	sSector1_0_Scrolls,
	sSector1_10_Scrolls,
	sSector1_20_Scrolls,
	sSector1_21_Scrolls,
	sSector1_22_Scrolls,
	sSector1_31_Scrolls,
	sSector1_36_Scrolls,
	sSector1_38_Scrolls,
	sSector1_39_Scrolls,
	sSector1_40_Scrolls,
	sSector1_41_Scrolls,
    sScroll_Empty
};

static const u8* sSector2Scrolls[] = {
	sSector2_5_Scrolls,
	sSector2_6_Scrolls,
	sSector2_9_Scrolls,
	sSector2_10_Scrolls,
	sSector2_17_Scrolls,
	sSector2_18_Scrolls,
	sSector2_19_Scrolls,
	sSector2_20_Scrolls,
	sSector2_21_Scrolls,
	sSector2_22_Scrolls,
	sSector2_24_Scrolls,
	sSector2_26_Scrolls,
	sSector2_27_Scrolls,
	sSector2_29_Scrolls,
	sSector2_31_Scrolls,
	sSector2_33_Scrolls,
	sSector2_34_Scrolls,
	sSector2_36_Scrolls,
	sSector2_44_Scrolls,
	sSector2_47_Scrolls,
	sSector2_51_Scrolls,
	sSector2_57_Scrolls,
	sSector2_58_Scrolls,
    sScroll_Empty
};

static const u8* sSector3Scrolls[] = {
	sSector3_3_Scrolls,
	sSector3_6_Scrolls,
	sSector3_8_Scrolls,
	sSector3_11_Scrolls,
	sSector3_12_Scrolls,
	sSector3_18_Scrolls,
	sSector3_19_Scrolls,
	sSector3_20_Scrolls,
	sSector3_22_Scrolls,
	sSector3_23_Scrolls,
	sSector3_24_Scrolls,
	sSector3_28_Scrolls,
	sSector3_30_Scrolls,
	sSector3_34_Scrolls,
    sScroll_Empty
};

static const u8* sSector5Scrolls[] = {
	sSector5_0_Scrolls,
	sSector5_4_Scrolls,
	sSector5_7_Scrolls,
	sSector5_9_Scrolls,
	sSector5_10_Scrolls,
	sSector5_15_Scrolls,
	sSector5_19_Scrolls,
	sSector5_20_Scrolls,
	sSector5_21_Scrolls,
	sSector5_22_Scrolls,
	sSector5_24_Scrolls,
	sSector5_25_Scrolls,
	sSector5_30_Scrolls,
	sSector5_36_Scrolls,
	sSector5_42_Scrolls,
	sSector5_43_Scrolls,
	sSector5_46_Scrolls,
	sSector5_50_Scrolls,
    sScroll_Empty
};

static const u8* sSector4Scrolls[] = {
	sSector4_8_Scrolls,
	sSector4_13_Scrolls,
	sSector4_17_Scrolls,
	sSector4_21_Scrolls,
	sSector4_23_Scrolls,
	sSector4_24_Scrolls,
	sSector4_27_Scrolls,
	sSector4_33_Scrolls,
	sSector4_34_Scrolls,
	sSector4_35_Scrolls,
	sSector4_36_Scrolls,
	sSector4_42_Scrolls,
    sScroll_Empty
};

static const u8* sSector6Scrolls[] = {
	sSector6_0_Scrolls,
	sSector6_5_Scrolls,
	sSector6_7_Scrolls,
	sSector6_8_Scrolls,
	sSector6_9_Scrolls,
	sSector6_12_Scrolls,
	sSector6_13_Scrolls,
	sSector6_14_Scrolls,
	sSector6_16_Scrolls,
	sSector6_17_Scrolls,
	sSector6_18_Scrolls,
	sSector6_19_Scrolls,
	sSector6_24_Scrolls,
	sSector6_26_Scrolls,
	sSector6_27_Scrolls,
	sSector6_28_Scrolls,
	sSector6_30_Scrolls,
	sSector6_31_Scrolls,
	sSector6_33_Scrolls,
    sScroll_Empty
};

static const u8** sAreaScrollPointers[AREA_END] = {
    [AREA_MAIN_DECK] = sMainDeckScrolls,
    [AREA_SECTOR_1] = sSector1Scrolls,
    [AREA_SECTOR_2] = sSector2Scrolls,
    [AREA_SECTOR_3] = sSector3Scrolls,
    [AREA_SECTOR_4] = sSector4Scrolls,
    [AREA_SECTOR_5] = sSector5Scrolls,
    [AREA_SECTOR_6] = sSector6Scrolls,
    [AREA_TEST_1] = sScrollPointer_Empty,
    [AREA_TEST_2] = sScrollPointer_Empty,
    [AREA_TEST_3] = sScrollPointer_Empty
};

static u8 sBlob_79bb30_79bbcc[] = INCBIN_U8("data/Blob_79bb30_79bbcc.bin");
